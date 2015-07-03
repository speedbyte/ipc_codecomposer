/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/**
 * \file 	APP_DIAG_C1.c
 * \brief	this module is the interface between standard diagnostic module SDS
 *          and the applications modules. Detailed description found below.
 * \brief	Detailed description of the file.
*/
/*-----------------------------------------------------------------------------
 * $Date: 2011-09-19 14:52:14 +0200 (Mo, 19 Sep 2011) $
 * $Rev: 21831 $
 * $Author: weber $
 * $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_DIAG/trunk/src/APP_DIAG_C1.c $
 *-----------------------------------------------------------------------------
 */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include <osek.h>           // vector
#include <osekext.h>        // vector
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "APP_DIAG.h"
#include "APP_DIAG_PL.h"
#include "APP_COMMON_Utils.h"
#include "OSEK_AppTask_H1.h"
#include "EEPROM_LAYOUT.h"
#include "MONITOR_ADC.h"
#include "APP_DIAG_C1.id"
#include "TRACE.h"
#include "APP_DIAG_ERM.h"
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/
/**
 \brief	example
 */

/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/
/**
 \brief	description of the type
 */
typedef enum
{
	enAppDiagStartStellglied,
	enAppDiagAudioSettings,
	enAppDiagTriggerAudioTones
}APP_DIAG_ENUM_STELLGLIED_STATUS;

typedef enum
{
    enAppDiagStartSelfTest,
    enAppDiagMicrophoneTest,
    enAppDiagROMTest,
    enAppDiagRAMTest,
    enAppDiagEndSelfTest
}APP_DIAG_ENUM_ONDEMANDSELFTEST_STATUS;

/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/
//static SuccessFailType not_implemented(Uint8Type u8MuteControlTimer)
//{
//	return SUCCESS;
//}
static void _APP_DIAG_u8ConvertToInteger(Uint8Type *ptru8BluetoothAddress);

static APP_DIAG_ENUM_STELLGLIED_STATUS _APP_DIAG_enStellgliedStatus = enAppDiagStartStellglied;

static Uint8Type _APP_DIAG_u8AppleICTest = 0xFF;
/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                     */
/*----------------------------------------------------------------------------*/
/**
 \brief	description of the macros
 */

/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/
/**
 \brief	description of the private variable
 */

static BooleanType _APP_DIAG_bWaitForCallBack = BT_FALSE;
static APP_DIAG_ST_DIAG_RESPONSE _APP_DIAG_stResponsePacketToDet;
static APP_DIAG_ST_DIAG_REQUEST  _APP_DIAG_stRequestPacketFromDet;

static Uint16Type APP_DIAG_ubCounterBusyResponseFromAppTask = 0;
static Uint16Type APP_DIAG_ubCounterWaitForCallBack = 0;

static APP_DIAG_ENUM_ONDEMANDSELFTEST_STATUS _APP_DIAG_enOnDemandSelfTestStatus = enAppDiagStartSelfTest;

static Uint16Type _APP_DIAG_u16MicrophoneTestRunningCounter = 400u; //4s
static Uint8Type _APP_DIAG_u8MicrophoneState = APP_DIAG_DTC_OK;
static BooleanType _APP_DIAG_bTestFailed = BT_FALSE;
/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/

#define MAX_BUSY_RESPONSE_FROM_AP_TASK              4000

#define READ_ACTIVE_PHONE_INDEX                     0x00
#define WRITE_ACTIVE_PHONE_INDEX                    0x01

#define ACTIVE_PHONE_INDEX_DISCONNECT_ACTIVE_PROFILE    0x00
#define ACTIVE_PHONE_INDEX_CONNECT_PROFILE_1            0x01
#define ACTIVE_PHONE_INDEX_CONNECT_PROFILE_2            0x02
#define ACTIVE_PHONE_INDEX_CONNECT_PROFILE_3            0x03
#define ACTIVE_PHONE_INDEX_CONNECT_PROFILE_4            0x04
#define ACTIVE_PHONE_INDEX_CONNECT_PROFILE_5            0x05
#define ACTIVE_PHONE_INDEX_CONNECT_PROFILE_6            0x06

