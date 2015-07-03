;******************************************************************************
;* TMS470 C/C++ Codegen                                       PC Version 2.71 *
;* Date/Time created: Fri Dec 09 08:43:05 2011                                *
;******************************************************************************
	.state16

DWCU	.dwtag  DW_TAG_compile_unit
	.dwattr DWCU, DW_AT_name("ADLATUS_DummyMain.c")
	.dwattr DWCU, DW_AT_producer("TMS470 C/C++ Codegen PC Version 2.71 Copyright (c) 1996-2008 Texas Instruments Incorporated")
	.dwattr DWCU, DW_AT_stmt_list(0x00)
	.dwattr DWCU, DW_AT_TI_VERSION(0x01)
	.global	_FlashParam
	.bss	_FlashParam,48,4
DW$1	.dwtag  DW_TAG_variable, DW_AT_name("FlashParam"), DW_AT_symbol_name("_FlashParam")
	.dwattr DW$1, DW_AT_type(*DWT$1037)
	.dwattr DW$1, DW_AT_location[DW_OP_addr _FlashParam]
	.dwattr DW$1, DW_AT_external(0x01)
;	C:\CCStudio_v3.3\tms470\cgtools_271\bin\opt470.exe -v1 -q -s -O2 -e r:/10_his/04_lst/ADLATUS_DummyMain.if r:/10_his/04_lst/ADLATUS_DummyMain.opt -w r:/10_his/04_lst 

	.sect	".text:v$0"
	.clink
	.global	_main

DW$2	.dwtag  DW_TAG_subprogram, DW_AT_name("main"), DW_AT_symbol_name("_main")
	.dwattr DW$2, DW_AT_veneer(0x01)
	.dwattr DW$2, DW_AT_low_pc(_main)
	.dwattr DW$2, DW_AT_high_pc(0x00)
	.dwattr DW$2, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _main                                                    *
;*****************************************************************************
_main:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $main
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$2



	.sect	".text"
	.clink
	.global	$main

