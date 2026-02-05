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

; ==============================================================================
; Kernal revision 3 Public interface
; ==============================================================================

; ==============================================================================
; Configuration
; ==============================================================================

.export KERNAL_ACTUAL_REVISION := $FF80

.export KERNAL_ORG := $E000

; ==============================================================================
; Entry points KERNAL_*
; ==============================================================================

.export KERNAL_CINT   := $FF81  ; -> pcint    = $FF5B
.export KERNAL_IOINIT := $FF84  ; -> ioinit   = $FDA3
.export KERNAL_RAMTAS := $FF87  ; -> ramtas   = $FD50
.export KERNAL_RESTOR := $FF8A  ; -> restor   = $FD15
.export KERNAL_VECTOR := $FF8D  ; -> vector   = $FD1A
.export KERNAL_SETMSG := $FF90  ; -> setmsg   = $FE18
.export KERNAL_SECOND := $FF93  ; -> secnd    = $EDB9
.export KERNAL_TKSA   := $FF96  ; -> tksa     = $EDC7
.export KERNAL_MEMTOP := $FF99  ; -> memtop   = $FE25                     ; set/read top of memory
.export KERNAL_MEMBOT := $FF9C  ; -> membot   = $FE34                     ; set/read bottom of memory
.export KERNAL_SCNKEY := $FF9F  ; -> scnkey   = $EA87                     ; scan keyboard
.export KERNAL_SETTMO := $FFA2  ; -> settmo   = $FE21                     ; set timeout in ieee
.export KERNAL_ACPTR  := $FFA5  ; -> acptr    = $EE13                     ; handshake ieee byte in
.export KERNAL_CIOUT  := $FFA8  ; -> ciout    = $EDDD                     ; handshake ieee byte out
.export KERNAL_UNTLK  := $FFAB  ; -> untlk    = $EDEF                     ; send untalk out ieee
.export KERNAL_UNLSN  := $FFAE  ; -> unlsn    = $EDFE                     ; send unlisten out ieee
.export KERNAL_LISTEN := $FFB1  ; -> listn    = $ED0C                     ; send listen out ieee
.export KERNAL_TALK   := $FFB4  ; -> talk     = $ED09                     ; send talk out ieee
.export KERNAL_READST := $FFB7  ; -> readss   = $FE07                     ; return i/o status byte
.export KERNAL_SETLFS := $FFBA  ; -> setlfs   = $FE00                     ; set la, fa, sa
.export KERNAL_SETNAM := $FFBD  ; -> setnam   = $FDF9                     ; set length and fn adr
.export KERNAL_OPEN   := $FFC0  ; -> [iopen]  = [$031A] = nopen  = $F34A
.export KERNAL_CLOSE  := $FFC3  ; -> [iclose] = [$031C] = nclose = $F291
.export KERNAL_CHKIN  := $FFC6  ; -> [ichkin] = [$031E] = nchkin = $F20E
.export KERNAL_CHKOUT := $FFC9  ; -> [ickout] = [$0320] = nckout = $F250
.export KERNAL_CLRCHN := $FFCC  ; -> [iclrch] = [$0322] = nclrch = $F333  ; close i/o channel
.export KERNAL_CHRIN  := $FFCF  ; -> [ibasin] = [$0324] = nbasin = $F157  ; input from channel
.export KERNAL_CHROUT := $FFD2  ; -> [ibsout] = [$0326] = nbsout = $F1CA  ; output to channel
.export KERNAL_LOAD   := $FFD5  ; -> loadsp   = $F49E                     ; load from file
.export KERNAL_SAVE   := $FFD8  ; -> savesp   = $F5DD                     ; save to file
.export KERNAL_SETTIM := $FFDB  ; -> settim   = $F6E4                     ; set internal clock
.export KERNAL_RDTIM  := $FFDE  ; -> rdtim    = $F6DD                     ; read internal clock
.export KERNAL_STOP   := $FFE1  ; -> [istop]  = [$0328] = nstop  = $F6ED  ; scan stop key
.export KERNAL_GETIN  := $FFE4  ; -> [igetin] = [$032A] = ngetin = $F13E  ; get char from q
.export KERNAL_CLALL  := $FFE7  ; -> [iclall] = [$032C] = nclall = $F32F  ; close all files
.export KERNAL_UDTIM  := $FFEA  ; -> udtim    = $F69B                     ; increment clock
.export KERNAL_SCREEN := $FFED  ; -> scrorg   = $E505                     ; screen org
.export KERNAL_PLOT   := $FFF0  ; -> plot     = $E50A                     ; read/set x,y coord
.export KERNAL_IOBASE := $FFF3  ; -> iobase   = $E500                     ; return i/o base

; ==============================================================================
; Constants
; ==============================================================================

