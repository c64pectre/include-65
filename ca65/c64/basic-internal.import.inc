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

;;; summary: Internal constants for C64 Basic

.ifndef __C64_BASIC_INTERNAL_IMPORT_INC__
    __C64_BASIC_INTERNAL_IMPORT_INC__ = 1

.importzp ZPBASIC_ADRAY1_LO
.importzp ZPBASIC_ADRAY1_HI
.importzp ZPBASIC_ADRAY2_LO
.importzp ZPBASIC_ADRAY2_HI
.importzp ZPBASIC_CHARAC_INTEGR
.importzp ZPBASIC_ENDCHR
.importzp ZPBASIC_TRMPOS
.importzp ZPBASIC_VERCK
.importzp ZPBASIC_COUNT
.importzp ZPBASIC_DIMFLG
.importzp ZPBASIC_VALTYP
.importzp ZPBASIC_INTFLG
.importzp ZPBASIC_DORES_GARBFL
.importzp ZPBASIC_SUBFLG
.importzp ZPBASIC_INPFLG
.importzp ZPBASIC_DOMASK_TANSGN
.importzp ZPBASIC_CHANNL
.importzp ZPBASIC_LINNUM_LO_POKER_LO
.importzp ZPBASIC_LINNUM_HI_POKER_HI
.importzp ZPBASIC_TEMPPT
.importzp ZPBASIC_LASTPT_LO
.importzp ZPBASIC_LASTPT_HI
.importzp ZPBASIC_TEMPST
.importzp ZPBASIC_INDEX_LO_INDEX1_LO
.importzp ZPBASIC_INDEX_HI_INDEX1_HI
.importzp ZPBASIC_INDEX2_LO
.importzp ZPBASIC_INDEX2_HI
.importzp ZPBASIC_RESHO
.importzp ZPBASIC_RESMOH
.importzp ZPBASIC_ADDEND_RESMO
.importzp ZPBASIC_RESLO
.importzp ZPBASIC_UNUSED_2A
.importzp ZPBASIC_TXTTAB_LO
.importzp ZPBASIC_TXTTAB_HI
.importzp ZPBASIC_VARTAB_LO
.importzp ZPBASIC_VARTAB_HI
.importzp ZPBASIC_ARYTAB_LO
.importzp ZPBASIC_ARYTAB_HI
.importzp ZPBASIC_STREND_LO
.importzp ZPBASIC_STREND_HI
.importzp ZPBASIC_FRETOP_LO
.importzp ZPBASIC_FRETOP_HI
.importzp ZPBASIC_FRESPC_LO
.importzp ZPBASIC_FRESPC_HI
.importzp ZPBASIC_MEMSIZ_LO
.importzp ZPBASIC_MEMSIZ_HI
.importzp ZPBASIC_CURLIN_LO
.importzp ZPBASIC_CURLIN_HI
.importzp ZPBASIC_OLDLIN_LO
.importzp ZPBASIC_OLDLIN_HI
.importzp ZPBASIC_OLDTXT_LO
.importzp ZPBASIC_OLDTXT_HI
.importzp ZPBASIC_DATLIN_LO
.importzp ZPBASIC_DATLIN_HI
.importzp ZPBASIC_DATPTR_LO
.importzp ZPBASIC_DATPTR_HI
.importzp ZPBASIC_INPPTR_LO
.importzp ZPBASIC_INPPTR_HI
.importzp ZPBASIC_VARNAM_LO
.importzp ZPBASIC_VARNAM_HI
.importzp ZPBASIC_FDECPT_LO_VARPNT_LO
.importzp ZPBASIC_FDECPT_HI_VARPNT_HI
.importzp ZPBASIC_ANDMSK_FORPNT_LO_LSTPNT_LO
.importzp ZPBASIC_EORMSK_FORPNT_HI_LSTPNT_HI
.importzp ZPBASIC_OPPTR_LO_VARTXT_LO
.importzp ZPBASIC_OPPTR_HI_VARTXT_HI
.importzp ZPBASIC_OPMASK
.importzp ZPBASIC_DEFPNT_LO_GRBPNT_LO_TEMPF3_LO
.importzp ZPBASIC_DEFPNT_HI_GRBPNT_HI_TEMPF3_HI
.importzp ZPBASIC_DSCPNT_LO
.importzp ZPBASIC_DSCPNT_HI
.importzp ZPBASIC_UNUSED_52
.importzp ZPBASIC_FOUR6
.importzp ZPBASIC_JMPER
.importzp ZPBASIC_SIZE
.importzp ZPBASIC_OLDOV
.importzp ZPBASIC_TEMPF1
.importzp ZPBASIC_ARYPNT_LO_HIGHDS_LO
.importzp ZPBASIC_ARYPNT_HI_HIGHDS_HI
.importzp ZPBASIC_HIGHTR_LO
.importzp ZPBASIC_HIGHTR_HI
.importzp ZPBASIC_TEMPF2
.importzp ZPBASIC_DECCNT_LO_LOWDS_LO
.importzp ZPBASIC_DECCNT_HI_LOWDS_HI_TENEXP
.importzp ZPBASIC_DPTFLG_GRBTOP_LOWTR
.importzp ZPBASIC_EXPSGN_EPSGN
.importzp ZPBASIC_DSCTMP_FAC_FACEXP
.importzp ZPBASIC_FACHO
.importzp ZPBASIC_FACMOH
.importzp ZPBASIC_FACMO_INDICE
.importzp ZPBASIC_FACLO
.importzp ZPBASIC_FACSGN
.importzp ZPBASIC_DEGREE_SGNFLG
.importzp ZPBASIC_BITS
.importzp ZPBASIC_ARGEXP
.importzp ZPBASIC_ARGHO
.importzp ZPBASIC_ARGMOH
.importzp ZPBASIC_ARGMO
.importzp ZPBASIC_ARGLO
.importzp ZPBASIC_ARGSGN
.importzp ZPBASIC_ARISGN_STRNGI_STRNG1
.importzp ZPBASIC_FACOV
.importzp ZPBASIC_BUFPTR_LO_CURTOL_LO_FBUFPT_LO_POLYPT_LO_STRNG2_LO
.importzp ZPBASIC_BUFPTR_HI_CURTOL_HI_FBUFPT_HI_POLYPT_HI_STRNG2_HI
.importzp ZPBASIC_CHRGET
.importzp ZPBASIC_CHRGOT
.importzp ZPBASIC_TXTPTR
.importzp ZPBASIC_QNUM
.importzp ZPBASIC_CHRRTS
.importzp ZPBASIC_RNDX

