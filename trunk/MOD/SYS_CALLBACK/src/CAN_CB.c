/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     CAN_CB.c
*-----------------------------------------------------------------------------
* Module Name:    MOD_CAN
*-----------------------------------------------------------------------------
* Description:    file to support all callback function of the CAN driver
*-----------------------------------------------------------------------------
* $Date: 2011-09-19 14:52:14 +0200 (Mo, 19 Sep 2011) $
* $Rev: 21831 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/SYS_CALLBACK/trunk/src/CAN_CB.c $
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
#include "ccl_inc.h"
#include "CAN_CB_cfg.h"

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "GIO.h"
#include "Port.h"
#include "spi.h"
#include "TRACE.h"
#include "CAN_CB.id"
#include "APP_CAN.h"  // DETECTION_DONE
#include "deh.h"
#include "DEH_DTC_CFG.h"
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/
static uint8 u8DiagNMHistory[5] = {0, 0, 0, 0, 0};

typedef enum
{
    CAN_NOTHING = 0,
    CAN_INIT    = 1,
    CAN_SLEEP   = 2,
    CAN_WAKEUP  = 3
} HWLoopcheckActionType;

/** 
 * \var demoCclPreventWakeUpStatus
 *      This variable represents the PWU status that is stored in the NVRAM. Within this demo it is only 
 *      stored in a static RAM variable.
 */
static vuint8 demoCclPreventWakeUpStatus;

/**
\brief	description of the type
*/

/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the method
*/
static void ApplCanResetTimer(CAN_CHANNEL_CANTYPE_FIRST vuint8 source);

/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                        */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the macros
*/
#define ApplCanWaitConfigChangeEnableLoopCounterLimit       ((vuint16)0xFFF0u)
#define ApplCanWaitPowerDownModeLoopCounterLimit            ((vuint16)0xFFF0u)
#define ApplCanWaitLeavePowerDownModeLoopCounterLimit       ((vuint16)0xFFF0u)
/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the private variable
*/
static CanRequests_CSHDL_MsgType     CanRequests_IL_CSHDL_MsgData;
static TriStateType BusActive = TS_UNKNOWN;
static TriStateType BusInWaitBusSleep = TS_UNKNOWN;

static HWLoopcheckActionType eHWLoopcheckAction = CAN_NOTHING;
/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the private constant
*/
static vuint16 ApplCanWaitConfigChangeEnableLoopCounter = 0;
static vuint16 ApplCanWaitPowerDownModeLoopCounter      = 0;
static vuint16 ApplCanWaitLeavePowerDownModeLoopCounter = 0;
/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/
void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhActiveFailed( NMH_CHANNEL_APPLTYPE_ONLY )
{
}


void CCL_API_CALLBACK_TYPE ApplCclFatalError(void)
{
    DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, " !!! ApplCclFatalError!");
}
VSTD_CALLBACK_0 void VSTD_CALLBACK_1 ApplVStdFatalError(vuint8 nErrorNumber)
{
    DEBUG_VALUE1(CALLBACK_SWI_ERR, MOD_CALLBACK, " !!! ApplVStdFatalError! with Error Number %d", nErrorNumber);
}

void CCL_API_CALLBACK_TYPE ApplCclLocalWakeup(void)
{
}

void CCL_API_CALLBACK_TYPE ApplCclSleep(void)
{
    /* Set event to System Task to switch Power supply off */
    DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, " !!! ApplCclSleep : Shut CAN !!!!!");
#ifndef UHV_BLUETOOTH_ZERTIFIZIERUNG_PBTESTMODE
    BusActive = TS_FALSE;
#endif
}

void CCL_API_CALLBACK_TYPE ApplCclNetworkWakeup(void)
{
    DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, "ApplCclNetworkWakeup");
}


