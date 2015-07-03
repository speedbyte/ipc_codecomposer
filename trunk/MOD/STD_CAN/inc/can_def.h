/* Kernbauer Version: 1.14 Konfiguration: can_driver Erzeugungsgangnummer: 1 */

/* STARTSINGLE_OF_MULTIPLE */

#ifndef  CAN_HL_H
# define  CAN_HL_H


/*****************************************************************************
| Project Name: C A N - D R I V E R
|    File Name: CAN_DEF.H
|
|  Description: Application-Interface of the CAN-Driver
|               Declaration of functions, variables, and constants
|
|     Compiler: see module file
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 1996-2009 by Vector Informatik GmbH.       All rights reserved.
|
| This software is copyright protected and proprietary 
| to Vector Informatik GmbH. Vector Informatik GmbH 
| grants to you only those rights as set out in the 
| license conditions. All other rights remain with 
| Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Ml           Patrick Markl             Vector Informatik GmbH
| Ard          Thomas Arnold             Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
|Date        Version   Author  Description
|----------  --------  ------  -----------------------------------------------
|2003-02-27  00.01.00    Ml     - Creation
|2003-07-07  00.02.00    Ml     - ESCAN00005987: added support for extended and mixed ID
|2003-07-31  00.03.00    Ml     - resolved issues found in code inspection
|2003-08-01  01.00.00    Ml     - Release for TMS320
|2003-08-03  01.01.00    Ml     - ESCAN00006259: no changes
|2003-08-04  02.00.00    Ml     - ESCAN00006262: added support for TMS470
|2003-12-04  03.00.00    Ml     - ESCAN00007131: added support for OMAP
|2004-01-13  03.01.00    Ml     - ESCAN00007253: fixed several Issues
|2004-01-18  03.02.00    Ml     - ESCAN00007282: no changes
|2004-02-21  03.03.00    Ml     - ESCAN00007670: added CAN RAM check
|2004-03-03  03.04.00    Ml     - ESCAN00007632: no changes
|2004-03-31              Ml     - ESCAN00008069: HECC workaround is configurable   
|2004-04-01              Ml     - ESCAN00008079: Resolved review issues    
|2004-05-17  03.05.00    Ml     - ESCAN00008423: no changes
|2004-07-11  03.06.00    Ml     - ESCAN00008818: no changes
|                        Ml     - ESCAN00006634: resolved errorcounter access
|                        Ml     - ESCAN00008818: no changes
|                        Ml     - ESCAN00008878: no changes
|                        Ml     - ESCAN00008986: no changes
|                        Ml     - ESCAN00007281: no changes
|                        Ml     - ESCAN00008986: no changes
|                        Ml     - ESCAN00009115: Support multiple configurations
|                        Ml     - ESCAN00010073: no changes
|                        Ml     - ESCAN00008885: no changes
|2004-10-19  03.07.00    Ml     - ESCAN00009135: changed handling of LoopCheck Returnvalues 
|                        Ml     - ESCAN00010203: no changes
|                        Ml     - ESCAN00010047: no changes
|                        Ml     - ESCAN00010625: no changes
|                        Ml     - ESCAN00007215: Added memcpy support
|                        Ml     - ESCAN10626, ESCAN10630: no changes
|2005-01-20  04.00.00    Ml     - ESCAN00011416: added support for TMS430
|2005-04-04  04.01.00    Ml     - ESCAN00011745: Changes after review and MISRA check
|                        Ml     - ESCAN00011746: Rx masking also possible in SCC mode (TMS470)
|2005-11-04  04.02.00    Ml     - ESCAN00014177: no changes
|2005-12-02  04.03.00    Ml     - ESCAN00014307: Changed version defines
|                        Ml     - ESCAN00013946: Changed prototypes because of compiler issue
|2005-12-12  04.04.00    Ml     - ESCAN00014611: Share code among CAN and LIN driver
|2006-01-30  04.05.00    Ard    - ESCAN00014987: Support new derivative TMS470P family
|                               - ESCAN00015100: Update to new highlevel version 1.39
|                               - ESCAN00015120: no changes
|                               - ESCAN00015551
|                                 ESCAN00015552
|                                 ESCAN00015553
|                                 ESCAN00015158: RawID macros for Standard ID
|2006-02-06  04.06.00    Ard    - ESCAN00015203
|                                 ESCAN00015208
|                                 ESCAN00015209
|                                 ESCAN00015211: Read error/status flags from CANES register correctly
|                               - ESCAN00015265
|                                 ESCAN00015556
|                                 ESCAN00015557: Change macros CanTxWriteActId, CanTxWriteActIdExt and CanTxWriteActDlc
|                               - ESCAN00015266: Fix number of used shadow buffers in SCC mode
|                               - ESCAN00015267: Suppress reception of remote frames
|                               - ESCAN00015268: Support for no usermode (GENy)
|                               - ESCAN00015341
|                                 ESCAN00015562: Set priority of low level message
|                               - ESCAN00015347
|                                 ESCAN00015564
|                                 ESCAN00015565
|                                 ESCAN00015566: Improve reception of Rx Basic/Full CAN messages
|                               - ESCAN00015348: Changes in HECC workaround
|2006-02-21  04.07.00    Ard    - ESCAN00015429: Minor changes
|                               - ESCAN00015832
|                                 ESCAN00015833
|                                 ESCAN00014933: Add version scan comments
|                               - ESCAN00015505: Support unprivileged driver with GENy
|                               - ESCAN00015661: Support ARM compiler for Omap59xx
|                               - ESCAN00015770: Suppressed TxConfirmation in case of cancelation in hw
|                               - ESCAN00015693: Support LowLevelTransmit messages
|                               - ESCAN00015697
|                                 ESCAN00015699: Fix Full CAN overrun handling
|                               - ESCAN00015706: MISRA compliance
|                               - ESCAN00015835
|                                 ESCAN00015836
|                                 ESCAN00015837
|                                 ESCAN00015839: Allow calls to CAN API in ApplCanWakeUp()
|2006-05-15  04.08.00    Ard    - ESCAN00016129: Fix global interrupt lock (TMS320)
|                                 ESCAN00016178: Compile error if C_ENABLE_CAN_RAM_CHECK is enabled
|                                 ESCAN00015891: Remove C_CLIENT_VECTOR switch
|                                 ESCAN00016334: Minor changes in WakeUp Handling
|                                 ESCAN00016351: MISRA compliance
|2006-06-28  04.09.00    Ard    - ESCAN00015555: Fix CanTxWriteActId,IdExt,Dlc macros (TMS320)
|                                 ESCAN00016467: Modify HECC_WORKAROUND_2
|                                 ESCAN00016788: Adapt OPC for usage of 3 Mailboxes for BasicCAN
|                                 ESCAN00016804: Ignore additional interrupt in ISR if CAN IRQs are disabled
|2006-08-21  04.10.00    Ard    - ESCAN00017119: MISRA for TMS320
|                                 ESCAN00016960: Apply review results (Minor changes for TMS320)
|                                 ESCAN00016963: Fix data copy in CanBasicCanMsgReceived (Omap)
|                                 ESCAN00017169: Improve handling of pending Rx messages in RxTasks
|                                 ESCAN00017338: Remove compiler warning (unused variable canMsgTransmitted)
|                                 ESCAN00015697: Apply review changes (Omap)
|2007-08-15  04.11.00    Ard    - ESCAN00019253: Remove warning at declaration of CanWritePrivileged()
|                                 ESCAN00021683: Add support for GreenHills compiler
|                                 ESCAN00019619: Fix compile error due to missing V_CALLBACK_1 and V_CALLBACK_2
|                                 ESCAN00019620: Add missing declaration of CAN_HW_CHANNEL_CANTYPE_FIRST
|2007-10-10  04.12.00    Ard    - ESCAN00022615: Fix bus off notification
|                                 ESCAN00020784: Rearrange CanTxWriteActId macro
|                                 ESCAN00022708: Use identical code sequence for internal and external wake-up
|2007-11-08  04.13.00    Ard    - ESCAN00022707: Support TMS320 Microsoft compiler (beta)
|                                 ESCAN00023395: Initialize ID register of Normal Tx message object 
|                                 ESCAN00023506: Fix cancelation in hardware in case of Tx polling mode
|2007-12-04  04.14.00    Ard    - ESCAN00022707: Support TMS320 Microsoft compiler (final)
|                                 ESCAN00023533: Fix data copy algorithm for Omap
|                                 ESCAN00023732: Add missing interrupt acknowledge after cancellation in hardware
|2008-01-17  04.15.00    Ard    - ESCAN00024106: Style improvements
|2008-03-04  04.16.00    Ard    - ESCAN00025079: Support multiple ECU configuration
|                                 ESCAN00024835: Support CanGetDriverStatus API
|2008-04-16  05.00.00    Ard    - ESCAN00028357: Support AUTOSAR (RI1.5), Remove platform TMS430
|2008-07-28  05.01.00    Ard    - ESCAN00028763: Fix reception of remote frames
|                                 ESCAN00028825: Improve copy algorithm for BasicCAN and FullCAN message
|                                 ESCAN00029273: Support Platform TMS320Arm (RI1.5)
|                                 ESCAN00029276: Support Platform Omap (AUTOSAR 3.0)
|                                 ESCAN00030789: Fix DLC of low level messages if HECC_WORKAROUND_2 is activated
|2008-12-09  05.02.00    Ard    - ESCAN00031892: Support Platform Omap (RI1.5)
|                                 ESCAN00032039: Fix issue in CanInterruptLock functionality
|                                 ESCAN00032395: Avoid unexpected repeated Rx interrupts in sleep mode
|2009-02-05  05.03.00    Ard    - ESCAN00032849: Support Platform Tms470 (RI1.5)
|****************************************************************************/
/*****************************************************************************
|
|    ************    Version and change information of      **********        
|    ************    high level part only                   **********        
|
|    Please find the version number of the whole module in the previous 
|    File header.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| Ht           Heike Honert              Vector Informatik GmbH
| Pl           Georg Pfluegel            Vector Informatik GmbH
| Vg           Frank Voorburg            Vector CANtech, Inc.
| An           Ahmad Nasser              Vector CANtech, Inc.
| Ml           Patrick Markl             Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Ver  Author  Description
| ---------  ---  ------ -----------------------------------------------------
| ---------  ---  ------ -- --------------------------------------------------
| 24-Jan-01  0.02      Ht     - derived from C16x V3.3
| 18-Apr-01  1.00      Pl     - adaption for ARM7 TDMI
| 26-Apr-01  1.01      Ht     - adaption to LI 1.2
|                             - changed from code doupling to indexed
| 19-Jun-01            Ht     - define of CanSetActive/Passive changed
| 31-Oct-01  1.02      Ht     - support hash search
|                      Vg     - adaption for PowerPC
| 07-Nov-01  1.03      Ht     - remove some comments
| 12-Nov-01  1.04      Fz     - no changes
| 02-Jan-02  1.05      Ht     - ESCAN00002009: support of polling mode improved
| 12-Feb-02  1.06      Pl     - ESCAN00002279: - now it is possible to use only the error-task without the tx-task
|                                              - support of the makro  REENTRANT
|                                              - support of the makro C_HL_ENABLE_RX_INFO_STRUCT_PTR
|                                              - For better performance for the T89C51C there is a switch-case
|                                                instruction for direct call of the PreTransmitfunction
|                                              - insert Prototyp for CanErrorTask
| 18-Mai-02  1.07       Ht    - ESCAN....    : support Hash search with FullCAN controller
|                             - ESCAN00002707: Reception could went wrong if IL and Hash Search
|                             - ESCAN00002893: adaption to LI 1.3
| 29-Mai-02  1.08       Ht    - ESCAN00003028: Transmission could fail in Polling mode
|                             - ESCAN00003082: call Can_LL_TxEnd() in CanMsgTransmit()
|                             - ESCAN00003083: Hash search with extended ID
|                             - ESCAN00003084: Support C_COMP_METROWERKS_PPC
|                             - ESCAN00002164: Temporary vaiable "i" not defined in function CanBasicCanMsgReceived
|                             - ESCAN00003085: support C_HL_ENABLE_IDTYPE_IN_ID
| 25-Jun     1.08.01    Vg    - Declared localInterruptOldFlag in CanRxTask()
|                             - Corrected call to CanWakeUp for multichannel
| 11-Jul-02  1.08.02    Ht    - ESCAN00003203: Hash Search routine does not work will with extended IDs
|                             - ESCAN00003205: Support of ranges could went wrong on some platforms
| 08-Aug-02  1.08.03    Ht    - ESCAN00003447: Transmission without databuffer and pretransmit-function 
| 08-Aug-02  1.08.04    An      no changes
| 09-Sep-02  1.09       Ht    - ESCAN00003837: code optimication with KernelBuilder 
| 2002-12-12 1.10       Ht    -                support Dummy functions for indirect function call 
| 2003-02-04 1.11       Ht    -                optimization for polling mode
|                       Fz    - ESCAN00004600: Flags changed for V850 aFCAN only
| 2003-03-19 1.12       Ht    - ESCAN00005153: Wrong number of Indication bytes for V850 aFCAN only
|                             - ESCAN00005152: optimization of CanInit() in case of Direct Tx Objects
|                             - ESCAN00005143: CompilerWarning about function prototype 
|                                              CanHL_ReceivedRxHandle() and CanHL_IndRxHandle
|                             - ESCAN00005130: Wrong result of Heash Search on second or higher channel               
| 2003-05-12 1.13       Ht    - ESCAN00005624: support CantxMsgDestroyed for multichannel system
|                             - ESCAN00005209: Support confirmation and indication flags for EasyCAN4
|                             - ESCAN00004721: Change data type of Handle in CanRxInfoStruct
| 2003-06-18 1.20       Ht    - ESCAN00005908: support features of RI1.4
|                             - ESCAN: Support FJ16LX-Workaround for multichannel system
|                             - ESCAN00005671: Dynamic ID in extended ID system could fail
|                             - ESCAN00005863: Notification about cancelation failes in case of CanTxMsgDestroyed
| 2003-06-30 1.21       Ht   - ESCAN00006117: Common Confirmation Function: Write access to wrong memory location
|                            - ESCAN00006008: CanCanInterruptDisable in case of polling
|                            - ESCAN00006118: Optimization for Mixed ID and ID type in Own Register or ID type in ID Register
|                            - ESCAN00006063: Undesirable hardware dependency for 
|                                             CAN_HL (CanLL_RxBasicTxIdReceived)
| 2003-09-10 1.22       Ht   - ESCAN00006853: Support V_MEMROM0
|                            - ESCAN00006854: suppress some Compiler warnings
|                            - ESCAN00006856: support CanTask if only Wakeup in polling mode
|                            - ESCAN00006857: variable newDLC not defined in case of Variable DataLen
| 2003-10-14 1.23       Ht   - ESCAN00006858: support BrsTime for internal runtime measurement
|                            - ESCAN00006860: support Conditional Msg Receive
|                            - ESCAN00006865: support "Cancel in HW" with CanTask
|                            - ESCAN00006866: support Direct Tx Objects
|                            - ESCAN00007109: support new memory qualifier for const data and pointer to const
| 2004-01-05 1.24       Ml   - ESCAN00007206: no changes
|                       Ml   - ESCAN00007254: several changes
| 2004-02-06 1.25       Ml   - ESCAN00007281: no changes
|                       Ml   - removed compiler warnings
| 2004-02-21 1.26       Ml   - ESCAN00007670: CAN RAM check
|                       Ml   - ESCAN00007671: no changes
|                       Ml   - ESCAN00007764: no changes
|                       Ml   - ESCAN00007681: no changes
|                       Ml   - ESCAN00007272: no changes
|                       Ml   - ESCAN00008064: encapsulated CanRxHashId in case of array dimension == 0
| 2004-04-16 1.27       Ml   - ESCAN00008204: Optimized CanRxActualId for different ID modes
|                       Ml   - ESCAN00008160: encapsulated functions declared by tool in case of multichannel
|                       Ml   - ESCAN00008266: changed name of parameter of function CanTxGetActHandle
|                       Fz   - ESCAN00008272: Compiler error due to missing array canPollingTaskActive
| 2004-05-10 1.28       Fz   - ESCAN00008328: Compiler error if cancel in hardware is active
|                            - ESCAN00008363: Hole closed when TX in interrupt and cancel in HW is used
|                            - ESCAN00008365: Switch C_ENABLE_APPLCANPREWAKEUP_FCT added
|                            - ESCAN00008391: Wrong parameter macro used in call of 
|                                             CanLL_WakeUpHandling
| 2004-05-24 1.29       Ht   - ESCAN00008441: Interrupt not restored in case of internal error if TX Polling is used
| 2004-09-21 1.30       Ht   - ESCAN00008824: check of reference implementation version added
|                            - ESCAN00008825: No call of ApplCanMsgCancelNotification during CanInit()
|                            - ESCAN00008826: Support asssertions for "Conditional Message Received"  
|                       Ml   - ESCAN00008752: Added function qualifier macros
|                       Ht   - ESCAN00008823: compiler error due to array size 0
|                            - ESCAN00008977: label without instructions
|                            - ESCAN00009485: Message via Normal Tx Object will not be sent  
|                            - ESCAN00009497: support of CommonCAN and RX queue added
| 2004-09-28 1.31       Ht   - ESCAN00009703: unresolved functions CAN_POLLING_IRQ_DISABLE/RESTORE()
| 2004-11-25 1.32       Ht   - move fix for ESCAN00007671 to CAN-LL of DrvCan_MpcToucanHll
|                            - ESCAN00010350: Dynamic Tx messages are send always with Std. ID
|                            - ESCAN00010388: ApplCanMsgConfirmed will only be called if realy transmitted
|                       Ml   - ESCAN00009931: The HardwareLoopCheck should have a channelparameter in multichannel systems.
|                            - ESCAN00010093: lint warning: function type inconsistent "CanCheckMemory"
|                        Ht  - ESCAN00010811: remove Misra and compiler warnings
|                            - ESCAN00010812: support Multi ECU
|                            - ESCAN00010526: CAN interrupts will be disabled accidently
|                            - ESCAN00010584: ECU may crash or behave strange with Rx queue active
| 2005-01-20 1.33       Ht   - ESCAN00010877: ApplCanMsgTransmitConf() is called erronemous
| 2005-03-03 1.34       Ht   - ESCAN00011139: Improvement/Correction of C_ENABLE_MULTI_ECU_CONFIG
|                            - ESCAN00011511: avoid PC-Lint warnings
|                            - ESCAN00011512: copy DLC in case of variable Rx Datalen
|                            - ESCAN00010847: warning due to missing brakets in can_par.c at CanChannelObject
| 2005-05-23 1.35       Ht   - ESCAN00012445: compiler error "V_MEMROMO undefined"in case of multi ECU
|                            - ESCAN00012350: Compiler Error "Illegal token channel"
| 2005-07-06 1.36       Ht   - ESCAN00012153: Compile Error: missing declaration of variable i
|                            - ESCAN00012460: Confirmation of LowLevel message will run into assertion (C_ENABLE_MULTI_ECU_PHYS enabled)
|                            - support Testpoints for CanTestKit
| 2005-07-14 1.37       Ht   - ESCAN00012892: compile error due to missing logTxObjHandle
|                            - ESCAN00012998: Compile Error: missing declaration of txHandle in CanInit()
|                            - support Testpoints for CanTestKit for FullCAN controller
| 2005-10-05 1.38       Ht   - ESCAN00013597: Linker error: Undefined symbol 'CanHL_IndRxHandle'
| 2005-11-10 1.39.00    Ht   - ESCAN00014331: Compile error due to missing 'else' in function CanTransmit
| 2005-04-26 2.00.00    Ht   - ESCAN00016698: support RI1.5
|                            - ESCAN00014770: Cosmic compiler reports truncating assignement
|                            - ESCAN00016191: Compiler warning about unused variable in CanTxTask
| 2007-01-23 2.01.00    Ht   - ESCAN00017279: Usage of SingleGlobalInterruptDisable lead to assertion in OSEK
|                            - ESCAN00017148: Compile error in higher layer due to missing declaration of CanTxMsgHandleToChannel
| 2007-03-14 2.02.00   Ht    - ESCAN00019825: error directives added and misra changes
|                            - ESCAN00019827: adaption to never version of VStdLib.
|                            - ESCAN00019619: V_CALLBACK_1 and V_CALLBACK_2 not defined
|                            - ESCAN00019953: Handling of FullCAN reception in interrupt instead of polling or vice versa.
|                            - ESCAN00019958: CanDynTxObjSetId() or CanDynTxObjSetExtId() will run into assertion
| 2007-03-26 2.03.00  Ht     - ESCAN00019988: Compile warnings in can_drv.c
|                            - ESCAN00018831: polling mode: function prototype without function implemenation (CanRxFullCANTask + CanRxBasicCANTask)
| 2007-04-20 2.04.00  dH     - ESCAN00020299: user assertion fired irregularly due to unknown parameter (in case of CommonCAN)
| 2007-05-02 2.05.00  Ht     - ESCAN00021069: Handling of canStatus improved, usage of preprocessor defines unified
|                            - ESCAN00021070: support relocation of HW objects in case of Multiple configuration
|                            - ESCAN00021166: Compiler Warnings: canHwChannel & canReturnCode not used in CanGetStatus
|                            - ESCAN00021223: CanCanInterruptDisabled called during Sleepmode in CanWakeupTask
|                            - ESCAN00022048: Parameter of ApplCancorruptMailbox is hardware channel instead of logical channel - Error directive added
| 2007-11-12 2.06.00  Ht     - ESCAN00023188: support CAN Controller specific polling sequence for BasicCAN objects
|                            - ESCAN00023208: Compile issue about undefined variable kCanTxQueuePadBits in the CAN driver in Bit based Tx queue
| 2008-10-20 2.07.00  Ht     - ESCAN00023010: support disabled mailboxes in case of extended RAM check
|                            - ESCAN00025706: provide C_SUPPORTS_MULTI_ECU_PHYS
|                            - ESCAN00026120: compiler warnings found on DrvCan_V85xAfcanHll RI 1.5     ##Ht: reviewed 2008-09-03
|                            - ESCAN00026322: ApplCanMsgNotMatched not called in special configuration
|                            - ESCAN00026413: Add possibility to reject remote frames received by FullCAN message objects
|                            - ESCAN00028758: CAN HL must support QNX
|                            - ESCAN00029788: CommonCAN for Driver which support only one Tx object improved (CanInit()).
|                            - ESCAN00029889: Compiler warning about uninitialized variable canHwChannel in CanCanInterruptDisable/Restore()
|                            - ESCAN00029891: Compiler warning: variable "rxHandle" was set but never used
|                            - ESCAN00029929: Support Extended ID Masking for Tx Fullcan messages 
|                            - ESCAN00030371: Improvements (assertions, misra)
|
|    ************    Version and change information of      **********        
|    ************    high level part only                   **********        
|
|    Please find the version number of the whole module in the previous 
|    File header.
|
|****************************************************************************/


