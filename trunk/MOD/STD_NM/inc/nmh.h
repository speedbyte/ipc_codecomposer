/******   STARTSINGLE_OF_MULTIPLE_COMMENT    ******/


/******************************************************************************
 | Project Name: Network Management for Powertrain
 |    File Name: nmh.h
 |
 |  Description: Header of Powertrain Network Management Implementation.
 |               Can also be used on other busses.
 |
 |               Project for Volkswagen/Audi.
 |
 |------------------------------------------------------------------------------
 |               C O P Y R I G H T
 |------------------------------------------------------------------------------
 | Copyright (c) 2004-2010 by Vector Informatik GmbH.          All rights reserved.
 |
 |       This software is copyright protected and 
 |       proprietary to Vector Informatik GmbH.
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
 | Hp           Armin Happel              Vector Informatik GmbH
 | Tri          Frank Triem               Vector Informatik GmbH
 | vismdr       Markus Drescher           Vector Informatik GmbH
 | visoh        Oliver Hornung            Vector Informatik GmbH
 |------------------------------------------------------------------------------
 |               R E V I S I O N   H I S T O R Y
 |------------------------------------------------------------------------------
 | Date         Ver      Author  Description
 | ----------   -------  ------  -----------------------------------------------
 | 2004-06-21   1.00.00  Hp,Tri  ESCAN00007396: Creation of module
 |                               ESCAN00008109: Added service that retrieves the internal state of the NM
 | 2004-07-09   1.01.00   Tri    ESCAN00008806: Tx Observe Mechanism might not recognize a timeout
 |                               ESCAN00008807: Timing of NM-message is incorrect after BusOff
 | 2004-09-16   1.02.00   Tri    ESCAN00009499: Apply PSC naming conventions of version definitions
 | 2004-12-01   1.03.00   Tri    ESCAN00010383: Support multi channel indexed API
 |                               ESCAN00009792: Implement API call types
 |                               ESCAN00008723: Use new memory qualifier
 |                               ESCAN00010496: NmhIntBusOffRxRestore not called
 | 2005-03-18   1.04.00   Tri    ESCAN00010075: Bus communication request for external networks
 |                               ESCAN00010803: Update of NM-message data
 | 2005-04-07   1.05.00   Tri    ESCAN00011756: Compiler error if 'Timeout Time' longer than 'NM-message Tx Timeout Time'
 | 2005-04-15   1.06.00   Tri    ESCAN00011837: NmhIntActiveFailed() gets called even if transmission is not damaged
 |                               ESCAN00011928: Add explicit type cast before negations
 |                               ESCAN00012997: Include structure revised
 | 2006-05-11   1.07.00   Tri    ESCAN00016281: Initialization in Bus-Sleep Mode
 |                               ESCAN00016320: Restore receive capability after BusOff one task cycle earlier
 |                               ESCAN00016323: Stop BusOff recovery when entering Bus-Sleep Mode
 | 2006-09-08   1.08.00   Tri    ESCAN00016580: Allow Repeat Message to be greater than Timeout Time
 |                               ESCAN00016795: Support multi channel indexed API with indirection
 |                               ESCAN00017026: Support for TxObserve shall be permanently disabled for OEM Porsche
 |                               ESCAN00017048: Support of 'restart during shutdown'
 |                               ESCAN00017402: Support of PAG BusOff algorithm
 | 2006-10-27   1.09.00   Tri    ESCAN00018084: Compilation issue in function NmhTxObjConfirmed()
 |                               ESCAN00017730: Resolve compiler warnings
 | 2006-12-19   1.10.00   Tri    ESCAN00018387: Initialization with wrong channel handle
 | 2007-03-13   1.11.00   visoh  ESCAN00019446: No changes.
 | 2007-06-04   1.12.00   visoh  ESCAN00020886: No changes.
 | 2007-08-06   1.12.01   visoh  ESCAN00021788: No changes.
 | 2008-03-05   1.12.02   visoh  ESCAN00025113: No changes.
 |                               ESCAN00025439: No changes
 | 2009-01-23   1.12.03   visoh  ESCAN00032240: No changes
 | 2010-08-27   1.12.04   vismdr ESCAN00028173: Corrected header file protection
 |                               ESCAN00034994: Reworked memory attributes for function parameters
 |                               ESCAN00038064: Improved MISRA compliance.
 |*****************************************************************************/
