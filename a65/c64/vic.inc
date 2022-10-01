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

;;; summary: VIC (VIC-II 6569 PAL)

VIC_R00   = VIC + $00
VIC_R01   = VIC + $01
VIC_R02   = VIC + $02
VIC_R03   = VIC + $03
VIC_R04   = VIC + $04
VIC_R05   = VIC + $05
VIC_R06   = VIC + $06
VIC_R07   = VIC + $07
VIC_R08   = VIC + $08
VIC_R09   = VIC + $09
VIC_R0A   = VIC + $0A
VIC_R0B   = VIC + $0B
VIC_R0C   = VIC + $0C
VIC_R0D   = VIC + $0D
VIC_R0E   = VIC + $0E
VIC_R0F   = VIC + $0F
VIC_R10   = VIC + $10
VIC_R11   = VIC + $11
VIC_R12   = VIC + $12
VIC_R13   = VIC + $13
VIC_R14   = VIC + $14
VIC_R15   = VIC + $15
VIC_R16   = VIC + $16
VIC_R17   = VIC + $17
VIC_R18   = VIC + $18
VIC_R19   = VIC + $19
VIC_R1A   = VIC + $1A
VIC_R1B   = VIC + $1B
VIC_R1C   = VIC + $1C
VIC_R1D   = VIC + $1D
VIC_R1E   = VIC + $1E
VIC_R1F   = VIC + $1F
VIC_R20   = VIC + $20
VIC_R21   = VIC + $21
VIC_R22   = VIC + $22
VIC_R23   = VIC + $23
VIC_R24   = VIC + $24
VIC_R25   = VIC + $25
VIC_R26   = VIC + $26
VIC_R27   = VIC + $27
VIC_R28   = VIC + $28
VIC_R29   = VIC + $29
VIC_R2A   = VIC + $2A
VIC_R2B   = VIC + $2B
VIC_R2C   = VIC + $2C
VIC_R2D   = VIC + $2D
VIC_R2E   = VIC + $2E
VIC_FIRST = VIC_R00
VIC_LAST  = VIC_R2E

; A synonym for sprite is MOB, hence the letter M is used for sprites.

VIC_M0X       = VIC_R00 ; X Coordinate Sprite 0
VIC_M0Y       = VIC_R01 ; Y Coordinate Sprite 0
VIC_M1X       = VIC_R02 ; X Coordinate Sprite 1
VIC_M1Y       = VIC_R03 ; Y Coordinate Sprite 1
VIC_M2X       = VIC_R04 ; X Coordinate Sprite 2
VIC_M2Y       = VIC_R05 ; Y Coordinate Sprite 2
VIC_M3X       = VIC_R06 ; X Coordinate Sprite 3
VIC_M3Y       = VIC_R07 ; Y Coordinate Sprite 3
VIC_M4X       = VIC_R08 ; X Coordinate Sprite 4
VIC_M4Y       = VIC_R09 ; Y Coordinate Sprite 4
VIC_M5X       = VIC_R0A ; X Coordinate Sprite 5
VIC_M5Y       = VIC_R0B ; Y Coordinate Sprite 5
VIC_M6X       = VIC_R0C ; X Coordinate Sprite 6
VIC_M6Y       = VIC_R0D ; Y Coordinate Sprite 6
VIC_M7X       = VIC_R0E ; X Coordinate Sprite 7
VIC_M7Y       = VIC_R0F ; Y Coordinate Sprite 7
VIC_M07X8     = VIC_R10 ; MSBs of X coordinates
VIC_CONTROL_1 = VIC_R11 ; Control register 1: 7:RST8 6:ECM 5:BMM 4:DEN 3:RSEL 2-0:YSCROLL
VIC_RST       = VIC_R12 ; Raster counter
VIC_LPX       = VIC_R13 ; Light Pen X
VIC_LPY       = VIC_R14 ; Light Pen Y
VIC_M07E      = VIC_R15 ; Sprite enabled
VIC_CONTROL_2 = VIC_R16 ; Control register 2: 7:- 6:- 5:RES 4:MCM 3:CSEL 2-0:XSCROLL
VIC_M07YE     = VIC_R17 ; Sprite Y expansion
VIC_MP        = VIC_R18 ; Memory pointers: 7:VM13 6:VM12 5:VM11 4:VM10 3:CB13 2:CB12 1:CB11 0:-
VIC_IR        = VIC_R19 ; Interrupt register
VIC_IE        = VIC_R1A ; Interrupt enabled
VIC_M07DB     = VIC_R1B ; Sprite data priority
VIC_M07MC     = VIC_R1C ; Sprite multicolor
VIC_M07XE     = VIC_R1D ; Sprite X expansion
VIC_M07M      = VIC_R1E ; Sprite-sprite collision
VIC_M07D      = VIC_R1F ; Sprite-data collision
VIC_EC        = VIC_R20 ; Border color
VIC_B0C       = VIC_R21 ; Background color 0
VIC_B1C       = VIC_R22 ; Background color 1
VIC_B2C       = VIC_R23 ; Background color 2
VIC_B3C       = VIC_R24 ; Background color 3
VIC_MM0       = VIC_R25 ; Sprite multicolor 0
VIC_MM1       = VIC_R26 ; Sprite multicolor 1
VIC_M0C       = VIC_R27 ; Color sprite 0
VIC_M1C       = VIC_R28 ; Color sprite 1
VIC_M2C       = VIC_R29 ; Color sprite 2
VIC_M3C       = VIC_R2A ; Color sprite 3
VIC_M4C       = VIC_R2B ; Color sprite 4
VIC_M5C       = VIC_R2C ; Color sprite 5
VIC_M6C       = VIC_R2D ; Color sprite 6
VIC_M7C       = VIC_R2E ; Color sprite 7