void CCL_API_CALLBACK_TYPE ApplCclComStart(void)
{
    DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, "ApplCclComStart");
    BusActive = TS_TRUE;
}
void CCL_API_CALLBACK_TYPE ApplCclComStop(void)
{
    DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, "ApplCclComStop");
    BusInWaitBusSleep = TS_FALSE;
}
void CCL_API_CALLBACK_TYPE ApplCclComWait(void)
{
    DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, "ApplCclComWait");
    BusInWaitBusSleep = TS_TRUE;
}
void CCL_API_CALLBACK_TYPE ApplCclComResume(void)
{
    DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, "ApplCclComResume");
    /*CanRequests_IL_CSHDL_MsgData.CshdlID_Rq = NETWORKMANAGEMENT_ST_RQ;
    CanRequests_IL_CSHDL_MsgData.BusStatus_Requests.BusStatus = 0x2;
    (void)SendMessage(msgCshdl_Requests, &CanRequests_IL_CSHDL_MsgData);*/
    BusInWaitBusSleep = TS_FALSE;
}
void CCL_API_CALLBACK_TYPE ApplCclBusOffStart(void)
{
    DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, "ApplCclBusOffStart");
    (void)DEH_AdditionalReportEvent(DTC_C12000_BUS_OFF_FEHLER, TRUE);
}
void CCL_API_CALLBACK_TYPE ApplCclBusOffEnd(void)
{
    DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, "ApplCclBusOffEnd");
    (void)DEH_AdditionalReportEvent(DTC_C12000_BUS_OFF_FEHLER, FALSE);
}
void CCL_API_CALLBACK_TYPE ApplCclInitTrcv(void)
{
    /*switch transceiver to normal mode*/
    DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, " !!! ApplCclInitTrcv : CAN_EN->High CAN_STB->High");
    SPI_vPinModify(SPI5, SpiEnablePin, PortIoOutHigh);   // CAN_EN
    CAN_vPortSet(CAN3, RX);                                 // CAN_STB
}

void CCL_API_CALLBACK_TYPE ApplCclInit(void)
{
}

void CCL_API_CALLBACK_TYPE ApplCclWakeUpTrcv(void)
{
        /*switch transceiver to normal mode*/
        DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, " !!! ApplCclWakeUpTrcv : CAN_EN->High CAN_STB->High");
        SPI_vPinModify(SPI5, SpiEnablePin, PortIoOutHigh);   // CAN_EN
        CAN_vPortSet(CAN3, RX);                                 // CAN_STB
}
void CCL_API_CALLBACK_TYPE ApplCclStandbyTrcv(void)
{
        /*switch Trancseiver to stand-by mode*/
        DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, " !!! ApplCclStandbyTrcv : CAN_EN->Low CAN_STB->Low");
        SPI_vPinModify(SPI5, SpiEnablePin, PortIoOutLow);    // CAN_EN
        CAN_vPortClear(CAN3, RX);                               // CAN_STB
}

/*----------------------------------------------------------------------------*/
/* Function    : ApplCanAddCanInterruptDisable                                */
/**
    \brief      callback function from CAN driver

    \brief      Description:
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    \param      channel
                CanChannelHandle

    \return     void
   */
/*----------------------------------------------------------------------------*/
void ApplCanAddCanInterruptDisable(CanChannelHandle channel)
{
	channel = channel;
    *((volatile uint32*)osdREQMASK) &=~CAN1_INT_FLAG_CIM;   /* disable interrupt */
}/* END OF ApplCanAddCanInterruptDisable() */

/*----------------------------------------------------------------------------*/
/* Function    : ApplCanAddCanInterruptRestore                                */
/**
    \brief      callback function from CAN driver

    \brief      Description:
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    \param      channel
                CanChannelHandle

    \return     void
   */
/*----------------------------------------------------------------------------*/
void ApplCanAddCanInterruptRestore(CanChannelHandle channel)
{
	channel = channel;
    *((volatile uint32*)osdFIRQPR)  &=~CAN1_INT_FLAG_CIM;   /* interrupt is IRQ */
	*((volatile uint32*)osdINTREQ)  &=~CAN1_INT_FLAG_CIM;   /* clear pending flag */
	*((volatile uint32*)osdREQMASK) |= CAN1_INT_FLAG_CIM;   /* enable interrupt  */
}/* END OF ApplCanAddCanInterruptRestore() */


