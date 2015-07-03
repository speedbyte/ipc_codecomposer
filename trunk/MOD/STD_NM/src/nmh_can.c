/******   STARTSINGLE_OF_MULTIPLE_COMMENT    ******/


/******************************************************************************
 | Project Name: Network Management High Wrapper
 |    File Name: nmh_can.c
 |
 |  Description: Adapter of Network Management High and Vector CAN Driver.
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
 | 2007-03-13   1.11.00   visoh  ESCAN00019446: No changes.
 | 2007-07-11   1.12.00   visoh  ESCAN00021387: Filter Message 0x6FF
 | 2007-07-18   1.12.01   visoh  ESCAN00021481: Correct define dependancy
 | 2007-07-27   1.12.02   visoh  ESCAN00021628: Enable multiple ECU usage for OEM VAG
 | 2007-11-20   1.12.03   visoh  ESCAN00021477: No changes.
 |                               ESCAN00023251: Completed solution for ESCAN00016177
 | 2010-08-27   1.12.04   vismdr ESCAN00028174: No changes.
 |                               ESCAN00034995: Reworked memory attributes for function parameters
 |                               ESCAN00038065: Improved MISRA compliance.
 |                               ESCAN00042522: Always using CanGlobalInterruptDisable()/CanGlobalInterruptRestore()
 |                               ESCAN00044432: No changes.
 |*****************************************************************************/
#define NMH_CAN_INTERNAL_MODULE

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "nmh.h"                             /* Include interface of NM-High. */
#include "nmh_can.h"                 /* Include interface of NM-High Wrapper. */
  

/******************************************************************************/
/* Version check                                                              */
/******************************************************************************/
#if ( NM_PWRTRAINWRAPPEREXT_VAG_VERSION != 0x0112u )   /* compare file header version   */
  #error "The included header nmh_can.h is incompatible with the nmh_can.c version."
#endif                                       /* legal file header version     */
#if ( NM_PWRTRAINWRAPPEREXT_VAG_RELEASE_VERSION != 0x04u )
  #error "Source and Header file are inconsistent!"
#endif


/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/

#if defined ( FALSE )
#else
  #define FALSE   0u
#endif

#if defined ( TRUE )
#else
  #define TRUE    1u
#endif

/* The parameters for the initialization of the CAN-Bus via CanInit is per default 0. */
/* Only pre-compile configuration of this parameter is supported. */
#if defined ( kNmhCanPara )
#else
  #define kNmhCanPara  0u
#endif

#if defined ( NMH_ENABLE_INDEXED_NM )
  #define NMH_SYSTEM_CHANNEL_IDX  channel
#else
  /* Per default the NM is mapped to system channel 0. */
  #if defined ( kNmhCanChannel )
    #define NMH_SYSTEM_CHANNEL_IDX  kNmhCanChannel
  #else
    #define NMH_SYSTEM_CHANNEL_IDX  0u
  #endif
#endif


/******************************************************************************/
/* Macros                                                                     */
/******************************************************************************/
#if defined ( NMH_ENABLE_INDEXED_NM ) || defined ( NMH_ENABLE_MULTI_ECU )

  #if defined ( NMH_ENABLE_INDEXED_NM )
    #define NMH_TX_NM_MSG_CHANNEL_INDEX   [NmhCanToNmChannel( NMH_CHANNEL_SYSTEMPARA_ONLY )]
  #else
    #define NMH_TX_NM_MSG_CHANNEL_INDEX
  #endif

  #if defined ( NMH_ENABLE_MULTI_ECU )
    #define NMH_TX_NM_MSG_IDENTITY_INDEX  [V_ACTIVE_IDENTITY_LOG]
  #else
    #define NMH_TX_NM_MSG_IDENTITY_INDEX
  #endif

  /* Transmit handle of the NM-message. */
  #define NmhGetTransmitHandle()   (kNmhTransmitHandleField NMH_TX_NM_MSG_CHANNEL_INDEX NMH_TX_NM_MSG_IDENTITY_INDEX )

  /* Pointer to NM-message data. */
  #define NmhGetNmMsgDataPtr()     (kNmhNmMsgDataPtrField NMH_TX_NM_MSG_CHANNEL_INDEX NMH_TX_NM_MSG_IDENTITY_INDEX )

