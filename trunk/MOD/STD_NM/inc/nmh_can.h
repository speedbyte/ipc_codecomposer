/******   STARTSINGLE_OF_MULTIPLE_COMMENT    ******/


/******************************************************************************
 | Project Name: Network Management High Wrapper
 |    File Name: nmh_can.h
 |
 |  Description: Header of NMH Vector CAN Driver adapter.
 |
 |------------------------------------------------------------------------------
 |               C O P Y R I G H T
 |------------------------------------------------------------------------------
 | Copyright (c) 2004-2010 by Vector Informatik GmbH.     All rights reserved.
 |
 |       This software is copyright protected and 
 |       proporietary to Vector Informatik GmbH.
 |       Vector Informatik GmbH grants to you only
 |       those rights as set out in the license conditions.
 |       All other rights remain with Vector Informatik GmbH.
 | 
 |       Diese Software ist urheberrechtlich geschuetzt. 
 |       Vector Informatik GmbH raeumt Ihnen an dieser Software nur 
 |       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
 |       Alle anderen Rechte verbleiben bei Vector Informatik GmbH.
 |
 |------------------------------------------------------------------------------
 |               A U T H O R   I D E N T I T Y
 |------------------------------------------------------------------------------
 | Initials     Name                      Company
 | --------     ---------------------     --------------------------------------
 | Pet          Thomas Petrus             Vector Informatik GmbH
 | Tri          Frank Triem               Vector Informatik GmbH
 | vismdr       Markus Drescher           Vector Informatik GmbH
 | visoh        Oliver Hornung            Vector Informatik GmbH
 |------------------------------------------------------------------------------
 |               R E V I S I O N   H I S T O R Y
 |------------------------------------------------------------------------------
 | Date         Ver      Author  Description
 | ----------   -------  ------  -----------------------------------------------
 | 2004-09-16   1.00.00   Tri    ESCAN00009513: Creation of module
 | 2004-10-01   1.01.00   Tri    ESCAN00009725: Support indexed CAN-Driver
 | 2004-10-06   1.02.00   Tri    ESCAN00009766: Support IL state 'waiting'
 |                               ESCAN00009762: Assertion in CanSleep fails
 | 2004-12-01   1.03.00   Tri    ESCAN00010385: Support multi channel indexed API
 |                               ESCAN00009791: Implement API call types
 |                               ESCAN00010103: Consistency check for generation tool settings
 |                               ESCAN00010487: Continuous BusOffs not recognized
 | 2005-03-18   1.04.00   Tri    ESCAN00010078: Bus communication request for external networks
 |                               ESCAN00010805: Update of NM-message data
 |                               ESCAN00010960: NmhRequestCommState from NmhIntActiveFailed removed
 | 2005-07-22   1.05.00   Tri    ESCAN00012236: Compiler error due to missing semicolon
 |                               ESCAN00012994: Support power fail handler of CCL
 | 2005-08-12   1.06.00   Pet    ESCAN00013202: support CANbedded handling by CCL
 | 2006-05-11   1.07.00   Tri    ESCAN00016177: CanResetBusXXX and CanInit interrupted by CAN-Interrupt
 | 2006-09-11   1.08.00   Tri    ESCAN00016798: IL not accessed by NM if CCL is available
 |                               ESCAN00016799: Support multi channel indexed API with indirection
 |                               ESCAN00016796: Support multiple identities
 |                               ESCAN00017017: Add callback to application for each reception of a NM message
 |                               ESCAN00017392: CanOffline has to be called in NmhIntSleep
 |                               ESCAN00017404: Support of PAG BusOff algorithm
 | 2006-10-31   1.09.00   Tri    ESCAN00018167: Support ApplCanTxConfirmation() of LI1.3 CAN-Driver
 |                               ESCAN00018208: Channel indirection
 | 2006-12-19   1.10.00   Tri    ESCAN00018355: Correct API of multi/single receive buffer
 | 2007-03-13   1.11.00   visoh  ESCAN00019446: Compiler Errors if an old CanDrv-version of HC12 is used
 | 2007-07-11   1.12.00   visoh  ESCAN00021387: No changes
 | 2007-07-18   1.12.01   visoh  ESCAN00021481: No changes
 | 2007-07-27   1.12.02   visoh  ESCAN00021628: No changes
 | 2007-11-20   1.12.03   visoh  ESCAN00021477: Support for special versions of MCS12
 |                               ESCAN00023251: No changes
 | 2010-08-27   1.12.04   vismdr ESCAN00028174: Corrected header file protection
 |                               ESCAN00034995: Reworked memory attributes for function parameters
 |                               ESCAN00038065: Improved MISRA compliance
 |                               ESCAN00042522: No changes
 |                               ESCAN00044432: Removed NMH_ENABLE_MULTI_ECU definition, handled by config file.
 |*****************************************************************************/
