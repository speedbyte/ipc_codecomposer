
/*****************************************************************************
|  File Name: CCL_INC.H 
|
|  Description: Communication Control Layer Header (CORE)
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2000-2010 by Vector Informatik GmbH.      All rights reserved.
|
|               This software is copyright protected and proprietary 
|               to Vector Informatik GmbH. Vector Informatik GmbH 
|               grants to you only those rights as set out in the 
|               license conditions. All other rights remain with 
|               Vector Informatik GmbH.
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Bs           Thomas Balster            Vector Informatik GmbH
| Et           Thomas Ebert              Vector Informatik GmbH
| Zw           Werner Ziegler            Vector Informatik GmbH
| Pet          Thomas Petrus             Vector Informatik GmbH
| Dhf          Daniel Hof                Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Ver     Author  Description
| ---------   ----    ------  --------------------------------------------------
| 19.06.02    1.00    Zw      Initial version 
| 2002-12-02  1.01    Pet     add support for psa
| 2002-12-03  1.01    Pet     add support for Micronas CEVF
| 2003-02-04  1.02    Pet     ESCAN00004878: add support for GMLAN (single receive channel)
| 2003-02-06          Pet     ESCAN00004881: add support for NM JUNIOR
| 2003-04-01  1.04    Pet     ESCAN00005345: separation CCL into core files and OEM extension files
| 2003-06-05  1.05    Pet     CCL DLL version change
| 2003-06-16  1.05.01 Pet     bugfix version changed
| 2003-07-25  1.05.02 Pet     optimization for PSA
| 2003-08-11  1.05.03 Pet     new DLL bugfix version
| 2003-08-19  1.05.04 Pet     new DLL version
|                     Pet     ESCAN00006299: check return value of "CanSleep"
|                     Pet     ESCAN00006375: multiple release of network requests
| 2003-09-24  1.06    Et      ESCAN00007184: EMC wake up
|                             ESCAN00007185: network management restriction
|                             ESCAN00007187: pagging support
|                             ESCAN00007189: initialization API
|                             ESCAN00007190: reworking (algorithms and namings)
| 2003-12-28  1.07    Et      ESCAN00007258: debug access to internal states (C_COMP_ANSI_CANOE)
|                             ESCAN00007259: initialisation of "cclComHwState" and "cclComSwState"
|                             ESCAN00007260: start EMC wake up timer at power on (+30 reset)
|                             ESCAN00007261: support EMC wake up for CAN driver API
|                             ESCAN00007262: "C_SINGLE_RECEIVE_BUFFER" and "C_MULTIPLE_RECEIVE_BUFFER"
|                             ESCAN00007263: DLL compatibility defines (< V1.06)
|                             ESCAN00007264: support edge triggered transceiver port interrupt
|                             ESCAN00007265: correct network restriction handling
|                             ESCAN00007266: correct network restriction handling
|                             ESCAN00007267: conditional message reception & internal network request
| 2004-01-17  1.07.01 Et      ESCAN00007277: COSMIC compiler option -pck
| 2004-01-21  1.07.02 Pet     ESCAN00007310: wrong #endif
|                             ESCAN00007311: missing encapsulation of cclCanSleepRepetition
|                             ESCAN00007296: different parameter list by Error Hook function CclFatalError
| 2004-01-23  1.08    Pet     ESCAN00007328: add component define for DPM
|                             ESCAN00007403: dummy assignment  NM_MSG_COND_RX_PARAMETER_NAME#
|                             ESCAN00007404: support MISRA compliance
| 2004-02-02  1.09    Et      ESCAN00007429: incorrect CclComRelFct notification (set network restriction)
|                             ESCAN00007481: gateway component handle
|                             ESCAN00007548: extern declaration debug variables
| 2004-03-01  1.10    Pet     ESCAN00007741: compiler error in CclInitPowerOn
|                     Et      ESCAN00007722: support no external network requests
|                             ESCAN00007763: add include v_inc.h
|                             ESCAN00007773: no cancel of repeated CanSleep by external wake up
| 2004-03-16  1.11    Pet     ESCAN00007907: function CclGetNmState now API function
|                             ESCAN00007615: support of virtual networks (only for single receive channel)
| 2004-06-17  1.12    Pet     ESCAN00008082: EMC Wakeup Time in DPM is lower than 500ms
|                             ESCAN00008379: missing datatype in the prototypes of ApplCclVnDeactivated and ApplCclVnActivated
| 2004-07-02  1.13    Pet     ESCAN00008750: wrong assertion check
| 2004-07-30  1.14    Pet     ESCAN00009037: support multiple configurations
|                     Pet     ESCAN00009074: init value of variable "cclNmState"
|                     Pet     ESCAN00009098: support for GMLAN multichannel
| 2004-09-09  1.15    Pet     ESCAN00009431: add support for VAG NM C
| 2004-09-21  1.16    Pet     ESCAN00009573: change StateOn handling
|                             ESCAN00009192: missing paging define "DRV_API_CALLBACK_TYPE" in function "ApplCanMsgCondReceived"
|                             ESCAN00009623: prevent additional CAN wake up events
| 2004-10-04  1.17    Pet     ESCAN00009634: missing defines kCclNoCanAvailable and kCclCanAvailable
|                             ESCAN00009686: new core version defines
|                             ESCAN00009693: add support for CAN driver macro CanResetWakeup
|                             ESCAN00009740: inconsistent system request/release state
|                             reject ESCAN00009623
| 2004-10-12  1.18    Pet     ESCAN00009851: add support for Fj16lx
|                             ESCAN00009856: administrative service component handle
|                             ESCAN00009857: NM user data component handle
| 2004-11-02  1.19    Pet     ESCAN00010066: encapsulate CCL software state [only GM]
|                             ESCAN00010069: add support for transceiver type NONE
| 2004-11-10  1.20    Pet     ESCAN00010181: Add support for INM-OSEK (Organ Typ 1)
|                             ESCAN00010071: Transition to network state "prepare to sleep" in spite of pending internal network requests
|                             ESCAN00010087: Transition to network state "sleep" while running communication [only DC]
| 2004-12-10  1.21    Pet     ESCAN00010140: Wrong comment for cclNmRestriction[]. [only DC]
|                             ESCAN00009061: CclGetTrcvErrorPortFct contains NULL pointer
|                             ESCAN00010588: change the visibility of the network request field
|                             ESCAN00010613: Define VGEN_ENABLE_CIOA
| 2005-02-17  1.22    Pet     ESCAN00011217: inconsistencies between DPM and CCL state handling [only DC]
|                             ESCAN00011218: wakeup via CAN bus is not possible
| 2005-02-18  1.23.   Bs      ESCAN00011140: delete double defines
|                             ESCAN00011141: delete (CanChannelHandle) cast in channel parameter defines
|                             ESCAN00011142: change define VGEN_ENABLE_CIOA into CCL_ENABLE_EXTENDED_STATEON
|                             ESCAN00011145: add a hint to an OEM specific header
|                             ESCAN00011151: function CclGetNmState() is not needed anymore
|                             ESCAN00011170: some variables and functions are not necessary if assertions are not activated
|                             ESCAN00011187: change name and type of 'CanECUHandle'
|                             ESCAN00011212: change type of "channel" variable
|                     Pet     ESCAN00010421: advance system shutdown handling
|                             ESCAN00011118: NULL should not be used in the component
|                             ESCAN00011273: During restriction missing EMC wake up event
| 2005-03-07  1.24    Pet     ESCAN00011382: Add define for advanced shutdown handling
|                             ESCAN00011401: Add defines CCL_ENABLE_SYSTEM_STARTUP and CCL_ENABLE_SYSTEM_SHUTDOWN
| 2005-03-14  1.25    Pet     ESCAN00011430: Remove not used variable cclEndIndex
|                     Pet     ESCAN00011453: Wrong VN handling
|                     Pet     ESCAN00011500: Non expected wake up
|                     Pet     ESCAN00011503: Non wake up able through bus event
|                     Pet     ESCAN00011508: Wrong wake up reason
| 2005-04-05  1.26    Pet     ESCAN00011709: network restriction handling for multichannel systems
|                     Pet     ESCAN00011723: Add define for CclGetNmState
| 2005-04-11  1.27    Pet     ESCAN00011832: add support for wake up registration
|                             ESCAN00011833: add support for the component FIM
| 2005-04-20  1.28    Pet     ESCAN00011977: Support wake up for conditional wake up message
| 2005-05-13  1.29    Pet     ESCAN00012254: No wake up is possible during active restricion in special cirrumstances.
| 2005-05-23  1.30    Pet     ESCAN00012399: multichannel support for network initialization
| 2005-06-08  1.31    Pet     ESCAN00012515: Missing variable encapsulation
|                             ESCAN00012538: Add support for power fail handling
|                             ESCAN00012544: Lock global interrupt during sleep mode transition
| 2005-06-21  1.32    Pet     ESCAN00012614: Add support for single channel optimized CCL with a multichannel CAN driver
|                             ESCAN00012627: Missing internal standby event notification during power fail
|                             ESCAN00012638: Wrong CanOnline call
| 2005-07-05  1.33    Pet     ESCAN00012760: Review changes
|                             ESCAN00013027: Missing excplicitly variable initialization
|                             ESCAN00013208: Wrong call of CanInit during Bus Off recovery at the end of power fail
| 2005-08-15  1.34    Pet     ESCAN00012342: Wrong IL-NI PowerOn/Reset handling
|                             ESCAN00013241: Unexpected Tx timeout error (Tx observe) on first message after PowerFail
| 2005-08-27  1.35    Et      ESCAN00013331: GAIO compiler: symbol redefinition (variable: cclInit / function: CclInit)
| 2005-09-07  1.36    Pet     ESCAN00013450: adapt CAN driver API for reference implementation 1.20
| 2005-09-12  1.37    Pet     ESCAN00013229: update wake up timer handling
|                             ESCAN00013534: Wrong state change notification
|                             ESCAN00013232: Wrong CAN Driver state check during system shutdown
|                             ESCAN00013538: Reduce interrupt locking time in the CCL task
|                             ESCAN00013609: Macro CclAssert must be external visible
| 2005-09-27  1.38    Pet     ESCAN00013679: Rename kCclBugFixVersion in to kCclBugfixVersion
| 2005-09-29  1.39    Pet     ESCAN00012038: Additional WakeUp Reason has to be inserted
| 2005-10-26  1.40    Pet     ESCAN00014084: Support new memory qualifier
|                             ESCAN00014141: Advance version check
| 2005-11-10  1.41    Pet     ESCAN00014240: Add support of Nm Mazda
| 2005-11-15  1.42    Pet     ESCAN00014282: change Transceiver interrupt function container call
| 2005-11-16  1.43    Pet     ESCAN00013956: 5s 'alive' timer not used for local wakeup or remote wakeup
| 2005-12-06  2.00    Pet     ESCAN00014618: Support CAN driver code replicated API (only single channel)
|                             ESCAN00014810: Advance the network request handling API
|                             ESCAN00014852: Add support for NPM functionality
|                             ESCAN00014934: Rename CCL version variable kCclBugfixVersion
| 2006-03-24  2.01    Pet     ESCAN00014056: no VN activation
|                             adapt core for GMLAN
|                             ESCAN00015888: Inconsistent interrupt lock 
| 2006-04-21  2.02    Pet     ESCAN00016122: Missing variable encapsulation
| 2006-06-13  2.03    Pet     ESCAN00016600: Remove special handling for PSA
|                             ESCAN00016604: Add support for organ type 2
| 2006-07-06  2.04    Pet     ESCAN00016816: remove dead assignments
|                             ESCAN00016713: ECU is not able to wake up
|                             ESCAN00016726: Missing state change notification function call
|                             ESCAN00016860: CAN channel is not able to wake up
|                             ESCAN00016882: Add support for the old request/release API in newer CCL core versions
| 2006-07-18  2.05    Pet     ESCAN00016726: adapt CCL core for Il NI handling
|                             ESCAN00016969: Remove compiler warning
| 2006-07-25  2.06    Pet     ESCAN00017047: Remove Compiler error
|                             ESCAN00017270: Adapt the NM startup timer
|                             ESCAN00017283: NM (NmOsek-direct) sets the sleep indication bit later then the expected time
|                             ESCAN00017290: Runtime assertion during CclInitPowerOn
| 2006-08-18  2.07    Pet     ESCAN00017326: Support of FBL restart
| 2006-10-06  2.08    Pet     ESCAN00017917: ECU does not transmit CAN messages
|                             adaptions for SYMC
| 2006-11-17  2.09    Pet     ESCAN00018001: change plausibility checks
| 2006-11-27  2.10    Pet     ESCAN00018736: Add minimum CAN channel awake time
| 2007-01-15  2.11    Pet     ESCAN00019022: Adapt CCL_CORE for NM-Osek(indirect) Organ Type 3
| 2007-01-29  2.12    Pet     ESCAN00018893: Missing variable cast
| 2007-02-08  2.13    Pet     ESCAN00018648: ECU does not transmit or receive messages
| 2007-05-30  2.14    Pet     ESCAN00020286: CAN channel stay alive even if no application network request is pending
|                             ESCAN00020765: The CAN channel is not more able to wake up via a CAN bus event
| 2007-06-11  2.15    Pet     ESCAN00020295: CAN channel stay alive even if no application network request is pending
| 2007-06-26  2.16    Dhf     ESCAN00021188: Wrong variable used
| 2007-07-27  2.17    Dhf     ESCAN00021299: Support of ECU Manager added
|                     Dhf     ESCAN00021604: Extended NM initialization and NM activation timer handling added
| 2007-08-13  2.18    Dhf     ESCAN00021870: Wrong function prototypes
| 2007-09-18  2.19    Pet/Dhf ESCAN00019944: Support of limphome supervision added
|                             ESCAN00020011: Adaption of the CCL to support the keep alive timer handling
|                             ESCAN00020012: Support of the Gateway Sleep Wake Up Handling
|                             ESCAN00021083: Emergency Stop handling added 
| 2007-10-10  2.20    Dhf     ESCAN00022602: Brace placement corrected
|                             ESCAN00022665: Encapsulated function CclSetUserRequest()
|                             ESCAN00022666: Summarisation of statements in CclReleaseCommunication()
|                             ESCAN00022670: NM initialization parameter validation adapted
|                             ESCAN00022723: Evaluation of the wake up source adapted
|                             ESCAN00022717: removed unsused variable
|                             ESCAN00022725: changed initialization of controller mode variables
|                             ESCAN00022743: added error code for wrong channel handle and component code for the car wake up manager
|                             ESCAN00022754: Offline switching in CclCanStandby() adapted
| 2007-11-14  2.21    Pet/Dhf ESCAN00022807: some minor changes to be MISRA compliant
|                             ESCAN00022973: Added support of transceiver TLE6152G
|                             ESCAN00022877: Add support for CAN channels which using no NM
|                             ESCAN00015144: Change configuration check for transceiver and CAN wake up settings
| 2007-12-06  2.22    Pet/Dhf ESCAN00023347: adaptions for NM type "None"
|                             ESCAN00023408: added support of NM passive mode
|                             ESCAN00023460: missing declaration of function CclInit()
|                             ESCAN00023464: adapted gateway handling to support multiple configuration
|                             ESCAN00023473: ECU does not change to sleep/stop mode
|                             ESCAN00023454: provided several features for general use
|                             ESCAN00023534: Adapt core for VN handling
|                             ESCAN00023724: added support of CAN driver reference implementation RI 1.2
| 2007-12-06  2.23    Pet     ESCAN00024231: Minor changes to support different INM Ecu types
| 2008-04-01  2.24    Dhf     ESCAN00025791: general adaptions
|                             ESCAN00026051: emergency stop handling made channel specific
|                             ESCAN00026013: Added check for number of channels
|                             ESCAN00026123: no transmission of CAN messages possible
|                             ESCAN00026161: bit operations adapted to be MISRA compliant
| 2008-04-25  2.25    Dhf     ESCAN00026414: encapsulation of braces
|                             ESCAN00026441: VN handling adapted
| 2008-04-29  2.25.01 Dhf     ESCAN00026476: minor changes for code filtering
| 2008-05-08  2.26    Dhf     ESCAN00026778: compile error when using an indexed CAN driver
|                             ESCAN00026785: added support for NM coordinator
|                             ESCAN00026780: compile error when an indexed NM Osek is used
|                             ESCAN00027176: MISRA compliance
| 2008-06-06  2.27    Dhf     ESCAN00027460: added support of ASR 3.0
| 2008-06-20  2.28    Pet     ESCAN00018830: Missing DPM state change notification during NM startup
|                             ESCAN00027769: Add compatibility to CANgen and DBKOMgen
| 2008-07-07  2.29    Dhf     ESCAN00028150: added definition of CAN driver API macros
| 2008-07-08  2.30    Dhf     ESCAN00028203: CAN channels do not start up due to external wake up events
| 2008-08-12  2.31    Dhf     ESCAN00029183: replace V_BUSTYPE_LIN switch with CCL_BUSTYPE_LIN
|                     Pet     ESCAN00029102: Support post build configurations which are mapped to different memory sections
| 2008-09-05  2.32    Dhf     ESCAN00029743: compile errors when multiple identity is enabled
| 2008-09-11  2.33    Pet     ESCAN00029931: Add support for complier and platform independent implementation of the ASR configuration pointer
| 2008-10-23  2.34    Dhf     ESCAN00030842: added delay for network related diagnostic
| 2008-12-03  2.35    Dhf     ESCAN00031376: added support of NM Honda
|                             ESCAN00031836: added else-path to avoid misra warning
| 2009-01-21  2.35.01 Dhf     ESCAN00027812: Ecu shutdown during running communication
| 2009-02-06  2.36    Dhf     ESCAN00032891: compiler error due to undefined variables
|                             ESCAN00032904: Add support of new memory qualifier V_MEMROMx_CFG
| 2009-04-02  2.37    Dhf     ESCAN00032540: added support of OEM GAC
|                             ESCAN00034328: BETA version - no series production allowed
| 2009-04-08  2.38    Dhf     ESCAN00034471: compiler warning
|                             ESCAN00034501: adapted wait and resume handling
|                             ESCAN00034653: some minor improvements
|                             ESCAN00034741: removed error directive for state notification functions
| 2009-08-25  2.39    Dhf     ESCAN00037336: added support of NM Toyota
| 2009-09-03  2.40    Dhf     ESCAN00037499: no changes in this file
|                             ESCAN00037554: no changes in this file
|                             ESCAN00037646: added support of OEM Baic
|                             ESCAN00037703: no changes in this file
|                             ESCAN00037697: no changes in this file
| 2009-12-03  2.41    Dhf     ESCAN00039551: added component ID for new NM component
| 2010-01-07  2.42    Dhf     ESCAN00039850: no changes
| 2010-02-18  2.43    Dhf     ESCAN00040967: adapted CclInitPowerOn/CclInit
|                             ESCAN00040721: no changes
| 2010-06-15  2.44    Dhf     ESCAN00043411: no changes
|                             ESCAN00043412: no changes
|                             ESCAN00043536: no changes
| 2010-07-20  2.45    Dhf     ESCAN00044173: no changes
|                             ESCAN00044298: no changes
| 2010-08-05  2.46    Dhf     ESCAN00028369: added NPM data access
|                             ESCAN00028484: CCL does not accept communication requests
|                             ESCAN00028492: no communication request possible
|                             ESCAN00028799: NPM message timeout notification for wrong channel
|                             ESCAN00044475: no changes
| 2010-08-16  2.47    Dhf     ESCAN00044481: no changes
|                             ESCAN00037523: no changes
|                             ESCAN00025339: no changes
|                             ESCAN00044778: no changes
|                             ESCAN00044782: no changes
|****************************************************************************/