#endif  /* defined ( NMH_ENABLE_INDEXED_NM ) || defined ( NMH_ENABLE_MULTI_ECU ) */

/* ESCAN00012994: If the power failed handler is used, 
   the NM-High Wrapper must not call CanOnline() and CanOffline() directly. */
#if defined ( NMH_ENABLE_POWERFAIL_HANDLER )
  #define NmhOnline()   CclCanOnline( NMH_CHANNEL_CANPARA_ONLY )
  #define NmhOffline()  CclCanOffline( NMH_CHANNEL_CANPARA_ONLY )
#else
  #define NmhOnline()   CanOnline( NMH_CHANNEL_CANPARA_ONLY )
  #define NmhOffline()  CanOffline( NMH_CHANNEL_CANPARA_ONLY )
#endif

/* Definition to get ID of current CAN message. */
#if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) || defined ( C_SINGLE_RECEIVE_CHANNEL )
  #define NMH_GET_RX_ACTUAL_ID ((vuint16)CanRxActualId(rxStruct))
#else
  #define NMH_GET_RX_ACTUAL_ID ((vuint16)CanRxActualId)
#endif


/****************************************************************************/
/* Local Constants                                                          */
/****************************************************************************/


/*==========================================================================*/
/* Driver Version for Diagnostics                                           */
/*==========================================================================*/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kNmhWrapperMainVersion    = (vuint8)(NM_PWRTRAINWRAPPEREXT_VAG_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kNmhWrapperSubVersion     = (vuint8)(NM_PWRTRAINWRAPPEREXT_VAG_VERSION  & 0x00FFu);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kNmhWrapperReleaseVersion = (vuint8)(NM_PWRTRAINWRAPPEREXT_VAG_RELEASE_VERSION);




/******************************************************************************/
/* Data definitions                                                           */
/******************************************************************************/


/* Flag that is set whenever the network management calls NmhIntPrepareSleep 
   and reset whenever the network mode is entered (NmhIntNetStart is called). */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 nmhPreparingForSleep[kCanNumberOfChannels];





#if defined ( NM_TYPE_NMHIGH )


/******************************************************************************
*
*
*           Code-Part for NM_TYPE_NMHIGH 
*
*
*******************************************************************************/


/*******************************************************************************
** Function:    NmhIntWakeUp
**
** Purpose:     Wake up of the CAN due to an application request to wake up
**              the network.
**
**  Called by:  NmhInit, NmhEnterStateRepeatMsg
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhIntWakeUp( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{

  /* the application has to call CanWakeUp */
  
  ApplNmhWakeUp( NMH_CHANNEL_APPLPARA_ONLY );   /* application callback function */
}


/*******************************************************************************
** Function:    NmhIntSleep
**
** Purpose:     Notifies the application, that the NMH has entered sleep state.
**
**  Called by:  NmhEnterStateSleep
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhIntSleep( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  /* The network management is preparing for sleeping. */
  nmhPreparingForSleep[NMH_SYSTEM_CHANNEL_IDX] = (vuint8)TRUE;

  /* the application has to call CanSleep */

  #if defined ( VGEN_ENABLE_CCL )
  /* Call CanOffline since it is not called by the CCL during intialization. */
  NmhOffline();  /* ESCAN00017392 */
  #endif

  ApplNmhSleep( NMH_CHANNEL_APPLPARA_ONLY );   /* application callback function */
}


