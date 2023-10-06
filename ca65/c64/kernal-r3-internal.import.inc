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

.ifndef __KERNAL_R3_INTERNAL_IMPORT_INC__
    __KERNAL_R3_INTERNAL_IMPORT_INC__ = 1

; ==============================================================================
; Kernal revision 3 internals
; ==============================================================================

; ==============================================================================
; segment "ZPKERNAL"
; ==============================================================================

.importzp ZPKERNAL_STATUS
.importzp ZPKERNAL_STKEY
.importzp ZPKERNAL_SVXT
.importzp ZPKERNAL_VERCK
.importzp ZPKERNAL_C3P0
.importzp ZPKERNAL_BSOUR
.importzp ZPKERNAL_SYNO
.importzp ZPKERNAL_XSAV
.importzp ZPKERNAL_LDTND
.importzp ZPKERNAL_DFLTN
.importzp ZPKERNAL_DFLTO
.importzp ZPKERNAL_PRTY
.importzp ZPKERNAL_DPSW
.importzp ZPKERNAL_MSGFLG
.importzp ZPKERNAL_PTR1_T1
.importzp ZPKERNAL_PTR2_T2_TMPC
.importzp ZPKERNAL_TIME_0
.importzp ZPKERNAL_TIME_1
.importzp ZPKERNAL_TIME_2
.importzp ZPKERNAL_PCNTR_R2D2
.importzp ZPKERNAL_BSOUR1_FIRT
.importzp ZPKERNAL_CNTDN_COUNT
.importzp ZPKERNAL_BUFPT
.importzp ZPKERNAL_INBIT_SHCNL
.importzp ZPKERNAL_BITCI_RER
.importzp ZPKERNAL_REZ_RINONE
.importzp ZPKERNAL_RDFLG_RIDATA
.importzp ZPKERNAL_RIPRTY_SHCNH
.importzp ZPKERNAL_SAL
.importzp ZPKERNAL_SAH
.importzp ZPKERNAL_EAL
.importzp ZPKERNAL_EAH
.importzp ZPKERNAL_CMP0
.importzp ZPKERNAL_TEMP
.importzp ZPKERNAL_TAPE1_LO
.importzp ZPKERNAL_TAPE1_HI
.importzp ZPKERNAL_BITTS_SNSW1
.importzp ZPKERNAL_DIFF_NXTBIT
.importzp ZPKERNAL_PRP_RODATA
.importzp ZPKERNAL_FNLEN
.importzp ZPKERNAL_LA
.importzp ZPKERNAL_SA
.importzp ZPKERNAL_FA
.importzp ZPKERNAL_FNADR_LO
.importzp ZPKERNAL_FNADR
.importzp ZPKERNAL_FNADR_HI
.importzp ZPKERNAL_OCHAR_ROPRTY
.importzp ZPKERNAL_FSBLK
.importzp ZPKERNAL_MYCH
.importzp ZPKERNAL_CAS1
.importzp ZPKERNAL_STAL_TMP0
.importzp ZPKERNAL_STAH
.importzp ZPKERNAL_MEMUSS_LO_TMP2_LO
.importzp ZPKERNAL_MEMUSS_HI_TMP2_HI
.importzp ZPKERNAL_LSTX
.importzp ZPKERNAL_NDX
.importzp ZPKERNAL_RVS
.importzp ZPKERNAL_INDX
.importzp ZPKERNAL_LSXP
.importzp ZPKERNAL_LSTP
.importzp ZPKERNAL_SFDX
.importzp ZPKERNAL_BLNSW
.importzp ZPKERNAL_BLNCT
.importzp ZPKERNAL_GDBLN
.importzp ZPKERNAL_BLNON
.importzp ZPKERNAL_CRSW
.importzp ZPKERNAL_PNT_LO
.importzp ZPKERNAL_PNT_HI
.importzp ZPKERNAL_PNTR
.importzp ZPKERNAL_QTSW
.importzp ZPKERNAL_LNMX
.importzp ZPKERNAL_TBLX
.importzp ZPKERNAL_DATA
.importzp ZPKERNAL_INSRT
.importzp ZPKERNAL_LDTB1
.importzp ZPKERNAL_USER_LO
.importzp ZPKERNAL_USER_HI
.importzp ZPKERNAL_KEYTAB_LO
.importzp ZPKERNAL_KEYTAB_HI
.importzp ZPKERNAL_RIBUF_LO
.importzp ZPKERNAL_RIBUF_HI
.importzp ZPKERNAL_ROBUF_LO
.importzp ZPKERNAL_ROBUF_HI
.importzp ZPKERNAL_FREKZP_FB
.importzp ZPKERNAL_FREKZP_FC
.importzp ZPKERNAL_FREKZP_FD
.importzp ZPKERNAL_FREKZP_FE
.importzp ZPKERNAL_BASZPT_STRTMP_LOFBUF

