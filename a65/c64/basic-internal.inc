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

ZPBASIC_ADRAY1_LO                     = $03
ZPBASIC_ADRAY1_HI                     = $04
ZPBASIC_ADRAY2_LO                     = $05
ZPBASIC_ADRAY2_HI                     = $06
ZPBASIC_CHARAC_INTEGR                 = $07
ZPBASIC_ENDCHR                        = $08
ZPBASIC_TRMPOS                        = $09
ZPBASIC_VERCK                         = $0A
ZPBASIC_COUNT                         = $0B
ZPBASIC_DIMFLG                        = $0C
ZPBASIC_VALTYP                        = $0D
ZPBASIC_INTFLG                        = $0E
ZPBASIC_DORES_GARBFL                  = $0F
ZPBASIC_SUBFLG                        = $10
ZPBASIC_INPFLG                        = $11
ZPBASIC_DOMASK_TANSGN                 = $12
ZPBASIC_CHANNL                        = $13
ZPBASIC_LINNUM_LO_POKER_LO            = $14
ZPBASIC_LINNUM_HI_POKER_HI            = $15
ZPBASIC_TEMPPT                        = $16
ZPBASIC_LASTPT_LO                     = $17
ZPBASIC_LASTPT_HI                     = $18
ZPBASIC_TEMPST                        = $19
ZPBASIC_INDEX_LO_INDEX1_LO            = $22
ZPBASIC_INDEX_HI_INDEX1_HI            = $23
ZPBASIC_INDEX2_LO                     = $24
ZPBASIC_INDEX2_HI                     = $25
ZPBASIC_RESHO                         = $26
ZPBASIC_RESMOH                        = $27
ZPBASIC_ADDEND_RESMO                  = $28
ZPBASIC_RESLO                         = $29
ZPBASIC_UNUSED_2A                     = $2A
ZPBASIC_TXTTAB_LO                     = $2B
ZPBASIC_TXTTAB_HI                     = $2C
ZPBASIC_VARTAB_LO                     = $2D
ZPBASIC_VARTAB_HI                     = $2E
ZPBASIC_ARYTAB_LO                     = $2F
ZPBASIC_ARYTAB_HI                     = $30
ZPBASIC_STREND_LO                     = $31
ZPBASIC_STREND_HI                     = $32
ZPBASIC_FRETOP_LO                     = $33
ZPBASIC_FRETOP_HI                     = $34
ZPBASIC_FRESPC_LO                     = $35
ZPBASIC_FRESPC_HI                     = $36
ZPBASIC_MEMSIZ_LO                     = $37
ZPBASIC_MEMSIZ_HI                     = $38
ZPBASIC_CURLIN_LO                     = $39
ZPBASIC_CURLIN_HI                     = $3A
ZPBASIC_OLDLIN_LO                     = $3B
ZPBASIC_OLDLIN_HI                     = $3C
ZPBASIC_OLDTXT_LO                     = $3D
ZPBASIC_OLDTXT_HI                     = $3E
ZPBASIC_DATLIN_LO                     = $3F
ZPBASIC_DATLIN_HI                     = $40
ZPBASIC_DATPTR_LO                     = $41
ZPBASIC_DATPTR_HI                     = $42
ZPBASIC_INPPTR_LO                     = $43
ZPBASIC_INPPTR_HI                     = $44
ZPBASIC_VARNAM_LO                     = $45
ZPBASIC_VARNAM_HI                     = $46
ZPBASIC_FDECPT_LO_VARPNT_LO           = $47
ZPBASIC_FDECPT_HI_VARPNT_HI           = $48
ZPBASIC_ANDMSK_FORPNT_LO_LSTPNT_LO    = $49
ZPBASIC_EORMSK_FORPNT_HI_LSTPNT_HI    = $4A
ZPBASIC_OPPTR_LO_VARTXT_LO            = $4B
ZPBASIC_OPPTR_HI_VARTXT_HI            = $4C
ZPBASIC_OPMASK                        = $4D
ZPBASIC_DEFPNT_LO_GRBPNT_LO_TEMPF3_LO = $4E
ZPBASIC_DEFPNT_HI_GRBPNT_HI_TEMPF3_HI = $4F
ZPBASIC_DSCPNT_LO                     = $50
ZPBASIC_DSCPNT_HI                     = $51
ZPBASIC_UNUSED_52                     = $52
ZPBASIC_FOUR6                         = $53
ZPBASIC_JMPER                         = $54
ZPBASIC_SIZE                          = $55
ZPBASIC_OLDOV                         = $56
ZPBASIC_TEMPF1                        = $57
ZPBASIC_ARYPNT_LO_HIGHDS_LO           = $58
ZPBASIC_ARYPNT_HI_HIGHDS_HI           = $59
ZPBASIC_HIGHTR_LO                     = $5A
ZPBASIC_HIGHTR_HI                     = $5B
ZPBASIC_TEMPF2                        = $5C
ZPBASIC_DECCNT_LO_LOWDS_LO            = $5D
ZPBASIC_DECCNT_HI_LOWDS_HI_TENEXP     = $5E
ZPBASIC_DPTFLG_GRBTOP_LOWTR           = $5F
ZPBASIC_EXPSGN_EPSGN                  = $60
ZPBASIC_DSCTMP_FAC_FACEXP             = $61
ZPBASIC_FACHO                         = $62
ZPBASIC_FACMOH                        = $63
ZPBASIC_FACMO_INDICE                  = $64
ZPBASIC_FACLO                         = $65
ZPBASIC_FACSGN                        = $66
ZPBASIC_DEGREE_SGNFLG                 = $67
ZPBASIC_BITS                          = $68
ZPBASIC_ARGEXP                        = $69
ZPBASIC_ARGHO                         = $6A
ZPBASIC_ARGMOH                        = $6B
ZPBASIC_ARGMO                         = $6C
ZPBASIC_ARGLO                         = $6D
ZPBASIC_ARGSGN                        = $6E
ZPBASIC_ARISGN_STRNGI_STRNG1          = $6F
ZPBASIC_FACOV                         = $70
ZPBASIC_BUFPTR_LO_CURTOL_LO_FBUFPT_LO_POLYPT_LO_STRNG2_LO = $71
ZPBASIC_BUFPTR_HI_CURTOL_HI_FBUFPT_HI_POLYPT_HI_STRNG2_HI = $72
ZPBASIC_CHRGET                        = $73
ZPBASIC_CHRGOT                        = $79
ZPBASIC_TXTPTR                        = $7A
ZPBASIC_QNUM                          = $80
ZPBASIC_CHRRTS                        = $8A
ZPBASIC_RNDX                          = $8B

