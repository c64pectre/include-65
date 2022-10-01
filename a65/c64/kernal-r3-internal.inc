;    include-65: Include files for 6502 and related processors, generic and Commodore 64.
;    Copyright (C) 2022  C64PECTRE
;
;    This program is free software: you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation, either version 3 of the License, or
;    (at your option) any later version.
;
;    This program is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License
;    along with this program.  If not, see <https://www.gnu.org/licenses/>.
;
;    Contact: https://github.com/c64pectre/include-65/ create an issue

;;; summary: C64 Kernal revision 3 internals

; ==============================================================================
; Kernal revision 3 internals
; ==============================================================================

; ==============================================================================
; Constants ZPKERNAL
; ==============================================================================

;ZPKERNAL_STATUS              = $90  ; see c64/kernal-r3.inc
ZPKERNAL_STKEY                = $91
ZPKERNAL_SVXT                 = $92
ZPKERNAL_VERCK                = $93
ZPKERNAL_C3P0                 = $94
ZPKERNAL_BSOUR                = $95
ZPKERNAL_SYNO                 = $96
ZPKERNAL_XSAV                 = $97
ZPKERNAL_LDTND                = $98
ZPKERNAL_DFLTN                = $99
ZPKERNAL_DFLTO                = $9A
ZPKERNAL_PRTY                 = $9B
ZPKERNAL_DPSW                 = $9C
ZPKERNAL_MSGFLG               = $9D
ZPKERNAL_PTR1_T1              = $9E
ZPKERNAL_PTR2_T2_TMPC         = $9F
ZPKERNAL_TIME_0               = $A0
ZPKERNAL_TIME_1               = $A1
ZPKERNAL_TIME_2               = $A2
ZPKERNAL_PCNTR_R2D2           = $A3
ZPKERNAL_BSOUR1_FIRT          = $A4
ZPKERNAL_CNTDN_COUNT          = $A5
ZPKERNAL_BUFPT                = $A6
ZPKERNAL_INBIT_SHCNL          = $A7
ZPKERNAL_BITCI_RER            = $A8
ZPKERNAL_REZ_RINONE           = $A9
ZPKERNAL_RDFLG_RIDATA         = $AA
ZPKERNAL_RIPRTY_SHCNH         = $AB
ZPKERNAL_SAL                  = $AC
ZPKERNAL_SAH                  = $AD
ZPKERNAL_EAL                  = $AE
ZPKERNAL_EAH                  = $AF
ZPKERNAL_CMP0                 = $B0
ZPKERNAL_TEMP                 = $B1
ZPKERNAL_TAPE1_LO             = $B2
ZPKERNAL_TAPE1_HI             = $B3
ZPKERNAL_BITTS_SNSW1          = $B4
ZPKERNAL_DIFF_NXTBIT          = $B5
ZPKERNAL_PRP_RODATA           = $B6
ZPKERNAL_FNLEN                = $B7
ZPKERNAL_LA                   = $B8
ZPKERNAL_SA                   = $B9
ZPKERNAL_FA                   = $BA
ZPKERNAL_FNADR_LO             = $BB
ZPKERNAL_FNADR                = ZPKERNAL_FNADR_LO
ZPKERNAL_FNADR_HI             = $BC
ZPKERNAL_OCHAR_ROPRTY         = $BD
ZPKERNAL_FSBLK                = $BE
ZPKERNAL_MYCH                 = $BF
ZPKERNAL_CAS1                 = $C0
ZPKERNAL_STAL_TMP0            = $C1
ZPKERNAL_STAH                 = $C2
ZPKERNAL_MEMUSS_LO_TMP2_LO    = $C3
ZPKERNAL_MEMUSS_HI_TMP2_HI    = $C4
ZPKERNAL_LSTX                 = $C5
ZPKERNAL_NDX                  = $C6
ZPKERNAL_RVS                  = $C7
ZPKERNAL_INDX                 = $C8
ZPKERNAL_LSXP                 = $C9
ZPKERNAL_LSTP                 = $CA
ZPKERNAL_SFDX                 = $CB
ZPKERNAL_BLNSW                = $CC
ZPKERNAL_BLNCT                = $CD
ZPKERNAL_GDBLN                = $CE
ZPKERNAL_BLNON                = $CF
ZPKERNAL_CRSW                 = $D0
ZPKERNAL_PNT_LO               = $D1
ZPKERNAL_PNT_HI               = $D2
ZPKERNAL_PNTR                 = $D3
ZPKERNAL_QTSW                 = $D4
ZPKERNAL_LNMX                 = $D5
ZPKERNAL_TBLX                 = $D6
ZPKERNAL_DATA                 = $D7
ZPKERNAL_INSRT                = $D8
ZPKERNAL_LDTB1                = $D9
ZPKERNAL_USER_LO              = $F3
ZPKERNAL_USER_HI              = $F4
ZPKERNAL_KEYTAB_LO            = $F5
ZPKERNAL_KEYTAB_HI            = $F6
ZPKERNAL_RIBUF_LO             = $F7
ZPKERNAL_RIBUF_HI             = $F8
ZPKERNAL_ROBUF_LO             = $F9
ZPKERNAL_ROBUF_HI             = $FA
ZPKERNAL_FREKZP_FB            = $FB
ZPKERNAL_FREKZP_FC            = $FC
ZPKERNAL_FREKZP_FD            = $FD
ZPKERNAL_FREKZP_FE            = $FE
ZPKERNAL_BASZPT_STRTMP_LOFBUF = $FF

