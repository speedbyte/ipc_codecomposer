/******************************************************************************/
/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/


#ifndef _APP_CAN_IL_H
#define _APP_CAN_IL_H

#include "APP_CAN_IL_CanSelfDiagnosis.h"
#include "APP_CAN_IL_CSHDL.h"
#include "APP_CAN_IL_Klima.h"
#include "APP_CAN_IL_INFO.h"
#include "APP_CAN_IL_Navigation.h"
#include "APP_CAN_IL_DIAGNOSIS.h"


extern void APP_CAN_IL_CheckSignalReception(void);


extern void APP_CAN_IL_Init(void);
extern void APP_CAN_IL_HandleEvents(EventMaskType event);

typedef struct
{
    /* Klima */
    Uint32Type Klima_Adr_Clima_Mono:1;
    Uint32Type Klima_Adr_T_LVT_O:1;
    Uint32Type Klima_Adr_T_LVT_M:1;
    Uint32Type Klima_Adr_T_LVT_U:1;
    /* Kombi */
    Uint32Type Kombi_Adr_Konfig_Datafeld1:3;
    Uint32Type Kombi_Adr_KI_BC_Rolle_Datenfeld1:5;
    Uint32Type Kombi_Adr_Konfig_Datafeld2:3;
    Uint32Type Kombi_Adr_KI_BC_Rolle_Datenfeld2:5;
    Uint32Type Kombi_Adr_Konfig_Datafeld3:3;
    Uint32Type Kombi_Adr_KI_BC_Rolle_Datenfeld3:5;
    Uint32Type Kombi_Adr_Konfig_Datafeld4:3;
    Uint32Type Kombi_Adr_KI_BC_Rolle_Datenfeld4:5;
    Uint32Type Kombi_Adr_KI_BC_Rolle_Konfig:8;
    Uint32Type Kombi_Adr_KL58d:7;
    Uint32Type Kombi_Adr_KI_Helligkeit:7;
    /* MFL */
    Uint32Type MFL_Adr_Joker_Taste:3;
    /* Einheiten */
    Uint32Type Einheit_KBI_Einheit_Datum:2;
    Uint32Type Einheit_KBI_Einheit_Druck:2;
    Uint32Type Einheit_KBI_Einheit_Streckenanz:1;
    Uint32Type Einheit_KBI_Einheit_Temp:1;
    Uint32Type Einheit_KBI_Einheit_Uhrzeit:1;
    Uint32Type Einheit_KBI_Einheit_Verbrauch:2;
    Uint32Type Einheit_KBI_Einheit_Volumen:2;
    Uint32Type Einheit_KBI_Einheit_Verbrauch_elektr:3;
    Uint32Type Einheit_KBI_Einheit_Sprache:8;
    Uint32Type Einheit_KBI_Set_Timer_1_Jahr:7;
    Uint32Type Einheit_KBI_Set_Timer_2_Jahr:7;
    Uint32Type Einheit_KBI_Set_Timer_3_Jahr:7;
    Uint32Type Einheit_KBI_Set_Timer_4_Jahr:7;
    Uint32Type Einheit_KBI_Set_Timer_1_Minute:6;
    Uint32Type Einheit_KBI_Set_Timer_2_Minute:6;
    Uint32Type Einheit_KBI_Set_Timer_3_Minute:6;
    Uint32Type Einheit_KBI_Set_Timer_4_Minute:6;
    Uint32Type Einheit_KBI_Set_Timer_1_Monat:4;
    Uint32Type Einheit_KBI_Set_Timer_2_Monat:4;
    Uint32Type Einheit_KBI_Set_Timer_3_Monat:4;
    Uint32Type Einheit_KBI_Set_Timer_4_Monat:4;
    Uint32Type Einheit_KBI_Set_Timer_1_Stunde:5;
    Uint32Type Einheit_KBI_Set_Timer_2_Stunde:5;
    Uint32Type Einheit_KBI_Set_Timer_3_Stunde:5;
    Uint32Type Einheit_KBI_Set_Timer_4_Stunde:5;
    Uint32Type Einheit_KBI_Set_Timer_1_Tag:5;
    Uint32Type Einheit_KBI_Set_Timer_2_Tag:5;
    Uint32Type Einheit_KBI_Set_Timer_3_Tag:5;
    Uint32Type Einheit_KBI_Set_Timer_4_Tag:5;
    Uint32Type Einheit_KBI_Set_Timer_1_Laden:1;
    Uint32Type Einheit_KBI_Set_Timer_2_Laden:1;
    Uint32Type Einheit_KBI_Set_Timer_3_Laden:1;
    Uint32Type Einheit_KBI_Set_Timer_4_Laden:1;
    Uint32Type Einheit_KBI_Set_Timer_1_Zyklus_Mo:1;
    Uint32Type Einheit_KBI_Set_Timer_2_Zyklus_Mo:1;
    Uint32Type Einheit_KBI_Set_Timer_3_Zyklus_Mo:1;
    Uint32Type Einheit_KBI_Set_Timer_4_Zyklus_Mo:1;
    Uint32Type Einheit_KBI_Set_Timer_1_Zyklus_Di:1;
    Uint32Type Einheit_KBI_Set_Timer_2_Zyklus_Di:1;
    Uint32Type Einheit_KBI_Set_Timer_3_Zyklus_Di:1;
    Uint32Type Einheit_KBI_Set_Timer_4_Zyklus_Di:1;
    Uint32Type Einheit_KBI_Set_Timer_1_Zyklus_Mi:1;
    Uint32Type Einheit_KBI_Set_Timer_2_Zyklus_Mi:1;
    Uint32Type Einheit_KBI_Set_Timer_3_Zyklus_Mi:1;
    Uint32Type Einheit_KBI_Set_Timer_4_Zyklus_Mi:1;
    Uint32Type Einheit_KBI_Set_Timer_1_Zyklus_Do:1;
    Uint32Type Einheit_KBI_Set_Timer_2_Zyklus_Do:1;
    Uint32Type Einheit_KBI_Set_Timer_3_Zyklus_Do:1;
    Uint32Type Einheit_KBI_Set_Timer_4_Zyklus_Do:1;
    Uint32Type Einheit_KBI_Set_Timer_1_Zyklus_Fr:1;
    Uint32Type Einheit_KBI_Set_Timer_2_Zyklus_Fr:1;
    Uint32Type Einheit_KBI_Set_Timer_3_Zyklus_Fr:1;
    Uint32Type Einheit_KBI_Set_Timer_4_Zyklus_Fr:1;
    Uint32Type Einheit_KBI_Set_Timer_1_Zyklus_Sa:1;
    Uint32Type Einheit_KBI_Set_Timer_2_Zyklus_Sa:1;
    Uint32Type Einheit_KBI_Set_Timer_3_Zyklus_Sa:1;
    Uint32Type Einheit_KBI_Set_Timer_4_Zyklus_Sa:1;
    Uint32Type Einheit_KBI_Set_Timer_1_Zyklus_So:1;
    Uint32Type Einheit_KBI_Set_Timer_2_Zyklus_So:1;
    Uint32Type Einheit_KBI_Set_Timer_3_Zyklus_So:1;
    Uint32Type Einheit_KBI_Set_Timer_4_Zyklus_So:1;
    Uint32Type Einheit_KBI_Set_Timer_1_Zyklus_WH:1;
    Uint32Type Einheit_KBI_Set_Timer_2_Zyklus_WH:1;
    Uint32Type Einheit_KBI_Set_Timer_3_Zyklus_WH:1;
    Uint32Type Einheit_KBI_Set_Timer_4_Zyklus_WH:1;
    /* Memory */
    Uint32Type Memory_KBI_Aussenspiegel_absenken_auto:1;
    Uint32Type Memory_KBI_FULL_AFS_Tourist:1;
    Uint32Type Memory_KBI_Dimmung_OriLicht:7;
    Uint32Type Memory_KBI_RS_d_akt:1;
    Uint32Type Memory_KBI_Nachleucht_IL:5;
    Uint32Type Memory_KBI_Nachleucht:5;
    Uint32Type Memory_KBI_TFL_akt:1;
    Uint32Type Memory_KBI_WV_Entr:5;
    Uint32Type Memory_KBI_Tuerentr_T:1;
    Uint32Type Memory_KBI_Carjack:2;
    Uint32Type Memory_KBI_WV_Entr_Kof:4;
    Uint32Type Memory_KBI_PTC_Zuheizer:1;
    Uint32Type Memory_KBI_Klimastyles:2;
    Uint32Type Memory_KBI_Innenlicht_per_Tuerkontakt:1;
    Uint32Type Memory_KBI_Aussenspiegel_einklapp_auto:1;
    /* Reserved bits */
    Uint32Type Res1:24;
    Uint32Type Res2:32;
}E2pRamPersistentData;

#endif /* _APP_CAN_IL_H */

/* End Of File _APP_CAN_IL.h */
