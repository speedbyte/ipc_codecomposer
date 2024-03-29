/*****************************************************************************/
/* time.h     v4.6.6                                                         */
/* Copyright (c) 1990-2011  Texas Instruments Incorporated                   */
/*****************************************************************************/

#ifndef _TIME
#define _TIME

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

  #if _AEABI_PORTABILITY_CHECK
     extern const int __aeabi_CLOCKS_PER_SEC;
     #define CLOCKS_PER_SEC (__aeabi_CLOCKS_PER_SEC)
  #else
     #define CLOCKS_PER_SEC 1000
  #endif /* defined(__TI_EABI_SUPPORT__) */

#ifndef NULL
#define NULL      0
#endif

#ifdef __cplusplus
extern "C" namespace std {
#endif

typedef unsigned int clock_t;
typedef unsigned int time_t;

#ifndef _SIZE_T
#define _SIZE_T
typedef __SIZE_T_TYPE__ size_t;
#endif

struct tm 
{
    int tm_sec;      /* seconds after the minute   - [0,59]  */
    int tm_min;      /* minutes after the hour     - [0,59]  */
    int tm_hour;     /* hours after the midnight   - [0,23]  */
    int tm_mday;     /* day of the month           - [1,31]  */
    int tm_mon;      /* months since January       - [0,11]  */
    int tm_year;     /* years since 1900                     */
    int tm_wday;     /* days since Sunday          - [0,6]   */
    int tm_yday;     /* days since Jan 1st         - [0,365] */
    int tm_isdst;    /* Daylight Savings Time flag           */
#if _AEABI_PORTABILITY_CHECK
    int __extra_1, __extra_2;            /* ABI-required extra fields */
#endif

};

/*************************************************************************/
/* TIME ZONE STRUCTURE DEFINITION                                        */
/*************************************************************************/
typedef struct 
{
    short daylight;
    long  timezone;
    char  tzname[4];
    char  dstname[4];
} TZ;

extern _DATA_ACCESS TZ _tz;

/****************************************************************************/
/* FUNCTION DECLARATIONS.  (NOTE : clock AND time ARE SYSTEM SPECIFIC)      */
/****************************************************************************/
_CODE_ACCESS clock_t    clock(void);             
_CODE_ACCESS time_t     time(time_t *_timer);   
 
_CODE_ACCESS time_t     mktime(struct tm *_tptr);
_CODE_ACCESS double     difftime(time_t _time1, time_t _time0);
      _IDECL char      *ctime(const time_t *_timer);
_CODE_ACCESS char      *asctime(const struct tm *_timeptr);
_CODE_ACCESS struct tm *gmtime(const time_t *_timer);
_CODE_ACCESS struct tm *localtime(const time_t *_timer);
_CODE_ACCESS size_t     strftime(char *_out, size_t _maxsize, 
				 const char *_format,
				 const struct tm *_timeptr);

#if defined(_INLINE) || defined(_CTIME_IMPLEMENTATION)

_IDEFN char *ctime(const time_t *timer)
{
   return(asctime(localtime(timer)));
}

#endif /* _INLINE || _CTIME_IMPLEMENTATION */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* _TIME */

#if defined(__cplusplus) && !defined(_CPP_STYLE_HEADER)
using std::clock_t;
using std::time_t;
using std::size_t;
using std::tm;
using std::TZ;
using std::_tz;
using std::clock;
using std::time;
using std::mktime;
using std::difftime;
using std::ctime;
using std::asctime;
using std::gmtime;
using std::localtime;
using std::strftime;
#endif /* ! _CPP_STYLE_HEADER */

