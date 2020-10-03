/*
 * Copyright (c) 2011 Matthew Iselin
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include <Widget.h>

#include <ipc/Ipc.h>

/// \todo GTFO libc!
#include <unistd.h>

/// \todo GTFO libc!
#include <string.h>
#include <stdlib.h>
#include <syslog.h>

#include <map>
#include <queue>

#include "protocol.h"

using namespace LibUiProtocol;

#define FORGOTTEN_WINMAN_ENDPOINT "fos-winman"

/// Default event handler for new widgets.
static bool defaultEventHandler(WidgetMessages message, size_t dataSize, void *dataBuffer)
{
    return false;
}

static Widget *g_pWidget = 0;

static ForgottenIpc::IpcEndpoint *g_pWinmanEndpoint = 0;

std::map<uint64_t, widgetCallback_t> Widget::m_CallbackMap;
std::queue<ForgottenIpc::IpcMessage *> g_PendingMessages;

Widget::Widget() :
    m_bConstructed(false), m_pFramebuffer(0), m_Handle(0),
    m_EventCallback(defaultEventHandler), m_Endpoint(0),
    m_SharedFramebuffer(0)
{
}

Widget::~Widget()
{
    if(m_Endpoint) {
        free((void *) m_Endpoint);
    }
}

bool Widget::construct(const char *endpoint, const char *title, widgetCallback_t cb, ForgottenGraphics::Rect &dimensions)
{
    if(m_Handle)
    {
        // Already constructed!
        return false;
    }

    /// \todo Maybe we can get a decent way of having a default handler?
    if(!cb)
        return false;

    // Create endpoint, if not already created.
    /// \todo fail if endpoint already exists.
    ForgottenIpc::createEndpoint(endpoint);
    m_Endpoint = ForgottenIpc::getEndpoint(endpoint);
    if(!g_pWinmanEndpoint)
    {
        g_pWinmanEndpoint = ForgottenIpc::getEndpoint(FORGOTTEN_WINMAN_ENDPOINT);
    }

    // Construct the handle first.
    uint64_t pid = getpid();
    uintptr_t widgetPointer = reinterpret_cast<uintptr_t>(this);
#ifdef BITS_64
    m_Handle = (pid << 32) | (((widgetPointer >> 32) | (widgetPointer & 0xFFFFFFFF)) & 0xFFFFFFFF);
#else
    m_Handle = (pid << 32) | (widgetPointer);
#endif

    ForgottenIpc::IpcMessage *pCreateMessage = new ForgottenIpc::IpcMessage();
    if(!pCreateMessage->initialise())
    {
        m_Handle = 0;
        return false;
    }

    // Prepare a message to send.
    size_t totalSize = sizeof(WindowManagerMessage) + sizeof(CreateMessage);
    char *messageData = static_cast<char *>(pCreateMessage->getBuffer());
    WindowManagerMessage *pWinMan = reinterpret_cast<WindowManagerMessage*>(messageData);
    CreateMessage *pCreate = reinterpret_cast<CreateMessage*>(messageData + sizeof(WindowManagerMessage));

    // Fill.
    pWinMan->messageCode = Create;
    pWinMan->messageSize = sizeof(CreateMessage);
    pWinMan->widgetHandle = m_Handle;
    pWinMan->isResponse = false;
    strlcpy(pCreate->endpoint, endpoint, 256);
    strlcpy(pCreate->title, title, 256);
    pCreate->minWidth = dimensions.getW();
    pCreate->minHeight = dimensions.getH();
    pCreate->rigid = true;

    // Send the message off to the window manager and wait for a response. The
    // response will contain a GraphicsProvider that we can use to create our
    // Framebuffer for drawing on.
    if(!ForgottenIpc::send(g_pWinmanEndpoint, pCreateMessage, false))
    {
        m_Handle = 0;
        delete pCreateMessage;
        return false;
    }

    ForgottenIpc::IpcMessage *pResponse = 0;

    while(1)
    {
        if(!ForgottenIpc::recv(m_Endpoint, &pResponse, false))
        {
            m_Handle = 0;
            return false;
        }

        if(!(pResponse && pResponse->getBuffer()))
        {
            continue;
        }

        pWinMan = reinterpret_cast<WindowManagerMessage*>(pResponse->getBuffer());
        if(!(pWinMan->isResponse && (pWinMan->messageCode == Create)))
        {
            g_PendingMessages.push(pResponse);
        }
        else
        {
            messageData = static_cast<char *>(pResponse->getBuffer());
            break;
        }
    }

    // Grab the results and use them.
    CreateMessageResponse *pCreateResp = reinterpret_cast<CreateMessageResponse*>(messageData + sizeof(WindowManagerMessage));
    m_EventCallback = cb;
    m_CallbackMap[m_Handle] = cb;

    delete pResponse;

    g_pWidget = this;

    // Asynchronously check for any events in the pipeline. This should be an
    // initial reposition event that we really need to get out to the client
    // ASAP.
    checkForEvents(true);

    return true;
}

bool Widget::setProperty(std::string propName, void *propVal, size_t maxSize)
{
    // Constructed yet?
    if(!m_Handle)
        return false;

    // Are the arguments sane?
    if(!propVal)
        return false;
    if(maxSize > 0x1000)
        return false;

    // Allocate the message.
    /// \todo Sanitise maxSize once large messages can be sent.
    size_t headerSize = sizeof(WindowManagerMessage) + sizeof(SetPropertyMessage);
    size_t totalSize = headerSize + maxSize;
    char *messageData = new char[totalSize];
    WindowManagerMessage *pWinMan = reinterpret_cast<WindowManagerMessage*>(messageData);
    SetPropertyMessage *pMessage = reinterpret_cast<SetPropertyMessage*>(messageData + sizeof(WindowManagerMessage));

    // Fill the message.
    pWinMan->messageCode = SetProperty;
    pWinMan->messageSize = sizeof(SetPropertyMessage) + maxSize;
    pWinMan->widgetHandle = m_Handle;
    pWinMan->isResponse = false;

    propName.copy(pMessage->propertyName, sizeof pMessage->propertyName);
    pMessage->valueLength = maxSize;

    // Copy in the property data.
    memcpy(messageData + headerSize, propVal, maxSize);

    // Transmit.
    bool result = sendMessage(messageData, totalSize);

    // Clean up.
    delete [] messageData;

    return result;
}

bool Widget::getProperty(std::string propName, char **buffer, size_t maxSize)
{
    return false;
}

void Widget::setParent(Widget *pWidget)
{
}

Widget *Widget::getParent()
{
    return 0;
}

bool Widget::redraw(ForgottenGraphics::Rect &rt)
{
    // Constructed yet?
    if(!m_Handle)
        return false;

    // Allocate the message.
    ForgottenIpc::IpcMessage *pRedrawMessage = new ForgottenIpc::IpcMessage();
    if(!pRedrawMessage->initialise())
    {
        m_Handle = 0;
        return false;
    }

    size_t totalSize = sizeof(WindowManagerMessage) + sizeof(RequestRedrawMessage);
    char *messageData = static_cast<char *>(pRedrawMessage->getBuffer());
    WindowManagerMessage *pWinMan = reinterpret_cast<WindowManagerMessage*>(messageData);
    RequestRedrawMessage *pMessage = reinterpret_cast<RequestRedrawMessage*>(messageData + sizeof(WindowManagerMessage));

    // Fill the message.
    pWinMan->messageCode = RequestRedraw;
    pWinMan->messageSize = sizeof(RequestRedrawMessage);
    pWinMan->widgetHandle = m_Handle;
    pWinMan->isResponse = false;
    pMessage->x = rt.getX();
    pMessage->y = rt.getY();
    pMessage->width = rt.getW();
    pMessage->height = rt.getH();

    // Transmit.
    if(!ForgottenIpc::send(g_pWinmanEndpoint, pRedrawMessage))
    {
        delete pRedrawMessage;
        return false;
    }

    return true;
}

bool Widget::visibility(bool vis)
{
    // Constructed yet?
    if(!m_Handle)
        return false;

    // Allocate the message.
    size_t totalSize = sizeof(WindowManagerMessage) + sizeof(SetVisibilityMessage);
    char *messageData = new char[totalSize];
    WindowManagerMessage *pWinMan = reinterpret_cast<WindowManagerMessage*>(messageData);
    SetVisibilityMessage *pMessage = reinterpret_cast<SetVisibilityMessage*>(messageData + sizeof(WindowManagerMessage));

    // Fill the message.
    pWinMan->messageCode = SetVisibility;
    pWinMan->messageSize = sizeof(SetVisibilityMessage);
    pWinMan->widgetHandle = m_Handle;
    pWinMan->isResponse = false;
    pMessage->bVisible = vis;

    // Transmit.
    bool result = sendMessage(messageData, totalSize);

    // Clean up.
    delete [] messageData;

    return result;
}

void Widget::destroy()
{
    // Constructed yet?
    if(!m_Handle)
        return;

    // Allocate the message.
    size_t totalSize = sizeof(WindowManagerMessage) + sizeof(DestroyMessage);
    char *messageData = new char[totalSize];
    WindowManagerMessage *pWinMan = reinterpret_cast<WindowManagerMessage*>(messageData);
    DestroyMessage *pMessage = reinterpret_cast<DestroyMessage*>(messageData + sizeof(WindowManagerMessage));

    // Fill the message.
    pWinMan->messageCode = Destroy;
    pWinMan->messageSize = sizeof(DestroyMessage);
    pWinMan->widgetHandle = m_Handle;
    pWinMan->isResponse = false;

    // Transmit.
    sendMessage(messageData, totalSize);

    // Clean up.
    delete [] messageData;

    // Invalidate this widget now.
    delete m_pFramebuffer;
    m_Handle = 0;
}

ForgottenGraphics::Framebuffer *Widget::getFramebuffer()
{
    return 0;

    /*
    // Constructed yet?
    if(!m_Handle)
        return 0;

    // No framebuffer yet?
    if(!m_pFramebuffer)
        return 0;

    // Allocate the message.
    size_t totalSize = sizeof(WindowManagerMessage) + sizeof(SyncMessage);
    char *messageData = new char[totalSize];
    WindowManagerMessage *pWinMan = reinterpret_cast<WindowManagerMessage*>(messageData);
    SyncMessage *pMessage = reinterpret_cast<SyncMessage*>(messageData + sizeof(WindowManagerMessage));

    // Fill the message.
    pWinMan->messageCode = Sync;
    pWinMan->messageSize = sizeof(SyncMessage);
    pWinMan->widgetHandle = m_Handle;
    pWinMan->isResponse = false;

    // Transmit, synchronously.
    syslog(LOG_INFO, "TX Sync [%d]", getpid());
    sendMessage(messageData, totalSize);
    syslog(LOG_INFO, "TX complete");

    delete [] messageData;

    // Get the response.
    totalSize = 1024;
    messageData = new char[totalSize];

    while(1)
    {
        if(!recvMessage(m_Endpoint, messageData, totalSize))
        {
            m_Handle = 0;
            delete [] messageData;
            return 0;
        }

        pWinMan = reinterpret_cast<WindowManagerMessage*>(messageData);
        if(!(pWinMan->isResponse && (pWinMan->messageCode == Sync)))
        {
            g_PendingMessages.push(messageData);
            messageData = new char[totalSize];
        }
        else
        {
            break;
        }
    }

    SyncMessageResponse *pSyncResp = reinterpret_cast<SyncMessageResponse*>(messageData + sizeof(WindowManagerMessage));
    if(m_pFramebuffer->getProvider().contextId !=
        pSyncResp->provider.contextId)
    {
        delete m_pFramebuffer;
        m_pFramebuffer = new ForgottenGraphics::Framebuffer(pSyncResp->provider);
    }

    return m_pFramebuffer;
    */
}