; ==============================================================================
; Constants KVAR
; ==============================================================================

.import KVAR_BUF_BUFOFS
.import KVAR_LAT
.import KVAR_FAT
.import KVAR_SAT
.import KVAR_KEYD
.import KVAR_MEMSTR
.import KVAR_MEMSTR_LO
.import KVAR_MEMSTR_HI
.import KVAR_MEMSIZ
.import KVAR_MEMSIZ_LO
.import KVAR_MEMSIZ_HI
.import KVAR_TIMOUT
.import KVAR_COLOR
.import KVAR_GDCOL
.import KVAR_HIBASE
.import KVAR_XMAX
.import KVAR_RPTFLG
.import KVAR_KOUNT
.import KVAR_DELAY
.import KVAR_SHFLAG
.import KVAR_LSTSHF
.import KVAR_KEYLOG
.import KVAR_KEYLOG_LO
.import KVAR_KEYLOG_HI
.import KVAR_MODE
.import KVAR_AUTODN
.import KVAR_M51CTR
.import KVAR_M51CDR
.import KVAR_M51AJB
.import KVAR_M51AJB_LO
.import KVAR_M51AJB_HI
.import KVAR_RSSTAT
.import KVAR_BITNUM
.import KVAR_BAUDOF
.import KVAR_BAUDOF_LO
.import KVAR_BAUDOF_HI
.import KVAR_RIDBE
.import KVAR_RIDBS
.import KVAR_RODBS
.import KVAR_RODBE
.import KVAR_IRQTMP
.import KVAR_IRQTMP_LO
.import KVAR_IRQTMP_HI
.import KVAR_ENABL
.import KVAR_CASTON
.import KVAR_KIKA26
.import KVAR_STUPID
.import KVAR_LINTMP
.import KVAR_PALNTS

; ==============================================================================
; Constants KVECTORS
; ==============================================================================

.import KVECTORS_CINV      ; -> KERNAL_KEY
.import KVECTORS_CINV_LO
.import KVECTORS_CINV_HI
.import KVECTORS_CBINV     ; -> KERNAL_TIMB
.import KVECTORS_CBINV_LO
.import KVECTORS_CBINV_HI
.import KVECTORS_NMINV     ; -> KERNAL_NNMI
.import KVECTORS_NMINV_LO
.import KVECTORS_NMINV_HI
.import KVECTORS_IOPEN     ; -> KERNAL_NOPEN
.import KVECTORS_IOPEN_LO
.import KVECTORS_IOPEN_HI
.import KVECTORS_ICLOSE    ; -> KERNAL_NCLOSE
.import KVECTORS_ICLOSE_LO
.import KVECTORS_ICLOSE_HI
.import KVECTORS_ICHKIN    ; -> KERNAL_NCHKIN
.import KVECTORS_ICHKIN_LO
.import KVECTORS_ICHKIN_HI
.import KVECTORS_ICKOUT    ; -> KERNAL_NCKOUT
.import KVECTORS_ICKOUT_LO
.import KVECTORS_ICKOUT_HI
.import KVECTORS_ICLRCH    ; -> KERNAL_NCLRCH
.import KVECTORS_ICLRCH_LO
.import KVECTORS_ICLRCH_HI
.import KVECTORS_IBASIN    ; -> KERNAL_NBASIN
.import KVECTORS_IBASIN_LO
.import KVECTORS_IBASIN_HI
.import KVECTORS_IBSOUT    ; -> KERNAL_NBSOUT
.import KVECTORS_IBSOUT_LO
.import KVECTORS_IBSOUT_HI
.import KVECTORS_ISTOP     ; -> KERNAL_NSTOP
.import KVECTORS_ISTOP_LO
.import KVECTORS_ISTOP_HI
.import KVECTORS_IGETIN    ; -> KERNAL_NGETIN
.import KVECTORS_IGETIN_LO
.import KVECTORS_IGETIN_HI
.import KVECTORS_ICLALL    ; -> KERNAL_NCLALL
.import KVECTORS_ICLALL_LO
.import KVECTORS_ICLALL_HI
.import KVECTORS_USRCMD    ; -> KERNAL_TIMB
.import KVECTORS_USRCMD_LO
.import KVECTORS_USRCMD_HI
.import KVECTORS_ILOAD     ; -> KERNAL_NLOAD
.import KVECTORS_ILOAD_LO
.import KVECTORS_ILOAD_HI
.import KVECTORS_ISAVE     ; -> KERNAL_NSAVE
.import KVECTORS_ISAVE_LO
.import KVECTORS_ISAVE_HI

