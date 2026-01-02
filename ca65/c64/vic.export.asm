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

.export VIC_REGISTER_BASE := $D000

.export VIC_R00   := VIC_REGISTER_BASE + $00
.export VIC_R01   := VIC_REGISTER_BASE + $01
.export VIC_R02   := VIC_REGISTER_BASE + $02
.export VIC_R03   := VIC_REGISTER_BASE + $03
.export VIC_R04   := VIC_REGISTER_BASE + $04
.export VIC_R05   := VIC_REGISTER_BASE + $05
.export VIC_R06   := VIC_REGISTER_BASE + $06
.export VIC_R07   := VIC_REGISTER_BASE + $07
.export VIC_R08   := VIC_REGISTER_BASE + $08
.export VIC_R09   := VIC_REGISTER_BASE + $09
.export VIC_R0A   := VIC_REGISTER_BASE + $0A
.export VIC_R0B   := VIC_REGISTER_BASE + $0B
.export VIC_R0C   := VIC_REGISTER_BASE + $0C
.export VIC_R0D   := VIC_REGISTER_BASE + $0D
.export VIC_R0E   := VIC_REGISTER_BASE + $0E
.export VIC_R0F   := VIC_REGISTER_BASE + $0F
.export VIC_R10   := VIC_REGISTER_BASE + $10
.export VIC_R11   := VIC_REGISTER_BASE + $11
.export VIC_R12   := VIC_REGISTER_BASE + $12
.export VIC_R13   := VIC_REGISTER_BASE + $13
.export VIC_R14   := VIC_REGISTER_BASE + $14
.export VIC_R15   := VIC_REGISTER_BASE + $15
.export VIC_R16   := VIC_REGISTER_BASE + $16
.export VIC_R17   := VIC_REGISTER_BASE + $17
.export VIC_R18   := VIC_REGISTER_BASE + $18
.export VIC_R19   := VIC_REGISTER_BASE + $19
.export VIC_R1A   := VIC_REGISTER_BASE + $1A
.export VIC_R1B   := VIC_REGISTER_BASE + $1B
.export VIC_R1C   := VIC_REGISTER_BASE + $1C
.export VIC_R1D   := VIC_REGISTER_BASE + $1D
.export VIC_R1E   := VIC_REGISTER_BASE + $1E
.export VIC_R1F   := VIC_REGISTER_BASE + $1F
.export VIC_R20   := VIC_REGISTER_BASE + $20
.export VIC_R21   := VIC_REGISTER_BASE + $21
.export VIC_R22   := VIC_REGISTER_BASE + $22
.export VIC_R23   := VIC_REGISTER_BASE + $23
.export VIC_R24   := VIC_REGISTER_BASE + $24
.export VIC_R25   := VIC_REGISTER_BASE + $25
.export VIC_R26   := VIC_REGISTER_BASE + $26
.export VIC_R27   := VIC_REGISTER_BASE + $27
.export VIC_R28   := VIC_REGISTER_BASE + $28
.export VIC_R29   := VIC_REGISTER_BASE + $29
.export VIC_R2A   := VIC_REGISTER_BASE + $2A
.export VIC_R2B   := VIC_REGISTER_BASE + $2B
.export VIC_R2C   := VIC_REGISTER_BASE + $2C
.export VIC_R2D   := VIC_REGISTER_BASE + $2D
.export VIC_R2E   := VIC_REGISTER_BASE + $2E

.export VIC_REGISTER_FIRST := VIC_R00
.export VIC_REGISTER_LAST  := VIC_R2E

; A synonym for sprite is MOB, hence the letter M is used for sprites.

.export VIC_M0X       := VIC_R00 ; X Coordinate Sprite 0
.export VIC_M0Y       := VIC_R01 ; Y Coordinate Sprite 0
.export VIC_M1X       := VIC_R02 ; X Coordinate Sprite 1
.export VIC_M1Y       := VIC_R03 ; Y Coordinate Sprite 1
.export VIC_M2X       := VIC_R04 ; X Coordinate Sprite 2
.export VIC_M2Y       := VIC_R05 ; Y Coordinate Sprite 2
.export VIC_M3X       := VIC_R06 ; X Coordinate Sprite 3
.export VIC_M3Y       := VIC_R07 ; Y Coordinate Sprite 3
.export VIC_M4X       := VIC_R08 ; X Coordinate Sprite 4
.export VIC_M4Y       := VIC_R09 ; Y Coordinate Sprite 4
.export VIC_M5X       := VIC_R0A ; X Coordinate Sprite 5
.export VIC_M5Y       := VIC_R0B ; Y Coordinate Sprite 5
.export VIC_M6X       := VIC_R0C ; X Coordinate Sprite 6
.export VIC_M6Y       := VIC_R0D ; Y Coordinate Sprite 6
.export VIC_M7X       := VIC_R0E ; X Coordinate Sprite 7
.export VIC_M7Y       := VIC_R0F ; Y Coordinate Sprite 7
.export VIC_M07X8     := VIC_R10 ; MSBs of X coordinates
.export VIC_CONTROL_1 := VIC_R11 ; Control register 1: 7:RST8 6:ECM 5:BMM 4:DEN 3:RSEL 2-0:YSCROLL
.export VIC_RST       := VIC_R12 ; Raster counter
.export VIC_LPX       := VIC_R13 ; Light Pen X
.export VIC_LPY       := VIC_R14 ; Light Pen Y
.export VIC_M07E      := VIC_R15 ; Sprite enabled
.export VIC_CONTROL_2 := VIC_R16 ; Control register 2: 7:- 6:- 5:RES 4:MCM 3:CSEL 2-0:XSCROLL
.export VIC_M07YE     := VIC_R17 ; Sprite Y expansion
.export VIC_MP        := VIC_R18 ; Memory pointers: 7:VM13 6:VM12 5:VM11 4:VM10 3:CB13 2:CB12 1:CB11 0:-
.export VIC_IR        := VIC_R19 ; Interrupt register
.export VIC_IE        := VIC_R1A ; Interrupt enabled
.export VIC_M07DB     := VIC_R1B ; Sprite data priority
.export VIC_M07MC     := VIC_R1C ; Sprite multicolor
.export VIC_M07XE     := VIC_R1D ; Sprite X expansion
.export VIC_M07M      := VIC_R1E ; Sprite-sprite collision
.export VIC_M07D      := VIC_R1F ; Sprite-data collision
.export VIC_EC        := VIC_R20 ; Border color
.export VIC_B0C       := VIC_R21 ; Background color 0
.export VIC_B1C       := VIC_R22 ; Background color 1
.export VIC_B2C       := VIC_R23 ; Background color 2
.export VIC_B3C       := VIC_R24 ; Background color 3
.export VIC_MM0       := VIC_R25 ; Sprite multicolor 0
.export VIC_MM1       := VIC_R26 ; Sprite multicolor 1
.export VIC_M0C       := VIC_R27 ; Color sprite 0
.export VIC_M1C       := VIC_R28 ; Color sprite 1
.export VIC_M2C       := VIC_R29 ; Color sprite 2
.export VIC_M3C       := VIC_R2A ; Color sprite 3
.export VIC_M4C       := VIC_R2B ; Color sprite 4
.export VIC_M5C       := VIC_R2C ; Color sprite 5
.export VIC_M6C       := VIC_R2D ; Color sprite 6
.export VIC_M7C       := VIC_R2E ; Color sprite 7

.export VIC_BANK_0_BASE : absolute := $0000
.export VIC_BANK_1_BASE := $4000
.export VIC_BANK_2_BASE := $8000
.export VIC_BANK_3_BASE := $C000
