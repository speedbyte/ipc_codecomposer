/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/** 
 * \file 	EEPROM_Layout_C1.c
 * \brief	This file contains the program to xxxx
 * \brief	This file fulfills the following requirements:
 * 			1. Requirement 1
 * 			2. Requirement 2
 * 			3. Requirement x
 */
/*-----------------------------------------------------------------------------
 * $Date: 2010-05-10 09:40:09 +0200 (Mo, 10 Mai 2010) $
 * $Rev: 12954 $
 * $Author: agrawal $
 * $URL: http://subversion-01/svn/SW_HW_System/Plattform/TMS470/MOD/MOD_EEPROM/branch/MOD_EEPROM_SOP2_REDESIGN_branch/src/EEPROM_Layout_C1.c $
 *-----------------------------------------------------------------------------
 */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include <osek.h>           // vector
#include <osekext.h>        // vector
#include "stdio.h"
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/
#include "APP_COMMON_Utils.h"
#include "APP_DIAG.h"
#include "EEPROM.h"
#include "Version.h"
#include "OSEK_HostTask_H1.h"
#include "OSEK_MonitorTask_H1.h"
#include "TRACE.h"
#include "EEPROM.h"
#include "EEPROM_LAYOUT.h"
/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "EEPROM_LAYOUT_CFG.h"
#include "EEPROM_LAYOUT_generated_H1.h"
#include "EEPROM_LAYOUT_generated_H2.h"
#include "EEPROM_Layout_Cfg_CI.h"
#include "EEPROM_Layout_Cfg_C1.id"

/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the type
 */

/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                        */
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
/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the private constant
 */

static const Uint8Type _EEPROM_au8DefaultE2PVersion[] = "00000000";

/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Function    : FunctionName                                                 */
/**
    \brief      Short description

    \brief      Description:
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
                XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    \param      EEP_Position

    \param      BlockSize_u16

    \param      Buffer_u8

    \return     CommonResponseCodeType
   */
/*----------------------------------------------------------------------------*/
void EEPROM_vLayoutCfgInit(void)
{
    ;
}

/*----------------------------------------------------------------------------*/
/* Function    : EEPROM_enGetEepromLayoutVersionNumber                  */
/**
 \brief       function for request to get Eeprom Layout sw version number

 \param		  ptrau8Value

 \param		  number_len

 \return      CommonResponseCodeType
 */
/*----------------------------------------------------------------------------*/
CommonResponseCodeType EEPROM_enGetEepromLayoutVersionNumber(Uint8Type* ptrau8Value, Uint8Type number_len)
{
    CommonResponseCodeType sF;
    RamMirrorRequest bmReadEeprom;
    Uint8Type u8TempVersionLen = 0;
    Uint8Type u8tmpdata[PAG_DB_EE_ADDRESS_EEPROM_Version_LEN];
    Uint8Type i=0;
    bmReadEeprom.Eeprom_id = EEPROM_LAYOUT_ENUM_EEPROM_Version;
    bmReadEeprom.payload_ptr.byte_seq.data = u8tmpdata;
    bmReadEeprom.payload_ptr.byte_seq.length = PAG_DB_EE_ADDRESS_EEPROM_Version_LEN;
    sF = EEPROM_enGetEepromValues(&bmReadEeprom);
    if ( sF == COMMON_RSP_OK )
    {
        while ( i < 4 )
        {
            ptrau8Value[u8TempVersionLen] = (((*(bmReadEeprom.payload_ptr.byte_seq.data +i)) & 0xF0) >> 4);
            if ( ptrau8Value[u8TempVersionLen]  >  0x9 )
            {
                sF = COMMON_RSP_ERROR;
                DEBUG_TEXT(EEPROM_LAYOUT_CFG_SWI_ERR, MOD_EEPROM_LAYOUT_CFG, "Invalid E2PVersion");
                break;
            }
            u8TempVersionLen++;
            ptrau8Value[u8TempVersionLen] = ((*(bmReadEeprom.payload_ptr.byte_seq.data +i)) & 0x0F);
            if ( ptrau8Value[u8TempVersionLen]  >  0x9 )
            {
                sF = COMMON_RSP_ERROR;
                DEBUG_TEXT(EEPROM_LAYOUT_CFG_SWI_WNG, MOD_EEPROM_LAYOUT_CFG, "Invalid E2PVersion");
                break;
            }
            u8TempVersionLen++;
            i++;
        }
        // copy len number of digits
        for (i=0;i<FODB_EE_ADDDRESS_EEPROM_Version_LEN_ASCII;i++)
        {   /* convert number to ascii character */
            ptrau8Value[i] = ptrau8Value[i] + 0x30;
        }
        ptrau8Value[u8TempVersionLen] = '\0';
    }
    if ( sF == COMMON_RSP_ERROR )
    {
        (void)memcpy(ptrau8Value, _EEPROM_au8DefaultE2PVersion, (FODB_EE_ADDDRESS_EEPROM_Version_LEN_ASCII+1));

        DEBUG_TEXT(EEPROM_LAYOUT_CFG_SWI_WNG, MOD_EEPROM_LAYOUT_CFG, "Error DefaultE2PVersion=0");
    }
    return sF;
}





/* End Of File EEPROM_Layout_Cfg_C1.c */