/*******************************************************************************
** Function:    NmhIntPrepareSleep
**
** Purpose:     Requests the application to prepare for sleeping.
**
**  Called by:  NmhTask
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhIntPrepareSleep( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  /* The network management prepares for sleeping. */
  nmhPreparingForSleep[NMH_SYSTEM_CHANNEL_IDX] = (vuint8)TRUE;

  /* Clear the transmit queue and switch the transmit path off. */
  NmhOffline();

  /* ESCAN00023251 */
  CanGlobalInterruptDisable(); /* ESCAN00042522 */
  /* Clear all hardware transmit objects prior to entering sleep mode. */
  #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  /* macros must be encapsulated in this way */
  CanResetBusSleep( NMH_CHANNEL_CANPARA_ONLY, (CanInitHandle)kNmhCanPara );
  #else
  CanResetBusSleep( (CanInitHandle)kNmhCanPara );
  #endif
  CanGlobalInterruptRestore(); /* ESCAN00042522 */

  #if defined ( NMH_ENABLE_CALLBACK_FCT )
  ApplNmhPrepareSleep( NMH_CHANNEL_APPLPARA_ONLY );   /* application callback function */  
  #endif  
}


/*******************************************************************************
** Function:    NmhIntNetStart
**
** Purpose:     Notifies the application, that the NMH has entered network mode.
**              Starts the IL in order to send application messages.
**
**  Called by:  NmhExitStatePrepareSleep, NmhExitStateSleep
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhIntNetStart( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  /* The network management has entered network mode. */
  nmhPreparingForSleep[NMH_SYSTEM_CHANNEL_IDX] = (vuint8)FALSE;

  /* Switch the transmit path on. */
  NmhOnline();

  #if defined ( VGEN_ENABLE_CCL )
  #else
    #if defined ( VGEN_ENABLE_IL_VECTOR )
  /* If the IL is used, the IL has to be started. */
  IlTxStart( NMH_CHANNEL_CANPARA_ONLY );  
  IlRxStart( NMH_CHANNEL_CANPARA_ONLY );
    #endif
  #endif

  #if defined ( NMH_ENABLE_CALLBACK_FCT )
  ApplNmhNetStart( NMH_CHANNEL_APPLPARA_ONLY );   /* application callback function */
  #endif
}


/*******************************************************************************
** Function:    NmhIntNetStop
**
** Purpose:     Notifies the application, that the NMH has left network mode.
**              Stops the IL in order to stop sending application messages.
**
**  Called by:  NmhExitStateReadySleep
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhIntNetStop( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  #if defined ( NMH_ENABLE_CALLBACK_FCT )
  ApplNmhNetStop( NMH_CHANNEL_APPLPARA_ONLY );   /* application callback function */
  #endif

  #if defined ( VGEN_ENABLE_CCL )
  #else
    #if defined ( VGEN_ENABLE_IL_VECTOR )
  /* If the IL is used, the IL has to be stopped. */
  IlTxStop( NMH_CHANNEL_CANPARA_ONLY );
  IlRxStop( NMH_CHANNEL_CANPARA_ONLY );
    #endif
  #endif
}


/*******************************************************************************
** Function:    NmhIntMsgRequest
**
** Purpose:     Requests the CAN Driver to transmit a NM-message.
**
**  Called by:  NmhTask
**
**  Parameter:  nmMsgData : pointer to NM-message data
**
**  Returncode: Returns whether the NM-message transmit request was accepted.
**              Refer to the header for a description the returned values.
*******************************************************************************/
vuint8 NMH_WRAPPER_API_CALL_TYPE NmhIntMsgRequest( NMH_CHANNEL_SYSTEMTYPE_FIRST  tNmhMsgDataType* nmMsgData ) /* PRQA S 3673 */ /* MD_NmhCan_3673b */
{
  vuint8 msgTxRequest;
  vuint8 i;

  /* Transmit the Network Management Message */

  /* Disable the interrupts because in order to avoid that the NM-message is transmitted
     while the data is being copied. */
  CanGlobalInterruptDisable(); /* ESCAN00042522 */
  
  /* Copy network management message data to transmit buffer.. */
  /* Interrupt locks not necessary due to 8 bit data us copied. */
  for (i=0; i<(vuint8)sizeof(tNmhMsgDataType); i++)
  {
    (NmhGetNmMsgDataPtr())[i] = (*nmMsgData)[i];
  }
  
  CanGlobalInterruptRestore(); /* ESCAN00042522 */

  #if defined ( NMH_ENABLE_INDEXED_NM )
  /* Verify the channel. */
  NmhIntAssert( NMH_CHANNEL_SYSTEMPARA_ONLY, (vuint8)( NmhCanToNmChannel( NMH_CHANNEL_SYSTEMPARA_ONLY ) < (NmhChannelHandle)kNmhNumberOfChannels), (vuint8)kNmhIntErrorChannelNotSupport );
  #endif

  /* .. and transmit the message. */
  msgTxRequest = CanTransmit( NmhGetTransmitHandle() );

  return msgTxRequest;
}


  #if defined ( NMH_ENABLE_CAR_WUP )
