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

;;; summary: CIA 1 & 2
;;; notes:
;;;   Registers:
;;;   CIA_PRA: Data Port A
;;;     Monitoring/control of the 8 data lines of Port A. The lines are used for multiple purposes.
;;;     Read/write: bit 0..7
;;;   CIA_PRB: Data Port B
;;;     Monitoring/control of the 8 data lines of Port B. The lines are used for multiple purposes.
;;;     Read/write: bit 0..7
;;;   CIA_DDRA  Data direction Port A
;;;     Bit N: 0=input (read only), 1=output (read and write)
;;;   CIA_DDRB: Data direction Port B
;;;     Bit N: 0=input (read only), 1=output (read and write)
;;;   CIA_TA_LO: Timer A (low byte)
;;;     Read: actual value Timer A (low byte)
;;;     Write: set latch of Timer A (low byte)
;;;   CIA_TA_HI: Timer A (high byte)
;;;     Read: actual value Timer A (high byte)
;;;     Write: set latch of timer A (high byte). If the timer is stopped, the high-byte will automatically be re-set as well.
;;;   CIA_TB_LO: Timer B (low byte)
;;;     Read: actual value Timer B (low byte)
;;;     Write: set latch of Timer B (low byte)
;;;   CIA_TB_HI: Timer B (high byte)
;;;     Read: actual value Timer B (high byte)
;;;     Write: set latch of timer B (high byte). If the timer is stopped, the high-byte will automatically be re-set as well.
;;;   CIA_TOD_10THS: Real Time Clock (tenth seconds)
;;;     Read:
;;;       Bit 0..3: Tenth seconds in BCD-format ($0-$9)
;;;       Bit 4..7: always 0
;;;     Write:
;;;       Bit 0..3: if CRB-Bit7=0: Set the tenth seconds in BCD-format
;;;       Bit 0..3: if CRB-Bit7=1: Set the tenth seconds of the alarm time in BCD-format
;;;   CIA_TOD_SEC Real Time Clock (seconds)
;;;     Read/Write:
;;;       Bit 0..3: Single seconds in BCD-format ($0-$9)
;;;       Bit 4..6: Ten seconds in BCD-format ($0-$5)
;;;       Bit 7: always 0 on read
;;;   CIA_TOD_MIN: Real Time Clock (minutes)
;;;     Read/write:
;;;       Bit 0..3: Single minutes in BCD-format( $0-$9)
;;;       Bit 4..6: Ten minutes in BCD-format ($0-$5)
;;;       Bit 7: always 0 on read
;;;   CIA_TOD_HR: Real Time Clock (hours)
;;;     Read/write:
;;;       Bit 0..3: Single hours in BCD-format ($0-$9)
;;;       Bit 4..6: Ten hours in BCD-format ($0-$5)
;;;       Bit 7: Differentiation AM/PM, 0=AM, 1=PM
;;;     Writing into this register stops TOD, until register 8 (TOD 10THS) will be read.
;;;   CIA_SDR: Serial data shift register
;;;     read/write: The byte within this register will be shifted bitwise to or from the SP-pin with every positive slope at the CNT-pin.
;;;   CIA_ICR: Interrupt Control and status
;;;     Read:
;;;       Bit 0..4: INT DATA: Origin of the interrupt
;;;       Bit 0: 1 = Underflow Timer A
;;;       Bit 1: 1 = Underflow Timer B
;;;       Bit 2: 1 = Time of day and alarm time is equal
;;;       Bit 3: 1 = SDR full or empty, so full byte was transferred, depending of operating mode serial bus
;;;       Bit 4: 1 = IRQ Signal occured at FLAG-pin (cassette port Data input, serial bus SRQ IN)
;;;       Bit 5..6: always 0
;;;       Bit 7: 1 = IRQ An interrupt occured, so at least one bit of INT MASK and INT DATA is set in both registers.
;;;       Flags will be cleared after reading the register!
;;;     Write:
;;;      Bit 0..4: INT MASK, Interrupt mask
;;;        Bit 0: 1 = Interrupt release through timer A underflow
;;;        Bit 1: 1 = Interrupt release through timer B underflow
;;;        Bit 2: 1 = Interrupt release if clock=alarmtime
;;;        Bit 3: 1 = Interrupt release if a complete byte has been received/sent.
;;;        Bit 4: 1 = Interrupt release if a positive slope occurs at the FLAG-Pin.
;;;        Bit 5..6: unused
;;;        Bit 7: Source bit. 0 = set bits 0..4 are clearing the according mask bit. 1 = set bits 0..4 are setting the according mask bit. If all bits 0..4 are cleared, there will be no change to the mask.
;;;   CIA_CRA: Control Timer A
;;;     Read/write:
;;;       Bit 0: 0 = Stop timer; 1 = Start timer
;;;       Bit 1: 1 = Indicates a timer underflow at port B in bit 6.
;;;       Bit 2: 0 = Through a timer overflow, bit 6 of port B will get high for one cycle , 1 = Through a timer underflow, bit 6 of port B will be inverted
;;;       Bit 3: 0 = Timer-restart after underflow (latch will be reloaded), 1 = Timer stops after underflow.
;;;       Bit 4: 1 = Load latch into the timer once.
;;;       Bit 5: 0 = Timer counts system cycles, 1 = Timer counts positive slope at CNT-pin
;;;       Bit 6: Direction of the serial shift register, 0 = SP-pin is input (read), 1 = SP-pin is output (write)
;;;       Bit 7: Real Time Clock, 0 = 60 Hz, 1 = 50 Hz
;;;   CIA_CRB: Control Timer B
;;;     Read/write:
;;;       Bit 0: 0 = Stop timer; 1 = Start timer
;;;       Bit 1: 1 = Indicates a timer underflow at port B in bit 7.
;;;       Bit 2: 0 = Through a timer overflow, bit 7 of port B will get high for one cycle , 1 = Through a timer underflow, bit 7 of port B will be inverted
;;;       Bit 3: 0 = Timer-restart after underflow (latch will be reloaded), 1 = Timer stops after underflow.
;;;       Bit 4: 1 = Load latch into the timer once.
;;;       Bit 5..6:
;;;         %00 = Timer counts System cycle
;;;         %01 = Timer counts positive slope on CNT-pin
;;;         %10 = Timer counts underflow of timer A
;;;         %11 = Timer counts underflow of timer A if the CNT-pin is high
;;;       Bit 7: 0 = Writing into the TOD register sets the clock time, 1 = Writing into the TOD register sets the alarm time.
;;;
;;;   Pins:
;;;     Vss         Ground connection 0V
;;;     PA0 .. PA7  I/O-Port A Bit0-7 Bidirectional parallell port
;;;     PB0 .. PB7  I/O-Port B Bit0-7 Bidirectional parallell port
;;;     /PC         Port Control - Handshake output, Low pulse after read/write on port B.
;;;     TOD         Time Of Day clock input, either 50Hz or 60Hz input.
;;;     Vcc         5VDC input
;;;     /IRQ        Interrupt Request, output to CPU's IRQ or NMI input
;;;     R/W         High-level = Read (Move data from CIA), Low-level = Write (Move data to CIA)
;;;     /CS         Chip Select - low level means active CIA.
;;;     /FLAG       Negative edge IRQ input, can be used as handshake for either parallel port.
;;;     /phi2       Processor Φ2 clock, data transfers occur only on high signal level.
;;;     DB0 .. DB7  Bidirectional data bus Bits 0 - 7
;;;     /RES        Reset input, low signal initiates CIA.
;;;     RS0 .. RS3  Register Select - Used to interface internal registers with bidirectional ports.
;;;     SP          Serial Port - bidirectional, internal shift register converts CPU parallel data into serial data and vice-versa.
;;;     CNT         Count - Internal timers can count pulses to this input. Can be used for frequency dependent operations.
;;;   12-hour clock meaning:
;;;     12-hour                 | 24-hour
;;;     ------------------------+--------
;;;     Midnight (start of day) | 00:00
;;;       12 midnight
;;;       12:00 a.m.
;;;     12:01 a.m.              | 00:01
;;;      1:00 a.m.              | 01:00
;;;     11:00 a.m.              | 11:00
;;;     11:59 a.m.              | 11:59
;;;     Noon                    | 12:00
;;;       12 noon
;;;       12:00 p.m.
;;;     12:01 p.m.              | 12:01
;;;      1:00 p.m.              | 13:00
;;;     11:00 p.m.              | 23:00
;;;     11:59 p.m.              | 23:59
;;;     Midnight (end of day) shown as start of next day
;;;   Conversion table for CIA_TOD_HR from 12-hour clock to 24-hour clock and v.v.:
;;;   -------+-----+------+------+------------+-----------------
;;;   H12    | H24 | >>>> | <<<< | CIA_TOD_HR | CONDITIONS
;;;   -------+-----+------+------+------------+-----------------
;;;   $12 AM | $00 |  $00 |  $92 | $12        | bpl ; < $12 else
;;;   -------+-----+------+------+------------+-----------------
;;;   $01 AM | $01 | +$00 | -$00 | $01        | bpl ; < $12 then
;;;   ...
;;;   $11 AM | $11 | +$00 | -$00 | $11        | bpl ; < $12 then
;;;   -------+-----+------+------+------------+-----------------
;;;   $12 PM | $12 |  $00 |  $12 | $92        | bmi ; < $92 else
;;;   -------+-----+------+------+------------+-----------------
;;;   $01 PM | $13 | +$68 | -$68 | $81        | bmi ; < $92 then
;;;   ...
;;;   $11 PM | $23 | +$68 | -$68 | $91        | bmi ; < $92 then
;;;   -------+-----+------+------+------------+-----------------
;;;   To write 12 PM (is 12 [24]) to TOD_HR, you need to write $12, because the AM/PM bit is flipped and $92 is stored and read.
;;;   To write 12 AM (is 00 [24]) to TOD_HR, you need to write $92, because the AM/PM bit is flipped and $12 is stored and read.


