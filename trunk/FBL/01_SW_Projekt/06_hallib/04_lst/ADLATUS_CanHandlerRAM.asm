;******************************************************************************
;* TMS470 C/C++ Codegen                                       PC Version 2.71 *
;* Date/Time created: Fri Dec 09 13:08:59 2011                                *
;******************************************************************************
	.state16

DWCU	.dwtag  DW_TAG_compile_unit
	.dwattr DWCU, DW_AT_name("ADLATUS_CanHandlerRAM.c")
	.dwattr DWCU, DW_AT_producer("TMS470 C/C++ Codegen PC Version 2.71 Copyright (c) 1996-2008 Texas Instruments Incorporated")
	.dwattr DWCU, DW_AT_stmt_list(0x00)
	.dwattr DWCU, DW_AT_TI_VERSION(0x01)
DW$1	.dwtag  DW_TAG_variable, DW_AT_name("CanCtrl_ST"), DW_AT_symbol_name("_CanCtrl_ST")
	.dwattr DW$1, DW_AT_type(*DWT$1038)
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_variable, DW_AT_name("e_SCC_ST"), DW_AT_symbol_name("_e_SCC_ST")
	.dwattr DW$2, DW_AT_type(*DWT$1052)
	.dwattr DW$2, DW_AT_declaration(0x01)
	.dwattr DW$2, DW_AT_external(0x01)
;	C:\CCStudio_v3.3\tms470\cgtools_271\bin\opt470.exe -v1 -q -s -O2 -e r:/06_hallib/04_lst/ADLATUS_CanHandlerRAM.if r:/06_hallib/04_lst/ADLATUS_CanHandlerRAM.opt -w r:/06_hallib/04_lst 

	.sect	".text:v$0"
	.clink
	.global	_FUN_CCcan_TxDataFromRam_V

DW$3	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_TxDataFromRam_V"), DW_AT_symbol_name("_FUN_CCcan_TxDataFromRam_V")
	.dwattr DW$3, DW_AT_veneer(0x01)
	.dwattr DW$3, DW_AT_low_pc(_FUN_CCcan_TxDataFromRam_V)
	.dwattr DW$3, DW_AT_high_pc(0x00)
	.dwattr DW$3, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_TxDataFromRam_V                               *
;*****************************************************************************
_FUN_CCcan_TxDataFromRam_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CCcan_TxDataFromRam_V+1, 32
	.state16
	.dwendtag DW$3



	.sect	".text"
	.clink
	.global	$FUN_CCcan_TxDataFromRam_V

DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_TxDataFromRam_V"), DW_AT_symbol_name("$FUN_CCcan_TxDataFromRam_V")
	.dwattr DW$4, DW_AT_low_pc($FUN_CCcan_TxDataFromRam_V)
	.dwattr DW$4, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandlerRAM.c",123,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 122 | void FUN_CCcan_TxDataFromRam_V(void)                                   
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_TxDataFromRam_V                                  *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SR                                      *
;*   Regs Used         : A1,A2,A3,A4,SR                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CCcan_TxDataFromRam_V:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 125 | ULONG t_EndlessLoopProtection_UL = 0xFFFFFFFFul;                       
; 127 | UBYTE t_Mailbox_UB;                                                    
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
;* A2    assigned to C$1
DW$5	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$5, DW_AT_type(*DWT$6)
	.dwattr DW$5, DW_AT_location[DW_OP_reg1]
;* A4    assigned to Q$1
DW$6	.dwtag  DW_TAG_variable, DW_AT_name("Q$1"), DW_AT_symbol_name("Q$1")
	.dwattr DW$6, DW_AT_type(*DWT$11)
	.dwattr DW$6, DW_AT_location[DW_OP_reg3]
;* A3    assigned to _t_Mailbox_UB
DW$7	.dwtag  DW_TAG_variable, DW_AT_name("t_Mailbox_UB"), DW_AT_symbol_name("_t_Mailbox_UB")
	.dwattr DW$7, DW_AT_type(*DWT$1018)
	.dwattr DW$7, DW_AT_location[DW_OP_reg2]
;* A2    assigned to _t_EndlessLoopProtection_UL
DW$8	.dwtag  DW_TAG_variable, DW_AT_name("t_EndlessLoopProtection_UL"), DW_AT_symbol_name("_t_EndlessLoopProtection_UL")
	.dwattr DW$8, DW_AT_type(*DWT$1022)
	.dwattr DW$8, DW_AT_location[DW_OP_reg1]
;* A1    assigned to K$10
DW$9	.dwtag  DW_TAG_variable, DW_AT_name("K$10"), DW_AT_symbol_name("K$10")
	.dwattr DW$9, DW_AT_type(*DWT$1042)
	.dwattr DW$9, DW_AT_location[DW_OP_reg0]
;** 130	-----------------------    if ( (C$1 = CanCtrl_ST.MbUsedinRAM_UB) == 255 ) goto g13;
	.dwpsn	"ADLATUS_CanHandlerRAM.c",130,3
