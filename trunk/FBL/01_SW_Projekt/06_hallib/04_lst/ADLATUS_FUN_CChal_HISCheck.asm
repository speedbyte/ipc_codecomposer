;******************************************************************************
;* TMS470 C/C++ Codegen                                       PC Version 2.71 *
;* Date/Time created: Tue Jan 24 12:32:23 2012                                *
;******************************************************************************
	.state16

DWCU	.dwtag  DW_TAG_compile_unit
	.dwattr DWCU, DW_AT_name("ADLATUS_FUN_CChal_HISCheck.c")
	.dwattr DWCU, DW_AT_producer("TMS470 C/C++ Codegen PC Version 2.71 Copyright (c) 1996-2008 Texas Instruments Incorporated")
	.dwattr DWCU, DW_AT_stmt_list(0x00)
	.dwattr DWCU, DW_AT_TI_VERSION(0x01)
DW$1	.dwtag  DW_TAG_variable, DW_AT_name("C_FlashDelay_UL"), DW_AT_symbol_name("_C_FlashDelay_UL")
	.dwattr DW$1, DW_AT_type(*DWT$1050)
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_variable, DW_AT_name("t_CChal_HalCtrl_ST"), DW_AT_symbol_name("_t_CChal_HalCtrl_ST")
	.dwattr DW$2, DW_AT_type(*DWT$1057)
	.dwattr DW$2, DW_AT_declaration(0x01)
	.dwattr DW$2, DW_AT_external(0x01)
	.global	_FlashParam
	.bss	_FlashParam,48,4
DW$3	.dwtag  DW_TAG_variable, DW_AT_name("FlashParam"), DW_AT_symbol_name("_FlashParam")
	.dwattr DW$3, DW_AT_type(*DWT$1038)
	.dwattr DW$3, DW_AT_location[DW_OP_addr _FlashParam]
	.dwattr DW$3, DW_AT_external(0x01)
;	C:\CCStudio_v3.3\tms470\cgtools_271\bin\opt470.exe -v1 -q -s -O2 -e r:/06_hallib/04_lst/ADLATUS_FUN_CChal_HISCheck.if r:/06_hallib/04_lst/ADLATUS_FUN_CChal_HISCheck.opt -w r:/06_hallib/04_lst 

	.sect	".text:v$0"
	.clink
	.global	_FUN_CChal_HISDriverCheck_UB

DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_HISDriverCheck_UB"), DW_AT_symbol_name("_FUN_CChal_HISDriverCheck_UB")
	.dwattr DW$4, DW_AT_veneer(0x01)
	.dwattr DW$4, DW_AT_low_pc(_FUN_CChal_HISDriverCheck_UB)
	.dwattr DW$4, DW_AT_high_pc(0x00)
	.dwattr DW$4, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_HISDriverCheck_UB                             *
;*****************************************************************************
_FUN_CChal_HISDriverCheck_UB:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CChal_HISDriverCheck_UB
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$4



	.sect	".text"
	.clink
	.global	$FUN_CChal_HISDriverCheck_UB