.import KERNAL_TBUFFR

.import MESSAGES_MS1
.import MESSAGES_MS5
.import MESSAGES_MS6
.import MESSAGES_MS7
.import MESSAGES_MS8
.import MESSAGES_MS10
.import MESSAGES_MS11
.import MESSAGES_MS21
.import MESSAGES_MS17
.import MESSAGES_MS18
.import MESSAGES_SPMSG
.import MESSAGES_MSG
.import MESSAGES_MSG10

.import ERROR_NSTOP
.import ERROR_STOP2
.import ERROR_ERROR1
.import ERROR_ERROR2
.import ERROR_ERROR3
.import ERROR_ERROR4
.import ERROR_ERROR5
.import ERROR_ERROR6
.import ERROR_ERROR7
.import ERROR_ERROR8
.import ERROR_ERROR9
.import ERROR_EREXIT

.import JMPTBL_KERNAL_ACTUAL_REVISION
.import JMPTBL_CINT
.import JMPTBL_IOINIT
.import JMPTBL_RAMTAS
.import JMPTBL_RESTOR
.import JMPTBL_VECTOR
.import JMPTBL_SETMSG
.import JMPTBL_SECOND
.import JMPTBL_TKSA
.import JMPTBL_MEMTOP
.import JMPTBL_MEMBOT
.import JMPTBL_SCNKEY
.import JMPTBL_SETTMO
.import JMPTBL_ACPTR
.import JMPTBL_CIOUT
.import JMPTBL_UNTLK
.import JMPTBL_UNLSN
.import JMPTBL_LISTEN
.import JMPTBL_TALK
.import JMPTBL_READST
.import JMPTBL_SETLFS
.import JMPTBL_SETNAM
.import JMPTBL_OPEN
.import JMPTBL_CLOSE
.import JMPTBL_CHKIN
.import JMPTBL_CKOUT_CHKOUT
.import JMPTBL_CLRCH_CLSCHN
.import JMPTBL_BASIN_CHRIN
.import JMPTBL_BSOUT_CHROUT
.import JMPTBL_LOAD
.import JMPTBL_SAVE
.import JMPTBL_SETTIM
.import JMPTBL_RDTIM
.import JMPTBL_STOP
.import JMPTBL_GETIN
.import JMPTBL_CLALL_CCALL
.import JMPTBL_UDTIM
.import JMPTBL_JSCROG_SCREEN
.import JMPTBL_JPLOT_PLOT
.import JMPTBL_JIOBAS_IOBASE_RDBAS
.import KERNAL_ACTUAL_SIGNATURE

;region Implementation of KVECTORS

.import KERNAL_KEY
.import KERNAL_TIMB
.import KERNAL_NNMI
.import KERNAL_NOPEN
.import KERNAL_NCLOSE
.import KERNAL_NCHKIN
.import KERNAL_NCKOUT
.import KERNAL_NCLRCH
.import KERNAL_NBASIN
.import KERNAL_NBSOUT
.import KERNAL_NSTOP
.import KERNAL_NGETIN
.import KERNAL_NCLALL
.import KERNAL_NLOAD
.import KERNAL_NSAVE

;endregion

.endif
