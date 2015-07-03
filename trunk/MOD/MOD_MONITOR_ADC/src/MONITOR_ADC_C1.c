/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/** 
 * \file 	MONITOR_ADC_C1.c
 * \brief	This module monitors the audio channel and intimates the Diagnostic for errors.
 * \brief	This file fulfills the following requirements:
 * 			1. Requirement 1
 * 			2. Requirement 2
 * 			3. Requirement x
*/
/*-----------------------------------------------------------------------------
 * $Date: 2011-04-20 10:31:20 +0200 (Mi, 20 Apr 2011) $
 * $Rev: 19199 $
 * $Author: kolozsvary $
 * $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_MONITOR_ADC/trunk/src/MONITOR_ADC_C1.c $
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
#include "MONITOR_ADC.h"
#include "ADC.h"
#include "HET.h"
#include "PORT_CE.h"
#include "APP_DTC.h"
#include "TRACE.h"
#include "MONITOR_ADC_C1.id"
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/
/** 
 \brief	example
 */
static Uint8Type MONITOR_ADC_u8MultiplexerState = 0;

typedef struct
{
    Uint16Type u16ADCValueAmplifierWakeUp;
    Uint16Type u16ADCValueDisplayPwm;
    Uint16Type u16ADCValueDisplayWakeUp;
    Uint16Type u16ADCValueVoltageAntenneOn;
    Uint16Type u16ADCValueVoltageFm1;
    Uint16Type u16ADCValueVoltageFm2;
    Uint16Type u16ADCValueVoltageDabSdars;
    Uint16Type u16ADCValueVoltageCamera;
    Uint16Type u16ADCValue5VCan;
    Uint16Type u16ADCValue5V2;
    Uint16Type u16ADCValueCurrentAntenneOn;
    Uint16Type u16ADCValueCurrentFm1;
    Uint16Type u16ADCValueCurrentFm2;
    Uint16Type u16ADCValueCurrentDabSdars;
    Uint16Type u16ADCValueCurrentCamera;
    Uint16Type u16ADCValueVoltageGps;
    Uint16Type u16ADCValueCurrentGps;
    Uint16Type u16ADCValueVoltageUsbHost1Bus;
    Uint16Type u16ADCValueVoltageUsbHost2Bus;
    Uint16Type u16ADCValueCurrentUsbHost1Bus;
    Uint16Type u16ADCValueCurrentUsbHost2Bus;
    Uint16Type u16ADCValue9V;
    Uint16Type u16ADCValueVoltageMikrophone;
    Uint16Type u16ADCValueMikrophonePlus;
    Uint16Type u16ADCValueAudioLeftPlus;
    Uint16Type u16ADCValueAudioLeftMinus;
    Uint16Type u16ADCValueAudioRightPlus;
    Uint16Type u16ADCValueAudioRightMinus;
    Uint16Type u16ADCValueTemperature;
    Uint16Type u16ADCValueUBatt;
    Uint8Type u8ValidSignalForErrorDetection;
}MONITOR_ADC_ValueType;

static MONITOR_ADC_ValueType adcMovingAverageValue;

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
    /* Mux 1 */
    enAmpWakeUpDiag,
    enDispPwmDiag,
    enDispWakeUpDiag,
    enUAntenneOn,
    enUFm1,
    enUFm2,
    enUDabSdars,
    enUCam,
    /* Mux 2 */
	enTemperature,
    en5VCan,
    en5V2,
    enIAntenneOn,
    enIFm1,
    enIFm2,
    enIDabSdars,
    enICam,

    enUBatt,
    enUGps,
    enIGps,
    enUsbHost1VBus,
    enUsbHost2VBus,
    enUsbHost1Cur,
    enUsbHost2Cur,
    en9V,
	enUMicrophone,
	enMicrophonePlus,
	enAudioLeftPlus,
	enAudioLeftMinus,
	enAudioRightPlus,
	enAudioRightMinus
} ENUM_AUDIO_LINE;
/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/
static SuccessFailType _MONITOR_ADC_u16MovingAverageADCValue(Uint16Type u16MovingAverageADCValueforDTC,
		ENUM_AUDIO_LINE u8AudioLineType);
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
/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/
/* Function    : _MONITOR_ADC_u16MovingAverageADCValue                        */
/** 
 \brief      Read ADC values and store it in a variable.
 
 \brief      Description:
 Read ADC Values, calculate the moving average and store it.

 \return     SuccessFailType
 If the function was successful or failed
 SUCCESS, FAIL
 */