;----------------------------------------------------------------------
; 130 | if(d_CCcan_NoMbforRamDefined != CanCtrl_ST.MbUsedinRAM_UB)             
;----------------------------------------------------------------------
        LDR       A1, CON1              ; |130| 
        LDRB      A2, [A1, #0]          ; |130| 
        CMP       A2, #255              ; |130| 
        BEQ       L5                    ; |130| 
        ; |130| 
;* --------------------------------------------------------------------------*
;** 133	-----------------------    t_Mailbox_UB = 1u<<C$1;
	.dwpsn	"ADLATUS_CanHandlerRAM.c",133,5
;----------------------------------------------------------------------
; 133 | t_Mailbox_UB = 0x00000001ul << CanCtrl_ST.MbUsedinRAM_UB;              
; 137 | while (e_SCC_ST.CANES_UN.CANES_ST.RM_B1)                               
; 139 |   ;                                                                    
;----------------------------------------------------------------------
        MOV       A1, #1                ; |133| 
        LSL       A1, A2                ; |133| 
        LSL       A3, A1, #24
        LSR       A3, A3, #24
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    Q$1 = 51;
        MOV       A4, #51
;**  	-----------------------    K$10 = &e_SCC_ST;
        LDR       A1, CON2
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L1
;*
;*   Loop source line                : 137
;*   Loop closing brace source line  : 140
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L1:    
DWL$$FUN_CCcan_TxDataFromRam_V$3$B:
;**	-----------------------g3:
;** 140	-----------------------    if ( ((volatile unsigned char *)K$10)[Q$1]&2u ) goto g3;
	.dwpsn	"ADLATUS_CanHandlerRAM.c",140,5
;----------------------------------------------------------------------
; 143 | while ((e_SCC_ST.CANTRS_UL & (ULONG)t_Mailbox_UB) != 0ul)              
; 145 |   ;                                                                    
;----------------------------------------------------------------------
        LDRB      A2, [A4, A1]          ; |140| 
        LSR       A2, A2, #2            ; |140| 
        BCS       L1                    ; |140| 
        ; |140| 
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
DWL$$FUN_CCcan_TxDataFromRam_V$3$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L2
;*
;*   Loop source line                : 143
;*   Loop closing brace source line  : 146
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L2:    
DWL$$FUN_CCcan_TxDataFromRam_V$4$B:
;**	-----------------------g6:
;** 146	-----------------------    if ( ((volatile struct _scc_st *)K$10)->CANTRS_UL&t_Mailbox_UB ) goto g6;
	.dwpsn	"ADLATUS_CanHandlerRAM.c",146,5
        LDR       A2, [A1, #8]          ; |146| 
        TST       A3, A2                ; |146| 
        BNE       L2                    ; |146| 
        ; |146| 
DWL$$FUN_CCcan_TxDataFromRam_V$4$E:
;* --------------------------------------------------------------------------*
;** 151	-----------------------    if ( ((volatile struct _scc_st *)K$10)->CANTA_UL&t_Mailbox_UB ) goto g12;
	.dwpsn	"ADLATUS_CanHandlerRAM.c",151,5
;----------------------------------------------------------------------
; 151 | while (((e_SCC_ST.CANTA_UL & (ULONG)t_Mailbox_UB) == 0ul) &&           
; 152 |            (0x0000ul != t_EndlessLoopProtection_UL))                   
; 155 |   t_EndlessLoopProtection_UL -= 0x0001ul;                              
;----------------------------------------------------------------------
        LDR       A2, [A1, #16]         ; |151| 
        TST       A3, A2                ; |151| 
        BNE       L4                    ; |151| 
        ; |151| 
;* --------------------------------------------------------------------------*
;**  	-----------------------    #pragma LOOP_FLAGS(4352u)
;** 125	-----------------------    t_EndlessLoopProtection_UL = 0xffffffffu;
	.dwpsn	"ADLATUS_CanHandlerRAM.c",125,9
        MOV       A2, #0                ; |125| 
        MVN       A2, A2                ; |125| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L3
;*
;*   Loop source line                : 151
;*   Loop closing brace source line  : 157
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L3:    
DWL$$FUN_CCcan_TxDataFromRam_V$7$B:
;**	-----------------------g10:
;** 157	-----------------------    if ( !t_EndlessLoopProtection_UL ) goto g12;
	.dwpsn	"ADLATUS_CanHandlerRAM.c",157,5
        CMP       A2, #0                ; |157| 
        BEQ       L4                    ; |157| 
        ; |157| 
DWL$$FUN_CCcan_TxDataFromRam_V$7$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_TxDataFromRam_V$8$B:
;** 155	-----------------------    --t_EndlessLoopProtection_UL;
	.dwpsn	"ADLATUS_CanHandlerRAM.c",155,7
        SUB       A2, #1                ; |155| 
;** 155	-----------------------    if ( !(((volatile struct _scc_st *)K$10)->CANTA_UL&t_Mailbox_UB) ) goto g10;
        LDR       A4, [A1, #16]         ; |155| 
        TST       A3, A4                ; |155| 
        BEQ       L3                    ; |155| 
        ; |155| 
DWL$$FUN_CCcan_TxDataFromRam_V$8$E:
;* --------------------------------------------------------------------------*
L4:    
;**	-----------------------g12:
;** 160	-----------------------    ((volatile struct _scc_st *)K$10)->CANTA_UL |= t_Mailbox_UB;
	.dwpsn	"ADLATUS_CanHandlerRAM.c",160,5
;----------------------------------------------------------------------
; 160 | e_SCC_ST.CANTA_UL  |= (ULONG)t_Mailbox_UB;                             
;----------------------------------------------------------------------
        LDR       A2, [A1, #16]         ; |160| 
        ORR       A2, A3                ; |160| 
        STR       A2, [A1, #16]         ; |160| 
;** 161	-----------------------    ((volatile struct _scc_st *)K$10)->CANTRS_UL |= t_Mailbox_UB;
	.dwpsn	"ADLATUS_CanHandlerRAM.c",161,5
;----------------------------------------------------------------------
; 161 | e_SCC_ST.CANTRS_UL |= (ULONG)t_Mailbox_UB;                             
; 163 | return;                                                                
;----------------------------------------------------------------------
        LDR       A2, [A1, #8]          ; |161| 
        ORR       A2, A3                ; |161| 
        STR       A2, [A1, #8]          ; |161| 
;**	-----------------------g13:
;**  	-----------------------    return;
;* --------------------------------------------------------------------------*
L5:    
	.dwpsn	"ADLATUS_CanHandlerRAM.c",164,1
        BX        LR

DW$10	.dwtag  DW_TAG_loop
	.dwattr DW$10, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandlerRAM.asm:L3:1:1323432539")
	.dwattr DW$10, DW_AT_begin_file("ADLATUS_CanHandlerRAM.c")
	.dwattr DW$10, DW_AT_begin_line(0x97)
	.dwattr DW$10, DW_AT_end_line(0x9d)
DW$11	.dwtag  DW_TAG_loop_range
	.dwattr DW$11, DW_AT_low_pc(DWL$$FUN_CCcan_TxDataFromRam_V$7$B)
	.dwattr DW$11, DW_AT_high_pc(DWL$$FUN_CCcan_TxDataFromRam_V$7$E)
DW$12	.dwtag  DW_TAG_loop_range
	.dwattr DW$12, DW_AT_low_pc(DWL$$FUN_CCcan_TxDataFromRam_V$8$B)
	.dwattr DW$12, DW_AT_high_pc(DWL$$FUN_CCcan_TxDataFromRam_V$8$E)
	.dwendtag DW$10


DW$13	.dwtag  DW_TAG_loop
	.dwattr DW$13, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandlerRAM.asm:L2:1:1323432539")
	.dwattr DW$13, DW_AT_begin_file("ADLATUS_CanHandlerRAM.c")
	.dwattr DW$13, DW_AT_begin_line(0x8f)
	.dwattr DW$13, DW_AT_end_line(0x92)
DW$14	.dwtag  DW_TAG_loop_range
	.dwattr DW$14, DW_AT_low_pc(DWL$$FUN_CCcan_TxDataFromRam_V$4$B)
	.dwattr DW$14, DW_AT_high_pc(DWL$$FUN_CCcan_TxDataFromRam_V$4$E)
	.dwendtag DW$13


DW$15	.dwtag  DW_TAG_loop
	.dwattr DW$15, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandlerRAM.asm:L1:1:1323432539")
	.dwattr DW$15, DW_AT_begin_file("ADLATUS_CanHandlerRAM.c")
	.dwattr DW$15, DW_AT_begin_line(0x89)
	.dwattr DW$15, DW_AT_end_line(0x8c)
DW$16	.dwtag  DW_TAG_loop_range
	.dwattr DW$16, DW_AT_low_pc(DWL$$FUN_CCcan_TxDataFromRam_V$3$B)
	.dwattr DW$16, DW_AT_high_pc(DWL$$FUN_CCcan_TxDataFromRam_V$3$E)
	.dwendtag DW$15

	.dwendentry
	.dwendtag DW$4



;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON1:	.field  	_CanCtrl_ST+16,32
	.align	4
CON2:	.field  	_e_SCC_ST,32
;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	_CanCtrl_ST
	.global	_e_SCC_ST

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
DWT$6	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned char")
	.dwattr DWT$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr DWT$6, DW_AT_byte_size(0x01)
DWT$1018	.dwtag  DW_TAG_typedef, DW_AT_name("UBYTE"), DW_AT_type(*DWT$6)
	.dwattr DWT$1018, DW_AT_language(DW_LANG_C)
DWT$11	.dwtag  DW_TAG_base_type, DW_AT_name("int")
	.dwattr DWT$11, DW_AT_encoding(DW_ATE_signed)
	.dwattr DWT$11, DW_AT_byte_size(0x04)
DWT$1022	.dwtag  DW_TAG_typedef, DW_AT_name("ULONG"), DW_AT_type(*DWT$12)
	.dwattr DWT$1022, DW_AT_language(DW_LANG_C)

DWT$1023	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1023, DW_AT_language(DW_LANG_C)
DWT$1038	.dwtag  DW_TAG_typedef, DW_AT_name("CANCONTROL_ST"), DW_AT_type(*DWT$1037)
	.dwattr DWT$1038, DW_AT_language(DW_LANG_C)
DWT$1042	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1041)
	.dwattr DWT$1042, DW_AT_address_class(0x20)
DWT$1052	.dwtag  DW_TAG_typedef, DW_AT_name("SCC_ST"), DW_AT_type(*DWT$1051)
	.dwattr DWT$1052, DW_AT_language(DW_LANG_C)
DWT$12	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned long")
	.dwattr DWT$12, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$12, DW_AT_byte_size(0x04)

DWT$1037	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1037, DW_AT_name("_CANCONTROL")
	.dwattr DWT$1037, DW_AT_byte_size(0x24)
DW$17	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1026)
	.dwattr DW$17, DW_AT_name("CanMsgObjConfig_PST"), DW_AT_symbol_name("_CanMsgObjConfig_PST")
	.dwattr DW$17, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$17, DW_AT_accessibility(DW_ACCESS_public)
DW$18	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$18, DW_AT_name("CanChannelTable_PST"), DW_AT_symbol_name("_CanChannelTable_PST")
	.dwattr DW$18, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$18, DW_AT_accessibility(DW_ACCESS_public)
DW$19	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$19, DW_AT_name("QuarzClockFrequency_UL"), DW_AT_symbol_name("_QuarzClockFrequency_UL")
	.dwattr DW$19, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$19, DW_AT_accessibility(DW_ACCESS_public)
DW$20	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1031)
	.dwattr DW$20, DW_AT_name("CanNode_UW"), DW_AT_symbol_name("_CanNode_UW")
	.dwattr DW$20, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$20, DW_AT_accessibility(DW_ACCESS_public)
DW$21	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$21, DW_AT_name("DefaultBaudrate_UB"), DW_AT_symbol_name("_DefaultBaudrate_UB")
	.dwattr DW$21, DW_AT_data_member_location[DW_OP_plus_uconst 0xe]
	.dwattr DW$21, DW_AT_accessibility(DW_ACCESS_public)
DW$22	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$22, DW_AT_name("SelectedChannel_UB"), DW_AT_symbol_name("_SelectedChannel_UB")
	.dwattr DW$22, DW_AT_data_member_location[DW_OP_plus_uconst 0xf]
	.dwattr DW$22, DW_AT_accessibility(DW_ACCESS_public)
DW$23	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$23, DW_AT_name("MbUsedinRAM_UB"), DW_AT_symbol_name("_MbUsedinRAM_UB")
	.dwattr DW$23, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$23, DW_AT_accessibility(DW_ACCESS_public)
DW$24	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$24, DW_AT_name("RepeatCounter_UB"), DW_AT_symbol_name("_RepeatCounter_UB")
	.dwattr DW$24, DW_AT_data_member_location[DW_OP_plus_uconst 0x11]
	.dwattr DW$24, DW_AT_accessibility(DW_ACCESS_public)
DW$25	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1032)
	.dwattr DW$25, DW_AT_name("SendData_PUB"), DW_AT_symbol_name("_SendData_PUB")
	.dwattr DW$25, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$25, DW_AT_accessibility(DW_ACCESS_public)
DW$26	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$26, DW_AT_name("MbUsedforStartup_UB"), DW_AT_symbol_name("_MbUsedforStartup_UB")
	.dwattr DW$26, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$26, DW_AT_accessibility(DW_ACCESS_public)
DW$27	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1036)
	.dwattr DW$27, DW_AT_name("DiagResponseTG_PST"), DW_AT_symbol_name("_DiagResponseTG_PST")
	.dwattr DW$27, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$27, DW_AT_accessibility(DW_ACCESS_public)
DW$28	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$28, DW_AT_name("WriteIndex_AUB"), DW_AT_symbol_name("_WriteIndex_AUB")
	.dwattr DW$28, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr DW$28, DW_AT_accessibility(DW_ACCESS_public)
DW$29	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$29, DW_AT_name("ReadIndex_AUB"), DW_AT_symbol_name("_ReadIndex_AUB")
	.dwattr DW$29, DW_AT_data_member_location[DW_OP_plus_uconst 0x21]
	.dwattr DW$29, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1037

DWT$1041	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1040)
DWT$1051	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1050)
DWT$1032	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1032, DW_AT_address_class(0x20)
DWT$1031	.dwtag  DW_TAG_typedef, DW_AT_name("UWORD"), DW_AT_type(*DWT$8)
	.dwattr DWT$1031, DW_AT_language(DW_LANG_C)
DWT$1026	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1025)
	.dwattr DWT$1026, DW_AT_address_class(0x20)
