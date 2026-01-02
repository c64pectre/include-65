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

.exportzp ZEROPAGE_BASE               := $00

.export STACK_BASE                    := $0100
.export KERNAL_BASIC_RAM_BASE         := $0200
.export SCREEN_TEXT_RAM_BASE          := $0400
.export BASIC_RAM_BASE                := $0800
.export VIC_CHARACTER_ROM_BASE        := $1000              ; Offset within VIC bank
.export VIC_CHARACTER_ROM_BANK_0_BASE := $1000
.export VIC_CHARACTER_ROM_BANK_3_BASE := $9000
.export BASIC_ROM_BASE                := $A000
.export UPPER_RAM_BASE                := $C000
.export IO_AREA_BASE                  := $D000
.export CHARACTER_ROM_BASE            := $D000
.export VIC_BASE                      := $D000
.export SID_BASE                      := $D400
.export SCREEN_COLOR_RAM_BASE         := $D800
.export CIA_1_BASE                    := $DC00
.export CIA_2_BASE                    := $DD00
.export IO_AREA_1_BASE                := $DE00
.export IO_AREA_2_BASE                := $DF00
.export KERNAL_ROM_BASE               := $E000