/***************************************************************************/
/* Version                  (abcd: Main version ab Sub Version cd )        */
/***************************************************************************/
#if defined(C_COMP_TI_TMS470)            
/* ##V_CFG_MANAGEMENT ##CQProject : DrvCan_Tms470HeccsccHll CQComponent : Implementation */
# define DRVCAN_TMS470HECCSCCHLL_VERSION 0x0503
# define DRVCAN_TMS470HECCSCCHLL_RELEASE_VERSION 0x00
#endif


/* ##V_CFG_MANAGEMENT ##CQProject : DrvCan__coreHll CQComponent : Implementation */
# define DRVCAN__COREHLL_VERSION                 0x0207
# define DRVCAN__COREHLL_RELEASE_VERSION         0x00

#define DRVCAN__HLLTXQUEUEBIT_VERSION 0x0105
#define DRVCAN__HLLTXQUEUEBIT_RELEASE_VERSION 0x00

/***************************************************************************/
/* Include                                                                 */
/***************************************************************************/

# include "v_def.h"

/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/

/***************************************************************************/
/* Default switches                                                        */
/* Automatic define settings, depending on user configuration in can_cfg.h */
/***************************************************************************/
# if defined( C_ENABLE_MULTICHANNEL_API )
#  define C_MULTIPLE_RECEIVE_CHANNEL
#  define MULTIPLE_RECEIVE_CHANNEL
# else
#  define C_SINGLE_RECEIVE_CHANNEL
# endif

# if ( kCanNumberOfTxObjects > 0 )
#  if !(defined( C_ENABLE_CAN_TRANSMIT ) || defined( C_DISABLE_CAN_TRANSMIT ))
#   define C_ENABLE_CAN_TRANSMIT
#  endif
# endif

# if !(defined( C_ENABLE_OFFLINE ) || defined( C_DISABLE_OFFLINE ))
#  define C_ENABLE_OFFLINE
# endif

# if !(defined( C_ENABLE_STOP ) || defined( C_DISABLE_STOP ))
#  define C_ENABLE_STOP
# endif

# if !(defined( C_ENABLE_CAN_CAN_INTERRUPT_CONTROL ) || defined( C_DISABLE_CAN_CAN_INTERRUPT_CONTROL ))
#  define C_ENABLE_CAN_CAN_INTERRUPT_CONTROL
# endif

# if !(defined( C_ENABLE_CAN_CANCEL_TRANSMIT ) || defined( C_DISABLE_CAN_CANCEL_TRANSMIT ))
#  if defined( C_ENABLE_CAN_TRANSMIT )
#   define C_ENABLE_CAN_CANCEL_TRANSMIT
#  endif
# endif

# if !defined( kCanNumberOfHwChannels )
/* compatibility for older tool versions */
#  define kCanNumberOfHwChannels                 kCanNumberOfChannels
# endif

#define C_HL_DISABLE_OVERRUN_IN_STATUS

#define C_HL_DISABLE_HW_RANGES_FILTER

#define C_HL_ENABLE_IDTYPE_IN_ID


#if defined(C_HL_ENABLE_IDTYPE_IN_ID)
/* Specify the ID tables which contain the ID type */
# define C_LL_RX_IDTYPE_TABLE      CanRxId0
# define C_LL_TX_IDTYPE_TABLE      CanTxId0
#endif


#define C_HL_DISABLE_DUMMY_FCT_CALL


#define C_HL_DISABLE_TX_MSG_DESTROYED


#define C_HL_DISABLE_CANCEL_IN_HW_TASK


#define C_HL_DISABLE_HW_EXIT_TRANSMIT 

#if defined(C_ENABLE_SLEEP_WAKEUP)
# define C_HL_ENABLE_LAST_INIT_OBJ     
#endif

/* TMS470 / Tms320Arm / Omap driver does not disable CAN interrupts to avoid phantom interrupts */
# define C_HL_DISABLE_CAN_IRQ_DISABLE


#define C_HL_DISABLE_ADJUST_RXHANDLE  


#define C_HL_DISABLE_REJECT_UNWANTED_IDTYPE

#define C_HL_ENABLE_REJECT_REMOTE_FRAME
#define C_HL_ENABLE_REJECT_REMOTE_FRAME_FULLCAN

#define C_HL_DISABLE_COPROCESSOR_SUPPORT


# if !( defined (C_ENABLE_DRIVER_STATUS) || defined (C_DISABLE_DRIVER_STATUS))
#  define C_ENABLE_DRIVER_STATUS
# endif

#if defined(C_COMP_TI_TMS470)                     
# if defined(C_PROCESSOR_TI_TMS470PLF521)         || \
     defined(C_PROCESSOR_TI_TMS470P)
#  define C_ENABLE_LAMOFFSETFROMRAM
# endif
#endif


#if defined(C_COMP_TI_TMS470)            
#define C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC
#else
#define C_LL_DISABLE_CONTROLLERMODE_HECCANDSCC      /* HECC only, not configurable */
#endif

#if defined (C_ENABLE_LAMOFFSETFROMRAM)
#define CAN_CONTROLLER_SIZE                   0x80
#define CAN_MAILBOX_SIZE                      0x1380
#else
#define CAN_CONTROLLER_SIZE                   0x200
#define CAN_MAILBOX_SIZE                      0x200
#endif



# if !defined( C_CALLBACK_1 )
#  define C_CALLBACK_1
# endif

# if !defined( C_CALLBACK_2 )
#  define C_CALLBACK_2
# endif

# if !defined( C_API_1 )
#  define C_API_1
# endif

# if !defined( C_API_2 )
#  define C_API_2
# endif

# if !defined( C_API_3 )
#  define C_API_3                                REENTRANT
# endif

# if !defined( REENTRANT )
#  define REENTRANT
# endif

# if defined( C_ENABLE_TX_POLLING )
#  if !(defined( C_ENABLE_ERROR_POLLING )  || defined( C_DISABLE_ERROR_POLLING ))
#   define C_ENABLE_ERROR_POLLING 
#  endif
# endif

# if !(defined( C_ENABLE_TASK_RECURSION_CHECK ) || defined( C_DISABLE_TASK_RECURSION_CHECK ))
#  define C_ENABLE_TASK_RECURSION_CHECK
# endif

# if defined( C_ENABLE_MULTI_ECU_PHYS )
#  define C_SUPPORTS_MULTI_ECU_PHYS
# endif

/***************************************************************************/
/* return values                                                           */
/***************************************************************************/

