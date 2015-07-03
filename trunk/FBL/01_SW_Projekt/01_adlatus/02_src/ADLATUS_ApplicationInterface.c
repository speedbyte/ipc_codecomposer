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
|  Filename:  ADLATUS_ApplicationInterface.c                                   |
|                                                                              |
|  Comment:   Interface between SMART ADLATUS Software and customers software. |
|                                                                              |
+------------------------------------------------------------------------------+
| R E V I S I O N   H I S T O R Y                                              |
+------------------------------------------------------------------------------+
|
| Subversion Info:
| $Id: ADLATUS_ApplicationInterface.c 4508 2008-11-28 12:28:20Z maennel $
| $HeadURL: http://smartsvn/svn/adlatusrepository/auslieferungen/S1NN/086350-S1NN-ADLATUS-TMS470R-MucSuc/20081201_S1NN_TMS470R_BlfIso-Source_V1.00/01_SW_Projekt/01_adlatus/02_src/ADLATUS_ApplicationInterface.c $
|
+------------------------------------------------------------------------------+
|      (c) SMART ELECTRONIC DEVELOPMENT GMBH - all rights reserved             |
+-----------------------------------------------------------------------------*/

/* ========================================================================== */
/* (1)  I N C L U D E S                                                       */
/* -------------------------------------------------------------------------- */
/*      C O N S T A N T   D E F I N I T I O N   F I L E S  (CDF)              */
/* ========================================================================== */
#include "ADLATUS_CompilerSwitches_cdf.h"    /* must be the first CDF-include */
#include "ADLATUS_Global_cdf.h"
#include "ADLATUS_CusInterfaceAudi_cdf.h"

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Includes for the address information                                       */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#include "ADLATUS_Adr_Info.h"

/* ========================================================================== */
/* (2)  I N C L U D E S                                                       */
/* -------------------------------------------------------------------------- */
/*      T Y P E   D E F I N I T I O N   F I L E S  (TDF)                      */
/* ========================================================================== */
#include "ADLATUS_Types_tdf.h"                 /* must be the first include   */
#include "ADLATUS_ExternalWatchdog_tdf.h"      /* access on WDT */

#include "ADLATUS_ApplicationInterface_tdf.h" /* Basic Application Interface  */

/* ========================================================================== */
/* (3)  C O M P I L E R   S W I T C H   S E T T I N G S                       */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */
/* Global Compiler switch settings are done at ADLATUS_CompilerSwitches_CDF.h */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Local compiler switches: No Entry                                          */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* ========================================================================== */
/* (4)  D A T A   S E C T I O N   D I R E C T I V E S                         */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */
/* NO ENTRY                                                                   */

/* ========================================================================== */
/* (5)  L O C A L   D E F I N E S                                             */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */
/* NO ENTRY                                                                   */

/* ========================================================================== */
/* (6)  L O C A L  T Y P E   D E F I N E S                                    */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */
/* NO ENTRY                                                                   */

/* ========================================================================== */
/* (7)  L O C A L   V A R I A B L E S  / C O N S T A N T S                    */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */
/* NO ENTRY                                                                   */

/* ========================================================================== */
/* (8)  L O C A L   F U N C T I O N   P R O T O T Y P E S                     */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */
/* NO ENTRIES                                                                 */

/* ========================================================================== */
/* (9)  G L O B A L   V A R I A B L E S                                       */
/* -------------------------------------------------------------------------- */
/*      D E F I N E D   W I T H I N   T H I S   M O D U L                     */
/* ========================================================================== */

/*+--------------------------------------------------------------------------+*/
/*| LINKER / LOCATER INFORMATION 01                                          |*/
/*+--------------------------------------------------------------------------+*/
/* --> --> --> --> --> --> --> --> --> --> --> --> --> --> --> --> --> --> -->*/
/*
#pragma DATA_SECTION (gt_CCapplint_FlashRequest_UL,".REQUEST") */
ULONG gt_CCapplint_FlashRequest_UL;

/* <-- <-- <-- <-- <-- <-- <-- <-- <-- <-- <-- <-- <-- <-- <-- <-- <-- <-- <--*/
/*+--------------------------------------------------------------------------+*/
/*| LINKER / LOCATER INFORMATION 01                                          |*/
/*| END OF "FSWInterface"                                                    |*/
/*+--------------------------------------------------------------------------+*/


/* ========================================================================== */
/* (10) F U N C T I O N   D E F I N I T I O N S                               */
/* -------------------------------------------------------------------------- */
/*      F O R   T H I S   M O D U L                                           */
/* ========================================================================== */


/*-----------------------------------------------------------------------------+
|    F U N C T I O N   I N F O R M A T I O N                                   |
+------------------------------------------------------------------------------+
|                                                                              |
|  Function Name:  FUN_CCapplint_JumpToFSW_V                                   |
|                                                                              |
|  Prototype at:   ADLATUS_ApplicationInterface_TDF.h                          |
|                                                                              |
|  Description:    Entry function to customers application software.           |
|                                                                              |
|  Parameter:      -                                                           |
|                                                                              |
|  Return Value:   -                                                           |
|                                                                              |
+-----------------------------------------------------------------------------*/
void FUN_CCapplint_JumpToFSW_V (void)
{
  /* Ptr to Dummy Function                                                    */
  void (*FUN_CCapplint_FswEntry_PFUN) (void);

  /*--------------------------------------------------------------------------*/
  /* Make it ready for execution                                              */
  /*--------------------------------------------------------------------------*/
  FUN_CCapplint_FswEntry_PFUN = (PTR_TO_FKT_VOID_VOID) d_CCadrinfo_AswEntryAddress;  /*l_int !e923 */

  /*--------------------------------------------------------------------------*/
  /* before jumping to FSW we will trigger the external WDT's a last time     */
  /* call trigger function with parameter t_WtdogTimerTicks_UW = 100ms to     */
  /* force the trigger */
  /*--------------------------------------------------------------------------*/
/*  FUN_CCwtdog_TriggerExtWatchdog_V((UWORD)100); */
  /*--------------------------------------------------------------------------*/
  /* Time to say GoodBye! Best wishes from SMART GmbH and have a nice day.    */
  /*--------------------------------------------------------------------------*/
   FUN_CCapplint_FswEntry_PFUN ();

} /*-+- END OF FUNCTION 'FUN_CCapplint_JumpToFSW_V'    -+-+-+-+-+-+-+-+-+-+-+-*/



