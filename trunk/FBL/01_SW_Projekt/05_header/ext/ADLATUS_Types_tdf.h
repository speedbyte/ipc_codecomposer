/*-----------------------------------------------------------------------------+
|            ____    ___            ____    _____           ____               |
|           |    |  |   \   |      |    |     |    |    |  |                   |
|           |____|  |    |  |      |____|     |    |    |  |____               |
|           |    |  |    |  |      |    |     |    |    |       |              |
|           |    |  |___/   |____  |    |     |    |____|   ____|              |
|                                                                              |
|           T H E   S M A R T   E M B E D D E D   S O L U T I O N              |
|                                                                              |
+------------------------------------------------------------------------------+
| F I L E   I N F O R M A T I O N                                              |
+------------------------------------------------------------------------------+
|                                                                              |
|  Filename:  ADLATUS_Types_tdf.h                                              |
|                                                                              |
|  Comment:   This file includes all type definitions for the ADLATUS project. |
|                                                                              |
+------------------------------------------------------------------------------+
| R E V I S I O N   H I S T O R Y                                              |
+------------------------------------------------------------------------------+
|
| Subversion Info:
| $Id: ADLATUS_Types_tdf.h 4396 2008-11-04 09:26:32Z maennel $
| $HeadURL: http://smartsvn/svn/adlatusrepository/auslieferungen/S1NN/086350-S1NN-ADLATUS-TMS470R-MucSuc/20081201_S1NN_TMS470R_BlfIso-Source_V1.00/01_SW_Projekt/05_header/ext/ADLATUS_Types_tdf.h $
|
+------------------------------------------------------------------------------+
|      (c) SMART ELECTRONIC DEVELOPMENT GMBH - all rights reserved             |
+-----------------------------------------------------------------------------*/

/* ========================================================================== */
/*      O P E N   M U L T I P L E   I N C L U D E   P R O T E C T I O N       */
/* ========================================================================== */
#ifndef __TDF_TYPES_
#define __TDF_TYPES_
/* ========================================================================== */

/* ========================================================================== */
/*                                                                            */
/*  C O M P I L E R   S W I T C H   S E T T I N G S                           */
/*  ---------------------------------------------------------------------     */
/*  The modul ADLATUS_Types_tdf.h will be included to each source file.       */
/*  Therefor the global compiler switch settings will be included to the      */
/*  ADLATUS_Types_tdf.h. So they are available within each source file.       */
/*                                                                            */
/* ========================================================================== */
#include "ADLATUS_CompilerSwitches_cdf.h"

/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Def.01                                                   */
/*  ---------------------------------------------------------------------     */
/*  Special defines                                                           */
/*                                                                            */
/* ========================================================================== */
#ifndef VOID
  #define VOID   void
#endif
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#ifndef FALSE
  #define FALSE   0
#endif
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#ifndef TRUE
  #define TRUE    (!FALSE)
#endif
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#ifndef NULL
  #define NULL    0
#endif

/* -+-  END OF Type Definition 'Def.01'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/




/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Var.01                                                   */
/*  ---------------------------------------------------------------------     */
/*  Variables                                                                 */
/*                                                                            */
/* ========================================================================== */
typedef unsigned char       BOOL;       /*  Boolean oject (FALSE/~FALSE)      */
typedef unsigned char       UBYTE;      /*  1 byte (8 Bit) unsigned           */
typedef unsigned char       ubyte;      /*  1 byte (8 Bit) unsigned           */
typedef signed char         SBYTE;      /*  1 byte (8 Bit) signed             */
typedef unsigned short      UWORD;      /*  2 byte (16 Bit) unsigned          */
typedef unsigned short      uword;      /*  2 byte (16 Bit) unsigned          */
typedef short               SWORD;      /*  2 byte (16 Bit) signed            */
typedef unsigned long       ULONG;      /*  4 byte (32 Bit) unsigned          */
typedef unsigned long       ulong;      /*  4 byte (32 Bit) unsigned          */
typedef long                SLONG;      /*  4 byte (32 Bit) signed            */
typedef float               FLOAT;      /*  4 byte float single-precision     */
typedef double              DOUBLE;     /*  8 byte float double-precision     */
typedef long double         LDOUBLE;    /* 10 byte float long-precision       */