/*----------------------------------------------------------------------------*/
static SuccessFailType _MONITOR_ADC_u16MovingAverageADCValue(Uint16Type u16MovingAverageADCValueforDTC,
		ENUM_AUDIO_LINE u8AudioLineType)
{
	switch (u8AudioLineType)
	{
	    case enAmpWakeUpDiag:
	        adcMovingAverageValue.u16ADCValueAmplifierWakeUp =
                (adcMovingAverageValue.u16ADCValueAmplifierWakeUp + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enDispPwmDiag:
	        adcMovingAverageValue.u16ADCValueDisplayPwm =
                (adcMovingAverageValue.u16ADCValueDisplayPwm + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enDispWakeUpDiag:
	        adcMovingAverageValue.u16ADCValueDisplayWakeUp =
	            (adcMovingAverageValue.u16ADCValueDisplayWakeUp + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enUAntenneOn:
	        adcMovingAverageValue.u16ADCValueVoltageAntenneOn =
                (adcMovingAverageValue.u16ADCValueVoltageAntenneOn + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enIAntenneOn:
	        adcMovingAverageValue.u16ADCValueCurrentAntenneOn =
                (adcMovingAverageValue.u16ADCValueCurrentAntenneOn + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enUFm1:
	        adcMovingAverageValue.u16ADCValueVoltageFm1 =
                (adcMovingAverageValue.u16ADCValueVoltageFm1 + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enIFm1:
	        adcMovingAverageValue.u16ADCValueCurrentFm1 =
                (adcMovingAverageValue.u16ADCValueCurrentFm1 + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enUFm2:
	         adcMovingAverageValue.u16ADCValueVoltageFm2 =
                (adcMovingAverageValue.u16ADCValueVoltageFm2 + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enIFm2:
	         adcMovingAverageValue.u16ADCValueCurrentFm2 =
                (adcMovingAverageValue.u16ADCValueCurrentFm2 + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enUDabSdars:
	        adcMovingAverageValue.u16ADCValueVoltageDabSdars =
                (adcMovingAverageValue.u16ADCValueVoltageDabSdars + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enIDabSdars:
	        adcMovingAverageValue.u16ADCValueCurrentDabSdars =
                (adcMovingAverageValue.u16ADCValueCurrentDabSdars + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enUCam:
	        adcMovingAverageValue.u16ADCValueVoltageCamera =
                (adcMovingAverageValue.u16ADCValueVoltageCamera + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enICam:
	        adcMovingAverageValue.u16ADCValueCurrentCamera =
                (adcMovingAverageValue.u16ADCValueCurrentCamera + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enUBatt:
	        adcMovingAverageValue.u16ADCValueUBatt =
                (adcMovingAverageValue.u16ADCValueUBatt + u16MovingAverageADCValueforDTC ) / 2U;
	        break;
	    case enTemperature:
            adcMovingAverageValue.u16ADCValueTemperature =
                (adcMovingAverageValue.u16ADCValueTemperature + u16MovingAverageADCValueforDTC ) / 2U;
            break;
	    case en5VCan:
            adcMovingAverageValue.u16ADCValue5VCan  =
                (adcMovingAverageValue.u16ADCValue5VCan + u16MovingAverageADCValueforDTC ) / 2U;
            break;
	    case en5V2:
            adcMovingAverageValue.u16ADCValue5V2 =
                (adcMovingAverageValue.u16ADCValue5V2 + u16MovingAverageADCValueforDTC ) / 2U;
            break;
	    case enUGps:
            adcMovingAverageValue.u16ADCValueVoltageGps =
                (adcMovingAverageValue.u16ADCValueVoltageGps+ u16MovingAverageADCValueforDTC ) / 2U;
            break;
	    case enIGps:
            adcMovingAverageValue.u16ADCValueCurrentGps =
                (adcMovingAverageValue.u16ADCValueCurrentGps + u16MovingAverageADCValueforDTC ) / 2U;
            break;
        case enUsbHost1VBus:
            adcMovingAverageValue.u16ADCValueVoltageUsbHost1Bus =
                (adcMovingAverageValue.u16ADCValueVoltageUsbHost1Bus + u16MovingAverageADCValueforDTC ) / 2U;
            break;
        case enUsbHost2VBus:
            adcMovingAverageValue.u16ADCValueVoltageUsbHost2Bus =
                (adcMovingAverageValue.u16ADCValueVoltageUsbHost2Bus + u16MovingAverageADCValueforDTC ) / 2U;
            break;
        case enUsbHost1Cur:
            adcMovingAverageValue.u16ADCValueCurrentUsbHost1Bus =
                (adcMovingAverageValue.u16ADCValueCurrentUsbHost1Bus + u16MovingAverageADCValueforDTC ) / 2U;
            break;
        case enUsbHost2Cur:
            adcMovingAverageValue.u16ADCValueCurrentUsbHost2Bus =
                (adcMovingAverageValue.u16ADCValueCurrentUsbHost2Bus + u16MovingAverageADCValueforDTC ) / 2U;
            break;
        case en9V:
            adcMovingAverageValue.u16ADCValue9V =
                (adcMovingAverageValue.u16ADCValue9V + u16MovingAverageADCValueforDTC ) / 2U;
            break;
	    case enUMicrophone:
            adcMovingAverageValue.u16ADCValueVoltageMikrophone =
                (adcMovingAverageValue.u16ADCValueVoltageMikrophone  + u16MovingAverageADCValueforDTC ) / 2U;
            break;
	    case enMicrophonePlus:
            adcMovingAverageValue.u16ADCValueMikrophonePlus =
                (adcMovingAverageValue.u16ADCValueMikrophonePlus + u16MovingAverageADCValueforDTC ) / 2U;
            break;

	    case enAudioLeftPlus:
	        adcMovingAverageValue.u16ADCValueAudioLeftPlus =
                (adcMovingAverageValue.u16ADCValueAudioLeftPlus + u16MovingAverageADCValueforDTC ) / 2U;
	        if ( abs(adcMovingAverageValue.u16ADCValueAudioLeftPlus - u16MovingAverageADCValueforDTC) <= 1)
	        {
	    		adcMovingAverageValue.u8ValidSignalForErrorDetection |= MONITOR_ADC_MASK_LEFT_PLUS;
	    	}
	    	else
	    	{
	    		DEBUG_VALUE1(MONITOR_ADC_SWI_WNG, MOD_MONITOR_ADC, "Last Left Plus Value not in range 2, Detection Invalid %d", u16MovingAverageADCValueforDTC);
	    		adcMovingAverageValue.u8ValidSignalForErrorDetection &= MONITOR_ADC_MASK_LEFT_PLUS;
	    	}
	    	break;
	    case enAudioLeftMinus:
	    	adcMovingAverageValue.u16ADCValueAudioLeftMinus
	    			= (adcMovingAverageValue.u16ADCValueAudioLeftMinus + u16MovingAverageADCValueforDTC ) / 2U;
	    	if ( abs(adcMovingAverageValue.u16ADCValueAudioLeftMinus - u16MovingAverageADCValueforDTC) <= 1)
	    	{
	    		adcMovingAverageValue.u8ValidSignalForErrorDetection |= MONITOR_ADC_MASK_LEFT_MINUS;
	    	}
	    	else
	    	{
	    		DEBUG_VALUE1(MONITOR_ADC_SWI_WNG, MOD_MONITOR_ADC, "Last Left Minus Value not in range 2, Detection Invalid %d", u16MovingAverageADCValueforDTC);
	    		adcMovingAverageValue.u8ValidSignalForErrorDetection &= MONITOR_ADC_MASK_LEFT_MINUS;
	    	}
	    	break;
	    case enAudioRightPlus:
	    	adcMovingAverageValue.u16ADCValueAudioRightPlus
	    			= (adcMovingAverageValue.u16ADCValueAudioRightPlus + u16MovingAverageADCValueforDTC ) / 2U;
	    	if ( abs(adcMovingAverageValue.u16ADCValueAudioRightPlus - u16MovingAverageADCValueforDTC) <= 1)
	    	{
	    		adcMovingAverageValue.u8ValidSignalForErrorDetection |= MONITOR_ADC_MASK_RIGHT_PLUS;
	    	}
	    	else
	    	{
	    		DEBUG_VALUE1(MONITOR_ADC_SWI_WNG, MOD_MONITOR_ADC, "Last Right Plus Value not in range 2, Detection Invalid %d", u16MovingAverageADCValueforDTC);
	    		adcMovingAverageValue.u8ValidSignalForErrorDetection &= MONITOR_ADC_MASK_RIGHT_PLUS;
	    	}
	    	break;
	    case enAudioRightMinus:
	    	adcMovingAverageValue.u16ADCValueAudioRightMinus
	    			= (adcMovingAverageValue.u16ADCValueAudioRightMinus + u16MovingAverageADCValueforDTC ) / 2U;
	    	if ( abs(adcMovingAverageValue.u16ADCValueAudioRightMinus - u16MovingAverageADCValueforDTC) <= 1)
	    	{
	    		adcMovingAverageValue.u8ValidSignalForErrorDetection |= MONITOR_ADC_MASK_RIGHT_MINUS;
	    	}
	    	else
	    	{
	    		DEBUG_VALUE1(MONITOR_ADC_SWI_WNG, MOD_MONITOR_ADC, "Last Right Minus Value not in range 2, Detection Invalid %d", u16MovingAverageADCValueforDTC);
	    		adcMovingAverageValue.u8ValidSignalForErrorDetection &= MONITOR_ADC_MASK_RIGHT_MINUS;
	    	}
	    	break;
	}
	return SUCCESS;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_sfReadADCValueForAudioDTCs                       */
/** 
 \brief      Read ADC values and store it in a variable.
 
 \brief      Description:
 Read ADC Values, calculate the moving average and store it.

 \return     SuccessFailType
 If the function was successful or failed
 SUCCESS, FAIL
 */
/*----------------------------------------------------------------------------*/
SuccessFailType MONITOR_ADC_sfReadADCValueForDTCs(void)
{
    MONITOR_ADC_ValueType tempADCValue;
    (void)memset(&tempADCValue, 0x00, sizeof(MONITOR_ADC_ValueType));

#if 0
	tempADCValueAntenna = (tempADCValueAntenna * 666)/(ADC_U16GETADCVALUE(ADC_UBATT));
#endif
    switch(MONITOR_ADC_u8MultiplexerState)
    {
        case 0:
            tempADCValue.u16ADCValueAmplifierWakeUp = ADC_U16GETADCVALUE(ADC_DIAG_MUX_1);
            tempADCValue.u16ADCValueTemperature = ADC_U16GETADCVALUE(ADC_DIAG_MUX_2);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueAmplifierWakeUp = %d", tempADCValue.u16ADCValueAmplifierWakeUp);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueTemperature = %d", tempADCValue.u16ADCValueTemperature);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueAmplifierWakeUp, enAmpWakeUpDiag);
	        (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueTemperature ,enTemperature);
            HET_vPinWrite(HET_MUX_A0, HIGH);
            HET_vPinWrite(HET_MUX_A1, LOW);
            HET_vPinWrite(HET_MUX_A2, LOW);
            MONITOR_ADC_u8MultiplexerState = 1;
            break;
        case 1:
            tempADCValue.u16ADCValueDisplayPwm = ADC_U16GETADCVALUE(ADC_DIAG_MUX_1);
            tempADCValue.u16ADCValue5VCan = ADC_U16GETADCVALUE(ADC_DIAG_MUX_2);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueDisplayPwm = %d", tempADCValue.u16ADCValueDisplayPwm);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValue5VCan = %d", tempADCValue.u16ADCValue5VCan);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueDisplayPwm, enDispPwmDiag);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValue5VCan, en5VCan);
            HET_vPinWrite(HET_MUX_A0, LOW);
            HET_vPinWrite(HET_MUX_A1, HIGH);
            HET_vPinWrite(HET_MUX_A2, LOW);
            MONITOR_ADC_u8MultiplexerState = 2;
            break;
        case 2:
            tempADCValue.u16ADCValueDisplayWakeUp = ADC_U16GETADCVALUE(ADC_DIAG_MUX_1);
            tempADCValue.u16ADCValue5V2 = ADC_U16GETADCVALUE(ADC_DIAG_MUX_2);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueDisplayWakeUp = %d", tempADCValue.u16ADCValueDisplayWakeUp);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValue5V2 = %d", tempADCValue.u16ADCValue5V2);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueDisplayWakeUp, enDispWakeUpDiag);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValue5V2, en5V2);
            HET_vPinWrite(HET_MUX_A0, HIGH);
            HET_vPinWrite(HET_MUX_A1, HIGH);
            HET_vPinWrite(HET_MUX_A2, LOW);
            MONITOR_ADC_u8MultiplexerState = 3;
            break;
        case 3:
            tempADCValue.u16ADCValueVoltageAntenneOn = ADC_U16GETADCVALUE(ADC_DIAG_MUX_1);
            tempADCValue.u16ADCValueCurrentAntenneOn = ADC_U16GETADCVALUE(ADC_DIAG_MUX_2);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueVoltageAntenneOn = %d", tempADCValue.u16ADCValueVoltageAntenneOn);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueCurrentAntenneOn = %d", tempADCValue.u16ADCValueCurrentAntenneOn);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueVoltageAntenneOn, enUAntenneOn);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueCurrentAntenneOn, enIAntenneOn);
            HET_vPinWrite(HET_MUX_A0, LOW);
            HET_vPinWrite(HET_MUX_A1, LOW);
            HET_vPinWrite(HET_MUX_A2, HIGH);
            MONITOR_ADC_u8MultiplexerState = 4;
            break;
        case 4:
            tempADCValue.u16ADCValueVoltageFm1 = ADC_U16GETADCVALUE(ADC_DIAG_MUX_1);
            tempADCValue.u16ADCValueCurrentFm1 = ADC_U16GETADCVALUE(ADC_DIAG_MUX_2);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueVoltageFm1 = %d", tempADCValue.u16ADCValueVoltageFm1);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueCurrentFm1 = %d", tempADCValue.u16ADCValueCurrentFm1);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueVoltageFm1, enUFm1);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueCurrentFm1, enIFm1);
            HET_vPinWrite(HET_MUX_A0, HIGH);
            HET_vPinWrite(HET_MUX_A1, LOW);
            HET_vPinWrite(HET_MUX_A2, HIGH);
            MONITOR_ADC_u8MultiplexerState = 5;
            break;
        case 5:
            tempADCValue.u16ADCValueVoltageFm2 = ADC_U16GETADCVALUE(ADC_DIAG_MUX_1);
            tempADCValue.u16ADCValueCurrentFm2 = ADC_U16GETADCVALUE(ADC_DIAG_MUX_2);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueVoltageFm2 = %d", tempADCValue.u16ADCValueVoltageFm2);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueCurrentFm2 = %d", tempADCValue.u16ADCValueCurrentFm2);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueVoltageFm2, enUFm2);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueCurrentFm2, enIFm2);
            HET_vPinWrite(HET_MUX_A0, LOW);
            HET_vPinWrite(HET_MUX_A1, HIGH);
            HET_vPinWrite(HET_MUX_A2, HIGH);
            MONITOR_ADC_u8MultiplexerState = 6;
            break;
        case 6:
            tempADCValue.u16ADCValueVoltageDabSdars = ADC_U16GETADCVALUE(ADC_DIAG_MUX_1);
            tempADCValue.u16ADCValueCurrentDabSdars = ADC_U16GETADCVALUE(ADC_DIAG_MUX_2);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueVoltageDabSdars = %d", tempADCValue.u16ADCValueVoltageDabSdars);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueCurrentDabSdars = %d", tempADCValue.u16ADCValueCurrentDabSdars);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueVoltageDabSdars, enUDabSdars);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueCurrentDabSdars, enIDabSdars);
            HET_vPinWrite(HET_MUX_A0, HIGH);
            HET_vPinWrite(HET_MUX_A1, HIGH);
            HET_vPinWrite(HET_MUX_A2, HIGH);
            MONITOR_ADC_u8MultiplexerState = 7;
            break;
        case 7:
            tempADCValue.u16ADCValueVoltageCamera = ADC_U16GETADCVALUE(ADC_DIAG_MUX_1);
            tempADCValue.u16ADCValueCurrentCamera = ADC_U16GETADCVALUE(ADC_DIAG_MUX_2);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueVoltageCamera = %d", tempADCValue.u16ADCValueVoltageCamera);
	        DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueCurrentCamera = %d", tempADCValue.u16ADCValueCurrentCamera);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueVoltageCamera, enUCam);
            (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueCurrentCamera, enICam);
            HET_vPinWrite(HET_MUX_A0, LOW);
            HET_vPinWrite(HET_MUX_A1, LOW);
            HET_vPinWrite(HET_MUX_A2, LOW);
            MONITOR_ADC_u8MultiplexerState = 0;
            break;
        default:
            ;
            break;
    }

    tempADCValue.u16ADCValueVoltageGps = ADC_U16GETADCVALUE(ADC_DIAG_U_GPS);
    tempADCValue.u16ADCValueCurrentGps = ADC_U16GETADCVALUE(ADC_DIAG_I_GPS);
    tempADCValue.u16ADCValueVoltageUsbHost1Bus = ADC_U16GETADCVALUE(ADC_DIAG_USB_HOST1_VBUS);
    tempADCValue.u16ADCValueVoltageUsbHost2Bus = ADC_U16GETADCVALUE(ADC_DIAG_USB_HOST2_VBUS);
    tempADCValue.u16ADCValueCurrentUsbHost1Bus = ADC_U16GETADCVALUE(ADC_DIAG_USB_HOST1_CUR);
    tempADCValue.u16ADCValueCurrentUsbHost2Bus = ADC_U16GETADCVALUE(ADC_DIAG_USB_HOST1_CUR);
    tempADCValue.u16ADCValue9V = ADC_U16GETADCVALUE(ADC_DIAG_9V);
    tempADCValue.u16ADCValueVoltageMikrophone = ADC_U16GETADCVALUE(ADC_DIAG_U_MIC);
    tempADCValue.u16ADCValueMikrophonePlus = ADC_U16GETADCVALUE(ADC_DIAG_MIC_PLUS);
    tempADCValue.u16ADCValueAudioLeftPlus = ADC_U16GETADCVALUE(ADC_DIAG_AUDIO_LEFT_PLUS);
    tempADCValue.u16ADCValueAudioLeftMinus = ADC_U16GETADCVALUE(ADC_DIAG_AUDIO_LEFT_MINUS);
    tempADCValue.u16ADCValueAudioRightPlus = ADC_U16GETADCVALUE(ADC_DIAG_AUDIO_RIGHT_PLUS);
    tempADCValue.u16ADCValueAudioRightMinus = ADC_U16GETADCVALUE(ADC_DIAG_AUDIO_RIGHT_MINUS);
	tempADCValue.u16ADCValueUBatt = ADC_U16GETADCVALUE(ADC_UBATT);

	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueVoltageGps = %d", tempADCValue.u16ADCValueVoltageGps);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueCurrentGps = %d", tempADCValue.u16ADCValueCurrentGps);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueVoltageUsbHost1Bus = %d", tempADCValue.u16ADCValueVoltageUsbHost1Bus);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueVoltageUsbHost2Bus = %d", tempADCValue.u16ADCValueVoltageUsbHost2Bus);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueCurrentUsbHost1Bus = %d", tempADCValue.u16ADCValueCurrentUsbHost1Bus);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueCurrentUsbHost2Bus = %d", tempADCValue.u16ADCValueCurrentUsbHost2Bus);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValue9V = %d", tempADCValue.u16ADCValue9V);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueVoltageMikrophone = %d",tempADCValue.u16ADCValueVoltageMikrophone);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueMikrophonePlus = %d", tempADCValue.u16ADCValueMikrophonePlus);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueAudioLeftPlus = %d", tempADCValue.u16ADCValueAudioLeftPlus);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueAudioLeftMinus = %d", tempADCValue.u16ADCValueAudioLeftMinus);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueAudioRightPlus = %d", tempADCValue.u16ADCValueAudioRightMinus);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueAudioRightMinus = %d", tempADCValue.u16ADCValueAudioRightMinus);
	DEBUG_VALUE1(MONITOR_ADC_SWI_DBG, MOD_MONITOR_ADC, "ADCValueUBatt = %d", tempADCValue.u16ADCValueUBatt);

    (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueVoltageGps, enUGps);
    (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueCurrentGps, enIGps);
    (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueVoltageUsbHost1Bus, enUsbHost1VBus);
    (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueVoltageUsbHost2Bus, enUsbHost2VBus);
    (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueCurrentUsbHost1Bus, enUsbHost1Cur);
    (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueCurrentUsbHost2Bus, enUsbHost2Cur);
    (void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValue9V, en9V);
	(void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueVoltageMikrophone, enUMicrophone);
	(void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueMikrophonePlus, enMicrophonePlus);

	(void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueUBatt, enUBatt);


	if ( BT_TRUE == APP_DTC_bGetAudioAllowed())
	{
		(void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueAudioLeftPlus, enAudioLeftPlus);
		(void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueAudioLeftMinus, enAudioLeftMinus);
		(void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueAudioRightMinus, enAudioRightPlus);
		(void)_MONITOR_ADC_u16MovingAverageADCValue(tempADCValue.u16ADCValueAudioRightMinus, enAudioRightMinus);
	}
	else
	{
		adcMovingAverageValue.u16ADCValueAudioLeftPlus = tempADCValue.u16ADCValueAudioLeftPlus;
		adcMovingAverageValue.u16ADCValueAudioLeftMinus = tempADCValue.u16ADCValueAudioLeftMinus;
		adcMovingAverageValue.u16ADCValueAudioRightPlus = tempADCValue.u16ADCValueAudioRightMinus;
		adcMovingAverageValue.u16ADCValueAudioRightMinus = tempADCValue.u16ADCValueAudioRightMinus;
	}
	return SUCCESS;
}

