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

;;; summary: C64 Kernal revision 3 internals

; ==============================================================================
; Kernal revision 3 zero page semi-public
; ==============================================================================

; ==============================================================================
; segment "ZPKERNAL"
; ==============================================================================

.exportzp KERNAL_STATUS := $90          ; i/o operation status byte
.exportzp KERNAL_STKEY  := $91          ; stop key flag
.exportzp KERNAL_MSGFLG := $9D          ; os message flag
.exportzp KERNAL_TIME   := $A0          ; 24 hour clock in 1/60th seconds ($A0-$A2)
