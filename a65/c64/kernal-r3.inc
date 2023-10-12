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

;;; summary: C64 Kernal revision 3

; ==============================================================================
; Kernal revision 3 Public interface
;
; See ca65/c64/kernal.export.asm for addresses.
;
; You can check for the required kernal revision in your program with
;   lda KERNAL_REVISION
;   ASSERT_A_EQ(KERNAL_REVISION_3)
; ==============================================================================

; ==============================================================================
; Configuration
; ==============================================================================

;KERNAL_ACTUAL_REVISION = $FF80

KERNAL_REVISION_1 = 1
KERNAL_REVISION_2 = 2
KERNAL_REVISION_3 = 3

KERNAL_CURRENT_REVISION = KERNAL_REVISION_3

;KERNAL_ORG = $E000

; ==============================================================================
; Entry points KERNAL_*
; ==============================================================================

;KERNAL_CINT   = $FF81  ; -> pcint    = $FF5B
;KERNAL_IOINIT = $FF84  ; -> ioinit   = $FDA3
;KERNAL_RAMTAS = $FF87  ; -> ramtas   = $FD50
;KERNAL_RESTOR = $FF8A  ; -> restor   = $FD15
;KERNAL_VECTOR = $FF8D  ; -> vector   = $FD1A
;KERNAL_SETMSG = $FF90  ; -> setmsg   = $FE18
;KERNAL_SECOND = $FF93  ; -> secnd    = $EDB9
;KERNAL_TKSA   = $FF96  ; -> tksa     = $EDC7
;KERNAL_MEMTOP = $FF99  ; -> memtop   = $FE25                     ; set/read top of memory
;KERNAL_MEMBOT = $FF9C  ; -> membot   = $FE34                     ; set/read bottom of memory
;KERNAL_SCNKEY = $FF9F  ; -> scnkey   = $EA87                     ; scan keyboard
;KERNAL_SETTMO = $FFA2  ; -> settmo   = $FE21                     ; set timeout in ieee
;KERNAL_ACPTR  = $FFA5  ; -> acptr    = $EE13                     ; handshake ieee byte in
;KERNAL_CIOUT  = $FFA8  ; -> ciout    = $EDDD                     ; handshake ieee byte out
;KERNAL_UNTLK  = $FFAB  ; -> untlk    = $EDEF                     ; send untalk out ieee
;KERNAL_UNLSN  = $FFAE  ; -> unlsn    = $EDFE                     ; send unlisten out ieee
;KERNAL_LISTEN = $FFB1  ; -> listn    = $ED0C                     ; send listen out ieee
;KERNAL_TALK   = $FFB4  ; -> talk     = $ED09                     ; send talk out ieee
;KERNAL_READST = $FFB7  ; -> readss   = $FE07                     ; return i/o status byte
;KERNAL_SETLFS = $FFBA  ; -> setlfs   = $FE00                     ; set la, fa, sa
;KERNAL_SETNAM = $FFBD  ; -> setnam   = $FDF9                     ; set length and fn adr
;KERNAL_OPEN   = $FFC0  ; -> [iopen]  = [$031A] = nopen  = $F34A
;KERNAL_CLOSE  = $FFC3  ; -> [iclose] = [$031C] = nclose = $F291
;KERNAL_CHKIN  = $FFC6  ; -> [ichkin] = [$031E] = nchkin = $F20E
;KERNAL_CHKOUT = $FFC9  ; -> [ickout] = [$0320] = nckout = $F250
;KERNAL_CLRCHN = $FFCC  ; -> [iclrch] = [$0322] = nclrch = $F333  ; close i/o channel
;KERNAL_CHRIN  = $FFCF  ; -> [ibasin] = [$0324] = nbasin = $F157  ; input from channel
;KERNAL_CHROUT = $FFD2  ; -> [ibsout] = [$0326] = nbsout = $F1CA  ; output to channel
;KERNAL_LOAD   = $FFD5  ; -> loadsp   = $F49E                     ; load from file
;KERNAL_SAVE   = $FFD8  ; -> savesp   = $F5DD                     ; save to file
;KERNAL_SETTIM = $FFDB  ; -> settim   = $F6E4                     ; set internal clock
;KERNAL_RDTIM  = $FFDE  ; -> rdtim    = $F6DD                     ; read internal clock
;KERNAL_STOP   = $FFE1  ; -> [istop]  = [$0328] = nstop  = $F6ED  ; scan stop key
;KERNAL_GETIN  = $FFE4  ; -> [igetin] = [$032A] = ngetin = $F13E  ; get char from q
;KERNAL_CLALL  = $FFE7  ; -> [iclall] = [$032C] = nclall = $F32F  ; close all files
;KERNAL_UDTIM  = $FFEA  ; -> udtim    = $F69B                     ; increment clock
;KERNAL_SCREEN = $FFED  ; -> scrorg   = $E505                     ; screen org
;KERNAL_PLOT   = $FFF0  ; -> plot     = $E50A                     ; read/set x,y coord
;KERNAL_IOBASE = $FFF3  ; -> iobase   = $E500                     ; return i/o base

