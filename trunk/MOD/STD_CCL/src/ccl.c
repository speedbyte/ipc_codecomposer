/*****************************************************************************
| Project Name: CCL Communication Control Layer
| File Name: 
|
|  Description: CCL OEM for PAG
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
|                      Dhf     ESCAN00022749: Added dummy assignment in ApplNmhBusOffStart()
| 2007-11-19  1.03     Pet     change core version to V2.20.01
| 2008-02-28  1.04     Dhf     change core version to V2.20.02
|                              ESCAN00024966: Added support of multiple NM High channel configurations
|                              ESCAN00024964: No positive response on initialization
| 2008-03-13  1.04.01  Dhf     ESCAN00025338: ECU does not transmit/receive application messages
| 2008-07-14  1.05     Dhf     ESCAN00028368: added NPM data access
|                              change core version to V2.20.04
| 2010-08-14  1.06     Dhf     change core version to V2.46.00
|                              ESCAN00044473: changed some precompile encapsulations
| 2010-08-16  1.07     Dhf     change core version to V2.47.00
|                              ESCAN00035478: adapted ApplNmhBusOffStart() and ApplNmhFatalError()
|                              ESCAN00044482: resolved
|                              ESCAN00044770: adapted CclNpmSnapshot() to remove compile errors
|                              ESCAN00044783: removed ";" after CclAssert()
|****************************************************************************/


/***************************************************************************/
/* CORE                                                                    */
/***************************************************************************/



/*****************************************************************************
|  File Name: CCL.C
|
|  Description: Communication Control Layer (CORE) 
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
| ---------   ----    ------  ------------------------------------------------
| 31.05.02    1.00    Et/Zw   Initial version
| 02.12.02            Pet     add support for psa
| 2002-12-03  1.01    Pet     add support for Micronas CEVF
| 2003-02-04  1.02    Pet     ESCAN00004878: add support for GMLAN (single receive channel)
| 2003-02-06          Pet     ESCAN00004881: add support for NM JUNIOR
|                     Pet     ESCAN00004886: variable task container
|                     Pet     ESCAN00005256: add internal version controll
|                     Pet     ESCAN00005188: add support for CANdesc
| 2003-03-10          Pet     ESCAN00005255: add support for DBAG OSEK
| 2003-03-24  1.03    Pet     ESCAN00005195: wrong plausibility check for GMLAN
| 2003-04-01  1.04    Pet     ESCAN00005345: separation CCL into core files and OEM extension files
| 2003-06-05  1.05    Pet     CCL DLL version change
| 2003-06-16  1.05.01 Pet     review changes
| 2003-07-25  1.05.02 Pet     optimization for PSA organ type 3
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
|                             ESCAN00007403: dummy assignment  NM_MSG_COND_RX_PARAMETER_NAME
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
|                             ESCAN00007939: wrong assertion check
| 2004-06-17  1.12    Pet     ESCAN00008082: EMC Wakeup Time in DPM is lower than 500ms
|                             ESCAN00008379: missing datatype in the prototypes of ApplCclVnDeactivated and ApplCclVnActivated
| 2004-07-02  1.13    Pet     ESCAN00008750: wrong assertion check
| 2004-07-30  1.14    Pet     ESCAN00009037: support multiple configurations
|                     Pet     ESCAN00009074: init value of variable "cclNmState"
|                     Pet     ESCAN00009098: support for GMLAN multichannel
|                     Pet     ESCAN00009118: compiler warning: variable network not used
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
| 2005-02-18  1.23    Bs      ESCAN00011142: change define VGEN_ENABLE_CIOA into CCL_ENABLE_EXTENDED_STATEON
|                             ESCAN00011147: add a comment at any time the CCL changes from an indexed to a code-doubled system
|                             ESCAN00011151: function CclGetNmState() is not needed anymore
|                             ESCAN00011167: add or modify some comments
|                             ESCAN00011035: Compiler error in ccl.c CclAssert: missing parameter
|                             ESCAN00011170: some variables and functions are not necessary if assertions are not activated
|                             ESCAN00011173: change names of function parameters
|                             ESCAN00011176: use defines instead of numbers
|                             ESCAN00011177: wrong variable used in 'CclSystemShutdown()'
|                             ESCAN00011187: change name and type of 'CanECUHandle'
|                             ESCAN00011212: change type of "channel" variable
|                             ESCAN00010661: support fullpreemptive OSEK-OS
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
| 2005-11-25  1.44    Pet     ESCAN00014294: Compiler error if paging is used and CCL is located in a far page
| 2005-12-06  2.00    Pet     ESCAN00014618: Support CAN driver code replicated API (only single channel)
|                             ESCAN00014810: Advance the network request handling API
|                             ESCAN00014852: Add support for NPM functionality
|                             ESCAN00014934: Rename CCL version variable kCclBugfixVersion
|                             ESCAN00015231: Remove debug access to internal states
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
| 2009-09-03  2.40    Dhf     ESCAN00037499: extended function EcuM_CheckWakeup() for LIN
|                             ESCAN00037554: some minor changes for code optimization
|                             ESCAN00037646: added support of OEM Baic
|                             ESCAN00037703: call CclEmergencyEnd()
|                             ESCAN00037697: add assertion for channel parameter in CclInit()
| 2009-12-03  2.41    Dhf     ESCAN00039551: no changes in this file
| 2010-01-07  2.42    Dhf     ESCAN00039850: no changes
| 2010-02-18  2.43    Dhf     ESCAN00040967: adapted CclInitPowerOn/CclInit
|                             ESCAN00040721: added interrupt lock
| 2010-06-15  2.44    Dhf     ESCAN00043411: adapted limphome detection for coordinator usecase
|                             ESCAN00043412: adapted remote sleep detection for coordinator usecase
|                             ESCAN00043536: switch only online in CclCanOnline if state is > waitBusSleep for coordinator
| 2010-07-20  2.45    Dhf     ESCAN00044173: adaption for extended gateway
|                             ESCAN00044298: relocate EcuM function call 
| 2010-08-05  2.46    Dhf     ESCAN00028369: added NPM data access
|                             ESCAN00028484: CCL does not accept communication requests
|                             ESCAN00028492: no communication request possible
|                             ESCAN00028799: NPM message timeout notification for wrong channel
|                             ESCAN00044475: compile warning
| 2010-08-16  2.47    Dhf     ESCAN00044481: resolved
|                             ESCAN00037523: changed initialization of cclNmState for NM High
|                             ESCAN00025339: Change handling of the internal stored CCL state via cclStateTmp
|                             ESCAN00044778: used macro is not defined
|                             ESCAN00044782: removed ";" after CclAssert(), adapted assertions for multiple configuration
|****************************************************************************/

#define CCL_MODULE

/***************************************************************************/
/* Include files                                                           */
/***************************************************************************/
#include "v_cfg.h"

#if defined( VGEN_GENY )
#include "v_inc.h"
#endif

#include "ccl.h"


/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
#if( CCL__CORE_VERSION != 0x0247)
#  error "CCL core: incorrect main or sub version"
#endif

#if( CCL__CORE_RELEASE_VERSION != 0x00)
#  error "CCL core: incorrect release version"
#endif

#if defined( VGEN_GENY )
#  if( CCL__COREDLL_VERSION < 0x0206u )
#    error "Incompatible CCL DLL-Version with this CCL-Implementation!"
#  endif
#  if( CCL__COREDLL_VERSION == 0x0206u )
#    if( CCL__COREDLL_RELEASE_VERSION < 0x07u )
#      error "Incompatible CCL DLL-Version with this CCL-Implementation!"
#    endif
#  endif
#endif


/***************************************************************************/
/* Plausibility checks                                                     */
/***************************************************************************/
#if( CCL_DLL_VERSION < 0x0106 )
#  if((defined(CCL_USE_REQUEST_SETCOM_FCT) && !defined(CCL_USE_REQUEST_CLEARCOM_FCT)) || \
      (!defined(CCL_USE_REQUEST_SETCOM_FCT) && defined(CCL_USE_REQUEST_CLEARCOM_FCT)))
#    error "Not all CCL state notification functions are configured. If you use the state notification then you have to configure all state notification functions !!"
#  endif
#endif




/* ESCAN00026013 */
#if( kCclNrOfChannels > 8)
#  error "The CCL does not support more than 8 channels!"
#endif

#if (kCclNumberOfUser > 255)
#  error "The CCL does not support more than 255 user requests!"
#endif

/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/

#if defined(C_SINGLE_RECEIVE_BUFFER) || defined(C_MULTIPLE_RECEIVE_BUFFER)
#  if !defined(CAN_CHANNEL_CANTYPE_ONLY)
#    define CAN_CHANNEL_CANTYPE_ONLY      void
#  endif
#endif


#  define cclExtWakeUpReq     cclExtCanWakeUpReq
#  if(kCclNrOfChannels > 1)
#    define CclExtComReqFctTbl CclExtCanComReqFctTbl
#  else
#    define CclExtComReqFct    CclExtCanComReqFct
#  endif

#if( CCL_DLL_VERSION < 0x0106 )
#  define CCL_ENABLE_CANBEDDED_HANDLING
#endif

#  if defined ( C_VERSION_REF_IMPLEMENTATION )
#    if( C_VERSION_REF_IMPLEMENTATION < 0x130u )
#      define CanGlobalInterruptDisable  CanInterruptDisable
#      define CanGlobalInterruptRestore  CanInterruptRestore
#    endif
#  else
#    error "The CAN driver reference implementation define is missing!"
#  endif

/* ESCAN00028150 */
#if !defined ( DRV_API_CALL_TYPE )
#  define DRV_API_CALL_TYPE
#endif
#if !defined ( DRV_API_CALLBACK_TYPE )
#  define DRV_API_CALLBACK_TYPE
#endif


/***************************************************************************/
/* Macros                                                                  */
/***************************************************************************/
#if !defined(CAN_RESET_WAKEUP)
/* ESCAN00026778 */
#  if ( ( kCclNrOfSystemChannels > 1 ) || (defined (C_ENABLE_MULTICHANNEL_API) ) )
#        define CanResetWakeup(a) ((void)CanWakeUp((a)))
#  else
#        define CanResetWakeup() ((void)CanWakeUp())
#  endif
#endif

/***************************************************************************/
/* Constants                                                               */
/***************************************************************************/


/***************************************************************************/
/* Local data definitions                                                  */
/***************************************************************************/
#if defined( CCL_ENABLE_EXTERNAL_REQUEST ) 

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclExtCanWakeUpReq[kCclNrOfChannels];
 /*
 * Description        : flag to handle external channel wake up by CAN
 * Access rights      : r/w
 * Val. range / Coding: kCclNoExtCanChWupReq / kCclExtCanChWupReq
 */




#  if defined(CCL_ENABLE_SLEEP_REPETITION)
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclCanSleepRepetition[kCclNrOfChannels];
 /*
 * Description        : flag to handle repetition of function "CanSleep"
 *                      due to failed transition from NORMAL to SLEEP mode
 * Access rights      : r/w
 * Val. range / Coding: kCclNoRepeatCanSleep / kCclRepeatCanSleep
 */
#  endif

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM1 cclCanSleepReturnCode[kCclNrOfChannels];
 /*
 * Description        : return value of function "CanSleep" to ask
 *                      the application about the following handling
 * Access rights      : r/w
 * Val. range / Coding: kCclNoRepeatCanSleep / kCclRepeatCanSleep
 */

#endif

#if defined( CCL_ENABLE_INTERNAL_REQUEST )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclIntNetReq[kCclNrOfNetworks];
 /*
 * Description        : flag to handle internal network request
 * Access rights      : r/w
 * Val. range / Coding: 0..kCclNrOfNetworks
 */

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclIntNetRel[kCclNrOfNetworks];
 /*
 * Description        : flag to handle internal network release
 * Access rights      : r/w
 * Val. range / Coding: 0..kCclNrOfNetworks
 */

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclIntNetRelHistory[kCclNrOfNetworks];
 /*
 * Description        : flag to handle internal network release
 * Access rights      : r/w
 * Val. range / Coding: 0..kCclNrOfNetworks
 */

#endif


V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclComHwState[kCclNrOfChannels];
 /*
 * Description        : state of HW to make communication possible
 *                      (PLL, CAN controller, CAN transceiver)
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclComHwEnabled  (HW is enabled by power management)
 *                      1: kCclComHwDisabled (HW is disabled by power management)
 */

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclBusState[kCclNrOfChannels];
 /*
 * Description        : Bus state 
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclBusOn
 *                      1: kCclBusOff
 */

#if defined(CCL_ENABLE_TRCV_PORT_INT)
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclWakeUpIntState[kCclNrOfChannels];
 /*
 * Description        : state of wake up interrupt by IO port
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclDisableWakeUpInt (port INT is disabled)
 *                      1: kCclEnableWakeUpInt  (port INT is enabled)
 */
#endif


#  if( CCL_DLL_VERSION < 0x0106 )
#  else
#    if defined( CCL_ENABLE_CANBEDDED_HANDLING ) 
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclStackInit;
 /*
 * Description        : flag to distinguish between the system specific and
 *                      channel specific CANbedded stack intialisation
 * Access rights      : r/w
 * Val. range / Coding: 0: system specific initialisation
 *                      1: channel specific initialisation
 */
#    endif
#  endif















#if defined(CCL_ENABLE_NMSTARTUP_TIMER)
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 cclNmStartupTimer[kCclNrOfChannels];
 /*
 * Description        : NM startup timer to hold the CAN channel in normal
 * Access rights      : r/w
 * Val. range / Coding: 0..xx
 */
#endif

#if defined(CCL_ENABLE_NPM_SUPPORT)

V_MEMRAM0 static volatile V_MEMRAM1 vuint8 V_MEMRAM2 cclNpmIgnitionState;
 /*
 * Description        : store the ignition state
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclNpmIgnitionOn
 *                      1: kCclNpmIgnitionOff
 */

#  if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclNpmEEPROMPreventWakeUp[kCclNrOfChannels];
 /*
 * Description        : store the EEPROM prevent wake up value
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclNpmPreventWakeUpOn
 *                      1: kCclNpmPreventWakeUpOff
 */

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclNpmMsgData[kCclNrOfChannels];
/*
 * Description        : internal buffer of the NPM message informations
 * Access rights      : r/w
 * Val. range / Coding: 0x01: kCclNpmMessageReceived
 *                      0x02: kCclNpmPreventWakeUpOn
 *                      0x04: kCclNpmForceShutdownOn
  */

V_MEMRAM0 static volatile V_MEMRAM1 vuint16 V_MEMRAM2 cclNpmMessageTimeout[kCclNrOfChannels];
 /*
 * Description        : NPM message timeout timer
 * Access rights      : r/w
 * Val. range / Coding: 0..xx
 */

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclNpmPwuFsRestriction[kCclNrOfChannels];
 /*
 * Description        : restriction state of CAN channel to force the
 *                      transition from ACTIVE to GO TO SLEEP and vice versa
 *                      depending on the internal requests and releases.
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclNpmPwuFsRestrictionOn  (state is restricted to GO TO SLEEP)
                        1: kCclNpmPwuFsRestrictionOff (no state restriction)
 */

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclNpmHandling[kCclNrOfChannels];
/*
 * Description        : store the value if NPM handling is active or deactive
 * Access rights      : r/w
 * Val. range / Coding: kCclNpmOn: NPM handling (PWU,FSD and NPM Message timeout observation) is enabled (default)
 *                      kCclNpmOff: NPM handling (PWU,FSD and NPM Message timeout observation) is disabled
 */
#  endif

V_MEMRAM0 static volatile V_MEMRAM1 vuint8 V_MEMRAM2 cclNpmState[kCclNrOfChannels];
/*
 * Description        : bit field to store the NPM state
 * Access rights      : r/w
 * Val. range / Coding: bit 2: prevent wake up state (enable/disable)
 *                      bit 3: force shutdown state (enable/disable)
 *                      bit 5: NPM message timeout state (timeout occure/ timeout not occure)
 *                      bit 6: NPM prevent wake up is valid/invalid
 *                      bit 7: NPM force shutdown is valid/invalid
 */

V_MEMRAM0 static volatile V_MEMRAM1 vuint8 V_MEMRAM2 cclNpmFsdPwuTriggered[kCclNrOfChannels];
/*
 * Description        : flag that is set when the restriction is triggered, must be reset by the application
 * Access rights      : r/w
 * Val. range / Coding: bit 0: prevent wake triggered
 *                      bit 1: force shutdown triggered
 */
#endif

#if defined(NM_TYPE_NMHIGH)
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclStateTmp[kCclNrOfChannels];
 /*
 * Description        : saves the latest NM High state, is needed for the start up
 *                      sequence (CCL must know if the NM High starts the network out
 *                      of state WaitBusSleep or Sleep)
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclNmStateSleep (NM High starts up out of state sleep)
 *                      1: kCclStateWaitBusSleep (NM High starts up out of state WaitBusSleep)
 *                      1: kCclStateGoToSleep (NM High prepares for sleep)
 *                      3: kCclNmStateActive (NM High is in network mode)
 */
#endif

#if defined(CCL_ENABLE_POSRES_FBL)
V_MEMRAM0 static V_MEMRAM1 t_descFblPosRespType V_MEMRAM2 cclPosRespData[kCclNrOfChannels];
 /*
 * Description        : store the reason for the diagnositc positive response message
 * Access rights      : r/w
 * Val. range / Coding: kDescSendFblPosRespEcuHardReset
 *                      kDescSendFblPosRespDscDefault
 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclSendPosRespFbl[kCclNrOfChannels];
 /*
 * Description        : send state if a candesc positive response have to be send
 *                      during the NM start up
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclSendPosResp
 *                      1: kCclSendNoPosResp
 */
#endif


#if defined ( NM_TYPE_NMHIGH )  /* ESCAN00022670 */
#  if (kNmhNumberOfChannels > 1)
#    if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cclOldNmHighInitValue;
 /*
 * Description        : used to save the NM High initialization value
 * Access rights      : r/w
 * Val. range         : 0..255
 */
#    endif
#  endif
#endif







/***************************************************************************/
/* Global data definitions                                                 */
/***************************************************************************/
#if defined( CCL_ENABLE_ERROR_HOOK)
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 cclChannelNumber;
 /*
 * Description        : channel number to identify the occured assertion
 * Access rights      : r/w
 * Val. range / Coding: 0..kCclNrOfChannels
 */

V_MEMRAM0 V_MEMRAM1 vuint16 V_MEMRAM2 cclErrorCode;
 /*
 * Description        : error code to identify the occured assertion
 * Access rights      : r/w
 * Val. range / Coding: s. CCL_INC.H
 */

