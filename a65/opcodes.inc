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
; ID  ImplieD
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

OPCODE_BIT_ZP = $24
OPCODE_BIT_AB = $2C

;;; summary: Jams (hangs/kills) the CPU.
;;; notes: These opcodes also kill: $12 $22 $32 $42 $52 $62 $72 $92 $B2 $D2 $F2
;;; see: https://www.pagetable.com/c64ref/6502/
OPCODE_JAM    = $02
OPCODE_JMP_AB = $4C
OPCODE_JMP_AI = $6C
OPCODE_JSR_AB = $20
OPCODE_BRK    = $00
OPCODE_NOP    = $EA
