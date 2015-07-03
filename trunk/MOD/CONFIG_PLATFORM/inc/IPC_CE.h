
#ifndef _IPC_CE_H
#define _IPC_CE_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Import configuration                                                       */
/*----------------------------------------------------------------------------*/
/*  This will monitor the wathc from the remote client and send watchdog at regular intervals. */
#undef WATCHDOG_PRINZIP_IPC
#undef RESET_REMOTE_CHANNEL_IPC
/*  This will monitor the heartbeat from the remote client. */
#undef HEARTBEAT_PRINZIP_IPC
#undef DEBUG_MESSAGES_IPC
#undef TRACE_MESSAGES_IPC
#define PRINT_MESSAGES_IPC               /*  Higher application trace concept */
#define CHECKSUM_PRINZIP_IPC

#define RESEND_LAST_STREAM
#undef IPC_RELEASE_OUTGOING_COMM
#undef OSEK_SUPPORTED_OS               /*  defined: OS CAN bedded system supported */
                                        /*  undef: higher application OS (Linux) */

#undef SINGLE_BYTE_TRANSMISSION		/* defined: TMS470 Bootloader without ISR */
										/* undef:	with CANbedded support or Linux */

#ifdef SINGLE_BYTE_TRANSMISSION			/* if SINGLE_BYTE_TRANSMISSION, no Message support */
	#undef DEBUG_MESSAGES_IPC
	#undef TRACE_MESSAGES_IPC
	#undef PRINT_MESSAGES_IPC
	#define OSEK_SUPPORTED_OS
	#undef HEARTBEAT_PRINZIP_IPC
	#define TMS470R1_BASEADDRESS_SCI2 	  (REG_32)0xFFF7F500
	#define UART2 						(SCI_PST)TMS470R1_BASEADDRESS_SCI2
#endif

/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Constants                                                           */
/*----------------------------------------------------------------------------*/
#define IPC_LENGTH_WATCH_DOG 2
#define IPC_LENGTH_RESEND_LAST_COMMAND 2

#define IPC_MAX_WATCHDOG_COUNT 5 /*  10 seconds for 2 second periodic watch dog interrupt */
#define IPC_MAX_HEARTBEAT_COUNT 5  /*  6 seconds for 2 second periodic watch dog interrupt */

#define IPC_COMMAND_RESEND_LAST_COMMAND {0xF0, 0x0F}

#define DLE   0x7E
#define STX   0xF0
#define ETX   0x0F
#define ACK   0xAA
#define NACK   0x55

#define COUNT_DOWN_TIMER 1000  /*  1 second for 1 ms task. */

#define IPC_GET_RX_COUNT_FROM_BUS ( UART_u8RxGetCount(UART_IPC) != 0 )

typedef enum
{
    enIpcChannelWatchDog,
    enIpcChannelBootloader,
    enIpcChannelCtrlCommands,
    enIpcTestChannel,
    enIpcMaxChannel
} IPC_ENUM_CHANNEL;

#define IPC_CHANNEL_0 0
#define IPC_CHANNEL_1 1
#define IPC_CHANNEL_2 2
#define IPC_CHANNEL_3 3
#define IPC_CHANNEL_4 4
#define IPC_CHANNEL_5 5
#define IPC_CHANNEL_6 6
#define IPC_CHANNEL_7 7
#define IPC_CHANNEL_8 8
#define IPC_CHANNEL_9 9

#define IPC_CHANNEL_WATCHDOG enIpcChannelWatchDog

#define USE_IPC_CHANNEL_0
#define USE_IPC_CHANNEL_1
#define USE_IPC_CHANNEL_2
#define USE_IPC_CHANNEL_3
#undef USE_IPC_CHANNEL_4
#undef USE_IPC_CHANNEL_5
#undef USE_IPC_CHANNEL_6
#undef USE_IPC_CHANNEL_7
#undef USE_IPC_CHANNEL_8
#undef USE_IPC_CHANNEL_9

#define IPC0_SIZEOF_RX_RING_BUFFER         150

#define IPC0_SIZEOF_TX_RING_BUFFER         150


#define IPC1_SIZEOF_RX_RING_BUFFER         150

#define IPC1_SIZEOF_TX_RING_BUFFER         150


#define IPC2_SIZEOF_RX_RING_BUFFER         150

#define IPC2_SIZEOF_TX_RING_BUFFER         150


#define IPC3_SIZEOF_RX_RING_BUFFER         150

#define IPC3_SIZEOF_TX_RING_BUFFER         150

#define IPC3_SIZEOF_TX_RING_BUFFER         150

#define IPC_MAX_SIZE_OF_TX_BUFFER          150

#define IPC_MAX_SIZE_OF_TX_RESPONSE_BUFFER  150

#define IPC_MAX_CS_ERROR_RETRY_COUNT        2

#define UART_IPC  UART2  // Actual


#endif /* _IPC_CE_H */

/*
 * 0x1, 0xF0
 * 0x1, 0xf0
 * 0x1, 0xf0, 0x0
 * 0x1, 0xf0
 * 0x1, 0xf0, 0x3
 *
 */
/* End Of File IPC_CE.h */


