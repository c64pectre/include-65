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

.ifndef __C64_CIA_2_IMPORT_INC__
    __C64_CIA_2_IMPORT_INC__ = 1

.import CIA_2_REGISTER_BASE

.import CIA_2_PRA
.import CIA_2_PRB
.import CIA_2_DDRA
.import CIA_2_DDRB
.import CIA_2_TA_LO
.import CIA_2_TA_HI
.import CIA_2_TB_LO
.import CIA_2_TB_HI
.import CIA_2_TOD
.import CIA_2_TOD_10THS
.import CIA_2_TOD_SEC
.import CIA_2_TOD_MIN
.import CIA_2_TOD_HR
.import CIA_2_SDR
.import CIA_2_ICR
.import CIA_2_CRA
.import CIA_2_CRB

.import CIA_2_PRB_USERPORT_CDEFHJKL

.endif
