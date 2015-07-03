/* Kernbauer Version: 1.14 Konfiguration: can_driver Erzeugungsgangnummer: 1 */

/* STARTSINGLE_OF_MULTIPLE */


#if defined(C_COMP_TI_TMS470)
/*****************************************************************************
| Project Name: C A N - D R I V E R
|    File Name: CAN_DRV.C
|
|  Description: Implementation of the CAN driver
|               Target systems: TMS470 all SCC and HECC derivatives
|               Compiler:       Texas Instruments Compiler
|                                                                           */
#endif
/*----------------------------------------------------------------------------
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
| --------     ---------------------     -------------------------------------
| Ml           Patrick Markl             Vector Informatik GmbH
| Ard          Thomas Arnold             Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Version   Author  Description
|----------  --------  ------  -----------------------------------------------
|2003-02-27  00.01.00    Ml     - Creation
|2003-07-07  00.02.00    Ml     - ESCAN00005987: added support for extended and mixed ID
|2003-07-31  00.03.00    Ml     - resolved issues found in code inspection
|2003-08-01  01.00.00    Ml     - Release for TMS320
|2003-08-03  01.01.00    Ml     - ESCAN00006259: resolved clearing of CANRMP register
|2003-08-04  02.00.00    Ml     - ESCAN00006262: added support for TMS470
|2003-12-04  03.00.00    Ml     - ESCAN00007131: added support for OMAP
|2004-01-13  03.01.00    Ml     - ESCAN00007253: fixed several Issues
|2004-01-18  03.02.00    Ml     - ESCAN00007282: removed warning
|2004-02-21  03.03.00    Ml     - ESCAN00007670: added CAN RAM check
|2004-03-03  03.04.00    Ml     - ESCAN00007632: IDE bit is not set in LAM register
|2004-03-31              Ml     - ESCAN00008069: HECC workaround is configurable       
|2004-04-01              Ml     - ESCAN00008079: Resolved review issues
|2004-05-17  03.05.00    Ml     - ESCAN00008423: workaround for eCAN access conflicts
|2004-07-11  03.06.00    Ml     - ESCAN00008818: handling of RxTx IRQs in sleep mode
|                        Ml     - ESCAN00006634: no changes
|                        Ml     - ESCAN00008818: Sleepmode is checked in RxTx Interrupt
|                        Ml     - ESCAN00008878: changed handling of User and Systemmode
|                        Ml     - ESCAN00008986: Wakeup IRQ activated
|                        Ml     - ESCAN00007281: resolved compilerwarning in CanTransmit
|                        Ml     - ESCAN00008986: Wakeup interrupt is enabled always
|                        Ml     - ESCAN00009115: Support multiple configurations
|                        Ml     - ESCAN00010073: BusOff IRQ is fired
|                        Ml     - ESCAN00008885: Check Wakeup in RxTx IRQ
|2004-10-19  03.07.00    Ml     - ESCAN00009135: changed handling of LoopCheck Returnvalues 
|                        Ml     - ESCAN00010203: Implementation of CanStart/CanStop changed
|                        Ml     - ESCAN00010047: Set BOIM flag
|                        Ml     - ESCAN00010625: Resolved compilererror
|                        Ml     - ESCAN00007215: Added memcpy support
|                        Ml     - ESCAN10626, ESCAN10630: resolved message doubling
|2005-01-20  04.00.00    Ml     - ESCAN00011416: added support for TMS430
|2005-04-04  04.01.00    Ml     - ESCAN00011745: Changes after review and MISRA check
|                        Ml     - ESCAN00011746: Rx masking also possible in SCC mode (TMS470)
|2005-11-04  04.02.00    Ml     - ESCAN00014177: Fixed channel parameter of the timer loop check functions
|2005-12-02  04.03.00    Ml     - ESCAN00014307: Changed version defines
|                        Ml     - ESCAN00013946: Changed prototypes because of compiler issue
|2005-12-12  04.04.00    Ml     - ESCAN00014611: Share code among CAN and LIN driver
|2006-01-30  04.05.00    Ard    - ESCAN00014987: Support new derivative TMS470P family
|                               - ESCAN00015100: Update to new highlevel version 1.39
|                               - ESCAN00015120: Fix erroneous call of observe and confirmation callback for messages canceled from hardware
|                               - ESCAN00015551
|                                 ESCAN00015552
|                                 ESCAN00015553
|                                 ESCAN00015158: no changes
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
|2007-05-21  04.11.00    Ard    - ESCAN00019253: Remove warning at declaration of CanWritePrivileged()
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
|***************************************************************************/
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
| --------     ---------------------     -------------------------------------
| Ht           Heike Honert              Vector Informatik GmbH
| Pl           Georg Pfluegel            Vector Informatik GmbH
| Vg           Frank Voorburg            Vector CANtech, Inc.
| An           Ahmad Nasser              Vector CANtech, Inc.
| Ml           Patrick Markl             Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Ver  Author  Description
| ---------  ---  ------  ----------------------------------------------------
| 19-Jan-01  0.02  Ht     - derived form C16x V3.3
| 18-Apr-01  1.00  Pl     - derived for ARM7 TDMI
| 02-May-01  1.01  Ht     - adaption to LI1.2
|                         - change from code doupling to indexed
| 31-Oct-01  1.02  Ht     - support hash search
|                  Ht     - optimisation for message access (hardware index)
|                  Vg     - adaption for PowerPC
| 07-Nov-01  1.03  Ht     - remove some comments
|                         - support of basicCAN polling extended
| 12-Dez-01  1.04  Ht     - avoid compiler warnings for KEIL C166
|                         - ESCAN00001881: warning in CanInitPowerOn
|                         - ESCAN00001913: call of CanLL_TxEnd()
|                  Fz     - ESCAN00001914: CanInterruptRestore changed for M32C
| 02-Jan-02  1.05  Ht     - ESCAN00002009: support of polling mode improved
|                         - ESCAN00002010: Prototype of CanHL_TxConfirmation() 
|                                          not available in every case.
| 12-Feb-02  1.06 Pl      - ESCAN00002279: - now it is possible to use only the error-task without the tx-task
|                                          - support of the makro  REENTRANT
|                                          - support of the makro C_HL_ENABLE_RX_INFO_STRUCT_PTR
|                                          - For better performance for the T89C51C there is a switch-case
|                                            instruction for direct call of the PreTransmitfunction
|                                          - add C_ENABLE_RX_BASICCAN_POLLING in CanInitPowerOn
| 18-Mai-02  1.07 Ht      - ESCAN....    : support Hash search with FullCAN controller
|                         - ESCAN00002707: Reception could went wrong if IL and Hash Search
|                         - ESCAN00002893: adaption to LI 1.3
| 29-Mai-02  1.08 Ht      - ESCAN00003028: Transmission could fail in Polling mode
|                         - ESCAN00003082: call Can_LL_TxEnd() in CanMsgTransmit()
|                         - ESCAN00003083: Hash search with extended ID
|                         - ESCAN00003084: Support C_COMP_METROWERKS_PPC
|                         - ESCAN00002164: Temporary vaiable "i" not defined in function CanBasicCanMsgReceived
|                         - ESCAN00003085: support C_HL_ENABLE_IDTYPE_IN_ID
| 25-Jun     1.08.01 Vg   - Declared localInterruptOldFlag in CanRxTask()
|                         - Corrected call to CanWakeUp for multichannel
| 11-Jul-02  1.08.02 Ht   - ESCAN00003203: Hash Search routine does not work will with extended IDs
|                         - ESCAN00003205: Support of ranges could went wrong on some platforms
| 08-Aug-02  1.08.03 Ht   - ESCAN00003447: Transmission without databuffer and pretransmit-function 
| 08-Aug-02  1.08.04 An   - Added support to Green Hills
| 09-Sep-02  1.09    Ht   - ESCAN00003837: code optimication with KernelBuilder
|                         - ESCAN00004479: change the place oft the functioncall of CanLL_TxCopyMsgTransmit
|                                          in CanMsgTransmit 
| 2002-12-06 1.10    Ht   -                Support consistancy for polling tasks
|                         - ESCAN00004567: Definiton of V_NULL pointer
|                         -                remove include of string.h
|                         -                support Dummy functions for indirect function call 
|                         -                optimization for one single Tx mail box
| 2003-02-04 1.11    Ht   -                optimization for polling mode
| 2003-03-19 1.12    Ht   - ESCAN00005152: optimization of CanInit() in case of Direct Tx Objects
|                         - ESCAN00005143: CompilerWarning about function prototype 
|                                          CanHL_ReceivedRxHandle() and CanHL_IndRxHandle
|                         - ESCAN00005130: Wrong result of Heash Search on second or higher channel               
| 2003-05-12 1.13    Ht   - ESCAN00005624: support CantxMsgDestroyed for multichannel system
|                         - ESCAN00005209: Support confirmation and indication flags for EasyCAN4
|                         - ESCAN00004721: Change data type of Handle in CanRxInfoStruct
| 2003-06-18 1.20   Ht    - ESCAN00005908: support features of RI1.4
|                         - ESCAN: Support FJ16LX-Workaround for multichannel system
|                         - ESCAN00005671: Dynamic Transmit Objects: ID in extended ID frames is wrong
|                         - ESCAN00005863: Notification about cancelation failes in case of CanTxMsgDestroyed
| 2003-06-30 1.21   Ht   - ESCAN00006117: Common Confirmation Function: Write access to wrong memory location
|                        - ESCAN00006008: CanCanInterruptDisable in case of polling
|                        - ESCAN00006118: Optimization for Mixed ID and ID type in Own Register or ID type in ID Register
|                        - ESCAN00006100: transmission with wrong ID in mixed ID mode
|                        - ESCAN00006063: Undesirable hardware dependency for 
|                                         CAN_HL (CanLL_RxBasicTxIdReceived)
| 2003-09-10 1.22   Ht   - ESCAN00006853: Support V_MEMROM0
|                        - ESCAN00006854: suppress some Compiler warnings
|                        - ESCAN00006856: support CanTask if only Wakeup in polling mode
|                        - ESCAN00006857: variable newDLC not defined in case of Variable DataLen
| 2003-10-14 1.23   Ht   - ESCAN00006858: support BrsTime for internal runtime measurement
|                        - ESCAN00006860: support Conditional Msg Receive
|                        - ESCAN00006865: support "Cancel in HW" with CanTask
|                        - ESCAN00006866: support Direct Tx Objects
|                        - ESCAN00007109: support new memory qualifier for const data and pointer to const
| 2004-01-05 1.24   Ml   - ESCAN00007206: resolved preprocessor error for Hitachi compiler
|                   Ml   - ESCAN00007254: several changes
| 2004-02-06 1.25   Ml   - ESCAN00007281: solved compilerwarning
|                   Ml   - removed compiler warnings
| 2004-02-21 1.26   Ml   - ESCAN00007670: CAN RAM check
|                   Ml   - ESCAN00007671: fixed dyn Tx object issue
|                   Ml   - ESCAN00007764: added possibility to adjust Rx handle in LL drv
|                   Ml   - ESCAN00007681: solved compilerwarning in CanHL_IndRxHandle
|                   Ml   - ESCAN00007272: solved queue transmission out of LowLevel object
|                   Ml   - ESCAN00008064: no changes
| 2004-04-16 1.27   Ml   - ESCAN00008204: no changes
|                   Ml   - ESCAN00008160: no changes
|                   Ml   - ESCAN00008266: changed name of parameter of function CanTxGetActHandle
|                   Fz   - ESCAN00008272: Compiler error due to missing array canPollingTaskActive
| 2004-05-10 1.28   Fz   - ESCAN00008328: Compiler error if cancel in hardware is active
|                        - ESCAN00008363: Hole closed when TX in interrupt and cancel in HW is used
|                        - ESCAN00008365: Switch C_ENABLE_APPLCANPREWAKEUP_FCT added
|                        - ESCAN00008391: Wrong parameter macro used in call of 
|                                         CanLL_WakeUpHandling
| 2004-05-24 1.29   Ht   - ESCAN00008441: Interrupt not restored in case of internal error if TX Polling is used
| 2004-09-21 1.30   Ht   - ESCAN00008914: CAN channel may stop transmission for a certain time
|                        - ESCAN00008824: check of reference implementation version added
|                        - ESCAN00008825: No call of ApplCanMsgCancelNotification during CanInit()
|                        - ESCAN00008826: Support asssertions for "Conditional Message Received"  
|                   Ml   - ESCAN00008752: Added function qualifier macros
|                   Ht   - ESCAN00008823: compiler error due to array size 0
|                        - ESCAN00008977: label without instructions
|                        - ESCAN00009485: Message via Normal Tx Object will not be sent  
|                        - ESCAN00009497: support of CommonCAN and RX queue added
|                        - ESCAN00009521: Inconsitancy in total polling mode
| 2004-09-28 1.31   Ht   - ESCAN00009703: unresolved functions CAN_POLLING_IRQ_DISABLE/RESTORE()
| 2004-11-25 1.32   Ht   - move fix for ESCAN00007671 to CAN-LL of DrvCan_MpcToucanHll
|                        - ESCAN00010350: Dynamic Tx messages are send always with Std. ID
|                        - ESCAN00010388: ApplCanMsgConfirmed will only be called if realy transmitted
|                    Ml  - ESCAN00009931: The HardwareLoopCheck should have a channelparameter in multichannel systems.
|                    Ml  - ESCAN00010093: lint warning: function type inconsistent "CanCheckMemory"
|                    Ht  - ESCAN00010811: remove Misra and compiler warnings
|                        - ESCAN00010812: support Multi ECU
|                        - ESCAN00010526: CAN interrupts will be disabled accidently
|                        - ESCAN00010584: ECU may crash or behave strange with Rx queue active
| 2005-01-20 1.33    Ht  - ESCAN00010877: ApplCanMsgTransmitConf() is called erronemous
| 2005-03-03 1.34    Ht  - ESCAN00011139: Improvement/Correction of C_ENABLE_MULTI_ECU_CONFIG
|                        - ESCAN00011511: avoid PC-Lint warnings
|                        - ESCAN00011512: copy DLC in case of variable Rx Datalen
|                        - ESCAN00010847: warning due to missing brakets in can_par.c at CanChannelObject
| 2005-05-23 1.35   Ht   - ESCAN00012445: compiler error "V_MEMROMO undefined"in case of multi ECU
|                        - ESCAN00012350: Compiler Error "Illegal token channel"
| 2005-07-06 1.36   Ht   - ESCAN00012153: Compile Error: missing declaration of variable i
|                        - ESCAN00012460: Confirmation of LowLevel message will run into assertion (C_ENABLE_MULTI_ECU_PHYS enabled)
|                        - support Testpoints for CanTestKit
| 2005-07-14 1.37   Ht   - ESCAN00012892: compile error due to missing logTxObjHandle
|                        - ESCAN00012998: Compile Error: missing declaration of txHandle in CanInit()
|                        - support Testpoints for CanTestKit for FullCAN controller
| 2005-09-21 1.38   Ht   - ESCAN00013597: Linker error: Undefined symbol 'CanHL_IndRxHandle'
| 2005-11-10 1.39.00 Ht  - ESCAN00014331: Compile error due to missing 'else' in function CanTransmit
|
| 2005-04-26 2.00.00  Ht - ESCAN00016698: support RI1.5
|                        - ESCAN00014770: Cosmic compiler reports truncating assignement
|                        - ESCAN00016191: Compiler warning about unused variable in CanTxTask
|
| 2007-01-23 2.01.00  Ht - ESCAN00017279: Usage of SingleGlobalInterruptDisable lead to assertion in OSEK
|                        - ESCAN00017148: Compile error in higher layer due to missing declaration of CanTxMsgHandleToChannel
| 2007-03-14 2.02.00  Ht - ESCAN00019825: error directives added and misra changes
|                        - ESCAN00019827: adaption to never version of VStdLib.
|                        - ESCAN00019619: V_CALLBACK_1 and V_CALLBACK_2 not defined
|                        - ESCAN00019953: Handling of FullCAN reception in interrupt instead of polling or vice versa.
|                        - ESCAN00019958: CanDynTxObjSetId() or CanDynTxObjSetExtId() will run into assertion
| 2007-03-26 2.03.00  Ht - ESCAN00019988: Compile warnings in can_drv.c
|                        - ESCAN00018831: polling mode: function prototype without function implemenation (CanRxFullCANTask + CanRxBasicCANTask)
| 2007-04-20 2.04.00  dH - ESCAN00020299: user assertion fired irregularly due to unknown parameter (in case of CommonCAN)
| 2007-05-02 2.05.00  Ht - ESCAN00021069: Handling of canStatus improved, usage of preprocessor defines unified
|                        - ESCAN00021070: support relocation of HW objects in case of Multiple configuration
|                        - ESCAN00021166: Compiler Warnings: canHwChannel & canReturnCode not used in CanGetStatus
|                        - ESCAN00021223: CanCanInterruptDisabled called during Sleepmode in CanWakeupTask
|                        - ESCAN00022048: Parameter of ApplCancorruptMailbox is hardware channel instead of logical channel - Error directive added
| 2007-11-12 2.06.00  Ht - ESCAN00023188: support CAN Controller specific polling sequence for BasicCAN objects
|                        - ESCAN00023208: Compile issue about undefined variable kCanTxQueuePadBits in the CAN driver in Bit based Tx queue
| 2008-10-20 2.07.00  Ht - ESCAN00023010: support disabled mailboxes in case of extended RAM check
|                        - ESCAN00025706: provide C_SUPPORTS_MULTI_ECU_PHYS
|                        - ESCAN00026120: compiler warnings found on DrvCan_V85xAfcanHll RI 1.5     ##Ht: reviewed 2008-09-03
|                        - ESCAN00026322: ApplCanMsgNotMatched not called in special configuration
|                        - ESCAN00026413: Add possibility to reject remote frames received by FullCAN message objects
|                        - ESCAN00028758: CAN HL must support QNX
|                        - ESCAN00029788: CommonCAN for Driver which support only one Tx object improved (CanInit()).
|                        - ESCAN00029889: Compiler warning about uninitialized variable canHwChannel in CanCanInterruptDisable/Restore()
|                        - ESCAN00029891: Compiler warning: variable "rxHandle" was set but never used
|                        - ESCAN00029929: Support Extended ID Masking for Tx Fullcan messages 
|                        - ESCAN00030371: Improvements (assertions, misra)
|                            
|
|    ************    Version and change information of      **********        
|    ************    high level part only                   **********        
|
|    Please find the version number of the whole module in the previous 
|    File header.
|
|***************************************************************************/

#define C_DRV_INTERNAL

/* PRQA S 3453 EOF */      /* suppress messages: a function should probably used instead of function like macro. misra 19.7 */
/* PRQA S 3109 EOF */      /* suppress messages about empty statements. misra 14.3 */
/* PRQA S 2006 EOF */      /* suppress misra message about multiple return. misra 14.7 */


/*lint -function(exit,ApplCanFatalError)*/

/***************************************************************************/
/* Include files                                                           */
/***************************************************************************/

#include "can_inc.h"


/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
#if defined(C_COMP_TI_TMS470)            
# if( DRVCAN_TMS470HECCSCCHLL_VERSION != 0x0503)
#  error "Source and Header file are inconsistent!"
# endif

# if( DRVCAN_TMS470HECCSCCHLL_RELEASE_VERSION != 0x00)
#  error "Source and Header file are inconsistent!"
# endif
#endif


#if( C_VERSION_REF_IMPLEMENTATION != 0x150u)
# error "Generated Data and CAN driver source file are inconsistent!"
#endif

#if( DRVCAN__COREHLL_VERSION != 0x0207)
# error "Source and Header file are inconsistent!"
#endif
#if( DRVCAN__COREHLL_RELEASE_VERSION != 0x00)
# error "Source and Header file are inconsistent!"
#endif

#if ( ( DRVCAN__HLLTXQUEUEBIT_VERSION != 0x0105) )
# error "TxQueue Source and Header Version inconsistent!"
#endif
#if ( ( DRVCAN__HLLTXQUEUEBIT_RELEASE_VERSION != 0x00) )
# error "TxQueue Source and Header Version inconsistent!"
#endif


#if defined( DRVCAN__HLLTXQUEUEBIT_VERSION )
# if ( ( DRVCAN__HLLTXQUEUEBIT_VERSION != 0x0105) || \
       ( DRVCAN__HLLTXQUEUEBIT_RELEASE_VERSION != 0x00)  )
#  error "TxQueue Version inconsistent!"
# endif

/* defines to satisfy MISRA checker tool */
# define DRVCAN__HLLTXQUEUEBYTE_VERSION 0x0000
# define DRVCAN__HLLTXQUEUEBYTE_RELEASE_VERSION 0x00

#else
# if defined( DRVCAN__HLLTXQUEUEBYTE_VERSION )
#  if ( ( DRVCAN__HLLTXQUEUEBYTE_VERSION != 0x0103) || \
       ( DRVCAN__HLLTXQUEUEBYTE_RELEASE_VERSION != 0x00)  )
#   error "TxQueue Version inconsistent!"
#  endif
# else
#  error "No TxQueue available"
# endif

/* defines to satisfy MISRA checker tool */
# define DRVCAN__HLLTXQUEUEBIT_VERSION 0x0000
# define DRVCAN__HLLTXQUEUEBIT_RELEASE_VERSION 0x00

#endif


/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/


/* ##RI-1.1: Object parameters for Tx-Observe functions */
/* status of transmit objects */
#define kCanBufferFree                                     ((CanTransmitHandle)0xFFFFFFFFU)   /* mark a transmit object is free */
#define kCanBufferCancel                                   ((CanTransmitHandle)0xFFFFFFFEU)   /* mark a transmit object as canceled */
#define kCanBufferMsgDestroyed                             ((CanTransmitHandle)0xFFFFFFFDU)   /* mark a transmit object as destroyed */
/* reserved value because of definition in header:    0xFFFFFFFCU */
/* valid transmit message handle:   0x0 to kCanNumberOfTxObjects   */

/* return values */ 
#define kCanHlFinishRx                                     ((vuint8)0x00)
#define kCanHlContinueRx                                   ((vuint8)0x01)

#define  CANHL_TX_QUEUE_BIT
/*lint -e793 allow more than 511 distinct identifiers */










#if defined (C_ENABLE_CANCEL_IN_HW)
# define kCanMsgCanceled        ((vuint8)0)
# define kCanMsgTransmitted     ((vuint8)1)
# define kCanMsgUndefined       ((vuint8)2)
#endif


/* Mailbox Enable Register (CANME)                */
#define kCanDisableAllObj    ((tCanRegType)0x00000000)

/* Master Control Register (CANMC)                */
/*lint -esym(750, kCanMbcc,kCanTcc,kCanScm,kCanPdr,kCanDbo,kCanWuba,kCanCdr,kCanAbo,kCanStm) */
#define kCanMbcc      ((tCanRegType)0x00008000)
#define kCanTcc       ((tCanRegType)0x00004000)
#define kCanScm       ((tCanRegType)0x00002000)
#define kCanCcr       ((tCanRegType)0x00001000)
#define kCanPdr       ((tCanRegType)0x00000800)
#define kCanDbo       ((tCanRegType)0x00000400)
#define kCanWuba      ((tCanRegType)0x00000200)
#define kCanCdr       ((tCanRegType)0x00000100)
#define kCanAbo       ((tCanRegType)0x00000080)
#define kCanStm       ((tCanRegType)0x00000040)
#define kCanSres      ((tCanRegType)0x00000020)

/* Bit-Timing Configuration Register (CANBTC)     */
#define kCanTSegMask ((vuint32)0x0000007F)

/* Error and Status Register (CANES)              */
/*lint -esym(750, kCanFe,kCanBe,kCanSa1,kCanCrce,kCanSe,kCanAcke,kCanBo,kCanEp,kCanEw,kCanSma,kCanRm,kCanTm) */

#define kCanFe        ((tCanRegType)0x01000000)
#define kCanBe        ((tCanRegType)0x00800000)
#define kCanSa1       ((tCanRegType)0x00400000)
#define kCanCrce      ((tCanRegType)0x00200000)
#define kCanSe        ((tCanRegType)0x00100000)
#define kCanAcke      ((tCanRegType)0x00080000)
#define kCanBo        ((tCanRegType)0x00040000)
#define kCanEp        ((tCanRegType)0x00020000)
#define kCanEw        ((tCanRegType)0x00010000)
#define kCanSma       ((tCanRegType)0x00000020)
#define kCanCce       ((tCanRegType)0x00000010)
#define kCanPda       ((tCanRegType)0x00000008)
#define kCanRm        ((tCanRegType)0x00000002)
#define kCanTm        ((tCanRegType)0x00000001)
#define kCanErrorMask ((tCanRegType)0x01BF0000)

/* Global Interrupt Flag Register 0 CANGIF0       */
/*lint -esym(750, kCanMtof0,kCanTcof0,kCanGmif0,kCanAaif0,kCanWdif0,kCanWuif0,kCanRmlif0,kCanBoif0,kCanEpif0,kCanWlif0,kCanMivMask) */
#define kCanMtof0     ((tCanRegType)0x00020000)
#define kCanTcof0     ((tCanRegType)0x00010000)
#define kCanGmif0     ((tCanRegType)0x00008000)
#define kCanAaif0     ((tCanRegType)0x00004000)
#define kCanWdif0     ((tCanRegType)0x00002000)
#define kCanWuif0     ((tCanRegType)0x00001000)
#define kCanRmlif0    ((tCanRegType)0x00000800)
#define kCanBoif0     ((tCanRegType)0x00000400)
#define kCanEpif0     ((tCanRegType)0x00000200)
#define kCanWlif0     ((tCanRegType)0x00000100)
#define kCanMivMask   ((tCanRegType)0x0000001F)

/* Global Interrupt Flag Register 1 CANGIF1       */
/*lint -esym(750, kCanMtof1,kCanTcof1,kCanGmif1,kCanAaif1,kCanWdif1,kCanWuif1,kCanRmlif1,kCanBoif1,kCanEpif1,kCanWlif1) */
#define kCanMtof1     ((tCanRegType)0x00020000)
#define kCanTcof1     ((tCanRegType)0x00010000)
#define kCanGmif1     ((tCanRegType)0x00008000)
#define kCanAaif1     ((tCanRegType)0x00004000)
#define kCanWdif1     ((tCanRegType)0x00002000)
#define kCanWuif1     ((tCanRegType)0x00001000)
#define kCanRmlif1    ((tCanRegType)0x00000800)
#define kCanBoif1     ((tCanRegType)0x00000400)
#define kCanEpif1     ((tCanRegType)0x00000200)
#define kCanWlif1     ((tCanRegType)0x00000100)

/* Global Interrupt Mask Register (CANGIM)        */
/*lint -esym(750, kCanMtom,kCanTcom,kCanAaim,kCanWdim,kCanWuim,kCanRmlim,kCanBoim,kCanEpim,kCanWlim,kCanGil,kCanI1en,kCanI0en) */
#define kCanMtom      ((tCanRegType)0x00020000)
#define kCanTcom      ((tCanRegType)0x00010000)
#define kCanAaim      ((tCanRegType)0x00004000)
#define kCanWdim      ((tCanRegType)0x00002000)
#define kCanWuim      ((tCanRegType)0x00001000)
#define kCanRmlim     ((tCanRegType)0x00000800)
#define kCanBoim      ((tCanRegType)0x00000400)
#define kCanEpim      ((tCanRegType)0x00000200)
#define kCanWlim      ((tCanRegType)0x00000100)
#define kCanGil       ((tCanRegType)0x00000004)
#define kCanI1en      ((tCanRegType)0x00000002)
#define kCanI0en      ((tCanRegType)0x00000001)

/* Mailbox Interrupt Mask Register (CANMIM)       */
/* Mailbox Interrupt Level Register (CANMIL)      */
#define kCanAllLevel0 ((tCanRegType)0x00000000)
#define kCanAllLevel1 ((tCanRegType)0xFFFFFFFF)

/* I/O Tx Control Registers (CANTIOC)             */
/*lint -esym(750, kCanTxDir,kCanTxOut,kCanTxIn)   */
#define kCanTxFunc    ((tCanRegType)0x00000008) 
#define kCanTxDir     ((tCanRegType)0x00000004) 
#define kCanTxOut     ((tCanRegType)0x00000002) 
#define kCanTxIn      ((tCanRegType)0x00000001) 
/* I/O Rx Control Registers (CANRIOC)             */
/*lint -esym(750, kCanRxDir,kCanRxOut,kCanRxIn)   */
#define kCanRxFunc    ((tCanRegType)0x00000008) 
#define kCanRxDir     ((tCanRegType)0x00000004) 
#define kCanRxOut     ((tCanRegType)0x00000002) 
#define kCanRxIn      ((tCanRegType)0x00000001) 
#if (defined(C_COMP_TI_TMS470)                     )                  && \
     defined(C_PROCESSOR_TI_TMS470PLF521)
/* Enhanced I/O Tx Control Registers (CANTIOCE)   */
/*lint -esym(750, kCanTxESrs,kCanTxEPulDis,kCanTxEOpdr,kCanTxEDir,kCanTxEOut,kCanTxEIn)   */
# define kCanTxESrs     ((tCanRegType)0x00080000) 
# define kCanTxEPsl     ((tCanRegType)0x00040000) 
# define kCanTxEPulDis  ((tCanRegType)0x00020000) 
# define kCanTxEOpdr    ((tCanRegType)0x00010000) 
# define kCanTxEFunc    ((tCanRegType)0x00000008) 
# define kCanTxEDir     ((tCanRegType)0x00000004) 
# define kCanTxEOut     ((tCanRegType)0x00000002) 
# define kCanTxEIn      ((tCanRegType)0x00000001) 

/* Enhanced I/O Rx Control Registers (CANRIOCE)   */
/*lint -esym(750, kCanRxESrs,kCanRxEPulDis,kCanRxEOpdr,kCanRxEDir,kCanRxEOut,kCanRxEIn)   */
# define kCanRxESrs     ((tCanRegType)0x00080000) 
# define kCanRxEPsl     ((tCanRegType)0x00040000) 
# define kCanRxEPulDis  ((tCanRegType)0x00020000) 
# define kCanRxEOpdr    ((tCanRegType)0x00010000) 
# define kCanRxEFunc    ((tCanRegType)0x00000008) 
# define kCanRxEDir     ((tCanRegType)0x00000004) 
# define kCanRxEOut     ((tCanRegType)0x00000002) 
# define kCanRxEIn      ((tCanRegType)0x00000001) 

/* Error Test Control Registers (CANETC)          */
/*lint -esym(750, kCanEtcFe,kCanEtcBe,kCanEtcSa1e,kCanEtcCrce,kCanEtcSe,kCanEtcEnabled,CanEtcFldStd,kCanEtcFldDlc) */
/*lint -esym(750, kCanEtcFldDta,kCanEtcFldCrcFld,kCanEtcFldCrcDel,kCanEtcFldAckSlt,kCanEtcFldAckDel,kCanEtcFldEof,kCanEtcFldExt) */
# define kCanEtcFe         ((tCanRegType)0x01000000)
# define kCanEtcBe         ((tCanRegType)0x00800000)
# define kCanEtcSa1e       ((tCanRegType)0x00400000)
# define kCanEtcCrce       ((tCanRegType)0x00200000)
# define kCanEtcSe         ((tCanRegType)0x00100000)
# define kCanEtcDisable    ((tCanRegType)0x00000500)
# define kCanEtcEnable     ((tCanRegType)0x00000A00)
# define kCanEtcFldStd     ((tCanRegType)0x00001000)
# define kCanEtcFldDlc     ((tCanRegType)0x00002000)
# define kCanEtcFldDta     ((tCanRegType)0x00003000)
# define kCanEtcFldCrcFld  ((tCanRegType)0x00004000)
# define kCanEtcFldCrcDel  ((tCanRegType)0x00005000)
# define kCanEtcFldAckSlt  ((tCanRegType)0x00006000)
# define kCanEtcFldAckDel  ((tCanRegType)0x00007000)
# define kCanEtcFldEof     ((tCanRegType)0x00008000)
# define kCanEtcFldExt     ((tCanRegType)0x00009000)
#endif /* C_PROCESSOR_TI_TMS470PLF521 */


/* Message Identifier Register (CANMID)           */
/*lint -esym(750, kCanIde,kCanAam) */
#define kCanIde       ((vuint32)0x80000000)
#define kCanIdeNeg    ((vuint32)0x7FFFFFFF)
#define kCanAme       ((vuint32)0x40000000)
#define kCanAam       ((vuint32)0x20000000) 

/* Message Control Field Register (CANMCF)        */
#define kCanRtr       ((tCanRegType)0x00000010)


#if defined(C_COMP_TI_TMS470)           
# define kCanNumberOfMaxMailboxes ((tCanRegType)32)
#endif

#if defined(C_COMP_TI_TMS470)           
/* CPSR */
# define kModeBits     ((tCanRegType)0x0000000f)
# define kUserMode     ((tCanRegType)0x00000000)
# define kIrqFlag      ((tCanRegType)0x00000080)
#endif


#define kCanRmpDeletePendingHECC     (tCanRegType)0xFFFFFFFF
#define kCanRmpDeletePendingSCC      (tCanRegType)0x0000FFFF

# if defined( C_ENABLE_TX_OBSERVE ) || \
     defined ( C_ENABLE_CAN_TX_CONF_FCT )
#  define C_ENABLE_OBSERVE_TXCANCELATION
# endif


/***************************************************************************/
/* macros                                                                  */
/***************************************************************************/

#if !(defined( C_HL_DISABLE_RX_INFO_STRUCT_PTR ) || defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR ))
# define C_HL_ENABLE_RX_INFO_STRUCT_PTR
#endif

#if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
# define CAN_HL_P_RX_INFO_STRUCT(channel)                  (pCanRxInfoStruct)  
# define CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)           (pCanRxInfoStruct->Handle)  
#else
# define CAN_HL_P_RX_INFO_STRUCT(channel)                  (&canRxInfoStruct[channel])
# define CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)           (canRxInfoStruct[channel].Handle)  
#endif 


/*disabled - lint -emacro( (572,778), C_RANGE_MATCH) */


#if defined( C_SINGLE_RECEIVE_CHANNEL )
# if (kCanNumberOfUsedCanRxIdTables == 1)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, mask, code) \
                  (  ((idRaw0) & (tCanRxId0)~MK_RX_RANGE_MASK_IDSTD0(mask)) == MK_RX_RANGE_CODE_IDSTD0(code) )
#  define C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, mask, code) \
                  (  ((idRaw0) & (tCanRxId0)~MK_RX_RANGE_MASK_IDEXT0(mask)) == MK_RX_RANGE_CODE_IDEXT0(code) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 2)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDSTD0(mask)) == MK_RX_RANGE_CODE_IDSTD0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDSTD1(mask)) == MK_RX_RANGE_CODE_IDSTD1(code) ) )
#  define C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDEXT0(mask)) == MK_RX_RANGE_CODE_IDEXT0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDEXT1(mask)) == MK_RX_RANGE_CODE_IDEXT1(code) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 3)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDSTD0(mask)) == MK_RX_RANGE_CODE_IDSTD0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDSTD1(mask)) == MK_RX_RANGE_CODE_IDSTD1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDSTD2(mask)) == MK_RX_RANGE_CODE_IDSTD2(code) ) )
#  define C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDEXT0(mask)) == MK_RX_RANGE_CODE_IDEXT0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDEXT1(mask)) == MK_RX_RANGE_CODE_IDEXT1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDEXT2(mask)) == MK_RX_RANGE_CODE_IDEXT2(code) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 4)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDSTD0(mask)) == MK_RX_RANGE_CODE_IDSTD0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDSTD1(mask)) == MK_RX_RANGE_CODE_IDSTD1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDSTD2(mask)) == MK_RX_RANGE_CODE_IDSTD2(code) ) && \
                    ( ((idRaw3) & (tCanRxId3)~ MK_RX_RANGE_MASK_IDSTD3(mask)) == MK_RX_RANGE_CODE_IDSTD3(code) ) )