DW$5	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_HISDriverCheck_UB"), DW_AT_symbol_name("$FUN_CChal_HISDriverCheck_UB")
	.dwattr DW$5, DW_AT_low_pc($FUN_CChal_HISDriverCheck_UB)
	.dwattr DW$5, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_FUN_CChal_HISCheck.c",102,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 101 | UBYTE FUN_CChal_HISDriverCheck_UB ( tHis_Header *t_ExpHisHeader_PST )  
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_HISDriverCheck_UB                                *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,SP,SR                                *
;*   Regs Used         : A1,A2,A3,A4,V1,SP,LR,SR                             *
;*   Local Frame Size  : 0 Args + 0 Auto + 8 Save = 8 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_HISDriverCheck_UB:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
        PUSH      {V1, LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 4, 2
	.dwcfa	0x0e, 8
;* A1    assigned to _t_ExpHisHeader_PST
DW$6	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_ExpHisHeader_PST"), DW_AT_symbol_name("_t_ExpHisHeader_PST")
	.dwattr DW$6, DW_AT_type(*DWT$1045)
	.dwattr DW$6, DW_AT_location[DW_OP_reg0]
;* V1    assigned to C$1
DW$7	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$7, DW_AT_type(*DWT$6)
	.dwattr DW$7, DW_AT_location[DW_OP_reg4]
;* V1    assigned to C$2
DW$8	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$8, DW_AT_type(*DWT$6)
	.dwattr DW$8, DW_AT_location[DW_OP_reg4]
;* A3    assigned to C$3
DW$9	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$9, DW_AT_type(*DWT$1051)
	.dwattr DW$9, DW_AT_location[DW_OP_reg2]
;* A3    assigned to _pHisHeader
DW$10	.dwtag  DW_TAG_variable, DW_AT_name("pHisHeader"), DW_AT_symbol_name("_pHisHeader")
	.dwattr DW$10, DW_AT_type(*DWT$1045)
	.dwattr DW$10, DW_AT_location[DW_OP_reg2]
;* A2    assigned to _t_Result_UB
DW$11	.dwtag  DW_TAG_variable, DW_AT_name("t_Result_UB"), DW_AT_symbol_name("_t_Result_UB")
	.dwattr DW$11, DW_AT_type(*DWT$1018)
	.dwattr DW$11, DW_AT_location[DW_OP_reg1]
;* A1    assigned to _t_ExpHisHeader_PST
DW$12	.dwtag  DW_TAG_variable, DW_AT_name("t_ExpHisHeader_PST"), DW_AT_symbol_name("_t_ExpHisHeader_PST")
	.dwattr DW$12, DW_AT_type(*DWT$1052)
	.dwattr DW$12, DW_AT_location[DW_OP_reg0]
;* A4    assigned to U$20
DW$13	.dwtag  DW_TAG_variable, DW_AT_name("U$20"), DW_AT_symbol_name("U$20")
	.dwattr DW$13, DW_AT_type(*DWT$1018)
	.dwattr DW$13, DW_AT_location[DW_OP_reg3]
;----------------------------------------------------------------------
; 103 | UBYTE       t_Result_UB;                                               
; 104 | tHis_Header *pHisHeader;                                               
; 106 | t_Result_UB = d_CCglo_Ready;                                           
; 108 | pHisHeader = (tHis_Header*) d_CCadrinfo_FlashFctRamStartAdr;   /*l_int
;     | !e923 */                                                               
;----------------------------------------------------------------------
;** 110	-----------------------    C$3 = &FlashParam;
	.dwpsn	"ADLATUS_FUN_CChal_HISCheck.c",110,3
;----------------------------------------------------------------------
; 110 | FlashParam.Delaytime_UL = C_FlashDelay_UL;                             
;----------------------------------------------------------------------
        LDR       A3, CON1              ; |110| 
;** 110	-----------------------    C$3->Delaytime_UL = C_FlashDelay_UL;
        LDR       A2, CON2              ; |110| 
        LDR       A2, [A2, #0]          ; |110| 
        STR       A2, [A3, #44]         ; |110| 
;** 111	-----------------------    C$3->errorAddress = t_CChal_HalCtrl_ST.TimerTicksForOneMilliSecond_UL;
	.dwpsn	"ADLATUS_FUN_CChal_HISCheck.c",111,3
;----------------------------------------------------------------------
; 111 | FlashParam.errorAddress = t_CChal_HalCtrl_ST.TimerTicksForOneMilliSecon
;     | d_UL;                                                                  
;----------------------------------------------------------------------
        LDR       A2, CON3              ; |111| 
        LDR       A2, [A2, #0]          ; |111| 
        STR       A2, [A3, #28]         ; |111| 
;** 115	-----------------------    U$20 = (pHisHeader = (struct $$fake0 *)0x401000u)->ubInterfaceVersion;
	.dwpsn	"ADLATUS_FUN_CChal_HISCheck.c",115,3
;----------------------------------------------------------------------
; 115 | if (((pHisHeader->ubInterfaceVersion == 0xFF) || (pHisHeader->ubInterfa
;     | ceVersion == 0x00)) && \                                               
;----------------------------------------------------------------------
        LDR       A3, CON4              ; |115| 
        LDRB      A4, [A3, #0]          ; |115| 
;** 106	-----------------------    t_Result_UB = 0x80u;
	.dwpsn	"ADLATUS_FUN_CChal_HISCheck.c",106,3
        MOV       A2, #128              ; |106| 
;** 115	-----------------------    if ( U$20 != 255 && U$20 ) goto g3;
	.dwpsn	"ADLATUS_FUN_CChal_HISCheck.c",115,3
;----------------------------------------------------------------------
; 116 | ((pHisHeader->ubMask             == 0xFF) || (pHisHeader->ubMask
;     |       == 0x00)) && \                                                   
; 117 | ((pHisHeader->ubMCU              == 0xFF) || (pHisHeader->ubMCU
;     |       == 0x00))    )                                                   
; 119 | t_Result_UB = (d_CCglo_Error | 0x01);                                  
; 125 | else                                                                   
;----------------------------------------------------------------------
        CMP       A4, #255              ; |115| 
        BEQ       L1                    ; |115| 
        ; |115| 
;* --------------------------------------------------------------------------*
        CMP       A4, #0                ; |115| 
        BNE       L3                    ; |115| 
        ; |115| 
;* --------------------------------------------------------------------------*
L1:    
;** 115	-----------------------    if ( (C$2 = pHisHeader->ubMask) != 255 && C$2 ) goto g3;
        LDRB      V1, [A3, #2]          ; |115| 
        CMP       V1, #255              ; |115| 
        BEQ       L2                    ; |115| 
        ; |115| 
;* --------------------------------------------------------------------------*
        CMP       V1, #0                ; |115| 
        BNE       L3                    ; |115| 
        ; |115| 
;* --------------------------------------------------------------------------*
L2:    
;** 115	-----------------------    if ( (C$1 = pHisHeader->ubMCU) == 255 || C$1 == 0u ) goto g5;
        LDRB      V1, [A3, #3]          ; |115| 
        CMP       V1, #255              ; |115| 
        BEQ       L5                    ; |115| 
        ; |115| 
;* --------------------------------------------------------------------------*
        CMP       V1, #0                ; |115| 
        BEQ       L5                    ; |115| 
        ; |115| 
;* --------------------------------------------------------------------------*
L3:    
;**	-----------------------g3:
;** 133	-----------------------    if ( U$20 == t_ExpHisHeader_PST->ubInterfaceVersion && pHisHeader->ubMask == t_ExpHisHeader_PST->ubMask && pHisHeader->ubMCU == t_ExpHisHeader_PST->ubMCU ) goto g6;
	.dwpsn	"ADLATUS_FUN_CChal_HISCheck.c",133,7
;----------------------------------------------------------------------
; 133 | if ( (pHisHeader->ubInterfaceVersion != t_ExpHisHeader_PST->ubInterface
;     | Version) || \                                                          
; 134 |      (pHisHeader->ubMask             != t_ExpHisHeader_PST->ubMask
;     |        ) || \                                                          
; 135 |      (pHisHeader->ubMCU              != t_ExpHisHeader_PST->ubMCU
;     |        )    )                                                          
;----------------------------------------------------------------------
        LDRB      V1, [A1, #0]          ; |133| 
        CMP       A4, V1                ; |133| 
        BNE       L4                    ; |133| 
        ; |133| 
;* --------------------------------------------------------------------------*
        LDRB      A4, [A1, #2]          ; |133| 
        LDRB      V1, [A3, #2]          ; |133| 
        CMP       V1, A4                ; |133| 
        BNE       L4                    ; |133| 
        ; |133| 
;* --------------------------------------------------------------------------*
        LDRB      A1, [A1, #3]          ; |133| 
        LDRB      A3, [A3, #3]          ; |133| 
        CMP       A3, A1                ; |133| 
        BEQ       L6                    ; |133| 
        ; |133| 
;* --------------------------------------------------------------------------*
L4:    
;** 137	-----------------------    return 34;
	.dwpsn	"ADLATUS_FUN_CChal_HISCheck.c",137,7
;----------------------------------------------------------------------
; 137 | t_Result_UB = (d_CCglo_Error | 0x02);                                  
;----------------------------------------------------------------------
        MOV       A1, #34               ; |137| 
        POP       {V1, PC}
;* --------------------------------------------------------------------------*
L5:    
;**	-----------------------g5:
;** 119	-----------------------    t_Result_UB = 33u;
	.dwpsn	"ADLATUS_FUN_CChal_HISCheck.c",119,5
        MOV       A2, #33               ; |119| 
;* --------------------------------------------------------------------------*
L6:    
;**	-----------------------g6:
;** 141	-----------------------    return t_Result_UB;
	.dwpsn	"ADLATUS_FUN_CChal_HISCheck.c",141,3
;----------------------------------------------------------------------
; 141 | return t_Result_UB;                                                    
;----------------------------------------------------------------------
        MOV       A1, A2
	.dwpsn	"ADLATUS_FUN_CChal_HISCheck.c",142,2
	.dwcfa	0x0e, 8
        POP       {V1, PC}
	.dwendentry
	.dwendtag DW$5



;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON1:	.field  	_FlashParam,32
	.align	4
CON2:	.field  	_C_FlashDelay_UL,32
	.align	4
CON3:	.field  	_t_CChal_HalCtrl_ST+16,32
	.align	4
CON4:	.field  	4198400,32
;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	_C_FlashDelay_UL
	.global	_t_CChal_HalCtrl_ST

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
DWT$6	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned char")
	.dwattr DWT$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr DWT$6, DW_AT_byte_size(0x01)
DWT$1018	.dwtag  DW_TAG_typedef, DW_AT_name("UBYTE"), DW_AT_type(*DWT$6)
	.dwattr DWT$1018, DW_AT_language(DW_LANG_C)

DWT$1046	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1046, DW_AT_language(DW_LANG_C)
DW$14	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1045)
	.dwendtag DWT$1046

DWT$1050	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1049)
DWT$1038	.dwtag  DW_TAG_typedef, DW_AT_name("tFlashParam"), DW_AT_type(*DWT$1037)
	.dwattr DWT$1038, DW_AT_language(DW_LANG_C)
DWT$1051	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1037)
	.dwattr DWT$1051, DW_AT_address_class(0x20)
DWT$1045	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1044)
	.dwattr DWT$1045, DW_AT_address_class(0x20)
DWT$1052	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1045)
DWT$1057	.dwtag  DW_TAG_typedef, DW_AT_name("HALCONTROL_ST"), DW_AT_type(*DWT$1056)
	.dwattr DWT$1057, DW_AT_language(DW_LANG_C)
DWT$1049	.dwtag  DW_TAG_typedef, DW_AT_name("ULONG"), DW_AT_type(*DWT$12)
	.dwattr DWT$1049, DW_AT_language(DW_LANG_C)

DWT$1037	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1037, DW_AT_byte_size(0x30)
DW$15	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1019)
	.dwattr DW$15, DW_AT_name("patchlevel"), DW_AT_symbol_name("_patchlevel")
	.dwattr DW$15, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$15, DW_AT_accessibility(DW_ACCESS_public)
DW$16	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1020)
	.dwattr DW$16, DW_AT_name("minornumber"), DW_AT_symbol_name("_minornumber")
	.dwattr DW$16, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$16, DW_AT_accessibility(DW_ACCESS_public)
DW$17	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1021)
	.dwattr DW$17, DW_AT_name("majornumber"), DW_AT_symbol_name("_majornumber")
	.dwattr DW$17, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$17, DW_AT_accessibility(DW_ACCESS_public)
DW$18	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$18, DW_AT_name("reserved1"), DW_AT_symbol_name("_reserved1")
	.dwattr DW$18, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$18, DW_AT_accessibility(DW_ACCESS_public)
DW$19	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$19, DW_AT_name("errorcode"), DW_AT_symbol_name("_errorcode")
	.dwattr DW$19, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$19, DW_AT_accessibility(DW_ACCESS_public)
DW$20	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$20, DW_AT_name("reserved2"), DW_AT_symbol_name("_reserved2")
	.dwattr DW$20, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr DW$20, DW_AT_accessibility(DW_ACCESS_public)
DW$21	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1023)
	.dwattr DW$21, DW_AT_name("address"), DW_AT_symbol_name("_address")
	.dwattr DW$21, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$21, DW_AT_accessibility(DW_ACCESS_public)
DW$22	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1024)
	.dwattr DW$22, DW_AT_name("length"), DW_AT_symbol_name("_length")
	.dwattr DW$22, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$22, DW_AT_accessibility(DW_ACCESS_public)
DW$23	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1026)
	.dwattr DW$23, DW_AT_name("data"), DW_AT_symbol_name("_data")
	.dwattr DW$23, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$23, DW_AT_accessibility(DW_ACCESS_public)
DW$24	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1029)
	.dwattr DW$24, DW_AT_name("wdTriggerFct"), DW_AT_symbol_name("_wdTriggerFct")
	.dwattr DW$24, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$24, DW_AT_accessibility(DW_ACCESS_public)
DW$25	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$25, DW_AT_name("intendedData"), DW_AT_symbol_name("_intendedData")
	.dwattr DW$25, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$25, DW_AT_accessibility(DW_ACCESS_public)
DW$26	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$26, DW_AT_name("actualData"), DW_AT_symbol_name("_actualData")
	.dwattr DW$26, DW_AT_data_member_location[DW_OP_plus_uconst 0x1a]
	.dwattr DW$26, DW_AT_accessibility(DW_ACCESS_public)
DW$27	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1023)
	.dwattr DW$27, DW_AT_name("errorAddress"), DW_AT_symbol_name("_errorAddress")
	.dwattr DW$27, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$27, DW_AT_accessibility(DW_ACCESS_public)