/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_sfInit                                           */
/** 
 \brief      Return Radio Mute ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     SuccessFailType
 */
/*----------------------------------------------------------------------------*/
SuccessFailType MONITOR_ADC_sfInit(void)
{
    (void)memset(&adcMovingAverageValue, 0x00, sizeof(MONITOR_ADC_ValueType));
    MONITOR_ADC_u8MultiplexerState = 0;

    HET_vPinWrite(HET_MUX_A0, LOW);
    HET_vPinWrite(HET_MUX_A1, LOW);
    HET_vPinWrite(HET_MUX_A2, LOW);
	return SUCCESS;
}


/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueAmplifierWakeUp             */
/** 
 \brief      Return AmplifierWakeUp ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueAmplifierWakeUp(void)
{
	return adcMovingAverageValue.u16ADCValueAmplifierWakeUp;
}

/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueDisplayPwm             */
/** 
 \brief      Return DisplayPwm ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueDisplayPwm(void)
{
	return adcMovingAverageValue.u16ADCValueDisplayPwm;
}

/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueDisplayWakeUp             */
/** 
 \brief      Return DisplayWakeUp ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueDisplayWakeUp(void)
{
    return adcMovingAverageValue.u16ADCValueDisplayWakeUp;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueVoltageAntenneOn             */