/* return values for precopy-routines */
# define kCanNoCopyData                          ((vuint8)0x00)
# define kCanCopyData                            ((vuint8)0x01)

/* Bitmask of return value of CanGetStatus() */
# define kCanTxOff                               ((vuint8)0x00)
# define kCanStatusInit                          ((vuint8)0x00)
# define kCanTxOn                                ((vuint8)0x01)
# define kCanTxNotOn                             ((vuint8)0xFE)              /* internal use only */
# define kCanHwIsStop                            ((vuint8)0x02)
# define kCanHwIsInit                            ((vuint8)0x04)
# define kCanHwIsInconsistent                    ((vuint8)0x08)              /* used of for common CAN */
# define kCanHwIsWarning                         ((vuint8)0x10)
# define kCanHwIsPassive                         ((vuint8)0x20)
# define kCanHwIsBusOff                          ((vuint8)0x40)
# define kCanHwIsSleep                           ((vuint8)0x80)

/* CanTransmit return values -----------------------------------------------*/
# define kCanTxFailed                            ((vuint8)0x00)  /* Tx path switched off or no sending possible */
# define kCanTxOk                                ((vuint8)0x01)  /* msg transmitted or in queue                 */
# define kCanTxPartOffline                       ((vuint8)0x02)  /* Tx path switched part off or           */
# define kCanCommunicationDisabled               ((vuint8)0x03)  /* if application has disabled com after memory check */

# if defined( C_DRV_INTERNAL )
#  define kCanTxNotify                           ((vuint8)0x05)  /* internal returncode only - not used for the API */
# endif

/* CanGetDynTxObj return values -----------------------------------------------*/
# define kCanNoTxDynObjAvailable                 ((CanTransmitHandle)0xFFFFFFFFU)

/* CanReleaseDynTxObj return values -------------------------------------------*/
# define kCanDynReleased                         ((vuint8)0x00)
# define kCanDynNotReleased                      ((vuint8)0x01)

/* generel return values */
# define kCanFailed                              ((vuint8)0x00)
# define kCanOk                                  ((vuint8)0x01)
# define kCanNotSupported                        ((vuint8)0x02)

# define kCanFalse                               ((vuint8)0x00)
# define kCanTrue                                ((vuint8)0x01)

/* CanTxGetActHandle return value - status of transmit objects */
# define kCanBufferMsgTransmit                   ((CanTransmitHandle)0xFFFFFFFCU)   /* mark a transmit object as used by CanMsgTransmit */

/* results of CAN RAM check */
# define kCanRamCheckFailed                      ((vuint8)0x00)
# define kCanRamCheckOk                          ((vuint8)0x01)
# define kCanDisableCommunication                ((vuint8)0x00)
# define kCanEnableCommunication                 ((vuint8)0x01)


/* return values of CanRxActualIdType */
#define kCanIdTypeStd                            (0x00UL)
#define kCanIdTypeExt                            (0x80000000UL)


/* return values of CanGetDriverStatus */
#define kCanDriverBusoff        0x01u             /* CAN driver is in recovery phase after bus off */ 
#define kCanDriverBusoffInit    0x02u             /* Driver finished recovery and needs to be initialized */
#define kCanDriverNormal        0x03u             /* Driver completed recovery and is in normal mode */ 

/***************************************************************************/
/* parameter values                                                        */
/***************************************************************************/
/* parameters for partial offline */
# define kCanTxPartInit                          ((vuint8)0x00)

/* paramater for assertions */
# define kCanAllChannels                         ((CanChannelHandle)0xFFU)
/* used for generated tables */
# define kCanChannelNotUsed                      ((CanChannelHandle)0xFFU)

/* canRxHandle does not contain a certain message handle or entry in table is not used */
# define kCanRxHandleNotUsed                     ((CanReceiveHandle)  0xFFFFFFFFU)
# define kCanTxHandleNotUsed                     ((CanTransmitHandle) 0xFFFFFFFFU)

# if defined( C_DRV_INTERNAL )
#  define kCanRxHandleRange0                     ((CanReceiveHandle)  0xFFFFFFF0U)
#  define kCanRxHandleRange1                     ((CanReceiveHandle)  0xFFFFFFF1U)
#  define kCanRxHandleRange2                     ((CanReceiveHandle)  0xFFFFFFF2U)
#  define kCanRxHandleRange3                     ((CanReceiveHandle)  0xFFFFFFF3U)

/* entries for generated table CanHwMsgTransmitIndex[], CanHwTxNormalIndex[] - unsed in case of CommonCan */
/* table entry does not contain a HW object assignment */
#  define kCanObjectHandleNotUsed                ((CanObjectHandle)0xFFU)
# endif
/* parameter for ApplCanTimerStart(),-End(), -Loop()*/
#define kCanLoopWaitConfigChangeEnable     ((vuint8)0x00)
#define kCanLoopWaitPowerDownMode          ((vuint8)0x01)
#define kCanLoopWaitLeavePowerDownMode     ((vuint8)0x02)
#define kCanLoopCopyRxBasicMailBox         ((vuint8)0x03)
#define kCanLoopWaitCanStop                ((vuint8)0x04)
#define kCanLoopWaitCanStart               ((vuint8)0x05)
#define kCanLoopCopyRxFullMailBox          ((vuint8)0x06)


/***************************************************************************/
/* macros                                                                  */
/***************************************************************************/

# if defined( C_SINGLE_RECEIVE_CHANNEL ) 
#  define CAN_CHANNEL_CANTYPE_ONLY               void                                 /* PRQA S 3460 */
#  define CAN_CHANNEL_CANTYPE_FIRST
#  define CAN_CHANNEL_CANTYPE_LOCAL         
#  define CAN_CHANNEL_CANPARA_ONLY
#  define CAN_CHANNEL_CANPARA_FIRST
#  define CAN_HW_CHANNEL_CANTYPE_ONLY            void                                 /* PRQA S 3460 */
#  define CAN_HW_CHANNEL_CANTYPE_FIRST
#  define CAN_HW_CHANNEL_CANTYPE_LOCAL
#  define CAN_HW_CHANNEL_CANPARA_ONLY
#  define CAN_HW_CHANNEL_CANPARA_FIRST
# else
#  define CAN_CHANNEL_CANTYPE_ONLY               CanChannelHandle channel
#  define CAN_CHANNEL_CANTYPE_FIRST              CanChannelHandle channel,
#  define CAN_CHANNEL_CANTYPE_LOCAL              CanChannelHandle channel;             /* PRQA S 3412 */
#  define CAN_CHANNEL_CANPARA_ONLY               channel
#  define CAN_CHANNEL_CANPARA_FIRST              channel,
#  define CAN_HW_CHANNEL_CANTYPE_ONLY            CanChannelHandle canHwChannel
#  define CAN_HW_CHANNEL_CANTYPE_FIRST           CanChannelHandle canHwChannel,
#  define CAN_HW_CHANNEL_CANTYPE_LOCAL           CanChannelHandle canHwChannel;        /* PRQA S 3412 */
#  define CAN_HW_CHANNEL_CANPARA_ONLY            canHwChannel
#  define CAN_HW_CHANNEL_CANPARA_FIRST           canHwChannel,
# endif

# if defined( C_DRV_INTERNAL )
/* macros to fill struct elements RangeMask and RangeCode of type tCanChannelObject - used by generation tool only */
#  if (kCanNumberOfUsedCanRxIdTables == 1)
#   define MK_RX_RANGE_MASK_IDSTD(i)             {MK_RX_RANGE_MASK_IDSTD0(i)}
#   define MK_RX_RANGE_CODE_IDSTD(i)             {MK_RX_RANGE_CODE_IDSTD0(i)}
#  endif
#  if (kCanNumberOfUsedCanRxIdTables == 2)
#   define MK_RX_RANGE_MASK_IDSTD(i)             {MK_RX_RANGE_MASK_IDSTD0(i),MK_RX_RANGE_MASK_IDSTD1(i)}
#   define MK_RX_RANGE_CODE_IDSTD(i)             {MK_RX_RANGE_CODE_IDSTD0(i),MK_RX_RANGE_CODE_IDSTD1(i)}
#  endif
#  if (kCanNumberOfUsedCanRxIdTables == 3)
#   define MK_RX_RANGE_MASK_IDSTD(i)             {MK_RX_RANGE_MASK_IDSTD0(i),MK_RX_RANGE_MASK_IDSTD1(i),MK_RX_RANGE_MASK_IDSTD2(i)}
#   define MK_RX_RANGE_CODE_IDSTD(i)             {MK_RX_RANGE_CODE_IDSTD0(i),MK_RX_RANGE_CODE_IDSTD1(i),MK_RX_RANGE_CODE_IDSTD2(i)}
#  endif
#  if (kCanNumberOfUsedCanRxIdTables == 4)
#   define MK_RX_RANGE_MASK_IDSTD(i)             {MK_RX_RANGE_MASK_IDSTD0(i),MK_RX_RANGE_MASK_IDSTD1(i),MK_RX_RANGE_MASK_IDSTD2(i),MK_RX_RANGE_MASK_IDSTD3(i)}
#   define MK_RX_RANGE_CODE_IDSTD(i)             {MK_RX_RANGE_CODE_IDSTD0(i),MK_RX_RANGE_CODE_IDSTD1(i),MK_RX_RANGE_CODE_IDSTD2(i),MK_RX_RANGE_CODE_IDSTD3(i)}
#  endif
#  if (kCanNumberOfUsedCanRxIdTables == 5)
#   define MK_RX_RANGE_MASK_IDSTD(i)             {MK_RX_RANGE_MASK_IDSTD0(i),MK_RX_RANGE_MASK_IDSTD1(i),MK_RX_RANGE_MASK_IDSTD2(i),MK_RX_RANGE_MASK_IDSTD3(i),MK_RX_RANGE_MASK_IDSTD4(i)}
#   define MK_RX_RANGE_CODE_IDSTD(i)             {MK_RX_RANGE_CODE_IDSTD0(i),MK_RX_RANGE_CODE_IDSTD1(i),MK_RX_RANGE_CODE_IDSTD2(i),MK_RX_RANGE_CODE_IDSTD3(i),MK_RX_RANGE_CODE_IDSTD4(i)}
#  endif

#  if (kCanNumberOfUsedCanRxIdTables == 1)
#   define MK_RX_RANGE_MASK_IDEXT(i)             {MK_RX_RANGE_MASK_IDEXT0(i)}
#   define MK_RX_RANGE_CODE_IDEXT(i)             {MK_RX_RANGE_CODE_IDEXT0(i)}
#  endif
#  if (kCanNumberOfUsedCanRxIdTables == 2)
#   define MK_RX_RANGE_MASK_IDEXT(i)             {MK_RX_RANGE_MASK_IDEXT0(i),MK_RX_RANGE_MASK_IDEXT1(i)}
#   define MK_RX_RANGE_CODE_IDEXT(i)             {MK_RX_RANGE_CODE_IDEXT0(i),MK_RX_RANGE_CODE_IDEXT1(i)}
#  endif
#  if (kCanNumberOfUsedCanRxIdTables == 3)
#   define MK_RX_RANGE_MASK_IDEXT(i)             {MK_RX_RANGE_MASK_IDEXT0(i),MK_RX_RANGE_MASK_IDEXT1(i),MK_RX_RANGE_MASK_IDEXT2(i)}
#   define MK_RX_RANGE_CODE_IDEXT(i)             {MK_RX_RANGE_CODE_IDEXT0(i),MK_RX_RANGE_CODE_IDEXT1(i),MK_RX_RANGE_CODE_IDEXT2(i)}
#  endif
#  if (kCanNumberOfUsedCanRxIdTables == 4)
#   define MK_RX_RANGE_MASK_IDEXT(i)             {MK_RX_RANGE_MASK_IDEXT0(i),MK_RX_RANGE_MASK_IDEXT1(i),MK_RX_RANGE_MASK_IDEXT2(i),MK_RX_RANGE_MASK_IDEXT3(i)}
#   define MK_RX_RANGE_CODE_IDEXT(i)             {MK_RX_RANGE_CODE_IDEXT0(i),MK_RX_RANGE_CODE_IDEXT1(i),MK_RX_RANGE_CODE_IDEXT2(i),MK_RX_RANGE_CODE_IDEXT3(i)}
#  endif
#  if (kCanNumberOfUsedCanRxIdTables == 5)
#   define MK_RX_RANGE_MASK_IDEXT(i)             {MK_RX_RANGE_MASK_IDEXT0(i),MK_RX_RANGE_MASK_IDEXT1(i),MK_RX_RANGE_MASK_IDEXT2(i),MK_RX_RANGE_MASK_IDEXT3(i),MK_RX_RANGE_MASK_IDEXT4(i)}
#   define MK_RX_RANGE_CODE_IDEXT(i)             {MK_RX_RANGE_CODE_IDEXT0(i),MK_RX_RANGE_CODE_IDEXT1(i),MK_RX_RANGE_CODE_IDEXT2(i),MK_RX_RANGE_CODE_IDEXT3(i),MK_RX_RANGE_CODE_IDEXT4(i)}
#  endif
# endif

/* calculate size of cond/ind-flags */
# define kCanNumberOfConfBytes                   ((kCanNumberOfConfFlags + 7)/8)
# define kCanNumberOfConfWords                   ((kCanNumberOfConfFlags + 15)/16)
# define kCanNumberOfConfDWords                  ((kCanNumberOfConfFlags + 31)/32)
# define kCanNumberOfIndBytes                    ((kCanNumberOfIndFlags + 7)/8)
# define kCanNumberOfIndWords                    ((kCanNumberOfIndFlags + 15)/16)
# define kCanNumberOfIndDWords                   ((kCanNumberOfIndFlags + 31)/32)

/* Macros for CAN message access within ApplCanMsgReceived() or PreCopy() function */

# if defined( C_ENABLE_EXTENDED_ID )
#  if defined( C_ENABLE_MIXED_ID )
#   define CanRxActualId(rxStruct)               ((CanRxActualIdType(rxStruct) == kCanIdTypeExt) ?      \
                                                 CanRxActualExtId(rxStruct) : ((vuint32)CanRxActualStdId(rxStruct)))      /* returns vuint32 */
#  else
#   define CanRxActualId(rxStruct)               (CanRxActualExtId(rxStruct))             /* returns vuint32 */
#  endif
# else
#  define CanRxActualId(rxStruct)                (CanRxActualStdId(rxStruct))             /* returns vuint16 */
# endif

/* Macros for CAN Status */
# define CanHwIsOk(state)                        (((state) & (kCanHwIsWarning |     \
                                                    kCanHwIsPassive |     \
                                                    kCanHwIsBusOff) )    ? 0 : 1)
