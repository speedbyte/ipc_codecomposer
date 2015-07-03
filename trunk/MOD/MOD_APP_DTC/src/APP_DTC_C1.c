/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/** 
 * \file 	APP_DTC_C1.c
 * \brief	this module monitors the audio channel and intimates the Diagnostic
 * \brief	This file fulfills the following requirements:
 * 			1. Diagnose Antenna if Antenna diagnose is set in Codierung.
 * 			2. Diagnose Baseplate if base plate Diagnose is set in Codierung.
 * 			3. Diagnose 3BM if 3 button module diagnose availablity is set to 1 by Codeirung.
 *          4. if the part numbers do not support baseplate, then set the DTCs to OPEN CKT.
 *             ( This is a workaround for the hardware because the pins on these HW Variants
 *             for baseplate and antenna are left open.
*/
/*-----------------------------------------------------------------------------
* $Date: 2011-09-19 14:52:14 +0200 (Mo, 19 Sep 2011) $
* $Rev: 21831 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_DTC/trunk/src/APP_DTC_C1.c $
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
#include "Common.h"
#include "APP_DTC.h"
#include "APP_DTC_CI.h"
#include "deh.h"
#include "DEH_DTC_CFG.h"
#include "ADC.h"
#include "APP_CAN.h"
#include "MONITOR_ADC.h"
#include "APP_COMMON_Utils.h"
#include "APP_DIAG.h"
#include "OSEK_MonitorTask_H1.h"
#include "HET.h"
#include "PORT_CE.h"
#include "desc.h"
#include "APP_DESC.h"
#include "APP_DTC_C1.id"
#include "TRACE.h"
#include "EEPROM_LAYOUT.h"
#include "Pwrmgr.h"
#include "TEMPERATURE.h"
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/
/** 
    \brief	example
*/
static BooleanType _APP_DTC_bAudioDtcAllowed = BT_FALSE;

static BooleanType _APP_DTC_bStartUpFinished = BT_FALSE;

static APP_DTC_ENUM_START_SEQUENCE _APP_DTC_enAppDtcStartSequence = enAppDtcReadValuesOnStartUp;

static Uint8Type _APP_DTC_u8CurrentVariantType = 0xFF;

static Uint16Type _APP_DTC_u8StartAudioDiagnoseStartDelay = 0;

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
static void _APP_DTC_vMonitorMikroTelefon(void);
static void _APP_DTC_vMonitorAudioLeftChannel(void);
static void _APP_DTC_vMonitorAudioRightChannel(void);
static void _APP_DTC_vMonitorTemperature(void);
static void _APP_DTC_vMonitorUBatt(void);
static void _APP_DTC_vCheckCodingValues(void);
static void _APP_DTC_vCheckEcuCoded(void);

/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                     */
/*----------------------------------------------------------------------------*/
/** 
\brief	 description of the macros
*/
#undef AUDIO_DIAG_ALWAYS_ON
/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the private variable
*/
typedef struct  
{
	Uint8Type u8MikrophoneStatus;
	Uint8Type u8AudioRightStatus;
	Uint8Type u8AudioLeftStatus;
	Uint8Type u8CodingStatus;
	Uint8Type u8TemperatureStatus;
	Uint8Type u8UBattStatus;
} APP_DTC_ST_ALL_DTCS;

static APP_DTC_ST_ALL_DTCS  APP_DTC_stAppDTC_DeviceDtcStatus;
/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/
//Mask for ECUDataProgrammingInfo
#define MASK_UNGULTIGE_EEPROM_DATEN				0xC0

/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function    : APP_DTC_sfInit                                                    */
/**
    \brief      initialise app dtc init values to default

    \brief      Description:
                this function initialise all app dtc variables back to
                the specific default settings.

    \return     SuccessFailType
   */