# if defined( C_ENABLE_HW_LOOP_TIMER )
/**************************************************************************************************
   Function name    : ApplCanTimerStart
   ------------------------------------------------------------------------------------------------
   Description      : Call back implementation of the CAN driver's hardware loop check start.
                      Resets the counter of the specified loop source.
   ------------------------------------------------------------------------------------------------
   Called by        : CAN driver
   ------------------------------------------------------------------------------------------------
   Parameter        : Source of the call
   ------------------------------------------------------------------------------------------------
   Returncode       : void
   ------------------------------------------------------------------------------------------------
   Misc             :
**************************************************************************************************/
C_CALLBACK_1 void     C_CALLBACK_2 ApplCanTimerStart(CAN_CHANNEL_CANTYPE_FIRST vuint8 source)
{
    ApplCanResetTimer(source);
    eHWLoopcheckAction = CAN_NOTHING;;
}

/**************************************************************************************************
   Function name    : ApplCanTimerLoop
   ------------------------------------------------------------------------------------------------
   Description      : Call back implementation of the CAN driver's hardware loop check run.
                      Increments the counter of the specified source and checks if the loop
                      is still allowed to run.
   ------------------------------------------------------------------------------------------------
   Called by        : CAN driver
   ------------------------------------------------------------------------------------------------
   Parameter        : Source of the call
   ------------------------------------------------------------------------------------------------
   Returncode       : kCanTrue if the loop is still allowed to run.
                      kCanFalse if the loop isn't allowed to run anymore.
   ------------------------------------------------------------------------------------------------
   Misc             :
**************************************************************************************************/
C_CALLBACK_1 vuint8 C_CALLBACK_2 ApplCanTimerLoop (CAN_CHANNEL_CANTYPE_FIRST vuint8 source)
{
    vuint8 returnValue = kCanTrue;
    switch (source)
    {
        case (vuint8)kCanLoopWaitConfigChangeEnable:
            ApplCanWaitConfigChangeEnableLoopCounter++;
            if (ApplCanWaitConfigChangeEnableLoopCounter > ApplCanWaitConfigChangeEnableLoopCounterLimit)
            {
                returnValue = kCanFalse;
                eHWLoopcheckAction = CAN_INIT;
            }
            break;
        case (vuint8)kCanLoopWaitPowerDownMode:
            ApplCanWaitPowerDownModeLoopCounter++;
            if (ApplCanWaitPowerDownModeLoopCounter > ApplCanWaitPowerDownModeLoopCounterLimit)
            {
                returnValue = kCanFalse;
                eHWLoopcheckAction = CAN_SLEEP;
            }
            break;
        case (vuint8)kCanLoopWaitLeavePowerDownMode:
            ApplCanWaitLeavePowerDownModeLoopCounter++;
            if (ApplCanWaitLeavePowerDownModeLoopCounter > ApplCanWaitLeavePowerDownModeLoopCounterLimit)
            {
                returnValue = kCanFalse;
                eHWLoopcheckAction = CAN_WAKEUP;
            }
            break;
        default:
            break;
    }
    return returnValue;
}

/**************************************************************************************************
   Function name    : ApplCanTimerEnd
   ------------------------------------------------------------------------------------------------
   Description      : Call back implementation of the CAN driver's hardware loop check end.
   ------------------------------------------------------------------------------------------------
   Called by        : CAN driver
   ------------------------------------------------------------------------------------------------
   Parameter        : Source of the call
   ------------------------------------------------------------------------------------------------
   Returncode       : void
   ------------------------------------------------------------------------------------------------
   Misc             :
**************************************************************************************************/
C_CALLBACK_1 void     C_CALLBACK_2 ApplCanTimerEnd  (CAN_CHANNEL_CANTYPE_FIRST vuint8 source)
{
    ApplCanResetTimer(source);
}

