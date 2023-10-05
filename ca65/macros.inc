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

.ifndef __MACROS_INC__
    __MACROS_INC__ = 1

; ==============================================================================
; Macros
;
; notes:
;   You need to include registers.inc, or declare the AX-DX registers.
;
;   When below you see:
;     lda 0 + (M)
;   this is done to prevent an "Illegal addressing mode" assemble error when a
;   parameter is surrounded with parentheses in the macro body, or if the macro is
;   called with an actual parameter surrounded with parentheses.
;   We surround the parameter in the macro body with paranthesis to prevent
;   bugs caused by operator precendences.
;
;   Do NOT use .scope ... .endscope in macros because this messes up the
;   recognition of zeropage addressing. E.g. incw AX yields absolute addressing
;   even though AX is explicitly declared (.zpexport) as zeropage. Instead,
;   use unnamed labels or .local.
; ==============================================================================

.include "cpu-6502.inc"                 ; for phi, pli
.include "opcodes.inc"

; ==============================================================================
; Frames with CE and CR calling convention
;
; Using the macros from above, you can write nice code like this:
;
;   .proc MY_FUNCTION
;       __begin_cedecl_frame
;       ...
;       __end_cedecl_frame
;       rts
;    .endproc
;
; Now MY_FUNCTION uses the cedecl calling convention, and has a scope because of
; .proc
; ==============================================================================

.include "cedecl.inc"
.include "crdecl.inc"

.include "ce_decl.inc"

.macro INIT_FRAME_AND_REGISTERS
    lda # 0          ; A = 0
    tay              ; Y = 0
    ldx # REGISTERS_SIZEOF - 1          ; X = 7
    loop_do:
        sta REGISTERS_BASE , x          ; [REGISTERS_BASE + X] = 0
        dex                             ; X--
        bpl loop_do                     ; X >= 0 ?
    loop_end:
    ;
    ldx # FS                            ; X = FS
    stx FSP                             ; [FSP] = FS
    ldx # RS                            ; X = RS
    stx RSP                             ; [RSP] = RS = X
    stx FP                              ; [FP] = RS = X
    ; AX = BX = CX = DX = A = Y = 0 ; X = RSP = FP
.endmacro

; ==============================================================================
; Synthetic instuctions - Bit manipulation
; ==============================================================================

;;; summary: Bit 7 of A to Carry
;;; result: C = A.7
;;; bytes: 2
;;; cycles: 2
.macro a7c
    cmp # %10000000
.endmacro

;;; summary: Bit 7 of X to Carry
;;; result: C = X.7
;;; bytes: 2
;;; cycles: 2
.macro x7c
    cpx # %10000000
.endmacro

;;; summary: Bit 7 of Y to Carry
;;; result: C = Y.7
;;; bytes: 2
;;; cycles: 2
.macro y7c
    cpy # %10000000
.endmacro

;;; summary: Rotate Straight Left A  8-bit rotate left
;;; result: A.7 <- A.6, A.6 <- A.5, ..., A.1 <- A.7, A.0 <- A.7
;;; bytes: 3
;;; cycles: 4
.macro rsla
    a7c
    rol
.endmacro

;;; summary: Rotate Straight Left Byte in memory  8-bit rotate left
;;; result: [M].7 <- [M].6, [M].6 <- [M].5, ..., [M].1 <- [M].7, [M].0 <- [M].7 , A = +
.macro rslb M
    lda 0 + (M)
    asl
    rol 0 + (M)
.endmacro

;;; summary: Arithmic Shift Right A  signed
;;; result: A.7 <- A.7, A.6 <- A.7, ..., A.1 <- A.2, A.0 <- A.1
;;; bytes: 3
;;; cycles: 4
.macro asra
    a7c
    ror
.endmacro

;;; summary: Rotate Straight Right A  8-bit rotate right
;;; result: A.7 <- A.0, A.6 <- A.7, ..., A.1 <- A.2, A.0 <- A.1
;;; bytes: 5
;;; cycles: 6-8
;;; notes: at adc: C = 1, so will add extra 1.
.macro rsra
    lsr
    bcc :+
    adc # $80 - 1
    :
.endmacro

;;; summary: Rotate Straight Right  8-bit rotate right Byte in memory
;;; result: [M].7 <- [M].0, [M].6 <- [M].7, ..., [M].1 <- [M].2, [M].0 <- [M].1, A = +
.macro rsrb M
    lda 0 + (M)
    lsr
    ror 0 + (M)
.endmacro

;;; summary: Accumulator Swap Nibble
;;; result: A.7 <- A.3, A.6 <- A.2, A.5 <- A.1, A.4 <- A.0, A.3 <- A.7, A.2 <- A.6, A.1 <- A.5, A.0 <- A.4
;;; bytes: 8
;;; cycles: 12
.macro asn
    asl
    adc # $80
    rol
    asl
    adc # $80
    rol
.endmacro

;;; summary: One-s complement of A  not, invert, negate
;;; result: A <- ~A
;;; bytes: 2
;;; cycles: 2
.macro oca
    eor # %11111111
.endmacro

;;; summary: Not A
;;; result: A <- ~A
;;; bytes: 2
;;; cycles: 2
;;; notes: same as oca
.macro nota
    oca
.endmacro

;;; summary: Two-s Complement A  signed unary minus
;;; result: A <- 0 - A
;;; bytes: 5
;;; cycles: 6
.macro tca
    oca
    clc
    adc # 1
.endmacro

;;; summary: Is bit bitindex set in source byte?
.macro isbitset M, bitindex
    lda 0 + (M)
    and # 1 << (bitindex)
.endmacro

;;; summary: Set bit bitindex in memory source byte
.macro setbit M, bitindex
    lda 0 + (M)
    ora # 1 << (bitindex)
    sta 0 + (M)
.endmacro

;;; summary: Clear bit bitindex in memory byte
.macro clrbit M, bitindex
    lda 0 + (M)
    and # < ~ (1 << (bitindex))
    sta 0 + (M)
.endmacro

;;; summary: Clear bits in memory byte by set mask
.macro clrbits M, setMask
    lda 0 + (M)
    and # ~ (setMask)
    sta 0 + (M)
.endmacro

; ==============================================================================
; Synthetic instuctions - Load constant values
; ==============================================================================

;;; summary: LoaD A from constant byte Value
;;; result: A = value
;;; changed: N+ , Z+
.macro ldav value
    lda # (value)
.endmacro

;;; summary: LoaD X from constant byte Value
;;; result: X = value
;;; changed: N+ , Z+
.macro ldxv value
    ldx # (value)
.endmacro

;;; summary: LoaD Y from constant byte Value
;;; result: Y = value
;;; changed: N+ , Z+
.macro ldyv value
    ldy # (value)
.endmacro

;;; summary: LoaD memory Byte target from constant byte Value
;;; result: [target] = value
;;; changed: A , N+ , Z+
.macro ldbv target, value
    lda # (value)
    sta 0 + (target)