/*----------------------------------------------------------------------------*/
SuccessFailType APP_DTC_sfInit(void)
{
  SuccessFailType          sF      = SUCCESS;


  _APP_DTC_bAudioDtcAllowed = BT_FALSE;
  APP_DTC_stAppDTC_DeviceDtcStatus.u8MikrophoneStatus = APP_DIAG_DTC_OK;
  
  _APP_DTC_enAppDtcStartSequence = enAppDtcReadValuesOnStartUp;
  _APP_DTC_u8CurrentVariantType = 0xFF;

  return sF;
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_DTC_vSoftwareDiagnostics                                                    */
/**
    \brief      Startup Sequence and Software Diagnostics.

    \brief      Description:
				In this function, the start up sequence will be carried out and
				software diagnostics done for exampe ( nicht codiert, ungültige ds,
				falsch codiert etc. )

    \return     void
   */
/*----------------------------------------------------------------------------*/
void APP_DTC_vSoftwareDiagnostics(void)
{
    if( TRUE == APP_CAN_bDTCStore() )
    {
        _APP_DTC_vCheckCodingValues();
        _APP_DTC_vCheckEcuCoded();
    }
    else
    {
        DEBUG_TEXT(APP_DTC_SWI_WNG, MOD_APP_DTC, "KL15Off/Under-OverVolt/StrtStpBit isSet");
    }
}
/*----------------------------------------------------------------------------*/
/* Function    : _APP_DTC_vMonitorUBatt                                      */
/**
    \brief      function to handle the DTC storage for Voltage monitoring

    \brief      Description:
                function to manage the DTC storage for the different Voltage states


    \param      void
    \return     void
   */
/*----------------------------------------------------------------------------*/
static void _APP_DTC_vMonitorUBatt(void)
{
    PWMGR_enVoltageStates voltageState = Pwrmgr_GetVoltageState();

	if (ON == APP_CAN_u8Klemme15Status())
	{
		DEBUG_TEXT(APP_DTC_SWI_DBG, MOD_APP_DTC, "KL15 is ON");
		switch(voltageState)
		{
			case PWMGR_NormalLowVoltage:
				(void)DEH_AdditionalReportEvent(DTC_C11000_UNTERSPANNUNG, TRUE);
				(void)DEH_AdditionalReportEvent(DTC_C11001_UEBERSPANNUNG, FALSE);
				DEBUG_TEXT(APP_DTC_SWI_WNG, MOD_APP_DTC, "Normal Low Voltage");
			break;

			case PWMGR_NormalLowRecoverVoltage:
				(void)DEH_AdditionalReportEvent(DTC_C11000_UNTERSPANNUNG, FALSE);
				(void)DEH_AdditionalReportEvent(DTC_C11001_UEBERSPANNUNG, FALSE);
				DEBUG_TEXT(APP_DTC_SWI_WNG, MOD_APP_DTC, "Normal Low Recover Voltage");
			break;

			case PWMGR_NormalHighVoltage:
				(void)DEH_AdditionalReportEvent(DTC_C11000_UNTERSPANNUNG, FALSE);
				(void)DEH_AdditionalReportEvent(DTC_C11001_UEBERSPANNUNG, TRUE);
				DEBUG_TEXT(APP_DTC_SWI_WNG, MOD_APP_DTC, "Normal High Voltage");
			break;

			case PWMGR_NormalHighRecoverVoltage:
				(void)DEH_AdditionalReportEvent(DTC_C11000_UNTERSPANNUNG, FALSE);
				(void)DEH_AdditionalReportEvent(DTC_C11001_UEBERSPANNUNG, FALSE);
				DEBUG_TEXT(APP_DTC_SWI_WNG, MOD_APP_DTC, "Normal Recover High Voltage");
			break;

			case PWMGR_NormalVoltage:
				(void)DEH_AdditionalReportEvent(DTC_C11000_UNTERSPANNUNG, FALSE);
				(void)DEH_AdditionalReportEvent(DTC_C11001_UEBERSPANNUNG, FALSE);
				DEBUG_TEXT(APP_DTC_SWI_DBG, MOD_APP_DTC, "Normal Voltage");
			break;

			default:
			break;
		}
	}
}

/*----------------------------------------------------------------------------*/
/* Function    : _APP_DTC_vMonitorTemperature                                 */
/**
    \brief      Montitors for short circuit on Temperature Channel.

    \brief      Description:
                corresponding DTCs are set when a error is detected.

    \return     void

*/
/*----------------------------------------------------------------------------*/
static void _APP_DTC_vMonitorTemperature(void)
{
	Uint8Type u8Temperature;
	u8Temperature  = TEMPERATURE_u8GetTemperature();

	if ((u8Temperature > TEMPERATURE_HIGH) &&
        (u8Temperature < (Uint8Type)TEMPERATURE_LOW))
    {
	    /* Attention - Measurement are only all 2 second - steer over host task */
	    // after 60s temperature > TEMPERATURE_HIGH degree DTC have to register - Config over deh_cfg.c
        DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "Temperature too high");
        (void)DEH_AdditionalReportEvent(DTC_C11003_UEBERTEMPERATUR, TRUE);
        (void)DEH_AdditionalReportEvent(DTC_C11002_UNTERTEMPERATUR, FALSE);
    }
    else if((u8Temperature < (Uint8Type)TEMPERATURE_LOW) &&
            (u8Temperature > TEMPERATURE_HIGH))
    {
	    /* Attention - Measurement are only all 2 second - steer over host task */
	    // after 60s temperature < TEMPERATURE_LOW degree DTC have to register - Config over deh_cfg.c
        DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "Temperature too low");
        (void)DEH_AdditionalReportEvent(DTC_C11003_UEBERTEMPERATUR, FALSE);
        (void)DEH_AdditionalReportEvent(DTC_C11002_UNTERTEMPERATUR, TRUE);
    }
    else
    {
        DEBUG_TEXT(APP_DTC_SWI_DBG, MOD_APP_DTC, "No temperature Error");
        (void)DEH_AdditionalReportEvent(DTC_C11003_UEBERTEMPERATUR, FALSE);
        (void)DEH_AdditionalReportEvent(DTC_C11002_UNTERTEMPERATUR, FALSE);
    }
	DEBUG_VALUE1(APP_DTC_SWI_DBG, MOD_APP_DTC, "Temperature = %d", u8Temperature);
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_DTC_vSlowRampUpDiagnostics                                                    */
/**
    \brief      Diagnostics for slow ramp up pins.

    \brief      Description:
                Some pins such as Power pin and Temperature pins do not require fast measurements
                as they slowly ramp up to their final state. Hence the diagnostics for these pins are
                done in 2 second cycle.

    \return     void
   */
