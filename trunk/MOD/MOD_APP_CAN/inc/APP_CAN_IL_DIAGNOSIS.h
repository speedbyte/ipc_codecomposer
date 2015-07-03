/******************************************************************************/
/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/


#ifndef _APP_CAN_IL_DIAGNOSIS_H
#define _APP_CAN_IL_DIAGNOSIS_H

void APP_CAN_IL_InitSignalReception_DIAGNOSIS( void );
void APP_CAN_IL_CheckSignalReception_DIAGNOSIS( void );

/*Interface for Diagnosis module*/
void APP_CAN_IL_DIAGNOSIS_Get_Global_Real_Time( Uint8Type* pDD00Data );

BooleanType APP_CAN_IL_DIAGNOSIS_Get_IgnitionOffStatus( void );

#endif /* _APP_CAN_IL_DIAGNOSIS_H */

/* End Of File APP_CAN_IL_DIAGNOSIS.h */