/****************************************************************************/
/* one further header (the OEM specific one) is included                    */
/* at the end of this core header file                                      */
/****************************************************************************/

/* check multiple inclusion */
#ifndef CCL_INC_H
#define CCL_INC_H


/***************************************************************************/ 
/* Include files                                                           */ 
/***************************************************************************/ 
/* CCL configuration  */
#include "ccl_cfg.h"
#include "v_cfg.h"

#if defined(VGEN_ENABLE_NMHIGH)
#include "Nmh_can.h"
#endif


/***************************************************************************/ 
/* Version  (core version)  (abcd: Main version ab Sub Version cd )        */ 
/***************************************************************************/ 
/* ##V_CFG_MANAGEMENT ##CQProject : Ccl__core CQComponent : Implementation */
#define CCL__CORE_VERSION          0x0247
#define CCL__CORE_RELEASE_VERSION  0x00

/***************************************************************************/
/* Version Defines to stay compatiple with older versions                  */
/***************************************************************************/
#define CCL_CORE_VERSION          CCL__CORE_VERSION
#define CCL_CORE_BUGFIX_VERSION   CCL__CORE_RELEASE_VERSION
#define kCclBugfixVersion         kCclReleaseVersion


/***************************************************************************/ 
/* Defines                                                                 */ 
/***************************************************************************/
#if defined(kCclNrOfSystemChannels)
#else
#  if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#    define kCclNrOfSystemChannels 2
#  endif
#endif