#ifndef BITFIELD                 
typedef unsigned int        BITFIELD;   /* Bit object                   */
#endif 

/* -+-  END OF Type Definition 'Var.01'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/




/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Buffer.01                                                */
/*  ---------------------------------------------------------------------     */
/*  BUFFER                                                                    */
/*                                                                            */
/* ========================================================================== */
typedef UBYTE           BUFFER_UB;  /* Buffer with UBYTE - elements           */
typedef UWORD           BUFFER_UW;  /* Buffer with UWORD - elements           */
typedef ULONG           BUFFER_UL;  /* Buffer with ULONG - elements           */

/* -+-  END OF Type Definition 'Buffer.01'  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/


/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Timer.01                                                 */
/*  ---------------------------------------------------------------------     */
/*  Timer                                                                     */
/*                                                                            */
/* ========================================================================== */
typedef UBYTE           TIMER_8;   /* Timer  8 Bit -->  0 .. 255              */
typedef UWORD           TIMER_16;  /* Timer 16 Bit -->  0 .. 65 535           */
typedef ULONG           TIMER_32;  /* Timer 32 Bit -->  0 .. 4 294 967 295    */

/* -+-  END OF Type Definition 'Timer.01'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/


/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Ptr.01                                                   */
/*  ---------------------------------------------------------------------     */
/*  Pointer                                                                   */
/*                                                                            */
/* ========================================================================== */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* HUGE POINTER                                                               */
/*                                                                            */
/* NOTE: The nomenclature is compiler dependent!!                             */
/*       Be sure that the correct syntax is used !!                           */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
typedef UBYTE*     HUGE_PTR_UBYTE;     /* --> UBYTE*  'PTR to UBYTE'   */  
typedef UWORD*     HUGE_PTR_UWORD;     /* --> UWORD*  'PTR to UWORD'   */
typedef ULONG*     HUGE_PTR_ULONG;     /* --> ULONG*  'PTR to ULONG'   */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* FAR POINTER                                                                */
/*                                                                            */
/* NOTE: The nomenclature is compiler dependent!!                             */
/*       Be sure that the correct syntax is used !!                           */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
typedef UBYTE*    FAR_PTR_UBYTE; /* --> UBYTE*  'PTR to UBYTE'                */
typedef UWORD*    FAR_PTR_UWORD; /* --> UWORD*  'PTR to UWORD'                */
typedef ULONG*    FAR_PTR_ULONG; /* --> ULONG*  'PTR to ULONG'                */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* NEAR POINTER                                                               */
/*                                                                            */
/* NOTE: The nomenclature is compiler dependent!!                             */
/*       Be sure that the correct syntax is used !!                           */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
typedef UBYTE*          NEAR_PTR_UBYTE;    /* --> UBYTE*  'PTR to UBYTE'      */
typedef UWORD*          NAER_PTR_UWORD;    /* --> UWORD*  'PTR to UWORD'      */
typedef ULONG*          NAER_PTR_ULONG;    /* --> ULONG*  'PTR to ULONG'      */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* FAR VOLATILE POINTER                                                       */
/*                                                                            */
/* NOTE: The nomenclature is compiler dependent!!                             */
/*       Be sure that the correct syntax is used !!                           */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
typedef volatile UBYTE*    FAR_VOL_PTR_UBYTE;  /* --> Volatile Ptr to UBYTE   */
typedef volatile UWORD*    FAR_VOL_PTR_UWORD;  /* --> Volatile Ptr to UWORD   */
typedef volatile ULONG*    FAR_VOL_PTR_ULONG;  /* --> Volatile Ptr to ULONG   */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* POINTER TO BUFFER                                                          */
/*                                                                            */
/* NOTE: The nomenclature is compiler dependent!!                             */
/*       Be sure that the correct syntax is used !!                           */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
typedef BUFFER_UB*          PTR_BUFFER_UB;    /* --> UBYTE* 'PTR to Buffer UBYTE' */
typedef BUFFER_UW*          PTR_BUFFER_UW;    /* --> UWORD* 'PTR to Buffer UWORD' */
typedef BUFFER_UL*          PTR_BUFFER_UL;    /* --> ULONG* 'PTR to Buffer ULONG' */


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* POINTER FOR CHECKSUM ACCESS                                                */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
typedef   FAR_PTR_UBYTE     CHK_ACCESS_PTR_UB;
typedef   FAR_PTR_UWORD     CHK_ACCESS_PTR_UW;
typedef   FAR_PTR_ULONG     CHK_ACCESS_PTR_UL;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* POINTER FOR RAM CHECK ACCESS                                               */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
typedef   FAR_VOL_PTR_UBYTE     RAM_CHK_PTR_UB;
typedef   FAR_VOL_PTR_UWORD     RAM_CHK_PTR_UW;
typedef   FAR_VOL_PTR_ULONG     RAM_CHK_PTR_UL;


