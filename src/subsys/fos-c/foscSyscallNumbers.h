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

#ifndef SYSCALL_NUMBERS_H
#define SYSCALL_NUMBERS_H

#define FORGOTTEN_LOGIN                      1
#define FORGOTTEN_SIGRET                     2
#define FORGOTTEN_INIT_SIGRET                3
#define FORGOTTEN_INIT_PTHREADS              4
#define FORGOTTEN_LOAD_KEYMAP                5
#define FORGOTTEN_GET_MOUNT                  6
#define FORGOTTEN_REBOOT                     7

#define FORGOTTEN_CONFIG_GETCOLNAME          8
#define FORGOTTEN_CONFIG_GETSTR_N            9
#define FORGOTTEN_CONFIG_GETNUM_N            10
#define FORGOTTEN_CONFIG_GETBOOL_N           11
#define FORGOTTEN_CONFIG_GETSTR_S            12
#define FORGOTTEN_CONFIG_GETNUM_S            13
#define FORGOTTEN_CONFIG_GETBOOL_S           14
#define FORGOTTEN_CONFIG_QUERY               15
#define FORGOTTEN_CONFIG_FREERESULT          16
#define FORGOTTEN_CONFIG_NUMCOLS             17
#define FORGOTTEN_CONFIG_NUMROWS             18
#define FORGOTTEN_CONFIG_WAS_SUCCESSFUL      19
#define FORGOTTEN_CONFIG_GET_ERROR_MESSAGE   20

#define FORGOTTEN_MODULE_LOAD                21
#define FORGOTTEN_MODULE_UNLOAD              22
#define FORGOTTEN_MODULE_IS_LOADED           23
#define FORGOTTEN_MODULE_GET_DEPENDING       24

#define FORGOTTEN_INPUT_INSTALL_CALLBACK     25
#define FORGOTTEN_INPUT_REMOVE_CALLBACK      26

#define FORGOTTEN_SYS_REQUEST_MEM            27

#define FORGOTTEN_EVENT_RETURN               60

#define FORGOTTEN_GFX_GET_PROVIDER           64
#define FORGOTTEN_GFX_GET_CURR_MODE          65
#define FORGOTTEN_GFX_GET_RAW_BUFFER         66
#define FORGOTTEN_GFX_CREATE_BUFFER          67
#define FORGOTTEN_GFX_DESTROY_BUFFER         68
#define FORGOTTEN_GFX_REDRAW                 69
#define FORGOTTEN_GFX_BLIT                   70
#define FORGOTTEN_GFX_RECT                   71
#define FORGOTTEN_GFX_COPY                   72
#define FORGOTTEN_GFX_LINE                   73
#define FORGOTTEN_GFX_SET_PIXEL              74
#define FORGOTTEN_GFX_DRAW                   75
#define FORGOTTEN_GFX_CREATE_FBUFFER         76
#define FORGOTTEN_GFX_DELETE_FBUFFER         77
#define FORGOTTEN_GFX_FBINFO                 78
#define FORGOTTEN_GFX_SETPALETTE             79

#endif
