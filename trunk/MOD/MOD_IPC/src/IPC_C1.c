/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include <string.h>

#indef OSEK_SUPPORTED_OS
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>   /* Posix 1003.1c threads */
#define MODEM_DEVICE "/dev/ttyS1"
#endif
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "Common.h"
#include "IPC.h"
#include "IPC_C1.h"
#ifdef OSEK_SUPPORTED_OS
#ifndef SINGLE_BYTE_TRANSMISSION
#include "UART.h"
#ifdef DEBUG_MESSAGES_IPC
#include "DEBUG.h"
#endif
#endif
#else
#include <unistd.h>
#endif
#ifdef TRACE_MESSAGES_IPC
#include "TRACE.h"
#include "IPC_C1.id"
#endif
#ifdef PRINT_MESSAGES_IPC
#include <stdio.h>
#endif
#ifdef SINGLE_BYTE_TRANSMISSION
#include "ADR_SciHandler_CI.h"
#include "ADR_OperatingSystem_CI.h"
#endif
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/
#if defined( WATCHDOG_PRINZIP_IPC)
static const Uint8Type _IPC_au8WatchDog[1] =         {0x22};
#endif
#if defined(RESET_REMOTE_CHANNEL_IPC)
static const Uint8Type _IPC_au8ResetChannel[1] =     {0xFF};
#endif
static const Uint8Type _IPC_au8NegativeResponse[1] = {0x7F};
#if defined( HEARTBEAT_PRINZIP_IPC)
static const Uint8Type _IPC_au8HeartBeatStatus[1] =  {0x78};
#endif
#if defined( RESEND_LAST_STREAM)
static const Uint8Type _IPC_au8ResendLastStream[1] =  {0x33};
#endif
static const Uint8Type _IPC_au8ImmediateResponseRequested[1] =  {0x77};

static Uint8Type au8ProtocolArrayHeaderRequest[3] = {DLE, 0xFF, 0xFF };
static Uint8Type au8ProtocolArrayFooterRequest[2] = {0xFF, 0xFF };
static Uint8Type au8ProtocolArrayHeaderResponse[3] = {DLE, 0xFF, 0xFF };
static Uint8Type au8ProtocolArrayFooterResponse[2] = {0xFF, 0xFF };

static Uint8Type _IPC_bMonitorProtocolByte = 0;
static Uint8Type _IPC_u8LastChannelSend = 0xFF;
/*#define DEBUG_COMMAND(x)
#define COMMAND(NAME)  { #NAME, DEBUG_## NAME, DEBUG_PARAMETER_## NAME }

typedef struct command
{
    char *module_name;
    Uint8Type module_value;
    Uint8Type module_property;
} DEBUG_ST_DEBUG_MODULES;
#ifdef DEBUG_MESSAGES_IPC
#define TRACE_COMMAND(x,y,z)               (void)DEBUG_Printf(DEBUG_## x, DEBUG_## y, z );
)
#endif
#ifdef TRACE_MESSAGES_IPC

#endif
#ifdef PRINT_MESSAGES_IPC
#endif


#ifdef DEBUG_MESSAGES_IPC
                    TRACE_COMMAND(TRACE, IPC, "%d Payload bytes received", _IPC_u8NumberofBytes);
*/
/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/
/** 
	\brief	Buffer Properties for IPC1
*/
/**
    \brief  Buffer Properties for IPC1 03
*/
static IPC_ST_BUFFERPROPERTIES _IPC_stBufferProperties[enIpcMaxChannel];

#define USE_IPC_CHANNEL_0

#ifdef USE_IPC_CHANNEL_0
static Uint8Type Tx_Buffer_for_IPC0[IPC0_SIZEOF_TX_RING_BUFFER];
static Uint8Type Rx_Buffer_for_IPC0[IPC0_SIZEOF_RX_RING_BUFFER];
#endif
#ifdef USE_IPC_CHANNEL_1
static Uint8Type Tx_Buffer_for_IPC1[IPC1_SIZEOF_TX_RING_BUFFER];
static Uint8Type Rx_Buffer_for_IPC1[IPC1_SIZEOF_RX_RING_BUFFER];
#endif
#ifdef USE_IPC_CHANNEL_2
static Uint8Type Tx_Buffer_for_IPC2[IPC2_SIZEOF_TX_RING_BUFFER];
static Uint8Type Rx_Buffer_for_IPC2[IPC2_SIZEOF_RX_RING_BUFFER];
#endif
#ifdef USE_IPC_CHANNEL_3
static Uint8Type Tx_Buffer_for_IPC3[IPC3_SIZEOF_TX_RING_BUFFER];
static Uint8Type Rx_Buffer_for_IPC3[IPC3_SIZEOF_RX_RING_BUFFER];
#endif


/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/
static SuccessFailType IPC_sfInitialiseBuffer(IPC_ENUM_CHANNEL channel, SCIFUNCTIONS u8Location);
static void _IPC_cbInternalHandling(Uint8Type *block, Uint8Type length);
/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                     */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the macros
*/
/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the private variable
*/
static Uint8Type _IPC_au8ByteArrayFromUart[2] = {0xFF, 0xFF};
static Uint8Type _IPC_u8CountFromByteArray = 0;
static ENUM_IPC_STATE _IPC_enIpcState = enIpcStateIdle;
static BooleanType _IPC_bReceiveCommandUnderProcess = BT_FALSE;
static Uint16Type _IPC_u16CountDownTimer = COUNT_DOWN_TIMER;
static Uint8Type _IPC_u8CalculatedChecksum=0;
static Uint8Type _IPC_u8CalculatedChecksumOutgoing=0;
#if defined( WATCHDOG_PRINZIP_IPC)
static Uint8Type _IPC_u8WatchDogCount = IPC_MAX_WATCHDOG_COUNT;
#endif
static Uint8Type _IPC_u8ProtocolByte = 0xFF;
static Uint8Type _IPC_u8NegativeResponseErrorRetryCount = 0;
/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/

static void _IPC_cbInternalHandling(Uint8Type *block, Uint8Type length)
{
    ;   
}

static SuccessFailType _IPC_sfTxPutByteResend(IPC_ENUM_CHANNEL channel, Uint8Type dasByte);
static SuccessFailType _IPC_sfTxPutByteResponse(IPC_ENUM_CHANNEL channel, Uint8Type dasByte, BooleanType bChecksumCalc);
static void _IPC_vCommonResendRoutine(IPC_ENUM_CHANNEL channel);

/*----------------------------------------------------------------------------*/
/* Function    : UART_sfInit                                         */
/**
    \brief      Initialise the IPC

    \brief      Description:
                Initialise the IPC to a correct state.

    \param      pstUart
                SCI_ST
                IPC1 / IPC2
    \return     SuccessFailType
                If the function was successful or failed
                SUCCESS, FAIL
*/
/*----------------------------------------------------------------------------*/
SuccessFailType IPC_sfInit(IPC_ENUM_CHANNEL channel)
{
    _IPC_stBufferProperties[channel].bInitDone = (Uint8Type)BT_FALSE;
    _IPC_stBufferProperties[channel].bWriteResponseBlockBusy = BT_FALSE;
    /*----------------------------------------------------------------------*/
    /* Initialize the ring buffers                                          */
    /*----------------------------------------------------------------------*/
    (void)IPC_sfInitialiseBuffer(channel, SciReceive);
    (void)IPC_sfInitialiseBuffer(channel, SciTransmit);

    return(SUCCESS);
}