#  define C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDEXT0(mask)) == MK_RX_RANGE_CODE_IDEXT0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDEXT1(mask)) == MK_RX_RANGE_CODE_IDEXT1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDEXT2(mask)) == MK_RX_RANGE_CODE_IDEXT2(code) ) && \
                    ( ((idRaw3) & (tCanRxId3)~ MK_RX_RANGE_MASK_IDEXT3(mask)) == MK_RX_RANGE_CODE_IDEXT3(code) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 5)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDSTD0(mask)) == MK_RX_RANGE_CODE_IDSTD0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDSTD1(mask)) == MK_RX_RANGE_CODE_IDSTD1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDSTD2(mask)) == MK_RX_RANGE_CODE_IDSTD2(code) ) && \
                    ( ((idRaw3) & (tCanRxId3)~ MK_RX_RANGE_MASK_IDSTD3(mask)) == MK_RX_RANGE_CODE_IDSTD3(code) ) && \
                    ( ((idRaw4) & (tCanRxId4)~ MK_RX_RANGE_MASK_IDSTD4(mask)) == MK_RX_RANGE_CODE_IDSTD4(code) ) )
#  define C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDEXT0(mask)) == MK_RX_RANGE_CODE_IDEXT0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDEXT1(mask)) == MK_RX_RANGE_CODE_IDEXT1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDEXT2(mask)) == MK_RX_RANGE_CODE_IDEXT2(code) ) && \
                    ( ((idRaw3) & (tCanRxId3)~ MK_RX_RANGE_MASK_IDEXT3(mask)) == MK_RX_RANGE_CODE_IDEXT3(code) ) && \
                    ( ((idRaw4) & (tCanRxId4)~ MK_RX_RANGE_MASK_IDEXT4(mask)) == MK_RX_RANGE_CODE_IDEXT4(code) ) )
# endif
#else     /* C_MULTIPLE_RECEIVE_CHANNEL */

# if (kCanNumberOfUsedCanRxIdTables == 1)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH( CAN_RX_IDRAW_PARA, mask, code)    \
                                (  ((idRaw0) & (tCanRxId0)~((mask).Id0)) == ((code).Id0) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 2)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH( CAN_RX_IDRAW_PARA, mask, code)    \
                                ( ( ((idRaw0) & (tCanRxId0)~((mask).Id0)) == ((code).Id0) ) &&\
                                  ( ((idRaw1) & (tCanRxId1)~((mask).Id1)) == ((code).Id1) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 3)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH( CAN_RX_IDRAW_PARA, mask, code)    \
                                ( ( ((idRaw0) & (tCanRxId0)~((mask).Id0)) == ((code).Id0) ) &&\
                                  ( ((idRaw1) & (tCanRxId1)~((mask).Id1)) == ((code).Id1) ) &&\
                                  ( ((idRaw2) & (tCanRxId2)~((mask).Id2)) == ((code).Id2) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 4)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH( CAN_RX_IDRAW_PARA, mask, code)    \
                                ( ( ((idRaw0) & (tCanRxId0)~((mask).Id0)) == ((code).Id0) ) &&\
                                  ( ((idRaw1) & (tCanRxId1)~((mask).Id1)) == ((code).Id1) ) &&\
                                  ( ((idRaw2) & (tCanRxId2)~((mask).Id2)) == ((code).Id2) ) &&\
                                  ( ((idRaw3) & (tCanRxId3)~((mask).Id3)) == ((code).Id3) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 5)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH( CAN_RX_IDRAW_PARA, mask, code)    \
                                ( ( ((idRaw0) & (tCanRxId0)~((mask).Id0)) == ((code).Id0) ) &&\
                                  ( ((idRaw1) & (tCanRxId1)~((mask).Id1)) == ((code).Id1) ) &&\
                                  ( ((idRaw2) & (tCanRxId2)~((mask).Id2)) == ((code).Id2) ) &&\
                                  ( ((idRaw3) & (tCanRxId3)~((mask).Id3)) == ((code).Id3) ) &&\
                                  ( ((idRaw4) & (tCanRxId4)~((mask).Id4)) == ((code).Id4) ) )
# endif
#endif


#if (kCanNumberOfUsedCanRxIdTables == 1)
# define CAN_RX_IDRAW_PARA                                 idRaw0
#endif
#if (kCanNumberOfUsedCanRxIdTables == 2)
# define CAN_RX_IDRAW_PARA                                 idRaw0,idRaw1
#endif
#if (kCanNumberOfUsedCanRxIdTables == 3)
# define CAN_RX_IDRAW_PARA                                 idRaw0,idRaw1,idRaw2
#endif
#if (kCanNumberOfUsedCanRxIdTables == 4)
# define CAN_RX_IDRAW_PARA                                 idRaw0,idRaw1,idRaw2,idRaw3
#endif
#if (kCanNumberOfUsedCanRxIdTables == 5)
# define CAN_RX_IDRAW_PARA                                 idRaw0,idRaw1,idRaw2,idRaw3,idRaw4
#endif


#if defined( C_SINGLE_RECEIVE_CHANNEL )
# define channel                                           ((CanChannelHandle)0)
# define canHwChannel                                      ((CanChannelHandle)0)
# define CAN_HL_HW_CHANNEL_STARTINDEX(channel)             ((CanChannelHandle)0)
# define CAN_HL_HW_CHANNEL_STOPINDEX(channel)              ((CanChannelHandle)0)
# define CAN_HL_HW_MSG_TRANSMIT_INDEX(canHwChannel)        (kCanMsgTransmitObj)
# define CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel)           (kCanHwTxNormalIndex)

/* Offset which has to be added to change the hardware Tx handle into a logical handle, which is unique over all channels */
/*        Tx-Hardware-Handle - CAN_HL_HW_TX_STARTINDEX(canHwChannel) + CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel) */
# define CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)          ((vsintx)0-kCanHwTxStartIndex)

# define CAN_HL_TX_STARTINDEX(channel)                     ((CanTransmitHandle)0)
# define CAN_HL_TX_STAT_STARTINDEX(channel)                ((CanTransmitHandle)0)
# define CAN_HL_TX_DYN_ROM_STARTINDEX(channel)             (kCanNumberOfTxStatObjects)
# define CAN_HL_TX_DYN_RAM_STARTINDEX(channel)             ((CanTransmitHandle)0)
/* # define CAN_HL_RX_STARTINDEX(channel)                     ((CanReceiveHandle)0) */
/* index to access the ID tables - Basic index only for linear search 
   for hash search this is the start index of the ??? */
# define CAN_HL_RX_BASIC_STARTINDEX(channel)               ((CanReceiveHandle)0)
# if defined( C_SEARCH_HASH ) 
#  define CAN_HL_RX_FULL_STARTINDEX(canHwChannel)          ((CanReceiveHandle)0)
# else
#  define CAN_HL_RX_FULL_STARTINDEX(canHwChannel)          (kCanNumberOfRxBasicCANObjects)
# endif
# define CAN_HL_INIT_OBJ_STARTINDEX(channel)               ((vuint8)0)
# define CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel)         ((CanObjectHandle)0)
# define CAN_HL_HW_TX_STARTINDEX(canHwChannel)             (kCanHwTxStartIndex)
# define CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel)        (kCanHwRxFullStartIndex)
# define CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)       (kCanHwRxBasicStartIndex)
# define CAN_HL_HW_UNUSED_STARTINDEX(canHwChannel)         (kCanHwUnusedStartIndex)

# define CAN_HL_TX_STOPINDEX(channel)                      (kCanNumberOfTxObjects)
# define CAN_HL_TX_STAT_STOPINDEX(channel)                 (kCanNumberOfTxStatObjects)
# define CAN_HL_TX_DYN_ROM_STOPINDEX(channel)              (kCanNumberOfTxObjects)
# define CAN_HL_TX_DYN_RAM_STOPINDEX(channel)              (kCanNumberOfTxDynObjects)
/* # define CAN_HL_RX_STOPINDEX(channel)                      (kCanNumberOfRxObjects) */
# define CAN_HL_RX_BASIC_STOPINDEX(channel)                (kCanNumberOfRxBasicCANObjects)
# if defined( C_SEARCH_HASH ) 
#  define CAN_HL_RX_FULL_STOPINDEX(canHwChannel)           (kCanNumberOfRxFullCANObjects)
# else
#  define CAN_HL_RX_FULL_STOPINDEX(canHwChannel)           (kCanNumberOfRxBasicCANObjects+kCanNumberOfRxFullCANObjects)
# endif
# define CAN_HL_INIT_OBJ_STOPINDEX(channel)                (kCanNumberOfInitObjects)
# define CAN_HL_LOG_HW_TX_STOPINDEX(canHwChannel)          (kCanNumberOfUsedTxCANObjects)
# define CAN_HL_HW_TX_STOPINDEX(canHwChannel)              (kCanHwTxStartIndex     +kCanNumberOfUsedTxCANObjects)
# define CAN_HL_HW_RX_FULL_STOPINDEX(canHwChannel)         (kCanHwRxFullStartIndex +kCanNumberOfRxFullCANObjects)
# define CAN_HL_HW_RX_BASIC_STOPINDEX(canHwChannel)        (kCanHwRxBasicStartIndex+kCanNumberOfUsedRxBasicCANObjects)
# define CAN_HL_HW_UNUSED_STOPINDEX(canHwChannel)          (kCanHwUnusedStartIndex +kCanNumberOfUnusedObjects)

#else
#  define canHwChannel                                     channel   /*brackets are not allowed here due to compiler error with Renesas HEW compiler for SH2*/
#  define CAN_HL_HW_CHANNEL_STARTINDEX(channel)            (channel)
#  define CAN_HL_HW_CHANNEL_STOPINDEX(channel)             (channel)

#  define CAN_HL_HW_MSG_TRANSMIT_INDEX(canHwChannel)       (CanHwMsgTransmitIndex[(canHwChannel)])
#  define CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel)          (CanHwTxNormalIndex[(canHwChannel)])
/* Offset which has to be added to change the hardware Tx handle into a logical handle, which is unique over all channels */
/*        Tx-Hardware-Handle - CAN_HL_HW_TX_STARTINDEX(canHwChannel) + CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel) */
#  define CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)         (CanTxOffsetHwToLog[(canHwChannel)])

# define CAN_HL_TX_STARTINDEX(channel)                     (CanTxStartIndex[(channel)])
# define CAN_HL_TX_STAT_STARTINDEX(channel)                (CanTxStartIndex[(channel)])
# define CAN_HL_TX_DYN_ROM_STARTINDEX(channel)             (CanTxDynRomStartIndex[(channel)])
# define CAN_HL_TX_DYN_RAM_STARTINDEX(channel)             (CanTxDynRamStartIndex[(channel)])
/* # define CAN_HL_RX_STARTINDEX(channel)                     (CanRxStartIndex[(channel)]) */
/* index to access the ID tables - Basic index only for linear search */
# define CAN_HL_RX_BASIC_STARTINDEX(channel)               (CanRxBasicStartIndex[(channel)])      
# define CAN_HL_RX_FULL_STARTINDEX(canHwChannel)           (CanRxFullStartIndex[(canHwChannel)])
# define CAN_HL_INIT_OBJ_STARTINDEX(channel)               (CanInitObjectStartIndex[(channel)])      
# define CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel)         (CanLogHwTxStartIndex[(canHwChannel)])
#  define CAN_HL_HW_TX_STARTINDEX(canHwChannel)             (CanHwTxStartIndex[(canHwChannel)])   
#  define CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel)        (CanHwRxFullStartIndex[(canHwChannel)])
#  define CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)       (CanHwRxBasicStartIndex[(canHwChannel)]) 
#  define CAN_HL_HW_UNUSED_STARTINDEX(canHwChannel)         (CanHwUnusedStartIndex[(canHwChannel)])
                                                           
# define CAN_HL_TX_STOPINDEX(channel)                      (CanTxStartIndex[(channel) + 1]) 
# define CAN_HL_TX_STAT_STOPINDEX(channel)                 (CanTxDynRomStartIndex[(channel)])
# define CAN_HL_TX_DYN_ROM_STOPINDEX(channel)              (CanTxStartIndex[(channel) + 1]) 
# define CAN_HL_TX_DYN_RAM_STOPINDEX(channel)              (CanTxDynRamStartIndex[(channel) + 1])
/* # define CAN_HL_RX_STOPINDEX(channel)                      (CanRxStartIndex[(channel) + 1]) */
/* index to access the ID tables - Basic index only for linear search */
# define CAN_HL_RX_BASIC_STOPINDEX(channel)                (CanRxFullStartIndex[CAN_HL_HW_CHANNEL_STARTINDEX(channel)])
# define CAN_HL_INIT_OBJ_STOPINDEX(channel)                (CanInitObjectStartIndex[(channel) + 1])
# define CAN_HL_LOG_HW_TX_STOPINDEX(canHwChannel)          (CanLogHwTxStartIndex[(canHwChannel) +1])      
#  define CAN_HL_HW_TX_STOPINDEX(canHwChannel)              (CanHwTxStopIndex[(canHwChannel)])
#  define CAN_HL_HW_RX_FULL_STOPINDEX(canHwChannel)         (CanHwRxFullStopIndex[(canHwChannel)])
#  define CAN_HL_HW_RX_BASIC_STOPINDEX(canHwChannel)         (CanHwRxBasicStopIndex[(canHwChannel)])
#  define CAN_HL_HW_UNUSED_STOPINDEX(canHwChannel)         (CanHwUnusedStopIndex[(canHwChannel)])

#endif


#if defined( C_SINGLE_RECEIVE_CHANNEL )

# define CANRANGE0ACCMASK(i)                               C_RANGE0_ACC_MASK
# define CANRANGE0ACCCODE(i)                               C_RANGE0_ACC_CODE
# define CANRANGE1ACCMASK(i)                               C_RANGE1_ACC_MASK
# define CANRANGE1ACCCODE(i)                               C_RANGE1_ACC_CODE
# define CANRANGE2ACCMASK(i)                               C_RANGE2_ACC_MASK
# define CANRANGE2ACCCODE(i)                               C_RANGE2_ACC_CODE
# define CANRANGE3ACCMASK(i)                               C_RANGE3_ACC_MASK
# define CANRANGE3ACCCODE(i)                               C_RANGE3_ACC_CODE

/* generated id type of the range */
# define CANRANGE0IDTYPE(i)                                C_RANGE0_IDTYPE
# define CANRANGE1IDTYPE(i)                                C_RANGE1_IDTYPE
# define CANRANGE2IDTYPE(i)                                C_RANGE2_IDTYPE
# define CANRANGE3IDTYPE(i)                                C_RANGE3_IDTYPE

# define APPL_CAN_MSG_RECEIVED( i )                        (APPL_CAN_MSGRECEIVED( i ))

# define APPLCANRANGE0PRECOPY( i )                         (ApplCanRange0Precopy( i ))   
# define APPLCANRANGE1PRECOPY( i )                         (ApplCanRange1Precopy( i ))   
# define APPLCANRANGE2PRECOPY( i )                         (ApplCanRange2Precopy( i ))   
# define APPLCANRANGE3PRECOPY( i )                         (ApplCanRange3Precopy( i ))   

# define APPL_CAN_BUSOFF( i )                              (ApplCanBusOff())
# define APPL_CAN_WAKEUP( i )                              (ApplCanWakeUp())

# if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
#  define APPLCANCANCELNOTIFICATION( i, j )                (APPL_CAN_CANCELNOTIFICATION( j ))
# else
#  define APPLCANCANCELNOTIFICATION( i, j )
# endif
#  define APPLCANMSGCANCELNOTIFICATION( i )

# define CAN_RX_INDEX_TBL(channel,id)                      (CanRxIndexTbl[id])

#else

# define CANRANGE0ACCMASK(i)                               (CanChannelObject[i].RangeMask[0])
# define CANRANGE0ACCCODE(i)                               (CanChannelObject[i].RangeCode[0])
# define CANRANGE1ACCMASK(i)                               (CanChannelObject[i].RangeMask[1])
# define CANRANGE1ACCCODE(i)                               (CanChannelObject[i].RangeCode[1])
# define CANRANGE2ACCMASK(i)                               (CanChannelObject[i].RangeMask[2])
# define CANRANGE2ACCCODE(i)                               (CanChannelObject[i].RangeCode[2])
# define CANRANGE3ACCMASK(i)                               (CanChannelObject[i].RangeMask[3])
# define CANRANGE3ACCCODE(i)                               (CanChannelObject[i].RangeCode[3])

/* generated id type of the range */
# define CANRANGE0IDTYPE(i)                                (CanChannelObject[i].RangeIdType[0])
# define CANRANGE1IDTYPE(i)                                (CanChannelObject[i].RangeIdType[1])
# define CANRANGE2IDTYPE(i)                                (CanChannelObject[i].RangeIdType[2])
# define CANRANGE3IDTYPE(i)                                (CanChannelObject[i].RangeIdType[3])

# define APPL_CAN_MSG_RECEIVED( i )                        (CanChannelObject[(i)->Channel].ApplCanMsgReceivedFct(i))

# define APPLCANRANGE0PRECOPY( i )                         (CanChannelObject[(i)->Channel].ApplCanRangeFct[0](i))
# define APPLCANRANGE1PRECOPY( i )                         (CanChannelObject[(i)->Channel].ApplCanRangeFct[1](i))   
# define APPLCANRANGE2PRECOPY( i )                         (CanChannelObject[(i)->Channel].ApplCanRangeFct[2](i))   
# define APPLCANRANGE3PRECOPY( i )                         (CanChannelObject[(i)->Channel].ApplCanRangeFct[3](i))   

# define APPL_CAN_BUSOFF( i )                              (CanChannelObject[i].ApplCanBusOffFct(i))
# define APPL_CAN_WAKEUP( i )                              (CanChannelObject[i].ApplCanWakeUpFct(i))

# if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
#  define APPLCANCANCELNOTIFICATION( i, j )                (CanChannelObject[i].ApplCanCancelNotificationFct( j ))
# else
#  define APPLCANCANCELNOTIFICATION( i, j )
# endif

#  define APPLCANMSGCANCELNOTIFICATION( i )

# define CAN_RX_INDEX_TBL(channel,id)                      (CanRxIndexTbl[channel][id])

#endif

#ifndef CAN_POLLING_IRQ_DISABLE
# define CAN_POLLING_IRQ_DISABLE(i)                        (CanCanInterruptDisable(i))
#endif
#ifndef CAN_POLLING_IRQ_RESTORE
# define CAN_POLLING_IRQ_RESTORE(i)                        (CanCanInterruptRestore(i))
#endif




/* mask for range enable status */
#define kCanRange0                                         ((vuint16)1)
#define kCanRange1                                         ((vuint16)2)
#define kCanRange2                                         ((vuint16)4)
#define kCanRange3                                         ((vuint16)8)


/* Assertions ----------------------------------------------------------------*/
/*lint -function(exit,ApplCanFatalError)*/

/*lint -emacro( (506), assertUser) */
#if defined( C_ENABLE_USER_CHECK )
# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define assertUser(p,c,e)                                if (!(p))   {ApplCanFatalError(e);}                    /* PRQA S 3412 */
# else
#  define assertUser(p,c,e)                                if (!(p))   {ApplCanFatalError((c),(e));}              /* PRQA S 3412 */
# endif
#else
# define assertUser(p,c,e)
#endif

/*lint -emacro( (506), assertGen) */
#if defined( C_ENABLE_GEN_CHECK )
# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define assertGen(p,c,e)                                 if (!(p))   {ApplCanFatalError(e);}                    /* PRQA S 3412 */
# else
#  define assertGen(p,c,e)                                 if (!(p))   {ApplCanFatalError((c),(e));}              /* PRQA S 3412 */
# endif
#else
# define assertGen(p,c,e)
#endif

/*lint -emacro( (506), assertHardware) */
#if defined( C_ENABLE_HARDWARE_CHECK )
# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define assertHardware(p,c,e)                            if (!(p))   {ApplCanFatalError(e);}                    /* PRQA S 3412 */
# else
#  define assertHardware(p,c,e)                            if (!(p))   {ApplCanFatalError((c),(e));}              /* PRQA S 3412 */
# endif
#else
# define assertHardware(p,c,e)
#endif

/*lint -emacro( (506), assertInternal) */
#if defined( C_ENABLE_INTERNAL_CHECK )
# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define assertInternal(p,c,e)                            if (!(p))   {ApplCanFatalError(e);}                   /* PRQA S 3412 */
# else
#  define assertInternal(p,c,e)                            if (!(p))   {ApplCanFatalError((c),(e));}             /* PRQA S 3412 */
# endif
#else
# define assertInternal(p,c,e)
#endif

#if defined( C_ENABLE_TRANSMIT_QUEUE )
#if defined( C_CPUTYPE_32BIT )
# define kCanTxQueueShift     5
#endif



/* mask used to get the flag index from the handle */
# define kCanTxQueueMask      (((vuint8)1 << kCanTxQueueShift) - (vuint8)1)


#if defined( C_SINGLE_RECEIVE_CHANNEL )
# define CAN_HL_TXQUEUE_PADBITS(channel)             ((CanTransmitHandle)0)
# define CAN_HL_TXQUEUE_STARTINDEX(channel)          ((CanSignedTxHandle)0)
# define CAN_HL_TXQUEUE_STOPINDEX(channel)           ((CanSignedTxHandle)kCanTxQueueSize)
#else
# define CAN_HL_TXQUEUE_PADBITS(channel)             ((CanTransmitHandle)CanTxQueuePadBits[(channel)])
# define CAN_HL_TXQUEUE_STARTINDEX(channel)          (CanTxQueueStartIndex[(channel)])
# define CAN_HL_TXQUEUE_STOPINDEX(channel)           (CanTxQueueStartIndex[(channel) + (CanChannelHandle)1])
#endif


#endif
#if defined(C_COMP_TI_TMS470)           
# if defined(VGEN_GENY)
#  if defined (V_ENABLE_NO_USERMODE)
#   define C_ENABLE_NO_USERMODE
#  endif
#  if defined (V_DISABLE_NO_USERMODE)
#   define C_DISABLE_NO_USERMODE
#  endif
#  if defined(V_ENABLE_PRIVILEGED_DRIVER)
#   define C_ENABLE_PRIVILEGED_DRIVER
#  endif
#  if defined(V_DISABLE_PRIVILEGED_DRIVER)
#   define C_DISABLE_PRIVILEGED_DRIVER
#  endif
#  define CanSwitchToUserMode()             VSwitchToUserMode()       
#  define CanSwitchToPrivilegedMode()       VSwitchToPrivilegedMode() 
#  define CanWriteProtectedRegister(a,m,v)  VWriteProtectedRegister((a) ,(m) ,(v))
# endif
#endif

#if defined(C_COMP_TI_TMS470)           
# define CAN_IS_USERMODE_ACTIVE()  (((vuint32)CanGetCpsr() & kModeBits) == kUserMode) 
#endif

/*lint -e773 no parenthesis around macro*/
#if defined(C_COMP_TI_TMS470)           
# if defined(C_ENABLE_NO_USERMODE)
#  define CAN_WRITE_REGISTER(a,m,v)  ((*(volatile vuint32*)(a)) = (v))
# else
#  if defined(C_ENABLE_PRIVILEGED_DRIVER)
#   define CAN_WRITE_REGISTER(a,m,v) (CanWritePrivileged((a),(v)))
#  else
#   define CAN_WRITE_REGISTER(a,m,v) (CanWriteProtectedRegister((a),(m),(v)))
#  endif
# endif
#endif




#if defined(C_ENABLE_HW_LOOP_TIMER) 
#  define APPLCANTIMERSTART(a) ApplCanTimerStart(CAN_CHANNEL_CANPARA_FIRST (a))
#  define APPLCANTIMERLOOP(a)  ApplCanTimerLoop(CAN_CHANNEL_CANPARA_FIRST (a))
#  define APPLCANTIMEREND(a)   ApplCanTimerEnd(CAN_CHANNEL_CANPARA_FIRST (a))
#else
# define APPLCANTIMERSTART(a)
# define APPLCANTIMEREND(a)
#endif

#define CAN_IS_RX_FULLCAN_PENDING()   ((CANRMP & (tCanRegType)CAN_RX_FULLCAN_OBJ_MASK) != (tCanRegType)0x00000000)
#define CAN_IS_RX_BASICCAN_PENDING()  ((CANRMP & (tCanRegType)CAN_BASICCAN_OBJ_MASK)   != (tCanRegType)0x00000000)


/* BasicCAN Object Mask */

# if defined(C_SINGLE_RECEIVE_CHANNEL)
#  define CAN_BASICCAN_OBJ_MASK            ((vuint32)kCanRxBasicCANObjMask)
# else  /* C_SINGLE_RECEIVE_CHANNEL */
#  define CAN_BASICCAN_OBJ_MASK            ((vuint32)CanRxBasicCANObjMask[channel])
# endif /* C_SINGLE_RECEIVE_CHANNEL */

#define CAN_RX_OBJ_MASK                    (CAN_BASICCAN_OBJ_MASK & CAN_RX_FULLCAN_OBJ_MASK)

#if defined(C_SINGLE_RECEIVE_CHANNEL)
# define CAN_RX_FULLCAN_OBJ_MASK           ((vuint32)kCanRxFullCANObjMask)
#  define CAN_CNTRL_BASIS_ADR(channel)     ((tCanCntrlRegBlock MEMORY_CAN *)(kCanBasisAdr))
#  define CAN_MAILBOX_BASIS_ADR(channel)   ((tCanMailBox MEMORY_CAN *)(kCanMailboxBasisAdr))
#  if defined (C_ENABLE_LAMOFFSETFROMRAM)
#   define CAN_CNTRL_LAM_ADR(channel)      ((tCanLamRegBlock MEMORY_CAN *)(kCanMailboxBasisAdr))
#  else
#   define CAN_CNTRL_LAM_ADR(channel)      ((tCanLamRegBlock MEMORY_CAN *)(kCanBasisAdr))
#  endif
#else /* C_SINGLE_RECEIVE_CHANNEL */



#  define CAN_RX_FULLCAN_OBJ_MASK          ((vuint32)CanRxFullCANObjMask[channel])
#   define CAN_CNTRL_BASIS_ADR(channel)     ((tCanCntrlRegBlock MEMORY_CAN *)(CanBasisAdr[channel]))
#   define CAN_MAILBOX_BASIS_ADR(channel)   ((tCanMailBox MEMORY_CAN *)(CanMailboxBasisAdr[channel]))
#   if defined (C_ENABLE_LAMOFFSETFROMRAM)
#    define CAN_CNTRL_LAM_ADR(channel)      ((tCanLamRegBlock MEMORY_CAN *)(CanMailboxBasisAdr[channel]))
#   else
#    define CAN_CNTRL_LAM_ADR(channel)      ((tCanLamRegBlock MEMORY_CAN *)(CanBasisAdr[channel]))
#   endif

#endif /* C_SINGLE_RECEIVE_CHANNEL */





/*lint -esym(750,CANTRR,CANAA,CANRFP,CANTEC,CANREC,CANLNT,CANTOC,CANTOS,CANGIF1)   */

#define CANME             (CAN_CNTRL_BASIS_ADR(channel) -> CanMe)
#define CANMD             (CAN_CNTRL_BASIS_ADR(channel) -> CanMd)
#define CANTRS            (CAN_CNTRL_BASIS_ADR(channel) -> CanTrs)
#define CANTRR            (CAN_CNTRL_BASIS_ADR(channel) -> CanTrr)
#define CANTA             (CAN_CNTRL_BASIS_ADR(channel) -> CanTa)
#define CANAA             (CAN_CNTRL_BASIS_ADR(channel) -> CanAa)
#define CANRMP            (CAN_CNTRL_BASIS_ADR(channel) -> CanRmp)
#define CANRML            (CAN_CNTRL_BASIS_ADR(channel) -> CanRml)
#define CANRFP            (CAN_CNTRL_BASIS_ADR(channel) -> CanRfp)
#define CANMC             (CAN_CNTRL_BASIS_ADR(channel) -> CanMc)
#define CANES             (CAN_CNTRL_BASIS_ADR(channel) -> CanEs)
#define CANGIM            (CAN_CNTRL_BASIS_ADR(channel) -> CanGim)
#define CANMIM            (CAN_CNTRL_BASIS_ADR(channel) -> CanMim)
#define CANOPC            (CAN_CNTRL_BASIS_ADR(channel) -> CanOpc)
#define CANGIF0           (CAN_CNTRL_BASIS_ADR(channel) -> CanGif0)

#if defined(C_COMP_TI_TMS470)            
#  define CANGAM           (CAN_CNTRL_BASIS_ADR(channel) -> CanGam)
# define CANBTC            (CAN_CNTRL_BASIS_ADR(channel) -> CanBtc)
# define CANTEC            (CAN_CNTRL_BASIS_ADR(channel) -> CanTec)
# define CANREC            (CAN_CNTRL_BASIS_ADR(channel) -> CanRec)
# define CANGIF1           (CAN_CNTRL_BASIS_ADR(channel) -> CanGif1)
# define CANMIL            (CAN_CNTRL_BASIS_ADR(channel) -> CanMil)
# define CANTIOC           (CAN_CNTRL_BASIS_ADR(channel) -> CanTioc)
# define CANRIOC           (CAN_CNTRL_BASIS_ADR(channel) -> CanRioc)
# if (defined(C_COMP_TI_TMS470)                     )                  && \
      defined(C_PROCESSOR_TI_TMS470PLF521)
#  define CANTIOCE         (CAN_CNTRL_BASIS_ADR(channel) -> CanTioce)
#  define CANRIOCE         (CAN_CNTRL_BASIS_ADR(channel) -> CanRioce)
#  define CANETC           (CAN_CNTRL_BASIS_ADR(channel) -> CanEtc)
# endif
# define CANLAMSCC(i)      ((CAN_CNTRL_BASIS_ADR(channel) -> CanLam)[i])
# define CANLAMHECC(i)     ((CAN_CNTRL_LAM_ADR(channel) -> CanLam)[i])
# define CANLNT            (CAN_CNTRL_BASIS_ADR(channel) -> CanLnt)
# define CANTOC            (CAN_CNTRL_BASIS_ADR(channel) -> CanToc)
# define CANTOS            (CAN_CNTRL_BASIS_ADR(channel) -> CanTos)
#endif

#define CANMSGOBJ(i)      (CAN_MAILBOX_BASIS_ADR(channel)[i])








#define CanLL_TxIsHWObjFree( canHwChannel, txObjHandle ) \
        (((CANTRS & CanSlotMask[txObjHandle]) == (tCanRegType)0x00000000) ? kCanTrue : kCanFalse)

#if defined( C_ENABLE_SLEEP_WAKEUP )
# define CanLL_HwIsSleep( CAN_HW_CHANNEL_CANPARA_ONLY)  ((CANES & kCanPda) == kCanPda)
#else
# define CanLL_HwIsSleep( CAN_HW_CHANNEL_CANPARA_ONLY)  (kCanFalse != kCanFalse)  /* avoid misra warning */
#endif


#define CanLL_HwIsStop( CAN_HW_CHANNEL_CANPARA_ONLY ) ((CANES & kCanCce) == kCanCce)

#define CanLL_HwIsBusOff( CAN_HW_CHANNEL_CANPARA_ONLY ) ((CANES & kCanBo) == kCanBo)

#if defined( C_ENABLE_EXTENDED_STATUS )
# define CanLL_HwIsPassive( CAN_HW_CHANNEL_CANPARA_ONLY )  ((CANES & kCanEp) == kCanEp)

# define CanLL_HwIsWarning( CAN_HW_CHANNEL_CANPARA_ONLY )  ((CANES & kCanEw) == kCanEw)
#endif /* C_ENABLE_EXTENDED_STATUS */

/***************************************************************************/
/* Defines / data types / structs / unions                                 */
/***************************************************************************/

#if defined( C_ENABLE_TRANSMIT_QUEUE )
#endif
/* Define CAN Chip hardware; segment must be located in locator file    */
/* register layout of the can chip                                      */
/* Structure describing CAN receive buffer. */

/****************************************************************************/
/* Constants                                                                */
/****************************************************************************/

#if defined( C_ENABLE_TRANSMIT_QUEUE )
/* ROM CATEGORY 1 START*/
/* lookup table for setting the flags in the queue */
V_MEMROM0 static V_MEMROM1 tCanQueueElementType V_MEMROM2 CanShiftLookUp[1 << kCanTxQueueShift] = 
{
#if defined( C_CPUTYPE_32BIT ) 
  (tCanQueueElementType)0x00000001, (tCanQueueElementType)0x00000002, (tCanQueueElementType)0x00000004, (tCanQueueElementType)0x00000008, 
  (tCanQueueElementType)0x00000010, (tCanQueueElementType)0x00000020, (tCanQueueElementType)0x00000040, (tCanQueueElementType)0x00000080
#endif

#if defined( C_CPUTYPE_32BIT ) 
 ,(tCanQueueElementType)0x00000100, (tCanQueueElementType)0x00000200, (tCanQueueElementType)0x00000400, (tCanQueueElementType)0x00000800, 
  (tCanQueueElementType)0x00001000, (tCanQueueElementType)0x00002000, (tCanQueueElementType)0x00004000, (tCanQueueElementType)0x00008000
#endif

#if defined( C_CPUTYPE_32BIT )
 ,(tCanQueueElementType)0x00010000, (tCanQueueElementType)0x00020000, (tCanQueueElementType)0x00040000, (tCanQueueElementType)0x00080000, 
  (tCanQueueElementType)0x00100000, (tCanQueueElementType)0x00200000, (tCanQueueElementType)0x00400000, (tCanQueueElementType)0x00800000,
  (tCanQueueElementType)0x01000000, (tCanQueueElementType)0x02000000, (tCanQueueElementType)0x04000000, (tCanQueueElementType)0x08000000, 
  (tCanQueueElementType)0x10000000, (tCanQueueElementType)0x20000000, (tCanQueueElementType)0x40000000, (tCanQueueElementType)0x80000000
#endif
};

/* returns the highest pending flag from the lower nibble */
V_MEMROM0 static V_MEMROM1 vsint8 V_MEMROM2 CanGetHighestFlagFromNibble[16] =        /* PRQA S 3218 */ /* Misra rule 8.7: only accessed in one function. - depends on configuration */
{    
  (vsint8)-1,                /* (vsint8)0xFF - changed due to misra ; cast due to R32C */
  0x00,
  0x01, 0x01,
  0x02, 0x02, 0x02, 0x02,
  0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
};
/* ROM CATEGORY 1 END*/
#endif
/* Global constants with CAN driver main and subversion */
/* ROM CATEGORY 4 START*/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kCanMainVersion   = (vuint8)(( DRVCAN_TMS470HECCSCCHLL_VERSION ) >> 8);  /*lint !e572 !e778*/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kCanSubVersion    = (vuint8)( DRVCAN_TMS470HECCSCCHLL_VERSION & 0x00FF );
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kCanBugFixVersion = (vuint8)( DRVCAN_TMS470HECCSCCHLL_RELEASE_VERSION );
/* array of masks to access the slots of the different mailboxes */
V_MEMROM0 V_MEMROM1 static tCanRegType V_MEMROM2 CanSlotMask[kCanNumberOfMaxMailboxes] = 
{
  (tCanRegType)0x00000001ul, (tCanRegType)0x00000002ul, (tCanRegType)0x00000004ul, (tCanRegType)0x00000008ul,
  (tCanRegType)0x00000010ul, (tCanRegType)0x00000020ul, (tCanRegType)0x00000040ul, (tCanRegType)0x00000080ul,
  (tCanRegType)0x00000100ul, (tCanRegType)0x00000200ul, (tCanRegType)0x00000400ul, (tCanRegType)0x00000800ul,
  (tCanRegType)0x00001000ul, (tCanRegType)0x00002000ul, (tCanRegType)0x00004000ul, (tCanRegType)0x00008000ul,
  (tCanRegType)0x00010000ul, (tCanRegType)0x00020000ul, (tCanRegType)0x00040000ul, (tCanRegType)0x00080000ul,
  (tCanRegType)0x00100000ul, (tCanRegType)0x00200000ul, (tCanRegType)0x00400000ul, (tCanRegType)0x00800000ul,
  (tCanRegType)0x01000000ul, (tCanRegType)0x02000000ul, (tCanRegType)0x04000000ul, (tCanRegType)0x08000000ul,
  (tCanRegType)0x10000000ul, (tCanRegType)0x20000000ul, (tCanRegType)0x40000000ul, (tCanRegType)0x80000000ul
};

/* ROM CATEGORY 4 END*/

/***************************************************************************/
/* CAN-Hardware Data Definitions                                            */
/***************************************************************************/


/***************************************************************************/
/* external declarations                                                    */
/***************************************************************************/

#if !defined( CANDRV_SET_CODE_TEST_POINT )
# define CANDRV_SET_CODE_TEST_POINT(x)
#else
extern vuint8 tscCTKTestPointState[CTK_MAX_TEST_POINT];       /* PRQA S 3447 */
#endif

/***************************************************************************/
/* global data definitions                                                 */
/***************************************************************************/

/* RAM CATEGORY 1 START*/
volatile CanReceiveHandle canRxHandle[kCanNumberOfChannels];        /* PRQA S 1514 */
/* RAM CATEGORY 1 END*/

/* RAM CATEGORY 3 START*/
#if defined( C_ENABLE_CONFIRMATION_FCT ) && \
    defined( C_ENABLE_DYN_TX_OBJECTS )   && \
    defined( C_ENABLE_TRANSMIT_QUEUE )
CanTransmitHandle          confirmHandle[kCanNumberOfChannels];
#endif
/* RAM CATEGORY 3 END*/

/* RAM CATEGORY 1 START*/
#if defined( C_ENABLE_CONFIRMATION_FLAG )
/* Msg(4:0750) A union type has been used. MISRA Rules 110 - no change */
V_MEMRAM0 volatile V_MEMRAM1_NEAR union CanConfirmationBits V_MEMRAM2_NEAR CanConfirmationFlags;       /* PRQA S 0759 */
#endif

#if defined( C_ENABLE_INDICATION_FLAG )
/* Msg(4:0750) A union type has been used. MISRA Rules 110 - no change */
V_MEMRAM0 volatile V_MEMRAM1_NEAR union CanIndicationBits   V_MEMRAM2_NEAR CanIndicationFlags;         /* PRQA S 0759 */
#endif
/* RAM CATEGORY 1 END*/

/* RAM CATEGORY 1 START*/
#if defined( C_ENABLE_VARIABLE_RX_DATALEN )
/* ##RI1.4 - 3.31: Dynamic Receive DLC */
volatile vuint8 canVariableRxDataLen[kCanNumberOfRxObjects];
#endif
/* RAM CATEGORY 1 END*/

/* RAM CATEGORY 1 START*/
CanChipDataPtr canRDSRxPtr[kCanNumberOfChannels];                  /* PRQA S 1514 */
/* RAM CATEGORY 1 END*/
/* RAM CATEGORY 1 START*/
CanChipDataPtr canRDSTxPtr[kCanNumberOfUsedTxCANObjects];          /* PRQA S 1514 */
/* RAM CATEGORY 1 END*/


/***************************************************************************/
/* local data definitions                                                  */
/***************************************************************************/

/* support for CAN driver features : */
/* RAM CATEGORY 1 START*/
static volatile CanTransmitHandle canHandleCurTxObj[kCanNumberOfUsedTxCANObjects];
/* RAM CATEGORY 1 END*/

/* RAM CATEGORY 2 START*/
#if defined( C_ENABLE_ECU_SWITCH_PASS )
static vuint8 canPassive[kCanNumberOfChannels];
#endif
/* RAM CATEGORY 2 END*/

/* RAM CATEGORY 2 START*/
#if defined( C_ENABLE_CAN_RAM_CHECK )
static vuint8 canComStatus[kCanNumberOfChannels]; /* stores the decision of the App after the last CAN RAM check */
#endif

#if defined( C_ENABLE_DYN_TX_OBJECTS )
static volatile vuint8 canTxDynObjReservedFlag[kCanNumberOfTxDynObjects];

# if defined( C_ENABLE_DYN_TX_ID )
static tCanTxId0 canDynTxId0[kCanNumberOfTxDynObjects];
#  if (kCanNumberOfUsedCanTxIdTables > 1)
static tCanTxId1 canDynTxId1[kCanNumberOfTxDynObjects];
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 2)
static tCanTxId2 canDynTxId2[kCanNumberOfTxDynObjects];
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 3)
static tCanTxId3 canDynTxId3[kCanNumberOfTxDynObjects];
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 4)
static tCanTxId4 canDynTxId4[kCanNumberOfTxDynObjects];
#  endif
#  if defined( C_ENABLE_MIXED_ID )
#   if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#   else
static tCanIdType                 canDynTxIdType[kCanNumberOfTxDynObjects];
#   endif
#  endif
# endif

