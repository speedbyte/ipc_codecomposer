;******************************************************************************
;* TMS470 C/C++ Codegen                                       PC Version 2.71 *
;* Date/Time created: Tue Jan 24 12:32:32 2012                                *
;******************************************************************************
	.state16

DWCU	.dwtag  DW_TAG_compile_unit
	.dwattr DWCU, DW_AT_name("ADLATUS_ConfigProject.c")
	.dwattr DWCU, DW_AT_producer("TMS470 C/C++ Codegen PC Version 2.71 Copyright (c) 1996-2008 Texas Instruments Incorporated")
	.dwattr DWCU, DW_AT_stmt_list(0x00)
	.dwattr DWCU, DW_AT_TI_VERSION(0x01)

	.sect	".const"
	.align	4
_c_CCconprj_ClockFrequency_UL:
	.field  	24000000,32			; _c_CCconprj_ClockFrequency_UL @ 0

	.sect	".text"
	.global	_c_CCconprj_ClockFrequency_UL
DW$1	.dwtag  DW_TAG_variable, DW_AT_name("c_CCconprj_ClockFrequency_UL"), DW_AT_symbol_name("_c_CCconprj_ClockFrequency_UL")
	.dwattr DW$1, DW_AT_type(*DWT$1026)
	.dwattr DW$1, DW_AT_location[DW_OP_addr _c_CCconprj_ClockFrequency_UL]
	.dwattr DW$1, DW_AT_external(0x01)

	.sect	".const"
	.align	4
_c_CCconprj_CanClockFrequency_UL:
	.field  	24000000,32			; _c_CCconprj_CanClockFrequency_UL @ 0

	.sect	".text"
	.global	_c_CCconprj_CanClockFrequency_UL
DW$2	.dwtag  DW_TAG_variable, DW_AT_name("c_CCconprj_CanClockFrequency_UL"), DW_AT_symbol_name("_c_CCconprj_CanClockFrequency_UL")
	.dwattr DW$2, DW_AT_type(*DWT$1026)
	.dwattr DW$2, DW_AT_location[DW_OP_addr _c_CCconprj_CanClockFrequency_UL]
	.dwattr DW$2, DW_AT_external(0x01)

	.sect	".const"
	.align	4
_c_CCconprj_TimerFrequency_UL:
	.field  	24000000,32			; _c_CCconprj_TimerFrequency_UL @ 0

	.sect	".text"
	.global	_c_CCconprj_TimerFrequency_UL
DW$3	.dwtag  DW_TAG_variable, DW_AT_name("c_CCconprj_TimerFrequency_UL"), DW_AT_symbol_name("_c_CCconprj_TimerFrequency_UL")
	.dwattr DW$3, DW_AT_type(*DWT$1026)
	.dwattr DW$3, DW_AT_location[DW_OP_addr _c_CCconprj_TimerFrequency_UL]
	.dwattr DW$3, DW_AT_external(0x01)

	.sect	".const"
	.align	2
_c_CCconprj_IntWdtTimeout_UW:
	.field  	1,16			; _c_CCconprj_IntWdtTimeout_UW @ 0

	.sect	".text"
	.global	_c_CCconprj_IntWdtTimeout_UW
DW$4	.dwtag  DW_TAG_variable, DW_AT_name("c_CCconprj_IntWdtTimeout_UW"), DW_AT_symbol_name("_c_CCconprj_IntWdtTimeout_UW")
	.dwattr DW$4, DW_AT_type(*DWT$1022)
	.dwattr DW$4, DW_AT_location[DW_OP_addr _c_CCconprj_IntWdtTimeout_UW]
	.dwattr DW$4, DW_AT_external(0x01)

	.sect	".const"
	.align	4
_C_FlashDelay_UL:
	.field  	12,32			; _C_FlashDelay_UL @ 0

	.sect	".text"
	.global	_C_FlashDelay_UL
DW$5	.dwtag  DW_TAG_variable, DW_AT_name("C_FlashDelay_UL"), DW_AT_symbol_name("_C_FlashDelay_UL")
	.dwattr DW$5, DW_AT_type(*DWT$1026)
	.dwattr DW$5, DW_AT_location[DW_OP_addr _C_FlashDelay_UL]
	.dwattr DW$5, DW_AT_external(0x01)

	.sect	".const"
	.align	1
_c_CCconprj_DisableReset_UB:
	.field  	0,8			; _c_CCconprj_DisableReset_UB @ 0

	.sect	".text"
	.global	_c_CCconprj_DisableReset_UB
DW$6	.dwtag  DW_TAG_variable, DW_AT_name("c_CCconprj_DisableReset_UB"), DW_AT_symbol_name("_c_CCconprj_DisableReset_UB")
	.dwattr DW$6, DW_AT_type(*DWT$1019)
	.dwattr DW$6, DW_AT_location[DW_OP_addr _c_CCconprj_DisableReset_UB]
	.dwattr DW$6, DW_AT_external(0x01)

	.sect	".const"
	.align	2
_c_CCconprj_StartValue_CRC16_UW:
	.field  	0,16			; _c_CCconprj_StartValue_CRC16_UW @ 0

	.sect	".text"
	.global	_c_CCconprj_StartValue_CRC16_UW
DW$7	.dwtag  DW_TAG_variable, DW_AT_name("c_CCconprj_StartValue_CRC16_UW"), DW_AT_symbol_name("_c_CCconprj_StartValue_CRC16_UW")
	.dwattr DW$7, DW_AT_type(*DWT$1022)
	.dwattr DW$7, DW_AT_location[DW_OP_addr _c_CCconprj_StartValue_CRC16_UW]
	.dwattr DW$7, DW_AT_external(0x01)
