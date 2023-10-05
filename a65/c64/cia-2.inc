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

;;; summary: CIA 2: Serial bus, RS-232, VIC memory, NMI control
;;; notes:
;;;   Pin CIA_1.FLAG is connected to CPU.NMI.
;;;
;;;   CIA_2_PRA
;;;     Bit 0..1: Select the position of the VIC-memory
;;;       %00, 0: Bank 3: $C000-$FFFF, 49152-65535
;;;       %01, 1: Bank 2: $8000-$BFFF, 32768-49151
;;;       %10, 2: Bank 1: $4000-$7FFF, 16384-32767
;;;       %11, 3: Bank 0: $0000-$3FFF, 0-16383 (standard)
;;;     Bit 2: RS-232: TXD Output, userport: Data PA 2 (pin M)
;;;     Bit 3..5: serial bus Output (0=High/Inactive, 1=Low/Active)
;;;     Bit 3: ATN OUT
;;;     Bit 4: CLOCK OUT
;;;     Bit 5: DATA OUT
;;;     Bit 6..7: serial bus Input (0=Low/Active, 1=High/Inactive)
;;;     Bit 6: CLOCK IN
;;;     Bit 7: DATA IN
;;;
;;;   CIA_2_PRB
;;;     Bit 0..7: userport Data PB 0-7 (Pins C,D,E,F,H,J,K,L)
;;;     The KERNAL offers several RS232-Routines, which use the pins as followed:
;;;     Bit 0, 3..7: RS-232: reading
;;;     Bit 0: RXD
;;;     Bit 3: RI
;;;     Bit 4: DCD
;;;     Bit 5: User port pin J
;;;     Bit 6: CTS
;;;     Bit 7: DSR
;;;     Bit 1..5: RS-232: writing
;;;     Bit 1: RTS
;;;     Bit 2: DTR
;;;     Bit 3: RI
;;;     Bit 4: DCD
;;;     Bit 5: User port pin J

CIA_2_PRA_SELECT_VIC_BANK_MASK            = %00000011
CIA_2_PRA_SELECT_VIC_BANK_CLR             = %11111100
CIA_2_PRA_SELECT_VIC_BANK_BANK_3          = %00000000  ; $C000-$FFFF
CIA_2_PRA_SELECT_VIC_BANK_BANK_2          = %00000001  ; $8000-$BFFF
CIA_2_PRA_SELECT_VIC_BANK_BANK_1          = %00000010  ; $4000-$7FFF
CIA_2_PRA_SELECT_VIC_BANK_BANK_0          = %00000011  ; $0000-$3FFF
CIA_2_PRA_USERPORT_M_RS232_TXD_OUT        = 2
CIA_2_PRA_USERPORT_M_RS232_TXD_OUT_MASK   = %00000100
CIA_2_PRA_USERPORT_M_RS232_TXD_OUT_CLR    = %11111011
CIA_2_PRA_W_SERIAL_INV_ATN_OUT            = 3
CIA_2_PRA_W_SERIAL_INV_ATN_OUT_MASK       = %00001000
CIA_2_PRA_W_SERIAL_INV_ATN_OUT_CLR        = %11110111
CIA_2_PRA_W_SERIAL_INV_CLOCK_OUT          = 4
CIA_2_PRA_W_SERIAL_INV_CLOCK_OUT_MASK     = %00010000
CIA_2_PRA_W_SERIAL_INV_CLOCK_OUT_CLR      = %11101111
CIA_2_PRA_W_SERIAL_INV_DATA_OUT           = 5
CIA_2_PRA_W_SERIAL_INV_DATA_OUT_MASK      = %00100000
CIA_2_PRA_W_SERIAL_INV_DATA_OUT_CLR       = %11011111
CIA_2_PRA_R_SERIAL_INV_CLOCK_IN           = 6
CIA_2_PRA_R_SERIAL_INV_CLOCK_IN_MASK      = %01000000
CIA_2_PRA_R_SERIAL_INV_CLOCK_IN_CLR       = %10111111
CIA_2_PRA_R_SERIAL_INV_DATA_IN            = 7
CIA_2_PRA_R_SERIAL_INV_DATA_IN_MASK       = %10000000
CIA_2_PRA_R_SERIAL_INV_DATA_IN_CLR        = %01111111

CIA_2_PRB_R_USERPORT_C_RS232_RXD      = 0
CIA_2_PRB_R_USERPORT_C_RS232_RXD_MASK = %00000001
CIA_2_PRB_R_USERPORT_C_RS232_RXD_CLR  = %11111110
CIA_2_PRB_R_USERPORT_F_RS232_RI       = 3
CIA_2_PRB_R_USERPORT_F_RS232_RI_MASK  = %00001000
CIA_2_PRB_R_USERPORT_F_RS232_RI_CLR   = %11110111
CIA_2_PRB_R_USERPORT_H_RS232_DCD      = 4
CIA_2_PRB_R_USERPORT_H_RS232_DCD_MASK = %00010000
CIA_2_PRB_R_USERPORT_H_RS232_DCD_CLR  = %11101111
CIA_2_PRB_R_USERPORT_J                = 5
CIA_2_PRB_R_USERPORT_J_MASK           = %00100000
CIA_2_PRB_R_USERPORT_J_CLR            = %11011111
CIA_2_PRB_R_USERPORT_K_RS232_CTS      = 6
CIA_2_PRB_R_USERPORT_K_RS232_CTS_MASK = %01000000
CIA_2_PRB_R_USERPORT_K_RS232_CTS_CLR  = %10111111
CIA_2_PRB_R_USERPORT_L_RS232_DSR      = 7
CIA_2_PRB_R_USERPORT_L_RS232_DSR_MASK = %10000000
CIA_2_PRB_R_USERPORT_L_RS232_DSR_CLR  = %01111111
CIA_2_PRB_W_USERPORT_D_RS232_RTS      = 1
CIA_2_PRB_W_USERPORT_D_RS232_RTS_MASK = %00000010
CIA_2_PRB_W_USERPORT_D_RS232_RTS_CLR  = %11111101
CIA_2_PRB_W_USERPORT_E_RS232_DTR      = 2
CIA_2_PRB_W_USERPORT_E_RS232_DTR_MASK = %00000100
CIA_2_PRB_W_USERPORT_E_RS232_DTR_CLR  = %11111011
CIA_2_PRB_W_USERPORT_F_RS232_RI       = 3
CIA_2_PRB_W_USERPORT_F_RS232_RI_MASK  = %00001000
CIA_2_PRB_W_USERPORT_F_RS232_RI_CLR   = %11110111
CIA_2_PRB_W_USERPORT_H_RS232_DCD      = 4
CIA_2_PRB_W_USERPORT_H_RS232_DCD_MASK = %00010000
CIA_2_PRB_W_USERPORT_H_RS232_DCD_CLR  = %11101111
CIA_2_PRB_W_USERPORT_J                = 5
CIA_2_PRB_W_USERPORT_J_MASK           = %00100000
CIA_2_PRB_W_USERPORT_J_CLR            = %11011111
