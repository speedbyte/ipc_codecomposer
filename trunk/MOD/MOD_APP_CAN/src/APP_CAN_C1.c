/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     APP_CAN_C1.c
*-----------------------------------------------------------------------------
* Module Name:    APP_CAN
*-----------------------------------------------------------------------------
* Description:    Handle CAN related doings for the applications
*-----------------------------------------------------------------------------
* $Date: 2011-07-20 16:38:51 +0200 (Mi, 20 Jul 2011) $
* $Rev: 20971 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_CAN/trunk/src/APP_CAN_C1.c $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/
#include <osek.h>           // vector
#include <osekext.h>        // vector

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*---------------------------------------------------------------------------- */
#include "ccl_inc.h"
#include "APP_CAN_C1.id"
#include "TRACE.h"
#include "ccl_inc.h"
#include "EEPROM.h"
#include "OSEK_HostTask_H1.h"
#include "EEPROM_LAYOUT.h"
#include "SPI.h"
#include "PORT.h"
#include "deh.h"
#include "il_inc.h"
#include "APP_COMMON_Utils.h"
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/
AppCanContextType gAppCanContext;
/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the type
*/

/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                     */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the macros
*/

/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the private constant
*/
/*Baud rate defines*/
#define SLEEPDELAY      430
/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function    : FunctionName                                                 */
/**
    \brief      Short description

    \brief      Description:
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    \param      EEP_Position

    \param      BlockSize_u16

    \param		Buffer_u8

    \return     CommonResponseCodeType
   */
/*----------------------------------------------------------------------------*/
void APP_CAN_vInit(void)
{
    (void)memset(&gAppCanContext, 0, sizeof(AppCanContextType));
    gAppCanContext.bNWDFdet = BT_TRUE;
    gAppCanContext.sleepDelayTimer = SLEEPDELAY;
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_CAN_u8DTCStore                                        */
/** 
    \brief      Function to check the Klemme 15 status, the NWDF status \n
                and outside of the voltage range for set the DTC. 
               
    \return     BooleanType
    			BT_TRUE, BT_FALSE
*/
/*----------------------------------------------------------------------------*/
BooleanType APP_CAN_bDTCStore(void)
{
    BooleanType retVal = BT_FALSE;

    if((OFF == IlGetRxZAS_Kl_15()) ||
       (FALSE == Pwrmgr_GetCurrentScope()) || (BT_FALSE == gAppCanContext.bNWDFdet))
    {
        retVal = BT_FALSE;
    }
    else
    {
        retVal = BT_TRUE;
    }
    return (retVal);
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_CAN_u8Klemme15Status                                     */
/** 
    \brief      Function to check Klemme 15 status. 
                               
    \return     Uint8Type
    			Status of Klemme 15
    			ON or OFF
*/
/*----------------------------------------------------------------------------*/
Uint8Type APP_CAN_u8Klemme15Status(void)
{
    return (IlGetRxZAS_Kl_15());
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_CAN_u8EigenDiagDTCStore                                        */
/**
    \brief      Function to check the Klemme 15 status, the NWDF status \n
                and outside of the voltage range for set the Eigen Diagnose DTC.

    \return     BooleanType
    			BT_TRUE, BT_FALSE
*/
/*----------------------------------------------------------------------------*/
BooleanType APP_CAN_bEigenDiagDTCStore(void)
{
    return (gAppCanContext.selfDiagnosisDtcStatus);
}

/*----------------------------------------------------------------------------*/
/* Function    :  APP_CAN_vSelfDiagnosisDtcCheck                              */
/**
    \brief      Function to check cyclic the Klemme 15 status, the NWDF status, \n
                outside of the voltage range for set the Eigen Diagnose DTC and \n
                the timer for self diagnosis.

    \return     none
*/
/*----------------------------------------------------------------------------*/
void APP_CAN_vSelfDiagnosisDtcCheck(void)
{
    if(gAppCanContext.sleepDelayTimer > 0)
    {
        gAppCanContext.sleepDelayTimer--;
    }

    if (1 == DEH_GET_CAN_EVENT_BIT)
    {
        IlPutTxHU_KD_Fehler(DEH_GET_CAN_EVENT_BIT);
    }

    if(BT_FALSE == APP_CAN_bDTCStore())
    {
        if (BT_TRUE == APP_COMMON_UTILS_bIsAlarmActive(CTA_HOST_SELF_DIAG_TIMER))
        {
            (void)APP_COMMON_UTILS_stCancelOsekRelAlarm(CTA_HOST_SELF_DIAG_TIMER);
        }
        IlRxWait();
        gAppCanContext.selfDiagnosisDtcStatus = BT_FALSE;
        gAppCanContext.selfDiagnosisStatusState = APP_CAN_SELF_DIAGNOSIS_START_TIMER;
    }
    else
    {
        switch (gAppCanContext.selfDiagnosisStatusState)
        {
            case APP_CAN_SELF_DIAGNOSIS_START_TIMER:
            {
                DEBUG_TEXT(APP_CAN_SWI_TRC, MOD_APP_CAN, "vSelfDiagnosisDtcCheck start timer");
                (void)APP_COMMON_UTILS_stSetOsekRelAlarm(CTA_HOST_SELF_DIAG_TIMER, MSEC(2000), 0);
                gAppCanContext.selfDiagnosisStatusState = APP_CAN_SELF_DIAGNOSIS_TIMER_WAITING;
                break;
            }
            case APP_CAN_SELF_DIAGNOSIS_TIMER_WAITING:
            {
                break;
            }
            case APP_CAN_SELF_DIAGNOSIS_ENABLE_SELF_DIAG:
            {
                IlRxRelease();
                DEBUG_TEXT(APP_CAN_SWI_TRC, MOD_APP_CAN, "vSelfDiagnosisDtcCheck is active");
                gAppCanContext.selfDiagnosisDtcStatus = BT_TRUE;
                gAppCanContext.selfDiagnosisStatusState = APP_CAN_SELF_DIAGNOSIS_ENABLE_SELF_DIAG_WAITING;
                break;
            }
            case APP_CAN_SELF_DIAGNOSIS_ENABLE_SELF_DIAG_WAITING:
            default:
                // wait until timer is expired
                break;
        }
    }
}

ALARMCALLBACK(APP_CAN_cbHostSelfDiagnosisTimer)
{
    gAppCanContext.selfDiagnosisStatusState = APP_CAN_SELF_DIAGNOSIS_ENABLE_SELF_DIAG;
}


/*----------------------------------------------------------------------------*/
/* Function    : APP_CAN_u8GetNWDF                                           */
/** 
    \brief      Function to check the NWDF status
    
    \return     BooleanType
    			BT_TRUE, BT_FALSE
*/
/*----------------------------------------------------------------------------*/
BooleanType APP_CAN_bGetNWDF(void)
{
    return(gAppCanContext.bNWDFdet);
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_CAN_bIsDiagnose1MessageReceived                         */
/**
    \brief     
 
    \return     BooleanType
    			BT_TRUE, BT_FALSE
*/
/*----------------------------------------------------------------------------*/
BooleanType APP_CAN_bIsDiagnose1MessageReceived(void)
{
    return (gAppCanContext.bDiagnose_1_MsgReceived);
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_CAN_SleepDelayTimer                                      */
/** 
    \brief      Get the current SleepDelayTimer
               
    \return     Uint16Type
    			all values
*/
/*----------------------------------------------------------------------------*/
Uint16Type APP_CAN_SleepDelayTimer(void)
{
    return gAppCanContext.sleepDelayTimer;
}

/* End Of File APP_CAN_C1.c */
