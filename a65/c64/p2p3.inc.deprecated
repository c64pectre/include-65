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

;;; summary: P2P3 - Page 2 and 3 memory usable without disturbing Kernal and
;;;   Basic.
;;; notes:
;;;   1. $0293 .. $0296   4 MEMORY_1_FIRST [0..2]SYS_00_IMPL_BRK_HANDLER
;;;   2. $0298 .. $02A0   9 MEMORY_2_FIRST
;;;   3. $02A6 .. $02FF  90 MEMORY_3_FIRST SYS_00_LOAD_MOD_TABLE
;;;   4. $0313 .. $0313   1 MEMORY_4_FIRST
;;;   5. $0334 .. $03FF 204 MEMORY_5_FIRST SYS_00_HEAP_TABLE
;;;   6. $07E8 .. $07FF  24 MEMORY_6_FIRST  Used by SYS_00_GLOBAL_IRQ_HANDLER_TABLE
;;;      Total          332

MEMORY_1_FIRST = $0293
MEMORY_1_LAST  = $0296
MEMORY_1_SIZE  = MEMORY_1_LAST - MEMORY_1_FIRST + 1

MEMORY_2_FIRST = $0298
MEMORY_2_LAST  = $02A0
MEMORY_2_SIZE  = MEMORY_2_LAST - MEMORY_2_FIRST + 1

MEMORY_3_FIRST = $02A6
MEMORY_3_LAST  = $02FF
MEMORY_3_SIZE  = MEMORY_3_LAST - MEMORY_3_FIRST + 1

MEMORY_4_FIRST = $0313
MEMORY_4_LAST  = $0313
MEMORY_4_SIZE  = MEMORY_4_LAST - MEMORY_4_FIRST + 1

MEMORY_5_FIRST = $0334
MEMORY_5_LAST  = $03FF
MEMORY_5_SIZE  = MEMORY_5_LAST - MEMORY_5_FIRST + 1

MEMORY_6_FIRST = $07E8
MEMORY_6_LAST  = $07FF
MEMORY_6_SIZE  = MEMORY_6_LAST - MEMORY_6_FIRST + 1
