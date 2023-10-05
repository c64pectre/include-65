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

;;; summary: GEORAM

GEORAM_BANK_MIN          = 0
GEORAM_BANK_MAX_512KB    = 31
GEORAM_BANK_COUNT_512KB  = GEORAM_BANK_MAX_512KB - GEORAM_BANK_MIN + 1
GEORAM_BANK_MAX_1024KB   = 63
GEORAM_BANK_COUNT_1024KB = GEORAM_BANK_MAX_1024KB - GEORAM_BANK_MIN + 1
GEORAM_BANK_MAX_2048KB   = 127
GEORAM_BANK_COUNT_2048KB = GEORAM_BANK_MAX_2048KB - GEORAM_BANK_MIN + 1
GEORAM_BANK_MAX_4096KB   = 255
GEORAM_BANK_COUNT_4096KB = GEORAM_BANK_MAX_4096KB - GEORAM_BANK_MIN + 1

GEORAM_PAGE_MIN   = 0
GEORAM_PAGE_MAX   = 63
GEORAM_PAGE_COUNT = GEORAM_PAGE_MAX - GEORAM_PAGE_MIN + 1