V_MEMRAM0 V_MEMRAM1 vuint16 V_MEMRAM2 cclErrorLine;
 /*
 * Description        : error line to identify the occured assertion
 * Access rights      : r/w
 * Val. range / Coding: s. DRV, IL, NM, TP or DIAG
 */

V_MEMRAM0 V_MEMRAM1 vuint16 V_MEMRAM2 cclComponentID;
 /*
 * Description        : component identifier to identify the occured assertion
 * Access rights      : r/w
 * Val. range / Coding: s. CCL_INC.H
 */
#endif

#if defined(CCL_ENABLE_INTERNAL_REQUEST)
V_MEMRAM0 volatile V_MEMRAM1 vuint8 V_MEMRAM2 cclIntNetState[kCclNetReqTableSize];
 /*
 * Description        : state of internal network request/release
 * Access rights      : r/w
 * Val. range / Coding: 0: network released
 *                      1: network requested
 */

#endif

V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 cclNmState[kCclNrOfChannels];
 /*
 * Description        : state of CCL depending
 *                      on external channel requests and
 *                      internal network requests or releases
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclNmStateSleep (neither external nor internal request)
 *                      1: kCclNmStateGoToSleep (only external request)
 *                      2: kCclNmStateActive (at least internal request)
 *                      3: kCclNmPowerFail (power fail is active)
 */




#if defined( CCL_ENABLE_SW_COM_STATE )
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 cclComSwState[kCclNrOfChannels];
 /*
 * Description        : communication state of CANbedded stack (DRV, IL, NM)
 * Access rights      : r/w
 * Val. range / Coding: 0: kCclComSwOff  (communication is switched off by CCL)
 *                      1: kCclComSwOn   (communication is switched on by CCL)
 */
#endif




#if defined(CCL_ENABLE_NPM_SUPPORT)
#  if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
V_MEMRAM0 volatile V_MEMRAM1 vuint8 V_MEMRAM2 cclNpmMsgDataTmp[kCclNrOfChannels];
/*
 * Description        : shadow buffer of the NPM message informations
 * Access rights      : r/w
 * Val. range / Coding: 0x01: kCclNpmMessageReceived
 *                      0x02: kCclNpmPreventWakeUpOn
 *                      0x04: kCclNpmForceShutdownOn
 */
#  endif
#endif

/***************************************************************************/
/* Local function prototypes                                               */
/***************************************************************************/
static void CCL_API_CALL_TYPE CclInitPorts(CCL_CHANNEL_CCLTYPE_ONLY);

#if defined(CCL_ENABLE_NPM_SUPPORT)
#  if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
static void CCL_API_CALL_TYPE CclNpmSetPwuFsRestriction(CCL_CHANNEL_CCLTYPE_ONLY);
static void CCL_API_CALL_TYPE CclNpmClearPwuFsRestriction(CCL_CHANNEL_CCLTYPE_ONLY);
static void CCL_API_CALL_TYPE CclNpmBusSleepActivities(CCL_CHANNEL_CCLTYPE_ONLY);
#  endif
#  if defined(CCL_ENABLE_PREVENT_WAKEUP)
static void CCL_API_CALL_TYPE CclNpmCheckPreventWakeUpState(CCL_CHANNEL_CCLTYPE_ONLY);
#  endif
#  if defined(CCL_ENABLE_FORCE_SHUTDOWN)
static void CCL_API_CALL_TYPE CclNpmCheckForceShutdownState(CCL_CHANNEL_CCLTYPE_ONLY);
#  endif
#endif









/* ESCAN00032540 */





#if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
#  if ( ((defined NM_TYPE_NMHIGH) && (kNmhNumberOfChannels > 1)) ) /* ESCAN00022670 */
static void CclValidateNmInitValue( CCL_CHANNEL_CCLTYPE_FIRST tCclNmInitParaType nmInitValue );
#  endif
#endif

/***************************************************************************/
/* Local functions                                                         */
/***************************************************************************/





/* ESCAN00032540 */





#if defined(CCL_ENABLE_ERROR_HOOK)
/************************************************************************
| NAME:               CclFatalError
| PROTOTYPE:          void CCL_API_CALL_TYPE CclFatalError(vuint8 ChannelNumber, vuint16 ErrorCode, vuint16 ErrorLine, vuint8 ComponentID)
| CALLED BY:          assertions within the CANbedded stack and/or CCL
|                     re-directe the call of the "FatalError"-functions
|                     Application is NOT ALLOWED to call this function!
| PRECONDITIONS:      'use CCL ErrorHook' has to be activated in the used generation tool to notify the application
| INPUT PARAMETERS:   ChannelNumber: 0-255    (255 default for 'NO_CHANNEL_INFO_AVAILABLE')
|                     ErrorCode    : 0-65.535 (individual specified in each layer)
|                     ErrorLine    : __LINE__ (0 if no information is available)
|                     ComponentID  : s. CCL_INC.H
| RETURN VALUE:       void
| DESCRIPTION:        Convert the given error information to the global error handling
|                     variables and call a application function to handle the error.
|*************************************************************************/
void CCL_API_CALL_TYPE CclFatalError(CanChannelHandle ChannelNumber, vuint16 ErrorCode, vuint16 ErrorLine, vuint8 ComponentID)
 {
   /* pin assertion information */
   cclChannelNumber = (vuint8)ChannelNumber; /* channel number */
   cclErrorCode     = ErrorCode;     /* error code */
   cclErrorLine     = ErrorLine;     /* error line */
   cclComponentID   = ComponentID;   /* component ID */

   /* error hook (assertions) */
   ApplCclFatalError();
 }
#endif


/************************************************************************
| NAME:               CclInitPorts
| PROTOTYPE:          void CclInitPorts(CanChannelHandle channel)
|                     or
|                     void CclInitPorts(void)
| CALLED BY:          CclInitPowerOn
|                     Application is NOT ALLOWED to call this function!
| PRECONDITIONS:      to be called in loop for each channel
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        calls function container to inizialise all HW ports
|                     (both the transceiver port register and the
|                     transceiver port interrupt) with the channel specific
|                     parameters.
|*************************************************************************/
static void CCL_API_CALL_TYPE CclInitPorts(CCL_CHANNEL_CCLTYPE_ONLY)
{
#if defined (CCL_ENABLE_MULTIPLE_CONFIG)
  if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > 0x00)