/*----------------------------------------------------------------------------*/
/* Function    : IPC_sfInitialiseBuffer                                         */
/**
    \brief      Reinitialise or Initialise the buffer.

    \brief      Description:
                Resets the Buffer Properties with value = 0

    \param      pstUart
                SCI_ST
                IPC1 / IPC2
    \param      u8Location
                SCIFUNCTIONS
                SciClock,SciReceive,SciTransmit,SciError
    \return     SuccessFailType
                If the function was successful or failed
                SUCCESS, FAIL
*/
/*----------------------------------------------------------------------------*/
static SuccessFailType IPC_sfInitialiseBuffer(IPC_ENUM_CHANNEL channel, SCIFUNCTIONS u8Location)
{
    Uint32Type i = 0U;
    if ( u8Location == SciReceive )
    {
#ifdef USE_IPC_CHANNEL_0
        if ( channel == IPC_CHANNEL_0 )
        {
            _IPC_stBufferProperties[channel].sizeofRxBuffer = IPC0_SIZEOF_RX_RING_BUFFER;
            _IPC_stBufferProperties[channel].rxRingBuffer = Rx_Buffer_for_IPC0;
        }
#endif
#ifdef USE_IPC_CHANNEL_1
        else if ( channel == IPC_CHANNEL_1)
        {
            _IPC_stBufferProperties[channel].sizeofRxBuffer = IPC1_SIZEOF_RX_RING_BUFFER;
            _IPC_stBufferProperties[channel].rxRingBuffer = Rx_Buffer_for_IPC1;
        }
#endif
#ifdef USE_IPC_CHANNEL_2
        else if ( channel == IPC_CHANNEL_2 )
        {
            _IPC_stBufferProperties[channel].sizeofRxBuffer = IPC2_SIZEOF_RX_RING_BUFFER;
            _IPC_stBufferProperties[channel].rxRingBuffer = Rx_Buffer_for_IPC2;
        }
#endif
#ifdef USE_IPC_CHANNEL_3
        else if ( channel == IPC_CHANNEL_3)
        {
            _IPC_stBufferProperties[channel].sizeofRxBuffer = IPC3_SIZEOF_RX_RING_BUFFER;
            _IPC_stBufferProperties[channel].rxRingBuffer = Rx_Buffer_for_IPC3;
        }
#endif
        _IPC_stBufferProperties[channel].rxStatus = 0U;
        _IPC_stBufferProperties[channel].rxGetCount = 0U;
        _IPC_stBufferProperties[channel].rxPutCount = 0U;
        _IPC_stBufferProperties[channel].rxPutPtr = &(_IPC_stBufferProperties[channel].rxRingBuffer)[0];
        _IPC_stBufferProperties[channel].rxGetPtr = &(_IPC_stBufferProperties[channel].rxRingBuffer)[0];
        for ( i = 0; i < (_IPC_stBufferProperties[channel].sizeofRxBuffer); i++)
            _IPC_stBufferProperties[channel].rxRingBuffer[i] = 0;
    }
    else if ( u8Location == SciTransmit )
    {
#ifdef USE_IPC_CHANNEL_0
        if ( channel == IPC_CHANNEL_0 )
        {
            _IPC_stBufferProperties[channel].sizeofTxBuffer = IPC0_SIZEOF_TX_RING_BUFFER;
            _IPC_stBufferProperties[channel].txRingBuffer = Tx_Buffer_for_IPC0;
        }
#endif
#ifdef USE_IPC_CHANNEL_1
        else if ( channel == IPC_CHANNEL_1)
        {
            _IPC_stBufferProperties[channel].sizeofTxBuffer = IPC1_SIZEOF_TX_RING_BUFFER;
            _IPC_stBufferProperties[channel].txRingBuffer = Tx_Buffer_for_IPC1;
        }
#endif
#ifdef USE_IPC_CHANNEL_2
        else if ( channel == IPC_CHANNEL_2 )
        {
            _IPC_stBufferProperties[channel].sizeofTxBuffer = IPC2_SIZEOF_TX_RING_BUFFER;
            _IPC_stBufferProperties[channel].txRingBuffer = Tx_Buffer_for_IPC2;
        }
#endif
#ifdef USE_IPC_CHANNEL_3
        else if ( channel == IPC_CHANNEL_3 )
        {
            _IPC_stBufferProperties[channel].sizeofTxBuffer = IPC3_SIZEOF_TX_RING_BUFFER;
            _IPC_stBufferProperties[channel].txRingBuffer = Tx_Buffer_for_IPC3;
        }
#endif
        _IPC_stBufferProperties[channel].txStatus = 0U;
        _IPC_stBufferProperties[channel].txPutCount = 0U;
        _IPC_stBufferProperties[channel].txGetCount = 0U;
        _IPC_stBufferProperties[channel].txPutPtr = &(_IPC_stBufferProperties[channel].txRingBuffer)[0];
        _IPC_stBufferProperties[channel].txGetPtr = &(_IPC_stBufferProperties[channel].txRingBuffer)[0];
        _IPC_stBufferProperties[channel].BufferoverflowCount = 0;
        for ( i = 0; i < (_IPC_stBufferProperties[channel].sizeofTxBuffer); i++)
        {
            _IPC_stBufferProperties[channel].txRingBuffer[i] = 0;
        }
    }
    _IPC_stBufferProperties[channel].bIncomingCommunication = BT_FALSE;
    _IPC_stBufferProperties[channel].bOutgoingCommunication = BT_FALSE;
    _IPC_stBufferProperties[channel].u8HeartBeatCount = IPC_MAX_HEARTBEAT_COUNT;

    memset ( _IPC_stBufferProperties[channel].au8LastByteStream, 0xFF , IPC_MAX_SIZE_OF_TX_BUFFER);
    _IPC_stBufferProperties[channel].u8LastByteStreamCount = 0;

    memset ( _IPC_stBufferProperties[channel].txResponseBuffer, 0xFF , IPC_MAX_SIZE_OF_TX_RESPONSE_BUFFER);
    _IPC_stBufferProperties[channel].txResponseBufferCount = 0;

    _IPC_stBufferProperties[channel].bHeartbeatmessage = BT_FALSE;

    _IPC_stBufferProperties[channel].bInitDone = (Uint8Type)BT_TRUE;
    return SUCCESS;
}
#ifdef OSEK_SUPPORTED_OS
void IPC_vProcessCommands(void)
#endif
#ifndef OSEK_SUPPORTED_OS
void IPC_vProcessCommands(int fd, int getCount)
#endif
{
    static Uint8Type _IPC_u8NumberofBytes = 0;
#ifdef SINGLE_BYTE_TRANSMISSION
    Uint8Type rxByte = 0;
    Uint8Type count = 0;
    Uint8Type *txGetTempPtr;
#endif
#ifdef OSEK_SUPPORTED_OS
#ifndef SINGLE_BYTE_TRANSMISSION
    if (IPC_GET_RX_COUNT_FROM_BUS)
#endif
#ifdef SINGLE_BYTE_TRANSMISSION
    if(ADR_SCI_receiveByte(&rxByte) == SCI_BUS_RX_DATA)
#endif
#endif
#ifndef OSEK_SUPPORTED_OS
    if (0 < getCount )
#endif
    {
#ifdef OSEK_SUPPORTED_OS
#ifndef SINGLE_BYTE_TRANSMISSION
    	_IPC_au8ByteArrayFromUart[_IPC_u8CountFromByteArray] = UART_u8ReadByte(UART_IPC);
#endif
#ifdef SINGLE_BYTE_TRANSMISSION
        _IPC_au8ByteArrayFromUart[_IPC_u8CountFromByteArray] = rxByte;
#endif
#endif
#ifndef OSEK_SUPPORTED_OS
        read(fd, &_IPC_au8ByteArrayFromUart[_IPC_u8CountFromByteArray], 1);
        // ds
	    printf("RX: 0x%02X\n", _IPC_au8ByteArrayFromUart[_IPC_u8CountFromByteArray]);
#endif
        _IPC_u16CountDownTimer = COUNT_DOWN_TIMER;
        if ( _IPC_au8ByteArrayFromUart[_IPC_u8CountFromByteArray] == DLE )
        {
            // RESYNC
            _IPC_bReceiveCommandUnderProcess = BT_TRUE;
            _IPC_au8ByteArrayFromUart[0] = DLE;
            _IPC_enIpcState = enIpcStateIdle;
        }
        _IPC_u8CountFromByteArray++;
    }
    else if ( _IPC_bReceiveCommandUnderProcess == BT_TRUE )
    {
        _IPC_u16CountDownTimer--;
        if ( _IPC_u16CountDownTimer == 0x0 )
        {
#ifdef TRACE_MESSAGES_IPC
		        DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Reception time out");
#endif
#ifdef PRINT_MESSAGES_IPC
                printf("IPC_vProcessCommands: Reception time out\n");
#endif
            _IPC_enIpcState = enIpcStateIdle;
            _IPC_u8CountFromByteArray = 0;
            _IPC_bReceiveCommandUnderProcess = BT_FALSE;
            IPC_sfInit((IPC_ENUM_CHANNEL)_IPC_u8ProtocolByte);
            //IPC_u16WriteBlock((IPC_ENUM_CHANNEL)0xFF, (const Uint8Type *)_IPC_au8ResendLastStream, 0x01, _IPC_cbInternalHandling);
        }
    }
    else
    {
    	; /* do nothing */
    }
    switch(_IPC_enIpcState)
    {
        case enIpcStateIdle:
        {
            if (  _IPC_au8ByteArrayFromUart[0] == DLE &&
                  (_IPC_u8CountFromByteArray == 0x02))
            {
#ifdef TRACE_MESSAGES_IPC
		        DEBUG_VALUE1(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Start of Reception at channel %d", _IPC_au8ByteArrayFromUart[1]&0x0F);
#endif
#ifdef PRINT_MESSAGES_IPC
                printf("IPC_vProcessCommands: Start of Reception at channel %d\n", _IPC_au8ByteArrayFromUart[1]&0x0F);
#endif
                _IPC_enIpcState = enIpcStateStartOfTransmission;
                _IPC_u8CountFromByteArray = 0;
                _IPC_u8CalculatedChecksum = (DLE ^ 0x12 );
                _IPC_u8CalculatedChecksum = (_IPC_u8CalculatedChecksum + _IPC_au8ByteArrayFromUart[1])^0x12;
                _IPC_u8ProtocolByte = _IPC_au8ByteArrayFromUart[1];
                _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxPutCount = 0;
            }
            else if ( _IPC_u8CountFromByteArray > 0x02)
            {
                _IPC_u8CountFromByteArray = 0;
            }

            break;
        }
        case enIpcStateStartOfTransmission:
        {
            if ( _IPC_u16CountDownTimer == COUNT_DOWN_TIMER)
            {
                _IPC_u8NumberofBytes = _IPC_au8ByteArrayFromUart[0];
                if ( _IPC_u8NumberofBytes == 0x0 )
                {
#ifdef TRACE_MESSAGES_IPC
		            DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Invalid Number of Bytes");
#endif
#ifdef PRINT_MESSAGES_IPC
		            printf("IPC_vProcessCommands: Invalid Number of Bytes\n");
#endif
                    _IPC_u8CountFromByteArray = 0;
                    _IPC_enIpcState = enIpcStateSendStatusNegativeResponse;
                }
                else
                {
                    _IPC_u8CalculatedChecksum = (_IPC_u8CalculatedChecksum + _IPC_u8NumberofBytes )^0x12;
                    _IPC_u8CountFromByteArray = 0;
                    _IPC_enIpcState = enIpcStateCreatePayload;
                }
            }
            break;
        }
        case enIpcStateCreatePayload:
        {
#ifdef PRINT_MESSAGES_IPC
            Uint8Type x = 0;
#endif
            if ( _IPC_u16CountDownTimer == COUNT_DOWN_TIMER)
            {
                _IPC_u8CountFromByteArray = 0;
                _IPC_u8CalculatedChecksum = (_IPC_u8CalculatedChecksum +  _IPC_au8ByteArrayFromUart[0])^0x12;
                if ( _IPC_bMonitorProtocolByte == 0x01 )
                {
                    if ( _IPC_au8ByteArrayFromUart[0] == 0x3D )
                    {
                        _IPC_bMonitorProtocolByte = 0x02;
                        _IPC_u8NumberofBytes--;
                        _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxPutCount++] =  0x7D;
                    }
                    else if ( _IPC_au8ByteArrayFromUart[0] == 0x3E )
                    {
                        _IPC_bMonitorProtocolByte = 0x02;
                        _IPC_u8NumberofBytes--;
                        _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxPutCount++] =  0x7E;
                    }
                    else
                    {
                        _IPC_bMonitorProtocolByte = 0x03;
                        _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxPutCount++] =  0x7D;
                    }
                }
                else if (_IPC_bMonitorProtocolByte == 0x02)
                {
                	_IPC_bMonitorProtocolByte = 0x03;
                }
                if ( _IPC_au8ByteArrayFromUart[0] == 0x7D )
                {
                    _IPC_bMonitorProtocolByte = 0x01;
                }
                else if ( _IPC_bMonitorProtocolByte == 0x03)
                {
                    _IPC_bMonitorProtocolByte = 0x00;
                    _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxPutCount++] =  _IPC_au8ByteArrayFromUart[0];
                }
                else if ( _IPC_bMonitorProtocolByte == 0x00)
                {
                    _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxPutCount++] =  _IPC_au8ByteArrayFromUart[0];
                }
                if (_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxPutCount == (_IPC_u8NumberofBytes))
                {
#ifdef TRACE_MESSAGES_IPC
		            DEBUG_VALUE1(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: %d Payload bytes received", _IPC_u8NumberofBytes);
#endif
#ifdef PRINT_MESSAGES_IPC
//		            printf("IPC_vProcessCommands: %d Payload bytes received\n", _IPC_u8NumberofBytes);
//		            for ( x = 0; x < _IPC_u8NumberofBytes; x++)
//		            {
//		            	printf("IPC_vProcessCommands: RX %02X\n", _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[x]);
//		            }
#endif
                    _IPC_enIpcState = enIpcStateCheckProtocol;
                }
            }
            break;
        }
        case enIpcStateCheckProtocol:
        {
            if ( _IPC_u16CountDownTimer == COUNT_DOWN_TIMER)
            {
                _IPC_u8CountFromByteArray = 0;
                _IPC_bReceiveCommandUnderProcess = BT_FALSE;
#if defined(CHECKSUM_PRINZIP_IPC)
#ifdef TRACE_MESSAGES_IPC
		            DEBUG_VALUE2(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Calculated CS=%02X Received CS=%02X, ",_IPC_u8CalculatedChecksum, _IPC_au8ByteArrayFromUart[0]);
#endif
#ifdef PRINT_MESSAGES_IPC
                    printf("IPC_vProcessCommands: Calculated CS=%02X Received CS=%02X, \n",_IPC_u8CalculatedChecksum, _IPC_au8ByteArrayFromUart[0]);
#endif
                if (  (_IPC_au8ByteArrayFromUart[0] != 0xFF) && (_IPC_au8ByteArrayFromUart[0] != _IPC_u8CalculatedChecksum))
                {
                    _IPC_enIpcState = enIpcStateSendStatusNegativeResponse;
                    break;
                }
                else
                {
                       ;
                }
#endif
                /* Checksum is ok, now take care of the incoming byte stream. */
                /* 1 st case is when it is not any command. i.e the protocol byte is 0x10. */
                if ( (_IPC_u8ProtocolByte & (Uint8Type)0xF0) == (Uint8Type)0x10 )
                {
                    if  (((_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[0] == _IPC_au8NegativeResponse[0])))
                    {
                        _IPC_enIpcState = enIpcStateIdle;
                        _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].bOutgoingCommunication = BT_FALSE;
                        //_IPC_vCommonResendRoutine((IPC_ENUM_CHANNEL)(_IPC_u8ProtocolByte & 0x0F));
                    }
                    else if  (((_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[0] == ((_IPC_u8ProtocolByte & 0x0F) + 0x40 + (_IPC_u8ProtocolByte & 0x0F)*16))))
                    {
                        /* Postive response */
                        /* Callback application with Channel response and payload. */
                        _IPC_enIpcState = enIpcStateIdle;
            #ifdef TRACE_MESSAGES_IPC
                        DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Analyse Response");
            #endif
            #ifdef PRINT_MESSAGES_IPC
                        printf("IPC_vProcessCommands: Analyse Response\n");
            #endif
                        if ( _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].bOutgoingCommunication == BT_TRUE  )
                        {
                             /*  Inform Application */
                            if(NULL != _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].funcPtr)
                            {
                                _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].funcPtr((_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer+1), _IPC_u8NumberofBytes-1);
                            }
                        }
                        else
                        {
            #ifdef TRACE_MESSAGES_IPC
                            DEBUG_VALUE1(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: No active communication on channel = %d",_IPC_u8ProtocolByte&0x0F);
            #endif
            #ifdef PRINT_MESSAGES_IPC
                            printf("IPC_vProcessCommands: No active communication on channel = %d\n",_IPC_u8ProtocolByte&0x0F);
            #endif
                        }
                        _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].bOutgoingCommunication = BT_FALSE;

                    }
