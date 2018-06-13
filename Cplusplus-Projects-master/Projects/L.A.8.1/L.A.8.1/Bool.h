/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 */

#ifndef BOOL_H
#define BOOL_H

#define bool int

#if defined(false)
  #if false != 0
    #error Incompatible 'false' already #defined
  #endif
#else
  #define false 0
#endif

#if defined(true)
  #if true != 1
    #error Incompatible 'true' already #defined
  #endif
#else
  #define true 1
#endif

#endif /* BOOL_H */
