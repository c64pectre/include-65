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

.ifndef __STRUCTURED_PROGRAMMING_INC__
    __STRUCTURED_PROGRAMMING_INC__ = 1

;;; summary: if-then-end or if-then-else-end construct with optional scope name
.macro if scope
    .scope scope
    _if:
.endmacro

.macro then
    _then:
.endmacro

.macro else
    _else:
.endmacro

.macro end
    _end:
    .endscope
.endmacro

.macro if_then scope
    .scope scope
    _if:
    _then:
.endmacro

.macro else_end
    _else:
    _end:
    .endscope
.endmacro

.macro if_eq_then scope
    .scope scope
    _if:
        bne _else
    _then:
.endmacro

.macro if_ne_then scope
    .scope scope
    _if:
        beq _else
    _then:
.endmacro

.macro if_cc_then scope
    .scope scope
    _if:
        bcs _else
    _then:
.endmacro

.macro if_cs_then scope
    .scope scope
    _if:
        bcc _else
    _then:
.endmacro

.macro if_vc_then scope
    .scope scope
    _if:
        bvs _else
    _then:
.endmacro

.macro if_vs_then scope
    .scope scope
    _if:
        bvc _else
    _then:
.endmacro

.macro if_pl_then scope
    .scope scope
    _if:
        bmi _else
    _then:
.endmacro

.macro if_mi_then scope
    .scope scope
    _if:
        bpl _else
    _then:
.endmacro

.macro if_lt_then scope
    .scope scope
    _if:
        bcs _else
    _then:
.endmacro

.macro if_ge_then scope
    .scope scope
    _if:
        bcc _else
    _then:
.endmacro

;;; summary: from-loop-next-end construct with optional scope name
.macro from scope
    .scope scope
    _from:
.endmacro

.macro loop
    _loop:
.endmacro

.macro from_loop scope
    .scope scope
    _from:
    _loop:
.endmacro

.macro next
    _next:
.endmacro

.macro from_loop_next scope
    .scope scope
    _from:
    _loop:
    _next:
.endmacro

.macro loop_next
    _loop:
    _next:
.endmacro

;;; summary: switch-case-end
.macro switch scope
    .scope scope
    _switch:
.endmacro

.macro case label
    label:
.endmacro

.macro default
    _default:
.endmacro

.macro try scope
    .scope scope
    _try:
.endmacro

.macro catch
    _catch:
.endmacro

.macro finally
    _finally:
.endmacro

.macro finally_end
    _finally:
    _end:
    .endscope
.endmacro

.macro catch_finally_end
    _catch:
    _finally:
    _end:
    .endscope
.endmacro

.endif
