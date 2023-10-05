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

.include "../../a65/cia.inc"

.export CIA_2_REGISTER_BASE := $DD00

.export CIA_2_PRA       := CIA_2_REGISTER_BASE + CIA_PRA
.export CIA_2_PRB       := CIA_2_REGISTER_BASE + CIA_PRB
.export CIA_2_DDRA      := CIA_2_REGISTER_BASE + CIA_DDRA
.export CIA_2_DDRB      := CIA_2_REGISTER_BASE + CIA_DDRB
.export CIA_2_TA_LO     := CIA_2_REGISTER_BASE + CIA_TA_LO
.export CIA_2_TA_HI     := CIA_2_REGISTER_BASE + CIA_TA_HI
.export CIA_2_TB_LO     := CIA_2_REGISTER_BASE + CIA_TB_LO
.export CIA_2_TB_HI     := CIA_2_REGISTER_BASE + CIA_TB_HI
.export CIA_2_TOD       := CIA_2_REGISTER_BASE + CIA_TOD
.export CIA_2_TOD_10THS := CIA_2_REGISTER_BASE + CIA_TOD_10THS
.export CIA_2_TOD_SEC   := CIA_2_REGISTER_BASE + CIA_TOD_SEC
.export CIA_2_TOD_MIN   := CIA_2_REGISTER_BASE + CIA_TOD_MIN
.export CIA_2_TOD_HR    := CIA_2_REGISTER_BASE + CIA_TOD_HR
.export CIA_2_SDR       := CIA_2_REGISTER_BASE + CIA_SDR
.export CIA_2_ICR       := CIA_2_REGISTER_BASE + CIA_ICR
.export CIA_2_CRA       := CIA_2_REGISTER_BASE + CIA_CRA
.export CIA_2_CRB       := CIA_2_REGISTER_BASE + CIA_CRB

.export CIA_2_PRB_USERPORT_CDEFHJKL := CIA_2_PRB
