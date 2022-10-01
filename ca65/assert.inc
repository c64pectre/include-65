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

.ifndef __ASSERT_INC__
  __ASSERT_INC__ = 1

; ==============================================================================
; Assertions
; ==============================================================================

;;; summary: Border color on assert fail
.define ASSERT_FAIL_COLOR COLOR_RED

;;; summary: Assert that A equals value
__begin_macro ASSERT_A_EQ value
  __begin_scope
      php
      cmp # < value
      beq ok
    fail:
      pha
      lda # ASSERT_FAIL_COLOR
      sta VIC_EC
    hang:
      bne hang
    ok:
      plp
  __end_scope
__end_macro

;;; summary: Assert that target word equals value
__begin_macro ASSERT_EQ_W target, value
  __begin_scope
      php
      pha
      lda target
      cmp # < value
      beq lo_ok
    fail:
      lda # ASSERT_FAIL_COLOR
      sta VIC_EC
    hang:
      bne hang
    lo_ok:
      lda target + 1
      cmp # > value
      bne fail
      pla
      plp
  __end_scope
__end_macro

;;; summary: Assert that Carry is Clear
__begin_macro ASSERT_CC
  __begin_scope
      bcc ok
    fail:
      pha
      lda # ASSERT_FAIL_COLOR
      sta VIC_EC
    hang:
      bne hang
    ok:
  __end_scope
__end_macro

.endif