;	C:\CCStudio_v3.3\tms470\cgtools_271\bin\opt470.exe -v1 -q -s -O2 -e r:/01_adlatus/04_lst/ADLATUS_ConfigProject.if r:/01_adlatus/04_lst/ADLATUS_ConfigProject.opt -w r:/01_adlatus/04_lst 

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
DWT$1019	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1018)
DWT$1022	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1021)
DWT$1026	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1025)
DWT$1018	.dwtag  DW_TAG_typedef, DW_AT_name("UBYTE"), DW_AT_type(*DWT$6)
	.dwattr DWT$1018, DW_AT_language(DW_LANG_C)
DWT$1021	.dwtag  DW_TAG_typedef, DW_AT_name("UWORD"), DW_AT_type(*DWT$8)
	.dwattr DWT$1021, DW_AT_language(DW_LANG_C)
DWT$1025	.dwtag  DW_TAG_typedef, DW_AT_name("ULONG"), DW_AT_type(*DWT$12)
	.dwattr DWT$1025, DW_AT_language(DW_LANG_C)
DWT$6	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned char")
	.dwattr DWT$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr DWT$6, DW_AT_byte_size(0x01)
DWT$8	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned short")
	.dwattr DWT$8, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$8, DW_AT_byte_size(0x02)
DWT$12	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned long")
	.dwattr DWT$12, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$12, DW_AT_byte_size(0x04)


;***************************************************************
;* DWARF CIE ENTRIES                                           *
;***************************************************************

DW$CIE	.dwcie 1, 26
	.dwcfa	0x0c, 13, 0
	.dwcfa	0x07, 0
	.dwcfa	0x07, 1
	.dwcfa	0x07, 2
	.dwcfa	0x07, 3
	.dwcfa	0x07, 4
	.dwcfa	0x07, 5
	.dwcfa	0x07, 6
	.dwcfa	0x07, 7
	.dwcfa	0x07, 8
	.dwcfa	0x07, 9
	.dwcfa	0x07, 10
	.dwcfa	0x07, 11
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

DW$8	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$8, DW_AT_location[DW_OP_reg0]
DW$9	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$9, DW_AT_location[DW_OP_reg1]
DW$10	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$10, DW_AT_location[DW_OP_reg2]
DW$11	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$11, DW_AT_location[DW_OP_reg3]
DW$12	.dwtag  DW_TAG_assign_register, DW_AT_name("V1")
	.dwattr DW$12, DW_AT_location[DW_OP_reg4]
DW$13	.dwtag  DW_TAG_assign_register, DW_AT_name("V2")
	.dwattr DW$13, DW_AT_location[DW_OP_reg5]
DW$14	.dwtag  DW_TAG_assign_register, DW_AT_name("V3")
	.dwattr DW$14, DW_AT_location[DW_OP_reg6]
DW$15	.dwtag  DW_TAG_assign_register, DW_AT_name("V4")
	.dwattr DW$15, DW_AT_location[DW_OP_reg7]
DW$16	.dwtag  DW_TAG_assign_register, DW_AT_name("V5")
	.dwattr DW$16, DW_AT_location[DW_OP_reg8]
DW$17	.dwtag  DW_TAG_assign_register, DW_AT_name("V6")
	.dwattr DW$17, DW_AT_location[DW_OP_reg9]
DW$18	.dwtag  DW_TAG_assign_register, DW_AT_name("V7")
	.dwattr DW$18, DW_AT_location[DW_OP_reg10]
DW$19	.dwtag  DW_TAG_assign_register, DW_AT_name("V8")
	.dwattr DW$19, DW_AT_location[DW_OP_reg11]
DW$20	.dwtag  DW_TAG_assign_register, DW_AT_name("V9")
	.dwattr DW$20, DW_AT_location[DW_OP_reg12]
DW$21	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$21, DW_AT_location[DW_OP_reg13]
DW$22	.dwtag  DW_TAG_assign_register, DW_AT_name("LR")
	.dwattr DW$22, DW_AT_location[DW_OP_reg14]
DW$23	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$23, DW_AT_location[DW_OP_reg15]
DW$24	.dwtag  DW_TAG_assign_register, DW_AT_name("C0")
	.dwattr DW$24, DW_AT_location[DW_OP_reg16]
DW$25	.dwtag  DW_TAG_assign_register, DW_AT_name("C1")
	.dwattr DW$25, DW_AT_location[DW_OP_reg17]
DW$26	.dwtag  DW_TAG_assign_register, DW_AT_name("C2")
	.dwattr DW$26, DW_AT_location[DW_OP_reg18]
DW$27	.dwtag  DW_TAG_assign_register, DW_AT_name("C3")
	.dwattr DW$27, DW_AT_location[DW_OP_reg19]
DW$28	.dwtag  DW_TAG_assign_register, DW_AT_name("C4")
	.dwattr DW$28, DW_AT_location[DW_OP_reg20]
DW$29	.dwtag  DW_TAG_assign_register, DW_AT_name("C5")
	.dwattr DW$29, DW_AT_location[DW_OP_reg21]
DW$30	.dwtag  DW_TAG_assign_register, DW_AT_name("C6")
	.dwattr DW$30, DW_AT_location[DW_OP_reg22]
DW$31	.dwtag  DW_TAG_assign_register, DW_AT_name("C7")
	.dwattr DW$31, DW_AT_location[DW_OP_reg23]
DW$32	.dwtag  DW_TAG_assign_register, DW_AT_name("AP")
	.dwattr DW$32, DW_AT_location[DW_OP_reg24]
DW$33	.dwtag  DW_TAG_assign_register, DW_AT_name("SR")
	.dwattr DW$33, DW_AT_location[DW_OP_reg25]
DW$34	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$34, DW_AT_location[DW_OP_reg26]
	.dwendtag DWCU