; ==============================================================================
; Constants KVAR
; ==============================================================================

KVAR_BUF_BUFOFS = $0200
KVAR_LAT        = $0259
KVAR_FAT        = $0263
KVAR_SAT        = $026D
KVAR_KEYD       = $0277
KVAR_MEMSTR     = $0281
KVAR_MEMSTR_LO  = $0281
KVAR_MEMSTR_HI  = $0282
KVAR_MEMSIZ     = $0283
KVAR_MEMSIZ_LO  = $0283
KVAR_MEMSIZ_HI  = $0284
KVAR_TIMOUT     = $0285
KVAR_COLOR      = $0286
KVAR_GDCOL      = $0287
KVAR_HIBASE     = $0288
KVAR_XMAX       = $0289
KVAR_RPTFLG     = $028A
KVAR_KOUNT      = $028B
KVAR_DELAY      = $028C
KVAR_SHFLAG     = $028D
KVAR_LSTSHF     = $028E
KVAR_KEYLOG     = $028F
KVAR_KEYLOG_LO  = $028F
KVAR_KEYLOG_HI  = $0290
KVAR_MODE       = $0291
KVAR_AUTODN     = $0292
KVAR_M51CTR     = $0293
KVAR_M51CDR     = $0294
KVAR_M51AJB     = $0295
KVAR_M51AJB_LO  = $0295
KVAR_M51AJB_HI  = $0296
KVAR_RSSTAT     = $0297
KVAR_BITNUM     = $0298
KVAR_BAUDOF     = $0299
KVAR_BAUDOF_LO  = $0299
KVAR_BAUDOF_HI  = $029A
KVAR_RIDBE      = $029B
KVAR_RIDBS      = $029C
KVAR_RODBS      = $029D
KVAR_RODBE      = $029E
KVAR_IRQTMP     = $029F
KVAR_IRQTMP_LO  = $029F
KVAR_IRQTMP_HI  = $02A0
KVAR_ENABL      = $02A1
KVAR_CASTON     = $02A2
KVAR_KIKA26     = $02A3
KVAR_STUPID     = $02A4
KVAR_LINTMP     = $02A5
KVAR_PALNTS     = $02A6

; ==============================================================================
; Constants KVECTORS
; ==============================================================================