/*******************************************************************************
** Function:    NmhIntCancelMsgRequest
**
** Purpose:     Request to cancel a network management message 
**              transmission request.
**
**  Called by:  NmhTask
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhIntCancelMsgRequest( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  /* Cancel the last network management transmit request.*/
  (void)CanCancelTransmit( NmhGetTransmitHandle() );  
}
  #endif


/*******************************************************************************
** Function:    NmhIntActiveFailed
**
** Purpose:     Notification that the transmission of a NM-message has timed out,
**              while no network management message has been received.
**
**  Called by:  NmhTask
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhIntActiveFailed( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  #if defined ( NMH_ENABLE_INDEXED_NM ) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* Dummy statement to avoid compiler warnings. */
  if ( NMH_CHANNEL_SYSTEMPARA_ONLY == (vuint8)0u )
  {
  }
  #endif

  #if defined ( NMH_ENABLE_CALLBACK_FCT )
  ApplNmhActiveFailed( NMH_CHANNEL_APPLPARA_ONLY );  /* application callback function */
  #endif
}



/*******************************************************************************
** Function:    NmhIntBusOffStart
**
** Purpose:     Notification about the begin of a BusOff.
**              Start BusOff handling.
**
**  Called by:  NmhBusCriticalFailure
**
**  Parameter:  
**              numberOfBusOff : Number of consecutie BusOffs
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhIntBusOffStart( NMH_CHANNEL_SYSTEMTYPE_FIRST  vuint8 numberOfBusOff )
{
  #if defined ( VGEN_ENABLE_CCL )
  #else
    #if defined ( VGEN_ENABLE_IL_VECTOR )
  /* If the IL is used and running, the IL Tx path has to enter state 'waiting'. */
  /* If the IL is stopped, the IL won't enter state 'waiting' */
  IlTxWait( NMH_CHANNEL_CANPARA_ONLY );
    #endif
  #endif
  
  /* Start BusOff handling. */
  NmhOffline(); /* Clear the transmit queue and switch the transmit path off. */

  CanGlobalInterruptDisable(); /* ESCAN00042522 */
  #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  /* macros must be encapsulated in this way */
  CanResetBusOffStart( NMH_CHANNEL_CANPARA_ONLY,  (CanInitHandle)kNmhCanPara );  /* Start BusOff handling. */
  #else
  CanResetBusOffStart( (CanInitHandle)kNmhCanPara ); /* Start BusOff handling. */
  #endif
  CanGlobalInterruptRestore(); /* ESCAN00042522 */

  /* Because the BusOff handling may endure up to a few ms on some hardware platforms,
     the BusOff handling has to be stopped in a different function.                    */

  #if defined ( NMH_ENABLE_CALLBACK_FCT )
  ApplNmhBusOffStart( NMH_CHANNEL_APPLPARA_FIRST  numberOfBusOff );
  #else
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)numberOfBusOff; /* PRQA S 3112 */ /* MD_NmhCan_3112 */
    #endif
  #endif
}