/* -+-  END OF Type Definition 'Ptr.01'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Struct.01                                                */
/*  ---------------------------------------------------------------------     */
/*  Structure                                                                 */
/*                                                                            */
/* ========================================================================== */

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#ifdef cs_CCtypes_BigEndian
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

typedef struct _ULONG1
{                             /*  types                                       */
  ULONG  ULong0_UL;           /*  4 Byte - ULONG                              */
} ULONG1_ST;                  /*--------------------------------------------- */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
typedef  struct _UWORD1
{
  UWORD  UWord0_UW;           /*  2 Byte - UWORD 0 (byte 0-1) */
} UWORD1_ST;                  /* -------------------------------------------- */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
typedef  struct _UWORD2
{
  UWORD  UWord0_UW;           /*  2 Byte - UWORD 0 (byte 0-1) */
  UWORD  UWord1_UW;           /*  2 Byte - UWORD 1 (byte 2-3) */
} UWORD2_ST;                  /* -------------------------------------------- */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
typedef  struct _UBYTE2
{
  UBYTE   UByte0_UB;          /*  1 Byte - UBYTE 0                            */
  UBYTE   UByte1_UB;          /*  1 Byte - UBYTE 1                            */
} UBYTE2_ST;                  /* -------------------------------------------- */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
typedef  struct _UBYTE4
{
  UBYTE   UByte0_UB;          /*  1 Byte - UBYTE 0                            */
  UBYTE   UByte1_UB;          /*  1 Byte - UBYTE 1                            */
  UBYTE   UByte2_UB;          /*  1 Byte - UBYTE 2                            */
  UBYTE   UByte3_UB;          /*  1 Byte - UBYTE 3                            */
} UBYTE4_ST;                  /* -------------------------------------------- */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*----------------------------------------------------------------------------*/
#endif /* cs_CCtypes_BigEndian                                                */
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#ifdef cs_CCtypes_LittleEndian
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

typedef struct _ULONG1
{                             /*  types                                       */
  ULONG  ULong0_UL;           /*  4 Byte - ULONG                              */
} ULONG1_ST;                  /*--------------------------------------------- */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
typedef  struct _UWORD1
{
  UWORD  UWord0_UW;           /*  2 Byte - UWORD 0 (byte 1-0) */
} UWORD1_ST;                  /* -------------------------------------------- */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
typedef  struct _UWORD2
{
  UWORD  UWord1_UW;           /*  2 Byte - UWORD 1 (byte 3-2) */
  UWORD  UWord0_UW;           /*  2 Byte - UWORD 0 (byte 1-0) */
} UWORD2_ST;                  /* -------------------------------------------- */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
typedef  struct _UBYTE2
{
  UBYTE   UByte1_UB;          /*  1 Byte - UBYTE 1                            */
  UBYTE   UByte0_UB;          /*  1 Byte - UBYTE 0                            */
} UBYTE2_ST;                  /* -------------------------------------------- */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
typedef  struct _UBYTE4
{
  UBYTE   UByte3_UB;          /*  1 Byte - UBYTE 3                            */
  UBYTE   UByte2_UB;          /*  1 Byte - UBYTE 2                            */
  UBYTE   UByte1_UB;          /*  1 Byte - UBYTE 1                            */
  UBYTE   UByte0_UB;          /*  1 Byte - UBYTE 0                            */
} UBYTE4_ST;                  /* -------------------------------------------- */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*----------------------------------------------------------------------------*/
#endif /* cs_CCtypes_LittleEndian                                             */
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/* -+-  END OF Type Definition 'Struct.01'  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/




/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Union.01                                                 */
/*  ---------------------------------------------------------------------     */
/*  Union                                                                     */
/*                                                                            */
/* ========================================================================== */

