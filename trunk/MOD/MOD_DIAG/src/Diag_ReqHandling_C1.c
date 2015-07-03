/******************************************************************************/
/*****************  Copyright (c) 2011 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     Diag_Service_22.c
*-----------------------------------------------------------------------------
* Module Name:    DIAG
*-----------------------------------------------------------------------------
* Description:    Handle Diagnose Service 22
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

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*---------------------------------------------------------------------------- */

#include "Common.h"
#include "Version.h"
#include "Startup.h"
#include "desc.h"
#include "ccl_inc.h"
#include "Diag_Service_22.h"
#include "Diag_Service_2E.h"
#include "APP_COMMON_Utils.h"
#include "APP_DESC.h"
#include "Diag_ReqHandling.h"
#include "EEPROM.h"
#include "EEPROM_LAYOUT_CFG.h"
#include "TRACE.h"
#include "Diag_ReqHandling_C1.id"
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/
#pragma DATA_SECTION (Set_FlashRequest_Paddern, ".REQUEST")
/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/
/*variable for dynamic Baudrate handling*/
/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the type
*/

DiagnoseContextType gDiagnoseContext;
Uint32Type Set_FlashRequest_Paddern;
Uint32Type systemTime;
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

/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/

/*  FUNCTION Uint8Type ubCheckKeyValid
 **************************************************************************
 *  PURPOSE:        vergleich den vom Tester gesendeten Key mit dem selbst berechneten Key
 **************************************************************************
 *  PARAMETERS:     KeyInput:    Key vom Tester
 *                  SeedBuf:     Seed zum Berechnen vom Key
 *                  LenOfKey:    Länge vom Key in Bytes (Default = 4)
 **************************************************************************
 *  RETURN VALUE:   Key valid or not valid
 *************************************************************************/


void DIAG_vGenerateSecurityAccessKey(void)
{
    /* Security Access String */
    /* 680684A76D90EE824A05871BF91ADF494C for more informations see LH_FLASH_SA2_V1_0_3.pdf*/
    #define SA2_DATA_1      0xA76D90EEul
    #define SA2_DATA_2      0x1BF91ADFul

    Uint32Type SA2_Seed, SeedHelp = 0;
    Uint32Type SA2_Carry = 0;
    Uint8Type SA2_Iterations = 6;

    SA2_Seed =  (gDiagnoseContext.au8Seed[0] << 24) |
                (gDiagnoseContext.au8Seed[1] << 16) |
                (gDiagnoseContext.au8Seed[2] <<  8) |
                (gDiagnoseContext.au8Seed[3] <<  0);
    SA2_Carry  = SA2_Seed;

    while(SA2_Iterations >= 1u)
    {
       SA2_Seed -= SA2_DATA_1;
       SA2_Carry = 0u;
       SA2_Carry = (SA2_Seed & 0x00000001ul);
       SeedHelp = SA2_Carry;
       SA2_Seed >>= 1u;
       SeedHelp <<= 31u;
       SA2_Seed |= SeedHelp;
       SA2_Iterations--;
       if(SA2_Carry == 1u)
       {
          SA2_Seed ^=SA2_DATA_2;
       }
    }

    gDiagnoseContext.au8Key[0] = (Uint8Type)(SA2_Seed >> 24);
    gDiagnoseContext.au8Key[1] = (Uint8Type)(SA2_Seed >> 16);
    gDiagnoseContext.au8Key[2] = (Uint8Type)(SA2_Seed >>  8);
    gDiagnoseContext.au8Key[3] = (Uint8Type)SA2_Seed;
    DEBUG_VALUE4(DIAG_SWI_TRC, MOD_DIAG,"DIAG_vGenerateSecurityAccessKey 0x%02x 0x%02x 0x%02x 0x%02x",
                                             gDiagnoseContext.au8Key[0],
                                             gDiagnoseContext.au8Key[1],
                                             gDiagnoseContext.au8Key[2],
                                             gDiagnoseContext.au8Key[3]);
}