/*******************************************************************************
** Function:    NmhIntBusOffEnd
**
** Purpose:     Notification about the end of a BusOff.
**              Stop BusOff handling.
**
**  Called by:  NmhTask
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhIntBusOffEnd( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  /* Check whether the network management is preparing for bus-sleep mode. */
  if ( nmhPreparingForSleep[NMH_SYSTEM_CHANNEL_IDX] == (vuint8)FALSE )
  {
    NmhOnline();  /* Switch the transmit path on again. */
  }

  #if defined ( VGEN_ENABLE_CCL )
  #else
    #if defined ( VGEN_ENABLE_IL_VECTOR )
  /* If the IL is used, the IL Tx path has to be released from state 'waiting'. */
  /* If the IL is stopped, the IL won't be started here. */
  IlTxRelease( NMH_CHANNEL_CANPARA_ONLY );
    #endif
  #endif

  #if defined ( NMH_ENABLE_CALLBACK_FCT )
  ApplNmhBusOffEnd( NMH_CHANNEL_APPLPARA_ONLY );
  #endif
}


/*******************************************************************************
** Function:    NmhIntBusOffRxRestore
**
** Purpose:     Notification to restore the message reception during BusOff.
**
**  Called by:  NmhTask
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhIntBusOffRxRestore( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  /* Stop the CAN-Driver BusOff handling. Enables message reception. */
  CanGlobalInterruptDisable(); /* ESCAN00042522 */
  #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  /* macros must be encapsulated in this way */
  CanResetBusOffEnd( NMH_CHANNEL_CANPARA_ONLY,  (CanInitHandle)kNmhCanPara );  /* Start BusOff handling. */
  #else
  CanResetBusOffEnd( (CanInitHandle)kNmhCanPara ); /* Start BusOff handling. */
  #endif
  CanGlobalInterruptRestore(); /* ESCAN00042522 */

  #if defined ( NMH_ENABLE_CALLBACK_FCT )
  ApplNmhBusOffRxRestore( NMH_CHANNEL_APPLPARA_ONLY );
  #endif
}


  #if defined ( NMH_ENABLE_TESTDEBUG )
/*******************************************************************************
** Function:    NmhAssert
**
** Purpose:     In debug mode, this function is called, to verify whether 
**              certain circumstances are proper.
**              Fatal errors are reported to the application.
**
**  Called by:  
**
**  Parameter:  condition : condition that describes a circumstance.
**              errCode   : Error code of this circumstance.
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhIntAssert( NMH_CHANNEL_SYSTEMTYPE_FIRST  vuint8 condition, vuint8 errCode)
{
  if ( condition == (vuint8)FALSE )
  {
    /* Report fatal errors to the application */
    {
      ApplNmhFatalError( NMH_CHANNEL_APPLPARA_FIRST  errCode );
    }
  }
}
  
  #endif  /* defined ( NMH_ENABLE_TESTDEBUG ) */



/*******************************************************************************
** Function:    NmhCanMsgPrecopy
**
** Purpose:     Notifies the NM-High about the reception of a NM-message.
**              The NM-message range has to be configured in the generation tool.
**
**  Called by:  Data link layer
**
**  Parameter:  Handle of CAN-object is either a pointer to the data buffer or
**              a handle to the receive object.
**
**  Returncode: kCanCopyData:   Indicates the copy of data to global data buffer.
**              kNoCanCopyData: Finish the action in the data link layer.
*******************************************************************************/
vuint8 NMH_WRAPPER_API_CALL_TYPE NmhCanMsgPrecopy ( PRECOPY_PARAM_TYPE PRECOPY_PARAM )
{
  /* Check whether the channel is valid. */
  #if defined ( NMH_ENABLE_INDEXED_NM )
  NmhIntAssert( PRECOPY_CHANNEL_PARAM, (vuint8)(NmhCanToNmChannel( PRECOPY_CHANNEL_PARAM ) != kNmhInvalidChannel), (vuint8)kNmhIntInvalidChannel);
  #else
    #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  NmhIntAssert( (vuint8)(MSG_RECEIVED_CHANNEL_IDX == (CanChannelHandle)kNmhCanChannel), (vuint8)kNmhIntInvalidChannel);
    #endif
  #endif

  /* For OEM PAG and OEM VAG the CAN ID 0x6FF is no NM-message and therefore has to be filtered. */
  if ( NMH_GET_RX_ACTUAL_ID != (vuint16)0x6FFu )
  {
    /* Notification that a NM message has been received */
    NmhMsgIndication( PRECOPY_CHANNEL_PARAM );

  #if defined ( NMH_ENABLE_NM_MSG_RX_IND_FCT )
    /* Notification of the application that a NM message has been received 
    (passes the NM message ID and the associated data pointer). */
    #if defined ( NMH_ENABLE_INDEXED_NM )
    ApplNmhCanNmMsgReceived( PRECOPY_CHANNEL_PARAM, NMH_GET_RX_ACTUAL_ID, PRECOPY_PARAM->pChipData );
    #else
    ApplNmhCanNmMsgReceived( NMH_GET_RX_ACTUAL_ID, PRECOPY_PARAM->pChipData );
    #endif
  #endif

  #if defined ( NMH_ENABLE_INDEXED_NM ) || defined ( NMH_ENABLE_NM_MSG_RX_IND_FCT )
  #else
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
    /* avoid compiler warning due to unused parameters */
    (void)PRECOPY_PARAM; /* PRQA S 3112 */ /* MD_NmhCan_3112 */
    #endif 
  #endif
  }

  return kCanCopyData;
}


