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

ZEROPAGE                            = $0000
PAGE_ZEROPAGE                       = $00
STACK                               = $0100
PAGE_STACK                          = $01
KERNAL_BASIC_RAM                    = $0200
PAGE_KERNAL_BASIC_RAM_FIRST         = $02
PAGE_KERNAL_BASIC_RAM_LAST          = $03
PAGE_KERNAL_BASIC_RAM_SIZE          = PAGE_KERNAL_BASIC_RAM_LAST - PAGE_KERNAL_BASIC_RAM_FIRST + 1
SCREEN_TEXT_RAM                     = $0400
PAGE_SCREEN_TEXT_RAM_FIRST          = $04
PAGE_SCREEN_TEXT_RAM_LAST           = $07
PAGE_SCREEN_TEXT_RAM_SIZE           = PAGE_SCREEN_TEXT_RAM_LAST - PAGE_SCREEN_TEXT_RAM_FIRST + 1
BASIC_RAM                           = $0800
PAGE_BASIC_RAM_FIRST                = $08
PAGE_BASIC_RAM_LAST                 = $9F
PAGE_BASIC_RAM_SIZE                 = PAGE_BASIC_RAM_LAST - PAGE_BASIC_RAM_FIRST + 1
VIC_CHARACTER_ROM_BANK_0            = $1000
PAGE_VIC_CHARACTER_ROM_BANK_0_FIRST = $10
PAGE_VIC_CHARACTER_ROM_BANK_0_LAST  = $1F
PAGE_VIC_CHARACTER_ROM_BANK_0_SIZE  = PAGE_VIC_CHARACTER_ROM_BANK_0_LAST - PAGE_VIC_CHARACTER_ROM_BANK_0_FIRST + 1
VIC_CHARACTER_ROM_BANK_1            = $9000
PAGE_VIC_CHARACTER_ROM_BANK_1_FIRST = $90
PAGE_VIC_CHARACTER_ROM_BANK_1_LAST  = $9F
PAGE_VIC_CHARACTER_ROM_BANK_1_SIZE  = PAGE_VIC_CHARACTER_ROM_BANK_1_LAST - PAGE_VIC_CHARACTER_ROM_BANK_1_FIRST + 1
BASIC_ROM                           = $A000
PAGE_BASIC_ROM_FIRST                = $A0
PAGE_BASIC_ROM_LAST                 = $BF
PAGE_BASIC_ROM_SIZE                 = PAGE_BASIC_ROM_LAST - PAGE_BASIC_ROM_FIRST + 1
UPPER_RAM                           = $C000
PAGE_UPPER_RAM_FIRST                = $C0
PAGE_UPPER_RAM_LAST                 = $CF
PAGE_UPPER_RAM_SIZE                 = PAGE_UPPER_RAM_LAST - PAGE_UPPER_RAM_FIRST + 1
IO                                  = $D000
PAGE_IO_FIRST                       = $D0
PAGE_IO_LAST                        = $DF
PAGE_IO_SIZE                        = PAGE_IO_LAST - PAGE_IO_FIRST + 1
CHARACTER_ROM                       = $D000
PAGE_CHARACTER_ROM_FIRST            = $D0
PAGE_CHARACTER_ROM_LAST             = $DF
PAGE_CHARACTER_ROM_SIZE             = PAGE_CHARACTER_ROM_LAST - PAGE_CHARACTER_ROM_FIRST + 1
VIC                                 = $D000
PAGE_VIC_FIRST                      = $D0
PAGE_VIC_LAST                       = $D3
PAGE_VIC_SIZE                       = PAGE_VIC_LAST - PAGE_VIC_FIRST + 1
SID                                 = $D400
PAGE_SID_FIRST                      = $D4
PAGE_SID_LAST                       = $D7
PAGE_SID_SIZE                       = PAGE_SID_LAST - PAGE_SID_FIRST + 1
PAGE_SCREEN_COLOR_RAM_FIRST         = $D8
PAGE_SCREEN_COLOR_RAM_LAST          = $DB
PAGE_SCREEN_COLOR_RAM_SIZE          = PAGE_SCREEN_COLOR_RAM_LAST - PAGE_SCREEN_COLOR_RAM_FIRST + 1
SCREEN_COLOR_RAM                    = $D800
CIA_1                               = $DC00
PAGE_CIA_1                          = $DC
PAGE_CIA_1_FIRST                    = PAGE_CIA_1
PAGE_CIA_1_LAST                     = PAGE_CIA_1
PAGE_CIA_1_SIZE                     = PAGE_CIA_1_LAST - PAGE_CIA_1_FIRST + 1
CIA_2                               = $DD00
PAGE_CIA_2                          = $DD
PAGE_CIA_2_FIRST                    = PAGE_CIA_2
PAGE_CIA_2_LAST                     = PAGE_CIA_2
PAGE_CIA_2_SIZE                     = PAGE_CIA_2_LAST - PAGE_CIA_2_FIRST + 1
IO_AREA_1                           = $DE00
PAGE_IO_AREA_1                      = $DE
PAGE_IO_AREA_1_FIRST                = PAGE_IO_AREA_1
PAGE_IO_AREA_1_LAST                 = PAGE_IO_AREA_1
PAGE_IO_AREA_1_SIZE                 = PAGE_IO_AREA_1_LAST - PAGE_IO_AREA_1_FIRST + 1
IO_AREA_2                           = $DF00
PAGE_IO_AREA_2                      = $DF
PAGE_IO_AREA_2_FIRST                = PAGE_IO_AREA_2
PAGE_IO_AREA_2_LAST                 = PAGE_IO_AREA_2
PAGE_IO_AREA_2_SIZE                 = PAGE_IO_AREA_2_LAST - PAGE_IO_AREA_2_FIRST + 1
KERNAL_ROM                          = $E000
PAGE_KERNAL_ROM_FIRST               = $E0
PAGE_KERNAL_ROM_LAST                = $FF
PAGE_KERNAL_ROM_SIZE                = PAGE_KERNAL_ROM_LAST - PAGE_KERNAL_ROM_FIRST + 1

; Execution address of interrupt service routine. Default $EA31
KERNAL_VECTOR_IRQ    = $0314
KERNAL_VECTOR_IRQ_LO = $0314
KERNAL_VECTOR_IRQ_HI = $0315

; Execution address of BRK service routine. Default $FE66
KERNAL_VECTOR_BRK    = $0316
KERNAL_VECTOR_BRK_LO = $0316
KERNAL_VECTOR_BRK_HI = $0317

; Execution address of non-maskable interrupt service routine. Default $FE47
KERNAL_VECTOR_NMI    = $0318
KERNAL_VECTOR_NMI_LO = $0318
KERNAL_VECTOR_NMI_HI = $0319

KERNAL_NMI   = $FFFA
KERNAL_IRQ   = $FFFE
KERNAL_RESET = $FFFC
