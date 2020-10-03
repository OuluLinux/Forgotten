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

#include "foscSyscallNumbers.h"

#include "fos-c-syscall.h"

#include <processor/types.h>
#include <fos_config.h>

#include <stdlib.h>
#include <unistd.h>

// These are provided by libc
void *malloc(size_t);
size_t strlen(const char *);

int fos_load_keymap(char *buf, size_t sz)
{
    return syscall2(FORGOTTEN_LOAD_KEYMAP, (long)buf, (long)sz);
}

void fos_reboot()
{
    syscall0(FORGOTTEN_REBOOT);
}

int fos_get_mount(char* mount_buf, char* info_buf, size_t n)
{
    return syscall3(FORGOTTEN_GET_MOUNT, (long) mount_buf, (long) info_buf, n);
}

void *fos_sys_request_mem(size_t len) {
    return (void *) syscall1(FORGOTTEN_SYS_REQUEST_MEM, (long) len);
}

void fos_input_install_callback(void *p, uint32_t type, uintptr_t param)
{
    syscall3(FORGOTTEN_INPUT_INSTALL_CALLBACK, (long) p, type, param);
}

void fos_input_remove_callback(void *p)
{
    syscall1(FORGOTTEN_INPUT_REMOVE_CALLBACK, (long) p);
}

void fos_event_return()
{
    syscall0(FORGOTTEN_EVENT_RETURN);
}

void fos_module_load(char *file)
{
    syscall1(FORGOTTEN_MODULE_LOAD, (long)file);
}

void fos_module_unload(char *name)
{
    syscall1(FORGOTTEN_MODULE_UNLOAD, (long)name);
}

int fos_module_is_loaded(char *name)
{
    return syscall1(FORGOTTEN_MODULE_IS_LOADED, (long)name);
}

int fos_module_get_depending(char *name, char *buf, size_t bufsz)
{
    return syscall3(FORGOTTEN_MODULE_GET_DEPENDING, (long)name, (long)buf, bufsz);
}

void fos_config_getcolname(size_t resultIdx, size_t n, char *buf, size_t bufsz)
{
    syscall4(FORGOTTEN_CONFIG_GETCOLNAME, resultIdx, n, (long)buf, bufsz);
}

void fos_config_getstr_n(size_t resultIdx, size_t row, size_t n, char *buf, size_t bufsz)
{
    syscall5(FORGOTTEN_CONFIG_GETSTR_N, resultIdx, row, n, (long)buf, bufsz);
}
void fos_config_getstr_s(size_t resultIdx, size_t row, const char *col, char *buf, size_t bufsz)
{
    syscall5(FORGOTTEN_CONFIG_GETSTR_S, resultIdx, row, (long)col, (long)buf, bufsz);
}

int fos_config_getnum_n(size_t resultIdx, size_t row, size_t n)
{
    return syscall3(FORGOTTEN_CONFIG_GETNUM_N, row, resultIdx, n);
}
int fos_config_getnum_s(size_t resultIdx, size_t row, const char *col)
{
    return syscall3(FORGOTTEN_CONFIG_GETNUM_S, row, resultIdx, (long)col);
}

int fos_config_getbool_n(size_t resultIdx, size_t row, size_t n)
{
    return syscall3(FORGOTTEN_CONFIG_GETBOOL_N, resultIdx, row, n);
}
int fos_config_getbool_s(size_t resultIdx, size_t row, const char *col)
{
    return syscall3(FORGOTTEN_CONFIG_GETBOOL_S, resultIdx, row, (long)col);
}

int fos_config_query(const char *query)
{
    return syscall1(FORGOTTEN_CONFIG_QUERY, (long)query);
}

void fos_config_freeresult(size_t resultIdx)
{
    syscall1(FORGOTTEN_CONFIG_FREERESULT, resultIdx);
}

int fos_config_numcols(size_t resultIdx)
{
    return syscall1(FORGOTTEN_CONFIG_NUMCOLS, resultIdx);
}

int fos_config_numrows(size_t resultIdx)
{
    return syscall1(FORGOTTEN_CONFIG_NUMROWS, resultIdx);
}