void DiagInit(void)
{
    (void)memset(&gDiagnoseContext, 0, sizeof(DiagnoseContextType));

    systemTime = osGetSystemCounter() + 1500;

    gDiagnoseContext.activeDiagnosticSession = kDescStateSessionDefault;
    /* first get security status from application */
    (void)EEPROM_enGetSingleByteFromRamMirror(&gDiagnoseContext.securityState, EEPROM_LAYOUT_ENUM_SecurityAccessState);

    gDiagnoseContext.securityState &= ~MASK_SEED_ALREADY_SEND;   // dieser Zustand wird nicht ins EEPROM gespeichert, bzw. beim Zurücklesen nach Systemstart ausmaskiert
    if((gDiagnoseContext.securityState & MASK_SEC_STATUS_LOCKED) == MASK_SEC_STATUS_LOCKED)
    {
        /* Setting Security Status to State LOCKED */
        gDiagnoseContext.timerSecurityAccess = SECURITY_BLOCKING_TIME;
        gDiagnoseContext.securityState |= MASK_SEC_STATUS_LOCKED; // dreimal falscher Key => für 10min sperren !!!
        DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG,"Security Status is locked");
    }
    gDiagnoseContext.securityState &= MASK_HIDE_SEED_COUNTER;
    // ubSecState ins EEPROM speichern
    (void)EEPROM_sfRamWriteOnly(&gDiagnoseContext.securityState, EEPROM_LAYOUT_ENUM_SecurityAccessState);
    DEBUG_VALUE1(DIAG_SWI_TRC, MOD_DIAG, "ubSecState 0x%02X",  gDiagnoseContext.securityState);
}


/*----------------------------------------------------------------------------*/
/* Function    : FunctionName                                                 */
/**
    \brief      Short description

    \brief      Description:
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    \return     none
   */
/*----------------------------------------------------------------------------*/
void Diag_vTask(void)
{
	// Timer Handling Security access
	if (gDiagnoseContext.timerSecurityAccess > 0)
	{
		gDiagnoseContext.timerSecurityAccess--;
		if (gDiagnoseContext.timerSecurityAccess == 0)
		{
            // Timer läuft gerade ab
			DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "Security Timer finished. So unlock");
			gDiagnoseContext.securityState &= MASK_SEC_STATUS_UNLOCKED; // die Key Sperre wieder aufheben und im EEPROM sichern
			// save security state at the E2P
			(void)EEPROM_sfRamWriteOnly(&gDiagnoseContext.securityState, EEPROM_LAYOUT_ENUM_SecurityAccessState);
		}
	}
    if ( FLASH_REQUEST_PADDERN_BOOT == Set_FlashRequest_Paddern)
    {
        if(systemTime < osGetSystemCounter())
        {
            Union16Type programCounter;
            Uint8Type date[3] = {0, 0, 0};
            programCounter.u16 = 0;
            DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "Flash update done: Write Softwareversion & increment programming count");
            (void)EEPROM_enGetByteSequenceFromRamMirror(programCounter.u8,
                                                        PAG_DB_EE_ADDRESS_AswSWCntProgrAttempts_LEN,
                                                        EEPROM_LAYOUT_ENUM_AswSWCntProgrAttempts);
            programCounter.u16 += 1;
            (void)EEPROM_sfRamWriteOnly(programCounter.u8, EEPROM_LAYOUT_ENUM_AswSWCntProgrAttempts);
            (void)EEPROM_sfRamWriteOnly((Uint8Type *)SoftwareVersion, EEPROM_LAYOUT_ENUM_AppSoftwareVersionNbr);
            if(TRUE == APP_CAN_bIsDiagnose1MessageReceived())
            {
                date[0] = IlGetRxUH_Tag();
                date[1] = IlGetRxUH_Monat();
                date[2] = IlGetRxUH_Jahr();
            }
            else
            {
                DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "Flash update: No vaild Diagnose_1 message received");
                date[0] = 0x01;
                date[1] = 0x01;
            }
            (void)EEPROM_sfRamWriteOnly(date, EEPROM_LAYOUT_ENUM_ProgDate);
            Set_FlashRequest_Paddern = FLASH_REQUEST_PATTERN_RESET;
        }
    }
    switch ( gDiagnoseContext.resetControl )
    {
        case UDS_11_HardReset:
            gDiagnoseContext.resetControl = 0;
            c_int00();
            break;
        case UDS_11_KeyOffOnReset:
            // Check E2P data, if nothing to do reset the TMS
            gDiagnoseContext.resetControl = 0;
            c_int00();
            break;
        default:
            // do nothing
            break;
    }
}