/** 
 \brief      Return VoltageAntenneOn ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueVoltageAntenneOn(void)
{
    return adcMovingAverageValue.u16ADCValueVoltageAntenneOn;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueCurrentAntenneOn             */
/** 
 \brief      Return CurrentAntenneO ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueCurrentAntenneOn(void)
{
    return adcMovingAverageValue.u16ADCValueCurrentAntenneOn;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueVoltageFm1             */
/** 
 \brief      Return VoltageFm1 ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueVoltageFm1(void)
{
    return adcMovingAverageValue.u16ADCValueVoltageFm1;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueCurrentFm1             */
/** 
 \brief      Return CurrentFm1 ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueCurrentFm1(void)
{
    return adcMovingAverageValue.u16ADCValueCurrentFm1;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueVoltageFm2             */
/** 
 \brief      Return VoltageFm2 ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueVoltageFm2(void)
{
    return adcMovingAverageValue.u16ADCValueVoltageFm2;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueCurrentFm2             */
/** 
 \brief      Return CurrentFm2 ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueCurrentFm2(void)
{
    return adcMovingAverageValue.u16ADCValueCurrentFm2;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueVoltageDabSdars             */
/** 
 \brief      Return VoltageDabSdars ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueVoltageDabSdars(void)
{
    return adcMovingAverageValue.u16ADCValueVoltageDabSdars;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueCurrentDabSdars             */
