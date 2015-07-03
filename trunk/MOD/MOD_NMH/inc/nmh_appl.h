/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/* File Name:     nmh_appl.h
*-----------------------------------------------------------------------------
* Module Name:    NMH
*-----------------------------------------------------------------------------
* Description:    Describe all DTC for the UHVNAR system 
*-----------------------------------------------------------------------------
* $Date:  $
* $Rev:  $
* $Author:  $
* $URL:  $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/
/*---------------------------------------------------------------------------*/
/* Event Fault data block for DEH Handler                                    */
#define NM_SIGNAL_BYTE_DEFAULT                  0x00
 /* NWM wakeup - Byte 3                   */
#define NM_WAKE_UP_NO_RESET                     0x00
#define NM_WAKE_UP_KLEMME_30_RESET              0x00
#define NM_WAKE_UP_KLEMME_30_RESET_VALUE        0x02
#define NM_WAKE_UP_CAN_WAKE_UP                  0x01
/* NWM after-running reason - Byte 4      */
#define NM_WAKE_UP_KLEMME_15_ON                 0x01
#define NM_DIAGNOSE_ON_WO_KL15                  0x02
#define NM_OSEKNM_MIN_ACTIVETIME                0x04
#define NM_OSEKNM_CALL_ACTIVETIME               0x08
#define NM_OSEKNM_MEDIASTREAM_ACTIVETIME        0x10
/* NWM after-running reason - Byte 5      */
//#define NM_WAKE_UP_LOKAL_FUNC_POWER_ACTIVE      0x02
//#define NM_WAKE_UP_TELEFON_SLEEP_POWER_ACTIVE   0x01
/* NWM systeminfo - Byte 6                */
#define NM_SIGNAL_ERROR_STORED                  0x01
#define NM_TIME_OUT_ERROR_STORED                0x02
#define NM_SELF_DIAG_DEACTIVATED                0x04
#define NM_KSB_FUNCTION_QUALIFICATION           0x08
#define NM_MUTE_ACTIV                           0x10
#define NM_FUNC_LIMIT_TRANSPORTMODUS            0x20
#define NM_FUNCTIONAL_SHUTOFF                   0x40
#define NM_ONE_WIRE_MODE                        0x80
/*---------------------------------------------------------------------------*/
void NMH_vNmCyclicTask(void);

