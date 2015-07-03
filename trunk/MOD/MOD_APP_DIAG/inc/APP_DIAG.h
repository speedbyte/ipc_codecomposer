/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/** 
 * \file 	APP_DIAG.h
 * \brief	This file contains prototypes of all the functions that can be used
 * by other modules. Detailed description found below. 
 * \brief	It also contains enum, structure, constant definition etc. that can 
 * be used by other modules. The application/system must include this file 
 * in order to use the interfaces provided by this module.
*/
/*-----------------------------------------------------------------------------
* $Date: 2011-02-18 15:19:00 +0100 (Fr, 18 Feb 2011) $
* $Rev: 18030 $
* $Author: kolozsvary $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_DIAG/trunk/inc/APP_DIAG.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _APP_DIAG_H
#define _APP_DIAG_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include "Common.h"
#include "tms470r1.h"

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
/* include the export configuration file */
#include "APP_DIAG_CE.h"
#include "APP_DIAG_ID_CHART_PARAMS_LEN.h"
/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global const Declarations                                                  */
/*----------------------------------------------------------------------------*/
/* return values of the function SDSext_WriteUserAndIOData() */

typedef enum
{
	enAppDiagResponseOkImm           = 0,
	enAppDiagResponseErrorImm,
	enAppDiagResponseErrorBusyImm,
	enAppDiagResponseWaitForCallBack,
	enAppDiagResponseFurtherRequestsPending,
	enAppDiagResponseAbortDetRequest,
	enAppDiagResponseInvalid = 0xFF
} APP_DIAG_ENUM_RESPONSE_CODES;

typedef enum
{
	enAppDiagParrotSWVersion = 1,
	enAppDiagParrotDerivative,
	enAppDiagParrotBluetoothChipVersion
} APP_DIAG_ENUM_PARROT_DETAILS;

/* Message from Host-Diagnose (SDSext) to Application */
typedef struct {
     Uint16Type       Identifier;
     Uint8Type        data[APP_DIAG_MAX_DATA_LENGTH];
     Uint8Type        length;
} APP_DIAG_ST_DIAG_REQUEST, *APP_DIAG_PST_DIAG_REQUEST; 

/* Message from Application to Host-Diagnose (SDSext) */
typedef struct {
     Uint16Type               Identifier;
     Uint8Type                data[APP_DIAG_MAX_DATA_LENGTH];
     Uint8Type                length;
//     APP_DIAG_enResponseCode  result;
     Uint8Type                result;
} APP_DIAG_ST_DIAG_RESPONSE, *APP_DIAG_PST_DIAG_RESPONSE;

/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/

extern void APP_DIAG_SetAppleICTestResult( BooleanType bResult );

/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/
#ifdef IAPP_DIAG_INIT /* BEGIN DECLARE INTERFACE(IAPP_DIAG_INIT) */

void APP_DIAG_vHandleEvents(EventMaskType event);
SuccessFailType APP_DIAG_sfInit();
#endif

/*----------------------------------------------------------------------------*/


#endif /* _APP_DIAG_H */

/* End Of File APP_DIAG.h */