#if defined(N_NMHIGH_H)
#else
#define N_NMHIGH_H

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "v_inc.h"


/*******************************************************************************
* Version
*******************************************************************************/
/* Network Management High version */
/* ##V_CFG_MANAGEMENT ##CQProject : Nm_PwrTrain_Vag CQComponent : Implementation */
#define NM_PWRTRAIN_VAG_VERSION          0x0112u /* BCD coded version number of NMH-module */
#define NM_PWRTRAIN_VAG_RELEASE_VERSION  0x04    /* Only incremented on Low-Level changes  */


/*******************************************************************************
* Global defines
*******************************************************************************/




#if defined ( NMH_ENABLE_INDEXED_NM )
  /* Channel handle for external NM-High functions. */
  #define NMH_CHANNEL_SYSTEMTYPECAN_ONLY  NmhChannelHandle channel
  #define NMH_CHANNEL_SYSTEMTYPE_ONLY     NmhChannelHandle channel
  #define NMH_CHANNEL_SYSTEMTYPE_FIRST    NmhChannelHandle channel,
  #define NMH_CHANNEL_SYSTEMPARA_ONLY     channel
  #define NMH_CHANNEL_SYSTEMPARA_FIRST    channel,
  /* Channel handle for internal NM-High functions. */
  #if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
    #define NMH_CHANNEL_NMTYPE_ONLY       NmhChannelHandle nmhChannel
    #define NMH_CHANNEL_NMTYPE_FIRST      NmhChannelHandle nmhChannel,
    #define NMH_CHANNEL_NMPARA_ONLY       nmhChannel
    #define NMH_CHANNEL_NMPARA_FIRST      nmhChannel,
  #else
    #define NMH_CHANNEL_NMTYPE_ONLY       NmhChannelHandle channel
    #define NMH_CHANNEL_NMTYPE_FIRST      NmhChannelHandle channel,
    #define NMH_CHANNEL_NMPARA_ONLY       channel
    #define NMH_CHANNEL_NMPARA_FIRST      channel,
  #endif
#else
  /* Channel handle for external NM-High functions. */
  #define NMH_CHANNEL_SYSTEMTYPECAN_ONLY  void /* PRQA S 3460 */ /* MD_CBD_19.4 */
  #define NMH_CHANNEL_SYSTEMTYPE_ONLY     void /* PRQA S 3460 */ /* MD_CBD_19.4 */
  #define NMH_CHANNEL_SYSTEMTYPE_FIRST
  #define NMH_CHANNEL_SYSTEMPARA_ONLY
  #define NMH_CHANNEL_SYSTEMPARA_FIRST
  /* Channel handle for internal NM-High functions. */
  #define NMH_CHANNEL_NMTYPE_ONLY         void /* PRQA S 3460 */ /* MD_CBD_19.4 */
  #define NMH_CHANNEL_NMTYPE_FIRST
  #define NMH_CHANNEL_NMPARA_ONLY
  #define NMH_CHANNEL_NMPARA_FIRST
#endif  /* NMH_ENABLE_INDEXED_NM */


/* API call and callback types.. */
#if defined ( NMH_API_CALL_TYPE )
#else
  #define NMH_API_CALL_TYPE
#endif

#if defined ( NMH_API_CALLBACK_TYPE )
#else
  #define NMH_API_CALLBACK_TYPE
#endif

#if defined ( NMH_INTERNAL_CALL_TYPE )
#else
  #define NMH_INTERNAL_CALL_TYPE
#endif