void DIAG_ReqHandler(void)
{
    if (DIAG_REQ_READ_BY_IDENTIFIER == gDiagMsgContext.reqType)
    {
        DEBUG_STATE1(DIAG_SWI_TRC, MOD_DIAG, "DIAG_ReqHandler: state = $DiagRequestStateType$ (%d)", gDiagnoseContext.DiagnoseRequestState);
        switch(gDiagnoseContext.DiagnoseRequestState)
        {
            case DIAG_REQ_SEARCHING_DID_STATE: // entry point
                gDiagnoseContext.DiagnoseRequestState = DIAG_REQ_WAITING_UNTIL_FUNC_IS_FINISHED_STATE;
                (void)APP_COMMON_UTILS_stSetOsekRelAlarm(CTA_HOST_HANDLE_DIAG_REQ, MSEC(5), 0);
                cs_ReadDataIdItem[gDiagMsgContext.data[gDiagMsgContext.counter].idx].Address(gDiagMsgContext.data[gDiagMsgContext.counter].data);
                gDiagMsgContext.counter += 1;
                break;

            case DIAG_REQ_WAITING_UNTIL_FUNC_IS_FINISHED_STATE:   // waiting state untile function is finished
                break;

            case DIAG_REQ_NEXT_DID_STATE:   // check if next id is available
                if (gDiagMsgContext.elements != gDiagMsgContext.counter)/*check if more than one job available*/
                {
                    gDiagnoseContext.DiagnoseRequestState = DIAG_REQ_SEARCHING_DID_STATE;
                    (void)APP_COMMON_UTILS_stSetOsekRelAlarm(CTA_HOST_HANDLE_DIAG_REQ, MSEC(5), 0);
                }
                else
                {
                    gDiagnoseContext.DiagnoseRequestState = DIAG_REQ_FINISHED_STATE;
                    (void)APP_COMMON_UTILS_stSetOsekRelAlarm(CTA_HOST_HANDLE_DIAG_REQ, MSEC(5), 0);
                }
                break;

            case DIAG_REQ_FINISHED_STATE:  // send positive response
                gDiagnoseContext.DiagnoseRequestState = DIAG_REQ_SEARCHING_DID_STATE;
                DescProcessingDone();
                break;

            default:
                DEBUG_TEXT(DIAG_SWI_ERR, MOD_DIAG, "DIAG_ReqHandler: invalid state");
                gDiagnoseContext.DiagnoseRequestState = DIAG_REQ_SEARCHING_DID_STATE;
                DescProcessingDone();
                break;
        }
    }
    else if (DIAG_REQ_WRITE_BY_IDENTIFIER == gDiagMsgContext.reqType)
    {
	   cs_WriteDataIdItem[gDiagMsgContext.data[0].idx].Address(gDiagMsgContext.data[0].data, gDiagMsgContext.data[0].len);
    }
    else
    {
        //do nothing 
    }
}



BooleanType DIAG_bCodingParameterCheck(CodingBitMaskType *codingMask)
{
    BooleanType retVal = BT_TRUE;
    if(codingMask->KI_BC_Rolle_Datafield_1 > 0x11)
    {
        retVal = BT_FALSE;
    }
    if(codingMask->KI_BC_Rolle_Datafield_2 > 0x11)
    {
        retVal = BT_FALSE;
    }
    if(codingMask->KI_BC_Rolle_Datafield_3 > 0x11)
    {
        retVal = BT_FALSE;
    }
    if(codingMask->KI_BC_Rolle_Datafield_4 > 0x11)
    {
        retVal = BT_FALSE;
    }
    if(codingMask->Joker_Taste > 0x04)
    {
        retVal = BT_FALSE;
    }
    if(codingMask->KBI_Einheit_Datum > 0x02)
    {
        retVal = BT_FALSE;
    }
    if(codingMask->KBI_Einheit_Verbrauch_elektr > 0x04)
    {
        retVal = BT_FALSE;
    }
    if(codingMask->KBI_Einheit_Sprachen > 0x03)
    {
        retVal = BT_FALSE;
    }
    if(codingMask->Memory_Nachleuchtdauer_Innenlicht > 30)
    {
        retVal = BT_FALSE;
    }
    if(codingMask->Memory_Nachleuchtdauer_Coming_Home > 24)
    {
        retVal = BT_FALSE;
    }
    if(codingMask->Memory_Wiederverriegelung_ohne_Tueroeffnung > 18)
    {
        retVal = BT_FALSE;
    }
    return(retVal);
}