/*----------------------------------------------------------------------------*/
/* UNION 2 BYTE (UWORD)                                                       */
/*----------------------------------------------------------------------------*/
typedef union _UNION2
{
  UWORD1_ST    UWord_ST; /* 1 x UWORD                                         */
  UBYTE2_ST    UByte_ST; /* 2 x UBYTE                                         */
                         /*---------------------------------------------------*/
} UNION2;                /* 2 Byte                                            */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


/*----------------------------------------------------------------------------*/
/* UNION 4 BYTE (ULONG)                                                       */
/*----------------------------------------------------------------------------*/
typedef union _UNION4
{
  ULONG1_ST    ULong_ST; /* 1 x ULONG                                         */
  UWORD2_ST    UWord_ST; /* 2 x UWORD                                         */
  UBYTE4_ST    UByte_ST; /* 4 x UBYTE                                         */
                         /*---------------------------------------------------*/
} UNION4;                /*  4 Byte                                           */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* -+-  END OF Type Definition 'Union.01'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* POINTER FOR REGISTER ACCESS                                                */
/*                                                                            */
/* NOTE: The nomenclature is compiler dependent!!                             */
/*       Be sure that the correct syntax is used !!                           */
/*       Be sure that the correct register length is used !!                  */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
typedef UWORD volatile*    PTR_REG;


/* -+-  END OF Type Definition 'Ptr.01'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/



/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Ptr.02                                                   */
/*  ---------------------------------------------------------------------     */
/*  Pointer to function                                                       */
/*                                                                            */
/*                                                                            */
/* NOTE: The nomenclature is compiler dependent!!                             */
/*       Be sure that the correct syntax is used !!                           */
/* ========================================================================== */

  /*--------------------------------------------------------------------------*/
  /* void functionname (void)                                                 */
  /*--------------------------------------------------------------------------*/
  typedef void (*PTR_TO_FKT_VOID_VOID) (void);
  typedef  void (*PTR_TO_EVENTPROCESSING_FKT) (void);

  /*--------------------------------------------------------------------------*/
  /* UBYTE functionname ( PTR_BUFFER_UB x, PTR_BUFFER_UB y )                  */
  /*--------------------------------------------------------------------------*/
  typedef UBYTE (*PTR_TO_COM_STACK_FKT) (PTR_BUFFER_UB InBuffer_PBUF, \
                                        PTR_BUFFER_UB OutBuffer_PBUF); 

  /*--------------------------------------------------------------------------*/
  /* UBYTE functionname ( void )                                              */
  /*--------------------------------------------------------------------------*/
  typedef UBYTE (*PTR_TO_COM_HAL_FKT) (void); 

  /*--------------------------------------------------------------------------*/
  /* void functionname ( UWORD x )                                            */
  /*--------------------------------------------------------------------------*/
  typedef void  (*PTR_TO_SWTIMER_FKT) ( UWORD t_TimerTick_UW );

/* -+-  END OF Type Definition 'Ptr.02'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Buffer.02                                                */
/*  ---------------------------------------------------------------------     */
/*  Buffer Init                                                               */
/*                                                                            */
/* ========================================================================== */
typedef struct _BUFFERINIT
{
  UBYTE     Config_UB;        /*  1 Byte - Channel number                     */
  UBYTE     ChannelInf_UB;    /*  1 Byte - currently active session           */
  UBYTE     Length_UB;        /*  1 Byte - Response Index                     */
  UBYTE     reserved01_UB;    /*  1 Byte - reserved                           */
                              /*--------------------------------------------- */
} BUFFERINIT;                 /*  4 Byte                                      */