DW$3	.dwtag  DW_TAG_subprogram, DW_AT_name("main"), DW_AT_symbol_name("$main")
	.dwattr DW$3, DW_AT_low_pc($main)
	.dwattr DW$3, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_DummyMain.c",135,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 134 | void main (void)                                                       
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: main                                                       *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,V2,V3,V4,V9,SP,LR,SR                 *
;*   Regs Used         : A1,A2,A3,A4,V1,V2,V3,V4,V9,SP,LR,SR                 *
;*   Local Frame Size  : 0 Args + 0 Auto + 20 Save = 20 byte                 *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$main:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 136 | tHis_Header  *pHisHeader;                                              
; 137 | void        (*_FlashInit)    (tFlashParam*);                           
; 138 | void         (*_FlashWrite)  (tFlashParam*);                           
; 139 | void         (*_FlashErase)  (tFlashParam*);                           
; 140 | void         (*_FlashDeinit) (tFlashParam*);                           
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
        PUSH      {V1, V2, V3, V4, LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 7, 2
	.dwcfa	0x0e, 12
	.dwcfa	0x80, 6, 3
	.dwcfa	0x0e, 16
	.dwcfa	0x80, 5, 4
	.dwcfa	0x0e, 20
	.dwcfa	0x80, 4, 5
	.dwcfa	0x0e, 20
;* V4    assigned to C$1
DW$4	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$4, DW_AT_type(*DWT$1041)
	.dwattr DW$4, DW_AT_location[DW_OP_reg7]
;* V2    assigned to C$2
DW$5	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$5, DW_AT_type(*DWT$10)
	.dwattr DW$5, DW_AT_location[DW_OP_reg5]
;* V2    assigned to _pHisHeader
DW$6	.dwtag  DW_TAG_variable, DW_AT_name("pHisHeader"), DW_AT_symbol_name("_pHisHeader")
	.dwattr DW$6, DW_AT_type(*DWT$1046)
	.dwattr DW$6, DW_AT_location[DW_OP_reg5]
;** 145	-----------------------    pHisHeader = (struct $$fake1 *)(C$2 = 4198400u);
	.dwpsn	"ADLATUS_DummyMain.c",145,3
;----------------------------------------------------------------------
; 145 | pHisHeader = (tHis_Header*) d_CCadrinfo_FlashFctRamStartAdr; /*l_int !e
;     | 923 */                                                                 
; 146 | _FlashInit = pHisHeader->pfnFlashInit;                                 
;----------------------------------------------------------------------
        LDR       V2, CON1              ; |145| 
;** 148	-----------------------    C$1 = &FlashParam;
	.dwpsn	"ADLATUS_DummyMain.c",148,3
;----------------------------------------------------------------------
; 148 | _FlashInit (&FlashParam);                                              
; 150 | pHisHeader  = (tHis_Header*) d_CCadrinfo_FlashFctRamStartAdr; /*l_int !
;     | e923 */                                                                
; 151 | _FlashErase = pHisHeader->pfnFlashErase;                               
;----------------------------------------------------------------------
        LDR       V4, CON2              ; |148| 
;** 148	-----------------------    (*pHisHeader->pfnFlashInit)(C$1);
        MOV       A1, V4
        LDR       V1, [V2, #4]          ; |148| 
        MOV       V3, #1                ; |148| 
        MOV       LR, V3
        LDR       A2, CON3
        ADD       LR, PC
        BX        A2
        ; |148| 
;** 153	-----------------------    (*pHisHeader->pfnFlashErase)(C$1);
	.dwpsn	"ADLATUS_DummyMain.c",153,3
;----------------------------------------------------------------------
; 153 | _FlashErase(&FlashParam);                                              
; 155 | pHisHeader  = (tHis_Header*) d_CCadrinfo_FlashFctRamStartAdr; /*l_int !
;     | e923 */                                                                
; 156 | _FlashWrite = pHisHeader->pfnFlashWrite;                               
;----------------------------------------------------------------------
        MOV       A1, V4
        LDR       V1, [V2, #12]         ; |153| 
        MOV       LR, V3
        LDR       A2, CON4
        ADD       LR, PC
        BX        A2
        ; |153| 
;** 158	-----------------------    (*pHisHeader->pfnFlashWrite)(C$1);
	.dwpsn	"ADLATUS_DummyMain.c",158,3
;----------------------------------------------------------------------
; 158 | _FlashWrite (&FlashParam);                                             
; 163 | pHisHeader = (tHis_Header*) d_CCadrinfo_FlashFctRamStartAdr; /*l_int !e
;     | 923 */                                                                 
; 164 | _FlashDeinit = pHisHeader->pfnFlashDeinit;                             
;----------------------------------------------------------------------
        MOV       A1, V4
        LDR       V1, [V2, #16]         ; |158| 
        MOV       LR, V3
        LDR       A2, CON5
        ADD       LR, PC
        BX        A2
        ; |158| 
;** 166	-----------------------    (*pHisHeader->pfnFlashDeinit)(C$1);
	.dwpsn	"ADLATUS_DummyMain.c",166,3
;----------------------------------------------------------------------
; 166 | _FlashDeinit (&FlashParam);                                            
;----------------------------------------------------------------------
        MOV       A1, V4
        LDR       V1, [V2, #8]          ; |166| 
        MOV       LR, V3
        LDR       A2, CON6
        ADD       LR, PC
        BX        A2
        ; |166| 
;** 166	-----------------------    return;
	.dwpsn	"ADLATUS_DummyMain.c",168,1
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}
	.dwendentry
	.dwendtag DW$3



;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON1:	.field  	4198400,32
	.align	4
CON2:	.field  	_FlashParam,32
	.align	4
CON3:	.field  	IND$CALL+1,32
	.align	4
CON4:	.field  	IND$CALL+1,32
	.align	4
CON5:	.field  	IND$CALL+1,32
	.align	4
CON6:	.field  	IND$CALL+1,32
;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	IND$CALL

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
DWT$10	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned int")
	.dwattr DWT$10, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$10, DW_AT_byte_size(0x04)

DWT$1018	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1018, DW_AT_language(DW_LANG_C)
DWT$1037	.dwtag  DW_TAG_typedef, DW_AT_name("tFlashParam"), DW_AT_type(*DWT$1036)
	.dwattr DWT$1037, DW_AT_language(DW_LANG_C)
DWT$1041	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1036)
	.dwattr DWT$1041, DW_AT_address_class(0x20)
DWT$1046	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1045)
	.dwattr DWT$1046, DW_AT_address_class(0x20)

DWT$1036	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1036, DW_AT_byte_size(0x30)
DW$7	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1019)
	.dwattr DW$7, DW_AT_name("patchlevel"), DW_AT_symbol_name("_patchlevel")
	.dwattr DW$7, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$7, DW_AT_accessibility(DW_ACCESS_public)
DW$8	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1020)
	.dwattr DW$8, DW_AT_name("minornumber"), DW_AT_symbol_name("_minornumber")
	.dwattr DW$8, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$8, DW_AT_accessibility(DW_ACCESS_public)