/** 
 \brief      Return CurrentDabSdars ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueCurrentDabSdars(void)
{
    return adcMovingAverageValue.u16ADCValueCurrentDabSdars;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueVoltageCamera             */
/** 
 \brief      Return VoltageCamera ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueVoltageCamera(void)
{
    return adcMovingAverageValue.u16ADCValueVoltageCamera;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueCurrentCamera             */
/** 
 \brief      Return CurrentCamera ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueCurrentCamera(void)
{
    return adcMovingAverageValue.u16ADCValueCurrentCamera;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValue5VCan             */
/** 
 \brief      Return 5VCan ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValue5VCan(void)
{
    return adcMovingAverageValue.u16ADCValue5VCan;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValue5V2             */
/** 
 \brief      Return 5V2 ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValue5V2(void)
{
    return adcMovingAverageValue.u16ADCValue5V2;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueVoltageGps             */
/** 
 \brief      Return VoltageGps ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueVoltageGps(void)
{
    return adcMovingAverageValue.u16ADCValueVoltageGps;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueCurrentGps             */
/** 
 \brief      Return CurrentGps ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueCurrentGps(void)
{
    return adcMovingAverageValue.u16ADCValueCurrentGps;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueVoltageUsbHost1Bus             */
/** 
 \brief      Return VoltageUsbHost1Bus ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueVoltageUsbHost1Bus(void)
{
    return adcMovingAverageValue.u16ADCValueVoltageUsbHost1Bus;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueVoltageUsbHost2Bus             */