/* Error codes of assertions. */
#define kNmhErrorStateOutOfRange              0x10u
#define kNmhErrorEventOutOfRange              0x11u
#define kNmhErrorCommStateOutOfRange          0x12u
#define kNmhErrorNmStateOutOfRange            0x13u
#define kNmhErrorExtCommStateOutOfRange       0x14u
/*  */
#define kNmhErrorTimeoutTimerOutOfRange       0x20u
#define kNmhErrorMsgTimerOutOfRange           0x21u
#define kNmhErrorWaitBusSleepTimerOutOfRange  0x22u
#define kNmhErrorRepeatMsgTimerOutOfRange     0x23u


/* States of the network management. */
#define kNmhStartFromSleep                    0x01u
#define kNmhStartFromPrepareSleep             0x02u
#define kNmhNormalOperationFromStart          0x04u
#define kNmhNormalOperationFromReadySleep     0x08u


/*******************************************************************************
* Global data types and structures
*******************************************************************************/

/*---- data type for nmh communication mode ----------------------------------*/
typedef enum
{
  NMH_READY_SLEEP = 0,           /* The application has no communication need */
                                 /* and is ready to sleep.                    */
  NMH_NORMAL_OPERATION = 1       /* The application has communication need.   */
} tNmhCommStateType;

/* States of the NMH state machine. */
typedef enum
{
  kNmhStateRepeatMsg    = 0u,
  kNmhStateNormalMode   = 1u,
  kNmhStateReadySleep   = 2u,
  kNmhStatePrepareSleep = 3u,
  kNmhStateSleep        = 4u
} tNmhStateType;

/* Shutdown validation in Bus-Sleep Mode. */
typedef enum
{
  NMH_SHUTDOWN_VALID    = 0u,   /* Network shutdown is still valid */
  NMH_RESTART_REQ       = 1u,   /* Network restart request is pending */
  NMH_SHUTDOWN_FAILED   = 2u    /* Network shutdown has been aborted */
} tNmhShutdownType;

/* Initialization states of the network management. */
typedef enum
{
  NMH_INIT_NORMAL       = 0u,
  NMH_INIT_SLEEP        = 1u
} tNmhInitType;

/*------------------- data type for message data -----------------------------*/
typedef vuint8 tNmhMsgDataType[7];

#if defined ( NMH_ENABLE_INDEXED_NM )
/*---------- data type for post-compile configuration parameters -------------*/
typedef struct 
{
  const vuint16 kNmhMsgCycleTime;         /* Cycle time of the transmitted Network Management Message */
  const vuint16 kNmhTimeoutTime;          /* Timeout of the reception of Network Management Messages. */
  const vuint16 kNmhWaitBusSleepTime;     /* Bus calm down time. */
  const vuint16 kNmhPrepareSleepTime;     /* Wait a certain time in prepare sleep mode before preparing for sleeping. */
  const vuint16 kNmhRepeatMsgCountsPara;  /* Number of Network Management Messages to be sent in sub-state Repeat Message. */

  const vuint16 kNmhMsgTimeout;           /* Timeout for the successful transmission of NM-messages. */


  const vuint16 kNmhBusOffRecoveryTime1;  /* BusOff recovery time of first BusOff. */
  const vuint16 kNmhBusOffRecoveryTime2;  /* BusOff recovery time of consecutive BusOffs. */
} tNmhConfigType;
#endif  /* defined ( NMH_ENABLE_INDEXED_NM ) */
 

/*******************************************************************************
* Return values 
*******************************************************************************/

/* NmhIntMsgRequest return values ----------------------------------------*/
#define kNmhTxRequestFailed 0x00u /* Message transmission disabled or no sending possible */
#define kNmhTxRequestOk     0x01u /* Message transmitted or queued                        */
#define kNmhTxPartOffline   0x02u /* Message transmission disabled or partial offline     */




/*******************************************************************************
* External Data
*******************************************************************************/
/* Network Management High version */
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kNmhMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kNmhSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kNmhReleaseVersion;