#if defined( CCL_ENABLE_DEBUG)
#  if ( kCclNrOfSystemChannels > 1 )
#    if ( kCclNrOfChannels > 1 )
#      define CclAssert(p,e)  {if(!(p)){CclFatalError(channel, (e), (vuint16)(__LINE__),kModuleCcl);}}
#    else
#        define CclAssert(p,e)  {if(!(p)){CclFatalError((CanChannelHandle)kCclChannelIndex, (e), (vuint16)(__LINE__),kModuleCcl);}}
#    endif
#  else
#    if (kCclNrOfChannels > 1)
/* non-indexed systems are not supported by the CCL */
#    else
#      define CclAssert(p,e)  {if(!(p)){CclFatalError(0, (e), (vuint16)(__LINE__),kModuleCcl);}}
#    endif
#  endif
#else
#  define CclAssert(p,e)
#endif

/* defines for Paging-mode */
#ifndef CCL_API_CALL_TYPE
# define CCL_API_CALL_TYPE
#endif
#ifndef CCL_API_CALLBACK_TYPE
# define CCL_API_CALLBACK_TYPE
#endif
#ifndef CCL_INTERNAL_CALL_TYPE
# define CCL_INTERNAL_CALL_TYPE
#endif

/* downwards compatible defines */
#if( CCL_DLL_VERSION < 0x0106 )
#  define cclNetRequestField   cclIntNetState
#  define kCclNrOfNetworks     kCclNrOfNmNetworks
#  define cclStateCom          cclComSwState