#if defined( HEARTBEAT_PRINZIP_IPC)
                    else if  (((_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[0] == _IPC_au8HeartBeatStatus[0])))
                    {
                        _IPC_enIpcState = enIpcStateIdle;
#ifdef TRACE_MESSAGES_IPC
		                DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Heartbeat");
#endif
#ifdef PRINT_MESSAGES_IPC
                        printf("IPC_vProcessCommands: Heartbeat\n");
#endif
                        _IPC_stBufferProperties[_IPC_u8ProtocolByte & 0x0F].u8HeartBeatCount = IPC_MAX_HEARTBEAT_COUNT;
                        /* This is a heartbeat and no ACK should be send. */
                    }
#endif
#if defined( WATCHDOG_PRINZIP_IPC)
                    else if  (((_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[0] == _IPC_au8WatchDog[0])))
                    {
                        _IPC_enIpcState = enIpcStateIdle;
#ifdef TRACE_MESSAGES_IPC
                        DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Recvd Watchdog");
#endif
#ifdef PRINT_MESSAGES_IPC
                        printf("IPC_vProcessCommands: Recvd Watchdog\n");
#endif
                        _IPC_u8WatchDogCount = IPC_MAX_WATCHDOG_COUNT;
                    }
#endif
                    else if  (((_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[0] == 0xFF)))
                    {
                        Uint8Type u8TempChannelResponse[1] = {0xFF};
                        _IPC_enIpcState = enIpcStateIdle;
#if defined(RESET_REMOTE_CHANNEL_IPC)
    #ifdef TRACE_MESSAGES_IPC
    		                DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Reset Channel");
    #endif
    #ifdef PRINT_MESSAGES_IPC
                            printf("IPC_vProcessCommands: Reset Channel\n");
    #endif
                        /* Do not wait for the application response, send the Channel response immediately. */
                        /* Message to APL without Response and with Payload */
                        u8TempChannelResponse[0] = (_IPC_u8ProtocolByte & 0x0F) + 0x40 + (_IPC_u8ProtocolByte & 0x0F)*16;
#ifdef TRACE_MESSAGES_IPC
                        DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Send Reset Response");
#endif
#ifdef PRINT_MESSAGES_IPC
                        printf("IPC_vProcessCommands: Send Reset Response\n");
#endif
                        IPC_u16WriteResponseBlock((IPC_ENUM_CHANNEL)(_IPC_u8ProtocolByte&0x0F), (const Uint8Type *)u8TempChannelResponse, 0x01, _IPC_cbInternalHandling);
    #endif
                    }

                    else
                    {
                        _IPC_enIpcState = enIpcStateIdle;
#ifdef TRACE_MESSAGES_IPC
		                DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Undefined message");
#endif
#ifdef PRINT_MESSAGES_IPC
                        printf("IPC_vProcessCommands: Undefined message\n");
#endif
                    }                            
                }
                /* 2nd case is when the channel should be resetted. */
                else if  (((_IPC_u8ProtocolByte & 0xF0) == 0xF0 ) )
                {
                    /*TODO:  Reset channel. */
                    _IPC_enIpcState = enIpcStateIdle;    /*  3rd STEP */
#ifdef TRACE_MESSAGES_IPC
		                DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Reset Channel");
#endif
#ifdef PRINT_MESSAGES_IPC
                        printf("IPC_vProcessCommands: Reset Channel\n");
#endif

#if defined(RESET_REMOTE_CHANNEL_IPC)
                    IPC_sfInitialiseBuffer((IPC_ENUM_CHANNEL)(_IPC_u8ProtocolByte&0x0F), SciReceive);
#endif
                }
                else
                {
#ifdef TRACE_MESSAGES_IPC
                    DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: A proper Command");
#endif
#ifdef PRINT_MESSAGES_IPC
                    printf("IPC_vProcessCommands: A proper Command\n");
#endif
                    _IPC_enIpcState = enIpcStateAnalyseCommand;
                    _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].bIncomingCommunication = BT_TRUE;
                }
            }
            break;
        }
    }
    switch (_IPC_enIpcState)
    {
        case enIpcStateSendStatusNegativeResponse:
        {
            _IPC_u8CountFromByteArray = 0;
            _IPC_enIpcState = enIpcStateIdle;
#ifdef TRACE_MESSAGES_IPC
            DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Send negative. Response");
#endif
#ifdef PRINT_MESSAGES_IPC
            printf("IPC_vProcessCommands: Send negative. Response\n");
#endif
            IPC_u16WriteResponseBlock((IPC_ENUM_CHANNEL)(_IPC_u8ProtocolByte&0x0F), (const Uint8Type *)_IPC_au8NegativeResponse, 0x01, _IPC_cbInternalHandling);
            break;
        }
        case enIpcStateAnalyseCommand:
        {
            _IPC_u8CountFromByteArray = 0;
            _IPC_u16CountDownTimer = COUNT_DOWN_TIMER;
            _IPC_enIpcState = enIpcStateIdle;
            /*  Callback application with Channel response and payload. */
#ifdef TRACE_MESSAGES_IPC
            DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Analyse Command");
#endif
#ifdef PRINT_MESSAGES_IPC
            printf("IPC_vProcessCommands: Analyse Command\n");
#endif
            if ( _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[0] == 0x77 )
            {
                Uint8Type u8TempChannelResponse[1] = {0xFF};
                /* Do not wait for the application response, send the Channel response immediately. */
                /* Message to APL without Response and with Payload */
                u8TempChannelResponse[0] = (_IPC_u8ProtocolByte & 0x0F) + 0x40 + (_IPC_u8ProtocolByte & 0x0F)*16;
#ifdef TRACE_MESSAGES_IPC
                DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Send channel Response Immediate");
#endif
#ifdef PRINT_MESSAGES_IPC
                printf("IPC_vProcessCommands: Send channel Response Immediate\n");
#endif
                IPC_u16WriteResponseBlock((IPC_ENUM_CHANNEL)(_IPC_u8ProtocolByte&0x0F), (const Uint8Type *)u8TempChannelResponse, 0x01, _IPC_cbInternalHandling);
            }
            else
            {
#ifdef TRACE_MESSAGES_IPC
                DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: incoming Communication Active, Heartbeat started");
#endif
#ifdef PRINT_MESSAGES_IPC
                printf("IPC_vProcessCommands: incoming Communication Active, Heartbeat started\n");
#endif
            }
#ifdef TRACE_MESSAGES_IPC
            DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Trigger event");
#endif
#ifdef PRINT_MESSAGES_IPC
            printf("IPC_vProcessCommands: Trigger event\n");
#endif
            if  (((_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[0] == _IPC_au8ResendLastStream[0])
                    && _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxPutCount == 0x01 )) /* Resend last command */
            {
                _IPC_enIpcState = enIpcStateIdle;
#ifdef TRACE_MESSAGES_IPC
                DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: A Resend Command is sent");
#endif
#ifdef PRINT_MESSAGES_IPC
                printf("IPC_vProcessCommands: A Resend Command is sent\n");
#endif
                _IPC_vCommonResendRoutine((IPC_ENUM_CHANNEL)_IPC_u8LastChannelSend);
            }
            else
            {
#ifdef TRACE_MESSAGES_IPC
                DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Copy message in Appl Buffer");
#endif
#ifdef PRINT_MESSAGES_IPC
                printf("IPC_vProcessCommands: Copy message in Appl Buffer\n");
#endif
            	// _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[0] --> Pointer auf die empfangenen Daten
            	// _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxPutCount 	 --> enth?lt die L?nge der empfangenen Daten --> max: 255 Byte Nutzdaten
                /*  Command to application */
				ADR_TriggerCommandFromIpc(&_IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxRingBuffer[0], _IPC_stBufferProperties[_IPC_u8ProtocolByte&0x0F].rxPutCount);
            }
            break;
        }
        default:
        {
            break;
        }
    }
}
#ifndef OSEK_SUPPORTED_OS
void IPC_vMonitorCommunication(int fd)
#else
void IPC_vMonitorCommunication(void)
#endif
{
    /* this function sets the watch dog bit, heart beat bit, monitors watch dog bit and monitors heartbeats. */
    /* Outgoing watch dog and heart beat */
#if defined( HEARTBEAT_PRINZIP_IPC)
    Uint8Type i = 0;
#endif
#if defined( WATCHDOG_PRINZIP_IPC)
    IPC_u16WriteBlock(IPC_CHANNEL_WATCHDOG, (const Uint8Type *)_IPC_au8WatchDog, sizeof(_IPC_au8WatchDog), _IPC_cbInternalHandling);
    /* Monitor watch dog from the other side. */
    _IPC_u8WatchDogCount--;
    if ( _IPC_u8WatchDogCount == 0x0 )
    {
        _IPC_u8WatchDogCount = IPC_MAX_WATCHDOG_COUNT;
#ifdef TRACE_MESSAGES_IPC
        DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vMonitorCommunication: No watch dog for 5 seconds, trigger reset");
#endif
#ifdef PRINT_MESSAGES_IPC
        printf("IPC_vMonitorCommunication: No watch dog for 5 seconds, trigger reset\n");
#endif
    }
#endif
#if defined( HEARTBEAT_PRINZIP_IPC)
    for ( i = 0; i < enIpcMaxChannel; i++)
    {
        if (( _IPC_stBufferProperties[i].bIncomingCommunication == BT_TRUE ) )
        {
            IPC_u16WriteResponseBlock((IPC_ENUM_CHANNEL)i, (const Uint8Type *)_IPC_au8HeartBeatStatus, 0x01, _IPC_cbInternalHandling);
        }
    }
    /* Monitor heartbeat from the other side. */
    for ( i = 0; i < enIpcMaxChannel; i++)
    {
        if ( _IPC_stBufferProperties[i].bOutgoingCommunication == BT_TRUE  )
        {
            _IPC_stBufferProperties[i].u8HeartBeatCount--;
            if ( _IPC_stBufferProperties[i].u8HeartBeatCount == 0x0 )
            {
                _IPC_stBufferProperties[i].u8HeartBeatCount = IPC_MAX_HEARTBEAT_COUNT;
                _IPC_stBufferProperties[i].bOutgoingCommunication = BT_FALSE;
#if defined(RESET_REMOTE_CHANNEL_IPC)
                IPC_u16WriteBlock((IPC_ENUM_CHANNEL)i, (const Uint8Type *)_IPC_au8ResetChannel, sizeof(_IPC_au8ResetChannel), _IPC_cbInternalHandling);
#endif
#ifdef TRACE_MESSAGES_IPC
                DEBUG_VALUE1(IPC_SWI_TRC, MOD_IPC, "IPC_vMonitorCommunication: No heart beat for 5 seconds, reset channel %d",i);
#endif
#ifdef PRINT_MESSAGES_IPC
                printf("IPC_vMonitorCommunication: No heart beat for 5 seconds, reset channel %d\n",i);
#endif
            }
        }
    }
#endif
}