void DIAG_vWriteCodingParameterInPersistentData(CodingBitMaskType *codingMask)
{
    E2pRamPersistentData persistentE2pRamData;

    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DIAG_vWriteCodingParameterInPersistentData: write coding data in persistent data");
    persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld1 = codingMask->KI_BC_Rolle_Datafield_1;
    persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld2 = codingMask->KI_BC_Rolle_Datafield_2;
    persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld3 = codingMask->KI_BC_Rolle_Datafield_3;
    persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld4 = codingMask->KI_BC_Rolle_Datafield_4;
    persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Konfig = codingMask->KI_RC_Rolle_Konfig;
    persistentE2pRamData.MFL_Adr_Joker_Taste = codingMask->Joker_Taste;

    persistentE2pRamData.Einheit_KBI_Einheit_Datum = codingMask->KBI_Einheit_Datum;
    persistentE2pRamData.Einheit_KBI_Einheit_Druck = codingMask->KBI_Einheit_Druck;
    persistentE2pRamData.Einheit_KBI_Einheit_Streckenanz = codingMask->KBI_Einheit_Streckenanzeige;
    persistentE2pRamData.Einheit_KBI_Einheit_Temp = codingMask->KBI_Einheit_Temp;
    persistentE2pRamData.Einheit_KBI_Einheit_Uhrzeit = codingMask->KBI_Einheit_Uhrzeit;
    persistentE2pRamData.Einheit_KBI_Einheit_Verbrauch = codingMask->KBI_Einheit_Verbrauch;
    persistentE2pRamData.Einheit_KBI_Einheit_Volumen = codingMask->KBI_Einheit_Volumen;
    persistentE2pRamData.Einheit_KBI_Einheit_Verbrauch_elektr = codingMask->KBI_Einheit_Verbrauch_elektr;
    persistentE2pRamData.Einheit_KBI_Einheit_Sprache = codingMask->KBI_Einheit_Sprachen;
    /* Hint: Memory_Links_Rechs_Verkehr not supported in dbc */
    persistentE2pRamData.Memory_KBI_FULL_AFS_Tourist = codingMask->Memory_KBI_FULL_AFS_Tourist;
    persistentE2pRamData.Memory_KBI_RS_d_akt = codingMask->Memory_Regensensor_aktiv;
    persistentE2pRamData.Memory_KBI_Nachleucht_IL = codingMask->Memory_Nachleuchtdauer_Innenlicht;
    persistentE2pRamData.Memory_KBI_Nachleucht = codingMask->Memory_Nachleuchtdauer_Coming_Home;
    persistentE2pRamData.Memory_KBI_TFL_akt = codingMask->Memory_Tagfahrlicht_aktiv;
    persistentE2pRamData.Memory_KBI_WV_Entr = codingMask->Memory_Wiederverriegelung_ohne_Tueroeffnung;
    persistentE2pRamData.Memory_KBI_WV_Entr_Kof = codingMask->Memory_KBI_VW_Entr_Kof;
    persistentE2pRamData.Memory_KBI_Tuerentr_T = codingMask->Memory_KBI_Tuerentr_T;
    persistentE2pRamData.Memory_KBI_Carjack = codingMask->Memory_KBI_Carjack;
    persistentE2pRamData.Memory_KBI_Innenlicht_per_Tuerkontakt = codingMask->Memory_Tuerkontaktfunktion_ein;

    (void)EEPROM_sfRamWriteOnly((Uint8Type *)&persistentE2pRamData, EEPROM_LAYOUT_ENUM_PersistentECUData);
}
/* End Of File APP_CAN_C1.c */