/*----------------------------------------------------------------------------*/
void APP_DTC_vSlowRampUpPinsDiagnostics(void)
{
    _APP_DTC_vMonitorUBatt();
    if( TRUE == APP_CAN_bDTCStore() )
    {
    	_APP_DTC_vMonitorTemperature();
    }
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_DTC_vFastRampUpPinsDiagnostics                                                    */
/**
    \brief      Diagnostics for fast ramp up pins.

    \brief      Description:
                pins such as Audio pin and Baseplate pins etc require fast measurements
                as they qucikly ramp up to their final state. Hence the diagnostics for these pins are
                done in 50ms cycle.

    \return     void
   */
/*----------------------------------------------------------------------------*/
void APP_DTC_vFastRampUpPinsDiagnostics(void)
{
    if( TRUE == APP_CAN_bDTCStore() )
    {
        DEBUG_TEXT(APP_DTC_SWI_DBG, MOD_APP_DTC, "MONITORING START");
        if ( (_APP_DTC_u8StartAudioDiagnoseStartDelay > 10 )  && ( _APP_DTC_bAudioDtcAllowed == BT_FALSE) )
        {
			DEBUG_VALUE1(APP_DTC_SWI_TRC, MOD_APP_DTC, "Audio Diag active after count %d", _APP_DTC_u8StartAudioDiagnoseStartDelay);
			_APP_DTC_bAudioDtcAllowed = BT_TRUE;
        }


        DEBUG_TEXT(APP_DTC_SWI_DBG, MOD_APP_DTC, "MONITORING END");
    }
}

/*----------------------------------------------------------------------------*/
/* Function    : _APP_DTC_vMonitorMikroTelefon                                */
/** 
    \brief      Montitors for short circuit on Mikrophone line.
  
    \brief      Description:
                corresponding DTCs are set when a error is detected. 

    \return     void

*/
/*----------------------------------------------------------------------------*/
static void _APP_DTC_vMonitorMikroTelefon()
{
	
    Uint16Type u16MicrophonePlus;
    /*DTC's
     DTC_0x9d791e  Circ. Res. Out of Range
     DTC_0x9d7913  Circuit Open
     DTC_0x9d7912  Circ. short to Battery
     DTC_0x9d7911  Circ. short to Ground
    */

    u16MicrophonePlus  = MONITOR_ADC_u16GetMovingAverageADCValueMikrophonePlus();

    if ( ((u16MicrophonePlus >= APP_DTC_MICROPHONE_NOPROBLEM_PLUS_MIN) && (u16MicrophonePlus <= APP_DTC_MICROPHONE_NOPROBLEM_PLUS_MAX)) )
    {
        /*Normal*/
            //(void)Dem_SetEventStatus( DTC_0x9d791e, DEM_EVENT_STATUS_PASSED );
            //(void)Dem_SetEventStatus( DTC_0x9d7913, DEM_EVENT_STATUS_PASSED );
            //(void)Dem_SetEventStatus( DTC_0x9d7912, DEM_EVENT_STATUS_PASSED );
            //(void)Dem_SetEventStatus( DTC_0x9d7911, DEM_EVENT_STATUS_PASSED );

            DEBUG_TEXT(APP_DTC_SWI_DBG, MOD_APP_DTC, "No microphone Error");
            APP_DTC_stAppDTC_DeviceDtcStatus.u8MikrophoneStatus = APP_DIAG_DTC_OK;
    }
    else if ( (u16MicrophonePlus > APP_DTC_MICROPHONE_UNTERBRECHNUNG_PLUS_MIN) && (u16MicrophonePlus < APP_DTC_MICROPHONE_UNTERBRECHNUNG_PLUS_MAX)  )
    {
        /*Open circuit*/
            //(void)Dem_SetEventStatus( DTC_0x9d7913, DEM_EVENT_STATUS_PREFAILED );
            //(void)Dem_SetEventStatus( DTC_0x9d791e, DEM_EVENT_STATUS_PASSED );
            //(void)Dem_SetEventStatus( DTC_0x9d7912, DEM_EVENT_STATUS_PASSED );
            //(void)Dem_SetEventStatus( DTC_0x9d7911, DEM_EVENT_STATUS_PASSED );

            DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "open ckt microphone error");
            APP_DTC_stAppDTC_DeviceDtcStatus.u8MikrophoneStatus = APP_DIAG_DTC_OPEN_CIRCUIT;
    }
    else if ( (u16MicrophonePlus >= APP_DTC_MICROPHONE_KURZSCHLUSSNACHPLUS_PLUS) )
    {
        /*Short circuit to Battery*/
            //(void)Dem_SetEventStatus( DTC_0x9d7912, DEM_EVENT_STATUS_PREFAILED );
            //(void)Dem_SetEventStatus( DTC_0x9d791e, DEM_EVENT_STATUS_PASSED );
            //(void)Dem_SetEventStatus( DTC_0x9d7913, DEM_EVENT_STATUS_PASSED );
            //(void)Dem_SetEventStatus( DTC_0x9d7911, DEM_EVENT_STATUS_PASSED );

            DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC to Plus microphone error");
            APP_DTC_stAppDTC_DeviceDtcStatus.u8MikrophoneStatus = APP_DIAG_DTC_SHORT_CIRCUIT_TO_BATTERY;
    }
    else if ( (u16MicrophonePlus <= APP_DTC_MICROPHONE_KURZSCHLUSSNACHMASSE_PLUS)  )
    {
        /*Short circuit to Ground*/
            //(void)Dem_SetEventStatus( DTC_0x9d7911, DEM_EVENT_STATUS_PREFAILED );
            //(void)Dem_SetEventStatus( DTC_0x9d791e, DEM_EVENT_STATUS_PASSED );
            //(void)Dem_SetEventStatus( DTC_0x9d7913, DEM_EVENT_STATUS_PASSED );
            //(void)Dem_SetEventStatus( DTC_0x9d7912, DEM_EVENT_STATUS_PASSED );

            DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC to Gnd microphone");
            APP_DTC_stAppDTC_DeviceDtcStatus.u8MikrophoneStatus = APP_DIAG_DTC_SHORT_CIRCUIT_TO_GROUND;
    }
    else
    {
        /*Circuit resistance out of range by microphone*/
            //(void)Dem_SetEventStatus( DTC_0x9d791e, DEM_EVENT_STATUS_PREFAILED );
            //(void)Dem_SetEventStatus( DTC_0x9d7913, DEM_EVENT_STATUS_PASSED );
            //(void)Dem_SetEventStatus( DTC_0x9d7912, DEM_EVENT_STATUS_PASSED );
            //(void)Dem_SetEventStatus( DTC_0x9d7911, DEM_EVENT_STATUS_PASSED );

            DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "Circuit resistance out of range by microphone");
            APP_DTC_stAppDTC_DeviceDtcStatus.u8MikrophoneStatus = APP_DIAG_DTC_CIRC_RES_OUT_OF_RANGE;
    }

    DEBUG_VALUE1(APP_DTC_SWI_DBG, MOD_APP_DTC, "status microphone = %d ", APP_DTC_stAppDTC_DeviceDtcStatus.u8MikrophoneStatus);
	DEBUG_VALUE1(APP_DTC_SWI_DBG, MOD_APP_DTC, "adcMicrophonePlus = %d", u16MicrophonePlus);
}