DW$28	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1031)
	.dwattr DW$28, DW_AT_name("Command_UB"), DW_AT_symbol_name("_Command_UB")
	.dwattr DW$28, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr DW$28, DW_AT_accessibility(DW_ACCESS_public)
DW$29	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1032)
	.dwattr DW$29, DW_AT_name("Direction_UB"), DW_AT_symbol_name("_Direction_UB")
	.dwattr DW$29, DW_AT_data_member_location[DW_OP_plus_uconst 0x21]
	.dwattr DW$29, DW_AT_accessibility(DW_ACCESS_public)
DW$30	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1033)
	.dwattr DW$30, DW_AT_name("Format_UB"), DW_AT_symbol_name("_Format_UB")
	.dwattr DW$30, DW_AT_data_member_location[DW_OP_plus_uconst 0x22]
	.dwattr DW$30, DW_AT_accessibility(DW_ACCESS_public)
DW$31	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1034)
	.dwattr DW$31, DW_AT_name("Millisec_UB"), DW_AT_symbol_name("_Millisec_UB")
	.dwattr DW$31, DW_AT_data_member_location[DW_OP_plus_uconst 0x23]
	.dwattr DW$31, DW_AT_accessibility(DW_ACCESS_public)
DW$32	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1035)
	.dwattr DW$32, DW_AT_name("StartSector_US"), DW_AT_symbol_name("_StartSector_US")
	.dwattr DW$32, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr DW$32, DW_AT_accessibility(DW_ACCESS_public)