/* -+-  END OF Type Definition 'Buffer.02'  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/





/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Config.01                                                */
/*  ---------------------------------------------------------------------     */
/*  Memory Map for Download                                                   */
/*                                                                            */
/* ========================================================================== */
typedef struct _DOWNLOADMEMORYMAP
{
  UBYTE ubInterfaceVersion;
  UBYTE ubReserverd;
  UBYTE ubMask;
  UBYTE ubMCU;

  ULONG StartAddress_UL;    /*  4 Byte - Start address of check               */
  ULONG EndAddress_UL;      /*  4 Byte - Stop Address of check                */
  UWORD MemoryInfo_UW;      /*  2 Byte - Error Message entry                  */
} DOWNLOADMAP_ST;           /* 10/24 Byte                                     */

/* -+-  END OF Type Definition 'Config.01'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/




/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Sys.01                                                   */
/*  ---------------------------------------------------------------------     */
/*  Buffer configuration                                                      */
/*                                                                            */
/* ========================================================================== */
typedef struct _BUFFERCONFIGURATION
{
  PTR_BUFFER_UB  Line_PBUF[6];

} BUFFERCONFIGURATION_ST;

/* -+-  END OF Type Definition 'Sys.01'  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/




/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Sys.02                                                   */
/*  ---------------------------------------------------------------------     */
/*  Communication Stack functions                                             */
/*                                                                            */
/* ========================================================================== */
typedef struct _COMSTACKFUNCTIONS
{
  PTR_TO_COM_STACK_FKT Layer_PFUN[7];

} COMSTACKFUNCTIONS_ST;

/* -+-  END OF Type Definition 'Sys.02'  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/




/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Sys.03                                                   */
/*  ---------------------------------------------------------------------     */
/*  HAL Functions for communication                                           */
/*                                                                            */
/* ========================================================================== */
typedef struct _COMHALFUNCTIONS
{
  PTR_TO_COM_HAL_FKT   ComHALFkt_PFUN;

} COMHALFUNCTIONS_ST;

/* -+-  END OF Type Definition 'Sys.03'  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/




/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Sys.04                                                   */
/*  ---------------------------------------------------------------------     */
/*  Communication Modul Error Functions                                       */
/*                                                                            */
/* ========================================================================== */
typedef struct _COMMODULERRORFKTS
{
  /*--------------------------------------------------------------------------*/
  /* One error fkt for each direction of each layer                           */
  /*--------------------------------------------------------------------------*/
  PTR_TO_FKT_VOID_VOID Layer_PFUN[7];

} COMMODULERRORFKTS_ST;

/* -+-  END OF Type Definition 'Sys.04'  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/





/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Sys.05                                                   */
/*  ---------------------------------------------------------------------     */
/*  System Interface                                                          */
/*                                                                            */
/* ========================================================================== */
typedef struct _SYSTEMINTERFACE
{
  /*--------------------------------------------------------------------------*/
  /* System Buffer Configuration Table                                        */
  /*--------------------------------------------------------------------------*/
  const BUFFERCONFIGURATION_ST* SystemBufferConfig_PST;

  /*--------------------------------------------------------------------------*/
  /* Communication Stack Function Table                                       */
  /*--------------------------------------------------------------------------*/
  const COMSTACKFUNCTIONS_ST* ComStackFunctions_PST;

  /*--------------------------------------------------------------------------*/
  /* Communication HAL Function Table                                         */
  /*--------------------------------------------------------------------------*/
  const COMHALFUNCTIONS_ST* ComHalFunctions_PST;

  /*--------------------------------------------------------------------------*/
  /* Event Processing Function Table                                          */
  /*--------------------------------------------------------------------------*/
  const PTR_TO_EVENTPROCESSING_FKT* EventProcessingFkt_PAFUN;

  } SYSTEMINTERFACE_ST;

