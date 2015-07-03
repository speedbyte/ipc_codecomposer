/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/** 
 * \file 	APP_DIAG.h
 * \brief	This file contains prototypes of all the functions that can be used
 * by other modules. Detailed description found below. 
 * \brief	It also contains enum, structure, constant definition etc. that can 
 * be used by other modules. The application/system must include this file 
 * in order to use the interfaces provided by this module.
*/
/*-----------------------------------------------------------------------------
* $Date: 2010-06-10 16:31:27 +0200 (Do, 10 Jun 2010) $
* $Rev: 13526 $
* $Author: agrawal $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_DIAG/trunk/inc/APP_DIAG.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _APP_DESC_H
#define _APP_DESC_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
/* include the export configuration file */

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global const Declarations                                                  */
/*----------------------------------------------------------------------------*/
/* return values of the function SDSext_WriteUserAndIOData() */
/* */


/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/
typedef struct
{
    vuint8 idx;
    vuint8 len;
    DescMsg data;
}DiagMsgDataType;

typedef enum
{
    DIAG_REQ_READ_BY_IDENTIFIER = 0,
    DIAG_REQ_WRITE_BY_IDENTIFIER
}DiagRequestType;

typedef struct
{
    vuint8 elements;
    vuint8 counter;
    DiagRequestType reqType;
    DiagMsgDataType data[8];
}DiagMsgContextType;


typedef struct
{
    Uint8Type KI_RC_Rolle_Konfig;

    Uint8Type KI_BC_Rolle_Datafield_4_reserved:3;
    Uint8Type KI_BC_Rolle_Datafield_4:5;

    Uint8Type KI_BC_Rolle_Datafield_3_reserved:3;
    Uint8Type KI_BC_Rolle_Datafield_3:5;

    Uint8Type KI_BC_Rolle_Datafield_2_reserved:3;
    Uint8Type KI_BC_Rolle_Datafield_2:5;

    Uint8Type KI_BC_Rolle_Datafield_1_reserved:3;
    Uint8Type KI_BC_Rolle_Datafield_1:5;

    Uint8Type Joker_Taste_reserved:5;
    Uint8Type Joker_Taste:3;

    Uint8Type Reserved_Byte_01;

    Uint8Type KBI_Einheit_Sprachen:8;
    Uint8Type KBI_Einheit_Verbrauch_elektr:3;
    Uint8Type KBI_Einheit_Volumen:2;
    Uint8Type KBI_Einheit_Verbrauch:2;
    Uint8Type KBI_Einheit_Temp:1;
    Uint8Type KBI_Einheit_Reserved_01:2;
    Uint8Type KBI_Einheit_Streckenanzeige:1;
    Uint8Type KBI_Einheit_Druck:2;
    Uint8Type KBI_Einheit_Uhrzeit:1;
    Uint8Type KBI_Einheit_Datum:2;

    Uint8Type Memory_reserved_03:3;
    Uint8Type Memory_Entwicklermenue_aktiv:1;
    Uint8Type Memory_WLAN_aktiv:1;
    Uint8Type Memory_Bluetooth_aktiv:1;
    Uint8Type Memory_DAB_aktiv:1;
    Uint8Type Memory_SDARS_aktiv:1;
    Uint8Type Memory_Navigation_aktiv:1;
    Uint8Type Memory_Audioverstaerker_verbaut:1;
    Uint8Type Memory_reserved_02:1;
    Uint8Type Memory_Tuerkontaktfunktion_ein:1;
    Uint8Type Memory_KBI_VW_Entr_Kof:4;
    Uint8Type Memory_KBI_Carjack:2;
    Uint8Type Memory_KBI_Tuerentr_T:1;
    Uint8Type Memory_Wiederverriegelung_ohne_Tueroeffnung:5;

    Uint8Type Memory_reserved_01:2;
    Uint8Type Memory_Tagfahrlicht_aktiv:1;
    Uint8Type Memory_Nachleuchtdauer_Coming_Home:5;
    Uint8Type Memory_Nachleuchtdauer_Innenlicht:5;
    Uint8Type Memory_Regensensor_aktiv:1;
    Uint8Type Memory_KBI_FULL_AFS_Tourist:1;
    Uint8Type Memory_Links_Rechs_Verkehr:1;

    Uint8Type Tuner_FM_Frequenzband;
    Uint8Type Tuner_Schwellen;
    Uint8Type Reserved_Byte_02;
    Uint8Type Reserved_Byte_03;
}CodingBitMaskType;