# define CanHwIsWarning(state)                   (((state) & kCanHwIsWarning)      ? 1 : 0)
# define CanHwIsPassive(state)                   (((state) & kCanHwIsPassive)      ? 1 : 0)
# define CanHwIsBusOff(state)                    (((state) & kCanHwIsBusOff)       ? 1 : 0)
# define CanHwIsWakeup(state)                    (((state) & kCanHwIsSleep)        ? 0 : 1)
# define CanHwIsSleep(state)                     (((state) & kCanHwIsSleep)        ? 1 : 0)
# define CanHwIsStop(state)                      (((state) & kCanHwIsStop)         ? 1 : 0)
# define CanHwIsStart(state)                     (((state) & kCanHwIsStop)         ? 0 : 1)
# define CanIsOnline(state)                      (((state) & kCanTxOn)             ? 1 : 0)
# define CanIsOffline(state)                     (((state) & kCanTxOn)             ? 0 : 1)
# define CanHwIsInconsistent(state)              (((state) & kCanHwIsInconsistent) ? 1 : 0)



#  if defined( C_DRV_INTERNAL )
#   define CanGetTxId0(i)                        (CanTxId0[i])
#   define CanGetTxId1(i)                        (CanTxId1[i])
#   define CanGetTxId2(i)                        (CanTxId2[i])
#   define CanGetTxId3(i)                        (CanTxId3[i])
#   define CanGetTxId4(i)                        (CanTxId4[i])
#   if defined( C_ENABLE_EXTENDED_ID )
#    if defined( C_ENABLE_MIXED_ID )
#     if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#      define CanGetTxIdType(i)                  (C_LL_TX_IDTYPE_TABLE[i] & kCanIdTypeExt)
#     else
#       define CanGetTxIdType(i)                 (CanTxIdType[i] & kCanIdTypeExt)
#     endif
#    else
#     define CanGetTxIdType(i)                   (kCanIdTypeExt)
#    endif
#   else
#    define CanGetTxIdType(i)                    (kCanIdTypeStd)
#   endif
#  endif /* C_DRV_INTERNAL */

#  define CanGetTxDlc(i)                         (CanTxDLC[i])
#  define CanGetTxDataPtr(i)                     (CanTxDataPtr[i])
#  define CanGetConfirmationOffset(i)            (CanConfirmationOffset[i])
#  define CanGetConfirmationMask(i)              (CanConfirmationMask[i])
#   define CanGetTxHwObj(i)                      (CanTxHwObj[i])
#  define CanGetTxSendMask(i)                    (CanTxSendMask[i])
#  define CanGetApplPreTransmitPtr(i)            (CanTxApplPreTransmitPtr[i])
#  define CanGetApplConfirmationPtr(i)           (CanTxApplConfirmationPtr[i])
#  define CanGetChannelOfTxObj(i)                (CanTxMsgHandleToChannel[i])

#  if defined( C_DRV_INTERNAL )
#   define CanGetRxId0(i)                        (CanRxId0[i])
#   define CanGetRxId1(i)                        (CanRxId1[i])
#   define CanGetRxId2(i)                        (CanRxId2[i])
#   define CanGetRxId3(i)                        (CanRxId3[i])
#   define CanGetRxId4(i)                        (CanRxId4[i])
#   if defined( C_ENABLE_EXTENDED_ID )
#    if defined( C_ENABLE_MIXED_ID )
#     if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#      define CanGetRxIdType(i)                  (C_LL_RX_IDTYPE_TABLE[i] & kCanIdTypeExt)
#     else
#      define CanGetRxIdType(i)                  (CanRxIdType[i] & kCanIdTypeExt)
#     endif
#    else
#     define CanGetRxIdType(i)                   (kCanIdTypeExt)
#    endif
#   else
#    define CanGetRxIdType(i)                    (kCanIdTypeStd)
#   endif
#  endif /* C_DRV_INTERNAL */

#  define CanGetRxDataLen(i)                     (CanRxDataLen[i])
#  define CanGetRxMinDataLen(i)                  (CanRxMinDataLen[i])
#  define CanGetRxDataPtr(i)                     (CanRxDataPtr[i])
#  define CanGetIndicationOffset(i)              (CanIndicationOffset[i])
#  define CanGetIndicationMask(i)                (CanIndicationMask[i])
#  define CanGetApplPrecopyPtr(i)                (CanRxApplPrecopyPtr[i])
#  define CanGetApplIndicationPtr(i)             (CanRxApplIndicationPtr[i])

# if defined( C_ENABLE_CONFIRMATION_FCT ) && \
    defined( C_ENABLE_DYN_TX_OBJECTS )  && \
    defined( C_ENABLE_TRANSMIT_QUEUE )
  /* set confirmation active for CanReleaseDynTxObj() */
#  if defined( C_SINGLE_RECEIVE_CHANNEL ) 
#   define CanConfirmStart(txHandle)             {confirmHandle[0] = (txHandle);}                 /* PRQA S 3458 */
#   define CanConfirmEnd()                       {confirmHandle[0] = kCanTxHandleNotUsed;}        /* PRQA S 3458 */
#  else
#   define CanConfirmStart(channel, txHandle)    {confirmHandle[channel] = (txHandle);}           /* PRQA S 3458 */
#   define CanConfirmEnd(channel)                {confirmHandle[channel] = kCanTxHandleNotUsed;}  /* PRQA S 3458 */
#  endif
# endif

# if defined( C_ENABLE_PART_OFFLINE )
#  if defined( C_SINGLE_RECEIVE_CHANNEL ) 
#   define CanPartOffline(sendGroup)             (CanSetPartOffline( sendGroup))
#   define CanPartOnline(sendGroup)              (CanSetPartOnline( (vuint8)~(vuint8)(sendGroup)) )
#  else
#   define CanPartOffline(channel, sendGroup)    (CanSetPartOffline((channel), (sendGroup)))
#   define CanPartOnline(channel,  sendGroup)    (CanSetPartOnline((channel), (vuint8)~(vuint8)(sendGroup)) )
#  endif
# else
#  if defined( C_SINGLE_RECEIVE_CHANNEL ) 
#   define CanPartOffline(sendGroup)
#   define CanPartOnline(sendGroup)
#  else
#   define CanPartOffline(channel, sendGroup)
#   define CanPartOnline(channel, sendGroup)
#  endif
# endif

/* provide interface for interrupt disable and restore functions */
# define CanGlobalInterruptDisable               VStdSuspendAllInterrupts
# define CanGlobalInterruptRestore               VStdResumeAllInterrupts

# if ( C_SECURITY_LEVEL == 0 )
#  define CanDeclareGlobalInterruptOldStatus
#  define CanPutGlobalInterruptOldStatus(x)
#  define CanGetGlobalInterruptOldStatus(x)
#  define CanNestedGlobalInterruptDisable()
#  define CanNestedGlobalInterruptRestore()
# else  /* C_SECURITY_LEVEL == 0 */
#  define CanDeclareGlobalInterruptOldStatus     VStdDeclareGlobalInterruptOldStatus
#  define CanPutGlobalInterruptOldStatus(x)      VStdPutGlobalInterruptOldStatus(x)
#  define CanGetGlobalInterruptOldStatus(x)      VStdGetGlobalInterruptOldStatus(x)
#  if (VSTDLIB__COREHLL_VERSION  <  0x0216 )
#   define CanNestedGlobalInterruptDisable()      VStdNestedGlobalInterruptDisable()
#   define CanNestedGlobalInterruptRestore()      VStdNestedGlobalInterruptRestore()
#  else
#   define CanNestedGlobalInterruptDisable()      VStdGlobalInterruptDisable()
#   define CanNestedGlobalInterruptRestore()      VStdGlobalInterruptRestore()
#  endif
# endif /* C_SECURITY_LEVEL == 0 */


/* provide support for multiple callbacks */
#if !defined( APPL_CAN_GENERIC_PRECOPY )
# define APPL_CAN_GENERIC_PRECOPY                          ApplCanGenericPrecopy
#endif
#if !defined( APPL_CAN_TX_CONFIRMATION )
# define APPL_CAN_TX_CONFIRMATION                          ApplCanTxConfirmation
#endif
#if !defined( APPL_CAN_MSGTRANSMITCONF )
# define APPL_CAN_MSGTRANSMITCONF                          ApplCanMsgTransmitConf
#endif
#if !defined( APPL_CAN_MSGTRANSMITINIT )
# define APPL_CAN_MSGTRANSMITINIT                          ApplCanMsgTransmitInit
#endif
#if !defined( APPL_CAN_ONLINE )
# define APPL_CAN_ONLINE                                   ApplCanOnline
#endif
#if !defined( APPL_CAN_OFFLINE )
# define APPL_CAN_OFFLINE                                  ApplCanOffline
#endif
#if !defined( APPL_CAN_MSGRECEIVED )
# define APPL_CAN_MSGRECEIVED                              ApplCanMsgReceived
#endif
#if !defined( APPL_CAN_CANCELNOTIFICATION )
# define APPL_CAN_CANCELNOTIFICATION                       ApplCanCancelNotification
#endif
#if !defined( APPL_CAN_MSGCANCELNOTIFICATION )
# define APPL_CAN_MSGCANCELNOTIFICATION                    ApplCanMsgCancelNotification
#endif

#if defined( C_CPUTYPE_32BIT )
# define kCanTxQueueSize      ((kCanTxQueueBytes + 3) >> 2)
#endif


#if defined( C_ENABLE_VARIABLE_DLC )
/* mask to keep some bits unchanged in the DLC for use with variable DLC */
/*  - bit remaining unchanged should be masked with 1 e.g. id type or direction (difference between MK_TX_DLC and MK_TX_DLC_EXT?) */
# define CanLL_DlcMask            0x00
#endif



/* macros to set DLC and ID in rx-,tx-structures ---------------------------*/
/* MK... macros are used by the generation tool to fill the rx and tx structures */
/* In case the IDE bit is located in the ID registers, this bit has to be handled as must match.
   In general, this is done by setting the IDE bit to 0 in the .._MASK_.. macros.
*/


#if defined(C_COMP_TI_TMS470)             
# define kCanSCCMode  0
# define kCanHECCMode 1
#endif


#define MK_RX_RANGE_MASK_IDSTD0(id)   ( MK_STDID0(id) )

#define MK_RX_RANGE_CODE_IDSTD0(id)   ( MK_STDID0(id) )

#define MK_RX_RANGE_MASK_IDEXT0(id)   ( MK_EXTID0(id) & ~kCanIdTypeExt)

#define MK_RX_RANGE_CODE_IDEXT0(id)   ( MK_EXTID0(id) )



#define MK_STDID0(id)             ((vuint32)( ((vuint32)(id) & (vuint32)0x000007FF) << 18))



#define MK_EXTID0(id)             ((vuint32)( ((vuint32)(id) & (vuint32)0x1FFFFFFF) | (vuint32)kCanIdTypeExt))




/* Message Configuration Register:
 * Example C16x:
 * DLC3 DLC2 DLC1 DLC0 Dir Xtd 0 0
 *                      |   |+------------- 0: standard ID; 1: exended ID
 *                      +------------------ 0: receive    ; 1: transmit
*/
#define C_RX_DIR             0x00
#define C_TX_DIR             0x08

#define MK_TX_DLC(dlc)       ((dlc) & 0xF)
#define MK_TX_DLC_EXT(dlc)   MK_TX_DLC((dlc))

#define XT_TX_DLC(dlc)       ((dlc) & 0xF)


#if defined( C_SINGLE_RECEIVE_CHANNEL )
/* Bus-Off functions */
# define CanResetBusOffStart(a)
# define CanResetBusOffEnd(a)  (CanInit(a))

/* Bus-Sleep functions */
# define CanResetBusSleep(a)     (CanInit(a))

#else
/* Bus-Off functions */
# define CanResetBusOffStart(ch,a)
# define CanResetBusOffEnd(ch,a)    (CanInit((ch),(a)))
  
/* Bus-Sleep functions */
# define CanResetBusSleep(ch,a)     (CanInit((ch),(a)))
#endif


/* The macros CanRxActualIdRawx() have to provide the register context of the ID registers.
   It is not necessary to mask any bits. These macros are for internal use only and masking
   will be done in can_hls.c
*/
#define CanRxActualIdRaw0(rxStruct)    ((vuint32)*((vuint32 *)((rxStruct)->pChipMsgObj)))


/* Macros for CAN message access within ApplCanMsgReceived() or PreCopy() function */
#if defined( C_ENABLE_EXTENDED_ID )
# define CanRxActualIdExtHi(rxStruct)       ((vuint8)((*(vuint32*)((rxStruct) -> pChipMsgObj) & (vuint32)0x1F000000ul) >> 24))
# define CanRxActualIdExtMidHi(rxStruct)    ((vuint8)((*(vuint32*)((rxStruct) -> pChipMsgObj) & (vuint32)0x00FF0000ul) >> 16))
# define CanRxActualIdExtMidLo(rxStruct)    ((vuint8)((*(vuint32*)((rxStruct) -> pChipMsgObj) & (vuint32)0x0000FF00ul) >>  8))
# define CanRxActualIdExtLo(rxStruct)       ((vuint8)((*(vuint32*)((rxStruct) -> pChipMsgObj) & (vuint32)0x000000FFul)      ))
#endif
#if defined(C_COMP_TI_TMS470)  
# define CanRxActualExtId(rxStruct)         ((vuint32)((*(vuint32*)((rxStruct) -> pChipMsgObj)) & (vuint32)0x1FFFFFFFul))
# define CanRxActualStdId(rxStruct)         ((vuint16)(((*(vuint16*)((rxStruct) -> pChipMsgObj)) >> 2) & (vuint32)0x000007FFul))
#endif


# define CanRxActualData(rxStruct,i)     ((vuint8)(*((rxStruct)->pChipData+(i))))                  /* return code has to be vuint8 */
# define CanRxActualDLC(rxStruct)        ((vuint8)(((tCanMailBox*)((rxStruct) -> pChipMsgObj))->CanMcf & (vuint32)0x0000000Ful))

# define CanRxActualIdType(rxStruct)     ((((vuint32)(*(vuint32*)((rxStruct) -> pChipMsgObj) & kCanIdTypeExt) != (vuint32)0)) ? kCanIdTypeExt : kCanIdTypeStd)



#if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define CanRxActualErrorCounter()         (((tCanCntrlRegBlock*)kCanBasisAdr) -> CanRec)
#  define CanTxActualErrorCounter()         (((tCanCntrlRegBlock*)kCanBasisAdr) -> CanTec)
#else
#  define CanRxActualErrorCounter(channel)  (((tCanCntrlRegBlock*)(CanBasisAdr[(channel)])) -> CanRec)
#  define CanTxActualErrorCounter(channel)  (((tCanCntrlRegBlock*)(CanBasisAdr[(channel)])) -> CanTec)
#endif