CIA_R00   =  0
CIA_R01   =  1
CIA_R02   =  2
CIA_R03   =  3
CIA_R04   =  4
CIA_R05   =  5
CIA_R06   =  6
CIA_R07   =  7
CIA_R08   =  8
CIA_R09   =  9
CIA_R0A   = 10
CIA_R0B   = 11
CIA_R0C   = 12
CIA_R0D   = 13
CIA_R0E   = 14
CIA_R0F   = 15
CIA_FIRST = CIA_R00
CIA_LAST  = CIA_R0F

CIA_PRA       = CIA_R00
CIA_PRB       = CIA_R01
CIA_DDRA      = CIA_R02
CIA_DDRB      = CIA_R03
CIA_TA_LO     = CIA_R04
CIA_TA_HI     = CIA_R05
CIA_TB_LO     = CIA_R06
CIA_TB_HI     = CIA_R07
CIA_TOD_10THS = CIA_R08
CIA_TOD_SEC   = CIA_R09
CIA_TOD_MIN   = CIA_R0A
CIA_TOD_HR    = CIA_R0B
CIA_SDR       = CIA_R0C
CIA_ICR       = CIA_R0D
CIA_CRA       = CIA_R0E
CIA_CRB       = CIA_R0F

CIA_PRA_BIT_0 = 0
CIA_PRA_BIT_1 = 1
CIA_PRA_BIT_2 = 2
CIA_PRA_BIT_3 = 3
CIA_PRA_BIT_4 = 4
CIA_PRA_BIT_5 = 5
CIA_PRA_BIT_6 = 6
CIA_PRA_BIT_7 = 7