DWT$1030	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1029)
	.dwattr DWT$1030, DW_AT_address_class(0x20)
DWT$1036	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1035)
	.dwattr DWT$1036, DW_AT_address_class(0x20)

DWT$1040	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1040, DW_AT_byte_size(0x04)
DW$30	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$30, DW_AT_name("Notused1"), DW_AT_symbol_name("_Notused1")
	.dwattr DW$30, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x07)
	.dwattr DW$30, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$30, DW_AT_accessibility(DW_ACCESS_public)
DW$31	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$31, DW_AT_name("FE_B1"), DW_AT_symbol_name("_FE_B1")
	.dwattr DW$31, DW_AT_bit_offset(0x07), DW_AT_bit_size(0x01)
	.dwattr DW$31, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$31, DW_AT_accessibility(DW_ACCESS_public)
DW$32	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$32, DW_AT_name("BE_B1"), DW_AT_symbol_name("_BE_B1")
	.dwattr DW$32, DW_AT_bit_offset(0x08), DW_AT_bit_size(0x01)
	.dwattr DW$32, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$32, DW_AT_accessibility(DW_ACCESS_public)
DW$33	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$33, DW_AT_name("SA1_B1"), DW_AT_symbol_name("_SA1_B1")
	.dwattr DW$33, DW_AT_bit_offset(0x09), DW_AT_bit_size(0x01)
	.dwattr DW$33, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$33, DW_AT_accessibility(DW_ACCESS_public)