# if defined( C_ENABLE_DYN_TX_DLC )
static vuint8                   canDynTxDLC[kCanNumberOfTxDynObjects];
# endif
# if defined( C_ENABLE_DYN_TX_DATAPTR )
static vuint8*                  canDynTxDataPtr[kCanNumberOfTxDynObjects];
# endif
# if defined( C_ENABLE_CONFIRMATION_FCT )
# endif 
#endif /* C_ENABLED_DYN_TX_OBJECTS */


#if defined( C_ENABLE_TX_MASK_EXT_ID )
static tCanTxId0 canTxMask0[kCanNumberOfChannels];
# if (kCanNumberOfUsedCanTxIdTables > 1)
static tCanTxId1 canTxMask1[kCanNumberOfChannels];
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
static tCanTxId2 canTxMask2[kCanNumberOfChannels];
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
static tCanTxId3 canTxMask3[kCanNumberOfChannels];
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
static tCanTxId4 canTxMask4[kCanNumberOfChannels];
# endif
#endif

#if defined( C_ENABLE_VARIABLE_DLC )
static vuint8 canTxDLC_RAM[kCanNumberOfTxObjects];
#endif

#if defined( C_HL_ENABLE_COPROCESSOR_SUPPORT )
#else
static volatile vuint8 canStatus[kCanNumberOfChannels];

# if defined( C_ENABLE_PART_OFFLINE )
static vuint8 canTxPartOffline[kCanNumberOfChannels];
# endif
#endif
/* RAM CATEGORY 2 END*/

/* RAM CATEGORY 1 START*/
static vsintx          canCanInterruptCounter[kCanNumberOfChannels];
#if defined( C_HL_ENABLE_CAN_IRQ_DISABLE )
static tCanLLCanIntOld canCanInterruptOldStatus[kCanNumberOfHwChannels];
#endif
/* RAM CATEGORY 1 END*/

#if defined( C_HL_ENABLE_LAST_INIT_OBJ )
/* RAM CATEGORY 4 START*/
static CanInitHandle lastInitObject[kCanNumberOfChannels];
/* RAM CATEGORY 4 END*/
#endif
#if defined( C_ENABLE_TX_POLLING )          || \
    defined( C_ENABLE_RX_FULLCAN_POLLING )  || \
    defined( C_ENABLE_RX_BASICCAN_POLLING ) || \
    defined( C_ENABLE_ERROR_POLLING )       || \
    defined( C_ENABLE_WAKEUP_POLLING )      
/* RAM CATEGORY 2 START*/
static vuint8 canPollingTaskActive[kCanNumberOfChannels];
/* RAM CATEGORY 2 END*/
#endif

/* RAM CATEGORY 1 START*/
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )  || \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
static tCanRxInfoStruct        canRxInfoStruct[kCanNumberOfChannels];
#endif
#if defined( C_ENABLE_CAN_TX_CONF_FCT )
/* ##RI-1.10 Common Callbackfunction in TxInterrupt */
static tCanTxConfInfoStruct    txInfoStructConf[kCanNumberOfChannels];
#endif

#if defined( C_ENABLE_COND_RECEIVE_FCT )
static volatile vuint8 canMsgCondRecState[kCanNumberOfChannels];
#endif

/* RAM CATEGORY 1 END*/

#if defined( C_ENABLE_TRANSMIT_QUEUE )
/* RAM CATEGORY 1 START*/
static volatile tCanQueueElementType canTxQueueFlags[kCanTxQueueSize];
/* RAM CATEGORY 1 END*/
#endif

#if defined( C_ENABLE_CAN_RAM_CHECK )
/* ROM CATEGORY 4 START*/
V_MEMROM0 V_MEMROM1 static vuint32 V_MEMROM2 CanMemCheckValues32bit[3][4] = /* PRQA S 3218 */ /* Misra rule 8.7: const variable has to be declared globally */
{
  { 0xAAAAAAAAul, 0x00000008ul, 0xAAAAAAAAul, 0xAAAAAAAAul }, 
  { 0x55555555ul, 0x00000007ul, 0x55555555ul, 0x55555555ul },
  { 0x00000000ul, 0x00000000ul, 0x00000000ul, 0x00000000ul } 
};


V_MEMROM0 V_MEMROM1 static vuint32 V_MEMROM2 CanMemCheckMasks32bit[4] =     /* PRQA S 3218 */ /* Misra rule 8.7: const variable has to be declared globally */
{
  0xFFFFFFFFul, 0x0000000Ful, 0xFFFFFFFFul, 0xFFFFFFFFul
};
/* ROM CATEGORY 4 END*/
#endif

/* RAM CATEGORY 2 START*/
# if defined (C_ENABLE_RX_FULLCAN_OBJECTS) || defined (C_ENABLE_RX_BASICCAN_OBJECTS)
static tCanTempRamMailBox canTempCanObj[kCanNumberOfChannels];                        /* PRQA S 3218 */ /* Misra rule 8.7: variable declared globally for compatibility reasons */ 
# endif
/* RAM CATEGORY 2 END*/


#  if defined (C_ENABLE_PRETRANSMIT_FCT)
/* RAM CATEGORY 2 START*/
static tCanTempPreTransmitObj canTempPreTransmitObj[kCanNumberOfUsedTxCANObjects];    /* PRQA S 3218 */ /* Misra rule 8.7: variable declared globally for compatibility reasons */
/* RAM CATEGORY 2 END*/
#  endif

#if defined(C_COMP_TI_TMS470)            
# if defined(C_ENABLE_HECC_WORKAROUND_1)
/* RAM CATEGORY 2 START*/
static vuint32 gCANTRS[kCanNumberOfChannels];
/* RAM CATEGORY 2 END*/
# endif /* C_ENABLE_HECC_WORKAROUND_1 */
#endif  /* TMS470 */


/***************************************************************************/
/*  local prototypes                                                       */
/***************************************************************************/
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )  || \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/* CODE CATEGORY 1 START*/
static vuint8 CanHL_ReceivedRxHandle( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 1 END*/
# if defined( C_ENABLE_INDICATION_FLAG ) || \
     defined( C_ENABLE_INDICATION_FCT )
/* CODE CATEGORY 1 START*/
static void CanHL_IndRxHandle( CanReceiveHandle rxHandle );
/* CODE CATEGORY 1 END*/
# endif
#endif
#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/* CODE CATEGORY 1 START*/
static void CanBasicCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle);  
/* CODE CATEGORY 1 END*/
#endif
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/* CODE CATEGORY 1 START*/
static void CanFullCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle);
/* CODE CATEGORY 1 END*/
#endif

/* CODE CATEGORY 1 START*/
static void CanHL_TxConfirmation(CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txObjHandle);
/* CODE CATEGORY 1 END*/
# if defined( C_ENABLE_CAN_TRANSMIT )
/* CODE CATEGORY 1 START*/
static vuint8 CanCopyDataAndStartTransmission(CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txObjHandle, CanTransmitHandle txHandle)  C_API_3;   /*lint !e14 !e31*/
/* CODE CATEGORY 1 END*/
# endif   /* C_ENABLE_CAN_TRANSMIT */

#if defined( C_ENABLE_TRANSMIT_QUEUE )
/* CODE CATEGORY 4 START*/
static void CanDelQueuedObj( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END*/
# if defined( C_ENABLE_TX_POLLING ) 
/* CODE CATEGORY 2 START*/
static void CanHl_RestartTxQueue( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 2 END*/
# endif
#endif 

/* CODE CATEGORY 2 START*/
static void CanHL_ErrorHandling( CAN_HW_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 2 END*/

#if defined( C_ENABLE_VARIABLE_RX_DATALEN )
/* CODE CATEGORY 1 START*/
static void CanSetVariableRxDatalen ( CanReceiveHandle rxHandle, vuint8 dataLen );
/* CODE CATEGORY 1 END*/
#endif


#if defined( C_ENABLE_SLEEP_WAKEUP )
/* CODE CATEGORY 4 START*/
static void CanLL_WakeUpHandling(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END*/
#endif

#if defined(C_COMP_TI_TMS470)           
# if !defined(C_ENABLE_NO_USERMODE)
#  if defined(C_ENABLE_PRIVILEGED_DRIVER)
/* CODE CATEGORY 1 START*/
static void CanWritePrivileged(volatile vuint32* pAddr, vuint32 nVal);
/* CODE CATEGORY 1 END*/
#  endif
# endif
#endif

#if defined( C_ENABLE_CAN_RAM_CHECK )
/* CODE CATEGORY 4 START*/
static vuint8 CanLL_IsMailboxCorrupt(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle hwObjHandle);
/* CODE CATEGORY 4 END*/
#endif


#if ((defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
     (defined( C_ENABLE_RX_FULLCAN_OBJECTS )  && !defined( C_ENABLE_RX_FULLCAN_POLLING  )) || \
      !defined( C_ENABLE_TX_POLLING )        || \
      !defined( C_ENABLE_ERROR_POLLING )     ||\
      !defined( C_ENABLE_WAKEUP_POLLING ))        /* ISR necessary; no pure polling configuration*/
/* CODE CATEGORY 1 START*/
static void CanInterrupt(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 1 END*/
#endif



/***************************************************************************/
/*  Error Check                                                            */
/***************************************************************************/

/***************** error check for Organi process **************************/







/***************** error check for not supported feature  **************************/
#if defined( C_ENABLE_MSG_TRANSMIT )
# error "Low Level Message Transmit is not supported with this CAN driver implementation"
#endif

#if defined( C_ENABLE_INDIVIDUAL_POLLING )
# error "Individual polling is not supported with this CAN driver implementation"
#endif

#if defined( C_ENABLE_MULTIPLE_BASICCAN )
# error "Multiple Basic CAN is not supported with this CAN driver implementation"
#endif

#if defined( C_ENABLE_RX_QUEUE )
# error "Rx Queue is not supported with this CAN driver implementation"
#endif

#if defined( C_ENABLE_COMMON_CAN )
# error "Common CAN is not supported with this CAN driver implementation"
#endif

#if defined( C_ENABLE_MULTI_ECU_CONFIG )
# error "Multiple Configuration is not supported with this CAN driver implementation"
#endif


#if (VSTDLIB__COREHLL_VERSION  <  0x0213 )
# error "Incompatible version of VStdLib. Core Version 2.13.00 or higher is necessary."
#endif


#if defined( C_SEARCH_HASH )
# if !defined( kHashSearchListCountEx )
#  error "kHashSearchListCountEx not defined"
# endif
# if !defined( kHashSearchMaxStepsEx )
#  error "kHashSearchMaxStepsEx not defined"
# endif
# if !defined( kHashSearchListCount )
#  error "kHashSearchListCount not defined"
# endif
# if !defined( kHashSearchMaxSteps )
#  error "kHashSearchMaxSteps not defined"
# endif
# if ( (kHashSearchMaxStepsEx < 1U) ||(kHashSearchMaxStepsEx > 32768U) )
#  error "kHashSearchMaxStepsEx has ilegal value"
# endif
# if ( kHashSearchListCountEx > 32768U )
#  error "Hash table for extended ID is too large"
# endif
# if ( (kHashSearchMaxSteps < 1U) ||(kHashSearchMaxSteps > 32768U) )
#  error "kHashSearchMaxStepsEx has ilegal value"
# endif
# if ( kHashSearchListCount > 32768U )
#  error "Hash table for standard ID is too large"
# endif
# if !defined( C_ENABLE_EXTENDED_ID) && (kHashSearchListCountEx > 0U)
#  error "kHashSearchListCountEx has to be 0 in this configuration"
# endif
# if defined( C_ENABLE_EXTENDED_ID) && !defined( C_ENABLE_MIXED_ID) &&(kHashSearchListCount > 0U)
#  error "kHashSearchListCount has to be 0 in this configuration"
# endif
#endif









/***************************************************************************/
/*  Functions                                                              */
/***************************************************************************/


# if defined( C_ENABLE_MEMCOPY_SUPPORT )
/****************************************************************************
| NAME:             CanCopyFromCan
| CALLED BY:        Application
| PRECONDITIONS:    none
|
| INPUT PARAMETERS: void *             dst        | pointer to destionation buffer
|                   CanChipDataPtr     src        | pointer to CAN buffer
|                   vuint8             len        | number of bytes to copy
|
| RETURN VALUES:    -
|
| DESCRIPTION:      copy data from CAN receive buffer to RAM.
|
| ATTENTION:        
****************************************************************************/
/* Msg(4:3673) The object addressed by the pointer "txMsgStruct" is not modified in this function.
   The use of "const" should be considered to indicate that it never changes. MISRA Rule 81 - no change */
/* CODE CATEGORY 1 START*/
void CanCopyFromCan(void *dst, CanChipDataPtr src, vuint8 len)     /* PRQA S 3673 */      /* suppress message about const pointer */
{
  while ((len--) != 0)   /* PRQA S 3440 */ /* MISRA Rule 12.13: Usage of postincrement/decrement produces more efficient code */
  {
    *((vuint8 *)dst) = *src++;  /* PRQA S 3440, 0489 */ /* MISRA Rule 12.13: Usage of postincrement/decrement produces more efficient code */ /* MISRA Rule 17.4: Pointer arithmetics used for efficient execution */
    dst = ((vuint8 *)dst)+1;    /* PRQA S 0489 */ /* MISRA Rule 17.4: Pointer arithmetics used for efficient execution */
  }
}
/* CODE CATEGORY 1 END*/

/****************************************************************************
| NAME:             CanCopyToCan
| CALLED BY:        Application
| PRECONDITIONS:    none
|
| INPUT PARAMETERS: void *             src        | pointer to source buffer
|                   CanChipDataPtr     dst        | pointer to CAN buffer
|                   vuint8             len        | number of bytes to copy
|
| RETURN VALUES:    -
|
| DESCRIPTION:      copy data from CAN receive buffer to RAM.
|
| ATTENTION:        
****************************************************************************/
/* Msg(4:3673) The object addressed by the pointer "txMsgStruct" is not modified in this function.
   The use of "const" should be considered to indicate that it never changes. MISRA Rule 81 - no change */
/* CODE CATEGORY 1 START*/
void CanCopyToCan(CanChipDataPtr dst, void * src, vuint8 len)       /* PRQA S 3673 */     /* suppress message about const pointer */
{
  while ((len--) != 0)  /* PRQA S 3440 */ /* MISRA Rule 12.13: Usage of postincrement/decrement produces more efficient code */
  {
    *dst++ = *((vuint8 *)src);  /* PRQA S 3440, 0489 */ /* MISRA Rule 12.13: Usage of postincrement/decrement produces more efficient code */ /* MISRA Rule 17.4: Pointer arithmetics used for efficient execution */
    src = ((vuint8 *)src)+1;    /* PRQA S 0489 */ /* MISRA Rule 17.4: Pointer arithmetics used for efficient execution */
  }
}
/* CODE CATEGORY 1 END*/
# endif

# if defined ( C_ENABLE_DRIVER_STATUS )
/************************************************************************
| NAME:             CanGetDriverStatus
| CALLED BY:        Application
| PRECONDITIONS:    none  
| INPUT PARAMETER:  CanChannelHandle   channel    | 
| RETURN VALUE:     kCanDriverBusoff:     CAN Driver is in state Busoff, 
|                                         Init mode is not reached jet.
|                   kCanDriverBusoffInit: Initmode is reached, CanResetBusoffEnd
|                                         can be processed without delay on entry. 
|                   kCanDriverNormal:     Initmode is already left. CanResetBusoffEnd
|                                         can be processed without delay on entry 
|                                         (if not already performed). 
|
| DESCRIPTION:      The API function provide the current state of the 
|                   bus off recovery. This allows to call CanResetBusOffEnd
|                   more early to be able to receive messages as soon 
|                   as possible after Busoff.
*************************************************************************/
/* CODE CATEGORY 4 START*/
vuint8 CanGetDriverStatus(CAN_CHANNEL_CANTYPE_ONLY)
{ 
  vuint8 retvalue;


  /* Update content of CANES register */
  CANES = (CANES & kCanErrorMask);

  if ((CANES & kCanBo) == kCanBo) 
  {
    retvalue = kCanDriverBusoff;
  } 
  else 
  {
    retvalue = kCanDriverBusoffInit;
  }
  return retvalue;
}
/* CODE CATEGORY 4 END*/
# endif /* C_ENABLE_DRIVER_STATUS         */
#if defined( C_ENABLE_SLEEP_WAKEUP ) 
/****************************************************************************
| NAME:             CanLL_WakeUpHandling
| CALLED BY:        CanWakeUpTask() and WakeUp-ISR
| PRECONDITIONS:    none
|
| INPUT PARAMETERS: CanChannelHandle  channel        | current CAN channel
|                   and parameters which are defined in CanLL_WakeUpTaskLocalParameter
|
| RETURN VALUES:    -
|
| DESCRIPTION:      perform wakeup handling.
|
| ATTENTION:        CanLL_WakeUpHandling has to contain:
|                     ApplCanPreWakeUp(CAN_CHANNEL_CANPARA_ONLY);
|                     CanWakeUp(CAN_CHANNEL_CANPARA_ONLY);        - if hardware does not wake up automatically
|                     APPL_CAN_WAKEUP( channel );
|                   In case of CommonCAN, it might be necessary to call CanWakeUp even if the hardware
|                   wakes up automatically to make sure all associated HW channels are awaken.
****************************************************************************/
/* CODE CATEGORY 4 START*/
static void CanLL_WakeUpHandling(CAN_CHANNEL_CANTYPE_ONLY)
{
  CANGIF0 = kCanWuif0;  /* clear the interrupt flag */
# if defined( C_ENABLE_APPLCANPREWAKEUP_FCT )
  ApplCanPreWakeUp(CAN_CHANNEL_CANPARA_ONLY);
# endif
  (void)CanWakeUp(CAN_CHANNEL_CANPARA_ONLY);         /* if hardware does not wake up automatically */
  APPL_CAN_WAKEUP( channel );
}
/* CODE CATEGORY 4 END*/
#endif

# if defined( C_ENABLE_CAN_RAM_CHECK )
/* CODE CATEGORY 4 START*/
static vuint8 CanLL_IsMailboxCorrupt(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle hwObjHandle)
{
  tCanRegType oldCanmeValue;
  tCanRegType tmpCanME;
  vuint8 retval;
  vuint8 i;

  oldCanmeValue = CANME;                           /* save CAN mailbox enable register */
  tmpCanME = CANME & (~CanSlotMask[hwObjHandle]);  /* disable mailbox to be checked */
  CANME = tmpCanME;

  retval = kCanFalse; /* we assume the mailbox is not corrupt */

  /* at this point the mailbox is not initialized therefore the contents are not saved! */
  for(i = 0; i < 3; i++)
  {
    CANMSGOBJ(hwObjHandle).CanMid               = CanMemCheckValues32bit[i][0];
    CANMSGOBJ(hwObjHandle).CanMcf               = CanMemCheckValues32bit[i][1];
    CANMSGOBJ(hwObjHandle).CanMsg.dwords.CanMdl = CanMemCheckValues32bit[i][2];
    CANMSGOBJ(hwObjHandle).CanMsg.dwords.CanMdh = CanMemCheckValues32bit[i][3];

    if( ((CANMSGOBJ(hwObjHandle).CanMid               & CanMemCheckMasks32bit[0]) != CanMemCheckValues32bit[i][0]) ||
        ((CANMSGOBJ(hwObjHandle).CanMcf               & CanMemCheckMasks32bit[1]) != CanMemCheckValues32bit[i][1]) ||
        ((CANMSGOBJ(hwObjHandle).CanMsg.dwords.CanMdl & CanMemCheckMasks32bit[2]) != CanMemCheckValues32bit[i][2]) ||
        ((CANMSGOBJ(hwObjHandle).CanMsg.dwords.CanMdh & CanMemCheckMasks32bit[3]) != CanMemCheckValues32bit[i][3]) )
    {
      retval = kCanTrue; /* the mailbox is corrupt */
      break;
    }
  } 

  CANME = oldCanmeValue; /* restore old CANME value */

  return retval;
}
/* CODE CATEGORY 4 END*/
# endif



#if ((defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
     (defined( C_ENABLE_RX_FULLCAN_OBJECTS )  && !defined( C_ENABLE_RX_FULLCAN_POLLING  )) || \
      !defined( C_ENABLE_TX_POLLING )        || \
      !defined( C_ENABLE_ERROR_POLLING )     ||\
      !defined( C_ENABLE_WAKEUP_POLLING ))        /* ISR necessary; no pure polling configuration*/
/****************************************************************************
| NAME:             CanInterrupt
| CALLED BY:        CanIsr_<physicalChannelIndex>()
| PRECONDITIONS:
| INPUT PARAMETERS: canHwChannel
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service functions according to the CAN controller
|                   interrupt stucture
|                   - check for the interrupt reason ( interrupt source )
|                   - work appropriate interrupt:
|                     + status/error interrupt (busoff, wakeup, error warning)
|                     + basic can receive
|                     + full can receive
|                     + can transmit
|
|                   If an Rx-Interrupt occurs while the CAN controller is in Sleep mode, 
|                   a wakeup has to be generated. 
|
|                   If an Tx-Interrupt occurs while the CAN controller is in Sleep mode, 
|                   an assertion has to be called and the interrupt has to be ignored.
|
|                   The name of BrsTimeStrt...() and BrsTimeStop...() can be addapted to 
|                   realy used name of the interrupt functions.
|
****************************************************************************/
/* CODE CATEGORY 1 START*/
static
void CanInterrupt(CAN_CHANNEL_CANTYPE_ONLY)
{ 
# if !defined(C_ENABLE_TX_POLLING)                                                    || \
      defined(C_ENABLE_RX_BASICCAN_OBJECTS) && !defined(C_ENABLE_RX_BASICCAN_POLLING) || \
      defined(C_ENABLE_RX_FULLCAN_OBJECTS)  && !defined(C_ENABLE_RX_FULLCAN_POLLING)
  cansint16 mb;    /* mailbox iterator */
# endif


# if defined(C_ENABLE_SLEEP_WAKEUP)
  if((CANES & kCanPda) == kCanPda)                        /* check if we are in power down mode */
  {
    return;
  }
# endif


# if defined(C_ENABLE_SLEEP_WAKEUP)  
# else
  assertInternal(( (CANMIL == kCanAllLevel0) && ((CANGIM & kCanI0en) != (tCanRegType)0) ), channel, kErrorWrongInterruptLine);
# endif


# if !defined(C_ENABLE_ERROR_POLLING) 
  CanHL_ErrorHandling(CAN_CHANNEL_CANPARA_ONLY);
# endif

# if defined(C_ENABLE_SLEEP_WAKEUP)
#  if !defined(C_ENABLE_WAKEUP_POLLING)
  if((CANGIF0 & kCanWuif0) != 0)
  {
    CanLL_WakeUpHandling(CAN_CHANNEL_CANPARA_ONLY);
  } 
#  endif
# endif


# if !defined(C_ENABLE_TX_POLLING)
  {
    mb = (cansint16)(CAN_HL_HW_TX_STOPINDEX(channel) - 1);
#  if defined(C_ENABLE_CANCEL_IN_HW)
    while((mb >= CAN_HL_HW_TX_STARTINDEX(channel)) && ((CANTA | CANAA) != (tCanRegType)0x00000000))
    {
      if( ( (CANTA & CanSlotMask[mb]) != (tCanRegType)0 ) || ( (CANAA & CanSlotMask[mb]) != (tCanRegType)0) ) /* if successful transmitted or aborted */
#  else
    while((mb >= (cansint16)CAN_HL_HW_TX_STARTINDEX(channel)) && (CANTA != (tCanRegType)0x00000000))
    {
      if( (CANTA & CanSlotMask[mb]) != (tCanRegType)0)
#  endif
      {
        CanHL_TxConfirmation(CAN_CHANNEL_CANPARA_FIRST (CanObjectHandle)mb);
      }                     
      mb--;
    }
  }
# endif
# if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
#  if !defined(C_ENABLE_RX_FULLCAN_POLLING)
  mb = (cansint16)(CAN_HL_HW_RX_FULL_STOPINDEX(channel) - 1); 
  while((mb >= (cansint16)CAN_HL_HW_RX_FULL_STARTINDEX(channel)) && CAN_IS_RX_FULLCAN_PENDING())
  {
    if((CANRMP & CanSlotMask[mb]) != (tCanRegType)0)
    {
      CanFullCanMsgReceived(CAN_CHANNEL_CANPARA_FIRST (CanObjectHandle)mb);
    }                     
    mb--;
  }
#  endif
# endif
# if defined(C_ENABLE_RX_BASICCAN_OBJECTS)
#  if !defined(C_ENABLE_RX_BASICCAN_POLLING)
  mb = (cansint16)(CAN_HL_HW_RX_BASIC_STOPINDEX(channel) - 1); 
  while((mb >= (cansint16)CAN_HL_HW_RX_BASIC_STARTINDEX(channel)))
  {
    if((CANRMP & CanSlotMask[mb]) != (tCanRegType)0)
    {
      CanBasicCanMsgReceived(CAN_CHANNEL_CANPARA_FIRST (CanObjectHandle)mb);
    }                     
    mb--;
  }
#  endif
# endif
}
/* CODE CATEGORY 1 END*/
#endif



#if defined(C_COMP_TI_TMS470)          
# if !defined(C_ENABLE_NO_USERMODE)
#  if defined(C_ENABLE_PRIVILEGED_DRIVER)
/* CODE CATEGORY 1 START*/
/****************************************************************************
| NAME:             CanWritePrivileged
| CALLED BY:        different functions accessing protected registers
| PRECONDITIONS:    none
|
| INPUT PARAMETERS: pAddr: Address of the register to be written
|                   nVal: Value to be written
|
| RETURN VALUES:    none
|
| DESCRIPTION:      Writes data to a protected register
****************************************************************************/
static void CanWritePrivileged(volatile vuint32* pAddr, vuint32 nVal)
{
  CanDeclareGlobalInterruptOldStatus;
  CanNestedGlobalInterruptDisable();
  
  if(CAN_IS_USERMODE_ACTIVE())
  {
    CanSwitchToPrivilegedMode();   /* switch to systemmode */
    (*(vuint32*)pAddr) = nVal;     /* PRQA S 0312 */ /* MISRA Rule 11.5: Volatile qualifier not required */
    CanSwitchToUserMode();         /* restore usermode  */
  }  
  else
  {
    (*(vuint32*)pAddr) = nVal;     /* PRQA S 0312 */ /* MISRA Rule 11.5: Volatile qualifier not required */
  } 
  CanNestedGlobalInterruptRestore();
}
/* CODE CATEGORY 1 END*/
#  endif
# endif
#endif

#if ((defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
     (defined( C_ENABLE_RX_FULLCAN_OBJECTS )  && !defined( C_ENABLE_RX_FULLCAN_POLLING  )) || \
      !defined( C_ENABLE_TX_POLLING )        || \
      !defined( C_ENABLE_ERROR_POLLING )     ||\
      !defined( C_ENABLE_WAKEUP_POLLING ))        /* ISR necessary; no pure polling configuration*/
/* CODE CATEGORY 1 START*/
/****************************************************************************
| NAME:             CanIsr_0
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service functions according to the CAN controller
|                   interrupt stucture
|
|  Attention:  <Name> has to be repleased with the name of the ISR. 
|              Naming conventions: with Name = "","Rx","Tx","RxTx","Wakeup","Status" 
|  The name of the ISR will always have a channel index at the end. Even in single channel
|  systems.
****************************************************************************/
# if defined( kCanPhysToLogChannelIndex_0 )
#  if defined( C_ENABLE_OSEK_OS ) && \
      defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconstant configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsr_0 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && \
      defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconstant configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
CAN_IRQ_FUNC_QUAL1 void CAN_IRQ_FUNC_QUAL2 CanIsr_0( void )
#  endif /* C_ENABLE_OSEK_OS */
{

  CanInterrupt(kCanPhysToLogChannelIndex_0);     /* call Interrupthandling with logical channel */


} /* END OF CanISR */
# endif /* (kCanPhysToLogChannelIndex_0) */
/****************************************************************************
| NAME:             CanIsr_1
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service functions according to the CAN controller
|                   interrupt stucture
|
|  Attention:  <Name> has to be repleased with the name of the ISR. 
|              Naming conventions: with Name = "","Rx","Tx","RxTx","Wakeup","Status" 
|  The name of the ISR will always have a channel index at the end. Even in single channel
|  systems.
****************************************************************************/
# if defined( kCanPhysToLogChannelIndex_1 )
#  if defined( C_ENABLE_OSEK_OS ) && \
      defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_1Cat)
#    if (osdIsrCanIsr_1Cat != 2)
#     error "inconstant configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsr_1 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && \
      defined (osdIsrCanIsr_1Cat)
#    if (osdIsrCanIsr_1Cat != 1)
#     error "inconstant configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
CAN_IRQ_FUNC_QUAL1 void CAN_IRQ_FUNC_QUAL2 CanIsr_1( void )
#  endif /* C_ENABLE_OSEK_OS */
{

  CanInterrupt(kCanPhysToLogChannelIndex_1);     /* call Interrupthandling with logical channel */


} /* END OF CanISR */
# endif /* (kCanPhysToLogChannelIndex_1) */
/****************************************************************************
| NAME:             CanIsr_2
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service functions according to the CAN controller
|                   interrupt stucture
|
|  Attention:  <Name> has to be repleased with the name of the ISR. 
|              Naming conventions: with Name = "","Rx","Tx","RxTx","Wakeup","Status" 
|  The name of the ISR will always have a channel index at the end. Even in single channel
|  systems.
****************************************************************************/
# if defined( kCanPhysToLogChannelIndex_2 )
#  if defined( C_ENABLE_OSEK_OS ) && \
      defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_2Cat)
#    if (osdIsrCanIsr_2Cat != 2)
#     error "inconstant configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsr_2 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && \
      defined (osdIsrCanIsr_2Cat)
#    if (osdIsrCanIsr_2Cat != 1)
#     error "inconstant configuration of Osek-OS interrupt categorie between CANgen and OIL-configurator (CanIsr)"
#    endif
#   endif
CAN_IRQ_FUNC_QUAL1 void CAN_IRQ_FUNC_QUAL2 CanIsr_2( void )
#  endif /* C_ENABLE_OSEK_OS */
{

  CanInterrupt(kCanPhysToLogChannelIndex_2);     /* call Interrupthandling with logical channel */


} /* END OF CanISR */
# endif /* (kCanPhysToLogChannelIndex_2) */
/* CODE CATEGORY 1 END*/

#endif  /* Not a pure polling configuration */


/****************************************************************************
| NAME:             CanInit
| CALLED BY:        CanInitPowerOn(), Network management
| PRECONDITIONS:    none
| INPUT PARAMETERS: Handle to initstructure
| RETURN VALUES:    none
| DESCRIPTION:      initialization of chip-hardware
|                   initialization of receive and transmit message objects
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanInit( CAN_CHANNEL_CANTYPE_FIRST CanInitHandle initObject )     /* PRQA S 1505 */
{
#if defined( C_ENABLE_CAN_RAM_CHECK )
  vuint8                 canRamCheckStatus;
#endif
  CanObjectHandle        hwObjHandle;
#if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION ) 
  CanTransmitHandle      txHandle;
#endif
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
  CanReceiveHandle       rxHandle;
#endif
  CanObjectHandle        logTxObjHandle;

  tCanRegType tmpCanMC;
  tCanRegType tmpCanMD;
  tCanRegType tmpCanME;
  tCanRegType tmpCanMIM;
  tCanRegType tmpCanGIM;

#if defined( C_HL_ENABLE_LAST_INIT_OBJ )  
  lastInitObject[channel] = initObject;
#endif

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
/* Msg(4:3759) Implicit conversion: int to unsigned short. MISRA Rule 43 - no change in RI 1.4 */
  initObject  += CAN_HL_INIT_OBJ_STARTINDEX(channel);
#endif


#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#endif
  assertUser(initObject < kCanNumberOfInitObjects, channel, kErrorInitObjectHdlTooLarge);    /* PRQA S 3109 */
  assertUser(initObject < CAN_HL_INIT_OBJ_STOPINDEX(channel), channel, kErrorInitObjectHdlTooLarge);     /* PRQA S 3109 */

#if defined( C_ENABLE_CAN_RAM_CHECK )
  canRamCheckStatus = kCanRamCheckOk;
#endif

  {

    tmpCanGIM = 0;
    CAN_WRITE_REGISTER(&CANTIOC, (tCanRegType)0xFFFFFFFF, kCanTxFunc);
    CAN_WRITE_REGISTER(&CANRIOC, (tCanRegType)0xFFFFFFFF, kCanRxFunc);
    #if (defined(C_COMP_TI_TMS470)                     )                  && \
         defined(C_PROCESSOR_TI_TMS470PLF521)
    CAN_WRITE_REGISTER(&CANTIOCE, (tCanRegType)0xFFFFFFFF, (tCanRegType)(kCanTxEPsl | kCanTxEFunc));
    CAN_WRITE_REGISTER(&CANRIOCE, (tCanRegType)0xFFFFFFFF, (tCanRegType)(kCanRxEPsl | kCanRxEFunc));
    CAN_WRITE_REGISTER(&CANETC, (tCanRegType)0xFFFFFFFF, kCanEtcDisable);
    #endif
    tmpCanMC = kCanCcr;
    CAN_WRITE_REGISTER(&CANMC, (tCanRegType)0xFFFFFFFF, tmpCanMC);   /* set change configuration request */
    APPLCANTIMERSTART(kCanLoopWaitConfigChangeEnable);
    while((CANES & kCanCce) != kCanCce)
    {
    #if defined(C_ENABLE_HW_LOOP_TIMER)
      if(0 == APPLCANTIMERLOOP(kCanLoopWaitConfigChangeEnable))
      {
        APPLCANTIMEREND(kCanLoopWaitConfigChangeEnable);
    # if defined(C_COMP_TI_TMS470)           
        /* disconnect the CAN controller from the bus in case the initialization failed */
        CAN_WRITE_REGISTER(&CANTIOC, (tCanRegType)0xFFFFFFFF, (tCanRegType)0x00000000);
        CAN_WRITE_REGISTER(&CANRIOC, (tCanRegType)0xFFFFFFFF, (tCanRegType)0x00000000);
    # endif
        return;
      }
      else
    #endif
      {
        ; /* wait until CAN controller allows configuration access */
      }
    }
    APPLCANTIMEREND(kCanLoopWaitConfigChangeEnable);
    /* software reset to flush all CAN registers -> kCanSres bit is reset automatically by hardware */
    CAN_WRITE_REGISTER(&CANMC, (tCanRegType)0xFFFFFFFF, (tCanRegType)(tmpCanMC | kCanSres)); 
    #if defined (C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC)
    /*
    If the SCC is used the lower three mailboxes are configured as BasicCANs, because
    the first acceptance mask (LAM0) is used for these three mailboxes.
    In HECC mode every mailbox has its own acceptance mask, therefore in HECC mode
    there are only two BasicCAN mailboxes.
    */
    # if defined(C_SINGLE_RECEIVE_CHANNEL)
    #  if(kCanControllerMode == kCanSCCMode)
    tmpCanMC &= ~kCanScm;   /* activate SCC mode */
    #  else
    tmpCanMC |= kCanScm;   /* activate HECC mode */
    #  endif
    # else
    if(CanControllerMode[channel] == kCanSCCMode)
    {
      tmpCanMC &= ~kCanScm;   /* activate SCC mode */
    }
    else
    {
      tmpCanMC |= kCanScm;   /* activate HECC mode */
    }
    # endif
    #else    /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
    tmpCanMC |= kCanScm;   /* activate HECC mode */
    #endif   /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
    /* initialize the temporary variables with the register values */
    tmpCanMD = CANMD;
    tmpCanME = CANME;
    
    #if defined (C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC)
    # if defined(C_SINGLE_RECEIVE_CHANNEL)
    #  if(kCanControllerMode == kCanSCCMode)
    CANOPC = (tCanRegType)0x00000006; 
    #  else  /* kCanSCCMode */
    CANOPC = (tCanRegType)0x00000002;
    #  endif /* kCanSCCMode */
    # else  /* C_SINGLE_RECEIVE_CHANNEL */
    if(CanControllerMode[channel] == kCanSCCMode)
    {
      CANOPC = (tCanRegType)0x00000006;
    }
    else
    {
      CANOPC = (tCanRegType)0x00000002;
    }
    # endif /* C_SINGLE_RECEIVE_CHANNEL */
    #else
    CANOPC = (tCanRegType)0x00000002;
    #endif
    
    /* if TSeg1 or TSeg2 are equal to 0 the CAN controller will not leave config mode! */
    assertGen(((CanInitBTC[initObject] & kCanTSegMask) > (vuint32)0), channel, kErrorWrongTSegValue);
    /* set bus timing register */
    CAN_WRITE_REGISTER(&CANBTC, (tCanRegType)0xFFFFFFFF, (tCanRegType)CanInitBTC[initObject]);
    CANMIL = (vuint32)kCanAllLevel0;    /* all mailbox IRQs on level 0 */
    CAN_WRITE_REGISTER(&CANMIM, (tCanRegType)0xFFFFFFFF, (tCanRegType)0x00000000);    /* disable IRQs for all mailboxes */
    tmpCanMIM = (tCanRegType)0x00000000;
    CANME     = kCanDisableAllObj;                                     /* disable all mailboxes to have write access */
    tmpCanME  = kCanDisableAllObj;
    
    /* Init Tx-Objects -------------------------------------------------------- */
    /* init saved Tx handles: */                   
    /* in case of CommonCAN, transmission is always on the frist HW channel of a CommonCAN channel */
    {
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
      assertGen( (vsintx)CAN_HL_HW_TX_STOPINDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel) 
                 == CAN_HL_LOG_HW_TX_STOPINDEX(canHwChannel), channel, kErrorHwToLogTxObjCalculation);          /* PRQA S 3109 */
      assertGen( (vsintx)CAN_HL_HW_TX_STARTINDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel) 
                 == CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel), channel, kErrorHwToLogTxObjCalculation);         /* PRQA S 3109 */
      assertGen( CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel) <= CAN_HL_LOG_HW_TX_STOPINDEX(canHwChannel), channel, kErrorHwToLogTxObjCalculation);  /* PRQA S 3109 */