.endmacro

;;; summary: LoaD memory Word target from constant word Value
;;; result: [target]:w = value
;;; changed: A , N+ , Z+
.macro ldwv target, value
    lda # < (value)
    sta 0 + (target)
    lda # > (value)
    sta 1 + (target)
.endmacro

;;; summary: LoaD AL from constant byte Value
;;; result: AL <- value
;;; changed: A , N+ , Z+
.macro ldalv value
    ldbv AL, (value)
.endmacro

;;; summary: LoaD AH from constant byte Value
;;; result: AH = value
;;; changed: A , N+ , Z+
.macro ldahv value
    ldbv AH, (value)
.endmacro

;;; summary: LoaD AX from constant word Value
;;; result: AX = value
;;; changed: A , N+ , Z+
.macro ldaxv value
    ldwv AX, (value)
.endmacro

;;; summary: LoaD BL from constant byte Value
;;; result: BL = value
;;; changed: A , N+ , Z+
.macro ldblv value
    ldbv BL, (value)
.endmacro

;;; summary: LoaD BH from constant byte Value
;;; result: BH = value
;;; changed: A, N+ , Z+
.macro ldbhv value
    ldbv BH, (value)
.endmacro

;;; summary: LoaD BX from constant word Value
;;; result: BX = value
;;; changed: A , N+ , Z+
.macro ldbxv value
    ldwv BX, (value)
.endmacro

;;; summary: LoaD CL from constant byte Value
;;; result: CL <- value
;;; changed: N+ , Z+
;;; changed: A , N+ , Z+
.macro ldclv value
    ldbv CL, (value)
.endmacro

;;; summary: LoaD CH from constant byte Value
;;; result: CH = value
;;; changed: A, N+ , Z+
.macro ldchv value
    ldbv CH, (value)
.endmacro

;;; summary: LoaD CX from constant word Value
;;; result: CX = value
;;; changed: A , N+ , Z+
.macro ldcxv value
    ldwv CX, (value)
.endmacro

;;; summary: LoaD DL from constant byte Value
;;; result: DL = value
;;; changed: A , N+ , Z+
.macro lddlv value
    ldbv DL, (value)
.endmacro

;;; summary: LoaD DH from constant byte Value
;;; result: DH = value
;;; changed: A , N+ , Z+
.macro lddhv value
    ldbv DH, (value)
.endmacro

;;; summary: LoaD DX from constant word Value
;;; result: DX = value
;;; changed: A , N+ , Z+
.macro lddxv value
    ldwv DX, (value)
.endmacro

;;; summary: Clear A
;;; result: A = 0
;;; changed: A, N0 , Z1
.macro clra
    ldav 0
.endmacro

;;; summary: Clear X
;;; result: X = 0
;;; changed: X, N0 , Z1
.macro clrx
    ldxv 0
.endmacro

;;; summary: Clear Y
;;; result: Y = 0
;;; changed: Y, N0 , Z1
.macro clry
    ldyv 0
.endmacro

;;; summary: Clear Byte memory
;;; result: [M]:b = 0
;;; changed: [M], N0 , Z1
.macro clrb M
    ldbv M, 0
.endmacro

;;; summary: Clear Word memory
;;; result: [M]:w = 0
;;; changed: [M], N0 , Z1
.macro clrw M
    ldwv M, 0
.endmacro

;;; summary: Clear AL
;;; result: AL = 0
;;; changed: AL, N0 , Z1
.macro clral
    clrb AL
.endmacro

;;; summary: Clear AH
;;; result: AH = 0
;;; changed: AH, N0 , Z1
.macro clrah
    clrb AH
.endmacro

;;; summary: Clear AX
;;; result: AX = 0
;;; changed: AX, N0 , Z1
.macro clrax
    clrw AX
.endmacro

;;; summary: Clear BL
;;; result: BL = 0
;;; changed: BL, N0 , Z1
.macro clrbl
    clrb BL
.endmacro

;;; summary: Clear BH
;;; result: BH = 0
;;; changed: BH, N0 , Z1
.macro clrbh
    clrb BH
.endmacro

;;; summary: Clear BX
;;; result: BX = 0
;;; changed: BX, N0 , Z1
.macro clrbx
    clrw BX
.endmacro

;;; summary: Clear CL
;;; result: CL = 0
;;; changed: CL, N0 , Z1
.macro clrcl
    clrb CL
.endmacro

;;; summary: Clear CH
;;; result: CH = 0
;;; changed: CH, N0 , Z1
.macro clrch
    clrb CH
.endmacro

;;; summary: Clear CX
;;; result: CX = 0
;;; changed: CX, N0 , Z1
.macro clrcx
    clrw CX
.endmacro

;;; summary: Clear DL
;;; result: DL = 0
;;; changed: DL, N0 , Z1
.macro clrdl
    clrb DL
.endmacro

;;; summary: Clear DH
;;; result: DH = 0
;;; changed: DH, N0 , Z1
.macro clrdh
    clrb DH
.endmacro

;;; summary: Clear DX
;;; result: DX = 0
;;; changed: DX, N0 , Z1
.macro clrdx
    clrw DX
.endmacro

; ==============================================================================
; Synthetic instuctions - Load
; ==============================================================================

;;; summary: LoaD memory target from memory source Byte
;;; result: [target] <- [source]
;;; changed: A , N+ , Z+
.macro ldb target, source
    lda 0 + (source)
    sta 0 + (target)
.endmacro

;;; summary: LoaD memory target from memory source Word
;;; result: [target]:w <- [source]:w
;;; changed: A , N+ , Z+
.macro ldw target, source
    lda 0 + (source)
    sta 0 + (target)
    lda 1 + (source)
    sta 1 + (target)
.endmacro

;;; summary: LoaD AL from byte source
;;; result: AL <- [source]
;;; changed: A , N+ , Z+
.macro ldal source
    ldb AL, (source)
.endmacro

;;; summary: LoaD AH from byte source
;;; result: AH <- [source]
;;; changed: A , N+ , Z+
.macro ldah source
    ldb AH, (source)
.endmacro

;;; summary: LoaD AX from word source
;;; result: AX <- [source]:w
;;; changed: A , N+ , Z+
.macro ldax source
    ldw AX, (source)
.endmacro

;;; summary: LoaD BL from source
;;; result: BL <- [source]
;;; changed: A , N+ , Z+
.macro ldbl source
    ldb BL, (source)
.endmacro

;;; summary: LoaD BH from source
;;; result: BH <- [source]
;;; changed: A , N+ , Z+
.macro ldbh source
    ldb BH, (source)
.endmacro

;;; summary: LoaD BX from source
;;; result: BX <- [source]:w
;;; changed: A , N+ , Z+
.macro ldbx source
    ldw BX, (source)
.endmacro

;;; summary: LoaD CL from source
;;; result: CL <- [source]
;;; changed: A , N+ , Z+
.macro ldcl source
    ldb CL, (source)