#endif    
  {
#if defined( CCL_ENABLE_TRCV_TYPE_NONE )
   /* nothing to do */
#else
   /* init transceiver port register */
#  if(kCclNrOfChannels > 1)
   if( CclInitTrcvFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
   {
     /* By using the following table of function calls, code-doubled functions 
     * are called from the indexed CCL. This is done to simplify the called 
     * functions (no distinction of the parameter 'channel' is necessary). */
     (CclInitTrcvFctTbl[CCL_CHANNEL_CCLINDEX])();
   }
#  else
   CclInitTrcvFct();
#  endif
#endif

#if defined(CCL_ENABLE_TRCV_PORT_INT)
#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
   /* init transceiver port interrupt */
#    if(kCclNrOfChannels > 1)
   /* By using the following tables of function calls, code-doubled functions 
  * are called from the indexed CCL. This is done to simplify the called 
  * functions (no distinction of the parameter 'channel' is necessary). */
   if(CclConfigTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
   {
     (CclConfigTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
   }
   if(CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
   {
     (CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
   }
   if(CclClearTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
   {
     (CclClearTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
   }
#    else
   CclConfigTrcvIntFct();
   CclDisableTrcvIntFct();
   CclClearTrcvIntFct();
#    endif
   /* set INT state to "disable" */
   cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] = kCclDisableWakeUpInt;
#  endif
#endif
  }
 }

#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
 /************************************************************************
 | NAME:               ApplCanWakeUp
 | PROTOTYPE:          void ApplCanWakeUp(CanChannelHandle channel)
 |                     or
 |                     void ApplCanWakeUp(void)
 | CALLED BY:          CANdrv:  CanWakeUpInt / CanWakeUpTask (internal wake up INT)
 |                     CCL:     CclCanWakeUpInt (external wake up INT)
 |                     Application is NOT ALLOWED to call this function!
 | PRECONDITIONS:      -
 | INPUT PARAMETERS:   channel (multiple channel)
 |                     or
 |                     void (single channel)
 | RETURN VALUE:       void
 | DESCRIPTION:        Function notifies WakeUp over RX/INH transceiver port
 |                     (handled in CCL) or WakeUp over CAN controller
 |                     (handled in CAN driver), sets the external channel
 |                     wakeup request flag and requests the power manager state.
 |*************************************************************************/
void DRV_API_CALLBACK_TYPE ApplCanWakeUp(CAN_CHANNEL_CANTYPE_ONLY)
 {
#    if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#      if( kCclNrOfChannels == 1)
   if(channel == (CanChannelHandle)kCclChannelIndex)
#      endif
#    endif
   {
     /* set external EMC or CAN wake up request */
     cclExtWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclExtChWupReq;

#    if defined( CCL_ENABLE_INTERNAL_REQUEST)
#        if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
     if( (cclIntNetReq[CCL_CHANNEL_CCLINDEX] == kCclNoIntNetReq) ||
         (cclNpmPwuFsRestriction[CCL_CHANNEL_CCLINDEX] == kCclNpmPwuFsRestrictionOn) )
#        else
     if(cclIntNetReq[CCL_CHANNEL_CCLINDEX] == kCclNoIntNetReq) /* ESCAN00011217 and ESCAN00011218 */
#        endif
#    endif
     {


#    if ( defined(CCL_USE_REQUEST_SETEXTCOM_FCT) )
       /* external EMC or CAN communication request notification */
       if( cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep )
       {
#      if defined(CCL_USE_REQUEST_SETEXTCOM_FCT)
#        if(kCclNrOfChannels > 1)
         if (CclExtComReqFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
         {
           /* By using the following table of function calls, code-doubled functions 
            * are called from the indexed CCL. This is done to simplify the called 
            * functions (no distinction of the parameter 'channel' is necessary). */
           (CclExtComReqFctTbl[CCL_CHANNEL_CCLINDEX])();
         }
#        else
         CclExtComReqFct();
#        endif
#      endif


       }
#  endif

     }
   }
 }
#  endif






#if defined(CCL_ENABLE_NPM_SUPPORT)
#  if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
/************************************************************************
| NAME:               CclNpmSetPwuFsRestriction
| PROTOTYPE:          void CclNpmSetPwuFsRestriction(CCL_CHANNEL_CCLTYPE_ONLY)
| CALLED BY:          CCL
| PRECONDITIONS:      Application is NOT ALLOWED to call this function!
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       -
| DESCRIPTION:        enable the restriction of the CAN channel state
|                     and force a transition from ACTIVE to GO TO SLEEP
|                     if at least on internal network request is waiting
|*************************************************************************/
static void CCL_API_CALL_TYPE CclNpmSetPwuFsRestriction(CCL_CHANNEL_CCLTYPE_ONLY)
 {
#  if(kCclNetReqTableSize > 1)
   vuint8 reqIndex;
#  endif
   vuint8 pendReq;

   pendReq = 0;

   /* check restriction state */
   if(cclNpmPwuFsRestriction[CCL_CHANNEL_CCLINDEX] == kCclNpmPwuFsRestrictionOff)
   {
     /* restriction is deactive,
      * activate restriction 
      */
     cclNpmPwuFsRestriction[CCL_CHANNEL_CCLINDEX] = kCclNpmPwuFsRestrictionOn;

     /* clear network request field */
#  if(kCclNetReqTableSize > 1)
     for(reqIndex=cclStartIndex[CCL_CHANNEL_CCLINDEX]; reqIndex<=cclStopIndex[CCL_CHANNEL_CCLINDEX]; reqIndex++)
     {
       pendReq |= cclIntNetState[reqIndex];
       cclIntNetState[reqIndex] = 0x00;
     }
#  else
     pendReq = cclIntNetState[0];
     cclIntNetState[0] = 0x00;
#  endif

     /* check CCL state */
     if(cclNmState[CCL_CHANNEL_CCLINDEX]==kCclNmStateSleep)
     {
       /* check for internal network request */
       if(cclIntNetReq[CCL_CHANNEL_CCLINDEX] != kCclNoIntNetReq)
       {
         /* network request is pending and not processed,
          * clear internal network request flag
          */
#  if defined(CCL_ENABLE_PREVENT_WAKEUP)
         /* communication requested but restricted by CCL, PWU has triggered, set flag: */
         cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] |= kCclNpmPwuTriggered;
#  endif

         cclIntNetReq[CCL_CHANNEL_CCLINDEX] = kCclNoIntNetReq;

#    if defined(CCL_USE_REQUEST_CLEARCOM_FCT)
         /* communication release notification */
#      if(kCclNrOfChannels > 1)
         if(CclComRelFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
         {
           /* By using the following table of function calls, code-doubled functions 
           * are called from the indexed CCL. This is done to simplify the called 
           * functions (no distinction of the parameter 'channel' is necessary). */
           (CclComRelFctTbl[CCL_CHANNEL_CCLINDEX])();
         }
#      else
         CclComRelFct();
#      endif
#    endif

#    if defined(CCL_ENABLE_TRCV_PORT_INT)
       CanGlobalInterruptDisable();
         /* enable transceiver port interrupt */
#      if( kCclNrOfChannels > 1 )
         /* By using the following table of function calls, code-doubled functions 
         * are called from the indexed CCL. This is done to simplify the called 
         * functions (no distinction of the parameter 'channel' is necessary). */
         /* Wtihin the following function calls a maybe pending 
         *  Transceiver interrupt will be cleared! */
         if(CclClearTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
         {
           (CclClearTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
         }
         if(CclEnableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
         {
           (CclEnableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
         }
#      else
         /* Wtihin the following function calls a maybe pending 
         *  Transceiver interrupt will be cleared! */
         CclClearTrcvIntFct();
         CclEnableTrcvIntFct();
#      endif

         /* set INT state to "enable" */
         cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] = kCclEnableWakeUpInt;

#      if defined(CCL_ENABLE_TRCV_PORT_EDGE_TRIGGER)
         /* check transceiver port register */
#        if( kCclNrOfChannels > 1 )
         if(CclCheckTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX]() == kCclTrcvWakeIntPending)
         {
           /* By using the following table of function calls, code-doubled functions 
           * are called from the indexed CCL. This is done to simplify the called 
           * functions (no distinction of the parameter 'channel' is necessary). */

           /* disable transceiver port interrupt */
           if(CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
           {
             (CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
           }
#        else
         if(CclCheckTrcvIntFct() == kCclTrcvWakeIntPending)
         {
           /* disable transceiver port interrupt */
           CclDisableTrcvIntFct();
#        endif

           /* check INT state */
           if(cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] == kCclEnableWakeUpInt)
           {
             /* external EMC/CAN wake up notification */
             CclCanWakeUpInt(CCL_CHANNEL_CCLPARA_ONLY);
           }
         }
#      endif
         CanGlobalInterruptRestore();
#    endif
       }
     }
     else
     { 
       if( pendReq > 0 )
       {
         /* set internal network release */
         cclIntNetRel[CCL_CHANNEL_CCLINDEX] = (vuint8)CCL_NET_CCLINDEX;
       }

       if( (pendReq > 0) || (cclIntNetReq[CCL_CHANNEL_CCLINDEX] != kCclNoIntNetReq) )
       {
#  if defined(CCL_ENABLE_PREVENT_WAKEUP)
         if( (vuint8)(cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmPreventWakeUpOn) == kCclNpmPreventWakeUpOn )
         {
           /* communication requested but restricted by CCL, PWU has triggered, set flag: */
           cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] |= kCclNpmPwuTriggered;
         }
#  endif

#  if defined(CCL_ENABLE_FORCE_SHUTDOWN)
         if( (vuint8)(cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmForceShutdownOn) == kCclNpmForceShutdownOn)
         {
           /* communication requested but restricted by CCL, FSD has triggered, set flag: */
           cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] |= kCclNpmFsdTriggered;
         }
#  endif
       }

       /* clear internal network request flag */
       cclIntNetReq[CCL_CHANNEL_CCLINDEX] = kCclNoIntNetReq;
     }
   }
 }

/************************************************************************
| NAME:               CclNpmClearPwuFsRestriction
| PROTOTYPE:          void CclNpmClearPwuFsRestriction(CCL_CHANEL_CCLTYPE_ONLY)
| CALLED BY:          CCL
| PRECONDITIONS:      Application is NOT ALLOWED to call this function!
| INPUT PARAMETERS:   channel (multiple channel
|                     or
|                     void (single channel)
| RETURN VALUE:       -
| DESCRIPTION:        clear the restriction of the CAN channel state
|*************************************************************************/
static void CCL_API_CALL_TYPE CclNpmClearPwuFsRestriction(CCL_CHANNEL_CCLTYPE_ONLY)
 {
   /* deactivate restriction */
   cclNpmPwuFsRestriction[CCL_CHANNEL_CCLINDEX] = kCclNpmPwuFsRestrictionOff;
 }


/************************************************************************
| NAME:               CclNpmBusSleepActivities
| PROTOTYPE:          void CclNpmBusSleepActivities(CCL_CHANEL_CCLTYPE_ONLY)
| CALLED BY:          CCL
| PRECONDITIONS:      Application is NOT ALLOWED to call this function!
| INPUT PARAMETERS:   channel (multiple channel
|                     or
|                     void (single channel)
| RETURN VALUE:       -
| DESCRIPTION:        stop the NPM message timer,
|                     check the actual prevent wake up state and perform further 
|                     action (activate prevent wake up, inform the application),
|                     check the actual force shutdown state and perform further
|                     actions (deactivate force shutdown and inform the application)
|*************************************************************************/
static void CCL_API_CALL_TYPE CclNpmBusSleepActivities(CCL_CHANNEL_CCLTYPE_ONLY)
{
  /* stop NPM message timeout observe */
  cclNpmMessageTimeout[CCL_CHANNEL_CCLINDEX] = kCclNpmMessageTimerStopped;

#    if defined(CCL_ENABLE_PREVENT_WAKEUP)
  /* check the prevent wake up state */
  CclNpmCheckPreventWakeUpState(CCL_CHANNEL_CCLPARA_ONLY);

#      if defined(CCL_ENABLE_EEPROM_PREVENT_WAKEUP)
  if(cclNpmEEPROMPreventWakeUp[CCL_CHANNEL_CCLINDEX] == kCclNpmPreventWakeUpOn)
  {
    /* the EEPROM prevent wake up value is on */
    if( (vuint8)(cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmPreventWakeUpOn) != kCclNpmPreventWakeUpOn )
    {
      /* the actual prevent wake up state is off,
       * inform the application about the new prevent wake up value for EEPROM storage */
      ApplCclNpmWritePwuStateToNVRAM(CCL_CHANNEL_CCLPARA_FIRST kCclNpmPreventWakeUpOff);
      /* set the CCL EEPROM value to off */
      cclNpmEEPROMPreventWakeUp[CCL_CHANNEL_CCLINDEX] = kCclNpmPreventWakeUpOff;
    }
  }
  else
  {
    /* the EEPROM prevent wake up value is off */
    if( (vuint8)(cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmPreventWakeUpOn) == kCclNpmPreventWakeUpOn)
    {
      /* the actual prevent wake up state is on,
       * inform the application about the new prevent wake up value for EEPROM storage */
      ApplCclNpmWritePwuStateToNVRAM(CCL_CHANNEL_CCLPARA_FIRST kCclNpmPreventWakeUpOn);
      /* set the CCL EEPROM value to on */
      cclNpmEEPROMPreventWakeUp[CCL_CHANNEL_CCLINDEX] = kCclNpmPreventWakeUpOn;
    }
  }
#      endif
#    endif

#    if defined(CCL_ENABLE_FORCE_SHUTDOWN)
  /* check the NPM force shutdown state */
  if( (vuint8)(cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmForceShutdownOn) == kCclNpmForceShutdownOn)
  {
    /* force shutdown is active,
     * check the NPM prevent wake up state */
    if( (vuint8)(cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmPreventWakeUpOn) != kCclNpmPreventWakeUpOn )
    {
      /* prevent wake up is off,
       * enable communication request handling */
      CclNpmClearPwuFsRestriction(CCL_CHANNEL_CCLPARA_ONLY);
    }

    /* set the NPM force shutdown state to off */
    cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmForceShutdownOff;
    /* inform the application about the force shutdown state change */
    ApplCclNpmForceShutdown(CCL_CHANNEL_CCLPARA_FIRST kCclNpmForceShutdownOff);
  }
#    endif
}


#  endif


#  if defined(CCL_ENABLE_PREVENT_WAKEUP)
/************************************************************************
| NAME:               CclNpmCheckPreventWakeUpState
| PROTOTYPE:          vuint8 CclNpmCheckPreventWakeUpState( void ) or
|                     vuint8 CclNpmCheckPreventWakeUpState( CanChannelHandle channel )
| CALLED BY:          CCL
|                     Application is NOT ALLOWED to call this function!
| PRECONDITIONS:
| INPUT PARAMETERS:   void or CAN channel handle
| RETURN VALUE:       vuint8
| DESCRIPTION:        check the prevent wake up state
|*************************************************************************/
static void CCL_API_CALL_TYPE CclNpmCheckPreventWakeUpState(CCL_CHANNEL_CCLTYPE_ONLY)
{
  vuint8 cclOldNpmState;

  /* save the actual NPM state */
  cclOldNpmState = cclNpmState[CCL_CHANNEL_CCLINDEX];

  /* check if the CAN was woken up by a message */
  if(cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] == kCclExtChWupReq)
  {
    /* if the CAN is woken up by a message than 
     * check if prevent wake up is active
     */
    if( (vuint8)(cclOldNpmState & kCclNpmPreventWakeUpOn) == kCclNpmPreventWakeUpOn )
    {
      /* prevent wake up is active, 
       * set NPM state prevent wake up state off
       */
      cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmPreventWakeUpOff;
      /* set the NPM state prevent wake up off in the NPM message shadow buffer */
      cclNpmMsgData[CCL_CHANNEL_CCLINDEX] &= kCclNpmPreventWakeUpOff;
      /* informs the application about the deactivation */
      ApplCclNpmPreventWakeup(CCL_CHANNEL_CCLPARA_FIRST kCclNpmPreventWakeUpOff);
    }
    /* ESCAN00028484 */
    /* activate communication request handling */   
    CclNpmClearPwuFsRestriction(CAN_CHANNEL_CANPARA_ONLY);
  }

#  if defined(CCL_ENABLE_EEPROM_PREVENT_WAKEUP)
  /* check the prevent wake up state */
  if( (vuint8)(cclNpmMsgData[CCL_CHANNEL_CCLINDEX] & 0x02) == kCclNpmPreventWakeUpOn)
  {
    /* prevent wake up is active, check the prevent wake up EEPROM value */
    if(cclNpmEEPROMPreventWakeUp[CCL_CHANNEL_CCLINDEX] == kCclNpmPreventWakeUpOff)
    {
      /* prevent wake up EEPROM value is off */
#  if defined(CCL_ENABLE_EEPROM_PREVENT_WAKEUP)
      /* inform the application about about the prevent wake up state change 
       * to store the information in the EEPROM */
      ApplCclNpmWritePwuStateToNVRAM(CCL_CHANNEL_CCLPARA_FIRST kCclNpmPreventWakeUpOn);
#  endif
      /* set the prevent wake up EEPROM value to on */
      cclNpmEEPROMPreventWakeUp[CCL_CHANNEL_CCLINDEX] = kCclNpmPreventWakeUpOn;
    }
  }
#  endif

  /* set the NPM prevent wake up state to off */
  cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmPreventWakeUpOff;

  /* check ignition state */
  if(cclNpmIgnitionState == kCclNpmIgnitionOff)
  {
    /* ignition is off,
     * check CAN channel state */
    if(cclNmState[CCL_CHANNEL_CCLINDEX] < kCclStateGoToSleep)
    {
      /* the CAN channel is in sleep or wait bus sleep,
       * check if the NPM message prevent wake up state */
      if( (vuint8)(cclNpmMsgData[CCL_CHANNEL_CCLINDEX] & 0x02) == kCclNpmPreventWakeUpOn)
      {
        /* prevent wake up is on,
         * check the actual prevent wake up state */
        if( (vuint8)(cclOldNpmState & kCclNpmPreventWakeUpOn) != kCclNpmPreventWakeUpOn )
        {
          /* Inform application only when we are not about to start up: */
          if(cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] != kCclExtChWupReq)
          {
            ApplCclNpmPreventWakeup(CCL_CHANNEL_CCLPARA_FIRST kCclNpmPreventWakeUpOn);
            /* deactivate the communication request handling */
            CclNpmSetPwuFsRestriction(CCL_CHANNEL_CCLPARA_ONLY);
          }
        }

        /* PWU is only activated when we are not about to start up: */
        if(cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] != kCclExtChWupReq)
        {
          cclNpmState[CCL_CHANNEL_CCLINDEX] |= kCclNpmPreventWakeUpOn;
        }
      }
    }
  }
  else
  {
    /* ignition is on,
     * check the actual prevent wake up state*/
    if( (vuint8)(cclOldNpmState & kCclNpmPreventWakeUpOn) == kCclNpmPreventWakeUpOn )
    {
      /* prevent wake up is on,
      * inform the application about the prevet wake up deactivation */
      ApplCclNpmPreventWakeup(CCL_CHANNEL_CCLPARA_FIRST kCclNpmPreventWakeUpOff);
      /* activate the communication request handling */
      CclNpmClearPwuFsRestriction(CAN_CHANNEL_CANPARA_ONLY);
    }
  }
}
#  endif


#  if defined(CCL_ENABLE_FORCE_SHUTDOWN)
/************************************************************************
| NAME:               CclNpmCheckForceShutdownState
| PROTOTYPE:          vuint8 CclNpmCheckForceShutdownState( void ) or
|                     vuint8 CclNpmCheckForceShutdownState( CanChannelHandle channel )
| CALLED BY:          CCL
|                     Application is NOT ALLOWED to call this function!
| PRECONDITIONS:
| INPUT PARAMETERS:   void or channel handle
| RETURN VALUE:       vuint8
| DESCRIPTION:        check the force shutdown state
|*************************************************************************/
static void CCL_API_CALL_TYPE CclNpmCheckForceShutdownState(CCL_CHANNEL_CCLTYPE_ONLY)
{
  vuint8 oldNpmState;

  /* save the actual NPM state */
  oldNpmState = cclNpmState[CCL_CHANNEL_CCLINDEX];

  /* set the NPM force shutdown state to off */
  cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmForceShutdownOff;

  /* check ignition state */
  if(cclNpmIgnitionState == kCclNpmIgnitionOff)
  {
    /* ignition is off,
     * check the received force shutdown state */
    if( (vuint8)(cclNpmMsgData[CCL_CHANNEL_CCLINDEX] & 0x04) == kCclNpmForceShutdownOn )
    {
      if(cclNmState[CCL_CHANNEL_CCLINDEX] > kCclStateWaitBusSleep)
      {
        /* force shutdown is active,
        * set the NPM force shutdown down state to on */
        cclNpmState[CCL_CHANNEL_CCLINDEX] |= kCclNpmForceShutdownOn;
        /* check the actual force shutdown state */
        if( (vuint8)(oldNpmState & kCclNpmForceShutdownOn) != kCclNpmForceShutdownOn)
        {
          /* force shutdown is actual off,
          * inform the application about the force shutdown activation */
          ApplCclNpmForceShutdown(CCL_CHANNEL_CCLPARA_FIRST kCclNpmForceShutdownOn);
        }
      }
    }
  }
  
  if( ((vuint8)(oldNpmState & kCclNpmForceShutdownOn) == kCclNpmForceShutdownOn) &&
      ((vuint8)(cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmForceShutdownOn) != kCclNpmForceShutdownOn) )
  {
    /* the actual NPM state is on and the new NPM state is off,
     * activate the communication request handling */
    CclNpmClearPwuFsRestriction(CCL_CHANNEL_CCLPARA_ONLY);
    /* clear the NPM force shutdown state */
    cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmForceShutdownOff;
    /* inform the application about the force shutdown state change */
    ApplCclNpmForceShutdown(CCL_CHANNEL_CCLPARA_FIRST kCclNpmForceShutdownOff);
  }
}
#  endif
#endif


/***************************************************************************/
/* Global functions                                                        */
/***************************************************************************/

/************************************************************************
 | NAME:               CclCanNormal
 | PROTOTYPE:          void CclCanNormal(CanChannelHandle channel)
 |                     or
 |                     void CclCanNormal(void)
 | CALLED BY:          CCL
 |                     Application is NOT ALLOWED to call this function!
 | PRECONDITIONS:      -
 | INPUT PARAMETERS:   channel (multiple channel)
 |                     or
 |                     void (single channel)
 | RETURN VALUE:       void
 | DESCRIPTION:        set CAN transceiver and CAN controller to NORMAL mode
 |*************************************************************************/
void CCL_API_CALL_TYPE CclCanNormal(CCL_CHANNEL_CCLTYPE_ONLY)
{

#if defined(CCL_ENABLE_EXTERNAL_REQUEST)
#  if defined(CCL_ENABLE_SLEEP_REPETITION)
  /* stop sleep repetition handling */
  cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = kCclNoRepeatCanSleep;
#  endif
#endif

  {
    /* check the actual bus state, to prevent multiple activations */
    if(cclBusState[CCL_CHANNEL_CCLINDEX] == kCclBusOff)
    {
      /* the bus state is off */
#if defined( CCL_ENABLE_TRCV_TYPE_NONE )
   /* nothing to do */
#else
       /* set transceiver to NORMAL mode by port register */
#  if(kCclNrOfChannels > 1)
       if( CclWakeUpTrcvFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
       {
         /* By using the following table of function calls, code-doubled functions 
          * are called from the indexed CCL. This is done to simplify the called 
          * functions (no distinction of the parameter 'channel' is necessary). */
         (CclWakeUpTrcvFctTbl[CCL_CHANNEL_CCLINDEX])();
       }
#  else
       CclWakeUpTrcvFct();
#  endif
#endif

#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
#    if(kCclNrOfChannels > 1)
       /* check wake up / sleep support */
       if((cclNmWakeUpAble & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) != kCclNoWakeUpAble)
#    endif
       {
         /* set CAN controller to NORMAL mode */
         /* ESCAN00026778 */
        CanGlobalInterruptDisable();
#    if ( ( kCclNrOfSystemChannels > 1 ) || (defined (C_ENABLE_MULTICHANNEL_API) ) )
        CanResetWakeup(CCL_CHANNEL_CANPARA_ONLY);
#    else
        CanResetWakeup();
#    endif
        CanGlobalInterruptRestore();

       }
#  endif
       /* set the CAN state to on */
       cclBusState[CCL_CHANNEL_CCLINDEX] = kCclBusOn;
     }
#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
    else if(cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] == kCanFailed)
    {
#    if(kCclNrOfChannels > 1)
      /* check wake up / sleep support */
      if((cclNmWakeUpAble & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) != kCclNoWakeUpAble)
#    endif
      {
        /* set CAN controller to NORMAL mode */
        /* ESCAN00026778 */
        CanGlobalInterruptDisable();
#    if ( ( kCclNrOfSystemChannels > 1 ) || (defined (C_ENABLE_MULTICHANNEL_API) ) ) 
        CanResetWakeup(CCL_CHANNEL_CANPARA_ONLY);
#    else
        CanResetWakeup();
#    endif
        CanGlobalInterruptRestore();

      }
    }
    /* ESCAN00031836 */
    else
    {
    }
#  endif

#if defined(CCL_ENABLE_EXTERNAL_REQUEST)
     /* reset the CanSleep return value */
    cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] = kCanOk;
#endif

#  if defined(CCL_ENABLE_NPM_SUPPORT)
#    if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
    if(cclNpmHandling[CCL_CHANNEL_CCLINDEX] == kCclNpmOn)
    {
      /* ESCAN00028799 */
      if((cclNmWakeUpAble & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) != kCclNoWakeUpAble)
      {
         /* restart NPM message timeout timer */
         cclNpmMessageTimeout[CCL_CHANNEL_CCLINDEX] = cclNpmMsgTimeoutValue[CCL_CHANNEL_CCLINDEX];
         /* clear NPM message timeout occure flag */
         cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmMessageTimeoutClear;
      }
    }
#    endif
#  endif


  }
}

 /************************************************************************
 | NAME:                CclCanStandby
 | PROTOTYPE:           void CclCanStandby(CanChannelHandle channel)
 |                      or
 |                      void CclCanStandby(void)
 | CALLED BY:           CCL
 |                      Application is NOT ALLOWED to call this function!
 | PRECONDITIONS:       -
 | INPUT PARAMETERS:    channel (multiple channel)
 |                      or
 |                      void (single channel)
 | RETURN VALUE:        void
 | DESCRIPTION:         set CAN controller and CAN transceiver to SLEEP mode,
 |                      release the power manager state and enable the
 |                      external wakeup port INT
 |*************************************************************************/
void CCL_API_CALL_TYPE CclCanStandby(CCL_CHANNEL_CCLTYPE_ONLY)
{
  CanGlobalInterruptDisable();

  {
    {
      {
#  if defined(CCL_ENABLE_EXTERNAL_REQUEST) 
#      if(kCclNrOfChannels > 1)
        /* check wake up / sleep support */
        if((cclNmWakeUpAble & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) != kCclNoWakeUpAble )
#      endif
        {
          /* set CAN controller to SLEEP mode */
          cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] = CanSleep(CCL_CHANNEL_CANPARA_ONLY);
        }

#    if defined(CCL_ENABLE_NPM_SUPPORT)
#      if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
         if(cclNmState[CCL_CHANNEL_CCLINDEX] == kCclStateActive)
         {
           /* CCL is in normal mode */
           if(cclNpmHandling[CCL_CHANNEL_CCLINDEX] == kCclNpmOn)
           {
             /* NPM handling is activated,
              * set CCL into wait bus sleep
              */
             cclNmState[CCL_CHANNEL_CCLINDEX] = kCclStateWaitBusSleep;

             /* check PWU state */
             CclNpmBusSleepActivities(CCL_CHANNEL_CCLPARA_ONLY);
           }
         }
         else
#      endif
#    endif
         {          
           /* set CCL into wait bus sleep */
           cclNmState[CCL_CHANNEL_CCLINDEX] = kCclStateWaitBusSleep;
         }
         
       /* check "CanSleep" return code */
       if(cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] != kCanFailed)
#  endif
       {

#if defined(CCL_ENABLE_EXTERNAL_REQUEST) 
#  if defined(CCL_ENABLE_SLEEP_REPETITION)
         /* stop sleep repetition handling */
         cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = kCclNoRepeatCanSleep;
#  endif
#endif

#  if defined( CCL_ENABLE_TRCV_TYPE_NONE )
         /* nothing to do */
#  else
         /* set transceiver to SLEEP or STANDBY mode by port register */
#    if(kCclNrOfChannels > 1)
         if( CclSleepTrcvFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
         {
           /* By using the following table of function calls, code-doubled functions 
           * are called from the indexed CCL. This is done to simplify the called 
           * functions (no distinction of the parameter 'channel' is necessary). */
           (CclSleepTrcvFctTbl[CCL_CHANNEL_CCLINDEX])();
         }
#    else
         CclSleepTrcvFct();
#    endif
#  endif


         /* set the CCL state to SLEEP */
         cclNmState[CCL_CHANNEL_CCLINDEX] = kCclStateSleep;

         /* set the bus state to off */
         cclBusState[CCL_CHANNEL_CCLINDEX] = kCclBusOff;


#if defined(CCL_USE_REQUEST_CLEARCOM_FCT)
         {
           /* communication release notification */
#  if(kCclNrOfChannels > 1)
           if(CclComRelFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
           {
             /* By using the following table of function calls, code-doubled functions 
              * are called from the indexed CCL. This is done to simplify the called 
              * functions (no distinction of the parameter 'channel' is necessary). */
             (CclComRelFctTbl[CCL_CHANNEL_CCLINDEX])();
           }
#  else
         CclComRelFct();
#  endif
         }
#endif

#if defined(CCL_ENABLE_TRCV_PORT_INT)
#  if defined(CCL_ENABLE_INTERNAL_REQUEST)
         if(cclIntNetReq[CCL_CHANNEL_CCLINDEX] == kCclNoIntNetReq)
         {
           /* no internal request is pending */
#  endif
           /* enable transceiver port interrupt */
#  if( kCclNrOfChannels > 1 )
           /* By using the following table of function calls, code-doubled functions 
           * are called from the indexed CCL. This is done to simplify the called 
           * functions (no distinction of the parameter 'channel' is necessary). */
           /* Wtihin the following function calls a maybe pending 
           *  Transceiver interrupt will be cleared! */
           if(CclClearTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
           {
             (CclClearTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
           }
           if(CclEnableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
           {
             (CclEnableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
           }
#  else
           /* Within the following function calls a maybe pending 
           *  Transceiver interrupt will be cleared! */
           CclClearTrcvIntFct();
           CclEnableTrcvIntFct();
#  endif

           /* set INT state to "enable" */
           cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] = kCclEnableWakeUpInt;

#  if defined(CCL_ENABLE_TRCV_PORT_EDGE_TRIGGER)
           /* check transceiver port register */
#    if( kCclNrOfChannels > 1 )
           if(CclCheckTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX]() == kCclTrcvWakeIntPending)
           {
             /* By using the following table of function calls, code-doubled functions 
             * are called from the indexed CCL. This is done to simplify the called 
             * functions (no distinction of the parameter 'channel' is necessary). */

             /* disable transceiver port interrupt */
             if(CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
             {
               (CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
             }
#    else
             if(CclCheckTrcvIntFct() == kCclTrcvWakeIntPending)
             {
               /* disable transceiver port interrupt */
               CclDisableTrcvIntFct();
#    endif

               /* check INT state */
               if(cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] == kCclEnableWakeUpInt)
               {
                 /* external EMC/CAN wake up notification */
                 CclCanWakeUpInt(CCL_CHANNEL_CCLPARA_ONLY);
               }
             }
#  endif
#  if defined(CCL_ENABLE_INTERNAL_REQUEST)
           }
#  endif
#endif

       }

#if defined(CCL_ENABLE_EXTERNAL_REQUEST) 
#  if defined(CCL_ENABLE_SLEEP_REPETITION)
       cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = ApplCclCanStandby(CCL_CHANNEL_CCLPARA_FIRST cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX]);

       CclAssert( ( ((cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] == kCclNoRepeatCanSleep) && (cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] == kCanOk)) || \
                        ((cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] == kCclNoRepeatCanSleep) && (cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] == kCanNotSupported)) || \
                        ((cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] == kCclRepeatCanSleep) && (cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] == kCanFailed)) \
                       ), kWrongReturnValue)

#  else
       (void)ApplCclCanStandby(CCL_CHANNEL_CCLPARA_FIRST cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX]);
#  endif
#endif



#if defined(CCL_ENABLE_INTERNAL_REQUEST)
#  if defined(CCL_USE_REQUEST_SETINTCOM_FCT) 
        if(cclIntNetReq[CCL_CHANNEL_CCLINDEX] != kCclNoIntNetReq)
       {
         /* min. one internal request is pending */
#    if defined( CCL_USE_REQUEST_SETINTCOM_FCT )
#      if defined(CCL_ENABLE_EXTERNAL_REQUEST) 
         /* check "CanSleep" return code */
         if(cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] != kCanFailed) /* ESCAN00022602 */
#      endif
         {

           {
           
             /* internal communication request notification */
#      if ( kCclNrOfChannels > 1 )
             if (CclIntComReqFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
             {
               /* By using the following table of function calls, code-doubled functions 
                * are called from the indexed CCL. This is done to simplify the called 
                * functions (no distinction of the parameter 'channel' is necessary). */
               (CclIntComReqFctTbl[CCL_CHANNEL_CCLINDEX])();
             }
#      else
             CclIntComReqFct();
#      endif
           }
         }
#    endif

       }
#  endif
#endif
      }
    }
  }

  CanGlobalInterruptRestore();
 }


