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

.exportzp ZPBASIC_ADRAY1_LO                     := $03
.exportzp ZPBASIC_ADRAY1_HI                     := $04
.exportzp ZPBASIC_ADRAY2_LO                     := $05
.exportzp ZPBASIC_ADRAY2_HI                     := $06
.exportzp ZPBASIC_CHARAC_INTEGR                 := $07
.exportzp ZPBASIC_ENDCHR                        := $08
.exportzp ZPBASIC_TRMPOS                        := $09
.exportzp ZPBASIC_VERCK                         := $0A
.exportzp ZPBASIC_COUNT                         := $0B
.exportzp ZPBASIC_DIMFLG                        := $0C
.exportzp ZPBASIC_VALTYP                        := $0D
.exportzp ZPBASIC_INTFLG                        := $0E
.exportzp ZPBASIC_DORES_GARBFL                  := $0F
.exportzp ZPBASIC_SUBFLG                        := $10
.exportzp ZPBASIC_INPFLG                        := $11
.exportzp ZPBASIC_DOMASK_TANSGN                 := $12
.exportzp ZPBASIC_CHANNL                        := $13
.exportzp ZPBASIC_LINNUM_LO_POKER_LO            := $14
.exportzp ZPBASIC_LINNUM_HI_POKER_HI            := $15
.exportzp ZPBASIC_TEMPPT                        := $16
.exportzp ZPBASIC_LASTPT_LO                     := $17
.exportzp ZPBASIC_LASTPT_HI                     := $18
.exportzp ZPBASIC_TEMPST                        := $19 ; $19-$21
.exportzp ZPBASIC_INDEX_LO_INDEX1_LO            := $22
.exportzp ZPBASIC_INDEX_HI_INDEX1_HI            := $23
.exportzp ZPBASIC_INDEX2_LO                     := $24
.exportzp ZPBASIC_INDEX2_HI                     := $25
.exportzp ZPBASIC_RESHO                         := $26
.exportzp ZPBASIC_RESMOH                        := $27
.exportzp ZPBASIC_ADDEND_RESMO                  := $28
.exportzp ZPBASIC_RESLO                         := $29
.exportzp ZPBASIC_UNUSED_2A                     := $2A
.exportzp ZPBASIC_TXTTAB_LO                     := $2B
.exportzp ZPBASIC_TXTTAB_HI                     := $2C
.exportzp ZPBASIC_VARTAB_LO                     := $2D
.exportzp ZPBASIC_VARTAB_HI                     := $2E
.exportzp ZPBASIC_ARYTAB_LO                     := $2F
.exportzp ZPBASIC_ARYTAB_HI                     := $30
.exportzp ZPBASIC_STREND_LO                     := $31
.exportzp ZPBASIC_STREND_HI                     := $32
.exportzp ZPBASIC_FRETOP_LO                     := $33
.exportzp ZPBASIC_FRETOP_HI                     := $34
.exportzp ZPBASIC_FRESPC_LO                     := $35
.exportzp ZPBASIC_FRESPC_HI                     := $36
.exportzp ZPBASIC_MEMSIZ_LO                     := $37
.exportzp ZPBASIC_MEMSIZ_HI                     := $38
.exportzp ZPBASIC_CURLIN_LO                     := $39
.exportzp ZPBASIC_CURLIN_HI                     := $3A
.exportzp ZPBASIC_OLDLIN_LO                     := $3B
.exportzp ZPBASIC_OLDLIN_HI                     := $3C
.exportzp ZPBASIC_OLDTXT_LO                     := $3D
.exportzp ZPBASIC_OLDTXT_HI                     := $3E
.exportzp ZPBASIC_DATLIN_LO                     := $3F
.exportzp ZPBASIC_DATLIN_HI                     := $40
.exportzp ZPBASIC_DATPTR_LO                     := $41
.exportzp ZPBASIC_DATPTR_HI                     := $42
.exportzp ZPBASIC_INPPTR_LO                     := $43
.exportzp ZPBASIC_INPPTR_HI                     := $44
.exportzp ZPBASIC_VARNAM_LO                     := $45
.exportzp ZPBASIC_VARNAM_HI                     := $46
.exportzp ZPBASIC_FDECPT_LO_VARPNT_LO           := $47
.exportzp ZPBASIC_FDECPT_HI_VARPNT_HI           := $48
.exportzp ZPBASIC_ANDMSK_FORPNT_LO_LSTPNT_LO    := $49
.exportzp ZPBASIC_EORMSK_FORPNT_HI_LSTPNT_HI    := $4A
.exportzp ZPBASIC_OPPTR_LO_VARTXT_LO            := $4B
.exportzp ZPBASIC_OPPTR_HI_VARTXT_HI            := $4C
.exportzp ZPBASIC_OPMASK                        := $4D
.exportzp ZPBASIC_DEFPNT_LO_GRBPNT_LO_TEMPF3_LO := $4E
.exportzp ZPBASIC_DEFPNT_HI_GRBPNT_HI_TEMPF3_HI := $4F
.exportzp ZPBASIC_DSCPNT_LO                     := $50
.exportzp ZPBASIC_DSCPNT_HI                     := $51
.exportzp ZPBASIC_UNUSED_52                     := $52
.exportzp ZPBASIC_FOUR6                         := $53
.exportzp ZPBASIC_JMPER                         := $54
.exportzp ZPBASIC_SIZE                          := $55
.exportzp ZPBASIC_OLDOV                         := $56
.exportzp ZPBASIC_TEMPF1                        := $57
.exportzp ZPBASIC_ARYPNT_LO_HIGHDS_LO           := $58
.exportzp ZPBASIC_ARYPNT_HI_HIGHDS_HI           := $59
.exportzp ZPBASIC_HIGHTR_LO                     := $5A
.exportzp ZPBASIC_HIGHTR_HI                     := $5B
.exportzp ZPBASIC_TEMPF2                        := $5C
.exportzp ZPBASIC_DECCNT_LO_LOWDS_LO            := $5D
.exportzp ZPBASIC_DECCNT_HI_LOWDS_HI_TENEXP     := $5E
.exportzp ZPBASIC_DPTFLG_GRBTOP_LOWTR           := $5F
.exportzp ZPBASIC_EXPSGN_EPSGN                  := $60
.exportzp ZPBASIC_DSCTMP_FAC_FACEXP             := $61
.exportzp ZPBASIC_FACHO                         := $62
.exportzp ZPBASIC_FACMOH                        := $63
.exportzp ZPBASIC_FACMO_INDICE                  := $64
.exportzp ZPBASIC_FACLO                         := $65
.exportzp ZPBASIC_FACSGN                        := $66
.exportzp ZPBASIC_DEGREE_SGNFLG                 := $67
.exportzp ZPBASIC_BITS                          := $68
.exportzp ZPBASIC_ARGEXP                        := $69
.exportzp ZPBASIC_ARGHO                         := $6A
.exportzp ZPBASIC_ARGMOH                        := $6B
.exportzp ZPBASIC_ARGMO                         := $6C
.exportzp ZPBASIC_ARGLO                         := $6D
.exportzp ZPBASIC_ARGSGN                        := $6E
.exportzp ZPBASIC_ARISGN_STRNGI_STRNG1          := $6F
.exportzp ZPBASIC_FACOV                         := $70
.exportzp ZPBASIC_BUFPTR_LO_CURTOL_LO_FBUFPT_LO_POLYPT_LO_STRNG2_LO := $71
.exportzp ZPBASIC_BUFPTR_HI_CURTOL_HI_FBUFPT_HI_POLYPT_HI_STRNG2_HI := $72
.exportzp ZPBASIC_CHRGET                        := $73 ; $72-$8A
.exportzp ZPBASIC_CHRGOT                        := $79
.exportzp ZPBASIC_TXTPTR                        := $7A
.exportzp ZPBASIC_QNUM                          := $80
.exportzp ZPBASIC_CHRRTS                        := $8A
.exportzp ZPBASIC_RNDX                          := $8B ; $8B-$8F

