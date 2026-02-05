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

; ==============================================================================
; Kernal revision 3 internals
; ==============================================================================

; ==============================================================================
; segment "ZPKERNAL"
; ==============================================================================

.exportzp ZPKERNAL_STATUS               := $90
.exportzp ZPKERNAL_STKEY                := $91
.exportzp ZPKERNAL_SVXT                 := $92
.exportzp ZPKERNAL_VERCK                := $93
.exportzp ZPKERNAL_C3P0                 := $94
.exportzp ZPKERNAL_BSOUR                := $95
.exportzp ZPKERNAL_SYNO                 := $96
.exportzp ZPKERNAL_XSAV                 := $97
.exportzp ZPKERNAL_LDTND                := $98
.exportzp ZPKERNAL_DFLTN                := $99
.exportzp ZPKERNAL_DFLTO                := $9A
.exportzp ZPKERNAL_PRTY                 := $9B
.exportzp ZPKERNAL_DPSW                 := $9C
.exportzp ZPKERNAL_MSGFLG               := $9D
.exportzp ZPKERNAL_PTR1_T1              := $9E
.exportzp ZPKERNAL_PTR2_T2_TMPC         := $9F
.exportzp ZPKERNAL_TIME_0               := $A0
.exportzp ZPKERNAL_TIME_1               := $A1
.exportzp ZPKERNAL_TIME_2               := $A2
.exportzp ZPKERNAL_PCNTR_R2D2           := $A3
.exportzp ZPKERNAL_BSOUR1_FIRT          := $A4
.exportzp ZPKERNAL_CNTDN_COUNT          := $A5
.exportzp ZPKERNAL_BUFPT                := $A6
.exportzp ZPKERNAL_INBIT_SHCNL          := $A7
.exportzp ZPKERNAL_BITCI_RER            := $A8
.exportzp ZPKERNAL_REZ_RINONE           := $A9
.exportzp ZPKERNAL_RDFLG_RIDATA         := $AA
.exportzp ZPKERNAL_RIPRTY_SHCNH         := $AB
.exportzp ZPKERNAL_SAL                  := $AC
.exportzp ZPKERNAL_SAH                  := $AD
.exportzp ZPKERNAL_EAL                  := $AE
.exportzp ZPKERNAL_EAH                  := $AF
.exportzp ZPKERNAL_CMP0                 := $B0
.exportzp ZPKERNAL_TEMP                 := $B1
.exportzp ZPKERNAL_TAPE1_LO             := $B2
.exportzp ZPKERNAL_TAPE1_HI             := $B3
.exportzp ZPKERNAL_BITTS_SNSW1          := $B4
.exportzp ZPKERNAL_DIFF_NXTBIT          := $B5
.exportzp ZPKERNAL_PRP_RODATA           := $B6
.exportzp ZPKERNAL_FNLEN                := $B7
.exportzp ZPKERNAL_LA                   := $B8
.exportzp ZPKERNAL_SA                   := $B9
.exportzp ZPKERNAL_FA                   := $BA
.exportzp ZPKERNAL_FNADR_LO             := $BB
.exportzp ZPKERNAL_FNADR                := ZPKERNAL_FNADR_LO
.exportzp ZPKERNAL_FNADR_HI             := $BC
.exportzp ZPKERNAL_OCHAR_ROPRTY         := $BD
.exportzp ZPKERNAL_FSBLK                := $BE
.exportzp ZPKERNAL_MYCH                 := $BF
.exportzp ZPKERNAL_CAS1                 := $C0
.exportzp ZPKERNAL_STAL_TMP0            := $C1
.exportzp ZPKERNAL_STAH                 := $C2
.exportzp ZPKERNAL_MEMUSS_LO_TMP2_LO    := $C3
.exportzp ZPKERNAL_MEMUSS_HI_TMP2_HI    := $C4
.exportzp ZPKERNAL_LSTX                 := $C5
.exportzp ZPKERNAL_NDX                  := $C6
.exportzp ZPKERNAL_RVS                  := $C7
.exportzp ZPKERNAL_INDX                 := $C8
.exportzp ZPKERNAL_LSXP                 := $C9
.exportzp ZPKERNAL_LSTP                 := $CA
.exportzp ZPKERNAL_SFDX                 := $CB
.exportzp ZPKERNAL_BLNSW                := $CC
.exportzp ZPKERNAL_BLNCT                := $CD
.exportzp ZPKERNAL_GDBLN                := $CE
.exportzp ZPKERNAL_BLNON                := $CF
.exportzp ZPKERNAL_CRSW                 := $D0
.exportzp ZPKERNAL_PNT_LO               := $D1
.exportzp ZPKERNAL_PNT_HI               := $D2
.exportzp ZPKERNAL_PNT                  := ZPKERNAL_PNT_LO
.exportzp ZPKERNAL_PNTR                 := $D3
.exportzp ZPKERNAL_QTSW                 := $D4
.exportzp ZPKERNAL_LNMX                 := $D5
.exportzp ZPKERNAL_TBLX                 := $D6
.exportzp ZPKERNAL_DATA                 := $D7
.exportzp ZPKERNAL_INSRT                := $D8
.exportzp ZPKERNAL_LDTB1                := $D9
.exportzp ZPKERNAL_USER_LO              := $F3
.exportzp ZPKERNAL_USER_HI              := $F4
.exportzp ZPKERNAL_KEYTAB_LO            := $F5
.exportzp ZPKERNAL_KEYTAB_HI            := $F6
.exportzp ZPKERNAL_RIBUF_LO             := $F7
.exportzp ZPKERNAL_RIBUF_HI             := $F8
.exportzp ZPKERNAL_ROBUF_LO             := $F9
.exportzp ZPKERNAL_ROBUF_HI             := $FA
.exportzp ZPKERNAL_FREKZP_FB            := $FB
.exportzp ZPKERNAL_FREKZP_FC            := $FC
.exportzp ZPKERNAL_FREKZP_FD            := $FD
.exportzp ZPKERNAL_FREKZP_FE            := $FE
.exportzp ZPKERNAL_BASZPT_STRTMP_LOFBUF := $FF