/**************************************************************************************************
   Function name    : ApplCanResetTimer
   ------------------------------------------------------------------------------------------------
   Description      : Resets the HW loop check counter specified by the source parameter.
   ------------------------------------------------------------------------------------------------
   Called by        : ApplCanTimerStart, ApplCanTimerEnd
   ------------------------------------------------------------------------------------------------
   Parameter        : Source of the call
   ------------------------------------------------------------------------------------------------
   Returncode       : void
   ------------------------------------------------------------------------------------------------
   Misc             :
**************************************************************************************************/
static void ApplCanResetTimer(CAN_CHANNEL_CANTYPE_FIRST vuint8 source)
{
    DEBUG_VALUE1(CALLBACK_SWI_TRC, MOD_CALLBACK, "HW loopcheck ApplCanWaitConfigChangeEnableLoopCounter=%d", ApplCanWaitConfigChangeEnableLoopCounter);
    switch (source)
    {
    case (vuint8)kCanLoopWaitConfigChangeEnable:
        ApplCanWaitConfigChangeEnableLoopCounter = 0;
        break;
    case (vuint8)kCanLoopWaitPowerDownMode:
        ApplCanWaitPowerDownModeLoopCounter = 0;
        break;
    case (vuint8)kCanLoopWaitLeavePowerDownMode:
        ApplCanWaitLeavePowerDownModeLoopCounter = 0;
        break;
    default:
        break;
    }
    eHWLoopcheckAction = CAN_NOTHING;
}
# endif


vuint8 CCL_API_CALLBACK_TYPE ApplCclCanStandby(CCL_CHANNEL_CCLTYPE_FIRST vuint8 sleepResult)
{
    vuint8 rval;
    switch( sleepResult )
    {
        case kCanFailed:
            /* CanSleep() failed => try again */
            rval = kCclRepeatCanSleep;
            break;
        default:
            rval = kCclNoRepeatCanSleep;
            BusActive = TS_FALSE;
            break;
    }
    return( rval );
}

void ApplCclLimphomeTimeout(CCL_CHANNEL_CCLTYPE_ONLY)
{
    DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, "ApplCclLimphomeTimeout");
}

/*----------------------------------------------------------------------------*/
/* Function    : WriteProtReg                                                 */
/**
    \brief      callback function from CAN driver

    \brief      Description:
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    \param      addr
                volatile canuint32*
                value limits
    \param      msk
                canuint32
                value limits
    \param      val
                canuint32
                value limits

    \return     void
   */
/*----------------------------------------------------------------------------*/
void WriteProtReg(volatile canuint32* addr, canuint32 msk, canuint32 val)
{
	canuint32 tmp;

	tmp = *addr;
	tmp &= (~msk);
	tmp |= val;
	*addr = tmp;
}/* END OF WriteProtReg() */

/*----------------------------------------------------------------------------*/
/* Function    : BusTransceiverToSleep                                      */
/**
    \brief      callback function from CAN driver

    \brief      Description:
                set the transceiver in the sleep mode
				first:  CAN_EN = HIGH;      CAN_STB_ = LOW;
                second: CAN_EN = LOW;       CAN_STB_ = LOW;

    \return     void
   */
/*----------------------------------------------------------------------------*/
void CCL_API_CALLBACK_TYPE ApplCclSleepTrcv(void)
{
        /* !!!! THE while LOOP Counter is hardware and compiler dependant. Please read the
         * CAN Transreciever data sheet about the max time !!! */
        canuint32 Iterations = 3000;

        DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, " !!! ApplCclSleepTrcv : CAN_EN->High CAN_STB->Low");

        SPI_vPinModify(SPI5, SpiEnablePin, PortIoOutHigh);   // CAN_EN


        while (Iterations != 0)
        {
            Iterations--;
        }
        Iterations = 3000;

        CAN_vPortClear(CAN3, RX);                               // CAN_STB

        while (Iterations != 0)
        {
            asm("nop");

            Iterations = Iterations - 1;
        }

        /* Sleep CAN transceiver */
        DEBUG_TEXT(CALLBACK_SWI_TRC, MOD_CALLBACK, " !!! ApplCclSleepTrcv : CAN_EN->Low CAN_STB->Low");
        SPI_vPinModify(SPI5, SpiEnablePin, PortIoOutLow);    // CAN_EN
        CAN_vPortClear(CAN3, RX);                              // CAN_STB
}/* END OF BusTransceiverToSleep() */