.endmacro

;;; summary: LoaD CH from source
;;; result: CH <- [source]
;;; changed: A , N+ , Z+
.macro ldch source
    ldb CH,source
.endmacro

;;; summary: LoaD CX from source
;;; result: CX <- [source]:w
;;; changed: A , N+ , Z+
.macro ldcx source
    ldw CX, (source)
.endmacro

;;; summary: LoaD DL from source
;;; result: DL <- [source]
;;; changed: A , N+ , Z+
.macro lddl source
    ldb DL, (source)
.endmacro

;;; summary: LoaD DH from source
;;; result: DH <- [source]
;;; changed: A , N+ , Z+
.macro lddh source
    ldb DH, (source)
.endmacro

;;; summary: LoaD DX from source
;;; result: DX <- [source]:w
;;; changed: A , N+ , Z+
.macro lddx source
    ldw DX, (source)
.endmacro

;;; summary: LoaD AX from BX
;;; result: AX <- BX
;;; changed: A , N+ , Z+
.macro ldaxbx
    ldw AX, BX
.endmacro

;;; summary: LoaD AX from CX
;;; result: AX <- CX
;;; changed: A , N+ , Z+
.macro ldaxcx
    ldw AX, CX
.endmacro

;;; summary: LoaD AX from DX
;;; result: AX <- DX
;;; changed: A , N+ , Z+
.macro ldaxdx
    ldw AX, DX
.endmacro

;;; summary: LoaD BX from AX
;;; result: BX <- AX
;;; changed: A , N+ , Z+
.macro ldbxax
    ldw BX, AX
.endmacro

;;; summary: LoaD BX from CX
;;; result: BX <- CX
;;; changed: A , N+ , Z+
.macro ldbxcx
    ldw BX, CX
.endmacro

;;; summary: LoaD BX from DX
;;; result: BX <- DX
;;; changed: A , N+ , Z+
.macro ldbxdx
    ldw BX, DX
.endmacro

;;; summary: LoaD CX from AX
;;; result: CX <- AX
;;; changed: A , N+ , Z+
.macro ldcxax
    ldw CX, AX
.endmacro

;;; summary: LoaD CX from BX
;;; result: CX <- BX
;;; changed: A , N+ , Z+
.macro ldcxbx
    ldw CX, BX
.endmacro

;;; summary: LoaD CX from DX
;;; result: CX <- DX
;;; changed: A , N+ , Z+
.macro ldcxdx
    ldw CX, DX
.endmacro

;;; summary: LoaD DX from AX
;;; result: DX <- AX
;;; changed: A , N+ , Z+
.macro lddxax
    ldw DX, AX
.endmacro

;;; summary: LoaD DX from BX
;;; result: DX <- BX
;;; changed: A , N+ , Z+
.macro lddxbx
    ldw DX, BX
.endmacro

;;; summary: LoaD DX from CX
;;; result: DX <- CX
;;; changed: A , N+ , Z+
.macro lddxcx
    ldw DX, CX
.endmacro

;;; summary: LoaD AL from AH
;;; result: AL <- AH
;;; changed: A , N+ , Z+
.macro ldalah
    ldb AL, AH
.endmacro

;;; summary: LoaD AL from BL
;;; result: AL <- BL
;;; changed: A , N+ , Z+
.macro ldalbl
    ldb AL, BL
.endmacro

;;; summary: LoaD AL from BH
;;; result: AL <- BH
;;; changed: A , N+ , Z+
.macro ldalbh
    ldb AL, BH
.endmacro

;;; summary: LoaD AL from CL
;;; result: AL <- CL
;;; changed: A , N+ , Z+
.macro ldalcl
    ldb AL, CL
.endmacro

;;; summary: LoaD AL from CH
;;; result: AL <- CH
;;; changed: A , N+ , Z+
.macro ldalch
    ldb AL, CH
.endmacro

;;; summary: LoaD AL from DL
;;; result: AL <- DL
;;; changed: A , N+ , Z+
.macro ldaldl
    ldb AL, DL
.endmacro

;;; summary: LoaD AL from DH
;;; result: AL <- DH
;;; changed: A , N+ , Z+
.macro ldaldh
    ldb AL, DH
.endmacro

;;; summary: LoaD AH from AL
;;; result: AH <- AL
;;; changed: A , N+ , Z+
.macro ldahal
    ldb AH, AL
.endmacro

;;; summary: LoaD AH from BL
;;; result: AH <- BL
;;; changed: A , N+ , Z+
.macro ldahbl
    ldb AH, BL
.endmacro

;;; summary: LoaD AH from BH
;;; result: AH <- BH
;;; changed: A , N+ , Z+
.macro ldahbh
    ldb AH, BH
.endmacro

;;; summary: LoaD AH from CL
;;; result: AH <- CL
;;; changed: A , N+ , Z+
.macro ldahcl
    ldb AH, CL
.endmacro

;;; summary: LoaD AH from CH
;;; result: AH <- CH
;;; changed: A , N+ , Z+
.macro ldahch
    ldb AH, CH
.endmacro

;;; summary: LoaD AH from DL
;;; result: AH <- DL
;;; changed: A , N+ , Z+
.macro ldahdl
    ldb AH, DL
.endmacro

;;; summary: LoaD AH from DH
;;; result: AH <- DH
;;; changed: A , N+ , Z+
.macro ldahdh
    ldb AH, DH
.endmacro

;;; summary: LoaD BL from AL
;;; result: BL <- AL
;;; changed: A , N+ , Z+
.macro ldblal
    ldb BL, AL
.endmacro

;;; summary: LoaD BL from AH
;;; result: BL <- AH
;;; changed: A , N+ , Z+
.macro ldblah
    ldb BL, AH
.endmacro

;;; summary: LoaD BL from BH
;;; result: BL <- BH
;;; changed: A , N+ , Z+
.macro ldblbh
    ldb BL, BH
.endmacro

;;; summary: LoaD BL from CL
;;; result: BL <- CL
;;; changed: A , N+ , Z+
.macro ldblcl
    ldb BL, CL
.endmacro

;;; summary: LoaD BL from CH
;;; result: BL <- CH
;;; changed: A , N+ , Z+
.macro ldblch
    ldb BL, CH
.endmacro

;;; summary: LoaD BL from DL
;;; result: BL <- DL
;;; changed: A , N+ , Z+
.macro ldbldl
    ldb BL, DL
.endmacro

;;; summary: LoaD BL from DH
;;; result: BL <- DH
;;; changed: A , N+ , Z+
.macro ldbldh
    ldb BL, DH
.endmacro

;;; summary: LoaD BH from AL
;;; result: BH <- AL
;;; changed: A , N+ , Z+
.macro ldbhal
    ldb BH, AL
.endmacro

;;; summary: LoaD BH from AH
;;; result: BH <- AH
;;; changed: A , N+ , Z+
.macro ldbhah
    ldb BH, AH