CIA_PRA_BIT_0_MASK = %00000001
CIA_PRA_BIT_1_MASK = %00000010
CIA_PRA_BIT_2_MASK = %00000100
CIA_PRA_BIT_3_MASK = %00001000
CIA_PRA_BIT_4_MASK = %00010000
CIA_PRA_BIT_5_MASK = %00100000
CIA_PRA_BIT_6_MASK = %01000000
CIA_PRA_BIT_7_MASK = %10000000

CIA_PRA_BIT_0_MASK_CLR = %11111110
CIA_PRA_BIT_1_MASK_CLR = %11111101
CIA_PRA_BIT_2_MASK_CLR = %11111011
CIA_PRA_BIT_3_MASK_CLR = %11110111
CIA_PRA_BIT_4_MASK_CLR = %11101111
CIA_PRA_BIT_5_MASK_CLR = %11011111
CIA_PRA_BIT_6_MASK_CLR = %10111111
CIA_PRA_BIT_7_MASK_CLR = %01111111

CIB_PRB_BIT_0 = 0
CIB_PRB_BIT_1 = 1
CIB_PRB_BIT_2 = 2
CIB_PRB_BIT_3 = 3
CIB_PRB_BIT_4 = 4
CIB_PRB_BIT_5 = 5
CIB_PRB_BIT_6 = 6
CIB_PRB_BIT_7 = 7