/*----------------------------------------------------------------------------*/
/* Function    : APP_DIAG_sfInit                              */
/**
 \brief       To initialise the variables

 */
/*----------------------------------------------------------------------------*/
SuccessFailType APP_DIAG_sfInit()
{
	return SUCCESS;
}

/*----------------------------------------------------------------------------*/
/* Function    : _APP_DIAG_enConvertAPP_PHONE_ResponseCodes                                                    */
/**
 \brief      to convert the aplication response codes into Diagnose response codes

 \brief

 \param      res
            APP_COMMON_enResponseCode

 \return     APP_DIAG_ENUM_RESPONSE_CODES
 */
/*----------------------------------------------------------------------------*/
static APP_DIAG_ENUM_RESPONSE_CODES _APP_DIAG_enConvertAPP_PHONE_ResponseCodes(APP_COMMON_enResponseCode res)
{
    APP_DIAG_ENUM_RESPONSE_CODES enResponseImmediate;
    if (res == APP_COMMON_RSP_OK)
    {
        enResponseImmediate = enAppDiagResponseOkImm;
    }
    else if (res == APP_COMMON_RSP_ERROR)
    {
        enResponseImmediate = enAppDiagResponseErrorImm;
    }
    else if (res == APP_COMMON_RSP_ERROR_BUSY)
    {
        enResponseImmediate = enAppDiagResponseErrorBusyImm;
    }
    else
    {
        enResponseImmediate = enAppDiagResponseInvalid;
    }
    return enResponseImmediate;
}

/*----------------------------------------------------------------------------*/
/* Function    : _APP_DIAG_enConvertAPP_PHONE_ResponseCodes                                                    */
/**
 \brief      to convert the aplication response codes into Diagnose response codes

 \brief

 \param     sF
 			SuccessFailType

 \return     APP_DIAG_ENUM_RESPONSE_CODES
 */
/*----------------------------------------------------------------------------*/
/*static APP_DIAG_ENUM_RESPONSE_CODES _APP_DIAG_enConvertSuccessFail_ResponseCodes(SuccessFailType sF)
{
	APP_DIAG_ENUM_RESPONSE_CODES enResponseImmediate;
	if (sF == SUCCESS)
    {
		enResponseImmediate = enAppDiagResponseOkImm;
	}
    else
    {
		enResponseImmediate = enAppDiagResponseErrorImm;
	}
	return enResponseImmediate;
}
*/

/*----------------------------------------------------------------------------*/
/* Function    : _APP_DIAG_cbResponseCode                                                    */
/**
 \brief      to convert the application response codes into Diagnose response codes

 \brief

 \param      rsp
            APP_COMMON_enResponseCode

 */
/*----------------------------------------------------------------------------*/
static void _APP_DIAG_cbResponseCode(APP_COMMON_enResponseCode rsp)
{
    // Ruckgabe bewerten:
    APP_DIAG_ENUM_RESPONSE_CODES enDiagResponse;
    (void)APP_COMMON_UTILS_stCancelOsekRelAlarm(CTA_APP_DIAG_WAIT_FOR_APP_CB);
    _APP_DIAG_bWaitForCallBack = BT_FALSE;
    _APP_DIAG_enStellgliedStatus = enAppDiagStartStellglied;
    enDiagResponse = _APP_DIAG_enConvertAPP_PHONE_ResponseCodes(rsp);
    _APP_DIAG_stResponsePacketToDet.Identifier = _APP_DIAG_stRequestPacketFromDet.Identifier;
    _APP_DIAG_stResponsePacketToDet.result = enDiagResponse;

    //DEBUG_VALUE2(APP_DIAG_SWI_TRC, MOD_APP_DIAG, "Callback Response from Application rsp=%d,id = %04X", rsp,
    //        _APP_DIAG_stResponsePacketToDet.Identifier);
    APP_DIAG_ubCounterWaitForCallBack = 0;
    // The below code is to take care of error over callback and active stellglied tests.
    if ( enDiagResponse == enAppDiagResponseErrorImm )
    {
        _APP_DIAG_enStellgliedStatus = enAppDiagStartStellglied;
    //    DEBUG_VALUE1(APP_DIAG_SWI_ERR, MOD_APP_DIAG, "change status = %d", _APP_DIAG_enStellgliedStatus);
        //(void)SetRelAlarm(CTA_APP_DIAG_RETRY_BUSY,MSEC(100),MSEC(0));
    }
    (void)SendMessage(msgAppDiagDiagnoseResponse, &_APP_DIAG_stResponsePacketToDet);

}