#endif
  
      for (hwObjHandle=CAN_HL_HW_TX_STARTINDEX(canHwChannel); hwObjHandle<CAN_HL_HW_TX_STOPINDEX(canHwChannel); hwObjHandle++ )     /*lint !e661*/
      {
        logTxObjHandle = (CanObjectHandle)((vsintx)hwObjHandle + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));     /*lint !e661*/

#if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION ) 
        if((canStatus[channel] & kCanHwIsInit) == kCanHwIsInit)                    /*lint !e661*/
        {
          /* inform application, if a pending transmission is canceled */
          txHandle = canHandleCurTxObj[logTxObjHandle];

# if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
          if( txHandle < kCanNumberOfTxObjects )
          {
            APPLCANCANCELNOTIFICATION(channel, txHandle);
          }
# endif
        }
#endif

        canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;                   /* MsgObj is free */

#if defined( C_ENABLE_CAN_RAM_CHECK )
        if(kCanTrue == CanLL_IsMailboxCorrupt(CAN_HW_CHANNEL_CANPARA_FIRST hwObjHandle))
        {
# if defined( C_ENABLE_NOTIFY_CORRUPT_MAILBOX )
          ApplCanCorruptMailbox(CAN_CHANNEL_CANPARA_FIRST hwObjHandle);
# endif
          canRamCheckStatus = kCanRamCheckFailed;
        }
#endif

        tmpCanMD &= ~CanSlotMask[hwObjHandle]; /* set to Tx */
        tmpCanME |= CanSlotMask[hwObjHandle];  /* enable mailbox */
        CANMSGOBJ(hwObjHandle).CanMid = 0;
        
        #if defined(C_ENABLE_TX_POLLING)
        tmpCanMIM &= ~CanSlotMask[hwObjHandle];
        #else
        tmpCanMIM |= CanSlotMask[hwObjHandle]; 
        #endif
      }

    }

    /* init unused msg objects ------------------------------------------------ */
    for (hwObjHandle=CAN_HL_HW_UNUSED_STARTINDEX(canHwChannel); hwObjHandle<CAN_HL_HW_UNUSED_STOPINDEX(canHwChannel); hwObjHandle++ )  /*lint !e661 !e681*/
    {
      tmpCanME &= ~CanSlotMask[hwObjHandle];
    }


#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
    /* init full can receive msg objects: ------------------------------------- */
    for (hwObjHandle=CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel); hwObjHandle<CAN_HL_HW_RX_FULL_STOPINDEX(canHwChannel); hwObjHandle++ )
    {
      /* brackets to avoid lint info 834 */
      rxHandle = (hwObjHandle-CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel))+CAN_HL_RX_FULL_STARTINDEX(canHwChannel);

#if defined( C_ENABLE_CAN_RAM_CHECK )
      if(kCanTrue == CanLL_IsMailboxCorrupt(CAN_HW_CHANNEL_CANPARA_FIRST hwObjHandle))
      {
# if defined( C_ENABLE_NOTIFY_CORRUPT_MAILBOX )
        ApplCanCorruptMailbox(CAN_CHANNEL_CANPARA_FIRST hwObjHandle);
# endif
        canRamCheckStatus = kCanRamCheckFailed;
      }
#endif

      #if defined (C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC)
      /*
         The acceptance mask for the FullCAN is set to must match. If it is a SCC
         controller LAM3 and GAM are set only otherwise every mailbox specific LAM register
      */
      # if defined(C_SINGLE_RECEIVE_CHANNEL)
      #  if(kCanControllerMode == kCanSCCMode)
      #   if defined( C_ENABLE_RX_MASK_EXT_ID )    
      CANLAMSCC(3) = ((vuint32)MK_EXTID0(~C_MASK_EXT_ID)) & ((vuint32)0x1FFFFFFF);
      CANGAM    = ((vuint32)MK_EXTID0(~C_MASK_EXT_ID)) & ((vuint32)0x1FFFFFFF);
      #   else
      CANLAMSCC(3) = (vuint32)0x00000000;
      CANGAM    = (vuint32)0x00000000;
      #   endif
      #  else
      #   if defined(C_ENABLE_RX_MASK_EXT_ID)
      if((((vuint32)((CanGetRxId0(rxHandle)))) & kCanIdTypeExt) == kCanIdTypeExt)
      {
        CANLAMHECC(hwObjHandle) = ((vuint32)MK_EXTID0(~C_MASK_EXT_ID)) & ((vuint32)0x1FFFFFFF);
      }
      else
      #   endif
      {
        CANLAMHECC(hwObjHandle) = (vuint32)0x00000000;
      }
      #  endif
      # else /* C_SINGLE_RECEIVE_CHANNEL */
      if(CanControllerMode[channel] == kCanSCCMode)
      {
      #  if defined(C_ENABLE_RX_MASK_EXT_ID)
        CANLAMSCC(3) = ((vuint32)MK_EXTID0(~C_MASK_EXT_ID)) & ((vuint32)0x1FFFFFFF);
        CANGAM    = ((vuint32)MK_EXTID0(~C_MASK_EXT_ID)) & ((vuint32)0x1FFFFFFF);
      #  else
        CANLAMSCC(3) = (vuint32)0x00000000;
        CANGAM    = (vuint32)0x00000000;
      #  endif
      }
      else
      {
      #  if defined(C_ENABLE_RX_MASK_EXT_ID)
        if((((vuint32)((CanGetRxId0(rxHandle)))) & kCanIdTypeExt) == kCanIdTypeExt)
        {  
          CANLAMHECC(hwObjHandle) = ((vuint32)MK_EXTID0(~C_MASK_EXT_ID)) & ((vuint32)0x1FFFFFFF);
        }    
        else
      #  endif
        {   
          CANLAMHECC(hwObjHandle) = (vuint32)0x00000000;
        }    
      }
      # endif /* C_SINGLE_RECEIVE_CHANNEL */
      
      #else /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
      
      # if defined(C_ENABLE_RX_MASK_EXT_ID)
      if((((vuint32)((CanGetRxId0(rxHandle)))) & kCanIdTypeExt) == kCanIdTypeExt)
      {  
        CANLAMHECC(hwObjHandle) = ((vuint32)MK_EXTID0(~C_MASK_EXT_ID)) & ((vuint32)0x1FFFFFFF);
      }    
      else
      # endif /* C_ENABLE_RX_MASK_EXT_ID */
      {  
        CANLAMHECC(hwObjHandle) = (vuint32)0x00000000;
      }    
      #endif /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
      
      
      
      
      tmpCanMD |= CanSlotMask[hwObjHandle];        /* set to Rx */
      # if !defined(C_ENABLE_RX_FULLCAN_POLLING)
      tmpCanMIM |= CanSlotMask[hwObjHandle];       /* mailbox generates interrupts on events */
      # endif
      
      
      
      #if defined (C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC)
      # if defined(C_SINGLE_RECEIVE_CHANNEL)
      #  if(kCanControllerMode == kCanSCCMode)
      #   if defined( C_ENABLE_RX_MASK_EXT_ID )    
      CANMSGOBJ(hwObjHandle).CanMid = (vuint32)((CanGetRxId0(rxHandle)) | kCanAme); /* SCC uses acceptance mask for Rx masking */
      #   else
      CANMSGOBJ(hwObjHandle).CanMid = (vuint32)((CanGetRxId0(rxHandle))); /* Acceptance mask is not used! */
      #   endif
      #  else
      CANMSGOBJ(hwObjHandle).CanMid = (vuint32)((CanGetRxId0(rxHandle)) | kCanAme); /* HECC uses acceptance mask */
      #  endif
      # else /* C_SINGLE_RECEIVE_CHANNEL */
      if(CanControllerMode[channel] == kCanSCCMode)
      {
      #  if defined( C_ENABLE_RX_MASK_EXT_ID )    
        CANMSGOBJ(hwObjHandle).CanMid = (vuint32)((CanGetRxId0(rxHandle)) | kCanAme); /* SCC uses acceptance mask for Rx masking */
      #  else
        CANMSGOBJ(hwObjHandle).CanMid = (vuint32)((CanGetRxId0(rxHandle))); /* Acceptance mask is not used! */
      #  endif
      }
      else
      {
        CANMSGOBJ(hwObjHandle).CanMid = (vuint32)((CanGetRxId0(rxHandle)) | kCanAme);
      }
      # endif /* C_SINGLE_RECEIVE_CHANNEL */
      
      #else   /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
      
      CANMSGOBJ(hwObjHandle).CanMid = (vuint32)((CanGetRxId0(rxHandle)) | kCanAme);
      
      #endif  /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
      
      tmpCanME |= CanSlotMask[hwObjHandle];        /* enable mailbox */
    }
#endif

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
    /* init basic can receive msg object: ------------------------------------- */
    for (hwObjHandle=CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel); hwObjHandle<CAN_HL_HW_RX_BASIC_STOPINDEX(canHwChannel); hwObjHandle++ )
    {
#if defined( C_ENABLE_CAN_RAM_CHECK )
      if(kCanTrue == CanLL_IsMailboxCorrupt(CAN_HW_CHANNEL_CANPARA_FIRST hwObjHandle))
      {
# if defined( C_ENABLE_NOTIFY_CORRUPT_MAILBOX )
        ApplCanCorruptMailbox(CAN_CHANNEL_CANPARA_FIRST hwObjHandle);
# endif
        canRamCheckStatus = kCanRamCheckFailed;
      }
#endif

      /* the LL driver has to know which ID tpyes have to be received by which object */
      
      tmpCanMD |= CanSlotMask[hwObjHandle];                                         /* set to Rx */
      
      /* Write acceptance mask depending on controller mode */
      # if defined (C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC)
      #  if defined(C_SINGLE_RECEIVE_CHANNEL)
      #   if(kCanControllerMode == kCanSCCMode)
      CANLAMSCC(0) = (vuint32)CanInitLAM0[initObject];             /* set acceptance mask */
      #   else
      CANLAMHECC(hwObjHandle) = (vuint32)CanInitLAM0[initObject];   /* set acceptance mask */
      #   endif
      #  else  /* C_SINGLE_RECEIVE_CHANNEL */
      if(CanControllerMode[channel] == kCanSCCMode)
      {
        CANLAMSCC(0) = (vuint32)CanInitLAM0[initObject];           /* set acceptance mask */
      }
      else
      {
        CANLAMHECC(hwObjHandle) = (vuint32)CanInitLAM0[initObject]; /* set acceptance mask */
      }
      #  endif /* C_SINGLE_RECEIVE_CHANNEL */
      # else  /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
      CANLAMHECC(hwObjHandle) = (vuint32)CanInitLAM0[initObject];           /* set acceptance mask */
      # endif /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
      
      
      /* Write Code to message objects ID register */
      CANMSGOBJ(hwObjHandle).CanMid = (vuint32)CanInitMID1[initObject] | kCanAme; /* set code register   */
      
      # if !defined(C_ENABLE_RX_BASICCAN_POLLING)
      tmpCanMIM |= CanSlotMask[hwObjHandle];   /* mailbox generates interrupts on events */
      # endif
      tmpCanME |= CanSlotMask[hwObjHandle];    /* enable mailbox */
    }
#endif
                     
    tmpCanGIM = 0;
    
    #if defined(C_ENABLE_SLEEP_WAKEUP)
    # if !defined(C_ENABLE_WAKEUP_POLLING)
    tmpCanGIM |= kCanWuim;
    # endif
    #endif
    
    #if !defined(C_ENABLE_ERROR_POLLING)
    /* overrun is polled within the receive function */
    tmpCanGIM |= kCanBoim; /* enable bus off interrupt */
    #endif
    #if !defined(C_ENABLE_TX_POLLING)
    # if defined(C_ENABLE_CANCEL_IN_HW)
    tmpCanGIM |= kCanAaim; /* enable abort acknowledge interrupt */
    # endif
    #endif
    
    
    #if !defined(C_ENABLE_TX_POLLING)          || \
        !defined(C_ENABLE_RX_FULLCAN_POLLING)  || \
        !defined(C_ENABLE_RX_BASICCAN_POLLING) || \
        !defined(C_ENABLE_ERROR_POLLING)       || \
        !defined(C_ENABLE_WAKEUP_POLLING)
    tmpCanGIM |= kCanI0en; /* enable all CAN interrupts */
    #endif
    /* now set the register values using 32 bit accesses */
    CANMD  = tmpCanMD;  
    CANME  = tmpCanME; 
    CAN_WRITE_REGISTER(&CANMIM, (vuint32)0xFFFFFFFF, tmpCanMIM);
    CAN_WRITE_REGISTER(&CANGIM, (vuint32)0xFFFFFFFF, tmpCanGIM);
    
    #if defined(C_COMP_TI_TMS470)  
    # if !defined(C_ENABLE_TX_POLLING)          || \
         !defined(C_ENABLE_RX_FULLCAN_POLLING)  || \
         !defined(C_ENABLE_RX_BASICCAN_POLLING) || \
         !defined(C_ENABLE_ERROR_POLLING)       || \
         !defined(C_ENABLE_WAKEUP_POLLING)
    assertInternal(((CANMIL == kCanAllLevel0) && ((CANGIM & kCanI0en) != (tCanRegType)0) ) , channel, kErrorWrongInterruptLine);
    # endif
    #endif
    
    tmpCanMC &= ~kCanCcr;  /* clear configuration change request bit */
    CAN_WRITE_REGISTER(&CANMC, 0xFFFFFFFF, tmpCanMC);
    
    APPLCANTIMERSTART(kCanLoopWaitConfigChangeEnable);
    while((CANES & kCanCce) == kCanCce)
    {
    #if defined(C_ENABLE_HW_LOOP_TIMER)
      if(0 == APPLCANTIMERLOOP(kCanLoopWaitConfigChangeEnable))
      {
        break; /* exit loop */
      }
    #else
      ; /* wait until CAN controller leaves configuration mode */
    #endif
    }
    APPLCANTIMEREND(kCanLoopWaitConfigChangeEnable);
    
  } /* end of loop over all hw channels */

#if defined( C_ENABLE_TX_OBSERVE )
  ApplCanInit( CAN_CHANNEL_CANPARA_FIRST CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel), CAN_HL_LOG_HW_TX_STOPINDEX(canHwChannel) );
#endif

#if defined( C_ENABLE_CAN_RAM_CHECK )
  if( canRamCheckStatus == kCanRamCheckFailed)
  {
    /* let the application decide if communication is disabled */
    if (ApplCanMemCheckFailed(CAN_CHANNEL_CANPARA_ONLY) == kCanDisableCommunication)
    {
      canComStatus[channel] = kCanDisableCommunication;
    }  
  }
#endif


} /* END OF CanInit */
/* CODE CATEGORY 4 END*/


/****************************************************************************
| NAME:             CanInitPowerOn
| CALLED BY:        Application
| PRECONDITIONS:    This function must be called by the application before
|                   any other CAN driver function 
|                   Interrupts must be disabled
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Initialization of the CAN chip
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanInitPowerOn( void )
{ 

#if defined( C_ENABLE_VARIABLE_DLC )        || \
      defined( C_ENABLE_DYN_TX_OBJECTS )      || \
      defined( C_ENABLE_INDICATION_FLAG )     || \
      defined( C_ENABLE_CONFIRMATION_FLAG )
  CanTransmitHandle txHandle;
#endif
#if defined( C_ENABLE_VARIABLE_RX_DATALEN )
  CanReceiveHandle rxHandle;
#endif
  CAN_CHANNEL_CANTYPE_LOCAL


  VStdInitPowerOn();

#if defined( C_ENABLE_VARIABLE_DLC )
  for (txHandle = 0; txHandle < kCanNumberOfTxObjects; txHandle++)
  {
    assertGen(XT_TX_DLC(CanGetTxDlc(txHandle))<(vuint8)9, kCanAllChannels, kErrorTxROMDLCTooLarge);      /* PRQA S 3109 */
    canTxDLC_RAM[txHandle] = CanGetTxDlc(txHandle);
  }
#endif

#if defined( C_ENABLE_DYN_TX_OBJECTS )
  /*  Reset dynamic transmission object management -------------------------- */
  for (txHandle = 0; txHandle < kCanNumberOfTxDynObjects; txHandle++)
  {
    /*  Reset management information  */
    canTxDynObjReservedFlag[txHandle] = 0;
  }
#endif /* C_ENABLE_DYN_TX_OBJECTS */

#if defined( C_ENABLE_VARIABLE_RX_DATALEN )
  /*  Initialize the array with received dlc -------------------------- */
  for (rxHandle = 0; rxHandle < kCanNumberOfRxObjects; rxHandle++) {
    canVariableRxDataLen[rxHandle] = CanGetRxDataLen(rxHandle);
  }
#endif

#if defined( C_ENABLE_INDICATION_FLAG )
/* txHandle as loop variable is ok here, because the number of indication bytes is not as high as the number of Rx Messages */
  for (txHandle = 0; txHandle < kCanNumberOfIndBytes; txHandle++) {
    CanIndicationFlags._c[txHandle] = 0;
  }
#endif

#if defined( C_ENABLE_CONFIRMATION_FLAG )
  for (txHandle = 0; txHandle < kCanNumberOfConfBytes; txHandle++) {
    CanConfirmationFlags._c[txHandle] = 0;
  }
#endif



#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  for (channel=0; channel<kCanNumberOfChannels; channel++)
#endif
  {

#if defined( C_ENABLE_CAN_RAM_CHECK )
    canComStatus[channel] = kCanEnableCommunication;
#endif
   
    canStatus[channel]              = kCanStatusInit;


#if defined( C_ENABLE_CAN_TX_CONF_FCT )
    txInfoStructConf[channel].Channel = channel;
#endif
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )  || \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
    canRxInfoStruct[channel].Channel  = channel;
#endif
    canCanInterruptCounter[channel] = 0; 

#if defined( C_ENABLE_TX_POLLING )          || \
      defined( C_ENABLE_RX_FULLCAN_POLLING )  || \
      defined( C_ENABLE_RX_BASICCAN_POLLING ) || \
      defined( C_ENABLE_ERROR_POLLING )       || \
      defined( C_ENABLE_WAKEUP_POLLING )      
    canPollingTaskActive[channel] = 0;
#endif

#if defined( C_ENABLE_DYN_TX_OBJECTS )   && \
    defined( C_ENABLE_CONFIRMATION_FCT ) && \
    defined( C_ENABLE_TRANSMIT_QUEUE )
  /*  Reset dynamic transmission object management -------------------------- */
    confirmHandle[channel] = kCanBufferFree;
#endif

#if defined( C_ENABLE_TX_MASK_EXT_ID )
    canTxMask0[channel] = 0;
# if (kCanNumberOfUsedCanTxIdTables > 1)
    canTxMask1[channel] = 0;
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
    canTxMask2[channel] = 0;
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
    canTxMask3[channel] = 0;
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
    canTxMask4[channel] = 0;
# endif
#endif

#if defined( C_ENABLE_ECU_SWITCH_PASS )
    canPassive[channel]             = 0;
#endif

#if defined( C_ENABLE_PART_OFFLINE )
    canTxPartOffline[channel]       = kCanTxPartInit;
#endif
#if defined( C_ENABLE_COND_RECEIVE_FCT )
    canMsgCondRecState[channel]     = kCanTrue;
#endif

    canRxHandle[channel] = kCanRxHandleNotUsed;

    {
#if defined( C_ENABLE_TRANSMIT_QUEUE )
  /* clear all Tx queue flags */
      CanDelQueuedObj( CAN_CHANNEL_CANPARA_ONLY );
#endif

      CanInit( CAN_CHANNEL_CANPARA_FIRST 0 );

      /* canStatus is only set to init and online, if CanInit() is called for this channel. */
      canStatus[channel]              |= (kCanHwIsInit | kCanTxOn);
    }

  }

} /* END OF CanInitPowerOn */
/* CODE CATEGORY 4 END*/

#if defined( C_ENABLE_TRANSMIT_QUEUE )
/************************************************************************
* NAME:               CanDelQueuedObj
* CALLED BY:          
* PRECONDITIONS:      
* PARAMETER:          notify: if set to 1 for every deleted obj the appl is notified
* RETURN VALUE:       -
* DESCRIPTION:        Resets the bits with are set to 0 in mask
*                     Clearing the Transmit-queue
*************************************************************************/
/* CODE CATEGORY 4 START*/
static void CanDelQueuedObj( CAN_CHANNEL_CANTYPE_ONLY )
{ 
  CanSignedTxHandle     queueElementIdx;
  #if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
  CanSignedTxHandle     elementBitIdx;
  CanTransmitHandle     txHandle;
  tCanQueueElementType  elem;
  #endif

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(channel < kCanNumberOfChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);    /* PRQA S 3109 */
# endif

  #  if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
  if((canStatus[channel] & kCanHwIsInit) == kCanHwIsInit)
  {
    CanCanInterruptDisable(CAN_CHANNEL_CANPARA_ONLY);        /* avoid interruption by CanHL_TxConfirmation */
    for(queueElementIdx = CAN_HL_TXQUEUE_STARTINDEX(channel); queueElementIdx < CAN_HL_TXQUEUE_STOPINDEX(channel); queueElementIdx++)
    { 
      elem = canTxQueueFlags[queueElementIdx];
      if(elem != (tCanQueueElementType)0) /* is there any flag set in the queue element? */
      {
        /* iterate through all flags and notify application for every scheduled transmission */
        for(elementBitIdx = ((CanSignedTxHandle)1 << kCanTxQueueShift) - (CanSignedTxHandle)1; elementBitIdx >= (CanSignedTxHandle)0; elementBitIdx--)
        { 
          if( ( elem & CanShiftLookUp[elementBitIdx] ) != (tCanQueueElementType)0)
          { 
            txHandle = (((CanTransmitHandle)queueElementIdx << kCanTxQueueShift) + (CanTransmitHandle)elementBitIdx) - CAN_HL_TXQUEUE_PADBITS(channel);
            APPLCANCANCELNOTIFICATION(channel, txHandle);
          } 
        } 
        canTxQueueFlags[queueElementIdx] = (tCanQueueElementType)0;
      }
    } 
    CanCanInterruptRestore(CAN_CHANNEL_CANPARA_ONLY);
  } 
  else
  #  endif
  {
    for(queueElementIdx = CAN_HL_TXQUEUE_STARTINDEX(channel); queueElementIdx < CAN_HL_TXQUEUE_STOPINDEX(channel); queueElementIdx++)
    { 
      canTxQueueFlags[queueElementIdx] = (tCanQueueElementType)0;
    } 
  }

# if defined( C_HL_ENABLE_COPROCESSOR_SUPPORT )
# endif
}
/* CODE CATEGORY 4 END*/
#endif

#if defined( C_ENABLE_CAN_TRANSMIT )
# if defined( C_ENABLE_CAN_CANCEL_TRANSMIT )
/* CODE CATEGORY 3 START*/
/****************************************************************************
| NAME:             CanCancelTransmit
| CALLED BY:        Application
| PRECONDITIONS:    none
| INPUT PARAMETERS: Tx-Msg-Handle
| RETURN VALUES:    none
| DESCRIPTION:      delete on Msg-Object
****************************************************************************/
C_API_1 void C_API_2 CanCancelTransmit( CanTransmitHandle txHandle )
{
  CanDeclareGlobalInterruptOldStatus
  CAN_CHANNEL_CANTYPE_LOCAL 
  CanObjectHandle        logTxObjHandle;
  /* ##RI1.4 - 1.6: CanCancelTransmit and CanCancelMsgTransmit */
#  if defined( C_ENABLE_CANCEL_IN_HW )
  CanObjectHandle        txObjHandle;
#  endif

# if defined( C_ENABLE_TRANSMIT_QUEUE )
  CanSignedTxHandle queueElementIdx; /* index for accessing the tx queue */
  CanSignedTxHandle elementBitIdx;  /* bit index within the tx queue element */
  CanTransmitHandle queueBitPos;  /* physical bitposition of the handle */
# endif

  if (txHandle < kCanNumberOfTxObjects)         /* legal txHandle ? */
  {
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    channel = CanGetChannelOfTxObj(txHandle);
# endif

# if defined( C_ENABLE_MULTI_ECU_PHYS )
    assertUser(((CanTxIdentityAssignment[txHandle] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk)0 ), channel , kErrorDisabledTxMessage);    /* PRQA S 3109 */
# endif

    CanNestedGlobalInterruptDisable();
# if defined( C_ENABLE_TRANSMIT_QUEUE )
    #if defined( C_ENABLE_INTERNAL_CHECK ) &&\
        defined( C_MULTIPLE_RECEIVE_CHANNEL )
    if (sizeof(queueBitPos) == 1)
    {
      assertInternal( ((kCanNumberOfTxObjects + CanTxQueuePadBits[kCanNumberOfChannels-1]) <= 256u), kCanAllChannels, kErrorTxQueueTooManyHandle) /* PRQA S 3109 */ /*lint !e572 !e506*/
    }
    else
    {
      assertInternal( ((kCanNumberOfTxObjects + CanTxQueuePadBits[kCanNumberOfChannels-1]) <= 65536u), kCanAllChannels, kErrorTxQueueTooManyHandle) /* PRQA S 3109 */ /*lint !e572 !e506*/
    }
    #endif
    queueBitPos  = txHandle + CAN_HL_TXQUEUE_PADBITS(channel);
    queueElementIdx = (CanSignedTxHandle)(queueBitPos >> kCanTxQueueShift); /* get the queue element where to set the flag */
    elementBitIdx  = (CanSignedTxHandle)(queueBitPos & kCanTxQueueMask);   /* get the flag index wihtin the queue element */
    if( (canTxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) != (tCanQueueElementType)0 )
    {
      canTxQueueFlags[queueElementIdx] &= ~CanShiftLookUp[elementBitIdx]; /* clear flag from the queue */
      APPLCANCANCELNOTIFICATION(channel, txHandle);
    }
# endif

# if defined( C_ENABLE_TX_FULLCAN_OBJECTS )
    logTxObjHandle = (CanObjectHandle)((vsintx)CanGetTxHwObj(txHandle) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));
# else
    logTxObjHandle = (CanObjectHandle)((vsintx)CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));
# endif/* C_ENABLE_TX_FULLCAN_OBJECTS */
    if (canHandleCurTxObj[logTxObjHandle] == txHandle)
    {
      canHandleCurTxObj[logTxObjHandle] = kCanBufferCancel;

      /* ##RI1.4 - 1.6: CanCancelTransmit and CanCancelMsgTransmit */
# if defined( C_ENABLE_CANCEL_IN_HW )
#  if defined( C_ENABLE_TX_FULLCAN_OBJECTS )
      txObjHandle = CanGetTxHwObj(txHandle);
#  else
      txObjHandle = CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel);
#  endif /* C_ENABLE_TX_FULLCAN_OBJECTS */
      CANTRR = CanSlotMask[txObjHandle]; /* set transmission reset request flag */
