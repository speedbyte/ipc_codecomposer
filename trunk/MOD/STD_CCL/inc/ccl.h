
/*****************************************************************************
|  File Name: CCL.H 
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
| 26.02.02    1.00    Zw      Initial version 
| 02.12.02            Pet     add support for psa
| 2002-12-03  1.01    Pet     add support for Micronas CEVF
| 2003-02-04  1.02    Pet     ESCAN00004878: add support for GMLAN (single receive channel)
| 2003-02-06          Pet     ESCAN00004881: add support for NM JUNIOR
| 2003-03-24  1.03    Pet     version changed
| 2003-04-01  1.04    Pet     ESCAN00005345: separation CCL into core files and OEM extension files
| 2003-06-05  1.05    Pet     CCL DLL version change
| 2003-06-16  1.05.01 Pet     version changed
| 2003-07-25  1.05.02 Pet     version changed
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
| 2005-02-18  1.23.00 Bs      only the version number changed in this file
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
| 2007-08-13  2.18    Dhf     ESCAN00021870: no changes in this file
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
|                             ESCAN00037646: no changes in this file
|                             ESCAN00037703: no changes in this file
|                             ESCAN00037697: no changes in this file
| 2009-12-03  2.41    Dhf     ESCAN00039551: no changes in this file
| 2010-01-07  2.42    Dhf     ESCAN00039850: no changes
| 2010-02-18  2.43    Dhf     ESCAN00040967: no changes
|                             ESCAN00040721: no changes
| 2010-06-15  2.44    Dhf     ESCAN00043411: no changes
|                             ESCAN00043412: no changes
|                             ESCAN00043536: no changes
| 2010-07-20  2.45    Dhf     ESCAN00044173: no changes
|                             ESCAN00044298: no changes
| 2010-08-05  2.46    Dhf     ESCAN00028369: no changes
|                             ESCAN00028484: no changes
|                             ESCAN00028492: no changes
|                             ESCAN00028799: no changes
|                             ESCAN00044475: no changes
| 2010-08-16  2.47    Dhf     ESCAN00044481: no changes
|                             ESCAN00037523: no changes
|                             ESCAN00025339: no changes
|                             ESCAN00044778: no changes
|                             ESCAN00044782: no changes
|****************************************************************************/


/* Check if information is already included */
#ifndef CCL_H
#define CCL_H

/***************************************************************************/
/* HEADER-FILES (Only those that are needed in this file)                  */ 
/***************************************************************************/
/* System-headerfiles */
#include "ccl_par.h"
#include "ccl_inc.h"   /* Public definitions and types */

/***************************************************************************/ 
/* Include files                                                           */ 
/***************************************************************************/ 

/***************************************************************************/ 
/* Version                  (abcd: Main version ab Sub Version cd )        */ 
/***************************************************************************/ 
#if( CCL__CORE_VERSION != 0x0247)
 #error "CCL core version number is inconsistent!"
#endif

#if( CCL__CORE_RELEASE_VERSION != 0x00)
 #error "CCL core release number are inconsistent!"
#endif


/***************************************************************************/ 
/* Defines                                                                 */ 
/***************************************************************************/ 
#define kCclExtChWupReq           0x01
#define kCclNoExtChWupReq         0xFF

#define kCclNoIntNetReq           0xFF
#define kCclNoIntNetRel           0xFF

#define kCclDisablePortIRQ        0x00
#define kCclEnablePortIRQ         0x01


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
/* error codes                                                             */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* macros                                                                  */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* compatibility defines                                                   */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* function prototypes internal                                            */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* data types                                                              */ 
/***************************************************************************/ 



/***************************************************************************/ 
/* External Declarations                                                   */ 
/***************************************************************************/ 


/***************************************************************************/ 
/* Callback functions                                                      */ 
/***************************************************************************/ 


#endif /* ifndef CCL_H */
/************************** end of file ***************************************/ 
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