#if defined ( NMH_ENABLE_INDEXED_NM )
/* Structure for post-compile configuration parameters. */
V_MEMROM0 extern V_MEMROM1 tNmhConfigType V_MEMROM2 NmhConfiguration[kNmhNumberOfChannels];

  #if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
/* Channel indirection: CAN to NM */
V_MEMROM0 extern V_MEMROM1 NmhChannelHandle V_MEMROM2 kNmhCanToNmIndirection[kCanNumberOfChannels];

/* Channel indirection: NM to CAN */
V_MEMROM0 extern V_MEMROM1 NmhChannelHandle V_MEMROM2 kNmhNmToCanIndirection[kNmhNumberOfChannels];
  #endif

#endif /* defined ( NMH_ENABLE_INDEXED_NM ) */



/*******************************************************************************
* Prototypes of export functions
*******************************************************************************/


/*--- functions called from network management high by application. ----------*/

 /* Initialize NM-High on Power-up */
extern void NMH_API_CALL_TYPE NmhInitPowerOn( tNmhInitType nmhInitState );

/* Initialize NM-High */
extern void NMH_API_CALL_TYPE NmhInit( NMH_CHANNEL_SYSTEMTYPE_FIRST  tNmhInitType nmhInitState );

/* Cyclic NM-High task. Has to be called cyclic every kNmhCycleTime ms. */
extern void NMH_API_CALL_TYPE NmhTask( NMH_CHANNEL_SYSTEMTYPE_ONLY );

/* Request to change the bus-communication state. */
extern void NMH_API_CALL_TYPE NmhRequestCommState( NMH_CHANNEL_SYSTEMTYPE_FIRST  tNmhCommStateType commState );

#if defined ( NMH_ENABLE_CAR_WUP )
/* Request to wake up the external networks. */
extern void NMH_API_CALL_TYPE NmhCarWupRequest( NMH_CHANNEL_SYSTEMTYPE_FIRST  tNmhCommStateType carWupState );
#endif

/* Return the internal state of the network management. */
extern tNmhStateType NMH_API_CALL_TYPE NmhGetState( NMH_CHANNEL_SYSTEMTYPE_ONLY );

/* Validation of network shutdown. */
extern tNmhShutdownType NMH_API_CALL_TYPE NmhValidateShutdown( NMH_CHANNEL_SYSTEMTYPE_ONLY );

/* Get access to user data buffer. */
extern vuint8* NMH_API_CALL_TYPE NmhGetUserDataBuffer( NMH_CHANNEL_SYSTEMTYPE_ONLY );


/*--- functions called from nm-high by data link layer. ----------------------*/

/* Indidcation of the reception of a NM-message. */
extern void NMH_API_CALL_TYPE NmhMsgIndication( NMH_CHANNEL_SYSTEMTYPE_ONLY );
/* Confirmation of the successful transmission of a NM-message. */
extern void NMH_API_CALL_TYPE NmhMsgConfirmation( NMH_CHANNEL_SYSTEMTYPE_ONLY );

/* Confirmation of sucessfull transmission of CAN message. */
extern void NMH_API_CALL_TYPE NmhTxObjConfirmed( NMH_CHANNEL_SYSTEMTYPE_ONLY );

/* Notification of a critical error on the bus. */
extern void NMH_API_CALL_TYPE NmhBusCriticalFailure( NMH_CHANNEL_SYSTEMTYPECAN_ONLY ); /* PRQA S 3451 */ /* MD_Nmh_3451 */

/* Indication function for the reception of CAN messages. */
extern void NMH_API_CALL_TYPE NmhRxObjReceived( NMH_CHANNEL_SYSTEMTYPE_ONLY );

/* Notification about wake-up event, like e.g. ignition, message on CAN-bus that is sleeping. */
extern void NMH_API_CALL_TYPE NmhWakeUpRequest( NMH_CHANNEL_SYSTEMTYPECAN_ONLY ); /* PRQA S 3451 */ /* MD_Nmh_3451 */