DW$9	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1021)
	.dwattr DW$9, DW_AT_name("majornumber"), DW_AT_symbol_name("_majornumber")
	.dwattr DW$9, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$9, DW_AT_accessibility(DW_ACCESS_public)
DW$10	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$10, DW_AT_name("reserved1"), DW_AT_symbol_name("_reserved1")
	.dwattr DW$10, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$10, DW_AT_accessibility(DW_ACCESS_public)
DW$11	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$11, DW_AT_name("errorcode"), DW_AT_symbol_name("_errorcode")
	.dwattr DW$11, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$11, DW_AT_accessibility(DW_ACCESS_public)
DW$12	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$12, DW_AT_name("reserved2"), DW_AT_symbol_name("_reserved2")
	.dwattr DW$12, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr DW$12, DW_AT_accessibility(DW_ACCESS_public)
DW$13	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1023)
	.dwattr DW$13, DW_AT_name("address"), DW_AT_symbol_name("_address")
	.dwattr DW$13, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$13, DW_AT_accessibility(DW_ACCESS_public)
DW$14	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1024)
	.dwattr DW$14, DW_AT_name("length"), DW_AT_symbol_name("_length")
	.dwattr DW$14, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$14, DW_AT_accessibility(DW_ACCESS_public)
DW$15	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1026)
	.dwattr DW$15, DW_AT_name("data"), DW_AT_symbol_name("_data")
	.dwattr DW$15, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$15, DW_AT_accessibility(DW_ACCESS_public)
DW$16	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1028)
	.dwattr DW$16, DW_AT_name("wdTriggerFct"), DW_AT_symbol_name("_wdTriggerFct")
	.dwattr DW$16, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$16, DW_AT_accessibility(DW_ACCESS_public)
DW$17	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1029)
	.dwattr DW$17, DW_AT_name("intendedData"), DW_AT_symbol_name("_intendedData")
	.dwattr DW$17, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$17, DW_AT_accessibility(DW_ACCESS_public)
DW$18	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1029)
	.dwattr DW$18, DW_AT_name("actualData"), DW_AT_symbol_name("_actualData")
	.dwattr DW$18, DW_AT_data_member_location[DW_OP_plus_uconst 0x1a]
	.dwattr DW$18, DW_AT_accessibility(DW_ACCESS_public)
DW$19	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1023)
	.dwattr DW$19, DW_AT_name("errorAddress"), DW_AT_symbol_name("_errorAddress")
	.dwattr DW$19, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$19, DW_AT_accessibility(DW_ACCESS_public)
DW$20	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$20, DW_AT_name("Command_UB"), DW_AT_symbol_name("_Command_UB")
	.dwattr DW$20, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr DW$20, DW_AT_accessibility(DW_ACCESS_public)
DW$21	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1031)
	.dwattr DW$21, DW_AT_name("Direction_UB"), DW_AT_symbol_name("_Direction_UB")
	.dwattr DW$21, DW_AT_data_member_location[DW_OP_plus_uconst 0x21]
	.dwattr DW$21, DW_AT_accessibility(DW_ACCESS_public)
DW$22	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1032)
	.dwattr DW$22, DW_AT_name("Format_UB"), DW_AT_symbol_name("_Format_UB")
	.dwattr DW$22, DW_AT_data_member_location[DW_OP_plus_uconst 0x22]
	.dwattr DW$22, DW_AT_accessibility(DW_ACCESS_public)
