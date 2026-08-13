/*  GNU SED, a batch stream editor.
    Copyright (C) 1998-2026 Free Software Foundation, Inc.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2, or (at your option)
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <https://www.gnu.org/licenses/>. */

#ifndef BASICDEFS_H
#define BASICDEFS_H

#include <wchar.h>
#include <locale.h>
#include <wctype.h>
#include <stdbool.h>

#include <gettext.h>
#define _(String) gettext(String)

#include "idx.h"
#include "xalloc.h"

#define obstack_chunk_alloc  xzalloc
#define obstack_chunk_free   free

/* MAX_PATH is not defined in some platforms, most notably GNU/Hurd.
   In that case we define it here to some constant.  Note however that
   this relies in the fact that sed does reallocation if a buffer
   needs to be larger than PATH_MAX.  */
#ifndef PATH_MAX
# define PATH_MAX 200
#endif

/* handle misdesigned <ctype.h> macros (snarfed from lib/regex.c) */
/* Jim Meyering writes:

   "... Some ctype macros are valid only for character codes that
   isascii says are ASCII (SGI's IRIX-4.0.5 is one such system --when
   using /bin/cc or gcc but without giving an ansi option)....  If
   STDC_HEADERS is defined, then autoconf has verified that the ctype
   macros don't need to be guarded with references to isascii. ...
   Defining isascii to 1 should let any compiler worth its salt
   eliminate the && through constant folding."
   Solaris defines some of these symbols so we must undefine them first. */

#undef ISASCII
#if defined STDC_HEADERS || (!defined isascii && !defined HAVE_ISASCII)
# define ISASCII(c) 1
#else
# define ISASCII(c) isascii(c)
#endif

#if defined isblank || defined HAVE_ISBLANK
# define ISBLANK(c) (ISASCII (c) && isblank (c))
#else
# define ISBLANK(c) ((c) == ' ' || (c) == '\t')
#endif

#define ISSPACE(c) (ISASCII (c) && isspace (c))

#ifndef initialize_main
# ifdef __EMX__
#  define initialize_main(argcp, argvp) \
  { _response (argcp, argvp); _wildcard (argcp, argvp); }
# else /* NOT __EMX__ */
#  define initialize_main(argcp, argvp)
# endif
#endif

#endif /*!BASICDEFS_H*/
