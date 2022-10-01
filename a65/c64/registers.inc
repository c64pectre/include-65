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

;;; summary: Registers
;;; notes:
;;;   You may assume that registers AX - DX are in consecutive memory.

REGISTERS_BASE  = ZP_1_FIRST + 0
REGISTERS_COUNT = 8

; Register AX
AX    = REGISTERS_BASE + 0
AX_LO = AX + 0
AX_HI = AX + 1
AL    = AX_LO
AH    = AX_HI

; Register BX
BX    = REGISTERS_BASE + 2
BX_LO = BX + 0
BX_HI = BX + 1
BL    = BX_LO
BH    = BX_HI

; Register CX
CX    = REGISTERS_BASE + 4
CX_LO = CX + 0
CX_HI = CX + 1
CL    = CX_LO
CH    = CX_HI

; Register DX
DX    = REGISTERS_BASE + 6
DX_LO = DX + 0
DX_HI = DX + 1
DL    = DX_LO
DH    = DX_HI

;;; summary: total size of the 4 registers in bytes
REGISTERS_SIZEOF = 8
