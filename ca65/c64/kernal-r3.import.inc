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

.ifndef __C64_KERNAL_R3_IMPORT_INC__
    __C64_KERNAL_R3_IMPORT_INC__ = 1

; ==============================================================================
; Kernal revision 3 Public interface
; ==============================================================================

; ==============================================================================
; Configuration
; ==============================================================================

.import KERNAL_ACTUAL_REVISION

.import KERNAL_ORG

; ==============================================================================
; Entry points KERNAL_*
; ==============================================================================

.import KERNAL_CINT
.import KERNAL_IOINIT
.import KERNAL_RAMTAS
.import KERNAL_RESTOR
.import KERNAL_VECTOR
.import KERNAL_SETMSG
.import KERNAL_SECOND
.import KERNAL_TKSA
.import KERNAL_MEMTOP
.import KERNAL_MEMBOT
.import KERNAL_SCNKEY
.import KERNAL_SETTMO
.import KERNAL_ACPTR
.import KERNAL_CIOUT
.import KERNAL_UNTLK
.import KERNAL_UNLSN
.import KERNAL_LISTEN
.import KERNAL_TALK
.import KERNAL_READST
.import KERNAL_SETLFS
.import KERNAL_SETNAM
.import KERNAL_OPEN
.import KERNAL_CLOSE
.import KERNAL_CHKIN
.import KERNAL_CHKOUT
.import KERNAL_CLRCHN
.import KERNAL_CHRIN
.import KERNAL_CHROUT
.import KERNAL_LOAD
.import KERNAL_SAVE
.import KERNAL_SETTIM
.import KERNAL_RDTIM
.import KERNAL_STOP
.import KERNAL_GETIN
.import KERNAL_CLALL
.import KERNAL_UDTIM
.import KERNAL_SCREEN
.import KERNAL_PLOT
.import KERNAL_IOBASE

; ==============================================================================
; Constants
; ==============================================================================

.import MEMSTR_DEFAULT
.import MEMSIZ_DEFAULT

; ==============================================================================
; segment "KVECTORS"
; ==============================================================================

; Initialized by vector from table vectss
.import KERNAL_CINV
.import KERNAL_CBINV
.import KERNAL_NMINV
.import KERNAL_IOPEN
.import KERNAL_ICLOSE
.import KERNAL_ICHKIN
.import KERNAL_ICKOUT
.import KERNAL_ICLRCH
.import KERNAL_IBASIN
.import KERNAL_IBSOUT
.import KERNAL_ISTOP
.import KERNAL_IGETIN
.import KERNAL_ICLALL
.import KERNAL_USRCMD
.import KERNAL_ILOAD
.import KERNAL_ISAVE

; ==============================================================================
; End of Kernal revision 3 Public interface
; ==============================================================================

.endif
