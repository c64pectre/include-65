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