.import BVECTORS_IERROR     ; indirect error (output error in .x)
.import BVECTORS_IERROR_LO  ;
.import BVECTORS_IERROR_HI  ;
.import BVECTORS_IMAIN      ; indirect main (system direct loop)
.import BVECTORS_IMAIN_LO   ;
.import BVECTORS_IMAIN_HI   ;
.import BVECTORS_ICRNCH     ; indirect crunch (tokenization routine)
.import BVECTORS_ICRNCH_LO  ;
.import BVECTORS_ICRNCH_HI  ;
.import BVECTORS_IQPLOP     ; indirect list (char list)
.import BVECTORS_IQPLOP_LO  ;
.import BVECTORS_IQPLOP_HI  ;
.import BVECTORS_IGONE      ; indirect gone (char dispatch)
.import BVECTORS_IGONE_LO   ;
.import BVECTORS_IGONE_HI   ;
.import BVECTORS_IEVAL      ; indirect eval (symbol evaluation)
.import BVECTORS_IEVAL_LO   ;
.import BVECTORS_IEVAL_HI   ;
.import BVECTORS_SAREG      ; temp storage a reg
.import BVECTORS_SXREG      ; temp storage x reg
.import BVECTORS_SYREG      ; temp storage y reg
.import BVECTORS_SPREG      ; temp storage p reg
.import BVECTORS_USRPOK     ; user function dispatch
.import BVECTORS_USRPOK_0   ;
.import BVECTORS_USRPOK_1   ;
.import BVECTORS_USRPOK_2   ;

.endif