extern DiagMsgContextType gDiagMsgContext;
/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/
#define SECURITY_BLOCKING_TIME     (10 * 60 * 100)     // 10min via 10ms Timer

/* Flash pattern */
#define FLASH_REQUEST_PADDERN_BOOT          0x55AA0FF0UL
#define FLASH_REQUEST_PATTERN_RESET         0x00000000UL


/* Service 19 sub IDs */
#define UDS_19_ReportNumberOfDTCByStatusMask                            0x01
#define UDS_19_ReportDTCByStatusMask                                    0x02
#define UDS_19_ReportDTCSnapshotRecordByDTCNumber                       0x04
#define UDS_19_ReportDTCExtendedDataRecordByDTCNumber                   0x06
#define UDS_19_ReportNumberOfEmissionRelatedOBDDTCByStatusMask          0x12
#define UDS_19_ReportEmissionRelatedOBDDTCByStatusMask                  0x13
#define UDS_19_StandardDTCInformation                                   0x01
#define UDS_19_StandardFreezeFrame_1                                    0x02
#define UDS_19_AllStandardFreezeFrameAndStandardDTCInformation          0x8F
#define UDS_19_AllOBDExtendedDataRecordNumbers                          0xFE
#define UDS_19_AllDTCExtendedDataRecordNumbers                          0xFF



/* Service 11 ResetType */

#define UDS_11_TimeToPowerDown              (vuint8)5      /* 1..30 s, 255=not supported */ 

#define UDS_11_HardReset                                                0x01
#define UDS_11_KeyOffOnReset                                            0x02
#define UDS_11_SoftReset                                                0x03
#define UDS_11_EnableRapidPowerShutDownSequence                         0x04
#define UDS_11_DisableRapidPowerShutDownSequence                        0x05

/* Service 27 SecurityAccessType */
#define UDS_27_SECURITY_ACCESS_SEED_CODING                              0x03
#define UDS_27_SECURITY_ACCESS_KEY_CODING                               0x04
#define UDS_27_SECURITY_ACCESS_SEED_WRITE_READ_BY_ADDRESS               0x09
#define UDS_27_SECURITY_ACCESS_KEY_WRITE_READ_BY_ADDRESS                0x0A


#define SECURITY_KEY_NOT_VALID            0                 // no key valid
#define SECURITY_KEY_VALID                1                 // normal key for user login valid
#define SECURITY_KEY_DD_VALID             2                 // datensatz download key valid
#define SECURITY_MAX_KEY_LEN              4                 // andere Länge brauchen vorerst nicht unterstützt werden

// Mask for ubSecState (security access)
#define MASK_SEED_COUNTER        0x03
#define MASK_HIDE_SEED_COUNTER   0xFC
#define MASK_SEED_ALREADY_SEND   0x04
#define MASK_SEC_STATUS_LOCKED   0x08
#define MASK_SEC_STATUS_UNLOCKED 0xF4
#define MASK_SEC_ACTIVE          0x40                      // user Login error
#define MASK_SEC_DEACTIVE        0xBF
#define MASK_SEC_DD_ACTIVE       0x80                      // Datensatz Download error
#define MASK_SEC_DD_DEACTIVE     0x7F
#define MASK_SEC_ALL_DEACTIVE    0x3B

//ADR supported 1 login methods
//1) SA2 Login (0x03/0x04)  - Normal Login
#define NUMBER_OF_LOGIN_METHODS_IMPLEMETED    0x01

DescStateGroup ApplDescGetActiveDiagnosticSession(void);
/*----------------------------------------------------------------------------*/


#endif /* _APP_DESC_H */

/* End Of File APP_DIAG.h */