DW$33	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1035)
	.dwattr DW$33, DW_AT_name("EndSector_US"), DW_AT_symbol_name("_EndSector_US")
	.dwattr DW$33, DW_AT_data_member_location[DW_OP_plus_uconst 0x26]
	.dwattr DW$33, DW_AT_accessibility(DW_ACCESS_public)
DW$34	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1035)
	.dwattr DW$34, DW_AT_name("NbrOfSectors_US"), DW_AT_symbol_name("_NbrOfSectors_US")
	.dwattr DW$34, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr DW$34, DW_AT_accessibility(DW_ACCESS_public)
DW$35	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1035)
	.dwattr DW$35, DW_AT_name("ActualSector_US"), DW_AT_symbol_name("_ActualSector_US")
	.dwattr DW$35, DW_AT_data_member_location[DW_OP_plus_uconst 0x2a]
	.dwattr DW$35, DW_AT_accessibility(DW_ACCESS_public)
DW$36	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1036)
	.dwattr DW$36, DW_AT_name("Delaytime_UL"), DW_AT_symbol_name("_Delaytime_UL")
	.dwattr DW$36, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr DW$36, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1037

DWT$1044	.dwtag  DW_TAG_typedef, DW_AT_name("tHis_Header"), DW_AT_type(*DWT$1043)
	.dwattr DWT$1044, DW_AT_language(DW_LANG_C)