static void _IPC_vCommonResendRoutine(IPC_ENUM_CHANNEL channel)
{
    Uint8Type count, tempCountValue = 0;
    SuccessFailType sF = SUCCESS;
    if ( _IPC_u8NegativeResponseErrorRetryCount < IPC_MAX_CS_ERROR_RETRY_COUNT )
    {
        count = tempCountValue = _IPC_stBufferProperties[channel].u8LastByteStreamCount;
        _IPC_u8NegativeResponseErrorRetryCount++;
#ifdef TRACE_MESSAGES_IPC
        DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Resending last byte stream");
#endif
#ifdef PRINT_MESSAGES_IPC
        printf("IPC_vProcessCommands: Resending last byte stream\n");
#endif
        while (count && (sF == SUCCESS) )
        {
            #ifdef TRACE_MESSAGES_IPC
                    DEBUG_VALUE2(IPC_SWI_TRC, MOD_IPC, "Sending Payload Byte %02X at bytenumber %d",_IPC_stBufferProperties[channel].au8LastByteStream[tempCountValue - count], count);
            #endif
            #ifdef PRINT_MESSAGES_IPC
                    printf("Sending Payload Byte %02X at bytenumber %d\n",_IPC_stBufferProperties[channel].au8LastByteStream[tempCountValue - count], count);
            #endif
            sF = _IPC_sfTxPutByteResend((IPC_ENUM_CHANNEL)(channel), _IPC_stBufferProperties[channel].au8LastByteStream[tempCountValue-count]);
            if (sF == SUCCESS)
            {
                count--;
            }
        }
    }
    else
    {
#ifdef TRACE_MESSAGES_IPC
        DEBUG_TEXT(IPC_SWI_TRC, MOD_IPC, "IPC_vProcessCommands: Give up Checksum Retry Error");
#endif
#ifdef PRINT_MESSAGES_IPC
        printf("IPC_vProcessCommands: Give up Checksum REtry Error\n");
#endif
        _IPC_u8NegativeResponseErrorRetryCount = 0;
        _IPC_stBufferProperties[channel].bOutgoingCommunication = BT_FALSE;
    }
    /*  It is required to resend the last byte stream. */
    /*  Resend the last commmand byte to be set to 1 */
}