/*----------------------------------------------------------------------------*/
/* Function    : _APP_DTC_vMonitorAudioLeftChannel                            */
/** 
    \brief      Montitors for short circuit on Audio Right Channel.
  
    \brief      Description:
                corresponding DTCs are set when a error is detected. 

    \return     void

*/
/*----------------------------------------------------------------------------*/
static void _APP_DTC_vMonitorAudioLeftChannel(void)
{
	//tDEH_Return retVal_u8 = DEH_OK;
	//Uint16Type u16AudioLeftPlus;
	//Uint16Type u16AudioLeftMinus;
	//Uint16Type u16U7V5;
	//BooleanType _APP_DTC_bAudioLeftDtcAllowed;

	//u16AudioLeftPlus  = MONITOR_ADC_u16GetMovingAverageADCValueAudioLeftPlus();
	//u16AudioLeftMinus = MONITOR_ADC_u16GetMovingAverageADCValueAudioLeftMinus(); 	

	//u16U7V5           = MONITOR_ADC_u16GetMovingAverageADCValueU7V5();
    //EEPROM_LAYOUT_vGetPlayerEnabled(&_APP_DTC_bAudioLeftDtcAllowed);
    //if (u16U7V5 != 0)
    //{
    //  u16AudioLeftPlus  = (u16AudioLeftPlus  * (APP_DTC_U7V5_CORR_VALUE / u16U7V5)) >> 4;
    //  u16AudioLeftMinus = (u16AudioLeftMinus * (APP_DTC_U7V5_CORR_VALUE / u16U7V5)) >> 4;
    //}

    //if ( (MONITOR_ADC_u8GetValidSignalForErrorDetection() & MONITOR_ADC_MASK_LEFT_PLUS ) && (MONITOR_ADC_u8GetValidSignalForErrorDetection() & MONITOR_ADC_MASK_LEFT_MINUS ) )
    //{
	//	if ( ((u16AudioLeftPlus > APP_DTC_AUDIO_LEFT_NOPROBLEM_PLUS_MIN) && (u16AudioLeftPlus < APP_DTC_AUDIO_LEFT_NOPROBLEM_PLUS_MAX))
	//		 && ((u16AudioLeftMinus > APP_DTC_AUDIO_LEFT_NOPROBLEM_MINUS_MIN) && (u16AudioLeftMinus < APP_DTC_AUDIO_LEFT_NOPROBLEM_MINUS_MAX)))
	//	{
	//	  if ( (u16AudioLeftPlus - u16AudioLeftMinus) > APP_DTC_AUDIO_LEFT_NOPROBLEM_DELTA_PLUS_MINUS )
	//	  {
	//			if ( _APP_DTC_bAudioLeftDtcAllowed == BT_TRUE)
	//			{
	//				retVal_u8 = DEH_AdditionalReportEvent(DTC_904F11_AUDIOKANALLINKS_KURZSCHLUSSNACHMASSE, FALSE);
	//				retVal_u8 = DEH_AdditionalReportEvent(DTC_904F12_AUDIOKANALLINKS_KURZSCHLUSSNACHPLUS, FALSE);
	//				retVal_u8 = DEH_AdditionalReportEvent(DTC_904FF0_AUDIOKANALLINKS_KURZSCHLUSSUNTEREINANDER, FALSE);
	//				retVal_u8 = DEH_AdditionalReportEvent(DTC_904F13_AUDIOKANALLINKS_UNTERBRECHUNG, FALSE);
	//			}

	//			DEBUG_TEXT(APP_DTC_SWI_DBG, MOD_APP_DTC, "No audio left Error");
	//			DEBUG_VALUE1(APP_DTC_SWI_DBG, MOD_APP_DTC, "adcAudioLeftPlus = %d", u16AudioLeftPlus);
	//			DEBUG_VALUE1(APP_DTC_SWI_DBG, MOD_APP_DTC, "adcAudioLeftMinus = %d", u16AudioLeftMinus);
	//			APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioLeftStatus = APP_DIAG_DTC_OK;
	//	  }
	//	  else
	//	  {
	//			if ( _APP_DTC_bAudioLeftDtcAllowed == BT_TRUE)
	//			{
	//				retVal_u8 = DEH_AdditionalReportEvent(DTC_904F11_AUDIOKANALLINKS_KURZSCHLUSSNACHMASSE, FALSE);
	//				retVal_u8 = DEH_AdditionalReportEvent(DTC_904F12_AUDIOKANALLINKS_KURZSCHLUSSNACHPLUS, FALSE);
	//				retVal_u8 = DEH_AdditionalReportEvent(DTC_904FF0_AUDIOKANALLINKS_KURZSCHLUSSUNTEREINANDER, TRUE);
	//				retVal_u8 = DEH_AdditionalReportEvent(DTC_904F13_AUDIOKANALLINKS_UNTERBRECHUNG, FALSE);
	//			}

	//			DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC among themselves audio left Error");
	//			DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftPlus = %d", u16AudioLeftPlus);
	//			DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftMinus = %d", u16AudioLeftMinus);
	//			APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioLeftStatus = APP_DIAG_DTC_SHORT_CIRCUIT_AMONG_THEMSELVES;
	//	  }
	//	}
	//	else if ( (u16AudioLeftPlus > APP_DTC_AUDIO_LEFT_UNTERBRECHNUNG_PLUS_MIN) && (u16AudioLeftPlus < APP_DTC_AUDIO_LEFT_UNTERBRECHNUNG_PLUS_MAX) && (u16AudioLeftMinus < APP_DTC_AUDIO_LEFT_UNTERBRECHNUNG_MINUS_MAX) )
	//	{
	//		if ( _APP_DTC_bAudioLeftDtcAllowed == BT_TRUE)
	//		{
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F11_AUDIOKANALLINKS_KURZSCHLUSSNACHMASSE, FALSE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F12_AUDIOKANALLINKS_KURZSCHLUSSNACHPLUS, FALSE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904FF0_AUDIOKANALLINKS_KURZSCHLUSSUNTEREINANDER, FALSE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F13_AUDIOKANALLINKS_UNTERBRECHUNG, TRUE);
	//		}

	//		DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "open ckt audio left error");
	//		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftPlus = %d", u16AudioLeftPlus);
	//		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftMinus = %d", u16AudioLeftMinus);
	//		APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioLeftStatus = APP_DIAG_DTC_OPEN_CIRCUIT;
	//	}
	//	else if ( (u16AudioLeftPlus > APP_DTC_AUDIO_LEFT_KURZSCHLUSSNACHPLUS_PLUS_MIN) )
	//	{
	//		if ( _APP_DTC_bAudioLeftDtcAllowed == BT_TRUE)
	//		{
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F11_AUDIOKANALLINKS_KURZSCHLUSSNACHMASSE, FALSE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F12_AUDIOKANALLINKS_KURZSCHLUSSNACHPLUS, TRUE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904FF0_AUDIOKANALLINKS_KURZSCHLUSSUNTEREINANDER, FALSE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F13_AUDIOKANALLINKS_UNTERBRECHUNG, FALSE);
	//		}

	//		DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC to Plus audio left error");
	//		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftPlus = %d", u16AudioLeftPlus);
	//		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftMinus = %d", u16AudioLeftMinus);
	//		APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioLeftStatus = APP_DIAG_DTC_SHORT_CIRCUIT_TO_BATTERY;
	//	}
	//	else if ( (u16AudioLeftPlus <= APP_DTC_AUDIO_LEFT_KURZSCHLUSSNACHMASSE_PLUS_MAX) && (u16AudioLeftMinus < APP_DTC_AUDIO_LEFT_KURZSCHLUSSNACHMASSE_MINUS_MAX) )
	//	{
	//		if ( _APP_DTC_bAudioLeftDtcAllowed == BT_TRUE)
	//		{
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F11_AUDIOKANALLINKS_KURZSCHLUSSNACHMASSE, TRUE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F12_AUDIOKANALLINKS_KURZSCHLUSSNACHPLUS, FALSE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904FF0_AUDIOKANALLINKS_KURZSCHLUSSUNTEREINANDER, FALSE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F13_AUDIOKANALLINKS_UNTERBRECHUNG, FALSE);
	//		}

	//		DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC to Gnd audio left");
	//		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftPlus = %d", u16AudioLeftPlus);
	//		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftMinus = %d", u16AudioLeftMinus);
	//		APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioLeftStatus = APP_DIAG_DTC_SHORT_CIRCUIT_TO_GROUND;
	//	}
	//	else if (u16AudioLeftMinus > APP_DTC_AUDIO_LEFT_KURZSCHLUSSNACHPLUS_MINUS_MIN)
	//	{
	//		if ( _APP_DTC_bAudioLeftDtcAllowed == BT_TRUE)
	//		{
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F11_AUDIOKANALLINKS_KURZSCHLUSSNACHMASSE, FALSE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F12_AUDIOKANALLINKS_KURZSCHLUSSNACHPLUS, TRUE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904FF0_AUDIOKANALLINKS_KURZSCHLUSSUNTEREINANDER, FALSE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F13_AUDIOKANALLINKS_UNTERBRECHUNG, FALSE);
	//		}

	//		DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC to Plus audio left error");
	//		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftPlus = %d", u16AudioLeftPlus);
	//		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftMinus = %d", u16AudioLeftMinus);
	//		APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioLeftStatus = APP_DIAG_DTC_SHORT_CIRCUIT_TO_BATTERY;
	//	}
	//	else if (u16AudioLeftPlus < APP_DTC_AUDIO_RIGHT_NOPROBLEM_PLUS_MIN)
	//	{
	//		if ( _APP_DTC_bAudioLeftDtcAllowed == BT_TRUE)
	//		{
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F11_AUDIOKANALLINKS_KURZSCHLUSSNACHMASSE, TRUE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F12_AUDIOKANALLINKS_KURZSCHLUSSNACHPLUS, FALSE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904FF0_AUDIOKANALLINKS_KURZSCHLUSSUNTEREINANDER, FALSE);
	//			retVal_u8 = DEH_AdditionalReportEvent(DTC_904F13_AUDIOKANALLINKS_UNTERBRECHUNG, FALSE);
	//		}

	//		DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC to Gnd audio left");
	//		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftPlus = %d", u16AudioLeftPlus);
	//		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioLeftMinus = %d", u16AudioLeftMinus);
	//		APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioLeftStatus = APP_DIAG_DTC_SHORT_CIRCUIT_TO_GROUND;
	//	}
	//	if ( _APP_DTC_bAudioLeftDtcAllowed == BT_FALSE)
	//	{
	//		retVal_u8 = DEH_AdditionalReportEvent(DTC_904F11_AUDIOKANALLINKS_KURZSCHLUSSNACHMASSE, FALSE);
	//		retVal_u8 = DEH_AdditionalReportEvent(DTC_904F12_AUDIOKANALLINKS_KURZSCHLUSSNACHPLUS, FALSE);
	//		retVal_u8 = DEH_AdditionalReportEvent(DTC_904FF0_AUDIOKANALLINKS_KURZSCHLUSSUNTEREINANDER, FALSE);
	//		retVal_u8 = DEH_AdditionalReportEvent(DTC_904F13_AUDIOKANALLINKS_UNTERBRECHUNG, FALSE);
	//	}
	//	if ( retVal_u8 != DEH_OK )
	//	{

	//		DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "Audio Links: deh error");
	//	}
	//	DEBUG_VALUE1(APP_DTC_SWI_DBG, MOD_APP_DTC, "status audio left = %d", APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioLeftStatus);
    //}
	//else
	//{
	//	DEBUG_VALUE2(APP_DTC_SWI_ERR, MOD_APP_DTC, "Throw invalid Values Left Plus %d, Left Minus %d", u16AudioLeftPlus, u16AudioLeftMinus );
	//}

}