#if (defined( CCL_ENABLE_EXTERNAL_REQUEST) ||\
     defined( CCL_ENABLE_INTERNAL_REQUEST))
/************************************************************************
| NAME:               CclTask
| PROTOTYPE:          void CclTask( void )
| CALLED BY:          generated task container function
|                     Application is NOT ALLOWED to call this function!
| PRECONDITIONS:
| INPUT PARAMETERS:   void
| RETURN VALUE:       void
| DESCRIPTION:        internal network request handling
|                     internal network release handling
|                     external channel request handling
|                     EMC wake up timeout handling
|                     sleep repetition handling
|*************************************************************************/
void CCL_API_CALL_TYPE CclTask(void)
 {
#  if(kCclNrOfChannels > 1)
   CanChannelHandle channel; /* number of physical channels */
#  endif


#  if(kCclNrOfNetworks > 1)
   vuint8 network; /* number of logical networks */
#  endif


#  if(kCclNrOfChannels > 1)
   channel = 0;
#  endif


#  if(kCclNrOfNetworks > 1)
   network = 0;
#  endif




#  if(kCclNrOfNetworks > 1)
   for(network=0; network<kCclNrOfNetworks; network++)
   {
#  endif
     /* ESCAN00010661 
      *  Disable the global interrupt to guarantee data consistency 
      *  if this function is called from interrupt insted of task level. */

#    if(kCclNrOfChannels > 1)
     channel = (CanChannelHandle)network;
#    endif

#  if defined (CCL_ENABLE_MULTIPLE_CONFIG)
     if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > 0x00)
     {
#  endif    
     
     /* check HW communication state */
     if(cclComHwState[CCL_CHANNEL_CCLINDEX] == kCclComHwEnabled)
     {
#  if defined( CCL_ENABLE_INTERNAL_REQUEST )
       
#    if defined(CCL_ENABLE_NMSTARTUP_TIMER)
/* ===================================================================== */
/* = begin "NM startup timer handling" ================================= */
/* ===================================================================== */
         /* timer is activated? */
         if(cclNmStartupTimer[CCL_CHANNEL_CCLINDEX] != kCclNmStartupTimerStopped)
         {
           /* decrement timer */
           cclNmStartupTimer[CCL_CHANNEL_CCLINDEX]--;

           /* timer is expired? */
           if(cclNmStartupTimer[CCL_CHANNEL_CCLINDEX] == kCclNmStartupTimerExpired)
           {
             /* release communication request of the CCL system user */
             CclReleaseCommunication(CCL_CHANNEL_CCLINDEX);
           }
         }
/* ===================================================================== */
/* = end   "NM startup timer handling" ================================= */
/* ===================================================================== */
#    endif


#    if defined(CCL_ENABLE_NPM_SUPPORT)
#      if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
         if(cclNpmHandling[CCL_CHANNEL_CCLINDEX] == kCclNpmOn)
         {
           /* ESCAN00028492 */
           /* Ignore NPM messages in state WaitBusSleep or Sleep: */
           CanGlobalInterruptDisable();
           if( cclNmState[CCL_CHANNEL_CCLINDEX] > kCclStateWaitBusSleep )
           {
             
             if( (vuint8)(cclNpmMsgDataTmp[CCL_CHANNEL_CCLINDEX] & 0x01) == kCclNpmMessageReceived)
             { 
               /* copy the NPM message information into an internal shadow buffer */
               cclNpmMsgData[CCL_CHANNEL_CCLINDEX] = cclNpmMsgDataTmp[CCL_CHANNEL_CCLINDEX];
               /* clear the NPM message resceived flag */
               cclNpmMsgDataTmp[CCL_CHANNEL_CCLINDEX] &= kCclNpmMessageReceivedClear;
             }
           }
           else
           {
             /* clear message flag, NPM messages in this state are ignored: */
             cclNpmMsgDataTmp[CCL_CHANNEL_CCLINDEX] &= kCclNpmMessageReceivedClear;
           }
           CanGlobalInterruptRestore();

           if( (vuint8)(cclNpmMsgData[CCL_CHANNEL_CCLINDEX] & 0x01) == kCclNpmMessageReceived)
           { 
             /* NPM message was resceived, 
               * restart NPM message timeout timer
               */
             cclNpmMessageTimeout[CCL_CHANNEL_CCLINDEX] = cclNpmMsgTimeoutValue[CCL_CHANNEL_CCLINDEX];
             /* clear the NPM message resceived flag */
             cclNpmMsgData[CCL_CHANNEL_CCLINDEX] &= kCclNpmMessageReceivedClear;
             /* clear the NPM message timeout flag */
             cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmMessageTimeoutClear;

             /* ESCAN00028368 */
             if(cclNpmIgnitionState == kCclNpmIgnitionOff)
             {
               /* NPM is enabled, NPM message received, ignition is off. If PW or FS is enabled in the message data set
                * the NPM state to valid: */
#        if defined(CCL_ENABLE_FORCE_SHUTDOWN)
               if( (vuint8)(cclNpmMsgData[CCL_CHANNEL_CCLINDEX] & 0x04) == kCclNpmForceShutdownOn )
               {
                 cclNpmState[CCL_CHANNEL_CCLINDEX] |= kCclNpmForceShutdownValid;
               }
               else
               {
                 cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmForceShutdownInvalid;
                 
                 cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] &= kCclNpmFsdNotTriggered;
               }
#        endif
#        if defined(CCL_ENABLE_PREVENT_WAKEUP)
               if( (vuint8)(cclNpmMsgData[CCL_CHANNEL_CCLINDEX] & 0x02) == kCclNpmPreventWakeUpOn)
               {
                 cclNpmState[CCL_CHANNEL_CCLINDEX] |= kCclNpmPreventWakeUpValid;
               }
               else
               {
                 cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmPreventWakeUpInvalid;
                 
                 cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] &= kCclNpmPwuNotTriggered;
               }
#        endif
             }

#        if defined(CCL_ENABLE_FORCE_SHUTDOWN)
             if(cclNmStartupTimer[CCL_CHANNEL_CCLINDEX] == kCclNmStartupTimerExpired)
             {
               /* the startup timer is expired,
                * check the force shutdown state
                */
               CclNpmCheckForceShutdownState(CCL_CHANNEL_CCLPARA_ONLY);
               if( (vuint8)(cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmForceShutdownOn) == kCclNpmForceShutdownOn )
               {
                 /* force shutdown is active,
                  * deactivate the network request handling and
                  * start the state transition from normal to sleep
                  */
                 CclNpmSetPwuFsRestriction(CCL_NET_CCLPARA_ONLY);
               }
             }
#        endif
           }

#        if defined(CCL_ENABLE_PREVENT_WAKEUP) 
           /* check the prevent wake up state */
           CclNpmCheckPreventWakeUpState(CCL_CHANNEL_CCLPARA_ONLY);
#        endif
         }
#      endif
#    endif
#  endif
         CanGlobalInterruptDisable();
#  if defined( CCL_ENABLE_INTERNAL_REQUEST )
/* ===================================================================== */
/* = begin "internal network request handling" ========================= */
/* ===================================================================== */
         
           /* pending internal network request? */
           if((cclIntNetReq[CCL_NET_CCLINDEX] != kCclNoIntNetReq))
           {

               /* ESCAN00026441 */
               if(cclNmState[CCL_CHANNEL_CCLINDEX] < kCclNmStateActive)
               {

                   /* container function for transition from SLEEP or GO TO SLEEP to ACTIVE */


#      if(kCclNrOfChannels > 1)
                   /* By using the following table of function calls, code-doubled functions 
                    * are called from the indexed CCL. This is done to simplify the called 
                    * functions (no distinction of the parameter 'channel' is necessary). */
                  (void)CclNmActiveReqFctTbl[CCL_NET_CCLINDEX](cclIntNetReq[CCL_NET_CCLINDEX]);
#      else
                  (void)CclNmActiveReqFct(cclIntNetReq[CCL_NET_CCLINDEX]);
#      endif

#    if defined(CCL_ENABLE_NMSTARTUP_TIMER)
                 if(cclNmState[CCL_CHANNEL_CCLINDEX] < kCclStateGoToSleep)
                 {
                   /* the CCL state is sleep or wait bus sleep,
                    * check for using a wake up able network management */
                   if((cclNmWakeUpAble & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) != kCclNoWakeUpAble )
                   {
                     (void)CclRequestCommunication(CCL_CHANNEL_CCLINDEX);
                     /* start NPM message observe timer */
                     cclNmStartupTimer[CCL_CHANNEL_CCLINDEX] = cclNmStartupTimerValue[CCL_CHANNEL_CCLINDEX];
                   }
                 }
#    endif





                 /* set CCL state to ACTIVE */
                 cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateActive;
             
                 /* ESCAN00026441 */
               }

                 
               /* clear internal network request flag */
               cclIntNetReq[CCL_NET_CCLINDEX] = kCclNoIntNetReq;

               /* clear internal network release history flag */
               cclIntNetRelHistory[CCL_NET_CCLINDEX] = kCclNoIntNetRel;

#    if defined( CCL_ENABLE_EXTERNAL_REQUEST )

               /* clear external CAN channel request flag */
               cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq;

#      if defined(CCL_ENABLE_SLEEP_REPETITION)
               /* stop sleep repetition handling */
               cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = kCclNoRepeatCanSleep;
#      endif
#    endif
           }

/* ===================================================================== */
/* = end "internal network request handling" =========================== */
/* ===================================================================== */

/* ===================================================================== */
/* = begin "internal network release handling" ========================= */
/* ===================================================================== */
         if( (cclIntNetRel[CCL_NET_CCLINDEX] != kCclNoIntNetRel) )
         {
           /* no communication request is pending,
            * set the CCL state to prepare sleep */

           cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateGoToSleep;

           /* container function for transition from active to prepare sleep */
#    if ( kCclNrOfChannels > 1 )
           /* By using the following table of function calls, code-doubled functions 
            * are called from the indexed CCL. This is done to simplify the called 
            * functions (no distinction of the parameter 'channel' is necessary). */
           (CclNmSleepReqFctTbl[CCL_CHANNEL_CCLINDEX])(cclIntNetRel[CCL_NET_CCLINDEX]);
#    else
           CclNmSleepReqFct(cclIntNetRel[CCL_NET_CCLINDEX]);
#    endif
           


           /* clear internal network release flag */
           cclIntNetRel[CCL_NET_CCLINDEX] = kCclNoIntNetRel;

           /* clear internal network release history flag */
           cclIntNetRelHistory[CCL_NET_CCLINDEX] = kCclNoIntNetRel;


         }
/* ===================================================================== */
/* = end "internal network release handling" =========================== */
/* ===================================================================== */
#  endif

#  if defined(CCL_ENABLE_EXTERNAL_REQUEST)
/* ===================================================================== */
/* = begin "external channel request handling" ========================= */
/* ===================================================================== */

         /* pending external CAN channel request? */
         if(cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] == kCclExtChWupReq)
         {
           {

             if( cclNmState[CCL_CHANNEL_CCLINDEX] < kCclNmStateGoToSleep )
             {


               if( cclNmState[CCL_CHANNEL_CCLINDEX] == kCclNmStateSleep )
               {

                 /* set CCL state to prepare sleep */
                 cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateGoToSleep;

                 /* container function for transition from sleep to prepare sleep */
#      if(kCclNrOfChannels > 1)
                 /* By using the following table of function calls, code-doubled functions 
                  * are called from the indexed CCL. This is done to simplify the called 
                  * functions (no distinction of the parameter 'channel' is necessary). */
                 (CclNmPrepareSleepReqFctTbl[CCL_CHANNEL_CCLINDEX])();
#      else
                 CclNmPrepareSleepReqFct();
#      endif



               }
               else
               {
                 /* set CCL state to prepare sleep */
                 cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateGoToSleep;
               }


#      if defined(CCL_ENABLE_SLEEP_REPETITION)
               /* stop sleep repetition handling */
               cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = kCclNoRepeatCanSleep;
#      endif



#      if defined(CCL_ENABLE_NMSTARTUP_TIMER)
               /* the CCL starts up from sleep or wait bus sleep */
               /* set communication request of the CCL system user */
               (void)CclRequestCommunication(CCL_CHANNEL_CCLINDEX);
               /* start NPM message observe timer */
               cclNmStartupTimer[CCL_CHANNEL_CCLINDEX] = cclNmStartupTimerValue[CCL_CHANNEL_CCLINDEX];
#      endif




           }
             /* clear external CAN channel request flag */
             cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq;
           }
         }
/* ===================================================================== */
/* = end "external channel request handling" =========================== */
/* ===================================================================== */




#    if defined(CCL_ENABLE_SLEEP_REPETITION)
/* ===================================================================== */
/* = begin "sleep repetition handling" =================================== */
/* ===================================================================== */
         /* check sleep repetition handling */
         if(cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] != kCclNoRepeatCanSleep)
         {
           /* sleep repetition is active,
            * set CAN communication (HW and SW) to SLEEP
            */
           CclCanStandby(CCL_CHANNEL_CCLPARA_ONLY);
         }
/* ===================================================================== */
/* = end "sleep repetition handling" =================================== */
/* ===================================================================== */
#    endif



#  endif


         CanGlobalInterruptRestore();
     }
#  if defined(CCL_ENABLE_NPM_SUPPORT)
#    if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
         CanGlobalInterruptDisable();
/* ===================================================================== */
/* = begin "NPM Message timeout observe" =================================== */
/* ===================================================================== */
         /* check NPM message timer */
         if(cclNpmMessageTimeout[CCL_CHANNEL_CCLINDEX] != kCclNpmMessageTimerStopped)
         {
           /* timer is active,
            * decrement timer
            */
           cclNpmMessageTimeout[CCL_CHANNEL_CCLINDEX]--;

           /* check NPM timer*/
           if(cclNpmMessageTimeout[CCL_CHANNEL_CCLINDEX] == kCclNpmMessageTimerExpired)
           {
             /* reset force shutdown / prevent wake up triggered flags: */
             cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] = 0x00;

             /* NPM message timer expired */
#      if defined(CCL_ENABLE_PREVENT_WAKEUP)
             /* disable prevent wake up */
             cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmPreventWakeUpOff;
             /* prevent wake up is not valid anymore */
             cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmPreventWakeUpInvalid;
             
             /* disable prevent wake up in the internal NPM message shadow buffer */
             cclNpmMsgData[CCL_CHANNEL_CCLINDEX] &= kCclNpmPreventWakeUpOff;
             /* clear NPM message shadow buffer */
             cclNpmMsgDataTmp[CCL_CHANNEL_CCLINDEX] = 0x00;
#      endif
             cclNpmState[CCL_CHANNEL_CCLINDEX] |= kCclNpmMessageTimeoutOccur;
#      if defined(CCL_ENABLE_FORCE_SHUTDOWN)
             /* force shutdown is not valid anymore */
             cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmForceShutdownInvalid;
                      
             /* check the NPM force shutdown force shutdown state */
             if( (vuint8)(cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmForceShutdownOn) == kCclNpmForceShutdownOn)
             {
               /* force shutdown is off,
                * activate the communication request handling
                */
               CclNpmClearPwuFsRestriction(CCL_CHANNEL_CCLPARA_ONLY);
               /* disable prevent wake up */
               cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmForceShutdownOff;
               /* disable prevent wake up in the internal NPM message shadow buffer */
               cclNpmMsgData[CCL_CHANNEL_CCLINDEX] &= kCclNpmForceShutdownOff;
               /* inform the application about the force shutdown state change to off */
               ApplCclNpmForceShutdown(CCL_CHANNEL_CCLPARA_FIRST kCclNpmForceShutdownOff);
             }
#      endif
             /* inform the application about the timout via a callback function */
             ApplCclNpmMsgTimeout(CCL_CHANNEL_CCLPARA_ONLY);
           }
         }
