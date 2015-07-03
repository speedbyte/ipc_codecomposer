/*****************************************************************************/
/*  ERRNO.H  v4.6.6                                                          */
/*  Copyright (c) 1995-2011 Texas Instruments Incorporated                   */
/*****************************************************************************/

#ifndef _ERRNO
#define _ERRNO

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
// <cerrno> IS RECOMMENDED OVER <errno.h>.  <errno.h> IS PROVIDED FOR
// COMPATIBILITY WITH C AND THIS USAGE IS DEPRECATED IN C++
//----------------------------------------------------------------------------
extern "C" namespace std
{
#endif /* __cplusplus */

#include <linkage.h>

#if defined(__TMS470__) && defined(__TI_EABI_SUPPORT__) 
   #if _AEABI_PORTABILITY_LEVEL != 0 
    extern const int __aeabi_EDOM;
    extern const int __aeabi_ERANGE;
    extern const int __aeabi_EILSEQ;
    #define EDOM (__aeabi_EDOM)
    #define ERANGE (__aeabi_ERANGE)
    #define EILSEQ (__aeabi_EILSEQ)
    extern volatile int *__aeabi_errno_addr(void);
    #ifdef __cplusplus
      #define errno (* ::std::__aeabi_errno_addr())
    #else
      #define errno (* __aeabi_errno_addr())
    #endif

   #else
    extern _DATA_ACCESS int errno;
    #ifdef __cplusplus
      #define errno ::std::errno
    #else
      #define errno errno
    #endif
    #define EDOM   33
    #define ERANGE 34
    #define ENOENT 2
    #define EFPOS  152
    #define EILSEQ 88
   #endif

#else /* defined(__TMS470__) && defined(__TI_EABI_SUPPORT__) */

extern _DATA_ACCESS int errno;
#ifdef __cplusplus
  #define errno ::std::errno
#else
  #define errno errno
#endif

/*---------------------------------------------------------------------------*/
/* Change #defines for CLIB ABI conformance.                                 */
/*---------------------------------------------------------------------------*/

    #define EDOM   1
    #define ERANGE 2
    #define ENOENT 3
    #define EFPOS  5
    #define EILSEQ 6


#endif /* defined(__TMS470__) && defined(__TI_EABI_SUPPORT__) */

#ifdef __cplusplus
} /* extern "C" namespace std */
#endif /* __cplusplus */

#endif  /* _ERRNO */

#if defined(__cplusplus) && !defined(_CPP_STYLE_HEADER)

#if _AEABI_PORTABILITY_CHECK
using std::__aeabi_errno_addr;
using std::__aeabi_EDOM;
using std::__aeabi_ERANGE;
using std::__aeabi_EILSEQ;
#endif

#endif /* _CPP_STYLE_HEADER */

