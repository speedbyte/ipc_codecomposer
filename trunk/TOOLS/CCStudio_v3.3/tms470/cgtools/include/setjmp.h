/*****************************************************************************/
/* setjmp.h   v4.6.6                                                         */
/* Copyright (c) 1993-2011 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _SETJMP
#define _SETJMP

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
extern "C" namespace std {
#endif

#if defined(__TMS470__) && defined(__TI_EABI_SUPPORT__)
    #define setjmp(x) setjmp(x)
#else
    #define setjmp(x) _setjmp(x)
#endif

   #if defined(__TI_EABI_SUPPORT__)
      #if _AEABI_PORTABILITY_LEVEL != 0 
        typedef long long jmp_buf[];
        extern const int __aeabi_JMP_BUF_SIZE;
      #else
        typedef long long jmp_buf[13]; 
      #endif /* _AEABI_PORTABILITY_LEVEL != 0 */
   #else
        typedef long long jmp_buf[13]; 
   #endif /* __TI_EABI_SUPPORT__ */

   #if defined(__EDG_JMP_BUF_NUM_ELEMENTS)
      #if __EDG_JMP_BUF_NUM_ELEMENTS != 13
         #error "Front end and runtime disagree on size of jmp_buf"
      #endif
   #endif

#if defined(__TMS470__) && defined(__TI_EABI_SUPPORT__)
_CODE_ACCESS int  setjmp(jmp_buf env); 
#else
_CODE_ACCESS int  _setjmp(jmp_buf env); 
#endif

_CODE_ACCESS void longjmp(jmp_buf env, int val);


#ifdef __cplusplus
} /* extern "C" namespace std */
#endif /* __cplusplus */

#endif /* _SETJMP */

#if defined(__cplusplus) && !defined(_CPP_STYLE_HEADER)
using std::jmp_buf;
#if defined(__TMS470__) && defined(__TI_EABI_SUPPORT__)
using std::setjmp;
#else
using std::_setjmp;
#endif
using std::longjmp;
#if _AEABI_PORTABILITY_CHECK
using std::__aeabi_JMP_BUF_SIZE;
#endif
#endif /* _CPP_STYLE_HEADER */


