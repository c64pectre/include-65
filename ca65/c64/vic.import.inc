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

.ifndef __C64_VIC_IMPORT_INC__
    __C64_VIC_IMPORT_INC__ = 1

.import VIC_REGISTER_BASE

.import VIC_R00
.import VIC_R01
.import VIC_R02
.import VIC_R03
.import VIC_R04
.import VIC_R05
.import VIC_R06
.import VIC_R07
.import VIC_R08
.import VIC_R09
.import VIC_R0A
.import VIC_R0B
.import VIC_R0C
.import VIC_R0D
.import VIC_R0E
.import VIC_R0F
.import VIC_R10
.import VIC_R11
.import VIC_R12
.import VIC_R13
.import VIC_R14
.import VIC_R15
.import VIC_R16
.import VIC_R17
.import VIC_R18
.import VIC_R19
.import VIC_R1A
.import VIC_R1B
.import VIC_R1C
.import VIC_R1D
.import VIC_R1E
.import VIC_R1F
.import VIC_R20
.import VIC_R21
.import VIC_R22
.import VIC_R23
.import VIC_R24
.import VIC_R25
.import VIC_R26
.import VIC_R27
.import VIC_R28
.import VIC_R29
.import VIC_R2A
.import VIC_R2B
.import VIC_R2C
.import VIC_R2D
.import VIC_R2E

.import VIC_REGISTER_FIRST
.import VIC_REGISTER_LAST

; A synonym for sprite is MOB, hence the letter M is used for sprites.

.import VIC_M0X
.import VIC_M0Y
.import VIC_M1X
.import VIC_M1Y
.import VIC_M2X
.import VIC_M2Y
.import VIC_M3X
.import VIC_M3Y
.import VIC_M4X
.import VIC_M4Y
.import VIC_M5X
.import VIC_M5Y
.import VIC_M6X
.import VIC_M6Y
.import VIC_M7X
.import VIC_M7Y
.import VIC_M07X8
.import VIC_CONTROL_1
.import VIC_RST
.import VIC_LPX
.import VIC_LPY
.import VIC_M07E
.import VIC_CONTROL_2
.import VIC_M07YE
.import VIC_MP
.import VIC_IR
.import VIC_IE
.import VIC_M07DB
.import VIC_M07MC
.import VIC_M07XE
.import VIC_M07M
.import VIC_M07D
.import VIC_EC
.import VIC_B0C
.import VIC_B1C
.import VIC_B2C
.import VIC_B3C
.import VIC_MM0
.import VIC_MM1
.import VIC_M0C
.import VIC_M1C
.import VIC_M2C
.import VIC_M3C
.import VIC_M4C
.import VIC_M5C
.import VIC_M6C
.import VIC_M7C

.import VIC_BANK_0_BASE
.import VIC_BANK_1_BASE
.import VIC_BANK_2_BASE
.import VIC_BANK_3_BASE

.endif