#  define kCclComOn                kCclComSwOn
#  define kCclComOff               kCclComSwOff

#  if defined( CCL_USE_REQUEST_SETCOM_FCT )
#    define CCL_USE_REQUEST_SETINTCOM_FCT CCL_USE_REQUEST_SETCOM_FCT
#    define CCL_USE_REQUEST_SETEXTCOM_FCT CCL_USE_REQUEST_SETCOM_FCT
#  endif

#  if(kCclNrOfChannels > 1)
#    define CclInitTransFctTbl    CclInitTrcvFctTbl
#    define CclWakeUpTransFctTbl  CclWakeUpTrcvFctTbl
#    define CclSleepTransFctTbl   CclSleepTrcvFctTbl
#    define CclComRelFctTbl       CclClearComReqFctTbl
#    define CclExtCanComReqFctTbl CclSetComReqFctTbl
#    define CclIntComReqFctTbl    CclSetComReqFctTbl
#  else
#    define CclInitTransFct      CclInitTrcvFct
#    define CclWakeUpTransFct    CclWakeUpTrcvFct
#    define CclSleepTransFct     CclSleepTrcvFct
#    define CclComRelFct         CclClearComReqFct
#    define CclExtCanComReqFct   CclSetComReqFct
#    define CclIntComReqFct      CclSetComReqFct
#  endif
#endif

#if defined( VGEN_GENY )
/* enable commuincation request handling API */
#  if( CCL__COREDLL_VERSION >= 0x0295u )
#    define CCL_ENABLE_COM_REQ_HANDLING_API
#  endif
#endif

/* ESCAN00011723 */
#define CclGetNmState              CclGetChannelState

/* downwards compatible defines */
#define kModuleCanDrv            kComponentCanDrv
#define kModuleLinDrv            kComponentLinDrv
#define kModuleIl                kComponentIl
#define kModuleDbk               kComponentDbk
#define kModuleMm                kComponentMm
#define kModuleTp                kComponentTp
#define kModuleNm                kComponentNm
#define kModuleNmPt              kComponentNmPt
#define kModuleSm                kComponentSm
#define kModuleNmVagC            kComponentNmVagC
#define kModuleDiagx             kComponentDiagx
#define kModuleCANdesc           kComponentCANdesc
#define kModuleCcl               kComponentCcl

#define kCclNmStateSleep         kCclStateSleep
#define kCclNmStateGoToSleep     kCclStateGoToSleep
#define kCclNmStateActive        kCclStateActive
#define kCclNmPowerFail          kCclPowerFail


