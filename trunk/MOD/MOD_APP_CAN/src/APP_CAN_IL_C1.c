/******************************************************************************/
/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/
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
#include "ccl_inc.h"

#include "EEPROM.h"
#include "EEPROM_LAYOUT_CFG.h"
#include "APP_CAN_IL.h"
#include "APP_CAN_IL_C1.id"
#include "TRACE.h"


/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/
extern AppCanContextType gAppCanContext;
static E2pRamPersistentData persistentE2pRamData;
static BooleanType firstMessageAtStartup = BT_TRUE;
/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/

static void APP_CAN_vSetCanDefaultValues(void);
static void APP_CAN_IL_vWriteCodingParameterToCan(void);



void APP_CAN_IL_CheckSignalReception(void)
{
    APP_CAN_IL_CheckSignalSelfDiagnosisAltBitReception();
    APP_CAN_IL_CheckSignalReception_DIAGNOSIS();
    APP_CAN_IL_CheckSignalReception_CSHDL();
    APP_CAN_IL_CheckSignalReception_INFO();
    APP_CAN_IL_CheckSignalReception_Klima();
    APP_CAN_IL_CheckSignalReception_Navigation();
}


void ApplZAS_Kl_15RxSigTimeout(void)
{
    CclRel_KL_15();
}


void APP_CAN_IL_HandleEvents(EventMaskType event)
{
    if (event & evHostTask_INFO_Response)
    {
        APP_CAN_IL_Send_INFO_Signals();

        if(E_COM_NOMSG == GetMessageStatus(msgInfo_Responses))
        {
            // clear only if all msg received
           (void)ClearEvent(evHostTask_INFO_Response);
        }
    }
    if(event & evHostTaskSendingCodingData)
    {
        DEBUG_TEXT(APP_CAN_SWI_TRC, MOD_APP_CAN, "Sending coding changes on CAN bus");
        APP_CAN_IL_vWriteCodingParameterToCan();
        (void)ClearEvent(evHostTaskSendingCodingData);
    }
}

static void APP_CAN_IL_vWriteCodingParameterToCan(void)
{
    (void)EEPROM_enGetByteSequenceFromRamMirror((Uint8Type *)&persistentE2pRamData,
                                                PAG_DB_EE_ADDRESS_PersistentECUData_LEN,
                                                EEPROM_LAYOUT_ENUM_PersistentECUData);

    IlPutTxAdr_KI_BC_Rolle_Konfig(persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Konfig);
    IlPutTxAdr_Joker_Taste(persistentE2pRamData.MFL_Adr_Joker_Taste);
    IlPutTxKBI_Einheit_Datum(persistentE2pRamData.Einheit_KBI_Einheit_Datum);
    IlPutTxKBI_Einheit_Druck(persistentE2pRamData.Einheit_KBI_Einheit_Druck);
    IlPutTxKBI_Einheit_Streckenanz(persistentE2pRamData.Einheit_KBI_Einheit_Streckenanz);
    IlPutTxKBI_Einheit_Temp(persistentE2pRamData.Einheit_KBI_Einheit_Temp);
    IlPutTxKBI_Einheit_Uhrzeit(persistentE2pRamData.Einheit_KBI_Einheit_Uhrzeit);
    IlPutTxKBI_Einheit_Verbrauch(persistentE2pRamData.Einheit_KBI_Einheit_Verbrauch);
    IlPutTxKBI_Einheit_Volumen(persistentE2pRamData.Einheit_KBI_Einheit_Volumen);
    IlPutTxKBI_Einheit_Verbrauch_elektr(persistentE2pRamData.Einheit_KBI_Einheit_Verbrauch_elektr);
    IlPutTxKBI_Einheit_Sprache(persistentE2pRamData.Einheit_KBI_Einheit_Sprache);
    IlPutTxKBI_FULL_AFS_Tourist(persistentE2pRamData.Memory_KBI_FULL_AFS_Tourist);
    IlPutTxKBI_RS_d_akt(persistentE2pRamData.Memory_KBI_RS_d_akt);
    IlPutTxKBI_Nachleucht_IL(persistentE2pRamData.Memory_KBI_Nachleucht_IL);
    IlPutTxKBI_Nachleucht(persistentE2pRamData.Memory_KBI_Nachleucht);
    IlPutTxKBI_TFL_akt(persistentE2pRamData.Memory_KBI_TFL_akt);
    IlPutTxKBI_WV_Entr(persistentE2pRamData.Memory_KBI_WV_Entr);
    IlPutTxKBI_WV_Entr_Kof(persistentE2pRamData.Memory_KBI_WV_Entr_Kof);
    IlPutTxKBI_Tuerentr_T(persistentE2pRamData.Memory_KBI_Tuerentr_T);
    IlPutTxKBI_Carjack(persistentE2pRamData.Memory_KBI_Carjack);
    IlPutTxKBI_Innenlicht_per_Tuerkontakt(persistentE2pRamData.Memory_KBI_Innenlicht_per_Tuerkontakt);
}