int fos_config_was_successful(size_t resultIdx)
{
    return syscall1(FORGOTTEN_CONFIG_WAS_SUCCESSFUL, resultIdx);
}

void fos_config_get_error_message(size_t resultIdx, char *buf, int bufsz)
{
    syscall3(FORGOTTEN_CONFIG_GET_ERROR_MESSAGE, resultIdx, (long)buf, bufsz);
}

char *fos_config_escape_string(const char *str)
{
    // Expect the worst: every char needs to be escaped
    char *bufferStart = (char*)malloc(strlen(str) * 2 + 1);
    char *buffer = bufferStart;
    while(*str)
    {
        if(*str == '\'')
        {
            *buffer++ = '\'';
            *buffer++ = '\'';
        }
        else
            *buffer++ = *str;

        str++;
    }
    *buffer = '\0';

    // Reallocate so we won't use more space than we need
    bufferStart = realloc(bufferStart, strlen(bufferStart) + 1);

    return bufferStart;
}

// Forgotten-specific function: login with given uid and password.
int login(uid_t uid, char *password)
{
    return (long)syscall2(FORGOTTEN_LOGIN, uid, (long)password);
}

int fos_gfx_get_provider(void *p)
{
    return syscall1(FORGOTTEN_GFX_GET_PROVIDER, (long) p);
}

int fos_gfx_get_curr_mode(void *p, void *sm)
{
    return syscall2(FORGOTTEN_GFX_GET_CURR_MODE, (long) p, (long) sm);
}

uintptr_t fos_gfx_get_raw_buffer(void *p)
{
    return (uintptr_t) syscall1(FORGOTTEN_GFX_GET_RAW_BUFFER, (long) p);
}

int fos_gfx_create_buffer(void *p, void **b, void *args)
{
    return syscall3(FORGOTTEN_GFX_CREATE_BUFFER, (long) p, (long) b, (long) args);
}

int fos_gfx_destroy_buffer(void *p, void *b)
{
    return syscall2(FORGOTTEN_GFX_DESTROY_BUFFER, (long) p, (long) b);
}

void fos_gfx_redraw(void *p, void *args)
{
    syscall2(FORGOTTEN_GFX_REDRAW, (long) p, (long) args);
}

void fos_gfx_blit(void *p, void *args)
{
    syscall2(FORGOTTEN_GFX_BLIT, (long) p, (long) args);
}

void fos_gfx_set_pixel(void *p, uint32_t x, uint32_t y, uint32_t colour, uint32_t fmt)
{
    syscall5(FORGOTTEN_GFX_SET_PIXEL, (long) p, x, y, colour, fmt);
}

void fos_gfx_rect(void *p, void *args)
{
    syscall2(FORGOTTEN_GFX_RECT, (long) p, (long) args);
}

void fos_gfx_copy(void *p, void *args)
{
    syscall2(FORGOTTEN_GFX_COPY, (long) p, (long) args);
}

void fos_gfx_line(void *p, void *args)
{
    syscall2(FORGOTTEN_GFX_LINE, (long) p, (long) args);
}

void fos_gfx_draw(void *p, void *args)
{
    syscall2(FORGOTTEN_GFX_DRAW, (long) p, (long) args);
}

int fos_gfx_create_fbuffer(void *p, void *args)
{
    return syscall2(FORGOTTEN_GFX_CREATE_FBUFFER, (long) p, (long) args);
}

void fos_gfx_delete_fbuffer(void *p)
{
    syscall1(FORGOTTEN_GFX_DELETE_FBUFFER, (long) p);
}

void fos_gfx_fbinfo(void *p, size_t *w, size_t *h, uint32_t *fmt, size_t *bypp)
{
    syscall5(FORGOTTEN_GFX_FBINFO, (long) p, (long) w, (long) h, (long) fmt, (long) bypp);
}

void fos_gfx_setpalette(void* p, uint32_t *data, size_t entries)
{
    syscall3(FORGOTTEN_GFX_SETPALETTE, (long) p, (long) data, (long) entries);
}