#if defined(N_NMHIGH_CAN_H)
#else
#define N_NMHIGH_CAN_H

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "v_inc.h"


/*******************************************************************************
* Version
*******************************************************************************/
/* Network Management High Wrapper version */
/* ##V_CFG_MANAGEMENT ##CQProject : Nm_PwrTrainWrapperExt_Vag CQComponent : Implementation */
#define NM_PWRTRAINWRAPPEREXT_VAG_VERSION          0x0112u /* BCD coded version number of NMH-CAN-module */
#define NM_PWRTRAINWRAPPEREXT_VAG_RELEASE_VERSION  0x04u   /* Only incremented on Low-Level changes  */

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kNmhWrapperMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kNmhWrapperSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kNmhWrapperReleaseVersion;


/*******************************************************************************
* Global defines
*******************************************************************************/


#if defined ( NMH_ENABLE_INDEXED_NM )
  /* Channel handle for application callback function calls. */
  #if defined ( NMH_CHANNEL_APPLTYPE_ONLY )
  /* Compatibility with nmh.c version 1.00.00. */
  #else
    #define NMH_CHANNEL_APPLTYPE_ONLY   NMH_CHANNEL_SYSTEMTYPE_ONLY
    #define NMH_CHANNEL_APPLTYPE_FIRST  NMH_CHANNEL_SYSTEMTYPE_FIRST
    #define NMH_CHANNEL_APPLPARA_ONLY   NMH_CHANNEL_SYSTEMPARA_ONLY
    #define NMH_CHANNEL_APPLPARA_FIRST  NMH_CHANNEL_SYSTEMPARA_FIRST
  #endif
  /* Channel handle for CAN-Driver function calls. */
  #define NMH_CHANNEL_CANTYPE_ONLY      CanChannelHandle channel
  #define NMH_CHANNEL_CANTYPE_FIRST     CanChannelHandle channel,
  #define NMH_CHANNEL_CANPARA_ONLY    channel
  #define NMH_CHANNEL_CANPARA_FIRST   channel,
#else
  /* Channel handle for application callback function calls. */
  #if defined ( NMH_CHANNEL_APPLTYPE_ONLY )
  /* Compatibility with nmh.c version 1.00.00. */
  #else
    #define NMH_CHANNEL_APPLTYPE_ONLY   NMH_CHANNEL_SYSTEMTYPE_ONLY
    #define NMH_CHANNEL_APPLTYPE_FIRST  NMH_CHANNEL_SYSTEMTYPE_FIRST
    #define NMH_CHANNEL_APPLPARA_ONLY
    #define NMH_CHANNEL_APPLPARA_FIRST
  #endif
  /* Channel handle for CAN-Driver function calls. */
  #if defined ( kNmhCanChannel )
    #define NMH_CHANNEL_CANTYPE_ONLY    CanChannelHandle channel
    #define NMH_CHANNEL_CANTYPE_FIRST   CanChannelHandle channel,
    #define NMH_CHANNEL_CANPARA_ONLY    (CanChannelHandle)kNmhCanChannel
    #define NMH_CHANNEL_CANPARA_FIRST   (CanChannelHandle)kNmhCanChannel,
  #else
    #define NMH_CHANNEL_CANTYPE_ONLY    NMH_CHANNEL_SYSTEMTYPE_ONLY
    #define NMH_CHANNEL_CANTYPE_FIRST   NMH_CHANNEL_SYSTEMTYPE_FIRST
    #define NMH_CHANNEL_CANPARA_ONLY    
    #define NMH_CHANNEL_CANPARA_FIRST   
  #endif
#endif  /* NMH_ENABLE_INDEXED_NM */


/* API call and callback types.. */
#if defined ( NMH_WRAPPER_API_CALL_TYPE )
#else
  #define NMH_WRAPPER_API_CALL_TYPE  NMH_API_CALLBACK_TYPE
#endif

#if defined ( NMH_WRAPPER_API_CALLBACK_TYPE )
#else
  #define NMH_WRAPPER_API_CALLBACK_TYPE
#endif

#if defined ( NMH_WRAPPER_INTERNAL_CALL_TYPE )
#else
  #define NMH_WRAPPER_INTERNAL_CALL_TYPE
#endif

/* Error codes of assertions. */
#define kNmhIntErrorConsistency         0xF0u
#define kNmhIntErrorChannelNotSupport   0xF1u
#define kNmhIntInvalidTxHandle          0xF2u
#define kNmhIntInvalidTxObject          0xF3u
#define kNmhIntInvalidChannel           0xF4u

/* Channel definition */
#define kNmhInvalidChannel ((NmhChannelHandle)0xFF)