/* Macros for CAN message access within PreTransmit() function */




#if defined(C_COMP_TI_TMS470)           
/* Macros for CAN message access within PreTransmit() function */
# if defined(C_ENABLE_EXTENDED_ID)
#  define CanTxWriteActExtId(txStruct,id)                                     \
{                                                                             \
  ((tCanMailBox*)((txStruct).pChipData - 8)) -> CanMid = MK_EXTID0((id));     \
}   /* PRQA S 3458 */ /* MISRA Rule 19.4: Braced code statement block in macro for efficient code (avoid function calls) */
# endif
# define CanTxWriteActId(txStruct,id)                                         \
{                                                                             \
  ((tCanMailBox*)((txStruct).pChipData - 8)) -> CanMid = MK_STDID0((id));     \
}   /* PRQA S 3458 */ /* MISRA Rule 19.4: Braced code statement block in macro for efficient code (avoid function calls) */

# define CanTxWriteActDLC(txStruct,dlc)                                       \
{                                                                             \
  ((tCanMailBox*)((txStruct).pChipData - 8)) -> CanMcf = MK_TX_DLC((dlc));    \
}   /* PRQA S 3458 */ /* MISRA Rule 19.4: Braced code statement block in macro for efficient code (avoid function calls) */
#endif

/* Macros to fill variables of the type tCanMsgTransmitStruct */
#define CanMsgTransmitSetStdId(pCanMsgTransmitStruct, id)               { (pCanMsgTransmitStruct)->IdRaw   = MK_STDID0((id)); }           /* PRQA S 3458 */ /* MISRA Rule 19.4: Braced code statement block in macro for efficient code (avoid function calls) */
#define CanMsgTransmitSetExtId(pCanMsgTransmitStruct, id)               { (pCanMsgTransmitStruct)->IdRaw   = MK_EXTID0((id)); }           /* PRQA S 3458 */ /* MISRA Rule 19.4: Braced code statement block in macro for efficient code (avoid function calls) */
#define CanMsgTransmitSetDlc(pCanMsgTransmitStruct, dlc)                { (pCanMsgTransmitStruct)->DlcRaw = (vuint32)MK_TX_DLC((dlc)); }  /* PRQA S 3458 */ /* MISRA Rule 19.4: Braced code statement block in macro for efficient code (avoid function calls) */
#define CanMsgTransmitSetData(pCanMsgTransmitStruct, dataByte, msgData) { (pCanMsgTransmitStruct)->DataFld[(dataByte)] = (msgData); }     /* PRQA S 3458 */ /* MISRA Rule 19.4: Braced code statement block in macro for efficient code (avoid function calls) */


/* macros for buffer access */
#define StartRxReadSync()          (VStdSuspendAllInterrupts())
#define EndRxReadSync()            (VStdResumeAllInterrupts())

#define StartRxWriteSync()         (VStdSuspendAllInterrupts())
#define EndRxWriteSync()           (VStdResumeAllInterrupts())

#define StartTxReadSync()
#define EndTxReadSync()

#define StartTxWriteSync()         (VStdSuspendAllInterrupts())
#define EndTxWriteSync()           (VStdResumeAllInterrupts())

#define StartRxWriteCANSync() 
#define EndRxWriteCANSync()   

#define StartRxReadCANSync()  
#define EndRxReadCANSync()    

#define StartRxFullCANReadSync(Obj)   
#define EndRxFullCANReadSync(Obj)     

#define StartRxFullCANWriteSync(obj)  
#define EndRxFullCANWriteSync(obj)    

/* macros for flag access */
#define CanStartFlagWriteSync()    (VStdSuspendAllInterrupts())
#define CanEndFlagWriteSync()      (VStdResumeAllInterrupts())




/***************************************************************************/
/* error codes                                                             */
/***************************************************************************/
/* error numbers for User Assertions 0x00-0x1f - hardware independed */
# define kErrorTxDlcTooLarge                     ((vuint8)0x01)
# define kErrorTxHdlTooLarge                     ((vuint8)0x02)
# define kErrorIntRestoreTooOften                ((vuint8)0x03)
# define kErrorIntDisableTooOften                ((vuint8)0x04)
# define kErrorChannelHdlTooLarge                ((vuint8)0x05)
# define kErrorInitObjectHdlTooLarge             ((vuint8)0x06)
# define kErrorTxHwHdlTooLarge                   ((vuint8)0x07)
# define kErrorHwObjNotInPolling                 ((vuint8)0x08)
# define kErrorHwHdlTooSmall                     ((vuint8)0x09)
# define kErrorHwHdlTooLarge                     ((vuint8)0x0A)

# define kErrorAccessedInvalidDynObj             ((vuint8)0x0B)
# define kErrorAccessedStatObjAsDyn              ((vuint8)0x0C)
# define kErrorDynObjReleased                    ((vuint8)0x0D)

# define kErrorPollingTaskRecursion              ((vuint8)0x0E)
# define kErrorDisabledChannel                   ((vuint8)0x0F)
# define kErrorDisabledTxMessage                 ((vuint8)0x10)
# define kErrorDisabledCanInt                    ((vuint8)0x11)

# define kErrorCanSleep                          ((vuint8)0x12)
# define kErrorCanOnline                         ((vuint8)0x13)
# define kErrorCanStop                           ((vuint8)0x14)
# define kErrorWrongMask                         ((vuint8)0x15)
# define kErrorWrongId                           ((vuint8)0x16)
#if defined(C_COMP_TI_TMS470)           
# define kErrorPriviledgedModeRequired ((vuint8)0x20)
#endif
#define kErrorFunctionNotSupported    ((vuint8)0x21)


/* error numbers for Gentool Assertions 0x40-0x5f */
# define kErrorTxROMDLCTooLarge                  ((vuint8)0x40)
# define kErrorWrongHwTxObjHandle                ((vuint8)0x41)
# define kErrorHwToLogTxObjCalculation           ((vuint8)0x42)

/* error numbers for Gentool Assertions 0x60-0x7f - hardware depended */
#define kErrorWrongTSegValue          ((vuint8)0x60) /* TSeg1 and TSeg2 must not be equal to 0 ! */
#define kErrorBasicCANMask            ((vuint8)0x61)

/* error numbers for Hardware Assertions 0x80-0x9f */
# define kErrorTxBufferBusy                      ((vuint8)0x80)

/* error numbers for Hardware Assertions 0xa0-0xbf - hardware depended */

/* error numbers for Internal Assertions 0xc0-0xdf */
# define kErrorTxHandleWrong                     ((vuint8)0xC0)
# define kErrorInternalTxHdlTooLarge             ((vuint8)0xC1)
# define kErrorRxHandleWrong                     ((vuint8)0xC2)        
# define kErrorTxObjHandleWrong                  ((vuint8)0xC3)
# define kErrorReleasedUnusedDynObj              ((vuint8)0xC4)
# define kErrorTxQueueTooManyHandle              ((vuint8)0xC5)
# define kErrorInternalChannelHdlTooLarge        ((vuint8)0xC6)
# define kErrorInternalDisabledChannel           ((vuint8)0xC7)
# define kErrorInternalDisabledTxMessage         ((vuint8)0xC8)

/* error numbers for Internal Assertions 0xe0-0xff - hardware depended */
#define kErrorWrongInterruptLine      ((vuint8)0xe0) /* CAN interrupts are mapped to the wrong interrupt line */
#define kErrorMemAlignment            ((vuint8)0xe1) /* computed memory alignment not correct */


/***************************************************************************/
/* DummyFunction                                                           */
/***************************************************************************/
# if defined( C_DRV_INTERNAL )
#  define CAN_RECEIVE_FCT_DUMMY                  ApplCanRxStructPtrDummy
#  define CAN_RANGE_FCT_DUMMY                    ApplCanRxStructPtrDummy
#  define CAN_BUSOFF_FCT_DUMMY                   ApplCanChannelDummy
#  if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
#   define CAN_INDICATION_FCT_DUMMY              ApplCanRxHandleDummy
#   define CAN_PRECOPY_FCT_DUMMY                 ApplCanRxStructPtrDummy
#   define CAN_CONFIRMATION_FCT_DUMMY            ApplCanTxHandleDummy
#   define CAN_PRETRANSMIT_FCT_DUMMY             ApplCanTxStructDummy
#  else
#   define CAN_INDICATION_FCT_DUMMY              V_NULL
#   define CAN_PRECOPY_FCT_DUMMY                 V_NULL
#   define CAN_CONFIRMATION_FCT_DUMMY            V_NULL
#   define CAN_PRETRANSMIT_FCT_DUMMY             V_NULL
#  endif
# endif

# if defined( C_NO_COMPATIBILITY )
# else
/***************************************************************************/
/* compatibility defines                                                   */
/***************************************************************************/

#  define CAN_TX_DLC(i)                          (CanGetTxDlc(i))            
#  define CAN_TX_DATA_PTR(i)                     (CanGetTxDataPtr(i))         
#  define CAN_CONFIRMATION_OFFSET(i)             (CanGetConfirmationOffset(i))
#  define CAN_CONFIRMATION_MASK(i)               (CanGetConfirmationMask(i))

#  define CAN_RX_DATA_LEN(i)                     (CanGetRxDataLen(i))
#  define CAN_RX_DATA_PTR(i)                     (CanGetRxDataPtr(i))
#  define CAN_INDICATION_OFFSET(i)               (CanGetIndicationOffset(i))
#  define CAN_INDICATION_MASK(i)                 (CanGetIndicationMask(i))

#  define CanInterruptDisable()                  (VStdSuspendAllInterrupts())
#  define CanInterruptRestore()                  (VStdResumeAllInterrupts())

#  define ApplCanReceiveDummy0                   ApplCanRxStructPtrDummy
#  define ApplCanReceiveDummy1                   ApplCanChannelDummy

#  define CanGetTxDirectMsg                      (CanGetTxHwObj)

#  define canRxDlcRam                            (canVariableRxDataLen)

#  define CAN_START_INDEX_INIT_OBJ(i)            (CanInitObjectStartIndex[i])
#  define CAN_START_INDEX_TX_OBJ(i)              (CanTxStartIndex[i])
#  define CAN_START_INDEX_RX_OBJ(i)              (CanRxStartIndex[i])

#  if !defined( VGEN_GENY )
#   if defined( C_ENABLE_RANGE_EXTENDED_ID )
#    define MK_RX_RANGE_MASK0(id)                (MK_RX_RANGE_MASK_IDEXT0(id))
#    define MK_RX_RANGE_MASK1(id)                (MK_RX_RANGE_MASK_IDEXT1(id))
#    define MK_RX_RANGE_MASK2(id)                (MK_RX_RANGE_MASK_IDEXT2(id))
#    define MK_RX_RANGE_MASK3(id)                (MK_RX_RANGE_MASK_IDEXT3(id))
#    define MK_RX_RANGE_MASK4(id)                (MK_RX_RANGE_MASK_IDEXT4(id))

#    define MK_RX_RANGE_CODE0(id)                (MK_RX_RANGE_CODE_IDEXT0(id))
#    define MK_RX_RANGE_CODE1(id)                (MK_RX_RANGE_CODE_IDEXT1(id))
#    define MK_RX_RANGE_CODE2(id)                (MK_RX_RANGE_CODE_IDEXT2(id))
#    define MK_RX_RANGE_CODE3(id)                (MK_RX_RANGE_CODE_IDEXT3(id))
#    define MK_RX_RANGE_CODE4(id)                (MK_RX_RANGE_CODE_IDEXT4(id))
#   else
#    define MK_RX_RANGE_MASK0(id)                (MK_RX_RANGE_MASK_IDSTD0(id))
#    define MK_RX_RANGE_MASK1(id)                (MK_RX_RANGE_MASK_IDSTD1(id))
#    define MK_RX_RANGE_MASK2(id)                (MK_RX_RANGE_MASK_IDSTD2(id))
#    define MK_RX_RANGE_MASK3(id)                (MK_RX_RANGE_MASK_IDSTD3(id))
#    define MK_RX_RANGE_MASK4(id)                (MK_RX_RANGE_MASK_IDSTD4(id))

#    define MK_RX_RANGE_CODE0(id)                (MK_RX_RANGE_CODE_IDSTD0(id))
#    define MK_RX_RANGE_CODE1(id)                (MK_RX_RANGE_CODE_IDSTD1(id))
#    define MK_RX_RANGE_CODE2(id)                (MK_RX_RANGE_CODE_IDSTD2(id))
#    define MK_RX_RANGE_CODE3(id)                (MK_RX_RANGE_CODE_IDSTD3(id))
#    define MK_RX_RANGE_CODE4(id)                (MK_RX_RANGE_CODE_IDSTD4(id))
#   endif
#  endif




/***************************************************************************/
/* end of compatibility defines                                            */
/***************************************************************************/
# endif /* C_NO_COMPATIBILITY */

/***************************************************************************/
/* Memory qualifier                                                        */
/***************************************************************************/
/* memory qualifier for the CAN controller registers */
#define MEMORY_CAN

/***************************************************************************/
/* data types                                                              */
/***************************************************************************/

/* declare data type for the queue */
#if defined( C_CPUTYPE_32BIT )
typedef vuint32 tCanQueueElementType;
#endif
/* data types for driver function parameters */
/* the types of CanInitHandle, CanChannelHandle and CanObjectHandle depends
   on the compiler and controller - what generates effective code */
typedef vuint16           CanInitHandle;
typedef vuint16           CanChannelHandle;
/* CanObjectHandle has to be unsigned! */
typedef vuint16           CanObjectHandle;

typedef vuint16           CanTransmitHandle;
typedef vuint16           CanReceiveHandle;

/* define datatype of local signed variables for message handles */

typedef vsintx CanSignedTxHandle;

typedef vuint32 tCanRegType;

typedef vsintx CanSignedRxHandle;

 /* ptr to msgObj & data on chip used in precopy function  (No MEMORY_CAN -> no HW access here) */
typedef volatile vuint8       *  CanChipDataPtr;
typedef volatile vuint8       *  CanChipMsgPtr;

/* up to 5 tables can be defined for the transmission ID. The type and how 
   many tables are needed depends on the CPU bus type and on the ID registers 
   of the CAN controller. E.g. a CPU with a 16-Bit bus and 2 byte ID registers 
   for standard ID needs 1 table and tCanRxId0 of type vuint16. The same CPU
   with 5 byte ID registers for extended ID needs in this case 3 tables and
   tCanRxId0 = vuint16, tCanRxId1 = vuint16 and tCanRxId2 = vuint16. */
typedef vuint32          tCanTxId0;

/* type of variable for ID type kCanIdTypeExt or kCanIdTypeStd will be assigned to 
   a variable of this type */
typedef vuint32          tCanIdType;

