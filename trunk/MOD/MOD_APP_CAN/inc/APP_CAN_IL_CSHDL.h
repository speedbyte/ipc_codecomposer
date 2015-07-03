/******************************************************************************/
/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/


#ifndef _APP_CAN_IL_CSHDL_H
#define _APP_CAN_IL_CSHDL_H

/* CAN Reqeusts */
typedef enum
{
    IGNITION_STATUS_15_RQ,
    IGNITION_STATUS_S_RQ,
    NETWORKMANAGEMENT_ST_RQ,
    BEM_ABSCHALTSTUFEN_RQ,
    FT_TUER_GEOEFFNET_RQ,
    FT_TUER_GULTIG_RQ,
    LOCKING_DWA_RQ,
    LOCKING_ZV_EXTERN_RQ,
    LOCKING_GUELTIG_RQ,
    ZIELGANG_RQ,
    ULTRA_LONG_PRESS_RQ
}CAN_REQUESTS_CSHDL_ID;

typedef struct
{
    CAN_REQUESTS_CSHDL_ID CshdlID_Rq;

    union
    {
    	Uint16Type payLoad;
    	struct
		{
			Uint8Type ZAS_KL_15             	:1;
			Uint8Type ZAS_KL_S					:1;
			Uint8Type ZAS_Reserved          	:6;
			Uint8Type dummy;
		}Klemmen_Status_Requests;  // 16 Bits

		struct
		{
			Uint8Type BEM_Abschaltstufe   		:3;
			Uint8Type BEM_Reserved          	:5;
			Uint8Type dummy;
		}BEM_Abschaltstufen_Status_Requests;  // 16 Bits

        struct
        {
            Uint8Type FT_Tuer_geoeffnet         :1;
            Uint8Type FT_Tuer_gueltig           :1;
            Uint8Type FT_Tuer_Reserved          :6;
            Uint8Type dummy;
        }FT_Tuer_Geoeffnet_Status_Request;

        struct
        {
            Uint8Type LOCK_DWA_active           :1;
            Uint8Type LOCK_ZV_Extern            :1;
            Uint8Type LOCK_gueltig              :1;
            Uint8Type LOCK_Reserved             :5;
            Uint8Type dummy;
        }Locking_Status_Request;

        struct
        {
            Uint8Type GE_Zielgang               :4;
            Uint8Type GE_Reserved               :4;
            Uint8Type dummy;
        }Getriebe_Status_Request;

        struct
        {
            Uint8Type Miko_UltraLongPress       :1;
            Uint8Type Miko_Reserved             :7;
            Uint8Type dummy;
        }Mittelkonsole_Status_Request;

		struct
		{
			Uint8Type CarConfig_FactoryMode		:3;
			Uint8Type CarConfig_Reserved        :5;
			Uint8Type dummy;
		}CarConfig_Requests;  // 16 Bits

		struct
		{
			Uint16Type BusStatus;
		}BusStatus_Requests;  // 16 Bits


    }APP_CAN_UnionCanToCshdl;

}CanRequests_CSHDL_MsgType;


void APP_CAN_IL_CheckSignalReception_CSHDL(void);
void APP_CAN_IL_InitSignalReception_CSHDL(void);



#endif /* _APP_CAN_IL_CSHDL_H */

/* End Of File _APP_CAN_IL_CSHDL_H.h */
