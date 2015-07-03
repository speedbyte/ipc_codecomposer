/******************************************************************************/
/*****************  Copyright (c) 2011 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
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
#include "Common.h"
#include "nmh_appl.h"
#include "nmh.h"
#include "GIO.h"
#include "desc.h"
#include "APP_DESC.h"
#include "NM_CB_cfg.h"
#include "APP_CAN.h"
#include "ccl_inc.h"
#include "deh.h"
#include "DEH_DTC_CFG.h"
#include "nmh_appl.id"
#include "TRACE.h"


/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function    : APP_CAN_IL_CheckSignalReception_CSHDL                                              */
/**
    \brief      CSHDL

    \brief      Description:
                This function is called cyclically and informs the CSHDL about the current
                status.

    \param      void
    \return     void
 */
/*----------------------------------------------------------------------------*/

void NMH_vNmCyclicTask(void)
{
    tNmhStateType nmState;
    Uint8Type *userDataPtr;
    Uint8Type i=0;

    Uint8Type nmDiagSession     = (Uint8Type)ApplDescGetActiveDiagnosticSession();
    Uint8Type nmKlemme15        = (Uint8Type)IlGetRxZAS_Kl_15();
    Uint8Type nmNWDF            = (Uint8Type)APP_CAN_bGetNWDF();
    Uint8Type nmCurrentScope    = (Uint8Type)Pwrmgr_GetCurrentScopeEigenDiag();
    userDataPtr = 0;
     /*get network management state*/
    nmState = NmhGetState();
    /*safe network state in user data frame*/
    *(userDataPtr) =  (Uint8Type) nmState;

    /*get pointer to user data buffer*/
    userDataPtr = NmhGetUserDataBuffer();
    /* set NW-Bytes 3-8 with default values                                 */
    *(userDataPtr)  = NM_SIGNAL_BYTE_DEFAULT;
    *(userDataPtr+1)= NM_SIGNAL_BYTE_DEFAULT;
    *(userDataPtr+2)= NM_SIGNAL_BYTE_DEFAULT;
    *(userDataPtr+3)= NM_SIGNAL_BYTE_DEFAULT;
    *(userDataPtr+4)= NM_SIGNAL_BYTE_DEFAULT;
    *(userDataPtr+5)= NM_SIGNAL_BYTE_DEFAULT;

    /* NWM wakeup - Byte 2  */
    if(wakeupReason == NO_RESET)
    {
        DEBUG_TEXT(NM_SWI_DBG, MOD_NM, " !!! Wake Up No Reset!!!!!");
        *(userDataPtr) = NM_WAKE_UP_NO_RESET;
    }
    else if(wakeupReason == KLEMME30_RESET)
    {
        DEBUG_TEXT(NM_SWI_DBG, MOD_NM, " !!! Wake Up KL30 Reset!!!!!");
        *(userDataPtr) = NM_WAKE_UP_KLEMME_30_RESET_VALUE;
    }
    else if(wakeupReason == CAN_WAKE_UP)
    {
        DEBUG_TEXT(NM_SWI_DBG, MOD_NM, " !!! Wake Up Can Wake!!!!!");
        *(userDataPtr) = NM_WAKE_UP_CAN_WAKE_UP;
    }
    /* NWM after-running reason - Byte4                                     */
    /* Byte3,Bit0 - Klemme15 on                                             */
    if(ON == nmKlemme15)
    {
        DEBUG_TEXT(NM_SWI_DBG, MOD_NM, " !!! KL15 ON!!!!!");
        *(userDataPtr+1) |= NM_WAKE_UP_KLEMME_15_ON;
    }
    /* Byte3,Bit1 - Diagnose on with Klemme15 off                           */
    if((kDescStateSessionDefault != nmDiagSession) && (OFF == nmKlemme15))
    {
        DEBUG_VALUE1(NM_SWI_DBG, MOD_NM, " !!! DIAG ON KL15 Off!!!!! %x", nmDiagSession);
        *(userDataPtr+1) |= NM_DIAGNOSE_ON_WO_KL15;
    }
    /* Byte3,Bit2 - minimal active time for OSEK-NM                           */
    if(APP_CAN_SleepDelayTimer() > 0)
    {
        DEBUG_TEXT(NM_SWI_DBG, MOD_NM, " !!! Sleep Delay not expired!!!!!");
        *(userDataPtr+1) |= NM_OSEKNM_MIN_ACTIVETIME;
    }
    /* NWM systeminfo                                                       */
    /* Signalfehler Fehler - set bit 0                                       */
    for (i = DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG; i <= DTC_C120B5_SIGNALFEHLER_MITTELKONSOLE; i+=1)
    {
        if(((DEH_EventBuffer[i] & DEH_EVENT_ACTIVE)            == DEH_EVENT_ACTIVE)            ||
          ((DEH_EventBuffer[i] & DEH_EVENT_DEBOUNCE_ACTIVE)    == DEH_EVENT_DEBOUNCE_ACTIVE))
        {
            DEBUG_TEXT(NM_SWI_DBG, MOD_NM, " !!! CAN message: CAN Signal error !!!!!");
            *(userDataPtr+3) |= NM_SIGNAL_ERROR_STORED;
            break;
        }
    }
    /* NWM systeminfo                                                       */
    /* Can-TimeOut Fehler - set bit 1                                       */
    for (i = DTC_C12002_TIMEOUT_MOTORSTEUERUNG; i <= DTC_C1207F_TIMEOUT_MITTELKONSOLE; i+=1)
    {
        if(((DEH_EventBuffer[i] & DEH_EVENT_ACTIVE)            == DEH_EVENT_ACTIVE)            ||
          ((DEH_EventBuffer[i] & DEH_EVENT_DEBOUNCE_ACTIVE)    == DEH_EVENT_DEBOUNCE_ACTIVE))
        {
            DEBUG_TEXT(NM_SWI_DBG, MOD_NM, " !!! CAN message: one message is missing !!!!!");
            *(userDataPtr+3) |= NM_TIME_OUT_ERROR_STORED;
            break;
        }
    }
    /* Can bezogene Eigendiagnose - set bit 2                               */
    if((FALSE == nmCurrentScope) || (BT_FALSE == nmNWDF))
    {
        DEBUG_TEXT(NM_SWI_DBG, MOD_NM, " !!! No Eigen Diag allowed !!!!!");
        *(userDataPtr+3) |= NM_SELF_DIAG_DEACTIVATED;
    }
    /* Eindrahtbetrieb Can  - set bit 7                                     */
    if(LOW == GIO_u8PinRead(PORT_CAN_ERROR, GIOA))
    {
        DEBUG_TEXT(NM_SWI_TRC, MOD_NM, " !!! One Line CAN mode!!!!!");
        *(userDataPtr+3) |= NM_ONE_WIRE_MODE;
    }
}
/* End Of File nmh_appl.c */