; ==============================================================================
; Constants KVAR
; ==============================================================================

.export KVAR_BUF_BUFOFS := $0200
.export KVAR_LAT        := $0259
.export KVAR_FAT        := $0263
.export KVAR_SAT        := $026D
.export KVAR_KEYD       := $0277
.export KVAR_MEMSTR     := $0281
.export KVAR_MEMSTR_LO  := $0281
.export KVAR_MEMSTR_HI  := $0282
.export KVAR_MEMSIZ     := $0283
.export KVAR_MEMSIZ_LO  := $0283
.export KVAR_MEMSIZ_HI  := $0284
.export KVAR_TIMOUT     := $0285
.export KVAR_COLOR      := $0286
.export KVAR_GDCOL      := $0287
.export KVAR_HIBASE     := $0288
.export KVAR_XMAX       := $0289
.export KVAR_RPTFLG     := $028A
.export KVAR_KOUNT      := $028B
.export KVAR_DELAY      := $028C
.export KVAR_SHFLAG     := $028D
.export KVAR_LSTSHF     := $028E
.export KVAR_KEYLOG     := $028F
.export KVAR_KEYLOG_LO  := $028F
.export KVAR_KEYLOG_HI  := $0290
.export KVAR_MODE       := $0291
.export KVAR_AUTODN     := $0292
.export KVAR_M51CTR     := $0293
.export KVAR_M51CDR     := $0294
.export KVAR_M51AJB     := $0295
.export KVAR_M51AJB_LO  := $0295
.export KVAR_M51AJB_HI  := $0296
.export KVAR_RSSTAT     := $0297
.export KVAR_BITNUM     := $0298
.export KVAR_BAUDOF     := $0299
.export KVAR_BAUDOF_LO  := $0299
.export KVAR_BAUDOF_HI  := $029A
.export KVAR_RIDBE      := $029B
.export KVAR_RIDBS      := $029C
.export KVAR_RODBS      := $029D
.export KVAR_RODBE      := $029E
.export KVAR_IRQTMP     := $029F
.export KVAR_IRQTMP_LO  := $029F
.export KVAR_IRQTMP_HI  := $02A0
.export KVAR_ENABL      := $02A1
.export KVAR_CASTON     := $02A2
.export KVAR_KIKA26     := $02A3
.export KVAR_STUPID     := $02A4
.export KVAR_LINTMP     := $02A5
.export KVAR_PALNTS     := $02A6