CIB_PRB_BIT_0_MASK = %00000001
CIB_PRB_BIT_1_MASK = %00000010
CIB_PRB_BIT_2_MASK = %00000100
CIB_PRB_BIT_3_MASK = %00001000
CIB_PRB_BIT_4_MASK = %00010000
CIB_PRB_BIT_5_MASK = %00100000
CIB_PRB_BIT_6_MASK = %01000000
CIB_PRB_BIT_7_MASK = %10000000

CIB_PRB_BIT_0_MASK_CLR = %11111110
CIB_PRB_BIT_1_MASK_CLR = %11111101
CIB_PRB_BIT_2_MASK_CLR = %11111011
CIB_PRB_BIT_3_MASK_CLR = %11110111
CIB_PRB_BIT_4_MASK_CLR = %11101111
CIB_PRB_BIT_5_MASK_CLR = %11011111
CIB_PRB_BIT_6_MASK_CLR = %10111111
CIB_PRB_BIT_7_MASK_CLR = %01111111

CIA_DDRA_BIT_0 = 0
CIA_DDRA_BIT_1 = 1
CIA_DDRA_BIT_2 = 2
CIA_DDRA_BIT_3 = 3
CIA_DDRA_BIT_4 = 4
CIA_DDRA_BIT_5 = 5
CIA_DDRA_BIT_6 = 6
CIA_DDRA_BIT_7 = 7

CIA_DDRA_BIT_0_MASK = %00000001
CIA_DDRA_BIT_1_MASK = %00000010
CIA_DDRA_BIT_2_MASK = %00000100
CIA_DDRA_BIT_3_MASK = %00001000
CIA_DDRA_BIT_4_MASK = %00010000
CIA_DDRA_BIT_5_MASK = %00100000
CIA_DDRA_BIT_6_MASK = %01000000
CIA_DDRA_BIT_7_MASK = %10000000

CIA_DDRA_BIT_0_MASK_CLR = %11111110
CIA_DDRA_BIT_1_MASK_CLR = %11111101
CIA_DDRA_BIT_2_MASK_CLR = %11111011
CIA_DDRA_BIT_3_MASK_CLR = %11110111
CIA_DDRA_BIT_4_MASK_CLR = %11101111
CIA_DDRA_BIT_5_MASK_CLR = %11011111
CIA_DDRA_BIT_6_MASK_CLR = %10111111
CIA_DDRA_BIT_7_MASK_CLR = %01111111

CIA_DDRA_BIT_0_MASK_INPUT = %00000000
CIA_DDRA_BIT_0_MASK_OUPUT = %00000001
CIA_DDRA_BIT_1_MASK_INPUT = %00000000
CIA_DDRA_BIT_1_MASK_OUPUT = %00000010
CIA_DDRA_BIT_2_MASK_INPUT = %00000000
CIA_DDRA_BIT_2_MASK_OUPUT = %00000100
CIA_DDRA_BIT_3_MASK_INPUT = %00000000
CIA_DDRA_BIT_3_MASK_OUPUT = %00001000
CIA_DDRA_BIT_4_MASK_INPUT = %00000000
CIA_DDRA_BIT_4_MASK_OUPUT = %00010000
CIA_DDRA_BIT_5_MASK_INPUT = %00000000
CIA_DDRA_BIT_5_MASK_OUPUT = %00100000
CIA_DDRA_BIT_6_MASK_INPUT = %00000000
CIA_DDRA_BIT_6_MASK_OUPUT = %01000000
CIA_DDRA_BIT_7_MASK_INPUT = %00000000
CIA_DDRA_BIT_7_MASK_OUPUT = %10000000

CIA_DDRB_BIT_0 = 0
CIA_DDRB_BIT_1 = 1
CIA_DDRB_BIT_2 = 2
CIA_DDRB_BIT_3 = 3
CIA_DDRB_BIT_4 = 4
CIA_DDRB_BIT_5 = 5
CIA_DDRB_BIT_6 = 6
CIA_DDRB_BIT_7 = 7

CIA_DDRB_BIT_0_MASK = %00000001
CIA_DDRB_BIT_1_MASK = %00000010
CIA_DDRB_BIT_2_MASK = %00000100
CIA_DDRB_BIT_3_MASK = %00001000
CIA_DDRB_BIT_4_MASK = %00010000
CIA_DDRB_BIT_5_MASK = %00100000
CIA_DDRB_BIT_6_MASK = %01000000
CIA_DDRB_BIT_7_MASK = %10000000

