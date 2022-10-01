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

;;; summary: Frame registers:
;;;   RSP            Register Stack pointer
;;;   FSP            Frame Stack Pointer
;;;   FP             Frame Pointer
;;; notes:
;;;   Register stack grows upwards from RS.
;;;   Frame stack grows downwards from FS.

FS  = ZP_3_LAST       ; Top of Frame Stack
RS  = ZP_5_FIRST      ; Bottom of Register Stack
RSP = ZP_7_FIRST + 0  ; Register Stack Pointer
FSP = ZP_8_FIRST + 0  ; Frame Stack Pointer
FP  = ZP_8_FIRST + 1  ; Frame Pointer
