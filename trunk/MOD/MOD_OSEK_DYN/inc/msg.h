/* PRQA S 0883 EOF */ /* this file is intentionally included multiple times */
/* file: msg.h, automatically generated by GENTMS470.EXE, Version: 3.10 */
/* from: F:\PROJECTS\ADR-PORSCHE\PORSCHE_ADR_DEVELOPMENT_TRUNK\MOD\MOD_OSEK_DYN\CFG\PAG_ADR.oil */
/* at  : Wed Feb 22 07:46:34 2012 */
/* License 2400100185 for S1nn GmbH u. Co. KG, Infotainment and Connectivity */
/* Implementation: TMS470R1 */
/* Version of general code: 3.54b */

#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif
#define osdVrmGenMajRelNum 3
#define osdVrmGenMinRelNum 10
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif

#ifndef __MSG_1__
#define __MSG_1__

/* first part - included at the beginning of osekcom.h */

/* conformance class */
#define osdCCCA 1
#define osdCCCB 2
#define osdCCC osdCCCB

/* number of all messages */
#define osdNumberOfMsgs 9

/* number of all unqueued messages */
#define osdNumberOfMsgsUnQueuedMsgs 4

/* number of all queued messages */
#define osdNumberOfMsgsQueuedMsgs 5

/* number of all queues with size >= 1 */
#define osdNumberOfMsgsQueues 5

/* number of all receiving tasks */
#define osdNumberOfMsgsRcvTasks 3

/* number of all notifications */
#define osdNumberOfMsgsNotifications 9

/* number of callback notifications */
#define osdNumberOfMsgsCallbackNotifics 0

/* number of flag notifications */
#define osdNumberOfMsgsFlagNotifics 0

/* usage of message resource */
#define osdUseMessageResource 1

/* usage of message status */
#define osdUseMessageStatus 1

#define osdMsgQSizemsgCshdl_Requests 7
#define osdMsgQSizemsgAppTaskSystemStates 2
#define osdMsgQSizemsgInfo_Responses 4
#define osdMsgQSizemsgInfo_Requests 4
#define osdMsgQSizemsgApplResponse 6
#ifndef osdAsmFile

/* user defined structures for messages */
#if osdNumberOfMsgs > 0
#if defined USE_QUOTE_INCLUDES
 #include "umsgtype.h"
#else
 #include <umsgtype.h>
#endif
#else
extern uint8 ucComDummy;
#endif

/* collection of all user defined structures */
typedef union
{
   PWMGR_enVoltageStates PWMGR_enVoltageStates_obj;
   CanRequests_CSHDL_MsgType CanRequests_CSHDL_MsgType_obj;
   APP_DIAG_ST_DIAG_RESPONSE APP_DIAG_ST_DIAG_RESPONSE_obj;
   APP_DIAG_ST_DIAG_REQUEST APP_DIAG_ST_DIAG_REQUEST_obj;
   CSHDL_enSystemStates CSHDL_enSystemStates_obj;
   CSHDL_ENUM_REQUEST_TO_CAN CSHDL_ENUM_REQUEST_TO_CAN_obj;
   CanResponses_INFO_MsgType CanResponses_INFO_MsgType_obj;
   CanRequests_INFO_MsgType CanRequests_INFO_MsgType_obj;
   ApplRspMessageType ApplRspMessageType_obj;
} DataType;

/* a reference to the user defined data will be used */
typedef DataType* DataRefType;

#endif

#else
#ifndef __MSG_2__
#define __MSG_2__
/* second part - included at the end of osekcom.h */

/* externals for messages */
osqROM0 extern osqROM1 const osqROM2 osComMsg osqROM3 msgPwrmgrState;
osqROM0 extern osqROM1 const osqROM2 osComMsg osqROM3 msgCshdl_Requests;
osqROM0 extern osqROM1 const osqROM2 osComMsg osqROM3 msgAppDiagDiagnoseResponse;
osqROM0 extern osqROM1 const osqROM2 osComMsg osqROM3 msgAppDiagDiagnoseRequest;
osqROM0 extern osqROM1 const osqROM2 osComMsg osqROM3 msgAppTaskSystemStates;
osqROM0 extern osqROM1 const osqROM2 osComMsg osqROM3 msgCshdlRequestToCan;
osqROM0 extern osqROM1 const osqROM2 osComMsg osqROM3 msgInfo_Responses;
osqROM0 extern osqROM1 const osqROM2 osComMsg osqROM3 msgInfo_Requests;
osqROM0 extern osqROM1 const osqROM2 osComMsg osqROM3 msgApplResponse;

/* externals for unqueued user data (needed for "WithoutCopy") */
extern PWMGR_enVoltageStates msgPwrmgrStateUsrData;
extern APP_DIAG_ST_DIAG_RESPONSE msgAppDiagDiagnoseResponseUsrData;
extern APP_DIAG_ST_DIAG_REQUEST msgAppDiagDiagnoseRequestUsrData;
extern CSHDL_ENUM_REQUEST_TO_CAN msgCshdlRequestToCanUsrData;

/* access names - global buffers for copies */
extern PWMGR_enVoltageStates RecPWMGR_enVoltageStates;
extern PWMGR_enVoltageStates SentPWMGR_enVoltageStates;
extern CanRequests_CSHDL_MsgType SentBSGmessageType;
extern CanRequests_CSHDL_MsgType CanRx_CSHDL_ReceivedMsgData;
extern APP_DIAG_ST_DIAG_RESPONSE RecAppDiagResp;
extern APP_DIAG_ST_DIAG_RESPONSE SetAppDiagReq;
extern APP_DIAG_ST_DIAG_REQUEST SentAppDiagReq;
extern APP_DIAG_ST_DIAG_REQUEST RecAppDiagReq;
extern CSHDL_enSystemStates RecCSHDL_enSystemStates;
extern CSHDL_enSystemStates SentCSHDL_enSystemStates;
extern CSHDL_ENUM_REQUEST_TO_CAN ReceivedMessage_Cshdl_To_Can;
extern CSHDL_ENUM_REQUEST_TO_CAN SentMessage_Cshdl_To_Can;
extern CanResponses_INFO_MsgType CanTx_INFO_ReceivedMsgData;
extern CanResponses_INFO_MsgType CanTx_INFO_SentMsgData;
extern CanRequests_INFO_MsgType CanRx_INFO_SentMsgData;
extern CanRequests_INFO_MsgType CanTx_INFO_ReceiveMsgData;
extern ApplRspMessageType RecvApplResponse;
extern ApplRspMessageType SentApplResponse;

/* access names - direct access to message object */

/* prototypes for callback functions */

/* defines for flag access */
#if osdNumberOfMsgsFlagNotifics
extern osqTcbRAM1 osqTcbRAM2 FlagType osqTcbRAM3 osComFlags[osdNumberOfMsgsFlagNotifics];
#endif

#endif

#endif

#ifndef osrNumberOfMsgsFlagNotifics /*double include preventer*/
# if osdLib
#  define osrNumberOfMsgsFlagNotifics oskNumberOfMsgsFlagNotifics
extern const uint16 oskNumberOfMsgsFlagNotifics;
# else
#  define osrNumberOfMsgsFlagNotifics osdNumberOfMsgsFlagNotifics
# endif
#endif

/* END OF F:\PROJECTS\ADR-PORSCHE\PORSCHE_ADR_DEVELOPMENT_TRUNK\MOD\MOD_OSEK_DYN\CFG\tcb\msg.h */

