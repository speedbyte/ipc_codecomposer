/******************************************************************************/
/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/


#ifndef _APP_CAN_IL_KLIMA_H
#define _APP_CAN_IL_KLIMA_H


/* CAN Reqeusts */
typedef enum
{
    INVALID_PHONE_RQ = 0          ,
    HMI_BTSENDDTMFTONE_RQ      ,
    HMI_BTENDTELSERVICE_RQ     ,
    HMI_BTINCOMINGCALL_RQ      ,
    HMI_SETINCCALLOPTION_RQ    ,
    HMI_PHONESSTS_RQ           ,
    HMI_PHMICROPHONEMUTE_RQ    ,
    HMI_SETBLUTOOTHMODE_RQ     ,
    HMI_SUBSCRIBESTINFO_RQ     ,
    HMI_SETDEFAULTPHONE_RQ     ,
    HEC_BTENDTELSERVICE2_RQ    ,
    HEC_BTINCOMINGCALL2_RQ     ,
    HEC_PHONEVOICECTRLBUTTONS_RQ ,
    TP_INITIATEBTCALL_HMI_RQ,
    TP_BTGETLASTNUMBER_HMI_RQ,
    TP_BTPHONEBOOKITEMS_HMI_RQ,
    TP_BTSEARCHPHONEBOOK_HMI_RQ,
    TP_INITIATEBTCALL_HEC_RQ,
    TP_BTGETLASTNUMBER_HEC_RQ,
    TP_BTPHONEBOOKITEMS_HEC_RQ,
    TP_BTSEARCHPHONEBOOK_HEC_RQ
}CAN_REQUESTS_PHONE_ID;

typedef struct
{
    CAN_REQUESTS_PHONE_ID PhoneID_Rq;

    struct
    {
        Uint8Type HMI_BTSendDTMFTone_Rq      :4;
        Uint8Type HMI_BTEndTelService_Rq     :2;
        Uint8Type HMI_BTIncomingCall_Rq      :2;
        Uint8Type HMI_SetIncCallOption_Rq    :2;
        Uint8Type HMI_PhonesSts_Rq           :2;
        Uint8Type HMI_PhMicrophoneMute_Rq    :2;
        Uint8Type HMI_SetBlutoothMode_Rq     :2;
        Uint8Type HMI_SubscribeStInfo_Rq     :2;
        Uint8Type HMI_SetDefaultPhone_Rq     :3;
        Uint8Type TP_Rq[27];
    }HMI_Requests;

    struct
    {
        Uint8Type HEC_BTEndTelService2_Rq    :2;
        Uint8Type HEC_BTIncomingCall2_Rq     :2;
        Uint8Type HEC_PhoneVoiceCtrlButtons  :3;
        Uint8Type TP_Rq[27];
    }HEC_Requests;  // 8 Bits
}CanRequests_PHONE_MsgType;

/* CAN Responses */
typedef enum
{
     INVALID_PHONE_RSP           ,
     VRM_BTSENDDTMFTONE_RSP      ,
     VRM_BTENDTELSERVICE_RSP     ,
     VRM_BTINCOMINGCALL_RSP      ,
     VRM_PHONESSTS_RSP           ,
     VRM_DEFAULTPHONE_RSP        ,
     TP_INITIATEBTCALL_RSP       ,
     TP_BTGETLASTNUMBER_RSP      ,
     TP_BTPHONEBOOKITEMS_RSP     ,
     TP_BTSEARCHPHONEBOOK_RSP    ,
     /*--------------------------*/
     VRM_BTSIGNALSTRENGTH_ST     ,               /* 0x2D0*/
     VRM_BTBATTERYLEVEL_ST       ,
     VRM_BTNETWORKPROVIDER_ST    ,
     VRM_PHMICROPHONEMUTE_ST     ,
     VRM_BTNETWORKSTATUS_ST      ,
     VRM_BLUTOOTHSTATUS_ST       ,
     VRM_BTPHONESTS_ST           ,
     VRM_SUBSCRIBESTATUS_ST      ,
     FLT_RESENDSTATUS_ST         ,              /* Fault handling -> resend Phone status signals */
     TP_BTCALLERIDENTIFICATION_ST,
     /*--------------------------*/
     VRM_CALLDURATION_ST         ,
     VRM_INCCALLOPTION_ST
}CAN_RESPONSES_PHONE_ID;

#define MAX_PHONE_TP_RESP_BUFFER_LENTH 1
#define MAX_PHONE_TP_RESP_STAT_BUFFER_LENTH 1
#define MAX_PHONE_TP_STAT_BUFFER_LENTH 1
typedef Uint8Type CAN_TP_PhoneRespString[MAX_PHONE_TP_RESP_BUFFER_LENTH];
typedef Uint8Type CAN_TP_PhoneRespStatString[MAX_PHONE_TP_RESP_STAT_BUFFER_LENTH];
typedef Uint8Type CAN_TP_PhoneStatString[MAX_PHONE_TP_STAT_BUFFER_LENTH];

typedef enum
{
    TP_ID_HMI = 0,
    TP_ID_HEC = 1
}CAN_TP_REQ_TP_ID;

typedef struct
{
    CAN_TP_PhoneRespString tpBuffer;
    Uint16Type tpLength;
    Uint8Type tpNumbOfItems;
    CAN_TP_REQ_TP_ID rqTpId;
}CanTPResponse_PHONE_BufType;

typedef struct
{
    CAN_TP_PhoneRespStatString tpBuffer;
    Uint16Type tpLength;
    Uint8Type tpNumbOfItems;
    CAN_TP_REQ_TP_ID rqTpId;
}CanTPResponse_PHONE_BufStatType;

typedef struct
{
    CAN_TP_PhoneStatString tpBuffer;
    Uint16Type tpLength;
}CanTPStatus_PHONE_BufType;


typedef struct
{
    CAN_RESPONSES_PHONE_ID PhoneID_Res;

    struct
    {
        CanTPResponse_PHONE_BufType *pTPRespBuffer;
        CanTPResponse_PHONE_BufStatType *pTPRespStatBuffer;
        CanTPStatus_PHONE_BufType *pTPStatBuffer;
    }TP_Data;

    struct
    {
        Uint8Type  VRM_BTSendDTMFTone_Rsp    :2;
        Uint8Type  VRM_BTEndTelService_Rsp   :2;
        Uint8Type  VRM_BTIncomingCall_Rsp    :2;
        Uint8Type  VRM_PhonesSts_Rsp         :8;
        Uint8Type  VRM_DefaultPhone_Rsp      :4;
    }VRM_BT_Responses;

    struct
    {
        Uint8Type  VRM_BTSignalStrength_St   :4;
        Uint8Type  VRM_BTBatteryLevel_St     :4;
        Uint8Type  VRM_PhMicrophoneMute_St   :2;
        Uint8Type  VRM_BTNetworkStatus_St    :3;
        Uint8Type  VRM_SubscribeStatus_St    :2;
        Uint8Type  VRM_BlutoothStatus_St     :2;
        Uint8Type  VRM_BTPhoneSts_St         :5;
        Uint16Type VRM_CallDuration_St       :16;
        Uint8Type  VRM_IncCallOption_St      :2;
        Uint8Type  VRM_dummy4                :7;
    }VRM_BT_Status;
    
}CanResponses_PHONE_MsgType;




void APP_CAN_IL_InitSignalReception_Klima(void);
void APP_CAN_IL_CheckSignalReception_Klima(void);

void APP_CAN_IL_Send_KLima_Signals(void);

#endif /* _APP_CAN_IL_KLIMA_H */

/* End Of File _APP_CAN_IL_KLIMA.h */