DW$34	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$34, DW_AT_name("CRCE_B1"), DW_AT_symbol_name("_CRCE_B1")
	.dwattr DW$34, DW_AT_bit_offset(0x0a), DW_AT_bit_size(0x01)
	.dwattr DW$34, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$34, DW_AT_accessibility(DW_ACCESS_public)
DW$35	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$35, DW_AT_name("SE_B1"), DW_AT_symbol_name("_SE_B1")
	.dwattr DW$35, DW_AT_bit_offset(0x0b), DW_AT_bit_size(0x01)
	.dwattr DW$35, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$35, DW_AT_accessibility(DW_ACCESS_public)
DW$36	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$36, DW_AT_name("ACKE_B1"), DW_AT_symbol_name("_ACKE_B1")
	.dwattr DW$36, DW_AT_bit_offset(0x0c), DW_AT_bit_size(0x01)
	.dwattr DW$36, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$36, DW_AT_accessibility(DW_ACCESS_public)
DW$37	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$37, DW_AT_name("BO_B1"), DW_AT_symbol_name("_BO_B1")
	.dwattr DW$37, DW_AT_bit_offset(0x0d), DW_AT_bit_size(0x01)
	.dwattr DW$37, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$37, DW_AT_accessibility(DW_ACCESS_public)
DW$38	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$38, DW_AT_name("EP_B1"), DW_AT_symbol_name("_EP_B1")
	.dwattr DW$38, DW_AT_bit_offset(0x0e), DW_AT_bit_size(0x01)
	.dwattr DW$38, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$38, DW_AT_accessibility(DW_ACCESS_public)
DW$39	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$39, DW_AT_name("EW_B1"), DW_AT_symbol_name("_EW_B1")
	.dwattr DW$39, DW_AT_bit_offset(0x0f), DW_AT_bit_size(0x01)
	.dwattr DW$39, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$39, DW_AT_accessibility(DW_ACCESS_public)
DW$40	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$40, DW_AT_name("Notused2"), DW_AT_symbol_name("_Notused2")
	.dwattr DW$40, DW_AT_bit_offset(0x10), DW_AT_bit_size(0x0a)
	.dwattr DW$40, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$40, DW_AT_accessibility(DW_ACCESS_public)
DW$41	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$41, DW_AT_name("SMA_B1"), DW_AT_symbol_name("_SMA_B1")
	.dwattr DW$41, DW_AT_bit_offset(0x1a), DW_AT_bit_size(0x01)
	.dwattr DW$41, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$41, DW_AT_accessibility(DW_ACCESS_public)
DW$42	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$42, DW_AT_name("CCE_B1"), DW_AT_symbol_name("_CCE_B1")
	.dwattr DW$42, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$42, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$42, DW_AT_accessibility(DW_ACCESS_public)
DW$43	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$43, DW_AT_name("PDA_B1"), DW_AT_symbol_name("_PDA_B1")
	.dwattr DW$43, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$43, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$43, DW_AT_accessibility(DW_ACCESS_public)
DW$44	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$44, DW_AT_name("Notused3"), DW_AT_symbol_name("_Notused3")
	.dwattr DW$44, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$44, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$44, DW_AT_accessibility(DW_ACCESS_public)
DW$45	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$45, DW_AT_name("RM_B1"), DW_AT_symbol_name("_RM_B1")
	.dwattr DW$45, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$45, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$45, DW_AT_accessibility(DW_ACCESS_public)
DW$46	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$46, DW_AT_name("TM_B1"), DW_AT_symbol_name("_TM_B1")
	.dwattr DW$46, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$46, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$46, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1040