/*----------------------------------------------------------------------------*/
/* Function    : cylicNM                                      */
/**
    \brief      cyclic NM

    \brief      Description:
                set the transceiver in the sleep mode
				first:  CAN_EN = HIGH;      CAN_STB_ = LOW;
                second: CAN_EN = LOW;       CAN_STB_ = LOW;

    \return     void
   */
/*----------------------------------------------------------------------------*/
void cylicNM(void)
{
    if( BusInWaitBusSleep == TS_FALSE )
    {
        CanRequests_IL_CSHDL_MsgData.CshdlID_Rq = NETWORKMANAGEMENT_ST_RQ;
        CanRequests_IL_CSHDL_MsgData.APP_CAN_UnionCanToCshdl.BusStatus_Requests.BusStatus = 0x3;	// Active
        (void)SendMessage(msgCshdl_Requests, &CanRequests_IL_CSHDL_MsgData);
        BusInWaitBusSleep = TS_UNKNOWN;
    }
    else if( BusInWaitBusSleep == TS_TRUE )
    {
        CanRequests_IL_CSHDL_MsgData.CshdlID_Rq = NETWORKMANAGEMENT_ST_RQ;
        CanRequests_IL_CSHDL_MsgData.APP_CAN_UnionCanToCshdl.BusStatus_Requests.BusStatus = 0x4;	//
        (void)SendMessage(msgCshdl_Requests, &CanRequests_IL_CSHDL_MsgData);
        BusInWaitBusSleep = TS_UNKNOWN;
    }

    else if ( BusActive == TS_FALSE)
    {
    	CanRequests_IL_CSHDL_MsgData.CshdlID_Rq = NETWORKMANAGEMENT_ST_RQ;
        CanRequests_IL_CSHDL_MsgData.APP_CAN_UnionCanToCshdl.BusStatus_Requests.BusStatus = 0x0;	// Sleep
        (void)SendMessage(msgCshdl_Requests, &CanRequests_IL_CSHDL_MsgData);
        BusActive = TS_UNKNOWN;
    }
    else if ( BusActive == TS_TRUE )
    {
    	CanRequests_IL_CSHDL_MsgData.CshdlID_Rq = NETWORKMANAGEMENT_ST_RQ;
        CanRequests_IL_CSHDL_MsgData.APP_CAN_UnionCanToCshdl.BusStatus_Requests.BusStatus = 0x1;	// Active
        (void)SendMessage(msgCshdl_Requests, &CanRequests_IL_CSHDL_MsgData);
        BusActive = TS_UNKNOWN;
    }
}
/*----------------------------------------------------------------------------*/
/* Function    : HWLoopcheckStateMonitoring                                      */
/**
    \brief      monitoring HW loopcheck states

    \brief      Description:
                monitoring HW loopcheck states

    \return     void
   */
/*----------------------------------------------------------------------------*/
void HWLoopcheckStateMonitoring( void )
{
    switch(eHWLoopcheckAction)
    {
    case CAN_INIT:
        DEBUG_VALUE1(CALLBACK_SWI_TRC, MOD_CALLBACK, "HW loopcheck  StateMonitoring ApplCanWaitConfigChangeEnableLoopCounter=%d", ApplCanWaitConfigChangeEnableLoopCounter);
        //*((volatile uint32*)osdREQMASK) &=~CAN1_INT_FLAG_CIM;   /* disable interrupt */
        //CclEmergencyBegin();
        //CanInit(ANY_GLOBAL_EXTERNAL_VARIABLE);
        //CclEmergencyEnd();
        //*((volatile uint32*)osdFIRQPR)  &=~CAN1_INT_FLAG_CIM;   /* interrupt is IRQ */
        //*((volatile uint32*)osdINTREQ)  &=~CAN1_INT_FLAG_CIM;   /* clear pending flag */
        //*((volatile uint32*)osdREQMASK) |= CAN1_INT_FLAG_CIM;   /* enable interrupt  */
        break;
    case CAN_SLEEP:
        DEBUG_VALUE1(CALLBACK_SWI_TRC, MOD_CALLBACK, "HW loopcheck  StateMonitoring ApplCanWaitPowerDownModeLoopCounter=%d", ApplCanWaitPowerDownModeLoopCounter);
        break;
    case CAN_WAKEUP:
        DEBUG_VALUE1(CALLBACK_SWI_TRC, MOD_CALLBACK, "HW loopcheck  StateMonitoring ApplCanWaitLeavePowerDownModeLoopCounter=%d", ApplCanWaitLeavePowerDownModeLoopCounter);
        break;
    default:
        break;
    }
}

