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

.ifndef __C64_SID_IMPORT_INC__
    __C64_SID_IMPORT_INC__ = 1

.import SID_R00
.import SID_R01
.import SID_R02
.import SID_R03
.import SID_R04
.import SID_R05
.import SID_R06
.import SID_R07
.import SID_R08
.import SID_R09
.import SID_R0A
.import SID_R0B
.import SID_R0C
.import SID_R0D
.import SID_R0E
.import SID_R0F
.import SID_R10
.import SID_R11
.import SID_R12
.import SID_R13
.import SID_R14
.import SID_R15
.import SID_R16
.import SID_R17
.import SID_R18
.import SID_R19
.import SID_R1A
.import SID_R1B
.import SID_R1C

.import SID_FIRST
.import SID_LAST

.import SID_V1_FREQ_LO       ; voice 1 frequency low byte
.import SID_V1_FREQ_HI       ; voice 1 frequency high byte
.import SID_V1_PWDC_LO       ; voice 1 pulse wave duty cycle low byte
.import SID_V1_PWDC_HI       ; voice 1 0-3:pulse wave duty cycle high byte
.import SID_V1_CONTROL       ; voice 1 control register: 7:noise 6:pulse 5:sawtooth 4:triangle 3:test 2:ring modulation with voice 3 1:synchronize with voice 3 0:gate
.import SID_V1_ATT_DEC       ; voice 1 7-4:attack duration 3-0:decay duration
.import SID_V1_SUS_REL       ; voice 1 7-4:sustain level 3-0:release duration
.import SID_V2_FREQ_LO       ; voice 2 frequency low byte
.import SID_V2_FREQ_HI       ; voice 2 frequency high byte
.import SID_V2_PWDC_LO       ; voice 2 pulse wave duty cycle low byte
.import SID_V2_PWDC_HI       ; voice 2 3-0:pulse wave duty cycle high byte
.import SID_V2_CONTROL       ; voice 2 control register: 7:noise 6:pulse 5:sawtooth 4:triangle 3:test 2:ring modulation with voice 1 1:synchronize with voice 1 0:gate
.import SID_V2_ATT_DEC       ; voice 2 7-4:attack duration 3-0:decay duration
.import SID_V2_SUS_REL       ; voice 2 7-4:sustain level 3-0:release duration
.import SID_V3_FREQ_LO       ; voice 3 frequency low byte
.import SID_V3_FREQ_HI       ; voice 3 frequency high byte
.import SID_V3_PWDC_LO       ; voice 3 pulse wave duty cycle low byte
.import SID_V3_PWDC_HI       ; voice 3 3-0:pulse wave duty cycle high byte
.import SID_V3_CONTROL       ; voice 3 control register: 7:noise 6:pulse 5:sawtooth 4:triangle 3:test 2:ring modulation with voice 2 1:synchronize with voice 2 0:gate
.import SID_V3_ATT_DEC       ; voice 3 7-4:attack duration 3-0:decay duration
.import SID_V3_SUS_REL       ; voice 3 7-4:sustain level 3-0:release duration
.import SID_F_CUTOFF_FREQ_LO ; filter 3-0:cutoff frequency low byte
.import SID_F_CUTOFF_FREQ_HI ; filter cutoff frequency high byte
.import SID_F_RESN_ROUT      ; filter resonance and routing: 7-4:filter resonance 3:external input 2:voice 3 1:voice 2 0:voice 1
.import SID_F_MODE_MAIN_VOL  ; filter mode and main volume control: 7:mute voice 3 6:high pass 5:band pass 4:low pass 3-0:main volume
.import SID_PADDLE_X_READ    ; paddle x value (read only)
.import SID_PADDLE_Y_READ    ; paddle y value (read only)
.import SID_V3_OSC_READ      ; oscillator voice 3 (read only)
.import SID_V3_ENV_READ      ; envelope voice 3 (read only)

.endif