DWT$1050	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1050, DW_AT_name("scc_st")
	.dwattr DWT$1050, DW_AT_byte_size(0x5c)
DW$47	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$47, DW_AT_name("CANME_UL"), DW_AT_symbol_name("_CANME_UL")
	.dwattr DW$47, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$47, DW_AT_accessibility(DW_ACCESS_public)
DW$48	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$48, DW_AT_name("CANMD_UL"), DW_AT_symbol_name("_CANMD_UL")
	.dwattr DW$48, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$48, DW_AT_accessibility(DW_ACCESS_public)
DW$49	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$49, DW_AT_name("CANTRS_UL"), DW_AT_symbol_name("_CANTRS_UL")
	.dwattr DW$49, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$49, DW_AT_accessibility(DW_ACCESS_public)
DW$50	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$50, DW_AT_name("CANTRR_UL"), DW_AT_symbol_name("_CANTRR_UL")
	.dwattr DW$50, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$50, DW_AT_accessibility(DW_ACCESS_public)
DW$51	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$51, DW_AT_name("CANTA_UL"), DW_AT_symbol_name("_CANTA_UL")
	.dwattr DW$51, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$51, DW_AT_accessibility(DW_ACCESS_public)
DW$52	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$52, DW_AT_name("CANAA_UL"), DW_AT_symbol_name("_CANAA_UL")
	.dwattr DW$52, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$52, DW_AT_accessibility(DW_ACCESS_public)
DW$53	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$53, DW_AT_name("CANRMP_UL"), DW_AT_symbol_name("_CANRMP_UL")
	.dwattr DW$53, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$53, DW_AT_accessibility(DW_ACCESS_public)
DW$54	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$54, DW_AT_name("CANRML_UL"), DW_AT_symbol_name("_CANRML_UL")
	.dwattr DW$54, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$54, DW_AT_accessibility(DW_ACCESS_public)
DW$55	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$55, DW_AT_name("CANRFP_UL"), DW_AT_symbol_name("_CANRFP_UL")
	.dwattr DW$55, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr DW$55, DW_AT_accessibility(DW_ACCESS_public)
DW$56	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$56, DW_AT_name("CANGAM_UL"), DW_AT_symbol_name("_CANGAM_UL")
	.dwattr DW$56, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr DW$56, DW_AT_accessibility(DW_ACCESS_public)
DW$57	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$57, DW_AT_name("CANMC_UN"), DW_AT_symbol_name("_CANMC_UN")
	.dwattr DW$57, DW_AT_data_member_location[DW_OP_plus_uconst 0x2a]
	.dwattr DW$57, DW_AT_accessibility(DW_ACCESS_public)
DW$58	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$58, DW_AT_name("CANBTC_UL"), DW_AT_symbol_name("_CANBTC_UL")
	.dwattr DW$58, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr DW$58, DW_AT_accessibility(DW_ACCESS_public)
DW$59	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1045)
	.dwattr DW$59, DW_AT_name("CANES_UN"), DW_AT_symbol_name("_CANES_UN")
	.dwattr DW$59, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr DW$59, DW_AT_accessibility(DW_ACCESS_public)
DW$60	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$60, DW_AT_name("notused1"), DW_AT_symbol_name("_notused1")
	.dwattr DW$60, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x18)
	.dwattr DW$60, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr DW$60, DW_AT_accessibility(DW_ACCESS_public)
DW$61	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$61, DW_AT_name("CANTEC_UL"), DW_AT_symbol_name("_CANTEC_UL")
	.dwattr DW$61, DW_AT_data_member_location[DW_OP_plus_uconst 0x37]
	.dwattr DW$61, DW_AT_accessibility(DW_ACCESS_public)
DW$62	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$62, DW_AT_name("notused2"), DW_AT_symbol_name("_notused2")
	.dwattr DW$62, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x18)
	.dwattr DW$62, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr DW$62, DW_AT_accessibility(DW_ACCESS_public)
DW$63	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$63, DW_AT_name("CANREC_UL"), DW_AT_symbol_name("_CANREC_UL")
	.dwattr DW$63, DW_AT_data_member_location[DW_OP_plus_uconst 0x3b]
	.dwattr DW$63, DW_AT_accessibility(DW_ACCESS_public)
DW$64	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$64, DW_AT_name("CANGIFO_UL"), DW_AT_symbol_name("_CANGIFO_UL")
	.dwattr DW$64, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr DW$64, DW_AT_accessibility(DW_ACCESS_public)
DW$65	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$65, DW_AT_name("CANGIM_UL"), DW_AT_symbol_name("_CANGIM_UL")
	.dwattr DW$65, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr DW$65, DW_AT_accessibility(DW_ACCESS_public)
DW$66	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$66, DW_AT_name("CANGIF1_UL"), DW_AT_symbol_name("_CANGIF1_UL")
	.dwattr DW$66, DW_AT_data_member_location[DW_OP_plus_uconst 0x44]
	.dwattr DW$66, DW_AT_accessibility(DW_ACCESS_public)
DW$67	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$67, DW_AT_name("CANMIM_UL"), DW_AT_symbol_name("_CANMIM_UL")
	.dwattr DW$67, DW_AT_data_member_location[DW_OP_plus_uconst 0x48]
	.dwattr DW$67, DW_AT_accessibility(DW_ACCESS_public)
DW$68	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$68, DW_AT_name("CANMIL_UL"), DW_AT_symbol_name("_CANMIL_UL")
	.dwattr DW$68, DW_AT_data_member_location[DW_OP_plus_uconst 0x4c]
	.dwattr DW$68, DW_AT_accessibility(DW_ACCESS_public)
DW$69	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$69, DW_AT_name("CANOPC_UL"), DW_AT_symbol_name("_CANOPC_UL")
	.dwattr DW$69, DW_AT_data_member_location[DW_OP_plus_uconst 0x50]
	.dwattr DW$69, DW_AT_accessibility(DW_ACCESS_public)
DW$70	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1047)
	.dwattr DW$70, DW_AT_name("CANTIOC_UN"), DW_AT_symbol_name("_CANTIOC_UN")
	.dwattr DW$70, DW_AT_data_member_location[DW_OP_plus_uconst 0x54]
	.dwattr DW$70, DW_AT_accessibility(DW_ACCESS_public)