KVECTORS_CINV      = $0314
KVECTORS_CINV_LO   = $0314
KVECTORS_CINV_HI   = $0315
KVECTORS_CBINV     = $0316
KVECTORS_CBINV_LO  = $0316
KVECTORS_CBINV_HI  = $0317
KVECTORS_NMINV     = $0318
KVECTORS_NMINV_LO  = $0318
KVECTORS_NMINV_HI  = $0319
KVECTORS_IOPEN     = $031A
KVECTORS_IOPEN_LO  = $031A
KVECTORS_IOPEN_HI  = $031B
KVECTORS_ICLOSE    = $031C
KVECTORS_ICLOSE_LO = $031C
KVECTORS_ICLOSE_HI = $031D
KVECTORS_ICHKIN    = $031E
KVECTORS_ICHKIN_LO = $031E
KVECTORS_ICHKIN_HI = $031F
KVECTORS_ICKOUT    = $0320
KVECTORS_ICKOUT_LO = $0320
KVECTORS_ICKOUT_HI = $0321
KVECTORS_ICLRCH    = $0322
KVECTORS_ICLRCH_LO = $0322
KVECTORS_ICLRCH_HI = $0323
KVECTORS_IBASIN    = $0324
KVECTORS_IBASIN_LO = $0324
KVECTORS_IBASIN_HI = $0325
KVECTORS_IBSOUT    = $0326
KVECTORS_IBSOUT_LO = $0326
KVECTORS_IBSOUT_HI = $0327
KVECTORS_ISTOP     = $0328
KVECTORS_ISTOP_LO  = $0328
KVECTORS_ISTOP_HI  = $0329
KVECTORS_IGETIN    = $032A
KVECTORS_IGETIN_LO = $032A
KVECTORS_IGETIN_HI = $032B
KVECTORS_ICLALL    = $032C
KVECTORS_ICLALL_LO = $032C
KVECTORS_ICLALL_HI = $032D
KVECTORS_USRCMD    = $032E
KVECTORS_USRCMD_LO = $032E
KVECTORS_USRCMD_HI = $032F
KVECTORS_ILOAD     = $0330
KVECTORS_ILOAD_LO  = $0330
KVECTORS_ILOAD_HI  = $0331
KVECTORS_ISAVE     = $0332
KVECTORS_ISAVE_LO  = $0332
KVECTORS_ISAVE_HI  = $0333

KERNAL_TBUFFR = $033C

MESSAGES_MS1   = $F0BD
MESSAGES_MS5   = $F0C9
MESSAGES_MS6   = $F0D4
MESSAGES_MS7   = $F0D8
MESSAGES_MS8   = $F0EB
MESSAGES_MS10  = $F106
MESSAGES_MS11  = $F10E
MESSAGES_MS21  = $F116
MESSAGES_MS17  = $F120
MESSAGES_MS18  = $F127
MESSAGES_SPMSG = $F12B
MESSAGES_MSG   = $F12F
MESSAGES_MSG10 = $F13C

ERROR_NSTOP  = $F6ED
ERROR_STOP2  = $F6FA
ERROR_ERROR1 = $F6FB
ERROR_ERROR2 = $F6FE
ERROR_ERROR3 = $F701
ERROR_ERROR4 = $F704
ERROR_ERROR5 = $F707
ERROR_ERROR6 = $F70A
ERROR_ERROR7 = $F70D
ERROR_ERROR8 = $F710
ERROR_ERROR9 = $F713
ERROR_EREXIT = $F729

