/******************************************************************************/
/*****************  Copyright (c) 2011 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     DEH_DTC_CFG.h
*-----------------------------------------------------------------------------
* Module Name:    DEH
*-----------------------------------------------------------------------------
* Description:    Describe all DTC for the ADR system
*-----------------------------------------------------------------------------
* $Date:  $
* $Rev:  $
* $Author:  $
* $URL:  $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#define	DTC_C12000_BUS_OFF_FEHLER                                           0
#define	DTC_C12001_EINDRAHT_FEHLER                                          1
#define DTC_C12002_TIMEOUT_MOTORSTEUERUNG                                   2
#define DTC_C12004_TIMEOUT_GERTIEBESTEUERUNG                                3
#define DTC_C12007_TIMEOUT_PSM                                              4
#define DTC_C12008_TIMEOUT_ELEKTRISCHE_PARKBREMSE                           5
#define DTC_C1200B_TIMEOUT_LWS                                              6
#define DTC_C1200C_TIMEOUT_PASM                                             7
#define DTC_C1200F_TIMEOUT_SMLS                                             8
#define DTC_C12013_TIMEOUT_TUERSTEUERGERAET_FAHRER                          9
#define DTC_C12015_TIMEOUT_RDK                                              10
#define DTC_C12016_TIMEOUT_BCM_VORNE                                        11
#define DTC_C12017_TIMEOUT_BCM_HINTEN                                       12
#define DTC_C12018_TIMEOUT_KOMBIINSTRUMENT                                  13
#define DTC_C12019_TIMEOUT_BEDIEN_UND_KLIMAREGELUNG                         14
#define DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY                                  15
#define DTC_C12037_TIMEOUT_ON_BOARD_LADER                                   16
#define DTC_C12039_TIMEOUT_LIFT_VA                                          17
#define DTC_C1207F_TIMEOUT_MITTELKONSOLE                                    18
#define DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG                              19
#define DTC_C12082_SIGNALFEHLER_GETRIEBESTEUERUNG                           20
#define DTC_C12085_SIGNALFEHLER_PSM                                         21
#define DTC_C12089_SIGNALFEHLER_LWS                                         22
#define DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT                             23
#define DTC_C12097_SIGNALFEHLER_BEDIEN_UND_KLIMAREGELUNG                    24
#define DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER                              25
#define DTC_C120B1_SIGNALFEHLER_LIFT_VA                                     26
#define DTC_C120B5_SIGNALFEHLER_MITTELKONSOLE                               27
#define DTC_C11000_UNTERSPANNUNG                                            28
#define DTC_C11001_UEBERSPANNUNG                                            29
#define DTC_C11002_UNTERTEMPERATUR                                          30
#define DTC_C11003_UEBERTEMPERATUR                                          31

/*---------------------------------------------------------------------------*/
/* Event Fault data block for DEH Handler                                    */
/*---------------------------------------------------------------------------*/
typedef struct
{
    uint16_t             EventNumber;
    uint8_t              StatusOfDTC;
    uint8_t              LimitUnlearnCnt;
    uint8_t              OCC;

#ifdef DEH_READ_STD_FF
      tDEH_StdFreezeFrame StdFreezeFrames;
#endif

#ifdef DEH_READ_ADD_FF
      tDEH_AddFreezeFrame  AddFreezeFrame[DEH_MAX_NUMBER_ADD_FF];
#endif

} tDEH_EEPEventDataBlock;


typedef union
{
	tDEH_EEPEventDataBlock struc[DEH_MAX_NUMBER_EV_MEM];
	char AllString[EMB_BLOCK_SIZE * DEH_MAX_NUMBER_EV_MEM];
}
Union_EEPEventDataBlock;
