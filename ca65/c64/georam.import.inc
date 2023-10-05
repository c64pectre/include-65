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

.ifndef __C64_GEORAM_IMPORT_INC__
    __C64_GEORAM_IMPORT_INC__ = 1

;;; summary: Selected 256B page
.import GEORAM_PAGE := $DE00  # IO_AREA_1_BASE

;;; summary: GEORAM registers
.import GEORAM_REGISTER_BASE := $DF00  # IO_AREA_2_BASE

;;; summary: Select page in bank GEORAM_PAGE_MIN -- GEORAM_PAGE_MAX(0 -- 63 = $0 -- $3f)
;;; notes: write-only
.import GEORAM_PAGE_SELECT := GEORAM_REGISTER_BASE + $FE

;;; summary: Select 16KB bank, write-only
;;; notes:
;;;    512KB: GEORAM_BANK_MIN -- GEORAM_BANK_MAX_512KB  (0 --  31 = $0 -- $1F)
;;;   1024KB: GEORAM_BANK_MIN -- GEORAM_BANK_MAX_1024KB (0 --  63 = $0 -- $3F)
;;;   2048KB: GEORAM_BANK_MIN -- GEORAM_BANK_MAX_2048KB (0 -- 127 = $0 -- $7F)
;;;   4096KB: GEORAM_BANK_MIN -- GEORAM_BANK_MAX_4096KB (0 -- 255 = $0 -- $FF)
.import GEORAM_BANK_SELECT := GEORAM_REGISTER_BASE + $FF

.endif