/*----------------------------------------------------------------------------*/
/* Function    : DiagnosisNMStateMonitoring                                      */
/**
    \brief      monitoring NM states

    \brief      Description:
                monitoring NM state transitions, save 5 entries in history data

    \return     void
   */
/*----------------------------------------------------------------------------*/
void DiagnosisNMStateMonitoring( void )
{
//    static tNmStateExtType NetState;
//    uint8 u8DiagNMState = 0x00;
//
//    NetState = NmGetState();
//
//    switch(NetState)
//    {
//        case NM_STATE_RESET:
//            u8DiagNMState = 0x2B;
//        break;
//        case NM_STATE_NORMAL:
//            u8DiagNMState = 0x20;
//        break;
//        case NM_STATE_NORMAL_PREPSLEEP:
//            u8DiagNMState = 0x21;
//        break;
//        case NM_STATE_NORMAL_WAITBUSSLEEP:
//            u8DiagNMState = 0x22;
//        break;
//        case NM_STATE_LIMPHOME:
//            u8DiagNMState = 0x24;
//        break;
//        case NM_STATE_LIMPHOME_PREPSLEEP:
//            u8DiagNMState = 0x25;
//        break;
//        case NM_STATE_LIMPHOME_WAITBUSSLEEP:
//            u8DiagNMState = 0x26;
//        break;
//        case NM_STATE_BUSSLEEP:
//            u8DiagNMState = 0x27;
//        break;
//        case NM_STATE_BUSOFF:
//            u8DiagNMState = 0x29;
//        break;
//        case NM_STATE_BUSOFFWAIT:
//            u8DiagNMState = 0x28;
//        break;
//        case NM_STATE_EXPULSION:
//            u8DiagNMState = 0x23;
//        break;
//        case NM_STATE_STOPPED:
//            u8DiagNMState = 0x2A;
//        break;
//        case NM_STATE_OFF:
//            u8DiagNMState = 0x2D;
//        break;
//        default:
//        break;
//    }
//    if( u8DiagNMHistory[0] != u8DiagNMState )
//    {
//        DEBUG_VALUE1(CALLBACK_SWI_TRC, MOD_CALLBACK, " NMState : 0x%2X", u8DiagNMState);
//
//        if( u8DiagNMHistory[0] != u8DiagNMHistory[1] )
//        {
//            if( u8DiagNMHistory[1] != u8DiagNMHistory[2] )
//            {
//                if( u8DiagNMHistory[2] != u8DiagNMHistory[3] )
//                {
//                    if( u8DiagNMHistory[3] != u8DiagNMHistory[4] )
//                    {
//                        u8DiagNMHistory[4] = u8DiagNMHistory[3];
//                    }
//                    u8DiagNMHistory[3] = u8DiagNMHistory[2];
//                }
//                u8DiagNMHistory[2] = u8DiagNMHistory[1];
//            }
//            u8DiagNMHistory[1] = u8DiagNMHistory[0];
//        }
//        u8DiagNMHistory[0] = u8DiagNMState;
//    }

}

/*----------------------------------------------------------------------------*/
/* Function    : DiagNmGetHistoryStatus                                             */
/**
    \brief      Provide the NM history state byte from the specified position \n
                There are 5 positions available

    \return     uint8 NmStatus

   */
/*----------------------------------------------------------------------------*/
uint8 DiagNmGetHistoryStatus(uint8 u8HistoryPosition)
{
    return u8DiagNMHistory[u8HistoryPosition];
}

/*******************************************************************************/
/**
 * \brief      The NPM notifies the application about a new FSD state.
 * 
 * \attention  CCL requires depending on the configuration different callbacks to inform the application event 
 *             based about state changes. See the documentation of CCL for the usage of that callback!
 *
 * \param[in] - (single channel) or channel number
 *
 * \param[in] FSDState is either kCclNpmForceShutdownOn or kCclNpmForceShutdownOff
 *
 * \retval void
 */