/* channel parameter and index replacement */ 
#if ( kCclNrOfSystemChannels > 1 )
#  if( kCclNrOfChannels > 1 )
#    define CCL_CHANNEL_CCLPARA_ONLY       channel
#    define CCL_CHANNEL_CCLPARA_FIRST      channel,
#    define CCL_CHANNEL_CCLTYPE_ONLY       CanChannelHandle channel
#    define CCL_CHANNEL_CCLTYPE_FIRST      CanChannelHandle channel,
#    define CCL_CHANNEL_CCLINDEX           (vuint8)channel
#    define CCL_CHANNEL_CANPARA_ONLY       channel
#    define CCL_CHANNEL_CCLHANDLE_FIRST   (vuint8)channel,
#  else
#    define CCL_CHANNEL_CCLPARA_ONLY
#    define CCL_CHANNEL_CCLPARA_FIRST
#    define CCL_CHANNEL_CCLTYPE_ONLY       void
#    define CCL_CHANNEL_CCLTYPE_FIRST
#    define CCL_CHANNEL_CCLINDEX           (vuint8)0
#    define CCL_CHANNEL_CANPARA_ONLY       (CanChannelHandle)kCclChannelIndex
#    define CCL_CHANNEL_CCLHANDLE_FIRST
#  endif
#else
#  define CCL_CHANNEL_CCLPARA_ONLY
#  define CCL_CHANNEL_CCLPARA_FIRST
#  define CCL_CHANNEL_CCLTYPE_ONLY       void
#  define CCL_CHANNEL_CCLTYPE_FIRST
#  define CCL_CHANNEL_CCLINDEX           (vuint8)0
/* ESCAN00026778 */
#  if defined C_ENABLE_MULTICHANNEL_API
#    define CCL_CHANNEL_CANPARA_ONLY     (CanChannelHandle)0
#  else
#    define CCL_CHANNEL_CANPARA_ONLY
#  endif
#  define CCL_CHANNEL_CCLHANDLE_FIRST
#endif

/* network parameter and index replacement */
#if ( kCclNrOfSystemChannels > 1 )
#    if(kCclNrOfChannels > 1)
#      define CCL_NET_CCLPARA_ONLY         channel
#      define CCL_NET_CCLPARA_FIRST        channel,
#      define CCL_NET_CCLINDEX             channel
#        define CCL_NET_CCLTYPE_ONLY         CanChannelHandle channel
#        define CCL_NET_CCLTYPE_FIRST        CanChannelHandle channel,
#    else
#      define CCL_NET_CCLPARA_ONLY
#      define CCL_NET_CCLPARA_FIRST
#      define CCL_NET_CCLTYPE_ONLY           void
#      define CCL_NET_CCLTYPE_FIRST
#      define CCL_NET_CCLINDEX               0
#    endif
#else
#    define CCL_NET_CCLPARA_ONLY
#    define CCL_NET_CCLPARA_FIRST
#    define CCL_NET_CCLTYPE_ONLY           void
#    define CCL_NET_CCLTYPE_FIRST
#    define CCL_NET_CCLINDEX               0
#endif

/* ECU handle replacement */
#if defined(CCL_ENABLE_MULTIPLE_NODES) 
#  if defined(CCL_ENABLE_CANBEDDED_HANDLING)
#    define CCL_ECUS_NODESTYPE_ONLY        cclECUHandle  CanEcuNr
#      if defined(CCL_ENABLE_EXTENDED_NMINIT)  /* ESCAN00021604 */
#        define CCL_ECUS_NODESTYPE_FIRST       cclECUHandle  CanEcuNr,  
#      else
#        define CCL_ECUS_NODESTYPE_FIRST       cclECUHandle  CanEcuNr  
#      endif
#    define CCL_ECUS_NODESPARA_ONLY        (vuint8)CanEcuNr
#  else
#   define CCL_ECUS_NODESTYPE_ONLY         void
#     if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
#       define CCL_ECUS_NODESTYPE_FIRST 
#     else
#       define CCL_ECUS_NODESTYPE_FIRST   void
#     endif
#   define CCL_ECUS_NODESPARA_ONLY
#  endif
#else
#  if defined(CCL_ENABLE_MULTIPLE_CONFIG)
#    if defined(CCL_ENABLE_CANBEDDED_HANDLING)
#     define CCL_ECUS_NODESTYPE_ONLY        vuint8  IdentityNr
#     define CCL_ECUS_NODESTYPE_FIRST       vuint8  IdentityNr,
#     define CCL_ECUS_NODESPARA_ONLY        IdentityNr
#    else
#      define CCL_ECUS_NODESTYPE_ONLY        void
#      define CCL_ECUS_NODESTYPE_FIRST       
#      define CCL_ECUS_NODESPARA_ONLY
#    endif
#  else
#    define CCL_ECUS_NODESTYPE_ONLY        void
#    define CCL_ECUS_NODESTYPE_FIRST
#    define CCL_ECUS_NODESPARA_ONLY
#  endif
#endif


#if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
#  define CCL_NM_INITPOINTER_TYPE      const tCclNmInitParaListType* cclNmInitPointer
#  define CCL_NM_INITPOINTER_PARA      cclNmInitPointer
#else
#  define CCL_NM_INITPOINTER_TYPE      
#  define CCL_NM_INITPOINTER_PARA      
#endif

/* multiple configuration replacement */
#  define CCL_SET_MULTIPLE_CFG_HANDLE(i)



/* CCL states (active, go to sleep and sleep) */
#define kCclStateSleep                0x00    /* CCL state: sleep */
#define kCclStateWaitBusSleep         0x01    /* CCL state: wait bus sleep */
#define kCclStateGoToSleep            0x02    /* CCL state: go to sleep */
#define kCclStateActive               0x03    /* CCL state: active */
#define kCclPowerFail                 0x04    /* CCL state: power fail active */


#define kCclComHwDisabled               0x00    /* HW communication state: disabled */
#define kCclComHwEnabled                0x01    /* HW communication state: enabled */

#define kCclComSwOff                    0x00    /* SW communication state: off */
#define kCclComSwOn                     0x01    /* SW communication state: on */


#define kCclBusOn                        0x00     /* CAN hardware and transceiver are active */
#define kCclBusOff                       0x01     /* CAN hardware and transceiver are inactive */

#define kCclNoCanAvailable                0x00    /* CAN HW is not stable */
#define kCclCanAvailable                  0x01    /* CAN HW is stable */

#define kCclTrcvWakeIntPending    0x00
#define kCclTrcvWakeIntNoPending  0x01

#define CCL_NO_CHANNEL_INFO_AVAILABLE   0xFF

#define kCclNoErrPort                   0xFF
#define kCclTrcvErrPinActive            0x00

#define kCclNoRepeatCanSleep            0x00     /* no repeat of the function CanSleep */
#define kCclRepeatCanSleep              0x01     /* repeat the CanSleep function */

#define kCclSystemSpecificInit          0x00
#define kCclChannelSpecificInit         0x01