/*----------------------------------------------------------------------------*/
/* Function    : _APP_DTC_vMonitorAudioRightChannel                                         		  */
/** 
    \brief      Montitors for short circuit on Audio Right Channel.
  
    \brief      Description:
                corresponding DTCs are set when a error is detected. 

    \return     void

*/
/*----------------------------------------------------------------------------*/
static void _APP_DTC_vMonitorAudioRightChannel(void)
{
	//tDEH_Return retVal_u8 = DEH_OK;
	//Uint16Type u16AudioRightPlus;
	//Uint16Type u16AudioRightMinus;
	//Uint16Type u16U7V5;

	//u16AudioRightPlus  = MONITOR_ADC_u16GetMovingAverageADCValueAudioRightPlus();
	//u16AudioRightMinus = MONITOR_ADC_u16GetMovingAverageADCValueAudioRightMinus(); 	
    //u16U7V5            = MONITOR_ADC_u16GetMovingAverageADCValueU7V5();

    //if (u16U7V5 != 0)
    //{
    //  u16AudioRightPlus  = (u16AudioRightPlus  * (APP_DTC_U7V5_CORR_VALUE / u16U7V5)) >> 4;
    //  u16AudioRightMinus = (u16AudioRightMinus * (APP_DTC_U7V5_CORR_VALUE / u16U7V5)) >> 4;
    //}
    //if ( (MONITOR_ADC_u8GetValidSignalForErrorDetection() & MONITOR_ADC_MASK_RIGHT_PLUS ) && (MONITOR_ADC_u8GetValidSignalForErrorDetection() & MONITOR_ADC_MASK_RIGHT_MINUS ) )
    //{
    //    if ( ((u16AudioRightPlus > APP_DTC_AUDIO_RIGHT_NOPROBLEM_PLUS_MIN) && (u16AudioRightPlus < APP_DTC_AUDIO_RIGHT_NOPROBLEM_PLUS_MAX))
    //         && ((u16AudioRightMinus > APP_DTC_AUDIO_RIGHT_NOPROBLEM_MINUS_MIN) && (u16AudioRightMinus < APP_DTC_AUDIO_RIGHT_NOPROBLEM_MINUS_MAX)) )
    //    {
    //        if ( (u16AudioRightPlus - u16AudioRightMinus) > APP_DTC_AUDIO_RIGHT_NOPROBLEM_DELTA_PLUS_MINUS )
    //        {
    //            retVal_u8 = DEH_AdditionalReportEvent(DTC_904E11_AUDIOKANALRECHTS_KURZSCHLUSSNACHMASSE, FALSE);
    //            retVal_u8 = DEH_AdditionalReportEvent(DTC_904E12_AUDIOKANALRECHTS_KURZSCHLUSSNACHPLUS, FALSE);
    //            retVal_u8 = DEH_AdditionalReportEvent(DTC_904EF0_AUDIOKANALRECHTS_KURZSCHLUSSUNTEREINANDER, FALSE);
    //            retVal_u8 = DEH_AdditionalReportEvent(DTC_904E13_AUDIOKANALRECHTS_UNTERBRECHUNG, FALSE);

    //            DEBUG_TEXT(APP_DTC_SWI_DBG, MOD_APP_DTC, "No audio right Error");
    //    		DEBUG_VALUE1(APP_DTC_SWI_DBG, MOD_APP_DTC, "adcAudioRightPlus = %d", u16AudioRightPlus);
    //    		DEBUG_VALUE1(APP_DTC_SWI_DBG, MOD_APP_DTC, "adcAudioRightMinus = %d", u16AudioRightMinus);
    //            APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioRightStatus = APP_DIAG_DTC_OK;
    //        }
    //        else
    //        {
    //            retVal_u8 = DEH_AdditionalReportEvent(DTC_904E11_AUDIOKANALRECHTS_KURZSCHLUSSNACHMASSE, FALSE);
    //            retVal_u8 = DEH_AdditionalReportEvent(DTC_904E12_AUDIOKANALRECHTS_KURZSCHLUSSNACHPLUS, FALSE);
    //            retVal_u8 = DEH_AdditionalReportEvent(DTC_904EF0_AUDIOKANALRECHTS_KURZSCHLUSSUNTEREINANDER, TRUE);
    //            retVal_u8 = DEH_AdditionalReportEvent(DTC_904E13_AUDIOKANALRECHTS_UNTERBRECHUNG, FALSE);

    //            DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC among themselves audio right Error");
    //    		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightPlus = %d", u16AudioRightPlus);
    //    		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightMinus = %d", u16AudioRightMinus);
    //            APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioRightStatus = APP_DIAG_DTC_SHORT_CIRCUIT_AMONG_THEMSELVES;
    //      }
    //    }
    //    else if ( (u16AudioRightPlus > APP_DTC_AUDIO_RIGHT_UNTERBRECHNUNG_PLUS_MIN) && (u16AudioRightPlus < APP_DTC_AUDIO_RIGHT_UNTERBRECHNUNG_PLUS_MAX) && (u16AudioRightMinus < APP_DTC_AUDIO_RIGHT_UNTERBRECHNUNG_MINUS_MAX) )
    //    {
    //        retVal_u8 = DEH_AdditionalReportEvent(DTC_904E11_AUDIOKANALRECHTS_KURZSCHLUSSNACHMASSE, FALSE);
    //        retVal_u8 = DEH_AdditionalReportEvent(DTC_904E12_AUDIOKANALRECHTS_KURZSCHLUSSNACHPLUS, FALSE);
    //        retVal_u8 = DEH_AdditionalReportEvent(DTC_904EF0_AUDIOKANALRECHTS_KURZSCHLUSSUNTEREINANDER, FALSE);
    //        retVal_u8 = DEH_AdditionalReportEvent(DTC_904E13_AUDIOKANALRECHTS_UNTERBRECHUNG, TRUE);

    //        DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "open ckt audio right error");
    //		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightPlus = %d", u16AudioRightPlus);
    //		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightMinus = %d", u16AudioRightMinus);
    //        APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioRightStatus = APP_DIAG_DTC_OPEN_CIRCUIT;
    //    }
    //    else if ( (u16AudioRightPlus > APP_DTC_AUDIO_RIGHT_KURZSCHLUSSNACHPLUS_PLUS_MIN) )
    //    {
    //        retVal_u8 = DEH_AdditionalReportEvent(DTC_904E11_AUDIOKANALRECHTS_KURZSCHLUSSNACHMASSE, FALSE);
    //        retVal_u8 = DEH_AdditionalReportEvent(DTC_904E12_AUDIOKANALRECHTS_KURZSCHLUSSNACHPLUS, TRUE);
    //        retVal_u8 = DEH_AdditionalReportEvent(DTC_904EF0_AUDIOKANALRECHTS_KURZSCHLUSSUNTEREINANDER, FALSE);
    //        retVal_u8 = DEH_AdditionalReportEvent(DTC_904E13_AUDIOKANALRECHTS_UNTERBRECHUNG, FALSE);

    //        DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC to Plus audio right error");
    //		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightPlus = %d", u16AudioRightPlus);
    //		DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightMinus = %d", u16AudioRightMinus);
    //        APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioRightStatus = APP_DIAG_DTC_SHORT_CIRCUIT_TO_BATTERY;
    //    }
    //    else if ( (u16AudioRightPlus <= APP_DTC_AUDIO_RIGHT_KURZSCHLUSSNACHMASSE_PLUS_MAX) && (u16AudioRightMinus < APP_DTC_AUDIO_RIGHT_KURZSCHLUSSNACHMASSE_MINUS_MAX) )
    //    {
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904E11_AUDIOKANALRECHTS_KURZSCHLUSSNACHMASSE, TRUE);
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904E12_AUDIOKANALRECHTS_KURZSCHLUSSNACHPLUS, FALSE);
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904EF0_AUDIOKANALRECHTS_KURZSCHLUSSUNTEREINANDER, FALSE);
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904E13_AUDIOKANALRECHTS_UNTERBRECHUNG, FALSE);

    //			DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC to Gnd audio right");
    //			DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightPlus = %d", u16AudioRightPlus);
    //			DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightMinus = %d", u16AudioRightMinus);
    //			APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioRightStatus = APP_DIAG_DTC_SHORT_CIRCUIT_TO_GROUND;
    //    }
    //    else if (u16AudioRightMinus > APP_DTC_AUDIO_RIGHT_KURZSCHLUSSNACHPLUS_MINUS_MIN)
    //    {
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904E11_AUDIOKANALRECHTS_KURZSCHLUSSNACHMASSE, FALSE);
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904E12_AUDIOKANALRECHTS_KURZSCHLUSSNACHPLUS, TRUE);
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904EF0_AUDIOKANALRECHTS_KURZSCHLUSSUNTEREINANDER, FALSE);
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904E13_AUDIOKANALRECHTS_UNTERBRECHUNG, FALSE);

    //			DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC to Plus audio right error");
    //			DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightPlus = %d", u16AudioRightPlus);
    //			DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightMinus = %d", u16AudioRightMinus);
    //			APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioRightStatus = APP_DIAG_DTC_SHORT_CIRCUIT_TO_BATTERY;
    //    }
    //    else if (u16AudioRightPlus < APP_DTC_AUDIO_RIGHT_NOPROBLEM_PLUS_MIN)
    //    {
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904E11_AUDIOKANALRECHTS_KURZSCHLUSSNACHMASSE, TRUE);
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904E12_AUDIOKANALRECHTS_KURZSCHLUSSNACHPLUS, FALSE);
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904EF0_AUDIOKANALRECHTS_KURZSCHLUSSUNTEREINANDER, FALSE);
    //		  retVal_u8 = DEH_AdditionalReportEvent(DTC_904E13_AUDIOKANALRECHTS_UNTERBRECHUNG, FALSE);

    //			DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SC to Gnd audio right");
    //			DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightPlus = %d", u16AudioRightPlus);
    //			DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "adcAudioRightMinus = %d", u16AudioRightMinus);
    //			APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioRightStatus = APP_DIAG_DTC_SHORT_CIRCUIT_TO_GROUND;
    //    }
    //	if ( retVal_u8 != DEH_OK )
    //	{

    //		DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "Audio Recht: deh error");
    //	}
    //	DEBUG_VALUE1(APP_DTC_SWI_DBG, MOD_APP_DTC, "status audio right = %d", APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioRightStatus);
    //}
    //else
    //{
    //	DEBUG_VALUE2(APP_DTC_SWI_ERR, MOD_APP_DTC, "Throw invalid Values Right Plus %d, Right Minus %d", u16AudioRightPlus, u16AudioRightMinus );
    //}

}