/* -+-  END OF Type Definition 'Sys.05'  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/



/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Hal.01                                                   */
/*  ---------------------------------------------------------------------     */
/*  HAL Interface                                                             */
/*                                                                            */
/* ========================================================================== */
typedef struct _HALINTERFACE
{
  FAR_PTR_ULONG IntClkFrequency_UL;   /*  4 Byte - Internal clock frequency          */
  FAR_PTR_UWORD IntWdtTimeout_UW;     /*  2 Byte - Timeout for int. watchdog trigger */
                               /* ----------------------------------------    */
} HALINTERFACE_ST;             /*  6 Byte                                     */

/* -+-  END OF Type Definition 'Hal.01'  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/




/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Nvm.01                                                   */
/*  ---------------------------------------------------------------------     */
/*  NVM Entry                                                                 */
/*                                                                            */
/* ========================================================================== */
typedef struct _NVMENTRY
{
  UBYTE Name_UB;         /*  1 Byte - Name of NVM entry                       */
  UBYTE StorageType_UB;  /*  1 Byte - Storrage type of NVM data               */
  UWORD DataLength_UW;   /*  2 Byte - Length of NVM entry                     */
  UWORD TotalLength_UW;  /*  2 Byte - physical storage size                   */
  UWORD Address_UW;      /*  2 Byte - Address of NVM entry                    */

                         /* ------------------------------------------------- */
} NVMENTRY_ST;           /* 8 Byte                             */

/* -+-  END OF Type Definition 'Nvm.01'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/




/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Nvm.02                                                   */
/*  ---------------------------------------------------------------------     */
/*  NVM Interface                                                             */
/*                                                                            */
/* ========================================================================== */
typedef struct _NVMINTERFACE
{
  const NVMENTRY_ST* NvmAddressMap_PST; /*  2 Byte - Ptr to NVM address structure   */
                                  /* ---------------------------------------- */
} NVMINTERFACE_ST;                /* 2 Byte                             */

/* -+-  END OF Type Definition 'Nvm.02'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/


/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Nvm.03                                                   */
/*  ---------------------------------------------------------------------     */
/*  NVM Entry                                                                 */
/*                                                                            */
/* ========================================================================== */
typedef struct _NVMRUNTIMEENTRY
{
  UBYTE Access_UB;       /*  1 Byte - Read/write                              */
  UBYTE StorageType_UB;  /*  1 Byte - Storrage type of NVM data               */
  UWORD DataLength_UW;   /*  2 Byte - Length of NVM entry                     */
  UWORD TotalLength_UW;  /*  2 Byte - physical storage size                   */
  UWORD Address_UW;      /*  4 Byte - Address of NVM entry                    */
  
  FAR_PTR_UBYTE Buffer_UB;
                         /* ------------------------------------------------- */
} NVMRUNTIMEENTRY_ST;    /*  8 Byte                                           */

/* -+-  END OF Type Definition 'Nvm.03'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/


/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Nvm.05                                                   */
/*  ---------------------------------------------------------------------     */
/*  Direct access to NVM                                                      */
/*                                                                            */
/* ========================================================================== */
typedef struct _NVMACCESS_ST
{
  FAR_PTR_UBYTE Data_PUB;   /*  4 Byte - Pointer to data                      */
  UWORD Address_UW;         /*  2 Byte - NVM address                          */
  UWORD TotalBytes_UW;      /*  2 Byte - total number of data bytes to be     */
                            /*           written; is the number that results  */
                            /*           out of the request download          */
  UWORD NbrBytes_UB;        /*  1 Byte - number of data bytes to be written   */
                            /*           in this actual transfer data         */
                            /* -----------------------------------------------*/
} NVMACCESS_ST;             /*  7 Byte                                        */

