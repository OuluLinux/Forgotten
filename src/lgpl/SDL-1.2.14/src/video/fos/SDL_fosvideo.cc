/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2009 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Sam Lantinga
    slouken@libsdl.org
*/
#include "SDL_config.h"

#include "SDL_video.h"
#include "SDL_mouse.h"
#include "../SDL_sysvideo.h"
#include "../SDL_pixels_c.h"
#include "../../events/SDL_events_c.h"

#include "SDL_fosvideo.h"
#include "SDL_fosevents_c.h"
#include "SDL_fosmouse_c.h"

#include <graphics/Graphics.h>

#include <syslog.h>

#define FORGOTTENVID_DRIVER_NAME "fos"

extern "C"
{

/* Initialization/Query functions */
static int FORGOTTEN_VideoInit(_THIS, SDL_PixelFormat *vformat);
static SDL_Rect **FORGOTTEN_ListModes(_THIS, SDL_PixelFormat *format, Uint32 flags);
static SDL_Surface *FORGOTTEN_SetVideoMode(_THIS, SDL_Surface *current, int width, int height, int bpp, Uint32 flags);
static int FORGOTTEN_SetColors(_THIS, int firstcolor, int ncolors, SDL_Color *colors);
static void FORGOTTEN_VideoQuit(_THIS);

/* Hardware surface functions */
static int FORGOTTEN_AllocHWSurface(_THIS, SDL_Surface *surface);
static int FORGOTTEN_LockHWSurface(_THIS, SDL_Surface *surface);
static void FORGOTTEN_UnlockHWSurface(_THIS, SDL_Surface *surface);
static void FORGOTTEN_FreeHWSurface(_THIS, SDL_Surface *surface);

/* etc. */
static void FORGOTTEN_UpdateRects(_THIS, int numrects, SDL_Rect *rects);

};

/* FORGOTTEN driver bootstrap functions */

static int FORGOTTEN_Available(void)
{
    return 1;
}

static void FORGOTTEN_DeleteDevice(SDL_VideoDevice *device)
{
    FORGOTTEN_DestroyInput();
    
	SDL_free(device->hidden);
	SDL_free(device);
}

static SDL_VideoDevice *FORGOTTEN_CreateDevice(int devindex)
{
	SDL_VideoDevice *device;

	/* Initialize all variables that we clean on shutdown */
	device = (SDL_VideoDevice *)SDL_malloc(sizeof(SDL_VideoDevice));
	if ( device ) {
		SDL_memset(device, 0, (sizeof *device));
		device->hidden = (struct SDL_PrivateVideoData *)
				SDL_malloc((sizeof *device->hidden));
	}
	if ( (device == NULL) || (device->hidden == NULL) ) {
		SDL_OutOfMemory();
		if ( device ) {
			SDL_free(device);
		}
		return(0);
	}
	SDL_memset(device->hidden, 0, (sizeof *device->hidden));

	/* Set the function pointers */
	device->VideoInit = FORGOTTEN_VideoInit;
	device->ListModes = FORGOTTEN_ListModes;
	device->SetVideoMode = FORGOTTEN_SetVideoMode;
	device->CreateYUVOverlay = NULL;
	device->SetColors = FORGOTTEN_SetColors;
	device->UpdateRects = FORGOTTEN_UpdateRects;
	device->VideoQuit = FORGOTTEN_VideoQuit;
	device->AllocHWSurface = FORGOTTEN_AllocHWSurface;
	device->CheckHWBlit = NULL;
	device->FillHWRect = NULL;
	device->SetHWColorKey = NULL;
	device->SetHWAlpha = NULL;
	device->LockHWSurface = FORGOTTEN_LockHWSurface;
	device->UnlockHWSurface = FORGOTTEN_UnlockHWSurface;
	device->FlipHWSurface = NULL;
	device->FreeHWSurface = FORGOTTEN_FreeHWSurface;
	device->SetCaption = NULL;
	device->SetIcon = NULL;
	device->IconifyWindow = NULL;
	device->GrabInput = NULL;
	device->GetWMInfo = NULL;
	device->InitOSKeymap = FORGOTTEN_InitOSKeymap;
	device->PumpEvents = FORGOTTEN_PumpEvents;

	device->free = FORGOTTEN_DeleteDevice;

	return device;
}

VideoBootStrap FORGOTTEN_bootstrap = {
	FORGOTTENVID_DRIVER_NAME, "SDL fos video driver",
	FORGOTTEN_Available, FORGOTTEN_CreateDevice
};


int FORGOTTEN_VideoInit(_THIS, SDL_PixelFormat *vformat)
{
	// Default to 16 bpp
	vformat->BitsPerPixel = 16;
	vformat->BytesPerPixel = 2;

    // Bring up the input callbacks
    FORGOTTEN_InitInput();

	/* We're done! */
	return(0);
}

SDL_Rect **FORGOTTEN_ListModes(_THIS, SDL_PixelFormat *format, Uint32 flags)
{
    /// \todo Write?
   	return (SDL_Rect **) -1;
}

