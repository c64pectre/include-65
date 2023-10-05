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

.export CIA_1_REGISTER_BASE := $DC00

.export CIA_1_PRA       := CIA_1_REGISTER_BASE + CIA_PRA
.export CIA_1_PRB       := CIA_1_REGISTER_BASE + CIA_PRB
.export CIA_1_DDRA      := CIA_1_REGISTER_BASE + CIA_DDRA
.export CIA_1_DDRB      := CIA_1_REGISTER_BASE + CIA_DDRB
.export CIA_1_TA_LO     := CIA_1_REGISTER_BASE + CIA_TA_LO
.export CIA_1_TA_HI     := CIA_1_REGISTER_BASE + CIA_TA_HI
.export CIA_1_TB_LO     := CIA_1_REGISTER_BASE + CIA_TB_LO
.export CIA_1_TB_HI     := CIA_1_REGISTER_BASE + CIA_TB_HI
.export CIA_1_TOD       := CIA_1_REGISTER_BASE + CIA_TOD
.export CIA_1_TOD_10THS := CIA_1_REGISTER_BASE + CIA_TOD_10THS
.export CIA_1_TOD_SEC   := CIA_1_REGISTER_BASE + CIA_TOD_SEC
.export CIA_1_TOD_MIN   := CIA_1_REGISTER_BASE + CIA_TOD_MIN
.export CIA_1_TOD_HR    := CIA_1_REGISTER_BASE + CIA_TOD_HR
.export CIA_1_SDR       := CIA_1_REGISTER_BASE + CIA_SDR
.export CIA_1_ICR       := CIA_1_REGISTER_BASE + CIA_ICR
.export CIA_1_CRA       := CIA_1_REGISTER_BASE + CIA_CRA
.export CIA_1_CRB       := CIA_1_REGISTER_BASE + CIA_CRB

.export CIA_1_KEYBOARD_COLUMNS := CIA_1_PRA
.export CIA_1_KEYBOARD_ROWS    := CIA_1_PRB

