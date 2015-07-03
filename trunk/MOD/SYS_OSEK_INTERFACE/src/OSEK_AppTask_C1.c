/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     OSEK_AppTask_C1.c
*-----------------------------------------------------------------------------
* Module Name:    MOD_OSEK
*-----------------------------------------------------------------------------
* Description:    file to provide the Init and Task body for the
*                 AppTask_event_5ms.
*-----------------------------------------------------------------------------
* $Date: 2011-07-19 13:19:03 +0200 (Di, 19 Jul 2011) $
* $Rev: 20942 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/SYS_OSEK_INTERFACE/trunk/src/OSEK_AppTask_C1.c $
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
#include "OSEK_AppTask_H1.h"
#include "APP_CSHDL.h"
#include "APP_INFO.h"
#include "APP_DIAG.h"
#include "OSEK_AppTask_Alarm.h"
#include "APP_COMMON_AT_Dispatcher.h"
#include "OSEK_AppTask_C1.id"
#include "TRACE.h"

/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/
EEDeviceControlBlockType EEAppTaskControl;
/*----------------------------------------------------------------------------*/
/* Global const Definitions                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Prototypes of private Methods                                              */
/*----------------------------------------------------------------------------*/
EEDeviceControlBlockType* getEEAppTaskControl(void);
static void AppTask_vHandleEvent(EventMaskType event);

/*----------------------------------------------------------------------------*/
/* Private Code Macros                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Variables                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private const Definitions                                                  */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Function    : getEEAppTaskControl                                          */
/**
    \brief      Description:
                Register the adress on the structure for getEEAppTaskControl
                for the OSEK_AppTask task

    \return     EEDeviceControlBlockType*
   */
/*----------------------------------------------------------------------------*/
EEDeviceControlBlockType* getEEAppTaskControl(void)
{
    return &EEAppTaskControl;
}

/*----------------------------------------------------------------------------*/
/* Function    : InitAppTask                                                  */
/**
    \brief      Callback function for initialization of OsAppTask_event_100ms

    \brief      Description:
                Interface function to initialize the OsAppTask_event_100ms, this
				function will be only called one time during first activation
				of OSAppTask_event_5ms

    \return     SuccessFailType
    			Status of function run
    			SUCCESS, FAIL
   */
/*----------------------------------------------------------------------------*/
SuccessFailType InitAppTask(void)
{
    SuccessFailType sF = SUCCESS;

    getEEAppTaskControl()->priority = EEPromHIGH_PRIORITY;
    (void)EEPROM_sfInit(getEEAppTaskControl());

    _AppTask_vInitAlarm();

    (void)APP_CSHDL_sfInitApp();
    (void)APP_INFO_sfInitApp();

    (void)SetRelAlarm(CTA_APP, MSEC(CTA_APP_CYCLIC_TIME), 0);

    return(sF);
}


/*----------------------------------------------------------------------------*/
/* Function    : AppTask_vHandleEvent                                         */
/**
    \brief      Handles evActivateAppTAppTask_event_100msnt

    \param      event
                EventMaskType
                Bitmask containing all unhandled events

    \return     void
   */
/*----------------------------------------------------------------------------*/
void AppTask_vHandleEvent(EventMaskType event)
{
    if( event & evActivateAppTask_event_100ms )
    {
	    (void)ClearEvent(evActivateAppTask_event_100ms);
        _AppTask_vHandleAlarm();
    }
}

/*----------------------------------------------------------------------------*/
/* Function    : AppTask_event_100ms                                            */
/**
    \brief      Callback function for OsAppTask_event_100ms

    \brief      Description:
                Interface function from the OsAppTask_event_100ms this function
				will be activated by event and can be restarted by the task
				self with an static alarm (CTA_APP) which sets an event.
				The application functions are responsible to set an absolute alarm
				( not cyclic alarm ). The alarm should be newly set everytime the Application
				needs it.

    \return     void
   */
/*----------------------------------------------------------------------------*/
void AppTask_event_100ms(void)
{
    EventMaskType events;
    // cyclically called every CTA_APP_CYCLIC_TIME ms
	(void)WaitEvent(  evActivateAppTask_event_100ms         |
                /* events indicating pending fcts */
                evAppTaskDiagnoseRequest                   |
                evAppTaskSystemStates                      |
                evAppTask_INFO_Request                     |
                evAppTaskApplResponse

                );


    (void)GetEvent(OsAppTask_event_100ms, &events);

    AppTask_vHandleEvent(events);

    APP_COMMON_vHandleEvents(events);

    APP_DIAG_vHandleEvents(events);

    APP_CSHDL_vHandleEvents(events);
    
    APP_INFO_vHandleEvents(events);
    return;
}

/* End Of File OSEK_AppTask_C1.c */
