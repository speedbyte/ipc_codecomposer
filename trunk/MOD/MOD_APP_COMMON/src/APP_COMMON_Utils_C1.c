/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     APP_COMMON_UTILS_C1.c
*-----------------------------------------------------------------------------
* Module Name:    Common Application
*-----------------------------------------------------------------------------
* Description:    contains some helper functions common for all applications   
*-----------------------------------------------------------------------------
* $Date: 2011-05-10 08:47:40 +0200 (Di, 10 Mai 2011) $
* $Rev: 19553 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_COMMON/trunk/src/APP_COMMON_Utils_C1.c $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
//#include "osek.h"    
#include "osekcom.h"
#include "stdlib.h"
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "APP_COMMON_Utils.h"

#include "APP_COMMON_Utils_C1.id"
#include "Trace.h"
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
/** 
\brief	description of the method
*/

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
//ATResponseAllType   atRsp;

/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the private constant
*/


/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Function    : APP_COMMON_UTILS_vGetUint16Type                              */
/** 
    \brief      Extracts an Uint16Type from a byte sequence 
  
    \param      pBufferStart
                const Uint8Type*

    \return     Uint16Type
                The converted Uint16 value 
*/
/*----------------------------------------------------------------------------*/
Uint16Type APP_COMMON_UTILS_u16GetUint16Type( const Uint8Type *pBufferStart) 
{
    Uint16Type val = 0;

    // BAP sends right byte first, then the left byte ( when Uint16 read in
    // BigEndian

    // first copy right byte of received Uint16 and shift it to the left byte
    // of val
    val = *(pBufferStart + 1);
    val <<= 8;
    // copy left byte of received Uint16 to the right byte of val    
    val |= *pBufferStart;
        
    return val;
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_COMMON_UTILS_vSetUint16Type                              */
/** 
    \brief      Writes an Uint16Type to a byte sequence 
  
    \param      value
                Uint16Type

    \param      pBufferStart
                Uint8Type*

    \return     void 
*/
/*----------------------------------------------------------------------------*/
void APP_COMMON_UTILS_vSetUint16Type( Uint16Type value,
                                      Uint8Type *pBufferStart ) 
{
    // make right byte of value to left byte of Uint16 in pBufferStart 
    pBufferStart[0] = (Uint8Type)(value & 0xFF);
    // make left byte of value to right byte of Uint16 in pBufferStart 
    pBufferStart[1] = (Uint8Type)((value >>8) & 0xFF);
}
/*----------------------------------------------------------------------------*/
/* Function    : APP_COMMON_UTILS_vSetUpperNibble                             */
/** 
    \brief      Sets upper nibble of a byte to val 
  
    \param      ptr
                Uint8Type*
                Pointer to buffer

    \param      val 
                Value to set

    \return     void 
*/
/*----------------------------------------------------------------------------*/
void APP_COMMON_UTILS_vSetUpperNibble(Uint8Type *ptr, Uint8Type val)
{
    /* set upper 4 bits to zero */
    *ptr &= 0x0F; 
    /* set upper 4 bits to val */
    *ptr |= val<<4 ;
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_COMMON_UTILS_vSetLowerNibble                             */
/** 
    \brief      Sets lower nibble of a byte to val 
  
    \param      ptr
                Uint8Type*
                Pointer to buffer

    \param      val 
                Value to set

    \return     void 
*/
/*----------------------------------------------------------------------------*/
void APP_COMMON_UTILS_vSetLowerNibble(Uint8Type *ptr, Uint8Type val)
{
    /* set lower 4 bits to zero */
    *ptr &= 0xF0; 
    /* set lower 4 bits to val */
    *ptr |= (val & 0x0F) ;
}



/*----------------------------------------------------------------------------*/
/* Function    : APP_COMMON_UTILS_vSetOsekRelAlarm                            */
/** 
    \brief      Checks if the specified alarm is currently active, in that case
                the alarm is cancel before set, otherwise it is set directly  
  
    \param      inAlarmID
                Osek alarm id

    \param      inIncrement

    \param      inCycle
                
    \return     StatusType 
*/
/*----------------------------------------------------------------------------*/
StatusType APP_COMMON_UTILS_stSetOsekRelAlarm(  AlarmType   inAlarmID, 
                                                TickType    inIncrement, 
                                                TickType    inCycle)
{
    StatusType status = E_OK;
    TickType ticksLeft;

    /* first check if the specified alarm is running */
    if( GetAlarm(inAlarmID, &ticksLeft) == E_OK )
    {
        /* the alarm is running, so cancel it */
        (void)CancelAlarm(inAlarmID);
    }
    
    /* now set the alarm */
    status = SetRelAlarm(inAlarmID, inIncrement, inCycle);

    return status;
}


/*----------------------------------------------------------------------------*/
/* Function    : APP_COMMON_UTILS_bIsAlarmActive                              */
/** 
    \brief      Checks if the specified alarm is currently active 
  
    \param      inAlarmID
                Osek alarm id

                
    \return     BooleanType 
*/
/*----------------------------------------------------------------------------*/
BooleanType APP_COMMON_UTILS_bIsAlarmActive( AlarmType inAlarmID)
{
    TickType ticksLeft;

    /* first check if the specified alarm is running */
    if( GetAlarm(inAlarmID, &ticksLeft) == E_OK )
    {
        return BT_TRUE;
    }
    
    return BT_FALSE;
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_COMMON_UTILS_stCancelOsekRelAlarm                        */
/** 
    \brief      Cancel a given Osek Alarm
  
    \param      inAlarmID
                AlarmType
                
    \return     StatusType 
*/
/*----------------------------------------------------------------------------*/
StatusType APP_COMMON_UTILS_stCancelOsekRelAlarm(  AlarmType   inAlarmID)
{
    StatusType status = E_OK;
    TickType ticksLeft;

    /* first check if the specified alarm is running */
    if( GetAlarm(inAlarmID, &ticksLeft) == E_OK )
    {
        /* the alarm is running, so cancel it */
        status = CancelAlarm(inAlarmID);
    }

    return status;
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_COMMON_UTILS_stGetTimeoutLeft                            */
/** 
    \brief      Returns the time that is left for the specified larm 
  
    \param      inAlarmID
                Osek alarm id

    \param      diffTickTime
                The time that is left in ticks
                
    \return     StatusType
*/
/*----------------------------------------------------------------------------*/
StatusType APP_COMMON_UTILS_stGetTimeoutLeft( AlarmType    inAlarmID, 
                                              TickRefType  diffTickTime)
{
    return GetAlarm(inAlarmID, diffTickTime);
}


/*----------------------------------------------------------------------------*/
/* Function :   APP_COMMON_u32GetSDBM_Hash                                      */
/** 
  \brief        Returns a hash for the given string  
                Hash Code Source: http://www.fantasy-coders.de/projects/gh/html/x435.html
                7.2.4. SDBM Algorithmus
                
                Dieser Algorithmus wird in Sleepycat's Datenbank BDB (Berkeley DataBase) verwendet.
                Original-Code:
                unsigned long
                sdbm(unsigned char *str)
                {
                  unsigned long hash = 0;
                  int c;
                
                  while (c = *str++)
                    hash = c + (hash << 6) + (hash << 16) - hash;
                
                  return hash;
                }

  \param        const Uint8Type * str
                byte buffer to calculate the hash for

  \param        Uint16Type len
                length of buffer

  \return       Uint32Type hash
                hash for given buffer
 */
/*----------------------------------------------------------------------------*/
Uint32Type APP_COMMON_u32GetSDBM_Hash(const Uint8Type * str, Uint16Type len)
{
    Uint32Type hash = 0;
    Uint8Type c;
    Uint16Type idx = 0;
    
    // for each character
    for(idx=0; idx<len;idx++)
    {
        c =  str[idx];
        hash = c + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}
            


/* End Of File APP_COMMON_UTILS_C1.c */