/* up to 3 tables can be defined for the reception ID. The type and how many
   tables are needed depends on the CPU bus type and on the ID registers of
   the CAN controller. E.g. a CPU with a 16-Bit bus and 2 byte ID registers 
   for standard ID needs 1 table and tCanRxId0 of type vuint16. The same CPU
   with 5 byte ID registers for extended ID needs in this case 3 tables and 
   tCanRxId0 = vuint16, tCanRxId1 = vuint16 and tCanRxId2 = vuint16. */
typedef vuint32          tCanRxId0;


/* type of the variable, in which the old status of the interrupt flag or
   level is stored */
typedef vuint32         tCanHLIntOld;

/* this type could also be a struct if more than one variable is necessary */
typedef vuint32         tCanLLCanIntOld;

/* stucture of the CAN message object used by CanMsgTransmit() and RxQueue*/
#if defined(C_COMP_TI_TMS470)  
typedef struct
{
  vuint32 IdRaw;        
  vuint16 reserved1;
  vuint8  TxPrio;
  vuint8  DlcRaw;
  vuint8  DataFld[8];
} 
tCanMsgTransmitStruct;
#endif




typedef struct 
{
  canbittype w0l : 8;
  canbittype w0h : 8;
  canbittype w1l : 8;
  canbittype w1h : 8;
  canbittype w2l : 8;
  canbittype w2h : 8;
  canbittype w3l : 8;
  canbittype w3h : 8;
}
tCanTempObj;

typedef struct 
{
  vuint32            CanMdl;
  vuint32            CanMdh;
}
tCanMsgBuffer;

typedef union
{ /* PRQA S 0750 */ /* MISRA Rule: 18.4: Union type defined for efficient and easy hardware access */
  tCanTempObj        bytes;
  tCanMsgBuffer      dwords;
}
tCanMsgBufferUnion;

typedef volatile struct
{
  vuint32            CanMid;
  vuint32            CanMcf;
  vuint8             CanData[8];
}
tCanTempRamMailBox;


/* control and status register block */
typedef volatile struct
{
  vuint32            CanMid;
  vuint32            CanMcf;
  tCanMsgBufferUnion CanMsg;
}
tCanMailBox;

typedef volatile union
{ /* PRQA S 0750 */ /* MISRA Rule: 18.4: Union type defined for efficient and easy hardware access */
  tCanMailBox        s;
  vuint16            a[8];
}
tCanTempPreTransmitObj;   

typedef struct 
{
  canbittype w0l : 8;
  canbittype w0h : 8;
  canbittype w1l : 8;
  canbittype w1h : 8;
}
tDWordToByte;

typedef struct
{
  canbittype lobyte : 8;
  canbittype hibyte : 8;
}
tWordToByte;

/*lint -esym(750,CanTrr,CanAa,CanRfp,CanReserved_0,CanTec,CanRec,CanGif1,CanLnt,CanToc,CanTos,CanReserved_1,CanMots,CanMoto) */

#if defined(C_COMP_TI_TMS470)           
typedef volatile struct
{
  tCanRegType CanMe; 
  tCanRegType CanMd;
  tCanRegType CanTrs;
  tCanRegType CanTrr;
  tCanRegType CanTa;
  tCanRegType CanAa;
  tCanRegType CanRmp;
  tCanRegType CanRml;
  tCanRegType CanRfp;
  tCanRegType CanGam;
  tCanRegType CanMc;
  tCanRegType CanBtc;
  tCanRegType CanEs;
  tCanRegType CanTec;
  tCanRegType CanRec;
  tCanRegType CanGif0;
  tCanRegType CanGim;
  tCanRegType CanGif1;
  tCanRegType CanMim;
  tCanRegType CanMil;
  tCanRegType CanOpc;
  tCanRegType CanTioc;
  tCanRegType CanRioc;
  tCanRegType CanLnt;
  tCanRegType CanToc;
  tCanRegType CanTos;

# if (defined(C_COMP_TI_TMS470)                     )                  && \
      defined(C_PROCESSOR_TI_TMS470PLF521)
  tCanRegType CanTioce;
  tCanRegType CanRioce;
  tCanRegType CanEtc;
  tCanRegType CanReserved_1[3]; 
# else  
  tCanRegType CanReserved_1[6];
# endif  
  tCanRegType CanLam[4];
}
tCanCntrlRegBlock;

typedef volatile struct {
# if defined  (C_ENABLE_LAMOFFSETFROMRAM)
  tCanRegType Dummy[1024]; /* 0x1000 Offset */
# else
  tCanRegType Dummy[32]; /* 0x80 Offset */
# endif
  tCanRegType CanLam[32];
  tCanRegType CanMots[32];
  tCanRegType CanMoto[32];
}
tCanLamRegBlock;
#endif


typedef struct 
{
  CanChipDataPtr     pChipData;
  CanTransmitHandle  Handle;
/* CPU-specific part */
} tCanTxInfoStruct;

/* ##RI-1.10 Common Callbackfunction in TxInterrupt */
typedef struct 
{
  CanChannelHandle   Channel;
  CanTransmitHandle  Handle;
/* CPU-specific part */
} tCanTxConfInfoStruct;

typedef struct 
{
  CanChannelHandle  Channel;
  CanChipMsgPtr     pChipMsgObj;
  CanChipDataPtr    pChipData;
  CanReceiveHandle  Handle;
/* CPU-specific part */
} tCanRxInfoStruct;

typedef tCanRxInfoStruct          *CanRxInfoStructPtr;
typedef tCanTxInfoStruct          CanTxInfoStruct;
/* ##RI-1.10 Common Callbackfunction in TxInterrupt */
typedef tCanTxConfInfoStruct      *CanTxInfoStructPtr;

/* types of application functions called by driver ---------------------------*/
typedef C_CALLBACK_1 vuint8   (C_CALLBACK_2 *ApplCanMsgRcvFct)    (CanRxInfoStructPtr rxStruct);
typedef C_CALLBACK_1 vuint8   (C_CALLBACK_2 *ApplRangeFct)        (CanRxInfoStructPtr rxStruct);
typedef C_CALLBACK_1 vuint8   (C_CALLBACK_2 *ApplPrecopyFct)      (CanRxInfoStructPtr rxStruct);
typedef C_CALLBACK_1 void     (C_CALLBACK_2 *ApplIndicationFct)   (CanReceiveHandle rxObject);
typedef C_CALLBACK_1 void     (C_CALLBACK_2 *ApplConfirmationFct) (CanTransmitHandle txObject);
typedef C_CALLBACK_1 vuint8   (C_CALLBACK_2 *ApplPreTransmitFct)  (CanTxInfoStruct txStruct);
typedef C_CALLBACK_1 void     (C_CALLBACK_2 *ApplChannelFct)      (CAN_CHANNEL_CANTYPE_ONLY);

typedef struct
{
  tCanRxId0           Id0;
# if (kCanNumberOfUsedCanRxIdTables > 1)
  tCanRxId1           Id1;
# endif
# if (kCanNumberOfUsedCanRxIdTables > 2)
  tCanRxId2           Id2;
# endif     
# if (kCanNumberOfUsedCanRxIdTables > 3)
  tCanRxId3           Id3;
# endif
# if (kCanNumberOfUsedCanRxIdTables > 4)
  tCanRxId4           Id4;
# endif
} tCanStructRxIdType;

# if defined( C_DRV_INTERNAL )
typedef struct
{
  ApplChannelFct      ApplCanWakeUpFct; 
  ApplCanMsgRcvFct    ApplCanMsgReceivedFct;
  ApplRangeFct        ApplCanRangeFct[4];
  ApplChannelFct      ApplCanBusOffFct;
  ApplConfirmationFct ApplCanCancelNotificationFct;
  ApplChannelFct      ApplCanMsgTransmitCancelNotifyFct;
  tCanStructRxIdType  RangeMask[4];
  tCanStructRxIdType  RangeCode[4];
  vuint16             RangeActiveFlag;
  tCanIdType          RangeIdType[4];
} tCanChannelObject;
# endif


/* datatypes for indication and confirmation flags */
# if defined( C_ENABLE_CONFIRMATION_FLAG )
union CanConfirmationBits                                 
{    /* PRQA S 0750 */
  vuint8         _c[kCanNumberOfConfBytes];
#  if defined( V_CPUTYPE_BITARRAY_32BIT )
#   if kCanNumberOfConfFlags > 16
  struct _c_bits32 w[kCanNumberOfConfDWords];
#   elif kCanNumberOfConfFlags > 8
  struct _c_bits16 w[kCanNumberOfConfWords];
#   else
  struct _c_bits8  w[1];
#   endif
#  else
#   if kCanNumberOfConfFlags > 8
  struct _c_bits16 w[kCanNumberOfConfWords];
#   else
  struct _c_bits8  w[1];
#   endif
#  endif
}; 
# endif


# if defined( C_ENABLE_INDICATION_FLAG )
union CanIndicationBits                                  
{    /* PRQA S 0750 */
  vuint8         _c[kCanNumberOfIndBytes];
#  if defined( V_CPUTYPE_BITARRAY_32BIT )
#   if kCanNumberOfIndFlags > 16
  struct _c_bits32 w[kCanNumberOfIndDWords];
#   elif kCanNumberOfIndFlags > 8
  struct _c_bits16 w[kCanNumberOfIndWords];
#   else
  struct _c_bits8  w[1];
#   endif
#  else
#   if kCanNumberOfIndFlags > 8
  struct _c_bits16 w[kCanNumberOfIndWords];
#   else
  struct _c_bits8 w[1];
#   endif
#  endif
};
# endif



/***************************************************************************/
/* External Declarations                                                   */
/***************************************************************************/

/*  CAN driver version */
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kCanMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kCanSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kCanBugFixVersion;
/* ROM CATEGORY 4 END*/



# if defined( C_ENABLE_PRECOPY_FCT )
/* RAM CATEGORY 1 START*/
extern volatile CanReceiveHandle canRxHandle[kCanNumberOfChannels];
/* RAM CATEGORY 1 END*/
# endif

# if defined( C_ENABLE_CONFIRMATION_FLAG )
/* RAM CATEGORY 1 START*/
V_MEMRAM0 extern volatile V_MEMRAM1_NEAR union CanConfirmationBits V_MEMRAM2_NEAR CanConfirmationFlags;              /* PRQA S 0759 */
/* RAM CATEGORY 1 END*/
# endif

# if defined( C_ENABLE_INDICATION_FLAG )
/* RAM CATEGORY 1 START*/
V_MEMRAM0 extern volatile V_MEMRAM1_NEAR union CanIndicationBits   V_MEMRAM2_NEAR CanIndicationFlags;                /* PRQA S 0759 */
/* RAM CATEGORY 1 END*/
# endif


# if defined( C_ENABLE_CONFIRMATION_FCT ) && \
    defined( C_ENABLE_DYN_TX_OBJECTS )  && \
    defined( C_ENABLE_TRANSMIT_QUEUE )
/* RAM CATEGORY 3 START*/
extern CanTransmitHandle          confirmHandle[kCanNumberOfChannels];
/* RAM CATEGORY 3 END*/
# endif

/* ##RI1.4 - 3.31: Dynamic Receive DLC */
# if defined( C_ENABLE_VARIABLE_RX_DATALEN )
#  if ( kCanNumberOfRxObjects > 0 )
/* RAM CATEGORY 1 START*/
extern volatile vuint8 canVariableRxDataLen[kCanNumberOfRxObjects];
/* RAM CATEGORY 1 END*/
#  endif
# endif

/* RAM CATEGORY 1 START*/
extern CanChipDataPtr canRDSRxPtr[kCanNumberOfChannels];
/* RAM CATEGORY 1 END*/
/* RAM CATEGORY 1 START*/
extern CanChipDataPtr canRDSTxPtr[kCanNumberOfUsedTxCANObjects];
/* RAM CATEGORY 1 END*/


/***************************************************************************/
/* Data structures filled with data by parameter generating tool           */
/***************************************************************************/

# if defined( C_DRV_INTERNAL )
/* structures for init and common objects -----------------------*/
#  if defined( C_SINGLE_RECEIVE_CHANNEL )
#  else
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 tCanChannelObject   V_MEMROM2 CanChannelObject[kCanNumberOfChannels];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 vuint8              V_MEMROM2 CanInitObjectStartIndex[kCanNumberOfChannels+1];
/* ROM CATEGORY 4 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle   V_MEMROM2 CanTxDynRomStartIndex[kCanNumberOfChannels];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle   V_MEMROM2 CanTxDynRamStartIndex[kCanNumberOfChannels+1];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 CanReceiveHandle    V_MEMROM2 CanRxBasicStartIndex[kCanNumberOfChannels+1];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 CanReceiveHandle    V_MEMROM2 CanRxFullStartIndex[kCanNumberOfHwChannels+1];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 2 START*/
V_MEMROM0 extern V_MEMROM1 CanObjectHandle     V_MEMROM2 CanLogHwTxStartIndex[kCanNumberOfHwChannels+1];
/* ROM CATEGORY 2 END*/

/* ROM CATEGORY 2 START*/
V_MEMROM0 extern V_MEMROM1 CanObjectHandle     V_MEMROM2 CanHwTxStartIndex[kCanNumberOfHwChannels];
/* ROM CATEGORY 2 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 CanObjectHandle     V_MEMROM2 CanHwRxFullStartIndex[kCanNumberOfHwChannels];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 CanObjectHandle     V_MEMROM2 CanHwRxBasicStartIndex[kCanNumberOfHwChannels];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 CanObjectHandle     V_MEMROM2 CanHwUnusedStartIndex[kCanNumberOfHwChannels];
/* ROM CATEGORY 4 END*/
/* ROM CATEGORY 2 START*/
V_MEMROM0 extern V_MEMROM1 CanObjectHandle     V_MEMROM2 CanHwTxStopIndex[kCanNumberOfHwChannels];
/* ROM CATEGORY 2 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 CanObjectHandle     V_MEMROM2 CanHwRxFullStopIndex[kCanNumberOfHwChannels];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 CanObjectHandle     V_MEMROM2 CanHwRxBasicStopIndex[kCanNumberOfHwChannels];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 CanObjectHandle     V_MEMROM2 CanHwUnusedStopIndex[kCanNumberOfHwChannels];
/* ROM CATEGORY 4 END*/

/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 CanObjectHandle     V_MEMROM2 CanHwMsgTransmitIndex[kCanNumberOfHwChannels];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 CanObjectHandle     V_MEMROM2 CanHwTxNormalIndex[kCanNumberOfHwChannels];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 vsintx              V_MEMROM2 CanTxOffsetHwToLog[kCanNumberOfHwChannels];
/* ROM CATEGORY 1 END*/

#  endif  /* C_SINGLE_RECEIVE_CHANNEL */