#ifndef OSEK_SUPPORTED_OS
void IPC_vWriteManager(int fd)
#else
void IPC_vWriteManager(void)
#endif
{
    Uint8Type channel = 0;
    Uint8Type *txGetTempPtr;

    /* This function checks if there is any byte to be sent on the bus. */
    for ( channel = 0; channel < enIpcMaxChannel; channel++)
    {
        if ( _IPC_stBufferProperties[channel].bInitDone == BT_FALSE)
        {
    #ifdef TRACE_MESSAGES_IPC
            DEBUG_VALUE1(IPC_SWI_ERR, MOD_IPC, "Init not done !!!!!! for Channel %d",channel);
    #endif
    #ifdef PRINT_MESSAGES_IPC
            printf("Init not done !!!!!! for Channel %d\n",channel);
    #endif
break;
        }

        txGetTempPtr = _IPC_stBufferProperties[channel].txResponseBuffer;
        _IPC_stBufferProperties[channel].u8LastByteStreamCount = 0;
        if ( ((*txGetTempPtr) == DLE) &&
        	 (_IPC_stBufferProperties[channel].bIncomingCommunication == BT_TRUE) &&
             (_IPC_stBufferProperties[channel].bOutgoingCommunication == BT_FALSE) &&
             (_IPC_stBufferProperties[channel].bWriteResponseBlockBusy == BT_FALSE))
        {
            do
            {
#ifdef OSEK_SUPPORTED_OS
#ifndef SINGLE_BYTE_TRANSMISSION
                (void)UART_u16WriteBlock(UART_IPC, txGetTempPtr , 0x01 );
#endif
#ifdef SINGLE_BYTE_TRANSMISSION
                while(SCI_BUS_TX_DATA != ADR_SCI_sendByte(*txGetTempPtr));  /* versendet 1 Byte ?ber SCI-Interface */
#endif
#else
                write(fd, txGetTempPtr, (Uint8Type)(0x01));
#endif
#ifdef HEARTBEAT_PRINZIP_IPC
                if ((*txGetTempPtr == _IPC_au8HeartBeatStatus[0]) &&
                    (_IPC_stBufferProperties[channel].u8LastByteStreamCount == 0x03))
                {
                    _IPC_stBufferProperties[channel].bHeartbeatmessage = BT_TRUE;
                }
#endif
                txGetTempPtr++;
                _IPC_u8LastChannelSend = channel;
                _IPC_stBufferProperties[channel].au8LastByteStream[_IPC_stBufferProperties[channel].u8LastByteStreamCount] = _IPC_stBufferProperties[channel].txGetPtr[0];
                _IPC_stBufferProperties[channel].u8LastByteStreamCount++;
            } while (*txGetTempPtr != DLE );
            memset ( _IPC_stBufferProperties[channel].txResponseBuffer, 0xFF , IPC_MAX_SIZE_OF_TX_RESPONSE_BUFFER);
            _IPC_stBufferProperties[channel].txResponseBufferCount = 0;

            if(BT_FALSE == _IPC_stBufferProperties[channel].bHeartbeatmessage)
            {
                _IPC_stBufferProperties[channel].bIncomingCommunication = BT_FALSE;
            }

        }
        else if ((_IPC_stBufferProperties[channel].txPutCount - _IPC_stBufferProperties[channel].txGetCount)!= 0)
        {
            if ( _IPC_stBufferProperties[channel].txGetPtr[0] == DLE && _IPC_stBufferProperties[channel].bOutgoingCommunication == BT_FALSE &&
                    _IPC_stBufferProperties[channel].bIncomingCommunication == BT_FALSE)
            {
                do
                {
#ifdef OSEK_SUPPORTED_OS
#ifndef SINGLE_BYTE_TRANSMISSION
                    //semP(UART_LockResource);
                    (void)UART_u16WriteBlock(UART_IPC, _IPC_stBufferProperties[channel].txGetPtr, 0x01 );
#endif
#ifdef SINGLE_BYTE_TRANSMISSION
                    while(SCI_BUS_TX_DATA != ADR_SCI_sendByte(_IPC_stBufferProperties[channel].txGetPtr[0]));  /* versendet 1 Byte ?ber SCI-Interface */
#endif
#else
                    write(fd, _IPC_stBufferProperties[channel].txGetPtr, (Uint8Type)(0x01));
#endif
                    _IPC_stBufferProperties[channel].txGetCount++;
                    _IPC_stBufferProperties[channel].txGetPtr++;
                    if (_IPC_stBufferProperties[channel].txGetPtr >= ((_IPC_stBufferProperties[channel].txRingBuffer) + (_IPC_stBufferProperties[channel].sizeofTxBuffer)))
                    {
                        _IPC_stBufferProperties[channel].txGetPtr = _IPC_stBufferProperties[channel].txRingBuffer;
                    }
                    _IPC_u8LastChannelSend = channel;
                    _IPC_stBufferProperties[channel].au8LastByteStream[_IPC_stBufferProperties[channel].u8LastByteStreamCount] = _IPC_stBufferProperties[channel].txGetPtr[0];
                    _IPC_stBufferProperties[channel].u8LastByteStreamCount++;
                } while (_IPC_stBufferProperties[channel].txGetPtr[0] != DLE );
                //semV(UART_LockResource);
                _IPC_stBufferProperties[channel].txGetCount++;
                _IPC_stBufferProperties[channel].txGetPtr++; // Skip the DLE End.
                if (_IPC_stBufferProperties[channel].txGetPtr >= ((_IPC_stBufferProperties[channel].txRingBuffer) + (_IPC_stBufferProperties[channel].sizeofTxBuffer)))
                {
                    _IPC_stBufferProperties[channel].txGetPtr = _IPC_stBufferProperties[channel].txRingBuffer;
                }
                if ( channel == enIpcChannelWatchDog )
                {
                    _IPC_stBufferProperties[channel].bOutgoingCommunication = BT_FALSE;
                }
                else
                {
                    _IPC_stBufferProperties[channel].bOutgoingCommunication = BT_TRUE;
                }
#if defined(IPC_RELEASE_OUTGOING_COMM)
                _IPC_stBufferProperties[channel].bOutgoingCommunication = BT_FALSE;
#endif
            }
        }
#ifdef OSEK_SUPPORTED_OS
        else
        {
#ifndef SINGLE_BYTE_TRANSMISSION
            _UART_vSendFirstByte(UART_IPC);
#else
            ;
#endif
        }
#endif
    }
}