/*----------------------------------------------------------------------------*/
/* Function    : _APP_DIAG_cbResponseCode                                                    */
/**
 \brief      to convert the application response codes into Diagnose response codes

 \brief

 \param      rsp
            APP_COMMON_enResponseCode

 */
/*----------------------------------------------------------------------------*/
/*static void _APP_DIAG_cbResponseAudio(APP_COMMON_enResponseCode rsp)
{
    // Ruckgabe bewerten:
    APP_DIAG_ENUM_RESPONSE_CODES enDiagResponse;
    (void)APP_COMMON_UTILS_stCancelOsekRelAlarm(CTA_APP_DIAG_WAIT_FOR_APP_CB);
    _APP_DIAG_bWaitForCallBack = BT_FALSE;
    enDiagResponse = _APP_DIAG_enConvertAPP_PHONE_ResponseCodes(rsp);
    _APP_DIAG_stResponsePacketToDet.Identifier = _APP_DIAG_stRequestPacketFromDet.Identifier;
    _APP_DIAG_stResponsePacketToDet.result = enDiagResponse;

    DEBUG_VALUE2(APP_DIAG_SWI_TRC, MOD_APP_DIAG, "Callback Response Audio Manager=%d,id = %04X", rsp,
            _APP_DIAG_stResponsePacketToDet.Identifier);
    APP_DIAG_ubCounterWaitForCallBack = 0;
    if ( enDiagResponse == enAppDiagResponseOkImm )
    {
        _APP_DIAG_enStellgliedStatus = enAppDiagTriggerAudioTones;
        DEBUG_VALUE1(APP_DIAG_SWI_TRC, MOD_APP_DIAG, "change status = %d", _APP_DIAG_enStellgliedStatus);
        (void)SetRelAlarm(CTA_APP_DIAG_RETRY_BUSY,MSEC(10),MSEC(0));
    }
    else if ( enDiagResponse == enAppDiagResponseErrorImm )
    {
        _APP_DIAG_enStellgliedStatus = enAppDiagStartStellglied;
        DEBUG_VALUE1(APP_DIAG_SWI_TRC, MOD_APP_DIAG, "change status = %d", _APP_DIAG_enStellgliedStatus);
        (void)SendMessage(msgAppDiagDiagnoseResponse, &_APP_DIAG_stResponsePacketToDet);
    }
    else
    {

    }
}
*/


/*-----------------------------------------------------------------------------*/
/* Function    : APP_DIAG_vHandleEvents                          		       */
/**
 \brief      	 Handle Events from Diagnose.
				 For All IDs following method is used.
				 FIRST : Check for validity of the data
				 SECOND: Call Application Function.
				 THIRD: Convert the response in Diagnose specific.
				 FOURTH: Send the response back to Diagnose.

				 This consists of


 \brief			 CODIERUNG:
				 FALLBACK_LANGUAGE
 \param		event
 			EventMaskType

 \return     None
 If the function was successful or failed
 SUCCESS, FAIL
 */
