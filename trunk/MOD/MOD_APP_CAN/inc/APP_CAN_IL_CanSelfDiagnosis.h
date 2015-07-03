/******************************************************************************/
/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/


#ifndef _APP_CAN_IL_CANSELFDIAGNOSIS_H
#define _APP_CAN_IL_CANSELFDIAGNOSIS_H

typedef union
{
    Uint16Type kombiError;
    struct
    {
        Uint16Type msgKombi_11_PAG    :1;
        Uint16Type msgKombi_02        :1;
        Uint16Type msgKombi_19_PAG    :1;
        Uint16Type msgKombi_EV_01_PAG :1;
        Uint16Type msgKombi_14_PAG    :1;
        Uint16Type msgKombi_17_PAG    :1;
        Uint16Type msgKombi_16_PAG    :1;
        Uint16Type msgKombi_10_PAG    :1;
        Uint16Type msgKombi_13_PAG    :1;
        Uint16Type altKombi_02_alt    :1;
        Uint16Type altUhrzeit_01_alt  :1;
        Uint16Type                    :5;
    }Bits;
}KombiErrorBits;
typedef union
{
    Uint8Type motorError;
    struct
    {
        Uint8Type msgMotor_06               :1;
        Uint8Type msgMotor_15_PAG           :1;
        Uint8Type msgMotor_K_02             :1;
        Uint8Type msgMotor_02_sek           :1;
        Uint8Type altMotor_06_alt           :1;
        Uint8Type altMotor_03_alt           :1;
        Uint8Type altF_Motor_Hybrid_01_Mmi  :1;
        Uint8Type                           :1;
    }Bits;
}MotorErrorBits;
typedef union
{
    Uint8Type bcmVorneError;
    struct
    {
        Uint8Type msgVIN_01             :1;
        Uint8Type msgBCM1_02            :1;
        Uint8Type msgKlemmen_Status_01  :1;
        Uint8Type altF_BCM2_02_Mmi      :1;
        Uint8Type altF_BCM1_01_Mmi      :1;
        Uint8Type                       :3;
    }Bits;
}BcmVorneErrorBits;
typedef union
{
    Uint8Type espError;
    struct
    {
        Uint8Type msgESP_10         :1;
        Uint8Type msgESP_02         :1;
        Uint8Type msgESP_01         :1;
        Uint8Type altESP_01_alt     :1;
        Uint8Type altF_ESP_04_Mmi   :1;
        Uint8Type altF_ESP_02_Mmi   :1;
        Uint8Type altF_ESP_13_Mmi   :1;
        Uint8Type                   :1;
    }Bits;
}EspErrorBits;
typedef union
{
    Uint8Type getriebeError;
    struct
    {
        Uint8Type msgGetriebe_03        :1;
        Uint8Type altGetriebe_03_alt    :1;
        Uint8Type                       :6;
    }Bits;
}GetriebeErrorBits;
typedef union
{
    Uint16Type gatewayError;
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
}GatewayErrorBits;
typedef union
{
    Uint8Type onBoardLaderError;
    struct
    {
        Uint8Type msgLAD_02         :1;
        Uint8Type msgHVLM_05        :1;
        Uint8Type msgHVLM_07_PAG    :1;
        Uint8Type                   :5;
    }Bits;
}OnBoardLaderErrorBits;

typedef union
{
    Uint8Type klimaError;
    struct
    {
        Uint8Type msgKlima_03       :1;
        Uint8Type msgKlima_02       :1;
        Uint8Type msgKlima_13_PAG   :1;
        Uint8Type                   :5;
    }Bits;
}KlimaErrorBits;

typedef struct
{
    KombiErrorBits kombi;
    MotorErrorBits  motor;
    BcmVorneErrorBits bcmVorne;
    EspErrorBits    esp;
    GetriebeErrorBits   getriebe;
    GatewayErrorBits    gateway;
    OnBoardLaderErrorBits   onBoardLader;
    KlimaErrorBits  klima;
}CanSelfDiagnosisMsgErrorType;

void APP_CAN_IL_CheckSignalSelfDiagnosisAltBitReception(void);
#endif /* _APP_CAN_IL_CANSELFDIAGNOSIS_H */

/* End Of File APP_CAN_IL_ISO_TP.h */