/*----------------------------------------------------------------------------*/
/* Function    : _IPC_sfTxPutByteRequest                                            */
/**
    \brief      Put Byte in Tx ring Buffer

    \brief      Description:
                Putting the byte in the Tx ring Buffer and incrementing the
                Putptr for the Ring Buffer and then wrap around.

    \param      pstUart
                SCI_PST
                IPC1 / IPC2
    \param      dasByte
                Uint8Type
                Value between 0 and 255
    \return     SuccessFailType
                If the function was successful or failed
                SUCCESS, FAIL
*/
/*----------------------------------------------------------------------------*/
static SuccessFailType _IPC_sfTxPutByteRequest(IPC_ENUM_CHANNEL channel, Uint8Type dasByte, BooleanType bChecksumCalc)
{
    SuccessFailType sF = SUCCESS;
    Uint8Type *temp;
    /*------------------------------------------------------------------------*/
    /* Buffered I/O is running so we write to the ring buffer.                */
    /*------------------------------------------------------------------------*/
    /* Is there room in the buffer?                                           */
    if (
        (_IPC_stBufferProperties[channel].txPutCount
                - _IPC_stBufferProperties[channel].txGetCount)
            < (_IPC_stBufferProperties[channel].sizeofTxBuffer)
        )
    {
        /* Calculate Outgoing Checksum */
        if ( bChecksumCalc == BT_TRUE )
        {
            _IPC_u8CalculatedChecksumOutgoing = (_IPC_u8CalculatedChecksumOutgoing + dasByte) ^ 0x12;
        }        
        /* Yes, so write the byte then update the put pointer wrapping        */
        /* it if we reached the end back to the beginning of the buffer       */
        temp = (_IPC_stBufferProperties[channel].txRingBuffer) + (_IPC_stBufferProperties[channel].sizeofTxBuffer);
        if (_IPC_stBufferProperties[channel].txPutPtr >= (temp))
        {
            _IPC_stBufferProperties[channel].txPutPtr = _IPC_stBufferProperties[channel].txRingBuffer;
        }
        *(_IPC_stBufferProperties[channel].txPutPtr) = dasByte;
        
        // ds
        printf("PutByteRequest: 0x%02X\n", dasByte);

        _IPC_stBufferProperties[channel].txPutPtr++;
        /* Must increment the count                                        */
        _IPC_stBufferProperties[channel].txPutCount++;
    }
    else
    {
        /* Record error                                                    */
        sF = FAIL;
        _IPC_stBufferProperties[channel].txStatus = 1;
        _IPC_stBufferProperties[channel].BufferoverflowCount++;
        IPC_sfInit(channel);
#ifdef TRACE_MESSAGES_IPC
        DEBUG_VALUE1(IPC_SWI_TRC, MOD_IPC, "Rotuine TxPutByte Buffer Overflow !!!!!! for Channel %d",channel);
#endif
#ifdef PRINT_MESSAGES_IPC
        printf("Routine TxPutByte Buffer Overflow !!!!!! for Channel %d",channel);
#endif
#ifdef DEBUG_MESSAGES_IPC
        DEBUG_Printf(DEBUG_TRACE, DEBUG_IPC, "Routine TxPutByte Buffer Overflow !!!!!! for Channel %d",channel);
#endif
    }
    return(sF);
}

/*----------------------------------------------------------------------------*/
/* Function    : _IPC_sfTxPutByteRequest                                            */
/**
    \brief      Put Byte in Tx ring Buffer

    \brief      Description:
                Putting the byte in the Tx ring Buffer and incrementing the
                Putptr for the Ring Buffer and then wrap around.

    \param      pstUart
                SCI_PST
                IPC1 / IPC2
    \param      dasByte
                Uint8Type
                Value between 0 and 255
    \return     SuccessFailType
                If the function was successful or failed
                SUCCESS, FAIL
*/
/*----------------------------------------------------------------------------*/
static SuccessFailType _IPC_sfTxPutByteResponse(IPC_ENUM_CHANNEL channel, Uint8Type dasByte, BooleanType bChecksumCalc)
{
    SuccessFailType sF = SUCCESS;
    /*------------------------------------------------------------------------*/
    /* Buffered I/O is running so we write to the ring buffer.                */
    /*------------------------------------------------------------------------*/
    /* Is there room in the buffer?                                           */
    /* Calculate Outgoing Checksum */
    if ( bChecksumCalc == BT_TRUE )
    {
        _IPC_u8CalculatedChecksumOutgoing = (_IPC_u8CalculatedChecksumOutgoing + dasByte) ^ 0x12;
    }
    /* Yes, so write the byte then update the put pointer wrapping        */
    /* it if we reached the end back to the beginning of the buffer       */
    *(_IPC_stBufferProperties[channel].txResponseBuffer + _IPC_stBufferProperties[channel].txResponseBufferCount) = dasByte;

    // ds
	printf("PutByteResponse: 0x%02X\n", dasByte);

    _IPC_stBufferProperties[channel].txResponseBufferCount++;
    return(sF);
}


