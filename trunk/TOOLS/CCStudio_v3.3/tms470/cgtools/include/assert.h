/*****************************************************************************/
/* assert.h   v4.6.6                                                         */
/* Copyright (c) 1993-2011 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _ASSERT
#define _ASSERT

#include <linkage.h>

/*---------------------------------------------------------------------------*/
/* A header file conforming to ARM CLIB ABI (GENC-003539), should            */
/* define _AEABI_PORTABLE when _AEABI_PORTABILITY_LEVEL is defined.          */
/*---------------------------------------------------------------------------*/
#if defined(_AEABI_PORTABILITY_LEVEL) && !defined(_AEABI_PORTABLE)
#define _AEABI_PORTABLE
#endif

/*---------------------------------------------------------------------------*/
/* The macro definition that guards CLIB ABI (GENC-003539) requirements.     */
/*---------------------------------------------------------------------------*/
#if defined(__TI_EABI_SUPPORT__)
#define _AEABI_PORTABILITY_CHECK (defined(__TMS470__) && \
	                          defined(__TI_EABI_SUPPORT__) && \
	                          _AEABI_PORTABILITY_LEVEL != 0)
#else
#define _AEABI_PORTABILITY_CHECK 0
#endif

#ifdef __cplusplus
//----------------------------------------------------------------------------
// <cassert> IS RECOMMENDED OVER <assert.h>.  <assert.h> IS PROVIDED FOR
// COMPATIBILITY WITH C AND THIS USAGE IS DEPRECATED IN C++
//----------------------------------------------------------------------------

#define _NAMESPACE_PREFIX std::

extern "C" namespace std
{
#else
#define _NAMESPACE_PREFIX
#endif

/* this #ifndef can go away when C2000 uses extern C builtins */
extern _CODE_ACCESS void _nassert(int);
extern _CODE_ACCESS void _assert(int, const char *);

extern _CODE_ACCESS void _abort_msg(const char *);

#define _STR(x)  __STR(x)
#define __STR(x) #x

#if defined(NDEBUG)
#define assert(_ignore) ((void)0)
#elif defined(NASSERT)
#define assert(_expr)   _NAMESPACE_PREFIX _nassert(_expr)
#else
#if _AEABI_PORTABILITY_CHECK
     extern void __aeabi_assert(const char *expr, const char *file, int line);
     #define assert(__e) ((__e) ? (void)0 : \
	        _NAMESPACE_PREFIX __aeabi_assert(#__e, __FILE__, __LINE__))
#else /* _AEABI_PORTABILITY_CHECK */
     #define assert(_expr)   _NAMESPACE_PREFIX _assert((_expr) != 0,      \
                    "Assertion failed, (" _STR(_expr) "), file " __FILE__ \
                    ", line " _STR(__LINE__) "\n")
#endif /* _AEABI_PORTABILITY_CHECK */
#endif /* NDEBUG, NASSERT */

#ifdef __cplusplus
} /* extern "C" namespace std */
#endif /* __cplusplus */

#endif /* _ASSERT */

#if defined(__cplusplus) && !defined(_CPP_STYLE_HEADER)
using std::_nassert;

#if _AEABI_PORTABILITY_CHECK
using std::__aeabi_assert;
#endif /* __TMS470__ etc */

#endif /* _CPP_STYLE_HEADER */

