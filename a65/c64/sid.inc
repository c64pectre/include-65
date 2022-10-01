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

;;; summary: SID

SID_R00   = SID + $00
SID_R01   = SID + $01
SID_R02   = SID + $02
SID_R03   = SID + $03
SID_R04   = SID + $04
SID_R05   = SID + $05
SID_R06   = SID + $06
SID_R07   = SID + $07
SID_R08   = SID + $08
SID_R09   = SID + $09
SID_R0A   = SID + $0A
SID_R0B   = SID + $0B
SID_R0C   = SID + $0C
SID_R0D   = SID + $0D
SID_R0E   = SID + $0E
SID_R0F   = SID + $0F
SID_R10   = SID + $10
SID_R11   = SID + $11
SID_R12   = SID + $12
SID_R13   = SID + $13
SID_R14   = SID + $14
SID_R15   = SID + $15
SID_R16   = SID + $16
SID_R17   = SID + $17
SID_R18   = SID + $18
SID_R19   = SID + $19
SID_R1A   = SID + $1A
SID_R1B   = SID + $1B
SID_R1C   = SID + $1C
SID_FIRST = SID_R00
SID_LAST  = SID_R1C

SID_V1_FREQ_LO       = SID_R00 ; voice 1 frequency low byte
SID_V1_FREQ_HI       = SID_R01 ; voice 1 frequency high byte
SID_V1_PWDC_LO       = SID_R02 ; voice 1 pulse wave duty cycle low byte
SID_V1_PWDC_HI       = SID_R03 ; voice 1 0-3:pulse wave duty cycle high byte
SID_V1_CONTROL       = SID_R04 ; voice 1 control register: 7:noise 6:pulse 5:sawtooth 4:triangle 3:test 2:ring modulation with voice 3 1:synchronize with voice 3 0:gate
SID_V1_ATT_DEC       = SID_R05 ; voice 1 7-4:attack duration 3-0:decay duration
SID_V1_SUS_REL       = SID_R06 ; voice 1 7-4:sustain level 3-0:release duration
SID_V2_FREQ_LO       = SID_R07 ; voice 2 frequency low byte
SID_V2_FREQ_HI       = SID_R08 ; voice 2 frequency high byte
SID_V2_PWDC_LO       = SID_R09 ; voice 2 pulse wave duty cycle low byte
SID_V2_PWDC_HI       = SID_R0A ; voice 2 3-0:pulse wave duty cycle high byte
SID_V2_CONTROL       = SID_R0B ; voice 2 control register: 7:noise 6:pulse 5:sawtooth 4:triangle 3:test 2:ring modulation with voice 1 1:synchronize with voice 1 0:gate
SID_V2_ATT_DEC       = SID_R0C ; voice 2 7-4:attack duration 3-0:decay duration
SID_V2_SUS_REL       = SID_R0D ; voice 2 7-4:sustain level 3-0:release duration
SID_V3_FREQ_LO       = SID_R0E ; voice 3 frequency low byte
SID_V3_FREQ_HI       = SID_R0F ; voice 3 frequency high byte
SID_V3_PWDC_LO       = SID_R10 ; voice 3 pulse wave duty cycle low byte
SID_V3_PWDC_HI       = SID_R11 ; voice 3 3-0:pulse wave duty cycle high byte
SID_V3_CONTROL       = SID_R12 ; voice 3 control register: 7:noise 6:pulse 5:sawtooth 4:triangle 3:test 2:ring modulation with voice 2 1:synchronize with voice 2 0:gate
SID_V3_ATT_DEC       = SID_R13 ; voice 3 7-4:attack duration 3-0:decay duration
SID_V3_SUS_REL       = SID_R14 ; voice 3 7-4:sustain level 3-0:release duration
SID_F_CUTOFF_FREQ_LO = SID_R15 ; filter 3-0:cutoff frequency low byte
SID_F_CUTOFF_FREQ_HI = SID_R16 ; filter cutoff frequency high byte
SID_F_RESN_ROUT      = SID_R17 ; filter resonance and routing: 7-4:filter resonance 3:external input 2:voice 3 1:voice 2 0:voice 1
SID_F_MODE_MAIN_VOL  = SID_R18 ; filter mode and main volume control: 7:mute voice 3 6:high pass 5:band pass 4:low pass 3-0:main volume
SID_PADDLE_X_READ    = SID_R19 ; paddle x value (read only)
SID_PADDLE_Y_READ    = SID_R1A ; paddle y value (read only)
SID_V3_OSC_READ      = SID_R1B ; oscillator voice 3 (read only)
SID_V3_ENV_READ      = SID_R1C ; envelope voice 3 (read only)

; For SID_PADDLE_[X|Y]_READ

;;; summary: Paddle [X|Y] not present
SID_PADDLE_NOT_PRESENT = $FF

;;; summary: Minimum SID_PADDLE_[X|Y]_READ value
SID_PADDLE_MIN         = $40

;;; summary: Maximum SID_PADDLE_[X|Y]_READ value
SID_PADDLE_MAX         = $BF

;;; summary: SID_PADDLE_[X|Y]_READ value cycle.
;;; notes: (new SID_PADDLE_X_READ - old SID_PADDLE_X_READ) is a group with cycle $80.
SID_PADLE_CYCLE_BITS         = 7
SID_PADLE_CYCLE              = 1 << SID_PADLE_CYCLE_BITS
SID_PADLE_HALF_CYCLE_BITS    = SID_PADLE_CYCLE_BITS - 1
SID_PADLE_HALF_CYCLE         = 1 << SID_PADLE_HALF_CYCLE_BITS
SID_PADLE_MOD_HALF_CYCLE     = SID_PADLE_HALF_CYCLE - 1
SID_PADLE_NEG_MOD_HALF_CYCLE = < ~ SID_PADLE_MOD_HALF_CYCLE