DW$71	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1049)
	.dwattr DW$71, DW_AT_name("CANRIOC_UN"), DW_AT_symbol_name("_CANRIOC_UN")
	.dwattr DW$71, DW_AT_data_member_location[DW_OP_plus_uconst 0x58]
	.dwattr DW$71, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1050

DWT$8	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned short")
	.dwattr DWT$8, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$8, DW_AT_byte_size(0x02)
DWT$1039	.dwtag  DW_TAG_typedef, DW_AT_name("BITFIELD"), DW_AT_type(*DWT$10)
	.dwattr DWT$1039, DW_AT_language(DW_LANG_C)
DWT$1025	.dwtag  DW_TAG_typedef, DW_AT_name("CANMSGOBJCONFIG_ST"), DW_AT_type(*DWT$1024)
	.dwattr DWT$1025, DW_AT_language(DW_LANG_C)
DWT$1029	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1028)
DWT$1035	.dwtag  DW_TAG_typedef, DW_AT_name("DIAGRESPONSETG_ST"), DW_AT_type(*DWT$1034)
	.dwattr DWT$1035, DW_AT_language(DW_LANG_C)

DWT$1044	.dwtag  DW_TAG_union_type
	.dwattr DWT$1044, DW_AT_byte_size(0x02)
DW$72	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1031)
	.dwattr DW$72, DW_AT_name("CANMC_UW"), DW_AT_symbol_name("_CANMC_UW")
	.dwattr DW$72, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$72, DW_AT_accessibility(DW_ACCESS_public)
DW$73	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1043)
	.dwattr DW$73, DW_AT_name("CANMC_ST"), DW_AT_symbol_name("_CANMC_ST")
	.dwattr DW$73, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$73, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1044


DWT$1045	.dwtag  DW_TAG_union_type
	.dwattr DWT$1045, DW_AT_byte_size(0x04)
DW$74	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1031)
	.dwattr DW$74, DW_AT_name("CANES_UL"), DW_AT_symbol_name("_CANES_UL")
	.dwattr DW$74, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$74, DW_AT_accessibility(DW_ACCESS_public)
DW$75	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1040)
	.dwattr DW$75, DW_AT_name("CANES_ST"), DW_AT_symbol_name("_CANES_ST")
	.dwattr DW$75, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$75, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1045


DWT$1047	.dwtag  DW_TAG_union_type
	.dwattr DWT$1047, DW_AT_byte_size(0x04)
DW$76	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1031)
	.dwattr DW$76, DW_AT_name("CANTIOC_UL"), DW_AT_symbol_name("_CANTIOC_UL")
	.dwattr DW$76, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$76, DW_AT_accessibility(DW_ACCESS_public)
DW$77	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1046)
	.dwattr DW$77, DW_AT_name("CANTIOC_ST"), DW_AT_symbol_name("_CANTIOC_ST")
	.dwattr DW$77, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$77, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1047


DWT$1049	.dwtag  DW_TAG_union_type
	.dwattr DWT$1049, DW_AT_byte_size(0x04)
DW$78	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1031)
	.dwattr DW$78, DW_AT_name("CANRIOC_UL"), DW_AT_symbol_name("_CANRIOC_UL")
	.dwattr DW$78, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$78, DW_AT_accessibility(DW_ACCESS_public)
DW$79	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1048)
	.dwattr DW$79, DW_AT_name("CANRIOC_ST"), DW_AT_symbol_name("_CANRIOC_ST")
	.dwattr DW$79, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$79, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1049

DWT$10	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned int")
	.dwattr DWT$10, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$10, DW_AT_byte_size(0x04)

DWT$1024	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1024, DW_AT_name("_CANMSGOBJCONFIG")
	.dwattr DWT$1024, DW_AT_byte_size(0x0c)
DW$80	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$80, DW_AT_name("MsgObjectNbr_UB"), DW_AT_symbol_name("_MsgObjectNbr_UB")
	.dwattr DW$80, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$80, DW_AT_accessibility(DW_ACCESS_public)
DW$81	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$81, DW_AT_name("MsgObjState_UB"), DW_AT_symbol_name("_MsgObjState_UB")
	.dwattr DW$81, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$81, DW_AT_accessibility(DW_ACCESS_public)
DW$82	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$82, DW_AT_name("MsgObjDirection_UB"), DW_AT_symbol_name("_MsgObjDirection_UB")
	.dwattr DW$82, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$82, DW_AT_accessibility(DW_ACCESS_public)
DW$83	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$83, DW_AT_name("IDLength_UB"), DW_AT_symbol_name("_IDLength_UB")
	.dwattr DW$83, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$83, DW_AT_accessibility(DW_ACCESS_public)
DW$84	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$84, DW_AT_name("CanIdentifier_UL"), DW_AT_symbol_name("_CanIdentifier_UL")
	.dwattr DW$84, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$84, DW_AT_accessibility(DW_ACCESS_public)
DW$85	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$85, DW_AT_name("AcceptanceMask_UL"), DW_AT_symbol_name("_AcceptanceMask_UL")
	.dwattr DW$85, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$85, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1024

DWT$1028	.dwtag  DW_TAG_typedef, DW_AT_name("CANMSGOBJINFO_ST"), DW_AT_type(*DWT$1027)
	.dwattr DWT$1028, DW_AT_language(DW_LANG_C)

DWT$1034	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1034, DW_AT_name("_DIAGRESPONSETG_ST")
	.dwattr DWT$1034, DW_AT_byte_size(0x0a)
DW$86	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$86, DW_AT_name("SendMailBox_UB"), DW_AT_symbol_name("_SendMailBox_UB")
	.dwattr DW$86, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$86, DW_AT_accessibility(DW_ACCESS_public)
DW$87	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$87, DW_AT_name("Reserve_UB"), DW_AT_symbol_name("_Reserve_UB")
	.dwattr DW$87, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$87, DW_AT_accessibility(DW_ACCESS_public)
DW$88	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1033)
	.dwattr DW$88, DW_AT_name("Data_AUB"), DW_AT_symbol_name("_Data_AUB")
	.dwattr DW$88, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$88, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1034


