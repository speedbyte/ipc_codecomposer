/******************************************************************************/
/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/


#ifndef _APP_CAN_IL_NAVIGATION_H
#define _APP_CAN_IL_NAVIGATION_H


/* CAN Reqeusts */
typedef enum
{
     INVALID_MDI_RQ,
     /* --------------------------- */    // CAN-ID 0x1D0/0x1D2
     DSP_USB_SETOPMODE_RQ    ,
     DSP_IPOD_SETOPMODE_RQ   ,
     DSP_BTAUD_SETOPMODE_RQ  ,
     /* --------------------------- */    // CAN-ID 0x1EC
     DSP_USB_SETSHUFFLE_RQ   ,
     DSP_USB_SETINTROSCAN_RQ ,
     DSP_USB_SETREPEAT_RQ    ,
     DSP_USB_SKIPTRACK_RQ    ,
     DSP_USB_SKIPFOLDER_RQ   ,
     DSP_IPOD_SETSHUFFLE_RQ   ,
     DSP_IPOD_SETINTROSCAN_RQ ,
     DSP_IPOD_SETREPEAT_RQ    ,
     DSP_IPOD_SKIPTRACK_RQ    ,
     DSP_IPOD_SKIPFOLDER_RQ   ,
     DSP_BTAUD_SETSHUFFLE_RQ   ,
     DSP_BTAUD_SETINTROSCAN_RQ ,
     DSP_BTAUD_SETREPEAT_RQ    ,
     DSP_BTAUD_SKIPTRACK_RQ    ,
     DSP_BTAUD_SKIPFOLDER_RQ   ,
     /* --------------------------- */    // CAN-ID 0x1F4
     DSP_USB_FOLDERNAME_RQ   ,
     DSP_BTAUD_FOLDERNAME_RQ ,
     /* --------------------------- */    // CAN-ID 0x1F6
     DSP_USB_FILELIST_RQ     ,
     DSP_BTAUD_FILELIST_RQ   ,
     /* --------------------------- */    // CAN-ID 0x1F7
     DSP_USB_PLAYFOLDER_RQ   ,
     DSP_BTAUD_PLAYFOLDER_RQ ,
     /* --------------------------- */    // CAN-ID 0x1F8
     MC_USB_FOLDERNAME_RQ    ,
     MC_BTAUD_FOLDERNAME_RQ  ,
     /* --------------------------- */    // CAN-ID 0x1F9
     MC_USB_FILELIST_RQ      ,
     MC_BTAUD_FILELIST_RQ    ,
     /* --------------------------- */    // CAN-ID 0x1FA
     MC_USB_PLAYFOLDER_RQ    ,
     MC_BTAUD_PLAYFOLDER_RQ  ,
     /* --------------------------- */    // CAN-ID 0x1FB
     MC_IPOD_SETTRACK_RQ     ,
     /* --------------------------- */    // CAN-ID 0x1FC
     MC_IPOD_DBINFO_RQ      ,
     /* --------------------------- */    // CAN-ID 0x1FD
     DSP_IPOD_SETTRACK_RQ    ,
     /* --------------------------- */    // CAN-ID 0x1FE
     DSP_IPOD_DBINFO_RQ,
     /* --------------------------- */    // CAN-ID 0x2FB
     VC_COM_PLAY_RQ
}CAN_REQUESTS_MDI_ID;