#define kCclNoNetRequest                0x00
#define kCclNetRequest                  0x01

#define kCclComReqNotPending               0x00
#define kCclComReqPending                  0x01

#define kCclNoWakeUpAble                0x00
#define kCclChWithNm                    0x00

#define kCclReqOk                       0x00
#define kCclReqFailed                   0xFF



#if defined(CCL_ENABLE_TRCV_PORT_INT)
#  define kCclDisableWakeUpInt          0x00     /* transceiver port interrupt is disabled */
#  define kCclEnableWakeUpInt           0x00     /* transceiver port interrupt is enabled */
#endif








#define kCclNoIlNiChannel             0x00

#define kCclOk                          0x01
#define kCclFailed                      0x00


#if defined(CCL_ENABLE_NPM_SUPPORT)
#  define kCclNpmDirectAddressingOn        0x01
#  define kCclNpmDirectAddressingOff       0x00

#  define kCclNpmPreventWakeUpOn           (vuint8)0x02
#  define kCclNpmPreventWakeUpOff          (vuint8)0xFD
#  define kCclNpmForceShutdownOn           (vuint8)0x04
#  define kCclNpmForceShutdownOff          (vuint8)0xFB

#  define kCclNpmPreventWakeUpValid        (vuint8)0x20
#  define kCclNpmPreventWakeUpInvalid      (vuint8)0xDF
#  define kCclNpmForceShutdownValid        (vuint8)0x40
#  define kCclNpmForceShutdownInvalid      (vuint8)0xBF
#  define kCclNpmFsdTriggered              (vuint8)0x02
#  define kCclNpmPwuTriggered              (vuint8)0x01
#  define kCclNpmFsdNotTriggered           (vuint8)0xFD
#  define kCclNpmPwuNotTriggered           (vuint8)0xFE 

#  define kCclNpmIgnitionOn                0x00
#  define kCclNpmIgnitionOff               0x01

#  define kCclNpmMessageTimerStopped       0x00
#  define kCclNpmMessageTimerExpired       0x00
#  define kCclNpmMessageTimeoutOccur       (vuint8)0x10
#  define kCclNpmMessageTimeoutClear       (vuint8)0xEF
#  define kCclNpmMessageReceived           (vuint8)0x01
#  define kCclNpmMessageReceivedClear      (vuint8)0xFE

#  define kCclNpmPwuFsRestrictionOn        0x00    /* prevent wake up, force shutdown restriction: on */
#  define kCclNpmPwuFsRestrictionOff       0x01    /* prevent wake up, force shutdown restriction: off */

#  define kCclNpmOn                        0x00    /* NPM functionality is enabled */
#  define kCclNpmOff                       0x01    /* NPM functionality is disabled */
#endif

#if defined(CCL_ENABLE_NMSTARTUP_TIMER)
#  define kCclNmStartupTimerStopped     0x00
#  define kCclNmStartupTimerExpired     0x00
#endif





#if defined (NM_TYPE_NMHIGH)
#  if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
#    define kCclNmhInitValue           0xFF
#  endif
#endif

#if defined(CCL_ENABLE_POSRES_FBL)
#  define kCclSendPosResp               0x00    /* send a diagnostic positive response message */
#  define kCclSendNoPosResp             0x01    /* send no diagnostic positive response message */
#endif





#define kCclTrcvStateChangePerformed       0x01
#define kCclTrcvStateChangeNotPerformed    0x00


/***************************************************************************/

#define kCclBusOffRecActive        0x01
#define kCclBusOffRecNotActive     0x00


#define kCclEnable    0x01
#define kCclDisable   0x00


/***************************************************************************/ 
/* Default switches                                                        */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* Memory qualifier                                                        */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* return values                                                           */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* Component Identifiers                                                   */ 
/***************************************************************************/ 
/* DRV component codes */ 
#define kComponentCanDrv                   0x01  /* CAN driver */
#define kComponentLinDrv                   0x02  /* LIN driver */

/* IL component codes */
#define kComponentIl                       0x10  /* Vector Interaction Layer */
#define kComponentDbk                      0x11  /* DBKOM Layer */
#define kComponentMm                       0x12  /* Message Manager */

/* NM component codes */
#define kComponentNm                       0x20  /* NM OSEK (direct)*/
#define kComponentNmPt                     0x21  /* NM Powertrain */
#define kComponentSm                       0x22  /* Station Manager for NM-OSEK (indirect) */
#define kComponentNmVagC                   0x23  /* NM VagC */
#define kComponentNmUData                  0x24  /* NM User Data */
#define kComponentNmHigh                   0x25  /* NM High */
#define kComponentNmBasic                  0x26  /* NM Powertrain Basic */
#define kComponentNmMazda                  0x27  /* NM Powertrain Mazda */
#define kComponentNmCbdWrp                 0x28  /* NM Autosar Wrapper */
#define kComponentNmAsrGeneric             0x29  /* NM Autosar Generic */
#define kComponentNmAsrCan                 0x2a  /* Nm Autosar CAN */
#define kComponentCwm                      0x2b  /* Car wake up manager */ /* ESCAN00022743 */
#define kComponentIndirectNm               0x2c  /* NM OSEK (indirect) */
#define kComponentNmHonda                  0x2d  /* NM HONDA */
#define kComponentNmToyota                 0x2e  /* NM TOYOTA */
#define kComponentNmFiat                   0x2f  /* NM FIAT */

/* TP component codes */
#define kComponentTp                       0x30  /* ISO TP */

/* DIAG component codes */
#define kComponentDiagx                    0x40  /* Diagnose: DiagX */
#define kComponentCANdesc                  0x41  /* Diagnose: CANdesc (Basic, UDS etc) */

/* CCL component codes */
#define kComponentCcl                      0x50  /* CCL */

/* DPM component code */
#define kComponentDpm                      0x60  /* DPM */

/* GW component code */
#define kComponentSigGW                    0x70  /* Signal Gateway */
#define kComponentAs                       0x71  /* Administrative Services */


/***************************************************************************/ 
/* CCL Error Codes                                                         */ 
/***************************************************************************/
#define kAssertCANandTRCVINT            0x00
#define kAssertNotSleepAndTRCVINTactive 0x01

#define kIllegalWakeUpInterrupt         0x03
#define kWrongReturnValue               0x04

#define kExtAndIntWakeUp                0x05

#define kCclErrEMCTimerHdlgFailed       0x06

#define kCclErrWakeFailed               0x07

#define kCclErrInvalidComHandle         0x08