DWT$1043	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1043, DW_AT_byte_size(0x02)
DW$89	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$89, DW_AT_name("LNTC_B1"), DW_AT_symbol_name("_LNTC_B1")
	.dwattr DW$89, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x01)
	.dwattr DW$89, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$89, DW_AT_accessibility(DW_ACCESS_public)
DW$90	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$90, DW_AT_name("LNTM_B1"), DW_AT_symbol_name("_LNTM_B1")
	.dwattr DW$90, DW_AT_bit_offset(0x01), DW_AT_bit_size(0x01)
	.dwattr DW$90, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$90, DW_AT_accessibility(DW_ACCESS_public)
DW$91	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$91, DW_AT_name("SCM_B1"), DW_AT_symbol_name("_SCM_B1")
	.dwattr DW$91, DW_AT_bit_offset(0x02), DW_AT_bit_size(0x01)
	.dwattr DW$91, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$91, DW_AT_accessibility(DW_ACCESS_public)
DW$92	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$92, DW_AT_name("CCR_B1"), DW_AT_symbol_name("_CCR_B1")
	.dwattr DW$92, DW_AT_bit_offset(0x03), DW_AT_bit_size(0x01)
	.dwattr DW$92, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$92, DW_AT_accessibility(DW_ACCESS_public)
DW$93	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$93, DW_AT_name("PDR_B1"), DW_AT_symbol_name("_PDR_B1")
	.dwattr DW$93, DW_AT_bit_offset(0x04), DW_AT_bit_size(0x01)
	.dwattr DW$93, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$93, DW_AT_accessibility(DW_ACCESS_public)
DW$94	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$94, DW_AT_name("DBO_B1"), DW_AT_symbol_name("_DBO_B1")
	.dwattr DW$94, DW_AT_bit_offset(0x05), DW_AT_bit_size(0x01)
	.dwattr DW$94, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$94, DW_AT_accessibility(DW_ACCESS_public)
DW$95	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$95, DW_AT_name("WUBA_B1"), DW_AT_symbol_name("_WUBA_B1")
	.dwattr DW$95, DW_AT_bit_offset(0x06), DW_AT_bit_size(0x01)
	.dwattr DW$95, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$95, DW_AT_accessibility(DW_ACCESS_public)
DW$96	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$96, DW_AT_name("CDR_B1"), DW_AT_symbol_name("_CDR_B1")
	.dwattr DW$96, DW_AT_bit_offset(0x07), DW_AT_bit_size(0x01)
	.dwattr DW$96, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$96, DW_AT_accessibility(DW_ACCESS_public)
DW$97	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$97, DW_AT_name("ABO_B1"), DW_AT_symbol_name("_ABO_B1")
	.dwattr DW$97, DW_AT_bit_offset(0x08), DW_AT_bit_size(0x01)
	.dwattr DW$97, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$97, DW_AT_accessibility(DW_ACCESS_public)
DW$98	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$98, DW_AT_name("STM_B1"), DW_AT_symbol_name("_STM_B1")
	.dwattr DW$98, DW_AT_bit_offset(0x09), DW_AT_bit_size(0x01)
	.dwattr DW$98, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$98, DW_AT_accessibility(DW_ACCESS_public)
DW$99	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$99, DW_AT_name("SRES_B1"), DW_AT_symbol_name("_SRES_B1")
	.dwattr DW$99, DW_AT_bit_offset(0x0a), DW_AT_bit_size(0x01)
	.dwattr DW$99, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$99, DW_AT_accessibility(DW_ACCESS_public)
DW$100	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$100, DW_AT_name("WBNR_B5"), DW_AT_symbol_name("_WBNR_B5")
	.dwattr DW$100, DW_AT_bit_offset(0x0b), DW_AT_bit_size(0x05)
	.dwattr DW$100, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$100, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1043


DWT$1046	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1046, DW_AT_byte_size(0x04)
DW$101	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$101, DW_AT_name("Notused1"), DW_AT_symbol_name("_Notused1")
	.dwattr DW$101, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x1c)
	.dwattr DW$101, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$101, DW_AT_accessibility(DW_ACCESS_public)
DW$102	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$102, DW_AT_name("TXFUNC_B1"), DW_AT_symbol_name("_TXFUNC_B1")
	.dwattr DW$102, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$102, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$102, DW_AT_accessibility(DW_ACCESS_public)
DW$103	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$103, DW_AT_name("TXDIR_B1"), DW_AT_symbol_name("_TXDIR_B1")
	.dwattr DW$103, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$103, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$103, DW_AT_accessibility(DW_ACCESS_public)
DW$104	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$104, DW_AT_name("TXOUT_B1"), DW_AT_symbol_name("_TXOUT_B1")
	.dwattr DW$104, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$104, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$104, DW_AT_accessibility(DW_ACCESS_public)
DW$105	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$105, DW_AT_name("TXIN_B1"), DW_AT_symbol_name("_TXIN_B1")
	.dwattr DW$105, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$105, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$105, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1046


DWT$1048	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1048, DW_AT_byte_size(0x04)
DW$106	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$106, DW_AT_name("Notused1"), DW_AT_symbol_name("_Notused1")
	.dwattr DW$106, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x1c)
	.dwattr DW$106, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$106, DW_AT_accessibility(DW_ACCESS_public)
DW$107	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$107, DW_AT_name("RXFUNC_B1"), DW_AT_symbol_name("_RXFUNC_B1")
	.dwattr DW$107, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$107, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$107, DW_AT_accessibility(DW_ACCESS_public)
DW$108	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$108, DW_AT_name("RXDIR_B1"), DW_AT_symbol_name("_RXDIR_B1")
	.dwattr DW$108, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$108, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$108, DW_AT_accessibility(DW_ACCESS_public)
DW$109	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$109, DW_AT_name("RXOUT_B1"), DW_AT_symbol_name("_RXOUT_B1")
	.dwattr DW$109, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$109, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$109, DW_AT_accessibility(DW_ACCESS_public)
DW$110	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1039)
	.dwattr DW$110, DW_AT_name("RXIN_B1"), DW_AT_symbol_name("_RXIN_B1")
	.dwattr DW$110, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$110, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$110, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1048


DWT$1033	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1033, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1033, DW_AT_byte_size(0x08)
DW$111	.dwtag  DW_TAG_subrange_type
	.dwattr DW$111, DW_AT_upper_bound(0x07)
	.dwendtag DWT$1033


