/******************************************************************************/
/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/


#ifndef _APP_CAN_IL_INFO_H
#define _APP_CAN_IL_INFO_H


/* CAN Requests */
typedef enum
{
    ADR_01_PAG_LED_BUTTON_CHANGE 
}CAN_RESPONSES_INFO_ID;


typedef struct
{
    CAN_RESPONSES_INFO_ID InfoID_Res;

    struct
    {
        Uint8Type  ADR_01_PAG_Adr_AC_Menue_LED_an  :1;
        Uint8Type  ADR_01_PAG_Adr_Phone_LED_an     :1;
        Uint8Type  ADR_01_PAG_Adr_Media_LED_an     :1;
        Uint8Type  ADR_01_PAG_Adr_Tuner_LED_an     :1;
        Uint8Type  ADR_01_PAG_Adr_Car_LED_an       :1;
        Uint8Type  ADR_01_PAG_Adr_Info_LED_an      :1;
        Uint8Type  ADR_01_PAG_Adr_Navi_LED_an      :1;

    }ADR_01_PAG_ButtonStatus;

}CanResponses_INFO_MsgType;


/* CAN Responses */
typedef enum
{
    MIKO_BUTTON_RQ,
    KOMBI_02_OUTSIDE_TEMPERATURE_RQ
}CAN_REQUESTS_INFO_ID;

typedef struct
{
    CAN_REQUESTS_INFO_ID InfoID_Rq;

    struct
    {
        Uint16Type Miko_T_Source:1;
        Uint16Type Miko_T_AC_Menue:1;
        Uint16Type Miko_T_Phone:1;
        Uint16Type Miko_T_Media:1;
        Uint16Type Miko_T_Tuner:1;
        Uint16Type Miko_T_Back:1;
        Uint16Type Miko_T_Option:1;
        Uint16Type Miko_T_Car:1;
        Uint16Type Miko_T_Info:1;
        Uint16Type Miko_T_Navi:1;
        Uint16Type Miko_Volume_press:1;
        Uint16Type Miko_ADR_UltralongPress:1;
        Uint16Type res:4;
    }Miko_Status;
    struct
    {
        Uint8Type Aussen_Temp_status:8;
    }Kombi_02_Status;
}CanRequests_INFO_MsgType;



typedef union
{
    Uint16Type kombiSigError;
    struct
    {
        Uint16Type sigKBI_Aussen_Temp_gef    :1;
        Uint16Type sigKBI_Fotosensor        :1;
        Uint16Type sigKBI_KL58s    :1;
        Uint16Type sigKBI_E_Restreichweite :1;
        Uint16Type sigKBI_Trip_Reset_Min    :1;
        Uint16Type sigKBI_Trip_Reset_Std    :1;
        Uint16Type sigKBI_Trip_E_Strecke_seit    :1;
        Uint16Type sigKBI_Trip_E_Strecke_fortl    :1;
        Uint16Type sigKBI_Trip_E_Verbr_seit    :1;
        Uint16Type sigKBI_Trip_E_Verbr_fortl    :1;
        Uint16Type sigKBI_Kilometerstand        :1;
        Uint16Type                    :5;
    }Bits;
}KombiSigErrorBits;
typedef union
{
    Uint8Type motorSigError;
    struct
    {
        Uint8Type sigMO_Drehzahl_01               :1;
        Uint8Type sigEnrgfluss_State_sek           :1;
        Uint8Type sigEnrgfluss_State_BN             :1;
        Uint8Type sigLadezustand           :1;
        Uint8Type sigEnrgfluss_State           :1;
        Uint8Type                           :3;
    }Bits;
}MotorSigErrorBits;
typedef union
{
    Uint8Type espSigError;
    struct
    {
        Uint8Type sigESP_Laengsbeschl           :1;
        Uint8Type sigESP_Wegimpuls_VL           :1;
        Uint8Type sigESP_Wegimpuls_HL           :1;
        Uint8Type sigESP_Wegimpuls_VR           :1;
        Uint8Type sigESP_Wegimpuls_HR           :1;
        Uint8Type sigESP_v_Signal               :1;
        Uint8Type sigESP_Querbeschleunigung_Offset     :1;
        Uint8Type sigESP_Querbeschleunigung_Roh   :1;
    }Bits;
}EspSigErrorBits;
typedef union
{
    Uint8Type getriebeSigError;
    struct
    {
        Uint8Type sigGE_Waehlhebel        :1;
        Uint8Type sigGE_Zielgang    :1;
        Uint8Type                       :6;
    }Bits;
}GetriebeSigErrorBits;
typedef union
{
    Uint16Type gatewaySigError;
    struct
    {
        Uint16Type msgDiagnose_01   :1;
        Uint16Type msgGateway_03    :1;
        Uint16Type msgBEM_02        :1;
        Uint16Type msgGW_Mmi_07_PAG :1;
        Uint16Type msgGW_Mmi_06_PAG :1;
        Uint16Type msgGW_Mmi_10_PAG :1;
        Uint16Type msgNPM_01_PAG    :1;
        Uint16Type msgGateway_01    :1;
        Uint16Type msgGW_Mmi_01_PAG :1;
        Uint16Type msgGW_Mmi_05_PAG :1;
        Uint16Type msgGW_Mmi_04_PAG :1;
        Uint16Type                  :5;
    }Bits;
}GatewaySigErrorBits;
typedef union
{
    Uint8Type onBoardLaderSigError;
    struct
    {
        Uint16Type HVLM_Restladezeit_HV_Bat_02         :1;
        Uint16Type HVLM_Status_Timer_1_Minute        :1;
        Uint16Type HVLM_Status_Timer_2_Minute        :1;
        Uint16Type HVLM_Status_Timer_3_Minute        :1;
        Uint16Type HVLM_Status_Timer_4_Minute        :1;
        Uint16Type HVLM_Status_Timer_7_Minute        :1;
        Uint16Type HVLM_Status_Timer_1_Stunde        :1;
        Uint16Type HVLM_Status_Timer_2_Stunde        :1;
        Uint16Type HVLM_Status_Timer_3_Stunde        :1;
        Uint16Type HVLM_Status_Timer_4_Stunde        :1;
        Uint16Type HVLM_Status_Timer_7_Stunde        :1;
        Uint16Type HVLM_Status_Timer_1_Monat        :1;
        Uint16Type HVLM_Status_Timer_2_Monat        :1;
        Uint16Type HVLM_Status_Timer_3_Monat        :1;
        Uint16Type HVLM_Status_Timer_4_Monat        :1;
        Uint16Type HVLM_Status_Timer_7_Monat        :1;
    }Bits;
}OnBoardLaderSigErrorBits;

typedef struct
{
    KombiSigErrorBits kombi;
    MotorSigErrorBits  motor;
    EspSigErrorBits    esp;
    GetriebeSigErrorBits   getriebe;
    GatewaySigErrorBits    gateway;
    OnBoardLaderSigErrorBits   onBoardLader;
}CanSelfDiagnosisSignalErrorType;

void APP_CAN_IL_InitSignalReception_INFO(void);
void APP_CAN_IL_CheckSignalReception_INFO(void);

void APP_CAN_IL_Send_INFO_Signals(void);

#endif /* _APP_CAN_IL_INFO_H */

/* End Of File _APP_CAN_IL_INFO.h */