/*----------------------------------------------------------------------------*/
/* Function    : APP_DTC_vStartupSequence                                         		  */
/**
    \brief      diagnosis coding connect check

    \brief      Description:
                this function check whether coding items are not coded but connected and reversed

    \return     void
*/
/*----------------------------------------------------------------------------*/
void APP_DTC_vStartupSequence(void)
{
  	//data download handling

	if ( (_APP_DTC_bStartUpFinished == BT_TRUE))
	{
		;
	}
	else
	{
		switch(_APP_DTC_enAppDtcStartSequence)
		{
			case enAppDtcReadValuesOnStartUp:
			{
				_APP_DTC_enAppDtcStartSequence = enAppDtcInitialize;
				break;
			}
			case enAppDtcInitialize:
            {
                if ( (osGetSystemCounter() > 4000) )
                {
                    /*initialize DTC's*/
                    //(void)Dem_SetEventStatus( DTC_0x9d791e, DEM_EVENT_STATUS_PASSED );
                    //(void)Dem_SetEventStatus( DTC_0x9d7913, DEM_EVENT_STATUS_PASSED );
                    //(void)Dem_SetEventStatus( DTC_0x9d7912, DEM_EVENT_STATUS_PASSED );
                    //(void)Dem_SetEventStatus( DTC_0x9d7911, DEM_EVENT_STATUS_PASSED );
                    //(void)Dem_SetEventStatus( DTC_0xf00051, DEM_EVENT_STATUS_PASSED );
                    //(void)Dem_SetEventStatus( DTC_0xf00046, DEM_EVENT_STATUS_PASSED );
                    //(void)Dem_SetEventStatus( DTC_0xf00045, DEM_EVENT_STATUS_PASSED );
                    //(void)Dem_SetEventStatus( DTC_0xf00044, DEM_EVENT_STATUS_PASSED );
                    //(void)Dem_SetEventStatus( DTC_0xf00041, DEM_EVENT_STATUS_PASSED );
                    //(void)Dem_SetEventStatus( DTC_0xe10100, DEM_EVENT_STATUS_PASSED );
                    //(void)Dem_SetEventStatus( DTC_0xe10000, DEM_EVENT_STATUS_PASSED );
                    //(void)Dem_SetEventStatus( DTC_0xc01088, DEM_EVENT_STATUS_PASSED );

                    _APP_DTC_enAppDtcStartSequence = enAppDtcStartMonitoringCodierung;
                }
                break;
            }
			case enAppDtcStartMonitoringCodierung:
			{
				if ( (osGetSystemCounter() > 6000) )
				{
					_APP_DTC_bStartUpFinished = BT_TRUE;
					DEBUG_TEXT(APP_DTC_SWI_TRC, MOD_APP_DTC, "APP DTC Startup Finished");
				}
				break;
			}
		}
	}
}