CIA_DDRB_BIT_0_MASK_CLR = %11111110
CIA_DDRB_BIT_1_MASK_CLR = %11111101
CIA_DDRB_BIT_2_MASK_CLR = %11111011
CIA_DDRB_BIT_3_MASK_CLR = %11110111
CIA_DDRB_BIT_4_MASK_CLR = %11101111
CIA_DDRB_BIT_5_MASK_CLR = %11011111
CIA_DDRB_BIT_6_MASK_CLR = %10111111
CIA_DDRB_BIT_7_MASK_CLR = %01111111

CIA_DDRB_BIT_0_MASK_INPUT = %00000000
CIA_DDRB_BIT_0_MASK_OUPUT = %00000001
CIA_DDRB_BIT_1_MASK_INPUT = %00000000
CIA_DDRB_BIT_1_MASK_OUPUT = %00000010
CIA_DDRB_BIT_2_MASK_INPUT = %00000000
CIA_DDRB_BIT_2_MASK_OUPUT = %00000100
CIA_DDRB_BIT_3_MASK_INPUT = %00000000
CIA_DDRB_BIT_3_MASK_OUPUT = %00001000
CIA_DDRB_BIT_4_MASK_INPUT = %00000000
CIA_DDRB_BIT_4_MASK_OUPUT = %00010000
CIA_DDRB_BIT_5_MASK_INPUT = %00000000
CIA_DDRB_BIT_5_MASK_OUPUT = %00100000
CIA_DDRB_BIT_6_MASK_INPUT = %00000000
CIA_DDRB_BIT_6_MASK_OUPUT = %01000000
CIA_DDRB_BIT_7_MASK_INPUT = %00000000
CIA_DDRB_BIT_7_MASK_OUPUT = %10000000

CIA_TOD_HR_HOURS_MASK       = %01111111
CIA_TOD_HR_HOURS_MASK_CLR   = %10000000
CIA_TOD_HR_AMPM_MASK        = %10000000
CIA_TOD_HR_AMPM_MASK_CLR    = %01111111
CIA_TOD_HR_AMPM_MASK_SET_AM = %00000000
CIA_TOD_HR_AMPM_MASK_SET_PM = %10000000

;; summary: Offset from AM to PM is 12 hours bcd (and v.v.)
CIA_TOD_HR_AMPM_OFFSET = $12

CIA_TOD_MIN_HR_24   = $00  ; bcd
CIA_TOD_MAX_HR_24   = $23  ; bcd
CIA_TOD_MIN_HR_AMPM = $01  ; bcd
CIA_TOD_MAX_HR_AMPM = $12  ; bcd
CIA_TOD_MIN_MIN     = $00  ; bcd
CIA_TOD_MAX_MIN     = $59  ; bcd
CIA_TOD_MIN_SEC     = $00  ; bcd
CIA_TOD_MAX_SEC     = $59  ; bcd
CIA_TOD_MIN_10THS   = $00  ; bcd
CIA_TOD_MAX_10THS   = $09  ; bcd

CIA_ICR_TIMER_A   = 0
CIA_ICR_TIMER_B   = 1
CIA_ICR_ALARM     = 2
CIA_ICR_SDR       = 3
CIA_ICR_FLAG      = 4
CIA_ICR_INTERRUPT = 7

CIA_ICR_TIMER_A_MASK   = %00000001
CIA_ICR_TIMER_A_CLR    = %11111110
CIA_ICR_TIMER_B_MASK   = %00000010
CIA_ICR_TIMER_B_CLR    = %11111101
CIA_ICR_ALARM_MASK     = %00000100
CIA_ICR_ALARM_CLR      = %11111011
CIA_ICR_SDR_MASK       = %00001000
CIA_ICR_SDR_CLR        = %11110111
CIA_ICR_FLAG_MASK      = %00010000
CIA_ICR_FLAG_CLR       = %11101111
CIA_ICR_INTERRUPT_MASK = %10000000
CIA_ICR_INTERRUPT_CLR  = %01111111

