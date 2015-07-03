;******************************************************************************
;* TMS470 C/C++ Codegen                                       PC Version 2.71 *
;* Date/Time created: Tue Jan 24 12:32:41 2012                                *
;******************************************************************************
	.state16

DWCU	.dwtag  DW_TAG_compile_unit
	.dwattr DWCU, DW_AT_name("lld_SPI.c")
	.dwattr DWCU, DW_AT_producer("TMS470 C/C++ Codegen PC Version 2.71 Copyright (c) 1996-2008 Texas Instruments Incorporated")
	.dwattr DWCU, DW_AT_stmt_list(0x00)
	.dwattr DWCU, DW_AT_TI_VERSION(0x01)

DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCtim_SystemTimerCheck_V"), DW_AT_symbol_name("$FUN_CCtim_SystemTimerCheck_V")
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_variable, DW_AT_name("e_SPI2_ST"), DW_AT_symbol_name("_e_SPI2_ST")
	.dwattr DW$2, DW_AT_type(*DWT$1135)
	.dwattr DW$2, DW_AT_declaration(0x01)
	.dwattr DW$2, DW_AT_external(0x01)

	.sect	".const"
	.align	2
_SPI2_st_EepromMode:
	.field  	360,16			; _SPI2_st_EepromMode._uw_Ctrl1 @ 0
	.field  	57,16			; _SPI2_st_EepromMode._uw_Ctrl2 @ 16
	.field  	0,16			; _SPI2_st_EepromMode._uw_Ctrl3 @ 32

	.sect	".text"
	.global	_SPI2_st_EepromMode
DW$3	.dwtag  DW_TAG_variable, DW_AT_name("SPI2_st_EepromMode"), DW_AT_symbol_name("_SPI2_st_EepromMode")
	.dwattr DW$3, DW_AT_type(*DWT$1032)
	.dwattr DW$3, DW_AT_location[DW_OP_addr _SPI2_st_EepromMode]
	.dwattr DW$3, DW_AT_external(0x01)

	.sect	".const"
	.align	2
_SPI2_st_Pins:
	.field  	23,16			; _SPI2_st_Pins._uw_PC1 @ 0
	.field  	31,16			; _SPI2_st_Pins._uw_PC3 @ 16
	.field  	14,16			; _SPI2_st_Pins._uw_PC6 @ 32

	.sect	".text"
	.global	_SPI2_st_Pins
DW$4	.dwtag  DW_TAG_variable, DW_AT_name("SPI2_st_Pins"), DW_AT_symbol_name("_SPI2_st_Pins")
	.dwattr DW$4, DW_AT_type(*DWT$1140)
	.dwattr DW$4, DW_AT_location[DW_OP_addr _SPI2_st_Pins]
	.dwattr DW$4, DW_AT_external(0x01)
	.global	_g_buf_UB
	.bss	_g_buf_UB,1,1
DW$5	.dwtag  DW_TAG_variable, DW_AT_name("g_buf_UB"), DW_AT_symbol_name("_g_buf_UB")
	.dwattr DW$5, DW_AT_type(*DWT$1018)
	.dwattr DW$5, DW_AT_location[DW_OP_addr _g_buf_UB]
	.dwattr DW$5, DW_AT_external(0x01)
;	C:\CCStudio_v3.3\tms470\cgtools_271\bin\opt470.exe -v1 -q -s -O2 -e r:/01_adlatus/04_lst/lld_SPI.if r:/01_adlatus/04_lst/lld_SPI.opt -w r:/01_adlatus/04_lst 

	.sect	".text:v$0"
	.clink
	.global	_OCSPI_InitSync

DW$6	.dwtag  DW_TAG_subprogram, DW_AT_name("OCSPI_InitSync"), DW_AT_symbol_name("_OCSPI_InitSync")
	.dwattr DW$6, DW_AT_veneer(0x01)
	.dwattr DW$6, DW_AT_low_pc(_OCSPI_InitSync)
	.dwattr DW$6, DW_AT_high_pc(0x00)
	.dwattr DW$6, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _OCSPI_InitSync                                          *
;*****************************************************************************
_OCSPI_InitSync:
	 LDR       ip, [pc]
	 BX        ip
	.field     $OCSPI_InitSync+1, 32
	.state16
	.dwendtag DW$6



	.sect	".text"
	.clink
	.global	$OCSPI_InitSync

DW$7	.dwtag  DW_TAG_subprogram, DW_AT_name("OCSPI_InitSync"), DW_AT_symbol_name("$OCSPI_InitSync")
	.dwattr DW$7, DW_AT_low_pc($OCSPI_InitSync)
	.dwattr DW$7, DW_AT_high_pc(0x00)
	.dwpsn	"lld_SPI.c",106,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 105 | IO_ErrorType OCSPI_InitSync(OCSPI_ConfigType config)                   
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: OCSPI_InitSync                                             *
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
$OCSPI_InitSync:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;* A1    assigned to _config
DW$8	.dwtag  DW_TAG_formal_parameter, DW_AT_name("config"), DW_AT_symbol_name("_config")
	.dwattr DW$8, DW_AT_type(*DWT$1037)
	.dwattr DW$8, DW_AT_location[DW_OP_reg0]
;** 111	-----------------------    C$1 = &e_SPI2_ST;
;* A2    assigned to C$1
DW$9	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$9, DW_AT_type(*DWT$1137)
	.dwattr DW$9, DW_AT_location[DW_OP_reg1]
;* A1    assigned to C$2
DW$10	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$10, DW_AT_type(*DWT$1039)
	.dwattr DW$10, DW_AT_location[DW_OP_reg0]
;* A1    assigned to C$3
DW$11	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$11, DW_AT_type(*DWT$1142)
	.dwattr DW$11, DW_AT_location[DW_OP_reg0]
	.dwpsn	"lld_SPI.c",111,3
;----------------------------------------------------------------------
; 111 | e_SPI2_ST.ctrl2_UN.ctrl2_UW.uw_Ctrl2 &= ~SPI_cuw_SPIEN;                
;----------------------------------------------------------------------
        LDR       A2, CON1              ; |111| 