.endmacro

;;; summary: LoaD BH from BL
;;; result: BH <- BL
;;; changed: A , N+ , Z+
.macro ldbhbl
    ldb BH, BL
.endmacro

;;; summary: LoaD BH from CL
;;; result: BH <- CL
;;; changed: A , N+ , Z+
.macro ldbhcl
    ldb BH, CL
.endmacro

;;; summary: LoaD BH from CH
;;; result: BH <- CH
;;; changed: A , N+ , Z+
.macro ldbhch
    ldb BH, CH
.endmacro

;;; summary: LoaD BH from DL
;;; result: BH <- DL
;;; changed: A , N+ , Z+
.macro ldbhdl
    ldb BH, DL
.endmacro

;;; summary: LoaD BH from DH
;;; result: BH <- DH
;;; changed: A , N+ , Z+
.macro ldbhdh
    ldb BH, DH
.endmacro

;;; summary: LoaD CL from AL
;;; result: CL <- AL
;;; changed: A , N+ , Z+
.macro ldclal
    ldb CL, AL
.endmacro

;;; summary: LoaD CL from AH
;;; result: CL <- AH
;;; changed: A , N+ , Z+
.macro ldclah
    ldb CL, AH
.endmacro

;;; summary: LoaD CL from BL
;;; result: CL <- BL
;;; changed: A , N+ , Z+
.macro ldclbl
    ldb CL, BL
.endmacro

;;; summary: LoaD CL from BH
;;; result: CL <- BH
;;; changed: A , N+ , Z+
.macro ldclbh
    ldb CL, BH
.endmacro

;;; summary: LoaD CL from CH
;;; result: CL <- CH
;;; changed: A , N+ , Z+
.macro ldclch
    ldb CL, CH
.endmacro

;;; summary: LoaD CL from DL
;;; result: CL <- DL
;;; changed: A , N+ , Z+
.macro ldcldl
    ldb CL, DL
.endmacro

;;; summary: LoaD CL from DH
;;; result: CL <- DH
;;; changed: A , N+ , Z+
.macro ldcldh
    ldb CL, DH
.endmacro

;;; summary: LoaD CH from AL
;;; result: CH <- AL
;;; changed: A , N+ , Z+
.macro ldchal
    ldb CH, AL
.endmacro

;;; summary: LoaD CH from AH
;;; result: CH <- AH
;;; changed: A , N+ , Z+
.macro ldchah
    ldb CH, AH
.endmacro

;;; summary: LoaD CH from BL
;;; result: CH <- BL
;;; changed: A , N+ , Z+
.macro ldchbl
    ldb CH, BL
.endmacro

;;; summary: LoaD CH from BH
;;; result: CH <- BH
;;; changed: A , N+ , Z+
.macro ldchbh
    ldb CH, BH
.endmacro

;;; summary: LoaD CH from CL
;;; result: CH <- CL
;;; changed: A , N+ , Z+
.macro ldchcl
    ldb CH, CL
.endmacro

;;; summary: LoaD CH from DL
;;; result: CH <- DL
;;; changed: A , N+ , Z+
.macro ldchdl
    ldb CH, DL
.endmacro

;;; summary: LoaD CH from DH
;;; result: CH <- DH
;;; changed: A , N+ , Z+
.macro ldchdh
    ldb CH, DH
.endmacro

;;; summary: LoaD DL from AL
;;; result: DL <- AL
;;; changed: A , N+ , Z+
.macro lddlal
    ldb DL, AL
.endmacro

;;; summary: LoaD DL from AH
;;; result: DL <- AH
;;; changed: A , N+ , Z+
.macro lddlah
    ldb DL, AH
.endmacro

;;; summary: LoaD DL from BL
;;; result: DL <- BL
;;; changed: A , N+ , Z+
.macro lddlbl
    ldb DL, BL
.endmacro

;;; summary: LoaD DL from BH
;;; result: DL <- BH
;;; changed: A , N+ , Z+
.macro lddlbh
    ldb DL, BH
.endmacro

;;; summary: LoaD DL from CL
;;; result: DL <- CL
;;; changed: A , N+ , Z+
.macro lddlcl
    ldb DL, CL
.endmacro

;;; summary: LoaD DL from CH
;;; result: DL <- CH
;;; changed: A , N+ , Z+
.macro lddlch
    ldb DL, CH
.endmacro

;;; summary: LoaD DL from DH
;;; result: DL <- DH
;;; changed: A , N+ , Z+
.macro lddldh
    ldb DL, DH
.endmacro

;;; summary: LoaD DH from AL
;;; result: DH <- AL
;;; changed: A , N+ , Z+
.macro lddhal
    ldb DH, AL
.endmacro

;;; summary: LoaD DH from AH
;;; result: DH <- AH
;;; changed: A , N+ , Z+
.macro lddhah
    ldb DH, AH
.endmacro

;;; summary: LoaD DH from BL
;;; result: DH <- BL
;;; changed: A , N+ , Z+
.macro lddhbl
    ldb DH, BL
.endmacro

;;; summary: LoaD DH from BH
;;; result: DH <- BH
;;; changed: A , N+ , Z+
.macro lddhbh
    ldb DH, BH
.endmacro

;;; summary: LoaD DH from CL
;;; result: DH <- CL
;;; changed: A , N+ , Z+
.macro lddhcl
    ldb DH, CL
.endmacro

;;; summary: LoaD DH from CH
;;; result: DH <- CH
;;; changed: A , N+ , Z+
.macro lddhch
    ldb DH, CH
.endmacro

;;; summary: LoaD DH from DL
;;; result: DH <- DL
;;; changed: A , N+ , Z+
.macro lddhdl
    ldb DH, DL
.endmacro

; ==============================================================================
; Synthetic instuctions - Clear
; ==============================================================================

;;; summary: CLear A
;;; result: A = 0
;;; changed: N0 , Z1
.macro cla
    ldav 0
.endmacro

;;; summary: CLear X
;;; result: X = 0
;;; changed: N0 , Z1
.macro clx
    ldxv 0
.endmacro

;;; summary: CLear Y
;;; result: Y = 0
;;; changed: N0 Z1
.macro cly
    ldyv 0
.endmacro

;;; summary: CLear Byte
;;; result: [target] = 0
;;; changed: N0 , Z0
.macro clb target
    ldb (target), 0
.endmacro

;;; summary: CLear Word
;;; result: [target]:w = 0
;;; changed: N0 , Z0
.macro clw target
    cla
    sta 0 + (target)
    sta 1 + (target)
.endmacro

; ==============================================================================
; Synthetic instuctions - Store constant values
; ==============================================================================

;;; summary: STore byte Value into A
;;; result: A = value
;;; changed: N+ , Z+
.macro stva value
    ldav (value)
.endmacro

;;; summary: STore byte Value into X
;;; result: X = value
;;; changed: N+ , Z+
.macro stvx value
    ldxv (value)