JMPTBL_KERNAL_ACTUAL_REVISION = $FF80
JMPTBL_CINT                   = $FF81
JMPTBL_IOINIT                 = $FF84
JMPTBL_RAMTAS                 = $FF87
JMPTBL_RESTOR                 = $FF8A
JMPTBL_VECTOR                 = $FF8D
JMPTBL_SETMSG                 = $FF90
JMPTBL_SECOND                 = $FF93
JMPTBL_TKSA                   = $FF96
JMPTBL_MEMTOP                 = $FF99
JMPTBL_MEMBOT                 = $FF9C
JMPTBL_SCNKEY                 = $FF9F
JMPTBL_SETTMO                 = $FFA2
JMPTBL_ACPTR                  = $FFA5
JMPTBL_CIOUT                  = $FFA8
JMPTBL_UNTLK                  = $FFAB
JMPTBL_UNLSN                  = $FFAE
JMPTBL_LISTEN                 = $FFB1
JMPTBL_TALK                   = $FFB4
JMPTBL_READST                 = $FFB7
JMPTBL_SETLFS                 = $FFBA
JMPTBL_SETNAM                 = $FFBD
JMPTBL_OPEN                   = $FFC0
JMPTBL_CLOSE                  = $FFC3
JMPTBL_CHKIN                  = $FFC6
JMPTBL_CKOUT_CHKOUT           = $FFC9
JMPTBL_CLRCH_CLSCHN           = $FFCC
JMPTBL_BASIN_CHRIN            = $FFCF
JMPTBL_BSOUT_CHROUT           = $FFD2
JMPTBL_LOAD                   = $FFD5
JMPTBL_SAVE                   = $FFD8
JMPTBL_SETTIM                 = $FFDB
JMPTBL_RDTIM                  = $FFDE
JMPTBL_STOP                   = $FFE1
JMPTBL_GETIN                  = $FFE4
JMPTBL_CLALL_CCALL            = $FFE7
JMPTBL_UDTIM                  = $FFEA
JMPTBL_JSCROG_SCREEN          = $FFED
JMPTBL_JPLOT_PLOT             = $FFF0
JMPTBL_JIOBAS_IOBASE_RDBAS    = $FFF3
KERNAL_ACTUAL_SIGNATURE       = $FFF6

; ==============================================================================
; Constants
; ==============================================================================

KERNAL_INTERNAL_timrb  = $19      ; 6526 crb enable one-shot tb

; tape block types
KERNAL_INTERNAL_eot    = 5        ; end of tape
KERNAL_INTERNAL_blf    = 1        ; basic load file
KERNAL_INTERNAL_bdf    = 2        ; bdf: basic data file
KERNAL_INTERNAL_plf    = 3        ; plf: fixed program type
KERNAL_INTERNAL_bdfh   = 4        ; bdfh: basic data file header

KERNAL_INTERNAL_bufsz  = 192      ; tape buffer size

; screen editor constants

KERNAL_INTERNAL_llen   = 40       ; single line 40 columns
KERNAL_INTERNAL_llen2  = 80       ; double line = 80 columns
KERNAL_INTERNAL_nlines = 25       ; 25 rows on screen
KERNAL_INTERNAL_white  = $01      ; white screen color
KERNAL_INTERNAL_blue   = $06      ; blue char color
KERNAL_INTERNAL_cr     = $D       ; cr: carriage return

; .segment "EDITOR"
KERNAL_INTERNAL_maxchr = 80
KERNAL_INTERNAL_nwrap  = 2        ; max number of physical lines per logical line

; ==============================================================================
; Constants - Tape and IEEE errors
; ==============================================================================

KERNAL_INTERNAL_sberr  =  4       ; %00000100 bit 2
KERNAL_INTERNAL_lberr  =  8       ; %00001000 bit 3
KERNAL_INTERNAL_sperr  = 16       ; %00010000 bit 4
KERNAL_INTERNAL_ckerr  = 32       ; %00100000 bit 5

; ==============================================================================
; Constants - IEC
; ==============================================================================

KERNAL_INTERNAL_CHANNEL_CLSEI = $F642
KERNAL_INTERNAL_CHANNEL_OPENI = $F3D5

KERNAL_INTERNAL_SERIAL_ACPTR = $EE13
KERNAL_INTERNAL_SERIAL_TALK  = $ED09
KERNAL_INTERNAL_SERIAL_TKSA  = $EDC7
KERNAL_INTERNAL_SERIAL_UNTLK = $EDEF

KERNAL_INTERNAL_KEY  = $EA31            ; IRQ handler, see KERNAL_CINV
KERNAL_INTERNAL_NNMI = $FE47            ; NMI handler, see KERNAL_NMINV
KERNAL_INTERNAL_TIMB = $FE66            ; BRK handler, see KERNAL_CBINV