/*----------------------------------------------------------------------------*/
/* Function    : _APP_DTC_vCheckEcuCoded                                      */
/**
    \brief      diagnosis to check if the ECU is coded.

    \brief      Description:
                This function checks if the ECU has already been coded. The check is done every 2 seconds
                and after successful coding the FSP should be completely deleted.

    \return     void
*/
/*----------------------------------------------------------------------------*/
static void _APP_DTC_vCheckEcuCoded(void)
{
	//tDEH_Return retVal_u8 = DEH_OK;
	//Uint8Type u8CodedDoneAnyTime;
	//BooleanType bSteuerGeraetNichtCodiert = BT_FALSE;

	//(void)EEPROM_enGetSingleByteFromRamMirror(&u8CodedDoneAnyTime, EEPROM_LAYOUT_ENUM_VWTesterCodingInformation);
	//// Low nibble is length of coding
	//// High nibble is for coding write successful done. High nibble value 0x1 is define as successful coding
	//if (((u8CodedDoneAnyTime & 0xF0)>> 4)!= 0x01)
	//{
	//	bSteuerGeraetNichtCodiert = BT_TRUE;
	//}

	//if (bSteuerGeraetNichtCodiert == BT_TRUE)
	//{
	//	(void)DEH_AdditionalReportEvent(DTC_D01300_SG_NICHTCODIERT, TRUE);
	//	DEBUG_TEXT(APP_DTC_SWI_DBG, MOD_APP_DTC, "SU,00-in-date");
	//}
	//else
	//{
	//	retVal_u8 = DEH_ClearEvent(DTC_D01300_SG_NICHTCODIERT);
	//	DEBUG_TEXT(APP_DTC_SWI_DBG,MOD_APP_DTC,"SU,CodingDateReady");
	//}

}
/*----------------------------------------------------------------------------*/
/* Function    : _APP_DTC_vCheckCodingValues                                         		  */
/** 
    \brief      diagnosis coding connect check
  
    \brief      Description:
                this function check whether coding items are not coded but connected and reversed 

    \return     void
*/
/*----------------------------------------------------------------------------*/
static void _APP_DTC_vCheckCodingValues(void)
{
	//tDEH_Return retVal_u8 = DEH_OK;
	//SuccessFailType sF = SUCCESS;
    //Uint8Type u8EepromCodingParameters[ID_2E_0600_CODIERUNG_MAX_LEN];

	//(void)EEPROM_enGetByteSequenceFromRamMirror(&u8EepromCodingParameters[0], ID_2E_0600_CODIERUNG_MAX_LEN, EEPROM_LAYOUT_ENUM_VWCodingValue);
	//if ( _APP_DTC_u8CurrentVariantType == 0xFF)
	//{
	//	DEBUG_VALUE1(APP_DTC_SWI_ERR, MOD_APP_DTC, "VAriant still not read from E2P %d", _APP_DTC_u8CurrentVariantType);
	//}
	//else
	//{
	//	if (( _APP_DTC_u8CurrentVariantType == 0x00 ) || ( _APP_DTC_u8CurrentVariantType == 0x02 )) // HW without cradle support
	//	{
	//		if ((u8EepromCodingParameters[5] == 0))
	//			 sF = FAIL;    // AerialDiagnosis ein codiert, aber hardwaremäßig nicht verbunden.

	//		if ((u8EepromCodingParameters[6] == 0) || (u8EepromCodingParameters[6] == 2))
	//			 sF = FAIL;    // BaseplateDiagnosis ein codiert, aber hardwaremäßig nicht verbunden.
	//	}
	//	else if( _APP_DTC_u8CurrentVariantType == 0x01 ) // HW with cradle support
	//	{
	//		if ((u8EepromCodingParameters[5] == 1) && (APP_DTC_stAppDTC_DeviceDtcStatus.u8AntennaStatus == APP_DIAG_DTC_OK)
	//				&& (APP_DTC_stAppDTC_DeviceDtcStatus.u8AntennaStatus != APP_DIAG_DTC_INVALID))
	//		{
	//			 sF = FAIL;    // AerialDiagnosis aus codiert, aber hardwaremäßig verbunden => also falsch kodiert
	//		}

	//		if ((u8EepromCodingParameters[6] == 1) && (APP_DTC_stAppDTC_DeviceDtcStatus.u8BaseplateStatus == APP_DIAG_DTC_OK)
	//			&& (APP_DTC_stAppDTC_DeviceDtcStatus.u8BaseplateStatus != APP_DIAG_DTC_INVALID))
	//		{
	//			sF = FAIL;    // BaseplateDiagnosis aus codiert, aber hardwaremäßig verbunden => also falsch kodiert
	//		}
	//	}
	//	if ((u8EepromCodingParameters[7] == 0x10) && (APP_DTC_stAppDTC_DeviceDtcStatus.u83ButtonModuleStatus == APP_DIAG_DTC_OK)
	//		&& (APP_DTC_stAppDTC_DeviceDtcStatus.u83ButtonModuleStatus != APP_DIAG_DTC_INVALID))
	//	{
	//		 sF = FAIL;    // RooflineDiagnosis aus codiert, aber hardwaremäßig verbunden => also falsch kodiert
	//	}

	//	if (sF == FAIL)
	//	{
	//		DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "SG is coded wrongly");
	//		retVal_u8 = DEH_AdditionalReportEvent(DTC_D01400_SG_FALSCHCODIERT, TRUE);
	//	}
	//	else
	//	{
	//		APP_DTC_stAppDTC_DeviceDtcStatus.u8CodingStatus = APP_DIAG_DTC_OK;
	//		retVal_u8 = DEH_ClearEvent(DTC_D01400_SG_FALSCHCODIERT);
	//	}
	//}
}