.endmacro

;;; summary: STore byte Value into Y
;;; result: Y = value
;;; changed: N+ , Z+
.macro stvy value
    ldyv (value)
.endmacro

;;; summary: STore Value to target Byte
;;; result: [target] = value
;;; changed: A , N+ , Z+
.macro stvb value, target
    ldbv (target), (value)
.endmacro

;;; summary: STore Value Word
;;; result: [target]:w = value
;;; changed: A , N+ , Z+
.macro stvw value, target
    ldwv (target), (value)
.endmacro

;;; summary: STore byte Value into AL
;;; result: AL = value
;;; changed: A , N+ , Z+
.macro stval value
    ldalv (value)
.endmacro

;;; summary: STore byte Value into AH
;;; result: AH = value
;;; changed: A , N+ , Z+
.macro stvah value
    ldahv (value)
.endmacro

;;; summary: STore word Value into AX
;;; result: AX = value
;;; changed: A , N+ , Z+
.macro stvax value
    ldaxv (value)
.endmacro

;;; summary: STore byte Value into BL
;;; result: BL = value
;;; changed: A , N+ , Z+
.macro stvbl value
    ldblv (value)
.endmacro

;;; summary: STore byte Value into BH
;;; result: BH = value
;;; changed: A , N+ , Z+
.macro stvbh value
    ldbhv (value)
.endmacro

;;; summary: STore word Value into BX
;;; result: BX = value
;;; changed: A , N+ , Z+
.macro stvbx value
    ldbxv (value)
.endmacro

;;; summary: STore byte Value into CL
;;; result: CL = value
;;; changed: A , N+ , Z+
.macro stdvcl value
    ldclv (value)
.endmacro

;;; summary: STore byte Value into CH
;;; result: CH = value
;;; changed: A , N+ , Z+
.macro stvch value
    ldchv (value)
.endmacro

;;; summary: STore word Value into CX
;;; result: CX = value
;;; changed: A , N+ , Z+
.macro stvcx value
    ldcxv (value)
.endmacro

;;; summary: STore byte Value into DL
;;; result: DL = value
;;; changed: A , N+ , Z+
.macro stvdl value
    lddlv (value)
.endmacro

;;; summary: STore byte Value into DH
;;; result: DH = value
;;; changed: A , N+ , Z+
.macro stvdh value
    lddhv (value)
.endmacro

;;; summary: STore word Value into DX
;;; result: DX = value
;;; changed: A , N+ , Z+
.macro stvdx value
    lddxv (value)
.endmacro

; ==============================================================================
; Synthetic instuctions - Store memory values
; ==============================================================================

;;; summary: STore memory source into target Byte
;;; result: [target] <- [source]
;;; changed: A , N+ , Z+
.macro stb source, target
    ldb (target), (source)
.endmacro

;;; summary: Store memory source into target Word
;;; result: [target]:w <- [source]:w
;;; changed: A , N+ , N+
.macro stw source, target
    ldw (target), (source)
.endmacro

;;; summary: STore AL into target Byte
;;; result: [target] <- AL
;;; changed: A , N+ , Z+
.macro stal target
    stb AL, (target)
.endmacro

;;; summary: STore AH into target Byte
;;; result: [target] <- AH
;;; changed: A , N+ , Z+
.macro stah target
    stb AH, (target)
.endmacro

;;; summary: STore AX into target Word
;;; result: [target]:w <- AX
;;; changed: A , N+ , Z+
.macro stax target
    stw AX, (target)
.endmacro

;;; summary: STore BL into target Byte
;;; result: [target] <- BL
;;; changed: A , N+ , Z+
.macro stbl target
    stb BL, (target)
.endmacro

;;; summary: STore BH into target Byte
;;; result: [target] <- BH
;;; changed: A , N+ , Z+
.macro stbh target
    stb BH, (target)
.endmacro

;;; summary: STore BX into target Word
;;; result: [target]:w <- BX
;;; changed: A , N+ , Z+
.macro stbx target
    stw BX, (target)
.endmacro

;;; summary: STore CL into target Byte
;;; result: [target] <- CL
;;; changed: A , N+ , Z+
.macro stcl target
    stb CL, (target)
.endmacro

;;; summary: STore CH into target Byte
;;; result: [target] <- CH
;;; changed: A , N+ , Z+
.macro stch target
    stb CH, (target)
.endmacro

;;; summary: STore CX into target Word
;;; result: [target]:w <- CX
;;; changed: A , N+ , Z+
.macro stcx target
    stw CX, (target)
.endmacro

;;; summary: STore DL into target Byte
;;; result: [target] <- DL
;;; changed: A , N+ , Z+
.macro stdl target
    stb DL, (target)
.endmacro

;;; summary: STore DH into target Byte
;;; result: [target] <- DH
;;; changed: A , N+ , Z+
.macro stdh target
    stb DH, (target)
.endmacro

;;; summary: STore DX into target Word
;;; result: [target]:w <- DX
;;; changed: A , N+ , Z+
.macro stdx target
    stw DX, (target)
.endmacro

; ==============================================================================
; Synthetic instuctions - Math
; ==============================================================================

;;; summary: Reverse subtract A Value
;;; result: A <- V - A
;;; bytes: 5-6
;;; cycles: 4-10
.macro revsubav V
    oca
    sec
    adc # V
.endmacro

;;; summary: Reverse subtract A memory Byte
;;; result: A <- [M] - A
;;; bytes: 5-6
;;; cycles: 4-10
.macro revsuba M
    oca
    sec
    adc 0 + (M)
.endmacro

;;; summary: INcrement memory Word
;;; result: [M]:w <- [M]:w + 1
;;; bytes: zp: 6 , ab: 8
;;; cycles: zp: 12-14 , ab: 14-16
.macro inw M
    inc 0 + (M)
    bne :+
    inc 1 + (M)
    :
.endmacro

;;; summary: INCrement memory Word
;;; result: [M]:w <- [M]:w + 1
;;; bytes: zp: 6 , ab: 8
;;; cycles: zp: 12-14 , ab: 14-16
.macro incw M
    inw M
.endmacro

.macro incax
    incw AX
.endmacro

.macro incbx
    incw BX
.endmacro

.macro inccx
    incw CX
.endmacro

.macro incdx
    incw DX
.endmacro

;;; summary: DEcrement memory Word
;;; result: [M]:w <- [M]:w - 1
.macro dew M
    lda 0 + (M)
    bne :+
    dec 1 + (M)
    :
    dec 0 + (M)
.endmacro

;;; summary: DECrement memory Word
;;; result: [M]:w <- [M]:w - 1
.macro decw M
    dew M
.endmacro

.macro decax
    decw AX
.endmacro

.macro decbx
    decw BX
.endmacro

.macro deccx
    decw CX
.endmacro

.macro decdx
    decw DX
.endmacro