/** 
 \brief      Return VoltageUsbHost2Bus ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueVoltageUsbHost2Bus(void)
{
    return adcMovingAverageValue.u16ADCValueVoltageUsbHost2Bus;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueCurrentUsbHost1Bus             */
/** 
 \brief      Return CurrentUsbHost1Bus ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueCurrentUsbHost1Bus(void)
{
    return adcMovingAverageValue.u16ADCValueCurrentUsbHost1Bus;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueCurrentUsbHost2Bus             */
/** 
 \brief      Return CurrentUsbHost2Bus ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueCurrentUsbHost2Bus(void)
{
    return adcMovingAverageValue.u16ADCValueCurrentUsbHost2Bus;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValue9V             */
/** 
 \brief      Return 9V ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValue9V(void)
{
    return adcMovingAverageValue.u16ADCValue9V;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueVoltageMikrophone             */
/** 
 \brief      Return VoltageMikrophone ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueVoltageMikrophone(void)
{
    return adcMovingAverageValue.u16ADCValueVoltageMikrophone;
}
/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueMikrophonePlus             */
/** 
 \brief      Return MikrophonePlus ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueMikrophonePlus(void)
{
    return adcMovingAverageValue.u16ADCValueMikrophonePlus;
}

/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u8GetMikrophoneCurrentDrain                                         		  */
/** 
 \brief      Return Mikrophone current drain to APP Diag
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint8Type
 */