/* -+-  END OF Type Definition 'Nvm.05'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/


/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Reprog.01                                                */
/*  ---------------------------------------------------------------------     */
/*  Memory Mapping                                                            */
/*                                                                            */
/* ========================================================================== */
typedef struct _REPROGMEMORYMAP
{
  ULONG OldAdlatusStartAddress_UL;        /*  4 Byte - StartAddress of the old ADLATUS         */
  ULONG OldAdlatusEndAddress_UL;          /*  4 Byte - EndAddress of the old ADLATUS           */
  ULONG NewAdlatusStartAddress_UL;        /*  4 Byte - StartAddress of the new ADLATUS         */
  ULONG NewAdlatusEndAddress_UL;          /*  4 Byte - EndAddress of the new ADLATUS           */
  ULONG FlashFunctStartAddressInFlash_UL; /*  4 Byte - StartAddress of the FlashFunct in Flash */
  ULONG FlashFunctEndAddressInFlash_UL;   /*  4 Byte - EndAddress of the FlashFunct in Flash   */
  ULONG FlashFunctStartAddressInRAM_UL;   /*  4 Byte - StartAddress of the FlashFunct in RAM   */
  ULONG FlashFunctEndAddressInRAM_UL;     /*  4 Byte - EndAddress of the FlashFunct in RAM     */
  ULONG ApplSWChecksumStartAddress_UL;    /*  4 Byte - StartAddress of the Appl.-SW Checksum   */
  ULONG ApplSWChecksumEndAddress_UL;      /*  4 Byte - EndAddress of the Appl.-SW Checksum     */
                                          /* ------------------------------------------------- */
} REPROGMEMORYMAP_ST;                     /* 40 Byte                                           */

/* -+-  END OF Type Definition 'Reprog.01'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/



/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Reprog.02                                                */
/*  ---------------------------------------------------------------------     */
/*  Reprog System Interface                                                   */
/*                                                                            */
/* ========================================================================== */
typedef struct _REPROGSYSTEMINTERFACE
{
  /*--------------------------------------------------------------------------*/
  /* System Buffer Configuration Table                                        */
  /*--------------------------------------------------------------------------*/
  REPROGMEMORYMAP_ST* ReprogMemoryMapConfig_PST;
  /*--------------------------------------------------------------------------*/
  /* Max. Blocksize of data for programming                                   */
  /*--------------------------------------------------------------------------*/
  UWORD* MaxBlockSizeForProgData_PUW;

} REPROGSYSTEMINTERFACE_ST;

/* -+-  END OF Type Definition 'Reprog.02'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/



/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Timer.01                                                 */
/*  ---------------------------------------------------------------------     */
/*  Software Timer Handler Interface                                          */
/*                                                                            */
/* ========================================================================== */
typedef struct _SWTIMERHANDLERINTERFACE
{
  /*--------------------------------------------------------------------------*/
  /* SW Timer Table                                                           */
  /*--------------------------------------------------------------------------*/
  const PTR_TO_SWTIMER_FKT* SWTimerFunctions_PST;        /* Ptr to Function pointer */

} SWTIMERHANDLERINTERFACE_ST;

/* -+-  END OF Type Definition 'Timer.01'  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

/* ========================================================================== */
/*                                                                            */
/*  T Y P E   D E F I N I T I O N                                             */
/*  ---------------------------------------------------------------------     */
/*  Type definition: Sci.01                                                   */
/*  ---------------------------------------------------------------------     */
/*  UART Interface                                                            */
/*                                                                            */
/* ========================================================================== */
typedef struct _SCIINTERFACE
{
  FAR_PTR_ULONG IntClkFrequency_UL;     /*  4 Byte - Internal clock frequency  */
  FAR_PTR_ULONG DefaultBaudrate_UL;     /*  4 Byte - Timeout for int. watchdog trigger */
                               /* ----------------------------------------    */
} SCIINTERFACE_ST;             /*  6 Byte                                     */

/* ========================================================================== */
/*      C L O S E   M U L T I P L E   I N C L U D E   P R O T E C T I O N     */
/* ========================================================================== */
#endif
/* ========================================================================== */

/* ========================================================================== */
/*      E N D   O F   F I L E                                                 */
/* ========================================================================== */
