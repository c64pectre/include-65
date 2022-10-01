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

.ifndef __CRDECL_INC__
    __CRDECL_INC__ = 1

; ==============================================================================
; // Frames for __cdecl_cr: CalleR removes parameters from stack
; ==============================================================================

;;; summary: Begin frame
;;; result: X = [RSP] = [FP] , Y = [FSP]
;;; changed: P.N=+, P.Z=0
;;; bytes: 12
;;; cycles: 21
;;; notes:
;;;   Same as __begin_cedecl_frame
.macro __begin_crdecl_frame
    ldx z:FP
    ldy z:FSP
    stx z:0 , y
    dec z:FSP
    ldx z:RSP
    stx z:FP
.endmacro

;;; summary: End frame
;;; result: X = [FP], Y = [FSP]
;;; changed: P.N=+, P.Z=0
;;; bytes: 12
;;; cycles: 21
;;; notes:
;;; [RSP  ][rsp1 ] --+
;;; [     ][     ]   |
;;; [RS   ][?    ]   |
;;; [...  ][     ]   |
;;; [fp0  ][?    ]   |
;;; [...  ][     ]   |
;;; [rsp0 ][?    ]   | <-+ <-- FP
;;; [...  ][?    ]   |   |
;;; [rsp1 ][?    ] <-+   | <-- RSP
;;; [...  ][     ]       |
;;; [fsp-1][?    ] <-+   | <-- FSP
;;; [fsp  ][fp0  ]   |   |
;;; [...  ][     ]   |   |
;;; [FS   ][?    ]   |   |
;;; [     ][     ]   |   |
;;; [FSP  ][fsp-1] --+   |
;;; [FP   ][rsp0 ] ------+
;;; ldx FP   ; X = rsp0      P:N+Z+  ; 2/3
;;; stx RSP  ; [RSP] = rsp0          ; 2/3
;;; inc FSP  ; [FSP] = fsp0  P:N+Z+  ; 2/5
;;; ldy FSP  ; Y = fp0       P:N+Z+  ; 2/3
;;; ldx 0,y  ; X = fp0       P:N+Z+  ; 2/4
;;; stx FP   ; [FP] = fp0            ; 2/3
;;; |RSP|[rsp] --+
;;; |   |[   ]   |
;;; |RS |[ ? ]   |
;;; |...|[   ]   |
;;; |fp |[ ? ]   | <-+ <- FP X
;;; |...|[   ]   |   |
;;; |rsp|[ ? ] <-+   | <- RSP
;;; |...|[   ]       |
;;; |fsp|[ ? ] <-+   | <- FSP Y
;;; |...|[   ]   |   |
;;; |FS |[ ? ]   |   |
;;; |   |[   ]   |   |
;;; |FSP|[fsp] --+   |
;;; |FP |[fp ] ------+
.macro __end_crdecl_frame
    ldx z:FP
    stx z:RSP
    inc z:FSP
    ldy z:FSP
    ldx z:0 , y
    stx z:FP
.endmacro

.endif