void APP_CAN_IL_Init(void)
{
    (void)EEPROM_enGetByteSequenceFromRamMirror((Uint8Type *)&persistentE2pRamData,
                                                PAG_DB_EE_ADDRESS_PersistentECUData_LEN,
                                                EEPROM_LAYOUT_ENUM_PersistentECUData);
    //APP_CAN_vSetCanDefaultValues();
    //(void)EEPROM_sfRamWriteOnly((Uint8Type *)&persistentE2pRamData, EEPROM_LAYOUT_ENUM_PersistentECUData );
    /* set default parameter for CAN-Signals */
    /* 0x0C0 ADR_01_PAG */
    IlPutTxAdr_Pos_En(1);
    IlPutTxAdr_Display_Status(1);
    IlPutTxAdr_Active_Character_Page(1);

    /* 0x0C2 ADR_02_PAG */
    IlPutTxAdr_KL58d(persistentE2pRamData.Kombi_Adr_KL58d);
    IlPutTxAdr_KI_Helligkeit(persistentE2pRamData.Kombi_Adr_KI_Helligkeit);
    IlPutTxAdr_Miko_Helligkeit(50);

    IlPutTxKBI_Einheit_Verbrauch(persistentE2pRamData.Einheit_KBI_Einheit_Verbrauch);
    IlPutTxKBI_Dimmung_OriLicht(persistentE2pRamData.Memory_KBI_Dimmung_OriLicht);
    IlPutTxKBI_Nachleucht_IL(persistentE2pRamData.Memory_KBI_Nachleucht_IL);
    IlPutTxKBI_Nachleucht(persistentE2pRamData.Memory_KBI_Nachleucht);
    IlPutTxKBI_WV_Entr(persistentE2pRamData.Memory_KBI_WV_Entr);
    IlPutTxKBI_PTC_Zuheizer(persistentE2pRamData.Memory_KBI_PTC_Zuheizer);
    IlPutTxAdr_KI_BC_Rolle_Konfig(persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Konfig);
    IlPutTxAdr_Joker_Taste(persistentE2pRamData.MFL_Adr_Joker_Taste);
    IlPutTxKBI_Einheit_Datum(persistentE2pRamData.Einheit_KBI_Einheit_Datum);
    IlPutTxKBI_Einheit_Druck(persistentE2pRamData.Einheit_KBI_Einheit_Druck);
    IlPutTxKBI_Einheit_Streckenanz(persistentE2pRamData.Einheit_KBI_Einheit_Streckenanz);
    IlPutTxKBI_Einheit_Temp(persistentE2pRamData.Einheit_KBI_Einheit_Temp);
    IlPutTxKBI_Einheit_Uhrzeit(persistentE2pRamData.Einheit_KBI_Einheit_Uhrzeit);
    IlPutTxKBI_Einheit_Volumen(persistentE2pRamData.Einheit_KBI_Einheit_Volumen);
    IlPutTxKBI_Einheit_Verbrauch_elektr(persistentE2pRamData.Einheit_KBI_Einheit_Verbrauch_elektr);
    IlPutTxKBI_Einheit_Sprache(persistentE2pRamData.Einheit_KBI_Einheit_Sprache);
    IlPutTxKBI_FULL_AFS_Tourist(persistentE2pRamData.Memory_KBI_FULL_AFS_Tourist);
    IlPutTxKBI_RS_d_akt(persistentE2pRamData.Memory_KBI_RS_d_akt);
    IlPutTxKBI_TFL_akt(persistentE2pRamData.Memory_KBI_TFL_akt);
    IlPutTxKBI_WV_Entr_Kof(persistentE2pRamData.Memory_KBI_WV_Entr_Kof);
    IlPutTxKBI_Tuerentr_T(persistentE2pRamData.Memory_KBI_Tuerentr_T);
    IlPutTxKBI_Carjack(persistentE2pRamData.Memory_KBI_Carjack);
    IlPutTxKBI_Innenlicht_per_Tuerkontakt(persistentE2pRamData.Memory_KBI_Innenlicht_per_Tuerkontakt);

    IlPutTxKBI_Klimastyles(persistentE2pRamData.Memory_KBI_Klimastyles);
    IlPutTxKBI_Aussenspiegel_absenken_auto(persistentE2pRamData.Memory_KBI_Aussenspiegel_absenken_auto);
    IlPutTxKBI_Aussenspiegel_einklapp_auto(persistentE2pRamData.Memory_KBI_Aussenspiegel_einklapp_auto);

}