/* ===================================================================== */
/* = end   "NPM Message timeout observe" ==================================== */
/* ===================================================================== */
         /* ESCAN00010661 
          *  Disable the global interrupt to guarantee data consistency 
          *  if this function is called from interrupt instead of task level. */
         CanGlobalInterruptRestore();
#    endif
#  endif
#  if defined (CCL_ENABLE_MULTIPLE_CONFIG)
    }
#  endif
#  if(kCclNrOfNetworks > 1)
  }
#  endif
}
#endif


/************************************************************************
| NAME:               CclInit
| PROTOTYPE:          void CclInit(CanChannelHandle channel)
|                     or
|                     void CclInit(void)
| CALLED BY:          Application during startup the system or while runtime
| PRECONDITIONS:      -
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        channel specific initialisation of CCL and CANbedded stack
|*************************************************************************/
#if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
void CCL_API_CALL_TYPE CclInit(CCL_CHANNEL_CCLTYPE_FIRST CCL_NM_INITPOINTER_TYPE)
#else
void CCL_API_CALL_TYPE CclInit(CCL_CHANNEL_CCLTYPE_ONLY)
#endif
 {

#if defined( CCL_ENABLE_INTERNAL_REQUEST)
   vuint8 count;
#endif

#if (kCclNrOfChannels > 1 )
  CclAssert(channel < kCclNrOfChannels ,kCclWrongChannelHandle)
#endif

#if defined( CCL_ENABLE_ERROR_HOOK)
   cclChannelNumber = 0; /* init channel number */
   cclErrorCode     = 0; /* init error code */
   cclErrorLine     = 0; /* init error line */
   cclComponentID   = 0; /* init component ID */
#endif


#if defined( CCL_ENABLE_EXTERNAL_REQUEST )
   /* clear the external CAN channel request flag */
   cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] = kCclNoExtChWupReq;

#    if defined CCL_ENABLE_SLEEP_REPETITION
   /* deactivate sleep repetition */
   cclCanSleepRepetition[CCL_CHANNEL_CCLINDEX] = kCclNoRepeatCanSleep;
#    endif
   /* set the default value kCanOk of the CanSleep return value */
   cclCanSleepReturnCode[CCL_CHANNEL_CCLINDEX] = kCanOk;
#endif

#if defined( CCL_ENABLE_SW_COM_STATE )
   /* disable communication SW state */
   cclComSwState[CCL_CHANNEL_CCLINDEX] = kCclComSwOff;
#endif




#if defined (CCL_ENABLE_MULTIPLE_CONFIG)
   if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > 0x00)
   {
#endif




#if defined(NM_TYPE_NMHIGH)
#  if ( kCclNrOfChannels > 1 )
     if( cclNmType[CCL_CHANNEL_CCLINDEX] == kComponentNmHigh)
     {
#  endif
       /* ESCAN00037523 */
       cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateGoToSleep;
#  if ( kCclNrOfChannels > 1 )
     }
     else
     {
       cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateActive;
     }
#  endif
#else
     cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateActive;
#endif
     

     /* enable communication HW state */
     cclComHwState[CCL_CHANNEL_CCLINDEX] = kCclComHwEnabled;

     /* set CCL bus state to on */
     cclBusState[CCL_CHANNEL_CCLINDEX] = kCclBusOn;

#if defined (CCL_ENABLE_MULTIPLE_CONFIG)
   }
   else
   {


     /* set CCL state to sleep */
     cclNmState[CCL_CHANNEL_CCLINDEX] = kCclNmStateSleep;

#  if defined(NM_TYPE_NMHIGH)
     cclStateTmp[CCL_CHANNEL_CCLINDEX] = kCclNmStateSleep;
#  endif

     /* disable communication HW state */
     cclComHwState[CCL_CHANNEL_CCLINDEX] = kCclComHwDisabled;

     /* set CCL bus state to of */
     cclBusState[CCL_CHANNEL_CCLINDEX] = kCclBusOff;
   }
#endif

   
#if defined( CCL_ENABLE_INTERNAL_REQUEST )

   {
     {
       for(count=cclStartIndex[CCL_NET_CCLINDEX]; count<=cclStopIndex[CCL_NET_CCLINDEX]; count++)
       {
         /* clear communication request field */
         cclIntNetState[count] = 0x00;
       }

       /* clear internal network request flag */
       cclIntNetReq[CCL_NET_CCLINDEX] = kCclNoIntNetReq;

       /* clear internal network release flag */
       cclIntNetRel[CCL_NET_CCLINDEX] = kCclNoIntNetRel;

       /* clear internal network release history flag */
       cclIntNetRelHistory[CCL_NET_CCLINDEX] = kCclNoIntNetRel;
     }
   }



#endif



#if defined(NM_TYPE_NMHIGH)
   cclStateTmp[CCL_CHANNEL_CCLINDEX] = kCclStateSleep;
#endif






   

#if defined(CCL_ENABLE_NMSTARTUP_TIMER)
   cclNmStartupTimer[CCL_CHANNEL_CCLINDEX] = kCclNmStartupTimerStopped;
#endif

#if  defined(CCL_ENABLE_NPM_SUPPORT)
#  if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
   /* stop NPM message timeout observation */
   cclNpmMessageTimeout[CCL_CHANNEL_CCLINDEX] = kCclNpmMessageTimerStopped;
#  endif
#endif



#if defined(CCL_ENABLE_POSRES_FBL)
  cclPosRespData[CCL_CHANNEL_CCLINDEX] = kDescSendFblPosRespDscDefault;
  cclSendPosRespFbl[CCL_CHANNEL_CCLINDEX] = kCclSendNoPosResp;
#endif






#if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
#  if ( ((defined NM_TYPE_NMHIGH) && (kNmhNumberOfChannels > 1)) ) /* ESCAN00022670 */
#    if (kCclNrOfChannels > 1)  
  switch (CCL_CHANNEL_CCLINDEX)
  {
    case 0:
#    endif
      CclValidateNmInitValue( CCL_CHANNEL_CCLPARA_FIRST cclNmInitPointer->cclNmInit_0 );            

#    if (kCclNrOfChannels > 1)
      break;
              
    case 1:
      CclValidateNmInitValue( CCL_CHANNEL_CCLPARA_FIRST cclNmInitPointer->cclNmInit_1 );             
      break;
#    endif

#    if (kCclNrOfChannels > 2)
    case 2:
      CclValidateNmInitValue( CCL_CHANNEL_CCLPARA_FIRST cclNmInitPointer->cclNmInit_2 );             
      break;
#    endif

#    if (kCclNrOfChannels > 3)
    case 3:
      CclValidateNmInitValue( CCL_CHANNEL_CCLPARA_FIRST cclNmInitPointer->cclNmInit_3 );             
      break;
#    endif

#    if (kCclNrOfChannels > 4)
    case 4:
      CclValidateNmInitValue( CCL_CHANNEL_CCLPARA_FIRST cclNmInitPointer->cclNmInit_4 );             
      break;
#    endif

#    if (kCclNrOfChannels > 5)
    case 5:
      CclValidateNmInitValue( CCL_CHANNEL_CCLPARA_FIRST cclNmInitPointer->cclNmInit_5 );             
       break;
#    endif

#    if (kCclNrOfChannels > 6)
    case 6:
     CclValidateNmInitValue( CCL_CHANNEL_CCLPARA_FIRST cclNmInitPointer->cclNmInit_6 );             
      break;
#    endif

#    if (kCclNrOfChannels > 7)
    case 7:
      CclValidateNmInitValue( CCL_CHANNEL_CCLPARA_FIRST cclNmInitPointer->cclNmInit_7 );             
      break;
#    endif

#    if (kCclNrOfChannels > 1) 
       default:
         break;
      }
#    endif
#  endif
#endif


#  if( CCL_DLL_VERSION < 0x0106 )
#  else
   /* check initialisation type flag */
#    if defined( CCL_ENABLE_CANBEDDED_HANDLING )
   if(cclStackInit == kCclChannelSpecificInit)
   {
     /* re-initialisation is active */
     /* call container function for CANbedded re-initialisation */
#      if(kCclNrOfChannels > 1)
     /* By using the following table of function calls, code-doubled functions 
     * are called from the indexed CCL. This is done to simplify the called 
     * functions (no distinction of the parameter 'channel' is necessary). */
     (CclInitFctTbl[CCL_CHANNEL_CCLINDEX])(CCL_NM_INITPOINTER_PARA);
#      else
     CclInitFct(CCL_NM_INITPOINTER_PARA);
#      endif
   }
#    endif
#  endif
 }

/************************************************************************
| NAME:               CclInitPowerOn
| CALLED BY:          Application during startup the system or while runtime
| PRECONDITIONS:      global interrupts have to be disabled
| RETURN VALUE:       void
| DESCRIPTION:        system specific initialisation of CCL and CANbedded stack
|*************************************************************************/
#if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
void CCL_API_CALL_TYPE CclInitPowerOn(CCL_ECUS_NODESTYPE_FIRST CCL_NM_INITPOINTER_TYPE)
#else
 void CCL_API_CALL_TYPE CclInitPowerOn(CCL_ECUS_NODESTYPE_ONLY)
#endif
{
#if(kCclNrOfChannels > 1)
   CanChannelHandle channel;
#endif

#if defined(CCL_ENABLE_NPM_SUPPORT)
#  if defined(CCL_ENABLE_PREVENT_WAKEUP)
   vuint8 cclNpmEEPROMPwuState;
#  endif
#endif


#if defined(CCL_ENABLE_NPM_SUPPORT)
#  if defined(CCL_ENABLE_PREVENT_WAKEUP)
   cclNpmEEPROMPwuState = kCclNpmPreventWakeUpOff;
#  endif
#endif

#  if( CCL_DLL_VERSION < 0x0106 )
#  else
#    if defined( CCL_ENABLE_CANBEDDED_HANDLING ) 
   /* clear repeated initialisation flag */
   cclStackInit = kCclSystemSpecificInit;
#    endif
#  endif


#if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
#  if(kCclNrOfChannels > 1)
   /* initialize channel variable, needed for assertion */
   channel = (CanChannelHandle)0;
#  endif
   /* check NM initialization pointer: */
   CclAssert(cclNmInitPointer != V_NULL, kCclErrNullPointer)

#  if defined ( NM_TYPE_NMHIGH )  /* ESCAN00022670 */
#    if (kNmhNumberOfChannels > 1)
   /* initialize NM High initialization variable */
   cclOldNmHighInitValue = kCclNmhInitValue;
#    endif
#  endif
#endif   

#if defined( CCL_ENABLE_CANBEDDED_HANDLING )
#  if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   /* set active identity */
   VSetActiveIdentity(CCL_ECUS_NODESPARA_ONLY)
#  endif
#endif

#if(kCclNrOfChannels > 1)
   /* init channel parameters */
   for(channel=0; channel<(CanChannelHandle)kCclNrOfChannels; channel++)
#endif
   {
     /* initialize the transceiver ports */
     CclInitPorts(CCL_CHANNEL_CCLPARA_ONLY);

     /* inititialize the communication control layer */
#if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
     CclInit(CCL_CHANNEL_CCLPARA_FIRST CCL_NM_INITPOINTER_PARA); /* ESCAN00021604 */
#else  /* ESCAN00021870 */
     CclInit(CCL_CHANNEL_CCLPARA_ONLY);
#endif

#if defined(CCL_ENABLE_NPM_SUPPORT)
#  if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
     /* clear NPM state */
     cclNpmState[CCL_CHANNEL_CCLINDEX] = 0x00;
     /* clear NPM message data information */
     cclNpmMsgData[CCL_CHANNEL_CCLINDEX] = 0x00;

     cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] = 0x00; 

     /* clear NPM message data information shadow buffer */
     cclNpmMsgDataTmp[CCL_CHANNEL_CCLINDEX] = 0x00;
#  if defined(CCL_ENABLE_EEPROM_PREVENT_WAKEUP)
     /* set prevent wake up EEPROM default value to off */
     cclNpmEEPROMPreventWakeUp[CCL_CHANNEL_CCLINDEX] = kCclNpmPreventWakeUpOff;
#  endif
     /* set ignition to off */
     cclNpmIgnitionState = kCclNpmIgnitionOff;
     /* set default value for the prevent wake up and force shutdown restriction */
     cclNpmPwuFsRestriction[CCL_CHANNEL_CCLINDEX] = kCclNpmPwuFsRestrictionOff;


#    if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > 0x00)
     {
#    endif
       cclNpmHandling[CCL_CHANNEL_CCLINDEX] = kCclNpmOn;
#    if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     }
     else
     {
       cclNpmHandling[CCL_CHANNEL_CCLINDEX] = kCclNpmOff;
     }
#    endif
#  endif
#endif

#if defined(CCL_ENABLE_NPM_SUPPORT)
#  if defined(CCL_ENABLE_PREVENT_WAKEUP)
#    if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > 0x00)
#    endif
     {
#      if defined(CCL_ENABLE_EEPROM_PREVENT_WAKEUP)
       /* get the EEPROM prevent wake up value */
       cclNpmEEPROMPwuState = ApplCclNpmReadPwuStateFromNVRAM(CCL_CHANNEL_CCLPARA_ONLY);     
#      endif
       
       if(cclNpmEEPROMPwuState == kCclNpmPreventWakeUpOn)
       {
         /* prevent wake up is active,
          * store the EEPROM value for further handling */
         cclNpmEEPROMPreventWakeUp[CCL_CHANNEL_CCLINDEX] = kCclNpmPreventWakeUpOn;
         /* activate prevent wake up */
         cclNpmMsgData[CCL_CHANNEL_CCLINDEX] |= kCclNpmPreventWakeUpOn;
         /* activate prevent wake up */
         cclNpmMsgDataTmp[CCL_CHANNEL_CCLINDEX] |= kCclNpmPreventWakeUpOn;
         /* prevent wake up is valid for this channel: */
         cclNpmState[CCL_CHANNEL_CCLINDEX] |= kCclNpmPreventWakeUpValid;
       }
     }
#  endif
#endif

   }


#if defined( CCL_ENABLE_CANBEDDED_HANDLING )
#  if defined(CCL_ENABLE_MULTIPLE_NODES)
#    if defined(VGEN_GENY)
   /* set active identity */
   VSetActiveIdentity(CCL_ECUS_NODESPARA_ONLY);
#    else
   /* set common multiple ECU handle for CAN modules */
   ComSetCurrentECU(CCL_ECUS_NODESPARA_ONLY);
#    endif
#  endif

   /* container function for CANbedded component initialization */
   CclInitPowerOnFct(CCL_NM_INITPOINTER_PARA);
#endif





#if defined( CCL_ENABLE_TRCV_PORT_INT )
   CclAssert(cclNmWakeUpAble!=0,kExtAndIntWakeUp)
#endif

#  if( CCL_DLL_VERSION < 0x0106 )
#  else
#    if defined( CCL_ENABLE_CANBEDDED_HANDLING ) 
   /* set repeated initialisation flag */
   cclStackInit = kCclChannelSpecificInit;
#    endif
#  endif

 }



#if defined(CCL_ENABLE_EXTENDED_NMINIT) /* ESCAN00021604 */
#  if ( ((defined NM_TYPE_NMHIGH) && (kNmhNumberOfChannels > 1)) ) /* ESCAN00022670 */
/************************************************************************
| NAME:               CclValidateNmInitValue
| CALLED BY:          CCL
| PRECONDITIONS:
| INPUT PARAMETERS:   CAN channel, NM initialization parameter value
| RETURN VALUE:       void
| DESCRIPTION:        validate init pointer and set NM Osek activation timer
|*************************************************************************/
static void CclValidateNmInitValue( CCL_CHANNEL_CCLTYPE_FIRST tCclNmInitParaType nmInitValue)
{





#    if defined ( NM_TYPE_NMHIGH )  /* ESCAN00022670 */
#      if (kNmhNumberOfChannels > 1)
  if (cclNmType[CCL_CHANNEL_CCLINDEX] == kComponentNmHigh)
  {
    /* NM High part: check if init value is already set: */
    if (cclOldNmHighInitValue == kCclNmhInitValue)
    {
      /* this is the first time the init value is set, save this value: */
      cclOldNmHighInitValue = (vuint8)nmInitValue;
    }
    else
    {
      /* check value with assertion: */
      CclAssert(cclOldNmHighInitValue == (vuint8)nmInitValue, kCclErrInvalidNmHInitValue)
    }
  }
#      endif
#    endif
    
}
#  endif
#endif



#if defined(CCL_ENABLE_SYSTEM_STARTUP)
/************************************************************************
| NAME:               CclSystemStartup
| PROTOTYPE:          void CclSystemStartup(void)
| CALLED BY:          Application
| PRECONDITIONS:
| INPUT PARAMETERS:   void
| RETURN VALUE:       void
| DESCRIPTION:        startup handling of CANbedded stack
|*************************************************************************/
void CCL_API_CALL_TYPE CclSystemStartup(void)
 {
#if(kCclNrOfChannels > 1)
   CanChannelHandle channel;

   /* init channel parameters */
   for(channel=0; channel<(CanChannelHandle)kCclNrOfChannels; channel++)
   {
     /* By using the following table of function calls, code-doubled functions 
     * are called from the indexed CCL. This is done to simplify the called 
     * functions (no distinction of the parameter 'channel' is necessary). */

     /* system startup notification */
     (CclSystemStartupFctTbl[CCL_CHANNEL_CCLINDEX])();
   }
#else
   /* system startup notification */
   CclSystemStartupFct();
#endif
 }
#endif


#if defined(CCL_ENABLE_SYSTEM_SHUTDOWN)
/************************************************************************
| NAME:               CclSystemShutdown
| PROTOTYPE:          void CclSystemShutdown(void)
| CALLED BY:          Application
| PRECONDITIONS:      This function has to be called with disabled global
|                     interrupts.
| INPUT PARAMETERS:   void
| RETURN VALUE:       void
| DESCRIPTION:        shutdown handling of CANbedded stack
|*************************************************************************/
void CCL_API_CALL_TYPE CclSystemShutdown(void)
 {

#  if(kCclNrOfChannels > 1)
   CanChannelHandle channel;
#  endif


#  if(kCclNrOfChannels > 1)
   /* init channel parameters */
   for(channel=0; channel<(CanChannelHandle)kCclNrOfChannels; channel++)
#  endif
   {
#  if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > 0x00)
     {
#  endif
     /* By using the following table of function calls, code-doubled functions 
     * are called from the indexed CCL. This is done to simplify the called 
     * functions (no distinction of the parameter 'channel' is necessary). */
#  if(kCclNrOfChannels > 1)
       /* system shutdown notification */
       (CclSystemShutdownFctTbl[CCL_CHANNEL_CCLINDEX])();
#  endif
#  if defined(CCL_ENABLE_MULTIPLE_CONFIG)
     }
#  endif
   }
#  if(kCclNrOfChannels > 1)
#  else

     CclSystemShutdownFct();
#  endif

 }