#define kCclErrInvalidNmHInitValue      0x09

#define kCclErrWrongCclState            0x0A

#define kCclErrInvalidNmMode            0x0B

#define kCclErrNullPointer              0x10

#define kCclErrWrongWakeUpChannel       0x11

#define kCclWrongChannelHandle          0x12    /* ESCAN00022743 */

#define kCclErrWrongStateTransition     0x13

#define kCclErrComReqFailed             0x14   /* CCL communiation request is not acepted by the NM, not allowed */



/***************************************************************************/ 
/* macros                                                                  */ 
/***************************************************************************/ 
#if defined(CCL_ENABLE_NPM_SUPPORT)
/* macros to analyse the NPM state */
#  define NpmStateIsPreventWakeUp(state)            ((((state) & kCclNpmPreventWakeUpOn) == kCclNpmPreventWakeUpOn) ? 1 : 0)
#  define NpmStateIsForceShutdown(state)            ((((state) & kCclNpmForceShutdownOn) == kCclNpmForceShutdownOn) ? 1 : 0)
#  define NpmMessageIsTimeout(state)                ((((state) & kCclNpmMessageTimeoutOccur) == kCclNpmMessageTimeoutOccur) ? 1 : 0)
#endif


/***************************************************************************/ 
/* compatibility defines                                                   */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* data types                                                              */ 
/***************************************************************************/
#if defined(CCL_ENABLE_MULTIPLE_NODES)
typedef vuint8 cclECUHandle; /* ECU handle */  /* ESCAN00011187 */
#endif




#if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
typedef enum
{
  kCclNmInitSleep,
  kCclNmInitNormal
}tCclNmInitParaType;

typedef struct CclNmInitParaList
{
  tCclNmInitParaType cclNmInit_0;
#if (kCclNrOfChannels > 1)
  tCclNmInitParaType cclNmInit_1;
#endif
#if (kCclNrOfChannels > 2)
  tCclNmInitParaType cclNmInit_2;
#endif
#if (kCclNrOfChannels > 3)
  tCclNmInitParaType cclNmInit_3;
#endif
#if (kCclNrOfChannels > 4)
  tCclNmInitParaType cclNmInit_4;
#endif
#if (kCclNrOfChannels > 5)
  tCclNmInitParaType cclNmInit_5;
#endif
#if (kCclNrOfChannels > 6)
  tCclNmInitParaType cclNmInit_6;
#endif
#if (kCclNrOfChannels > 7)
  tCclNmInitParaType cclNmInit_7;
#endif
}tCclNmInitParaListType;
#endif


/* ESCAN00023724 */
#  if( C_VERSION_REF_IMPLEMENTATION < 0x130 )
typedef vuint8 CanChannelHandle;
#  endif

/***************************************************************************/ 
/* internal function prototypes                                            */ 
/***************************************************************************/ 
#if defined(CCL_ENABLE_ERROR_HOOK)
extern void CCL_API_CALL_TYPE CclFatalError(CanChannelHandle ChannelNumber, vuint16 ErrorCode, vuint16 ErrorLine, vuint8 ComponentID);
#endif

extern void CCL_API_CALL_TYPE CclCanNormal(CCL_CHANNEL_CCLTYPE_ONLY);
extern void CCL_API_CALL_TYPE CclCanStandby(CCL_CHANNEL_CCLTYPE_ONLY);

/***************************************************************************/ 
/* external function prototypes                                            */
/***************************************************************************/



#if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
extern void CCL_API_CALL_TYPE CclInitPowerOn(CCL_ECUS_NODESTYPE_FIRST CCL_NM_INITPOINTER_TYPE);
extern void CCL_API_CALL_TYPE CclInit(CCL_CHANNEL_CCLTYPE_FIRST CCL_NM_INITPOINTER_TYPE);
#else
extern void CCL_API_CALL_TYPE CclInitPowerOn(CCL_ECUS_NODESTYPE_ONLY);
extern void CCL_API_CALL_TYPE CclInit(CCL_CHANNEL_CCLTYPE_ONLY);
#endif

#if defined(CCL_ENABLE_SYSTEM_STARTUP)
extern void CCL_API_CALL_TYPE CclSystemStartup(void);
#endif

#if(defined( CCL_ENABLE_EXTERNAL_REQUEST ) || \
    defined( CCL_ENABLE_INTERNAL_REQUEST ))
extern void CCL_API_CALL_TYPE CclTask(void);
#endif

#if defined(CCL_ENABLE_SYSTEM_SHUTDOWN)
extern void CCL_API_CALL_TYPE CclSystemShutdown(void);
#endif

#if defined( CCL_ENABLE_INTERNAL_REQUEST )
#  if defined(CCL_ENABLE_COM_REQ_HANDLING_API)
extern vuint8 CCL_API_CALL_TYPE CclRequestCommunication(vuint8 cclComHandle);
extern void CCL_API_CALL_TYPE CclReleaseCommunication(vuint8 cclComHandle);
#  endif


#  if defined( CCL_ENABLE_COM_REQ_HANDLING_API )
extern vuint8 CCL_API_CALL_TYPE CclComRequestPending(CCL_CHANNEL_CCLTYPE_ONLY);
extern vuint8 CCL_API_CALL_TYPE CclGetComHandleState(vuint8 cclComHandle);
#  endif
#endif

extern void CCL_API_CALL_TYPE CclEnableCommunication(CCL_CHANNEL_CCLTYPE_ONLY);
extern void CCL_API_CALL_TYPE CclDisableCommunication(CCL_CHANNEL_CCLTYPE_ONLY);

extern vuint8 CCL_API_CALL_TYPE CclGetChannelState(CCL_CHANNEL_CCLTYPE_ONLY);

#if defined(CCL_ENABLE_TRCV_PORT_INT)
#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
extern void CCL_API_CALL_TYPE CclCanWakeUpInt(CCL_CHANNEL_CCLTYPE_ONLY);
#  endif
#endif


#if defined( CCL_ENABLE_ERROR_PIN )
extern vuint8 CCL_API_CALL_TYPE CclGetErrorPort(CCL_CHANNEL_CCLTYPE_ONLY);
#endif




#if defined (CCL_ENABLE_TRCV_TYPE_TLE6251G) /* ESCAN00022973 */
extern vuint8 CclSetTrcvRxOnlyMode(CCL_CHANNEL_CCLTYPE_ONLY);
extern vuint8 CclLeaveTrcvRxOnlyMode(CCL_CHANNEL_CCLTYPE_ONLY);
#endif

