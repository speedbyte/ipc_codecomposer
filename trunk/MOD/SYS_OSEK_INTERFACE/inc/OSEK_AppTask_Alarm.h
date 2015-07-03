/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:   OSEK_AppTask_Alarm.h
*-----------------------------------------------------------------------------
* Module Name:  MOD_OSEK
*-----------------------------------------------------------------------------
* Description:  Interface header for the AppTask_event_100ms
*-----------------------------------------------------------------------------
* $Date: 2009-03-17 10:33:33 +0100 (Di, 17 Mrz 2009) $
* $Rev: 5312 $
* $Author: rammelt $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/MOD/SYS_OSEK_INTERFACE/trunk/inc/OSEK_AppTask_H1.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _APPTASK_ALARM
#define _APPTASK_ALARM

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
#define CTA_APP_CYCLIC_TIME 10

/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/
typedef  void (*AppTaskAlarmCbType)( void );

typedef enum
{
    APP_TASK_ALARM_MDI_PLAYSTATE_UPDATE, // release at the first play state update
    APP_TASK_ALARM_MDI_PLAYSTATE_MONITOR, // verify once again the player state after the timeout
    APP_TASK_ALARM_MDI_USB_POWER_CONTROL, // controls the 5V on USB port in case of unreadable device
    APP_TASK_ALARM_MDI_PGMT_REQUEST,
    APP_TASK_ALARM_MDI_SEND_SIGNALS,
    APP_TASK_ALARM_MDI_RESTORE_FUNCT_STATUS,
    APP_TASK_ALARM_MDI_RESET_FUNCT_STATUS,
    APP_TASK_ALARM_MDI_RESET_ERROR,
    APP_TASK_ALARM_MDI_DGPS_REQUEST,
    APP_TASK_ALARM_MDI_DELAYED_DPLY_AFTER_CALL,
    APP_TASK_ALARM_MDI_RESET_CALL_INFORMATION_TIMEOUT,
    APP_TASK_ALARM_MDI_ALIN_TIMEOUT,
    APP_TASK_ALARM_APP_CONNECTION_PAIRING,
    APP_TASK_ALARM_APP_CONNECTION_BTDEBONDDEVICE_RETRY,
    APP_TASK_ALARM_APP_CONNECTION_DELAYED_BT_PIN,
    APP_TASK_ALARM_APP_CONNECTION_ACTIVATION_TIMEOUT,
    APP_TASK_ALARM_APP_CONNECTION_BT_UPDATE_TIMER,
    APP_TASK_ALARM_APP_CONNECTION_DELAYED_PHONE_STATUS,
    APP_TASK_ALARM_APP_PHONE_DELAYED_BTFUNCT_STATUS,
    APP_TASK_ALARM_APP_PHONE_DELAYED_PHONE_IDLE,
    APP_TASK_ALARM_APP_PHONE_TIMEOUT_OUTGOING_CALL,
    APP_TASK_ALARM_APP_PHONE_DELAYED_PAVS,
    APP_TASK_ALARM_AUDIO_MANAGER_A2DP_TIMEOUT,
    /* max number of alarm */
    APP_TASK_ALARM_MAX

}APP_TASK_enAlarmType;


typedef struct
{
    AppTaskAlarmCbType cb;
    TickType expires;
}AppTaskAlarmEntryType;

/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global const Declarations                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/
void _AppTask_vInitAlarm();
void _AppTask_vHandleAlarm();
void AppTask_vSetAlarm(APP_TASK_enAlarmType alarmType, TickType ms, AppTaskAlarmCbType cb);
void AppTask_vClearAlarm(APP_TASK_enAlarmType alarmType);
BooleanType AppTask_bGetAlarm(APP_TASK_enAlarmType alarmType);
/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/





#endif /* _APPTASK_ALARM */

/* End Of File OSEK_AppTask_Alarm.h */
