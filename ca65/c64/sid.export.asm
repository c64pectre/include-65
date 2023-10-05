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

.export SID_REGISTER_BASE := $D400

.export SID_R00   := SID_REGISTER_BASE + $00
.export SID_R01   := SID_REGISTER_BASE + $01
.export SID_R02   := SID_REGISTER_BASE + $02
.export SID_R03   := SID_REGISTER_BASE + $03
.export SID_R04   := SID_REGISTER_BASE + $04
.export SID_R05   := SID_REGISTER_BASE + $05
.export SID_R06   := SID_REGISTER_BASE + $06
.export SID_R07   := SID_REGISTER_BASE + $07
.export SID_R08   := SID_REGISTER_BASE + $08
.export SID_R09   := SID_REGISTER_BASE + $09
.export SID_R0A   := SID_REGISTER_BASE + $0A
.export SID_R0B   := SID_REGISTER_BASE + $0B
.export SID_R0C   := SID_REGISTER_BASE + $0C
.export SID_R0D   := SID_REGISTER_BASE + $0D
.export SID_R0E   := SID_REGISTER_BASE + $0E
.export SID_R0F   := SID_REGISTER_BASE + $0F
.export SID_R10   := SID_REGISTER_BASE + $10
.export SID_R11   := SID_REGISTER_BASE + $11
.export SID_R12   := SID_REGISTER_BASE + $12
.export SID_R13   := SID_REGISTER_BASE + $13
.export SID_R14   := SID_REGISTER_BASE + $14
.export SID_R15   := SID_REGISTER_BASE + $15
.export SID_R16   := SID_REGISTER_BASE + $16
.export SID_R17   := SID_REGISTER_BASE + $17
.export SID_R18   := SID_REGISTER_BASE + $18
.export SID_R19   := SID_REGISTER_BASE + $19
.export SID_R1A   := SID_REGISTER_BASE + $1A
.export SID_R1B   := SID_REGISTER_BASE + $1B
.export SID_R1C   := SID_REGISTER_BASE + $1C

.export SID_FIRST := SID_R00
.export SID_LAST  := SID_R1C

.export SID_V1_FREQ_LO       := SID_R00
.export SID_V1_FREQ_HI       := SID_R01
.export SID_V1_PWDC_LO       := SID_R02
.export SID_V1_PWDC_HI       := SID_R03
.export SID_V1_CONTROL       := SID_R04
.export SID_V1_ATT_DEC       := SID_R05
.export SID_V1_SUS_REL       := SID_R06
.export SID_V2_FREQ_LO       := SID_R07
.export SID_V2_FREQ_HI       := SID_R08
.export SID_V2_PWDC_LO       := SID_R09
.export SID_V2_PWDC_HI       := SID_R0A
.export SID_V2_CONTROL       := SID_R0B
.export SID_V2_ATT_DEC       := SID_R0C
.export SID_V2_SUS_REL       := SID_R0D
.export SID_V3_FREQ_LO       := SID_R0E
.export SID_V3_FREQ_HI       := SID_R0F
.export SID_V3_PWDC_LO       := SID_R10
.export SID_V3_PWDC_HI       := SID_R11
.export SID_V3_CONTROL       := SID_R12
.export SID_V3_ATT_DEC       := SID_R13
.export SID_V3_SUS_REL       := SID_R14
.export SID_F_CUTOFF_FREQ_LO := SID_R15
.export SID_F_CUTOFF_FREQ_HI := SID_R16
.export SID_F_RESN_ROUT      := SID_R17
.export SID_F_MODE_MAIN_VOL  := SID_R18
.export SID_PADDLE_X_READ    := SID_R19
.export SID_PADDLE_Y_READ    := SID_R1A
.export SID_V3_OSC_READ      := SID_R1B
.export SID_V3_ENV_READ      := SID_R1C
