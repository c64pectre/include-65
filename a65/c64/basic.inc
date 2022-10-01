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

;;; summary: Constants for C64 Basic

; Constants - addresses

BASIC_LOAD_ADDRESS = $0801

BASIC_NEXT_LINE_END_MARKER = $0000

; Constants - tokens
BASIC_TOKEN_EOL          = $00
BASIC_TOKEN_END          = $80
BASIC_TOKEN_FOR          = $81
BASIC_TOKEN_NEXT         = $82
BASIC_TOKEN_DATA         = $83
BASIC_TOKEN_INPUT_HASH   = $84
BASIC_TOKEN_INPUT        = $85
BASIC_TOKEN_DIM          = $86
BASIC_TOKEN_READ         = $87
BASIC_TOKEN_LET          = $88
BASIC_TOKEN_GOTO         = $89
BASIC_TOKEN_RUN          = $8A
BASIC_TOKEN_IF           = $8B
BASIC_TOKEN_RESTORE      = $8C
BASIC_TOKEN_GOSUB        = $8D
BASIC_TOKEN_RETURN       = $8E
BASIC_TOKEN_REM          = $8F
BASIC_TOKEN_STOP         = $90
BASIC_TOKEN_ON           = $91
BASIC_TOKEN_WAIT         = $92
BASIC_TOKEN_LOAD         = $93
BASIC_TOKEN_SAVE         = $94
BASIC_TOKEN_VERIFY       = $95
BASIC_TOKEN_DEF          = $96
BASIC_TOKEN_POKE         = $97
BASIC_TOKEN_PRINT_HASH   = $98
BASIC_TOKEN_PRINT        = $99
BASIC_TOKEN_CONT         = $9A
BASIC_TOKEN_LIST         = $9B
BASIC_TOKEN_CLR          = $9C
BASIC_TOKEN_CMD          = $9D
BASIC_TOKEN_SYS          = $9E
BASIC_TOKEN_OPEN         = $9F
BASIC_TOKEN_CLOSE        = $A0
BASIC_TOKEN_GET          = $A1
BASIC_TOKEN_NEW          = $A2
BASIC_TOKEN_TAB          = $A3
BASIC_TOKEN_TO           = $A4
BASIC_TOKEN_FN           = $A5
BASIC_TOKEN_SPC          = $A6
BASIC_TOKEN_THEN         = $A7
BASIC_TOKEN_NOT          = $A8
BASIC_TOKEN_STEP         = $A9
BASIC_TOKEN_ADD          = $AA
BASIC_TOKEN_SUBTRACT     = $AB
BASIC_TOKEN_MULTIPLY     = $AC
BASIC_TOKEN_DIVIDE       = $AD
BASIC_TOKEN_EXPONENTIATE = $AE
BASIC_TOKEN_AND          = $AF
BASIC_TOKEN_OR           = $B0
BASIC_TOKEN_GREATER_THAN = $B1
BASIC_TOKEN_EQUALS       = $B2
BASIC_TOKEN_LESS_THAN    = $B3
BASIC_TOKEN_SGN          = $B4
BASIC_TOKEN_INT          = $B5
BASIC_TOKEN_ABS          = $B6
BASIC_TOKEN_USR          = $B7
BASIC_TOKEN_FRE          = $B8
BASIC_TOKEN_POS          = $B9
BASIC_TOKEN_SQR          = $BA
BASIC_TOKEN_RND          = $BB
BASIC_TOKEN_LOG          = $BC
BASIC_TOKEN_EXP          = $BD
BASIC_TOKEN_COS          = $BE
BASIC_TOKEN_SIN          = $BF
BASIC_TOKEN_TAN          = $C0
BASIC_TOKEN_ATN          = $C1
BASIC_TOKEN_PEEK         = $C2
BASIC_TOKEN_LEN          = $C3
BASIC_TOKEN_STR          = $C4
BASIC_TOKEN_VAL          = $C5
BASIC_TOKEN_ASC          = $C6
BASIC_TOKEN_CHR          = $C7
BASIC_TOKEN_LEFT         = $C8
BASIC_TOKEN_RIGHT        = $C9
BASIC_TOKEN_MID          = $CA