SDL_Surface *FORGOTTEN_SetVideoMode(_THIS, SDL_Surface *current,
				int width, int height, int bpp, Uint32 flags)
{
	if ( _this->hidden->buffer ) {
		SDL_free( _this->hidden->buffer );
	}

    syslog(LOG_INFO, "SetVideoMode(%d, %d, %d)", width, height, bpp);

    ForgottenGraphics::Framebuffer *pRootFramebuffer = new ForgottenGraphics::Framebuffer();
    ForgottenGraphics::Framebuffer *pFramebuffer = pRootFramebuffer->createChild(0, 0, width, height);
    if(!pFramebuffer->getRawBuffer())
    {
		_this->hidden->buffer = NULL;
		SDL_SetError("Couldn't get a framebuffer to use");
		return(NULL);
    }
    
    _this->hidden->provider = (void*) pFramebuffer;

	_this->hidden->buffer = SDL_malloc(width * height * (bpp / 8));
	if ( ! _this->hidden->buffer ) {
		SDL_SetError("Couldn't allocate buffer for requested mode");
		return(NULL);
	}

	SDL_memset(_this->hidden->buffer, 0, width * height * (bpp / 8));

	/* Allocate the new pixel format for the screen */
	if ( ! SDL_ReallocFormat(current, bpp, 0, 0, 0, 0) ) {
		SDL_free(_this->hidden->buffer);
		_this->hidden->buffer = NULL;
		SDL_SetError("Couldn't allocate new pixel format for requested mode");
		return(NULL);
	}

	/* Set up the new mode framebuffer */
	current->flags = (flags & SDL_FULLSCREEN) | SDL_HWPALETTE;
	_this->hidden->w = current->w = width;
	_this->hidden->h = current->h = height;
	current->pitch = current->w * (bpp / 8);
	current->pixels = _this->hidden->buffer;

	/* We're done */
	return(current);
}

/* We don't actually allow hardware surfaces other than the main one */
static int FORGOTTEN_AllocHWSurface(_THIS, SDL_Surface *surface)
{
	return(-1);
}
static void FORGOTTEN_FreeHWSurface(_THIS, SDL_Surface *surface)
{
	return;
}

/* We need to wait for vertical retrace on page flipped displays */
static int FORGOTTEN_LockHWSurface(_THIS, SDL_Surface *surface)
{
	return(0);
}

static void FORGOTTEN_UnlockHWSurface(_THIS, SDL_Surface *surface)
{
	return;
}

static void FORGOTTEN_UpdateRects(_THIS, int numrects, SDL_Rect *rects)
{
    if(!_this->hidden->provider)
        return;

    ForgottenGraphics::Framebuffer *pFramebuffer = reinterpret_cast<ForgottenGraphics::Framebuffer*>(_this->hidden->provider);
    
    ForgottenGraphics::PixelFormat format;
    if(_this->screen->format->BitsPerPixel == 32)
        format = ForgottenGraphics::Bits32_Rgb;
    else if(_this->screen->format->BitsPerPixel == 16)
        format = ForgottenGraphics::Bits16_Rgb565;
    else if(_this->screen->format->BitsPerPixel == 8)
        format = ForgottenGraphics::Bits8_Idx;
    else
        format = ForgottenGraphics::Bits24_Rgb;

    pFramebuffer->draw(_this->hidden->buffer, 0, 0, 0, 0, 800, 600, format);
    pFramebuffer->redraw(0, 0, 800, 600, true);
    return;

    for(int i = 0; i < numrects; i++)
    {
        syslog(LOG_INFO, "UpdateRects: redraw %dx%d [%dx%d]\n", rects[i].x, rects[i].y, rects[i].w, rects[i].h);
        pFramebuffer->draw(_this->hidden->buffer, rects[i].x, rects[i].y, rects[i].x, rects[i].y, rects[i].w, rects[i].h, format);
        pFramebuffer->redraw(rects[i].x, rects[i].y, rects[i].w, rects[i].h, true);
    }
}

int FORGOTTEN_SetColors(_THIS, int firstcolor, int ncolors, SDL_Color *colors)
{
    if(!_this->hidden->provider)
        return 0;

    ForgottenGraphics::Framebuffer *pFramebuffer = reinterpret_cast<ForgottenGraphics::Framebuffer*>(_this->hidden->provider);

    uint32_t *palette = new uint32_t[256];
    
    size_t n = 0;
    for(size_t i = firstcolor; i < (firstcolor + ncolors); i++)
    {
        palette[i] = ForgottenGraphics::createRgb(colors[n].r, colors[n].g, colors[n].b);
        n++;
    }
    
    pFramebuffer->setPalette(palette, 256);

    return 1;
}

/* Note:  If we are terminated, this could be called in the middle of
   another SDL video routine -- notably UpdateRects.
*/
void FORGOTTEN_VideoQuit(_THIS)
{
	if (_this->screen->pixels != NULL)
	{
		SDL_free(_this->screen->pixels);
		_this->screen->pixels = NULL;
	}
}