;;; summary: add to unsigned word the signed byte A
;;; result: [UW]:uw <- [UW]:uw + A:sb
;;; see: http://forums.nesdev.com/viewtopic.php?t=10975
;;; result: N+ Z+ from UW:hi
.macro add_uw_sa UW
    bpl :+
    dec 1 + (UW)
    :
    clc
    adc 0 + (UW)
    sta 0 + (UW)
    bcc :+
    inc 1 + (UW)
    :
.endmacro

;;; summary: Add to AL value of A (with clear C)
;;; result: AL <- A + AL with C=0
.macro addala
    clc
    adc AL
    sta AL
.endmacro

;;; summary: Add to AH value of A (with clear C)
;;; result: AH <- A + AH with C=0
.macro addaha
    clc
    adc AH
    sta AH
.endmacro

;;; summary: Add to BL value of A (with clear C)
;;; result: BL <- A + BL with C=0
.macro addbla
    clc
    adc BL
    sta BL
.endmacro

;;; summary: Add to BH value of A (with clear C)
;;; result: BH <- A + BH with C=0
.macro addbha
    clc
    adc BH
    sta BH
.endmacro

;;; summary: Add to CL value of A (with clear C)
;;; result: CL <- A + CL with C=0
.macro addcla
    clc
    adc CL
    sta CL
.endmacro

;;; summary: Add to CH value of A (with clear C)
;;; result: CH <- A + CH with C=0
.macro addcha
    clc
    adc CH
    sta CH
.endmacro

;;; summary: Add to DL value of A (with clear C)
;;; result: DL <- A + DL with C=0
.macro adddla
    clc
    adc DL
    sta DL
.endmacro

;;; summary: Add to DH value of A (with clear C)
;;; result: DH <- A + DH with C=0
.macro adddha
    clc
    adc DH
    sta DH
.endmacro

;;; summary: Add to AX the constant value V
.macro addaxv V
    clc
    lda AL
    adc # < (V)
    sta AL
    lda AH
    adc # > (V)
    sta AH
.endmacro

;;; summary: Add to BX the constant value V
.macro addbxv V
    clc
    lda BL
    adc # < (V)
    sta BL
    lda BH
    adc # > (V)
    sta BH
.endmacro

;;; summary: Add to CX the constant value V
.macro addcxv V
    clc
    lda CL
    adc # < (V)
    sta CL
    lda CH
    adc # > (V)
    sta CH
.endmacro

;;; summary: Add to DX the constant value V
.macro adddxv V
    clc
    lda DL
    adc # < (V)
    sta DL
    lda DH
    adc # > (V)
    sta DH
.endmacro

; ==============================================================================
; Synthetic instuctions - Control flow
; ==============================================================================

;;; summary JuMP to address stored at M + X
;;; result: PC <- [M + X]:w
;;; bytes:  zp:  8 , ab: 10
;;; cycles: zp: 23 , ab: 23-26
.macro jmpx M
    lda 1 + (M),x
    pha
    lda 0 + (M),x
    pha
    php
    rti
.endmacro

;;; summary: Skip next byte
;;; changed: N+ V+ Z+
;;; notes: C-
.macro skip1
    .byte OPCODE_BIT_ZP
.endmacro

;;; summary: Skip next 2 bytes
;;; changed: N+ V+ Z+
;;; notes: C-
.macro skip2
    .byte OPCODE_BIT_AB
.endmacro

; ==============================================================================
; Synthetic instructions - Frame
; ==============================================================================

;;; summary: Restore RSP cache
;;; result: X <- [RSP]
.macro RESTORE_RSP
    ldx z:RSP
.endmacro

;;; summary: Restore FP cache
;;; result: X <- [FP]
.macro RESTORE_FP
    ldx z:FP
.endmacro

;;; summary: Begin pushing parameters
;;; result: X <- [RSP]
.macro BEGIN_PUSH
    ldx z:RSP
.endmacro

;;; summary: End pushing parameters
;;; result: [RSP] <- X
.macro END_PUSH
    stx z:RSP
.endmacro

;;; summary: Reset frame  discard any pushed parameters
;;; result: [FP] -> [FPP] , X = [FP] = [RSP]
.macro RESET_FRAME
    ldx z:FP
    stx z:RSP
.endmacro

; ==============================================================================
; Synthetic instructions - Push parameter constant values
; ==============================================================================

;;; summary: PusH Parameter Value Byte
;;; result: [old X] <- value , X = old X + 1
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpvb value
    lda # (value)
    inx
    sta z: < -1,x
.endmacro

;;; summary: PusH Parameter Value Word
;;; result: [old X]w = value:w , X = old X + 2
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpvw value
    lda # < (value)
    inx
    sta z: < -1,x
    lda # > (value)
    inx
    sta z: < -1,x
.endmacro

; ==============================================================================
; Synthetic instructions - Push parameter registers, memory
; ==============================================================================

;;; summary:  PusH Parameter A
;;; result: [old X] = A, X = old X + 1
;;; changed: N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpa
    inx
    sta z: < -1,x
.endmacro

;;; summary:  PusH Parameter Y
;;; result: [old X] = Y , X = old X + 1
;;; changed: P:N+Z+
;;; changed: N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpy
    inx
    sty z: < -1,x
.endmacro

;;; summary: PusH Parameter Byte
;;; result: [old X] = [source] , X = old X + 1
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpb source
    lda 0 + (source)
    inx
    sta z: < -1,x
.endmacro

;;; summary: PusH Parameter Word
;;; result: [old X]:w = [source]:w , X = old X + 2
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpw source
    ; lo
    lda 0 + (source)
    inx
    sta z: < -1,x
    ; hi
    lda 1 + (source)
    inx
    sta z: < -1,x
.endmacro

;;; summary: PusH Parameter AL
;;; result: [old X] = AL , X = old X + 1
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpal
    phpb AL
.endmacro

;;; summary: PusH Parameter AH
;;; result: [old X] = AH , X = old X + 1
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpah
    phpb AH
.endmacro

;;; summary: PusH Parameter AX
;;; result: [old X]:w = AX , X = old X + 2
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpax
    phpw AX
.endmacro

;;; summary: PusH Parameter BL
;;; result: [old X] = BL , X = old X + 1
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpbl
    phpb BL
.endmacro

;;; summary: PusH Parameter BH
;;; result: [old X] = BH , X = old X + 1
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpbh
    phpb BH
.endmacro

;;; summary: PusH Parameter BX
;;; result: [old X]:w = BX , X = old X + 2
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpbx
    phpw BX
.endmacro

;;; summary: PusH Parameter CL
;;; result: [old X] = CL , X = old X + 1
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpcl
    phpb CL
.endmacro

;;; summary: PusH Parameter CH
;;; result: [old X] = CH , X = old X + 1
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpch
    phpb CH
.endmacro

;;; summary: PusH Parameter CX
;;; result: [old X]:w = CX , X = old X + 2
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpcx
    phpw CX