DWT$1027	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1027, DW_AT_name("_CANMSGOBJINFO")
	.dwattr DWT$1027, DW_AT_byte_size(0x04)
DW$112	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$112, DW_AT_name("MsgObjectNbr_UB"), DW_AT_symbol_name("_MsgObjectNbr_UB")
	.dwattr DW$112, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$112, DW_AT_accessibility(DW_ACCESS_public)
DW$113	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$113, DW_AT_name("ChannelNbr_UB"), DW_AT_symbol_name("_ChannelNbr_UB")
	.dwattr DW$113, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$113, DW_AT_accessibility(DW_ACCESS_public)
DW$114	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$114, DW_AT_name("AddIdByteInfo_UB"), DW_AT_symbol_name("_AddIdByteInfo_UB")
	.dwattr DW$114, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$114, DW_AT_accessibility(DW_ACCESS_public)
DW$115	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$115, DW_AT_name("AddIdentifier_UB"), DW_AT_symbol_name("_AddIdentifier_UB")
	.dwattr DW$115, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$115, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1027


	.dwattr DW$4, DW_AT_external(0x01)
	.dwattr DWCU, DW_AT_language(DW_LANG_C)

;***************************************************************
;* DWARF CIE ENTRIES                                           *
;***************************************************************

DW$CIE	.dwcie 1, 26
	.dwcfa	0x0c, 13, 0
	.dwcfa	0x07, 0
	.dwcfa	0x07, 1
	.dwcfa	0x07, 2
	.dwcfa	0x07, 3
	.dwcfa	0x08, 4
	.dwcfa	0x08, 5
	.dwcfa	0x08, 6
	.dwcfa	0x08, 7
	.dwcfa	0x08, 8
	.dwcfa	0x08, 9
	.dwcfa	0x08, 10
	.dwcfa	0x08, 11
	.dwcfa	0x07, 12
	.dwcfa	0x07, 13
	.dwcfa	0x07, 14
	.dwcfa	0x07, 15
	.dwcfa	0x07, 16
	.dwcfa	0x07, 17
	.dwcfa	0x07, 18
	.dwcfa	0x07, 19
	.dwcfa	0x07, 20
	.dwcfa	0x07, 21
	.dwcfa	0x07, 22
	.dwcfa	0x07, 23
	.dwcfa	0x07, 24
	.dwcfa	0x07, 25
	.dwcfa	0x07, 26

;***************************************************************
;* DWARF REGISTER MAP                                          *
;***************************************************************

DW$116	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$116, DW_AT_location[DW_OP_reg0]
DW$117	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$117, DW_AT_location[DW_OP_reg1]
DW$118	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$118, DW_AT_location[DW_OP_reg2]
DW$119	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$119, DW_AT_location[DW_OP_reg3]
DW$120	.dwtag  DW_TAG_assign_register, DW_AT_name("V1")
	.dwattr DW$120, DW_AT_location[DW_OP_reg4]
DW$121	.dwtag  DW_TAG_assign_register, DW_AT_name("V2")
	.dwattr DW$121, DW_AT_location[DW_OP_reg5]
DW$122	.dwtag  DW_TAG_assign_register, DW_AT_name("V3")
	.dwattr DW$122, DW_AT_location[DW_OP_reg6]
DW$123	.dwtag  DW_TAG_assign_register, DW_AT_name("V4")
	.dwattr DW$123, DW_AT_location[DW_OP_reg7]
DW$124	.dwtag  DW_TAG_assign_register, DW_AT_name("V5")
	.dwattr DW$124, DW_AT_location[DW_OP_reg8]
DW$125	.dwtag  DW_TAG_assign_register, DW_AT_name("V6")
	.dwattr DW$125, DW_AT_location[DW_OP_reg9]
DW$126	.dwtag  DW_TAG_assign_register, DW_AT_name("V7")
	.dwattr DW$126, DW_AT_location[DW_OP_reg10]
DW$127	.dwtag  DW_TAG_assign_register, DW_AT_name("V8")
	.dwattr DW$127, DW_AT_location[DW_OP_reg11]
DW$128	.dwtag  DW_TAG_assign_register, DW_AT_name("V9")
	.dwattr DW$128, DW_AT_location[DW_OP_reg12]
DW$129	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$129, DW_AT_location[DW_OP_reg13]
DW$130	.dwtag  DW_TAG_assign_register, DW_AT_name("LR")
	.dwattr DW$130, DW_AT_location[DW_OP_reg14]
DW$131	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$131, DW_AT_location[DW_OP_reg15]
DW$132	.dwtag  DW_TAG_assign_register, DW_AT_name("C0")
	.dwattr DW$132, DW_AT_location[DW_OP_reg16]
DW$133	.dwtag  DW_TAG_assign_register, DW_AT_name("C1")
	.dwattr DW$133, DW_AT_location[DW_OP_reg17]
DW$134	.dwtag  DW_TAG_assign_register, DW_AT_name("C2")
	.dwattr DW$134, DW_AT_location[DW_OP_reg18]
DW$135	.dwtag  DW_TAG_assign_register, DW_AT_name("C3")
	.dwattr DW$135, DW_AT_location[DW_OP_reg19]
DW$136	.dwtag  DW_TAG_assign_register, DW_AT_name("C4")
	.dwattr DW$136, DW_AT_location[DW_OP_reg20]
DW$137	.dwtag  DW_TAG_assign_register, DW_AT_name("C5")
	.dwattr DW$137, DW_AT_location[DW_OP_reg21]
DW$138	.dwtag  DW_TAG_assign_register, DW_AT_name("C6")
	.dwattr DW$138, DW_AT_location[DW_OP_reg22]
DW$139	.dwtag  DW_TAG_assign_register, DW_AT_name("C7")
	.dwattr DW$139, DW_AT_location[DW_OP_reg23]
DW$140	.dwtag  DW_TAG_assign_register, DW_AT_name("AP")
	.dwattr DW$140, DW_AT_location[DW_OP_reg24]
DW$141	.dwtag  DW_TAG_assign_register, DW_AT_name("SR")
	.dwattr DW$141, DW_AT_location[DW_OP_reg25]
DW$142	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$142, DW_AT_location[DW_OP_reg26]
	.dwendtag DWCU

