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
|  Filename:  ADLATUS_CompilerSwitches_cdf.h                                   |
|                                                                              |
|  Comment:   This file includes all global compilerswitches for the           |
|             SMART ADLATUS.                                                   |
|                                                                              |
+------------------------------------------------------------------------------+
| R E V I S I O N   H I S T O R Y                                              |
+------------------------------------------------------------------------------+
|
| Subversion Info:
| $Id: ADLATUS_CompilerSwitches_cdf.h 4396 2008-11-04 09:26:32Z maennel $
| $HeadURL: http://smartsvn/svn/adlatusrepository/auslieferungen/S1NN/086350-S1NN-ADLATUS-TMS470R-MucSuc/20081201_S1NN_TMS470R_BlfIso-Source_V1.00/01_SW_Projekt/05_header/ext/ADLATUS_CompilerSwitches_cdf.h $
|
+------------------------------------------------------------------------------+
|      (c) SMART ELECTRONIC DEVELOPMENT GMBH - all rights reserved             |
+-----------------------------------------------------------------------------*/

/* ========================================================================== */
/*      O P E N   M U L T I P L E   I N C L U D E   P R O T E C T I O N       */
/* ========================================================================== */
#ifndef __CDF_COMPILERSWITCHES_
#define __CDF_COMPILERSWITCHES_
/* ========================================================================== */


/* -------------------------------------------------------------------------- */
/*                                                                            */
/*    C O M P I L E R   S W I T C H   S E T T I N G S                         */
/*    -------------------------------------------------------------------     */
/*    Byte sequence and addressing                                            */
/*                                                                            */
/*                                                                            */
/*    Little Endian: e.g. INTEL - Format                                      */
/*    Big Endian:    e.g. MOTOROLA - Format                                   */
/*                                                                            */
/*    A 32 bit hexadecimal value 0x12345678 is stored in the memory the       */
/*    following way:                                                          */
/*                                                                            */
/*           +---------------+----+----+----+----+                            */
/*           | address       | 00 | 01 | 02 | 03 |                            */
/*           +---------------+----+----+----+----+                            */
/*           | little endian | 78 | 56 | 34 | 12 |                            */
/*           +---------------+----+----+----+----+                            */
/*           | big endian    | 12 | 34 | 56 | 78 |                            */
/*           +---------------+----+----+----+----+                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Addres format: little endian                                               */
/* #define  cs_CCtypes_LittleEndian */
/* Addres format: big endian                                                  */
#define  cs_CCtypes_BigEndian




/* -------------------------------------------------------------------------- */
/*                                                                            */
/*    C O M P I L E R   S W I T C H   S E T T I N G S                         */
/*    -------------------------------------------------------------------     */
/*    CPU size                                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* CPU size: 16 Bit data bus                                                  */
#define   cs_CCtypes_16BitCPU 
/* CPU size: 32 Bit data bus                                                  */
/* #define   cs_CCtypes_32BitCPU */



/* -------------------------------------------------------------------------- */
/*                                                                            */
/*    C O M P I L E R   S W I T C H   S E T T I N G S                         */
/*    -------------------------------------------------------------------     */
/*    Statemachine on SessionHandler / SequenceXXX                            */
/*                                                                            */
/*    This compiler switch defines the length of state machine's bit field.   */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* 32 Bit Statemachine on SequenceXXX.c                                       */
/*#define   cs_CCtypes_32BitSequence */
/* 16 Bit Statemachine on SequenceXXX.c                                       */
#define  cs_CCtypes_16BitSequence



/* -------------------------------------------------------------------------- */
/*                                                                            */
/*    C O M P I L E R   S W I T C H   S E T T I N G S                         */
/*    -------------------------------------------------------------------     */
/*    FlashFunctions                                                          */
/*                                                                            */
/*    This switch disables the checks for the protected areas which are only  */
/*    necessary on normal ADLATUS. The Interim ADLATUS for reprogramming      */
/*    should not do this checks!!                                             */
/*                                                                            */
/* -------------------------------------------------------------------------- */
 /* Compile Normal ADLATUS                                                    */
#define cs_CCflash_NormalADLATUS   
/* Compile ReprogADLATUS                                                      */
/*#define cs_CCwtdog_ReprogADLATUS*/



/* -------------------------------------------------------------------------- */
/*                                                                            */
/*    C O M P I L E R   S W I T C H   S E T T I N G S                         */
/*    -------------------------------------------------------------------     */
/*   Flash sequence                                                           */
/*                                                                            */
/* -------------------------------------------------------------------------- */



/* ========================================================================== */
/*      C L O S E   M U L T I P L E   I N C L U D E   P R O T E C T I O N     */
/* ========================================================================== */
#endif
/* ========================================================================== */


/* ========================================================================== */
/*      E N D   O F   F I L E                                                 */
/* ========================================================================== */
