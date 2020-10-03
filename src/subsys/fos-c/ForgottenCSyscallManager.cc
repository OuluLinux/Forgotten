/*
* Copyright (c) 2008 James Molloy, Jörg Pfähler, Matthew Iselin
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

#include <processor/SyscallManager.h>
#include <processor/Processor.h>
#include <process/Scheduler.h>
#include <Log.h>

#include "ForgottenCSyscallManager.h"
#include "foscSyscallNumbers.h"

#define FORGOTTENC_WITHIN_KERNEL
#include "fos-syscalls.h"

ForgottenCSyscallManager::ForgottenCSyscallManager()
{
}

ForgottenCSyscallManager::~ForgottenCSyscallManager()
{
}

void ForgottenCSyscallManager::initialise()
{
    SyscallManager::instance().registerSyscallHandler(fos_c, this);
    fos_config_init();
}

uintptr_t ForgottenCSyscallManager::call(uintptr_t function, uintptr_t p1, uintptr_t p2, uintptr_t p3, uintptr_t p4, uintptr_t p5)
{
    if (function >= serviceEnd)
    {
        ERROR("ForgottenCSyscallManager: invalid function called: " << Dec << static_cast<int>(function));
        return 0;
    }
    return SyscallManager::instance().syscall(posix, function, p1, p2, p3, p4, p5);
}

uintptr_t ForgottenCSyscallManager::syscall(SyscallState &state)
{
    uintptr_t p1 = state.getSyscallParameter(0);
    uintptr_t p2 = state.getSyscallParameter(1);
    uintptr_t p3 = state.getSyscallParameter(2);
    uintptr_t p4 = state.getSyscallParameter(3);
    uintptr_t p5 = state.getSyscallParameter(4);

    // We're interruptible.
    Processor::setInterrupts(true);

    switch (state.getSyscallNumber())
    {
        // Forgotten system calls, called from POSIX applications
        case FORGOTTEN_LOGIN:
            return fos_login(static_cast<int>(p1), reinterpret_cast<const char *>(p2));
        case FORGOTTEN_LOAD_KEYMAP:
            return fos_load_keymap(reinterpret_cast<char*>(p1), static_cast<size_t>(p2));
        case FORGOTTEN_GET_MOUNT:
            return fos_get_mount(reinterpret_cast<char*>(p1), reinterpret_cast<char*>(p2), static_cast<size_t>(p3));
        case FORGOTTEN_REBOOT:
            fos_reboot();
            return 0;
        case FORGOTTEN_CONFIG_GETCOLNAME:
            fos_config_getcolname(p1, p2, reinterpret_cast<char*>(p3), p4);
            return 0;
        case FORGOTTEN_CONFIG_GETSTR_N:
            fos_config_getstr(p1, p2, p3, reinterpret_cast<char*>(p4), p5);
            return 0;
        case FORGOTTEN_CONFIG_GETSTR_S:
            fos_config_getstr(p1, p2, reinterpret_cast<const char*>(p3), reinterpret_cast<char*>(p4), p5);
            return 0;
        case FORGOTTEN_CONFIG_GETNUM_N:
            return fos_config_getnum(p1, p2, p3);
        case FORGOTTEN_CONFIG_GETNUM_S:
            return fos_config_getnum(p1, p2, reinterpret_cast<const char*>(p3));
        case FORGOTTEN_CONFIG_GETBOOL_N:
            return fos_config_getbool(p1, p2, p3);
        case FORGOTTEN_CONFIG_GETBOOL_S:
            return fos_config_getbool(p1, p2, reinterpret_cast<const char*>(p3));
        case FORGOTTEN_CONFIG_QUERY:
            return fos_config_query(reinterpret_cast<const char*>(p1));
        case FORGOTTEN_CONFIG_FREERESULT:
            fos_config_freeresult(p1);
            return 0;
        case FORGOTTEN_CONFIG_NUMCOLS:
            return fos_config_numcols(p1);
        case FORGOTTEN_CONFIG_NUMROWS:
            return fos_config_numrows(p1);
        case FORGOTTEN_CONFIG_WAS_SUCCESSFUL:
            return fos_config_was_successful(p1);
        case FORGOTTEN_CONFIG_GET_ERROR_MESSAGE:
            fos_config_get_error_message(p1, reinterpret_cast<char*>(p2), p3);
            return 0;
        case FORGOTTEN_MODULE_LOAD:
            fos_module_load(reinterpret_cast<char*>(p1));
            return 0;
        case FORGOTTEN_MODULE_UNLOAD:
            fos_module_unload(reinterpret_cast<char*>(p1));
            return 0;
        case FORGOTTEN_MODULE_IS_LOADED:
            return fos_module_is_loaded(reinterpret_cast<char*>(p1));
        case FORGOTTEN_MODULE_GET_DEPENDING:
            return fos_module_get_depending(reinterpret_cast<char*>(p1), reinterpret_cast<char*>(p2), p3);
        case FORGOTTEN_GFX_GET_PROVIDER:
            return fos_gfx_get_provider(reinterpret_cast<void*>(p1));
        case FORGOTTEN_GFX_GET_CURR_MODE:
            return fos_gfx_get_curr_mode(reinterpret_cast<void*>(p1), reinterpret_cast<void*>(p2));
        case FORGOTTEN_GFX_GET_RAW_BUFFER:
            return fos_gfx_get_raw_buffer(reinterpret_cast<void*>(p1));
        case FORGOTTEN_GFX_CREATE_BUFFER:
            return fos_gfx_create_buffer(reinterpret_cast<void*>(p1), reinterpret_cast<void**>(p2), reinterpret_cast<void*>(p3));
        case FORGOTTEN_GFX_DESTROY_BUFFER:
            return fos_gfx_destroy_buffer(reinterpret_cast<void*>(p1), reinterpret_cast<void*>(p2));
        case FORGOTTEN_GFX_REDRAW:
            fos_gfx_redraw(reinterpret_cast<void*>(p1), reinterpret_cast<void*>(p2));
            return 0;
        case FORGOTTEN_GFX_BLIT:
            fos_gfx_blit(reinterpret_cast<void*>(p1), reinterpret_cast<void*>(p2));
            return 0;
        case FORGOTTEN_GFX_SET_PIXEL:
            fos_gfx_set_pixel(reinterpret_cast<void*>(p1), p2, p3, p4, p5);
            return 0;
        case FORGOTTEN_GFX_RECT:
            fos_gfx_rect(reinterpret_cast<void*>(p1), reinterpret_cast<void*>(p2));
            return 0;
        case FORGOTTEN_GFX_COPY:
            fos_gfx_copy(reinterpret_cast<void*>(p1), reinterpret_cast<void*>(p2));
            return 0;
        case FORGOTTEN_GFX_LINE:
            fos_gfx_line(reinterpret_cast<void*>(p1), reinterpret_cast<void*>(p2));
            return 0;
        case FORGOTTEN_GFX_DRAW:
            fos_gfx_draw(reinterpret_cast<void*>(p1), reinterpret_cast<void*>(p2));
            return 0;
        case FORGOTTEN_GFX_CREATE_FBUFFER:
            return fos_gfx_create_fbuffer(reinterpret_cast<void*>(p1), reinterpret_cast<void*>(p2));
        case FORGOTTEN_GFX_DELETE_FBUFFER:
            fos_gfx_delete_fbuffer(reinterpret_cast<void*>(p1));
            return 0;
        case FORGOTTEN_GFX_FBINFO:
            fos_gfx_fbinfo(reinterpret_cast<void*>(p1), reinterpret_cast<size_t*>(p2), reinterpret_cast<size_t*>(p3), reinterpret_cast<uint32_t*>(p4), reinterpret_cast<size_t*>(p5));
            return 0;
        case FORGOTTEN_GFX_SETPALETTE:
            fos_gfx_setpalette(reinterpret_cast<void*>(p1), reinterpret_cast<uint32_t*>(p2), static_cast<size_t>(p3));
            return 0;
        case FORGOTTEN_INPUT_INSTALL_CALLBACK:
            fos_input_install_callback(reinterpret_cast<void*>(p1), static_cast<uint32_t>(p2), static_cast<uintptr_t>(p3));
            return 0;
        case FORGOTTEN_INPUT_REMOVE_CALLBACK:
            fos_input_remove_callback(reinterpret_cast<void*>(p1));
            return 0;
        case FORGOTTEN_EVENT_RETURN:
            fos_event_return();
            return 0;
        case FORGOTTEN_SYS_REQUEST_MEM:
            return reinterpret_cast<uintptr_t>(fos_sys_request_mem(static_cast<size_t>(p1)));
        default: ERROR ("ForgottenCSyscallManager: invalid syscall received: " << Dec << state.getSyscallNumber()); return 0;
    }
}