/*******************************************************************************
** Function:    NmhCanMsgConfirmation
**
** Purpose:     Notifies the NM-High about the successful transmission of a NM-message.
**              The confirmation function has to be configured in the generation tool.
**
**  Called by:  Data link layer
**
**  Parameter:  Handle of the transmitted message.
**
**  Returncode: -
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhCanMsgConfirmation( CanTransmitHandle txObject )
{
  #if defined ( NMH_ENABLE_INDEXED_NM )

  /* Notify the application, that a NM-message has been transmitted successfully. */
  NmhIntAssert( CanTxMsgHandleToChannel[txObject], (vuint8)(NmhCanToNmChannel(CanTxMsgHandleToChannel[txObject]) != kNmhInvalidChannel), (vuint8)kNmhIntInvalidTxObject);
  NmhMsgConfirmation( CanTxMsgHandleToChannel[txObject] );

  #else

  /* Notify the application, that a NM-message has been transmitted successfully. */
  NmhIntAssert( (vuint8)(txObject == NmhGetTransmitHandle()), (vuint8)kNmhIntInvalidTxHandle);
  NmhMsgConfirmation();

    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT ) && !defined ( NMH_ENABLE_TESTDEBUG )
  /* avoid compiler warning due to unused parameters */
  (void)txObject; /* PRQA S 3112 */ /* MD_NmhCan_3112 */
    #endif

  #endif /* defined ( NMH_ENABLE_INDEXED_NM ) */
}


  #if defined ( kNmhCanChannel )
/*******************************************************************************
** Function:    NmhCanBusOff
**
** Purpose:     BusOff notification.
**
**  Called by:  Data link layer
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NmhCanBusOff( CAN_CHANNEL_CANTYPE_ONLY )
{
  if ( channel == kNmhCanChannel )
  {
    NmhBusCriticalFailure();
  }
}

/*******************************************************************************
** Function:    NmhCanWakeUp
**
** Purpose:     WakeUp notification.
**
**  Called by:  Data link layer
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NmhCanWakeUp( CAN_CHANNEL_CANTYPE_ONLY )
{
  if ( channel == kNmhCanChannel )
  {
    NmhWakeUpRequest();
  }
}
  #endif  /* defined ( kNmhCanChannel ) */





  #if defined ( C_ENABLE_CAN_TX_CONF_FCT )

