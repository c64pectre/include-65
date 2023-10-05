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

;;; summary: Opcodes for 6502, 6510 cpu

; Addressing modes:
;     ImplieD (no suffix)
; IT  ImmediaTe
; AB  ABsolute
; ZP  Zero Page
; RE  RElative
; AX  Absolute indexed with X
; AY  Absolute indexed with Y
; ZX  Zero page indexed with X
; ZY  Zero page indexed with Y
; XI  zero page Indirect indexed with X
; IY  zero page Indirect indexed with Y
; AI  Absolute Indirect

OPCODE_ADC_IT = $69
OPCODE_ADC_ZP = $65
OPCODE_ADC_ZX = $75
OPCODE_ADC_AB = $6D
OPCODE_ADC_AX = $7D
OPCODE_ADC_AY = $79
OPCODE_ADC_XI = $61
OPCODE_ADC_IY = $71
OPCODE_AND_IT = $29
OPCODE_AND_ZP = $25
OPCODE_AND_ZX = $35
OPCODE_AND_AB = $2D
OPCODE_AND_AX = $3D
OPCODE_AND_AY = $39
OPCODE_AND_XI = $21
OPCODE_AND_IY = $31
OPCODE_ASL    = $0A
OPCODE_ASL_ZP = $06
OPCODE_ASL_ZX = $16
OPCODE_ASL_AB = $0E
OPCODE_ASL_AX = $1E
OPCODE_BCC_RE = $90
OPCODE_BCS_RE = $B0
OPCODE_BEQ_RE = $F0
OPCODE_BIT_ZP = $24
OPCODE_BIT_AB = $2C
OPCODE_BMI_RE = $30
OPCODE_BNE_RE = $D0
OPCODE_BPL_RE = $10
OPCODE_BRK    = $00
OPCODE_BVC_RE = $50
OPCODE_BVS_RE = $70
OPCODE_CLC    = $18
OPCODE_CLD    = $D8
OPCODE_CLI    = $58
OPCODE_CLV    = $B8
OPCODE_CMP_IT = $C9
OPCODE_CMP_ZP = $C5
OPCODE_CMP_ZX = $D5
OPCODE_CMP_AB = $CD
OPCODE_CMP_AX = $DD
OPCODE_CMP_AY = $D9
OPCODE_CMP_XI = $C1
OPCODE_CMP_IY = $D1
OPCODE_CPX_IT = $E0
OPCODE_CPX_ZP = $E4
OPCODE_CPX_AB = $EC
OPCODE_CPY_IT = $C0
OPCODE_CPY_ZP = $C4
OPCODE_CPY_AB = $CC
OPCODE_DEC_ZP = $C6
OPCODE_DEC_ZX = $D6
OPCODE_DEC_AB = $CE
OPCODE_DEC_AX = $DE
OPCODE_DEX    = $CA
OPCODE_DEY    = $88
OPCODE_EOR_IT = $49
OPCODE_EOR_ZP = $45
OPCODE_EOR_ZX = $55
OPCODE_EOR_AB = $4D
OPCODE_EOR_AX = $5D
OPCODE_EOR_AY = $59
OPCODE_EOR_XI = $41
OPCODE_EOR_IY = $51
OPCODE_INC_ZP = $E6
OPCODE_INC_ZX = $F6
OPCODE_INC_AB = $EE
OPCODE_INC_AX = $FE
OPCODE_INX    = $E8
OPCODE_INY    = $C8
OPCODE_JMP_AB = $4C
OPCODE_JMP_AI = $6C
OPCODE_JSR_AB = $20
OPCODE_LDA_IT = $A9
OPCODE_LDA_ZP = $A5
OPCODE_LDA_ZX = $B5
OPCODE_LDA_AB = $AD
OPCODE_LDA_AX = $BD
OPCODE_LDA_AY = $B9
OPCODE_LDA_XI = $A1
OPCODE_LDA_IY = $B1
OPCODE_LDX_IT = $A2
OPCODE_LDX_ZP = $A6
OPCODE_LDX_ZY = $B6
OPCODE_LDX_AB = $AE
OPCODE_LDX_AY = $BE
OPCODE_LDY_IT = $A0
OPCODE_LDY_ZP = $A4
OPCODE_LDY_ZX = $B4
OPCODE_LDY_AB = $AC
OPCODE_LDY_AX = $BC
OPCODE_LSR    = $4A
OPCODE_LSR_ZP = $46
OPCODE_LSR_ZX = $56
OPCODE_LSR_AB = $4E
OPCODE_LSR_AX = $5E
OPCODE_NOP    = $EA
OPCODE_ORA_IT = $09
OPCODE_ORA_ZP = $05
OPCODE_ORA_ZX = $15
OPCODE_ORA_AB = $0D
OPCODE_ORA_AX = $1D
OPCODE_ORA_AY = $19
OPCODE_ORA_XI = $01
OPCODE_ORA_IY = $11
OPCODE_PHA    = $48
OPCODE_PHP    = $08
OPCODE_PLA    = $68
OPCODE_PLP    = $28
OPCODE_ROL    = $2A
OPCODE_ROL_ZP = $26
OPCODE_ROL_ZX = $36
OPCODE_ROL_AB = $2E
OPCODE_ROL_AX = $3E
OPCODE_ROR    = $6A
OPCODE_ROR_ZP = $66
OPCODE_ROR_ZX = $76
OPCODE_ROR_AB = $6E
OPCODE_ROR_AX = $7E
OPCODE_RTI    = $40
OPCODE_RTS    = $60
OPCODE_SBC_IT = $E9
OPCODE_SBC_ZP = $E5
OPCODE_SBC_ZX = $F5
OPCODE_SBC_AB = $ED
OPCODE_SBC_AX = $FD
OPCODE_SBC_AY = $F9
OPCODE_SBC_XI = $E1
OPCODE_SBC_IY = $F1
OPCODE_SEC    = $38
OPCODE_SED    = $F8
OPCODE_SEI    = $78
OPCODE_STA_ZP = $85
OPCODE_STA_ZX = $95
OPCODE_STA_AB = $8D
OPCODE_STA_AX = $9D
OPCODE_STA_AY = $99
OPCODE_STA_XI = $81
OPCODE_STA_IY = $91
OPCODE_STX_ZP = $86
OPCODE_STX_ZY = $96
OPCODE_STX_AB = $8E
OPCODE_STY_ZP = $84
OPCODE_STY_ZX = $94
OPCODE_STY_AB = $8C
OPCODE_TAX    = $AA
OPCODE_TAY    = $A8
OPCODE_TSX    = $BA
OPCODE_TXA    = $8A
OPCODE_TXS    = $9A
OPCODE_TYA    = $98

;;; summary: Jams (hangs/kills) the CPU (undocumented).
;;; notes: These opcodes also kill: $12 $22 $32 $42 $52 $62 $72 $92 $B2 $D2 $F2
;;; see: https://www.pagetable.com/c64ref/6502/
OPCODE_JAM    = $02
