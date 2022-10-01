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

MOD_LIB_ID_FIRST = $00
MOD_LIB_ID_LAST  = $7F
MOD_LIB_ID_RESERVED_FOR_SYS_00 = $00
MOD_APP_ID_FIRST = $80
MOD_APP_ID_LAST  = $FF

MOD_HEADER_OFFSET_TYPE = $00
  MOD_HEADER_TYPE_LIB = $01
  MOD_HEADER_TYPE_APP = $02

MOD_HEADER_OFFSET_ID = $01

MOD_HEADER_OFFSET_ENTRY_COUNT = $02

MOD_HEADER_OFFSET_ENTRY_TABLE = $03