/*******************************************************************************
** Function:    NmhCanMsgConfirmed
**
** Purpose:     Notifies the NM-High about the successful transmission of any CAN message.
**              The 'message receive function' has to be configured in the generation tool.
**
**  Called by:  Data link layer
**
**  Parameter:  Handle of CAN-object is either a pointer to the data buffer or
**              a handle to the transmitted object.
**
**  Returncode: none
*******************************************************************************/
void NMH_WRAPPER_API_CALL_TYPE NmhCanMsgConfirmed( MSG_TRANSMIT_PARAM_TYPE MSG_TRANSMIT_PARAM ) /* PRQA S 3673 */ /* MD_NmhCan_3673a */
{
    #if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && ( !defined ( NMH_ENABLE_INDEXED_NM ) || defined ( NMH_ENABLE_CHANNEL_INDIRECTION ) )

      #if defined ( NMH_ENABLE_INDEXED_NM )
  /* Check wether the NM-High Core runs on the CAN-channel.  */
  if ( NmhCanToNmChannel( MSG_TRANSMIT_CHANNEL_IDX ) != kNmhInvalidChannel )
      #else
  if ( MSG_TRANSMIT_CHANNEL_IDX == (CanChannelHandle)kNmhCanChannel )
      #endif  
  {
    /* Forward message confirmation to NM-High Core. */
    NmhTxObjConfirmed( MSG_TRANSMIT_CHANNEL_PARAM );
  }

    #else

  /* Forward message confirmation to NM-High Core. */
  NmhTxObjConfirmed( MSG_TRANSMIT_CHANNEL_PARAM );
  
    #endif

    #if defined ( NMH_ENABLE_CONF_FCT_CALLBACK )
  /* Call application message confirmation function. */
  ApplNmhCanMsgConfirmed( MSG_TRANSMIT_PARAM );
    #else
      #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* avoid compiler warning due to unused parameters */
  (void)MSG_TRANSMIT_PARAM; /* PRQA S 3112 */ /* MD_NmhCan_3112 */
      #endif
    #endif
}
  #endif  /* defined ( C_ENABLE_CAN_TX_CONF_FCT ) */




/*******************************************************************************
  Consistency checks
*******************************************************************************/


  /* The BusOff algorithm requires either the Tx-Observe mechanism or the Generic Message Confirmation Function. */

  #if defined ( C_ENABLE_CAN_TX_CONF_FCT )
  #else
    #error "NM-High Wrapper error: The Tx Confirmation function has to be enabled if the Tx-Observe mechanism is not used."
  #endif


/* The message confirmation function has to be enabled for OEM PAG. */
#if defined ( C_CLIENT_PAG )
  #if defined ( C_ENABLE_CAN_TX_CONF_FCT ) && defined ( C_CLIENT_PAG )
  #else
    #error "NM-High Wrapper error: The message confirmation function has to be enabled."
  #endif
#endif

#if defined ( NMH_ENABLE_CONF_FCT_CALLBACK )
  #if defined ( C_ENABLE_CAN_TX_CONF_FCT )
  #else
    #error "NM-High Wrapper error: The message confirmation callback function requires the message confirmed function."
  #endif
#endif

/* The message received function has to be enabled for OEM VAG. */

#if defined ( C_CLIENT_PAG )
#else
    #error "NM-High Wrapper error: The message received function has to be enabled."
#endif

#if defined ( NMH_ENABLE_RECEIVE_FCT_CALLBACK )
    #error "NM-High Wrapper error: The message received callback function requires the message received function."
#endif

/* Confirmation functions have to be enabled. */

#if defined ( C_ENABLE_CONFIRMATION_FCT )
#else
  #error "NM-High Wrapper error: The NM-message confirmation function has to be called."
#endif

/* Check consistency of NMH_xxx_CHANNEL_INDIRECTION */

#if defined ( NMH_ENABLE_INDEXED_NM )

  #if defined ( NMH_ENABLE_INDEXED_NM ) && defined ( NMH_DISABLE_INDEXED_NM )
    #error "NM-High consistency error: NMH_xxx_INDEXED_NM must be enabled or disabled."
  #endif
  #if defined ( NMH_ENABLE_CHANNEL_INDIRECTION ) && defined ( NMH_DISABLE_CHANNEL_INDIRECTION )
    #error "NM-High consistency error: NMH_xxx_CHANNEL_INDIRECTION must be either enabled or disabled."
  #endif
  
  #if ( kNmhNumberOfChannels == kCanNumberOfChannels ) 
    #if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
      #error "NM-High consistency error: NMH_xxx_CHANNEL_INDIRECTION not supported in this configuration."
    #endif
  #endif
  
  #if ( kCanNumberOfChannels > kNmhNumberOfChannels )
    #if defined ( NMH_DISABLE_CHANNEL_INDIRECTION )
      #error "NM-High consistency error: NMH_xxx_CHANNEL_INDIRECTION has to be defined in this configuration."
    #endif
  #endif  