; VIC_CONTROL_1:
; +------+-----+-----+-----+------+---------+
; |  7   |  6  |  5  |  4  |  3   |   2-0   |
; +------+-----+-----+-----+------+---------+
; | RST8 | ECM | BMM | DEN | RSEL | YSCROLL |
; +------+-----+-----+-----+------+---------+
; RST8: Raster bit 8
VIC_CONTROL_1_RST8_BIT     = 7
VIC_CONTROL_1_RST8_CLR     = %01111111
VIC_CONTROL_1_RST8_SET     = %10000000
; ECM: Enable extended color text mode
VIC_CONTROL_1_ECM_BIT      = 6
VIC_CONTROL_1_ECM_CLR      = %10111111
VIC_CONTROL_1_ECM_SET      = %01000000
; BMM: Enable bitmap mode
VIC_CONTROL_1_BMM_BIT      = 5
VIC_CONTROL_1_BMM_CLR      = %11011111
VIC_CONTROL_1_BMM_SET      = %00100000
VIC_CONTROL_1_BMM_SET_ON   = %00100000
VIC_CONTROL_1_BMM_SET_OFF  = %00000000
; DEN: Blank screen
VIC_CONTROL_1_DEN_BIT      = 4
VIC_CONTROL_1_DEN_CLR      = %11101111
VIC_CONTROL_1_DEN_SET      = %00010000
VIC_CONTROL_1_DEN_SET_SHOW = %00010000
VIC_CONTROL_1_DEN_SET_HIDE = %00000000
; RSEL: Row SELect (number oftext mode rows) 0=24 , 1 = 25
VIC_CONTROL_1_RSEL_BIT     = 3
VIC_CONTROL_1_RSEL_CLR     = %11110111
VIC_CONTROL_1_RSEL_SET     = %00001000
VIC_CONTROL_1_RSEL_24      = %00000000
VIC_CONTROL_1_RSEL_25      = %00001000
; YSCROLL: vertical scroll
VIC_CONTROL_1_YSCROLL_SET  = %00000111
VIC_CONTROL_1_YSCROLL_CLR  = %11111000

; VIC_CONTROL_2:
; +---+---+-----+-----+------+---------+
; | 7 | 6 |  5  |  4  |  3   |   2-0   |
; +---+---+-----+-----+------+---------+
; | 1 | 1 | RES | MCM | CSEL | XSCROLL |
; +---+---+-----+-----+------+---------+
; RES: Reset VIC (write 1 to reset)
VIC_CONTROL_2_RES_BIT      = 5
VIC_CONTROL_2_RES_CLR      = %11011111
VIC_CONTROL_2_RES_SET      = %00100000
; MCM: Enable multicolor mode
VIC_CONTROL_2_MCM_BIT      = 4
VIC_CONTROL_2_MCM_CLR      = %11101111
VIC_CONTROL_2_MCM_SET_ON   = %00010000
VIC_CONTROL_2_MCM_SET_OFF  = %00000000
; CSEL: Column SELect (text mode number of columns) 0 = 38 , 1 = 40
VIC_CONTROL_2_CSEL_BIT     = 3
VIC_CONTROL_2_CSEL_CLR     = %11110111
VIC_CONTROL_2_CSEL_SET     = %00001000
VIC_CONTROL_2_CSEL_SET_38  = %00000000
VIC_CONTROL_2_CSEL_SET_40  = %00001000
; XSCROLL: Horizonal scroll
VIC_CONTROL_2_XSCROLL_CLR  = %11111000
VIC_CONTROL_2_XSCROLL_SET  = %00000111