/*-----------------------------------------------------------------------------+
|    F U N C T I O N   I N F O R M A T I O N                                   |
+------------------------------------------------------------------------------+
|                                                                              |
|  Function Name:  FUN_CCapplint_CheckFlashRequest_UB                          |
|                                                                              |
|  Prototype at:   ADLATUS_ApplicationInterface_TDF.h                          |
|                                                                              |
|  Description:    Entry function checks if a flash request is occured.        |
|                                                                              |
|  Parameter:      -                                                           |
|                                                                              |
|  Return Value:   UBYTE t_Result_UB .. 0x00 No FlashRequest                   |
|                                       0x??    FlashRequest                   |
|                                                                              |
+-----------------------------------------------------------------------------*/
UBYTE FUN_CCapplint_CheckFlashRequest_UB (void)
{
	UBYTE t_Result_UB = d_CCglo_NoFSWFlashRequest;

	/*==========================================================================*/
  	/* -1-                                                                      */
  	/* Flash Request VW / AUDI access                                           */
  	/* ------------------------------                                           */
  	/* VW / AUDI access is working on Channel 00                                */
  	/*==========================================================================*/
  	if (d_CCcusint_FlashRequestAudi == gt_CCapplint_FlashRequest_UL)
  	{
  		t_Result_UB = (d_CCglo_FSWFlashRequest | d_CCglo_Channel00);
  	}
  	/*==========================================================================*/
  	/* -1- no Flash Request                                                     */
  	/*==========================================================================*/
  	else
  	{
  		/*========================================================================*/
  		/* -2-                                                                    */
  		/* ECU Reset Request VW / AUDI access                                     */
  		/* ----------------------------------                                     */
  		/* VW / AUDI access is working on Channel 00                              */
  		/*========================================================================*/
  		if (d_CCcusint_EcuResetRequestAudi == gt_CCapplint_FlashRequest_UL)
  		{
  			t_Result_UB = (d_CCglo_FSWEcuResetRequest | d_CCglo_Channel00);
  		}
  		/*========================================================================*/  /* [OPL286] */
  		/* -2- no ECU Reset Request                                               */
  		/*========================================================================*/
  		else
  		{
  			/*======================================================================*/
  			/* -3-                                                                  */
  			/* Default Session Request VW / AUDI access                             */
  			/* ----------------------------------                                   */
  			/* VW / AUDI access is working on Channel 00                            */
  			/*======================================================================*/
/*  			if (d_CCcusint_DefSessionRequestAudi == gt_CCapplint_FlashRequest_UL)
  			{
  				t_Result_UB = (d_CCglo_FSWDefSessionRequest | d_CCglo_Channel00);
  			}*/
  		}
  	}


  return t_Result_UB;

} /*-+- END OF FUNCTION 'FUN_CCapplint_CheckFlashRequest_UB' -+-+-+-+-+-+-+-+-*/


/*-----------------------------------------------------------------------------+
|    F U N C T I O N   I N F O R M A T I O N                                   |
+------------------------------------------------------------------------------+
|                                                                              |
|  Function Name:  FUN_CCapplint_ResetFlashRequest_V                           |
|                                                                              |
|  Prototype at:   ADLATUS_ApplicationInterface_TDF.h                          |
|                                                                              |
|  Description:    This function resets the flash request from customers       |
|                  application software.                                       |
|                                                                              |
|  Parameter:      -                                                           |
|                                                                              |
|  Return Value:   -                                                           |
|                                                                              |
+-----------------------------------------------------------------------------*/
void FUN_CCapplint_ResetFlashRequest_V (void)
{
	gt_CCapplint_FlashRequest_UL = 0x00000000ul;

	return;
} /*-+- END OF FUNCTION 'FUN_CCapplint_ResetFlashRequest_V' -+-+-+-+-+-+-+-+-+*/


/*-----------------------------------------------------------------------------+
|    F U N C T I O N   I N F O R M A T I O N                                   |
+------------------------------------------------------------------------------+
|                                                                              |
|  Function Name:  FUN_CCapplint_SetFlashRequest_V                             |
|                                                                              |
|  Prototype at:   ADLATUS_ApplicationInterface_TDF.h                          |
|                                                                              |
|  Description:    This function sets the flash request to show the adlatus    |
|                  that the programming session had been started in the        |
|                  application software                                        |
|                                                                              |
|  Parameter:      -                                                           |
|                                                                              |
|  Return Value:   -                                                           |
|                                                                              |
+-----------------------------------------------------------------------------*/
void FUN_CCapplint_SetFlashRequest_V (void)
{
	/*--------------------------------------------------------------------------*/
	/* set the ECU reset request                                                */
	/*--------------------------------------------------------------------------*/
	gt_CCapplint_FlashRequest_UL = d_CCcusint_FlashRequestAudi;

	return;
} /*-+- END OF FUNCTION 'FUN_CCapplint_SetFlashRequest_V' +-+-+-+-+-+-+-+-+-+-*/

/* ========================================================================== */
/*      E N D   O F   F I L E                                                 */
/* ========================================================================== */