#endif


#if defined(CCL_ENABLE_ERROR_PIN)
/************************************************************************
| NAME:               CclGetErrorPort
| PROTOTYPE:          vuint8 CclGetErrorPort(CanChannelHandle channel)
|                     or
|                     vuint8 CclGetErrorPort(void)
| CALLED BY:          Application
| PRECONDITIONS:
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       state of transceiver error port
| DESCRIPTION:        returns the current transceiver error port state
|*************************************************************************/
vuint8 CCL_API_CALL_TYPE CclGetErrorPort(CCL_CHANNEL_CCLTYPE_ONLY)
 {
   /* get transceiver error port value */
#if(kCclNrOfChannels > 1)
   /* By using the following table of function calls, code-doubled functions 
   * are called from the indexed CCL. This is done to simplify the called 
   * functions (no distinction of the parameter 'channel' is necessary). */
   if(CclGetTrcvErrorPortFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
   {
     return (CclGetTrcvErrorPortFctTbl[CCL_CHANNEL_CCLINDEX])();
   }
   else
   {
     /* no transceiver error port information available */
     return kCclNoErrPort;
   }
#  else
   return CclGetTrcvErrorPortFct();
#  endif
 }
#endif


/************************************************************************
| NAME:               CclGetChannelState
| PROTOTYPE:          vuint8 CclGetChannelState(CanChannelHandle channel)
|                     or
|                     vuint8 CclGetChannelState(void)
| CALLED BY:          Application
| PRECONDITIONS:
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       kCclNmStateSleep, sleep state 
|                     kCclNmStateGoToSleep, prepare sleep state
|                     kCclNmStateActive, normal state
|                     kCclNmPowerFail, power fail state
| DESCRIPTION:        returns the current CCL state
|*************************************************************************/
vuint8 CCL_API_CALL_TYPE CclGetChannelState(CCL_CHANNEL_CCLTYPE_ONLY)
{
  return cclNmState[CCL_CHANNEL_CCLINDEX];
}


#if (defined(CCL_ENABLE_EXTERNAL_REQUEST) &&\
     defined(CCL_ENABLE_TRCV_PORT_INT))
/************************************************************************
| NAME:               CclCanWakeUpInt
| PROTOTYPE:          void CclCanWakeUpInt(CanChannelHandle channel)
|                     or
|                     void CclCanWakeUpInt(void)
| CALLED BY:          application wakeup-ISR
| PRECONDITIONS:      external wakeup port INT via RX/INH of CAN transceiver
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        disable the external wakeup port INT and notify CCL
|                     the wakeup event
|*************************************************************************/
void CCL_API_CALL_TYPE CclCanWakeUpInt(CCL_CHANNEL_CCLTYPE_ONLY)
{
   CclAssert(cclWakeUpIntState[CCL_CHANNEL_CCLINDEX]==kCclDisablePortIRQ, kAssertNotSleepAndTRCVINTactive)

   /* disable port interrupt */
#  if (kCclNrOfChannels > 1)
   /* By using the following table of function calls, code-doubled functions 
   * are called from the indexed CCL. This is done to simplify the called 
   * functions (no distinction of the parameter 'channel' is necessary). */
   if(CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
   {
     (CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
   }
#  else
   CclDisableTrcvIntFct();
#  endif

   /* set INT state to "disable" */
   cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] = kCclDisableWakeUpInt;

   ApplCanWakeUp(CCL_CHANNEL_CANPARA_ONLY);
}
#endif



#if defined( CCL_ENABLE_INTERNAL_REQUEST )
#  if defined( CCL_ENABLE_COM_REQ_HANDLING_API )
/************************************************************************
| NAME:               CclRequestCommunication
| PROTOTYPE:          vuint8 CCL_API_CALL_TYPE CclRequestCommunication(vuint8 cclComHandle)
| CALLED BY:          Application
| PRECONDITIONS:
| INPUT PARAMETERS:   cclComHandle: communication request handle
| RETURN VALUE:       kCclReqOk: the communication request is set correctly
|                     kCclReqFailed: the communication request is stored but
|                                    not handeled
| DESCRIPTION:        request the communication on the CAN channels which
|                     are configured for the cclComHandle
|*************************************************************************/
vuint8 CCL_API_CALL_TYPE CclRequestCommunication(vuint8 cclComHandle)
{
  vuint8 intNetState;
#      if(kCclNetReqTableSize > 1)
  vuint8 index;
#      endif


  vuint8 channel;
  vuint8 retValue;

  /* ESCAN00010661 
   *  Disable the global interrupt to guarantee data consistency 
   *  if this function is called from interrupt insted of task level. */
  CanGlobalInterruptDisable();
 
  /* to avoid compiler warnings */
  channel = 0;
   
  /* set the return value to ok */
  retValue = kCclReqOk;

  /* check for valid communication handle */
  CclAssert( (cclComHandle < kCclNumberOfUser), kCclErrInvalidComHandle)

  channel = cclUserChannel[cclComHandle]; /*lint !e661*/ /* cclComHandle range is checked by an assertion */


#    if defined (CCL_ENABLE_MULTIPLE_CONFIG)
  CclAssert( (cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (channel))) > (vuint8)0x00, kCclWrongChannelHandle)
  
  if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (channel))) > 0x00)
  {
#    endif

  

    intNetState = 0;

    {
#      if defined(CCL_ENABLE_NPM_SUPPORT)
#        if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)  
      if(cclNpmPwuFsRestriction[channel] == kCclNpmPwuFsRestrictionOff)
      {
#        endif
#      endif
        /* the communication request is set the first time for the communication handle,
         * calculate if the request the first for this CAN channel
         */

     

#    if(kCclNetReqTableSize > 1)
          for(index=cclStartIndex[CCL_NET_CCLINDEX]; index<=cclStopIndex[CCL_NET_CCLINDEX]; index++)
          {
            intNetState |= cclIntNetState[index];
          }
#    else
          intNetState = cclIntNetState[0];
#    endif

          if((cclIntNetState[cclUserOffset[cclComHandle]] & cclUserMask[cclComHandle]) == 0)
          {
            /* store the communication request for this handle */
            cclIntNetState[cclUserOffset[cclComHandle]] |= cclUserMask[cclComHandle]; /*lint !e661*/ /* cclComHandle range is checked by an assertion */
            if( intNetState == kCclNoNetRequest )
            {
              /* the communication request is the first for this CAN channel */
              if(cclNmState[channel] == kCclNmStateSleep)
              {
                /* the CCL is in sleep */
                {
                  /* the communication request rrestriction is deactive */
#      if defined(CCL_ENABLE_TRCV_PORT_INT)
                  /* disable transceiver port interrupt */
#        if(kCclNrOfChannels > 1)
                  /* By using the following table of function calls, code-doubled functions 
                   * are called from the indexed CCL. This is done to simplify the called 
                   * functions (no distinction of the parameter 'channel' is necessary). */
                  if(CclDisableTrcvIntFctTbl[channel] != V_NULL)
                  {
                    (CclDisableTrcvIntFctTbl[channel])();
                  }
#        else
                  CclDisableTrcvIntFct();
#        endif
                  /* set the port interrupt state to deactive */
                  cclWakeUpIntState[channel] = kCclDisableWakeUpInt;
#      endif

#      if defined( CCL_USE_REQUEST_SETINTCOM_FCT )
                  /* inform the application about the first communication request */
#        if ( kCclNrOfChannels > 1 )
                  if (CclIntComReqFctTbl[channel] != V_NULL)
                  {
                    /* By using the following table of function calls, code-doubled functions 
                     * are called from the indexed CCL. This is done to simplify the called 
                     * functions (no distinction of the parameter 'channel' is necessary). */
                    (CclIntComReqFctTbl[channel])();
                  }
#        else
                  CclIntComReqFct();
#        endif
#    endif
                }
              }
              /* clear internal network release flag */
              cclIntNetRel[CCL_NET_CCLINDEX] = kCclNoIntNetReq;
              /* set internal network request flag */
              cclIntNetReq[CCL_NET_CCLINDEX] = CCL_CHANNEL_CCLINDEX;
            }
         } /* ESCAN00022602 */

      
      
   
#    if defined(CCL_ENABLE_NPM_SUPPORT)
#      if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
     } /* ESCAN00022602 */
     else
     {
#        if defined(CCL_ENABLE_PREVENT_WAKEUP)
       if( (vuint8)(cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmPreventWakeUpOn) == kCclNpmPreventWakeUpOn )
       {
         cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] |= kCclNpmPwuTriggered;
       }
#        endif

#        if defined(CCL_ENABLE_FORCE_SHUTDOWN)
       if( (vuint8)(cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmForceShutdownOn) == kCclNpmForceShutdownOn)
       {
         cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] |= kCclNpmFsdTriggered;
       }
#        endif
       
       retValue = kCclReqFailed;
     }
#        endif
#      endif
    }

#    if ( defined (CCL_ENABLE_MULTIPLE_CONFIG) )
  }
  else
  {
    retValue = kCclReqFailed;
  }
#    endif
   
   /* ESCAN00010661 
    *  Enable the global interrupt before leaving the function. */   
   CanGlobalInterruptRestore();
     
   return retValue;
}
#  endif

