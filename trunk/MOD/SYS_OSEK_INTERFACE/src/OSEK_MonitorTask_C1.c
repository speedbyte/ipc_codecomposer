/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     OSEK_MonitorTask_C1.c
*-----------------------------------------------------------------------------
* Module Name:    MOD_OSEK
*-----------------------------------------------------------------------------
* Description:    file to provide the Init and Task body for the
*                 MonitorTask_50ms.
*-----------------------------------------------------------------------------
* $Date: 2011-07-19 13:19:03 +0200 (Di, 19 Jul 2011) $
* $Rev: 20942 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/SYS_OSEK_INTERFACE/trunk/src/OSEK_MonitorTask_C1.c $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include <osek.h>

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "Common.h"
#include "OSEK_MonitorTask_H1.h"
#include "Pwrmgr.h"
#include "GIO.h"
#include "MONITOR_ADC.h"
#include "APP_DTC.h"
#include "UART.h"
#include "Pwrmgr.h"
#include "Crcmgr.h"
#include "OSEK_Utils.h"
#include "EEPROM_LAYOUT.h"
#include "TRACE.h"
#include "OSEK_MonitorTask_C1.id"
#include "TEMPERATURE.h"
#include "deh.h"
#include "DEH_DTC_CFG.h"
#include "IPC.h"
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global const Definitions                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/
EEDeviceControlBlockType EEMonitorControl;

/*----------------------------------------------------------------------------*/
/* Prototypes of private Methods                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Code Macros                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Variables                                                          */
/*----------------------------------------------------------------------------*/
static TickType statisticTime = 0;

/*----------------------------------------------------------------------------*/
/* Private const Definitions                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function    : getEEMonitorControl                                          */
/**
    \brief      Register the adress on the structure for EEcontrol for the
                database task

    \return     EEDeviceControlBlockType*

   */
/*----------------------------------------------------------------------------*/
EEDeviceControlBlockType* getEEMonitorControl(void)
{
    return &EEMonitorControl;
}


/*----------------------------------------------------------------------------*/
/* Function    : InitMonitorTask                                              */
/**
    \brief      Callback function for initialization of OsMonitorHostTask

    \brief      Description:
				Callback function to initialize the OsMonitorTask_50ms this
				function will be only called one time during first activation
				of OsMonitorTask_50ms

    \return     SuccessFailType
    			Status of function run
    			SUCCESS, FAIL
   */
/*----------------------------------------------------------------------------*/
SuccessFailType InitMonitorTask(void)
{
    SuccessFailType sF = SUCCESS;

    getEEMonitorControl()->priority = EEPromHIGH_PRIORITY;
    (void)EEPROM_sfInit(getEEMonitorControl());

    /* Initialization of the Power Manager */
    sF = Pwrmgr_Init();
    (void)SetRelAlarm(CTA_MONITOR_AUDIO, MSEC(10), MSEC(2000));
    /* sets evMonitorTask_MonitorAudio_for_DTC */
    return(sF);
}


/*----------------------------------------------------------------------------*/
/* Function    : MonitorTask_50ms                                             */
/**
    \brief      Callback function for OsMonitorTask_50ms

    \brief      Description:
                Callback function from the OsMonitorTask_50ms this function
               	will be cyclic called all 50ms

    \return     void
   */
/*----------------------------------------------------------------------------*/
void MonitorTask_50ms(void)
{
    SuccessFailType sF = SUCCESS;
    EventMaskType events;
  	(void)WaitEvent(evActivateMonitorTask_50ms |
			evMonitorTask_MonitorAudio_for_DTC);
	(void)ClearEvent(evActivateMonitorTask_50ms);

	(void)GetEvent(OsMonitorTask_50ms, &events);

    /* activation for the crc manager to check the eeprom and ROM consistency */
    CrcManager();

    (void)MONITOR_ADC_sfReadADCValueForDTCs();
    APP_DTC_vStartupSequence();
    APP_DTC_vFastRampUpPinsDiagnostics();

    (void)Pwrmgr_Manager_Handler_For_Rapid_Voltage_Changes();

    /* Eindrahtbetrieb Can */
    if(LOW == GIO_u8PinRead(PORT_CAN_ERROR, GIOA))
    {
        DEBUG_TEXT(OSEK_INTERFACE_SWI_ERR, MOD_OSEK_INTERFACE, " !!! One Line CAN Betrieb!!!!!")
        (void)DEH_AdditionalReportEvent(DTC_C12001_EINDRAHT_FEHLER, TRUE);
    }
    else
    {
        (void)DEH_AdditionalReportEvent(DTC_C12001_EINDRAHT_FEHLER, FALSE);
    }

    /* activation for the DTC manager to check radio mute, microphone, audio and 3 button states */
    if( events & evMonitorTask_MonitorAudio_for_DTC )
    {
    	(void)ClearEvent(evMonitorTask_MonitorAudio_for_DTC);
        /* activation for the temperature manager to check the device temperature */
        sF = TEMPERATURE_sfManager();
        /* Activation for the power manager to check the Battery voltage */
        /* Attention - Call only every 2 sec */
        sF = Pwrmgr_Manager();
        APP_DTC_vSoftwareDiagnostics();
        APP_DTC_vSlowRampUpPinsDiagnostics();
        /* TODO: seperate Alarm 1 seconds */
        IPC_vMonitorCommunication();
    }
    IPC_vWriteManager();

    if(statisticTime == 0)
    {
        statisticTime = osGetSystemCounter();
    }

    if(osGetSystemCounter() > statisticTime + STATISTIC_TIME_MS)
    {
        statisticTime = osGetSystemCounter();
        UART_PrintStatistic(UART1);
        UART_PrintStatistic(UART2);
        OSEK_TaskStackStatistic();
#if defined(USE_DEBUGGING_WITH_TRACE_ID)
        Trace_PrintStatistic();
#endif
    }
    EEPROM_LAYOUT_vCheckPendingFlags();
    sF = sF;
    return;
}

/* End Of File OSEK_MonitorTask_C1.c */
