;******************************************************************************
;* TMS470 C/C++ Codegen                                       PC Version 2.71 *
;* Date/Time created: Fri Dec 09 08:43:05 2011                                *
;******************************************************************************
	.state16

DWCU	.dwtag  DW_TAG_compile_unit
	.dwattr DWCU, DW_AT_name("FlashLib_TMS470.c")
	.dwattr DWCU, DW_AT_producer("TMS470 C/C++ Codegen PC Version 2.71 Copyright (c) 1996-2008 Texas Instruments Incorporated")
	.dwattr DWCU, DW_AT_stmt_list(0x00)
	.dwattr DWCU, DW_AT_TI_VERSION(0x01)

DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("Flash_Start_Command_B"), DW_AT_symbol_name("$Flash_Start_Command_B")
	.dwattr DW$1, DW_AT_type(*DWT$1018)
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1020)
DW$3	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$4	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$5	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1023)
DW$6	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1024)
DW$7	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1024)
	.dwendtag DW$1


DW$8	.dwtag  DW_TAG_subprogram, DW_AT_name("Flash_Prog_Data_B"), DW_AT_symbol_name("$Flash_Prog_Data_B")
	.dwattr DW$8, DW_AT_type(*DWT$1018)
	.dwattr DW$8, DW_AT_declaration(0x01)
	.dwattr DW$8, DW_AT_external(0x01)
DW$9	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1020)
DW$10	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1020)
DW$11	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$12	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$13	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$14	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1023)
DW$15	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1028)
DW$16	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$17	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1024)
	.dwendtag DW$8


DW$18	.dwtag  DW_TAG_subprogram, DW_AT_name("Flash_Status_U16"), DW_AT_symbol_name("$Flash_Status_U16")
	.dwattr DW$18, DW_AT_type(*DWT$11)
	.dwattr DW$18, DW_AT_declaration(0x01)
	.dwattr DW$18, DW_AT_external(0x01)
DW$19	.dwtag  DW_TAG_variable, DW_AT_name("e_SARRTI_ST"), DW_AT_symbol_name("_e_SARRTI_ST")
	.dwattr DW$19, DW_AT_type(*DWT$1107)
	.dwattr DW$19, DW_AT_declaration(0x01)
	.dwattr DW$19, DW_AT_external(0x01)
	.global	_fp
	.bss	_fp,4,4
DW$20	.dwtag  DW_TAG_variable, DW_AT_name("fp"), DW_AT_symbol_name("_fp")
	.dwattr DW$20, DW_AT_type(*DWT$1080)
	.dwattr DW$20, DW_AT_location[DW_OP_addr _fp]
	.dwattr DW$20, DW_AT_external(0x01)

	.sect	".const"
	.align	4
_HisHeader:
	.field  	1,8			; _HisHeader._ubInterfaceVersion @ 0
	.field  	0,8			; _HisHeader._ubReserverd @ 8
	.field  	129,8			; _HisHeader._ubMask @ 16
	.field  	1,8			; _HisHeader._ubMCU @ 24
	.field  	$FlashInit+1,32		; _HisHeader._pfnFlashInit @ 32
	.field  	$FlashDeinit+1,32		; _HisHeader._pfnFlashDeinit @ 64
	.field  	$FlashErase+1,32		; _HisHeader._pfnFlashErase @ 96
	.field  	$FlashWrite+1,32		; _HisHeader._pfnFlashWrite @ 128

	.sect	".text"
	.global	_HisHeader
DW$21	.dwtag  DW_TAG_variable, DW_AT_name("HisHeader"), DW_AT_symbol_name("_HisHeader")
	.dwattr DW$21, DW_AT_type(*DWT$1112)
	.dwattr DW$21, DW_AT_location[DW_OP_addr _HisHeader]
	.dwattr DW$21, DW_AT_external(0x01)

	.sect	".const"
	.align	4
_c_CCflash_SectorMap_AST:
	.field  	0,32			; _c_CCflash_SectorMap_AST[0]._Start_UL @ 0
	.field  	4096,32			; _c_CCflash_SectorMap_AST[0]._Length_UL @ 32
	.field  	0,16			; _c_CCflash_SectorMap_AST[0]._Sector_UW @ 64
	.field  	0,8			; _c_CCflash_SectorMap_AST[0]._Core_UB @ 80
	.field  	2,8			; _c_CCflash_SectorMap_AST[0]._FlashType_UB @ 88
	.field  	16384,32			; _c_CCflash_SectorMap_AST[1]._Start_UL @ 96
	.field  	4096,32			; _c_CCflash_SectorMap_AST[1]._Length_UL @ 128
	.field  	1,16			; _c_CCflash_SectorMap_AST[1]._Sector_UW @ 160
	.field  	0,8			; _c_CCflash_SectorMap_AST[1]._Core_UB @ 176
	.field  	2,8			; _c_CCflash_SectorMap_AST[1]._FlashType_UB @ 184
	.field  	32768,32			; _c_CCflash_SectorMap_AST[2]._Start_UL @ 192
	.field  	4096,32			; _c_CCflash_SectorMap_AST[2]._Length_UL @ 224
	.field  	2,16			; _c_CCflash_SectorMap_AST[2]._Sector_UW @ 256
	.field  	0,8			; _c_CCflash_SectorMap_AST[2]._Core_UB @ 272
	.field  	2,8			; _c_CCflash_SectorMap_AST[2]._FlashType_UB @ 280
	.field  	49152,32			; _c_CCflash_SectorMap_AST[3]._Start_UL @ 288
	.field  	4096,32			; _c_CCflash_SectorMap_AST[3]._Length_UL @ 320
	.field  	3,16			; _c_CCflash_SectorMap_AST[3]._Sector_UW @ 352
	.field  	0,8			; _c_CCflash_SectorMap_AST[3]._Core_UB @ 368
	.field  	2,8			; _c_CCflash_SectorMap_AST[3]._FlashType_UB @ 376
	.field  	65536,32			; _c_CCflash_SectorMap_AST[4]._Start_UL @ 384
	.field  	8192,32			; _c_CCflash_SectorMap_AST[4]._Length_UL @ 416
	.field  	4,16			; _c_CCflash_SectorMap_AST[4]._Sector_UW @ 448
	.field  	0,8			; _c_CCflash_SectorMap_AST[4]._Core_UB @ 464
	.field  	2,8			; _c_CCflash_SectorMap_AST[4]._FlashType_UB @ 472
	.field  	98304,32			; _c_CCflash_SectorMap_AST[5]._Start_UL @ 480
	.field  	8192,32			; _c_CCflash_SectorMap_AST[5]._Length_UL @ 512
	.field  	5,16			; _c_CCflash_SectorMap_AST[5]._Sector_UW @ 544
	.field  	0,8			; _c_CCflash_SectorMap_AST[5]._Core_UB @ 560
	.field  	2,8			; _c_CCflash_SectorMap_AST[5]._FlashType_UB @ 568
	.field  	131072,32			; _c_CCflash_SectorMap_AST[6]._Start_UL @ 576
	.field  	32768,32			; _c_CCflash_SectorMap_AST[6]._Length_UL @ 608
	.field  	6,16			; _c_CCflash_SectorMap_AST[6]._Sector_UW @ 640
	.field  	0,8			; _c_CCflash_SectorMap_AST[6]._Core_UB @ 656
	.field  	2,8			; _c_CCflash_SectorMap_AST[6]._FlashType_UB @ 664
	.field  	262144,32			; _c_CCflash_SectorMap_AST[7]._Start_UL @ 672
	.field  	32768,32			; _c_CCflash_SectorMap_AST[7]._Length_UL @ 704
	.field  	7,16			; _c_CCflash_SectorMap_AST[7]._Sector_UW @ 736
	.field  	0,8			; _c_CCflash_SectorMap_AST[7]._Core_UB @ 752
	.field  	2,8			; _c_CCflash_SectorMap_AST[7]._FlashType_UB @ 760
	.field  	393216,32			; _c_CCflash_SectorMap_AST[8]._Start_UL @ 768
	.field  	32768,32			; _c_CCflash_SectorMap_AST[8]._Length_UL @ 800
	.field  	8,16			; _c_CCflash_SectorMap_AST[8]._Sector_UW @ 832
	.field  	0,8			; _c_CCflash_SectorMap_AST[8]._Core_UB @ 848
	.field  	2,8			; _c_CCflash_SectorMap_AST[8]._FlashType_UB @ 856
	.field  	524288,32			; _c_CCflash_SectorMap_AST[9]._Start_UL @ 864
	.field  	32768,32			; _c_CCflash_SectorMap_AST[9]._Length_UL @ 896
	.field  	9,16			; _c_CCflash_SectorMap_AST[9]._Sector_UW @ 928
	.field  	1,8			; _c_CCflash_SectorMap_AST[9]._Core_UB @ 944
	.field  	2,8			; _c_CCflash_SectorMap_AST[9]._FlashType_UB @ 952
	.field  	655360,32			; _c_CCflash_SectorMap_AST[10]._Start_UL @ 960
	.field  	32768,32			; _c_CCflash_SectorMap_AST[10]._Length_UL @ 992
	.field  	10,16			; _c_CCflash_SectorMap_AST[10]._Sector_UW @ 1024
	.field  	1,8			; _c_CCflash_SectorMap_AST[10]._Core_UB @ 1040
	.field  	2,8			; _c_CCflash_SectorMap_AST[10]._FlashType_UB @ 1048

	.sect	".text"
	.global	_c_CCflash_SectorMap_AST
DW$22	.dwtag  DW_TAG_variable, DW_AT_name("c_CCflash_SectorMap_AST"), DW_AT_symbol_name("_c_CCflash_SectorMap_AST")
	.dwattr DW$22, DW_AT_type(*DWT$1117)
	.dwattr DW$22, DW_AT_location[DW_OP_addr _c_CCflash_SectorMap_AST]
	.dwattr DW$22, DW_AT_external(0x01)

	.sect	".const"
	.align	4
_C_FlashControl_ST:
	.field  	-537600,32			; _C_FlashControl_ST @ 0

	.sect	".text"
	.global	_C_FlashControl_ST
DW$23	.dwtag  DW_TAG_variable, DW_AT_name("C_FlashControl_ST"), DW_AT_symbol_name("_C_FlashControl_ST")
	.dwattr DW$23, DW_AT_type(*DWT$1078)
	.dwattr DW$23, DW_AT_location[DW_OP_addr _C_FlashControl_ST]
	.dwattr DW$23, DW_AT_external(0x01)
;	C:\CCStudio_v3.3\tms470\cgtools_271\bin\opt470.exe -v1 -q -s -O2 -e r:/10_his/04_lst/FlashLib_TMS470.if r:/10_his/04_lst/FlashLib_TMS470.opt -w r:/10_his/04_lst 

	.sect	".text:v$0"
	.clink
	.global	_FlashInit

DW$24	.dwtag  DW_TAG_subprogram, DW_AT_name("FlashInit"), DW_AT_symbol_name("_FlashInit")
	.dwattr DW$24, DW_AT_veneer(0x01)
	.dwattr DW$24, DW_AT_low_pc(_FlashInit)
	.dwattr DW$24, DW_AT_high_pc(0x00)
	.dwattr DW$24, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FlashInit                                               *
;*****************************************************************************
_FlashInit:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FlashInit+1, 32
	.state16
	.dwendtag DW$24



	.sect	".text"
	.clink
	.global	$FlashInit

DW$25	.dwtag  DW_TAG_subprogram, DW_AT_name("FlashInit"), DW_AT_symbol_name("$FlashInit")
	.dwattr DW$25, DW_AT_low_pc($FlashInit)
	.dwattr DW$25, DW_AT_high_pc(0x00)
	.dwpsn	"FlashLib_TMS470.c",239,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 238 | void FlashInit (tFlashParam *flashParam)                               
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FlashInit                                                  *
;*                                                                           *
;*   Regs Modified     : A2,A3,SR                                            *
;*   Regs Used         : A1,A2,A3,SR                                         *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FlashInit:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;* A1    assigned to _flashParam
DW$26	.dwtag  DW_TAG_formal_parameter, DW_AT_name("flashParam"), DW_AT_symbol_name("_flashParam")
	.dwattr DW$26, DW_AT_type(*DWT$1080)
	.dwattr DW$26, DW_AT_location[DW_OP_reg0]
;* A2    assigned to C$1
DW$27	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$27, DW_AT_type(*DWT$8)
	.dwattr DW$27, DW_AT_location[DW_OP_reg1]
;* A3    assigned to C$2
DW$28	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$28, DW_AT_type(*DWT$1060)
	.dwattr DW$28, DW_AT_location[DW_OP_reg2]
;* A3    assigned to C$3
DW$29	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$29, DW_AT_type(*DWT$10)
	.dwattr DW$29, DW_AT_location[DW_OP_reg2]
;* A3    assigned to C$4
DW$30	.dwtag  DW_TAG_variable, DW_AT_name("C$4"), DW_AT_symbol_name("C$4")
	.dwattr DW$30, DW_AT_type(*DWT$10)
	.dwattr DW$30, DW_AT_location[DW_OP_reg2]
;* A1    assigned to _flashParam
DW$31	.dwtag  DW_TAG_variable, DW_AT_name("flashParam"), DW_AT_symbol_name("_flashParam")
	.dwattr DW$31, DW_AT_type(*DWT$1085)
	.dwattr DW$31, DW_AT_location[DW_OP_reg0]
;** 240	-----------------------    fp = flashParam;
	.dwpsn	"FlashLib_TMS470.c",240,3