/*----------------------------------------------------------------------------*/
void APP_DIAG_vHandleEvents(EventMaskType event)
{
	APP_COMMON_enResponseCode res = APP_COMMON_RSP_OK;
	APP_DIAG_ENUM_RESPONSE_CODES enResponseImmediate = enAppDiagResponseOkImm;
	if (event & evAppTaskDiagnoseRequest)
	{
		(void)ClearEvent(evAppTaskDiagnoseRequest);
		// collect new message from Diagnose into static variable
		(void)ReceiveMessage(msgAppDiagDiagnoseRequest,&_APP_DIAG_stRequestPacketFromDet);
		_APP_DIAG_stResponsePacketToDet.length = _APP_DIAG_stRequestPacketFromDet.length;
		_APP_DIAG_stResponsePacketToDet.Identifier = _APP_DIAG_stRequestPacketFromDet.Identifier;

		//DEBUG_STATE2(APP_DIAG_SWI_TRC, MOD_APP_DIAG, "vHandleEvents: Diagnose id  $APP_DIAG_ENUM_DIAGNOSE_ID$ %04X, enStellgliedStatus=%d",
		//             _APP_DIAG_stRequestPacketFromDet.Identifier,
        //             _APP_DIAG_enStellgliedStatus);
		switch (_APP_DIAG_stRequestPacketFromDet.Identifier)
		{
	        default:
	        {
	            break;
	        }
        }

	    if  (enResponseImmediate == enAppDiagResponseErrorImm )
        {
	    	_APP_DIAG_stResponsePacketToDet.Identifier = _APP_DIAG_stRequestPacketFromDet.Identifier;
	    	_APP_DIAG_stResponsePacketToDet.result = enResponseImmediate;
	    	_APP_DIAG_enOnDemandSelfTestStatus = enAppDiagStartSelfTest;

	    //	DEBUG_VALUE2(APP_DIAG_SWI_ERR, MOD_APP_DIAG,"Immediate Response from Application=%d,Diagnose id=%04X",
	    //			     enResponseImmediate,_APP_DIAG_stResponsePacketToDet.Identifier);
	    	_APP_DIAG_bWaitForCallBack = BT_FALSE;
	    	(void)SendMessage(msgAppDiagDiagnoseResponse,&_APP_DIAG_stResponsePacketToDet);
	    }
	    else if ( enResponseImmediate == enAppDiagResponseAbortDetRequest)
	    {
	    	_APP_DIAG_stResponsePacketToDet.Identifier = _APP_DIAG_stRequestPacketFromDet.Identifier;
	    	_APP_DIAG_stResponsePacketToDet.result = enResponseImmediate;
	    //	DEBUG_VALUE2(APP_DIAG_SWI_ERR, MOD_APP_DIAG,"Immediate Response from Application=%d,Diagnose id=%04X",
	    //			     enResponseImmediate,_APP_DIAG_stResponsePacketToDet.Identifier);
	    	_APP_DIAG_bWaitForCallBack = BT_FALSE;

	    	// Now simulate a Stellglied Stop to the application, to bring the system in a correct state.
	    	(void)SendMessage(msgAppDiagDiagnoseResponse,&_APP_DIAG_stResponsePacketToDet);
	    	if ( _APP_DIAG_stResponsePacketToDet.Identifier == ID_31_F000_MICROPHONE_LOOPBACK )
    		{
    			(void)SetRelAlarm(CTA_APP_DIAG_RETRY_BUSY,MSEC(100),MSEC(0));
    		}
	    }
	    else if ( (enResponseImmediate == enAppDiagResponseErrorBusyImm))
	    {
	    	if (APP_DIAG_ubCounterBusyResponseFromAppTask > MAX_BUSY_RESPONSE_FROM_AP_TASK)
            {
	    		APP_DIAG_ubCounterBusyResponseFromAppTask = 0;
	    		_APP_DIAG_stResponsePacketToDet.Identifier = _APP_DIAG_stRequestPacketFromDet.Identifier;
	    		_APP_DIAG_stResponsePacketToDet.result = enResponseImmediate;
	    		_APP_DIAG_enStellgliedStatus = enAppDiagStartStellglied;
	    		(void)SendMessage(msgAppDiagDiagnoseResponse,&_APP_DIAG_stResponsePacketToDet);
	    //		DEBUG_VALUE2(APP_DIAG_SWI_ERR, MOD_APP_DIAG,"GIVE UP RETRY Immediate Response from Application=%d,Diagnose id=%04X",
	    //				         enResponseImmediate,_APP_DIAG_stRequestPacketFromDet.Identifier);
	    		(void)SetRelAlarm(CTA_APP_DIAG_RETRY_BUSY,MSEC(100),MSEC(0));
	    	}
            else
	    	{
	    //		DEBUG_VALUE2(APP_DIAG_SWI_WNG, MOD_APP_DIAG,"Immediate Response from Application=%d,Diagnose id=%04X",
	    //				         enResponseImmediate,_APP_DIAG_stRequestPacketFromDet.Identifier);
	    		APP_DIAG_ubCounterBusyResponseFromAppTask++;
    			(void)SetRelAlarm(CTA_APP_DIAG_RETRY_BUSY,MSEC(10),MSEC(0));
	    	}
	    }
	    else if ( (enResponseImmediate == enAppDiagResponseFurtherRequestsPending))
	    {
	    	(void)SetRelAlarm(CTA_APP_DIAG_RETRY_BUSY,MSEC(100),MSEC(0));
	    }
	    else if (enResponseImmediate == enAppDiagResponseOkImm)
        {
	    //	DEBUG_VALUE2(APP_DIAG_SWI_TRC, MOD_APP_DIAG,"Immediate Response from Application=%d,Diagnose id=%04X",
	    //			     enResponseImmediate,_APP_DIAG_stResponsePacketToDet.Identifier);
	    //	DEBUG_VALUE1(APP_DIAG_SWI_TRC, MOD_APP_DIAG,"First byte in the payload=%d",
	    //			     _APP_DIAG_stResponsePacketToDet.data[0]);
	    	(void)SetRelAlarm(CTA_APP_DIAG_WAIT_FOR_APP_CB, MSEC(0), MSEC(10));
	    }
        else if ( (enResponseImmediate == enAppDiagResponseWaitForCallBack))
        {
        	;
        }
    }
}