/*----------------------------------------------------------------------------*/
/* Function    : _IPC_sfTxPutByteRequest                                            */
/**
    \brief      Put Byte in Tx ring Buffer

    \brief      Description:
                Putting the byte in the Tx ring Buffer and incrementing the
                Putptr for the Ring Buffer and then wrap around.

    \param      pstUart
                SCI_PST
                IPC1 / IPC2
    \param      dasByte
                Uint8Type
                Value between 0 and 255
    \return     SuccessFailType
                If the function was successful or failed
                SUCCESS, FAIL
*/
/*----------------------------------------------------------------------------*/
static SuccessFailType _IPC_sfTxPutByteResend(IPC_ENUM_CHANNEL channel, Uint8Type dasByte)
{
    SuccessFailType sF = SUCCESS;
    Uint8Type *temp;
    /*------------------------------------------------------------------------*/
    /* Buffered I/O is running so we write to the ring buffer.                */
    /*------------------------------------------------------------------------*/
    /* Is there room in the buffer?                                           */
    if (
        (_IPC_stBufferProperties[channel].txPutCount
                - _IPC_stBufferProperties[channel].txGetCount)
            < (_IPC_stBufferProperties[channel].sizeofTxBuffer)
        )
    {
        /* Yes, so write the byte then update the put pointer wrapping        */
        /* it if we reached the end back to the beginning of the buffer       */
        temp = (_IPC_stBufferProperties[channel].txRingBuffer) + (_IPC_stBufferProperties[channel].sizeofTxBuffer);
        if (_IPC_stBufferProperties[channel].txPutPtr >= (temp))
        {
            _IPC_stBufferProperties[channel].txPutPtr = _IPC_stBufferProperties[channel].txRingBuffer;
        }
        *(_IPC_stBufferProperties[channel].txPutPtr) = dasByte;
        
        // ds
		printf("PutByteResend: 0x%02X\n", dasByte);

        _IPC_stBufferProperties[channel].txPutPtr++;
        /* Must increment the count                                        */
        _IPC_stBufferProperties[channel].txPutCount++;
    }
    else
    {
        /* Record error                                                    */
        sF = FAIL;
        _IPC_stBufferProperties[channel].txStatus = 1;
        _IPC_stBufferProperties[channel].BufferoverflowCount++;
        IPC_sfInit(channel);
#ifdef TRACE_MESSAGES_IPC
        DEBUG_VALUE1(IPC_SWI_TRC, MOD_IPC, "Rotuine TxResend Buffer Overflow !!!!!! for Channel %d",channel);
#endif
#ifdef PRINT_MESSAGES_IPC
        printf("Routine TxResend Buffer Overflow !!!!!! for Channel %d",channel);
#endif
    }
    return(sF);
}

/*----------------------------------------------------------------------------*/
/* Function    : IPC_u16WriteBlock                                         */
/**
    \brief      Send a block of bytes on the IPC.

    \brief      Description:
                This function puts the application block on the TX Ring buffer
                and increases the Putptr.

    \param      pstUart
                SCI_ST
                IPC1 / IPC2
    \param      block
                Uint8Type *
                Contains the address of the application buffer.
    \param      sizeofBlock
                Uint8Type
                No of iterations to be done.
    \return     Uint16Type
                Returns the no of bytes which were actually written to the
                Tx Ring buffer. In Success case, it should be the same as the
                Application has requested.
*/
/*----------------------------------------------------------------------------*/
Uint16Type IPC_u16WriteBlock(IPC_ENUM_CHANNEL channel, const Uint8Type *block, Uint8Type sizeofBlock, void (*cb)(Uint8Type *, Uint8Type))
{
    Uint8Type count = sizeofBlock;
    Uint8Type count_temp = sizeofBlock;
    Uint8Type count_protocol = 0x03;
    SuccessFailType sF = SUCCESS;

    if ( _IPC_stBufferProperties[channel].bInitDone == BT_FALSE)
    {
#ifdef TRACE_MESSAGES_IPC
        DEBUG_VALUE1(IPC_SWI_ERR, MOD_IPC, "Init not done !!!!!! for Channel %d",channel);
#endif
#ifdef PRINT_MESSAGES_IPC
        printf("Init not done !!!!!! for Channel %d",channel);
#endif
        return 0;
    }

    au8ProtocolArrayHeaderRequest[0] = DLE;
    au8ProtocolArrayHeaderRequest[1] = 0xFF;
    au8ProtocolArrayHeaderRequest[2] = 0xFF;
    
    au8ProtocolArrayFooterRequest[0] = 0xFF;
    au8ProtocolArrayFooterRequest[1] = 0xFF;
    //semP(IPC_LockResource);
    /*----------------------------------------------------------------------*/
    /* As long as we do not fail because we overflowed the buffer, we write */
    /* the block of bytes. The return value is the number of bytes written  */
    /* in case the caller needs to know there was an error.                 */
    /*----------------------------------------------------------------------*/
    if (_IPC_stBufferProperties[channel].txStatus != 0)
    {
//        //semV(IPC_LockResource);
        return 0;
    }
    /* Header */
    if (cb == _IPC_cbInternalHandling )
    {
        au8ProtocolArrayHeaderRequest[1] = 0x10 + channel;
    }
    else
    {
        au8ProtocolArrayHeaderRequest[1] = 0x00 + channel;
    }
    while (count_temp )
    {
        if ( (block[sizeofBlock - count_temp] == 0x7E) || ( block[sizeofBlock - count_temp] == 0x7D  ))
        {
            count++;
        }
        count_temp--;
    }
    if ( cb == NULL )
    {
        au8ProtocolArrayHeaderRequest[2] = count+1;
    }
    else
    {
        au8ProtocolArrayHeaderRequest[2] = count;
    }
    count = sizeofBlock;



/* Header */
    while (count_protocol && (sF == SUCCESS) )
    {
        sF = _IPC_sfTxPutByteRequest(channel, au8ProtocolArrayHeaderRequest[3-count_protocol], BT_TRUE);
        if (sF == SUCCESS)
        {
            count_protocol--;
        }
        else
        {
            //semV(IPC_LockResource);
            return (0x03 - count_protocol);
        }
    }
    if ( cb == NULL )
    {
#ifdef TRACE_MESSAGES_IPC
        DEBUG_VALUE1(IPC_SWI_TRC, MOD_IPC, "Sending Payload Byte %02X",_IPC_au8ImmediateResponseRequested[0]);
#endif
#ifdef PRINT_MESSAGES_IPC
        printf("IPC_u16WriteBlock: Sending Payload Byte %02X\n",_IPC_au8ImmediateResponseRequested[0]);
#endif
        sF = _IPC_sfTxPutByteRequest(channel, _IPC_au8ImmediateResponseRequested[0], BT_TRUE);
    }
/* Payload */
    while (count && (sF == SUCCESS) )
    {
    #ifdef TRACE_MESSAGES_IPC
            DEBUG_VALUE1(IPC_SWI_DBG, MOD_IPC, "Sending Payload Byte %02X",*block);
    #endif
    #ifdef PRINT_MESSAGES_IPC
            printf("Sending Payload Byte %02X\n",*block);
    #endif
        if ( *block == 0x7E )
        {
            sF = _IPC_sfTxPutByteRequest(channel, 0x7D, BT_TRUE);
            sF = _IPC_sfTxPutByteRequest(channel, 0x3E, BT_TRUE);
        }
        else if ( *block == 0x7D )
        {
            
            sF = _IPC_sfTxPutByteRequest(channel, 0x7D, BT_TRUE);
            sF = _IPC_sfTxPutByteRequest(channel, 0x3D, BT_TRUE);
        }
        else
        {
            sF = _IPC_sfTxPutByteRequest(channel, *block, BT_TRUE);
        }
        if (sF == SUCCESS)
        {
            block++;
            count--;
        }
        else
        {
            //semV(IPC_LockResource);
            return (sizeofBlock - count);
        }
    }
/* Footer */
#if !defined(CHECKSUM_PRINZIP_IPC)
    au8ProtocolArrayFooterRequest[0] = '\r';
    au8ProtocolArrayFooterRequest[1] = DLE;
#else
    au8ProtocolArrayFooterRequest[1] = DLE;
#endif
    count_protocol = 0x02;
    while (count_protocol && (sF == SUCCESS) )
    {
#if defined(CHECKSUM_PRINZIP_IPC)
        {
            if ( _IPC_u8CalculatedChecksumOutgoing  == 0x7E )
            {
                _IPC_u8CalculatedChecksumOutgoing = 0xFF;
            }
            au8ProtocolArrayFooterRequest[0] = _IPC_u8CalculatedChecksumOutgoing;
        }
#endif
        sF = _IPC_sfTxPutByteRequest(channel, au8ProtocolArrayFooterRequest[2-count_protocol], BT_FALSE);
        if (sF == SUCCESS)
        {
            count_protocol--;
        }
        else
        {
            //semV(IPC_LockResource);
            return (0x02 - count_protocol);
        }
    }
    _IPC_u8CalculatedChecksumOutgoing = 0;
    if ( cb != _IPC_cbInternalHandling )
    {
        _IPC_stBufferProperties[channel].funcPtr = cb;
            
    }
    //semV(IPC_LockResource);
    return(sizeofBlock - count);
}