# endif /* C_ENABLE_CANCEL_IN_HW */
      APPLCANCANCELNOTIFICATION(channel, txHandle);
    }

    CanNestedGlobalInterruptRestore();
  } /* if (txHandle < kCanNumberOfTxObjects) */
}
/* CODE CATEGORY 3 END*/
# endif /* defined( C_ENABLE_CAN_CANCEL_TRANSMIT ) */

#endif /* if defined( C_ENABLE_CAN_TRANSMIT ) */




#if defined( C_ENABLE_CAN_TRANSMIT )
# if defined( C_ENABLE_VARIABLE_DLC )
/* CODE CATEGORY 2 START*/
/****************************************************************************
| NAME:             CanTransmitVarDLC
| CALLED BY:        Netmanagement, application
| PRECONDITIONS:    Can driver must be initialized
| INPUT PARAMETERS: Handle to Tx message, DLC of Tx message
| RETURN VALUES:    kCanTxFailed: transmit failed
|                   kCanTxOk    : transmit was succesful
| DESCRIPTION:      If the CAN driver is not ready for send, the application
|                   decide, whether the transmit request is repeated or not.
****************************************************************************/
C_API_1 vuint8 C_API_2 CanTransmitVarDLC(CanTransmitHandle txHandle, vuint8 dlc)
{
  assertUser(dlc<(vuint8)9, kCanAllChannels, kErrorTxDlcTooLarge);         /* PRQA S 3109 */
  assertUser(txHandle<kCanNumberOfTxObjects, kCanAllChannels , kErrorTxHdlTooLarge);     /* PRQA S 3109 */

  canTxDLC_RAM[ txHandle ] = (canTxDLC_RAM[ txHandle ] & CanLL_DlcMask) | MK_TX_DLC(dlc);

  return CanTransmit( txHandle );
} /* END OF CanTransmitVarDLC */
/* CODE CATEGORY 2 END*/
# endif   /* C_ENABLE_VARIABLE_DLC */

/****************************************************************************
| NAME:             CanTransmit
| CALLED BY:        application
| PRECONDITIONS:    Can driver must be initialized
| INPUT PARAMETERS: Handle of the transmit object to be send
| RETURN VALUES:    kCanTxFailed: transmit failed
|                   kCanTxOk    : transmit was succesful
| DESCRIPTION:      If the CAN driver is not ready for send, the application
|                   decide, whether the transmit request is repeated or not.
****************************************************************************/
/* CODE CATEGORY 2 START*/

C_API_1 vuint8 C_API_2 CanTransmit(CanTransmitHandle txHandle)  C_API_3   /*lint !e14 !e31*/
{
  CanDeclareGlobalInterruptOldStatus

# if !defined( C_ENABLE_TX_POLLING )          ||\
     !defined( C_ENABLE_TRANSMIT_QUEUE )      ||\
     defined( C_ENABLE_TX_FULLCAN_OBJECTS )   
  CanObjectHandle      txObjHandle;
  CanObjectHandle      logTxObjHandle;
  vuint8             rc;
# endif   /* ! C_ENABLE_TX_POLLING  || ! C_ENABLE_TRANSMIT_QUEUE || C_ENABLE_TX_FULLCAN_OBJECTS || C_ENABLE_INDIVIDUAL_POLLING */
  CAN_CHANNEL_CANTYPE_LOCAL

# if defined( C_ENABLE_TRANSMIT_QUEUE )
  CanSignedTxHandle queueElementIdx; /* index for accessing the tx queue */
  CanSignedTxHandle elementBitIdx;  /* bit index within the tx queue element */
  CanTransmitHandle queueBitPos;  /* physical bitposition of the handle */
# endif



  assertUser(txHandle<kCanNumberOfTxObjects, kCanAllChannels , kErrorTxHdlTooLarge);      /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);          /*lint !e661*/
# endif

# if defined( C_ENABLE_MULTI_ECU_PHYS )
  assertUser(((CanTxIdentityAssignment[txHandle] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk)0 ), channel , kErrorDisabledTxMessage);    /* PRQA S 3109 */
# endif

  /* test offline ---------------------------------------------------------- */
  if ( (canStatus[channel] & kCanTxOn) != kCanTxOn )           /* transmit path switched off */
  {
    return kCanTxFailed;
  }

# if defined( C_ENABLE_PART_OFFLINE )
  if ( (canTxPartOffline[channel] & CanTxSendMask[txHandle]) != (vuint8)0)   /*lint !e661*/ /* CAN off ? */
  {
    return (kCanTxPartOffline);
  }
# endif

# if defined( C_ENABLE_CAN_RAM_CHECK )
  if(canComStatus[channel] == kCanDisableCommunication)
  {
    return(kCanCommunicationDisabled);
  }
# endif

# if defined( C_ENABLE_SLEEP_WAKEUP )
  assertUser(!CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanSleep);    /* PRQA S 3109 */
# endif
  assertUser(!CanLL_HwIsStop(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanStop);      /* PRQA S 3109 */

  /* passive mode ---------------------------------------------------------- */
# if defined( C_ENABLE_ECU_SWITCH_PASS )
  if ( canPassive[channel] != (vuint8)0)                             /*  set passive ? */
  {
#  if defined( C_ENABLE_CAN_TX_CONF_FCT ) || \
    defined( C_ENABLE_CONFIRMATION_FCT )
    CanCanInterruptDisable(CAN_CHANNEL_CANPARA_ONLY);      /* avoid CAN Rx interruption */
#  endif

#  if defined( C_ENABLE_CAN_TX_CONF_FCT )
/* ##RI-1.10 Common Callbackfunction in TxInterrupt */
    txInfoStructConf[channel].Handle  = txHandle;
    APPL_CAN_TX_CONFIRMATION(&txInfoStructConf[channel]);
#  endif

#  if defined( C_ENABLE_CONFIRMATION_FLAG )       /* set transmit ready flag  */
#   if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptDisable();
#   endif
    CanConfirmationFlags._c[CanGetConfirmationOffset(txHandle)] |= CanGetConfirmationMask(txHandle);      /*lint !e661*/
#   if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptRestore();
#   endif
#  endif

#  if defined( C_ENABLE_CONFIRMATION_FCT )
    {
#   if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
#   else
      if ( CanGetApplConfirmationPtr(txHandle) != V_NULL )
#   endif
      {
         (CanGetApplConfirmationPtr(txHandle))(txHandle);   /* call completion routine  */
      }
    }
#  endif /* C_ENABLE_CONFIRMATION_FCT */

#  if defined( C_ENABLE_CAN_TX_CONF_FCT ) || \
    defined( C_ENABLE_CONFIRMATION_FCT )
    CanCanInterruptRestore(CAN_CHANNEL_CANPARA_ONLY);
#  endif

    return kCanTxOk;
  }
# endif


   /* can transmit enabled ================================================== */

   /* ----------------------------------------------------------------------- */
   /* ---  transmit queue with one objects ---------------------------------- */
   /* ---  transmit using fullcan objects ----------------------------------- */
   /* ----------------------------------------------------------------------- */

#  if !defined( C_ENABLE_TX_POLLING )          ||\
      !defined( C_ENABLE_TRANSMIT_QUEUE )      ||\
      defined( C_ENABLE_TX_FULLCAN_OBJECTS )   

#   if defined( C_ENABLE_TX_FULLCAN_OBJECTS )
  txObjHandle = CanGetTxHwObj(txHandle);    /*lint !e661*/
#   else
  txObjHandle = CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel);                                          /* msg in object 0 */
#   endif

  logTxObjHandle = (CanObjectHandle)((vsintx)txObjHandle + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));
#  endif   /* ! C_ENABLE_TX_POLLING  || ! C_ENABLE_TRANSMIT_QUEUE || C_ENABLE_TX_FULLCAN_OBJECTS || C_ENABLE_INDIVIDUAL_POLLING */

  CanNestedGlobalInterruptDisable();
 
  /* test offline after interrupt disable ---------------------------------- */
  if ( (canStatus[channel] & kCanTxOn) != kCanTxOn )                /* transmit path switched off */
  {
    CanNestedGlobalInterruptRestore();
    return kCanTxFailed;
  }

# if defined( C_ENABLE_TRANSMIT_QUEUE )
#  if defined( C_ENABLE_TX_FULLCAN_OBJECTS )  ||\
      !defined( C_ENABLE_TX_POLLING )         
  if (
#   if defined( C_ENABLE_TX_FULLCAN_OBJECTS )
       (txObjHandle == CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel))                                   /*disabled - lint !e774 */
#   endif
#   if defined( C_ENABLE_TX_FULLCAN_OBJECTS )  &&\
       ( !defined( C_ENABLE_TX_POLLING )         )
     &&
#   endif

#   if defined( C_ENABLE_TX_POLLING )
        /* write always to queue; transmission is started out of TxTask */
#   else
       ( canHandleCurTxObj[logTxObjHandle] != kCanBufferFree)    /* MsgObj used?  */
#   endif
     )
#  endif   /*  ( C_ENABLE_TX_FULLCAN_OBJECTS )  || !( C_ENABLE_TX_POLLING ) || ( C_ENABLE_INDIVIDUAL_POLLING ) */

    {
      /* tx object 0 used -> set msg in queue: -----------------------------*/
      queueBitPos  = txHandle + CAN_HL_TXQUEUE_PADBITS(channel);
      queueElementIdx = (CanSignedTxHandle)(queueBitPos >> kCanTxQueueShift); /* get the queue element where to set the flag */
      elementBitIdx  = (CanSignedTxHandle)(queueBitPos & kCanTxQueueMask);   /* get the flag index wihtin the queue element */
      canTxQueueFlags[queueElementIdx] |= CanShiftLookUp[elementBitIdx];
      CanNestedGlobalInterruptRestore();
      return kCanTxOk;                          
  }
# endif  /* C_ENABLE_TRANSMIT_QUEUE */

# if !defined( C_ENABLE_TX_POLLING )          ||\
     !defined( C_ENABLE_TRANSMIT_QUEUE )      ||\
     defined( C_ENABLE_TX_FULLCAN_OBJECTS )   

#  if defined( C_ENABLE_TRANSMIT_QUEUE )    && \
      ( defined( C_ENABLE_TX_FULLCAN_OBJECTS )  ||\
        !defined( C_ENABLE_TX_POLLING )         )
  else
#  endif
  {
  /* check for transmit message object free ---------------------------------*/
    if (( canHandleCurTxObj[logTxObjHandle] != kCanBufferFree)    /* MsgObj used?  */
       || ( !CanLL_TxIsHWObjFree( canHwChannel, txObjHandle ) )

      /* hareware-txObject is not free --------------------------------------*/
       )  /* end of if question */

    {  /* object used */
      /* tx object n used, quit with error */
      CanNestedGlobalInterruptRestore();
      return kCanTxFailed;
    }
  }

  /* Obj, pMsgObject points to is free, transmit msg object: ----------------*/
  canHandleCurTxObj[logTxObjHandle] = txHandle;/* Save hdl of msgObj to be transmitted*/
  CanNestedGlobalInterruptRestore();

  rc = CanCopyDataAndStartTransmission( CAN_CHANNEL_CANPARA_FIRST txObjHandle, txHandle);

#  if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
  if ( rc == kCanTxNotify)
  {
    rc = kCanTxFailed;      /* ignore notification if calls of CanCopy.. is performed within CanTransmit */
  }
#  endif


  return(rc);

# else   /* ! C_ENABLE_TX_POLLING  || ! C_ENABLE_TRANSMIT_QUEUE || C_ENABLE_TX_FULLCAN_OBJECTS || C_ENABLE_INDIVIDUAL_POLLING */
# endif   /* ! C_ENABLE_TX_POLLING  || ! C_ENABLE_TRANSMIT_QUEUE || C_ENABLE_TX_FULLCAN_OBJECTS || C_ENABLE_INDIVIDUAL_POLLING */

} /* END OF CanTransmit */
/* CODE CATEGORY 2 END*/


/****************************************************************************
| NAME:             CanCopyDataAndStartTransmission
| CALLED BY:        CanTransmit, CanHl_RestartTxQueue and CanHL_TxConfirmation
| PRECONDITIONS:    - Can driver must be initialized
|                   - canTxCurHandle[logTxObjHandle] must be set
|                   - the hardwareObject (txObjHandle) must be free
| INPUT PARAMETERS: txHandle: Handle of the transmit object to be send
|                   txObjHandle:  Nr of the HardwareObjects to use
| RETURN VALUES:    kCanTxFailed: transmit failed
|                   kCanTxOk    : transmit was succesful
| DESCRIPTION:      If the CAN driver is not ready for send, the application
|                   decide, whether the transmit request is repeated or not.
****************************************************************************/
/* PRQA S 2001 ++ */    /* suppress misra message about usage of goto */
/* CODE CATEGORY 1 START*/
static vuint8 CanCopyDataAndStartTransmission( CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txObjHandle, CanTransmitHandle txHandle) C_API_3   /*lint !e14 !e31*/
{
   CanDeclareGlobalInterruptOldStatus
   vuint8             rc;
   CanObjectHandle      logTxObjHandle;
#  if defined( C_ENABLE_COPY_TX_DATA )  
   TxDataPtr   CanMemCopySrcPtr;
#  endif
# if defined( C_ENABLE_DYN_TX_OBJECTS )
   CanTransmitHandle    dynTxObj;
# endif /* C_ENABLE_DYN_TX_OBJECTS */
# if defined( C_ENABLE_PRETRANSMIT_FCT )
   CanTxInfoStruct      txStruct;
# endif

   tCanRegType   tmpCanME;
   vuint32   tmpTxBuf[2]; 

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
   assertInternal(channel < kCanNumberOfChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);      /* PRQA S 3109 */
# endif
   assertInternal(txHandle < kCanNumberOfTxObjects, kCanAllChannels , kErrorInternalTxHdlTooLarge);        /* PRQA S 3109 */

# if defined( C_ENABLE_DYN_TX_OBJECTS )
   if (txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel))
   {
     dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel);    /* PRQA S 3382,0291 */
   }
   else
   {
     dynTxObj = (CanTransmitHandle)0;
   }
# endif /* C_ENABLE_DYN_TX_OBJECTS */

   assertInternal(txObjHandle < CAN_HL_HW_TX_STOPINDEX(canHwChannel), channel, kErrorTxObjHandleWrong);      /* PRQA S 3109 */
   logTxObjHandle = (CanObjectHandle)((vsintx)txObjHandle + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));

   assertHardware( CanLL_TxIsHWObjFree( canHwChannel, txObjHandle ), channel, kErrorTxBufferBusy);          /* PRQA S 3109 */

   tmpCanME = CANME & (tCanRegType)~CanSlotMask[txObjHandle];  /* disable mailbox to get write access */
   CANME    = tmpCanME;

   /* set id and dlc  -------------------------------------------------------- */
   {
# if defined( C_ENABLE_DYN_TX_DLC ) || \
      defined( C_ENABLE_DYN_TX_ID )
     if (txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel))
     {           /* set dynamic part of dynamic objects ----------------------*/
#  if defined( C_ENABLE_DYN_TX_ID )
        CANMSGOBJ(txObjHandle).CanMid = canDynTxId0[dynTxObj];
#  endif
 
#  if defined( C_ENABLE_DYN_TX_DLC )
        
        
        CANMSGOBJ(txObjHandle).CanMcf = (canDynTxDLC[dynTxObj]);
        
#  endif
     }
     else
     {          /* set part of static objects assocciated the dynamic --------*/
#  if defined( C_ENABLE_DYN_TX_ID )
#   if defined( C_ENABLE_TX_MASK_EXT_ID )
#    if defined( C_ENABLE_MIXED_ID )
        if (CanGetTxIdType(txHandle)==kCanIdTypeStd)
        {
          CANMSGOBJ(txObjHandle).CanMid = CanGetTxId0(txHandle);
        }
        else
#    endif
        {
          /* mask extened ID */
          CANMSGOBJ(txObjHandle).CanMid = (CanGetTxId0(txHandle)|canTxMask0[channel]);
        }
#   else
        CANMSGOBJ(txObjHandle).CanMid = CanGetTxId0(txHandle);
#   endif
#  endif

#  if defined( C_ENABLE_DYN_TX_DLC )
#   if defined( C_ENABLE_VARIABLE_DLC )
        /* init DLC, RAM */
        
        
        CANMSGOBJ(txObjHandle).CanMcf = (canTxDLC_RAM[txHandle]);
        
#   else
        /* init DLC, ROM */
        
        
        CANMSGOBJ(txObjHandle).CanMcf = CanGetTxDlc(txHandle);
        
#   endif
#  endif
     }
# endif
     /* set static part commen for static and dynamic objects ----------------*/
# if defined( C_ENABLE_DYN_TX_ID )
# else
#  if defined( C_ENABLE_TX_MASK_EXT_ID )
#   if defined( C_ENABLE_MIXED_ID )
     if (CanGetTxIdType(txHandle)==kCanIdTypeStd)
     {
       CANMSGOBJ(txObjHandle).CanMid = CanGetTxId0(txHandle);
     }
     else
#   endif
     {
       /* mask extened ID */
       CANMSGOBJ(txObjHandle).CanMid = (CanGetTxId0(txHandle)|canTxMask0[channel]);
     }
#  else
     CANMSGOBJ(txObjHandle).CanMid = CanGetTxId0(txHandle);
#  endif
# endif
# if defined( C_ENABLE_DYN_TX_DLC )
# else
#  if defined( C_ENABLE_VARIABLE_DLC )
     /* init DLC, RAM */
     
     
     CANMSGOBJ(txObjHandle).CanMcf = (canTxDLC_RAM[txHandle]);
     
#  else
     /* init DLC, ROM */
     
     
     CANMSGOBJ(txObjHandle).CanMcf = CanGetTxDlc(txHandle);
     
#  endif
# endif

# if defined( C_ENABLE_MIXED_ID )
#  if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#  else
#   if defined( C_ENABLE_DYN_TX_DLC ) || \
       defined( C_ENABLE_DYN_TX_ID )
     if (txHandle >=  CAN_HL_TX_DYN_ROM_STARTINDEX(channel))
     {                      /* set dynamic part of dynamic objects */
#    if defined( C_ENABLE_DYN_TX_ID )
       
#    else
       
#    endif
     }
#   else
#   endif
#  endif
# endif

   }


 /* call pretransmit function ----------------------------------------------- */
# if defined( C_ENABLE_PRETRANSMIT_FCT )

   /* pointer needed for other modules */
   canTempPreTransmitObj[logTxObjHandle].s.CanMid = CANMSGOBJ(txObjHandle).CanMid;
   canTempPreTransmitObj[logTxObjHandle].s.CanMcf = CANMSGOBJ(txObjHandle).CanMcf;
   
   (txStruct.pChipData) = (CanChipMsgPtr)&(canTempPreTransmitObj[logTxObjHandle].a[4]); /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
   canRDSTxPtr[logTxObjHandle] = txStruct.pChipData;
   txStruct.Handle      = txHandle;

   {  
#  if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
#  else
    /* Is there a PreTransmit function ? ------------------------------------- */ 
    if ( CanGetApplPreTransmitPtr(txHandle) != V_NULL )    /* if PreTransmit exists */ 
#  endif
    { 
      if ( (CanGetApplPreTransmitPtr(txHandle)) (txStruct) == kCanNoCopyData)  
      { 
      
        /*lint -e740 -e826 cast okay */
        #if defined(C_COMP_TI_TMS470)  
        tmpTxBuf[0] = *(vuint32*)&(canTempPreTransmitObj[logTxObjHandle].a[4]);  /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
        tmpTxBuf[1] = *(vuint32*)&(canTempPreTransmitObj[logTxObjHandle].a[6]);  /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
        #endif
        CANMSGOBJ(txObjHandle).CanMsg.dwords.CanMdl = tmpTxBuf[0];
        CANMSGOBJ(txObjHandle).CanMsg.dwords.CanMdh = tmpTxBuf[1];
        /*lint +e740 +e826 cast okay */
        
        /* Do not copy the data - already done by the PreTransmit-function */  
        /* --- start transmission --- */  
        goto startTransmission; 
      } 
    } 
   }  
# endif /* C_ENABLE_PRETRANSMIT_FCT */

 /* copy data --------------------------------------------------------------- */
# if defined( C_ENABLE_COPY_TX_DATA )  
#  if defined( C_ENABLE_DYN_TX_DATAPTR )  
   if (txHandle >=  CAN_HL_TX_DYN_ROM_STARTINDEX(channel))  
   {  
      CanMemCopySrcPtr = canDynTxDataPtr[dynTxObj];  
   }  
   else  
#  endif  
   {  
     CanMemCopySrcPtr = CanGetTxDataPtr(txHandle);  
   }  
 /* copy via index in MsgObj data field, copy always 8 bytes -----------*/  
   if ( CanMemCopySrcPtr != V_NULL )   /* copy if buffer exists */
   {
#  if C_SECURITY_LEVEL > 10
     CanNestedGlobalInterruptDisable();  
#  endif

     /*lint -e740 -e826 cast okay */
     #if defined(C_COMP_TI_TMS470)  
     ((vuint8*)tmpTxBuf)[0] = ((vuint8*)CanMemCopySrcPtr)[0];   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
     ((vuint8*)tmpTxBuf)[1] = ((vuint8*)CanMemCopySrcPtr)[1];   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
     ((vuint8*)tmpTxBuf)[2] = ((vuint8*)CanMemCopySrcPtr)[2];   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
     ((vuint8*)tmpTxBuf)[3] = ((vuint8*)CanMemCopySrcPtr)[3];   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
     ((vuint8*)tmpTxBuf)[4] = ((vuint8*)CanMemCopySrcPtr)[4];   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
     ((vuint8*)tmpTxBuf)[5] = ((vuint8*)CanMemCopySrcPtr)[5];   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
     ((vuint8*)tmpTxBuf)[6] = ((vuint8*)CanMemCopySrcPtr)[6];   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
     ((vuint8*)tmpTxBuf)[7] = ((vuint8*)CanMemCopySrcPtr)[7];   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
     #endif
     CANMSGOBJ(txObjHandle).CanMsg.dwords.CanMdl = tmpTxBuf[0];
     CANMSGOBJ(txObjHandle).CanMsg.dwords.CanMdh = tmpTxBuf[1];
     /*lint +e740 +e826 cast okay */

#  if C_SECURITY_LEVEL > 10
     CanNestedGlobalInterruptRestore();  
#  endif
   }
# endif /* ( C_ENABLE_COPY_TX_DATA ) */  

   CANDRV_SET_CODE_TEST_POINT(0x10A);

# if defined( C_ENABLE_PRETRANSMIT_FCT )
/* Msg(4:2015) This label is not a case or default label for a switch statement. MISRA Rule 55 */
startTransmission:
# endif

   /* test offline and handle and start transmission ------------------------ */
   CanNestedGlobalInterruptDisable();  
   /* If CanTransmit was interrupted by a re-initialization or CanOffline */  
   /* no transmitrequest of this action should be started      */  
   if ((canHandleCurTxObj[logTxObjHandle] == txHandle) && ((canStatus[channel] & kCanTxOn) == kCanTxOn))
   {  
     # if defined( C_ENABLE_PRETRANSMIT_FCT )
     CANMSGOBJ(txObjHandle).CanMid = canTempPreTransmitObj[logTxObjHandle].s.CanMid;
     CANMSGOBJ(txObjHandle).CanMcf = canTempPreTransmitObj[logTxObjHandle].s.CanMcf;
     # endif
     tmpCanME  = CANME  | CanSlotMask[txObjHandle];  /* enable mailbox again */
     CANME  = tmpCanME;
     #if defined(C_COMP_TI_TMS470)            
     # if defined(C_ENABLE_HECC_WORKAROUND_1)
     if(((CANES & kCanTm) != (tCanRegType)0) && (CANTRS != (tCanRegType)0)) /* check if hardware is not busy with Tx */
     {
       gCANTRS[channel] |= CanSlotMask[txObjHandle];  /* set Tx request flag */
     }
     else
     # endif /* C_ENABLE_HECC_WORKAROUND_1 */
     #endif  /* TMS470 */
     { 
     #if defined(C_COMP_TI_TMS470)  
     # if defined(C_ENABLE_SCC_WORKAROUND_1)
     #  if defined (C_MULTIPLE_RECEIVE_CHANNEL)
       if (CanControllerMode[channel] == kCanSCCMode) {
         while ((CANES & kCanRm) != 0)
         {
           ; /* while CAN cell is receiving a message */
         }
       }
     #  else /* C_MULTIPLE_RECEIVE_CHANNEL */
     #   if(kCanControllerMode == kCanSCCMode)
       while ((CANES & kCanRm) != 0)
       {
         ; /* while CAN cell is receiving a message */
       }
     #   endif
     #  endif /* C_MULTIPLE_RECEIVE_CHANNEL */
     # endif  /* C_ENABLE_SCC_WORKAROUND_1 */
     #endif   /* TMS470 */
       CANTRS = CanSlotMask[txObjHandle];  /* set Tx request flag */
     }

# if defined( C_ENABLE_TX_OBSERVE )
     ApplCanTxObjStart( CAN_CHANNEL_CANPARA_FIRST logTxObjHandle );
# endif
     rc = kCanTxOk;                                    
   }  
   else  
   {  
# if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
     if (canHandleCurTxObj[logTxObjHandle] == txHandle)
     {
       /* only CanOffline was called on higher level */
       rc = kCanTxNotify;
     }
     else
# endif
     {
       rc = kCanTxFailed;   
     }
     assertInternal((canHandleCurTxObj[logTxObjHandle] == txHandle) || (canHandleCurTxObj[logTxObjHandle] == kCanBufferFree),
                                                                                       channel, kErrorTxHandleWrong);  /* PRQA S 3109 */
     canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;  /* release TxHandle (CanOffline) */
   }  

   CanNestedGlobalInterruptRestore();

   
   tmpCanME  = CANME | CanSlotMask[txObjHandle];  /* enable mailbox again */
   CANME     = tmpCanME;
   #if defined (V_ENABLE_USE_DUMMY_STATEMENT)
   tmpTxBuf[0] = tmpTxBuf[0] = 0;
   #endif
   
   return (rc);   

} /* END OF CanCopyDataAndStartTransmission */
/* CODE CATEGORY 1 END*/
/* PRQA S 2001 ++ */    /* suppress misra message about usage of goto */
#endif /* if defined( C_ENABLE_CAN_TRANSMIT ) */


#if defined( C_ENABLE_TX_POLLING ) || \
    defined( C_ENABLE_RX_FULLCAN_POLLING )  || \
    defined( C_ENABLE_RX_BASICCAN_POLLING ) || \
    defined( C_ENABLE_ERROR_POLLING ) || \
    defined( C_ENABLE_WAKEUP_POLLING ) 
/****************************************************************************
| NAME:             CanTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling error bus off
|                   - polling Tx objects
|                   - polling Rx objects
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanTask(void)
{
  CAN_CHANNEL_CANTYPE_LOCAL

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  for (channel = 0; channel < kCanNumberOfChannels; channel++)
# endif
  {
    {
# if defined( C_ENABLE_ERROR_POLLING )
      CanErrorTask(CAN_CHANNEL_CANPARA_ONLY);
# endif

# if defined( C_ENABLE_SLEEP_WAKEUP )
#  if defined( C_ENABLE_WAKEUP_POLLING )
      CanWakeUpTask(CAN_CHANNEL_CANPARA_ONLY);
#  endif
# endif

# if defined( C_ENABLE_TX_POLLING ) 
      CanTxTask(CAN_CHANNEL_CANPARA_ONLY);
# endif

# if defined( C_ENABLE_RX_FULLCAN_POLLING ) && \
     defined( C_ENABLE_RX_FULLCAN_OBJECTS )
      CanRxFullCANTask(CAN_CHANNEL_CANPARA_ONLY);
# endif

# if defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && \
    defined( C_ENABLE_RX_BASICCAN_POLLING )
      CanRxBasicCANTask(CAN_CHANNEL_CANPARA_ONLY);
# endif
    }
  }
}
/* CODE CATEGORY 2 END*/
#endif

#if defined( C_ENABLE_ERROR_POLLING )
/****************************************************************************
| NAME:             CanErrorTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling error status
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanErrorTask( CAN_CHANNEL_CANTYPE_ONLY )
{

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);     /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;

    {
# if defined( C_ENABLE_SLEEP_WAKEUP )
      if ( !CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY))
# endif
      {
        CAN_POLLING_IRQ_DISABLE(CAN_CHANNEL_CANPARA_ONLY);
        CanHL_ErrorHandling(CAN_HW_CHANNEL_CANPARA_ONLY);
        CAN_POLLING_IRQ_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
      }
    }

    canPollingTaskActive[channel] = 0;
  }
}
/* CODE CATEGORY 2 END*/
#endif

#if defined( C_ENABLE_SLEEP_WAKEUP )
# if defined( C_ENABLE_WAKEUP_POLLING )
/****************************************************************************
| NAME:             CanWakeUpTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling CAN wakeup event
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanWakeUpTask(CAN_CHANNEL_CANTYPE_ONLY)
{
  CanDeclareGlobalInterruptOldStatus

#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#  endif
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);    /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;

    if((CANGIF0 & kCanWuif0) == kCanWuif0)
    {
      CANDRV_SET_CODE_TEST_POINT(0x111);
      CanNestedGlobalInterruptDisable();          /* ESCAN00021223 */
      CanLL_WakeUpHandling(CAN_CHANNEL_CANPARA_ONLY);
      CanNestedGlobalInterruptRestore();          /* ESCAN00021223 */
    }
    canPollingTaskActive[channel] = 0;
  }
}
/* CODE CATEGORY 2 END*/
# endif /* C_ENABLE_WAKEUP_POLLING */
#endif /* C_ENABLE_SLEEP_WAKEUP */

#if defined( C_ENABLE_TX_POLLING ) 
/****************************************************************************
| NAME:             CanTxTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling Tx objects
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanTxTask( CAN_CHANNEL_CANTYPE_ONLY )
{
  CanObjectHandle      txObjHandle;



# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);    /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;


# if defined( C_ENABLE_SLEEP_WAKEUP )
    if ( !CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY))
# endif
    {
      /*--  polling Tx objects ----------------------------------------*/

# if defined( C_ENABLE_TX_POLLING )
      /* check for global confirmation Pending and may be reset global pending confirmation */
      # if defined(C_ENABLE_CANCEL_IN_HW)
      if((CANTA | CANAA) != (tCanRegType)0x00000000)
      # else
      if(CANTA != (tCanRegType)0x00000000)
      # endif
      {
        for ( txObjHandle = CAN_HL_HW_TX_STARTINDEX(canHwChannel); txObjHandle < CAN_HL_HW_TX_STOPINDEX(canHwChannel) ; txObjHandle++ )
        {
          {
            /* check for dedicated confirmation pending */
            # if defined(C_ENABLE_CANCEL_IN_HW)
            if(( (CANTA | CANAA) & CanSlotMask[txObjHandle]) == CanSlotMask[txObjHandle])
            # else
            if((CANTA & CanSlotMask[txObjHandle]) == CanSlotMask[txObjHandle])
            # endif
            {
              CANDRV_SET_CODE_TEST_POINT(0x110);
              CAN_POLLING_IRQ_DISABLE(CAN_CHANNEL_CANPARA_ONLY);
              /* do tx confirmation */
              CanHL_TxConfirmation(CAN_HW_CHANNEL_CANPARA_FIRST txObjHandle );
              CAN_POLLING_IRQ_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
            }
          } /* if individual polling & object has to be polled */
        }
      }
# endif /*( C_ENABLE_TX_POLLING ) */


# if defined( C_ENABLE_TRANSMIT_QUEUE )
      CanHl_RestartTxQueue( CAN_CHANNEL_CANPARA_ONLY );
# endif /*  C_ENABLE_TRANSMIT_QUEUE */

    } /* if ( CanLL_HwIsSleep... ) */

    canPollingTaskActive[channel] = 0;
  }


} /* END OF CanTxTask */
/* CODE CATEGORY 2 END*/
#endif /* C_ENABLE_TX_POLLING */

#if defined( C_ENABLE_TRANSMIT_QUEUE )
# if defined( C_ENABLE_TX_POLLING ) 
/****************************************************************************
| NAME:             CanHl_RestartTxQueue
| CALLED BY:        CanTxTask, via CanLL (TxMsgDestroyed)
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      start transmission if queue entry exists and HW is free
****************************************************************************/
/* CODE CATEGORY 2 START*/
static void CanHl_RestartTxQueue( CAN_CHANNEL_CANTYPE_ONLY )
{
  CanTransmitHandle    txHandle;
#  if  defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
  vuint8             rc;
#  endif
  CanDeclareGlobalInterruptOldStatus

  CanSignedTxHandle         queueElementIdx;    /* use as signed due to loop */
  CanSignedTxHandle         elementBitIdx;
  tCanQueueElementType             elem;

#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(channel < kCanNumberOfChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);      /* PRQA S 3109 */
#  endif


  if (canHandleCurTxObj[(vsintx)CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)] == kCanBufferFree)
  {
    for(queueElementIdx = CAN_HL_TXQUEUE_STOPINDEX(channel) - (CanSignedTxHandle)1; 
                             queueElementIdx >= CAN_HL_TXQUEUE_STARTINDEX(channel); queueElementIdx--)
    {
      elem = canTxQueueFlags[queueElementIdx];
      if(elem != (tCanQueueElementType)0) /* is there any flag set in the queue element? */
      {

        /* Transmit Queued Objects */
        /* start the bitsearch */
        #if defined( C_CPUTYPE_32BIT )
        if((elem & (tCanQueueElementType)0xFFFF0000) != (tCanQueueElementType)0)
        {
          if((elem & (tCanQueueElementType)0xFF000000) != (tCanQueueElementType)0)
          {
            if((elem & (tCanQueueElementType)0xF0000000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 28] + 28;
            }
            else /*0x0F000000*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 24] + 24;
            }
          }
          else
          {
            if((elem & (tCanQueueElementType)0x00F00000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 20] + 20;
            }
            else /* 0x000F0000*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 16] + 16;
            }
          }
        }
        else
        #endif
        {
        #if defined( C_CPUTYPE_32BIT ) 
          if((elem & (tCanQueueElementType)0x0000FF00) != (tCanQueueElementType)0)
          {
            if((elem & (tCanQueueElementType)0x0000F000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 12] + 12;
            }
            else /*0x00000F00*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 8] + 8;
            }
          }
          else
        #endif
          {
            if((elem & (tCanQueueElementType)0x000000F0) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 4] + 4;
            }
            else /* 0x0000000F*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem];
            }
          }
        }
        txHandle = (((CanTransmitHandle)queueElementIdx << kCanTxQueueShift) + (CanTransmitHandle)elementBitIdx) - CAN_HL_TXQUEUE_PADBITS(channel);
        {

            CanNestedGlobalInterruptDisable();
            if (canHandleCurTxObj[(vsintx)CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)] == kCanBufferFree)
            {
              if ( (canTxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) != (tCanQueueElementType)0 )
              {
                canTxQueueFlags[queueElementIdx] &= ~CanShiftLookUp[elementBitIdx]; /* clear flag from the queue */
                /* Save hdl of msgObj to be transmitted*/
                canHandleCurTxObj[(vsintx)CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)] = txHandle;
                CanNestedGlobalInterruptRestore();  
#  if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
                rc = CanCopyDataAndStartTransmission(CAN_CHANNEL_CANPARA_FIRST CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel), txHandle);
                if ( rc == kCanTxNotify)
                {
                  APPLCANCANCELNOTIFICATION(channel, txHandle);
                }
#  else
                (void)CanCopyDataAndStartTransmission(CAN_CHANNEL_CANPARA_FIRST CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel), txHandle);
#  endif
                return;
              }

            }
            CanNestedGlobalInterruptRestore();
            return;
        }
      }
    }
  }
} /* End of CanHl_RestartTxQueue */
/* CODE CATEGORY 2 END*/
# endif
#endif /*  C_ENABLE_TRANSMIT_QUEUE */

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS ) && \
    defined( C_ENABLE_RX_FULLCAN_POLLING )  
