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

;;; summary: C64 memory map

ZEROPAGE_PAGE                       = $00
ZEROPAGE_PAGE_FIRST                 = $00
ZEROPAGE_PAGE_LAST                  = $00
ZEROPAGE_PAGE_COUNT                 = 1

STACK_PAGE                          = $01
STACK_PAGE_FIRST                    = $00
STACK_PAGE_LAST                     = $00
STACK_PAGE_COUNT                    = 1

KERNAL_BASIC_RAM_PAGE_FIRST         = $02
KERNAL_BASIC_RAM_PAGE_LAST          = $03
KERNAL_BASIC_RAM_PAGE_COUNT         = KERNAL_BASIC_RAM_PAGE_LAST - KERNAL_BASIC_RAM_PAGE_FIRST + 1

SCREEN_TEXT_RAM_PAGE_FIRST          = $04
SCREEN_TEXT_RAM_PAGE_LAST           = $07
SCREEN_TEXT_RAM_PAGE_COUNT          = SCREEN_TEXT_RAM_PAGE_LAST - SCREEN_TEXT_RAM_PAGE_FIRST + 1

BASIC_RAM_PAGE_FIRST                = $08
BASIC_RAM_PAGE_LAST                 = $9F
BASIC_RAM_PAGE_COUNT                = BASIC_RAM_PAGE_LAST - BASIC_RAM_PAGE_FIRST + 1

VIC_CHARACTER_ROM_BANK_0_PAGE_FIRST = $10
VIC_CHARACTER_ROM_BANK_0_PAGE_LAST  = $1F
VIC_CHARACTER_ROM_BANK_0_PAGE_COUNT = VIC_CHARACTER_ROM_BANK_0_PAGE_LAST - VIC_CHARACTER_ROM_BANK_0_PAGE_FIRST + 1

VIC_CHARACTER_ROM_BANK_1_PAGE_FIRST = $90
VIC_CHARACTER_ROM_BANK_1_PAGE_LAST  = $9F
VIC_CHARACTER_ROM_BANK_1_PAGE_COUNT = VIC_CHARACTER_ROM_BANK_1_PAGE_FIRST - VIC_CHARACTER_ROM_BANK_1_PAGE_LAST + 1

BASIC_ROM_PAGE_FIRST                = $A0
BASIC_ROM_PAGE_LAST                 = $BF
BASIC_ROM_PAGE_COUNT                = BASIC_ROM_PAGE_LAST - BASIC_ROM_PAGE_FIRST + 1

UPPER_RAM_PAGE_FIRST                = $C0
UPPER_RAM_PAGE_LAST                 = $CF
UPPER_RAM_PAGE_COUNT                = UPPER_RAM_PAGE_LAST - UPPER_RAM_PAGE_FIRST + 1

IO_AREA_PAGE_FIRST                  = $D0
IO_AREA_PAGE_LAST                   = $DF
IO_AREA_PAGE_COUNT                  = IO_AREA_PAGE_LAST - IO_AREA_PAGE_FIRST + 1

CHARACTER_ROM_PAGE_FIRST            = $D0
CHARACTER_ROM_PAGE_LAST             = $DF
CHARACTER_ROM_PAGE_COUNT            = CHARACTER_ROM_PAGE_LAST - CHARACTER_ROM_PAGE_FIRST + 1

VIC_PAGE_FIRST                      = $D0
VIC_PAGE_LAST                       = $D3
VIC_PAGE_COUNT                      = VIC_PAGE_LAST - VIC_PAGE_FIRST + 1

SID_PAGE_FIRST                      = $D4
SID_PAGE_LAST                       = $D7
SID_PAGE_COUNT                      = SID_PAGE_LAST - SID_PAGE_FIRST + 1

SCREEN_COLOR_RAM_PAGE_FIRST         = $D8
SCREEN_COLOR_RAM_PAGE_LAST          = $DB
SCREEN_COLOR_RAM_PAGE_COUNT         = SCREEN_COLOR_RAM_PAGE_LAST - SCREEN_COLOR_RAM_PAGE_FIRST + 1

CIA_1_PAGE                          = $DC
CIA_1_PAGE_FIRST                    = CIA_1_PAGE
CIA_1_PAGE_LAST                     = CIA_1_PAGE
CIA_1_PAGE_COUNT                    = 1

CIA_2_PAGE                          = $DD
CIA_2_PAGE_FIRST                    = CIA_2_PAGE
CIA_2_PAGE_LAST                     = CIA_2_PAGE
CIA_2_PAGE_COUNT                    = 1

IO_AREA_1_PAGE                      = $DE
IO_AREA_1_PAGE_FIRST                = IO_AREA_1_PAGE
IO_AREA_1_PAGE_LAST                 = IO_AREA_1_PAGE
IO_AREA_1_PAGE_COUNT                = 1

IO_AREA_2_PAGE                      = $DF
IO_AREA_2_PAGE_FIRST                = IO_AREA_2_PAGE
IO_AREA_2_PAGE_LAST                 = IO_AREA_2_PAGE
IO_AREA_2_PAGE_COUNT                = 1

KERNAL_ROM_PAGE_FIRST               = $E0
KERNAL_ROM_PAGE_LAST                = $FF
KERNAL_ROM_PAGE_COUNT               = KERNAL_ROM_PAGE_LAST - KERNAL_ROM_PAGE_FIRST + 1
