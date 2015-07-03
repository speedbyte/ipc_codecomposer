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
|  Filename:  ADLATUS_ApplicationInterface_tdf.h                               |
|                                                                              |
|  Comment:   This file includes all type defines and extern declarations for  |
|             the interface between SMART ADLATUS and the customers software.  |
|                                                                              |
+------------------------------------------------------------------------------+
| R E V I S I O N   H I S T O R Y                                              |
+------------------------------------------------------------------------------+
|
| Subversion Info:
| $Id: ADLATUS_ApplicationInterface_tdf.h 4396 2008-11-04 09:26:32Z maennel $
| $HeadURL: http://smartsvn/svn/adlatusrepository/auslieferungen/S1NN/086350-S1NN-ADLATUS-TMS470R-MucSuc/20081201_S1NN_TMS470R_BlfIso-Source_V1.00/01_SW_Projekt/05_header/ext/ADLATUS_ApplicationInterface_tdf.h $
|
+------------------------------------------------------------------------------+
|      (c) SMART ELECTRONIC DEVELOPMENT GMBH - all rights reserved             |
+-----------------------------------------------------------------------------*/


/* ========================================================================== */
/*      O P E N   M U L T I P L E   I N C L U D E   P R O T E C T I O N       */
/* ========================================================================== */
#ifndef __TDF_APPLICATIONINTERFACE_
#define __TDF_APPLICATIONINTERFACE_
/* ========================================================================== */


/* ========================================================================== */
/*                                                                            */
/*      E X T E R N   D E C L A R A T I O N S                                 */
/*                                                                            */
/* ========================================================================== */

/*----------------------------------------------------------------------------*/
/* Description:   Special interface between ADLATUS and the customer software.*/
/*                (1) FlashRequest from Application Software                  */
/*----------------------------------------------------------------------------*/
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifdef cs_CCTP20
/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/* U S E   S E R V I C E   0 x 1 A                                            */
/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#ifndef cs_CCkwp_Use0x22 /* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/*----------------------------------------------------------------------------*/

/* constants for 0x1A 0x9B */
/* for accessing the default data in ASW when EEPROM access was not */
/* successful and the ASW is valid.                                 */
extern const ULONG C_CCapplint_ASWDefaultPartnumber1a9b_UL;
extern const ULONG C_CCapplint_ASWDefaultProgramStatus1a9b_UL;
extern const ULONG C_CCapplint_ASWDefaultDataStatus1a9b_UL;

#endif
#endif
/* ========================================================================== */
/*                                                                            */
/*      G L O B A L   F U N C T I O N   P R O T O T Y P E S                   */
/*                                                                            */
/* ========================================================================== */

/*----------------------------------------------------------------------------*/
/* Entry routine to customers software                                        */
/*----------------------------------------------------------------------------*/
void  FUN_CCapplint_JumpToFSW_V          (void);
/*----------------------------------------------------------------------------*/
/* Check routine for customer flash request                                   */
/*----------------------------------------------------------------------------*/
UBYTE FUN_CCapplint_CheckFlashRequest_UB (void);
/*----------------------------------------------------------------------------*/
/* Reset customer flash request                                               */
/*----------------------------------------------------------------------------*/
void  FUN_CCapplint_ResetFlashRequest_V  (void);
/*----------------------------------------------------------------------------*/
/* set ECU reset request                                                      */
/*----------------------------------------------------------------------------*/
void FUN_CCapplint_SetResetRequest_V (void);
/*----------------------------------------------------------------------------*/
/* set default Session request                                                */  /* [OPL286] */
/*----------------------------------------------------------------------------*/
void FUN_CCapplint_SetDefSessionRequ_V (void);

/*----------------------------------------------------------------------------*/
/* set flash request                                                      */
/*----------------------------------------------------------------------------*/
void FUN_CCapplint_SetFlashRequest_V (void);


/* ========================================================================== */
/*      C L O S E   M U L T I P L E   I N C L U D E   P R O T E C T I O N     */
/* ========================================================================== */
#endif
/* ========================================================================== */


/* ========================================================================== */
/*      E N D   O F   F I L E                                                 */
/* ========================================================================== */
