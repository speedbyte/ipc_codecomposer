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
|  Filename:  ADLATUS_ConfigSystem_cdf.h                                       |
|                                                                              |
|  Comment:   This file includes all defines which are importand for the       |
|             basic system configuration of the SMART ADLATUS.                 |
|                                                                              |
+------------------------------------------------------------------------------+
| R E V I S I O N   H I S T O R Y                                              |
+------------------------------------------------------------------------------+
|
| Subversion Info:
| $Id: ADLATUS_ConfigSystem_cdf.h 4396 2008-11-04 09:26:32Z maennel $
| $HeadURL: http://smartsvn/svn/adlatusrepository/auslieferungen/S1NN/086350-S1NN-ADLATUS-TMS470R-MucSuc/20081201_S1NN_TMS470R_BlfIso-Source_V1.00/01_SW_Projekt/05_header/ext/ADLATUS_ConfigSystem_cdf.h $
|
+------------------------------------------------------------------------------+
|      (c) SMART ELECTRONIC DEVELOPMENT GMBH - all rights reserved             |
+-----------------------------------------------------------------------------*/

/* ========================================================================== */
/*      O P E N   M U L T I P L E   I N C L U D E   P R O T E C T I O N       */
/* ========================================================================== */
#ifndef __CDF_CONFIGSYSTEM_
#define __CDF_CONFIGSYSTEM_
/* ========================================================================== */


/******************************************************************************/
/******************************************************************************/
/**                                                                          **/
/**     APPLICATION AREA CONSYS.01                                           **/
/**     ----------------------------------------------------------------     **/
/**     S Y S T E M   C O N F I G U R A T I O N                              **/
/**     ----------------------------------------------------------------     **/
/**     Number of logical communication channels                             **/
/**                                                                          **/
/**                                                                          **/
/******************************************************************************/
/******************************************************************************/
#define d_CCconsys_NbrOfLogChannel (UBYTE) 0x01u  /* 0x01 .. 0x0F             */

/******************************************************************************/
/* -- -- END OF APPLICATION AREA CONSYS.01 -- -- -- -- -- -- -- -- -- -- -- --*/
/******************************************************************************/


/******************************************************************************/
/******************************************************************************/
/**                                                                          **/
/**     APPLICATION AREA CONSYS.04                                           **/
/**     ----------------------------------------------------------------     **/
/**     S Y S T E M   C O N F I G U R A T I O N                              **/
/**     ----------------------------------------------------------------     **/
/**     Validation Handler - time slot size                                  **/
/**                                                                          **/
/**     The Validation Handler internally uses ULONG fixed point values.     **/
/**     3 bytes are used for the ms value, 1 byte (LSB) is used for the      **/
/**     sub-ms part.                                                         **/
/**                                                                          **/
/**     d_CCVhnd_TimeSlot_1ms_UW - Time slot in ms                           **/
/**     d_CCVhnd_TimeSlot_4us_UB - Time slot in (ms/0xFF)                    **/
/**                                                                          **/
/**     Time slot is calculated with:                                        **/
/**     ( (d_CCVhnd_TimeSlot_1ms_UW << 8) | (d_CCVhnd_TimeSlot_4us_UB) )     **/
/**                                                                          **/
/******************************************************************************/
/******************************************************************************/
#define d_CCVhnd_TimeSlot_1ms_UW               0x0000u
#define d_CCVhnd_TimeSlot_4us_UB               0x20u


/* ========================================================================== */
/*      C L O S E   M U L T I P L E   I N C L U D E   P R O T E C T I O N     */
/* ========================================================================== */
#endif
/* ========================================================================== */


/* ========================================================================== */
/*      E N D   O F   F I L E                                                 */
/* ========================================================================== */
