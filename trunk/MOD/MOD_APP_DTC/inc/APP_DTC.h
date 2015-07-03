/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/** 
 * \file 	APP_DTC.h
 * \brief	This file contains prototypes of all the functions that can be used
 * by other modules. Detailed description found below. 
 * \brief	It also contains enum, structure, constant definition etc. that can 
 * be used by other modules. The application/system must include this file 
 * in order to use the interfaces provided by this module.
*/
/*-----------------------------------------------------------------------------
* $Date: 2011-02-03 14:48:29 +0100 (Do, 03 Feb 2011) $
* $Rev: 17648 $
* $Author: agrawal $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_DTC/trunk/inc/APP_DTC.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _APP_DTC_H
#define _APP_DTC_H

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
#include "APP_DTC_CE.h"

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

/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/
SuccessFailType APP_DTC_sfInit(void);
void APP_DTC_vStartupSequence(void);
void APP_DTC_vSoftwareDiagnostics(void);
void APP_DTC_vFastRampUpPinsDiagnostics(void);
void APP_DTC_vSlowRampUpPinsDiagnostics(void);
Uint8Type APP_DTC_u8GetStatusMikroTelefon(void);
Uint8Type APP_DTC_u8GetStatusAudioLeft(void);
Uint8Type APP_DTC_u8GetStatusAudioRight(void);
BooleanType APP_DTC_bGetAudioAllowed(void);
void APP_DTC_vSetLeftChannelAudioMonitoring(BooleanType bLeftMonitoringValue);
Uint8Type APP_DTC_u8GetStatusRadioMute(void);
Uint8Type APP_DTC_u8GetStatusCoding(void);
Uint8Type APP_DTC_u8GetVariantType(void);

/*----------------------------------------------------------------------------*/


#endif /* _APP_DTC_H */

/* End Of File APP_DTC.h */