void Widget::checkForEvents(bool bAsync)
{
    /// \todo ALL created widgets, not just one.
    if(g_pWidget)
    {
        char *buffer = 0;
        ForgottenIpc::IpcMessage *pMessage = 0;
        if(g_PendingMessages.empty())
        {
            ForgottenIpc::recv(g_pWidget->m_Endpoint, &pMessage, bAsync);
        }
        else
        {
            pMessage = g_PendingMessages.front();
            g_PendingMessages.pop();
        }

        if(pMessage)
        {
            buffer = static_cast<char *>(pMessage->getBuffer());

            LibUiProtocol::WindowManagerMessage *pHeader =
                reinterpret_cast<LibUiProtocol::WindowManagerMessage*>(buffer);

            widgetCallback_t cb = m_CallbackMap[pHeader->widgetHandle];

            switch(pHeader->messageCode)
            {
                case LibUiProtocol::Reposition:
                {
                    LibUiProtocol::RepositionMessage *pReposition =
                        reinterpret_cast<LibUiProtocol::RepositionMessage*>(buffer + sizeof(LibUiProtocol::WindowManagerMessage));
                    delete g_pWidget->m_SharedFramebuffer;
                    g_pWidget->m_SharedFramebuffer =
                            new ForgottenIpc::SharedIpcMessage(pReposition->shmem_size, pReposition->shmem_handle);
                    g_pWidget->m_SharedFramebuffer->initialise();

                    // Run the callback now that the framebuffer is re-created.
                    cb(::Reposition, sizeof(pReposition->rt), &pReposition->rt);
                    break;
                }
                case LibUiProtocol::KeyEvent:
                {
                    LibUiProtocol::KeyEventMessage *pKeyEvent =
                        reinterpret_cast<LibUiProtocol::KeyEventMessage*>(buffer + sizeof(LibUiProtocol::WindowManagerMessage));

                    cb(::KeyUp, sizeof(pKeyEvent->key), &pKeyEvent->key);
                    break;
                }
                case LibUiProtocol::Focus:
                    cb(::Focus, 0, 0);
                    break;
                case LibUiProtocol::NoFocus:
                    cb(::NoFocus, 0, 0);
                    break;
                default:
                    syslog(LOG_INFO, "** unknown event");
            }
        }

        if(pMessage)
        {
            delete pMessage;
        }
    }
}