/****************************************************************************
| NAME:             CanRxFullCANTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling Rx FullCAN objects
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanRxFullCANTask(CAN_CHANNEL_CANTYPE_ONLY)
{

  CanObjectHandle     rxObjHandle;        /* keyword register removed 2005-06-29 Ht */


# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
# endif
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);    /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;

    {
# if defined( C_ENABLE_SLEEP_WAKEUP )
      if ( !CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY))
# endif
      {
        /*--  polling fullcan Rx objects ----------------------------------------*/

        /* check for global fullCan Rx indication pending and may be reset global */
        /* indication pending */
        if(CAN_IS_RX_FULLCAN_PENDING())
        {
          for (rxObjHandle=CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel); rxObjHandle<CAN_HL_HW_RX_FULL_STOPINDEX(canHwChannel); rxObjHandle++ )
          {
            {
              /* check for dedicated indication pending */
              if((CANRMP & CanSlotMask[rxObjHandle]) == CanSlotMask[rxObjHandle])
              {
                CANDRV_SET_CODE_TEST_POINT(0x109);
                CAN_POLLING_IRQ_DISABLE(CAN_CHANNEL_CANPARA_ONLY);
                CanFullCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxObjHandle);
                CAN_POLLING_IRQ_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
              }
            }  /* if individual polling & object has to be polled */
          } /* for ( txObjHandle ) */
        } /* if (global pending) */
      } /* if ( CanLL_HwIsSleep ... )  */
    }  /* for (all associated HW channel) */
    canPollingTaskActive[channel] = 0;
  }

} /* END OF CanRxTask */
/* CODE CATEGORY 2 END*/
#endif /*  C_ENABLE_RX_FULLCAN_OBJECTS && C_ENABLE_RX_FULLCAN_POLLING */

#if defined( C_ENABLE_RX_BASICCAN_POLLING ) && \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/****************************************************************************
| NAME:             CanRxBasicCANTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling Rx BasicCAN objects
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanRxBasicCANTask(CAN_CHANNEL_CANTYPE_ONLY)
{

  CanObjectHandle     rxObjHandle;          /* keyword register removed 2005-06-29 Ht */
  CanObjectHandle     loopCount;


# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);   /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;


# if defined( C_ENABLE_SLEEP_WAKEUP )
    if ( !CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY))
# endif
    {

      if(CAN_IS_RX_BASICCAN_PENDING())
      {
        rxObjHandle = CAN_HL_HW_RX_BASIC_STOPINDEX(canHwChannel);
        for (loopCount=CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel); loopCount<CAN_HL_HW_RX_BASIC_STOPINDEX(canHwChannel); loopCount++  )
        {
          rxObjHandle--; 
          {
            /* check for dedicated indication pending */
            if((CANRMP & CanSlotMask[rxObjHandle]) == CanSlotMask[rxObjHandle])
            {
              CANDRV_SET_CODE_TEST_POINT(0x108);

              CAN_POLLING_IRQ_DISABLE(CAN_CHANNEL_CANPARA_ONLY);
              CanBasicCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxObjHandle);
              CAN_POLLING_IRQ_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
            }
          } /* if individual polling & object has to be polled */
        }
      }
    } /* if ( CanLL_HwIsSleep... )  */

    canPollingTaskActive[channel] = 0;
  }

} /* END OF CanRxTask */
/* CODE CATEGORY 2 END*/
#endif /* C_ENABLE_RX_BASICCAN_POLLING && C_ENABLE_RX_BASICCAN_OBJECTS */

/****************************************************************************
| NAME:             CanHL_ErrorHandling
| CALLED BY:        CanISR(), CanErrorTask()
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - error interrupt (busoff, error warning,...)
****************************************************************************/
/* CODE CATEGORY 2 START*/
static void CanHL_ErrorHandling( CAN_HW_CHANNEL_CANTYPE_ONLY )
{

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(canHwChannel < kCanNumberOfHwChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);      /* PRQA S 3109 */
#endif




  /* check for status register (bus error)--*/
  if((CANGIF0 & kCanBoif0) == kCanBoif0) /* check for bus off */
  {
    CANGIF0 = kCanBoif0; /* clear bus off flag */
    /*==BUS OFF ERROR=========================*/
    APPL_CAN_BUSOFF( CAN_CHANNEL_CANPARA_ONLY );            /* call application specific function */
  }


} /* END OF CanHL_ErrorHandling */
/* CODE CATEGORY 2 END*/



#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/****************************************************************************
| NAME:             CanBasicCanMsgReceived
| CALLED BY:        CanISR()
| PRECONDITIONS:
| INPUT PARAMETERS: internal can chip number
| RETURN VALUES:    none
| DESCRIPTION:      - basic can receive
****************************************************************************/
/* PRQA S 2001 ++ */    /* suppress misra message about usage of goto */
/* CODE CATEGORY 1 START*/
static void CanBasicCanMsgReceived( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle)
{
# if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  tCanRxInfoStruct    *pCanRxInfoStruct;
# endif  
  
# if ( !defined( C_SEARCH_HASH ) )  ||\
     defined( C_ENABLE_RANGE_0 ) || \
     defined( C_ENABLE_RANGE_1 ) || \
     defined( C_ENABLE_RANGE_2 ) || \
     defined( C_ENABLE_RANGE_3 )
  tCanRxId0 idRaw0;
#  if (kCanNumberOfUsedCanRxIdTables > 1)
  tCanRxId1 idRaw1;
#  endif
#  if (kCanNumberOfUsedCanRxIdTables > 2)
  tCanRxId2 idRaw2;
#  endif
#  if (kCanNumberOfUsedCanRxIdTables > 3)
  tCanRxId3 idRaw3;
#  endif
#  if (kCanNumberOfUsedCanRxIdTables > 4)
  tCanRxId4 idRaw4;
#  endif
# endif

# if defined( C_SEARCH_HASH )
#  if (kCanNumberOfRxBasicCANObjects > 0)
#   if (kHashSearchListCountEx > 0)
  vuint32          idExt;
#    if (kHashSearchListCountEx > 1)
  vuint32          winternExt;        /* prehashvalue         */
#    endif
#   endif
#   if (kHashSearchListCount > 0)
  vuint16          idStd;
#    if (kHashSearchListCount > 1)
  vuint16          winternStd;        /* prehashvalue         */
#    endif
#   endif
#   if (((kHashSearchListCountEx > 1) && (kHashSearchMaxStepsEx > 1)) ||\
        ((kHashSearchListCount > 1)   && (kHashSearchMaxSteps > 1))) 
  vuint16          i_increment;    /* delta for next step  */
  vsint16          count;
#   endif
#  endif  /* kCanNumberOfRxBasicCANObjects > 0 */
# endif

  # if defined(C_ENABLE_OVERRUN)
  vuint32 bOverrunPending;
  # endif
  

# if defined( C_ENABLE_GENERIC_PRECOPY ) || \
    defined( C_ENABLE_PRECOPY_FCT )     || \
    defined( C_ENABLE_COPY_RX_DATA )    || \
    defined( C_ENABLE_INDICATION_FLAG ) || \
    defined( C_ENABLE_INDICATION_FCT )  || \
    defined( C_ENABLE_DLC_CHECK )       || \
    defined( C_ENABLE_NOT_MATCHED_FCT )
#  if (kCanNumberOfRxBasicCANObjects > 0)

  CanReceiveHandle         rxHandle;

  rxHandle = kCanRxHandleNotUsed;

#  endif /* kCanNumberOfRxBasicCANObjects > 0 */
# endif

  CANDRV_SET_CODE_TEST_POINT(0x100);

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(canHwChannel < kCanNumberOfHwChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);  /* PRQA S 3109 */
# endif

  #if defined (C_ENABLE_OVERRUN) 
  bOverrunPending = ((CANRML & CanSlotMask[rxObjHandle]) == CanSlotMask[rxObjHandle]) ? ((vuint32)1) : ((vuint32)0);
  #endif 
  
  APPLCANTIMERSTART(kCanLoopCopyRxBasicMailBox);
  do 
  {
    CANRMP = CanSlotMask[rxObjHandle]; /* reset interrupt flag */
  #if defined (C_ENABLE_OVERRUN) 
    bOverrunPending++;                 /* only evaluated if overrun activated */
  #endif
    /* **************************************** */
    /*     Copy data                            */
    /* **************************************** */
  
  
  
  
  #if defined(C_COMP_TI_TMS470)  
    canTempCanObj[channel] = *(tCanTempRamMailBox*)&(CANMSGOBJ(rxObjHandle));    /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
  #endif /* TMS470 all compilers */
  
    /* **************************************** */
    /*     Copy data done                       */
    /* **************************************** */
  
  #if defined(C_ENABLE_HW_LOOP_TIMER) 
    /* break the loop after data is copied once */
    if (0 == APPLCANTIMERLOOP(kCanLoopCopyRxBasicMailBox))
    { 
      goto finishBasicCan; /* ignore reception, data might be inconsistent */
  
    } 
  #endif
  }
  while ( (CANRMP & CanSlotMask[rxObjHandle]) != 0);
  APPLCANTIMEREND(kCanLoopCopyRxBasicMailBox);
  
  /* **************************************** */
  /*     Normalize data                       */
  /* **************************************** */
  #if defined(C_COMP_TI_TMS470)  
  /* Nothing to do any more, data already in correct order */
  #endif /* TMS470 all compilers */
  
  

# if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  pCanRxInfoStruct =  &canRxInfoStruct[channel];
  (pCanRxInfoStruct->pChipMsgObj) = (CanChipMsgPtr)&(canTempCanObj[channel]);    /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
  (pCanRxInfoStruct->pChipData) = (CanChipDataPtr)&(canTempCanObj[channel].CanData);    /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
  canRDSRxPtr[channel] = pCanRxInfoStruct->pChipData;
# else
  (canRxInfoStruct[channel].pChipMsgObj) = (CanChipMsgPtr)&(canTempCanObj[channel]);    /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
  (canRxInfoStruct[channel].pChipData) = (CanChipDataPtr)&(canTempCanObj[channel].CanData);    /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
  canRDSRxPtr[channel] = canRxInfoStruct[channel].pChipData;
# endif
  CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)      = kCanRxHandleNotUsed;  

# if defined( C_ENABLE_CAN_RAM_CHECK )
  if(canComStatus[channel] == kCanDisableCommunication)
  {
    goto finishBasicCan; /* ignore reception */
  }
# endif

#  if defined( C_ENABLE_OVERRUN )
  if(bOverrunPending > (vuint32)1)
  {
    ApplCanOverrun( CAN_CHANNEL_CANPARA_ONLY );
  }
#  endif

  /**************************** reject remote frames  ****************************************/
# if defined( C_HL_ENABLE_REJECT_REMOTE_FRAME )
  /* Suppress reception of remote frames */
  if ( (canTempCanObj[channel].CanMcf & kCanRtr) == kCanRtr) 
  {
    /* Remote Frame -> abandon reception */
    goto finishBasicCan;
  }
# endif /* C_HL_ENABLE_REJECT_REMOVE_FRAME */


  /**************************** reject messages with unallowed ID type ****************************************/
# if defined( C_HL_ENABLE_REJECT_UNWANTED_IDTYPE )
#  if defined( C_ENABLE_EXTENDED_ID )
#   if defined( C_ENABLE_MIXED_ID )
#   else
  if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) != kCanIdTypeExt)
  {
    goto finishBasicCan;
  }
#   endif
#  else
  if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) != kCanIdTypeStd)
  {
    goto finishBasicCan;
  }
#  endif
# endif /* C_HL_ENABLE_REJECT_UNWANTED_IDTYPE */


# if defined( C_ENABLE_COND_RECEIVE_FCT )
  /**************************** conditional message receive function  ****************************************/
  if(canMsgCondRecState[channel]==kCanTrue)
  {
    ApplCanMsgCondReceived( CAN_HL_P_RX_INFO_STRUCT(channel) );
  }
# endif

# if defined( C_ENABLE_RECEIVE_FCT )
  /**************************** call ApplCanMsgReceived() ****************************************************/
  if (APPL_CAN_MSG_RECEIVED( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanNoCopyData)
  {
    goto finishBasicCan;
  }
# endif
  

# if ( !defined( C_SEARCH_HASH ) ) || \
     defined( C_ENABLE_RANGE_0 ) || \
     defined( C_ENABLE_RANGE_1 ) || \
     defined( C_ENABLE_RANGE_2 ) || \
     defined( C_ENABLE_RANGE_3 )
  /**************************** calculate idRaw for filtering ************************************************/
#  if defined( C_ENABLE_EXTENDED_ID )
#   if defined( C_ENABLE_MIXED_ID )
  if (CanRxActualIdType(CAN_HL_P_RX_INFO_STRUCT(channel)) == kCanIdTypeExt)
#   endif
  {
#   if defined( C_ENABLE_RX_MASK_EXT_ID )
    idRaw0 = CanRxActualIdRaw0( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID0(C_MASK_EXT_ID);
#    if (kCanNumberOfUsedCanRxIdTables > 1)
    idRaw1 = CanRxActualIdRaw1( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID1(C_MASK_EXT_ID);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 2)
    idRaw2 = CanRxActualIdRaw2( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID2(C_MASK_EXT_ID);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 3)
    idRaw3 = CanRxActualIdRaw3( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID3(C_MASK_EXT_ID);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 4)
    idRaw4 = CanRxActualIdRaw4( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID4(C_MASK_EXT_ID);
#    endif
#   else
    idRaw0 = CanRxActualIdRaw0( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID0(0x1FFFFFFF);
#    if (kCanNumberOfUsedCanRxIdTables > 1)
    idRaw1 = CanRxActualIdRaw1( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID1(0x1FFFFFFF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 2)
    idRaw2 = CanRxActualIdRaw2( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID2(0x1FFFFFFF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 3)
    idRaw3 = CanRxActualIdRaw3( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID3(0x1FFFFFFF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 4)
    idRaw4 = CanRxActualIdRaw4( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID4(0x1FFFFFFF);
#    endif
#   endif /*  C_ENABLE_RX_MASK_EXT_ID */
  }
#   if defined( C_ENABLE_MIXED_ID )
  else
  {
    idRaw0 = CanRxActualIdRaw0( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID0(0x7FF);
#    if (kCanNumberOfUsedCanRxIdTables > 1)
    idRaw1 = CanRxActualIdRaw1( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID1(0x7FF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 2)
    idRaw2 = CanRxActualIdRaw2( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID2(0x7FF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 3)
    idRaw3 = CanRxActualIdRaw3( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID3(0x7FF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 4)
    idRaw4 = CanRxActualIdRaw4( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID4(0x7FF);
#    endif
  }
#   endif
#  else /* C_ENABLE_EXTENDED_ID */
  {
    idRaw0 = CanRxActualIdRaw0( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID0(0x7FF);
#   if (kCanNumberOfUsedCanRxIdTables > 1)
    idRaw1 = CanRxActualIdRaw1( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID1(0x7FF);
#   endif
#   if (kCanNumberOfUsedCanRxIdTables > 2)
    idRaw2 = CanRxActualIdRaw2( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID2(0x7FF);
#   endif
#   if (kCanNumberOfUsedCanRxIdTables > 3)
    idRaw3 = CanRxActualIdRaw3( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID3(0x7FF);
#   endif
#   if (kCanNumberOfUsedCanRxIdTables > 4)
    idRaw4 = CanRxActualIdRaw4( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID4(0x7FF);
#   endif
  }
#  endif /* C_ENABLE_EXTENDED_ID */
# endif /* ( !defined( C_SEARCH_HASH ) && ...  defined( C_ENABLE_RANGE_3 )*/

  /******************* Range filtering ********************************************************************/

  {
#  if defined( C_ENABLE_RANGE_0 )
#   if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    if ( (CanChannelObject[channel].RangeActiveFlag & kCanRange0) != (vuint16)0 )
    {
#    if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == CANRANGE0IDTYPE(channel))
#    endif
      {
        if ( C_RANGE_MATCH( CAN_RX_IDRAW_PARA, CANRANGE0ACCMASK(channel), CANRANGE0ACCCODE(channel)) )
#   else    /* C_SINGLE_RECEIVE_CHANNEL) */
    {
#    if (CANRANGE0IDTYPE(0) == kCanIdTypeStd )
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeStd)
#     endif
      {
        if ( C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, CANRANGE0ACCMASK(channel), CANRANGE0ACCCODE(channel)) )
#    else  /* C_RANGE_0_IDTYPE == kCanIdTypeExt */
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeExt)
#     endif
      {
        if ( C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, CANRANGE0ACCMASK(channel), CANRANGE0ACCCODE(channel)) )
#    endif
#   endif
        {
          {
            if (APPLCANRANGE0PRECOPY( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanNoCopyData)
            {
              goto finishBasicCan;
            }
          }
        }
      }
    }
#  endif  /* C_ENABLE_RANGE_0 */

#  if defined( C_ENABLE_RANGE_1 )
#   if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    if ( (CanChannelObject[channel].RangeActiveFlag & kCanRange1) != (vuint16)0 )
    {
#    if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == CANRANGE1IDTYPE(channel))
#    endif
      {
        if ( C_RANGE_MATCH( CAN_RX_IDRAW_PARA, CANRANGE1ACCMASK(channel), CANRANGE1ACCCODE(channel)) )
#   else    /* C_SINGLE_RECEIVE_CHANNEL) */
    {
#    if (CANRANGE1IDTYPE(0) == kCanIdTypeStd )
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeStd)
#     endif
      {
        if ( C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, CANRANGE1ACCMASK(channel), CANRANGE1ACCCODE(channel)) )
#    else  /* C_RANGE_1_IDTYPE == kCanIdTypeExt */
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeExt)
#     endif
      {
        if ( C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, CANRANGE1ACCMASK(channel), CANRANGE1ACCCODE(channel)) )
#    endif
#   endif
        {
          {
            if (APPLCANRANGE1PRECOPY( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanNoCopyData)
            {
              goto finishBasicCan;
            }
          }
        }
      }
    }
#  endif  /* C_ENABLE_RANGE_1 */

#  if defined( C_ENABLE_RANGE_2 )
#   if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    if ( (CanChannelObject[channel].RangeActiveFlag & kCanRange2) != (vuint16)0 )
    {
#    if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == CANRANGE2IDTYPE(channel))
#    endif
      {
        if ( C_RANGE_MATCH( CAN_RX_IDRAW_PARA, CANRANGE2ACCMASK(channel), CANRANGE2ACCCODE(channel)) )
#   else    /* C_SINGLE_RECEIVE_CHANNEL) */
    {
#    if (CANRANGE2IDTYPE(0) == kCanIdTypeStd )
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeStd)
#     endif
      {
        if ( C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, CANRANGE2ACCMASK(channel), CANRANGE2ACCCODE(channel)) )
#    else  /* C_RANGE_2_IDTYPE == kCanIdTypeExt */
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeExt)
#     endif
      {
        if ( C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, CANRANGE2ACCMASK(channel), CANRANGE2ACCCODE(channel)) )
#    endif
#   endif
        {
          {
            if (APPLCANRANGE2PRECOPY( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanNoCopyData)
            {
              goto finishBasicCan;
            }
          }
        }
      }
    }
#  endif  /* C_ENABLE_RANGE_2 */

#  if defined( C_ENABLE_RANGE_3 )
#   if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    if ( (CanChannelObject[channel].RangeActiveFlag & kCanRange3) != (vuint16)0 )
    {
#    if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == CANRANGE3IDTYPE(channel))
#    endif
      {
        if ( C_RANGE_MATCH( CAN_RX_IDRAW_PARA, CANRANGE3ACCMASK(channel), CANRANGE3ACCCODE(channel)) )
#   else    /* C_SINGLE_RECEIVE_CHANNEL) */
    {
#    if (CANRANGE3IDTYPE(0) == kCanIdTypeStd )
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeStd)
#     endif
      {
        if ( C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, CANRANGE3ACCMASK(channel), CANRANGE3ACCCODE(channel)) )
#    else  /* C_RANGE_3_IDTYPE == kCanIdTypeExt */
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeExt)
#     endif
      {
        if ( C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, CANRANGE3ACCMASK(channel), CANRANGE3ACCCODE(channel)) )
#    endif
#   endif
        {
          {
            if (APPLCANRANGE3PRECOPY( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanNoCopyData)
            {
              goto finishBasicCan;
            }
          }
        }
      }
    }
#  endif  /* C_ENABLE_RANGE_3 */

  }


# if defined( C_ENABLE_GENERIC_PRECOPY ) || \
    defined( C_ENABLE_PRECOPY_FCT )     || \
    defined( C_ENABLE_COPY_RX_DATA )    || \
    defined( C_ENABLE_INDICATION_FLAG ) || \
    defined( C_ENABLE_INDICATION_FCT )  || \
    defined( C_ENABLE_DLC_CHECK )       || \
    defined( C_ENABLE_NOT_MATCHED_FCT )
# if (kCanNumberOfRxBasicCANObjects > 0)

   /* search the received id in ROM table: */


#  if defined( C_SEARCH_LINEAR )
  /* ************* Linear search ******************************************** */
  for (rxHandle = CAN_HL_RX_BASIC_STARTINDEX(channel); rxHandle < CAN_HL_RX_BASIC_STOPINDEX(channel) ;rxHandle++)
  {
    if( idRaw0 == CanGetRxId0(rxHandle) )
    {
#   if (kCanNumberOfUsedCanRxIdTables > 1)
      if( idRaw1 == CanGetRxId1(rxHandle) )
#   endif
      {
#   if (kCanNumberOfUsedCanRxIdTables > 2)
        if( idRaw2 == CanGetRxId2(rxHandle) )
#   endif
        {
#   if (kCanNumberOfUsedCanRxIdTables > 3)
          if( idRaw3 == CanGetRxId3(rxHandle) )
#   endif
          {
#   if (kCanNumberOfUsedCanRxIdTables > 4)
            if( idRaw4 == CanGetRxId4(rxHandle) )
#   endif
            {
#   if defined( C_ENABLE_MIXED_ID ) 
#    if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#    else
              /* verify ID type, if not already done with the ID raw */
              if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == CanGetRxIdType(rxHandle))
#    endif
#   endif
              {
                break;    /*exit loop with index rxHandle */
              }
            }
          }
        }
      }
    }
  }
#  endif

#  if defined( C_SEARCH_HASH )
  /* ************* Hash search ********************************************* */
    
#   if defined( C_ENABLE_EXTENDED_ID ) 
  /* one or more Extended ID listed */
#    if defined( C_ENABLE_MIXED_ID )
  if((CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) )) == kCanIdTypeExt)
#    endif
#    if (kHashSearchListCountEx > 0)
  {
  /* calculate the logical ID */
#     if defined( C_ENABLE_RX_MASK_EXT_ID )
    idExt          = (CanRxActualId( CAN_HL_P_RX_INFO_STRUCT(channel) ) &  C_MASK_EXT_ID ) | \
                                                                               ((vuint32)channel << 29);                
#     else
    idExt          = CanRxActualId( CAN_HL_P_RX_INFO_STRUCT(channel) )| ((vuint32)channel << 29);
#     endif

#     if (kHashSearchListCountEx == 1)
    rxHandle       = (CanReceiveHandle)0;
#     else
    winternExt     = idExt + kHashSearchRandomNumberEx;                    
    rxHandle       = (CanReceiveHandle)(winternExt % kHashSearchListCountEx);
#     endif /* (kHashSearchListCountEx == 1) */

#     if ((kHashSearchListCountEx == 1) || (kHashSearchMaxStepsEx == 1))
    if (idExt != CanRxHashIdEx[rxHandle])   
    { 
#      if defined( C_ENABLE_NOT_MATCHED_FCT )
      ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#      endif
      goto finishBasicCan;
    }
#     else /* (kHashSearchListCountEx == 1) || (kHashSearchMaxStepsEx == 1) */

    i_increment = (vuint16)((winternExt % (kHashSearchListCountEx - 1)) + (vuint8)1);          /* ST10-CCAN Keil compiler complains without cast */
    count       = (vsint16)kHashSearchMaxStepsEx - 1;               
  
    while(idExt != CanRxHashIdEx[rxHandle])   
    {
      if(count == (vsint16)0)  
      {
#      if defined( C_ENABLE_NOT_MATCHED_FCT )
        ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#      endif
        goto finishBasicCan;
      }
      count--;
      rxHandle += i_increment;
      if( rxHandle >= (vuint16)kHashSearchListCountEx ) 
      {
        rxHandle -= kHashSearchListCountEx;
      }
    }
#     endif  /* (kHashSearchListCountEx == 1) || (kHashSearchMaxStepsEx == 1) */
    rxHandle = CanRxMsgIndirection[rxHandle+kHashSearchListCount];
  }
#    else /* (kHashSearchListCountEx > 0) */
  {
#     if defined( C_ENABLE_NOT_MATCHED_FCT )
    ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#     endif
    goto finishBasicCan;
  }
#    endif /* (kHashSearchListCountEx > 0) */

#    if defined( C_ENABLE_MIXED_ID )
  else   /* if((CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) )) == kCanIdTypeStd)  */
#    endif
#   endif /* If defined( C_ENABLE_EXTENDED_ID ) */

#   if defined( C_ENABLE_MIXED_ID ) || !defined( C_ENABLE_EXTENDED_ID ) 
#    if (kHashSearchListCount > 0)
  {
    idStd          = ((vuint16)CanRxActualId( CAN_HL_P_RX_INFO_STRUCT(channel) ) | ((vuint16)channel << 11));    /* calculate the logical ID */

#     if (kHashSearchListCount == 1)
    rxHandle       = (CanReceiveHandle)0;
#     else
    winternStd     = idStd + kHashSearchRandomNumber;
    rxHandle       = (CanReceiveHandle)(winternStd % kHashSearchListCount);
#     endif /* (kHashSearchListCount == 1) */

#     if ((kHashSearchListCount == 1)  || (kHashSearchMaxSteps == 1))
    if (idStd != CanRxHashId[rxHandle])
    {
#      if defined( C_ENABLE_NOT_MATCHED_FCT )
      ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#      endif
      goto finishBasicCan;
    }
#     else /* ((kHashSearchListCount == 1)  || (kHashSearchMaxSteps == 1)) */

    i_increment = (vuint16)((winternStd % (kHashSearchListCount - 1)) + (vuint8)1);
    count       = (vsint16)kHashSearchMaxSteps-1;

    /* type of CanRxHashId table depends on the used type of Id */
    while ( idStd != CanRxHashId[rxHandle])
    {
      if (count == (vsint16)0)
      {
#     if defined( C_ENABLE_NOT_MATCHED_FCT )
        ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#     endif
        goto finishBasicCan;
      }
      count--; 
      rxHandle += i_increment;
      if ( rxHandle >= kHashSearchListCount )
      {
        rxHandle -= kHashSearchListCount;
      }
    }
#     endif /* ((kHashSearchListCount == 1)  || (kHashSearchMaxSteps == 1)) */
    rxHandle = CanRxMsgIndirection[rxHandle];
  }
#    else /* (kHashSearchListCount > 0) */
  {
#     if defined( C_ENABLE_NOT_MATCHED_FCT )
    ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#     endif
    goto finishBasicCan;
  }
#    endif /* (kHashSearchListCount > 0) */
#   endif /* defined( C_ENABLE_MIXED_ID ) || !defined( C_ENABLE_EXTENDED_ID ) */ 
#  endif /* defined( C_SEARCH_HASH ) */



  /**************************** handle filtered message ****************************************************/
#  if defined( C_SEARCH_HASH )
  assertInternal((rxHandle < kCanNumberOfRxObjects), kCanAllChannels , kErrorRxHandleWrong);  /* PRQA S 3109 */ /* legal rxHandle ? */
#  else
  if ( rxHandle < CAN_HL_RX_BASIC_STOPINDEX(channel)) 
#  endif
  {
    /* ID found in table */
#  if defined( C_SEARCH_HASH ) 
#  else
#   if defined( C_ENABLE_RX_MSG_INDIRECTION )
    rxHandle = CanRxMsgIndirection[rxHandle];       /* indirection for special sort-algoritms */
#   endif
#  endif

    CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel) = rxHandle;  

    if (CanHL_ReceivedRxHandle( CAN_CHANNEL_CANPARA_ONLY ) == kCanHlContinueRx)
    { 
#  if defined( C_ENABLE_INDICATION_FLAG ) || \
          defined( C_ENABLE_INDICATION_FCT )

      CanHL_IndRxHandle( rxHandle );
      

      return;
#  endif
    }
  }
#  if defined( C_ENABLE_NOT_MATCHED_FCT )
#   if defined( C_SEARCH_HASH )
#   else
  else
  {
    ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
  }
#   endif
#  endif
# else  /* kCanNumberOfRxBasicCANObjects > 0 */
#  if defined( C_ENABLE_NOT_MATCHED_FCT )
  ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#  endif
# endif /* kCanNumberOfRxBasicCANObjects > 0 */

# endif

  goto finishBasicCan;     /* to avoid compiler warning */

/* Msg(4:2015) This label is not a case or default label for a switch statement. MISRA Rule 55 */
finishBasicCan:

  /* make receive buffer free*/


  return;    /* to avoid compiler warnings about label without code */

} /* end of BasicCan */
/* CODE CATEGORY 1 END*/
/* PRQA S 2001 -- */    /* suppress misra message about multiple return and usage of goto */
#endif

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/****************************************************************************
| NAME:             CanFullCanMsgReceived
| CALLED BY:        CanISR()
| PRECONDITIONS:
| INPUT PARAMETERS: internal can chip number
| RETURN VALUES:    none
| DESCRIPTION:      - full can receive
****************************************************************************/
/* PRQA S 2001 ++ */    /* suppress misra message about usage of goto */
/* CODE CATEGORY 1 START*/
static void CanFullCanMsgReceived( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle )
{
  CanReceiveHandle   rxHandle; 

# if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  tCanRxInfoStruct    *pCanRxInfoStruct;
# endif  

  
  # if defined(C_ENABLE_FULLCAN_OVERRUN)
  vuint32 bOverrunPending;
  # endif

  CANDRV_SET_CODE_TEST_POINT(0x101);
   
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(canHwChannel < kCanNumberOfHwChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);   /* PRQA S 3109 */
# endif



  # if defined(C_ENABLE_FULLCAN_OVERRUN)
  bOverrunPending = ((CANRML & CanSlotMask[rxObjHandle]) == CanSlotMask[rxObjHandle]) ? ((vuint32)1) : ((vuint32)0);
  # endif
  
  APPLCANTIMERSTART(kCanLoopCopyRxFullMailBox);
  do 
  {
    CANRMP = CanSlotMask[rxObjHandle]; /* reset interrupt flag */
  
  #if defined (C_ENABLE_FULLCAN_OVERRUN) 
    bOverrunPending++;                 /* only evaluated if overrun activated */
  #endif
    /* **************************************** */
    /*     Copy data                            */
    /* **************************************** */
  
  
  
  #if defined(C_COMP_TI_TMS470)  
    canTempCanObj[channel] = *(tCanTempRamMailBox*)&(CANMSGOBJ(rxObjHandle));   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
  #endif /* TMS470 all compilers */
  
    /* **************************************** */
    /*     Copy data done                       */
    /* **************************************** */
  
  #if defined(C_ENABLE_HW_LOOP_TIMER) 
    /* break the loop after data is copied once */
    if(0 == APPLCANTIMERLOOP(kCanLoopCopyRxFullMailBox))
    { 
      goto finishRxFullCan; /* ignore reception, data might be inconsistent */
    } 
  #endif
  }
  while ( (CANRMP & CanSlotMask[rxObjHandle]) != 0);
  APPLCANTIMEREND(kCanLoopCopyRxFullMailBox);
  
  
  /* **************************************** */
  /*     Normalize data                       */
  /* **************************************** */
  # if defined(C_COMP_TI_TMS470)  
  /* Nothing to do any more, data already in correct order */
  # endif /* TMS470 all compilers */
  
  
  
  

# if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  /* pointer needed for other modules */
  pCanRxInfoStruct =  &canRxInfoStruct[channel];
  (pCanRxInfoStruct->pChipMsgObj) = (CanChipMsgPtr)&(canTempCanObj[channel]);   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
  (pCanRxInfoStruct->pChipData) = (CanChipDataPtr)&(canTempCanObj[channel].CanData);   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
  canRDSRxPtr[channel] = pCanRxInfoStruct->pChipData;
# else
  (canRxInfoStruct[channel].pChipMsgObj) = (CanChipMsgPtr)&(canTempCanObj[channel]);   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
  (canRxInfoStruct[channel].pChipData) = (CanChipDataPtr)&(canTempCanObj[channel].CanData);   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
  canRDSRxPtr[channel] = canRxInfoStruct[channel].pChipData;
# endif

# if defined( C_ENABLE_CAN_RAM_CHECK )
  if(canComStatus[channel] == kCanDisableCommunication)
  {
    goto finishRxFullCan; /* ignore reception */
  }
# endif

#  if defined( C_ENABLE_FULLCAN_OVERRUN )

  if(bOverrunPending > (vuint32)1)
  {
     ApplCanFullCanOverrun( CAN_CHANNEL_CANPARA_ONLY );
  }
#  endif

# if defined( C_HL_ENABLE_REJECT_REMOTE_FRAME_FULLCAN )
  /**************************** reject remote frames  ****************************************/
  /* Suppress reception of remote frames */
  if ( (canTempCanObj[channel].CanMcf & kCanRtr) == kCanRtr) 
  {
    /* Remote Frame -> abandon reception */
    goto finishRxFullCan;
  }
# endif /* C_HL_ENABLE_REJECT_REMOVE_FRAME */

# if defined( C_HL_ENABLE_REJECT_UNWANTED_IDTYPE )
  /**************************** reject messages with unallowed ID type ****************************************/
#  if defined( C_ENABLE_EXTENDED_ID )
#   if defined( C_ENABLE_MIXED_ID )
#   else
  if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) != kCanIdTypeExt)
  {
    goto finishRxFullCan;
  }
#   endif
#  else
  if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) != kCanIdTypeStd)
  {
    goto finishRxFullCan;
  }
#  endif
# endif /* C_HL_ENABLE_REJECT_UNWANTED_IDTYPE */

# if defined( C_ENABLE_COND_RECEIVE_FCT )
  /**************************** conditional message receive function  ****************************************/
  if(canMsgCondRecState[channel]==kCanTrue)
  {
    ApplCanMsgCondReceived( CAN_HL_P_RX_INFO_STRUCT(channel) );
  }
# endif

# if defined( C_ENABLE_RECEIVE_FCT )
  /**************************** call ApplCanMsgReceived() ****************************************************/
  if (APPL_CAN_MSG_RECEIVED( CAN_HL_P_RX_INFO_STRUCT(channel) )==kCanNoCopyData)
  {
     goto finishRxFullCan;
  }
# endif

  /* calculate the message handle to access the generated data for the received message */

  /* brackets to avoid lint info 834 */
  rxHandle = (rxObjHandle - CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel))
# if defined( C_SEARCH_HASH )
                         + kHashSearchListCount
                         + kHashSearchListCountEx
# endif
                         + CAN_HL_RX_FULL_STARTINDEX(canHwChannel);


# if defined( C_ENABLE_RX_MSG_INDIRECTION ) || \
     defined( C_SEARCH_HASH ) 
  rxHandle = CanRxMsgIndirection[rxHandle];
# endif

  assertInternal((rxHandle < kCanNumberOfRxObjects), kCanAllChannels , kErrorRxHandleWrong);  /* PRQA S 3109 */ /* legal rxHandle ? */

  CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel) = rxHandle;  

  if (CanHL_ReceivedRxHandle( CAN_CHANNEL_CANPARA_ONLY ) == kCanHlContinueRx)
  { 
# if defined( C_ENABLE_INDICATION_FLAG ) || \
        defined( C_ENABLE_INDICATION_FCT )

    CanHL_IndRxHandle( rxHandle );

    ;

    return;
# endif
  }

  goto finishRxFullCan;     /* to avoid compiler warning */

/* Msg(4:2015) This label is not a case or default label for a switch statement. MISRA Rule 55 */
finishRxFullCan:

  /* make receive buffer free*/
  ;


  return;    /* to avoid compiler warnings about label without code */
}
/* CODE CATEGORY 1 END*/
/* PRQA S 2001 -- */    /* suppress misra message about usage of goto */

#endif

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )  || \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
# if ( kCanNumberOfRxObjects > 0 )
/****************************************************************************
| NAME:             CanHL_ReceivedRxHandle
| CALLED BY:        CanBasicCanMsgReceived, CanFullCanMsgReceived
| PRECONDITIONS:
| INPUT PARAMETERS: Handle of received Message to access generated data
| RETURN VALUES:    none
| DESCRIPTION:      DLC-check, Precopy and copy of Data for received message
****************************************************************************/
/* CODE CATEGORY 1 START*/
static vuint8 CanHL_ReceivedRxHandle( CAN_CHANNEL_CANTYPE_ONLY )
{
#  if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  tCanRxInfoStruct    *pCanRxInfoStruct;
#  endif

#  if defined( C_ENABLE_COPY_RX_DATA )
#   if C_SECURITY_LEVEL > 20
  CanDeclareGlobalInterruptOldStatus
#   endif
#  endif

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(channel < kCanNumberOfChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);  /* PRQA S 3109 */
# endif

#  if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  pCanRxInfoStruct =  &canRxInfoStruct[channel];
#  endif

#  if defined( C_ENABLE_MULTI_ECU_PHYS )
  if ( (CanRxIdentityAssignment[CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)] & V_ACTIVE_IDENTITY_MSK) == (tVIdentityMsk)0 )
  {
    /* message is not a receive message in the active indentity */
    CANDRV_SET_CODE_TEST_POINT(0x10B);
    return  kCanHlFinishRx;
  }
#  endif


#  if defined( C_ENABLE_DLC_CHECK )  
#   if defined( C_ENABLE_DLC_CHECK_MIN_DATALEN )
  if ( (CanGetRxMinDataLen(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel))) > CanRxActualDLC( CAN_HL_P_RX_INFO_STRUCT(channel) ) )
#   else
  if ( (CanGetRxDataLen(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel))) > CanRxActualDLC( CAN_HL_P_RX_INFO_STRUCT(channel) ) )
#   endif
  {
    /* ##RI1.4 - 2.7: Callbackfunction-DLC-Check */
#   if defined( C_ENABLE_DLC_FAILED_FCT )
    ApplCanMsgDlcFailed( CAN_HL_P_RX_INFO_STRUCT(channel) ); 
#   endif  /*C_ENABLE_DLC_FAILED_FCT */
    return  kCanHlFinishRx;
  }
#  endif

#  if defined( C_ENABLE_VARIABLE_RX_DATALEN )
  CanSetVariableRxDatalen (CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel), CanRxActualDLC( CAN_HL_P_RX_INFO_STRUCT(channel)));
#  endif

#  if defined( C_ENABLE_GENERIC_PRECOPY )
  if ( APPL_CAN_GENERIC_PRECOPY( CAN_HL_P_RX_INFO_STRUCT(channel) ) != kCanCopyData)
  {
    return kCanHlFinishRx;  
  }
#  endif

#  if defined( C_ENABLE_PRECOPY_FCT )
#   if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
#   else
  if ( CanGetApplPrecopyPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)) != V_NULL )    /*precopy routine */
#   endif
  {
    /* canRxHandle in indexed drivers only for consistancy check in higher layer modules */
    canRxHandle[channel] = CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel);
    
    if ( CanGetApplPrecopyPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel))( CAN_HL_P_RX_INFO_STRUCT(channel) )==kCanNoCopyData )
    {  /* precopy routine returns kCanNoCopyData:   */
      return  kCanHlFinishRx;
    }                      /* do not copy data check next irpt */
  }
