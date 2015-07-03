;******************************************************************************
;* TMS470 C/C++ Codegen                                       PC Version 2.71 *
;* Date/Time created: Tue Jan 24 12:32:31 2012                                *
;******************************************************************************
	.state16

DWCU	.dwtag  DW_TAG_compile_unit
	.dwattr DWCU, DW_AT_name("ADLATUS_ApplicationInterface.c")
	.dwattr DWCU, DW_AT_producer("TMS470 C/C++ Codegen PC Version 2.71 Copyright (c) 1996-2008 Texas Instruments Incorporated")
	.dwattr DWCU, DW_AT_stmt_list(0x00)
	.dwattr DWCU, DW_AT_TI_VERSION(0x01)
	.global	_gt_CCapplint_FlashRequest_UL
_gt_CCapplint_FlashRequest_UL:	.usect	".REQUEST",4,4
DW$1	.dwtag  DW_TAG_variable, DW_AT_name("gt_CCapplint_FlashRequest_UL"), DW_AT_symbol_name("_gt_CCapplint_FlashRequest_UL")
	.dwattr DW$1, DW_AT_type(*DWT$1021)
	.dwattr DW$1, DW_AT_location[DW_OP_addr _gt_CCapplint_FlashRequest_UL]
	.dwattr DW$1, DW_AT_external(0x01)
;	C:\CCStudio_v3.3\tms470\cgtools_271\bin\opt470.exe -v1 -q -s -O2 -e r:/01_adlatus/04_lst/ADLATUS_ApplicationInterface.if r:/01_adlatus/04_lst/ADLATUS_ApplicationInterface.opt -w r:/01_adlatus/04_lst 

	.sect	".text:v$0"
	.clink
	.global	_FUN_CCapplint_JumpToFSW_V

DW$2	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCapplint_JumpToFSW_V"), DW_AT_symbol_name("_FUN_CCapplint_JumpToFSW_V")
	.dwattr DW$2, DW_AT_veneer(0x01)
	.dwattr DW$2, DW_AT_low_pc(_FUN_CCapplint_JumpToFSW_V)
	.dwattr DW$2, DW_AT_high_pc(0x00)
	.dwattr DW$2, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCapplint_JumpToFSW_V                               *
;*****************************************************************************
_FUN_CCapplint_JumpToFSW_V:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CCapplint_JumpToFSW_V
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$2



	.sect	".text"
	.clink
	.global	$FUN_CCapplint_JumpToFSW_V

