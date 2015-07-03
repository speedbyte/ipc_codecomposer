
#ifndef _IPC_C1_H
#define _IPC_C1_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include "Common.h"
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "IPC_CI.h"
/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/
typedef enum
{
  enIpcStateIdle,
    enIpcStateStartOfTransmission,
    enIpcStateCreatePayload,
    enIpcStateEndofTransmisson,
    enIpcStateCheckProtocol,
    enIpcStateSendStatusChannelResponse,
    enIpcStateSendStatusNegativeResponse,
    enIpcStateAnalyseResponse,
    enIpcStateAnalyseCommand,
    enIpcStateTriggerEvent
} ENUM_IPC_STATE;
/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/
typedef struct _IPC_ST_BUFFERPROPERTIES
{
    Uint16Type  sizeofRxBuffer;
    Uint16Type  sizeofTxBuffer;
    Uint8Type   *txRingBuffer;
    Uint8Type   txStatus;
    Uint16Type  txGetCount;
    Uint16Type  txPutCount;
    Uint8Type   *txPutPtr;
    Uint8Type   BufferoverflowCount;

    Uint8Type   *txGetPtr;
    Uint8Type   *rxRingBuffer;
    Uint8Type   rxStatus;
    Uint16Type  rxGetCount;
    Uint16Type  rxPutCount;
    Uint8Type   *rxPutPtr;
    Uint8Type   *rxGetPtr;

    Uint8Type   bInitDone;

    Uint8Type   u8HeartBeatCount;
    BooleanType bIncomingCommunication;
    BooleanType bOutgoingCommunication;
    BooleanType bWriteResponseBlockBusy;

    BooleanType bHeartbeatmessage;

    void (*funcPtr)(Uint8Type *, Uint8Type);

    Uint8Type   au8LastByteStream[IPC_MAX_SIZE_OF_TX_BUFFER];
    Uint8Type   u8LastByteStreamCount;

    Uint8Type   txResponseBuffer[IPC_MAX_SIZE_OF_TX_RESPONSE_BUFFER];
    Uint8Type   txResponseBufferCount;
} IPC_ST_BUFFERPROPERTIES, *IPC_PST_BUFFERPROPERTIES;

/*----------------------------------------------------------------------------*/
/* Global const Declarations                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Module Global Methods                                                      */
/*----------------------------------------------------------------------------*/



#endif /* _IPC_C1_H */

/* End Of File IPC_C1.h */