#  endif

#  if defined( C_ENABLE_COPY_RX_DATA )
  /* no precopy or precopy returns kCanCopyData : copy data -- */
  /* copy via index -------------------------------------------*/
  if ( CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)) != V_NULL )      /* copy if buffer exists */
  {
    /* copy data ---------------------------------------------*/
#   if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptDisable();
#   endif
    CANDRV_SET_CODE_TEST_POINT(0x107);
#   if defined( C_ENABLE_COPY_RX_DATA_WITH_DLC )
    if ( CanRxActualDLC( CAN_HL_P_RX_INFO_STRUCT(channel)) < CanGetRxDataLen(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)) )
    {
#    if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )    
      /*lint -e616 -e825 fallthrough wanted */
      #if defined(C_COMP_TI_TMS470)           
      switch(CanRxActualDLC(CAN_HL_P_RX_INFO_STRUCT(channel)))   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
      {
        /* PRQA S 0312, 2003 9 */ /* MISRA Rule 11.5: Volatile qualifier not required */ /* MISRA Rule 15.2: intended fallthrough for efficient copy  */
        case 8:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[7] = ((vuint8*)pCanRxInfoStruct->pChipData)[7];
        case 7:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[6] = ((vuint8*)pCanRxInfoStruct->pChipData)[6];
        case 6:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[5] = ((vuint8*)pCanRxInfoStruct->pChipData)[5];
        case 5:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[4] = ((vuint8*)pCanRxInfoStruct->pChipData)[4];
        case 4:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[3] = ((vuint8*)pCanRxInfoStruct->pChipData)[3];
        case 3:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[2] = ((vuint8*)pCanRxInfoStruct->pChipData)[2];
        case 2:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[1] = ((vuint8*)pCanRxInfoStruct->pChipData)[1];
        case 1:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[0] = ((vuint8*)pCanRxInfoStruct->pChipData)[0];
        case 0:  break;
        default: break;
      }
      #endif
      /*lint +e616 +e825 fallthrough wanted */
#    else
      /*lint -e616 -e825 fallthrough wanted */
      #if defined(C_COMP_TI_TMS470)           
      switch(CanRxActualDLC(CAN_HL_P_RX_INFO_STRUCT(channel)))   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
      {
        /* PRQA S 0312, 2003 9 */ /* MISRA Rule 11.5: Volatile qualifier not required */ /* MISRA Rule 15.2: intended fallthrough for efficient copy  */
        case 8:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[7] = ((vuint8*)canRxInfoStruct[channel].pChipData)[7];
        case 7:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[6] = ((vuint8*)canRxInfoStruct[channel].pChipData)[6];
        case 6:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[5] = ((vuint8*)canRxInfoStruct[channel].pChipData)[5];
        case 5:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[4] = ((vuint8*)canRxInfoStruct[channel].pChipData)[4];
        case 4:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[3] = ((vuint8*)canRxInfoStruct[channel].pChipData)[3];
        case 3:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[2] = ((vuint8*)canRxInfoStruct[channel].pChipData)[2];
        case 2:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[1] = ((vuint8*)canRxInfoStruct[channel].pChipData)[1];
        case 1:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[0] = ((vuint8*)canRxInfoStruct[channel].pChipData)[0];
        case 0:  break;
        default: break;
      }
      #endif
      /*lint +e616 +e825 fallthrough wanted */
#    endif 
    }
    else
#   endif   /* C_ENABLE_COPY_RX_DATA_WITH_DLC */
    {
#   if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )    
      /*lint -e616 -e825 fallthrough wanted */
      #if defined(C_COMP_TI_TMS470)           
      switch(CanGetRxDataLen(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
      {
        /* PRQA S 0312, 2003 9 */ /* MISRA Rule 11.5: Volatile qualifier not required */ /* MISRA Rule 15.2: intended fallthrough for efficient copy  */
        case 8:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[7] = ((vuint8*)pCanRxInfoStruct->pChipData)[7];
        case 7:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[6] = ((vuint8*)pCanRxInfoStruct->pChipData)[6];
        case 6:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[5] = ((vuint8*)pCanRxInfoStruct->pChipData)[5];
        case 5:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[4] = ((vuint8*)pCanRxInfoStruct->pChipData)[4];
        case 4:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[3] = ((vuint8*)pCanRxInfoStruct->pChipData)[3];
        case 3:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[2] = ((vuint8*)pCanRxInfoStruct->pChipData)[2];
        case 2:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[1] = ((vuint8*)pCanRxInfoStruct->pChipData)[1];
        case 1:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[0] = ((vuint8*)pCanRxInfoStruct->pChipData)[0];
        case 0:  break;
        default: break;
      }
      #endif
      /*lint +e616 +e825 fallthrough wanted */
#   else
      /*lint -e616 -e825 fallthrough wanted */
      #if defined(C_COMP_TI_TMS470)           
      switch(CanGetRxDataLen(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))   /* PRQA S 0310 */ /* MISRA Rule 11.4: Casting to different object type for efficient access to hardware */
      {
        /* PRQA S 0312, 2003 9 */ /* MISRA Rule 11.5: Volatile qualifier not required */ /* MISRA Rule 15.2: intended fallthrough for efficient copy  */
        case 8:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[7] = ((vuint8*)canRxInfoStruct[channel].pChipData)[7];
        case 7:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[6] = ((vuint8*)canRxInfoStruct[channel].pChipData)[6];
        case 6:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[5] = ((vuint8*)canRxInfoStruct[channel].pChipData)[5];
        case 5:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[4] = ((vuint8*)canRxInfoStruct[channel].pChipData)[4];
        case 4:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[3] = ((vuint8*)canRxInfoStruct[channel].pChipData)[3];
        case 3:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[2] = ((vuint8*)canRxInfoStruct[channel].pChipData)[2];
        case 2:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[1] = ((vuint8*)canRxInfoStruct[channel].pChipData)[1];
        case 1:  ((vuint8*)CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)))[0] = ((vuint8*)canRxInfoStruct[channel].pChipData)[0];
        case 0:  break;
        default: break;
      }
      #endif
      /*lint +e616 +e825 fallthrough wanted */
#   endif 
    }
#   if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptRestore();
#   endif
  }
#  endif /* ( C_ENABLE_COPY_RX_DATA ) */

  CANDRV_SET_CODE_TEST_POINT(0x105);
  return kCanHlContinueRx;
} /* end of CanReceivceRxHandle() */
/* CODE CATEGORY 1 END*/

#  if defined( C_ENABLE_INDICATION_FLAG ) || \
     defined( C_ENABLE_INDICATION_FCT )
/****************************************************************************
| NAME:             CanHL_IndRxHandle
| CALLED BY:        CanBasicCanMsgReceived, CanFullCanMsgReceived
| PRECONDITIONS:
| INPUT PARAMETERS: Handle of received Message to access generated data
| RETURN VALUES:    none
| DESCRIPTION:      DLC-check, Precopy and copy of Data for received message
****************************************************************************/
/* CODE CATEGORY 1 START*/
static void CanHL_IndRxHandle( CanReceiveHandle rxHandle )
{
#   if defined( C_ENABLE_INDICATION_FLAG )
#    if C_SECURITY_LEVEL > 20
  CanDeclareGlobalInterruptOldStatus
#    endif
#   endif

#   if defined( C_ENABLE_INDICATION_FLAG )
#    if C_SECURITY_LEVEL > 20
  CanNestedGlobalInterruptDisable();
#    endif
  CanIndicationFlags._c[CanGetIndicationOffset(rxHandle)] |= CanGetIndicationMask(rxHandle);
#    if C_SECURITY_LEVEL > 20
  CanNestedGlobalInterruptRestore();
#    endif
#   endif

#   if defined( C_ENABLE_INDICATION_FCT )
#    if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
#    else
  if ( CanGetApplIndicationPtr(rxHandle) != V_NULL )
#    endif
  {
    CanGetApplIndicationPtr(rxHandle)(rxHandle);  /* call IndicationRoutine */
  }
#   endif
}
/* CODE CATEGORY 1 END*/
#  endif /* C_ENABLE_INDICATION_FLAG || C_ENABLE_INDICATION_FCT  */
# endif /* ( kCanNumberOfRxObjects > 0 ) */
#endif


/****************************************************************************
| NAME:             CanHL_TxConfirmation
| CALLED BY:        CanISR()
| PRECONDITIONS:
| INPUT PARAMETERS: - internal can chip number
|                   - interrupt ID
| RETURN VALUES:    none
| DESCRIPTION:      - full can transmit
****************************************************************************/
/* PRQA S 2001 ++ */    /* suppress misra message about usage of goto */
/* CODE CATEGORY 1 START*/
static void CanHL_TxConfirmation( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle txObjHandle)
{
  CanObjectHandle       logTxObjHandle;
  CanTransmitHandle     txHandle;

 
#if defined( C_ENABLE_TRANSMIT_QUEUE )
  CanSignedTxHandle         queueElementIdx;    /* use as signed due to loop */
  CanSignedTxHandle         elementBitIdx;
  tCanQueueElementType             elem;
  CanDeclareGlobalInterruptOldStatus
#else
# if defined( C_ENABLE_CONFIRMATION_FLAG )
#  if C_SECURITY_LEVEL > 20
  CanDeclareGlobalInterruptOldStatus
#  endif
# endif
#endif


#if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION ) && \
    defined( C_ENABLE_TRANSMIT_QUEUE )
  vuint8 rc;
#endif

  #if defined (C_ENABLE_CANCEL_IN_HW)
  # if defined( C_ENABLE_OBSERVE_TXCANCELATION )
  vuint8 canMsgTransmitted;
  # endif
  #endif
  
  
  
  #if defined (C_ENABLE_CANCEL_IN_HW)
  # if defined( C_ENABLE_OBSERVE_TXCANCELATION )
  canMsgTransmitted = kCanMsgUndefined;
  # endif
  #endif
  


# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(canHwChannel < kCanNumberOfHwChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);  /* PRQA S 3109 */
# endif



  logTxObjHandle = (CanObjectHandle)((vsintx)txObjHandle + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));

  {
  #if defined(C_COMP_TI_TMS470)            
  # if defined(C_ENABLE_HECC_WORKAROUND_1)
    if(CANTRS == (tCanRegType)0x00000000)
    {
  #  if !(defined( C_ENABLE_TRANSMIT_QUEUE ) || (defined (C_ENABLE_CONFIRMATION_FLAG) && (C_SECURITY_LEVEL > 20)) )
  #   if (!defined(C_ENABLE_RX_FULLCAN_POLLING)      || \
          !defined(C_ENABLE_RX_BASICCAN_POLLING) )   && \
          defined(C_ENABLE_TX_POLLING)
      CanDeclareGlobalInterruptOldStatus
  #   endif
  #  endif /* TRANSMIT_QUEUE / CONFIRMATION_FLAG / SECURITY_LEVEL */
  #  if (!defined(C_ENABLE_RX_FULLCAN_POLLING)      || \
         !defined(C_ENABLE_RX_BASICCAN_POLLING) )   && \
         defined(C_ENABLE_TX_POLLING) 
      /* in case of Tx polling mode and Rx interrupt mode the following
         code has to be protected */
      CanNestedGlobalInterruptDisable();
  #  endif /* *_POLLING */
  #  if defined (C_ENABLE_HECC_WORKAROUND_1_WITHSCC)
  #   if defined (C_MULTIPLE_RECEIVE_CHANNEL)
      if (CanControllerMode[channel] == kCanSCCMode) {
        while((CANES & kCanRm) != 0)
        {
          ; /* while CAN cell is receiving a message */
        }
      }
  #    else  /* MULTIPLE_RECEIVE_CHANNEL */
  #    if (kCanControllerMode == kCanSCCMode)
      while((CANES & kCanRm) != 0)
      {
        ; /* while CAN cell is receiving a message */
      }
  #    endif /* kCanControllerMode */
  #   endif  /* MULTIPLE_RECEIVE_CHANNEL */
  #  endif    /* C_ENABLE_HECC_WORKAROUND_1_WITHSCC */
      CANTRS = gCANTRS[channel];
      gCANTRS[channel] = (tCanRegType)0x00000000;
  #  if (!defined(C_ENABLE_RX_FULLCAN_POLLING)      || \
         !defined(C_ENABLE_RX_BASICCAN_POLLING) )   && \
         defined(C_ENABLE_TX_POLLING)
      CanNestedGlobalInterruptRestore();
  #  endif /* *_POLLING */
    }
  # endif /* HECC_WORKAROUND_2 */
  #endif  /* TMS470 */
  
  
    {
  
  
  #if defined (C_ENABLE_CANCEL_IN_HW)
  
  
      if ((CANTA & CanSlotMask[txObjHandle]) != 0) 
      {
        /* Workaround if CANTA and CANAA are both set for the message object */
        if ((CANAA & CanSlotMask[txObjHandle]) != 0) {
          CANAA = CanSlotMask[txObjHandle];
          CANGIF0 = kCanAaif0; /* clear abort acknowledge interrupt */
        } 
        CANTA = CanSlotMask[txObjHandle];
  # if defined( C_ENABLE_OBSERVE_TXCANCELATION ) 
        canMsgTransmitted = kCanMsgTransmitted;
  # endif
      } 
      else 
      {
  # if defined( C_ENABLE_OBSERVE_TXCANCELATION ) 
        canMsgTransmitted = kCanMsgCanceled;
  # endif
        CANAA = CanSlotMask[txObjHandle];
        CANGIF0 = kCanAaif0; /* clear abort acknowledge interrupt */
      }
  #else
      CANTA = CanSlotMask[txObjHandle];
  #endif
  
  
    }
  
  }

  txHandle = canHandleCurTxObj[logTxObjHandle];           /* get saved handle */

  /* check associated transmit handle */
  if (txHandle == kCanBufferFree)
  {
    assertInternal (0, channel, kErrorTxHandleWrong);          /* PRQA S 3109 */ /*lint !e506 !e774*/
    goto finishCanHL_TxConfirmation;
  }  

#if defined( C_ENABLE_TX_OBSERVE ) || \
    defined( C_ENABLE_CAN_TX_CONF_FCT )
# if defined( C_ENABLE_CANCEL_IN_HW )
  if (canMsgTransmitted == kCanMsgTransmitted) 
# endif
  {
# if defined( C_ENABLE_TX_OBSERVE )
    {
      ApplCanTxObjConfirmed( CAN_CHANNEL_CANPARA_FIRST logTxObjHandle );
    }
# endif

# if defined( C_ENABLE_CAN_TX_CONF_FCT )
/* ##RI-1.10 Common Callbackfunction in TxInterrupt */
    txInfoStructConf[channel].Handle  = txHandle;
    APPL_CAN_TX_CONFIRMATION(&txInfoStructConf[channel]);
# endif
  }
#endif /* defined( C_ENABLE_TX_OBSERVE ) || defined( C_ENABLE_CAN_TX_CONF_FCT ) */

#if defined( C_ENABLE_TRANSMIT_QUEUE )
# if defined( C_ENABLE_TX_FULLCAN_OBJECTS )  
  if (txObjHandle != CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel))
  {
    canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;                 /* free msg object of FullCAN or LowLevel Tx obj. */
  }
# endif
#else
  canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;                   /* free msg object if queue is not used */
#endif

  if (txHandle != kCanBufferCancel)
  {

#if defined( C_ENABLE_MULTI_ECU_PHYS )
    assertInternal(((CanTxIdentityAssignment[txHandle] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk)0 ), 
                                                                channel , kErrorInternalDisabledTxMessage);  /* PRQA S 3109 */
#endif

#if defined( C_ENABLE_CONFIRMATION_FLAG )       /* set transmit ready flag  */
# if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptDisable();
# endif
    CanConfirmationFlags._c[CanGetConfirmationOffset(txHandle)] |= CanGetConfirmationMask(txHandle);
# if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptRestore();
# endif
#endif

#if defined( C_ENABLE_CONFIRMATION_FCT )
    {
# if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
# else
      if ( CanGetApplConfirmationPtr(txHandle) != V_NULL )
# endif
      {
        (CanGetApplConfirmationPtr(txHandle))(txHandle);   /* call completion routine  */
      }
    }
#endif /* C_ENABLE_CONFIRMATION_FCT */

  } /* end if kCanBufferCancel */
  
#if defined( C_ENABLE_TRANSMIT_QUEUE )
# if defined( C_ENABLE_TX_FULLCAN_OBJECTS ) 
  if (txObjHandle == CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel)) 
# endif
  {
    CanNestedGlobalInterruptDisable();                /* ESCAN00008914 */

    for(queueElementIdx = CAN_HL_TXQUEUE_STOPINDEX(channel) - (CanSignedTxHandle)1; 
                             queueElementIdx >= CAN_HL_TXQUEUE_STARTINDEX(channel); queueElementIdx--)
    {
      elem = canTxQueueFlags[queueElementIdx];
      if(elem != (tCanQueueElementType)0) /* is there any flag set in the queue element? */
      {

        CanNestedGlobalInterruptRestore();

        /* start the bitsearch */
        #if defined( C_CPUTYPE_32BIT )
        if((elem & (tCanQueueElementType)0xFFFF0000) != (tCanQueueElementType)0)
        {
          if((elem & (tCanQueueElementType)0xFF000000) != (tCanQueueElementType)0)
          {
            if((elem & (tCanQueueElementType)0xF0000000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 28] + 28;
            }
            else /*0x0F000000*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 24] + 24;
            }
          }
          else
          {
            if((elem & (tCanQueueElementType)0x00F00000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 20] + 20;
            }
            else /* 0x000F0000*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 16] + 16;
            }
          }
        }
        else
        #endif
        {
        #if defined( C_CPUTYPE_32BIT ) 
          if((elem & (tCanQueueElementType)0x0000FF00) != (tCanQueueElementType)0)
          {
            if((elem & (tCanQueueElementType)0x0000F000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 12] + 12;
            }
            else /*0x00000F00*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 8] + 8;
            }
          }
          else
        #endif
          {
            if((elem & (tCanQueueElementType)0x000000F0) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 4] + 4;
            }
            else /* 0x0000000F*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem];
            }
          }
        }
        txHandle = (((CanTransmitHandle)queueElementIdx << kCanTxQueueShift) + (CanTransmitHandle)elementBitIdx) - CAN_HL_TXQUEUE_PADBITS(channel);
        {

            /* compute the logical message handle */
            CanNestedGlobalInterruptDisable();
 
            if ( (canTxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) != (tCanQueueElementType)0 )
            {
              canTxQueueFlags[queueElementIdx] &= ~CanShiftLookUp[elementBitIdx]; /* clear flag from the queue */

              CanNestedGlobalInterruptRestore();  
              canHandleCurTxObj[logTxObjHandle] = txHandle;/* Save hdl of msgObj to be transmitted*/
# if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
              rc = CanCopyDataAndStartTransmission( CAN_CHANNEL_CANPARA_FIRST txObjHandle,txHandle); 
              if ( rc == kCanTxNotify)
              {
                APPLCANCANCELNOTIFICATION(channel, txHandle);
              }
# else       /* C_ENABLE_CAN_CANCEL_NOTIFICATION */
              (void)CanCopyDataAndStartTransmission( CAN_CHANNEL_CANPARA_FIRST txObjHandle,txHandle); 
# endif /* C_ENABLE_CAN_CANCEL_NOTIFICATION */

              goto finishCanHL_TxConfirmation;
            }
            /* meanwhile, the queue is empty. E.g. due to CanOffline on higher level */
            canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;  /* free msg object if queue is empty */
            CanNestedGlobalInterruptRestore();  
            goto finishCanHL_TxConfirmation;
            
        }
        /* no entry found in Queue */
# if defined( CANHL_TX_QUEUE_BIT )
# else
        CanNestedGlobalInterruptDisable();                /*lint !e527 ESCAN00008914 */
                                                 /* unreachable in case of Bit-Queue */
# endif                                                 
      }
    }

    canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;  /* free msg object if queue is empty */
    CanNestedGlobalInterruptRestore();                 /* ESCAN00008914 */
  }
#endif
  /* check for next msg object in queue and transmit it */

/* Msg(4:2015) This label is not a case or default label for a switch statement. MISRA Rule 55 */
finishCanHL_TxConfirmation:


  return;

} /* END OF CanTxInterrupt */
/* CODE CATEGORY 1 END*/
/* PRQA S 2001 -- */    /* suppress misra message about usage of goto */


#if defined( C_ENABLE_ECU_SWITCH_PASS )
/************************************************************************
* NAME:               CanSetActive
* CALLED BY:          application
* PRECONDITIONS:      none
* PARAMETER:          none or channel
* RETURN VALUE:       none
* DESCRIPTION:        Set the CAN driver into active mode
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetActive( CAN_CHANNEL_CANTYPE_ONLY )
{
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#endif

  canPassive[channel] = 0;
} /* END OF CanSetActive */
/* CODE CATEGORY 4 END*/

/************************************************************************
* NAME:               CanSetPassive
* CALLED BY:          application
* PRECONDITIONS:      none
* PARAMETER:          none or channel
* RETURN VALUE:       none
* DESCRIPTION:        Set the can driver into passive mode
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetPassive( CAN_CHANNEL_CANTYPE_ONLY )
{
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);      /* PRQA S 3109 */
#endif

  canPassive[channel] = 1;
 
# if defined( C_ENABLE_TRANSMIT_QUEUE )
  /* clear all Tx queue flags: */
  CanDelQueuedObj( CAN_CHANNEL_CANPARA_ONLY ); 
# endif
 

} /* END OF CanSetPassive */
/* CODE CATEGORY 4 END*/
#endif /* IF defined( C_ENABLE_ECU_SWITCH_PASS ) */


#if defined( C_ENABLE_OFFLINE )
/************************************************************************
* NAME:               CanOnline( CanChannelHandle channel )
* CALLED BY:          netmanagement
* PRECONDITIONS:      none
* PARAMETER:          none or channel
* RETURN VALUE:       none
* DESCRIPTION:        Switch on transmit path
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanOnline(CAN_CHANNEL_CANTYPE_ONLY)
{
  CanDeclareGlobalInterruptOldStatus

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
#endif

  CanNestedGlobalInterruptDisable();

  canStatus[channel] |= kCanTxOn;

# if defined( C_ENABLE_ONLINE_OFFLINE_CALLBACK_FCT )
  APPL_CAN_ONLINE(CAN_CHANNEL_CANPARA_ONLY);
# endif
  CanNestedGlobalInterruptRestore();

}
/* CODE CATEGORY 4 END*/


/************************************************************************
* NAME:               CanOffline( CanChannelHandle channel )
* CALLED BY:          netmanagement
* PRECONDITIONS:      none
* PARAMETER:          none or channel
* RETURN VALUE:       none
* DESCRIPTION:        Switch off transmit path
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanOffline(CAN_CHANNEL_CANTYPE_ONLY)
{
  CanDeclareGlobalInterruptOldStatus

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#endif

  CanNestedGlobalInterruptDisable();

  canStatus[channel] &= kCanTxNotOn;

# if defined( C_ENABLE_ONLINE_OFFLINE_CALLBACK_FCT )
  APPL_CAN_OFFLINE(CAN_CHANNEL_CANPARA_ONLY);
# endif
  CanNestedGlobalInterruptRestore();

# if defined( C_ENABLE_TRANSMIT_QUEUE )
  CanDelQueuedObj( CAN_CHANNEL_CANPARA_ONLY );
# endif

}
/* CODE CATEGORY 4 END*/
#endif /* if defined( C_ENABLE_OFFLINE ) */


#if defined( C_ENABLE_PART_OFFLINE )
/************************************************************************
* NAME:               CanSetPartOffline
* CALLED BY:          application
* PRECONDITIONS:      none
* PARAMETER:          (channel), sendGroup
* RETURN VALUE:       none
* DESCRIPTION:        Switch partial off transmit path
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetPartOffline(CAN_CHANNEL_CANTYPE_FIRST vuint8 sendGroup)
{
  CanDeclareGlobalInterruptOldStatus

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
#endif

  CanNestedGlobalInterruptDisable();
  canTxPartOffline[channel] |= sendGroup;   /* set offlinestate and Save for use of CanOnline/CanOffline */
  CanNestedGlobalInterruptRestore();
}
/* CODE CATEGORY 4 END*/


/************************************************************************
* NAME:               CanSetPartOnline
* CALLED BY:          application
* PRECONDITIONS:      none
* PARAMETER:          (channel), invSendGroup
* RETURN VALUE:       none
* DESCRIPTION:        Switch partial on transmit path
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetPartOnline(CAN_CHANNEL_CANTYPE_FIRST vuint8 invSendGroup)
{
  CanDeclareGlobalInterruptOldStatus

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
#endif

  CanNestedGlobalInterruptDisable();
  canTxPartOffline[channel] &= invSendGroup;
  CanNestedGlobalInterruptRestore();
}
/* CODE CATEGORY 4 END*/


/************************************************************************
* NAME:               CanGetPartMode
* CALLED BY:          application
* PRECONDITIONS:      none
* PARAMETER:          none or channel
* RETURN VALUE:       canTxPartOffline
* DESCRIPTION:        return status of partoffline-Mode
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanGetPartMode(CAN_CHANNEL_CANTYPE_ONLY)
{
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
#endif

  return canTxPartOffline[channel];
}
/* CODE CATEGORY 4 END*/
#endif


/****************************************************************************
| NAME:             CanGetStatus
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none or channel
| RETURN VALUES:    Bit coded status (more than one status can be set):
|                   kCanTxOn
|                   kCanHwIsStop        
|                   kCanHwIsInit        
|                   kCanHwIsInconsistent
|                   kCanHwIsWarning     
|                   kCanHwIsPassive     
|                   kCanHwIsBusOff      
|                   kCanHwIsSleep       
| DESCRIPTION:      returns the status of the transmit path and the CAN hardware.
|                   Only one of the statusbits Sleep,Busoff,Passiv,Warning is set.
|                   Sleep has the highest priority, error warning the lowerst. 
****************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 vuint8 C_API_2 CanGetStatus( CAN_CHANNEL_CANTYPE_ONLY )
{
#if defined( C_ENABLE_EXTENDED_STATUS )
#endif


#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
#endif

#if defined( C_ENABLE_EXTENDED_STATUS )
  /* Update content of CANES register */
  CANES = (CANES & kCanErrorMask);

# if defined( C_ENABLE_SLEEP_WAKEUP )
  /***************************** verify Sleep mode *************************************/
  if ( CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY)   )  { return ( VUINT8_CAST ( canStatus[channel] | kCanHwIsSleep ) ); }

# endif

  /***************************** verify Stop mode *************************************/
  if ( CanLL_HwIsStop(CAN_HW_CHANNEL_CANPARA_ONLY)    )  { return ( VUINT8_CAST ( canStatus[channel] | kCanHwIsStop ) ); }

  /***************************** verify Busoff *************************************/
  if ( CanLL_HwIsBusOff(CAN_HW_CHANNEL_CANPARA_ONLY)  )  { return (( VUINT8_CAST  canStatus[channel] | kCanHwIsBusOff ) ); }

  /***************************** verify Error Passiv *******************************/
  {
    if ( CanLL_HwIsPassive(CAN_HW_CHANNEL_CANPARA_ONLY) )  { return ( VUINT8_CAST ( canStatus[channel] | kCanHwIsPassive ) ); }
  }

  /***************************** verify Error Warning ******************************/
  {
    if ( CanLL_HwIsWarning(CAN_HW_CHANNEL_CANPARA_ONLY) )  { return ( VUINT8_CAST ( canStatus[channel] | kCanHwIsWarning ) ); }
  }
#endif
  return ( VUINT8_CAST (canStatus[channel] & kCanTxOn) );

} /* END OF CanGetStatus */
/* CODE CATEGORY 3 END*/


/****************************************************************************
| NAME:             CanSleep
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none or channel
| RETURN VALUES:    kCanOk, if CanSleep was successfull
|                   kCanFailed, if function failed
|                   kCanNotSupported, if this function is not supported
| DESCRIPTION:      disable CAN 
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanSleep(CAN_CHANNEL_CANTYPE_ONLY)
{
#if defined( C_ENABLE_SLEEP_WAKEUP )
  vuint8         canReturnCode;
#endif

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
#endif
  assertUser((canCanInterruptCounter[channel] == (vsintx)0), channel, kErrorDisabledCanInt);    /* PRQA S 3109 */

#if defined( C_ENABLE_COND_RECEIVE_FCT )
  /* this has to be done, even if SLEEP_WAKEUP is not enabled */
  canMsgCondRecState[channel] = kCanTrue;
#endif