; ==============================================================================
; Signature
; ==============================================================================

;;; KERNAL_ACTUAL_SIGNATURE = $FFF6       ; see kernal-r3-internal.inc

.define KERNAL_EXPECTED_SIGNATURE "RRBY"

; ==============================================================================
; Constants - Devices
; Device numbers above 3 all refer to devices connected through the serial
; (ieee) port. They are all handled in exactly the same way from KERNAL-s
; point of view, but by convention
; ==============================================================================

DEVICE_MIN         =  0
DEVICE_MAX         = 30
DEVICE_KEYBOARD    =  0
DEVICE_DATASSETTE  =  1
DEVICE_RS232       =  2
DEVICE_TEXT_SCREEN =  3
DEVICE_SERIAL_MIN  =  4
DEVICE_SERIAL_MAX  = 30
DEVICE_PRINTER_MIN =  4
DEVICE_PRINTER_MAX =  5
DEVICE_PRINTER_4   =  4
DEVICE_PRINTER_5   =  5
DEVICE_PLOTTER_MIN =  6
DEVICE_PLOTTER_MAX =  7
DEVICE_PLOTTER_6   =  6
DEVICE_PLOTTER_7   =  7
DEVICE_DISK_MIN    =  8
DEVICE_DISK_MAX    = 30
DEVICE_DISK_8      =  8
DEVICE_DISK_9      =  9
DEVICE_DISK_10     = 10
DEVICE_DISK_11     = 11
DEVICE_DISK_12     = 12
DEVICE_DISK_13     = 13
DEVICE_DISK_14     = 14
DEVICE_DISK_15     = 15
DEVICE_DISK_16     = 16
DEVICE_DISK_17     = 17
DEVICE_DISK_18     = 18
DEVICE_DISK_19     = 19
DEVICE_DISK_20     = 20
DEVICE_DISK_21     = 21
DEVICE_DISK_22     = 22
DEVICE_DISK_23     = 23
DEVICE_DISK_24     = 24
DEVICE_DISK_25     = 25
DEVICE_DISK_26     = 26
DEVICE_DISK_27     = 27
DEVICE_DISK_28     = 28
DEVICE_DISK_29     = 29
DEVICE_DISK_30     = 30

DEVICE_DISK_DRIVE_MIN     =  0
DEVICE_DISK_DRIVE_MAX     =  1
DEVICE_DISK_DRIVE_0       =  0
DEVICE_DISK_DRIVE_1       =  1
DEVICE_DISK_DRIVE_DEFAULT =  0

