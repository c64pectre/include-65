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

.ifndef __CEDECL_INC__
    __CEDECL_INC__ = 1

; ==============================================================================
; Frames for cedecl: CalleE removes parameters from stack
; ==============================================================================

;;; summary: Begin frame
;;; changed: X=RSP=FP Y=FSP N+ Z0
;;; bytes: 12
;;; cycles: 21
;;; notes:
;;;   ; hi
;;;   ; [FP   ][fp0 ] ------+
;;;   ; [FSP  ][fsp0] --+   |
;;;   ;                 |   |
;;;   ; [FS   ][ ?  ]   |   |
;;;   ; [...  ][    ]   |   |
;;;   ; [fsp0 ][ ?  ] <-+   | <-- FSP
;;;   ; [...  ][    ]       |
;;;   ; [rsp0 ][ ?  ] <-+   | <-- RSP
;;;   ; [...  ][    ]   |   |
;;;   ; [fp0  ][ ?  ]   | <-+ <-- FP
;;;   ; [...  ][    ]   |
;;;   ; [RS   ][ ?  ]   |
;;;   ;                 |
;;;   ; [RSP  ][rsp0] --+
;;;   ; lo
;;;   ldx FP   ; X = fp0          , P:N+Z+  ; 2/3
;;;   ldy FSP  ; Y = fsp0         , P:N+Z+  ; 2/3
;;;   stx 0,y  ; [fsp0] = fp0               ; 2/4
;;;   dec FSP  ; [FSP] = fsp0 - 1 , P:N+Z+  ; 2/5
;;;   ldx RSP  ; X = rsp0         , P:N+Z+  ; 2/3
;;;   stx FP   ; [FP] = rsp0                ; 2/3
;;;   ; hi
;;;   ; [FP    ][rsp0  ] ------+
;;;   ; [FSP   ][fsp0-1] --+   |
;;;   ;                    |   |
;;;   ; [FS    ][ ?    ]   |   |
;;;   ; [...   ][      ]   |   |
;;;   ; [fsp0  ][fp0   ]   |   | <-- Y
;;;   ; [fsp0-1][ ?    ] <-+   | <-- FSP
;;;   ; [...   ][      ]       |
;;;   ; [rsp0  ][ ?    ] <-+ <-+ <-- FP RSP X
;;;   ; [...   ][      ]   |
;;;   ; [fp0   ][ ?    ]   |
;;;   ; [...   ][      ]   |
;;;   ; [RS    ][ ?    ]   |
;;;   ;                    |
;;;   ; [RSP   ][rsp0  ] --+
;;;   ; lo
.macro __begin_cedecl_frame
    ldx FP
    ldy FSP
    stx 0 , y
    dec FSP
    ldx RSP
    stx FP
.endmacro

;;; summary: End frame
;;; result: 
;;; changed: X=FP=RSP Y=FSP N+ Z0
;;; bytes: 10
;;; cycles: 18
;;; notes:
;;;   ; hi
;;;   ; [FP    ][rsp0  ] ------+
;;;   ; [FSP   ][fsp0-1] --+   |
;;;   ;                    |   |
;;;   ; [FS    ][?     ]   |   |
;;;   ; [...   ][      ]   |   |
;;;   ; [fsp0  ][fp0   ]   |   |
;;;   ; [fsp0-1][?     ] <-+   | <-- FSP
;;;   ; [...   ][      ]       |
;;;   ; [rsp1  ][?     ] <-+   | <-- RSP
;;;   ; [...   ][      ]   |   |
;;;   ; [rsp0  ][?     ]   | <-+ <-- FP
;;;   ; [...   ][      ]   |
;;;   ; [fp0   ][?     ]   |
;;;   ; [...   ][      ]   |
;;;   ; [RS    ][?     ]   |
;;;   ;                    |
;;;   ; [RSP   ][rsp1  ] --+
;;;   ; lo
;;;   inc FSP  ; [FSP] = fsp0 , P:N+Z+  ; 2/5
;;;   ldy FSP  ; Y = fsp0     , P:N+Z+  ; 2/3
;;;   ldx 0,y  ; X = fp0      , P:N+Z+  ; 2/4
;;;   stx FP   ; [FP] = fp0             ; 2/3
;;;   stx RSP  ; [RSP] = fp0            ; 2/3
;;;   ; hi
;;;   ; [FP ][fp0 ] ------+
;;;   ; [FSP][fsp0] --+   |
;;;   ;               |   |
;;;   ; [FS ][ ?  ]   |   |
;;;   ; [...][    ]   |   |
;;;   ; [fsp][ ?  ] <-+   | <-- FSP Y
;;;   ; [...][    ]       |
;;;   ; [rsp][ ?  ]       |
;;;   ; [...][    ]       |
;;;   ; [fp0][ ?  ] <-+ <-+ <-- FP RSP X
;;;   ; [...][    ]   |
;;;   ; [RS ][ ?  ]   |
;;;   ;               |
;;;   ; [RSP][fp0 ] --+
;;;   ; lo
.macro __end_cedecl_frame
    inc FSP                             ;N+ Z+
    ldy FSP                             ;Y+ N+ Z+
    ldx 0 , y                           ;X+ N+ Z+
    stx FP
    stx RSP
    ; check Z=0
.endmacro

.endif