/***************************************************************************/ 
/* External Declarations                                                   */ 
/***************************************************************************/ 

#if defined( CCL_ENABLE_ERROR_HOOK)
V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 cclChannelNumber;
V_MEMRAM0 extern V_MEMRAM1 vuint16 V_MEMRAM2 cclErrorCode;
V_MEMRAM0 extern V_MEMRAM1 vuint16 V_MEMRAM2 cclErrorLine;
V_MEMRAM0 extern V_MEMRAM1 vuint16 V_MEMRAM2 cclComponentID;
#endif



#if defined( CCL_ENABLE_SW_COM_STATE )
V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 cclComSwState[kCclNrOfChannels];
#endif


#if defined(CCL_ENABLE_INTERNAL_REQUEST)
V_MEMRAM0 extern volatile V_MEMRAM1 vuint8 V_MEMRAM2 cclIntNetState[kCclNetReqTableSize];
#endif



#if defined(CCL_ENABLE_NPM_SUPPORT)
#  if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
V_MEMRAM0 extern volatile V_MEMRAM1 vuint8 V_MEMRAM2 cclNpmMsgDataTmp[kCclNrOfChannels];
#  endif
#endif

#if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
V_MEMRAM0 extern V_MEMRAM1 tCclNmInitParaListType V_MEMRAM2 cclNmInitParaList;
#endif





V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 cclNmState[kCclNrOfChannels];

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kCclMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kCclSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kCclReleaseVersion;

/***************************************************************************/ 
/* Callback functions                                                      */ 
/***************************************************************************/ 
extern vuint8 CCL_API_CALLBACK_TYPE ApplCclCanStandby(CCL_CHANNEL_CCLTYPE_FIRST vuint8 sleepResult);

#if defined(CCL_ENABLE_NPM_SUPPORT)
extern void CCL_API_CALLBACK_TYPE ApplCclNpmMsgTimeout(CCL_CHANNEL_CCLTYPE_ONLY);
#  if defined(CCL_ENABLE_EEPROM_PREVENT_WAKEUP)
extern void CCL_API_CALLBACK_TYPE ApplCclNpmWritePwuStateToNVRAM(CCL_CHANNEL_CCLTYPE_FIRST vuint8 PwuState);
extern vuint8 CCL_API_CALLBACK_TYPE ApplCclNpmReadPwuStateFromNVRAM(CCL_CHANNEL_CCLTYPE_ONLY);
#  endif
#  if defined(CCL_ENABLE_PREVENT_WAKEUP)
extern void CCL_API_CALLBACK_TYPE ApplCclNpmPreventWakeup(CCL_CHANNEL_CCLTYPE_FIRST vuint8 PwuState);
#  endif
#  if defined(CCL_ENABLE_FORCE_SHUTDOWN)
extern void CCL_API_CALLBACK_TYPE ApplCclNpmForceShutdown(CCL_CHANNEL_CCLTYPE_FIRST vuint8 FSDState);
#  endif
#endif


#if defined(CCL_ENABLE_ERROR_HOOK)
extern void CCL_API_CALLBACK_TYPE ApplCclFatalError(void);
#endif










/***************************************************************************/ 
/* OEM specific                                                            */ 
/***************************************************************************/ 

/*****************************************************************************
| Project Name: CCL Communication Control Layer
| File Name: 
|
|  Description: CCL OEM for PAG
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2000-2008 by Vector Informatik GmbH.      All rights reserved.
|
|               This software is copyright protected and proprietary 
|               to Vector Informatik GmbH. Vector Informatik GmbH 
|               grants to you only those rights as set out in the 
|               license conditions. All other rights remain with 
|               Vector Informatik GmbH.
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Pet          Thomas Petrus             Vector Informatik GmbH
| Dhf          Daniel Hof                Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Ver      Author  Description
| ---------   -------  ------  --------------------------------------------------
| 2005-11-22  1.00     Pet     intitial version
| 2006-07-28  1.01     Pet     change core version to V2.07
|                              ESCAN00017327: Support of FBL restart
|                              ESCAN00017117: Add support for Nm Powertrain Vag
| 2007-10-10  1.02     Pet     change core version to V2.20
|                      Dhf     ESCAN00022699: Added definition of function ApplCwmFatalError()
| 2007-11-19  1.03     Pet     change core version to V2.20.01
| 2008-02-28  1.04     Dhf     change core version to V2.20.02
|                              ESCAN00024966: Added support of multiple NM High channel configurations
| 2008-03-13  1.04.01  Dhf     ESCAN00025338: ECU does not transmit/receive application messages
| 2008-07-14  1.05     Dhf     ESCAN00028368: added NPM data access
|                              change core version to V2.20.04
| 2010-08-14  1.06     Dhf     change core version to V2.46.00
|                              ESCAN00044473: no changes here
| 2010-08-16  1.07     Dhf     change core version to V2.47.00
|                              ESCAN00035478: no changes here
|                              ESCAN00044482: no changes here
|                              ESCAN00044770: no changes here
|                              ESCAN00044783: no changes here
|****************************************************************************/


/***************************************************************************/ 
/* Version defines                                                       */ 
/***************************************************************************/ 
/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Pag CQComponent : Implementation */
#define CCL_PAG_VERSION            0x0107
#define CCL_PAG_RELEASE_VERSION    0x00


/***************************************************************************/ 
/* external function prototypes                                            */
/***************************************************************************/
#if defined(CCL_ENABLE_POSRES_FBL)
#  if defined ( CCL_ENABLE_MULTIPLE_CONFIG )
extern void CclSendPosRespFBL( CCL_CHANNEL_CCLTYPE_FIRST t_descFblPosRespType posRespSId );
#  else
extern void CclSendPosRespFBL( t_descFblPosRespType posRespSId );
#  endif
#endif

#if defined(CCL_ENABLE_NPM_SUPPORT)
extern void CCL_API_CALL_TYPE CclNpmSetIgnitionState(vuint8 state);
extern vuint8 CCL_API_CALL_TYPE CclNpmGetState(CCL_CHANNEL_CCLTYPE_ONLY);
extern void CCL_API_CALL_TYPE CclNpmEnableNpmHandling(void);
extern void CCL_API_CALL_TYPE CclNpmDisableNpmHandling(void);
#endif
extern vuint8 CCL_API_CALL_TYPE CclNpmSnapshot(CCL_CHANNEL_CCLTYPE_FIRST vuint8* diagData, vuint16* didLen);


#endif /* ifndef CCL_INC_H */
/************************** end of file ***************************************/ 
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