typedef struct
{
    CAN_REQUESTS_MDI_ID MdiID_Rq;

    struct
    {
        /* 0x1D0/0x1D2 */
        Uint8Type  Dsp_USB_SetOpMode_Rq     :3;
        Uint8Type  Dsp_iPod_SetOpMode_Rq    :3;
        Uint8Type  Dsp_BTAud_SetOpMode_Rq   :3;
        /* 0x1EC */
        Uint8Type  Dsp_SetShuffle_Rq        :3;
        Uint8Type  Dsp_SetIntroScan_Rq      :3;
        Uint8Type  Dsp_SetRepeat_Rq         :3;
        Uint8Type  Dsp_SkipTrack_Rq         :2;
        Uint8Type  Dsp_SkipFolder_Rq        :2;
        /* 0x1F4 - GetMPFolderName_Rq */
        Uint8Type  Dsp_ItemNameLength_Rq;
        Uint16Type Dsp_CutItem_Rq;
        Uint16Type Dsp_FolderNumber_Rq;
        Uint32Type Dsp_SourceSetTrack_Rq;
        /* 0x1F6 - GetMPInfo_Rq */
        Uint16Type  Dsp_FolderNumber2_Rq;
        Uint16Type  Dsp_StartItemIndex_Rq;
        Uint16Type  Dsp_NbrOfItems2_Rq      :5;
        Uint16Type  Dsp_ItemNameLength2_Rq  :5;
        Uint16Type  Dsp_CutItem2_Rq         :2;
        Uint16Type  Dsp_FolderContent_Rq    :2;
        /* 0x1F7 - PlayFirstTrackInFolder_Rq */
        Uint16Type  Dsp_FolderNumber3_Rq;
        Uint16Type  Dsp_ItemIndex_Rq;
        Uint16Type  Dsp_PlayFrstTrInFldr_Rq;
        /* 0x1FD - MDBSetTrack_Rq (iPod) */
        Uint16Type  Dsp_DB1SetTrkSetFilt1_Rq;
        Uint16Type  Dsp_DB1SetTrkSetFilt2_Rq;
        Uint16Type  Dsp_DB1SetTrkSetFilt3_Rq;
        Uint8Type   Dsp_DB1SetTrkSetConf_Rq;
        Uint16Type  Dsp_DB1SetTrkItemIndex_Rq;
        /* 0x1FE - GetMDBInfo_Rq (iPod) */
        Uint16Type  Dsp_DBFilter1_Rq;
        Uint16Type  Dsp_DBFilter2_Rq;
        Uint16Type  Dsp_DBFilter3_Rq;
        Uint8Type   Dsp_DBFilterConf_Rq     :5;
        Uint8Type   Dsp_DBNbrOfItems_Rq     :1; // 0 = standard (as in Config); 1 = 1 item
        Uint16Type  Dsp_DBStartItemInd_Rq;
    }Dsp_Requests;

    struct
    {
        /* 0x1F4 - GetMPFolderName_Rq */
        Uint8Type  Mc_ItemNameLength_Rq;
        Uint16Type Mc_CutItem_Rq;
        Uint16Type Mc_FolderNumber_Rq;
        Uint32Type Mc_SourceSetTrack_Rq;
        /* 0x1F6 - GetMPInfo_Rq */
        Uint16Type  Mc_FolderNumber2_Rq;
        Uint16Type  Mc_StartItemIndex_Rq;
        Uint16Type  Mc_NbrOfItems2_Rq      :5;
        Uint16Type  Mc_ItemNameLength2_Rq  :5;
        Uint16Type  Mc_CutItem2_Rq         :2;
        Uint16Type  Mc_FolderContent_Rq    :2;
        /* 0x1F7 - PlayFirstTrackInFolder_Rq */
        Uint16Type  Mc_FolderNumber3_Rq;
        Uint16Type  Mc_ItemIndex_Rq;
        Uint16Type  Mc_PlayFrstTrInFldr_Rq;
        /* 0x1FD - MDBSetTrack_Rq (iPod) */
        Uint16Type  Mc_DB1SetTrkSetFilt1_Rq;
        Uint16Type  Mc_DB1SetTrkSetFilt2_Rq;
        Uint16Type  Mc_DB1SetTrkSetFilt3_Rq;
        Uint8Type   Mc_DB1SetTrkSetConf_Rq;
        Uint16Type  Mc_DB1SetTrkItemIndex_Rq;
        /* 0x1FE - GetMDBInfo_Rq (iPod) */
        Uint16Type  Mc_DBFilter1_Rq;
        Uint16Type  Mc_DBFilter2_Rq;
        Uint16Type  Mc_DBFilter3_Rq;
        Uint8Type   Mc_DBFilterConf_Rq     :5;
        Uint8Type   Mc_DBNbrOfItems_Rq     :1; // 0 = standard (as in Config); 1 = 1 item
        Uint16Type  Mc_DBStartItemInd_Rq;
    }Mc_Requests;

    struct
    {
        /* 0x2FB - VC Play request */
        Uint8Type   Vc_PlaySource           :3;
        Uint8Type   Vc_PlayType             :3;
        Uint16Type  Vc_PlayNumber;
    }Vc_Requests;
}CanRequests_MDI_MsgType;