DWT$1056	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1056, DW_AT_name("_HALCONTROL")
	.dwattr DWT$1056, DW_AT_byte_size(0x14)
DW$37	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1049)
	.dwattr DW$37, DW_AT_name("IntClockFrequency_UL"), DW_AT_symbol_name("_IntClockFrequency_UL")
	.dwattr DW$37, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$37, DW_AT_accessibility(DW_ACCESS_public)
DW$38	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1055)
	.dwattr DW$38, DW_AT_name("IntWatchdogTriggerTime_UW"), DW_AT_symbol_name("_IntWatchdogTriggerTime_UW")
	.dwattr DW$38, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$38, DW_AT_accessibility(DW_ACCESS_public)
DW$39	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1055)
	.dwattr DW$39, DW_AT_name("IntWtdTimerReloadValue_UW"), DW_AT_symbol_name("_IntWtdTimerReloadValue_UW")
	.dwattr DW$39, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr DW$39, DW_AT_accessibility(DW_ACCESS_public)
DW$40	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1055)
	.dwattr DW$40, DW_AT_name("HWTimerValue_UW"), DW_AT_symbol_name("_HWTimerValue_UW")
	.dwattr DW$40, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$40, DW_AT_accessibility(DW_ACCESS_public)
DW$41	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1049)
	.dwattr DW$41, DW_AT_name("OldTimerValue_UL"), DW_AT_symbol_name("_OldTimerValue_UL")
	.dwattr DW$41, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$41, DW_AT_accessibility(DW_ACCESS_public)