DEVICE_DISK_CHANNEL_MIN     = 0
DEVICE_DISK_CHANNEL_MAX     = 15
DEVICE_DISK_CHANNEL_LOAD    = 0
DEVICE_DISK_CHANNEL_SAVE    = 1
DEVICE_DISK_CHANNEL_2       = 2
DEVICE_DISK_CHANNEL_3       = 3
DEVICE_DISK_CHANNEL_4       = 4
DEVICE_DISK_CHANNEL_5       = 5
DEVICE_DISK_CHANNEL_6       = 6
DEVICE_DISK_CHANNEL_7       = 7
DEVICE_DISK_CHANNEL_8       = 8
DEVICE_DISK_CHANNEL_9       = 9
DEVICE_DISK_CHANNEL_10      = 10
DEVICE_DISK_CHANNEL_11      = 11
DEVICE_DISK_CHANNEL_12      = 12
DEVICE_DISK_CHANNEL_13      = 13
DEVICE_DISK_CHANNEL_14      = 14
DEVICE_DISK_CHANNEL_15      = 15
DEVICE_DISK_CHANNEL_COMMAND = 15

; ==============================================================================
; Constants - Serial bus commands
; ==============================================================================

SERIAL_COMMAND_GLOBAL    = $00  ; %000nnnnn
SERIAL_COMMAND_PA_LISTEN = $20  ; %001nnnnn
SERIAL_COMMAND_PA_TALK   = $40  ; %010nnnnn
SERIAL_COMMAND_SA_SECOND = $60  ; %011nnnnn
SERIAL_COMMAND_SA_CLOSE  = $E0  ; %1110nnnn
SERIAL_COMMAND_SA_OPEN   = $F0  ; %1111nnnn
SERIAL_COMMAND_UNLISTEN  = $3F  ; %00111111
SERIAL_COMMAND_UNTALK    = $5F  ; %01011111

; ==============================================================================
; Constants
; ==============================================================================

HIBASE_DEFAULT = $04      ; default hibase base location of screen (top)
;MEMSTR_DEFAULT = $0800    ; default memstr start of memory
;MEMSIZ_DEFAULT = $A000    ; default memsiz top of memory

; ==============================================================================
; Constants - Tape and IEEE errors
; ==============================================================================

;ZPKERNAL_STATUS = $90

KERNAL_IO_ERROR_BIT_0_BIT              = 0
KERNAL_IO_ERROR_READ_TIMEOUT_BIT       = 1
KERNAL_IO_ERROR_SHORT_BLOCK_BIT        = 2
KERNAL_IO_ERROR_LONG_BLOCK_BIT         = 3
KERNAL_IO_ERROR_SECOND_PASS_BIT        = 4
KERNAL_IO_ERROR_CHKSUM_BIT             = 5
KERNAL_IO_EOI_BIT                      = 6
KERNAL_IO_ERROR_DEVICE_NOT_PRESENT_BIT = 7

KERNAL_OK                          = 0
KERNAL_IO_ERROR_READ_TIMEOUT       = %00000010
KERNAL_IO_ERROR_SHORT_BLOCK        = %00000100
KERNAL_IO_ERROR_LONG_BLOCK         = %00001000
KERNAL_IO_ERROR_SECOND_PASS        = %00010000
KERNAL_IO_ERROR_CHKSUM             = %00100000
KERNAL_IO_EOI                      = %01000000      ; BIT M ; BVS TRUE BVC FALSE
KERNAL_IO_ERROR_DEVICE_NOT_PRESENT = %10000000      ; $80
KERNAL_IO_ERROR_FRAMING            = %00000011      ; $03

; ==============================================================================
; Constants - KERNAL_SETMSG
; Notes:
; Check msgflag:
;   bit KERNAL_SETMSG
;   bvc error_messages_disabled
;   bvs error_messages_enabled
;   bpl status_messages_disabled
;   bmi status_messages_enabled
; Enable error and status messages
;   lda #MSG_ERROR_ENABLE | MSG_STATUS_ENABLE
;   jsr KERNAL_SETMSG
; ==============================================================================