DW$23	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1033)
	.dwattr DW$23, DW_AT_name("Millisec_UB"), DW_AT_symbol_name("_Millisec_UB")
	.dwattr DW$23, DW_AT_data_member_location[DW_OP_plus_uconst 0x23]
	.dwattr DW$23, DW_AT_accessibility(DW_ACCESS_public)
DW$24	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1034)
	.dwattr DW$24, DW_AT_name("StartSector_US"), DW_AT_symbol_name("_StartSector_US")
	.dwattr DW$24, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr DW$24, DW_AT_accessibility(DW_ACCESS_public)
DW$25	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1034)
	.dwattr DW$25, DW_AT_name("EndSector_US"), DW_AT_symbol_name("_EndSector_US")
	.dwattr DW$25, DW_AT_data_member_location[DW_OP_plus_uconst 0x26]
	.dwattr DW$25, DW_AT_accessibility(DW_ACCESS_public)
DW$26	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1034)
	.dwattr DW$26, DW_AT_name("NbrOfSectors_US"), DW_AT_symbol_name("_NbrOfSectors_US")
	.dwattr DW$26, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr DW$26, DW_AT_accessibility(DW_ACCESS_public)
DW$27	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1034)
	.dwattr DW$27, DW_AT_name("ActualSector_US"), DW_AT_symbol_name("_ActualSector_US")
	.dwattr DW$27, DW_AT_data_member_location[DW_OP_plus_uconst 0x2a]
	.dwattr DW$27, DW_AT_accessibility(DW_ACCESS_public)
DW$28	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1035)
	.dwattr DW$28, DW_AT_name("Delaytime_UL"), DW_AT_symbol_name("_Delaytime_UL")
	.dwattr DW$28, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr DW$28, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1036

DWT$1045	.dwtag  DW_TAG_typedef, DW_AT_name("tHis_Header"), DW_AT_type(*DWT$1044)
	.dwattr DWT$1045, DW_AT_language(DW_LANG_C)
DWT$6	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned char")
	.dwattr DWT$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr DWT$6, DW_AT_byte_size(0x01)
DWT$1019	.dwtag  DW_TAG_typedef, DW_AT_name("tBugfixVersion"), DW_AT_type(*DWT$6)
	.dwattr DWT$1019, DW_AT_language(DW_LANG_C)
DWT$1020	.dwtag  DW_TAG_typedef, DW_AT_name("tMinorNumber"), DW_AT_type(*DWT$6)
	.dwattr DWT$1020, DW_AT_language(DW_LANG_C)
DWT$1021	.dwtag  DW_TAG_typedef, DW_AT_name("tMajorNumber"), DW_AT_type(*DWT$6)
	.dwattr DWT$1021, DW_AT_language(DW_LANG_C)
DWT$1026	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1025)
	.dwattr DWT$1026, DW_AT_address_class(0x20)

DWT$1029	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1025)
	.dwattr DWT$1029, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1029, DW_AT_byte_size(0x02)
DW$29	.dwtag  DW_TAG_subrange_type
	.dwattr DW$29, DW_AT_upper_bound(0x01)
	.dwendtag DWT$1029

DWT$1030	.dwtag  DW_TAG_typedef, DW_AT_name("tCommand"), DW_AT_type(*DWT$6)
	.dwattr DWT$1030, DW_AT_language(DW_LANG_C)
DWT$1031	.dwtag  DW_TAG_typedef, DW_AT_name("tDirection"), DW_AT_type(*DWT$6)
	.dwattr DWT$1031, DW_AT_language(DW_LANG_C)
DWT$1032	.dwtag  DW_TAG_typedef, DW_AT_name("tFormat"), DW_AT_type(*DWT$6)
	.dwattr DWT$1032, DW_AT_language(DW_LANG_C)
DWT$1033	.dwtag  DW_TAG_typedef, DW_AT_name("tMilTime"), DW_AT_type(*DWT$6)
	.dwattr DWT$1033, DW_AT_language(DW_LANG_C)
DWT$8	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned short")
	.dwattr DWT$8, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$8, DW_AT_byte_size(0x02)
