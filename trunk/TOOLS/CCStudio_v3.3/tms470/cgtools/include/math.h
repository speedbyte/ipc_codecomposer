/*****************************************************************************/
/* math.h     v4.6.6                                                         */
/* Copyright (c) 1996-2011 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _MATH
#define _MATH

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
#if defined(__TMS470__) && defined(__TI_EABI_SUPPORT__)
#define _AEABI_PORTABILITY_CHECK (defined(__TMS470__) && \
	                          defined(__TI_EABI_SUPPORT__) && \
	                          _AEABI_PORTABILITY_LEVEL != 0)
#else
#define _AEABI_PORTABILITY_CHECK 0
#endif


#include <float.h>

#if _AEABI_PORTABILITY_CHECK
    extern const double      __aeabi_HUGE_VAL;
    extern const long double __aeabi_HUGE_VALL;
    #define HUGE_VAL  (__aeabi_HUGE_VAL)
    #define HUGE_VALL (__aeabi_HUGE_VALL)
#else /* __TI_EABI_SUPPORT__ */
    #define HUGE_VAL   DBL_MAX
    #define HUGE_VALL  LDBL_MAX
#endif /* defined(__TI_EABI_SUPPORT__) */

#ifdef __cplusplus
//----------------------------------------------------------------------------
// <cmath> IS RECOMMENDED OVER <math.h>.  <math.h> IS PROVIDED FOR 
// COMPATIBILITY WITH C AND THIS USAGE IS DEPRECATED IN C++
//----------------------------------------------------------------------------
extern "C" namespace std {
#endif /* !__cplusplus */

/***************************************************************/
/* FUNCTION DEFINITIONS.                                       */
/***************************************************************/
        double modf(double x, double *y); 
        double asin(double x);
        double acos(double x);
        double atan(double x);
        double atan2(double y, double x);
#if defined(_OPTIMIZE_FOR_SPACE) && defined(__TMS470__)
        double ceil(double x);
#else
  _IDECL double ceil(double x);
#endif
        double cos(double x);
        double cosh(double x);
        double exp(double x);
        double fabs(double x);
#if defined(_OPTIMIZE_FOR_SPACE) && defined(__TMS470__)
        double floor(double x);
#else
  _IDECL double floor(double x);
#endif
         double fmod(double x, double y);
         double frexp(double x, int *exp);
         double ldexp(double x, int exp);
         double log(double x);
         double log10(double x);
         double pow(double x, double y);
         double sin(double x);
         double sinh(double x);
         double tan(double x);
         double tanh(double x);
         double sqrt(double x);

#if defined(_CEIL) ||						\
    (defined(_INLINE) && 					\
     !(defined(_OPTIMIZE_FOR_SPACE) && defined(__TMS470__)))
#if defined(_OPTIMIZE_FOR_SPACE) && defined(__TMS470__)
       double ceil(double x)
#else
_IDEFN double ceil(double x)
#endif
{
     double y; 
     return (modf(x, &y) > 0 ? y + 1.0 : y);
}
#endif /* (_CEIL || (_INLINE && !(_OPTIMIZE_FOR_SPACE && __TMS470))) */

#if defined(_FLOOR) ||						\
    (defined(_INLINE) && 					\
     !(defined(_OPTIMIZE_FOR_SPACE) && defined(__TMS470__)))
#if defined(_OPTIMIZE_FOR_SPACE) && defined(__TMS470__)
    double floor(double x)
#else
_IDEFN double floor(double x)
#endif
{
     double y; 
     return (modf(x, &y) < 0 ? y - 1.0 : y);
}
#endif /* (_FLOOR || (_INLINE && !(_OPTIMIZE_FOR_SPACE && __TMS470))) */
#ifdef __cplusplus
} /* extern "C" namespace std */
#endif /* __cplusplus */

/*******************************************************************************/
/* Overloaded version of math functions for float and long double in C++       */
/*******************************************************************************/
#endif /* _MATH */

#if defined(__cplusplus) && !defined(_CPP_STYLE_HEADER)
using std::modf;
using std::asin;
using std::acos;
using std::atan;
using std::atan2;
using std::ceil;
using std::cos;
using std::cosh;
using std::exp;
using std::fabs;
using std::floor;
using std::fmod;
using std::frexp;
using std::ldexp;
using std::log;
using std::log10;
using std::pow;
using std::sin;
using std::sinh;
using std::tan;
using std::tanh;
using std::sqrt;
#endif /* ! _CPP_STYLE_HEADER */