; VIC_MP:
VIC_MP_VM_SET = %11110000
VIC_MP_VM_CLR = %00001111
VIC_MP_CB_SET = %00001110
VIC_MP_CB_CLR = %11110001

; RST: RaSTer interrupt
VIC_IR_RST_BIT = 0
VIC_IR_RST_SET = %00000001
VIC_IR_RST_CLR = %11111110
; Sprite - Data Collision
VIC_IR_MDC_BIT = 1
VIC_IR_MDC_SET = %00000010
VIC_IR_MDC_CLR = %11111101
; Sprite - Sprite Collision
VIC_IR_MMC_BIT = 2
VIC_IR_MMC_SET = %00000100
VIC_IR_MMC_CLR = %11111011
; Light Pen
VIC_IR_LP_BIT  = 3
VIC_IR_LP_SET  = %00001000
VIC_IR_LP_CLR  = %11110111
; Interrupt
VIC_IR_IRQ_BIT = 7
VIC_IR_IRQ_SET = %10000000
VIC_IR_IRQ_CLR = %01111111

; RST: RaSTer interrupt
VIC_IE_RST_BIT = 0
VIC_IE_RST_SET = %00000001
VIC_IE_RST_CLR = %11111110
; Sprite - Data Collision
VIC_IE_MDC_BIT = 1
VIC_IE_MDC_SET = %00000010
VIC_IE_MDC_CLR = %11111101
; Sprite - Sprite Collision
VIC_IE_MMC_BIT = 2
VIC_IE_MMC_SET = %00000100
VIC_IE_MMC_CLR = %11111011
; Light Pen
VIC_IE_LP_BIT  = 3
VIC_IE_LP_SET  = %00001000
VIC_IE_LP_CLR  = %11110111

VIC_BANK_SIZE         = $4000
VIC_BANK_0            = $0000
VIC_BANK_1            = $4000
VIC_BANK_2            = $8000
VIC_BANK_3            = $C000
; See also cia-2.inc:CIA_2_PRA_SELECT_VIC_BANK_*

VIC_DEFAULT_BANK      = 0
VIC_SCREEN_SIZE       = $0400
VIC_SPRITE_COUNT      = 8
VIC_VM_SIZE           = $0400
VIC_DEFAULT_SCREEN_VM = 1

VIC_CHAR_X_PIXELS = 8
VIC_CHAR_Y_PIXELS = 8

VIC_SPRITE_BLOCK_SIZE_BITS = 6
VIC_SPRITE_BLOCK_SIZE      = 1 << VIC_SPRITE_BLOCK_SIZE_BITS

VIC_SPRITE_0_MASK_SET = %00000001
VIC_SPRITE_0_MASK_CLR = %11111110
VIC_SPRITE_1_MASK_SET = %00000010
VIC_SPRITE_1_MASK_CLR = %11111101
VIC_SPRITE_2_MASK_SET = %00000100
VIC_SPRITE_2_MASK_CLR = %11111011
VIC_SPRITE_3_MASK_SET = %00001000
VIC_SPRITE_3_MASK_CLR = %11110111
VIC_SPRITE_4_MASK_SET = %00010000
VIC_SPRITE_4_MASK_CLR = %11101111
VIC_SPRITE_5_MASK_SET = %00100000
VIC_SPRITE_5_MASK_CLR = %11011111
VIC_SPRITE_6_MASK_SET = %01000000
VIC_SPRITE_6_MASK_CLR = %10111111
VIC_SPRITE_7_MASK_CLR = %10000000
VIC_SPRITE_7_MASK_SET = %01111111

; The screen is actually larger, but we cannot use that.

VIC_SCREEN_FIRST_X = 0
VIC_SCREEN_FIRST_Y = 0

VIC_SCREEN_LAST_X = 343
VIC_SCREEN_LAST_Y = 255

VIC_SCREEN_SIZE_X = VIC_SCREEN_LAST_X - VIC_SCREEN_FIRST_X + 1
VIC_SCREEN_SIZE_Y = VIC_SCREEN_LAST_Y - VIC_SCREEN_FIRST_Y + 1