/* Internal definitions required for CAN-Driver compatibility. */
#if defined ( CAN_DRIVER_VERSION )
#else
  /* CAN_DRIVER_VERSION has to be defined in order to avoid compiler warnings. */
  #define CAN_DRIVER_VERSION 0xFFFF
#endif
/* ESCAN00021477 Correct versions */
#if ( C_VERSION_REF_IMPLEMENTATION > 0x130 ) 
#else
  #define NMH_TX_OBSERVE_LI_13_API
#endif

/* ESCAN00019446: Old HC12 Driver version line 0x02xx */


/*******************************************************************************
  Global data types and structures
*******************************************************************************/

#if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL )
  #define PRECOPY_PARAM_TYPE    CanRxInfoStructPtr
  #define PRECOPY_PARAM         rxStruct
#else /* if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL ) */
  #if defined ( C_SINGLE_RECEIVE_BUFFER )
    #define PRECOPY_PARAM_TYPE    CanReceiveHandle
    #define PRECOPY_PARAM         rxObject
  #endif /* if defined ( C_SINGLE_RECEIVE_BUFFER ) */
  #if defined ( C_MULTIPLE_RECEIVE_BUFFER )
    #define PRECOPY_PARAM_TYPE    CanChipDataPtr
    #define PRECOPY_PARAM         rxDataPtr
  #endif /* if defined ( C_MULTIPLE_RECEIVE_BUFFER ) */
#endif /* if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL ) */

#if defined ( NMH_ENABLE_INDEXED_NM )
  #define PRECOPY_CHANNEL_PARAM (rxStruct->Channel)
#else
  #define PRECOPY_CHANNEL_PARAM
#endif

#if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL )
  #define MSG_RECEIVED_PARAM_TYPE    CanRxInfoStructPtr
  #define MSG_RECEIVED_PARAM         rxStruct
    #define MSG_TRANSMIT_PARAM_TYPE  CanTxInfoStructPtr
  #define MSG_TRANSMIT_PARAM         txStruct
#else /* if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL ) */
  #define MSG_RECEIVED_PARAM_TYPE    void
  #define MSG_RECEIVED_PARAM
  #define MSG_TRANSMIT_PARAM_TYPE    CanTransmitHandle
  #define MSG_TRANSMIT_PARAM         txObject
#endif /* if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL ) */

#if defined ( NMH_ENABLE_INDEXED_NM )
  #define MSG_RECEIVED_CHANNEL_PARAM (rxStruct->Channel)
  #define MSG_TRANSMIT_CHANNEL_PARAM (txStruct->Channel)
#else
  #define MSG_RECEIVED_CHANNEL_PARAM
  #define MSG_TRANSMIT_CHANNEL_PARAM
#endif
#if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  #define MSG_RECEIVED_CHANNEL_IDX (rxStruct->Channel)
  #define MSG_TRANSMIT_CHANNEL_IDX (txStruct->Channel)
#endif


/*******************************************************************************
  Global macros for export
*******************************************************************************/
#if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
  #define NmhCanToNmChannel(channel) kNmhCanToNmIndirection[(channel)] /* PRQA S 3453 */ /* MD_CBD_19.7 */
#else
  #define NmhCanToNmChannel(channel) (channel)  /* PRQA S 3453 */ /* MD_CBD_19.7 */
#endif


/*******************************************************************************
* External Data
*******************************************************************************/
#if defined ( NMH_ENABLE_INDEXED_NM ) || defined ( NMH_ENABLE_MULTI_ECU )

  #if defined ( NMH_ENABLE_INDEXED_NM )
    #define NMH_TX_NM_MSG_CHANNEL_FIELD   [kNmhNumberOfChannels]
  #else
    #define NMH_TX_NM_MSG_CHANNEL_FIELD
  #endif

  #if defined ( NMH_ENABLE_MULTI_ECU )
    #define NMH_TX_NM_MSG_IDENTITY_FIELD  [kVNumberOfIdentities]
  #else
    #define NMH_TX_NM_MSG_IDENTITY_FIELD
  #endif

/* Transmit handles of the NM-message. */
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle V_MEMROM2 kNmhTransmitHandleField NMH_TX_NM_MSG_CHANNEL_FIELD NMH_TX_NM_MSG_IDENTITY_FIELD;

/* Pointer to NM-message data. */
V_MEMROM0 extern V_MEMROM1 vuint8* V_MEMROM2 kNmhNmMsgDataPtrField NMH_TX_NM_MSG_CHANNEL_FIELD NMH_TX_NM_MSG_IDENTITY_FIELD;

#endif  /* defined ( NMH_ENABLE_INDEXED_NM ) || defined ( NMH_ENABLE_MULTI_ECU ) */

#if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
/* Channel indirection: CAN to NM */
V_MEMROM0 extern V_MEMROM1 NmhChannelHandle V_MEMROM2 kNmhCanToNmIndirection[kCanNumberOfChannels]; /* PRQA S 3451 */ /* MD_NmhCan_3451a */