.export BVECTORS_IERROR    := $0300
.export BVECTORS_IERROR_LO := BVECTORS_IERROR + 0
.export BVECTORS_IERROR_HI := BVECTORS_IERROR + 1
.export BVECTORS_IMAIN     := $0302
.export BVECTORS_IMAIN_LO  := BVECTORS_IMAIN + 0
.export BVECTORS_IMAIN_HI  := BVECTORS_IMAIN + 1
.export BVECTORS_ICRNCH    := $0304
.export BVECTORS_ICRNCH_LO := BVECTORS_ICRNCH + 0
.export BVECTORS_ICRNCH_HI := BVECTORS_ICRNCH + 1
.export BVECTORS_IQPLOP    := $0306
.export BVECTORS_IQPLOP_LO := BVECTORS_IQPLOP + 0
.export BVECTORS_IQPLOP_HI := BVECTORS_IQPLOP + 1
.export BVECTORS_IGONE     := $0308
.export BVECTORS_IGONE_LO  := BVECTORS_IGONE + 0
.export BVECTORS_IGONE_HI  := BVECTORS_IGONE + 1
.export BVECTORS_IEVAL     := $030A
.export BVECTORS_IEVAL_LO  := BVECTORS_IEVAL + 0
.export BVECTORS_IEVAL_HI  := BVECTORS_IEVAL + 1
.export BVECTORS_SAREG     := $030C
.export BVECTORS_SXREG     := $030D
.export BVECTORS_SYREG     := $030E
.export BVECTORS_SPREG     := $030F
.export BVECTORS_USRPOK    := $0310
.export BVECTORS_USRPOK_0  := BVECTORS_USRPOK + 0
.export BVECTORS_USRPOK_1  := BVECTORS_USRPOK + 1
.export BVECTORS_USRPOK_2  := BVECTORS_USRPOK + 2
