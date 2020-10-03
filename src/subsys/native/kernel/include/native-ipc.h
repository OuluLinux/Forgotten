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
#define _NATIVE_IPC_API_H
#define _NATIVE_IPC_API_H

#include <types.h>
#include <ipc/Ipc.h>

/**
 * This file defines the system calls for IPC for the Native subsystem's
 * SyscallManager.
 */

/**
 * Creates a standard, < 4 KB IPC message and returns the address of its buffer.
 * \param pMessage Userspace message pointer to link to the created kernel message.
 */
uintptr_t createStandardMessage(ForgottenIpc::IpcMessage *pMessage);

/**
 * Creates a shared region of memory for IPC, and returns the address of its
 * buffer. Can either create a new region or copy an existing one.
 * \param pMessage Userspace message pointer to link to the created kernel one.
 * \param nBytes Size of the region to allocate.
 * \param handle A handle to an existing region to map into the current address space.
 */
uintptr_t createSharedMessage(ForgottenIpc::IpcMessage *pMessage, size_t nBytes, uintptr_t handle);

/**
 * Obtains the region handle for the given message, if one exists. Returns null
 * if no shared region exists. Must be called after createSharedMessage.
 */
void *getIpcSharedRegion(ForgottenIpc::IpcMessage *pMessage);

/**
 * Destroys the given message on the kernel side, freeing the memory related to
 * it for other messages to use.
 */
void destroyMessage(ForgottenIpc::IpcMessage *pMessage);

/**
 * Sends the given message to the given endpoint, optionally asynchronously.
 */
bool sendIpc(ForgottenIpc::IpcEndpoint *pEndpoint, ForgottenIpc::IpcMessage *pMessage, bool bAsync);

/**
 * First phase of receiving a message. Will return 0 if an error occurred or no
 * message is queued, otherwise will return a pointer to be passed to the
 * ForgottenIpc::SharedIpcMessage::SharedIpcMessage(void*) constructor.
 */
void *recvIpcPhase1(ForgottenIpc::IpcEndpoint *pEndpoint, bool bAsync);

/**
 * Second phase of receiving a message. To be called within the
 * ForgottenIpc::SharedIpcMessage::SharedIpcMessage(void*) constructor.
 * Takes a userspace pointer and a kernel message pointer (returned by recvPhase1)
 * and links them, then returns the buffer address for the message.
 */
uintptr_t recvIpcPhase2(ForgottenIpc::IpcMessage *pUserMessage, void *pMessage);

/**
 * Creates an endpoint with the given name, if one doesn't exist already.
 */
void createEndpoint(const char *name);

/**
 * Removes an endpoint with the given name.
 */
void removeEndpoint(const char *name);

/**
 * Gets a pointer to the endpoint with the given name.
 */
ForgottenIpc::IpcEndpoint *getEndpoint(const char *name);