#  if defined( CCL_ENABLE_COM_REQ_HANDLING_API )
/************************************************************************
| NAME:               CclReleaseCommunication
| PROTOTYPE:          void CCL_API_CALL_TYPE CclReleaseCommunication(vuint8 cclComHandle)
| CALLED BY:          Application
| PRECONDITIONS:
| INPUT PARAMETERS:   cclComHandle: communication request handle
| RETURN VALUE:       -
| DESCRIPTION:        release the communication request for CAN channels which
|                     are configured for the cclComHandle
|*************************************************************************/
void CCL_API_CALL_TYPE CclReleaseCommunication(vuint8 cclComHandle)
{
   vuint8 intNetState;
   vuint8 channel;
#    if (kCclNetReqTableSize > 1)
   vuint8 index;
#    endif



/* ESCAN00010661 
   *  Disable the global interrupt to guarantee data consistency 
   *  if this function is called from interrupt insted of task level. */
   CanGlobalInterruptDisable();

   /* to avoid compiler warnings */
   channel = 0;
   intNetState = 0;

   /* check for valid communication handle */
   CclAssert( (cclComHandle < kCclNumberOfUser), kCclErrInvalidComHandle)

   channel = cclUserChannel[cclComHandle]; /*lint !e661*/ /* cclComHandle range is checked by an assertion */

#    if defined(CCL_ENABLE_MULTIPLE_CONFIG)
   if((cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (CCL_CHANNEL_CCLINDEX))) > 0x00)   
   {
#    endif

   
     
#    if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
       if(cclNpmPwuFsRestriction[channel] == kCclNpmPwuFsRestrictionOff)
       {
#    endif
       
         if( (cclIntNetState[cclUserOffset[cclComHandle]] & cclUserMask[cclComHandle]) != kCclNoNetRequest ) /*lint !e661*/ /* cclComHandle range is checked by an assertion */
         {
           /* the communication request of the cclComHandle handle is released the first time,
            * clear communication request for the cclComHandle handle */
           cclIntNetState[cclUserOffset[cclComHandle]] &= (vuint8)(~cclUserMask[cclComHandle]); /*lint !e661*/ /* cclComHandle range is checked by an assertion */

           /* calculate if there are other communication requests pending */
  #    if(kCclNetReqTableSize > 1)
           for(index=cclStartIndex[CCL_NET_CCLINDEX]; index<=cclStopIndex[CCL_NET_CCLINDEX]; index++)
           {
             intNetState |= cclIntNetState[index];
           }
  #    else
           intNetState = cclIntNetState[0];
  #    endif

           if(intNetState == kCclNoNetRequest)
           {
             /* no communication requests are pending for the CAN channel */
               /* communication restriction is deactive,
                * check if an internal request is pending */
               if(cclIntNetReq[CCL_NET_CCLINDEX] == kCclNoIntNetReq)
               {
                 /* no internal network request is pending ,
                  * set the internal release network flag */
                 cclIntNetRel[CCL_NET_CCLINDEX] = channel;

                 /* set internal network release history flag */
                 cclIntNetRelHistory[CCL_NET_CCLINDEX] = channel;
               }
               else
               {
                 /* clear internal network request flag */
                 cclIntNetReq[CCL_NET_CCLINDEX] = kCclNoIntNetReq;

                 /* internal request is pending ,
                   * check the CCL state */
#      if defined(CCL_ENABLE_EXTERNAL_REQUEST)
                 /* and check if no external wake up request is pending: */
                 /* ESCAN00022666 */
                 if((cclNmState[channel] == kCclNmStateSleep) && (cclExtCanWakeUpReq[channel] == kCclNoExtChWupReq))
#      else
                 if(cclNmState[channel] == kCclNmStateSleep)
#      endif
                 {
                   {
                     /* inform the application about the state change to sleep */
#      if defined(CCL_USE_REQUEST_CLEARCOM_FCT)
#        if(kCclNrOfChannels > 1)
                     if(CclComRelFctTbl[channel] != V_NULL)
                     {
                       (CclComRelFctTbl[channel])();
                     }
#        else
                      
                     CclComRelFct();
#        endif
#      endif
                   }


                 }
                  
                 else
                 {
                   if(cclIntNetRelHistory[CCL_NET_CCLINDEX] != kCclNoIntNetRel)
                   {
                     /* ESCAN00020286 */
                     /* internal release network */
                     cclIntNetRel[CCL_NET_CCLINDEX] = channel; /* ESCAN00021188 */
                   }
                 }
               }

#  if defined(CCL_ENABLE_TRCV_PORT_INT)            
               if(cclNmState[channel] == kCclNmStateSleep)
               {
#    if defined(CCL_ENABLE_EXTERNAL_REQUEST)
                 /* clear external CAN network request */
                 if(cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] == kCclNoExtChWupReq)
#    endif
                 {
                   if(cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] == kCclDisableWakeUpInt)
                   {
                     /* enable transceiver port interrupt */
#    if( kCclNrOfChannels > 1 )
                     /* By using the following table of function calls, code-doubled functions 
                      * are called from the indexed CCL. This is done to simplify the called 
                      * functions (no distinction of the parameter 'channel' is necessary). */
            
                     /* Within the following function calls a maybe pending 
                      *  Transceiver interrupt will be cleared! */ 
                     if(CclClearTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
                     {                     
                       (CclClearTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
                     }
                     if(CclEnableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
                     {
                       (CclEnableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
                     }
  #      else
                     /* Wtihin the following function calls a maybe pending 
                      *  Transceiver interrupt will be cleared! */
                     CclClearTrcvIntFct();
                     CclEnableTrcvIntFct();
  #      endif

                     /* set INT state to "enable" */
                     cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] = kCclEnableWakeUpInt;

  #      if defined(CCL_ENABLE_TRCV_PORT_EDGE_TRIGGER)
                     /* check transceiver port register */
  #        if( kCclNrOfChannels > 1 )
                     if(CclCheckTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX]() == kCclTrcvWakeIntPending)
                     {
                       /* By using the following table of function calls, code-doubled functions 
                        * are called from the indexed CCL. This is done to simplify the called 
                        * functions (no distinction of the parameter 'channel' is necessary). */

                       /* disable transceiver port interrupt */
                       if(CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
                       {
                         (CclDisableTrcvIntFctTbl[CCL_CHANNEL_CCLINDEX])();
                       }
  #        else
                       if(CclCheckTrcvIntFct() == kCclTrcvWakeIntPending)
                       {
                         /* disable transceiver port interrupt */
                         CclDisableTrcvIntFct();
  #        endif
                     
                         /* check INT state */
                         if(cclWakeUpIntState[CCL_CHANNEL_CCLINDEX] == kCclEnableWakeUpInt)
                         {
                           /* external EMC/CAN wake up notification */
                           CclCanWakeUpInt(CCL_CHANNEL_CCLPARA_ONLY);
                         }
                       }
  #      endif
                     }
                   }
                 }
  #    endif
               /* clear internal network request flag */
               cclIntNetReq[CCL_NET_CCLINDEX] = kCclNoIntNetReq; /* ESCAN00011503 */
          }
        }
#    if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
      }
#    endif

#    if defined(CCL_ENABLE_MULTIPLE_CONFIG)
  }
#    endif


   /* ESCAN00010661 
   *  Enable the global interrupt before leaving the function. */
   CanGlobalInterruptRestore();
 }
#  endif

#  if defined( CCL_ENABLE_COM_REQ_HANDLING_API )
/************************************************************************
| NAME:               CclGetComHandleState
| PROTOTYPE:          vuint8 CCL_API_CALL_TYPE CclGetComHandleState(vuint8 cclComHandle)
| CALLED BY:          Application
| PRECONDITIONS:
| INPUT PARAMETERS:   cclComHandle: communication request handle
| RETURN VALUE:       kCclComReqPending: the communication request is set
|                     kCclComReqNotPending: the communication request is not set
| DESCRIPTION:        Return the communication handle request state
|*************************************************************************/
vuint8 CCL_API_CALL_TYPE CclGetComHandleState(vuint8 cclComHandle)
{
  vuint8 retValue;

  retValue = kCclComReqNotPending;

  /* disable glaobal interrupts */
  CanGlobalInterruptDisable();

  /* check if the communication request is set */
  if( (cclIntNetState[cclUserOffset[cclComHandle]] & cclUserMask[cclComHandle]) != kCclNoNetRequest )
  {
    /* the communication request is not set */
    retValue = kCclComReqPending;
  }

  /* enable global interrupts */
  CanGlobalInterruptRestore();

  return retValue;
}


/************************************************************************
| NAME:               CclComRequestPending
| PROTOTYPE:          vuint8 CCL_API_CALL_TYPE CclComRequestPending(void) or
|                     vuint8 CCL_API_CALL_TYPE CclComRequestPending(CanChannelHandle channel)
| CALLED BY:          Application
| PRECONDITIONS:      
| INPUT PARAMETERS:   channel: communication request handle
| RETURN VALUE:       kCclComReqPending: minimum one communication request is set
|                                        for the channel
|                     kCclComReqNotPending: no communication request is set
|                                           for the channel
| DESCRIPTION:        Return the communication state for the CAN channel
|*************************************************************************/
vuint8 CCL_API_CALL_TYPE CclComRequestPending(CCL_CHANNEL_CCLTYPE_ONLY)
{
  vuint8 retValue;
  vuint8 intNetState;
#    if(kCclNetReqTableSize > 1)
  vuint8 index;
#    endif

  intNetState = 0;
  retValue = kCclComReqPending;

  /* disable global interrupts */
  CanGlobalInterruptDisable();

  /* calculate if a communication request is pending */
#    if(kCclNetReqTableSize > 1)
  for(index=cclStartIndex[CCL_CHANNEL_CCLINDEX]; index<=cclStopIndex[CCL_CHANNEL_CCLINDEX]; index++)
  {
    intNetState |= cclIntNetState[index];
  }
#    else
  intNetState = cclIntNetState[CCL_CHANNEL_CCLINDEX];
#    endif

  if( intNetState == kCclNoNetRequest )
  {
    /* no communication request is pending for the CAN channel */
    retValue = kCclComReqNotPending;
  }

  /* enable global interrupts */
  CanGlobalInterruptRestore();

  return retValue;
}
#  endif





#endif /* CCL_ENABLE_INTERNAL_REQUEST */

/************************************************************************
| NAME:               CclEnableCommunication
| PROTOTYPE:          void CclEnableCommunication(vuint8 channel)
|                     or
|                     void CclEnableCommunication(void)
| CALLED BY:          DPM or Application
| PRECONDITIONS:      Not to be called within ISR
|                     If the DPM component is configured than it is not allowed
|                     to call this function by the application.
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       -
| DESCRIPTION:        enable the HW communication state of CAN controller
|                     CAN transceiver and allow the communication (caused
|                     by external channel and internal network requests)
|*************************************************************************/
void CCL_API_CALL_TYPE CclEnableCommunication(CCL_CHANNEL_CCLTYPE_ONLY)
 {
   /* set HW communication state to enable */
   cclComHwState[CCL_CHANNEL_CCLINDEX] = kCclComHwEnabled;
 }

/************************************************************************
| NAME:               CclDisableCommunication
| PROTOTYPE:          void CclDisableCommunication(vuint8 channel)
|                     or
|                     void CclDisableCommunication(void)
| CALLED BY:          DPM or Application
| PRECONDITIONS:      Not to be called within ISR
|                     If the DPM component is configured than it is not allowed
|                     to call this function by the application.
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       -
| DESCRIPTION:        disable the HW communication state of CAN controller
|                     CAN transceiver and prevent the communication (caused
|                     by external channel and internal network requests)
|*************************************************************************/
void CCL_API_CALL_TYPE CclDisableCommunication(CCL_CHANNEL_CCLTYPE_ONLY)
 {
   /* set HW communication state to disable */
   cclComHwState[CCL_CHANNEL_CCLINDEX] = kCclComHwDisabled;
 }






#if defined (CCL_ENABLE_TRCV_TYPE_TLE6251G) /* ESCAN00022973 */
/************************************************************************
| NAME:               CclSetTrcvRxOnlyMode
| PROTOTYPE:          void CclSetTrcvRxOnlyMode(CanChannelHandle channel)
| CALLED BY:          Application from task level
| PRECONDITIONS:
| INPUT PARAMETERS:   channel (multiple receive channel)
|                     or
|                     void (single receive channel)
| RETURN VALUE:       kCclTrcvStateChangePerformed
|                     or
|                     kCclTrcvStateChangeNotPerformed
| DESCRIPTION:        informs the CCL to set the transceiver into the receive
|                     only mode
|*************************************************************************/
vuint8 CclSetTrcvRxOnlyMode(CCL_CHANNEL_CCLTYPE_ONLY)
{
  vuint8 retVal;

  retVal = kCclTrcvStateChangePerformed;
  
  /* CCL must be in state Active or GoToSleep: */
  CclAssert( (cclNmState[CCL_CHANNEL_CCLINDEX] > kCclStateWaitBusSleep), kCclErrWrongCclState)

  if(cclNmState[CCL_CHANNEL_CCLINDEX] > kCclStateWaitBusSleep)
  {
#  if(kCclNrOfChannels > 1)
    if (CclSetTrcvRxOnlyModeFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
    {
      /* By using the following table of function calls, code-doubled functions 
      * are called from the indexed CCL. This is done to simplify the called 
      * functions (no distinction of the parameter 'channel' is necessary). */
      (CclSetTrcvRxOnlyModeFctTbl[CCL_CHANNEL_CCLINDEX])();
    }
#  else
    CclSetTrcvRxOnlyModeFct();
#  endif
  }
  else
  {
    retVal = kCclTrcvStateChangeNotPerformed;
  }

  return retVal;
}

/************************************************************************
| NAME:               CclLeaveTrcvRxOnlyMode
| PROTOTYPE:          void CclLeaveTrcvRxOnlyMode(CanChannelHandle channel)
| CALLED BY:          Application from task level
| PRECONDITIONS:
| INPUT PARAMETERS:   channel (multiple receive channel)
|                     or
|                     void (single receive channel)
| RETURN VALUE:       kCclTrcvStateChangePerformed
|                     or
|                     kCclTrcvStateChangeNotPerformed
| DESCRIPTION:        informs the CCL to set the transceiver back to normal mode
|*************************************************************************/
vuint8 CclLeaveTrcvRxOnlyMode(CCL_CHANNEL_CCLTYPE_ONLY)
{ 
  vuint8 retVal;

  retVal = kCclTrcvStateChangePerformed;

  /* CCL must be in state Active or GoToSleep: */
  CclAssert( (cclNmState[CCL_CHANNEL_CCLINDEX] > kCclStateWaitBusSleep), kCclErrWrongCclState)

  if(cclNmState[CCL_CHANNEL_CCLINDEX] > kCclStateWaitBusSleep)
  {
#  if(kCclNrOfChannels > 1)
    if (CclLeaveTrcvRxOnlyModeFctTbl[CCL_CHANNEL_CCLINDEX] != V_NULL)
    {
      /* By using the following table of function calls, code-doubled functions 
      * are called from the indexed CCL. This is done to simplify the called 
      * functions (no distinction of the parameter 'channel' is necessary). */
      (CclLeaveTrcvRxOnlyModeFctTbl[CCL_CHANNEL_CCLINDEX])();
    }
#  else
    CclLeaveTrcvRxOnlyModeFct();
#  endif
  }
  else
  {
    retVal = kCclTrcvStateChangeNotPerformed;
  }

  return retVal;
}
#endif



/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
#if (CCL_PAG_VERSION != 0x0107)
#  error "CCL PAG OEM: incorrect main or sub version"
#endif

#if (CCL_PAG_RELEASE_VERSION != 0x00)
#  error "CCL PAG OEM: incorrect release version"
#endif

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kCclMainVersion  =(vuint8)( (CCL_PAG_VERSION) >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kCclSubVersion   =(vuint8)( (CCL_PAG_VERSION) & 0xFF);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kCclReleaseVersion=(vuint8)( (CCL_PAG_RELEASE_VERSION) & 0xFF);
/***************************************************************************/ 
/* Plausibility checks                                                     */ 
/***************************************************************************/

#if !defined( NM_TYPE_NMHIGH ) 
#  error "The current version of the CCL does only work with NM-High and/or NM Basic!"
#else
#  if defined( NM_TYPE_NMHIGH )
#    if !defined( NMH_ENABLE_CALLBACK_FCT )
#      error "Please enable the extended callback functions for NM Powertrain VAG."
#    endif
#  endif
#endif

/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/
#if defined(CCL_ENABLE_POSRES_FBL)
#  if defined ( CCL_ENABLE_MULTIPLE_CONFIG )
#    define CCL_POS_RESP_CHANNEL CCL_CHANNEL_CCLINDEX
#  else
#    define CCL_POS_RESP_CHANNEL   (vuint8)kCclCanDescChannel
#  endif
#endif


/***************************************************************************/
/* Global functions                                                        */
/***************************************************************************/
#if defined(CCL_ENABLE_POSRES_FBL)
/************************************************************************
| NAME:                CclSendPosRespFBL
| PROTOTYPE:           void CclSendPosRespFBL(t_descFblPosRespType posRespSId)
| CALLED BY:           Application
| PRECONDITIONS:       CCL is intialized
| INPUT PARAMETERS:    kDescSendFblPosRespEcuHardReset or kDescSendFblPosRespDscDefault
| RETURN VALUE:        void
| DESCRIPTION:         Informs the CCL that a positive diagnostic response has to be sent.
|*************************************************************************/
#  if defined ( CCL_ENABLE_MULTIPLE_CONFIG )
void CclSendPosRespFBL( CCL_CHANNEL_CCLTYPE_FIRST t_descFblPosRespType posRespSId )
#  else
void CclSendPosRespFBL( t_descFblPosRespType posRespSId )
#  endif
{
#  if defined ( CCL_ENABLE_MULTIPLE_CONFIG )
  CclAssert( (cclIdChMap[V_ACTIVE_IDENTITY_LOG] & (vuint8)((vuint8)1 << (channel))) > (vuint8)0x00, kCclWrongChannelHandle)
#  endif

  /* ESCAN00024964 */
  if ( cclNmState[CCL_POS_RESP_CHANNEL] < kCclNmStateGoToSleep )
  {
# if defined(CCL_ENABLE_NMSTARTUP_TIMER)
    if((cclNmWakeUpAble & (vuint8)((vuint8)1 << (CCL_POS_RESP_CHANNEL))) != kCclNoWakeUpAble )
    {
      /* a wake up able NM is used,
      * set the CCL system user
      */
      (void)CclRequestCommunication(CCL_POS_RESP_CHANNEL);
      /* start the NM minimum awake timer */
      cclNmStartupTimer[CCL_POS_RESP_CHANNEL] = cclNmStartupTimerValue[CCL_POS_RESP_CHANNEL];
    }
#  endif
    cclPosRespData[CCL_POS_RESP_CHANNEL] = posRespSId;
    cclSendPosRespFbl[CCL_POS_RESP_CHANNEL] = kCclSendPosResp;
  }
  else
  {
    DescSendPosRespFBL(posRespSId);
  }
}
#endif

#if defined(CCL_ENABLE_NPM_SUPPORT)
/************************************************************************
| NAME:                CclNpmSetIgnitionState
| PROTOTYPE:           void CclNpmSetIgnitionState(vuint8 state)
| CALLED BY:           Application
| PRECONDITIONS:       CCL is intialized
| INPUT PARAMETERS:    state: kCclNpmIgnitionOn or kCclNpmIgnitionOff
| RETURN VALUE:        void
| DESCRIPTION:         Informs the CCL about the ignition state.
|*************************************************************************/
void CCL_API_CALL_TYPE CclNpmSetIgnitionState(vuint8 state)
{
#  if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
  vuint8 channel;
#  endif
  
  cclNpmIgnitionState = state;

#  if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
  /* ESCAN00028368 */
  for(channel = 0; channel < kCclNrOfChannels; channel++)
  {
    if( cclNpmIgnitionState == kCclNpmIgnitionOn )
    {
      /* When ignition is on PW/FS are invalid: */
#    if defined(CCL_ENABLE_FORCE_SHUTDOWN)
      cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmForceShutdownInvalid;
#    endif
#    if defined(CCL_ENABLE_PREVENT_WAKEUP)
      cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmPreventWakeUpInvalid;
#    endif
      cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] = 0x00;
    }  
  } 
#  endif 
}


/************************************************************************
| NAME:               CclNpmGetState
| PROTOTYPE:          vuint8 CclNpmGetState(void) or
|                     vuint8 CclNpmGetState(CanChannelHandle channel)
| CALLED BY:          Application
| PRECONDITIONS:
| INPUT PARAMETERS:   void (single channel) or channel (multiple channel)
| RETURN VALUE:       state field of the NPM
| DESCRIPTION:        The function returns a bit field with the NPM states.
|                     The current state of the NPM could be check by using 
|                     the following macros:
|                        NpmStateIsPreventWakeUp, to get the prevent wake up state
|                        NpmStateIsForceShutdown, to get the force shutdown state
|                        NpmMessageIsTimeout, to check if the NPM message timeout occured
|*************************************************************************/
vuint8 CCL_API_CALL_TYPE CclNpmGetState(CCL_CHANNEL_CCLTYPE_ONLY)
{
  return cclNpmState[CCL_CHANNEL_CCLINDEX];
}

#  if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
/************************************************************************
| NAME:                CclNpmEnableNpmHandling
| PROTOTYPE:           void CclNpmEnableNpmHandling(void)
| CALLED BY:           Application
| PRECONDITIONS:       CCL is intialized
| INPUT PARAMETERS:
| RETURN VALUE:        void
| DESCRIPTION:         Enable the NPM handling
|*************************************************************************/
void CCL_API_CALL_TYPE CclNpmEnableNpmHandling(void)
{
  vuint8 channel;

  for(channel = 0; channel < kCclNrOfChannels; channel++)
  {
    /* enable NPM functionality */
    cclNpmHandling[channel] = kCclNpmOn;
  }
}

/************************************************************************
| NAME:                CclNpmDisableNpmHandling
| PROTOTYPE:           void CclNpmDisableNpmHandling(void)
| CALLED BY:           Application
| PRECONDITIONS:       CCL is intialized
| INPUT PARAMETERS:
| RETURN VALUE:        void
| DESCRIPTION:         Disable the NPM Handling
|*************************************************************************/
void CCL_API_CALL_TYPE CclNpmDisableNpmHandling(void)
{
  vuint8 channel;

  for(channel = 0; channel < kCclNrOfChannels; channel++)
  {
    /* disable prevent wake up */
    cclNpmState[channel] &= kCclNpmPreventWakeUpOff;

    /* When NPM is disabled PW/FS are invalid: */
    cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmForceShutdownInvalid;

    cclNpmState[CCL_CHANNEL_CCLINDEX] &= kCclNpmPreventWakeUpInvalid;

    /* reset force shutdown/ prevent wake up triggered flags: */
    cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] = 0x00;

    /* disable prevent wake up in the internal NPM message shadow buffer */
    cclNpmMsgData[channel] &= kCclNpmPreventWakeUpOff;

    /* disable prevent wake up */
    cclNpmState[channel] &= kCclNpmForceShutdownOff;
    /* disable prevent wake up in the internal NPM message shadow buffer */
    cclNpmMsgData[channel] &= kCclNpmForceShutdownOff;

    /* clear restrictions */
    CclNpmClearPwuFsRestriction(CCL_CHANNEL_CCLPARA_ONLY);

    /* stop NPM message timer observation */
    cclNpmMessageTimeout[channel] = kCclNpmMessageTimerStopped;

    /* clear pending NPM message timeout */
    cclNpmState[channel] &= kCclNpmMessageTimeoutClear;

   /* enable NPM functionality */
    cclNpmHandling[channel] = kCclNpmOff;
  }
}
#  endif
#endif

/***************************************************************************/
/* callback functions                                                      */
/***************************************************************************/






#if defined(NM_TYPE_NMHIGH)
/************************************************************************
| NAME:                ApplNmhWakeUp
| PROTOTYPE:           void ApplNmhWakeUp(CanChannelHandle channel)
|                      or
|                      void ApplNmhWakeUp(void)
| CALLED BY:           NM HIGH
| PRECONDITIONS:       state transition to "NORMAL"
| INPUT PARAMETERS:    channel (multiple channel)
|                      or
|                      void (single channel)
| RETURN VALUE:        void
| DESCRIPTION:         -
|*************************************************************************/
void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhWakeUp( NMH_CHANNEL_APPLTYPE_ONLY )
{
}


/************************************************************************
| NAME:                ApplNmhSleep
| PROTOTYPE:           void ApplNmhSleep(CanChannelHandle channel)
|                      or
|                      void ApplNmhSleep(void)
| CALLED BY:           NM HIGH
| PRECONDITIONS:       state transition to "GO TO SLEEP"
| INPUT PARAMETERS:    channel (multiple channel)
|                      or
|                      void (single channel)
| RETURN VALUE:        void
| DESCRIPTION:         set CAN controller and CAN transceiver in SLEEP mode
|                      enable the external wakeup port INT
|*************************************************************************/
void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhSleep( NMH_CHANNEL_APPLTYPE_ONLY )
{
  tNmhShutdownType nmhState;

  nmhState = NMH_SHUTDOWN_FAILED;

  /* disable the can interrupts */
#  if(kCanNumberOfChannels > 1)
#    if defined(NMH_ENABLE_INDEXED_NM)  
  CanCanInterruptDisable(NMH_CHANNEL_APPLPARA_ONLY);
#    else
  CanCanInterruptDisable(kNmhCanChannel);
#    endif
#  else
  CanCanInterruptDisable(CCL_CHANNEL_CCLPARA_ONLY);
#  endif

#  if(kCanNumberOfChannels > 1)
#    if defined(NMH_ENABLE_INDEXED_NM)
  nmhState = NmhValidateShutdown(NMH_CHANNEL_APPLPARA_ONLY);
#    else
  nmhState = NmhValidateShutdown();
#    endif
#  else
  nmhState = NmhValidateShutdown(CCL_CHANNEL_CCLPARA_ONLY);
#  endif

  /* disable the global interrupts */
  CanGlobalInterruptDisable();

  /* restore the CAN interrupts */
#  if(kCanNumberOfChannels > 1)
#    if defined(NMH_ENABLE_INDEXED_NM)  
  CanCanInterruptRestore(NMH_CHANNEL_APPLPARA_ONLY);
#    else
  CanCanInterruptRestore(kNmhCanChannel);
#    endif
#  else
  CanCanInterruptRestore(CCL_CHANNEL_CCLPARA_ONLY);
#  endif

  if(nmhState == NMH_SHUTDOWN_VALID)
  {
#  if(kCanNumberOfChannels > 1)
#    if defined(NMH_ENABLE_INDEXED_NM)
    /* ESCAN00025338 */
    cclStateTmp[NMH_CHANNEL_APPLPARA_ONLY] = kCclStateSleep;
    CclComStop(NMH_CHANNEL_APPLPARA_ONLY);
    CclCanStandby(NMH_CHANNEL_APPLPARA_ONLY);
#    else
    /* ESCAN00025338 */
    cclStateTmp[kNmhCanChannel] = kCclStateSleep;
    CclComStop(kNmhCanChannel);
    CclCanStandby(kNmhCanChannel);
#    endif
#  else
    /* ESCAN00025338 */
    cclStateTmp[CCL_CHANNEL_CCLINDEX] = kCclStateSleep;
    CclComStop(CCL_CHANNEL_CCLPARA_ONLY);
    CclCanStandby(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
  }

  /* restore the globale interrupts */
  CanGlobalInterruptRestore();

  if(nmhState == NMH_RESTART_REQ)
  {
#  if(kCanNumberOfChannels > 1)
#    if defined(NMH_ENABLE_INDEXED_NM)
    /* ESCAN00025338 */
    cclStateTmp[NMH_CHANNEL_APPLPARA_ONLY] = kCclNmStateActive;
    ApplCanWakeUp(NMH_CHANNEL_APPLPARA_ONLY);
    CclCanNormal(NMH_CHANNEL_APPLPARA_ONLY);
    CclComResume(NMH_CHANNEL_APPLPARA_ONLY);
#    else
    /* ESCAN00025338 */
    cclStateTmp[kNmhCanChannel] = kCclNmStateActive;
    ApplCanWakeUp(kNmhCanChannel);
    CclCanNormal(kNmhCanChannel);
    CclComResume(kNmhCanChannel);
#    endif
#  else
    /* ESCAN00025338 */
    cclStateTmp[CCL_CHANNEL_CCLINDEX] = kCclNmStateActive;
    ApplCanWakeUp(CCL_CHANNEL_CCLPARA_ONLY);
    CclCanNormal(CCL_CHANNEL_CCLPARA_ONLY);
    CclComResume(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
  }
}


/************************************************************************
| NAME:               ApplNmhNetStart
| PROTOTYPE:          void ApplNmhNetStart(CanChannelHandle channel)
|                     or
|                     void ApplNmhNetStart(void)
| CALLED BY :         NM HIGH
| PRECONDITIONS :     enable "extended callbacks"
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE :      void
| DESCRIPTION :       Start the communication via interaction layer.
|*************************************************************************/
void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhNetStart( NMH_CHANNEL_APPLTYPE_ONLY )
{
#  if(kCanNumberOfChannels > 1)
#    if defined(NMH_ENABLE_INDEXED_NM)
  if(cclStateTmp[NMH_CHANNEL_APPLPARA_ONLY] == kCclStateWaitBusSleep)
  {
    ApplCanWakeUp( NMH_CHANNEL_NMPARA_ONLY );
    CclCanNormal( NMH_CHANNEL_APPLPARA_ONLY );
    CclComResume( NMH_CHANNEL_APPLPARA_ONLY );
  }
  else
  {
    /* Fix of ESCAN00025338: */
    if (cclNmState[NMH_CHANNEL_APPLPARA_ONLY] < kCclStateGoToSleep)
    {
      /* We are in state WaitBusSleep or Sleep and NM High starts up out of state sleep which is equal to an external wake up: */
      if ( cclExtCanWakeUpReq[NMH_CHANNEL_APPLPARA_ONLY] == kCclNoExtChWupReq )
      {
        ApplCanWakeUp( NMH_CHANNEL_APPLPARA_ONLY );
      }
    }

    CclCanNormal( NMH_CHANNEL_APPLPARA_ONLY );
    CclComStart( NMH_CHANNEL_APPLPARA_ONLY );
#      if defined(CCL_ENABLE_POSRES_FBL)
    if(cclSendPosRespFbl[NMH_CHANNEL_APPLPARA_ONLY] == kCclSendPosResp)
    {
      DescSendPosRespFBL(cclPosRespData[NMH_CHANNEL_APPLPARA_ONLY]);
      cclSendPosRespFbl[NMH_CHANNEL_APPLPARA_ONLY] = kCclSendNoPosResp;
    }
#      endif
  }
#    else
  if(cclStateTmp[kNmhCanChannel] == kCclStateWaitBusSleep)
  {
    ApplCanWakeUp( kNmhCanChannel );
    CclCanNormal( kNmhCanChannel );
    CclComResume( kNmhCanChannel );
  }
  else
  {
    /* Fix of ESCAN00025338: */
    if (cclNmState[kNmhCanChannel] < kCclStateGoToSleep)
    {
      if ( cclExtCanWakeUpReq[kNmhCanChannel] == kCclNoExtChWupReq )
      {
        /* We are in state WaitBusSleep or Sleep and NM High starts up out of state sleep which is equal to an external wake up: */
        ApplCanWakeUp( kNmhCanChannel );
      }
    }

    CclCanNormal( kNmhCanChannel );
    CclComStart( kNmhCanChannel );
#      if defined(CCL_ENABLE_POSRES_FBL)
    if(cclSendPosRespFbl[kNmhCanChannel] == kCclSendPosResp)
    {
      DescSendPosRespFBL(cclPosRespData[kNmhCanChannel]);
      cclSendPosRespFbl[kNmhCanChannel] = kCclSendNoPosResp;
    }
#      endif
  }
#    endif
#  else
  if(cclStateTmp[CCL_CHANNEL_CCLINDEX] == kCclStateWaitBusSleep)
  {
    ApplCanWakeUp( CCL_CHANNEL_CCLPARA_ONLY );
    CclCanNormal( CCL_CHANNEL_CCLPARA_ONLY );
    CclComResume( CCL_CHANNEL_CCLPARA_ONLY );
  }
  else
  {
    /* Fix of ESCAN00025338: */
    if (cclNmState[CCL_CHANNEL_CCLINDEX] < kCclStateGoToSleep)
    {
      if ( cclExtCanWakeUpReq[CCL_CHANNEL_CCLINDEX] == kCclNoExtChWupReq )
      {
        /* We are in state WaitBusSleep or Sleep and NM High starts up out of state sleep which is equal to an external wake up: */
        ApplCanWakeUp( CCL_CHANNEL_CCLPARA_ONLY );
      }
    }

    CclCanNormal(CCL_CHANNEL_CCLPARA_ONLY);
    CclComStart(CCL_CHANNEL_CCLPARA_ONLY);
#   if defined(CCL_ENABLE_POSRES_FBL)
    if(cclSendPosRespFbl[CCL_CHANNEL_CCLINDEX] == kCclSendPosResp)
    {
      DescSendPosRespFBL(cclPosRespData[CCL_CHANNEL_CCLINDEX]);
      cclSendPosRespFbl[CCL_CHANNEL_CCLINDEX] = kCclSendNoPosResp;
    }
#    endif
  }
#  endif

#  if(kCanNumberOfChannels > 1)
#    if defined(NMH_ENABLE_INDEXED_NM)  
  cclStateTmp[NMH_CHANNEL_APPLPARA_ONLY] = kCclStateActive;
#    else
  cclStateTmp[kNmhCanChannel] = kCclStateActive;
#    endif
#  else
  cclStateTmp[CCL_CHANNEL_CCLINDEX] = kCclStateActive;
#  endif
}


/************************************************************************
| NAME:               ApplNmhNetStop
| PROTOTYPE:          void ApplNmhNetStop(CanChannelHandle channel)
|                     or
|                     void ApplNmhNetStop(void)
| CALLED BY :         NM HIGH
| PRECONDITIONS :     enable "extended callbacks"
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE :      void
| DESCRIPTION :       Stop the communication via interaction layer.
|*************************************************************************/
void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhNetStop( NMH_CHANNEL_APPLTYPE_ONLY )
{
#  if(kCanNumberOfChannels > 1)
#    if defined(NMH_ENABLE_INDEXED_NM)
  CclComWait( NMH_CHANNEL_APPLPARA_ONLY );

  /* set the CCL state to wait bus sleep */
  cclNmState[NMH_CHANNEL_APPLPARA_ONLY] = kCclStateWaitBusSleep;
  cclStateTmp[NMH_CHANNEL_APPLPARA_ONLY] = kCclStateWaitBusSleep;

#      if defined(CCL_ENABLE_NPM_SUPPORT)
#        if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
  if(cclNpmHandling[NMH_CHANNEL_APPLPARA_ONLY] == kCclNpmOn)
  {
    CclNpmBusSleepActivities(NMH_CHANNEL_APPLPARA_ONLY);
  }
#        endif
#      endif

#    else

     CclComWait(kNmhCanChannel);

   /* set the CCL state to wait bus sleep */
   cclNmState[kNmhCanChannel] = kCclStateWaitBusSleep;
   /* store the current CCL state */
   cclStateTmp[kNmhCanChannel] = kCclStateWaitBusSleep;

#      if defined(CCL_ENABLE_NPM_SUPPORT)
#        if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
  if(cclNpmHandling[kNmhCanChannel] == kCclNpmOn)
  {
    CclNpmBusSleepActivities(kNmhCanChannel);
  }
#        endif
#      endif

#    endif

#  else
    CclComWait(CCL_CHANNEL_CCLPARA_ONLY);

   /* set the CCL state to wait bus sleep */
   cclNmState[CCL_CHANNEL_CCLINDEX] = kCclStateWaitBusSleep;
   cclStateTmp[CCL_CHANNEL_CCLINDEX] = kCclStateWaitBusSleep;

#      if defined(CCL_ENABLE_NPM_SUPPORT)
#        if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
  if(cclNpmHandling[CCL_CHANNEL_CCLINDEX] == kCclNpmOn)
  {
    CclNpmBusSleepActivities(CCL_CHANNEL_CCLPARA_ONLY);
  }
#        endif
#      endif
#  endif
}


/************************************************************************
| NAME:                ApplNmhPrepareSleep
| PROTOTYPE:           void ApplNmhPrepareSleep(CanChannelHandle channel)
|                      or
|                      void ApplNmhPrepareSleep(void)
| CALLED BY:           NM HIGH
| PRECONDITIONS:       state transition to "NORMAL"
| INPUT PARAMETERS:    channel (multiple channel)
|                      or
|                      void (single channel)
| RETURN VALUE:        void
| DESCRIPTION:         -
|*************************************************************************/
void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhPrepareSleep( NMH_CHANNEL_APPLTYPE_ONLY )
{
}


/************************************************************************
| NAME:               ApplNmhBusOffStart
| PROTOTYPE:          void ApplNmhBusOffStart(CanChannelHandle channel, vuint8 numberOfBusOff)
|                     or
|                     void ApplNmhBusOffStart( vuint8 numberOfBusOff)
| CALLED BY:          NM HIGH
| PRECONDITIONS:      event "BusOff"
| INPUT PARAMETERS:   channel (multiple channel)
|                     numberOfBusOff
|                     or
|                     numberOfBusOff (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        The CCL handles the configured interaction layer in
|                     dependency of the CCL configuration.
|*************************************************************************/
void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhBusOffStart( NMH_CHANNEL_APPLTYPE_FIRST  vuint8 numberOfBusOff )
{

#  if(kCanNumberOfChannels > 1)
#    if defined(NMH_ENABLE_INDEXED_NM)
   CclBusOffStart(NMH_CHANNEL_APPLPARA_ONLY);
#    else
   CclBusOffStart(kNmhCanChannel);
#    endif
#  else
   CclBusOffStart(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
}


/************************************************************************
| NAME:               ApplNmhBusOffEnd
| PROTOTYPE:          void ApplNmhBusOffEnd(CanChannelHandle channel)
|                     or
|                     void ApplNmhBusOffEnd(void)
| CALLED BY:          NM HIGH
| PRECONDITIONS:      event "BusOff"
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        The CCL handles the configured interaction layer in
|                     dependency of the CCL configuration.
|*************************************************************************/
void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhBusOffEnd( NMH_CHANNEL_APPLTYPE_ONLY )
{
#  if(kCanNumberOfChannels > 1)
#    if defined(NMH_ENABLE_INDEXED_NM)
   CclBusOffEnd(NMH_CHANNEL_APPLPARA_ONLY );
#    else
   CclBusOffEnd(kNmhCanChannel);
#    endif
#  else
   CclBusOffEnd(CCL_CHANNEL_CCLPARA_ONLY);
#  endif
}


/************************************************************************
| NAME:               ApplNmhBusOffRxRestore
| PROTOTYPE:          void ApplNmhBusOffRxRestore(CanChannelHandle channel)
|                     or
|                     void ApplNmhBusOffRxRestore(void)
| CALLED BY:          NM HIGH
| PRECONDITIONS:      event "BusOff"
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        -
|*************************************************************************/
void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhBusOffRxRestore( NMH_CHANNEL_APPLTYPE_ONLY )
{
}


#  if defined(CCL_ENABLE_ERROR_HOOK)
#    if defined ( NMH_ENABLE_TESTDEBUG )
/************************************************************************
| NAME:               ApplNmhFatalError
| PROTOTYPE:          void ApplNmhFatalError(CanChannelHandle channel, vuint8 errCode)
|                     or
|                     void ApplNmhFatalError(vuint8 errCode)
| CALLED BY:          NM HIGH
| PRECONDITIONS:      
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        Fatal error handling
|*************************************************************************/
void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhFatalError( NMH_CHANNEL_APPLTYPE_FIRST  vuint8 errCode )
{
#      if defined ( NMH_ENABLE_INDEXED_NM )
  CclFatalError(NMH_CHANNEL_APPLPARA_FIRST (vuint16)errCode, 0, kComponentNmHigh);
#      else
  CclFatalError(CCL_NO_CHANNEL_INFO_AVAILABLE, (vuint16)errCode, 0, kComponentNmHigh);
#      endif
}
#    endif
#  endif

#  if defined(CCL_ENABLE_ERROR_HOOK) /* ESCAN00022699 */
#    if defined (NMH_ENABLE_CAR_WUP) 
#      if defined (CWM_ENABLE_DEBUG)
/************************************************************************
| NAME:               ApplCwmFatalError
| PROTOTYPE:          void ApplCwmFatalError(CanChannelHandle channel, vuint8 errorCode)
|                     or
|                     void ApplNmhFatalError(vuint8 errorCode)
| CALLED BY:          CWM
| PRECONDITIONS:      
| INPUT PARAMETERS:   channel (multiple channel)
|                     or
|                     void (single channel)
| RETURN VALUE:       void
| DESCRIPTION:        Fatal error handling
|*************************************************************************/
void CWM_API_CALL_TYPE ApplCwmFatalError(CWM_CHANNEL_NMTYPE_FIRST V_MEMROM1 vuint8 V_MEMROM2 errorCode)
{
#        if defined ( NMH_ENABLE_INDEXED_NM )
  CclFatalError(CWM_CHANNEL_NMPARA_FIRST (vuint16)errorCode, 0, kComponentCwm);
#        else
  CclFatalError(CCL_NO_CHANNEL_INFO_AVAILABLE, (vuint16)errorCode, 0, kComponentCwm);
#        endif
}
#      endif
#    endif
#  endif

#endif

/************************************************************************
| NAME:               CclNpmSnapshot
| PROTOTYPE:          vuint8 CclNpmSnapshot(vuint8* diagData, vuint16* didLen)
|                     or
|                     vuint8 CclNpmSnapshot(CanChannelHandle channel, vuint8* diagData, vuint16* didLen)
| CALLED BY:          Application
| PRECONDITIONS:
| INPUT PARAMETERS:   handle of the CAN channel, pointer to the diagnostic data buffer, pointer where the
|                     diagnostic data length is copied to (number of used bytes) 
| RETURN VALUE:       kCclOk when function is called correctly, kCclFailed when function is not called correctly (wrong parameter)
|                     or when NPM is either disabled or not applicable
| DESCRIPTION:        this function returns a snapshot of the current internal NPM states and
|                     the static NPM configuration data.
|*************************************************************************/
vuint8 CCL_API_CALL_TYPE CclNpmSnapshot(CCL_CHANNEL_CCLTYPE_FIRST vuint8* diagData, vuint16* didLen)
{
#if defined(CCL_ENABLE_NPM_SUPPORT)

  vuint8 currentNpmStates = 0x00;
  
  vuint8 retVal = kCclFailed;
                    
#  if( kCclNrOfChannels > 1 )
  CclAssert( (channel < kCclNrOfChannels), kCclWrongChannelHandle)

  if( channel < kCclNrOfChannels )
#  endif
  {

      /* Bit 0: prevent wake up activation state */
      currentNpmStates |= ( cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] & kCclNpmPwuTriggered );
         
      /* Bit 1: force shutdown activation state */
      currentNpmStates |= ( cclNpmFsdPwuTriggered[CCL_CHANNEL_CCLINDEX] & kCclNpmFsdTriggered );
      
      /* Bit 2: ignition state */
      if( cclNpmIgnitionState == kCclNpmIgnitionOn )
      {
        currentNpmStates |= (vuint8)0x04;
      }
      else
      {
        /* clear ignition flag: */
        currentNpmStates &= (vuint8)0xFB;
      }

      /* Bit 3: communication request state, first check pending requests
                (returns 1 if true, shift return value to position 3)... */
      currentNpmStates |= ( CclComRequestPending(CCL_CHANNEL_CCLPARA_ONLY) << 3 );

      /* Bit 4: NPM message timeout state */
      currentNpmStates |= (cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmMessageTimeoutOccur );

      /* Bit 5: prevent wake up validation state */
      currentNpmStates |= (cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmPreventWakeUpValid );

      /* Bit 6: force shutdown validation state */
      currentNpmStates |= (cclNpmState[CCL_CHANNEL_CCLINDEX] & kCclNpmForceShutdownValid );
   
      /* write information into diagnostic buffer: */

      /* Byte 0: dynamic NPM data: */
      diagData[0] = currentNpmStates;

#  if defined(CCL_ENABLE_PREVENT_WAKEUP) || defined(CCL_ENABLE_FORCE_SHUTDOWN)
      /* Byte 1: configured force shutdown level: */
      diagData[1] = cclNpmFsLevel[CCL_CHANNEL_CCLINDEX];

      /* Byte 2: configured prevent wake up level: */
      diagData[2] = cclNpmPwuLevel[CCL_CHANNEL_CCLINDEX];

      /* Byte 3: configurerd ECU target address: */
      diagData[3] = cclNpmEcuAddress[CCL_CHANNEL_CCLINDEX];
#  else
      /* neither prevent wake up nor force shutdown enabled, set bytes to 0: */
      diagData[1] = 0;
      diagData[2] = 0;
      diagData[3] = 0;
#  endif

      /* Byte 4: configured NPM message timeout: */
      diagData[4] = (vuint8)(cclNpmMsgTimeoutValue[CCL_CHANNEL_CCLINDEX] >> 8);
      
      /* Byte 5: configured NPM message timeout: */
      diagData[5] = (vuint8)cclNpmMsgTimeoutValue[CCL_CHANNEL_CCLINDEX];   

      /* set the number of bytes: */
      *didLen = 0x06;

      retVal = kCclOk;
  }
#  if( kCclNrOfChannels > 1 )
  else
  {
    *didLen = 0x00; 
  }
#  endif

  return retVal;  

#else
#  if( kCclNrOfChannels > 1 )
#  endif

  *didLen = 0x00;

  return kCclFailed;
#endif
}

/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