DW$42	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1049)
	.dwattr DW$42, DW_AT_name("TimerTicksForOneMilliSecond_UL"), DW_AT_symbol_name("_TimerTicksForOneMilliSecond_UL")
	.dwattr DW$42, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$42, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1056

DWT$1019	.dwtag  DW_TAG_typedef, DW_AT_name("tBugfixVersion"), DW_AT_type(*DWT$6)
	.dwattr DWT$1019, DW_AT_language(DW_LANG_C)
DWT$1020	.dwtag  DW_TAG_typedef, DW_AT_name("tMinorNumber"), DW_AT_type(*DWT$6)
	.dwattr DWT$1020, DW_AT_language(DW_LANG_C)
DWT$1021	.dwtag  DW_TAG_typedef, DW_AT_name("tMajorNumber"), DW_AT_type(*DWT$6)
	.dwattr DWT$1021, DW_AT_language(DW_LANG_C)
DWT$1026	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1025)
	.dwattr DWT$1026, DW_AT_address_class(0x20)

DWT$1030	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1025)
	.dwattr DWT$1030, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1030, DW_AT_byte_size(0x02)
DW$43	.dwtag  DW_TAG_subrange_type
	.dwattr DW$43, DW_AT_upper_bound(0x01)
	.dwendtag DWT$1030

DWT$1031	.dwtag  DW_TAG_typedef, DW_AT_name("tCommand"), DW_AT_type(*DWT$6)
	.dwattr DWT$1031, DW_AT_language(DW_LANG_C)
DWT$1032	.dwtag  DW_TAG_typedef, DW_AT_name("tDirection"), DW_AT_type(*DWT$6)
	.dwattr DWT$1032, DW_AT_language(DW_LANG_C)
DWT$1033	.dwtag  DW_TAG_typedef, DW_AT_name("tFormat"), DW_AT_type(*DWT$6)
	.dwattr DWT$1033, DW_AT_language(DW_LANG_C)
DWT$1034	.dwtag  DW_TAG_typedef, DW_AT_name("tMilTime"), DW_AT_type(*DWT$6)
	.dwattr DWT$1034, DW_AT_language(DW_LANG_C)
DWT$8	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned short")
	.dwattr DWT$8, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$8, DW_AT_byte_size(0x02)