void CCL_API_CALLBACK_TYPE ApplCclNpmForceShutdown(CCL_CHANNEL_CCLTYPE_FIRST vuint8 FSDState)
{

  switch( FSDState ) {
    case kCclNpmForceShutdownOn:
      /* State has changed to FSD = on. Handel in your state machine that the bus communication 
         will now be stopped even there are pending communication requests */
      break;
    case kCclNpmForceShutdownOff:
      /* State has changed to FSD = off */
      break;
    default:
      /* Illegal call by CCL */
      break;
  }

}

/*******************************************************************************/
/**
 * \brief      The callback notifies the application that the NPM message is in
 *             timeout. This can be used to store e.g. the event in the fault memory.
 * 
 * \attention  CCL requires depending on the configuration different callbacks to inform the application event 
 *             based about state changes. See the documentation of CCL for the usage of that callback!
 *
 * \param[in] void (single channel) or channel number
 *
 * \retval void
 */
void CCL_API_CALLBACK_TYPE ApplCclNpmMsgTimeout(CCL_CHANNEL_CCLTYPE_ONLY)
{
 /* Store e.g. the timeout of NPM message in your fault memory. All other NPM handling is 
    already done by CCL/NPM. */
}

/*******************************************************************************/
/**
 * \brief      The NPM notifies the application about a new NPM state.
 * 
 * \attention  CCL requires depending on the configuration different callbacks to inform the application event 
 *             based about state changes. See the documentation of CCL for the usage of that callback!
 *
 * \param[in] - (single channel) or channel number
 *
 * \param[in] PwuState is either kCclNpmPreventWakeUpOn or kCclNpmPreventWakeUpOff
 *
 * \retval void
 */
void CCL_API_CALLBACK_TYPE ApplCclNpmPreventWakeup(CCL_CHANNEL_CCLTYPE_FIRST vuint8 PwuState)
{

  switch( PwuState ) {
    case kCclNpmPreventWakeUpOn:
      /* State has changed to PWU = on */
      break;
    case kCclNpmPreventWakeUpOff:
      /* State has changed to PWU = off */
      break;
    default:
      /* Illegal call by CCL */
      break;
  }
}

/*******************************************************************************/
/**
 * \brief      The NPM notifies the application that the NPM state has changed and
 *             is to be stored in the NVRAM.
 * 
 * \attention  CCL requires depending on the configuration different callbacks to inform the application event 
 *             based about state changes. See the documentation of CCL for the usage of that callback!
 *
 * \param[in] - (single channel) or channel number
 *
 * \param[in] PwuState is either kCclNpmPreventWakeUpOn or kCclNpmPreventWakeUpOff
 *
 * \retval void
 */
void CCL_API_CALLBACK_TYPE ApplCclNpmWritePwuStateToNVRAM(CCL_CHANNEL_CCLTYPE_FIRST vuint8 PwuState)
{

  /* Write status of PreventWakeUp to NVRAM (here simulated by storage in a static variable) */
  demoCclPreventWakeUpStatus = PwuState;
}

/*******************************************************************************/
/**
 * \brief      The NPM notifies the application that the NPM state is required out 
 *             of the NVRAM.
 * 
 * \attention  CCL requires depending on the configuration different callbacks to inform the application event 
 *             based about state changes. See the documentation of CCL for the usage of that callback!
 *
 * \param[in] - (single channel) or channel number
 *
 * \retval PwuState is either kCclNpmPreventWakeUpOn or kCclNpmPreventWakeUpOff
 */
vuint8 CCL_API_CALLBACK_TYPE ApplCclNpmReadPwuStateFromNVRAM(CCL_CHANNEL_CCLTYPE_ONLY)
{
  vuint8 rval;


  /* Read status of PreventWakeUp from NVRAM (here simulated by access into a static variable) */
  rval = demoCclPreventWakeUpStatus;

  return( rval );
}




/* End Of File MOD_CanInterface.c */
