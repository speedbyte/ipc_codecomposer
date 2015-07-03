/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/** 
 * \file 	APP_DIAG_ID_CHART.h
 * \brief	C File Header. 
 * 			This file must be included by the C File in order to use the 
 * 			constants, variables etc declared in this file. Detailed description found below. 
 * \brief	Detailed description of the file.
*/
/*-----------------------------------------------------------------------------
* $Date: 2011-06-15 07:54:55 +0200 (Mi, 15 Jun 2011) $
* $Rev: 20138 $
* $Author: kolozsvary $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_DIAG/trunk/inc/APP_DIAG_ID_CHART.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _APP_DIAG_ID_CHART_H
#define _APP_DIAG_ID_CHART_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/

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

/*CalibrationDataWritable*/
// TODO: Clean up  0x0317, CASE_ALL_ID_ANPASSUNG. Service 31 should be
// called directly from sds_ext.c without the intervention of Service2E.
typedef enum
{
ID_31_0202_On_Demand_Self_Test                      = 0x0202,
ID_31_F000_MICROPHONE_LOOPBACK                      = 0xF000,
ID_31_F001_AUX_LOOPBACK                             = 0xF001,
ID_31_F002_USB_PLAY                                 = 0xF002,
ID_2E_D131_REMOTE_ASSESSORY_DEVICE_NAME             = 0xD131,
ID_22_FD03_CK5050_SERIAL_NUMBER                     = 0xFD03,
ID_31_F003_RESET_TO_FACTORY_SETTINGS                = 0xF003,
ID_22_FD00_BLUETOOTH_MAC_ADDRESS                    = 0xFD00,
ID_22_911A_CRADLE_AND_PHONE_CONNECTION_STATE        = 0x911A,
ID_22_911B_ACTIVE_PHONE_INDEX                       = 0x911B,
ID_22_9101_VOICE_PROMPT_LANGUAGE_SELECTED           = 0x9101,
ID_22_E103_CAR_CONFIGURATION_PARAM_FAULTS           = 0xE103,
ID_22_FD09_APPLEIC_RESULT                           = 0xFD09,
ID_2E_FD02_PRODUCTION_FLAG                          = 0xFD02
} APP_DIAG_ENUM_DIAGNOSE_ID;

#define ID_31_0202_On_Demand_Self_Test                      0x0202
#define ID_31_F000_MICROPHONE_LOOPBACK                      0xF000
#define ID_31_F001_AUX_LOOPBACK                             0xF001
#define ID_31_F002_USB_PLAY                                 0xF002
#define ID_2E_D131_REMOTE_ASSESSORY_DEVICE_NAME             0xD131
#define ID_22_FD03_CK5050_SERIAL_NUMBER                     0xFD03
#define ID_31_F003_RESET_TO_FACTORY_SETTINGS                0xF003
#define ID_22_FD00_BLUETOOTH_MAC_ADDRESS                    0xFD00
#define ID_22_911A_CRADLE_AND_PHONE_CONNECTION_STATE        0x911A
#define ID_22_911B_ACTIVE_PHONE_INDEX                       0x911B
#define ID_22_9101_VOICE_PROMPT_LANGUAGE_SELECTED           0x9101
#define ID_22_E103_CAR_CONFIGURATION_PARAM_FAULTS           0xE103
#define ID_22_FD09_APPLEIC_RESULT                           0xFD09
#define ID_2E_FD02_PRODUCTION_FLAG                          0xFD02
#define ID_22_FD11_CK5050_ACTIVE_LANGUAGE                   0xFD11
#define ID_22_FD12_BLUETOOTH_LINK_KEY                       0xFD12
					 
#define SERVICE_FKT_START_EIN                                          0x01
#define SERVICE_FKT_START_AUS                                          0x02
#define SERVICE_FKT_STOP_LAST_STATE                                    0x03

#endif /* _APP_DIAG_ID_CHART_H */

/* End Of File APP_DIAG_ID_CHART.h */

