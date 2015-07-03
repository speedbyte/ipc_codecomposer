/*****************************************************************************/
/* limits.h   v4.6.6                                                         */
/* Copyright (c) 1996-2011 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _LIMITS
#define _LIMITS

/*---------------------------------------------------------------------------*/
/* A header file conforming to ARM CLIB ABI (GENC-003539), should            */
/* define _AEABI_PORTABLE when _AEABI_PORTABILITY_LEVEL is defined.          */
/*---------------------------------------------------------------------------*/
#if defined(_AEABI_PORTABILITY_LEVEL) && !defined(_AEABI_PORTABLE)
#define _AEABI_PORTABLE
#endif

#if defined(__TI_EABI_SUPPORT__) 
   #if _AEABI_PORTABILITY_LEVEL != 0
       extern const int __aeabi_MB_LEN_MAX;
       #define MB_LEN_MAX (__aeabi_MB_LEN_MAX)
   #else
       #define MB_LEN_MAX               8    /* MAX # BYTES IN MULTI-BYTE    */
   #endif
#else /* defined(__TI_EABI_SUPPORT__) */
#define MB_LEN_MAX               1    /* MAX # BYTES IN MULTI-BYTE    */
#endif /* defined(__TI_EABI_SUPPORT__) */

#define CHAR_BIT                 8    /* NUMBER OF BITS IN TYPE CHAR  */
#define SCHAR_MIN             -128    /* MIN VALUE FOR SIGNED CHAR    */
#define SCHAR_MAX              127    /* MAX VALUE FOR SIGNED CHAR    */
#define UCHAR_MAX              255    /* MAX VALUE FOR UNSIGNED CHAR  */

#ifdef __signed_chars__
#define CHAR_MIN         SCHAR_MIN    /* MIN VALUE FOR CHAR           */
#define CHAR_MAX         SCHAR_MAX    /* MAX VALUE FOR CHAR           */
#else
#define CHAR_MIN                 0
#define CHAR_MAX         UCHAR_MAX
#endif
 
#define SHRT_MIN            -32768    /* MIN VALUE FOR SHORT          */
#define SHRT_MAX             32767    /* MAX VALUE FOR SHORT          */
#define USHRT_MAX            65535    /* MAX VALUE FOR UNSIGNED SHORT */

#define INT_MIN         (-INT_MAX-1)  /* MIN VALUE FOR INT            */
#define INT_MAX         2147483647    /* MAX VALUE FOR INT            */
#define UINT_MAX        4294967295    /* MAX VALUE FOR UNSIGNED INT   */

#define LONG_MIN        (-LONG_MAX-1) /* MIN VALUE FOR LONG           */
#define LONG_MAX        2147483647    /* MAX VALUE FOR LONG           */
#define ULONG_MAX       4294967295    /* MAX VALUE FOR UNSIGNED LONG  */

#define LLONG_MIN         (-LLONG_MAX-1) /* MIN VALUE FOR LONG LONG          */
#define LLONG_MAX    9223372036854775807 /* MAX VALUE FOR LONG LONG          */
#define ULLONG_MAX  18446744073709551615 /* MAX VALUE FOR UNSIGNED LONG LONG */

#endif
