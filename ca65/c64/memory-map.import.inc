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

.ifndef __C64_MEMORY_MAP_IMPORT_INC__
    __C64_MEMORY_MAP_IMPORT_INC__ = 1

.import ZEROPAGE_BASE
.import STACK_BASE
.import KERNAL_BASIC_RAM_BASE
.import SCREEN_TEXT_RAM_BASE
.import BASIC_RAM_BASE
.import VIC_CHARACTER_ROM_BANK_0_BASE
.import VIC_CHARACTER_ROM_BANK_1_BASE
.import BASIC_ROM_BASE
.import UPPER_RAM_BASE
.import IO_AREA_BASE
.import CHARACTER_ROM_BASE
.import VIC_BASE
.import SID_BASE
.import SCREEN_COLOR_RAM_BASE
.import CIA_1_BASE
.import CIA_2_BASE
.import IO_AREA_1_BASE
.import IO_AREA_2_BASE
.import KERNAL_ROM_BASE

.endif