DWT$1022	.dwtag  DW_TAG_typedef, DW_AT_name("tFlashResult"), DW_AT_type(*DWT$8)
	.dwattr DWT$1022, DW_AT_language(DW_LANG_C)
DWT$1035	.dwtag  DW_TAG_typedef, DW_AT_name("tSector"), DW_AT_type(*DWT$8)
	.dwattr DWT$1035, DW_AT_language(DW_LANG_C)
DWT$1055	.dwtag  DW_TAG_typedef, DW_AT_name("UWORD"), DW_AT_type(*DWT$8)
	.dwattr DWT$1055, DW_AT_language(DW_LANG_C)
DWT$12	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned long")
	.dwattr DWT$12, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$12, DW_AT_byte_size(0x04)
DWT$1023	.dwtag  DW_TAG_typedef, DW_AT_name("tAddress"), DW_AT_type(*DWT$12)
	.dwattr DWT$1023, DW_AT_language(DW_LANG_C)
DWT$1024	.dwtag  DW_TAG_typedef, DW_AT_name("tLength"), DW_AT_type(*DWT$12)
	.dwattr DWT$1024, DW_AT_language(DW_LANG_C)
DWT$1036	.dwtag  DW_TAG_typedef, DW_AT_name("t_Delaytime"), DW_AT_type(*DWT$12)
	.dwattr DWT$1036, DW_AT_language(DW_LANG_C)
DWT$1029	.dwtag  DW_TAG_typedef, DW_AT_name("tWDTriggerFct"), DW_AT_type(*DWT$1028)
	.dwattr DWT$1029, DW_AT_language(DW_LANG_C)

DWT$1043	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1043, DW_AT_byte_size(0x14)
DW$44	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$44, DW_AT_name("ubInterfaceVersion"), DW_AT_symbol_name("_ubInterfaceVersion")
	.dwattr DW$44, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$44, DW_AT_accessibility(DW_ACCESS_public)
DW$45	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$45, DW_AT_name("ubReserverd"), DW_AT_symbol_name("_ubReserverd")
	.dwattr DW$45, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$45, DW_AT_accessibility(DW_ACCESS_public)
DW$46	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$46, DW_AT_name("ubMask"), DW_AT_symbol_name("_ubMask")
	.dwattr DW$46, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$46, DW_AT_accessibility(DW_ACCESS_public)
DW$47	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$47, DW_AT_name("ubMCU"), DW_AT_symbol_name("_ubMCU")
	.dwattr DW$47, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$47, DW_AT_accessibility(DW_ACCESS_public)
DW$48	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1042)
	.dwattr DW$48, DW_AT_name("pfnFlashInit"), DW_AT_symbol_name("_pfnFlashInit")
	.dwattr DW$48, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$48, DW_AT_accessibility(DW_ACCESS_public)
DW$49	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1042)
	.dwattr DW$49, DW_AT_name("pfnFlashDeinit"), DW_AT_symbol_name("_pfnFlashDeinit")
	.dwattr DW$49, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$49, DW_AT_accessibility(DW_ACCESS_public)
DW$50	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1042)
	.dwattr DW$50, DW_AT_name("pfnFlashErase"), DW_AT_symbol_name("_pfnFlashErase")
	.dwattr DW$50, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$50, DW_AT_accessibility(DW_ACCESS_public)
DW$51	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1042)
	.dwattr DW$51, DW_AT_name("pfnFlashWrite"), DW_AT_symbol_name("_pfnFlashWrite")
	.dwattr DW$51, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$51, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1043

DWT$1025	.dwtag  DW_TAG_typedef, DW_AT_name("tData"), DW_AT_type(*DWT$6)
	.dwattr DWT$1025, DW_AT_language(DW_LANG_C)
DWT$1028	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1027)
	.dwattr DWT$1028, DW_AT_address_class(0x20)
DWT$1042	.dwtag  DW_TAG_typedef, DW_AT_name("tFlashFct"), DW_AT_type(*DWT$1041)
	.dwattr DWT$1042, DW_AT_language(DW_LANG_C)

DWT$1027	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1027, DW_AT_language(DW_LANG_C)
DWT$1041	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1040)
	.dwattr DWT$1041, DW_AT_address_class(0x20)