# endif /* C_DRV_INTERNAL */

# if defined( C_SINGLE_RECEIVE_CHANNEL )
# else
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle   V_MEMROM2 CanTxStartIndex[kCanNumberOfChannels+1];
/* ROM CATEGORY 1 END*/ 
/* ROM CATEGORY 2 START*/ 
V_MEMROM0 extern V_MEMROM1 CanReceiveHandle    V_MEMROM2 CanRxStartIndex[kCanNumberOfChannels+1];
/* ROM CATEGORY 2 END*/
# endif

/* ROM generated */

# if ( kCanNumberOfTxObjects > 0 )
#   if defined( C_DRV_INTERNAL )
/* structures for transmit objects -----------------------*/
/* ROM CATEGORY 1 START*/ 
V_MEMROM0 extern V_MEMROM1 tCanTxId0 V_MEMROM2       CanTxId0[kCanNumberOfTxObjects];  
#    if (kCanNumberOfUsedCanTxIdTables > 1)
V_MEMROM0 extern V_MEMROM1 tCanTxId1 V_MEMROM2       CanTxId1[kCanNumberOfTxObjects];  
#    endif
#    if (kCanNumberOfUsedCanTxIdTables > 2)
V_MEMROM0 extern V_MEMROM1 tCanTxId2 V_MEMROM2       CanTxId2[kCanNumberOfTxObjects];  
#    endif
#    if (kCanNumberOfUsedCanTxIdTables > 3)
V_MEMROM0 extern V_MEMROM1 tCanTxId3 V_MEMROM2       CanTxId3[kCanNumberOfTxObjects];  
#    endif
#    if (kCanNumberOfUsedCanTxIdTables > 4)
V_MEMROM0 extern V_MEMROM1 tCanTxId4 V_MEMROM2       CanTxId4[kCanNumberOfTxObjects];  
#    endif

#    if defined( C_ENABLE_MIXED_ID )
#    endif
/* ROM CATEGORY 1 END*/
#   endif /* C_DRV_INTERNAL */

/* ROM CATEGORY 2 START*/
#   if defined( C_ENABLE_PART_OFFLINE )
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2          CanTxSendMask[kCanNumberOfTxObjects];
#   endif
/* ROM CATEGORY 2 END*/

/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2          CanTxDLC[kCanNumberOfTxObjects];
V_MEMROM0 extern V_MEMROM1 TxDataPtr V_MEMROM2       CanTxDataPtr[kCanNumberOfTxObjects];

#   if defined( C_ENABLE_CONFIRMATION_FLAG )
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2          CanConfirmationOffset[kCanNumberOfTxObjects];
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2          CanConfirmationMask[kCanNumberOfTxObjects];
#   endif
#   if defined( C_ENABLE_CONFIRMATION_FCT )
V_MEMROM0 extern V_MEMROM1 ApplConfirmationFct V_MEMROM2 CanTxApplConfirmationPtr[kCanNumberOfTxObjects];
#   endif
#   if defined( C_ENABLE_PRETRANSMIT_FCT )
V_MEMROM0 extern V_MEMROM1 ApplPreTransmitFct  V_MEMROM2 CanTxApplPreTransmitPtr[kCanNumberOfTxObjects];
#   endif
/* ROM CATEGORY 1 END*/

#   if defined( C_ENABLE_TX_FULLCAN_OBJECTS )
/* ROM CATEGORY 2 START*/
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2          CanTxHwObj[kCanNumberOfTxObjects];
/* ROM CATEGORY 2 END*/
#   endif

#   if defined( C_SINGLE_RECEIVE_CHANNEL )
#   else
#    if ( kCanNumberOfTxObjects > 0 )
/* ROM CATEGORY 2 START*/
V_MEMROM0 extern V_MEMROM1 CanChannelHandle    V_MEMROM2 CanTxMsgHandleToChannel[kCanNumberOfTxObjects];
/* ROM CATEGORY 2 END*/
#    endif
#   endif /* C_SINGLE_RECEIVE_CHANNEL */ 

#   if defined( C_ENABLE_MULTI_ECU_PHYS )
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 tVIdentityMsk V_MEMROM2      CanTxIdentityAssignment[kCanNumberOfTxObjects];
/* ROM CATEGORY 4 END*/
#   endif


#  if defined( C_ENABLE_TRANSMIT_QUEUE )
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
/* ROM CATEGORY 1 START*/
/* pad bits added before the current channel position*/
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 CanTxQueuePadBits[kCanNumberOfChannels];

/* start / stop indices for the element search*/
V_MEMROM0 extern V_MEMROM1 CanSignedTxHandle V_MEMROM2 CanTxQueueStartIndex[kCanNumberOfChannels + 1];
/* ROM CATEGORY 1 END*/
#endif
#  endif

# endif /* ( kCanNumberOfTxObjects > 0 ) */

/* structures for basic and full can receive objects -----------------------*/

# if ( kCanNumberOfRxObjects > 0 )
#  if defined( C_DRV_INTERNAL )
/* ROM CATEGORY 1 START*/
#   if defined( C_SEARCH_HASH ) 
#    if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
V_MEMROM0 extern V_MEMROM1 tCanRxId0 V_MEMROM2       CanRxId0[kCanNumberOfRxFullCANObjects];  
#     if (kCanNumberOfUsedCanRxIdTables > 1)
V_MEMROM0 extern V_MEMROM1 tCanRxId1 V_MEMROM2       CanRxId1[kCanNumberOfRxFullCANObjects];  
#     endif
#     if (kCanNumberOfUsedCanRxIdTables > 2)
V_MEMROM0 extern V_MEMROM1 tCanRxId2 V_MEMROM2       CanRxId2[kCanNumberOfRxFullCANObjects];  
#     endif
#     if (kCanNumberOfUsedCanRxIdTables > 3)
V_MEMROM0 extern V_MEMROM1 tCanRxId3 V_MEMROM2       CanRxId3[kCanNumberOfRxFullCANObjects];  
#     endif
#     if (kCanNumberOfUsedCanRxIdTables > 4)
V_MEMROM0 extern V_MEMROM1 tCanRxId4 V_MEMROM2       CanRxId4[kCanNumberOfRxFullCANObjects];  
#     endif

#     if defined( C_ENABLE_MIXED_ID )
#      if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#      else
V_MEMROM0 extern V_MEMROM1 tCanIdType V_MEMROM2      CanRxIdType[kCanNumberOfRxFullCANObjects];
#      endif
#     endif
#    endif /* C_ENABLE_RX_FULLCAN_OBJECTS */
#   else   /* C_SEARCH_HASH */
V_MEMROM0 extern V_MEMROM1 tCanRxId0 V_MEMROM2       CanRxId0[kCanNumberOfRxObjects];  
#    if (kCanNumberOfUsedCanRxIdTables > 1)
V_MEMROM0 extern V_MEMROM1 tCanRxId1 V_MEMROM2       CanRxId1[kCanNumberOfRxObjects];  
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 2)
V_MEMROM0 extern V_MEMROM1 tCanRxId2 V_MEMROM2       CanRxId2[kCanNumberOfRxObjects];  
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 3)
V_MEMROM0 extern V_MEMROM1 tCanRxId3 V_MEMROM2       CanRxId3[kCanNumberOfRxObjects];  
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 4)
V_MEMROM0 extern V_MEMROM1 tCanRxId4 V_MEMROM2       CanRxId4[kCanNumberOfRxObjects];  
#    endif

#    if defined( C_ENABLE_MIXED_ID )
#     if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#     else
V_MEMROM0 extern V_MEMROM1 tCanIdType V_MEMROM2      CanRxIdType[kCanNumberOfRxObjects];
#     endif
#    endif
#   endif  /* C_SEARCH_HASH */


#   if defined( C_SEARCH_HASH )
V_MEMROM0 extern V_MEMROM1 CanReceiveHandle V_MEMROM2     CanRxMsgIndirection[kHashSearchListCount + kHashSearchListCountEx + kCanNumberOfRxFullCANObjects];
#   else
#     if defined( C_ENABLE_RX_MSG_INDIRECTION )
V_MEMROM0 extern V_MEMROM1 CanReceiveHandle V_MEMROM2     CanRxMsgIndirection[kCanNumberOfRxObjects];
#     endif
#   endif

#   if defined( C_SEARCH_HASH )
#    if defined( C_ENABLE_EXTENDED_ID )
#     if( kHashSearchListCountEx > 0)
V_MEMROM0 extern V_MEMROM1 vuint32 V_MEMROM2              CanRxHashIdEx[kHashSearchListCountEx];
#     endif /* (kHashSearchListCountEx > 0) */
#     if defined( C_ENABLE_MIXED_ID )
#      if( kHashSearchListCount > 0)
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2              CanRxHashId[kHashSearchListCount];
#      endif
#     endif
#    else
#     if( kHashSearchListCount > 0)
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2              CanRxHashId[kHashSearchListCount];
#     endif 
#    endif
#   endif

#   if defined( C_ENABLE_MULTI_ECU_PHYS )
V_MEMROM0 extern V_MEMROM1 tVIdentityMsk V_MEMROM2           CanRxIdentityAssignment[kCanNumberOfRxObjects];
#   endif

/* ROM CATEGORY 1 END*/

/* ROM CATEGORY 4 START*/
/* ROM CATEGORY 4 END*/

#  endif /* C_DRV_INTERNAL */

/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMROM1 vuint8               V_MEMROM2 CanRxDataLen[kCanNumberOfRxObjects];
#   if defined( C_ENABLE_DLC_CHECK_MIN_DATALEN )
V_MEMROM0 extern V_MEMROM1 vuint8               V_MEMROM2 CanRxMinDataLen[kCanNumberOfRxObjects];
#   endif
V_MEMROM0 extern V_MEMROM1 RxDataPtr            V_MEMROM2 CanRxDataPtr[kCanNumberOfRxObjects];

#   if defined( C_ENABLE_PRECOPY_FCT )
V_MEMROM0 extern V_MEMROM1 ApplPrecopyFct       V_MEMROM2 CanRxApplPrecopyPtr[kCanNumberOfRxObjects];
#   endif
#   if defined( C_ENABLE_INDICATION_FLAG )
V_MEMROM0 extern V_MEMROM1 vuint8               V_MEMROM2 CanIndicationOffset[kCanNumberOfRxObjects];
V_MEMROM0 extern V_MEMROM1 vuint8               V_MEMROM2 CanIndicationMask[kCanNumberOfRxObjects];
#   endif
#   if defined( C_ENABLE_INDICATION_FCT )
V_MEMROM0 extern V_MEMROM1 ApplIndicationFct    V_MEMROM2 CanRxApplIndicationPtr[kCanNumberOfRxObjects];
#   endif
/* ROM CATEGORY 1 END*/
# endif /* ( kCanNumberOfRxObjects > 0 ) */


/* structure used on initialization CAN chip -------------------------------*/
#if defined(C_SINGLE_RECEIVE_CHANNEL)
#else
/* ROM CATEGORY 1 START*/
V_MEMROM0 extern V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3* V_MEMROM1 V_MEMROM2 CanMailboxBasisAdr[kCanNumberOfChannels];
V_MEMROM0 extern V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3* V_MEMROM1 V_MEMROM2 CanBasisAdr[kCanNumberOfChannels];
/* ROM CATEGORY 1 END*/
/* ROM CATEGORY 2 START*/
V_MEMROM0 extern V_MEMROM1 vuint32 V_MEMROM2 CanRxFullCANObjMask[kCanNumberOfChannels];
/* ROM CATEGORY 2 END*/
/* ROM CATEGORY 2 START*/
V_MEMROM0 extern  V_MEMROM1 vuint32 V_MEMROM2 CanRxBasicCANObjMask[kCanNumberOfChannels];
/* ROM CATEGORY 2 END*/
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern  V_MEMROM1 vuint32 V_MEMROM2 CanOPCSetting[kCanNumberOfChannels];
/* ROM CATEGORY 4 END*/
# if defined (C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC)
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 vuint32 V_MEMROM2 CanControllerMode[kCanNumberOfChannels];
/* ROM CATEGORY 4 END*/
# endif
#endif
/* structures for baudrate and filter initialization */
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 vuint32 V_MEMROM2 CanInitBTC[kCanNumberOfInitObjects];
V_MEMROM0 extern V_MEMROM1 vuint32 V_MEMROM2 CanInitLAM0[kCanNumberOfInitObjects];
V_MEMROM0 extern V_MEMROM1 vuint32 V_MEMROM2 CanInitMID1[kCanNumberOfInitObjects];
/* ROM CATEGORY 4 END*/


/***************************************************************************/
/* Callback functions                                                      */
/***************************************************************************/

# if defined( C_ENABLE_INTCTRL_ADD_CAN_FCT )
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanAddCanInterruptRestore(CanChannelHandle channel);
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanAddCanInterruptDisable(CanChannelHandle channel);
/* CODE CATEGORY 1 END*/
# endif

# if defined( C_ENABLE_HARDWARE_CHECK ) || \
    defined( C_ENABLE_USER_CHECK )     || \
    defined( C_ENABLE_GEN_CHECK )      || \
    defined( C_ENABLE_INTERNAL_CHECK ) 
/* CODE CATEGORY 4 START*/ 
C_CALLBACK_1 void C_CALLBACK_2 ApplCanFatalError(CAN_CHANNEL_CANTYPE_FIRST vuint8 errorNumber);
/* CODE CATEGORY 4 END*/
# endif