/*--- functions called by network management high ----------------------------*/

/* Functions, to indicate the change of the nmh state. */
extern void NMH_API_CALLBACK_TYPE NmhIntSleep( NMH_CHANNEL_SYSTEMTYPE_ONLY );        /* Nmh has entered sleep mode.  */
extern void NMH_API_CALLBACK_TYPE NmhIntPrepareSleep( NMH_CHANNEL_SYSTEMTYPE_ONLY ); /* Nmh prepares for sleeping.   */
extern void NMH_API_CALLBACK_TYPE NmhIntNetStart( NMH_CHANNEL_SYSTEMTYPE_ONLY );     /* Network mode is started. */
extern void NMH_API_CALLBACK_TYPE NmhIntNetStop( NMH_CHANNEL_SYSTEMTYPE_ONLY );      /* Network mode is stopped. */

/* Request to transmit a network management message. */
extern vuint8 NMH_API_CALLBACK_TYPE NmhIntMsgRequest( NMH_CHANNEL_SYSTEMTYPE_FIRST  tNmhMsgDataType* nmMsgData );
#if defined ( NMH_ENABLE_CAR_WUP )
/* Request to cancel a network management message transmission request. */
extern void NMH_API_CALLBACK_TYPE NmhIntCancelMsgRequest( NMH_CHANNEL_SYSTEMTYPE_ONLY );
#endif

/* Notification that the transmission of a NM-message has timed out, while no network managemenr messag has been received. */
extern void NMH_API_CALLBACK_TYPE NmhIntActiveFailed( NMH_CHANNEL_SYSTEMTYPE_ONLY );


/* Notification about begin and end of BusOff. */
extern void NMH_API_CALLBACK_TYPE NmhIntBusOffStart( NMH_CHANNEL_SYSTEMTYPE_FIRST  vuint8 numberOfBusOff );
extern void NMH_API_CALLBACK_TYPE NmhIntBusOffEnd( NMH_CHANNEL_SYSTEMTYPE_ONLY );
extern void NMH_API_CALLBACK_TYPE NmhIntBusOffRxRestore( NMH_CHANNEL_SYSTEMTYPE_ONLY );

/* The application requests to wake up the network. */
extern void NMH_API_CALLBACK_TYPE NmhIntWakeUp( NMH_CHANNEL_SYSTEMTYPE_ONLY );

#if defined ( NMH_ENABLE_CAR_WUP )
/* Confirmation for the successful Car Wakeup Request / Release  */
extern void NMH_API_CALLBACK_TYPE NmhIntCarWupRequestConfirmation( NMH_CHANNEL_SYSTEMTYPE_ONLY );
extern void NMH_API_CALLBACK_TYPE NmhIntCarWupReleaseConfirmation( NMH_CHANNEL_SYSTEMTYPE_ONLY );
#endif

  #if defined ( NMH_ENABLE_TESTDEBUG )
/* NM-High Assertion */
extern void NMH_API_CALLBACK_TYPE NmhIntAssert( NMH_CHANNEL_SYSTEMTYPE_FIRST  vuint8 condition, vuint8 errCode );


  #else
    #if defined ( NMH_ENABLE_INDEXED_NM )
      #define NmhIntAssert( channel, cond, err )
    #else
      #define NmhIntAssert( cond, err )
    #endif
  #endif


/* Disable the CAN-Interrupts. */
#if defined ( NmhIntInterruptDisable )
/* defined as macro */
#else
extern void NMH_API_CALLBACK_TYPE NmhIntInterruptDisable( void );
#endif

/* Restore the CAN-Interrupts. */
#if defined ( NmhIntInterruptRestore )
/* defined as macro */
#else
extern void NMH_API_CALLBACK_TYPE NmhIntInterruptRestore( void );
#endif


#endif /* if (!defined(N_NMHIGH_H)) */
/***** end of header file *****************************************************/

/*  *****   STOPSINGLE_OF_MULTIPLE_COMMENT    *****  */

/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