/*----------------------------------------------------------------------------*/
/* Function    : APP_DTC_u8GetStatusMikroTelefon                                   */
/**
    \brief      returns the current status of the microphone lines.

    \brief      

    \return     Uint8Type
                
   */
/*----------------------------------------------------------------------------*/
Uint8Type APP_DTC_u8GetStatusMikroTelefon(void)
{   
    return  (APP_DTC_stAppDTC_DeviceDtcStatus.u8MikrophoneStatus );
}


/*----------------------------------------------------------------------------*/
/* Function    : APP_DTC_u8GetVariantType                                   */
/**
    \brief      returns the UHV Variant

    \brief      

    \return     Uint8Type
              
*/
/*----------------------------------------------------------------------------*/
Uint8Type APP_DTC_u8GetVariantType(void)
{   
    return  (_APP_DTC_u8CurrentVariantType);
}
/*----------------------------------------------------------------------------*/
/* Function    : APP_DTC_u8GetStatusAudioLeft                                   */
/**
    \brief      returns the current status of the Audio left lines.

    \brief      

    \return     Uint8Type
                
   */
/*----------------------------------------------------------------------------*/
Uint8Type APP_DTC_u8GetStatusAudioLeft(void)
{   
    return  (APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioLeftStatus );
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_DTC_u8GetStatusAudioRight                                   */
/**
    \brief      returns the current status of the Audio Right lines.

    \brief      

    \return     Uint8Type
              value of Audio Right status
                
   */
/*----------------------------------------------------------------------------*/
Uint8Type APP_DTC_u8GetStatusAudioRight(void)
{   
    return  (APP_DTC_stAppDTC_DeviceDtcStatus.u8AudioRightStatus );
}


/*----------------------------------------------------------------------------*/
/* Function    : APP_DTC_bAudioAllowed                                   */
/**
    \brief      returns the current status of audio adc monitoring is allowed or not

    \brief      Audio Diagnose will be done in the following situation:
				1. When the elapsed time from the time of ECU Start is lesser than 4 seconds 
				and the no Audio Mute has been requested from any application ( Telefon, Voice, MDI )
				within this time
				2. When a Diagnose session is active.

    \return     BooleanType
               status of audio adc monitoring
                
   */
/*----------------------------------------------------------------------------*/
BooleanType APP_DTC_bGetAudioAllowed(void)
{
	if ( !(_APP_DTC_bStartUpFinished)  ||
          (kDescStateSessionDefault != ApplDescGetActiveDiagnosticSession()))
	{
		if ( _APP_DTC_bAudioDtcAllowed == BT_FALSE )
		{
			_APP_DTC_u8StartAudioDiagnoseStartDelay++;
			if ( _APP_DTC_u8StartAudioDiagnoseStartDelay == 0x01 )
			{
				DEBUG_TEXT(APP_DTC_SWI_TRC, MOD_APP_DTC, "Hardware Audio Diag triggered");
				AUDIO_DIAG_START
			}
		}
	}
#ifndef AUDIO_DIAG_ALWAYS_ON
	else
    {
		if ( _APP_DTC_u8StartAudioDiagnoseStartDelay > 0   )
		{
			_APP_DTC_u8StartAudioDiagnoseStartDelay = 0;
			DEBUG_TEXT(APP_DTC_SWI_TRC, MOD_APP_DTC, "Audio Diag not active");
			AUDIO_DIAG_END
			_APP_DTC_bAudioDtcAllowed = BT_FALSE;
		}
    }
#endif
    return  (_APP_DTC_bAudioDtcAllowed );

}



/* End Of File APP_DTC_C1.c */
