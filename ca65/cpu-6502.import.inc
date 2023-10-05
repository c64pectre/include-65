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

.ifndef __CPU_6502_IMPORT_INC__
    __CPU_6502_IMPORT_INC__ = 1

.import CPU_VECTOR_NMI
.import CPU_VECTOR_NMI_LO
.import CPU_VECTOR_NMI_HI

.import CPU_VECTOR_RES
.import CPU_VECTOR_RES_LO
.import CPU_VECTOR_RES_HI

.import CPU_VECTOR_IRQ
.import CPU_VECTOR_IRQ_LO
.import CPU_VECTOR_IRQ_HI

.endif
