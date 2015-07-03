/* -----------------------------------------------------------------------------
  Filename:    can_cfg.h
  Description: Toolversion: 03.20.21.01.10.02.79.00.00.00
               
               Serial Number: CBD1100279
               Customer Info: Dr. Ing. h. c. F. Porsche AG
                              CBD / Porsche 2007+
                              Texas Instruments TMS470 / TMS470 R1SF55
                              Texas Instruments 4.6.6 Compiler
               
               
               Generator Fwk   : GENy 
               Generator Module: DrvCan__base
               
               Configuration   : F:\projects\ADR-Porsche\Porsche_ADR_Development_trunk\MOD\MOD_CAN_GEN\cfg\Porsche_ADR.gny
               
               ECU: 
                       TargetSystem: Hw_Tms470Cpu
                       Compiler:     TexasInstruments
                       Derivates:    TMS470R1
               
               Channel "Channel0":
                       Databasefile: F:\projects\ADR-Porsche\Porsche_ADR_Development_trunk\MOD\MOD_CAN_GEN\cfg\CAN_Matrix_Dashboard_2_11_0_X2_Release.dbc
                       Bussystem:    CAN
                       Manufacturer: Porsche AG
                       Node:         ADR_PAG_X2

  Generated by , 2012-02-15  08:51:07
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2010 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(__CAN_CFG_H__)
#define __CAN_CFG_H__

#include "v_cfg.h"
#define HW_TMS470HECCSCCCPUCANDLL_VERSION    0x0208
#define HW_TMS470HECCSCCCPUCANDLL_RELEASE_VERSION 0x00

#define HW__BASECPUCANDLL_VERSION            0x0222
#define HW__BASECPUCANDLL_RELEASE_VERSION    0x10

#define DRVCAN__BASEDLL_VERSION              0x0321
#define DRVCAN__BASEDLL_RELEASE_VERSION      0x03

#define DRVCAN__BASERI14DLL_VERSION          0x0209
#define DRVCAN__BASERI14DLL_RELEASE_VERSION  0x01

#define DRVCAN__BASERI15DLL_VERSION          0x0104
#define DRVCAN__BASERI15DLL_RELEASE_VERSION  0x09

#define DRVCAN__BASEHLLDLL_VERSION           0x0305
#define DRVCAN__BASEHLLDLL_RELEASE_VERSION   0x01

#define DRVCAN__BASERI14HLLDLL_VERSION       0x0205
#define DRVCAN__BASERI14HLLDLL_RELEASE_VERSION 0x01

#define DRVCAN__BASERI15HLLDLL_VERSION       0x0101
#define DRVCAN__BASERI15HLLDLL_RELEASE_VERSION 0x03

#define CAN_DRV_TMS470DLL_VERSION            0x0206
#define CAN_DRV_TMS470DLL_RELEASE_VERSION    0x01


#define kCanNumberOfChannels                 1
#define kCanNumberOfHwChannels               1
#define kCanNumberOfPhysChannels             1
#define C_DISABLE_MEMCOPY_SUPPORT
#define C_ENABLE_OSEK_OS
#define C_DISABLE_VARIABLE_DLC
#define C_DISABLE_DLC_FAILED_FCT
#define C_DISABLE_VARIABLE_RX_DATALEN
#define C_DISABLE_MULTI_ECU_CONFIG
#define C_DISABLE_MULTI_ECU_PHYS
#define C_DISABLE_EXTENDED_ID
#define C_DISABLE_MIXED_ID
#define C_DISABLE_RECEIVE_FCT

#define C_DISABLE_ECU_SWITCH_PASS
#define C_ENABLE_TRANSMIT_QUEUE
#define C_DISABLE_OVERRUN
#define C_DISABLE_INTCTRL_BY_APPL
#define C_DISABLE_COMMON_CAN
#define C_DISABLE_USER_CHECK
#define C_DISABLE_HARDWARE_CHECK
#define C_DISABLE_GEN_CHECK
#define C_DISABLE_INTERNAL_CHECK
#define C_DISABLE_DYN_RX_OBJECTS
#define C_DISABLE_DYN_TX_OBJECTS
#define C_DISABLE_DYN_TX_ID
#define C_DISABLE_DYN_TX_DLC
#define C_DISABLE_DYN_TX_DATAPTR
#define C_DISABLE_DYN_TX_PRETRANS_FCT
#define C_DISABLE_DYN_TX_CONF_FCT
#define C_DISABLE_EXTENDED_STATUS
#define C_DISABLE_TX_OBSERVE
#define C_ENABLE_HW_LOOP_TIMER
#define C_DISABLE_NOT_MATCHED_FCT
#define C_SECURITY_LEVEL                     30

#define C_DISABLE_MULTICHANNEL_API
#define C_ENABLE_PART_OFFLINE
#define C_ENABLE_RANGE_0
#define C_DISABLE_RANGE_1
#define C_DISABLE_RANGE_2
#define C_DISABLE_RANGE_3
#define NmhCanBusOff                         NmhBusCriticalFailure
#define NmhCanWakeUp                         NmhWakeUpRequest
#define ApplCanBusOff                        NmhCanBusOff

#define ApplCanRange0Precopy                 NmhCanMsgPrecopy
#define kCanNumberOfTxObjects                11
#define kCanNumberOfTxStatObjects            11
#define kCanNumberOfTxDynObjects             0
#define kCanNumberOfRxObjects                45
#define kCanNumberOfRxStatFullCANObjects     29
#define kCanNumberOfRxStatBasicCANObjects    16
#define kCanNumberOfRxDynFullCANObjects      0
#define kCanNumberOfRxDynBasicCANObjects     0
#define kCanNumberOfRxDynObjects             0
#define kCanNumberOfRxStatObjects            45
#define kCanNumberOfConfFlags                9
#define kCanNumberOfIndFlags                 0
#define kCanNumberOfConfirmationFlags        2
#define kCanNumberOfIndicationFlags          0
#define kCanNumberOfInitObjects              1
#define kCanExtNumberOfInitObjects           0
#define kCanHwRxDynFullStartIndex            31
#define C_SEARCH_LINEAR

#define C_ENABLE_RX_MSG_INDIRECTION

#define C_ENABLE_CONFIRMATION_FLAG
#define C_DISABLE_INDICATION_FLAG
#define C_ENABLE_PRETRANSMIT_FCT
#define C_ENABLE_CONFIRMATION_FCT
#define C_ENABLE_INDICATION_FCT
#define C_ENABLE_PRECOPY_FCT
#define C_ENABLE_COPY_TX_DATA
#define C_ENABLE_COPY_RX_DATA
#define C_ENABLE_DLC_CHECK
#define C_DISABLE_DLC_CHECK_MIN_DATALEN

#define C_ENABLE_GENERIC_PRECOPY
#define APPL_CAN_GENERIC_PRECOPY             IlCanGenericPrecopy

#define C_SEND_GRP_NONE                      0x00
#define C_SEND_GRP_ALL                       0xFF
#define C_SEND_GRP_APPL                      0x01
#define C_SEND_GRP_USER1                     0x02
#define C_SEND_GRP_USER2                     0x04
#define C_SEND_GRP_USER3                     0x08
#define C_SEND_GRP_USER4                     0x10
#define C_SEND_GRP_USER5                     0x20
#define C_SEND_GRP_USER6                     0x40
#define C_SEND_GRP_USER7                     0x80
#define C_ENABLE_CAN_CANCEL_NOTIFICATION
#define APPL_CAN_CANCELNOTIFICATION          IlCanCancelNotification

#define kCanPhysToLogChannelIndex_0
#define C_RANGE0_ACC_MASK                    0x03F

#define C_RANGE0_ACC_CODE                    0x6C0

#define C_ENABLE_RX_FULLCAN_OBJECTS
#define C_ENABLE_RX_BASICCAN_OBJECTS
#define kCanNumberOfRxFullCANObjects         29

#define kCanNumberOfRxBasicCANObjects        16
#define kCanNumberOfUsedRxBasicCANObjects    2

#define kCanInitObj1                         0
#define C_DISABLE_TX_MASK_EXT_ID
#define C_DISABLE_RX_MASK_EXT_ID
#define C_MASK_EXT_ID                        0xFFFFFFFF

#define C_ENABLE_CAN_CAN_INTERRUPT_CONTROL
#define C_ENABLE_CAN_TX_CONF_FCT
#define APPL_CAN_TX_CONFIRMATION             NmhCanMsgConfirmed

#define C_DISABLE_TX_POLLING
#define C_DISABLE_RX_BASICCAN_POLLING
#define C_DISABLE_RX_FULLCAN_POLLING
#define C_DISABLE_ERROR_POLLING
#define C_DISABLE_WAKEUP_POLLING
#define C_DISABLE_FULLCAN_OVERRUN
#define C_ENABLE_OSEK_OS_INTCAT2
#define C_DISABLE_COPY_RX_DATA_WITH_DLC
#define kCanTxQueueBytes                     4
#define kCanNumberOfMaxBasicCAN              1
#define kCanNumberOfHwObjPerBasicCan         2
#define C_DISABLE_CAN_RAM_CHECK
#define C_ENABLE_SLEEP_WAKEUP
#define C_DISABLE_CANCEL_IN_HW
#define C_DISABLE_ONLINE_OFFLINE_CALLBACK_FCT

#define C_RANGE0_IDTYPE                      kCanIdTypeStd
#define kCanChannel_Channel0                 0
#define C_ENABLE_INTCTRL_ADD_CAN_FCT
#if defined(C_SINGLE_RECEIVE_BUFFER) || defined(C_MULTIPLE_RECEIVE_BUFFER)
#error "DrvCan__baseRI1.5 doesn't support Single/Multiple Receive Buffer API for the callback 'ApplCanMsgReceived'!"
#endif

#define C_DISABLE_RETRANSMIT
#define kCanNumberOfUsedCanTxIdTables        1
#define kCanNumberOfUsedCanRxIdTables        1
#define kCanHwTxStartIndex                   31

#define kCanHwUnusedStartIndex               31

#define kCanHwRxFullStartIndex               2

#define kCanHwRxBasicStartIndex              0

#define kCanNumberOfUsedTxCANObjects         1

#define kCanNumberOfUnusedObjects            0

#define kCanNumberOfTxDirectObjects          0

#define C_DISABLE_TX_FULLCAN_OBJECTS


#define kCanHwTxNormalIndex                  31

#define C_DISABLE_INDIVIDUAL_POLLING
#define kCanNumberOfHwObjIndivPolling        32

#define kCanBasisAdr                         0xFFF7E800
#define kCanMailboxBasisAdr                  0xFFF7E400
#define kCanControllerMode                   kCanHECCMode
#define kCanRxBasicCANObjMask                0x03
#define kCanOPCSetting                       0x02
#define kCanRxFullCANObjMask                 0x7FFFFFFC
#define C_DISABLE_INT_OSCAT2




/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 88863978
      #error "The magic number of the generated file <F:\projects\ADR-Porsche\Porsche_ADR_Development_trunk\MOD\MOD_CAN_GEN\inc\can_cfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 88863978
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __CAN_CFG_H__ */