.endmacro

;;; summary: PusH Parameter DL
;;; result: [old X] = DL , X = old X + 1
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpdl
    phpb DL
.endmacro

;;; summary: PusH Parameter DH
;;; result: [old X] = DH , X = old X + 1
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpdh
    phpb DH
.endmacro

;;; summary: PusH Parameter DX
;;; result: [old X]:w = DX , X = old X + 2
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro phpdx
    phpw DX
.endmacro

; ==============================================================================
; Synthetic instructions - Pull parameter registers, memory
; ==============================================================================

;;; summary: PuLl Parameter A
;;; result: X = old X - 1 , A = [X]
;;; changed: N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpa
    lda z: < -1,x
    dex
.endmacro

;;; summary: PuLl Parameter Y
;;; result: X = old X - 1 , Y = [X]
;;; changed: P:N+Z+
;;; changed: N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpy
    ldy z: < -1,x
    dex
.endmacro

;;; summary: PuLl Parameter Byte
;;; result: X = old X - 1 , [source] = [X]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpb source
    lda z: < -1,x
    sta 0 + (source)
    dex
.endmacro

;;; summary: Pull Parameter Word
;;; result: X = old X - 2 , [source]:w = [X]:w
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpw source
    lda z: < -1,x
    sta 1 + (source)
    dex
    lda z: < -1,x
    sta 0 + (source)
    dex
.endmacro

;;; summary: Pull Parameter AL
;;; result: X = old X - 1 , AL = [X]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpal
    plpb AL
.endmacro

;;; summary: Pull Parameter AH
;;; result: X = old X - 1 , AH = [X]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpah
    plpb AH
.endmacro

;;; summary: Pull Parameter AX
;;; result: X = old X - 2 , AX:w = [X]:w
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpax
    plpw AX
.endmacro

;;; summary: Pull Parameter BL
;;; result: X = old X - 1 , BL = [X]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpbl
    plpb BL
.endmacro

;;; summary: Pull Parameter BH
;;; result: X = old X - 1 , BH = [X]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpbh
    plpb BH
.endmacro

;;; summary: Pull Parameter BX
;;; result: X = old X - 2 , BX:w = [X]:w
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpbx
    plpw BX
.endmacro

;;; summary: Pull Parameter CL
;;; result: X = old X - 1 , CL = [X]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpcl
    plpb CL
.endmacro

;;; summary: Pull Parameter CH
;;; result: X = old X - 1 , CH = [X]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpch
    plpb CH
.endmacro

;;; summary: Pull Parameter CX
;;; result: X = old X - 2 , CX:w = [X]:w
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpcx
    plpw CX
.endmacro

;;; summary: Pull Parameter DL
;;; result: X = old X - 1 , DL = [X]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpdl
    plpb DL
.endmacro

;;; summary: Pull Parameter DH
;;; result: X = old X - 1 , DH = [X]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpdh
    plpb DH
.endmacro

;;; summary: Pull Parameter DX
;;; result: X = old X - 2 , DX:w = [X]:w
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [RSP]
.macro plpdx
    plpw DX
.endmacro

; ==============================================================================
; Synthetic instructions - Load target (A, Y, B, W, al, ...) from parameter
; ==============================================================================

;;; summary: LoaD A from Parameter
;;; result: A <- [X + parameter]
;;; changed: N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldap parameter
    lda z: < (0 + (parameter)) ,x
.endmacro

;;; summary: LoaD Y from Parameter
;;; result: Y <- [X + parameter]
;;; changed: N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldyp parameter
    ldy z: < (0 + (parameter)) ,x
.endmacro

;;; summary: LoaD Byte from Parameter
;;; result: [target] <- [X + parameter]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldbp target, parameter
    lda z: < (0 + (parameter)),x
    sta 0 + (target)
.endmacro

;;; summary: LoaD Word from Parameter
;;; result:  [target]:w <- [X + parameter]:w
;;; changed: A , P:N+Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldwp target, parameter
    lda z: < (0 + (parameter)) ,x
    sta 0 + (target)
    lda z: < (1 + (parameter)),x
    sta 1 + (target)
.endmacro

;;; summary: LoaD AL from Parameter
;;; result: AL <- [X + parameter]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldalp parameter
    ldbp AL, (parameter)
.endmacro

;;; summary: LoaD AH from Parameter
;;; result: AH <- [X + parameter]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldahp parameter
    ldbp AH, (parameter)
.endmacro

;;; summary: LoaD AX from Parameter
;;; result: AX <- [X + parameter]:w
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldaxp parameter
    ldwp AX, (parameter)
.endmacro

;;; summary: LoaD BL from Parameter
;;; result: BL <- [X + parameter]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldblp parameter
    ldbp BL, (parameter)
.endmacro

;;; summary: LoaD BH from Parameter
;;; result: BH <- [X + offset]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldbhp parameter
    ldbp BH, (parameter)
.endmacro

;;; summary: LoaD BX from Parameter
;;; result: BX <- [X + offset]:w
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldbxp parameter
    ldwp BX, (parameter)
.endmacro

;;; summary: LoaD CL from Parameter
;;; result: CL <- [X + parameter]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldclp parameter
    ldbp CL, (parameter)
.endmacro

;;; summary: LoaD CH from Parameter
;;; result: CH <- [X + parameter]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldchp parameter
    ldbp CH, (parameter)
.endmacro

;;; summary: LoaD CX from Parameter
;;; result: CX <- [X + parameter]:w
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro ldcxp parameter
    ldwp CX, (parameter)
.endmacro

;;; summary: LoaD DL from Parameter
;;; result: DL <- [X + parameter]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro lddlp parameter
    ldbp DL, (parameter)
.endmacro

;;; summary: LoaD DH from Parameter
;;; result: DH <- [X + parameter]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro lddhp parameter
    ldbp DH, (parameter)
.endmacro

;;; summary: LoaD DX from Parameter
;;; result: DX <- [X + parameter]:w
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro lddxp parameter
    ldwp DX, (parameter)
.endmacro

; ==============================================================================
; Synthetic instructions - Store soure (A, Y, B, W, al, ...) to parameters
; ==============================================================================

;;; summary: STore A into Parameter
;;; result: [X + parameter] <- A
;;; changed:
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stap parameter
    sta z: < (0 + (parameter)) , x
.endmacro

;;; summary: STore Y into Parameter
;;; result: [X + parameter] <- Y
;;; changed:
;;; notes: Assumes X is cached [FP]/[RSP]
.macro styp parameter
    sty z: < (0 + (parameter)) , x
.endmacro

;;; summary: STore Byte into Parameter
;;; result: [X + parameter] <- [source]
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stbp source, parameter
    lda 0 + (source)
    sta z: < (0 + (parameter)) , x
.endmacro