CIA_ICR_INTERRUPT_CLEAR_SOURCE = %00000000
CIA_ICR_INTERRUPT_SET_SOURCE   = %10000000
CIA_ICR_TIMER_A_ENABLE         = CIA_ICR_INTERRUPT_SET_SOURCE | CIA_ICR_TIMER_A_MASK
CIA_ICR_TIMER_A_DISABLE        = CIA_ICR_INTERRUPT_CLEAR_SOURCE | CIA_ICR_TIMER_A_MASK
CIA_ICR_TIMER_B_ENABLE         = CIA_ICR_INTERRUPT_SET_SOURCE | CIA_ICR_TIMER_B_MASK
CIA_ICR_TIMER_B_DISABLE        = CIA_ICR_INTERRUPT_CLEAR_SOURCE | CIA_ICR_TIMER_B_MASK
CIA_ICR_ALARM_ENABLE           = CIA_ICR_INTERRUPT_SET_SOURCE | CIA_ICR_ALARM_MASK
CIA_ICR_ALARM_DISABLE          = CIA_ICR_INTERRUPT_CLEAR_SOURCE | CIA_ICR_ALARM_MASK
CIA_ICR_SDR_ENABLE             = CIA_ICR_INTERRUPT_SET_SOURCE | CIA_ICR_SDR_MASK
CIA_ICR_SDR_DISABLE            = CIA_ICR_INTERRUPT_CLEAR_SOURCE | CIA_ICR_SDR_MASK
CIA_ICR_DISABLE_ALL            = CIA_ICR_INTERRUPT_CLEAR_SOURCE | CIA_ICR_TIMER_A_MASK | CIA_ICR_TIMER_B_MASK | CIA_ICR_ALARM_MASK | CIA_ICR_SDR_MASK

CIA_CRA_TIMER_A_START_STOP                   = 0
CIA_CRA_TIMER_A_UNDERFLOW_AT_PRB_BIT_6       = 1
CIA_CRA_TIMER_A_UNDERFLOW_PRB_BIT_6_BEHAVIOR = 2
CIA_CRA_TIMER_A_UNDERFLOW_RESTART            = 3
CIA_CRA_LOAD_LATCH_INTO_TIMER_ONCE           = 4
CIA_CRA_TIMER_A_COUNTS                       = 5
CIA_CRA_SDR_DIRECTION                        = 6
CIA_CRA_RTC_FREQUENCY                        = 7

CIA_CRA_TIMER_A_START_STOP_MASK  = %00000001
CIA_CRA_TIMER_A_START_STOP_CLR   = %11111110
CIA_CRA_TIMER_A_START_STOP_START = %00000001
CIA_CRA_TIMER_A_START_STOP_STOP  = %00000000

CIA_CRA_TIMER_A_UNDERFLOW_AT_PRB_BIT_6_MASK = %00000010
CIA_CRA_TIMER_A_UNDERFLOW_AT_PRB_BIT_6_CLR  = %11111101
CIA_CRA_TIMER_A_UNDERFLOW_AT_PRB_BIT_6_ON   = %00000010
CIA_CRA_TIMER_A_UNDERFLOW_AT_PRB_BIT_6_OFF  = %00000000

CIA_CRA_TIMER_A_UNDERFLOW_PRB_BIT_6_BEHAVIOR_MASK   = %00000100
CIA_CRA_TIMER_A_UNDERFLOW_PRB_BIT_6_BEHAVIOR_CLR    = %11111011
CIA_CRA_TIMER_A_UNDERFLOW_PRB_BIT_6_BEHAVIOR_CYCLE  = %00000000
CIA_CRA_TIMER_A_UNDERFLOW_PRB_BIT_6_BEHAVIOR_INVERT = %00000100

CIA_CRA_TIMER_A_UNDERFLOW_RESTART_MASK = %00001000
CIA_CRA_TIMER_A_UNDERFLOW_RESTART_CLR  = %11110111
CIA_CRA_TIMER_A_UNDERFLOW_RESTART_ON   = %00001000
CIA_CRA_TIMER_A_UNDERFLOW_RESTART_OFF  = %00000000

CIA_CRA_LOAD_LATCH_INTO_TIMER_ONCE_MASK =  %00010000
CIA_CRA_LOAD_LATCH_INTO_TIMER_ONCE_CLR  =  %11101111
CIA_CRA_LOAD_LATCH_INTO_TIMER_ONCE_ON   =  %00010000
CIA_CRA_LOAD_LATCH_INTO_TIMER_ONCE_OFF  =  %00000000

CIA_CRA_TIMER_A_COUNTS_MASK   = %00100000
CIA_CRA_TIMER_A_COUNTS_CLR    = %11011111
CIA_CRA_TIMER_A_COUNTS_CYCLES = %00000000
CIA_CRA_TIMER_A_COUNTS_CNT    = %00100000

