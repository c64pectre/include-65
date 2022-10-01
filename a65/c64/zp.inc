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

;;; summary: Zero Page
;;; notes:
;;;   Available zero page locations:
;;;   FROM- TO  SIZE  LABEL       USAGE
;;;   $02 - $09    8  ZP_1_FIRST  AX - DX
;;;   $0B - $12    8  ZP_2_FIRST
;;;   $14 - $2A   23  ZP_3_FIRST  FS
;;;   $3F - $48   10  ZP_4_FIRST
;;;   $4B - $72   40  ZP_5_FIRST  RS
;;;   $8B - $8F    5  ZP_6_FIRST
;;;   $92          1  ZP_7_FIRST  RSP
;;;   $96 - $97    2  ZP_8_FIRST  FSP FP
;;;   $9B - $9C    2  ZP_9_FIRST  MY_BRK_R0
;;;   $9E - $9F    2  ZP_A_FIRST
;;;   $A6 - $AB    6  ZP_B_FIRST
;;;   $B0 - $B6    7  ZP_C_FIRST
;;;   $BD - $C0    4  ZP_D_FIRST  
;;;   $F7 - $FF    9  ZP_E_FIRST
;;;   Total     127

ZP_1_FIRST = $02
ZP_1_LAST  = $09
ZP_1_SIZE  = ZP_1_LAST - ZP_1_FIRST + 1

ZP_2_FIRST = $0B
ZP_2_LAST  = $12
ZP_2_SIZE  = ZP_2_LAST - ZP_2_FIRST + 1

ZP_3_FIRST = $14
ZP_3_LAST  = $2A
ZP_3_SIZE  = ZP_3_LAST - ZP_3_FIRST + 1

ZP_4_FIRST = $3F
ZP_4_LAST  = $48
ZP_4_SIZE  = ZP_4_LAST - ZP_4_FIRST + 1

ZP_5_FIRST = $4B
ZP_5_LAST  = $72
ZP_5_SIZE  = ZP_5_LAST - ZP_5_FIRST + 1

ZP_6_FIRST = $8B
ZP_6_LAST  = $8F
ZP_6_SIZE  = ZP_6_LAST - ZP_6_FIRST + 1

ZP_7_FIRST = $92
ZP_7_LAST  = $92
ZP_7_SIZE  = ZP_7_LAST - ZP_7_FIRST + 1

ZP_8_FIRST = $96
ZP_8_LAST  = $97
ZP_8_SIZE  = ZP_8_LAST - ZP_8_FIRST + 1

ZP_9_FIRST = $9B
ZP_9_LAST  = $9C
ZP_9_SIZE  = ZP_9_LAST - ZP_9_FIRST + 1

ZP_A_FIRST = $9E
ZP_A_LAST  = $9F
ZP_A_SIZE  = ZP_A_LAST - ZP_A_FIRST + 1

ZP_B_FIRST = $A6
ZP_B_LAST  = $AB
ZP_B_SIZE  = ZP_B_LAST - ZP_B_FIRST + 1

ZP_C_FIRST = $B0
ZP_C_LAST  = $B6
ZP_C_SIZE  = ZP_C_LAST - ZP_C_FIRST + 1

ZP_D_FIRST = $BD
ZP_D_LAST  = $C0
ZP_D_SIZE  = ZP_D_LAST - ZP_D_FIRST + 1

ZP_E_FIRST = $F7
ZP_E_LAST  = $FF
ZP_E_SIZE  = ZP_E_LAST - ZP_E_FIRST + 1