/*----------------------------------------------------------------------------*/
/* Function    : IPC_u16WriteResponseBlock                                         */
/**
    \brief      Send a block of bytes on the IPC.

    \brief      Description:
                This function puts the application block on the TX Ring buffer
                and increases the Putptr.

    \param      pstUart
                SCI_ST
                IPC1 / IPC2
    \param      block
                Uint8Type *
                Contains the address of the application buffer.
    \param      sizeofBlock
                Uint8Type
                No of iterations to be done.
    \return     Uint16Type
                Returns the no of bytes which were actually written to the
                Tx Ring buffer. In Success case, it should be the same as the
                Application has requested.
*/
/*----------------------------------------------------------------------------*/
Uint16Type IPC_u16WriteResponseBlock(IPC_ENUM_CHANNEL channel, const Uint8Type *block, Uint8Type sizeofBlock, void (*cb)(Uint8Type *, Uint8Type))
{
    Uint8Type count = sizeofBlock;
    Uint8Type count_temp = sizeofBlock;
    Uint8Type count_protocol = 0x03;
    SuccessFailType sF = SUCCESS;
    Uint8Type u8TempChannelResponse[1] = {0xFF};

    au8ProtocolArrayHeaderResponse[0] = DLE;
    au8ProtocolArrayHeaderResponse[1] = 0xFF;
    au8ProtocolArrayHeaderResponse[2] = 0xFF;

    au8ProtocolArrayFooterResponse[0] = 0xFF;
    au8ProtocolArrayFooterResponse[1] = 0xFF;
    //semP(IPC_LockResource);
    /*----------------------------------------------------------------------*/
    /* As long as we do not fail because we overflowed the buffer, we write */
    /* the block of bytes. The return value is the number of bytes written  */
    /* in case the caller needs to know there was an error.                 */
    /*----------------------------------------------------------------------*/
    if (_IPC_stBufferProperties[channel].txStatus != 0)
    {
        //semV(IPC_LockResource);
        return 0;
    }
    if ( (_IPC_stBufferProperties[channel].bIncomingCommunication == BT_FALSE  || _IPC_stBufferProperties[channel].bOutgoingCommunication == BT_TRUE))
    {
        //semV(IPC_LockResource);
        return 0;
    }
    _IPC_stBufferProperties[channel].bWriteResponseBlockBusy = BT_TRUE;
    _IPC_u8LastChannelSend = channel;
    au8ProtocolArrayHeaderResponse[1] = 0x10 + channel;
    while (count_temp )
    {
        if ( (block[sizeofBlock - count_temp] == 0x7E) || ( block[sizeofBlock - count_temp] == 0x7D  ))
        {
            count++;
        }
        count_temp--;
    }

    if ( cb == NULL )
	{
        au8ProtocolArrayHeaderResponse[2] = count+1;
	}
    else
    {
        au8ProtocolArrayHeaderResponse[2] = count;
    }

    count = sizeofBlock;
    u8TempChannelResponse[0] = (channel & 0x0F) + 0x40 + (channel & 0x0F)*16;
    /* Header */
    while (count_protocol && (sF == SUCCESS) )
    {
        sF = _IPC_sfTxPutByteResponse(channel, au8ProtocolArrayHeaderResponse[3-count_protocol], BT_TRUE);
        if (sF == SUCCESS)
        {
            count_protocol--;
        }
        else
        {
            //semV(IPC_LockResource);
            return (0x03 - count_protocol);
        }
    }
    if ( cb == NULL )
	{
		sF = _IPC_sfTxPutByteResponse(channel, u8TempChannelResponse[0], BT_TRUE);// block[0] = u8TempChannelResponse[0];
	}
/*  Payload */
    while (count && (sF == SUCCESS) )
    {
    #ifdef TRACE_MESSAGES_IPC
            DEBUG_VALUE1(IPC_SWI_TRC, MOD_IPC, "Sending Payload Byte %02X",*block);
    #endif
    #ifdef PRINT_MESSAGES_IPC
            printf("IPC_u16WriteResponseBlock: Sending Payload Byte %02X\n",*block);
    #endif
         if ( *block == 0x7E )
        {
            sF = _IPC_sfTxPutByteResponse(channel, 0x7D, BT_TRUE);
            sF = _IPC_sfTxPutByteResponse(channel, 0x3E, BT_TRUE);
        }
        else if ( *block == 0x7D )
        {

            sF = _IPC_sfTxPutByteResponse(channel, 0x7D, BT_TRUE);
            sF = _IPC_sfTxPutByteResponse(channel, 0x3D, BT_TRUE);
        }
        else
        {
            sF = _IPC_sfTxPutByteResponse(channel, *block, BT_TRUE);
        }
        if (sF == SUCCESS)
        {
            block++;
            count--;
        }
        else
        {
            //semV(IPC_LockResource);
            return (sizeofBlock - count);
        }
    }
/* Footer */
#if !defined(CHECKSUM_PRINZIP_IPC)
    au8ProtocolArrayFooterResponse[0] = '\r';
    au8ProtocolArrayFooterResponse[1] = '\n';
#else
    au8ProtocolArrayFooterResponse[1] = DLE;
#endif
    count_protocol = 0x02;
    while (count_protocol && (sF == SUCCESS) )
    {
        #if defined(CHECKSUM_PRINZIP_IPC)
        {
            if ( _IPC_u8CalculatedChecksumOutgoing  == 0x7E )
            {
                _IPC_u8CalculatedChecksumOutgoing = 0xFF;
            }
            au8ProtocolArrayFooterResponse[0] = _IPC_u8CalculatedChecksumOutgoing;
        }
        #endif
        sF = _IPC_sfTxPutByteResponse(channel, au8ProtocolArrayFooterResponse[2-count_protocol], BT_FALSE);
        if (sF == SUCCESS)
        {
            count_protocol--;
        }
        else
        {
            //semV(IPC_LockResource);
            return (0x02 - count_protocol);
        }
    }
    _IPC_u8CalculatedChecksumOutgoing = 0;
    _IPC_stBufferProperties[channel].bWriteResponseBlockBusy = BT_FALSE;
    //semV(IPC_LockResource);
    return(sizeofBlock - count);
}

void ReleaseCommunication(IPC_ENUM_CHANNEL channel)
{
    _IPC_stBufferProperties[channel].bOutgoingCommunication = BT_FALSE;
}

/* End Of File IPC_C1.c */