ALARMCALLBACK(APP_DIAG_vHandlePendingResponseFromApplication)
{
	if (_APP_DIAG_bWaitForCallBack == BT_FALSE)
	{
		(void)APP_COMMON_UTILS_stCancelOsekRelAlarm(CTA_APP_DIAG_WAIT_FOR_APP_CB);
		_APP_DIAG_stResponsePacketToDet.Identifier = _APP_DIAG_stRequestPacketFromDet.Identifier;
		_APP_DIAG_stResponsePacketToDet.result = enAppDiagResponseOkImm;
		(void)SendMessage(msgAppDiagDiagnoseResponse,&_APP_DIAG_stResponsePacketToDet);
	}
	else if ( _APP_DIAG_bWaitForCallBack == BT_TRUE )
	{
		if (APP_DIAG_ubCounterWaitForCallBack > MAX_BUSY_RESPONSE_FROM_AP_TASK)
		{
			APP_DIAG_ubCounterWaitForCallBack = 0;
			_APP_DIAG_enStellgliedStatus = enAppDiagStartStellglied;
			_APP_DIAG_stResponsePacketToDet.Identifier = _APP_DIAG_stRequestPacketFromDet.Identifier;
			_APP_DIAG_stResponsePacketToDet.result = enAppDiagResponseWaitForCallBack;
			(void)SetRelAlarm(CTA_APP_DIAG_RETRY_BUSY,MSEC(100),MSEC(0));
			(void)SendMessage(msgAppDiagDiagnoseResponse,&_APP_DIAG_stResponsePacketToDet);
		}
		else
		{
			APP_DIAG_ubCounterWaitForCallBack++;
		}
	}
}

/*----------------------------------------------------------------------------*/
/* Function    : _APP_DIAG_u8ConvertToInteger                              */
/**
 \brief       to convert ASCII into HEX.
 */
/*----------------------------------------------------------------------------*/
static void _APP_DIAG_u8ConvertToInteger(Uint8Type *ptru8BluetoothAddress)
{
	if ( (*ptru8BluetoothAddress >= 0x30) && (*ptru8BluetoothAddress <= 0x39))
	{
		*ptru8BluetoothAddress = *ptru8BluetoothAddress - 0x30;
	}
	else if ( (*ptru8BluetoothAddress >= 0x41) && (*ptru8BluetoothAddress <= 0x46))
	{
		*ptru8BluetoothAddress = *ptru8BluetoothAddress - 0x37;
	}
}

Uint8Type UDS_ubIgnoreFuncReq( Uint8Type* RxBuf, Uint8Type Len, Uint8Type mode )
{
      //Dummy
    return 0;
}

void APP_DIAG_SetAppleICTestResult( BooleanType bResult )
{
    _APP_DIAG_u8AppleICTest = (Uint8Type) bResult;
}

/* End Of File APP_DIAG_C1.c */