;----------------------------------------------------------------------
; 240 | fp = flashParam;                                                       
;----------------------------------------------------------------------
        LDR       A2, CON1              ; |240| 
        STR       A1, [A2, #0]          ; |240| 
;** 242	-----------------------    flashParam->majornumber = 1u;
	.dwpsn	"FlashLib_TMS470.c",242,3
;----------------------------------------------------------------------
; 242 | flashParam->majornumber  = FLASH_DRIVER_VERSION_MAJOR;                 
;----------------------------------------------------------------------
        MOV       A2, #1                ; |242| 
        STRB      A2, [A1, #2]          ; |242| 
;** 243	-----------------------    flashParam->minornumber = 48u;
	.dwpsn	"FlashLib_TMS470.c",243,3
;----------------------------------------------------------------------
; 243 | flashParam->minornumber  = FLASH_DRIVER_VERSION_MINOR;                 
;----------------------------------------------------------------------
        MOV       A2, #48               ; |243| 
        STRB      A2, [A1, #1]          ; |243| 
;** 244	-----------------------    flashParam->patchlevel = 0u;
	.dwpsn	"FlashLib_TMS470.c",244,3
;----------------------------------------------------------------------
; 244 | flashParam->patchlevel   = FLASH_DRIVER_VERSION_PATCH;                 
;----------------------------------------------------------------------
        MOV       A2, #0                ; |244| 
        STRB      A2, [A1, #0]          ; |244| 
;** 245	-----------------------    flashParam->errorcode = C$1 = 0u;
	.dwpsn	"FlashLib_TMS470.c",245,3
;----------------------------------------------------------------------
; 245 | flashParam->errorcode    = kFlashOK;                                   
;----------------------------------------------------------------------
        STRH      A2, [A1, #4]          ; |245| 
;** 246	-----------------------    flashParam->address = C$4 = C$3 = 0u;
	.dwpsn	"FlashLib_TMS470.c",246,3
;----------------------------------------------------------------------
; 246 | flashParam->address      = 0x00;                                       
;----------------------------------------------------------------------
        MOV       A3, A2
        STR       A2, [A1, #8]          ; |246| 
;** 247	-----------------------    flashParam->length = C$4;
	.dwpsn	"FlashLib_TMS470.c",247,3
;----------------------------------------------------------------------
; 247 | flashParam->length       = 0x00;                                       
;----------------------------------------------------------------------
        STR       A3, [A1, #12]         ; |247| 
;** 248	-----------------------    flashParam->data = C$2 = (unsigned char *)C$3;
	.dwpsn	"FlashLib_TMS470.c",248,3
;----------------------------------------------------------------------
; 248 | flashParam->data         = 0x00;                                       
;----------------------------------------------------------------------
        STR       A3, [A1, #16]         ; |248| 
;** 250	-----------------------    flashParam->wdTriggerFct = (void (*)())C$2;
	.dwpsn	"FlashLib_TMS470.c",250,3
;----------------------------------------------------------------------
; 250 | flashParam->wdTriggerFct = 0x00000000; /* (tWDTriggerFct)FlashExtWatchd
;     | og_V; */                                                               
;----------------------------------------------------------------------
        STR       A3, [A1, #20]         ; |250| 
;** 252	-----------------------    flashParam->StartSector_US = C$1;
	.dwpsn	"FlashLib_TMS470.c",252,3
;----------------------------------------------------------------------
; 252 | flashParam->StartSector_US  = 0;  /* command byte */                   
;----------------------------------------------------------------------
        STRH      A2, [A1, #36]         ; |252| 
;** 253	-----------------------    flashParam->EndSector_US = C$1;
	.dwpsn	"FlashLib_TMS470.c",253,3
;----------------------------------------------------------------------
; 253 | flashParam->EndSector_US    = 0;  /* command byte */                   
;----------------------------------------------------------------------
        STRH      A2, [A1, #38]         ; |253| 
;** 254	-----------------------    flashParam->NbrOfSectors_US = C$1;
	.dwpsn	"FlashLib_TMS470.c",254,3
;----------------------------------------------------------------------
; 254 | flashParam->NbrOfSectors_US = 0;  /* command byte */                   
;----------------------------------------------------------------------
        STRH      A2, [A1, #40]         ; |254| 
;** 255	-----------------------    flashParam->ActualSector_US = C$1;
	.dwpsn	"FlashLib_TMS470.c",255,3
;----------------------------------------------------------------------
; 255 | flashParam->ActualSector_US = 0;  /* command byte */                   
;----------------------------------------------------------------------
        STRH      A2, [A1, #42]         ; |255| 
;** 260	-----------------------    return;
	.dwpsn	"FlashLib_TMS470.c",260,3
;----------------------------------------------------------------------
; 260 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"FlashLib_TMS470.c",262,1
        BX        LR
	.dwendentry
	.dwendtag DW$25




	.sect	".text:v$1"
	.clink
	.global	_FlashDeinit

DW$32	.dwtag  DW_TAG_subprogram, DW_AT_name("FlashDeinit"), DW_AT_symbol_name("_FlashDeinit")
	.dwattr DW$32, DW_AT_veneer(0x01)
	.dwattr DW$32, DW_AT_low_pc(_FlashDeinit)
	.dwattr DW$32, DW_AT_high_pc(0x00)
	.dwattr DW$32, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FlashDeinit                                             *
;*****************************************************************************
_FlashDeinit:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FlashDeinit+1, 32
	.state16
	.dwendtag DW$32



	.sect	".text"
	.clink
	.global	$FlashDeinit

DW$33	.dwtag  DW_TAG_subprogram, DW_AT_name("FlashDeinit"), DW_AT_symbol_name("$FlashDeinit")
	.dwattr DW$33, DW_AT_low_pc($FlashDeinit)
	.dwattr DW$33, DW_AT_high_pc(0x00)
	.dwpsn	"FlashLib_TMS470.c",277,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 276 | void FlashDeinit (tFlashParam *flashParam)                             
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FlashDeinit                                                *
;*                                                                           *
;*   Regs Modified     : A2,SR                                               *
;*   Regs Used         : A1,A2,SR                                            *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FlashDeinit:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;* A1    assigned to _flashParam
DW$34	.dwtag  DW_TAG_formal_parameter, DW_AT_name("flashParam"), DW_AT_symbol_name("_flashParam")
	.dwattr DW$34, DW_AT_type(*DWT$1080)
	.dwattr DW$34, DW_AT_location[DW_OP_reg0]
;* A2    assigned to C$1
DW$35	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$35, DW_AT_type(*DWT$1060)
	.dwattr DW$35, DW_AT_location[DW_OP_reg1]
;* A2    assigned to C$2
DW$36	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$36, DW_AT_type(*DWT$10)
	.dwattr DW$36, DW_AT_location[DW_OP_reg1]
;* A2    assigned to C$3
DW$37	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$37, DW_AT_type(*DWT$10)
	.dwattr DW$37, DW_AT_location[DW_OP_reg1]
;* A2    assigned to C$4
DW$38	.dwtag  DW_TAG_variable, DW_AT_name("C$4"), DW_AT_symbol_name("C$4")
	.dwattr DW$38, DW_AT_type(*DWT$6)
	.dwattr DW$38, DW_AT_location[DW_OP_reg1]
;* A1    assigned to _flashParam
DW$39	.dwtag  DW_TAG_variable, DW_AT_name("flashParam"), DW_AT_symbol_name("_flashParam")
	.dwattr DW$39, DW_AT_type(*DWT$1085)
	.dwattr DW$39, DW_AT_location[DW_OP_reg0]
;** 278	-----------------------    flashParam->majornumber = C$4 = 0u;
	.dwpsn	"FlashLib_TMS470.c",278,3
;----------------------------------------------------------------------
; 278 | flashParam->majornumber = 0x00;                                        
;----------------------------------------------------------------------
        MOV       A2, #0                ; |278| 
        STRB      A2, [A1, #2]          ; |278| 
;** 279	-----------------------    flashParam->minornumber = C$4;
	.dwpsn	"FlashLib_TMS470.c",279,3
;----------------------------------------------------------------------
; 279 | flashParam->minornumber = 0x00;                                        
;----------------------------------------------------------------------
        STRB      A2, [A1, #1]          ; |279| 
;** 280	-----------------------    flashParam->patchlevel = C$4;
	.dwpsn	"FlashLib_TMS470.c",280,3
;----------------------------------------------------------------------
; 280 | flashParam->patchlevel  = 0x00;                                        
;----------------------------------------------------------------------
        STRB      A2, [A1, #0]          ; |280| 
;** 281	-----------------------    flashParam->errorcode = 0u;
	.dwpsn	"FlashLib_TMS470.c",281,3
;----------------------------------------------------------------------
; 281 | flashParam->errorcode   = 0x00;                                        
;----------------------------------------------------------------------
        STRH      A2, [A1, #4]          ; |281| 
;** 282	-----------------------    flashParam->address = C$3 = C$2 = 0u;
	.dwpsn	"FlashLib_TMS470.c",282,3
;----------------------------------------------------------------------
; 282 | flashParam->address     = 0x00;                                        
;----------------------------------------------------------------------
        STR       A2, [A1, #8]          ; |282| 
;** 283	-----------------------    flashParam->length = C$3;
	.dwpsn	"FlashLib_TMS470.c",283,3
;----------------------------------------------------------------------
; 283 | flashParam->length      = 0x00;                                        
;----------------------------------------------------------------------
        STR       A2, [A1, #12]         ; |283| 
;** 284	-----------------------    flashParam->data = C$1 = (unsigned char *)C$2;
	.dwpsn	"FlashLib_TMS470.c",284,3
;----------------------------------------------------------------------
; 284 | flashParam->data        = 0x00;                                        
;----------------------------------------------------------------------
        STR       A2, [A1, #16]         ; |284| 
;** 285	-----------------------    flashParam->wdTriggerFct = (void (*)())C$1;
	.dwpsn	"FlashLib_TMS470.c",285,3
;----------------------------------------------------------------------
; 285 | flashParam->wdTriggerFct = 0x00000000ul;                               
;----------------------------------------------------------------------
        STR       A2, [A1, #20]         ; |285| 
;** 290	-----------------------    return;
	.dwpsn	"FlashLib_TMS470.c",290,3
;----------------------------------------------------------------------
; 290 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"FlashLib_TMS470.c",292,1
        BX        LR
	.dwendentry
	.dwendtag DW$33




	.sect	".text:v$2"
	.clink
	.global	_FlashErase

DW$40	.dwtag  DW_TAG_subprogram, DW_AT_name("FlashErase"), DW_AT_symbol_name("_FlashErase")
	.dwattr DW$40, DW_AT_veneer(0x01)
	.dwattr DW$40, DW_AT_low_pc(_FlashErase)
	.dwattr DW$40, DW_AT_high_pc(0x00)
	.dwattr DW$40, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FlashErase                                              *
;*****************************************************************************
_FlashErase:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FlashErase
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$40



	.sect	".text"
	.clink
	.global	$FlashErase

DW$41	.dwtag  DW_TAG_subprogram, DW_AT_name("FlashErase"), DW_AT_symbol_name("$FlashErase")
	.dwattr DW$41, DW_AT_low_pc($FlashErase)
	.dwattr DW$41, DW_AT_high_pc(0x00)
	.dwpsn	"FlashLib_TMS470.c",308,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 307 | void FlashErase(tFlashParam *flashParam)                               
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FlashErase                                                 *
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
$FlashErase:
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
;* A1    assigned to _flashParam
DW$42	.dwtag  DW_TAG_formal_parameter, DW_AT_name("flashParam"), DW_AT_symbol_name("_flashParam")
	.dwattr DW$42, DW_AT_type(*DWT$1080)
	.dwattr DW$42, DW_AT_location[DW_OP_reg0]
;* A2    assigned to C$1
DW$43	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$43, DW_AT_type(*DWT$8)
	.dwattr DW$43, DW_AT_location[DW_OP_reg1]
;* V3    assigned to C$2
DW$44	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$44, DW_AT_type(*DWT$8)
	.dwattr DW$44, DW_AT_location[DW_OP_reg6]
;* V2    assigned to _flashParam
DW$45	.dwtag  DW_TAG_variable, DW_AT_name("flashParam"), DW_AT_symbol_name("_flashParam")
	.dwattr DW$45, DW_AT_type(*DWT$1085)
	.dwattr DW$45, DW_AT_location[DW_OP_reg5]
;* V1    assigned to K$22
DW$46	.dwtag  DW_TAG_variable, DW_AT_name("K$22"), DW_AT_symbol_name("K$22")
	.dwattr DW$46, DW_AT_type(*DWT$11)
	.dwattr DW$46, DW_AT_location[DW_OP_reg4]
;* V4    assigned to U$9
DW$47	.dwtag  DW_TAG_variable, DW_AT_name("U$9"), DW_AT_symbol_name("U$9")
	.dwattr DW$47, DW_AT_type(*DWT$1035)
	.dwattr DW$47, DW_AT_location[DW_OP_reg7]
;----------------------------------------------------------------------
; 309 | ULONG ulAdr;                                                           
; 311 | volatile ULONG t_Start_UL;                                             
; 312 | volatile ULONG t_Core_UL;                                              
; 313 | volatile ULONG t_Delay_UL;                                             
; 314 | volatile ULONG t_Control_UL;                                           
; 316 | ulAdr = flashParam->address;                                           
;----------------------------------------------------------------------
        MOV       V2, A1
;** 321	-----------------------    C$2 = flashParam->errorcode;
	.dwpsn	"FlashLib_TMS470.c",321,3
;----------------------------------------------------------------------
; 321 | if ( (flashParam->errorcode) & kFlashEraseBusy )                       
; 326 |   flashParam->errorcode = kFlashOK;                                    
; 334 |   flashParam->errorcode = FlashEraseSector(flashParam);                
; 339 |   if ((UWORD)ERASE_SUCCESSFUL == flashParam->errorcode)                
; 344 |     flashParam->errorcode = kFlashOK;                                  
; 349 |     if ( flashParam->ActualSector_US > flashParam->EndSector_US )      
; 354 |       flashParam->errorcode |= kFlashEraseBusy;                        
; 359 |       flashParam->ActualSector_US--;                                   
; 367 | else                                                                   
;----------------------------------------------------------------------
        LDRH      V3, [V2, #4]          ; |321| 
;** 321	-----------------------    if ( C$2&0x40 ) goto g3;
        LSR       A2, V3, #7            ; |321| 
        BCS       L1                    ; |321| 
        ; |321| 
;* --------------------------------------------------------------------------*
;** 372	-----------------------    if ( (U$9 = flashParam->address) > 786431u ) goto g6;
	.dwpsn	"FlashLib_TMS470.c",372,5
;----------------------------------------------------------------------
; 372 | if (ulAdr <= FLASH_END)  /* ProgramFlash */                            
;----------------------------------------------------------------------
        LDR       V4, [V2, #8]          ; |372| 
        LDR       A1, CON2              ; |372| 
        CMP       V4, A1                ; |372| 
        BHI       L2                    ; |372| 
        ; |372| 
;* --------------------------------------------------------------------------*
;** 377	-----------------------    flashParam->StartSector_US = GetEraseStartSector(U$9, flashParam->length);
	.dwpsn	"FlashLib_TMS470.c",377,7
;----------------------------------------------------------------------
; 377 | flashParam->StartSector_US = GetEraseStartSector(flashParam->address, f
;     | lashParam->length );                                                   
;----------------------------------------------------------------------
        LDR       A2, [V2, #12]         ; |377| 
        MOV       A1, V4
        MOV       V1, #1                ; |377| 
        MOV       LR, V1
        LDR       A3, CON3
        ADD       LR, PC
        BX        A3
        ; |377| 
        STRH      A1, [V2, #36]         ; |377| 
;** 378	-----------------------    flashParam->EndSector_US = GetEraseEndSector(U$9);
	.dwpsn	"FlashLib_TMS470.c",378,7
;----------------------------------------------------------------------
; 378 | flashParam->EndSector_US   = GetEraseEndSector(flashParam->address);   
;----------------------------------------------------------------------
        MOV       A1, V4
        MOV       LR, V1
        LDR       A2, CON4
        ADD       LR, PC
        BX        A2
        ; |378| 
        STRH      A1, [V2, #38]         ; |378| 
;** 383	-----------------------    flashParam->ActualSector_US = flashParam->StartSector_US;
	.dwpsn	"FlashLib_TMS470.c",383,7
;----------------------------------------------------------------------
; 383 | flashParam->ActualSector_US = flashParam->StartSector_US;              
;----------------------------------------------------------------------
        LDRH      A1, [V2, #36]         ; |383| 
        STRH      A1, [V2, #42]         ; |383| 
;** 388	-----------------------    flashParam->errorcode = C$2|0x40u;
	.dwpsn	"FlashLib_TMS470.c",388,7
;----------------------------------------------------------------------
; 388 | flashParam->errorcode |= kFlashEraseBusy;                              
; 396 | return;                                                                
;----------------------------------------------------------------------
        MOV       A1, #64               ; |388| 
        ORR       A1, V3                ; |388| 
        STRH      A1, [V2, #4]          ; |388| 
;** 388	-----------------------    goto g6;
        POP       {V1, V2, V3, V4, PC}
;* --------------------------------------------------------------------------*
L1:    
;**	-----------------------g3:
;** 326	-----------------------    flashParam->errorcode = K$22 = 0;
	.dwpsn	"FlashLib_TMS470.c",326,5
        MOV       V1, #0                ; |326| 
        STRH      V1, [V2, #4]          ; |326| 
;** 334	-----------------------    flashParam->errorcode = FlashEraseSector(flashParam);
	.dwpsn	"FlashLib_TMS470.c",334,5
        MOV       A2, #1                ; |334| 
        MOV       LR, A2
        LDR       A2, CON5
        ADD       LR, PC
        BX        A2
        ; |334| 
        STRH      A1, [V2, #4]          ; |334| 
;** 339	-----------------------    if ( flashParam->errorcode != 1 ) goto g6;
	.dwpsn	"FlashLib_TMS470.c",339,5
        LDRH      A1, [V2, #4]          ; |339| 
        CMP       A1, #1                ; |339| 
        BNE       L2                    ; |339| 
        ; |339| 
;* --------------------------------------------------------------------------*
;** 344	-----------------------    flashParam->errorcode = K$22;
	.dwpsn	"FlashLib_TMS470.c",344,7
        STRH      V1, [V2, #4]          ; |344| 
;** 349	-----------------------    C$1 = flashParam->ActualSector_US;
	.dwpsn	"FlashLib_TMS470.c",349,7
        LDRH      A2, [V2, #42]         ; |349| 
;** 349	-----------------------    if ( C$1 <= flashParam->EndSector_US ) goto g6;
        LDRH      A1, [V2, #38]         ; |349| 
        CMP       A2, A1                ; |349| 
        BLE       L2                    ; |349| 
        ; |349| 
;* --------------------------------------------------------------------------*
;** 354	-----------------------    flashParam->errorcode |= 0x40u;
	.dwpsn	"FlashLib_TMS470.c",354,9
        LDRH      A3, [V2, #4]          ; |354| 
        MOV       A1, #64               ; |354| 
        ORR       A1, A3                ; |354| 
        STRH      A1, [V2, #4]          ; |354| 
;** 359	-----------------------    flashParam->ActualSector_US = C$1-1;
	.dwpsn	"FlashLib_TMS470.c",359,9
        SUB       A1, A2, #1            ; |359| 
        STRH      A1, [V2, #42]         ; |359| 
;**	-----------------------g6:
;**  	-----------------------    return;
;* --------------------------------------------------------------------------*
L2:    
	.dwpsn	"FlashLib_TMS470.c",398,1
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}
	.dwendentry
	.dwendtag DW$41




	.sect	".text:v$3"
	.clink
	.global	_FlashEraseSector

DW$48	.dwtag  DW_TAG_subprogram, DW_AT_name("FlashEraseSector"), DW_AT_symbol_name("_FlashEraseSector")
	.dwattr DW$48, DW_AT_veneer(0x01)
	.dwattr DW$48, DW_AT_low_pc(_FlashEraseSector)
	.dwattr DW$48, DW_AT_high_pc(0x00)
	.dwattr DW$48, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FlashEraseSector                                        *
;*****************************************************************************
_FlashEraseSector:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FlashEraseSector
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$48



	.sect	".text"
	.clink
	.global	$FlashEraseSector

DW$49	.dwtag  DW_TAG_subprogram, DW_AT_name("FlashEraseSector"), DW_AT_symbol_name("$FlashEraseSector")
	.dwattr DW$49, DW_AT_low_pc($FlashEraseSector)
	.dwattr DW$49, DW_AT_high_pc(0x00)
	.dwpsn	"FlashLib_TMS470.c",412,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 411 | UBYTE FlashEraseSector(const tFlashParam *flashParam )                 
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FlashEraseSector                                           *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,V2,V3,V4,V9,SP,LR,SR                 *
;*   Regs Used         : A1,A2,A3,A4,V1,V2,V3,V4,V9,SP,LR,SR                 *
;*   Local Frame Size  : 8 Args + 12 Auto + 20 Save = 40 byte                *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FlashEraseSector:
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
        ADD       SP, #-20
	.dwcfa	0x0e, 40
;* A1    assigned to _flashParam
DW$50	.dwtag  DW_TAG_formal_parameter, DW_AT_name("flashParam"), DW_AT_symbol_name("_flashParam")
	.dwattr DW$50, DW_AT_type(*DWT$1052)
	.dwattr DW$50, DW_AT_location[DW_OP_reg0]
;* V2    assigned to C$1
DW$51	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$51, DW_AT_type(*DWT$10)
	.dwattr DW$51, DW_AT_location[DW_OP_reg5]
;* V2    assigned to C$2
DW$52	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$52, DW_AT_type(*DWT$10)
	.dwattr DW$52, DW_AT_location[DW_OP_reg5]
;* A2    assigned to C$3
DW$53	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$53, DW_AT_type(*DWT$1122)
	.dwattr DW$53, DW_AT_location[DW_OP_reg1]
;* V4    assigned to _Statusflag_UB
DW$54	.dwtag  DW_TAG_variable, DW_AT_name("Statusflag_UB"), DW_AT_symbol_name("_Statusflag_UB")
	.dwattr DW$54, DW_AT_type(*DWT$1030)
	.dwattr DW$54, DW_AT_location[DW_OP_reg7]
;* A1    assigned to _flashParam
DW$55	.dwtag  DW_TAG_variable, DW_AT_name("flashParam"), DW_AT_symbol_name("_flashParam")
	.dwattr DW$55, DW_AT_type(*DWT$1084)
	.dwattr DW$55, DW_AT_location[DW_OP_reg0]
DW$56	.dwtag  DW_TAG_variable, DW_AT_name("t_Start_UL"), DW_AT_symbol_name("_t_Start_UL")
	.dwattr DW$56, DW_AT_type(*DWT$1021)
	.dwattr DW$56, DW_AT_location[DW_OP_breg13 8]
DW$57	.dwtag  DW_TAG_variable, DW_AT_name("t_Core_UL"), DW_AT_symbol_name("_t_Core_UL")
	.dwattr DW$57, DW_AT_type(*DWT$1021)
	.dwattr DW$57, DW_AT_location[DW_OP_breg13 12]
DW$58	.dwtag  DW_TAG_variable, DW_AT_name("t_Delay_UL"), DW_AT_symbol_name("_t_Delay_UL")
	.dwattr DW$58, DW_AT_type(*DWT$1021)
	.dwattr DW$58, DW_AT_location[DW_OP_breg13 16]
;----------------------------------------------------------------------
; 413 | volatile ULONG t_Start_UL;                                             
; 414 | volatile ULONG t_Core_UL;                                              
; 415 | volatile ULONG t_Delay_UL;                                             
; 421 | UBYTE Statusflag_UB = UNKNOWN_STATUS;                                  
;----------------------------------------------------------------------
;** 426	-----------------------    C$3 = &c_CCflash_SectorMap_AST[flashParam->ActualSector_US];
	.dwpsn	"FlashLib_TMS470.c",426,3
;----------------------------------------------------------------------
; 426 | t_Start_UL =   (ULONG) c_CCflash_SectorMap_AST[flashParam->ActualSector
;     | _US].Start_UL;                                                         
;----------------------------------------------------------------------
        LDRH      A2, [A1, #42]         ; |426| 
        MOV       A3, #12               ; |426| 
        MUL       A3, A2
        LDR       A2, CON6              ; |426| 
        ADD       A2, A2, A3            ; |426| 
;** 426	-----------------------    t_Start_UL = C$3->Start_UL;
        LDR       A3, [A2, #0]          ; |426| 
        STR       A3, [SP, #8]          ; |426| 
;** 427	-----------------------    t_Core_UL = C$3->Core_UB;
	.dwpsn	"FlashLib_TMS470.c",427,3
;----------------------------------------------------------------------
; 427 | t_Core_UL  =   (ULONG) c_CCflash_SectorMap_AST[flashParam->ActualSector
;     | _US].Core_UB;                                                          
;----------------------------------------------------------------------
        LDRB      A2, [A2, #10]         ; |427| 
        STR       A2, [SP, #12]         ; |427| 
;** 428	-----------------------    t_Delay_UL = flashParam->Delaytime_UL;
	.dwpsn	"FlashLib_TMS470.c",428,3
;----------------------------------------------------------------------
; 428 | t_Delay_UL =   (ULONG) flashParam->Delaytime_UL;                       
;----------------------------------------------------------------------
        LDR       A1, [A1, #44]         ; |428| 
        STR       A1, [SP, #16]         ; |428| 
;** 433	-----------------------    Flash_Start_Command_B((unsigned *)t_Start_UL, t_Core_UL, t_Delay_UL, (unsigned * const)0xfff7cc00u, 14u, 0u);
	.dwpsn	"FlashLib_TMS470.c",433,3
;----------------------------------------------------------------------
; 433 | Flash_Start_Command_B (                                                
; 434 |             (ULONG*) t_Start_UL,                                       
; 435 |             (ULONG)  t_Core_UL,                                        
; 436 |             (ULONG)  t_Delay_UL,                                       
; 437 |             (ULONG*) C_FlashControl_ST,                                
; 438 |             0x000Eu,                                                   
; 439 |             0x0000u);                                                  
;----------------------------------------------------------------------
        MOV       A1, #14               ; |433| 
        MOV       V3, SP
        STRH      A1, [V3, #0]          ; |433| 
        MOV       A1, #0                ; |433| 
        STRH      A1, [V3, #2]          ; |433| 
        LDR       A1, [SP, #8]          ; |433| 
        LDR       A2, [SP, #12]         ; |433| 
        LDR       A3, [SP, #16]         ; |433| 
        LDR       V2, CON10             ; |472| 
        MOV       A4, V2
        MOV       V1, #1                ; |433| 
        MOV       LR, V1
        LDR       V4, CON11
        ADD       LR, PC
        BX        V4
        ; |433| 
;**  	-----------------------    #pragma LOOP_FLAGS(5376u)
;** 421	-----------------------    Statusflag_UB = 0u;
	.dwpsn	"FlashLib_TMS470.c",421,9
        MOV       V4, #0                ; |433| 
;** 443	-----------------------    goto g3;
	.dwpsn	"FlashLib_TMS470.c",443,3
;----------------------------------------------------------------------
; 443 | while((Flash_Status_U16((ULONG*)C_FlashControl_ST) & 0x0100u) != 0u)   
; 448 |   Feed_Watchdog_V();                                                   
; 454 | if((Flash_Start_Command_B (                                            
; 455 |             (ULONG*) t_Start_UL,                                       
; 456 |             (ULONG)  t_Core_UL,                                        
; 457 |             (ULONG)  t_Delay_UL,                                       
; 458 |             (ULONG*) C_FlashControl_ST,                                
; 459 |             0x0006u,                                                   
; 460 |             0xFFFFu)) != 0)                                            
; 465 |   while((Flash_Status_U16((ULONG*)C_FlashControl_ST) & 0x0100u) != 0u) 
;----------------------------------------------------------------------
        B         L5                    ; |443| 
        ; |443| 
;* --------------------------------------------------------------------------*
L3:    
DWL$$FlashEraseSector$2$B:
;**	-----------------------g1:
;** 470	-----------------------    Feed_Watchdog_V();
	.dwpsn	"FlashLib_TMS470.c",470,7
;----------------------------------------------------------------------
; 470 | Feed_Watchdog_V();                                                     
;----------------------------------------------------------------------
        MOV       LR, V1
        LDR       A1, CON12
        ADD       LR, PC
        BX        A1
        ; |470| 
;** 470	-----------------------    goto g6;
        B         L6                    ; |470| 
        ; |470| 
DWL$$FlashEraseSector$2$E:
;* --------------------------------------------------------------------------*
L4:    
DWL$$FlashEraseSector$3$B:
;**	-----------------------g2:
;** 448	-----------------------    Feed_Watchdog_V();
	.dwpsn	"FlashLib_TMS470.c",448,5
        MOV       LR, V1
        LDR       A1, CON12
        ADD       LR, PC
        BX        A1
        ; |448| 
DWL$$FlashEraseSector$3$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L5
;* --------------------------------------------------------------------------*
L5:    
DWL$$FlashEraseSector$4$B:
;**	-----------------------g3:
;** 450	-----------------------    if ( Flash_Status_U16((unsigned * const)(C$2 = 0xfff7cc00u))&0x100 ) goto g2;
	.dwpsn	"FlashLib_TMS470.c",450,3
        MOV       A1, V2
        MOV       LR, V1
        LDR       A2, CON13
        ADD       LR, PC
        BX        A2
        ; |450| 
        LSR       A1, A1, #9            ; |450| 
        BCS       L4                    ; |450| 
        ; |450| 
DWL$$FlashEraseSector$4$E:
;* --------------------------------------------------------------------------*
;** 454	-----------------------    if ( !Flash_Start_Command_B((unsigned *)t_Start_UL, t_Core_UL, t_Delay_UL, (unsigned * const)C$2, 6u, 0xffffu) ) goto g9;
	.dwpsn	"FlashLib_TMS470.c",454,3
        MOV       A1, #6                ; |454| 
        STRH      A1, [V3, #0]          ; |454| 
        LDR       A1, CON16             ; |454| 
        STRH      A1, [V3, #2]          ; |454| 
        LDR       A1, [SP, #8]          ; |454| 
        MOV       A4, V2
        LDR       A2, [SP, #12]         ; |454| 
        LDR       A3, [SP, #16]         ; |454| 
        MOV       LR, V1
        LDR       V3, CON11
        ADD       LR, PC
        BX        V3
        ; |454| 
        CMP       A1, #0                ; |454| 
        BEQ       L7                    ; |454| 
        ; |454| 
;**  	-----------------------    #pragma LOOP_FLAGS(5376u)
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L6
;*
;*   Loop source line                : 465
;*   Loop closing brace source line  : 472
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L6:    
DWL$$FlashEraseSector$6$B:
;**	-----------------------g6:
;** 472	-----------------------    if ( Flash_Status_U16((unsigned * const)(C$1 = 0xfff7cc00u))&0x100 ) goto g1;
	.dwpsn	"FlashLib_TMS470.c",472,5
        MOV       A1, V2
        MOV       LR, V1
        LDR       A2, CON13
        ADD       LR, PC
        BX        A2
        ; |472| 
        LSR       A1, A1, #9            ; |472| 
        BCS       L3                    ; |472| 
        ; |472| 
DWL$$FlashEraseSector$6$E:
;* --------------------------------------------------------------------------*
;** 477	-----------------------    if ( Flash_Status_U16((unsigned * const)C$1) ) goto g9;
	.dwpsn	"FlashLib_TMS470.c",477,5
;----------------------------------------------------------------------
; 477 | if (Flash_Status_U16((ULONG*)C_FlashControl_ST) == 0u)                 
;----------------------------------------------------------------------
        MOV       A1, V2
        MOV       LR, V1
        LDR       A2, CON13
        ADD       LR, PC
        BX        A2
        ; |477| 
        CMP       A1, #0                ; |477| 
        BNE       L7                    ; |477| 
        ; |477| 
;* --------------------------------------------------------------------------*
;** 482	-----------------------    Statusflag_UB = 1u;
	.dwpsn	"FlashLib_TMS470.c",482,7
;----------------------------------------------------------------------
; 482 | Statusflag_UB = ERASE_SUCCESSFUL;                                      
;----------------------------------------------------------------------
        MOV       V4, V1
;* --------------------------------------------------------------------------*
L7:    
;**	-----------------------g9:
;** 490	-----------------------    return Statusflag_UB;
	.dwpsn	"FlashLib_TMS470.c",490,3
;----------------------------------------------------------------------
; 490 | return Statusflag_UB;                                                  
;----------------------------------------------------------------------
        MOV       A1, V4
	.dwpsn	"FlashLib_TMS470.c",492,1
        ADD       SP, #20               ; |490| 
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}

DW$59	.dwtag  DW_TAG_loop
	.dwattr DW$59, DW_AT_name("r:/10_his/04_lst/FlashLib_TMS470.asm:L5:1:1323416585")
	.dwattr DW$59, DW_AT_begin_file("FlashLib_TMS470.c")
	.dwattr DW$59, DW_AT_begin_line(0x1bb)
	.dwattr DW$59, DW_AT_end_line(0x1d6)
DW$60	.dwtag  DW_TAG_loop_range
	.dwattr DW$60, DW_AT_low_pc(DWL$$FlashEraseSector$4$B)
	.dwattr DW$60, DW_AT_high_pc(DWL$$FlashEraseSector$4$E)
DW$61	.dwtag  DW_TAG_loop_range
	.dwattr DW$61, DW_AT_low_pc(DWL$$FlashEraseSector$3$B)
	.dwattr DW$61, DW_AT_high_pc(DWL$$FlashEraseSector$3$E)
	.dwendtag DW$59


DW$62	.dwtag  DW_TAG_loop
	.dwattr DW$62, DW_AT_name("r:/10_his/04_lst/FlashLib_TMS470.asm:L6:1:1323416585")
	.dwattr DW$62, DW_AT_begin_file("FlashLib_TMS470.c")
	.dwattr DW$62, DW_AT_begin_line(0x1d1)
	.dwattr DW$62, DW_AT_end_line(0x1d8)
DW$63	.dwtag  DW_TAG_loop_range
	.dwattr DW$63, DW_AT_low_pc(DWL$$FlashEraseSector$6$B)
	.dwattr DW$63, DW_AT_high_pc(DWL$$FlashEraseSector$6$E)
DW$64	.dwtag  DW_TAG_loop_range
	.dwattr DW$64, DW_AT_low_pc(DWL$$FlashEraseSector$2$B)
	.dwattr DW$64, DW_AT_high_pc(DWL$$FlashEraseSector$2$E)
	.dwendtag DW$62

	.dwendentry
	.dwendtag DW$49




	.sect	".text:v$4"
	.clink
	.global	_FlashWrite

DW$65	.dwtag  DW_TAG_subprogram, DW_AT_name("FlashWrite"), DW_AT_symbol_name("_FlashWrite")
	.dwattr DW$65, DW_AT_veneer(0x01)
	.dwattr DW$65, DW_AT_low_pc(_FlashWrite)
	.dwattr DW$65, DW_AT_high_pc(0x00)
	.dwattr DW$65, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FlashWrite                                              *
;*****************************************************************************
_FlashWrite:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FlashWrite
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$65



	.sect	".text"
	.clink
	.global	$FlashWrite

DW$66	.dwtag  DW_TAG_subprogram, DW_AT_name("FlashWrite"), DW_AT_symbol_name("$FlashWrite")
	.dwattr DW$66, DW_AT_low_pc($FlashWrite)
	.dwattr DW$66, DW_AT_high_pc(0x00)
	.dwpsn	"FlashLib_TMS470.c",509,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 508 | void FlashWrite(tFlashParam *flashParam)                               
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FlashWrite                                                 *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,V2,V3,V4,V9,SP,LR,SR                 *
;*   Regs Used         : A1,A2,A3,A4,V1,V2,V3,V4,V9,SP,LR,SR                 *
;*   Local Frame Size  : 24 Args + 24 Auto + 20 Save = 68 byte               *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FlashWrite:
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
        ADD       SP, #-48
	.dwcfa	0x0e, 68
;* A1    assigned to _flashParam
DW$67	.dwtag  DW_TAG_formal_parameter, DW_AT_name("flashParam"), DW_AT_symbol_name("_flashParam")
	.dwattr DW$67, DW_AT_type(*DWT$1080)
	.dwattr DW$67, DW_AT_location[DW_OP_reg0]
;* A2    assigned to C$1
DW$68	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$68, DW_AT_type(*DWT$10)
	.dwattr DW$68, DW_AT_location[DW_OP_reg1]
;* A3    assigned to C$2
DW$69	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$69, DW_AT_type(*DWT$10)
	.dwattr DW$69, DW_AT_location[DW_OP_reg2]
;* A3    assigned to C$3
DW$70	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$70, DW_AT_type(*DWT$10)
	.dwattr DW$70, DW_AT_location[DW_OP_reg2]
;* A2    assigned to C$4
DW$71	.dwtag  DW_TAG_variable, DW_AT_name("C$4"), DW_AT_symbol_name("C$4")
	.dwattr DW$71, DW_AT_type(*DWT$10)
	.dwattr DW$71, DW_AT_location[DW_OP_reg1]
;* V3    assigned to _t_count_UB
DW$72	.dwtag  DW_TAG_variable, DW_AT_name("t_count_UB"), DW_AT_symbol_name("_t_count_UB")
	.dwattr DW$72, DW_AT_type(*DWT$1030)
	.dwattr DW$72, DW_AT_location[DW_OP_reg6]
;* A1    assigned to _t_Control_UL
DW$73	.dwtag  DW_TAG_variable, DW_AT_name("t_Control_UL"), DW_AT_symbol_name("_t_Control_UL")
	.dwattr DW$73, DW_AT_type(*DWT$1023)
	.dwattr DW$73, DW_AT_location[DW_OP_reg0]
;* A1    assigned to _t_FlashReturnValue_B
DW$74	.dwtag  DW_TAG_variable, DW_AT_name("t_FlashReturnValue_B"), DW_AT_symbol_name("_t_FlashReturnValue_B")
	.dwattr DW$74, DW_AT_type(*DWT$1018)
	.dwattr DW$74, DW_AT_location[DW_OP_reg0]
;* V2    assigned to _flashParam
DW$75	.dwtag  DW_TAG_variable, DW_AT_name("flashParam"), DW_AT_symbol_name("_flashParam")
	.dwattr DW$75, DW_AT_type(*DWT$1085)
	.dwattr DW$75, DW_AT_location[DW_OP_reg5]
;* A1    assigned to U$13
DW$76	.dwtag  DW_TAG_variable, DW_AT_name("U$13"), DW_AT_symbol_name("U$13")
	.dwattr DW$76, DW_AT_type(*DWT$1035)
	.dwattr DW$76, DW_AT_location[DW_OP_reg0]
DW$77	.dwtag  DW_TAG_variable, DW_AT_name("t_Delay_UL"), DW_AT_symbol_name("_t_Delay_UL")
	.dwattr DW$77, DW_AT_type(*DWT$1021)
	.dwattr DW$77, DW_AT_location[DW_OP_breg13 24]
DW$78	.dwtag  DW_TAG_variable, DW_AT_name("t_Core_UL"), DW_AT_symbol_name("_t_Core_UL")
	.dwattr DW$78, DW_AT_type(*DWT$1021)
	.dwattr DW$78, DW_AT_location[DW_OP_breg13 28]
DW$79	.dwtag  DW_TAG_variable, DW_AT_name("vol_ptdFlashStatus"), DW_AT_symbol_name("_vol_ptdFlashStatus")
	.dwattr DW$79, DW_AT_type(*DWT$1027)
	.dwattr DW$79, DW_AT_location[DW_OP_breg13 32]
;----------------------------------------------------------------------
; 510 | BOOL t_FlashReturnValue_B = FALSE;                                     
; 512 | volatile ULONG t_Delay_UL;                                             
; 513 | FLASH_ARRAY_ST t_Control_UL;                                           
; 514 | volatile ULONG t_Core_UL;                                              
; 516 | ULONG t_AlignmentCheck_UL;                                             
; 517 | FLASH_STATUS_ST vol_ptdFlashStatus;                                    
; 518 | UBYTE t_count_UB;                                                      
;----------------------------------------------------------------------
        MOV       V2, A1
;** 523	-----------------------    flashParam->errorcode = 0;
	.dwpsn	"FlashLib_TMS470.c",523,3
;----------------------------------------------------------------------
; 523 | flashParam->errorcode = UNKNOWN_STATUS;                                
;----------------------------------------------------------------------
        MOV       A1, #0                ; |523| 
        STRH      A1, [V2, #4]          ; |523| 
;** 528	-----------------------    t_Delay_UL = flashParam->Delaytime_UL;
	.dwpsn	"FlashLib_TMS470.c",528,3
;----------------------------------------------------------------------
; 528 | t_Delay_UL = flashParam->Delaytime_UL;                                 
; 529 | t_Control_UL = C_FlashControl_ST;                                      
;----------------------------------------------------------------------
        LDR       A1, [V2, #44]         ; |528| 
        STR       A1, [SP, #24]         ; |528| 
;** 534	-----------------------    if ( (C$3 = flashParam->length) < 4u ) goto g12;
	.dwpsn	"FlashLib_TMS470.c",534,3
;----------------------------------------------------------------------
; 534 | if(flashParam->length >= d_Value4)                                     
; 539 |   t_AlignmentCheck_UL = flashParam->address / (ULONG)d_Value4;         
;----------------------------------------------------------------------
        LDR       A3, [V2, #12]         ; |534| 
        CMP       A3, #4                ; |534| 
        BCC       L13                   ; |534| 
        ; |534| 
;* --------------------------------------------------------------------------*
;** 544	-----------------------    U$13 = flashParam->address;
	.dwpsn	"FlashLib_TMS470.c",544,5
;----------------------------------------------------------------------
; 544 | if((t_AlignmentCheck_UL * (ULONG)d_Value4) == flashParam->address)     
; 549 |   t_AlignmentCheck_UL = flashParam->length / (ULONG)d_Value4;          
; 554 |   if((t_AlignmentCheck_UL * (ULONG)d_Value4) == flashParam->length)    
; 559 |     t_count_UB = (UBYTE)0x80u;                                         
;----------------------------------------------------------------------
        LDR       A1, [V2, #8]          ; |544| 
;** 544	-----------------------    C$4 = 0xfffffffcu;
        MOV       A2, #3                ; |544| 
        MVN       A2, A2                ; |544| 
;** 544	-----------------------    if ( (U$13&C$4) != U$13 || (C$3&C$4) != C$3 ) goto g12;
        MOV       A4, A1
        AND       A4, A2
        CMP       A4, A1                ; |544| 
        BNE       L13                   ; |544| 
        ; |544| 
;* --------------------------------------------------------------------------*
        AND       A2, A3
        CMP       A2, A3                ; |544| 
        BNE       L13                   ; |544| 
        ; |544| 
;* --------------------------------------------------------------------------*
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;** 529	-----------------------    t_Control_UL = (volatile unsigned * const)0xfff7cc00u;
	.dwpsn	"FlashLib_TMS470.c",529,3
;** 564	-----------------------    t_count_UB = 0x80u;
	.dwpsn	"FlashLib_TMS470.c",564,9
;----------------------------------------------------------------------
; 564 | while (flashParam->length >= (ULONG)d_Value4)                          
;----------------------------------------------------------------------
        MOV       V3, #128              ; |564| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L8
;*
;*   Loop source line                : 564
;*   Loop closing brace source line  : 635
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L8:    
DWL$$FlashWrite$5$B:
;**	-----------------------g4:
;**  	-----------------------    #pragma LOOP_FLAGS(5376u)
;** 569	-----------------------    if ( --t_count_UB ) goto g6;
	.dwpsn	"FlashLib_TMS470.c",569,11
;----------------------------------------------------------------------
; 569 | t_count_UB--;                                                          
; 574 | if(t_count_UB == 0x00)                                                 
;----------------------------------------------------------------------
        SUB       A2, V3, #1            ; |569| 
        LSL       V3, A2, #24
        LSR       V3, V3, #24
        BNE       L9                    ; |569| 
        ; |569| 
DWL$$FlashWrite$5$E:
;* --------------------------------------------------------------------------*
DWL$$FlashWrite$6$B:
;** 579	-----------------------    Feed_Watchdog_V();
	.dwpsn	"FlashLib_TMS470.c",579,13
;----------------------------------------------------------------------
; 579 | Feed_Watchdog_V();                                                     
;----------------------------------------------------------------------
        MOV       A1, #1                ; |579| 
        MOV       LR, A1
        LDR       A1, CON12
        ADD       LR, PC
        BX        A1
        ; |579| 
;**  	-----------------------    U$13 = flashParam->address;
        LDR       A1, [V2, #8]
;** 584	-----------------------    t_count_UB = 0x80u;
	.dwpsn	"FlashLib_TMS470.c",584,13
;----------------------------------------------------------------------
; 584 | t_count_UB     = (UBYTE)0x80u;                                         
;----------------------------------------------------------------------
        MOV       V3, #128              ; |584| 
DWL$$FlashWrite$6$E:
;* --------------------------------------------------------------------------*
L9:    
DWL$$FlashWrite$7$B:
;**	-----------------------g6:
;** 591	-----------------------    if ( U$13 <= 524287u ) goto g8;
	.dwpsn	"FlashLib_TMS470.c",591,11
;----------------------------------------------------------------------
; 591 | if (flashParam->address <= d_Bank0End)                                 
; 593 |   t_Core_UL = 0x00u;                                                   
; 595 | else                                                                   
;----------------------------------------------------------------------
        LDR       A2, CON17             ; |591| 
        CMP       A1, A2                ; |591| 
        BLS       L10                   ; |591| 
        ; |591| 
DWL$$FlashWrite$7$E:
;* --------------------------------------------------------------------------*
DWL$$FlashWrite$8$B:
;** 597	-----------------------    t_Core_UL = 1u;
	.dwpsn	"FlashLib_TMS470.c",597,13
;----------------------------------------------------------------------
; 597 | t_Core_UL = 0x01u;                                                     
;----------------------------------------------------------------------
        MOV       A2, #1                ; |597| 
        STR       A2, [SP, #28]         ; |597| 
;** 597	-----------------------    goto g9;
        B         L11                   ; |597| 
        ; |597| 
DWL$$FlashWrite$8$E:
;* --------------------------------------------------------------------------*
L10:    
DWL$$FlashWrite$9$B:
;**	-----------------------g8:
;** 593	-----------------------    t_Core_UL = 0u;
	.dwpsn	"FlashLib_TMS470.c",593,13
        MOV       A2, #0                ; |523| 
        STR       A2, [SP, #28]         ; |593| 
DWL$$FlashWrite$9$E:
;* --------------------------------------------------------------------------*
L11:    
DWL$$FlashWrite$10$B:
;**	-----------------------g9:
;** 600	-----------------------    C$2 = 1u;
	.dwpsn	"FlashLib_TMS470.c",600,11
;----------------------------------------------------------------------
; 600 | t_FlashReturnValue_B = Flash_Prog_Data_B( (ULONG*)flashParam->address, 
; 601 |                                      (ULONG*)flashParam->data,         
; 602 |                                      (ULONG)1,                         
; 603 |                                      (ULONG)t_Core_UL,                 
; 604 |                                      t_Delay_UL,                       
; 605 |                                      t_Control_UL,                     
; 606 |                                      &vol_ptdFlashStatus,              
; 607 |                                      (ULONG)1,                         
; 608 |                                      0x0002u);                         
; 613 | if (t_FlashReturnValue_B != FALSE)                                     
;----------------------------------------------------------------------
        MOV       A3, #1                ; |600| 
;** 600	-----------------------    if ( !(t_FlashReturnValue_B = Flash_Prog_Data_B((unsigned *)U$13, flashParam->data, C$2, t_Core_UL, t_Delay_UL, t_Control_UL, &vol_ptdFlashStatus, C$2, 2u)) ) goto g11;
        LDR       A2, [SP, #24]         ; |600| 
        STR       A2, [SP, #0]          ; |600| 
        LDR       A2, CON10             ; |529| 
        STR       A2, [SP, #4]          ; |600| 
        ADD       A2, SP, #32           ; |600| 
        STR       A2, [SP, #8]          ; |600| 
        STR       A3, [SP, #12]         ; |600| 
        MOV       A4, #2                ; |600| 
        MOV       A2, SP
        STRH      A4, [A2, #16]         ; |600| 
        LDR       A2, [V2, #16]         ; |600| 
        LDR       A4, [SP, #28]         ; |600| 
        MOV       V1, A3
        MOV       LR, A3
        LDR       V4, CON19
        ADD       LR, PC
        BX        V4
        ; |600| 
        CMP       A1, #0                ; |600| 
        BEQ       L12                   ; |600| 
        ; |600| 
DWL$$FlashWrite$10$E:
;* --------------------------------------------------------------------------*
DWL$$FlashWrite$11$B:
;** 618	-----------------------    U$13 = flashParam->address += C$1 = 4u;
	.dwpsn	"FlashLib_TMS470.c",618,13
;----------------------------------------------------------------------
; 618 | flashParam->address += (ULONG)d_Value4;                                
;----------------------------------------------------------------------
        MOV       A2, #4                ; |618| 
        LDR       A1, [V2, #8]          ; |618| 
        ADD       A1, A2, A1            ; |618| 
        STR       A1, [V2, #8]          ; |618| 
;** 619	-----------------------    flashParam->length -= 4u;
	.dwpsn	"FlashLib_TMS470.c",619,13
;----------------------------------------------------------------------
; 619 | flashParam->length -= (ULONG)d_Value4;                                 
;----------------------------------------------------------------------
        LDR       A3, [V2, #12]         ; |619| 
        SUB       A3, #4                ; |619| 
        STR       A3, [V2, #12]         ; |619| 
;** 620	-----------------------    flashParam->data += (int)C$1;
	.dwpsn	"FlashLib_TMS470.c",620,13
;----------------------------------------------------------------------
; 620 | flashParam->data += (ULONG)d_Value4;                                   
;----------------------------------------------------------------------
        LDR       A3, [V2, #16]         ; |620| 
        ADD       A2, A2, A3            ; |620| 
        STR       A2, [V2, #16]         ; |620| 
;** 622	-----------------------    if ( flashParam->length >= 4u ) goto g4;
	.dwpsn	"FlashLib_TMS470.c",622,11
;----------------------------------------------------------------------
; 626 | else                                                                   
;----------------------------------------------------------------------
        LDR       A2, [V2, #12]         ; |622| 
        CMP       A2, #4                ; |622| 
        BCS       L8                    ; |622| 
        ; |622| 
DWL$$FlashWrite$11$E:
;* --------------------------------------------------------------------------*
;** 622	-----------------------    goto g13;
        ADD       SP, #48
        POP       {V1, V2, V3, V4, PC}
;* --------------------------------------------------------------------------*
L12:    
;**	-----------------------g11:
;** 631	-----------------------    flashParam->errorcode = 1;
	.dwpsn	"FlashLib_TMS470.c",631,13
;----------------------------------------------------------------------
; 631 | flashParam->errorcode = kFlashFailed;                                  
;----------------------------------------------------------------------
        STRH      V1, [V2, #4]          ; |631| 
;** 632	-----------------------    flashParam->length = 0u;
	.dwpsn	"FlashLib_TMS470.c",632,13
;----------------------------------------------------------------------
; 632 | flashParam->length = 0;                                                
; 640 | else                                                                   
; 642 | flashParam->errorcode = kFlashFailed;                                  
; 649 | else                                                                   
; 651 | flashParam->errorcode = kFlashFailed;                                  
; 658 | else                                                                   
;----------------------------------------------------------------------
        MOV       A1, #0                ; |523| 
        STR       A1, [V2, #12]         ; |632| 
;** 632	-----------------------    goto g13;
        ADD       SP, #48
        POP       {V1, V2, V3, V4, PC}
;* --------------------------------------------------------------------------*
L13:    
;**	-----------------------g12:
;** 660	-----------------------    flashParam->errorcode = 1;
	.dwpsn	"FlashLib_TMS470.c",660,5
;----------------------------------------------------------------------
; 660 | flashParam->errorcode = kFlashFailed;                                  
; 667 | return;                                                                
;----------------------------------------------------------------------
        MOV       A1, #1                ; |660| 
        STRH      A1, [V2, #4]          ; |660| 
;**	-----------------------g13:
;**  	-----------------------    return;
	.dwpsn	"FlashLib_TMS470.c",669,1
        ADD       SP, #48
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}

DW$80	.dwtag  DW_TAG_loop
	.dwattr DW$80, DW_AT_name("r:/10_his/04_lst/FlashLib_TMS470.asm:L8:1:1323416585")
	.dwattr DW$80, DW_AT_begin_file("FlashLib_TMS470.c")
	.dwattr DW$80, DW_AT_begin_line(0x234)
	.dwattr DW$80, DW_AT_end_line(0x27b)
DW$81	.dwtag  DW_TAG_loop_range
	.dwattr DW$81, DW_AT_low_pc(DWL$$FlashWrite$5$B)
	.dwattr DW$81, DW_AT_high_pc(DWL$$FlashWrite$5$E)
DW$82	.dwtag  DW_TAG_loop_range
	.dwattr DW$82, DW_AT_low_pc(DWL$$FlashWrite$6$B)
	.dwattr DW$82, DW_AT_high_pc(DWL$$FlashWrite$6$E)
DW$83	.dwtag  DW_TAG_loop_range
	.dwattr DW$83, DW_AT_low_pc(DWL$$FlashWrite$7$B)
	.dwattr DW$83, DW_AT_high_pc(DWL$$FlashWrite$7$E)
DW$84	.dwtag  DW_TAG_loop_range
	.dwattr DW$84, DW_AT_low_pc(DWL$$FlashWrite$8$B)
	.dwattr DW$84, DW_AT_high_pc(DWL$$FlashWrite$8$E)
DW$85	.dwtag  DW_TAG_loop_range
	.dwattr DW$85, DW_AT_low_pc(DWL$$FlashWrite$9$B)
	.dwattr DW$85, DW_AT_high_pc(DWL$$FlashWrite$9$E)
DW$86	.dwtag  DW_TAG_loop_range
	.dwattr DW$86, DW_AT_low_pc(DWL$$FlashWrite$10$B)
	.dwattr DW$86, DW_AT_high_pc(DWL$$FlashWrite$10$E)
DW$87	.dwtag  DW_TAG_loop_range
	.dwattr DW$87, DW_AT_low_pc(DWL$$FlashWrite$11$B)
	.dwattr DW$87, DW_AT_high_pc(DWL$$FlashWrite$11$E)
	.dwendtag DW$80

	.dwendentry
	.dwendtag DW$66




	.sect	".text:v$5"
	.clink
	.global	_GetEraseEndSector

DW$88	.dwtag  DW_TAG_subprogram, DW_AT_name("GetEraseEndSector"), DW_AT_symbol_name("_GetEraseEndSector")
	.dwattr DW$88, DW_AT_veneer(0x01)
	.dwattr DW$88, DW_AT_low_pc(_GetEraseEndSector)
	.dwattr DW$88, DW_AT_high_pc(0x00)
	.dwattr DW$88, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _GetEraseEndSector                                       *
;*****************************************************************************
_GetEraseEndSector:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $GetEraseEndSector
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$88



	.sect	".text"
	.clink
	.global	$GetEraseEndSector

DW$89	.dwtag  DW_TAG_subprogram, DW_AT_name("GetEraseEndSector"), DW_AT_symbol_name("$GetEraseEndSector")
	.dwattr DW$89, DW_AT_low_pc($GetEraseEndSector)
	.dwattr DW$89, DW_AT_high_pc(0x00)
	.dwpsn	"FlashLib_TMS470.c",683,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 682 | UWORD GetEraseEndSector ( ULONG ulStartAddress )                       
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: GetEraseEndSector                                          *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,V2,SP,SR                             *
;*   Regs Used         : A1,A2,A3,A4,V1,V2,SP,LR,SR                          *
;*   Local Frame Size  : 0 Args + 0 Auto + 12 Save = 12 byte                 *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$GetEraseEndSector:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
        PUSH      {V1, V2, LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 5, 2
	.dwcfa	0x0e, 12
	.dwcfa	0x80, 4, 3
	.dwcfa	0x0e, 12
;* A1    assigned to _ulStartAddress
DW$90	.dwtag  DW_TAG_formal_parameter, DW_AT_name("ulStartAddress"), DW_AT_symbol_name("_ulStartAddress")
	.dwattr DW$90, DW_AT_type(*DWT$1019)
	.dwattr DW$90, DW_AT_location[DW_OP_reg0]
;* V1    assigned to C$1
DW$91	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$91, DW_AT_type(*DWT$1128)
	.dwattr DW$91, DW_AT_location[DW_OP_reg4]
;* A2    assigned to C$2
DW$92	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$92, DW_AT_type(*DWT$1124)
	.dwattr DW$92, DW_AT_location[DW_OP_reg1]
;* V1    assigned to C$3
DW$93	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$93, DW_AT_type(*DWT$1128)
	.dwattr DW$93, DW_AT_location[DW_OP_reg4]
;* A1    assigned to _uwTempSector
DW$94	.dwtag  DW_TAG_variable, DW_AT_name("uwTempSector"), DW_AT_symbol_name("_uwTempSector")
	.dwattr DW$94, DW_AT_type(*DWT$1024)
	.dwattr DW$94, DW_AT_location[DW_OP_reg0]
;* A4    assigned to _ulStartAddress
DW$95	.dwtag  DW_TAG_variable, DW_AT_name("ulStartAddress"), DW_AT_symbol_name("_ulStartAddress")
	.dwattr DW$95, DW_AT_type(*DWT$1079)
	.dwattr DW$95, DW_AT_location[DW_OP_reg3]
;* A2    assigned to U$8
DW$96	.dwtag  DW_TAG_variable, DW_AT_name("U$8"), DW_AT_symbol_name("U$8")
	.dwattr DW$96, DW_AT_type(*DWT$1126)
	.dwattr DW$96, DW_AT_location[DW_OP_reg1]
        MOV       A4, A1
;**  	-----------------------    #pragma LOOP_FLAGS(4352u)
;** 687	-----------------------    uwTempSector = 2u;
	.dwpsn	"FlashLib_TMS470.c",687,9
;----------------------------------------------------------------------
; 687 | UWORD uwTempSector = d_FirstEraseableSector;                           
;----------------------------------------------------------------------
        MOV       A1, #2                ; |687| 
;** 692	-----------------------    C$2 = &c_CCflash_SectorMap_AST[0];
	.dwpsn	"FlashLib_TMS470.c",692,3
;----------------------------------------------------------------------
; 692 | while( ulStartAddress > ((c_CCflash_SectorMap_AST[uwTempSector].Start_U
;     | L \                                                                    
; 693 |                         + c_CCflash_SectorMap_AST[uwTempSector].Length_
;     | UL) - 1ul) )                                                           
;----------------------------------------------------------------------
        LDR       A2, CON6              ; |692| 
;** 692	-----------------------    C$3 = &C$2[2];
        MOV       A3, #24               ; |692| 
        ADD       V1, A3, A2            ; |692| 
;** 692	-----------------------    if ( ulStartAddress <= C$3->Start_UL+C$3->Length_UL-1u ) goto g4;
        LDR       V2, [V1, #0]          ; |692| 
        LDR       V1, [V1, #4]          ; |692| 
        ADD       V1, V1, V2            ; |692| 
        SUB       V1, #1                ; |692| 
        CMP       A4, V1                ; |692| 
        BLS       L15                   ; |692| 
        ; |692| 
;**  	-----------------------    U$8 = C$2;
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L14
;*
;*   Loop source line                : 692
;*   Loop closing brace source line  : 700
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L14:    
DWL$$GetEraseEndSector$2$B:
;**	-----------------------g3:
;** 698	-----------------------    ++uwTempSector;
	.dwpsn	"FlashLib_TMS470.c",698,5
;----------------------------------------------------------------------
; 698 | uwTempSector++;                                                        
;----------------------------------------------------------------------
        ADD       A1, A1, #1            ; |698| 
        LSL       A1, A1, #16           ; |722| 
        LSR       A1, A1, #16           ; |722| 
;** 698	-----------------------    C$1 = (U$8 += 12)+24;
        ADD       A2, #12               ; |698| 
        ADD       V1, A3, A2            ; |698| 
;** 698	-----------------------    if ( ulStartAddress > C$1->Start_UL+C$1->Length_UL-1u ) goto g3;
        LDR       V2, [V1, #0]          ; |698| 
        LDR       V1, [V1, #4]          ; |698| 
        ADD       V1, V1, V2            ; |698| 
        SUB       V1, #1                ; |698| 
        CMP       A4, V1                ; |698| 
        BHI       L14                   ; |698| 
        ; |698| 
DWL$$GetEraseEndSector$2$E:
;* --------------------------------------------------------------------------*
L15:    
;**	-----------------------g4:
;** 706	-----------------------    if ( uwTempSector <= 10 ) goto g6;
	.dwpsn	"FlashLib_TMS470.c",706,3
;----------------------------------------------------------------------
; 706 | if( uwTempSector > (UWORD)d_LastEraseableSector )                      
;----------------------------------------------------------------------
        CMP       A1, #10               ; |706| 
        BLE       L16                   ; |706| 
        ; |706| 
;* --------------------------------------------------------------------------*
;** 711	-----------------------    return 10;
	.dwpsn	"FlashLib_TMS470.c",711,5
;----------------------------------------------------------------------
; 711 | return (UWORD)d_LastEraseableSector;                                   
; 717 | else                                                                   
;----------------------------------------------------------------------
        MOV       A1, #10               ; |711| 
        POP       {V1, V2, PC}
;* --------------------------------------------------------------------------*
L16:    
;**	-----------------------g6:
;** 722	-----------------------    return uwTempSector;
	.dwpsn	"FlashLib_TMS470.c",722,5
;----------------------------------------------------------------------
; 722 | return uwTempSector;                                                   
;----------------------------------------------------------------------
	.dwpsn	"FlashLib_TMS470.c",726,1
	.dwcfa	0x0e, 12
        POP       {V1, V2, PC}

DW$97	.dwtag  DW_TAG_loop
	.dwattr DW$97, DW_AT_name("r:/10_his/04_lst/FlashLib_TMS470.asm:L14:1:1323416585")
	.dwattr DW$97, DW_AT_begin_file("FlashLib_TMS470.c")
	.dwattr DW$97, DW_AT_begin_line(0x2b4)
	.dwattr DW$97, DW_AT_end_line(0x2bc)
DW$98	.dwtag  DW_TAG_loop_range
	.dwattr DW$98, DW_AT_low_pc(DWL$$GetEraseEndSector$2$B)
	.dwattr DW$98, DW_AT_high_pc(DWL$$GetEraseEndSector$2$E)
	.dwendtag DW$97

	.dwendentry
	.dwendtag DW$89




	.sect	".text:v$6"
	.clink
	.global	_GetEraseStartSector

DW$99	.dwtag  DW_TAG_subprogram, DW_AT_name("GetEraseStartSector"), DW_AT_symbol_name("_GetEraseStartSector")
	.dwattr DW$99, DW_AT_veneer(0x01)
	.dwattr DW$99, DW_AT_low_pc(_GetEraseStartSector)
	.dwattr DW$99, DW_AT_high_pc(0x00)
	.dwattr DW$99, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _GetEraseStartSector                                     *
;*****************************************************************************
_GetEraseStartSector:
	 LDR       ip, [pc]
	 BX        ip
	.field     $GetEraseStartSector+1, 32
	.state16
	.dwendtag DW$99



	.sect	".text"
	.clink
	.global	$GetEraseStartSector

DW$100	.dwtag  DW_TAG_subprogram, DW_AT_name("GetEraseStartSector"), DW_AT_symbol_name("$GetEraseStartSector")
	.dwattr DW$100, DW_AT_low_pc($GetEraseStartSector)
	.dwattr DW$100, DW_AT_high_pc(0x00)
	.dwpsn	"FlashLib_TMS470.c",741,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 740 | UWORD GetEraseStartSector( ULONG ulStartAdr, ULONG ulLength )          
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: GetEraseStartSector                                        *
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
$GetEraseStartSector:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;* A1    assigned to _ulStartAdr
DW$101	.dwtag  DW_TAG_formal_parameter, DW_AT_name("ulStartAdr"), DW_AT_symbol_name("_ulStartAdr")
	.dwattr DW$101, DW_AT_type(*DWT$1019)
	.dwattr DW$101, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _ulLength
DW$102	.dwtag  DW_TAG_formal_parameter, DW_AT_name("ulLength"), DW_AT_symbol_name("_ulLength")
	.dwattr DW$102, DW_AT_type(*DWT$1019)
	.dwattr DW$102, DW_AT_location[DW_OP_reg1]
;* A2    assigned to C$1
DW$103	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$103, DW_AT_type(*DWT$1130)
	.dwattr DW$103, DW_AT_location[DW_OP_reg1]
;* A1    assigned to _uwTempSector
DW$104	.dwtag  DW_TAG_variable, DW_AT_name("uwTempSector"), DW_AT_symbol_name("_uwTempSector")
	.dwattr DW$104, DW_AT_type(*DWT$1024)
	.dwattr DW$104, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _ulLength
DW$105	.dwtag  DW_TAG_variable, DW_AT_name("ulLength"), DW_AT_symbol_name("_ulLength")
	.dwattr DW$105, DW_AT_type(*DWT$1079)
	.dwattr DW$105, DW_AT_location[DW_OP_reg1]
;* A1    assigned to _ulStartAdr
DW$106	.dwtag  DW_TAG_variable, DW_AT_name("ulStartAdr"), DW_AT_symbol_name("_ulStartAdr")
	.dwattr DW$106, DW_AT_type(*DWT$1079)
	.dwattr DW$106, DW_AT_location[DW_OP_reg0]
;* A3    assigned to K$6
DW$107	.dwtag  DW_TAG_variable, DW_AT_name("K$6"), DW_AT_symbol_name("K$6")
	.dwattr DW$107, DW_AT_type(*DWT$10)
	.dwattr DW$107, DW_AT_location[DW_OP_reg2]
;* A2    assigned to U$19
DW$108	.dwtag  DW_TAG_variable, DW_AT_name("U$19"), DW_AT_symbol_name("U$19")
	.dwattr DW$108, DW_AT_type(*DWT$1130)
	.dwattr DW$108, DW_AT_location[DW_OP_reg1]
;----------------------------------------------------------------------
; 745 | UWORD uwTempSector = d_LastEraseableSector;                            
;----------------------------------------------------------------------
;** 751	-----------------------    K$6 = ulStartAdr+ulLength-1u;
	.dwpsn	"FlashLib_TMS470.c",751,3
;----------------------------------------------------------------------
; 751 | while( ((ulStartAdr + ulLength) -1ul) < c_CCflash_SectorMap_AST[uwTempS
;     | ector].Start_UL )                                                      
;----------------------------------------------------------------------
        ADD       A1, A2, A1            ; |751| 
        SUB       A3, A1, #1            ; |751| 
;** 745	-----------------------    uwTempSector = 10u;
	.dwpsn	"FlashLib_TMS470.c",745,9
        MOV       A1, #10               ; |745| 
;** 751	-----------------------    C$1 = &c_CCflash_SectorMap_AST[0];
	.dwpsn	"FlashLib_TMS470.c",751,3
        LDR       A2, CON6              ; |751| 
;** 751	-----------------------    if ( K$6 >= *(const unsigned *)(C$1+120) ) goto g4;
        LDR       A4, [A2, #120]        ; |751| 
        CMP       A3, A4                ; |751| 
        BCS       L18                   ; |751| 
        ; |751| 
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    U$19 = C$1;
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L17
;*
;*   Loop source line                : 751
;*   Loop closing brace source line  : 758
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L17:    
DWL$$GetEraseStartSector$2$B:
;**	-----------------------g3:
;** 756	-----------------------    --uwTempSector;
	.dwpsn	"FlashLib_TMS470.c",756,5
;----------------------------------------------------------------------
; 756 | uwTempSector--;                                                        
;----------------------------------------------------------------------
        SUB       A1, A1, #1            ; |756| 
        LSL       A1, A1, #16           ; |780| 
        LSR       A1, A1, #16           ; |780| 
;** 756	-----------------------    if ( ((U$19 -= 12)+120)->Start_UL > K$6 ) goto g3;
        SUB       A2, #12               ; |756| 
        LDR       A4, [A2, #120]        ; |756| 
        CMP       A4, A3                ; |756| 
        BHI       L17                   ; |756| 
        ; |756| 
DWL$$GetEraseStartSector$2$E:
;* --------------------------------------------------------------------------*
L18:    
;**	-----------------------g4:
;** 764	-----------------------    if ( uwTempSector >= 2 ) goto g6;
	.dwpsn	"FlashLib_TMS470.c",764,3
;----------------------------------------------------------------------
; 764 | if( uwTempSector < (UWORD)d_FirstEraseableSector)  /* Lower Limit */   
;----------------------------------------------------------------------
        CMP       A1, #2                ; |764| 
        BGE       L19                   ; |764| 
        ; |764| 
;* --------------------------------------------------------------------------*
;** 769	-----------------------    return 2;
	.dwpsn	"FlashLib_TMS470.c",769,5
;----------------------------------------------------------------------
; 769 | return (UWORD)d_FirstEraseableSector;                                  
; 775 | else                                                                   
;----------------------------------------------------------------------
        MOV       A1, #2                ; |769| 
        BX        LR
;* --------------------------------------------------------------------------*
L19:    
;**	-----------------------g6:
;** 780	-----------------------    return uwTempSector;
	.dwpsn	"FlashLib_TMS470.c",780,5
;----------------------------------------------------------------------
; 780 | return uwTempSector;                                                   
;----------------------------------------------------------------------
	.dwpsn	"FlashLib_TMS470.c",784,1
        BX        LR

DW$109	.dwtag  DW_TAG_loop
	.dwattr DW$109, DW_AT_name("r:/10_his/04_lst/FlashLib_TMS470.asm:L17:1:1323416585")
	.dwattr DW$109, DW_AT_begin_file("FlashLib_TMS470.c")
	.dwattr DW$109, DW_AT_begin_line(0x2ef)
	.dwattr DW$109, DW_AT_end_line(0x2f6)
DW$110	.dwtag  DW_TAG_loop_range
	.dwattr DW$110, DW_AT_low_pc(DWL$$GetEraseStartSector$2$B)
	.dwattr DW$110, DW_AT_high_pc(DWL$$GetEraseStartSector$2$E)
	.dwendtag DW$109

	.dwendentry
	.dwendtag DW$100




	.sect	".text:v$7"
	.clink
	.global	_Feed_Watchdog_V

DW$111	.dwtag  DW_TAG_subprogram, DW_AT_name("Feed_Watchdog_V"), DW_AT_symbol_name("_Feed_Watchdog_V")
	.dwattr DW$111, DW_AT_veneer(0x01)
	.dwattr DW$111, DW_AT_low_pc(_Feed_Watchdog_V)
	.dwattr DW$111, DW_AT_high_pc(0x00)
	.dwattr DW$111, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _Feed_Watchdog_V                                         *
;*****************************************************************************
_Feed_Watchdog_V:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $Feed_Watchdog_V
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$111



	.sect	".text"
	.clink
	.global	$Feed_Watchdog_V

DW$112	.dwtag  DW_TAG_subprogram, DW_AT_name("Feed_Watchdog_V"), DW_AT_symbol_name("$Feed_Watchdog_V")
	.dwattr DW$112, DW_AT_low_pc($Feed_Watchdog_V)
	.dwattr DW$112, DW_AT_high_pc(0x00)
	.dwpsn	"FlashLib_TMS470.c",798,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 797 | void Feed_Watchdog_V()                                                 
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: Feed_Watchdog_V                                            *
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
$Feed_Watchdog_V:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 799 | ULONG *t_TempSrc_pul;                                                  
; 804 | t_TempSrc_pul  = (ULONG*)fp->wdTriggerFct;                             
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
        PUSH      {V1, LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 4, 2
	.dwcfa	0x0e, 8
;* A1    assigned to C$1
DW$113	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$113, DW_AT_type(*DWT$1108)
	.dwattr DW$113, DW_AT_location[DW_OP_reg0]
;* A1    assigned to C$2
DW$114	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$114, DW_AT_type(*DWT$1086)
	.dwattr DW$114, DW_AT_location[DW_OP_reg0]
;** 809	-----------------------    C$2 = fp;
	.dwpsn	"FlashLib_TMS470.c",809,3
;----------------------------------------------------------------------
; 809 | if (t_TempSrc_pul != 0x00000000UL)                                     
;----------------------------------------------------------------------
        LDR       A1, CON1              ; |809| 
        LDR       A1, [A1, #0]          ; |809| 
;** 809	-----------------------    if ( C$2->wdTriggerFct == NULL ) goto g2;
        LDR       A2, [A1, #20]         ; |809| 
        CMP       A2, #0                ; |809| 
        BEQ       L20                   ; |809| 
        ; |809| 
;* --------------------------------------------------------------------------*
;** 814	-----------------------    (*C$2->wdTriggerFct)();
	.dwpsn	"FlashLib_TMS470.c",814,5
;----------------------------------------------------------------------
; 814 | fp->wdTriggerFct();                                                    
;----------------------------------------------------------------------
        LDR       V1, [A1, #20]         ; |814| 
        MOV       A1, #1                ; |814| 
        MOV       LR, A1
        LDR       A1, CON20
        ADD       LR, PC
        BX        A1
        ; |814| 
;* --------------------------------------------------------------------------*
L20:    
;**	-----------------------g2:
;** 823	-----------------------    C$1 = &e_SARRTI_ST;
	.dwpsn	"FlashLib_TMS470.c",823,3
;----------------------------------------------------------------------
; 823 | e_SARRTI_ST.WKEY_UL = 0xE5;                                            
;----------------------------------------------------------------------
        LDR       A1, CON21             ; |823| 
;** 823	-----------------------    C$1->WKEY_UL = 229u;
        MOV       A2, #229              ; |823| 
        STR       A2, [A1, #12]         ; |823| 
;** 824	-----------------------    C$1->WKEY_UL = 163u;
	.dwpsn	"FlashLib_TMS470.c",824,3
;----------------------------------------------------------------------
; 824 | e_SARRTI_ST.WKEY_UL = 0xA3;                                            
;----------------------------------------------------------------------
        MOV       A2, #163              ; |824| 
        STR       A2, [A1, #12]         ; |824| 
;** 829	-----------------------    return;
	.dwpsn	"FlashLib_TMS470.c",829,3
;----------------------------------------------------------------------
; 829 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"FlashLib_TMS470.c",831,1
	.dwcfa	0x0e, 8
        POP       {V1, PC}
	.dwendentry
	.dwendtag DW$112



;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON1:	.field  	_fp,32
	.align	4
CON2:	.field  	786431,32
	.align	4
CON3:	.field  	$GetEraseStartSector+1,32
	.align	4
CON4:	.field  	$GetEraseEndSector+1,32
	.align	4
CON5:	.field  	$FlashEraseSector+1,32
	.align	4
CON6:	.field  	_c_CCflash_SectorMap_AST,32
	.align	4
CON10:	.field  	-537600,32
	.align	4
CON11:	.field  	$Flash_Start_Command_B+1,32
	.align	4
CON12:	.field  	$Feed_Watchdog_V+1,32
	.align	4
CON13:	.field  	$Flash_Status_U16+1,32
	.align	4
CON16:	.field  	65535,32
	.align	4
CON17:	.field  	524287,32
	.align	4
CON19:	.field  	$Flash_Prog_Data_B+1,32
	.align	4
CON20:	.field  	IND$CALL+1,32
	.align	4
CON21:	.field  	_e_SARRTI_ST,32
;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	$Flash_Start_Command_B
	.global	$Flash_Prog_Data_B
	.global	$Flash_Status_U16
	.global	_e_SARRTI_ST
	.global	IND$CALL

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
DWT$6	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned char")
	.dwattr DWT$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr DWT$6, DW_AT_byte_size(0x01)
DWT$1018	.dwtag  DW_TAG_typedef, DW_AT_name("BOOL"), DW_AT_type(*DWT$6)
	.dwattr DWT$1018, DW_AT_language(DW_LANG_C)

DWT$1025	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1025, DW_AT_language(DW_LANG_C)
DW$115	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1020)
DW$116	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$117	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$118	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1023)
DW$119	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1024)
DW$120	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1024)
	.dwendtag DWT$1025


DWT$1029	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1029, DW_AT_language(DW_LANG_C)
DW$121	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1020)
DW$122	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1020)
DW$123	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$124	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$125	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$126	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1023)
DW$127	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1028)
DW$128	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$129	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1024)
	.dwendtag DWT$1029

DWT$1030	.dwtag  DW_TAG_typedef, DW_AT_name("UBYTE"), DW_AT_type(*DWT$6)
	.dwattr DWT$1030, DW_AT_language(DW_LANG_C)

DWT$1053	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1030)
	.dwattr DWT$1053, DW_AT_language(DW_LANG_C)
DW$130	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1052)
	.dwendtag DWT$1053

DWT$1060	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$6)
	.dwattr DWT$1060, DW_AT_address_class(0x20)
DWT$8	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned short")
	.dwattr DWT$8, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$8, DW_AT_byte_size(0x02)
DWT$1024	.dwtag  DW_TAG_typedef, DW_AT_name("UWORD"), DW_AT_type(*DWT$8)
	.dwattr DWT$1024, DW_AT_language(DW_LANG_C)

DWT$1062	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1024)
	.dwattr DWT$1062, DW_AT_language(DW_LANG_C)
DW$131	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
	.dwendtag DWT$1062


DWT$1063	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1024)
	.dwattr DWT$1063, DW_AT_language(DW_LANG_C)
DW$132	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
DW$133	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1019)
	.dwendtag DWT$1063

DWT$11	.dwtag  DW_TAG_base_type, DW_AT_name("int")
	.dwattr DWT$11, DW_AT_encoding(DW_ATE_signed)
	.dwattr DWT$11, DW_AT_byte_size(0x04)

DWT$1069	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$11)
	.dwattr DWT$1069, DW_AT_language(DW_LANG_C)
DWT$10	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned int")
	.dwattr DWT$10, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$10, DW_AT_byte_size(0x04)
DWT$1019	.dwtag  DW_TAG_typedef, DW_AT_name("ULONG"), DW_AT_type(*DWT$12)
	.dwattr DWT$1019, DW_AT_language(DW_LANG_C)
DWT$1020	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1019)
	.dwattr DWT$1020, DW_AT_address_class(0x20)
DWT$1021	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1019)
DWT$1023	.dwtag  DW_TAG_typedef, DW_AT_name("FLASH_ARRAY_ST"), DW_AT_type(*DWT$1022)
	.dwattr DWT$1023, DW_AT_language(DW_LANG_C)
DWT$1078	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1023)
DWT$1079	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1019)
DWT$1035	.dwtag  DW_TAG_typedef, DW_AT_name("tAddress"), DW_AT_type(*DWT$12)
	.dwattr DWT$1035, DW_AT_language(DW_LANG_C)

DWT$1039	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1039, DW_AT_language(DW_LANG_C)

DWT$1081	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1081, DW_AT_language(DW_LANG_C)
DW$134	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1080)
	.dwendtag DWT$1081

DWT$1027	.dwtag  DW_TAG_typedef, DW_AT_name("FLASH_STATUS_ST"), DW_AT_type(*DWT$1026)
	.dwattr DWT$1027, DW_AT_language(DW_LANG_C)
DWT$1028	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1027)
	.dwattr DWT$1028, DW_AT_address_class(0x20)
DWT$1052	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1051)
	.dwattr DWT$1052, DW_AT_address_class(0x20)
DWT$1084	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1052)
DWT$1080	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1050)
	.dwattr DWT$1080, DW_AT_address_class(0x20)
DWT$1085	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1080)
DWT$1086	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1049)
	.dwattr DWT$1086, DW_AT_address_class(0x20)
DWT$1107	.dwtag  DW_TAG_typedef, DW_AT_name("SARRTI_ST"), DW_AT_type(*DWT$1106)
	.dwattr DWT$1107, DW_AT_language(DW_LANG_C)
DWT$1108	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1106)
	.dwattr DWT$1108, DW_AT_address_class(0x20)
DWT$1112	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1111)

DWT$1117	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1116)
	.dwattr DWT$1117, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1117, DW_AT_byte_size(0x84)
DW$135	.dwtag  DW_TAG_subrange_type
	.dwattr DW$135, DW_AT_upper_bound(0x0a)
	.dwendtag DWT$1117

DWT$1122	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1121)
	.dwattr DWT$1122, DW_AT_address_class(0x20)
DWT$1124	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1123)
	.dwattr DWT$1124, DW_AT_address_class(0x20)
DWT$1126	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1125)
	.dwattr DWT$1126, DW_AT_address_class(0x20)
DWT$1128	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1127)
	.dwattr DWT$1128, DW_AT_address_class(0x20)
DWT$1130	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1129)
	.dwattr DWT$1130, DW_AT_address_class(0x20)
DWT$12	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned long")
	.dwattr DWT$12, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$12, DW_AT_byte_size(0x04)
DWT$1022	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1021)
	.dwattr DWT$1022, DW_AT_address_class(0x20)

DWT$1026	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1026, DW_AT_name("_FLASH_STATUS_ST")
	.dwattr DWT$1026, DW_AT_byte_size(0x10)
DW$136	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1019)
	.dwattr DW$136, DW_AT_name("stat1"), DW_AT_symbol_name("_stat1")
	.dwattr DW$136, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$136, DW_AT_accessibility(DW_ACCESS_public)
DW$137	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1019)
	.dwattr DW$137, DW_AT_name("stat2"), DW_AT_symbol_name("_stat2")
	.dwattr DW$137, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$137, DW_AT_accessibility(DW_ACCESS_public)
DW$138	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1019)
	.dwattr DW$138, DW_AT_name("stat3"), DW_AT_symbol_name("_stat3")
	.dwattr DW$138, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$138, DW_AT_accessibility(DW_ACCESS_public)
DW$139	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1019)
	.dwattr DW$139, DW_AT_name("stat4"), DW_AT_symbol_name("_stat4")
	.dwattr DW$139, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$139, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1026


DWT$1049	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1049, DW_AT_byte_size(0x30)
DW$140	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1031)
	.dwattr DW$140, DW_AT_name("patchlevel"), DW_AT_symbol_name("_patchlevel")
	.dwattr DW$140, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$140, DW_AT_accessibility(DW_ACCESS_public)
DW$141	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1032)
	.dwattr DW$141, DW_AT_name("minornumber"), DW_AT_symbol_name("_minornumber")
	.dwattr DW$141, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$141, DW_AT_accessibility(DW_ACCESS_public)
DW$142	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1033)
	.dwattr DW$142, DW_AT_name("majornumber"), DW_AT_symbol_name("_majornumber")
	.dwattr DW$142, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$142, DW_AT_accessibility(DW_ACCESS_public)
DW$143	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$143, DW_AT_name("reserved1"), DW_AT_symbol_name("_reserved1")
	.dwattr DW$143, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$143, DW_AT_accessibility(DW_ACCESS_public)
DW$144	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1034)
	.dwattr DW$144, DW_AT_name("errorcode"), DW_AT_symbol_name("_errorcode")
	.dwattr DW$144, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$144, DW_AT_accessibility(DW_ACCESS_public)
DW$145	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$145, DW_AT_name("reserved2"), DW_AT_symbol_name("_reserved2")
	.dwattr DW$145, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr DW$145, DW_AT_accessibility(DW_ACCESS_public)
DW$146	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1035)
	.dwattr DW$146, DW_AT_name("address"), DW_AT_symbol_name("_address")
	.dwattr DW$146, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$146, DW_AT_accessibility(DW_ACCESS_public)
DW$147	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1036)
	.dwattr DW$147, DW_AT_name("length"), DW_AT_symbol_name("_length")
	.dwattr DW$147, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$147, DW_AT_accessibility(DW_ACCESS_public)
DW$148	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1038)
	.dwattr DW$148, DW_AT_name("data"), DW_AT_symbol_name("_data")
	.dwattr DW$148, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$148, DW_AT_accessibility(DW_ACCESS_public)
DW$149	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1041)
	.dwattr DW$149, DW_AT_name("wdTriggerFct"), DW_AT_symbol_name("_wdTriggerFct")
	.dwattr DW$149, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$149, DW_AT_accessibility(DW_ACCESS_public)
DW$150	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1042)
	.dwattr DW$150, DW_AT_name("intendedData"), DW_AT_symbol_name("_intendedData")
	.dwattr DW$150, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$150, DW_AT_accessibility(DW_ACCESS_public)
DW$151	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1042)
	.dwattr DW$151, DW_AT_name("actualData"), DW_AT_symbol_name("_actualData")
	.dwattr DW$151, DW_AT_data_member_location[DW_OP_plus_uconst 0x1a]
	.dwattr DW$151, DW_AT_accessibility(DW_ACCESS_public)
DW$152	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1035)
	.dwattr DW$152, DW_AT_name("errorAddress"), DW_AT_symbol_name("_errorAddress")
	.dwattr DW$152, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$152, DW_AT_accessibility(DW_ACCESS_public)
DW$153	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1043)
	.dwattr DW$153, DW_AT_name("Command_UB"), DW_AT_symbol_name("_Command_UB")
	.dwattr DW$153, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr DW$153, DW_AT_accessibility(DW_ACCESS_public)
DW$154	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$154, DW_AT_name("Direction_UB"), DW_AT_symbol_name("_Direction_UB")
	.dwattr DW$154, DW_AT_data_member_location[DW_OP_plus_uconst 0x21]
	.dwattr DW$154, DW_AT_accessibility(DW_ACCESS_public)
DW$155	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1045)
	.dwattr DW$155, DW_AT_name("Format_UB"), DW_AT_symbol_name("_Format_UB")
	.dwattr DW$155, DW_AT_data_member_location[DW_OP_plus_uconst 0x22]
	.dwattr DW$155, DW_AT_accessibility(DW_ACCESS_public)
DW$156	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1046)
	.dwattr DW$156, DW_AT_name("Millisec_UB"), DW_AT_symbol_name("_Millisec_UB")
	.dwattr DW$156, DW_AT_data_member_location[DW_OP_plus_uconst 0x23]
	.dwattr DW$156, DW_AT_accessibility(DW_ACCESS_public)
DW$157	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1047)
	.dwattr DW$157, DW_AT_name("StartSector_US"), DW_AT_symbol_name("_StartSector_US")
	.dwattr DW$157, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr DW$157, DW_AT_accessibility(DW_ACCESS_public)
DW$158	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1047)
	.dwattr DW$158, DW_AT_name("EndSector_US"), DW_AT_symbol_name("_EndSector_US")
	.dwattr DW$158, DW_AT_data_member_location[DW_OP_plus_uconst 0x26]
	.dwattr DW$158, DW_AT_accessibility(DW_ACCESS_public)
DW$159	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1047)
	.dwattr DW$159, DW_AT_name("NbrOfSectors_US"), DW_AT_symbol_name("_NbrOfSectors_US")
	.dwattr DW$159, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr DW$159, DW_AT_accessibility(DW_ACCESS_public)
DW$160	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1047)
	.dwattr DW$160, DW_AT_name("ActualSector_US"), DW_AT_symbol_name("_ActualSector_US")
	.dwattr DW$160, DW_AT_data_member_location[DW_OP_plus_uconst 0x2a]
	.dwattr DW$160, DW_AT_accessibility(DW_ACCESS_public)
DW$161	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1048)
	.dwattr DW$161, DW_AT_name("Delaytime_UL"), DW_AT_symbol_name("_Delaytime_UL")
	.dwattr DW$161, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr DW$161, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1049

DWT$1050	.dwtag  DW_TAG_typedef, DW_AT_name("tFlashParam"), DW_AT_type(*DWT$1049)
	.dwattr DWT$1050, DW_AT_language(DW_LANG_C)
DWT$1051	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1050)
DWT$1106	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1105)
DWT$1111	.dwtag  DW_TAG_typedef, DW_AT_name("tHis_Header"), DW_AT_type(*DWT$1110)
	.dwattr DWT$1111, DW_AT_language(DW_LANG_C)
DWT$1116	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1115)
DWT$1121	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1114)
DWT$1123	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1114)
DWT$1125	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1114)
DWT$1127	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1114)
DWT$1129	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1114)
DWT$1031	.dwtag  DW_TAG_typedef, DW_AT_name("tBugfixVersion"), DW_AT_type(*DWT$6)
	.dwattr DWT$1031, DW_AT_language(DW_LANG_C)
DWT$1032	.dwtag  DW_TAG_typedef, DW_AT_name("tMinorNumber"), DW_AT_type(*DWT$6)
	.dwattr DWT$1032, DW_AT_language(DW_LANG_C)
DWT$1033	.dwtag  DW_TAG_typedef, DW_AT_name("tMajorNumber"), DW_AT_type(*DWT$6)
	.dwattr DWT$1033, DW_AT_language(DW_LANG_C)
DWT$1038	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1037)
	.dwattr DWT$1038, DW_AT_address_class(0x20)

DWT$1042	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1037)
	.dwattr DWT$1042, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1042, DW_AT_byte_size(0x02)
DW$162	.dwtag  DW_TAG_subrange_type
	.dwattr DW$162, DW_AT_upper_bound(0x01)
	.dwendtag DWT$1042

DWT$1043	.dwtag  DW_TAG_typedef, DW_AT_name("tCommand"), DW_AT_type(*DWT$6)
	.dwattr DWT$1043, DW_AT_language(DW_LANG_C)
DWT$1044	.dwtag  DW_TAG_typedef, DW_AT_name("tDirection"), DW_AT_type(*DWT$6)
	.dwattr DWT$1044, DW_AT_language(DW_LANG_C)
DWT$1045	.dwtag  DW_TAG_typedef, DW_AT_name("tFormat"), DW_AT_type(*DWT$6)
	.dwattr DWT$1045, DW_AT_language(DW_LANG_C)
DWT$1046	.dwtag  DW_TAG_typedef, DW_AT_name("tMilTime"), DW_AT_type(*DWT$6)
	.dwattr DWT$1046, DW_AT_language(DW_LANG_C)
DWT$1034	.dwtag  DW_TAG_typedef, DW_AT_name("tFlashResult"), DW_AT_type(*DWT$8)
	.dwattr DWT$1034, DW_AT_language(DW_LANG_C)
DWT$1047	.dwtag  DW_TAG_typedef, DW_AT_name("tSector"), DW_AT_type(*DWT$8)
	.dwattr DWT$1047, DW_AT_language(DW_LANG_C)
DWT$1036	.dwtag  DW_TAG_typedef, DW_AT_name("tLength"), DW_AT_type(*DWT$12)
	.dwattr DWT$1036, DW_AT_language(DW_LANG_C)
DWT$1048	.dwtag  DW_TAG_typedef, DW_AT_name("t_Delaytime"), DW_AT_type(*DWT$12)
	.dwattr DWT$1048, DW_AT_language(DW_LANG_C)
DWT$1041	.dwtag  DW_TAG_typedef, DW_AT_name("tWDTriggerFct"), DW_AT_type(*DWT$1040)
	.dwattr DWT$1041, DW_AT_language(DW_LANG_C)

DWT$1105	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1105, DW_AT_name("rti")
	.dwattr DWT$1105, DW_AT_byte_size(0x20)
DW$163	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1096)
	.dwattr DW$163, DW_AT_name("DRTICNTR_UN"), DW_AT_symbol_name("_DRTICNTR_UN")
	.dwattr DW$163, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$163, DW_AT_accessibility(DW_ACCESS_public)
DW$164	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1098)
	.dwattr DW$164, DW_AT_name("DRTIPCTL_UN"), DW_AT_symbol_name("_DRTIPCTL_UN")
	.dwattr DW$164, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$164, DW_AT_accessibility(DW_ACCESS_public)
DW$165	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1100)
	.dwattr DW$165, DW_AT_name("DRTICNTL_UN"), DW_AT_symbol_name("_DRTICNTL_UN")
	.dwattr DW$165, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$165, DW_AT_accessibility(DW_ACCESS_public)
DW$166	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$166, DW_AT_name("WKEY_UL"), DW_AT_symbol_name("_WKEY_UL")
	.dwattr DW$166, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$166, DW_AT_accessibility(DW_ACCESS_public)
DW$167	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$167, DW_AT_name("RTICR1_UL"), DW_AT_symbol_name("_RTICR1_UL")
	.dwattr DW$167, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$167, DW_AT_accessibility(DW_ACCESS_public)
DW$168	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$168, DW_AT_name("RTICR2_UL"), DW_AT_symbol_name("_RTICR2_UL")
	.dwattr DW$168, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$168, DW_AT_accessibility(DW_ACCESS_public)
DW$169	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1102)
	.dwattr DW$169, DW_AT_name("DRTICINT_UN"), DW_AT_symbol_name("_DRTICINT_UN")
	.dwattr DW$169, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$169, DW_AT_accessibility(DW_ACCESS_public)
DW$170	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1104)
	.dwattr DW$170, DW_AT_name("DRTICNTEN_UN"), DW_AT_symbol_name("_DRTICNTEN_UN")
	.dwattr DW$170, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$170, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1105


DWT$1110	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1110, DW_AT_byte_size(0x14)
DW$171	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$171, DW_AT_name("ubInterfaceVersion"), DW_AT_symbol_name("_ubInterfaceVersion")
	.dwattr DW$171, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$171, DW_AT_accessibility(DW_ACCESS_public)
DW$172	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$172, DW_AT_name("ubReserverd"), DW_AT_symbol_name("_ubReserverd")
	.dwattr DW$172, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$172, DW_AT_accessibility(DW_ACCESS_public)
DW$173	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$173, DW_AT_name("ubMask"), DW_AT_symbol_name("_ubMask")
	.dwattr DW$173, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$173, DW_AT_accessibility(DW_ACCESS_public)
DW$174	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$174, DW_AT_name("ubMCU"), DW_AT_symbol_name("_ubMCU")
	.dwattr DW$174, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$174, DW_AT_accessibility(DW_ACCESS_public)
DW$175	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1109)
	.dwattr DW$175, DW_AT_name("pfnFlashInit"), DW_AT_symbol_name("_pfnFlashInit")
	.dwattr DW$175, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$175, DW_AT_accessibility(DW_ACCESS_public)
DW$176	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1109)
	.dwattr DW$176, DW_AT_name("pfnFlashDeinit"), DW_AT_symbol_name("_pfnFlashDeinit")
	.dwattr DW$176, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$176, DW_AT_accessibility(DW_ACCESS_public)
DW$177	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1109)
	.dwattr DW$177, DW_AT_name("pfnFlashErase"), DW_AT_symbol_name("_pfnFlashErase")
	.dwattr DW$177, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$177, DW_AT_accessibility(DW_ACCESS_public)
DW$178	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1109)
	.dwattr DW$178, DW_AT_name("pfnFlashWrite"), DW_AT_symbol_name("_pfnFlashWrite")
	.dwattr DW$178, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$178, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1110


DWT$1114	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1114, DW_AT_name("_FLASH")
	.dwattr DWT$1114, DW_AT_byte_size(0x0c)
DW$179	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1019)
	.dwattr DW$179, DW_AT_name("Start_UL"), DW_AT_symbol_name("_Start_UL")
	.dwattr DW$179, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$179, DW_AT_accessibility(DW_ACCESS_public)
DW$180	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1019)
	.dwattr DW$180, DW_AT_name("Length_UL"), DW_AT_symbol_name("_Length_UL")
	.dwattr DW$180, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$180, DW_AT_accessibility(DW_ACCESS_public)
DW$181	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1024)
	.dwattr DW$181, DW_AT_name("Sector_UW"), DW_AT_symbol_name("_Sector_UW")
	.dwattr DW$181, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$181, DW_AT_accessibility(DW_ACCESS_public)
DW$182	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$182, DW_AT_name("Core_UB"), DW_AT_symbol_name("_Core_UB")
	.dwattr DW$182, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr DW$182, DW_AT_accessibility(DW_ACCESS_public)
DW$183	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$183, DW_AT_name("FlashType_UB"), DW_AT_symbol_name("_FlashType_UB")
	.dwattr DW$183, DW_AT_data_member_location[DW_OP_plus_uconst 0xb]
	.dwattr DW$183, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1114

DWT$1115	.dwtag  DW_TAG_typedef, DW_AT_name("FLASH_ST"), DW_AT_type(*DWT$1114)
	.dwattr DWT$1115, DW_AT_language(DW_LANG_C)
DWT$1037	.dwtag  DW_TAG_typedef, DW_AT_name("tData"), DW_AT_type(*DWT$6)
	.dwattr DWT$1037, DW_AT_language(DW_LANG_C)
DWT$1040	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1039)
	.dwattr DWT$1040, DW_AT_address_class(0x20)
DWT$1109	.dwtag  DW_TAG_typedef, DW_AT_name("tFlashFct"), DW_AT_type(*DWT$1082)
	.dwattr DWT$1109, DW_AT_language(DW_LANG_C)

DWT$1096	.dwtag  DW_TAG_union_type
	.dwattr DWT$1096, DW_AT_byte_size(0x04)
DW$184	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$184, DW_AT_name("DRTICNTR_UL"), DW_AT_symbol_name("_DRTICNTR_UL")
	.dwattr DW$184, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$184, DW_AT_accessibility(DW_ACCESS_public)
DW$185	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1095)
	.dwattr DW$185, DW_AT_name("DRTICNTR_ST"), DW_AT_symbol_name("_DRTICNTR_ST")
	.dwattr DW$185, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$185, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1096


DWT$1098	.dwtag  DW_TAG_union_type
	.dwattr DWT$1098, DW_AT_byte_size(0x04)
DW$186	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$186, DW_AT_name("DRTIPCTL_UL"), DW_AT_symbol_name("_DRTIPCTL_UL")
	.dwattr DW$186, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$186, DW_AT_accessibility(DW_ACCESS_public)
DW$187	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1097)
	.dwattr DW$187, DW_AT_name("DRTIPCTL_ST"), DW_AT_symbol_name("_DRTIPCTL_ST")
	.dwattr DW$187, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$187, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1098


DWT$1100	.dwtag  DW_TAG_union_type
	.dwattr DWT$1100, DW_AT_byte_size(0x04)
DW$188	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$188, DW_AT_name("DRTICNTL_UL"), DW_AT_symbol_name("_DRTICNTL_UL")
	.dwattr DW$188, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$188, DW_AT_accessibility(DW_ACCESS_public)
DW$189	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1099)
	.dwattr DW$189, DW_AT_name("DRTICNTL_ST"), DW_AT_symbol_name("_DRTICNTL_ST")
	.dwattr DW$189, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$189, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1100


DWT$1102	.dwtag  DW_TAG_union_type
	.dwattr DWT$1102, DW_AT_byte_size(0x04)
DW$190	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$190, DW_AT_name("DRTICINT_UL"), DW_AT_symbol_name("_DRTICINT_UL")
	.dwattr DW$190, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$190, DW_AT_accessibility(DW_ACCESS_public)
DW$191	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1101)
	.dwattr DW$191, DW_AT_name("DRTICINT_ST"), DW_AT_symbol_name("_DRTICINT_ST")
	.dwattr DW$191, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$191, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1102


DWT$1104	.dwtag  DW_TAG_union_type
	.dwattr DWT$1104, DW_AT_byte_size(0x04)
DW$192	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$192, DW_AT_name("DRTICNTEN_UL"), DW_AT_symbol_name("_DRTICNTEN_UL")
	.dwattr DW$192, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$192, DW_AT_accessibility(DW_ACCESS_public)
DW$193	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1103)
	.dwattr DW$193, DW_AT_name("DRTICNTEN_ST"), DW_AT_symbol_name("_DRTICNTEN_ST")
	.dwattr DW$193, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$193, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1104

DWT$1082	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1081)
	.dwattr DWT$1082, DW_AT_address_class(0x20)

DWT$1095	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1095, DW_AT_byte_size(0x04)
DW$194	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$194, DW_AT_name("DRTICNTR_B21"), DW_AT_symbol_name("_DRTICNTR_B21")
	.dwattr DW$194, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x15)
	.dwattr DW$194, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$194, DW_AT_accessibility(DW_ACCESS_public)
DW$195	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$195, DW_AT_name("DRTIMOD_B11"), DW_AT_symbol_name("_DRTIMOD_B11")
	.dwattr DW$195, DW_AT_bit_offset(0x15), DW_AT_bit_size(0x0b)
	.dwattr DW$195, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$195, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1095


DWT$1097	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1097, DW_AT_byte_size(0x04)
DW$196	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$196, DW_AT_name("RTIM_B3"), DW_AT_symbol_name("_RTIM_B3")
	.dwattr DW$196, DW_AT_bit_offset(0x12), DW_AT_bit_size(0x03)
	.dwattr DW$196, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$196, DW_AT_accessibility(DW_ACCESS_public)
DW$197	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$197, DW_AT_name("PREDL_B11"), DW_AT_symbol_name("_PREDL_B11")
	.dwattr DW$197, DW_AT_bit_offset(0x15), DW_AT_bit_size(0x0b)
	.dwattr DW$197, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$197, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1097


DWT$1099	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1099, DW_AT_byte_size(0x04)
DW$198	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$198, DW_AT_name("RTIF_B1"), DW_AT_symbol_name("_RTIF_B1")
	.dwattr DW$198, DW_AT_bit_offset(0x18), DW_AT_bit_size(0x01)
	.dwattr DW$198, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$198, DW_AT_accessibility(DW_ACCESS_public)
DW$199	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$199, DW_AT_name("RTIE_B1"), DW_AT_symbol_name("_RTIE_B1")
	.dwattr DW$199, DW_AT_bit_offset(0x19), DW_AT_bit_size(0x01)
	.dwattr DW$199, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$199, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1099


DWT$1101	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1101, DW_AT_byte_size(0x04)
DW$200	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$200, DW_AT_name("CF1_B1"), DW_AT_symbol_name("_CF1_B1")
	.dwattr DW$200, DW_AT_bit_offset(0x18), DW_AT_bit_size(0x01)
	.dwattr DW$200, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$200, DW_AT_accessibility(DW_ACCESS_public)
DW$201	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$201, DW_AT_name("CF2_B1"), DW_AT_symbol_name("_CF2_B1")
	.dwattr DW$201, DW_AT_bit_offset(0x19), DW_AT_bit_size(0x01)
	.dwattr DW$201, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$201, DW_AT_accessibility(DW_ACCESS_public)
DW$202	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$202, DW_AT_name("CE1_B1"), DW_AT_symbol_name("_CE1_B1")
	.dwattr DW$202, DW_AT_bit_offset(0x1a), DW_AT_bit_size(0x01)
	.dwattr DW$202, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$202, DW_AT_accessibility(DW_ACCESS_public)
DW$203	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$203, DW_AT_name("CR2_B1"), DW_AT_symbol_name("_CR2_B1")
	.dwattr DW$203, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$203, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$203, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1101


DWT$1103	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1103, DW_AT_byte_size(0x04)
DW$204	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$204, DW_AT_name("CNTEN_B2"), DW_AT_symbol_name("_CNTEN_B2")
	.dwattr DW$204, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x02)
	.dwattr DW$204, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$204, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1103


	.dwattr DW$112, DW_AT_external(0x01)
	.dwattr DW$33, DW_AT_external(0x01)
	.dwattr DW$41, DW_AT_external(0x01)
	.dwattr DW$49, DW_AT_external(0x01)
	.dwattr DW$49, DW_AT_type(*DWT$1030)
	.dwattr DW$25, DW_AT_external(0x01)
	.dwattr DW$66, DW_AT_external(0x01)
	.dwattr DW$89, DW_AT_external(0x01)
	.dwattr DW$89, DW_AT_type(*DWT$1024)
	.dwattr DW$100, DW_AT_external(0x01)
	.dwattr DW$100, DW_AT_type(*DWT$1024)
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

DW$205	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$205, DW_AT_location[DW_OP_reg0]
DW$206	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$206, DW_AT_location[DW_OP_reg1]
DW$207	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$207, DW_AT_location[DW_OP_reg2]
DW$208	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$208, DW_AT_location[DW_OP_reg3]
DW$209	.dwtag  DW_TAG_assign_register, DW_AT_name("V1")
	.dwattr DW$209, DW_AT_location[DW_OP_reg4]
DW$210	.dwtag  DW_TAG_assign_register, DW_AT_name("V2")
	.dwattr DW$210, DW_AT_location[DW_OP_reg5]
DW$211	.dwtag  DW_TAG_assign_register, DW_AT_name("V3")
	.dwattr DW$211, DW_AT_location[DW_OP_reg6]
DW$212	.dwtag  DW_TAG_assign_register, DW_AT_name("V4")
	.dwattr DW$212, DW_AT_location[DW_OP_reg7]
DW$213	.dwtag  DW_TAG_assign_register, DW_AT_name("V5")
	.dwattr DW$213, DW_AT_location[DW_OP_reg8]
DW$214	.dwtag  DW_TAG_assign_register, DW_AT_name("V6")
	.dwattr DW$214, DW_AT_location[DW_OP_reg9]
DW$215	.dwtag  DW_TAG_assign_register, DW_AT_name("V7")
	.dwattr DW$215, DW_AT_location[DW_OP_reg10]
DW$216	.dwtag  DW_TAG_assign_register, DW_AT_name("V8")
	.dwattr DW$216, DW_AT_location[DW_OP_reg11]
DW$217	.dwtag  DW_TAG_assign_register, DW_AT_name("V9")
	.dwattr DW$217, DW_AT_location[DW_OP_reg12]
DW$218	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$218, DW_AT_location[DW_OP_reg13]
DW$219	.dwtag  DW_TAG_assign_register, DW_AT_name("LR")
	.dwattr DW$219, DW_AT_location[DW_OP_reg14]
DW$220	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$220, DW_AT_location[DW_OP_reg15]
DW$221	.dwtag  DW_TAG_assign_register, DW_AT_name("C0")
	.dwattr DW$221, DW_AT_location[DW_OP_reg16]
DW$222	.dwtag  DW_TAG_assign_register, DW_AT_name("C1")
	.dwattr DW$222, DW_AT_location[DW_OP_reg17]
DW$223	.dwtag  DW_TAG_assign_register, DW_AT_name("C2")
	.dwattr DW$223, DW_AT_location[DW_OP_reg18]
DW$224	.dwtag  DW_TAG_assign_register, DW_AT_name("C3")
	.dwattr DW$224, DW_AT_location[DW_OP_reg19]
DW$225	.dwtag  DW_TAG_assign_register, DW_AT_name("C4")
	.dwattr DW$225, DW_AT_location[DW_OP_reg20]
DW$226	.dwtag  DW_TAG_assign_register, DW_AT_name("C5")
	.dwattr DW$226, DW_AT_location[DW_OP_reg21]
DW$227	.dwtag  DW_TAG_assign_register, DW_AT_name("C6")
	.dwattr DW$227, DW_AT_location[DW_OP_reg22]
DW$228	.dwtag  DW_TAG_assign_register, DW_AT_name("C7")
	.dwattr DW$228, DW_AT_location[DW_OP_reg23]
DW$229	.dwtag  DW_TAG_assign_register, DW_AT_name("AP")
	.dwattr DW$229, DW_AT_location[DW_OP_reg24]
DW$230	.dwtag  DW_TAG_assign_register, DW_AT_name("SR")
	.dwattr DW$230, DW_AT_location[DW_OP_reg25]
DW$231	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$231, DW_AT_location[DW_OP_reg26]
	.dwendtag DWCU