CIA_CRA_SDR_DIRECTION_MASK   = %01000000
CIA_CRA_SDR_DIRECTION_CLR    = %10111111
CIA_CRA_SDR_DIRECTION_INPUT  = %00000000
CIA_CRA_SDR_DIRECTION_OUTPUT = %01000000

CIA_CRA_RTC_FREQUENCY_MASK = %10000000
CIA_CRA_RTC_FREQUENCY_CLR  = %01111111
CIA_CRA_RTC_FREQUENCY_60HZ = %00000000
CIA_CRA_RTC_FREQUENCY_50HZ = %10000000

CIA_CRB_TIMER_B_START_STOP                   = 0
CIA_CRB_TIMER_B_UNDERFLOW_AT_PRB_BIT_7       = 1
CIA_CRB_TIMER_B_UNDERFLOW_PRB_BIT_7_BEHAVIOR = 2
CIA_CRB_TIMER_B_UNDERFLOW_RESTART            = 3
CIA_CRB_LOAD_LATCH_INTO_TIMER_ONCE           = 4
CIA_CRB_TIMER_B_COUNTS_WHAT_BIT_0            = 5
CIA_CRB_TIMER_B_COUNTS_WHAT_BIT_1            = 6
CIA_CRB_WRITE_SELECT_TOD                     = 7

CIA_CRB_TIMER_B_START_STOP_MASK  = %00000001
CIA_CRB_TIMER_B_START_STOP_CLR   = %11111110
CIA_CRB_TIMER_B_START_STOP_START = %00000001
CIA_CRB_TIMER_B_START_STOP_STOP  = %00000000

CIA_CRB_TIMER_B_UNDERFLOW_AT_PRB_BIT_7_MASK = %00000010
CIA_CRB_TIMER_B_UNDERFLOW_AT_PRB_BIT_7_CLR  = %11111101
CIA_CRB_TIMER_B_UNDERFLOW_AT_PRB_BIT_7_ON   = %00000010
CIA_CRB_TIMER_B_UNDERFLOW_AT_PRB_BIT_7_OFF  = %00000000

CIA_CRB_TIMER_B_UNDERFLOW_PRB_BIT_7_BEHAVIOR_MASK   = %00000100
CIA_CRB_TIMER_B_UNDERFLOW_PRB_BIT_7_BEHAVIOR_CLR    = %11111011
CIA_CRB_TIMER_B_UNDERFLOW_PRB_BIT_7_BEHAVIOR_CYCLE  = %00000000
CIA_CRB_TIMER_B_UNDERFLOW_PRB_BIT_7_BEHAVIOR_INVERT = %00000100

CIA_CRB_TIMER_B_UNDERFLOW_RESTART_MASK = %00001000
CIA_CRB_TIMER_B_UNDERFLOW_RESTART_CLR  = %11110111
CIA_CRB_TIMER_B_UNDERFLOW_RESTART_ON   = %00001000
CIA_CRB_TIMER_B_UNDERFLOW_RESTART_OFF  = %00000000

CIA_CRB_LOAD_LATCH_INTO_TIMER_ONCE_MASK = %00010000
CIA_CRB_LOAD_LATCH_INTO_TIMER_ONCE_CLR  = %11101111
CIA_CRB_LOAD_LATCH_INTO_TIMER_ONCE_ON   = %00010000
CIA_CRB_LOAD_LATCH_INTO_TIMER_ONCE_OFF  = %00000000

CIA_CRB_TIMER_B_COUNTS_WHAT_MASK                          = %01100000
CIA_CRB_TIMER_B_COUNTS_WHAT_CLR                           = %10011111
CIA_CRB_TIMER_B_COUNTS_WHAT_CYCLES                        = %00000000
CIA_CRB_TIMER_B_COUNTS_WHAT_UNDERFLOW_TIMER_A             = %01000000
CIA_CRB_TIMER_B_COUNTS_WHAT_UNDERFLOW_TIMER_A_IF_CNT_HIGH = %01100000

CIA_CRB_WRITE_SELECT_TOD_MASK         = %10000000
CIA_CRB_WRITE_SELECT_TOD_CLR          = %01111111
CIA_CRB_WRITE_SELECT_TOD_SELECT_CLOCK = %00000000
CIA_CRB_WRITE_SELECT_TOD_SELECT_ALARM = %10000000