DWT$1022	.dwtag  DW_TAG_typedef, DW_AT_name("tFlashResult"), DW_AT_type(*DWT$8)
	.dwattr DWT$1022, DW_AT_language(DW_LANG_C)
DWT$1034	.dwtag  DW_TAG_typedef, DW_AT_name("tSector"), DW_AT_type(*DWT$8)
	.dwattr DWT$1034, DW_AT_language(DW_LANG_C)
DWT$1023	.dwtag  DW_TAG_typedef, DW_AT_name("tAddress"), DW_AT_type(*DWT$12)
	.dwattr DWT$1023, DW_AT_language(DW_LANG_C)
DWT$1024	.dwtag  DW_TAG_typedef, DW_AT_name("tLength"), DW_AT_type(*DWT$12)
	.dwattr DWT$1024, DW_AT_language(DW_LANG_C)
DWT$1035	.dwtag  DW_TAG_typedef, DW_AT_name("t_Delaytime"), DW_AT_type(*DWT$12)
	.dwattr DWT$1035, DW_AT_language(DW_LANG_C)
DWT$1028	.dwtag  DW_TAG_typedef, DW_AT_name("tWDTriggerFct"), DW_AT_type(*DWT$1027)
	.dwattr DWT$1028, DW_AT_language(DW_LANG_C)

DWT$1044	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1044, DW_AT_byte_size(0x14)
DW$30	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1042)
	.dwattr DW$30, DW_AT_name("ubInterfaceVersion"), DW_AT_symbol_name("_ubInterfaceVersion")
	.dwattr DW$30, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$30, DW_AT_accessibility(DW_ACCESS_public)
DW$31	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1042)
	.dwattr DW$31, DW_AT_name("ubReserverd"), DW_AT_symbol_name("_ubReserverd")
	.dwattr DW$31, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$31, DW_AT_accessibility(DW_ACCESS_public)
DW$32	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1042)
	.dwattr DW$32, DW_AT_name("ubMask"), DW_AT_symbol_name("_ubMask")
	.dwattr DW$32, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$32, DW_AT_accessibility(DW_ACCESS_public)
DW$33	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1042)
	.dwattr DW$33, DW_AT_name("ubMCU"), DW_AT_symbol_name("_ubMCU")
	.dwattr DW$33, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$33, DW_AT_accessibility(DW_ACCESS_public)
DW$34	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1043)
	.dwattr DW$34, DW_AT_name("pfnFlashInit"), DW_AT_symbol_name("_pfnFlashInit")
	.dwattr DW$34, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$34, DW_AT_accessibility(DW_ACCESS_public)
DW$35	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1043)
	.dwattr DW$35, DW_AT_name("pfnFlashDeinit"), DW_AT_symbol_name("_pfnFlashDeinit")
	.dwattr DW$35, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$35, DW_AT_accessibility(DW_ACCESS_public)
DW$36	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1043)
	.dwattr DW$36, DW_AT_name("pfnFlashErase"), DW_AT_symbol_name("_pfnFlashErase")
	.dwattr DW$36, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$36, DW_AT_accessibility(DW_ACCESS_public)
DW$37	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1043)
	.dwattr DW$37, DW_AT_name("pfnFlashWrite"), DW_AT_symbol_name("_pfnFlashWrite")
	.dwattr DW$37, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$37, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1044

DWT$1025	.dwtag  DW_TAG_typedef, DW_AT_name("tData"), DW_AT_type(*DWT$6)
	.dwattr DWT$1025, DW_AT_language(DW_LANG_C)
DWT$1042	.dwtag  DW_TAG_typedef, DW_AT_name("UBYTE"), DW_AT_type(*DWT$6)
	.dwattr DWT$1042, DW_AT_language(DW_LANG_C)
DWT$12	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned long")
	.dwattr DWT$12, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$12, DW_AT_byte_size(0x04)
DWT$1027	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1027, DW_AT_address_class(0x20)
DWT$1043	.dwtag  DW_TAG_typedef, DW_AT_name("tFlashFct"), DW_AT_type(*DWT$1040)
	.dwattr DWT$1043, DW_AT_language(DW_LANG_C)