;;; summary: STore Word into Parameter
;;; result: [X + parameter]:w [source]:w
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stwp source, parameter
    lda 0 + (source)
    sta z: < (0 + (parameter)) , x
    lda 1 + (source)
    sta z: < (1 + (parameter)) , x
.endmacro

;;; summary: STore AL into Parameter
;;; result: [X + parameter] <- AL
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stalp parameter
    stbp AL, (parameter)
.endmacro

;;; summary: STore AH into Parameter
;;; result: [X + parameter] <- AH
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stahp parameter
    stbp AH, (parameter)
.endmacro

;;; summary: STore AX into Parameter
;;; result: [X + parameter]:w <- AX
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro staxp source
    stwp AX, (source)
.endmacro

;;; summary: STore BL into Parameter
;;; result: [X + parameter] <- BL
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stblp parameter
    stbp BL, (parameter)
.endmacro

;;; summary: STore BH into Parameter
;;; result: [X + parameter] <- BH
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stbhp parameter
    stbp BH, (parameter)
.endmacro

;;; summary: STore BX into Parameter
;;; result: [X + parameter]:w <- BX
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stbxp parameter
    stwp BX, (parameter)
.endmacro

;;; summary: STore CL into Parameter
;;; result: [X + parameter] <- CL
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stclp parameter
    stbp CL, (parameter)
.endmacro

;;; summary: STore CH into Parameter
;;; result: [X + parameter] <- CH
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stchp parameter
    stbp CH, (parameter)
.endmacro

;;; summary: STore CX into Parameter
;;; result: [X + parameter]:w <- CX
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stcxp parameter
    stwp CX, (parameter)
.endmacro

;;; summary: STore DL into Parameter
;;; result: [X + parameter] <- CL
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stdlp parameter
    stbp DL, (parameter)
.endmacro

;;; summary: STore HH into Parameter
;;; result: [X + parameter] <- CH
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stdhp parameter
    stbp DH, (parameter)
.endmacro

;;; summary: STore DX into Parameter
;;; result: [X + parameter]:w <- DX
;;; changed: A , N+ , Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro stdxp parameter
    stwp DX, (parameter)
.endmacro

; ==============================================================================
; Synthetic instructions - Parameters operations
; ==============================================================================

;;; summary: ADD with cleared carry Parameter to A
;;; result: A,C <- A + [X + parameter] + C
;;; changed: N+ V+ C+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro addapa parameter
    clc
    adc z: < (0 + (parameter)) , x
.endmacro

;;; summary: ADd with Carry Parameter to A
;;; result: A,C <- A + [X + parameter] + C
;;; changed: N+ V+ C+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro adcapa parameter
    adc z: < (0 + (parameter)) , x
.endmacro

;;; summary: AND of A and value of Parameter to A
;;; result: A <- A & [X + parameter]
;;; changed: N+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro andapa parameter
    and z: < (0 + (parameter)) , x
.endmacro

;;; summary: Arithmic Shift Left Parameter
;;; result: @parameter <- @parameter << 1
;;; changed: N+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro aslp parameter
    asl z: < (0 + (parameter)) , x
.endmacro

;;; summary: CoMPare A with Parameter
;;; result: [X + parameter] <- A
;;; changed: N+ C+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro cmpap parameter
    cmp z: < (0 + (parameter)) , x
.endmacro

;;; summary: DECrement Parameter
;;; result: @parameter <- @parameter - 1
;;; changed: N+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro decp parameter
    dec z: < (0 + (parameter)) , x
.endmacro

;;; summary: Exclusive OR A with Parameter to A
;;; result: A <- A ^ @parameter
;;; changed: N+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro eorapa parameter
    eor z: < (0 + (parameter)) , x
.endmacro

;;; summary: INCrement Parameter
;;; result: @parameter <- @parameter + 1
;;; changed: N+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro incp parameter
    inc z: < (0 + (parameter)) , x
.endmacro

;;; summary: INCrement Parameter Byte
;;; result: @parameter <- @parameter + 1
;;; changed: N+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro incpb parameter
    incp parameter
.endmacro

;;; summary: INCrement Parameter Word
;;; result: @parameter:w <- @parameter:w + 1
;;; changed: N+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro incpw parameter
    inc z: < (0 + (parameter)) , x
    bne :+
    inc z: < (1 + (parameter)) , x
    :
.endmacro

;;; summary: Logical Shift Right Parameter (unsigned)
;;; result: @parameter <- @parameter >>1
;;; changed: N+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro lsrp parameter
    lsr z: < (0 + (parameter)) , x
.endmacro

;;; summary: OR A with Parameter to A
;;; result: A <- A | @parameter
;;; changed: N+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro orapa parameter
    ora z: < (0 + (parameter)) , x
.endmacro

;;; summary: ROtate Left Parameter
;;; result: C <- @parameter[76543210] <- C
;;; changed: N+ C+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro rolp parameter
    rol z: < (0 + (parameter)) , x
.endmacro

;;; summary: ROtate Right Parameter
;;; result: C -> @parameter[76543210] -> C
;;; changed: N+ C+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro rorp parameter
    ror z: < (0 + (parameter)) , x
.endmacro

;;; summary: SuBtract with Carry Parameter from A to A
;;; result: A <- A - @parameter - C
;;; changed: N+ V+ C+ Z+
;;; notes: Assumes X is cached [FP]/[RSP]
.macro sbcapa parameter
    sbc z: < (0 + (parameter)) , x
.endmacro

.macro addalp parameter
    lda AL
    addapa parameter
    sta AL
.endmacro

.macro addahp parameter
    lda AH
    addapa parameter
    sta AH
.endmacro

.macro addblp parameter
    lda BL
    addapa parameter
    sta BL
.endmacro

.macro addbhp parameter
    lda BH
    addapa parameter
    sta DH
.endmacro

.macro addclp parameter
    lda CL
    addapa parameter
    sta CL
.endmacro

.macro addchp parameter
    lda CH
    addapa parameter
    sta CH
.endmacro

.macro adddlp parameter
    lda DL
    addapa parameter
    sta DL
.endmacro

.macro adddhp parameter
    lda DH
    addapa parameter
    sta DH
.endmacro

.macro subapa parameter
    sec
    sbcapa p_size
.endmacro

.macro cmpclp parameter
    lda CL
    cmpap parameter
.endmacro

; ==============================================================================
; Synthetic instructions - Interrupt flag on stack
; ==============================================================================

;;; summary: Push I and set I.
;;; see-also: pli
.macro phi
    php
    sei
.endmacro

;;; summary: Pull processor status Interrupt flag from the stack.
;;; see-also: phi-ex
;;; notes:
;;;   It only transitions P.I from 1 to 0, and not v.v. because that would mean
;;;   that there is a possible bug in your program, because some part of the
;;;   program might not have been protected by a P.I = 1.
.macro pli
    pla
    and # CPU_P_I
    bne :+
    cli
    :
.endmacro

.endif
