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

#ifndef FORGOTTEN_SYSCALLS_H
#define FORGOTTEN_SYSCALLS_H

#ifndef FORGOTTEN_SYSCALLS_LIBC

#ifdef FORGOTTENC_WITHIN_KERNEL

#include <processor/types.h>

#if 1
#define P_NOTICE(x) NOTICE("[" << Dec << Processor::information().getCurrentThread()->getParent()->getId() << "]\t" << Hex << x)
#else
#define P_NOTICE(x)
#endif

#endif

#endif

/** Forgotten configuration manager system calls **/

void fos_config_init();

void fos_config_getcolname(size_t resultIdx, size_t n, char *buf, size_t bufsz);
#ifndef __cplusplus
void fos_config_getstr_n(size_t resultIdx, size_t row, size_t n, char *buf, size_t bufsz);
void fos_config_getstr_s(size_t resultIdx, size_t row, const char *col, char *buf, size_t bufsz);
int fos_config_getnum_n(size_t resultIdx, size_t row, size_t n);
int fos_config_getnum_s(size_t resultIdx, size_t row, const char *col);
int fos_config_getbool_n(size_t resultIdx, size_t row, size_t n);
int fos_config_getbool_s(size_t resultIdx, size_t row, const char *col);
#else
void fos_config_getstr(size_t resultIdx, size_t row, size_t n, char *buf, size_t bufsz);
void fos_config_getstr(size_t resultIdx, size_t row, const char *col, char *buf, size_t bufsz);
int fos_config_getnum(size_t resultIdx, size_t row, size_t n);
int fos_config_getnum(size_t resultIdx, size_t row, const char *col);
int fos_config_getbool(size_t resultIdx, size_t row, size_t n);
int fos_config_getbool(size_t resultIdx, size_t row, const char *col);
#endif

int fos_config_query(const char *query);
void fos_config_freeresult(size_t resultIdx);
int fos_config_numcols(size_t resultIdx);
int fos_config_numrows(size_t resultIdx);

int fos_config_was_successful(size_t resultIdx);
void fos_config_get_error_message(size_t resultIdx, char *buf, int buflen);

/** Forgotten generic system calls **/

int fos_login(int uid, const char *password);

int fos_reboot();

void fos_module_load(char *file);
void fos_module_unload(char *name);
int fos_module_is_loaded(char *name);
int fos_module_get_depending(char *name, char *buf, size_t bufsz);

int fos_get_mount(char* mount_buf, char* info_buf, size_t n);

void *fos_sys_request_mem(size_t len);

/** Forgotten graphics framework system calls */

#ifdef __cplusplus
extern "C" {
#endif

void fos_input_install_callback(void *p, uint32_t type, uintptr_t param);
void fos_input_remove_callback(void *p);
int fos_load_keymap(char *buffer, size_t len);

void fos_event_return();

int fos_gfx_get_provider(void *p);
int fos_gfx_get_curr_mode(void *p, void *sm);
uintptr_t fos_gfx_get_raw_buffer(void *p);
int fos_gfx_create_buffer(void *p, void **b, void *args);
int fos_gfx_destroy_buffer(void *p, void *b);
int fos_gfx_convert_pixel(void *p, uint32_t *in, uint32_t *out, uint32_t infmt, uint32_t outfmt);
void fos_gfx_redraw(void *p, void *args);
void fos_gfx_blit(void *p, void *args);
void fos_gfx_set_pixel(void *p, uint32_t x, uint32_t y, uint32_t colour, uint32_t fmt);
void fos_gfx_rect(void *p, void *args);
void fos_gfx_copy(void *p, void *args);
void fos_gfx_line(void *p, void *args);
void fos_gfx_draw(void *p, void *args);

int fos_gfx_create_fbuffer(void *p, void *args);
void fos_gfx_delete_fbuffer(void *p);

void fos_gfx_fbinfo(void *p, size_t *w, size_t *h, uint32_t *fmt, size_t *bypp);
void fos_gfx_setpalette(void* p, uint32_t *data, size_t entries);

#ifdef __cplusplus
}; // extern "C"
#endif

#endif