DWT$1040	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1039)
	.dwattr DWT$1040, DW_AT_address_class(0x20)

DWT$1039	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1039, DW_AT_language(DW_LANG_C)
DW$38	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1038)
	.dwendtag DWT$1039

DWT$1038	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1037)
	.dwattr DWT$1038, DW_AT_address_class(0x20)

	.dwattr DW$3, DW_AT_external(0x01)
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

DW$39	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$39, DW_AT_location[DW_OP_reg0]
DW$40	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$40, DW_AT_location[DW_OP_reg1]
DW$41	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$41, DW_AT_location[DW_OP_reg2]
DW$42	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$42, DW_AT_location[DW_OP_reg3]
DW$43	.dwtag  DW_TAG_assign_register, DW_AT_name("V1")
	.dwattr DW$43, DW_AT_location[DW_OP_reg4]
DW$44	.dwtag  DW_TAG_assign_register, DW_AT_name("V2")
	.dwattr DW$44, DW_AT_location[DW_OP_reg5]
DW$45	.dwtag  DW_TAG_assign_register, DW_AT_name("V3")
	.dwattr DW$45, DW_AT_location[DW_OP_reg6]
DW$46	.dwtag  DW_TAG_assign_register, DW_AT_name("V4")
	.dwattr DW$46, DW_AT_location[DW_OP_reg7]
DW$47	.dwtag  DW_TAG_assign_register, DW_AT_name("V5")
	.dwattr DW$47, DW_AT_location[DW_OP_reg8]
DW$48	.dwtag  DW_TAG_assign_register, DW_AT_name("V6")
	.dwattr DW$48, DW_AT_location[DW_OP_reg9]
DW$49	.dwtag  DW_TAG_assign_register, DW_AT_name("V7")
	.dwattr DW$49, DW_AT_location[DW_OP_reg10]
DW$50	.dwtag  DW_TAG_assign_register, DW_AT_name("V8")
	.dwattr DW$50, DW_AT_location[DW_OP_reg11]
DW$51	.dwtag  DW_TAG_assign_register, DW_AT_name("V9")
	.dwattr DW$51, DW_AT_location[DW_OP_reg12]
DW$52	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$52, DW_AT_location[DW_OP_reg13]
DW$53	.dwtag  DW_TAG_assign_register, DW_AT_name("LR")
	.dwattr DW$53, DW_AT_location[DW_OP_reg14]
DW$54	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$54, DW_AT_location[DW_OP_reg15]
DW$55	.dwtag  DW_TAG_assign_register, DW_AT_name("C0")
	.dwattr DW$55, DW_AT_location[DW_OP_reg16]
DW$56	.dwtag  DW_TAG_assign_register, DW_AT_name("C1")
	.dwattr DW$56, DW_AT_location[DW_OP_reg17]
DW$57	.dwtag  DW_TAG_assign_register, DW_AT_name("C2")
	.dwattr DW$57, DW_AT_location[DW_OP_reg18]
DW$58	.dwtag  DW_TAG_assign_register, DW_AT_name("C3")
	.dwattr DW$58, DW_AT_location[DW_OP_reg19]
DW$59	.dwtag  DW_TAG_assign_register, DW_AT_name("C4")
	.dwattr DW$59, DW_AT_location[DW_OP_reg20]
DW$60	.dwtag  DW_TAG_assign_register, DW_AT_name("C5")
	.dwattr DW$60, DW_AT_location[DW_OP_reg21]
DW$61	.dwtag  DW_TAG_assign_register, DW_AT_name("C6")
	.dwattr DW$61, DW_AT_location[DW_OP_reg22]
DW$62	.dwtag  DW_TAG_assign_register, DW_AT_name("C7")
	.dwattr DW$62, DW_AT_location[DW_OP_reg23]
DW$63	.dwtag  DW_TAG_assign_register, DW_AT_name("AP")
	.dwattr DW$63, DW_AT_location[DW_OP_reg24]
DW$64	.dwtag  DW_TAG_assign_register, DW_AT_name("SR")
	.dwattr DW$64, DW_AT_location[DW_OP_reg25]
DW$65	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$65, DW_AT_location[DW_OP_reg26]
	.dwendtag DWCU