DW$3	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCapplint_JumpToFSW_V"), DW_AT_symbol_name("$FUN_CCapplint_JumpToFSW_V")
	.dwattr DW$3, DW_AT_low_pc($FUN_CCapplint_JumpToFSW_V)
	.dwattr DW$3, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_ApplicationInterface.c",142,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 141 | void FUN_CCapplint_JumpToFSW_V (void)                                  
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCapplint_JumpToFSW_V                                  *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,V9,SP,LR,SR                          *
;*   Regs Used         : A1,A2,A3,A4,V1,V9,SP,LR,SR                          *
;*   Local Frame Size  : 0 Args + 0 Auto + 8 Save = 8 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CCapplint_JumpToFSW_V:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 144 | void (*FUN_CCapplint_FswEntry_PFUN) (void);                            
; 149 | FUN_CCapplint_FswEntry_PFUN = (PTR_TO_FKT_VOID_VOID) d_CCadrinfo_AswEnt
;     | ryAddress;  /*l_int !e923 */                                           
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
        PUSH      {V1, LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 4, 2
	.dwcfa	0x0e, 8
;* V1    assigned to _FUN_CCapplint_FswEntry_PFUN
DW$4	.dwtag  DW_TAG_variable, DW_AT_name("FUN_CCapplint_FswEntry_PFUN"), DW_AT_symbol_name("_FUN_CCapplint_FswEntry_PFUN")
	.dwattr DW$4, DW_AT_type(*DWT$1023)
	.dwattr DW$4, DW_AT_location[DW_OP_reg4]
;** 160	-----------------------    (*(FUN_CCapplint_FswEntry_PFUN = (void (*)())0x8000u))();
	.dwpsn	"ADLATUS_ApplicationInterface.c",160,4
;----------------------------------------------------------------------
; 160 | FUN_CCapplint_FswEntry_PFUN ();                                        
;----------------------------------------------------------------------
        MOV       V1, #1
        LSL       V1, V1, #15
        MOV       A1, #1                ; |160| 
        MOV       LR, A1
        LDR       A1, CON1
        ADD       LR, PC
        BX        A1
        ; |160| 
;** 160	-----------------------    return;
	.dwpsn	"ADLATUS_ApplicationInterface.c",162,1
	.dwcfa	0x0e, 8
        POP       {V1, PC}
	.dwendentry
	.dwendtag DW$3




	.sect	".text:v$1"
	.clink
	.global	_FUN_CCapplint_CheckFlashRequest_UB

DW$5	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCapplint_CheckFlashRequest_UB"), DW_AT_symbol_name("_FUN_CCapplint_CheckFlashRequest_UB")
	.dwattr DW$5, DW_AT_veneer(0x01)
	.dwattr DW$5, DW_AT_low_pc(_FUN_CCapplint_CheckFlashRequest_UB)
	.dwattr DW$5, DW_AT_high_pc(0x00)
	.dwattr DW$5, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCapplint_CheckFlashRequest_UB                      *
;*****************************************************************************
_FUN_CCapplint_CheckFlashRequest_UB:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CCapplint_CheckFlashRequest_UB+1, 32
	.state16
	.dwendtag DW$5



	.sect	".text"
	.clink
	.global	$FUN_CCapplint_CheckFlashRequest_UB

DW$6	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCapplint_CheckFlashRequest_UB"), DW_AT_symbol_name("$FUN_CCapplint_CheckFlashRequest_UB")
	.dwattr DW$6, DW_AT_low_pc($FUN_CCapplint_CheckFlashRequest_UB)
	.dwattr DW$6, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_ApplicationInterface.c",183,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 182 | UBYTE FUN_CCapplint_CheckFlashRequest_UB (void)                        
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCapplint_CheckFlashRequest_UB                         *
;*                                                                           *
;*   Regs Modified     : A1,SR                                               *
;*   Regs Used         : A1,SR                                               *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CCapplint_CheckFlashRequest_UB:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 184 | UBYTE t_Result_UB = d_CCglo_NoFSWFlashRequest;                         
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
;** 187	-----------------------    return 0u;
	.dwpsn	"ADLATUS_ApplicationInterface.c",187,3
;----------------------------------------------------------------------
; 187 | return t_Result_UB;                                                    
;----------------------------------------------------------------------
        MOV       A1, #0                ; |187| 
	.dwpsn	"ADLATUS_ApplicationInterface.c",189,1
        BX        LR
	.dwendentry
	.dwendtag DW$6




	.sect	".text:v$2"
	.clink
	.global	_FUN_CCapplint_ResetFlashRequest_V

DW$7	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCapplint_ResetFlashRequest_V"), DW_AT_symbol_name("_FUN_CCapplint_ResetFlashRequest_V")
	.dwattr DW$7, DW_AT_veneer(0x01)
	.dwattr DW$7, DW_AT_low_pc(_FUN_CCapplint_ResetFlashRequest_V)
	.dwattr DW$7, DW_AT_high_pc(0x00)
	.dwattr DW$7, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCapplint_ResetFlashRequest_V                       *
;*****************************************************************************
_FUN_CCapplint_ResetFlashRequest_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CCapplint_ResetFlashRequest_V+1, 32
	.state16
	.dwendtag DW$7



	.sect	".text"
	.clink
	.global	$FUN_CCapplint_ResetFlashRequest_V

DW$8	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCapplint_ResetFlashRequest_V"), DW_AT_symbol_name("$FUN_CCapplint_ResetFlashRequest_V")
	.dwattr DW$8, DW_AT_low_pc($FUN_CCapplint_ResetFlashRequest_V)
	.dwattr DW$8, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_ApplicationInterface.c",209,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 208 | void FUN_CCapplint_ResetFlashRequest_V (void)                          
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCapplint_ResetFlashRequest_V                          *
;*                                                                           *
;*   Regs Modified     : A1,A2,SR                                            *
;*   Regs Used         : A1,A2,SR                                            *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CCapplint_ResetFlashRequest_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;** 210	-----------------------    gt_CCapplint_FlashRequest_UL = 0u;
	.dwpsn	"ADLATUS_ApplicationInterface.c",210,3
;----------------------------------------------------------------------
; 210 | gt_CCapplint_FlashRequest_UL = 0x00000000ul;                           
;----------------------------------------------------------------------
        MOV       A2, #0                ; |210| 
        LDR       A1, CON2              ; |210| 
        STR       A2, [A1, #0]          ; |210| 
;** 212	-----------------------    return;
	.dwpsn	"ADLATUS_ApplicationInterface.c",212,3
;----------------------------------------------------------------------
; 212 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_ApplicationInterface.c",213,1
        BX        LR
	.dwendentry
	.dwendtag DW$8




	.sect	".text:v$3"
	.clink
	.global	_FUN_CCapplint_SetFlashRequest_V

DW$9	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCapplint_SetFlashRequest_V"), DW_AT_symbol_name("_FUN_CCapplint_SetFlashRequest_V")
	.dwattr DW$9, DW_AT_veneer(0x01)
	.dwattr DW$9, DW_AT_low_pc(_FUN_CCapplint_SetFlashRequest_V)
	.dwattr DW$9, DW_AT_high_pc(0x00)
	.dwattr DW$9, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCapplint_SetFlashRequest_V                         *
;*****************************************************************************
_FUN_CCapplint_SetFlashRequest_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CCapplint_SetFlashRequest_V+1, 32
	.state16
	.dwendtag DW$9



	.sect	".text"
	.clink
	.global	$FUN_CCapplint_SetFlashRequest_V

DW$10	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCapplint_SetFlashRequest_V"), DW_AT_symbol_name("$FUN_CCapplint_SetFlashRequest_V")
	.dwattr DW$10, DW_AT_low_pc($FUN_CCapplint_SetFlashRequest_V)
	.dwattr DW$10, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_ApplicationInterface.c",234,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 233 | void FUN_CCapplint_SetFlashRequest_V (void)                            
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCapplint_SetFlashRequest_V                            *
;*                                                                           *
;*   Regs Modified     :                                                     *
;*   Regs Used         :                                                     *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CCapplint_SetFlashRequest_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;** 234	-----------------------    return;
	.dwpsn	"ADLATUS_ApplicationInterface.c",238,1
        BX        LR
	.dwendentry
	.dwendtag DW$10



;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON1:	.field  	IND$CALL+1,32
	.align	4
CON2:	.field  	_gt_CCapplint_FlashRequest_UL,32
;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	IND$CALL

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************

DWT$1019	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1019, DW_AT_language(DW_LANG_C)
DWT$1021	.dwtag  DW_TAG_typedef, DW_AT_name("ULONG"), DW_AT_type(*DWT$12)
	.dwattr DWT$1021, DW_AT_language(DW_LANG_C)

DWT$1022	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1022, DW_AT_language(DW_LANG_C)
DWT$1023	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1022)
	.dwattr DWT$1023, DW_AT_address_class(0x20)
DWT$1018	.dwtag  DW_TAG_typedef, DW_AT_name("UBYTE"), DW_AT_type(*DWT$6)
	.dwattr DWT$1018, DW_AT_language(DW_LANG_C)
DWT$12	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned long")
	.dwattr DWT$12, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$12, DW_AT_byte_size(0x04)
DWT$6	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned char")
	.dwattr DWT$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr DWT$6, DW_AT_byte_size(0x01)

	.dwattr DW$6, DW_AT_external(0x01)
	.dwattr DW$6, DW_AT_type(*DWT$1018)
	.dwattr DW$3, DW_AT_external(0x01)
	.dwattr DW$8, DW_AT_external(0x01)
	.dwattr DW$10, DW_AT_external(0x01)
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

DW$11	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$11, DW_AT_location[DW_OP_reg0]
DW$12	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$12, DW_AT_location[DW_OP_reg1]
DW$13	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$13, DW_AT_location[DW_OP_reg2]
DW$14	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$14, DW_AT_location[DW_OP_reg3]
DW$15	.dwtag  DW_TAG_assign_register, DW_AT_name("V1")
	.dwattr DW$15, DW_AT_location[DW_OP_reg4]
DW$16	.dwtag  DW_TAG_assign_register, DW_AT_name("V2")
	.dwattr DW$16, DW_AT_location[DW_OP_reg5]
DW$17	.dwtag  DW_TAG_assign_register, DW_AT_name("V3")
	.dwattr DW$17, DW_AT_location[DW_OP_reg6]
DW$18	.dwtag  DW_TAG_assign_register, DW_AT_name("V4")
	.dwattr DW$18, DW_AT_location[DW_OP_reg7]
DW$19	.dwtag  DW_TAG_assign_register, DW_AT_name("V5")
	.dwattr DW$19, DW_AT_location[DW_OP_reg8]
DW$20	.dwtag  DW_TAG_assign_register, DW_AT_name("V6")
	.dwattr DW$20, DW_AT_location[DW_OP_reg9]
DW$21	.dwtag  DW_TAG_assign_register, DW_AT_name("V7")
	.dwattr DW$21, DW_AT_location[DW_OP_reg10]
DW$22	.dwtag  DW_TAG_assign_register, DW_AT_name("V8")
	.dwattr DW$22, DW_AT_location[DW_OP_reg11]
DW$23	.dwtag  DW_TAG_assign_register, DW_AT_name("V9")
	.dwattr DW$23, DW_AT_location[DW_OP_reg12]
DW$24	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$24, DW_AT_location[DW_OP_reg13]
DW$25	.dwtag  DW_TAG_assign_register, DW_AT_name("LR")
	.dwattr DW$25, DW_AT_location[DW_OP_reg14]
DW$26	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$26, DW_AT_location[DW_OP_reg15]
DW$27	.dwtag  DW_TAG_assign_register, DW_AT_name("C0")
	.dwattr DW$27, DW_AT_location[DW_OP_reg16]
DW$28	.dwtag  DW_TAG_assign_register, DW_AT_name("C1")
	.dwattr DW$28, DW_AT_location[DW_OP_reg17]
DW$29	.dwtag  DW_TAG_assign_register, DW_AT_name("C2")
	.dwattr DW$29, DW_AT_location[DW_OP_reg18]
DW$30	.dwtag  DW_TAG_assign_register, DW_AT_name("C3")
	.dwattr DW$30, DW_AT_location[DW_OP_reg19]
DW$31	.dwtag  DW_TAG_assign_register, DW_AT_name("C4")
	.dwattr DW$31, DW_AT_location[DW_OP_reg20]
DW$32	.dwtag  DW_TAG_assign_register, DW_AT_name("C5")
	.dwattr DW$32, DW_AT_location[DW_OP_reg21]
DW$33	.dwtag  DW_TAG_assign_register, DW_AT_name("C6")
	.dwattr DW$33, DW_AT_location[DW_OP_reg22]
DW$34	.dwtag  DW_TAG_assign_register, DW_AT_name("C7")
	.dwattr DW$34, DW_AT_location[DW_OP_reg23]
DW$35	.dwtag  DW_TAG_assign_register, DW_AT_name("AP")
	.dwattr DW$35, DW_AT_location[DW_OP_reg24]
DW$36	.dwtag  DW_TAG_assign_register, DW_AT_name("SR")
	.dwattr DW$36, DW_AT_location[DW_OP_reg25]
DW$37	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$37, DW_AT_location[DW_OP_reg26]
	.dwendtag DWCU