#else

  #if defined ( NMH_ENABLE_CHANNEL_INDIRECTION ) 
    #error "NM-High consistency error: NMH_xxx_CHANNEL_INDIRECTION not supported in this configuration."
  #endif
  
#endif /* defined ( NMH_ENABLE_INDEXED_NM ) */

/* Check consistency of kNmhCanChannel */

#if defined ( NMH_ENABLE_INDEXED_NM )
  #if defined ( kNmhCanChannel )
    #error "NM-High consistency error: kNmhCanChannel not supported in this configuration."
  #endif
#else
  #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
    #if defined ( kNmhCanChannel )
      #if ( kNmhCanChannel < kCanNumberOfChannels )
      #else
        #error "NM-High consistency error: kNmhCanChannel out of range."
      #endif
    #else
      #error "NM-High consistency error: kNmhCanChannel has to be defined in this configuration."
    #endif
  #else
    #if defined ( kNmhCanChannel )
      #error "NM-High consistency error: kNmhCanChannel not supported in this configuration."
    #endif
  #endif
#endif

/* Check consistency of kNmhNumberOfChannels */
 
#if ( kNmhNumberOfChannels > kCanNumberOfChannels )
  #error "NM-High consistency error: The number of NM-High channels has to be equal or less the number of CAN channels."
#endif

/* Check consistency of channel configuration */

#if defined ( NMH_ENABLE_INDEXED_NM )
  #if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  #else
    #error "NM-High configuration error: indexed NM-High requires a indexed CAN-Driver!"
  #endif
#endif

/* Check configuration of identities */

#if defined ( NMH_ENABLE_MULTI_ECU )
  #if defined ( V_ACTIVE_IDENTITY_LOG )
  #else
    #error "NM-High configuration error: Active identity has to be defined!"
  #endif
#endif

/* Check configuration depnedencies of CCL */

#if defined ( VGEN_ENABLE_CCL )
  #if defined ( NMH_ENABLE_CALLBACK_FCT )
  #else
    #error "NM-High configuration error: NMH_ENABLE_CALLBACK_FCT has to be enabled if CCL is used!"
  #endif
#endif

  
#endif      /* NM_TYPE_NMHIGH */


/*******************************************************************************
* Organi check
*******************************************************************************/



/* module specific MISRA deviations:
   MD_NmhCan_0883:
     Reason:     Preprocessor code is filtered anyway. No need for multiple-include protection.
     Risk:       Header file is being included multiple times.
     Prevention: Assert correct usage during review.
   MD_NmhCan_3112:
     Reason:     Dummy statement to avoid compiler warnings.
     Risk:       There is no risk as such statements have no effect on the code.
     Prevention: Covered by code review.
   MD_NmhCan_3451a:
     Reason:     nmh_can.h may be included directly without the usage of nmh.h, thus the declaration becomes necessary.
     Risk:       Deviations between the declaration.
     Prevention: Covered by code review.
   MD_NmhCan_3451b:
     Reason:     nmh_can.h may be included directly without the usage of can_par.h, thus the declaration becomes necessary.
     Risk:       Deviations between the declaration.
     Prevention: Covered by code review.
   MD_NmhCan_3673a:
     Reason:     The function prototype is defined by the CAN Driver.
     Risk:       The developer is tempted to change the data where the pointer points to.
     Prevention: Covered by code review.
   MD_NmhCan_3673b:
     Reason:     No usage of const for API parameters.
     Risk:       The developer is tempted to change the data where the pointer points to.
     Prevention: Covered by code review.
*/

/*****   STOPSINGLE_OF_MULTIPLE_COMMENT    ******/

/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