/*----------------------------------------------------------------------------*/
Uint8Type MONITOR_ADC_u8GetMikrophoneCurrentDrain(void)
{
  //Uint16Type u8MicrophoneCurrentValue = ((_MONITOR_ADC_u16MovingAverageADCValueU7V5 * 339 ) - (620 * _MONITOR_ADC_u16MovingAverageADCValueMikrophonePlus)) >> 10; 
  //if ( u8MicrophoneCurrentValue >  255 )
  //{
  //    u8MicrophoneCurrentValue = 0;
  //}
  //return ((Uint8Type)u8MicrophoneCurrentValue);
    return 0x00;
}

/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueAudioLeftPlus                                         		  */
/** 
 \brief      Return Audio Left Plus ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueAudioLeftPlus(void)
{
	return adcMovingAverageValue.u16ADCValueAudioLeftPlus;
}

/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueAudioLeftMinus */
/** 
 \brief      Return Audio Left Minus ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueAudioLeftMinus(void)
{
	return adcMovingAverageValue.u16ADCValueAudioLeftMinus;
}

/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueAudioRightPlus                                         		  */
/** 
 \brief      Return Audio Right Plus ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueAudioRightPlus(void)
{
	return adcMovingAverageValue.u16ADCValueAudioRightPlus;
}

/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueAudioRightMinus                                         		  */
/** 
 \brief      Return Audio Right Minus ADC value to the application
 
 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueAudioRightMinus(void)
{
	return adcMovingAverageValue.u16ADCValueAudioRightMinus;
}


/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueTemperature*/
/**
 \brief      Return Temperature value to the application

 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueTemperature(void)
{
	return adcMovingAverageValue.u16ADCValueTemperature;
}

/*----------------------------------------------------------------------------*/
/* Function    : MONITOR_ADC_u16GetMovingAverageADCValueUBatt*/
/**
 \brief      Return UBatt value to the application

 \brief      Description:
 Read ADC Values, and returns to the Application..

 \return     Uint16Type
 */
/*----------------------------------------------------------------------------*/
Uint16Type MONITOR_ADC_u16GetMovingAverageADCValueUBatt(void)
{
	return adcMovingAverageValue.u16ADCValueUBatt;
}

/* End Of File MONITOR_ADC_C1.c */