; ==============================================================================
; Constants KVECTORS
; ==============================================================================

.export KVECTORS_CINV      := $0314
.export KVECTORS_CINV_LO   := $0314
.export KVECTORS_CINV_HI   := $0315
.export KVECTORS_CBINV     := $0316
.export KVECTORS_CBINV_LO  := $0316
.export KVECTORS_CBINV_HI  := $0317
.export KVECTORS_NMINV     := $0318
.export KVECTORS_NMINV_LO  := $0318
.export KVECTORS_NMINV_HI  := $0319
.export KVECTORS_IOPEN     := $031A
.export KVECTORS_IOPEN_LO  := $031A
.export KVECTORS_IOPEN_HI  := $031B
.export KVECTORS_ICLOSE    := $031C
.export KVECTORS_ICLOSE_LO := $031C
.export KVECTORS_ICLOSE_HI := $031D
.export KVECTORS_ICHKIN    := $031E
.export KVECTORS_ICHKIN_LO := $031E
.export KVECTORS_ICHKIN_HI := $031F
.export KVECTORS_ICKOUT    := $0320
.export KVECTORS_ICKOUT_LO := $0320
.export KVECTORS_ICKOUT_HI := $0321
.export KVECTORS_ICLRCH    := $0322
.export KVECTORS_ICLRCH_LO := $0322
.export KVECTORS_ICLRCH_HI := $0323
.export KVECTORS_IBASIN    := $0324
.export KVECTORS_IBASIN_LO := $0324
.export KVECTORS_IBASIN_HI := $0325
.export KVECTORS_IBSOUT    := $0326
.export KVECTORS_IBSOUT_LO := $0326
.export KVECTORS_IBSOUT_HI := $0327
.export KVECTORS_ISTOP     := $0328
.export KVECTORS_ISTOP_LO  := $0328
.export KVECTORS_ISTOP_HI  := $0329
.export KVECTORS_IGETIN    := $032A
.export KVECTORS_IGETIN_LO := $032A
.export KVECTORS_IGETIN_HI := $032B
.export KVECTORS_ICLALL    := $032C
.export KVECTORS_ICLALL_LO := $032C
.export KVECTORS_ICLALL_HI := $032D
.export KVECTORS_USRCMD    := $032E
.export KVECTORS_USRCMD_LO := $032E
.export KVECTORS_USRCMD_HI := $032F
.export KVECTORS_ILOAD     := $0330
.export KVECTORS_ILOAD_LO  := $0330
.export KVECTORS_ILOAD_HI  := $0331
.export KVECTORS_ISAVE     := $0332
.export KVECTORS_ISAVE_LO  := $0332
.export KVECTORS_ISAVE_HI  := $0333

;;; summary: Datasette/tape buffer $033C-$03FB (192 bytes)
.export KERNAL_TBUFFR := $033C
.export KERNAL_UNUSED_03FC = $03FC
.export KERNAL_UNUSED_03FD = $03FD
.export KERNAL_UNUSED_03FE = $03FE
.export KERNAL_UNUSED_03FF = $03FF

.export MESSAGES_MS1   := $F0BD
.export MESSAGES_MS5   := $F0C9
.export MESSAGES_MS6   := $F0D4
.export MESSAGES_MS7   := $F0D8
.export MESSAGES_MS8   := $F0EB
.export MESSAGES_MS10  := $F106
.export MESSAGES_MS11  := $F10E
.export MESSAGES_MS21  := $F116
.export MESSAGES_MS17  := $F120
.export MESSAGES_MS18  := $F127
.export MESSAGES_SPMSG := $F12B
.export MESSAGES_MSG   := $F12F
.export MESSAGES_MSG10 := $F13C

.export ERROR_NSTOP  := $F6ED
.export ERROR_STOP2  := $F6FA
.export ERROR_ERROR1 := $F6FB
.export ERROR_ERROR2 := $F6FE
.export ERROR_ERROR3 := $F701
.export ERROR_ERROR4 := $F704
.export ERROR_ERROR5 := $F707
.export ERROR_ERROR6 := $F70A
.export ERROR_ERROR7 := $F70D
.export ERROR_ERROR8 := $F710
.export ERROR_ERROR9 := $F713
.export ERROR_EREXIT := $F729