DWT$1040	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1040, DW_AT_language(DW_LANG_C)
DW$52	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1039)
	.dwendtag DWT$1040

DWT$1039	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1038)
	.dwattr DWT$1039, DW_AT_address_class(0x20)

	.dwattr DW$5, DW_AT_external(0x01)
	.dwattr DW$5, DW_AT_type(*DWT$1018)
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

DW$53	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$53, DW_AT_location[DW_OP_reg0]
DW$54	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$54, DW_AT_location[DW_OP_reg1]
DW$55	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$55, DW_AT_location[DW_OP_reg2]
DW$56	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$56, DW_AT_location[DW_OP_reg3]
DW$57	.dwtag  DW_TAG_assign_register, DW_AT_name("V1")
	.dwattr DW$57, DW_AT_location[DW_OP_reg4]
DW$58	.dwtag  DW_TAG_assign_register, DW_AT_name("V2")
	.dwattr DW$58, DW_AT_location[DW_OP_reg5]
DW$59	.dwtag  DW_TAG_assign_register, DW_AT_name("V3")
	.dwattr DW$59, DW_AT_location[DW_OP_reg6]
DW$60	.dwtag  DW_TAG_assign_register, DW_AT_name("V4")
	.dwattr DW$60, DW_AT_location[DW_OP_reg7]
DW$61	.dwtag  DW_TAG_assign_register, DW_AT_name("V5")
	.dwattr DW$61, DW_AT_location[DW_OP_reg8]
DW$62	.dwtag  DW_TAG_assign_register, DW_AT_name("V6")
	.dwattr DW$62, DW_AT_location[DW_OP_reg9]
DW$63	.dwtag  DW_TAG_assign_register, DW_AT_name("V7")
	.dwattr DW$63, DW_AT_location[DW_OP_reg10]
DW$64	.dwtag  DW_TAG_assign_register, DW_AT_name("V8")
	.dwattr DW$64, DW_AT_location[DW_OP_reg11]
DW$65	.dwtag  DW_TAG_assign_register, DW_AT_name("V9")
	.dwattr DW$65, DW_AT_location[DW_OP_reg12]
DW$66	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$66, DW_AT_location[DW_OP_reg13]
DW$67	.dwtag  DW_TAG_assign_register, DW_AT_name("LR")
	.dwattr DW$67, DW_AT_location[DW_OP_reg14]
DW$68	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$68, DW_AT_location[DW_OP_reg15]
DW$69	.dwtag  DW_TAG_assign_register, DW_AT_name("C0")
	.dwattr DW$69, DW_AT_location[DW_OP_reg16]
DW$70	.dwtag  DW_TAG_assign_register, DW_AT_name("C1")
	.dwattr DW$70, DW_AT_location[DW_OP_reg17]
DW$71	.dwtag  DW_TAG_assign_register, DW_AT_name("C2")
	.dwattr DW$71, DW_AT_location[DW_OP_reg18]
DW$72	.dwtag  DW_TAG_assign_register, DW_AT_name("C3")
	.dwattr DW$72, DW_AT_location[DW_OP_reg19]
DW$73	.dwtag  DW_TAG_assign_register, DW_AT_name("C4")
	.dwattr DW$73, DW_AT_location[DW_OP_reg20]
DW$74	.dwtag  DW_TAG_assign_register, DW_AT_name("C5")
	.dwattr DW$74, DW_AT_location[DW_OP_reg21]
DW$75	.dwtag  DW_TAG_assign_register, DW_AT_name("C6")
	.dwattr DW$75, DW_AT_location[DW_OP_reg22]
DW$76	.dwtag  DW_TAG_assign_register, DW_AT_name("C7")
	.dwattr DW$76, DW_AT_location[DW_OP_reg23]
DW$77	.dwtag  DW_TAG_assign_register, DW_AT_name("AP")
	.dwattr DW$77, DW_AT_location[DW_OP_reg24]
DW$78	.dwtag  DW_TAG_assign_register, DW_AT_name("SR")
	.dwattr DW$78, DW_AT_location[DW_OP_reg25]
DW$79	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$79, DW_AT_location[DW_OP_reg26]
	.dwendtag DWCU