/* Channel indirection: NM to CAN */
V_MEMROM0 extern V_MEMROM1 NmhChannelHandle V_MEMROM2 kNmhNmToCanIndirection[kNmhNumberOfChannels]; /* PRQA S 3451 */ /* MD_NmhCan_3451a */
#endif /* defined ( NMH_ENABLE_CHANNEL_INDIRECTION ) */





/*******************************************************************************
  Prototypes of export functions
*******************************************************************************/

/******************************************************************************/
/*--- functions called by NM-High Wrapper; defined by application ------------*/
/******************************************************************************/

  #if defined ( NMH_ENABLE_CALLBACK_FCT )

/* Callback functions, to notify about begin and end of BusOff. */
extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhBusOffStart( NMH_CHANNEL_APPLTYPE_FIRST  vuint8 numberOfBusOff );
extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhBusOffEnd( NMH_CHANNEL_APPLTYPE_ONLY );
extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhBusOffRxRestore( NMH_CHANNEL_APPLTYPE_ONLY );

/* Callback function, to notify that the transmission of a NM-message has timed out, 
   while no network managemenr messag has been received. */
extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhActiveFailed( NMH_CHANNEL_APPLTYPE_ONLY );


  #endif

/* Callback functions, to request a wake up of the CAN. */
extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhWakeUp( NMH_CHANNEL_APPLTYPE_ONLY );

/* Callback functions, to notify about the change of the nmh state. */
extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhSleep( NMH_CHANNEL_APPLTYPE_ONLY );         /* Nmh has entered sleep mode.  */

  #if defined ( NMH_ENABLE_CALLBACK_FCT )

extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhPrepareSleep( NMH_CHANNEL_APPLTYPE_ONLY );  /* Nmh prepares for sleeping.   */
extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhNetStart( NMH_CHANNEL_APPLTYPE_ONLY );      /* Network mode is started. */
extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhNetStop( NMH_CHANNEL_APPLTYPE_ONLY );       /* Network mode is stopped. */

  #endif

  #if defined ( NMH_ENABLE_CAR_WUP )
/* Confirmation for the successful Car Wakeup Request / Release  */
extern void NMH_API_CALLBACK_TYPE ApplNmhCarWupRequestConfirmation( NMH_CHANNEL_APPLTYPE_ONLY ); /* PRQA S 3451 */ /* MD_NmhCan_3451a */
extern void NMH_API_CALLBACK_TYPE ApplNmhCarWupReleaseConfirmation( NMH_CHANNEL_APPLTYPE_ONLY ); /* PRQA S 3451 */ /* MD_NmhCan_3451a */
  #endif

  #if defined ( NMH_ENABLE_NM_MSG_RX_IND_FCT )
/* Notification that a NM message has been received (returns the NM message ID and the Data pointer). */
extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhCanNmMsgReceived( NMH_CHANNEL_APPLTYPE_FIRST  vuint16 nmhMsgId, CanChipDataPtr nmhMsgDataPtr );
  #endif

  #if defined ( NMH_ENABLE_TESTDEBUG )
/* Callback function to report fatal errors. */
extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhFatalError( NMH_CHANNEL_APPLTYPE_FIRST  vuint8 errCode );
  #endif


  #if defined( NMH_ENABLE_CONF_FCT_CALLBACK ) && defined ( C_ENABLE_CAN_TX_CONF_FCT )
  /* Application message confirmation function. */
extern void NMH_WRAPPER_API_CALLBACK_TYPE ApplNmhCanMsgConfirmed( MSG_TRANSMIT_PARAM_TYPE MSG_TRANSMIT_PARAM );
  #endif



/*--- functions called by NM-High Wrapper; defined by CCL --------------------*/

  #if defined ( NMH_ENABLE_POWERFAIL_HANDLER )
extern void CclCanOnline( NMH_CHANNEL_CANTYPE_ONLY );
extern void CclCanOffline( NMH_CHANNEL_CANTYPE_ONLY );
  #endif


/*--- functions called by network management high ----------------------------*/
/* All functions are defined as callback function within nmh.h */

/*--- functions normally called from NM-High Wrapper. ------------------------*/


  #if defined( C_ENABLE_CAN_TX_CONF_FCT )
extern void NMH_WRAPPER_API_CALL_TYPE NmhCanMsgConfirmed( MSG_TRANSMIT_PARAM_TYPE MSG_TRANSMIT_PARAM );
  #endif



#endif /* if (!defined(N_NMHIGH_CAN_H)) */
/***** end of header file *****************************************************/

/*  *****   STOPSINGLE_OF_MULTIPLE_COMMENT    *****  */

/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