typedef enum
{
    ConSWUpdateInvalid,         // 0
    ConSWUpdateNotRunning,      // 1
    ConSWUpdateInProgress,      // 2
    ConSWUpdateFailed,          // 3
    ConSWUpdateNotNecessary,    // 4
    ConSWUpdateSuccess          // 5
}Can_MDI_SWDLProgress;
typedef enum
{
    MDIPlayType_Invalid     = 0,
    MDIPlayType_Folder      = 1,
    MDIPlayType_Playlist    = 2
}Can_MDI_PlayType;
typedef enum
{
    MDBListType_Root        = 0x00,
    MDBListType_Playlist    = 0x01,
    MDBListType_Artist      = 0x02,
    MDBListType_Album       = 0x03,
    MDBListType_Genre       = 0x04,
    MDBListType_Track       = 0x05,
    MDBListType_Composer    = 0x06,
    MDBListType_Audiobook   = 0x07,
    MDBListType_Podcast     = 0x08,
    MDBListType_Unknown     = 0x1F
}Can_MDI_MDBInfo_ListType;
typedef enum
{
    MDBFilterPos_FilterConfig   = 0x0,
    MDBFilterPos_Filter1        = 0x1,
    MDBFilterPos_Filter2        = 0x2,
    MDBFilterPos_Filter3        = 0x3,
    MDBFilterPos_ItemIndex      = 0x4
}Can_MDI_MDBFilter_PositionType;
typedef enum
{
    VCPlaySource_USB        = 5,
    VCPlaySource_iPod       = 6,
    VCPlaySource_BTAudio    = 7
}Can_MDI_VcPlaySourceType;
typedef enum
{
    VCPlayType_FordFolder   = 2,
    VCPlayType_FordPlaylist = 3,
    VCPlayType_Track        = 4
}Can_MDI_VcPlayTypeType;