KERNAL_MSG_OFF            = 0
KERNAL_MSG_ERROR_BIT      = 6
KERNAL_MSG_ERROR_ENABLE   = %01000000
KERNAL_MSG_ERROR_DISABLE  = %10111111
KERNAL_MSG_STATUS_BIT     = 7
KERNAL_MSG_STATUS_ENABLE  = %10000000
KERNAL_MSG_STATUS_DISABLE = %01111111

; ==============================================================================
; Constants - I/O errors
; ==============================================================================
KERNAL_ERROR_NO_ERROR           = 0
KERNAL_ERROR_TOO_MANY_FILES     = 1
KERNAL_ERROR_FILE_OPEN          = 2
KERNAL_ERROR_FILE_NOT_OPEN      = 3
KERNAL_ERROR_FILE_NOT_FOUND     = 4
KERNAL_ERROR_DEVICE_NOT_PRESENT = 5
KERNAL_ERROR_NOT_INPUT_FILE     = 6
KERNAL_ERROR_NOT_OUTPUT_FILE    = 7
KERNAL_ERROR_MISSING_FILE_NAME  = 8
KERNAL_ERROR_BAD_DEVICE_NUMBER  = 9

; ==============================================================================
; Constants - KERNAL_LOAD
; ==============================================================================

KERNAL_LOAD_LOAD = 0
KERNAL_LOAD_VERIFY = 1

; ==============================================================================
; segment "ZPKERNAL"
; ==============================================================================

;KERNAL_STATUS = $90      ; i/o operation status byte
;KERNAL_STKEY  = $91      ; stop key flag
;KERNAL_MSGFLG = $9D      ; os message flag
;KERNAL_TIME   = $A0      ; 24 hour clock in 1/60th seconds ($A0-$A2)

; ==============================================================================
; segment "KVECTORS"
; ==============================================================================

; Initialized by vector from table vectss
;KERNAL_CINV   = $0314    ; irq ram vector                  (2 bytes $0314-$0315 default key    = $EA31)
;KERNAL_CBINV  = $0316    ; brk instr ram vector            (2 bytes $0316-$0317 default timb   = $FE66)
;KERNAL_NMINV  = $0318    ; nmi ram vector                  (2 bytes $0318-$0319 default nnmi   = $FE47)
;KERNAL_IOPEN  = $031A    ; indirects for code              (2 bytes $031A-$031B default nopen  = $F34A)
;KERNAL_ICLOSE = $031C    ; conforms to kernal spec 8/19/80 (2 bytes $031C-$031D default nclose = $F291)
;KERNAL_ICHKIN = $031E    ;                                 (2 bytes $031E-$031F default nchkin = $F20E)
;KERNAL_ICKOUT = $0320    ;                                 (2 bytes $0320-$0321 default nckout = $F250)
;KERNAL_ICLRCH = $0322    ;                                 (2 bytes $0322-$0323 default nclrch = $F333)
;KERNAL_IBASIN = $0324    ;                                 (2 bytes $0324-$0325 default nbasin = $F157)
;KERNAL_IBSOUT = $0326    ;                                 (2 bytes $0326-$0327 default nbsout = $F1CA)
;KERNAL_ISTOP  = $0328    ;                                 (2 bytes $0328-$0329 default nstop  = $F6ED)
;KERNAL_IGETIN = $032A    ;                                 (2 bytes $032A-$032B default ngetin = $F13E)
;KERNAL_ICLALL = $032C    ;                                 (2 bytes $032C-$032D default nclall = $F32F)
;KERNAL_USRCMD = $032E    ;                                 (2 bytes $032E-$032F default timb   = $FE66)
;KERNAL_ILOAD  = $0330    ;                                 (2 bytes $0330-$0331 default nload  = $F4A5)
;KERNAL_ISAVE  = $0332    ; savesp                          (2 bytes $0332-$0333 default nsave  = $F5ED)

; ==============================================================================
; End of Kernal revision 3 Public interface
; ==============================================================================