vuint8 PreTransmitFunctionADR_01_PAG(CanTxInfoStruct ctis)
{
    vuint8 len;
    /* Tx structure */
    _c_ADR_01_PAG_RDS_msgType modifyData;
    TxDataPtr pData;
    /* don't modify the first message after startup */
    if (BT_TRUE != firstMessageAtStartup)
    {
        /*Get DLC length*/
        len = CanGetTxDlc(ctis.Handle);
        /* Pionter to Tx data */
        pData = CanGetTxDataPtr(ctis.Handle);
        /* length check */
        if (len != sizeof(_c_ADR_01_PAG_RDS_msgType))
        {
            return 1;
        }
        /* copy data into TX structure */
        memcpy((void *)&modifyData, pData, len);
        /* modify alive counter */
        modifyData.Adr_Alive_Cnt += 1;
        /* back copy to Tx buffer */
        memcpy(pData, (void *)&modifyData,len);
    }
    else
    {
        firstMessageAtStartup = BT_FALSE;
    }
    return 1;
}
vuint8 PreTransmitFunctionADR_02_PAG(CanTxInfoStruct ctis)
{
    vuint8 len;
    /* Tx structure */
    _c_ADR_02_PAG_RDS_msgType modifyData;
    TxDataPtr pData;
    /*Get DLC length*/
    len = CanGetTxDlc(ctis.Handle);
    /* Pionter to Tx data */
    pData = CanGetTxDataPtr(ctis.Handle);
    /* length check */
    if (len != sizeof(_c_ADR_01_PAG_RDS_msgType))
    {
        return 1;
    }
    /* copy data into TX structure */
    memcpy((void *)&modifyData, pData, len);
    /* modify alive counter */
    if (4 == modifyData.Adr_Konfig_Datenfeld)
    {
        modifyData.Adr_Konfig_Datenfeld = 0;
    }
    modifyData.Adr_Konfig_Datenfeld += 1;
    switch (modifyData.Adr_Konfig_Datenfeld)
    {
        case 1: /* Konfiguration_Datenfeld_1 */
            /* read E2P data but know use default values */
            modifyData.Adr_KI_BC_Rolle_Datenfeld = persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld1;
            break;
        case 2: /* Konfiguration_Datenfeld_1 */
            /* read E2P data but know use default values */
            modifyData.Adr_KI_BC_Rolle_Datenfeld = persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld2;
            break;
        case 3: /* Konfiguration_Datenfeld_1 */
            /* read E2P data but know use default values */
            modifyData.Adr_KI_BC_Rolle_Datenfeld = persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld3;
            break;
        case 4: /* Konfiguration_Datenfeld_1 */
            /* read E2P data but know use default values */
            modifyData.Adr_KI_BC_Rolle_Datenfeld = persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld4;
            break;
        default:
            break;
    }
    /* back copy to Tx buffer */
    memcpy(pData, (void *)&modifyData,len);
    return 1;
}

void APP_CAN_vSetCanDefaultValues(void)
{
    memset((void *)&persistentE2pRamData, 0x00, sizeof(E2pRamPersistentData));
    persistentE2pRamData.Kombi_Adr_Konfig_Datafeld1 = 1;
    persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld1 = 0;
    persistentE2pRamData.Kombi_Adr_Konfig_Datafeld2 = 2;
    persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld2 = 5;
    persistentE2pRamData.Kombi_Adr_Konfig_Datafeld3 = 3;
    persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld3 = 17;
    persistentE2pRamData.Kombi_Adr_Konfig_Datafeld4 = 4;
    persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Datenfeld4 = 9;
    persistentE2pRamData.Kombi_Adr_KI_BC_Rolle_Konfig = 0xFF;
    persistentE2pRamData.Kombi_Adr_KL58d = 50;
    persistentE2pRamData.Kombi_Adr_KI_Helligkeit = 50;
    persistentE2pRamData.Einheit_KBI_Einheit_Verbrauch = 2;
    persistentE2pRamData.Memory_KBI_Dimmung_OriLicht = 50;
    persistentE2pRamData.Memory_KBI_Nachleucht_IL = 10;
    persistentE2pRamData.Memory_KBI_Nachleucht = 20;
    persistentE2pRamData.Memory_KBI_WV_Entr = 30;
    persistentE2pRamData.Memory_KBI_WV_Entr_Kof = 30;
    persistentE2pRamData.Memory_KBI_PTC_Zuheizer = 1;
    persistentE2pRamData.Memory_KBI_Klimastyles = 1;
}
/* End Of File APP_CAN_C1.c */