/* CAN Responses */
typedef enum
{
     INVALID_MDI_RSP                ,
     CON_RESET_ALL                  ,
     /* --------------------------- */  //  Can-ID 0x2E5
     CON_USB_OPMODE_ST              ,
     CON_USB_FUNCTSTATUS_ST         ,
     CON_USB_SHUFFLE_ST             ,
     CON_USB_INTROSCAN_ST           ,
     CON_USB_REPEAT_ST              ,
     CON_USB_ERROR_ST               ,
     CON_USB_PLAYTYPE_ST            ,
     CON_USB_SHOW_SWDL_PROGRESS_ST  ,
     CON_IPOD_OPMODE_ST             ,
     CON_IPOD_FUNCTSTATUS_ST        ,
     CON_IPOD_SHUFFLE_ST            ,
     CON_IPOD_INTROSCAN_ST          ,
     CON_IPOD_REPEAT_ST             ,
     CON_IPOD_ERROR_ST              ,
     /* --------------------------- */  //  Can-ID 0x2E7
     CON_USB_TRACKPLAYTIME_ST       ,
     CON_IPOD_TRACKPLAYTIME_ST      ,
     /* --------------------------- */  //  Can-ID 0x2E8
     CON_USB_ACTIVETRACK_ST         ,
     CON_USB_NBROFTRACKS_ST         ,
     /* --------------------------- */  //  Can-ID 0x2E9
     CON_IPOD_ACTIVEFILTER_ST       ,
     /* --------------------------- */  //  Can-ID 0x2EA
     CON_BTAUD_ACTIVETRACK_ST       ,
     CON_BTAUD_INTROSCAN_ST         ,
     CON_BTAUD_REPEAT_ST            ,
     CON_BTAUD_OPMODE_ST            ,
     CON_BTAUD_SHUFFLE_ST           ,
     CON_BTAUD_ERROR_ST             ,
     CON_BTAUD_FUNCTSTATUS_ST       ,
     /* --------------------------- */  //  Can-ID 0x2EC
     CON_BTAUD_TRACKPLAYTIME_ST     ,
     /* --------------------------- */  //  ISO-TP (single handling for all devices)
     CON_FOLDERNAME_RSP             ,
     CON_TRACKNAME_ST               ,
     CON_ALBUMNAME_ST               ,
     CON_ARTISTNAME_ST              ,
     CON_FOLDERNAME_ST              ,
     CON_GENRENAME_ST               ,
     CON_FILENAME_ST
}CAN_RESPONSES_MDI_ID;


typedef struct
{
    CAN_RESPONSES_MDI_ID MdiID_Res;

    struct
    {
        Uint8Type Con_USB_OpMode_St           :3;
        Uint8Type Con_USB_FunctStatus_St      :3;
        Uint8Type Con_USB_Shuffle_St          :2;
        Uint8Type Con_USB_IntroScan_St        :2;
        Uint8Type Con_USB_Repeat_St           :3;
        Uint8Type Con_USB_Error_St            :4;
        Uint8Type Con_USB_Playtype_St         :2;
        Uint8Type Con_USB_ShowSWDLprogress_St :3;
        Uint8Type Con_USB_ShowSWDLbargr_St    :7;
        Uint16Type Con_USB_TrackPlayTime_St;
        Uint32Type Con_USB_TrackNumber_St;
    }USB;

    struct
    {
        Uint8Type Con_IPOD_OpMode_St          :3;
        Uint8Type Con_IPOD_FunctStatus_St     :3;
        Uint8Type Con_IPOD_Repeat_St          :3;
        Uint8Type Con_IPOD_Shuffle_St         :2;
        Uint8Type Con_IPOD_Error_St           :4;
        Uint8Type Con_IPOD_IntroScan_St       :2;
        Uint16Type Con_IPOD_TrackPlayTime_St;
        Uint16Type Con_IPOD_DBFilter1_St;
        Uint16Type Con_IPOD_DBFilter2_St;
        Uint16Type Con_IPOD_DBFilter3_St;
        Uint8Type Con_IPOD_DBFilterConf_St;
        Uint16Type Con_IPOD_DBItemIndex_St;
    }IPOD;

    struct
    {
        Uint32Type Con_BTAud_TrackNumber_St;
        Uint8Type  Con_BTAud_IntroScan_St     :2;
        Uint8Type  Con_BTAud_Repeat_St        :3;
        Uint8Type  Con_BTAud_OpMode_St        :3;
        Uint8Type  Con_BTAud_Shuffle_St       :2;
        Uint8Type  Con_BTAud_Error_St         :4;
        Uint8Type  Con_BTAud_FunctStatus_St   :3;
        Uint16Type Con_BTAud_TrackPlayTime_St;
    }BT_AUDIO;

}CanResponses_MDI_MsgType;


void APP_CAN_IL_InitSignalReception_Navigation(void);
void APP_CAN_IL_CheckSignalReception_Navigation(void);

void APP_CAN_IL_Send_Navigation_Signals(void);

#endif /* _APP_CAN_IL_Navigation_H */

/* End Of File _APP_CAN_IL_Navigation .h */
