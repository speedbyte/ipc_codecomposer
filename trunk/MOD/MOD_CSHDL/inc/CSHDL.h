/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     CSHDL.h
*-----------------------------------------------------------------------------
* Module Name:
*-----------------------------------------------------------------------------
* Description:
*-----------------------------------------------------------------------------
* $Date: 2009-03-09 16:19:25 +0100 (Mo, 09 Mrz 2009) $
* $Rev: 4933 $
* $Author: agrawal $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/MOD/MOD_LED/trunk/inc/LED.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _CSHDL_H
#define _CSHDL_H


extern void CSHDL_vCK5050_PowerOFF_ACK(void);
extern void CSHDL_vCK5050_Startup(void);


extern BooleanType CSHDL_bIsHMI_ModeOn(void);

extern  void CSHDL_vMediaRequestStatusChange(void);

extern  void CSHDL_vPhoneRequestStatusChange(void);

extern BooleanType CSHDL_bIsUsbPortSwitcedOn(void);

typedef enum
{
	RequestCanCommunication,
	ReleaseCanCommunication,
	DisableCanCommunication,
	FastShutDownCanCommunication
}CSHDL_ENUM_REQUEST_TO_CAN;

#endif /* _CSHDL_H */

/* End Of File CSHDL.h */