BVECTORS_IERROR    = $0300                  ; indirect error (output error in .x)
BVECTORS_IERROR_LO = BVECTORS_IERROR + 0
BVECTORS_IERROR_HI = BVECTORS_IERROR + 1
BVECTORS_IMAIN     = $0302                  ; indirect main (system direct loop)
BVECTORS_IMAIN_LO  = BVECTORS_IMAIN + 0
BVECTORS_IMAIN_HI  = BVECTORS_IMAIN + 1
BVECTORS_ICRNCH    = $0304                  ; indirect crunch (tokenization routine)
BVECTORS_ICRNCH_LO = BVECTORS_ICRNCH + 0
BVECTORS_ICRNCH_HI = BVECTORS_ICRNCH + 1
BVECTORS_IQPLOP    = $0306                  ; indirect list (char list)
BVECTORS_IQPLOP_LO = BVECTORS_IQPLOP + 0
BVECTORS_IQPLOP_HI = BVECTORS_IQPLOP + 1
BVECTORS_IGONE     = $0308                  ; indirect gone (char dispatch)
BVECTORS_IGONE_LO  = BVECTORS_IGONE + 0
BVECTORS_IGONE_HI  = BVECTORS_IGONE + 1
BVECTORS_IEVAL     = $030A                  ; indirect eval (symbol evaluation)
BVECTORS_IEVAL_LO  = BVECTORS_IEVAL + 0
BVECTORS_IEVAL_HI  = BVECTORS_IEVAL + 1
BVECTORS_SAREG     = $030C                  ; temp storage a reg
BVECTORS_SXREG     = $030D                  ; temp storage x reg
BVECTORS_SYREG     = $030E                  ; temp storage y reg
BVECTORS_SPREG     = $030F                  ; temp storage p reg
BVECTORS_USRPOK    = $0310                  ; user function dispatch
BVECTORS_USRPOK_0  = BVECTORS_USRPOK + 0
BVECTORS_USRPOK_1  = BVECTORS_USRPOK + 1
BVECTORS_USRPOK_2  = BVECTORS_USRPOK + 2