.export JMPTBL_KERNAL_ACTUAL_REVISION := $FF80
.export JMPTBL_CINT                   := $FF81
.export JMPTBL_IOINIT                 := $FF84
.export JMPTBL_RAMTAS                 := $FF87
.export JMPTBL_RESTOR                 := $FF8A
.export JMPTBL_VECTOR                 := $FF8D
.export JMPTBL_SETMSG                 := $FF90
.export JMPTBL_SECOND                 := $FF93
.export JMPTBL_TKSA                   := $FF96
.export JMPTBL_MEMTOP                 := $FF99
.export JMPTBL_MEMBOT                 := $FF9C
.export JMPTBL_SCNKEY                 := $FF9F
.export JMPTBL_SETTMO                 := $FFA2
.export JMPTBL_ACPTR                  := $FFA5
.export JMPTBL_CIOUT                  := $FFA8
.export JMPTBL_UNTLK                  := $FFAB
.export JMPTBL_UNLSN                  := $FFAE
.export JMPTBL_LISTEN                 := $FFB1
.export JMPTBL_TALK                   := $FFB4
.export JMPTBL_READST                 := $FFB7
.export JMPTBL_SETLFS                 := $FFBA
.export JMPTBL_SETNAM                 := $FFBD
.export JMPTBL_OPEN                   := $FFC0
.export JMPTBL_CLOSE                  := $FFC3
.export JMPTBL_CHKIN                  := $FFC6
.export JMPTBL_CKOUT_CHKOUT           := $FFC9
.export JMPTBL_CLRCH_CLSCHN           := $FFCC
.export JMPTBL_BASIN_CHRIN            := $FFCF
.export JMPTBL_BSOUT_CHROUT           := $FFD2
.export JMPTBL_LOAD                   := $FFD5
.export JMPTBL_SAVE                   := $FFD8
.export JMPTBL_SETTIM                 := $FFDB
.export JMPTBL_RDTIM                  := $FFDE
.export JMPTBL_STOP                   := $FFE1
.export JMPTBL_GETIN                  := $FFE4
.export JMPTBL_CLALL_CCALL            := $FFE7
.export JMPTBL_UDTIM                  := $FFEA
.export JMPTBL_JSCROG_SCREEN          := $FFED
.export JMPTBL_JPLOT_PLOT             := $FFF0
.export JMPTBL_JIOBAS_IOBASE_RDBAS    := $FFF3
.export KERNAL_ACTUAL_SIGNATURE       := $FFF6

;region Implementation of KVECTORS

.export KERNAL_KEY    := $EA31
.export KERNAL_TIMB   := $FE66
.export KERNAL_NNMI   := $FE47
.export KERNAL_NOPEN  := $F34A
.export KERNAL_NCLOSE := $F291
.export KERNAL_NCHKIN := $F20E
.export KERNAL_NCKOUT := $F250
.export KERNAL_NCLRCH := $F333
.export KERNAL_NBASIN := $F157
.export KERNAL_NBSOUT := $F1CA
.export KERNAL_NSTOP  := $F6ED
.export KERNAL_NGETIN := $F13E
.export KERNAL_NCLALL := $F32F
.export KERNAL_NLOAD  := $F4A5
.export KERNAL_NSAVE  := $F5ED

;endregion

;region IEC handlers

.export KERNAL_INTERNAL_CHANNEL_CLSEI = $F642
.export KERNAL_INTERNAL_CHANNEL_OPENI = $F3D5

.export KERNAL_INTERNAL_SERIAL_ACPTR = $EE13
.export KERNAL_INTERNAL_SERIAL_TALK  = $ED09
.export KERNAL_INTERNAL_SERIAL_TKSA  = $EDC7
.export KERNAL_INTERNAL_SERIAL_UNTLK = $EDEF

;endregion

; IRQ NMI BRK handlers

.export KERNAL_INTERNAL_KEY  = $EA31            ; IRQ handler, see KERNAL_CINV
.export KERNAL_INTERNAL_NNMI = $FE47            ; NMI handler, see KERNAL_NMINV
.export KERNAL_INTERNAL_TIMB = $FE66            ; BRK handler, see KERNAL_CBINV

;endregion
