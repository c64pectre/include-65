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

.export CPU_VECTOR_NMI    := $FFFA
.export CPU_VECTOR_NMI_LO := CPU_VECTOR_NMI + 0
.export CPU_VECTOR_NMI_HI := CPU_VECTOR_NMI + 1

.export CPU_VECTOR_RES    := $FFFC
.export CPU_VECTOR_RES_LO := CPU_VECTOR_RES + 0
.export CPU_VECTOR_RES_HI := CPU_VECTOR_RES + 1

.export CPU_VECTOR_IRQ    := $FFFE
.export CPU_VECTOR_IRQ_LO := CPU_VECTOR_IRQ + 0
.export CPU_VECTOR_IRQ_HI := CPU_VECTOR_IRQ + 1