.export MEMSTR_DEFAULT := $0800    ; default memstr start of memory
.export MEMSIZ_DEFAULT := $A000    ; default memsiz top of memory

; ==============================================================================
; segment "KVECTORS"
; ==============================================================================

; Initialized by vector from table vectss
.export KERNAL_CINV      = $0314                ; (2 bytes $0314-$0315 default key    = $EA31) irq ram vector
.export KERNAL_CINV_LO   = KERNAL_CINV
.export KERNAL_CINV_HI   = KERNAL_CINV + 1
.export KERNAL_CBINV     = $0316                ; (2 bytes $0316-$0317 default timb   = $FE66) brk instr ram vector
.export KERNAL_CBINV_LO  = KERNAL_CBINV
.export KERNAL_CBINV_HI  = KERNAL_CBINV + 1
.export KERNAL_NMINV     = $0318                ; (2 bytes $0318-$0319 default nnmi   = $FE47) nmi ram vector
.export KERNAL_NMINV_LO  = KERNAL_NMINV
.export KERNAL_NMINV_HI  = KERNAL_NMINV + 1
.export KERNAL_IOPEN     = $031A                ; (2 bytes $031A-$031B default nopen  = $F34A) indirects for code
.export KERNAL_IOPEN_LO  = KERNAL_IOPEN
.export KERNAL_IOPEN_HI  = KERNAL_IOPEN + 1
.export KERNAL_ICLOSE    = $031C                ; (2 bytes $031C-$031D default nclose = $F291) conforms to kernal spec 8/19/80
.export KERNAL_ICLOSE_LO = KERNAL_ICLOSE
.export KERNAL_ICLOSE_HI = KERNAL_ICLOSE + 1
.export KERNAL_ICHKIN    = $031E                ; (2 bytes $031E-$031F default nchkin = $F20E)
.export KERNAL_ICHKIN_LO = KERNAL_ICHKIN
.export KERNAL_ICHKIN_HI = KERNAL_ICHKIN + 1
.export KERNAL_ICKOUT    = $0320                ; (2 bytes $0320-$0321 default nckout = $F250)
.export KERNAL_ICKOUT_LO = KERNAL_ICKOUT
.export KERNAL_ICKOUT_HI = KERNAL_ICKOUT + 1
.export KERNAL_ICLRCH    = $0322                ; (2 bytes $0322-$0323 default nclrch = $F333)
.export KERNAL_ICLRCH_LO = KERNAL_ICLRCH
.export KERNAL_ICLRCH_HI = KERNAL_ICLRCH + 1
.export KERNAL_IBASIN    = $0324                ; (2 bytes $0324-$0325 default nbasin = $F157)
.export KERNAL_IBASIN_LO = KERNAL_IBASIN
.export KERNAL_IBASIN_HI = KERNAL_IBASIN + 1
.export KERNAL_IBSOUT    = $0326                ; (2 bytes $0326-$0327 default nbsout = $F1CA)
.export KERNAL_IBSOUT_LO = KERNAL_IBSOUT
.export KERNAL_IBSOUT_HI = KERNAL_IBSOUT + 1
.export KERNAL_ISTOP     = $0328                ; (2 bytes $0328-$0329 default nstop  = $F6ED)
.export KERNAL_ISTOP_LO  = KERNAL_ISTOP
.export KERNAL_ISTOP_HI  = KERNAL_ISTOP + 1
.export KERNAL_IGETIN    = $032A                ; (2 bytes $032A-$032B default ngetin = $F13E)
.export KERNAL_IGETIN_LO = KERNAL_IGETIN
.export KERNAL_IGETIN_HI = KERNAL_IGETIN + 1
.export KERNAL_ICLALL    = $032C                ; (2 bytes $032C-$032D default nclall = $F32F)
.export KERNAL_ICLALL_LO = KERNAL_ICLALL
.export KERNAL_ICLALL_HI = KERNAL_ICLALL + 1
.export KERNAL_USRCMD    = $032E                ; (2 bytes $032E-$032F default timb   = $FE66)
.export KERNAL_USRCMD_LO = KERNAL_USRCMD
.export KERNAL_USRCMD_HI = KERNAL_USRCMD + 1
.export KERNAL_ILOAD     = $0330                ; (2 bytes $0330-$0331 default nload  = $F4A5)
.export KERNAL_ILOAD_LO  = KERNAL_ILOAD
.export KERNAL_ILOAD_HI  = KERNAL_ILOAD + 1
.export KERNAL_ISAVE     = $0332                ; (2 bytes $0332-$0333 default nsave  = $F5ED) savesp
.export KERNAL_ISAVE_LO  = KERNAL_ISAVE
.export KERNAL_ISAVE_HI  = KERNAL_ISAVE + 1

; ==============================================================================
; End of Kernal revision 3 Public interface
; ==============================================================================
