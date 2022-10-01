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

.ifndef __CE_DECL_INC__
    __CE_DECL_INC__ = 1

; ==============================================================================
; Frames for cedecl: CalleE removes parameters from stack
; ==============================================================================

.macro BEGIN_CE_FRAME
    lda z:FP                            ; 2/3
    pha                                 ; 1/3
    ldx z:RSP                           ; 2/3
    stx z:FP                            ; 2/3
.endmacro

.macro END_CE_FRAME
    pla                                 ; 1/4
    sta z:FP                            ; 2/3
    sta z:RSP                           ; 2/3
    tax                                 ; 1/2
.endmacro

.endif