;** 111	-----------------------    C$1->ctrl2_UN.ctrl2_UW.uw_Ctrl2 &= 0xffefu;
        LDRH      A4, [A2, #6]          ; |111| 
        LDR       A1, CON3              ; |114| 
        MOV       A3, A1
        SUB       A3, #14               ; |111| 
        AND       A3, A4                ; |111| 
        STRH      A3, [A2, #6]          ; |111| 
;** 114	-----------------------    C$1->ctrl3_UN.ctrl3_UW.uw_Ctrl3 &= 0xfffdu;
	.dwpsn	"lld_SPI.c",114,3
;----------------------------------------------------------------------
; 114 | e_SPI2_ST.ctrl3_UN.ctrl3_UW.uw_Ctrl3 &= ~SPI_cuw_RX_INT_ENABLE;        
;----------------------------------------------------------------------
        LDRH      A3, [A2, #10]         ; |114| 
        AND       A1, A3                ; |114| 
        STRH      A1, [A2, #10]         ; |114| 
;** 117	-----------------------    C$3 = &SPI2_st_Pins;
	.dwpsn	"lld_SPI.c",117,3
;----------------------------------------------------------------------
; 117 | e_SPI2_ST.pc6_UN.pc6_UW.uw_PC6 = SPI2_st_Pins.uw_PC6;                  
;----------------------------------------------------------------------
        LDR       A1, CON4              ; |117| 
;** 117	-----------------------    C$1->pc6_UN.pc6_UW.uw_PC6 = C$3->uw_PC6;
        LDRH      A3, [A1, #4]          ; |117| 
        STRH      A3, [A2, #50]         ; |117| 
;** 119	-----------------------    C$1->pc3_UN.pc3_UW.uw_PC3 = C$3->uw_PC3;
	.dwpsn	"lld_SPI.c",119,3
;----------------------------------------------------------------------
; 119 | e_SPI2_ST.pc3_UN.pc3_UW.uw_PC3 = SPI2_st_Pins.uw_PC3;                  
;----------------------------------------------------------------------
        LDRH      A3, [A1, #2]          ; |119| 
        STRH      A3, [A2, #38]         ; |119| 
;** 121	-----------------------    C$1->pc1_UN.pc1_UW.uw_PC1 = C$3->uw_PC1;
	.dwpsn	"lld_SPI.c",121,3
;----------------------------------------------------------------------
; 121 | e_SPI2_ST.pc1_UN.pc1_UW.uw_PC1 = SPI2_st_Pins.uw_PC1;                  
;----------------------------------------------------------------------
        LDRH      A1, [A1, #0]          ; |121| 
        STRH      A1, [A2, #30]         ; |121| 
;** 124	-----------------------    C$2 = &SPI2_st_EepromMode;
	.dwpsn	"lld_SPI.c",124,3
;----------------------------------------------------------------------
; 124 | e_SPI2_ST.ctrl1_UN.ctrl1_UW.uw_Ctrl1 = SPI2_st_EepromMode.uw_Ctrl1;    
;----------------------------------------------------------------------
        LDR       A1, CON5              ; |124| 
;** 124	-----------------------    C$1->ctrl1_UN.ctrl1_UW.uw_Ctrl1 = C$2->uw_Ctrl1;
        LDRH      A3, [A1, #0]          ; |124| 
        STRH      A3, [A2, #2]          ; |124| 
;** 126	-----------------------    C$1->ctrl3_UN.ctrl3_UW.uw_Ctrl3 = C$2->uw_Ctrl3;
	.dwpsn	"lld_SPI.c",126,3
;----------------------------------------------------------------------
; 126 | e_SPI2_ST.ctrl3_UN.ctrl3_UW.uw_Ctrl3 = SPI2_st_EepromMode.uw_Ctrl3;    
;----------------------------------------------------------------------
        LDRH      A3, [A1, #4]          ; |126| 
        STRH      A3, [A2, #10]         ; |126| 
;** 128	-----------------------    C$1->ctrl2_UN.ctrl2_UW.uw_Ctrl2 = C$2->uw_Ctrl2;
	.dwpsn	"lld_SPI.c",128,3
;----------------------------------------------------------------------
; 128 | e_SPI2_ST.ctrl2_UN.ctrl2_UW.uw_Ctrl2 = SPI2_st_EepromMode.uw_Ctrl2;    
;----------------------------------------------------------------------
        LDRH      A1, [A1, #2]          ; |128| 
        STRH      A1, [A2, #6]          ; |128| 
;** 130	-----------------------    C$1->ctrl2_UN.ctrl2_UW.uw_Ctrl2 |= 0x10u;
	.dwpsn	"lld_SPI.c",130,3
;----------------------------------------------------------------------
; 130 | e_SPI2_ST.ctrl2_UN.ctrl2_UW.uw_Ctrl2 |= SPI_cuw_SPIEN;                 
;----------------------------------------------------------------------
        LDRH      A3, [A2, #6]          ; |130| 
        MOV       A1, #16               ; |130| 
        ORR       A1, A3                ; |130| 
        STRH      A1, [A2, #6]          ; |130| 
;** 135	-----------------------    return 0;
	.dwpsn	"lld_SPI.c",135,5
;----------------------------------------------------------------------
; 135 | return IO_E_OK;                                                        
;----------------------------------------------------------------------
        MOV       A1, #0                ; |135| 
	.dwpsn	"lld_SPI.c",136,1
        BX        LR
	.dwendentry
	.dwendtag DW$7




	.sect	".text:v$1"
	.clink
	.global	_OCSPI_DeInitSync

DW$12	.dwtag  DW_TAG_subprogram, DW_AT_name("OCSPI_DeInitSync"), DW_AT_symbol_name("_OCSPI_DeInitSync")
	.dwattr DW$12, DW_AT_veneer(0x01)
	.dwattr DW$12, DW_AT_low_pc(_OCSPI_DeInitSync)
	.dwattr DW$12, DW_AT_high_pc(0x00)
	.dwattr DW$12, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _OCSPI_DeInitSync                                        *
;*****************************************************************************
_OCSPI_DeInitSync:
	 LDR       ip, [pc]
	 BX        ip
	.field     $OCSPI_DeInitSync+1, 32
	.state16
	.dwendtag DW$12



	.sect	".text"
	.clink
	.global	$OCSPI_DeInitSync

DW$13	.dwtag  DW_TAG_subprogram, DW_AT_name("OCSPI_DeInitSync"), DW_AT_symbol_name("$OCSPI_DeInitSync")
	.dwattr DW$13, DW_AT_low_pc($OCSPI_DeInitSync)
	.dwattr DW$13, DW_AT_high_pc(0x00)
	.dwpsn	"lld_SPI.c",146,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 145 | void OCSPI_DeInitSync(void)                                            
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: OCSPI_DeInitSync                                           *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,SR                                         *
;*   Regs Used         : A1,A2,A3,SR                                         *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$OCSPI_DeInitSync:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;** 151	-----------------------    e_SPI2_ST.ctrl2_UN.ctrl2_UW.uw_Ctrl2 &= 0xffefu;
	.dwpsn	"lld_SPI.c",151,5
;----------------------------------------------------------------------
; 151 | e_SPI2_ST.ctrl2_UN.ctrl2_UW.uw_Ctrl2 &= ~SPI_cuw_SPIEN;                
;----------------------------------------------------------------------
        LDR       A3, CON1              ; |151| 
        LDRH      A2, [A3, #6]          ; |151| 
        LDR       A1, CON3              ; |151| 
        SUB       A1, #14               ; |151| 
        AND       A1, A2                ; |151| 
        STRH      A1, [A3, #6]          ; |151| 
;** 151	-----------------------    return;
	.dwpsn	"lld_SPI.c",156,1
        BX        LR
	.dwendentry
	.dwendtag DW$13




	.sect	".text:v$2"
	.clink
	.global	_OCSPI_Busy

DW$14	.dwtag  DW_TAG_subprogram, DW_AT_name("OCSPI_Busy"), DW_AT_symbol_name("_OCSPI_Busy")
	.dwattr DW$14, DW_AT_veneer(0x01)
	.dwattr DW$14, DW_AT_low_pc(_OCSPI_Busy)
	.dwattr DW$14, DW_AT_high_pc(0x00)
	.dwattr DW$14, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _OCSPI_Busy                                              *
;*****************************************************************************
_OCSPI_Busy:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $OCSPI_Busy
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$14



	.sect	".text"
	.clink
	.global	$OCSPI_Busy

DW$15	.dwtag  DW_TAG_subprogram, DW_AT_name("OCSPI_Busy"), DW_AT_symbol_name("$OCSPI_Busy")
	.dwattr DW$15, DW_AT_low_pc($OCSPI_Busy)
	.dwattr DW$15, DW_AT_high_pc(0x00)
	.dwpsn	"lld_SPI.c",159,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 158 | IO_ErrorType OCSPI_Busy(void)                                          
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: OCSPI_Busy                                                 *
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
$OCSPI_Busy:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 160 | IO_ErrorType t_Temp_UB;                                                
; 162 | SPI_v_SetMode(&SPI2_st_EepromMode );                                   
; 164 | e_SPI2_ST.pc5_UN.pc5_UW.uw_PC5 = SPI_cuw_SCS_PIN;                      
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
;* A1    assigned to C$1
DW$16	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$16, DW_AT_type(*DWT$6)
	.dwattr DW$16, DW_AT_location[DW_OP_reg0]
;* V1    assigned to C$2
DW$17	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$17, DW_AT_type(*DWT$1137)
	.dwattr DW$17, DW_AT_location[DW_OP_reg4]
;* A2    assigned to C$3
DW$18	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$18, DW_AT_type(*DWT$1039)
	.dwattr DW$18, DW_AT_location[DW_OP_reg1]
;* A1    assigned to _t_Temp_UB
DW$19	.dwtag  DW_TAG_variable, DW_AT_name("t_Temp_UB"), DW_AT_symbol_name("_t_Temp_UB")
	.dwattr DW$19, DW_AT_type(*DWT$11)
	.dwattr DW$19, DW_AT_location[DW_OP_reg0]
;* V3    assigned to K$14
DW$20	.dwtag  DW_TAG_variable, DW_AT_name("K$14"), DW_AT_symbol_name("K$14")
	.dwattr DW$20, DW_AT_type(*DWT$11)
	.dwattr DW$20, DW_AT_location[DW_OP_reg6]
;* V2    assigned to K$20
DW$21	.dwtag  DW_TAG_variable, DW_AT_name("K$20"), DW_AT_symbol_name("K$20")
	.dwattr DW$21, DW_AT_type(*DWT$1019)
	.dwattr DW$21, DW_AT_location[DW_OP_reg5]
;* V1    assigned to K$7
DW$22	.dwtag  DW_TAG_variable, DW_AT_name("K$7"), DW_AT_symbol_name("K$7")
	.dwattr DW$22, DW_AT_type(*DWT$1136)
	.dwattr DW$22, DW_AT_location[DW_OP_reg4]
;** 89	-----------------------    C$3 = &SPI2_st_EepromMode;  // [1]
	.dwpsn	"lld_SPI.c",89,2
        LDR       A2, CON5              ; |89| 
;** 89	-----------------------    C$2 = &e_SPI2_ST;  // [1]
        LDR       V1, CON1              ; |89| 
;** 89	-----------------------    C$2->ctrl1_UN.ctrl1_UW.uw_Ctrl1 = C$3->uw_Ctrl1;  // [1]
        LDRH      A1, [A2, #0]          ; |89| 
        STRH      A1, [V1, #2]          ; |89| 
;** 91	-----------------------    C$2->ctrl2_UN.ctrl2_UW.uw_Ctrl2 = C$3->uw_Ctrl2;  // [1]
	.dwpsn	"lld_SPI.c",91,2
        LDRH      A1, [A2, #2]          ; |91| 
        STRH      A1, [V1, #6]          ; |91| 
;** 91	-----------------------    C$2->pc5_UN.pc5_UW.uw_PC5 = K$14 = 16;  // [1]
        MOV       V3, #16               ; |91| 
        STRH      V3, [V1, #46]         ; |91| 
;** 168	-----------------------    g_buf_UB = C$2->uw_Buf;
	.dwpsn	"lld_SPI.c",168,3
;----------------------------------------------------------------------
; 168 | g_buf_UB = e_SPI2_ST.uw_Buf;                                           
;----------------------------------------------------------------------
        LDRH      A1, [V1, #22]         ; |168| 
        LDR       V2, CON7              ; |168| 
        STRB      A1, [V2, #0]          ; |168| 
;** 171	-----------------------    C$2->uw_Dat0 = 5;
	.dwpsn	"lld_SPI.c",171,3
;----------------------------------------------------------------------
; 171 | e_SPI2_ST.uw_Dat0 = EEPROM_COM_STATUS_READ;                            
;----------------------------------------------------------------------
        MOV       A1, #5                ; |171| 
        STRH      A1, [V1, #14]         ; |171| 
;** 89	-----------------------    K$7 = C$2;  // [1]
	.dwpsn	"lld_SPI.c",89,2
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;** 174	-----------------------    goto g2;
	.dwpsn	"lld_SPI.c",174,3
;----------------------------------------------------------------------
; 174 | while ((e_SPI2_ST.ctrl3_UN.ctrl3_UW.uw_Ctrl3 & 0x0001u) == 0u)         
;----------------------------------------------------------------------
        B         L2                    ; |174| 
        ; |174| 
;* --------------------------------------------------------------------------*
L1:    
DWL$$OCSPI_Busy$2$B:
;**	-----------------------g1:
;** 176	-----------------------    FUN_CCtim_SystemTimerCheck_V();
	.dwpsn	"lld_SPI.c",176,5
;----------------------------------------------------------------------
; 176 | FUN_CCtim_SystemTimerCheck_V ();                                       
;----------------------------------------------------------------------
        MOV       A1, #1                ; |176| 
        MOV       LR, A1
        LDR       A1, CON8
        ADD       LR, PC
        BX        A1
        ; |176| 
DWL$$OCSPI_Busy$2$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L2
;* --------------------------------------------------------------------------*
L2:    
DWL$$OCSPI_Busy$3$B:
;**	-----------------------g2:
;** 176	-----------------------    if ( !(K$7->ctrl3_UN.ctrl3_UW.uw_Ctrl3&1) ) goto g1;
        LDRH      A1, [V1, #10]         ; |176| 
        LSR       A1, A1, #1            ; |176| 
        BCC       L1                    ; |176| 
        ; |176| 
DWL$$OCSPI_Busy$3$E:
;* --------------------------------------------------------------------------*
;** 168	-----------------------    K$20 = &g_buf_UB;
	.dwpsn	"lld_SPI.c",168,3
;** 180	-----------------------    *K$20 = K$7->uw_Buf;
	.dwpsn	"lld_SPI.c",180,3
;----------------------------------------------------------------------
; 180 | g_buf_UB = e_SPI2_ST.uw_Buf;                                           
;----------------------------------------------------------------------
        LDRH      A1, [V1, #22]         ; |180| 
        STRB      A1, [V2, #0]          ; |180| 
;** 183	-----------------------    K$7->uw_Dat0 = 0;
	.dwpsn	"lld_SPI.c",183,3
;----------------------------------------------------------------------
; 183 | e_SPI2_ST.uw_Dat0 = 0u;                                                
;----------------------------------------------------------------------
        MOV       V4, #0                ; |183| 
        STRH      V4, [V1, #14]         ; |183| 
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;** 186	-----------------------    goto g5;
	.dwpsn	"lld_SPI.c",186,3
;----------------------------------------------------------------------
; 186 | while ((e_SPI2_ST.ctrl3_UN.ctrl3_UW.uw_Ctrl3 & 0x0001u) == 0u)         
;----------------------------------------------------------------------
        B         L4                    ; |186| 
        ; |186| 
;* --------------------------------------------------------------------------*
L3:    
DWL$$OCSPI_Busy$5$B:
;**	-----------------------g4:
;** 188	-----------------------    FUN_CCtim_SystemTimerCheck_V();
	.dwpsn	"lld_SPI.c",188,5
;----------------------------------------------------------------------
; 188 | FUN_CCtim_SystemTimerCheck_V ();                                       
;----------------------------------------------------------------------
        MOV       A1, #1                ; |188| 
        MOV       LR, A1
        LDR       A1, CON8
        ADD       LR, PC
        BX        A1
        ; |188| 
DWL$$OCSPI_Busy$5$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L4
;* --------------------------------------------------------------------------*
L4:    
DWL$$OCSPI_Busy$6$B:
;**	-----------------------g5:
;** 188	-----------------------    if ( !(K$7->ctrl3_UN.ctrl3_UW.uw_Ctrl3&1) ) goto g4;
        LDRH      A1, [V1, #10]         ; |188| 
        LSR       A1, A1, #1            ; |188| 
        BCC       L3                    ; |188| 
        ; |188| 
DWL$$OCSPI_Busy$6$E:
;* --------------------------------------------------------------------------*
;** 192	-----------------------    *K$20 = C$1 = (unsigned char)K$7->uw_Buf;
	.dwpsn	"lld_SPI.c",192,3
;----------------------------------------------------------------------
; 192 | g_buf_UB = e_SPI2_ST.uw_Buf;                                           
;----------------------------------------------------------------------
        LDRH      A1, [V1, #22]         ; |192| 
        LSL       A1, A1, #24           ; |206| 
        LSR       A1, A1, #24           ; |206| 
        STRB      A1, [V2, #0]          ; |192| 
;** 193	-----------------------    (C$1&1) ? (t_Temp_UB = 2) : (t_Temp_UB = 0);
	.dwpsn	"lld_SPI.c",193,3
;----------------------------------------------------------------------
; 193 | if ((0x01 & g_buf_UB) == 0x01)                                         
; 195 |   t_Temp_UB = IO_E_BUSY;                                               
;----------------------------------------------------------------------
        LSR       A1, A1, #1            ; |193| 
        BCC       L5                    ; |193| 
        ; |193| 
;* --------------------------------------------------------------------------*
        MOV       A1, #2                ; |193| 
        STRH      V3, [V1, #42]         ; |196| 
        POP       {V1, V2, V3, V4, PC}
;* --------------------------------------------------------------------------*
L5:    
        MOV       A1, V4
;** 196	-----------------------    K$7->pc4_UN.pc4_UW.uw_PC4 = K$14;
	.dwpsn	"lld_SPI.c",196,3
;----------------------------------------------------------------------
; 197 | else                                                                   
; 199 |   t_Temp_UB = IO_E_OK;                                                 
; 203 | e_SPI2_ST.pc4_UN.pc4_UW.uw_PC4 = SPI_cuw_SCS_PIN;                      
;----------------------------------------------------------------------
        STRH      V3, [V1, #42]         ; |196| 
;** 206	-----------------------    return t_Temp_UB;
	.dwpsn	"lld_SPI.c",206,3
;----------------------------------------------------------------------
; 206 | return(t_Temp_UB);                                                     
;----------------------------------------------------------------------
	.dwpsn	"lld_SPI.c",207,1
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}

DW$23	.dwtag  DW_TAG_loop
	.dwattr DW$23, DW_AT_name("r:/01_adlatus/04_lst/lld_SPI.asm:L4:1:1327404761")
	.dwattr DW$23, DW_AT_begin_file("lld_SPI.c")
	.dwattr DW$23, DW_AT_begin_line(0xba)
	.dwattr DW$23, DW_AT_end_line(0xbc)
DW$24	.dwtag  DW_TAG_loop_range
	.dwattr DW$24, DW_AT_low_pc(DWL$$OCSPI_Busy$6$B)
	.dwattr DW$24, DW_AT_high_pc(DWL$$OCSPI_Busy$6$E)
DW$25	.dwtag  DW_TAG_loop_range
	.dwattr DW$25, DW_AT_low_pc(DWL$$OCSPI_Busy$5$B)
	.dwattr DW$25, DW_AT_high_pc(DWL$$OCSPI_Busy$5$E)
	.dwendtag DW$23


DW$26	.dwtag  DW_TAG_loop
	.dwattr DW$26, DW_AT_name("r:/01_adlatus/04_lst/lld_SPI.asm:L2:1:1327404761")
	.dwattr DW$26, DW_AT_begin_file("lld_SPI.c")
	.dwattr DW$26, DW_AT_begin_line(0xae)
	.dwattr DW$26, DW_AT_end_line(0xb0)
DW$27	.dwtag  DW_TAG_loop_range
	.dwattr DW$27, DW_AT_low_pc(DWL$$OCSPI_Busy$3$B)
	.dwattr DW$27, DW_AT_high_pc(DWL$$OCSPI_Busy$3$E)
DW$28	.dwtag  DW_TAG_loop_range
	.dwattr DW$28, DW_AT_low_pc(DWL$$OCSPI_Busy$2$B)
	.dwattr DW$28, DW_AT_high_pc(DWL$$OCSPI_Busy$2$E)
	.dwendtag DW$26

	.dwendentry
	.dwendtag DW$15




	.sect	".text:v$3"
	.clink
	.global	_OCSPI_ReadSync

DW$29	.dwtag  DW_TAG_subprogram, DW_AT_name("OCSPI_ReadSync"), DW_AT_symbol_name("_OCSPI_ReadSync")
	.dwattr DW$29, DW_AT_veneer(0x01)
	.dwattr DW$29, DW_AT_low_pc(_OCSPI_ReadSync)
	.dwattr DW$29, DW_AT_high_pc(0x00)
	.dwattr DW$29, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _OCSPI_ReadSync                                          *
;*****************************************************************************
_OCSPI_ReadSync:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $OCSPI_ReadSync
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$29



	.sect	".text"
	.clink
	.global	$OCSPI_ReadSync

DW$30	.dwtag  DW_TAG_subprogram, DW_AT_name("OCSPI_ReadSync"), DW_AT_symbol_name("$OCSPI_ReadSync")
	.dwattr DW$30, DW_AT_low_pc($OCSPI_ReadSync)
	.dwattr DW$30, DW_AT_high_pc(0x00)
	.dwpsn	"lld_SPI.c",216,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 215 | IO_ErrorType OCSPI_ReadSync(IO_ChannelType channel, OCSPI_MemPtrType re
;     | adAddress, OCSPI_SizeType size)                                        
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: OCSPI_ReadSync                                             *
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
$OCSPI_ReadSync:
;* --------------------------------------------------------------------------*
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
;* A1    assigned to _channel
DW$31	.dwtag  DW_TAG_formal_parameter, DW_AT_name("channel"), DW_AT_symbol_name("_channel")
	.dwattr DW$31, DW_AT_type(*DWT$1023)
	.dwattr DW$31, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _readAddress
DW$32	.dwtag  DW_TAG_formal_parameter, DW_AT_name("readAddress"), DW_AT_symbol_name("_readAddress")
	.dwattr DW$32, DW_AT_type(*DWT$1020)
	.dwattr DW$32, DW_AT_location[DW_OP_reg1]
;* A3    assigned to _size
DW$33	.dwtag  DW_TAG_formal_parameter, DW_AT_name("size"), DW_AT_symbol_name("_size")
	.dwattr DW$33, DW_AT_type(*DWT$1025)
	.dwattr DW$33, DW_AT_location[DW_OP_reg2]
;* V1    assigned to C$1
DW$34	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$34, DW_AT_type(*DWT$1137)
	.dwattr DW$34, DW_AT_location[DW_OP_reg4]
;* A2    assigned to C$2
DW$35	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$35, DW_AT_type(*DWT$1039)
	.dwattr DW$35, DW_AT_location[DW_OP_reg1]
;* V2    assigned to _size
DW$36	.dwtag  DW_TAG_variable, DW_AT_name("size"), DW_AT_symbol_name("_size")
	.dwattr DW$36, DW_AT_type(*DWT$1025)
	.dwattr DW$36, DW_AT_location[DW_OP_reg5]
;* V3    assigned to _readAddress
DW$37	.dwtag  DW_TAG_variable, DW_AT_name("readAddress"), DW_AT_symbol_name("_readAddress")
	.dwattr DW$37, DW_AT_type(*DWT$1020)
	.dwattr DW$37, DW_AT_location[DW_OP_reg6]
;* V2    assigned to L$1
DW$38	.dwtag  DW_TAG_variable, DW_AT_name("L$1"), DW_AT_symbol_name("L$1")
	.dwattr DW$38, DW_AT_type(*DWT$11)
	.dwattr DW$38, DW_AT_location[DW_OP_reg5]
;* A1    assigned to K$16
DW$39	.dwtag  DW_TAG_variable, DW_AT_name("K$16"), DW_AT_symbol_name("K$16")
	.dwattr DW$39, DW_AT_type(*DWT$11)
	.dwattr DW$39, DW_AT_location[DW_OP_reg0]
;* V4    assigned to K$36
DW$40	.dwtag  DW_TAG_variable, DW_AT_name("K$36"), DW_AT_symbol_name("K$36")
	.dwattr DW$40, DW_AT_type(*DWT$11)
	.dwattr DW$40, DW_AT_location[DW_OP_reg7]
;* V4    assigned to K$22
DW$41	.dwtag  DW_TAG_variable, DW_AT_name("K$22"), DW_AT_symbol_name("K$22")
	.dwattr DW$41, DW_AT_type(*DWT$1019)
	.dwattr DW$41, DW_AT_location[DW_OP_reg7]
;* V1    assigned to K$9
DW$42	.dwtag  DW_TAG_variable, DW_AT_name("K$9"), DW_AT_symbol_name("K$9")
	.dwattr DW$42, DW_AT_type(*DWT$1136)
	.dwattr DW$42, DW_AT_location[DW_OP_reg4]
;----------------------------------------------------------------------
; 217 | SPI_v_SetMode(&SPI2_st_EepromMode );                                   
; 219 | e_SPI2_ST.pc5_UN.pc5_UW.uw_PC5 = SPI_cuw_SCS_PIN;                      
;----------------------------------------------------------------------
        MOV       V2, A3
        MOV       V3, A2
;** 89	-----------------------    C$2 = &SPI2_st_EepromMode;  // [1]
	.dwpsn	"lld_SPI.c",89,2
        LDR       A2, CON5              ; |89| 
;** 89	-----------------------    C$1 = &e_SPI2_ST;  // [1]
        LDR       V1, CON1              ; |89| 
;** 89	-----------------------    C$1->ctrl1_UN.ctrl1_UW.uw_Ctrl1 = C$2->uw_Ctrl1;  // [1]
        LDRH      A1, [A2, #0]          ; |89| 
        STRH      A1, [V1, #2]          ; |89| 
;** 91	-----------------------    C$1->ctrl2_UN.ctrl2_UW.uw_Ctrl2 = C$2->uw_Ctrl2;  // [1]
	.dwpsn	"lld_SPI.c",91,2
        LDRH      A1, [A2, #2]          ; |91| 
        STRH      A1, [V1, #6]          ; |91| 
;** 91	-----------------------    C$1->pc5_UN.pc5_UW.uw_PC5 = K$16 = 16;  // [1]
        MOV       A1, #16               ; |91| 
        STRH      A1, [V1, #46]         ; |91| 
;** 222	-----------------------    g_buf_UB = C$1->uw_Buf;
	.dwpsn	"lld_SPI.c",222,3
;----------------------------------------------------------------------
; 222 | g_buf_UB = e_SPI2_ST.uw_Buf;                                           
;----------------------------------------------------------------------
        LDRH      A1, [V1, #22]         ; |222| 
        LDR       V4, CON7              ; |222| 
        STRB      A1, [V4, #0]          ; |222| 
;** 225	-----------------------    C$1->uw_Dat0 = *readAddress;
	.dwpsn	"lld_SPI.c",225,3
;----------------------------------------------------------------------
; 225 | e_SPI2_ST.uw_Dat0 = *readAddress;                                      
; 227 | readAddress++;                                                         
; 228 | size--;                                                                
;----------------------------------------------------------------------
        LDRB      A1, [V3, #0]          ; |225| 
        STRH      A1, [V1, #14]         ; |225| 
;** 89	-----------------------    K$9 = C$1;  // [1]
	.dwpsn	"lld_SPI.c",89,2
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;** 231	-----------------------    goto g2;
	.dwpsn	"lld_SPI.c",231,3
;----------------------------------------------------------------------
; 231 | while ((e_SPI2_ST.ctrl3_UN.ctrl3_UW.uw_Ctrl3 & 0x0001u) == 0u)         
;----------------------------------------------------------------------
        B         L7                    ; |231| 
        ; |231| 
;* --------------------------------------------------------------------------*
L6:    
DWL$$OCSPI_ReadSync$2$B:
;**	-----------------------g1:
;** 233	-----------------------    FUN_CCtim_SystemTimerCheck_V();
	.dwpsn	"lld_SPI.c",233,5
;----------------------------------------------------------------------
; 233 | FUN_CCtim_SystemTimerCheck_V ();                                       
;----------------------------------------------------------------------
        MOV       A1, #1                ; |233| 
        MOV       LR, A1
        LDR       A1, CON8
        ADD       LR, PC
        BX        A1
        ; |233| 
DWL$$OCSPI_ReadSync$2$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L7
;* --------------------------------------------------------------------------*
L7:    
DWL$$OCSPI_ReadSync$3$B:
;**	-----------------------g2:
;** 233	-----------------------    if ( !(K$9->ctrl3_UN.ctrl3_UW.uw_Ctrl3&1) ) goto g1;
        LDRH      A1, [V1, #10]         ; |233| 
        LSR       A1, A1, #1            ; |233| 
        BCC       L6                    ; |233| 
        ; |233| 
DWL$$OCSPI_ReadSync$3$E:
;* --------------------------------------------------------------------------*
;** 222	-----------------------    K$22 = &g_buf_UB;
	.dwpsn	"lld_SPI.c",222,3
;** 237	-----------------------    *K$22 = K$9->uw_Buf;
	.dwpsn	"lld_SPI.c",237,3
;----------------------------------------------------------------------
; 237 | g_buf_UB = e_SPI2_ST.uw_Buf;                                           
;----------------------------------------------------------------------
        LDRH      A1, [V1, #22]         ; |237| 
        STRB      A1, [V4, #0]          ; |237| 
;** 240	-----------------------    K$9->uw_Dat0 = *(++readAddress);
	.dwpsn	"lld_SPI.c",240,3
;----------------------------------------------------------------------
; 240 | e_SPI2_ST.uw_Dat0 = *readAddress;                                      
;----------------------------------------------------------------------
        LDRB      A1, [V3, #1]          ; |240| 
        ADD       V3, #1                ; |240| 
        STRH      A1, [V1, #14]         ; |240| 
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;** 243	-----------------------    goto g5;
	.dwpsn	"lld_SPI.c",243,3
;----------------------------------------------------------------------
; 243 | while ((e_SPI2_ST.ctrl3_UN.ctrl3_UW.uw_Ctrl3 & 0x0001u) == 0u)         
;----------------------------------------------------------------------
        B         L9                    ; |243| 
        ; |243| 
;* --------------------------------------------------------------------------*
L8:    
DWL$$OCSPI_ReadSync$5$B:
;**	-----------------------g4:
;** 245	-----------------------    FUN_CCtim_SystemTimerCheck_V();
	.dwpsn	"lld_SPI.c",245,5
;----------------------------------------------------------------------
; 245 | FUN_CCtim_SystemTimerCheck_V ();                                       
;----------------------------------------------------------------------
        MOV       A1, #1                ; |245| 
        MOV       LR, A1
        LDR       A1, CON8
        ADD       LR, PC
        BX        A1
        ; |245| 
DWL$$OCSPI_ReadSync$5$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L9
;* --------------------------------------------------------------------------*
L9:    
DWL$$OCSPI_ReadSync$6$B:
;**	-----------------------g5:
;** 245	-----------------------    if ( !(K$9->ctrl3_UN.ctrl3_UW.uw_Ctrl3&1) ) goto g4;
        LDRH      A1, [V1, #10]         ; |245| 
        LSR       A1, A1, #1            ; |245| 
        BCC       L8                    ; |245| 
        ; |245| 
DWL$$OCSPI_ReadSync$6$E:
;* --------------------------------------------------------------------------*
;** 249	-----------------------    *K$22 = K$9->uw_Buf;
	.dwpsn	"lld_SPI.c",249,3
;----------------------------------------------------------------------
; 249 | g_buf_UB = e_SPI2_ST.uw_Buf;                                           
; 251 | readAddress++;                                                         
; 252 | size--;                                                                
;----------------------------------------------------------------------
        LDRH      A1, [V1, #22]         ; |249| 
        STRB      A1, [V4, #0]          ; |249| 
;** 255	-----------------------    K$9->uw_Dat0 = *(++readAddress);
	.dwpsn	"lld_SPI.c",255,3
;----------------------------------------------------------------------
; 255 | e_SPI2_ST.uw_Dat0 = *readAddress;                                      
;----------------------------------------------------------------------
        LDRB      A1, [V3, #1]          ; |255| 
        ADD       V3, #1                ; |255| 
        STRH      A1, [V1, #14]         ; |255| 
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;** 258	-----------------------    goto g8;
	.dwpsn	"lld_SPI.c",258,3
;----------------------------------------------------------------------
; 258 | while ((e_SPI2_ST.ctrl3_UN.ctrl3_UW.uw_Ctrl3 & 0x0001u) == 0u)         
;----------------------------------------------------------------------
        B         L11                   ; |258| 
        ; |258| 
;* --------------------------------------------------------------------------*
L10:    
DWL$$OCSPI_ReadSync$8$B:
;**	-----------------------g7:
;** 260	-----------------------    FUN_CCtim_SystemTimerCheck_V();
	.dwpsn	"lld_SPI.c",260,5
;----------------------------------------------------------------------
; 260 | FUN_CCtim_SystemTimerCheck_V ();                                       
;----------------------------------------------------------------------
        MOV       A1, #1                ; |260| 
        MOV       LR, A1
        LDR       A1, CON8
        ADD       LR, PC
        BX        A1
        ; |260| 
DWL$$OCSPI_ReadSync$8$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L11
;* --------------------------------------------------------------------------*
L11:    
DWL$$OCSPI_ReadSync$9$B:
;**	-----------------------g8:
;** 260	-----------------------    if ( !(K$9->ctrl3_UN.ctrl3_UW.uw_Ctrl3&1) ) goto g7;
        LDRH      A1, [V1, #10]         ; |260| 
        LSR       A1, A1, #1            ; |260| 
        BCC       L10                   ; |260| 
        ; |260| 
DWL$$OCSPI_ReadSync$9$E:
;* --------------------------------------------------------------------------*
;** 264	-----------------------    *K$22 = K$9->uw_Buf;
	.dwpsn	"lld_SPI.c",264,3
;----------------------------------------------------------------------
; 264 | g_buf_UB = e_SPI2_ST.uw_Buf;                                           
;----------------------------------------------------------------------
        LDRH      A1, [V1, #22]         ; |264| 
        STRB      A1, [V4, #0]          ; |264| 
;** 228	-----------------------    if ( !(size -= 3) ) goto g16;
	.dwpsn	"lld_SPI.c",228,3
        SUB       A1, V2, #3            ; |228| 
        LSL       V2, A1, #16           ; |291| 
        LSR       V2, V2, #16           ; |291| 
        BEQ       L15                   ; |228| 
        ; |228| 
;* --------------------------------------------------------------------------*
;**  	-----------------------    #pragma MUST_ITERATE(1, 65536, 1)
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;** 266	-----------------------    ++readAddress;
	.dwpsn	"lld_SPI.c",266,3
;----------------------------------------------------------------------
; 266 | readAddress++;                                                         
; 267 | size--;                                                                
; 269 | for(;size>0;size--)                                                    
;----------------------------------------------------------------------
        ADD       V3, #1                ; |266| 
;**  	-----------------------    K$36 = 0;
        MOV       V4, #0
;** 274	-----------------------    L$1 = (int)size;
	.dwpsn	"lld_SPI.c",274,5
;----------------------------------------------------------------------
; 274 | e_SPI2_ST.uw_Dat0 = 0u;                                                
;----------------------------------------------------------------------
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L12
;*
;*   Loop source line                : 269
;*   Loop closing brace source line  : 286
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 65536
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L12:    
DWL$$OCSPI_ReadSync$12$B:
;**	-----------------------g12:
;** 274	-----------------------    K$9->uw_Dat0 = K$36;
        STRH      V4, [V1, #14]         ; |274| 
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;** 277	-----------------------    goto g14;
	.dwpsn	"lld_SPI.c",277,5
;----------------------------------------------------------------------
; 277 | while ((e_SPI2_ST.ctrl3_UN.ctrl3_UW.uw_Ctrl3 & 0x0001u) == 0u)         
;----------------------------------------------------------------------
        B         L14                   ; |277| 
        ; |277| 
DWL$$OCSPI_ReadSync$12$E:
;* --------------------------------------------------------------------------*
L13:    
DWL$$OCSPI_ReadSync$13$B:
;**	-----------------------g13:
;** 279	-----------------------    FUN_CCtim_SystemTimerCheck_V();
	.dwpsn	"lld_SPI.c",279,7
;----------------------------------------------------------------------
; 279 | FUN_CCtim_SystemTimerCheck_V ();                                       
;----------------------------------------------------------------------
        MOV       A1, #1                ; |279| 
        MOV       LR, A1
        LDR       A1, CON8
        ADD       LR, PC
        BX        A1
        ; |279| 
DWL$$OCSPI_ReadSync$13$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L14
;* --------------------------------------------------------------------------*
L14:    
DWL$$OCSPI_ReadSync$14$B:
;**	-----------------------g14:
;** 279	-----------------------    if ( !(K$9->ctrl3_UN.ctrl3_UW.uw_Ctrl3&1) ) goto g13;
        LDRH      A1, [V1, #10]         ; |279| 
        LSR       A1, A1, #1            ; |279| 
        BCC       L13                   ; |279| 
        ; |279| 
DWL$$OCSPI_ReadSync$14$E:
;* --------------------------------------------------------------------------*
DWL$$OCSPI_ReadSync$15$B:
;** 283	-----------------------    *readAddress = K$9->uw_Buf;
	.dwpsn	"lld_SPI.c",283,5
;----------------------------------------------------------------------
; 283 | *readAddress = e_SPI2_ST.uw_Buf;                                       
;----------------------------------------------------------------------
        LDRH      A1, [V1, #22]         ; |283| 
        STRB      A1, [V3, #0]          ; |283| 
;** 285	-----------------------    ++readAddress;
	.dwpsn	"lld_SPI.c",285,5
;----------------------------------------------------------------------
; 285 | readAddress++;                                                         
;----------------------------------------------------------------------
        ADD       V3, #1                ; |285| 
;** 286	-----------------------    if ( --L$1 ) goto g12;
	.dwpsn	"lld_SPI.c",286,3
        SUB       V2, #1                ; |286| 
        BNE       L12                   ; |286| 
        ; |286| 
DWL$$OCSPI_ReadSync$15$E:
;* --------------------------------------------------------------------------*
L15:    
;**	-----------------------g16:
;** 289	-----------------------    K$9->pc4_UN.pc4_UW.uw_PC4 = K$16;
	.dwpsn	"lld_SPI.c",289,2
;----------------------------------------------------------------------
; 289 | e_SPI2_ST.pc4_UN.pc4_UW.uw_PC4 = SPI_cuw_SCS_PIN;                      
;----------------------------------------------------------------------
        MOV       A1, #16               ; |91| 
        STRH      A1, [V1, #42]         ; |289| 
;** 291	-----------------------    return 0;
	.dwpsn	"lld_SPI.c",291,3
;----------------------------------------------------------------------
; 291 | return IO_E_OK;                                                        
;----------------------------------------------------------------------
        MOV       A1, #0                ; |291| 
	.dwpsn	"lld_SPI.c",292,1
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}

DW$43	.dwtag  DW_TAG_loop
	.dwattr DW$43, DW_AT_name("r:/01_adlatus/04_lst/lld_SPI.asm:L12:1:1327404761")
	.dwattr DW$43, DW_AT_begin_file("lld_SPI.c")
	.dwattr DW$43, DW_AT_begin_line(0x10d)
	.dwattr DW$43, DW_AT_end_line(0x11e)
DW$44	.dwtag  DW_TAG_loop_range
	.dwattr DW$44, DW_AT_low_pc(DWL$$OCSPI_ReadSync$12$B)
	.dwattr DW$44, DW_AT_high_pc(DWL$$OCSPI_ReadSync$12$E)
DW$45	.dwtag  DW_TAG_loop_range
	.dwattr DW$45, DW_AT_low_pc(DWL$$OCSPI_ReadSync$15$B)
	.dwattr DW$45, DW_AT_high_pc(DWL$$OCSPI_ReadSync$15$E)

DW$46	.dwtag  DW_TAG_loop
	.dwattr DW$46, DW_AT_name("r:/01_adlatus/04_lst/lld_SPI.asm:L14:2:1327404761")
	.dwattr DW$46, DW_AT_begin_file("lld_SPI.c")
	.dwattr DW$46, DW_AT_begin_line(0x115)
	.dwattr DW$46, DW_AT_end_line(0x117)
DW$47	.dwtag  DW_TAG_loop_range
	.dwattr DW$47, DW_AT_low_pc(DWL$$OCSPI_ReadSync$14$B)
	.dwattr DW$47, DW_AT_high_pc(DWL$$OCSPI_ReadSync$14$E)
DW$48	.dwtag  DW_TAG_loop_range
	.dwattr DW$48, DW_AT_low_pc(DWL$$OCSPI_ReadSync$13$B)
	.dwattr DW$48, DW_AT_high_pc(DWL$$OCSPI_ReadSync$13$E)
	.dwendtag DW$46

	.dwendtag DW$43


DW$49	.dwtag  DW_TAG_loop
	.dwattr DW$49, DW_AT_name("r:/01_adlatus/04_lst/lld_SPI.asm:L11:1:1327404761")
	.dwattr DW$49, DW_AT_begin_file("lld_SPI.c")
	.dwattr DW$49, DW_AT_begin_line(0x102)
	.dwattr DW$49, DW_AT_end_line(0x104)
DW$50	.dwtag  DW_TAG_loop_range
	.dwattr DW$50, DW_AT_low_pc(DWL$$OCSPI_ReadSync$9$B)
	.dwattr DW$50, DW_AT_high_pc(DWL$$OCSPI_ReadSync$9$E)
DW$51	.dwtag  DW_TAG_loop_range
	.dwattr DW$51, DW_AT_low_pc(DWL$$OCSPI_ReadSync$8$B)
	.dwattr DW$51, DW_AT_high_pc(DWL$$OCSPI_ReadSync$8$E)
	.dwendtag DW$49


DW$52	.dwtag  DW_TAG_loop
	.dwattr DW$52, DW_AT_name("r:/01_adlatus/04_lst/lld_SPI.asm:L9:1:1327404761")
	.dwattr DW$52, DW_AT_begin_file("lld_SPI.c")
	.dwattr DW$52, DW_AT_begin_line(0xf3)
	.dwattr DW$52, DW_AT_end_line(0xf5)
DW$53	.dwtag  DW_TAG_loop_range
	.dwattr DW$53, DW_AT_low_pc(DWL$$OCSPI_ReadSync$6$B)
	.dwattr DW$53, DW_AT_high_pc(DWL$$OCSPI_ReadSync$6$E)
DW$54	.dwtag  DW_TAG_loop_range
	.dwattr DW$54, DW_AT_low_pc(DWL$$OCSPI_ReadSync$5$B)
	.dwattr DW$54, DW_AT_high_pc(DWL$$OCSPI_ReadSync$5$E)
	.dwendtag DW$52


DW$55	.dwtag  DW_TAG_loop
	.dwattr DW$55, DW_AT_name("r:/01_adlatus/04_lst/lld_SPI.asm:L7:1:1327404761")
	.dwattr DW$55, DW_AT_begin_file("lld_SPI.c")
	.dwattr DW$55, DW_AT_begin_line(0xe7)
	.dwattr DW$55, DW_AT_end_line(0xe9)
DW$56	.dwtag  DW_TAG_loop_range
	.dwattr DW$56, DW_AT_low_pc(DWL$$OCSPI_ReadSync$3$B)
	.dwattr DW$56, DW_AT_high_pc(DWL$$OCSPI_ReadSync$3$E)
DW$57	.dwtag  DW_TAG_loop_range
	.dwattr DW$57, DW_AT_low_pc(DWL$$OCSPI_ReadSync$2$B)
	.dwattr DW$57, DW_AT_high_pc(DWL$$OCSPI_ReadSync$2$E)
	.dwendtag DW$55

	.dwendentry
	.dwendtag DW$30




	.sect	".text:v$4"
	.clink
	.global	_OCSPI_WriteSync

DW$58	.dwtag  DW_TAG_subprogram, DW_AT_name("OCSPI_WriteSync"), DW_AT_symbol_name("_OCSPI_WriteSync")
	.dwattr DW$58, DW_AT_veneer(0x01)
	.dwattr DW$58, DW_AT_low_pc(_OCSPI_WriteSync)
	.dwattr DW$58, DW_AT_high_pc(0x00)
	.dwattr DW$58, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _OCSPI_WriteSync                                         *
;*****************************************************************************
_OCSPI_WriteSync:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $OCSPI_WriteSync
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$58



	.sect	".text"
	.clink
	.global	$OCSPI_WriteSync

DW$59	.dwtag  DW_TAG_subprogram, DW_AT_name("OCSPI_WriteSync"), DW_AT_symbol_name("$OCSPI_WriteSync")
	.dwattr DW$59, DW_AT_low_pc($OCSPI_WriteSync)
	.dwattr DW$59, DW_AT_high_pc(0x00)
	.dwpsn	"lld_SPI.c",295,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 294 | IO_ErrorType OCSPI_WriteSync(IO_ChannelType channel, OCSPI_MemPtrType w
;     | riteAddress, OCSPI_SizeType size)                                      
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: OCSPI_WriteSync                                            *
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
$OCSPI_WriteSync:
;* --------------------------------------------------------------------------*
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
;* A1    assigned to _channel
DW$60	.dwtag  DW_TAG_formal_parameter, DW_AT_name("channel"), DW_AT_symbol_name("_channel")
	.dwattr DW$60, DW_AT_type(*DWT$1023)
	.dwattr DW$60, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _writeAddress
DW$61	.dwtag  DW_TAG_formal_parameter, DW_AT_name("writeAddress"), DW_AT_symbol_name("_writeAddress")
	.dwattr DW$61, DW_AT_type(*DWT$1020)
	.dwattr DW$61, DW_AT_location[DW_OP_reg1]
;* A3    assigned to _size
DW$62	.dwtag  DW_TAG_formal_parameter, DW_AT_name("size"), DW_AT_symbol_name("_size")
	.dwattr DW$62, DW_AT_type(*DWT$1025)
	.dwattr DW$62, DW_AT_location[DW_OP_reg2]
;* V3    assigned to C$1
DW$63	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$63, DW_AT_type(*DWT$1021)
	.dwattr DW$63, DW_AT_location[DW_OP_reg6]
;* V1    assigned to C$2
DW$64	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$64, DW_AT_type(*DWT$1137)
	.dwattr DW$64, DW_AT_location[DW_OP_reg4]
;* A2    assigned to C$3
DW$65	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$65, DW_AT_type(*DWT$1039)
	.dwattr DW$65, DW_AT_location[DW_OP_reg1]
;* V2    assigned to _size
DW$66	.dwtag  DW_TAG_variable, DW_AT_name("size"), DW_AT_symbol_name("_size")
	.dwattr DW$66, DW_AT_type(*DWT$1025)
	.dwattr DW$66, DW_AT_location[DW_OP_reg5]
;* V4    assigned to _writeAddress
DW$67	.dwtag  DW_TAG_variable, DW_AT_name("writeAddress"), DW_AT_symbol_name("_writeAddress")
	.dwattr DW$67, DW_AT_type(*DWT$1020)
	.dwattr DW$67, DW_AT_location[DW_OP_reg7]
;* V2    assigned to L$1
DW$68	.dwtag  DW_TAG_variable, DW_AT_name("L$1"), DW_AT_symbol_name("L$1")
	.dwattr DW$68, DW_AT_type(*DWT$11)
	.dwattr DW$68, DW_AT_location[DW_OP_reg5]
;* A1    assigned to K$16
DW$69	.dwtag  DW_TAG_variable, DW_AT_name("K$16"), DW_AT_symbol_name("K$16")
	.dwattr DW$69, DW_AT_type(*DWT$11)
	.dwattr DW$69, DW_AT_location[DW_OP_reg0]
;* V3    assigned to K$22
DW$70	.dwtag  DW_TAG_variable, DW_AT_name("K$22"), DW_AT_symbol_name("K$22")
	.dwattr DW$70, DW_AT_type(*DWT$1021)
	.dwattr DW$70, DW_AT_location[DW_OP_reg6]
;* V1    assigned to K$9
DW$71	.dwtag  DW_TAG_variable, DW_AT_name("K$9"), DW_AT_symbol_name("K$9")
	.dwattr DW$71, DW_AT_type(*DWT$1137)
	.dwattr DW$71, DW_AT_location[DW_OP_reg4]
;----------------------------------------------------------------------
; 297 | SPI_v_SetMode(&SPI2_st_EepromMode );                                   
; 299 | e_SPI2_ST.pc5_UN.pc5_UW.uw_PC5 = SPI_cuw_SCS_PIN;                      
;----------------------------------------------------------------------
        MOV       V2, A3
        MOV       V4, A2
;** 89	-----------------------    C$3 = &SPI2_st_EepromMode;  // [1]
	.dwpsn	"lld_SPI.c",89,2
        LDR       A2, CON5              ; |89| 
;** 89	-----------------------    C$2 = &e_SPI2_ST;  // [1]
        LDR       V1, CON1              ; |89| 
;** 89	-----------------------    C$2->ctrl1_UN.ctrl1_UW.uw_Ctrl1 = C$3->uw_Ctrl1;  // [1]
        LDRH      A1, [A2, #0]          ; |89| 
        STRH      A1, [V1, #2]          ; |89| 
;** 91	-----------------------    C$2->ctrl2_UN.ctrl2_UW.uw_Ctrl2 = C$3->uw_Ctrl2;  // [1]
	.dwpsn	"lld_SPI.c",91,2
        LDRH      A1, [A2, #2]          ; |91| 
        STRH      A1, [V1, #6]          ; |91| 
;** 91	-----------------------    C$2->pc5_UN.pc5_UW.uw_PC5 = K$16 = 16;  // [1]
        MOV       A1, #16               ; |91| 
        STRH      A1, [V1, #46]         ; |91| 
;** 302	-----------------------    C$1 = &g_buf_UB;
	.dwpsn	"lld_SPI.c",302,3
;----------------------------------------------------------------------
; 302 | g_buf_UB = e_SPI2_ST.uw_Buf;                                           
;----------------------------------------------------------------------
        LDR       V3, CON7              ; |302| 
;** 302	-----------------------    *C$1 = C$2->uw_Buf;
        LDRH      A1, [V1, #22]         ; |302| 
        STRB      A1, [V3, #0]          ; |302| 
;** 89	-----------------------    K$9 = C$2;  // [1]
	.dwpsn	"lld_SPI.c",89,2
;** 304	-----------------------    if ( !size ) goto g7;
	.dwpsn	"lld_SPI.c",304,3
;----------------------------------------------------------------------
; 304 | for(;size > (UBYTE) 0x00u;size--)                                      
;----------------------------------------------------------------------
        CMP       V2, #0                ; |304| 
        BEQ       L19                   ; |304| 
        ; |304| 
;* --------------------------------------------------------------------------*
;**  	-----------------------    #pragma MUST_ITERATE(1, 65536, 1)
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;** 307	-----------------------    L$1 = (int)size;
	.dwpsn	"lld_SPI.c",307,5
;----------------------------------------------------------------------
; 307 | e_SPI2_ST.uw_Dat0 = *writeAddress;                                     
;----------------------------------------------------------------------
;** 302	-----------------------    K$22 = C$1;
	.dwpsn	"lld_SPI.c",302,3
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L16
;*
;*   Loop source line                : 304
;*   Loop closing brace source line  : 319
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 65536
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L16:    
DWL$$OCSPI_WriteSync$3$B:
;**	-----------------------g3:
;** 307	-----------------------    K$9->uw_Dat0 = *writeAddress;
	.dwpsn	"lld_SPI.c",307,5
;----------------------------------------------------------------------
; 309 | writeAddress++;                                                        
;----------------------------------------------------------------------
        LDRB      A1, [V4, #0]          ; |307| 
        STRH      A1, [V1, #14]         ; |307| 
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;** 312	-----------------------    goto g5;
	.dwpsn	"lld_SPI.c",312,5
;----------------------------------------------------------------------
; 312 | while ((e_SPI2_ST.ctrl3_UN.ctrl3_UW.uw_Ctrl3 & 0x0001u) == 0u)         
;----------------------------------------------------------------------
        B         L18                   ; |312| 
        ; |312| 
DWL$$OCSPI_WriteSync$3$E:
;* --------------------------------------------------------------------------*
L17:    
DWL$$OCSPI_WriteSync$4$B:
;**	-----------------------g4:
;** 314	-----------------------    FUN_CCtim_SystemTimerCheck_V();
	.dwpsn	"lld_SPI.c",314,7
;----------------------------------------------------------------------
; 314 | FUN_CCtim_SystemTimerCheck_V ();                                       
;----------------------------------------------------------------------
        MOV       A1, #1                ; |314| 
        MOV       LR, A1
        LDR       A1, CON8
        ADD       LR, PC
        BX        A1
        ; |314| 
DWL$$OCSPI_WriteSync$4$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L18
;* --------------------------------------------------------------------------*
L18:    
DWL$$OCSPI_WriteSync$5$B:
;**	-----------------------g5:
;** 314	-----------------------    if ( !(K$9->ctrl3_UN.ctrl3_UW.uw_Ctrl3&1) ) goto g4;
        LDRH      A1, [V1, #10]         ; |314| 
        LSR       A1, A1, #1            ; |314| 
        BCC       L17                   ; |314| 
        ; |314| 
DWL$$OCSPI_WriteSync$5$E:
;* --------------------------------------------------------------------------*
DWL$$OCSPI_WriteSync$6$B:
;** 318	-----------------------    *K$22 = K$9->uw_Buf;
	.dwpsn	"lld_SPI.c",318,5
;----------------------------------------------------------------------
; 318 | g_buf_UB = e_SPI2_ST.uw_Buf;                                           
;----------------------------------------------------------------------
        LDRH      A1, [V1, #22]         ; |318| 
        STRB      A1, [V3, #0]          ; |318| 
;** 309	-----------------------    ++writeAddress;
	.dwpsn	"lld_SPI.c",309,5
        ADD       V4, #1                ; |309| 
;** 319	-----------------------    if ( --L$1 ) goto g3;
	.dwpsn	"lld_SPI.c",319,3
        SUB       V2, #1                ; |319| 
        BNE       L16                   ; |319| 
        ; |319| 
DWL$$OCSPI_WriteSync$6$E:
;* --------------------------------------------------------------------------*
L19:    
;**	-----------------------g7:
;** 321	-----------------------    K$9->pc4_UN.pc4_UW.uw_PC4 = K$16;
	.dwpsn	"lld_SPI.c",321,2
;----------------------------------------------------------------------
; 321 | e_SPI2_ST.pc4_UN.pc4_UW.uw_PC4 = SPI_cuw_SCS_PIN;                      
;----------------------------------------------------------------------
        MOV       A1, #16               ; |91| 
        STRH      A1, [V1, #42]         ; |321| 
;** 323	-----------------------    return 0;
	.dwpsn	"lld_SPI.c",323,3
;----------------------------------------------------------------------
; 323 | return IO_E_OK;                                                        
;----------------------------------------------------------------------
        MOV       A1, #0                ; |323| 
	.dwpsn	"lld_SPI.c",324,1
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}

DW$72	.dwtag  DW_TAG_loop
	.dwattr DW$72, DW_AT_name("r:/01_adlatus/04_lst/lld_SPI.asm:L16:1:1327404761")
	.dwattr DW$72, DW_AT_begin_file("lld_SPI.c")
	.dwattr DW$72, DW_AT_begin_line(0x130)
	.dwattr DW$72, DW_AT_end_line(0x13f)
DW$73	.dwtag  DW_TAG_loop_range
	.dwattr DW$73, DW_AT_low_pc(DWL$$OCSPI_WriteSync$3$B)
	.dwattr DW$73, DW_AT_high_pc(DWL$$OCSPI_WriteSync$3$E)
DW$74	.dwtag  DW_TAG_loop_range
	.dwattr DW$74, DW_AT_low_pc(DWL$$OCSPI_WriteSync$6$B)
	.dwattr DW$74, DW_AT_high_pc(DWL$$OCSPI_WriteSync$6$E)

DW$75	.dwtag  DW_TAG_loop
	.dwattr DW$75, DW_AT_name("r:/01_adlatus/04_lst/lld_SPI.asm:L18:2:1327404761")
	.dwattr DW$75, DW_AT_begin_file("lld_SPI.c")
	.dwattr DW$75, DW_AT_begin_line(0x138)
	.dwattr DW$75, DW_AT_end_line(0x13a)
DW$76	.dwtag  DW_TAG_loop_range
	.dwattr DW$76, DW_AT_low_pc(DWL$$OCSPI_WriteSync$5$B)
	.dwattr DW$76, DW_AT_high_pc(DWL$$OCSPI_WriteSync$5$E)
DW$77	.dwtag  DW_TAG_loop_range
	.dwattr DW$77, DW_AT_low_pc(DWL$$OCSPI_WriteSync$4$B)
	.dwattr DW$77, DW_AT_high_pc(DWL$$OCSPI_WriteSync$4$E)
	.dwendtag DW$75

	.dwendtag DW$72

	.dwendentry
	.dwendtag DW$59



;; Inlined function references:
;; [  1] SPI_v_SetMode
;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON1:	.field  	_e_SPI2_ST,32
	.align	4
CON3:	.field  	65533,32
	.align	4
CON4:	.field  	_SPI2_st_Pins,32
	.align	4
CON5:	.field  	_SPI2_st_EepromMode,32
	.align	4
CON7:	.field  	_g_buf_UB,32
	.align	4
CON8:	.field  	$FUN_CCtim_SystemTimerCheck_V+1,32
;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	$FUN_CCtim_SystemTimerCheck_V
	.global	_e_SPI2_ST

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
DWT$6	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned char")
	.dwattr DWT$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr DWT$6, DW_AT_byte_size(0x01)
DWT$1018	.dwtag  DW_TAG_typedef, DW_AT_name("T_U8"), DW_AT_type(*DWT$6)
	.dwattr DWT$1018, DW_AT_language(DW_LANG_C)
DWT$1019	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1019, DW_AT_address_class(0x20)
DWT$1020	.dwtag  DW_TAG_typedef, DW_AT_name("OCSPI_MemPtrType"), DW_AT_type(*DWT$1019)
	.dwattr DWT$1020, DW_AT_language(DW_LANG_C)
DWT$1021	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$6)
	.dwattr DWT$1021, DW_AT_address_class(0x20)
DWT$1023	.dwtag  DW_TAG_typedef, DW_AT_name("IO_ChannelType"), DW_AT_type(*DWT$8)
	.dwattr DWT$1023, DW_AT_language(DW_LANG_C)
DWT$1025	.dwtag  DW_TAG_typedef, DW_AT_name("OCSPI_SizeType"), DW_AT_type(*DWT$1024)
	.dwattr DWT$1025, DW_AT_language(DW_LANG_C)
DWT$11	.dwtag  DW_TAG_base_type, DW_AT_name("int")
	.dwattr DWT$11, DW_AT_encoding(DW_ATE_signed)
	.dwattr DWT$11, DW_AT_byte_size(0x04)

DWT$1028	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1028, DW_AT_language(DW_LANG_C)

DWT$1034	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1034, DW_AT_language(DW_LANG_C)
DW$78	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1033)
	.dwendtag DWT$1034

DWT$1037	.dwtag  DW_TAG_typedef, DW_AT_name("OCSPI_ConfigType"), DW_AT_type(*DWT$1036)
	.dwattr DWT$1037, DW_AT_language(DW_LANG_C)
DWT$1032	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1031)
DWT$1033	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1032)
	.dwattr DWT$1033, DW_AT_address_class(0x20)
DWT$1039	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1038)
	.dwattr DWT$1039, DW_AT_address_class(0x20)

DWT$1042	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1041)
	.dwattr DWT$1042, DW_AT_language(DW_LANG_C)
DW$79	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1037)
	.dwendtag DWT$1042


DWT$1043	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1041)
	.dwattr DWT$1043, DW_AT_language(DW_LANG_C)

DWT$1044	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1041)
	.dwattr DWT$1044, DW_AT_language(DW_LANG_C)
DW$80	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1023)
DW$81	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1020)
DW$82	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1025)
	.dwendtag DWT$1044

DWT$1135	.dwtag  DW_TAG_typedef, DW_AT_name("SPI_ST"), DW_AT_type(*DWT$1134)
	.dwattr DWT$1135, DW_AT_language(DW_LANG_C)
DWT$1136	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1135)
	.dwattr DWT$1136, DW_AT_address_class(0x20)
DWT$1137	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1134)
	.dwattr DWT$1137, DW_AT_address_class(0x20)
DWT$1140	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1139)
DWT$1142	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1141)
	.dwattr DWT$1142, DW_AT_address_class(0x20)
DWT$8	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned short")
	.dwattr DWT$8, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$8, DW_AT_byte_size(0x02)
DWT$1024	.dwtag  DW_TAG_typedef, DW_AT_name("T_U16"), DW_AT_type(*DWT$8)
	.dwattr DWT$1024, DW_AT_language(DW_LANG_C)
DWT$1036	.dwtag  DW_TAG_pointer_type
	.dwattr DWT$1036, DW_AT_address_class(0x20)
DWT$1031	.dwtag  DW_TAG_typedef, DW_AT_name("tSpiMode"), DW_AT_type(*DWT$1030)
	.dwattr DWT$1031, DW_AT_language(DW_LANG_C)
DWT$1038	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1030)
DWT$1041	.dwtag  DW_TAG_typedef, DW_AT_name("IO_ErrorType"), DW_AT_type(*DWT$1040)
	.dwattr DWT$1041, DW_AT_language(DW_LANG_C)
DWT$1134	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1133)
DWT$1139	.dwtag  DW_TAG_typedef, DW_AT_name("tSpiPins"), DW_AT_type(*DWT$1138)
	.dwattr DWT$1139, DW_AT_language(DW_LANG_C)
DWT$1141	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1138)

DWT$1030	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1030, DW_AT_name("st_Mode")
	.dwattr DWT$1030, DW_AT_byte_size(0x06)
DW$83	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$83, DW_AT_name("uw_Ctrl1"), DW_AT_symbol_name("_uw_Ctrl1")
	.dwattr DW$83, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$83, DW_AT_accessibility(DW_ACCESS_public)
DW$84	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$84, DW_AT_name("uw_Ctrl2"), DW_AT_symbol_name("_uw_Ctrl2")
	.dwattr DW$84, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$84, DW_AT_accessibility(DW_ACCESS_public)
DW$85	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$85, DW_AT_name("uw_Ctrl3"), DW_AT_symbol_name("_uw_Ctrl3")
	.dwattr DW$85, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$85, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1030


DWT$1040	.dwtag  DW_TAG_enumeration_type
	.dwattr DWT$1040, DW_AT_byte_size(0x04)
DW$86	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_OK"), DW_AT_const_value(0x00)
DW$87	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_PARAM_IGNORED"), DW_AT_const_value(0x01)
DW$88	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_BUSY"), DW_AT_const_value(0x02)
DW$89	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_UNKNOWN_MODE"), DW_AT_const_value(0x03)
DW$90	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_INVALID_CHANNEL_ID"), DW_AT_const_value(0x04)
DW$91	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_MISSING_INIT"), DW_AT_const_value(0x05)
DW$92	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_INVALID_VALUE"), DW_AT_const_value(0x06)
DW$93	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_INVALID_SIZE"), DW_AT_const_value(0x07)
DW$94	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_INVALID_POSITION"), DW_AT_const_value(0x08)
DW$95	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_INVALID_NOTIF_TYPE"), DW_AT_const_value(0x09)
DW$96	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_ROMVERSION"), DW_AT_const_value(0x0a)
DW$97	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_TYPE_MISMATCH"), DW_AT_const_value(0x0b)
DW$98	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_FCN_SUSPENDED"), DW_AT_const_value(0x0c)
DW$99	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_FAILURE"), DW_AT_const_value(0x0d)
DW$100	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_LOCKED"), DW_AT_const_value(0x0e)
DW$101	.dwtag  DW_TAG_enumerator, DW_AT_name("IO_E_INVALID_MODE"), DW_AT_const_value(0x0f)
	.dwendtag DWT$1040


DWT$1133	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1133, DW_AT_name("spi_st")
	.dwattr DWT$1133, DW_AT_byte_size(0x34)
DW$102	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$102, DW_AT_name("ctrl1_UN"), DW_AT_symbol_name("_ctrl1_UN")
	.dwattr DW$102, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$102, DW_AT_accessibility(DW_ACCESS_public)
DW$103	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1068)
	.dwattr DW$103, DW_AT_name("ctrl2_UN"), DW_AT_symbol_name("_ctrl2_UN")
	.dwattr DW$103, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$103, DW_AT_accessibility(DW_ACCESS_public)
DW$104	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1087)
	.dwattr DW$104, DW_AT_name("ctrl3_UN"), DW_AT_symbol_name("_ctrl3_UN")
	.dwattr DW$104, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$104, DW_AT_accessibility(DW_ACCESS_public)
DW$105	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$105, DW_AT_name("uw_Dat0"), DW_AT_symbol_name("_uw_Dat0")
	.dwattr DW$105, DW_AT_data_member_location[DW_OP_plus_uconst 0xe]
	.dwattr DW$105, DW_AT_accessibility(DW_ACCESS_public)
DW$106	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$106, DW_AT_name("uw_Dat1"), DW_AT_symbol_name("_uw_Dat1")
	.dwattr DW$106, DW_AT_data_member_location[DW_OP_plus_uconst 0x12]
	.dwattr DW$106, DW_AT_accessibility(DW_ACCESS_public)
DW$107	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$107, DW_AT_name("uw_Img_Reg"), DW_AT_symbol_name("_uw_Img_Reg")
	.dwattr DW$107, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$107, DW_AT_accessibility(DW_ACCESS_public)
DW$108	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$108, DW_AT_name("uw_Buf"), DW_AT_symbol_name("_uw_Buf")
	.dwattr DW$108, DW_AT_data_member_location[DW_OP_plus_uconst 0x16]
	.dwattr DW$108, DW_AT_accessibility(DW_ACCESS_public)
DW$109	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$109, DW_AT_name("uw_Emu"), DW_AT_symbol_name("_uw_Emu")
	.dwattr DW$109, DW_AT_data_member_location[DW_OP_plus_uconst 0x1a]
	.dwattr DW$109, DW_AT_accessibility(DW_ACCESS_public)
DW$110	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1100)
	.dwattr DW$110, DW_AT_name("pc1_UN"), DW_AT_symbol_name("_pc1_UN")
	.dwattr DW$110, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$110, DW_AT_accessibility(DW_ACCESS_public)
DW$111	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1132)
	.dwattr DW$111, DW_AT_name("pc2_UN"), DW_AT_symbol_name("_pc2_UN")
	.dwattr DW$111, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr DW$111, DW_AT_accessibility(DW_ACCESS_public)
DW$112	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1105)
	.dwattr DW$112, DW_AT_name("pc3_UN"), DW_AT_symbol_name("_pc3_UN")
	.dwattr DW$112, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr DW$112, DW_AT_accessibility(DW_ACCESS_public)
DW$113	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1112)
	.dwattr DW$113, DW_AT_name("pc4_UN"), DW_AT_symbol_name("_pc4_UN")
	.dwattr DW$113, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr DW$113, DW_AT_accessibility(DW_ACCESS_public)
DW$114	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1121)
	.dwattr DW$114, DW_AT_name("pc5_UN"), DW_AT_symbol_name("_pc5_UN")
	.dwattr DW$114, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr DW$114, DW_AT_accessibility(DW_ACCESS_public)
DW$115	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1128)
	.dwattr DW$115, DW_AT_name("pc6_UN"), DW_AT_symbol_name("_pc6_UN")
	.dwattr DW$115, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr DW$115, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1133


DWT$1138	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1138, DW_AT_name("st_SPI_Pins")
	.dwattr DWT$1138, DW_AT_byte_size(0x06)
DW$116	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$116, DW_AT_name("uw_PC1"), DW_AT_symbol_name("_uw_PC1")
	.dwattr DW$116, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$116, DW_AT_accessibility(DW_ACCESS_public)
DW$117	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$117, DW_AT_name("uw_PC3"), DW_AT_symbol_name("_uw_PC3")
	.dwattr DW$117, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$117, DW_AT_accessibility(DW_ACCESS_public)
DW$118	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1022)
	.dwattr DW$118, DW_AT_name("uw_PC6"), DW_AT_symbol_name("_uw_PC6")
	.dwattr DW$118, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$118, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1138

DWT$1022	.dwtag  DW_TAG_typedef, DW_AT_name("UWORD"), DW_AT_type(*DWT$8)
	.dwattr DWT$1022, DW_AT_language(DW_LANG_C)

DWT$1054	.dwtag  DW_TAG_union_type
	.dwattr DWT$1054, DW_AT_name("spi_ctrl1")
	.dwattr DWT$1054, DW_AT_byte_size(0x04)
DW$119	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1048)
	.dwattr DW$119, DW_AT_name("ctrl1_UW"), DW_AT_symbol_name("_ctrl1_UW")
	.dwattr DW$119, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$119, DW_AT_accessibility(DW_ACCESS_public)
DW$120	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1053)
	.dwattr DW$120, DW_AT_name("ctrl1_ST"), DW_AT_symbol_name("_ctrl1_ST")
	.dwattr DW$120, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$120, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1054


DWT$1068	.dwtag  DW_TAG_union_type
	.dwattr DWT$1068, DW_AT_name("spi_ctrl2")
	.dwattr DWT$1068, DW_AT_byte_size(0x04)
DW$121	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1059)
	.dwattr DW$121, DW_AT_name("ctrl2_UW"), DW_AT_symbol_name("_ctrl2_UW")
	.dwattr DW$121, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$121, DW_AT_accessibility(DW_ACCESS_public)
DW$122	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1067)
	.dwattr DW$122, DW_AT_name("ctrl2_ST"), DW_AT_symbol_name("_ctrl2_ST")
	.dwattr DW$122, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$122, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1068


DWT$1087	.dwtag  DW_TAG_union_type
	.dwattr DWT$1087, DW_AT_name("spi_ctrl3")
	.dwattr DWT$1087, DW_AT_byte_size(0x04)
DW$123	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1076)
	.dwattr DW$123, DW_AT_name("ctrl3_UW"), DW_AT_symbol_name("_ctrl3_UW")
	.dwattr DW$123, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$123, DW_AT_accessibility(DW_ACCESS_public)
DW$124	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1086)
	.dwattr DW$124, DW_AT_name("ctrl3_ST"), DW_AT_symbol_name("_ctrl3_ST")
	.dwattr DW$124, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$124, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1087


DWT$1100	.dwtag  DW_TAG_union_type
	.dwattr DWT$1100, DW_AT_byte_size(0x04)
DW$125	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1097)
	.dwattr DW$125, DW_AT_name("pc1_UW"), DW_AT_symbol_name("_pc1_UW")
	.dwattr DW$125, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$125, DW_AT_accessibility(DW_ACCESS_public)
DW$126	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1099)
	.dwattr DW$126, DW_AT_name("pc1_ST"), DW_AT_symbol_name("_pc1_ST")
	.dwattr DW$126, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$126, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1100


DWT$1105	.dwtag  DW_TAG_union_type
	.dwattr DWT$1105, DW_AT_byte_size(0x04)
DW$127	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1102)
	.dwattr DW$127, DW_AT_name("pc3_UW"), DW_AT_symbol_name("_pc3_UW")
	.dwattr DW$127, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$127, DW_AT_accessibility(DW_ACCESS_public)
DW$128	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1104)
	.dwattr DW$128, DW_AT_name("pc3_ST"), DW_AT_symbol_name("_pc3_ST")
	.dwattr DW$128, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$128, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1105


DWT$1112	.dwtag  DW_TAG_union_type
	.dwattr DWT$1112, DW_AT_byte_size(0x04)
DW$129	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1107)
	.dwattr DW$129, DW_AT_name("pc4_UW"), DW_AT_symbol_name("_pc4_UW")
	.dwattr DW$129, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$129, DW_AT_accessibility(DW_ACCESS_public)
DW$130	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1111)
	.dwattr DW$130, DW_AT_name("pc4_ST"), DW_AT_symbol_name("_pc4_ST")
	.dwattr DW$130, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$130, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1112


DWT$1121	.dwtag  DW_TAG_union_type
	.dwattr DWT$1121, DW_AT_byte_size(0x04)
DW$131	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1116)
	.dwattr DW$131, DW_AT_name("pc5_UW"), DW_AT_symbol_name("_pc5_UW")
	.dwattr DW$131, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$131, DW_AT_accessibility(DW_ACCESS_public)
DW$132	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1120)
	.dwattr DW$132, DW_AT_name("pc5_ST"), DW_AT_symbol_name("_pc5_ST")
	.dwattr DW$132, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$132, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1121


DWT$1128	.dwtag  DW_TAG_union_type
	.dwattr DWT$1128, DW_AT_byte_size(0x04)
DW$133	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1125)
	.dwattr DW$133, DW_AT_name("pc6_UW"), DW_AT_symbol_name("_pc6_UW")
	.dwattr DW$133, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$133, DW_AT_accessibility(DW_ACCESS_public)
DW$134	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1127)
	.dwattr DW$134, DW_AT_name("pc6_ST"), DW_AT_symbol_name("_pc6_ST")
	.dwattr DW$134, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$134, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1128


DWT$1132	.dwtag  DW_TAG_union_type
	.dwattr DWT$1132, DW_AT_byte_size(0x04)
DW$135	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1130)
	.dwattr DW$135, DW_AT_name("pc2_UW"), DW_AT_symbol_name("_pc2_UW")
	.dwattr DW$135, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$135, DW_AT_accessibility(DW_ACCESS_public)
DW$136	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1131)
	.dwattr DW$136, DW_AT_name("pc2_ST"), DW_AT_symbol_name("_pc2_ST")
	.dwattr DW$136, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$136, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1132


DWT$1048	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1048, DW_AT_byte_size(0x04)
DW$137	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$137, DW_AT_name("uw_Ctrl1"), DW_AT_symbol_name("_uw_Ctrl1")
	.dwattr DW$137, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$137, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1048


DWT$1053	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1053, DW_AT_byte_size(0x04)
DW$138	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$138, DW_AT_name("TapSel_B8"), DW_AT_symbol_name("_TapSel_B8")
	.dwattr DW$138, DW_AT_bit_offset(0x13), DW_AT_bit_size(0x08)
	.dwattr DW$138, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$138, DW_AT_accessibility(DW_ACCESS_public)
DW$139	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$139, DW_AT_name("CharLen_B5"), DW_AT_symbol_name("_CharLen_B5")
	.dwattr DW$139, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x05)
	.dwattr DW$139, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$139, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1053


DWT$1059	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1059, DW_AT_byte_size(0x04)
DW$140	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$140, DW_AT_name("uw_Ctrl2"), DW_AT_symbol_name("_uw_Ctrl2")
	.dwattr DW$140, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$140, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1059


DWT$1067	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1067, DW_AT_byte_size(0x04)
DW$141	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$141, DW_AT_name("ClkMod_B1"), DW_AT_symbol_name("_ClkMod_B1")
	.dwattr DW$141, DW_AT_bit_offset(0x1a), DW_AT_bit_size(0x01)
	.dwattr DW$141, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$141, DW_AT_accessibility(DW_ACCESS_public)
DW$142	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$142, DW_AT_name("SpiEN_B1"), DW_AT_symbol_name("_SpiEN_B1")
	.dwattr DW$142, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$142, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$142, DW_AT_accessibility(DW_ACCESS_public)
DW$143	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$143, DW_AT_name("Master_B1"), DW_AT_symbol_name("_Master_B1")
	.dwattr DW$143, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$143, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$143, DW_AT_accessibility(DW_ACCESS_public)
DW$144	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$144, DW_AT_name("PowerDown_B1"), DW_AT_symbol_name("_PowerDown_B1")
	.dwattr DW$144, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$144, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$144, DW_AT_accessibility(DW_ACCESS_public)
DW$145	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$145, DW_AT_name("Polarity_B1"), DW_AT_symbol_name("_Polarity_B1")
	.dwattr DW$145, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$145, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$145, DW_AT_accessibility(DW_ACCESS_public)
DW$146	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$146, DW_AT_name("Phase_B1"), DW_AT_symbol_name("_Phase_B1")
	.dwattr DW$146, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$146, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$146, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1067


DWT$1076	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1076, DW_AT_byte_size(0x04)
DW$147	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$147, DW_AT_name("uw_Ctrl3"), DW_AT_symbol_name("_uw_Ctrl3")
	.dwattr DW$147, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$147, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1076


DWT$1086	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1086, DW_AT_byte_size(0x04)
DW$148	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$148, DW_AT_name("TriStateEN_B1"), DW_AT_symbol_name("_TriStateEN_B1")
	.dwattr DW$148, DW_AT_bit_offset(0x1a), DW_AT_bit_size(0x01)
	.dwattr DW$148, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$148, DW_AT_accessibility(DW_ACCESS_public)
DW$149	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$149, DW_AT_name("DmaReqEN_B1"), DW_AT_symbol_name("_DmaReqEN_B1")
	.dwattr DW$149, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$149, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$149, DW_AT_accessibility(DW_ACCESS_public)
DW$150	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$150, DW_AT_name("OvrnIntEN_B1"), DW_AT_symbol_name("_OvrnIntEN_B1")
	.dwattr DW$150, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$150, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$150, DW_AT_accessibility(DW_ACCESS_public)
DW$151	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$151, DW_AT_name("RcvrOvrn_B1"), DW_AT_symbol_name("_RcvrOvrn_B1")
	.dwattr DW$151, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$151, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$151, DW_AT_accessibility(DW_ACCESS_public)
DW$152	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$152, DW_AT_name("IntEN_B1"), DW_AT_symbol_name("_IntEN_B1")
	.dwattr DW$152, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$152, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$152, DW_AT_accessibility(DW_ACCESS_public)
DW$153	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$153, DW_AT_name("IntFlag_B1"), DW_AT_symbol_name("_IntFlag_B1")
	.dwattr DW$153, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$153, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$153, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1086


DWT$1097	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1097, DW_AT_byte_size(0x04)
DW$154	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$154, DW_AT_name("uw_PC1"), DW_AT_symbol_name("_uw_PC1")
	.dwattr DW$154, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$154, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1097


DWT$1099	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1099, DW_AT_byte_size(0x04)
DW$155	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$155, DW_AT_name("SCSDir_B1"), DW_AT_symbol_name("_SCSDir_B1")
	.dwattr DW$155, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$155, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$155, DW_AT_accessibility(DW_ACCESS_public)
DW$156	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$156, DW_AT_name("SOMIDir_B1"), DW_AT_symbol_name("_SOMIDir_B1")
	.dwattr DW$156, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$156, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$156, DW_AT_accessibility(DW_ACCESS_public)
DW$157	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$157, DW_AT_name("SIMODir_B1"), DW_AT_symbol_name("_SIMODir_B1")
	.dwattr DW$157, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$157, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$157, DW_AT_accessibility(DW_ACCESS_public)
DW$158	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$158, DW_AT_name("ClkDir_B1"), DW_AT_symbol_name("_ClkDir_B1")
	.dwattr DW$158, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$158, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$158, DW_AT_accessibility(DW_ACCESS_public)
DW$159	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$159, DW_AT_name("EnableDir_B1"), DW_AT_symbol_name("_EnableDir_B1")
	.dwattr DW$159, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$159, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$159, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1099


DWT$1102	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1102, DW_AT_byte_size(0x04)
DW$160	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$160, DW_AT_name("uw_PC3"), DW_AT_symbol_name("_uw_PC3")
	.dwattr DW$160, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$160, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1102


DWT$1104	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1104, DW_AT_byte_size(0x04)
DW$161	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$161, DW_AT_name("SCSDout_B1"), DW_AT_symbol_name("_SCSDout_B1")
	.dwattr DW$161, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$161, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$161, DW_AT_accessibility(DW_ACCESS_public)
DW$162	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$162, DW_AT_name("SOMIDout_B1"), DW_AT_symbol_name("_SOMIDout_B1")
	.dwattr DW$162, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$162, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$162, DW_AT_accessibility(DW_ACCESS_public)
DW$163	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$163, DW_AT_name("SIMODout_B1"), DW_AT_symbol_name("_SIMODout_B1")
	.dwattr DW$163, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$163, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$163, DW_AT_accessibility(DW_ACCESS_public)
DW$164	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$164, DW_AT_name("ClkDout_B1"), DW_AT_symbol_name("_ClkDout_B1")
	.dwattr DW$164, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$164, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$164, DW_AT_accessibility(DW_ACCESS_public)
DW$165	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$165, DW_AT_name("EnableDout_B1"), DW_AT_symbol_name("_EnableDout_B1")
	.dwattr DW$165, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$165, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$165, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1104


DWT$1107	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1107, DW_AT_byte_size(0x04)
DW$166	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$166, DW_AT_name("uw_PC4"), DW_AT_symbol_name("_uw_PC4")
	.dwattr DW$166, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$166, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1107


DWT$1111	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1111, DW_AT_byte_size(0x04)
DW$167	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$167, DW_AT_name("SCSDoutSet_B1"), DW_AT_symbol_name("_SCSDoutSet_B1")
	.dwattr DW$167, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$167, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$167, DW_AT_accessibility(DW_ACCESS_public)
DW$168	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$168, DW_AT_name("SOMIDoutSet_B1"), DW_AT_symbol_name("_SOMIDoutSet_B1")
	.dwattr DW$168, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$168, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$168, DW_AT_accessibility(DW_ACCESS_public)
DW$169	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$169, DW_AT_name("SIMODoutSet_B1"), DW_AT_symbol_name("_SIMODoutSet_B1")
	.dwattr DW$169, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$169, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$169, DW_AT_accessibility(DW_ACCESS_public)
DW$170	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$170, DW_AT_name("ClkDoutSet_B1"), DW_AT_symbol_name("_ClkDoutSet_B1")
	.dwattr DW$170, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$170, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$170, DW_AT_accessibility(DW_ACCESS_public)
DW$171	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$171, DW_AT_name("EnableDoutSet_B1"), DW_AT_symbol_name("_EnableDoutSet_B1")
	.dwattr DW$171, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$171, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$171, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1111


DWT$1116	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1116, DW_AT_byte_size(0x04)
DW$172	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$172, DW_AT_name("uw_PC5"), DW_AT_symbol_name("_uw_PC5")
	.dwattr DW$172, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$172, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1116


DWT$1120	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1120, DW_AT_byte_size(0x04)
DW$173	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$173, DW_AT_name("SCSDoutClr_B1"), DW_AT_symbol_name("_SCSDoutClr_B1")
	.dwattr DW$173, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$173, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$173, DW_AT_accessibility(DW_ACCESS_public)
DW$174	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$174, DW_AT_name("SOMIDoutClr_B1"), DW_AT_symbol_name("_SOMIDoutClr_B1")
	.dwattr DW$174, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$174, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$174, DW_AT_accessibility(DW_ACCESS_public)
DW$175	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$175, DW_AT_name("SIMODoutClr_B1"), DW_AT_symbol_name("_SIMODoutClr_B1")
	.dwattr DW$175, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$175, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$175, DW_AT_accessibility(DW_ACCESS_public)
DW$176	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$176, DW_AT_name("ClkDoutClr_B1"), DW_AT_symbol_name("_ClkDoutClr_B1")
	.dwattr DW$176, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$176, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$176, DW_AT_accessibility(DW_ACCESS_public)
DW$177	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$177, DW_AT_name("EnableDoutClr_B1"), DW_AT_symbol_name("_EnableDoutClr_B1")
	.dwattr DW$177, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$177, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$177, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1120


DWT$1125	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1125, DW_AT_byte_size(0x04)
DW$178	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$178, DW_AT_name("uw_PC6"), DW_AT_symbol_name("_uw_PC6")
	.dwattr DW$178, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$178, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1125


DWT$1127	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1127, DW_AT_byte_size(0x04)
DW$179	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$179, DW_AT_name("SCSFun_B1"), DW_AT_symbol_name("_SCSFun_B1")
	.dwattr DW$179, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$179, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$179, DW_AT_accessibility(DW_ACCESS_public)
DW$180	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$180, DW_AT_name("SOMIFun_B1"), DW_AT_symbol_name("_SOMIFun_B1")
	.dwattr DW$180, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$180, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$180, DW_AT_accessibility(DW_ACCESS_public)
DW$181	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$181, DW_AT_name("SIMOFun_B1"), DW_AT_symbol_name("_SIMOFun_B1")
	.dwattr DW$181, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$181, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$181, DW_AT_accessibility(DW_ACCESS_public)
DW$182	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$182, DW_AT_name("ClkFun_B1"), DW_AT_symbol_name("_ClkFun_B1")
	.dwattr DW$182, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$182, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$182, DW_AT_accessibility(DW_ACCESS_public)
DW$183	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$183, DW_AT_name("EnableFun_B1"), DW_AT_symbol_name("_EnableFun_B1")
	.dwattr DW$183, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$183, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$183, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1127


DWT$1130	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1130, DW_AT_byte_size(0x04)
DW$184	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$184, DW_AT_name("uw_PC2"), DW_AT_symbol_name("_uw_PC2")
	.dwattr DW$184, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$184, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1130


DWT$1131	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1131, DW_AT_byte_size(0x04)
DW$185	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$185, DW_AT_name("SCSDin_B1"), DW_AT_symbol_name("_SCSDin_B1")
	.dwattr DW$185, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$185, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$185, DW_AT_accessibility(DW_ACCESS_public)
DW$186	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$186, DW_AT_name("SOMIDin_B1"), DW_AT_symbol_name("_SOMIDin_B1")
	.dwattr DW$186, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$186, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$186, DW_AT_accessibility(DW_ACCESS_public)
DW$187	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$187, DW_AT_name("SIMODin_B1"), DW_AT_symbol_name("_SIMODin_B1")
	.dwattr DW$187, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$187, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$187, DW_AT_accessibility(DW_ACCESS_public)
DW$188	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$188, DW_AT_name("ClkDin_B1"), DW_AT_symbol_name("_ClkDin_B1")
	.dwattr DW$188, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$188, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$188, DW_AT_accessibility(DW_ACCESS_public)
DW$189	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$189, DW_AT_name("EnableDin_B1"), DW_AT_symbol_name("_EnableDin_B1")
	.dwattr DW$189, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$189, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$189, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1131

DWT$10	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned int")
	.dwattr DWT$10, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$10, DW_AT_byte_size(0x04)

	.dwattr DW$15, DW_AT_external(0x01)
	.dwattr DW$15, DW_AT_type(*DWT$1041)
	.dwattr DW$13, DW_AT_external(0x01)
	.dwattr DW$7, DW_AT_external(0x01)
	.dwattr DW$7, DW_AT_type(*DWT$1041)
	.dwattr DW$30, DW_AT_external(0x01)
	.dwattr DW$30, DW_AT_type(*DWT$1041)
	.dwattr DW$59, DW_AT_external(0x01)
	.dwattr DW$59, DW_AT_type(*DWT$1041)
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

DW$190	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$190, DW_AT_location[DW_OP_reg0]
DW$191	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$191, DW_AT_location[DW_OP_reg1]
DW$192	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$192, DW_AT_location[DW_OP_reg2]
DW$193	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$193, DW_AT_location[DW_OP_reg3]
DW$194	.dwtag  DW_TAG_assign_register, DW_AT_name("V1")
	.dwattr DW$194, DW_AT_location[DW_OP_reg4]
DW$195	.dwtag  DW_TAG_assign_register, DW_AT_name("V2")
	.dwattr DW$195, DW_AT_location[DW_OP_reg5]
DW$196	.dwtag  DW_TAG_assign_register, DW_AT_name("V3")
	.dwattr DW$196, DW_AT_location[DW_OP_reg6]
DW$197	.dwtag  DW_TAG_assign_register, DW_AT_name("V4")
	.dwattr DW$197, DW_AT_location[DW_OP_reg7]
DW$198	.dwtag  DW_TAG_assign_register, DW_AT_name("V5")
	.dwattr DW$198, DW_AT_location[DW_OP_reg8]
DW$199	.dwtag  DW_TAG_assign_register, DW_AT_name("V6")
	.dwattr DW$199, DW_AT_location[DW_OP_reg9]
DW$200	.dwtag  DW_TAG_assign_register, DW_AT_name("V7")
	.dwattr DW$200, DW_AT_location[DW_OP_reg10]
DW$201	.dwtag  DW_TAG_assign_register, DW_AT_name("V8")
	.dwattr DW$201, DW_AT_location[DW_OP_reg11]
DW$202	.dwtag  DW_TAG_assign_register, DW_AT_name("V9")
	.dwattr DW$202, DW_AT_location[DW_OP_reg12]
DW$203	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$203, DW_AT_location[DW_OP_reg13]
DW$204	.dwtag  DW_TAG_assign_register, DW_AT_name("LR")
	.dwattr DW$204, DW_AT_location[DW_OP_reg14]
DW$205	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$205, DW_AT_location[DW_OP_reg15]
DW$206	.dwtag  DW_TAG_assign_register, DW_AT_name("C0")
	.dwattr DW$206, DW_AT_location[DW_OP_reg16]
DW$207	.dwtag  DW_TAG_assign_register, DW_AT_name("C1")
	.dwattr DW$207, DW_AT_location[DW_OP_reg17]
DW$208	.dwtag  DW_TAG_assign_register, DW_AT_name("C2")
	.dwattr DW$208, DW_AT_location[DW_OP_reg18]
DW$209	.dwtag  DW_TAG_assign_register, DW_AT_name("C3")
	.dwattr DW$209, DW_AT_location[DW_OP_reg19]
DW$210	.dwtag  DW_TAG_assign_register, DW_AT_name("C4")
	.dwattr DW$210, DW_AT_location[DW_OP_reg20]
DW$211	.dwtag  DW_TAG_assign_register, DW_AT_name("C5")
	.dwattr DW$211, DW_AT_location[DW_OP_reg21]
DW$212	.dwtag  DW_TAG_assign_register, DW_AT_name("C6")
	.dwattr DW$212, DW_AT_location[DW_OP_reg22]
DW$213	.dwtag  DW_TAG_assign_register, DW_AT_name("C7")
	.dwattr DW$213, DW_AT_location[DW_OP_reg23]
DW$214	.dwtag  DW_TAG_assign_register, DW_AT_name("AP")
	.dwattr DW$214, DW_AT_location[DW_OP_reg24]
DW$215	.dwtag  DW_TAG_assign_register, DW_AT_name("SR")
	.dwattr DW$215, DW_AT_location[DW_OP_reg25]
DW$216	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$216, DW_AT_location[DW_OP_reg26]
	.dwendtag DWCU