#if defined( C_ENABLE_SLEEP_WAKEUP )

  assertUser((canStatus[channel] & kCanTxOn) != kCanTxOn, channel, kErrorCanOnline);   /* PRQA S 3109 */

  {
    assertUser(!CanLL_HwIsStop(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanStop);     /* PRQA S 3109 */
    {
      tCanRegType tmpCanMC;
    
    
    
      /* Delete pending Rx messages */
    # if defined (C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC)
    #  if defined(C_SINGLE_RECEIVE_CHANNEL)
    #   if(kCanControllerMode == kCanSCCMode)
      CANRMP = kCanRmpDeletePendingSCC;
    #   else /* kCanControllerMode == kCanSCCMode */
      CANRMP = kCanRmpDeletePendingHECC;
    #   endif /* kCanControllerMode == kCanSCCMode */
    #  else /* C_SINGLE_RECEIVE_CHANNEL */
      if(CanControllerMode[channel] == kCanSCCMode)
      {
        CANRMP = kCanRmpDeletePendingSCC;
      }
      else
      {
        CANRMP = kCanRmpDeletePendingHECC;
      }
    #  endif /* C_SINGLE_RECEIVE_CHANNEL */
    # else /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
      CANRMP = kCanRmpDeletePendingHECC;
    # endif /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
    
    
      tmpCanMC = CANMC | kCanPdr | kCanWuba;
      CAN_WRITE_REGISTER(&CANMC, (tCanRegType)0xFFFFFFFF, tmpCanMC); /* set power down request bit */
    
    
      APPLCANTIMERSTART(kCanLoopWaitPowerDownMode);
      while(((CANES & kCanPda) != kCanPda) && ((CANMC & kCanPdr) == kCanPdr))
      {
    # if defined(C_ENABLE_HW_LOOP_TIMER) 
        if(0 == APPLCANTIMERLOOP(kCanLoopWaitPowerDownMode))
        {
          break;
        }
    # else
        ; /* wait until CAN controller allows configuration access */
    # endif
      }
      APPLCANTIMEREND(kCanLoopWaitPowerDownMode);
    
      if((CANES & kCanPda) != kCanPda)
      {
        canReturnCode = kCanFailed;
      }
      else
      {
    
        if (CANRMP == (tCanRegType)0) 
        {
          /* No pending */
          canReturnCode = kCanOk;
        } else {    
          /* Rx message is pending -> Wakeup to avoid permanent Rx interrupts which cannot be handled in sleep mode */
    
    
          tmpCanMC = CANMC & ~kCanPdr;
          CAN_WRITE_REGISTER(&CANMC, (tCanRegType)0xFFFFFFFF, tmpCanMC); /* clear power down request bit */ 
    
    
          APPLCANTIMERSTART(kCanLoopWaitLeavePowerDownMode);
          while((CANES & kCanPda) == kCanPda)
          {
          # if defined(C_ENABLE_HW_LOOP_TIMER) 
            if(0 == APPLCANTIMERLOOP(kCanLoopWaitLeavePowerDownMode))
            {  
              break;
            }    
          # else    
            ; /* wait until CAN controller allows configuration access */
          # endif
          }    
          APPLCANTIMEREND(kCanLoopWaitLeavePowerDownMode);
    
          CanInit(CAN_CHANNEL_CANPARA_FIRST lastInitObject[channel]);
          canReturnCode = kCanFailed;
    
        }
      }
    }
  }
  return canReturnCode;
#else
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && \
     defined( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;
# endif
  return kCanNotSupported;
#endif
} /* END OF CanSleep */
/* CODE CATEGORY 4 END*/

/****************************************************************************
| NAME:             CanWakeUp
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none or channel
| RETURN VALUES:    kCanOk, if CanWakeUp was successfull
|                   kCanFailed, if function failed
|                   kCanNotSupported, if this function is not supported
| DESCRIPTION:      enable CAN 
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanWakeUp( CAN_CHANNEL_CANTYPE_ONLY )
{
#if defined( C_ENABLE_SLEEP_WAKEUP )
  vuint8         canReturnCode;


#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#endif
  assertUser((canCanInterruptCounter[channel] == (vsintx)0), channel, kErrorDisabledCanInt);    /* PRQA S 3109 */

  {
    tCanRegType tmpCanMC;
    
    
    tmpCanMC = CANMC & ~kCanPdr;
    CAN_WRITE_REGISTER(&CANMC, (tCanRegType)0xFFFFFFFF, tmpCanMC); /* clear power down request bit */ 
    
    
    APPLCANTIMERSTART(kCanLoopWaitLeavePowerDownMode);
    while((CANES & kCanPda) == kCanPda)
    {
    # if defined(C_ENABLE_HW_LOOP_TIMER) 
      if(0 == APPLCANTIMERLOOP(kCanLoopWaitLeavePowerDownMode))
      {  
        break;
      }    
    # else    
      ; /* wait until CAN controller allows configuration access */
    # endif
    }    
    APPLCANTIMEREND(kCanLoopWaitLeavePowerDownMode);
    
    CanInit(CAN_CHANNEL_CANPARA_FIRST lastInitObject[channel]);
    
    if((CANES & kCanPda) == kCanPda)
    {  
      canReturnCode = kCanFailed;
    }    
    else
    {
      canReturnCode = kCanOk;
    }    
  }
  return canReturnCode;
#else
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && \
     defined( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;
# endif
  return kCanNotSupported;
#endif /* C_ENABLE_SLEEP_WAKEUP */
} /* END OF CanWakeUp */
/* CODE CATEGORY 4 END*/


#if defined( C_ENABLE_STOP )
/****************************************************************************
| NAME:             CanStop
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    kCanOk, if success
|                   kCanFailed, if function failed
|                   kCanNotSupported, if this function is not supported
| DESCRIPTION:      stop CAN-controller
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanStop( CAN_CHANNEL_CANTYPE_ONLY )
{
  vuint8         canReturnCode;

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
# endif
  assertUser((canStatus[channel] & kCanTxOn) != kCanTxOn, channel, kErrorCanOnline);   /* PRQA S 3109 */

  {
# if defined( C_ENABLE_SLEEP_WAKEUP )
    assertUser(!CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanSleep);   /* PRQA S 3109 */
# endif
    canReturnCode = kCanOk;
    /* disconnect the CAN controller by switching into initmode */
    
    CAN_WRITE_REGISTER(&CANMC, (tCanRegType)0xFFFFFFFF, kCanCcr);   /*lint !e740 !e826 unusual pointer cast */
    
    APPLCANTIMERSTART(kCanLoopWaitCanStop);
    while((CANES & kCanCce) != kCanCce)
    {
    #if defined(C_ENABLE_HW_LOOP_TIMER)
      if(0 == APPLCANTIMERLOOP(kCanLoopWaitCanStop))
      {
        canReturnCode = kCanFailed;
        break; /* loop is terminated by user */
      }
      else
    #endif
      {
        ; /* wait until CAN controller allows configuration access */
      }
    }
    APPLCANTIMEREND(kCanLoopWaitCanStop);
    
  }
  return canReturnCode;
}
/* CODE CATEGORY 4 END*/

/****************************************************************************
| NAME:             CanStart
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    kCanOk, if success
|                   kCanFailed, if function failed
|                   kCanNotSupported, if this function is not supported
| DESCRIPTION:      restart CAN-controller
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanStart( CAN_CHANNEL_CANTYPE_ONLY )
{
  vuint8         canReturnCode;

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
# endif

  {
    tCanRegType tmpCanMC;
    canReturnCode = kCanOk;
    tmpCanMC = CANMC;
    tmpCanMC &= ~kCanCcr;  /* clear configuration change request bit */
    CAN_WRITE_REGISTER(&CANMC, (tCanRegType)0xFFFFFFFF, tmpCanMC); /*lint !e740 !e826 unusual pointer cast */
    
    APPLCANTIMERSTART(kCanLoopWaitCanStart);
    while((CANES & kCanCce) == kCanCce)
    {
    #if defined(C_ENABLE_HW_LOOP_TIMER)
      if(0 == APPLCANTIMERLOOP(kCanLoopWaitCanStart))
      {
        canReturnCode = kCanFailed;
        break; /* loop is terminated by user */
      }
      else
    #endif
      {
        ; /* wait until CAN controller leaves configuration mode */
      }
    }
    APPLCANTIMEREND(kCanLoopWaitCanStart);
    
    /* stopmode clears the SCC/HECC configuration bit !! -> set to the correct value */
    #if defined (C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC)
    # if defined(C_SINGLE_RECEIVE_CHANNEL)
    #  if(kCanControllerMode == kCanSCCMode)
    tmpCanMC &= ~kCanScm;   /* activate SCC mode */
    #  else
    tmpCanMC |= kCanScm;   /* activate HECC mode */
    #  endif
    # else /* C_SINGLE_RECEIVE_CHANNEL */
    if(CanControllerMode[channel] == kCanSCCMode)
    {
      tmpCanMC &= ~kCanScm;   /* activate SCC mode */
    }
    else
    {
      tmpCanMC |= kCanScm;   /* activate HECC mode */
    }
    # endif /* C_SINGLE_RECEIVE_CHANNEL */
    #else  /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
    tmpCanMC |= kCanScm;   /* activate HECC mode */
    #endif /* C_LL_ENABLE_CONTROLLERMODE_HECCANDSCC */
    
    CAN_WRITE_REGISTER(&CANMC, (tCanRegType)0xFFFFFFFF, tmpCanMC); /*lint !e740 !e826 unusual pointer cast */
    
  }
  return canReturnCode;
}
/* CODE CATEGORY 4 END*/
#endif /* if defined( C_ENABLE_STOP ) */

#if defined (C_ENABLE_CAN_CAN_INTERRUPT_CONTROL)
/****************************************************************************
| NAME:             CanCanInterruptDisable
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      disables CAN interrupts and stores old interrupt status
****************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 CanCanInterruptDisable( CAN_CHANNEL_CANTYPE_ONLY )
{
# if defined (C_ENABLE_OSEK_CAN_INTCTRL)

  {
    OsCanCanInterruptDisable(CAN_HW_CHANNEL_CANPARA_ONLY);
  }
# else  /* defined (C_ENABLE_OSEK_CAN_INTCTRL) */

  CanDeclareGlobalInterruptOldStatus
#  if defined( C_HL_ENABLE_CAN_IRQ_DISABLE )
#  endif

  /* local variable must reside on stack or registerbank, switched */
  /* in interrupt level                                            */
  /* disable global interrupt                                      */
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
#  endif
  assertUser(canCanInterruptCounter[channel]<(vsint8)0x7f, kCanAllChannels, kErrorIntDisableTooOften);    /* PRQA S 3109 */

  CanNestedGlobalInterruptDisable();
  if (canCanInterruptCounter[channel] == (vsintx)0)  /* if 0 then save old interrupt status */
  {
#  if defined( C_HL_ENABLE_CAN_IRQ_DISABLE )
    {
#   if defined( C_ENABLE_SLEEP_WAKEUP )
      assertUser(!CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanSleep);     /* PRQA S 3109 */
#   endif

      CanLL_CanInterruptDisable(canHwChannel, &canCanInterruptOldStatus[canHwChannel]);
    }
#  endif
#  if defined( C_ENABLE_INTCTRL_ADD_CAN_FCT )
    ApplCanAddCanInterruptDisable(channel);
#  endif
  }
  canCanInterruptCounter[channel]++;               /* common for all platforms */

  CanNestedGlobalInterruptRestore();
# endif  /* C_ENABLE_OSEK_CAN_INTCTRL */
} /* END OF CanCanInterruptDisable */
/* CODE CATEGORY 1 END*/

/****************************************************************************
| NAME:             CanCanInterruptRestore
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      restores the old interrupt status of the CAN interrupt if 
|                   canCanInterruptCounter[channel] is zero
****************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 CanCanInterruptRestore( CAN_CHANNEL_CANTYPE_ONLY )
{
# if defined (C_ENABLE_OSEK_CAN_INTCTRL)

  {
    OsCanCanInterruptRestore(CAN_HW_CHANNEL_CANPARA_ONLY);
  }
# else  /* defined (C_ENABLE_OSEK_CAN_INTCTRL) */

  CanDeclareGlobalInterruptOldStatus
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#  endif
  assertUser(canCanInterruptCounter[channel]>(vsintx)0, kCanAllChannels, kErrorIntRestoreTooOften);   /* PRQA S 3109 */

  CanNestedGlobalInterruptDisable();
  /* restore CAN interrupt */
  canCanInterruptCounter[channel]--;

  if (canCanInterruptCounter[channel] == (vsintx)0)         /* restore interrupt if canCanInterruptCounter=0 */
  {
#  if defined( C_HL_ENABLE_CAN_IRQ_DISABLE )    
    {
#   if defined( C_ENABLE_SLEEP_WAKEUP )
      assertUser(!CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanSleep);   /* PRQA S 3109 */
#   endif

      CanLL_CanInterruptRestore(canHwChannel, canCanInterruptOldStatus[canHwChannel]);
    }
#  endif

#  if defined( C_ENABLE_INTCTRL_ADD_CAN_FCT )
    ApplCanAddCanInterruptRestore(channel);
#  endif
  }
  CanNestedGlobalInterruptRestore();
# endif  /* defined (C_ENABLE_OSEK_CAN_INTCTRL) */
} /* END OF CanCanInterruptRestore */
/* CODE CATEGORY 1 END*/
#endif /* defined (C_ENABLE_CAN_CAN_INTERRUPT_CONTROL) */



#if defined( C_ENABLE_DYN_TX_OBJECTS )
/************************************************************************
* NAME:           CanGetDynTxObj
* PARAMETER:      txHandle - Handle of the dynamic object to reserve
* RETURN VALUE:   kCanNoTxDynObjAvailable (0xFF) - 
*                   object not available
*                 0..F0 - 
*                   Handle to dynamic transmission object
* DESCRIPTION:    Function reserves and return a handle to a dynamic 
*                   transmission object
*
*                 To use dynamic transmission, an application must get
*                 a dynamic object from CAN-driver. 
*                 Before transmission, application must set all attributes 
*                 (id, dlc, data, confirmation function/flag, pretransmission
*                 etc. - as configurated). 
*                 Application can use a dynamic object for one or many
*                 transmissions (as it likes) - but finally, it must
*                 release the dynamic object by calling CanReleaseDynTxObj.
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 CanTransmitHandle C_API_2 CanGetDynTxObj(CanTransmitHandle txHandle )
{
  CanTransmitHandle nTxDynObj;
  CanDeclareGlobalInterruptOldStatus
  CAN_CHANNEL_CANTYPE_LOCAL
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);    /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
# endif

  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */

  nTxDynObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel); /* PRQA S 3382,0291 */

  CanNestedGlobalInterruptDisable();
  if ( canTxDynObjReservedFlag[nTxDynObj] != (vuint8)0)
  {
    CanNestedGlobalInterruptRestore();
    return kCanNoTxDynObjAvailable;
  }
  /*  Mark dynamic object as used  */
  canTxDynObjReservedFlag[nTxDynObj] = 1;

# if defined( C_ENABLE_CONFIRMATION_FLAG )
  CanConfirmationFlags._c[CanGetConfirmationOffset(txHandle)] &= 
                            (vuint8)(~CanGetConfirmationMask(txHandle));
# endif
  CanNestedGlobalInterruptRestore();

  /* Initialize dynamic object */
# if defined( C_ENABLE_DYN_TX_DATAPTR )  
  canDynTxDataPtr[nTxDynObj] = V_NULL;  
# endif  
  

  return (txHandle);
}
/* CODE CATEGORY 3 END*/

/************************************************************************
* NAME:           CanReleaseDynTxObj
* PARAMETER:      hTxObj -
*                   Handle of dynamic transmission object
* RETURN VALUE:   --
* DESCRIPTION:    Function releases dynamic transmission object
*                   which was reserved before (calling CanGetDynTxObj)
*                 
*                 After a transmission of one or more messages is finished,
*                 application must free the reserved resource, formally the
*                 dynamic transmission object calling this function.
*
*                 As the number of dynamic transmission object is limited,
*                 application should not keep unused dynamic transmission
*                 objects for a longer time.
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 vuint8 C_API_2 CanReleaseDynTxObj(CanTransmitHandle txHandle)
{
  CanTransmitHandle dynTxObj;
  CAN_CHANNEL_CANTYPE_LOCAL
# if defined( C_ENABLE_TRANSMIT_QUEUE )
  CanSignedTxHandle queueElementIdx; /* index for accessing the tx queue */
  CanSignedTxHandle elementBitIdx;  /* bit index within the tx queue element */
  CanTransmitHandle queueBitPos;  /* physical bitposition of the handle */
# endif
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);    /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
# endif

  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */

  dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel);  /* PRQA S 3382,0291 */

  assertInternal((canTxDynObjReservedFlag[dynTxObj] != (vuint8)0), channel, kErrorReleasedUnusedDynObj);  /* PRQA S 3109 */

# if defined( C_ENABLE_TRANSMIT_QUEUE )
  #if defined( C_ENABLE_INTERNAL_CHECK ) &&\
      defined( C_MULTIPLE_RECEIVE_CHANNEL )
  if (sizeof(queueBitPos) == 1)
  {
    assertInternal( ((kCanNumberOfTxObjects + CanTxQueuePadBits[kCanNumberOfChannels-1]) <= 256u), kCanAllChannels, kErrorTxQueueTooManyHandle) /* PRQA S 3109 */ /*lint !e572 !e506*/
  }
  else
  {
    assertInternal( ((kCanNumberOfTxObjects + CanTxQueuePadBits[kCanNumberOfChannels-1]) <= 65536u), kCanAllChannels, kErrorTxQueueTooManyHandle) /* PRQA S 3109 */ /*lint !e572 !e506*/
  }
  #endif
  queueBitPos  = txHandle + CAN_HL_TXQUEUE_PADBITS(channel);
  queueElementIdx = (CanSignedTxHandle)(queueBitPos >> kCanTxQueueShift); /* get the queue element where to set the flag */
  elementBitIdx  = (CanSignedTxHandle)(queueBitPos & kCanTxQueueMask);   /* get the flag index wihtin the queue element */
  if( (canTxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) != (tCanQueueElementType)0 )
  {
  }
  else
# endif
  {
    if (
# if defined( C_ENABLE_CONFIRMATION_FCT ) && \
    defined( C_ENABLE_TRANSMIT_QUEUE )
         (confirmHandle[channel] == txHandle) ||       /* confirmation active ? */
# endif
         (canHandleCurTxObj[(vsintx)CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)] != txHandle) )
    {
      /*  Mark dynamic object as not used  */
      canTxDynObjReservedFlag[dynTxObj] = 0;
      return(kCanDynReleased);
    }
  }
  return(kCanDynNotReleased);
}
/* CODE CATEGORY 3 END*/
#endif /* C_ENABLE_DYN_TX_OBJECTS */


#if defined( C_ENABLE_DYN_TX_ID ) 
# if !defined( C_ENABLE_EXTENDED_ID ) ||\
     defined( C_ENABLE_MIXED_ID )
/************************************************************************
* NAME:           CanDynTxObjSetId
* PARAMETER:      hTxObj -
*                   Handle of dynamic transmission object
*                 id -
*                   Id (standard-format) to register with dynamic object
* RETURN VALUE:   --
* DESCRIPTION:    Function registers submitted id (standard format)
*                 with dynamic object referenced by handle.
*************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetId(CanTransmitHandle txHandle, vuint16 id)
{
  CanTransmitHandle dynTxObj;

  CAN_CHANNEL_CANTYPE_LOCAL
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);  /* PRQA S 3109 */

#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
#  endif

  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */
  assertUser(id <= (vuint16)0x7FF, channel, kErrorWrongId);                                              /* PRQA S 3109 */

  dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel); /* PRQA S 3382,0291 */

#  if defined( C_ENABLE_MIXED_ID )
#   if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#   else
  canDynTxIdType[dynTxObj]  = kCanIdTypeStd; 
#   endif
#  endif

  canDynTxId0[dynTxObj] = MK_STDID0(id);
#  if (kCanNumberOfUsedCanTxIdTables > 1)
  canDynTxId1[dynTxObj] = MK_STDID1(id);
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 2)
  canDynTxId2[dynTxObj] = MK_STDID2(id);
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 3)
  canDynTxId3[dynTxObj] = MK_STDID3(id);
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 4)
  canDynTxId4[dynTxObj] = MK_STDID4(id);
#  endif
}
/* CODE CATEGORY 2 END*/
# endif /* !defined( C_ENABLE_EXTENDED_ID ) || defined( C_ENABLE_MIXED_ID ) */
#endif /* C_ENABLE_DYN_TX_ID */

#if defined( C_ENABLE_DYN_TX_ID ) && \
    defined( C_ENABLE_EXTENDED_ID )
/************************************************************************
* NAME:           CanDynTxObjSetExtId
* PARAMETER:      hTxObj -  Handle of dynamic transmission object
*                 idExtHi - Id low word (extended-format) to register with
*                                                         dynamic object
*                 idExtLo - Id high word (extended-format) 
* RETURN VALUE:   --
* DESCRIPTION:    Function registers submitted id (standard format)
*                 with dynamic object referenced by handle.
*************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetExtId(CanTransmitHandle txHandle, vuint16 idExtHi, vuint16 idExtLo)
{
  CanTransmitHandle dynTxObj;
  CAN_CHANNEL_CANTYPE_LOCAL
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);   /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
# endif

  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */
  assertUser(idExtHi <= (vuint16)0x1FFF, channel, kErrorWrongId);                                        /* PRQA S 3109 */

  dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel); /* PRQA S 3382,0291 */

# if defined( C_ENABLE_MIXED_ID )
#  if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#  else
  canDynTxIdType[dynTxObj] = kCanIdTypeExt; 
#  endif
# endif

  canDynTxId0[dynTxObj]      = MK_EXTID0( ((vuint32)idExtHi<<16) | (vuint32)idExtLo );
# if (kCanNumberOfUsedCanTxIdTables > 1)
  canDynTxId1[dynTxObj]      = MK_EXTID1( ((vuint32)idExtHi<<16) | (vuint32)idExtLo );
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
  canDynTxId2[dynTxObj]      = MK_EXTID2( ((vuint32)idExtHi<<16) | (vuint32)idExtLo );
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
  canDynTxId3[dynTxObj]      = MK_EXTID3( ((vuint32)idExtHi<<16) | (vuint32)idExtLo );
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
  canDynTxId4[dynTxObj]      = MK_EXTID4( ((vuint32)idExtHi<<16) | (vuint32)idExtLo );
# endif
}
/* CODE CATEGORY 2 END*/
#endif


#if defined( C_ENABLE_DYN_TX_DLC )
/************************************************************************
* NAME:           CanDynTxObjSetDlc
* PARAMETER:      hTxObj -
*                   Handle of dynamic transmission object
*                 dlc -
*                   data length code to register with dynamic object
* RETURN VALUE:   --
* DESCRIPTION:    Function registers data length code with 
*                 dynamic object referenced by submitted handle.
*************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetDlc(CanTransmitHandle txHandle, vuint8 dlc)
{
  CanTransmitHandle dynTxObj;
  CAN_CHANNEL_CANTYPE_LOCAL
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);     /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
# endif
  
  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */
  assertUser(dlc<(vuint8)9, channel, kErrorTxDlcTooLarge);                                               /* PRQA S 3109 */
  
  dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel); /* PRQA S 3382,0291 */
  
# if defined( C_ENABLE_EXTENDED_ID )
  canDynTxDLC[dynTxObj] = MK_TX_DLC_EXT(dlc);
# else
  canDynTxDLC[dynTxObj] = MK_TX_DLC(dlc);
# endif
}
/* CODE CATEGORY 2 END*/
#endif /* C_ENABLE_DYN_TX_DLC */


#if defined( C_ENABLE_DYN_TX_DATAPTR )
/************************************************************************
* NAME:           CanDynTxObjSetData
* PARAMETER:      hTxObj -
*                   Handle of dynamic transmission object
*                 pData -
*                   data reference to be stored in data buffer of dynamic object
* RETURN VALUE:   --
* DESCRIPTION:    Functions stores reference to data registered with
*                 dynamic object.
*                 
*                 The number of byte copied is (always) 8. The number of 
*                 relevant (and consequently evaluated) byte is to be 
*                 taken from function CanDynObjGetDLC.
*************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetDataPtr(CanTransmitHandle txHandle, void* pData)
{
  CanTransmitHandle dynTxObj;
  CAN_CHANNEL_CANTYPE_LOCAL
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);    /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
# endif

  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */

  dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel);  /* PRQA S 3382,0291 */

  canDynTxDataPtr[dynTxObj] = pData;
}
/* CODE CATEGORY 2 END*/
#endif /* C_ENABLE_DYN_TX_DATAPTR */




#if defined( C_ENABLE_TX_MASK_EXT_ID )
/************************************************************************
* NAME:               CanSetTxIdExtHi
* CALLED BY:          
* PRECONDITIONS:      CanInitPower should already been called.
* PARAMETER:          new source address for the 29-bit CAN-ID
* RETURN VALUE:       -
* DESCRIPTION:        Sets the source address in the lower 8 bit of the
*                     29-bit CAN identifier.
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtHi( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask )
{  
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
# endif
  assertUser(mask <= (vuint8)0x1F, channel, kErrorWrongMask);                                /* PRQA S 3109 */

  canTxMask0[channel] = (canTxMask0[channel] & MK_EXTID0(0x00FFFFFFUL)) | MK_EXTID0((vuint32)mask<<24);
# if (kCanNumberOfUsedCanTxIdTables > 1)
  canTxMask1[channel] = (canTxMask1[channel] & MK_EXTID1(0x00FFFFFFUL)) | MK_EXTID1((vuint32)mask<<24);
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
  canTxMask2[channel] = (canTxMask2[channel] & MK_EXTID2(0x00FFFFFFUL)) | MK_EXTID2((vuint32)mask<<24);
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
  canTxMask3[channel] = (canTxMask3[channel] & MK_EXTID3(0x00FFFFFFUL)) | MK_EXTID3((vuint32)mask<<24);
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
  canTxMask4[channel] = (canTxMask4[channel] & MK_EXTID4(0x00FFFFFFUL)) | MK_EXTID4((vuint32)mask<<24);
# endif
}
/* CODE CATEGORY 4 END*/

/************************************************************************
* NAME:               CanSetTxIdExtMidHi
* CALLED BY:          
* PRECONDITIONS:      CanInitPower should already been called.
* PARAMETER:          new source address for the 29-bit CAN-ID
* RETURN VALUE:       -
* DESCRIPTION:        Sets the source address in the lower 8 bit of the
*                     29-bit CAN identifier.
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtMidHi( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
# endif

  canTxMask0[channel] = (canTxMask0[channel] & MK_EXTID0(0xFF00FFFFUL)) | MK_EXTID0((vuint32)mask<<16);   /*lint !e572*/
# if (kCanNumberOfUsedCanTxIdTables > 1)
  canTxMask1[channel] = (canTxMask1[channel] & MK_EXTID1(0xFF00FFFFUL)) | MK_EXTID1((vuint32)mask<<16);   /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
  canTxMask2[channel] = (canTxMask2[channel] & MK_EXTID2(0xFF00FFFFUL)) | MK_EXTID2((vuint32)mask<<16);   /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
  canTxMask3[channel] = (canTxMask3[channel] & MK_EXTID3(0xFF00FFFFUL)) | MK_EXTID3((vuint32)mask<<16);   /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
  canTxMask4[channel] = (canTxMask4[channel] & MK_EXTID4(0xFF00FFFFUL)) | MK_EXTID4((vuint32)mask<<16);   /*lint !e572*/
# endif
}
/* CODE CATEGORY 4 END*/

/************************************************************************
* NAME:               CanSetTxIdExtMidLo
* CALLED BY:          
* PRECONDITIONS:      CanInitPower should already been called.
* PARAMETER:          new source address for the 29-bit CAN-ID
* RETURN VALUE:       -
* DESCRIPTION:        Sets the source address in the lower 8 bit of the
*                     29-bit CAN identifier.
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtMidLo( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif

  canTxMask0[channel] = (canTxMask0[channel] & MK_EXTID0(0xFFFF00FFUL)) | MK_EXTID0((vuint32)mask<<8);    /*lint !e572*/
# if (kCanNumberOfUsedCanTxIdTables > 1)
  canTxMask1[channel] = (canTxMask1[channel] & MK_EXTID1(0xFFFF00FFUL)) | MK_EXTID1((vuint32)mask<<8);    /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
  canTxMask2[channel] = (canTxMask2[channel] & MK_EXTID2(0xFFFF00FFUL)) | MK_EXTID2((vuint32)mask<<8);    /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
  canTxMask3[channel] = (canTxMask3[channel] & MK_EXTID3(0xFFFF00FFUL)) | MK_EXTID3((vuint32)mask<<8);    /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
  canTxMask4[channel] = (canTxMask4[channel] & MK_EXTID4(0xFFFF00FFUL)) | MK_EXTID4((vuint32)mask<<8);    /*lint !e572*/
# endif
}
/* CODE CATEGORY 4 END*/

/************************************************************************
* NAME:               CanSetTxIdExtLo
* CALLED BY:          
* PRECONDITIONS:      CanInitPower should already been called.
* PARAMETER:          new source address for the 29-bit CAN-ID
* RETURN VALUE:       -
* DESCRIPTION:        Sets the source address in the lower 8 bit of the
*                     29-bit CAN identifier.
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtLo( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif

  canTxMask0[channel] = (canTxMask0[channel] & MK_EXTID0(0xFFFFFF00UL)) | MK_EXTID0((vuint32)mask);     /*lint !e572*/
# if (kCanNumberOfUsedCanTxIdTables > 1)
  canTxMask1[channel] = (canTxMask1[channel] & MK_EXTID1(0xFFFFFF00UL)) | MK_EXTID1((vuint32)mask);     /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
  canTxMask2[channel] = (canTxMask2[channel] & MK_EXTID2(0xFFFFFF00UL)) | MK_EXTID2((vuint32)mask);     /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
  canTxMask3[channel] = (canTxMask3[channel] & MK_EXTID3(0xFFFFFF00UL)) | MK_EXTID3((vuint32)mask);     /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
  canTxMask4[channel] = (canTxMask4[channel] & MK_EXTID4(0xFFFFFF00UL)) | MK_EXTID4((vuint32)mask);    /*lint !e572*/
# endif
}
/* CODE CATEGORY 4 END*/
#endif

#if defined( C_ENABLE_TX_OBSERVE )
/************************************************************************
* NAME:               CanTxGetActHandle
* CALLED BY:          
* PRECONDITIONS:      
* PARAMETER:          logical hardware object handle
* RETURN VALUE:       handle of the message in the assigned mailbox
* DESCRIPTION:        get transmit handle of the message, which is currently
*                     in the mailbox txHwObject.
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 CanTransmitHandle C_API_2 CanTxGetActHandle( CanObjectHandle logicalTxHdl )
{
  assertUser(logicalTxHdl < kCanNumberOfUsedTxCANObjects, kCanAllChannels, kErrorTxHwHdlTooLarge);     /* PRQA S 3109 */

  return (canHandleCurTxObj[logicalTxHdl]);       /*lint !e661*/
}
/* CODE CATEGORY 3 END*/
#endif

#if defined( C_ENABLE_VARIABLE_RX_DATALEN )
/************************************************************************
* NAME:               CanSetVariableRxDatalen
* CALLED BY:          
* PRECONDITIONS:      
* PARAMETER:          rxHandle: Handle of receive Message for which the datalen has
*                               to be changed
*                     dataLen:  new number of bytes, which have to be copied to the 
*                               message buffer.
* RETURN VALUE:       -
* DESCRIPTION:        change the dataLen of a receive message to copy a 
*                     smaller number of bytes than defined in the database.
*                     the dataLen can only be decreased. If the parameter
*                     dataLen is bigger than the statically defined value
*                     the statically defined value will be set.
*************************************************************************/
/* CODE CATEGORY 1 START*/
static void CanSetVariableRxDatalen (CanReceiveHandle rxHandle, vuint8 dataLen)
{
  assertInternal(rxHandle < kCanNumberOfRxObjects, kCanAllChannels , kErrorRxHandleWrong);  /* PRQA S 3109 */ /* legal rxHandle ? */
  /* assertion for dataLen not necessary due to runtime check */

  if (dataLen < CanGetRxDataLen(rxHandle))
  {
    canVariableRxDataLen[rxHandle]=dataLen;
  }
  else
  {
    canVariableRxDataLen[rxHandle] = CanGetRxDataLen(rxHandle);
  }
}
/* CODE CATEGORY 1 END*/
#endif

#if defined( C_ENABLE_COND_RECEIVE_FCT )
/************************************************************************
* NAME:               CanSetMsgReceivedCondition
* CALLED BY:          Application
* PRECONDITIONS:      
* PARAMETER:          -.
* RETURN VALUE:       -
* DESCRIPTION:        The service function CanSetMsgReceivedCondition()
*                     enables the calling of ApplCanMsgCondReceived()
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 void C_API_2 CanSetMsgReceivedCondition( CAN_CHANNEL_CANTYPE_ONLY )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((channel < kCanNumberOfChannels), kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
# endif

  canMsgCondRecState[channel] = kCanTrue;
}
/* CODE CATEGORY 3 END*/

/************************************************************************
* NAME:               CanResetMsgReceivedCondition
* CALLED BY:          Application
* PRECONDITIONS:      
* PARAMETER:          -
* RETURN VALUE:       -
* DESCRIPTION:        The service function CanResetMsgReceivedCondition()
*                     disables the calling of ApplCanMsgCondReceived()
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 void C_API_2 CanResetMsgReceivedCondition( CAN_CHANNEL_CANTYPE_ONLY )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((channel < kCanNumberOfChannels), kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif

  canMsgCondRecState[channel] = kCanFalse;
}
/* CODE CATEGORY 3 END*/

/************************************************************************
* NAME:               CanGetMsgReceivedCondition
* CALLED BY:          Application
* PRECONDITIONS:      
* PARAMETER:          -
* RETURN VALUE:       status of Conditional receive function:
*                     kCanTrue : Condition is set -> ApplCanMsgCondReceived 
*                                will be called
*                     kCanFalse: Condition is not set -> ApplCanMsgCondReceived
*                                will not be called
* DESCRIPTION:        The service function CanGetMsgReceivedCondition() 
*                     returns the status of the condition for calling
*                     ApplCanMsgCondReceived()
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 vuint8 C_API_2 CanGetMsgReceivedCondition( CAN_CHANNEL_CANTYPE_ONLY )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((channel < kCanNumberOfChannels), kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
# endif

  return( canMsgCondRecState[channel] );
}
/* CODE CATEGORY 3 END*/
#endif


#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
/************************************************************************
* NAME:           ApplCanChannelDummy
* PARAMETER:      channel
*                 current receive channel
* RETURN VALUE:   ---
* DESCRIPTION:    dummy-function for unused Callback-functions
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 void C_API_2 ApplCanChannelDummy( CanChannelHandle channel )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;     /* to avoid lint warnings */
# endif
}
/* CODE CATEGORY 3 END*/
#endif   /* C_MULTIPLE_RECEIVE_CHANNEL */


#if defined( C_MULTIPLE_RECEIVE_CHANNEL ) || \
    defined( C_HL_ENABLE_DUMMY_FCT_CALL )
/************************************************************************
* NAME:           ApplCanRxStructPtrDummy
* PARAMETER:      rxStruct
*                 pointer of CanRxInfoStruct
* RETURN VALUE:   kCanCopyData 
* DESCRIPTION:    dummy-function for unused Callback-functions
*************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 vuint8 C_API_2 ApplCanRxStructPtrDummy( CanRxInfoStructPtr rxStruct )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  rxStruct = rxStruct;     /* to avoid lint warnings */
# endif
  return kCanCopyData;
}
/* CODE CATEGORY 1 END*/

/************************************************************************
* NAME:           ApplCanTxHandleDummy
* PARAMETER:      txHandle
*                 transmit handle
* RETURN VALUE:   ---
* DESCRIPTION:    dummy-function for unused Callback-functions
*************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 ApplCanTxHandleDummy( CanTransmitHandle txHandle )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  txHandle = txHandle;     /* to avoid lint warnings */
# endif
}
/* CODE CATEGORY 1 END*/
#endif   /* C_MULTIPLE_RECEIVE_CHANNEL || C_HL_ENABLE_DUMMY_FCT_CALL */

#if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
/************************************************************************
* NAME:           ApplCanTxStructDummy
* PARAMETER:      txStruct
*                 pointer of CanTxInfoStruct
* RETURN VALUE:   kCanCopyData
* DESCRIPTION:    dummy-function for unused Callback-functions
*************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 vuint8 C_API_2 ApplCanTxStructDummy( CanTxInfoStruct txStruct )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  txStruct = txStruct;     /* to avoid lint warnings */
# endif
  return kCanCopyData;
}
/* CODE CATEGORY 1 END*/

/************************************************************************
* NAME:           ApplCanRxHandleDummy
* PARAMETER:      rxHandle
*                 receive handle
* RETURN VALUE:   ---
* DESCRIPTION:    dummy-function for unused Callback-functions
*************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 ApplCanRxHandleDummy( CanReceiveHandle rxHandle )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  rxHandle = rxHandle;     /* to avoid lint warnings */
# endif  
}
/* CODE CATEGORY 1 END*/
#endif /* C_HL_ENABLE_DUMMY_FCT_CALL */





/* End of channel */
/* STOPSINGLE_OF_MULTIPLE */
/* Kernbauer Version: 1.14 Konfiguration: can_driver Erzeugungsgangnummer: 1 */

/* Kernbauer Version: 1.14 Konfiguration: can_driver Erzeugungsgangnummer: 1 */

/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