# if defined( C_SINGLE_RECEIVE_CHANNEL )
/* these two functions are declared by the tool in case of multichannel */
/* CODE CATEGORY 4 START*/ 
C_CALLBACK_1 void C_CALLBACK_2 ApplCanBusOff(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/ 
C_CALLBACK_1 void C_CALLBACK_2 ApplCanWakeUp(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END*/
# endif
# if defined( C_ENABLE_APPLCANPREWAKEUP_FCT )
/* CODE CATEGORY 4 START*/ 
C_CALLBACK_1 void C_CALLBACK_2 ApplCanPreWakeUp(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END*/
# endif
# if defined( C_ENABLE_OVERRUN )
/* CODE CATEGORY 4 START*/ 
C_CALLBACK_1 void C_CALLBACK_2 ApplCanOverrun ( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
# endif
# if defined( C_ENABLE_FULLCAN_OVERRUN )
/* CODE CATEGORY 4 START*/ 
C_CALLBACK_1 void C_CALLBACK_2 ApplCanFullCanOverrun ( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
# endif

/* Range precopy/ generic precopy functions ********************************/
# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  if defined( C_ENABLE_RANGE_0 )
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 vuint8 C_CALLBACK_2 ApplCanRange0Precopy( CanRxInfoStructPtr rxStruct );
/* CODE CATEGORY 1 END*/
#  endif
#  if defined( C_ENABLE_RANGE_1 )
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 vuint8 C_CALLBACK_2 ApplCanRange1Precopy( CanRxInfoStructPtr rxStruct );
/* CODE CATEGORY 1 END*/
#  endif
#  if defined( C_ENABLE_RANGE_2 )
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 vuint8 C_CALLBACK_2 ApplCanRange2Precopy( CanRxInfoStructPtr rxStruct );
/* CODE CATEGORY 1 END*/
#  endif
#  if defined( C_ENABLE_RANGE_3 )
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 vuint8 C_CALLBACK_2 ApplCanRange3Precopy( CanRxInfoStructPtr rxStruct );
/* CODE CATEGORY 1 END*/
#  endif
# endif

# if defined( C_ENABLE_COND_RECEIVE_FCT )
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanMsgCondReceived  ( CanRxInfoStructPtr rxStruct );
/* CODE CATEGORY 1 END*/
# endif

# if defined( C_ENABLE_CAN_RAM_CHECK )
#  if defined( C_ENABLE_NOTIFY_CORRUPT_MAILBOX )
/* CODE CATEGORY 4 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanCorruptMailbox(CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle hwObjHandle);
/* CODE CATEGORY 4 END*/
#  endif
/* CODE CATEGORY 4 START*/
C_CALLBACK_1 vuint8 C_CALLBACK_2 ApplCanMemCheckFailed(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END*/
# endif

# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  if defined( C_ENABLE_RECEIVE_FCT )
/* in case of multiple CAN channels this function is declared by the tool */
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 vuint8 C_CALLBACK_2 APPL_CAN_MSGRECEIVED(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END*/
#  endif
# endif

/* ##RI1.4 - 2.7: Callbackfunction-DLC-Check */
# if defined( C_ENABLE_DLC_FAILED_FCT )
/* CODE CATEGORY 4 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanMsgDlcFailed( CanRxInfoStructPtr rxStruct ); 
/* CODE CATEGORY 4 END*/ 
# endif  /*C_ENABLE_DLC_FAILED_FCT */

# if defined( C_ENABLE_GENERIC_PRECOPY )
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 vuint8 C_CALLBACK_2 APPL_CAN_GENERIC_PRECOPY( CanRxInfoStructPtr rxStruct );
/* CODE CATEGORY 1 END*/
# endif

# if defined( C_ENABLE_NOT_MATCHED_FCT )
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanMsgNotMatched( CanRxInfoStructPtr rxStruct );
/* CODE CATEGORY 1 END*/
# endif

# if defined( C_ENABLE_CAN_TX_CONF_FCT )
/* ##RI-1.10 Common Callbackfunction in TxInterrupt */
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 void C_CALLBACK_2 APPL_CAN_TX_CONFIRMATION(CanTxInfoStructPtr txStruct);
/* CODE CATEGORY 1 END*/
# endif

# if defined( C_ENABLE_TX_OBSERVE )
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanTxObjStart( CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txHwObject );
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanTxObjConfirmed( CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txHwObject );
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 4 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanInit( CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txHwObjectFirstUsed, CanObjectHandle txHwObjectFirstUnused);
/* CODE CATEGORY 4 END*/
# endif

# if defined( C_ENABLE_HW_LOOP_TIMER )
/* CODE CATEGORY 2 START*/
C_CALLBACK_1 void     C_CALLBACK_2 ApplCanTimerStart(CAN_CHANNEL_CANTYPE_FIRST vuint8 source);
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 2 START*/
C_CALLBACK_1 vuint8 C_CALLBACK_2 ApplCanTimerLoop (CAN_CHANNEL_CANTYPE_FIRST vuint8 source);
/* CODE CATEGORY 2 END*/
/* CODE CATEGORY 2 START*/
C_CALLBACK_1 void     C_CALLBACK_2 ApplCanTimerEnd  (CAN_CHANNEL_CANTYPE_FIRST vuint8 source);
/* CODE CATEGORY 2 END*/
# endif


# if defined( C_SINGLE_RECEIVE_CHANNEL )
/* in case of multichannel these two functions are declared by the tool */
#  if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
/* CODE CATEGORY 3 START*/
C_CALLBACK_1 void C_CALLBACK_2 APPL_CAN_CANCELNOTIFICATION( CanTransmitHandle txHandle );
/* CODE CATEGORY 3 END*/
#  endif
# endif


# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
/* CODE CATEGORY 3 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanChannelDummy( CanChannelHandle channel );
/* CODE CATEGORY 3 END*/
# endif
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) || \
    defined( C_HL_ENABLE_DUMMY_FCT_CALL )
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanTxHandleDummy( CanTransmitHandle txHandle );
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 vuint8 C_CALLBACK_2 ApplCanRxStructPtrDummy( CanRxInfoStructPtr rxStruct );
/* CODE CATEGORY 1 END*/
# endif
# if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 void C_CALLBACK_2 ApplCanRxHandleDummy( CanReceiveHandle rxHandle );
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 1 START*/
C_CALLBACK_1 vuint8 C_CALLBACK_2 ApplCanTxStructDummy( CanTxInfoStruct txStruct );
/* CODE CATEGORY 1 END*/
# endif
# if defined( C_ENABLE_ONLINE_OFFLINE_CALLBACK_FCT )
/* CODE CATEGORY 4 START*/
C_CALLBACK_1 void C_CALLBACK_2 APPL_CAN_OFFLINE( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
C_CALLBACK_1 void C_CALLBACK_2 APPL_CAN_ONLINE( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
# endif

# if defined (C_ENABLE_CAN_CAN_INTERRUPT_CONTROL) &&\
     defined (C_ENABLE_OSEK_CAN_INTCTRL)
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 OsCanCanInterruptDisable( CAN_HW_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 OsCanCanInterruptRestore( CAN_HW_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 1 END*/
# endif


/***************************************************************************/
/* function prototypes                                                     */
/***************************************************************************/

/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanInitPowerOn( void );
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanInit( CAN_CHANNEL_CANTYPE_FIRST CanInitHandle initObject );
/* CODE CATEGORY 4 END*/

# if defined( C_ENABLE_CAN_TRANSMIT )
/* CODE CATEGORY 2 START*/
C_API_1 vuint8 C_API_2 CanTransmit(CanTransmitHandle txHandle) C_API_3;
/* CODE CATEGORY 2 END*/
#  if defined( C_ENABLE_VARIABLE_DLC )
/* CODE CATEGORY 2 START*/
C_API_1 vuint8 C_API_2 CanTransmitVarDLC( CanTransmitHandle txHandle, vuint8 dlc);
/* CODE CATEGORY 2 END*/
#  endif
/* CODE CATEGORY 3 START*/
C_API_1 void C_API_2 CanCancelTransmit( CanTransmitHandle txHandle );
/* CODE CATEGORY 3 END*/
# endif


# if defined( C_ENABLE_OFFLINE )
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanOnline( CAN_CHANNEL_CANTYPE_ONLY );           /* switch CanStatus to On */
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanOffline( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
# endif

# if defined( C_ENABLE_PART_OFFLINE )
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetPartOffline( CAN_CHANNEL_CANTYPE_FIRST vuint8 sendGroup);
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetPartOnline( CAN_CHANNEL_CANTYPE_FIRST vuint8 invSendGroup);
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanGetPartMode( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
# endif

/* CODE CATEGORY 3 START*/
C_API_1 vuint8 C_API_2 CanGetStatus( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 3 END*/

/* CanSleep functions */
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanSleep( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanWakeUp( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/

# if defined( C_ENABLE_ECU_SWITCH_PASS )
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetActive(  CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetPassive( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
# else
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
#   define    CanSetActive( channel )            /* remove calls to setActive/Passive*/
#   define    CanSetPassive( channel )
#  else
#   define    CanSetActive( )                    /* remove calls to setActive/Passive*/
#   define    CanSetPassive( )
#  endif
# endif

# if defined( C_ENABLE_STOP )
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanStart( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanStop( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
# endif

# if defined (C_ENABLE_CAN_CAN_INTERRUPT_CONTROL)
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 CanCanInterruptDisable( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 CanCanInterruptRestore( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 1 END*/
# else
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
#   define    CanCanInterruptDisable( channel )            /* remove calls to canInterruptDisable/Restore */
#   define    CanCanInterruptRestore( channel )
#  else
#   define    CanCanInterruptDisable( )                    /* remove calls to canInterruptDisable/Restore */
#   define    CanCanInterruptRestore( )
#  endif
# endif

# if defined( C_ENABLE_TX_POLLING ) || \
    defined( C_ENABLE_RX_FULLCAN_POLLING )  || \
    defined( C_ENABLE_RX_BASICCAN_POLLING ) || \
    defined( C_ENABLE_ERROR_POLLING ) || \
    defined( C_ENABLE_WAKEUP_POLLING ) 
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanTask(void);
/* CODE CATEGORY 2 END*/
# endif
# if defined( C_ENABLE_TX_POLLING ) 
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanTxTask( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 2 END*/
# endif
# if defined( C_ENABLE_ERROR_POLLING )
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanErrorTask( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 2 END*/
# endif
# if defined( C_ENABLE_SLEEP_WAKEUP )
#  if defined( C_ENABLE_WAKEUP_POLLING )
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanWakeUpTask(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END*/
#  endif
# endif
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS ) && \
    defined( C_ENABLE_RX_FULLCAN_POLLING )  
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanRxFullCANTask(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END*/
# endif
#if defined( C_ENABLE_RX_BASICCAN_POLLING ) && \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanRxBasicCANTask(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END*/
# endif


# if defined( C_ENABLE_DYN_TX_OBJECTS )
/* CODE CATEGORY 3 START*/
C_API_1 CanTransmitHandle C_API_2 CanGetDynTxObj(CanTransmitHandle txHandle );
/* CODE CATEGORY 3 END*/
/* CODE CATEGORY 3 START*/
C_API_1 vuint8          C_API_2 CanReleaseDynTxObj(CanTransmitHandle txHandle);
/* CODE CATEGORY 3 END*/

#  if defined( C_ENABLE_DYN_TX_ID )
#   if !defined( C_ENABLE_EXTENDED_ID ) ||\
     defined( C_ENABLE_MIXED_ID )
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetId(CanTransmitHandle txHandle, vuint16 id);
/* CODE CATEGORY 2 END*/
#   endif
#   if defined( C_ENABLE_EXTENDED_ID )
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetExtId(CanTransmitHandle txHandle, vuint16 idExtHi, vuint16 idExtLo);
/* CODE CATEGORY 2 END*/
#   endif
#  endif
#  if defined( C_ENABLE_DYN_TX_DLC )
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetDlc(CanTransmitHandle txHandle, vuint8 dlc);
/* CODE CATEGORY 2 END*/
#  endif
#  if defined( C_ENABLE_DYN_TX_DATAPTR )
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetDataPtr(CanTransmitHandle txHandle, void* pData);
/* CODE CATEGORY 2 END*/
#  endif


# endif /* defined( C_ENABLE_DYN_TX_OBJECTS ) */

# if defined( C_ENABLE_TX_MASK_EXT_ID )
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtHi( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask );
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtMidHi( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask );
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtMidLo( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask );
/* CODE CATEGORY 4 END*/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtLo( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask );
/* CODE CATEGORY 4 END*/
# endif

# if defined( C_ENABLE_TX_OBSERVE )
/* CODE CATEGORY 3 START*/
C_API_1 CanTransmitHandle C_API_2 CanTxGetActHandle( CanObjectHandle logicalTxHdl );
/* CODE CATEGORY 3 END*/
# endif

# if defined( C_ENABLE_COND_RECEIVE_FCT )
/* CODE CATEGORY 3 START*/
C_API_1 void     C_API_2 CanSetMsgReceivedCondition( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 3 END*/
/* CODE CATEGORY 3 START*/
C_API_1 void     C_API_2 CanResetMsgReceivedCondition( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 3 END*/
/* CODE CATEGORY 3 START*/
C_API_1 vuint8 C_API_2 CanGetMsgReceivedCondition( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 3 END*/
# endif


/* Additional API for QNX */





#if defined( C_ENABLE_MEMCOPY_SUPPORT )
/* CODE CATEGORY 1 START*/
void CanCopyToCan(CanChipDataPtr dst, void * src, vuint8 len);
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 1 START*/
void CanCopyFromCan(void *dst, CanChipDataPtr src, vuint8 len);
/* CODE CATEGORY 1 END*/
#endif

# if defined ( C_ENABLE_DRIVER_STATUS )
/* CODE CATEGORY 4 START*/
vuint8 CanGetDriverStatus(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END*/
# endif




#  define CAN_IRQ_FUNC_QUAL1
#  define CAN_IRQ_FUNC_QUAL2


/* Possibility to disable the prototypes of interrupt service routines in the driver configuration header file.  */
#if !(defined( C_ENABLE_ISR_PROTOTYPE) || defined( C_DISABLE_ISR_PROTOTYPE ))
# define C_ENABLE_ISR_PROTOTYPE
#endif


#if defined (C_ENABLE_ISR_PROTOTYPE)
# if defined(C_ENABLE_OSEK_OS)&&\
     defined(C_ENABLE_OSEK_OS_INTCAT2)
/* ISR prototypes mus be provided by OSEK header file */
# else
#  if ((defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
       (defined( C_ENABLE_RX_FULLCAN_OBJECTS )  && !defined( C_ENABLE_RX_FULLCAN_POLLING  )) || \
        !defined( C_ENABLE_TX_POLLING )        || \
        !defined( C_ENABLE_ERROR_POLLING )     ||\
        !defined( C_ENABLE_WAKEUP_POLLING ))        /* ISR necessary; no pure polling configuration*/
/* CODE CATEGORY 1 START*/
#   if defined( kCanPhysToLogChannelIndex_0 )
CAN_IRQ_FUNC_QUAL1 void CAN_IRQ_FUNC_QUAL2 CanIsr_0( void );
#   endif
#   if defined( kCanPhysToLogChannelIndex_1 )
CAN_IRQ_FUNC_QUAL1 void CAN_IRQ_FUNC_QUAL2 CanIsr_1( void );
#   endif
#   if defined( kCanPhysToLogChannelIndex_2 )
CAN_IRQ_FUNC_QUAL1 void CAN_IRQ_FUNC_QUAL2 CanIsr_2( void );
#   endif
/* CODE CATEGORY 1 END*/
#  endif /* no pure polling configuration */
# endif
#endif /* if defined (C_ENABLE_ISR_PROTOTYPE) */



#endif /* CAN_DEF_H */

/* End of channel */



/* Kernbauer Version: 1.14 Konfiguration: can_driver Erzeugungsgangnummer: 1 */

/* Kernbauer Version: 1.14 Konfiguration: can_driver Erzeugungsgangnummer: 1 */

/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