VIC_VISIBLE_SCREEN_OFFSET_X = 24
VIC_VISIBLE_SCREEN_OFFSET_Y = 50

VIC_VISIBLE_SCREEN_FIRST_X = 0
VIC_VISIBLE_SCREEN_FIRST_Y = 0

VIC_VISIBLE_SCREEN_LAST_X = 319
VIC_VISIBLE_SCREEN_LAST_Y = 199

VIC_VISIBLE_SCREEN_SIZE_X = VIC_VISIBLE_SCREEN_LAST_X - VIC_VISIBLE_SCREEN_FIRST_X + 1
VIC_VISIBLE_SCREEN_SIZE_Y = VIC_VISIBLE_SCREEN_LAST_Y - VIC_VISIBLE_SCREEN_FIRST_Y + 1

VIC_VISIBLE_SCREEN_CENTER_X = VIC_VISIBLE_SCREEN_SIZE_X / 2
VIC_VISIBLE_SCREEN_CENTER_Y = VIC_VISIBLE_SCREEN_SIZE_Y / 2

LEFT_BORDER_FIRST_X   = VIC_SCREEN_FIRST_X
LEFT_BORDER_LAST_X    = VIC_SCREEN_FIRST_X + VIC_VISIBLE_SCREEN_OFFSET_X - 1
LEFT_BORDER_SIZE_X    = LEFT_BORDER_LAST_X - LEFT_BORDER_FIRST_X + 1

RIGHT_BORDER_FIRST_X  = VIC_SCREEN_FIRST_X + VIC_VISIBLE_SCREEN_OFFSET_X + VIC_VISIBLE_SCREEN_SIZE_X
RIGHT_BORDER_LAST_X   = VIC_VISIBLE_SCREEN_LAST_X
RIGHT_BORDER_SIZE_X   = RIGHT_BORDER_LAST_X - RIGHT_BORDER_FIRST_X + 1

TOP_BORDER_FIRST_Y    = VIC_SCREEN_FIRST_Y
TOP_BORDER_LAST_Y     = VIC_VISIBLE_SCREEN_OFFSET_Y - 1
TOP_BORDER_SIZE_Y     = TOP_BORDER_LAST_Y - TOP_BORDER_FIRST_Y + 1

BOTTOM_BORDER_FIRST_Y = VIC_SCREEN_FIRST_Y + VIC_VISIBLE_SCREEN_OFFSET_Y + VIC_VISIBLE_SCREEN_SIZE_Y
BOTTOM_BORDER_LAST_Y  = VIC_SCREEN_LAST_Y
BOTTOM_BORDER_SIZE_Y  = BOTTOM_BORDER_LAST_Y - BOTTOM_BORDER_FIRST_Y + 1

VIC_VISIBLE_SCREEN_FIRST_SCREEN_X = VIC_VISIBLE_SCREEN_OFFSET_X - VIC_SCREEN_FIRST_X
VIC_VISIBLE_SCREEN_FIRST_SCREEN_Y = VIC_VISIBLE_SCREEN_OFFSET_Y - VIC_SCREEN_FIRST_Y

VIC_VISIBLE_SCREEN_LAST_SCREEN_X = VIC_VISIBLE_SCREEN_FIRST_SCREEN_X + VIC_VISIBLE_SCREEN_SIZE_X - 1
VIC_VISIBLE_SCREEN_LAST_SCREEN_Y = VIC_VISIBLE_SCREEN_FIRST_SCREEN_Y + VIC_VISIBLE_SCREEN_SIZE_Y - 1

VIC_VISIBLE_SCREEN_CENTER_SCREEN_X = VIC_VISIBLE_SCREEN_FIRST_X + VIC_VISIBLE_SCREEN_CENTER_X
VIC_VISIBLE_SCREEN_CENTER_SCREEN_Y = VIC_VISIBLE_SCREEN_FIRST_Y + VIC_VISIBLE_SCREEN_CENTER_Y

; Sprite X & Y follow the SCREEN X & Y

VIC_CHAR_WIDTH  = 8
VIC_CHAR_HEIGHT = 8

VIC_CHAR_COLUMNS = < (VIC_VISIBLE_SCREEN_SIZE_X / VIC_CHAR_WIDTH)    ; 40
VIC_CHAR_LINES   = < (VIC_VISIBLE_SCREEN_SIZE_Y / VIC_CHAR_HEIGHT)  ; 25
