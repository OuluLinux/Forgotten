#!/usr/bin/perl

#
# Copyright (c) 2008 James Molloy, James Pritchett, Jörg Pfähler, Matthew Iselin
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#

use strict;
use warnings;

my $libc = shift @ARGV;
my $libm = shift @ARGV;
my $glue = shift @ARGV;
my $include = shift @ARGV;
my $ld = shift @ARGV;
my $ar = shift @ARGV;
my $binary_dir = shift @ARGV;
my $libgcc = shift @ARGV;

`mkdir -p /tmp/fos-tmp`;
`cp $libc /tmp/fos-tmp/libc.a`;
`cd /tmp/fos-tmp; $ar x /tmp/fos-tmp/libc.a`;
`rm /tmp/fos-tmp/libc.a`;
`cp $glue /tmp/fos-tmp`;
`rm /tmp/fos-tmp/lib_a-init.o`; # We don't want this in the .so - it contains shite that references hidden symbols that is never used.
`rm /tmp/fos-tmp/lib_a-getpwent.o`; # We implement this functionality.
`rm /tmp/fos-tmp/lib_a-signal.o`; # We implement signals
# `rm /tmp/fos-tmp/lib_a-fseek.o`; # We reimplement fseek
`rm /tmp/fos-tmp/lib_a-getcwd.o`;
`rm /tmp/fos-tmp/lib_a-rename.o`;
`rm /tmp/fos-tmp/lib_a-rewinddir.o`;
`rm /tmp/fos-tmp/lib_a-opendir.o`;
`rm /tmp/fos-tmp/lib_a-readdir.o`;
`rm /tmp/fos-tmp/lib_a-closedir.o`;
`rm /tmp/fos-tmp/lib_a-_isatty.o`;
`rm /tmp/fos-tmp/lib_a-fseek.o`;
`$ld -nostdlib -shared  -Wl,-shared -Wl,-soname,libc.so -L$libgcc -o $binary_dir/libc.so /tmp/fos-tmp/*.o -lgcc`;
`cd /tmp/fos-tmp; $ar cru libc.a *.o`;
`cp /tmp/fos-tmp/libc.a $binary_dir/libc.a`;
`rm -rf /tmp/fos-tmp/*`;
`cp $libm /tmp/fos-tmp/libm.a`;
`cd /tmp/fos-tmp; $ar x /tmp/fos-tmp/libm.a`;
`rm /tmp/fos-tmp/libm.a`;
`$ld -nostdlib -Wl,-shared -Wl,-soname,libm.so -L$libgcc -o $binary_dir/libm.so /tmp/fos-tmp/*.o -lgcc`;
`cp $libm $binary_dir/libm.a`;
`rm -rf /tmp/fos-tmp`;
`rm -rf $binary_dir/include-posix`;
`cp -r $include $binary_dir/include-posix`;
