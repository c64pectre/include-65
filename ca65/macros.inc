;    include-65: Include files for 6502 and related processors, generic and Commodore 64.
;    Copyright (C) 2022,2023  C64PECTRE
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

;region Initialization of registers and stack frame

    ;;; summary: Initialize registers and frame registers
    ;;; changed:
    ;;;   AX = BX = CX = DX = A = Y = 0
    ;;;   X = FP = RSP = #RS_BOTTOM
    .macro INIT_FRAME_AND_REGISTERS
        lda # 0                             ; A = 0
        tay                                 ; Y = 0
    ;   sta MPL
    ;   sta MPH                             ; [MPX] = w:0
        ldx # REGISTERS_SIZEOF - 1          ; X = 7
        loop_do:
            sta REGISTERS_BASE , x          ; [REGISTERS_BASE + X] = 0
            dex                             ; X--
            bpl loop_do                     ; X >= 0 ?
        loop_end:
        ;
        ldx # FS_TOP                        ; X = #FS_TOP
        stx FSP                             ; FSP = #FS_TOP
        ldx # RS_BOTTOM                     ; X = #RS_BOTTOM
        stx RSP                             ; RSP = X = #RS_BOTTOM
        stx FP                              ; FP  = X = #RS_BOTTOM
    .endmacro

;endregion

;region Synthetic instuctions - Bit manipulation

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
    .macro rsl_a
        a7c
        rol
    .endmacro

    ;;; summary: Rotate Straight Left Byte in memory  8-bit rotate left
    ;;; result: [M].7 <- [M].6, [M].6 <- [M].5, ..., [M].1 <- [M].7, [M].0 <- [M].7 , A = +
    .macro rsl_b M
        lda 0 + (M)
        asl
        rol 0 + (M)
    .endmacro

    ;;; summary: Arithmic Shift Right A  signed
    ;;; result: A.7 <- A.7, A.6 <- A.7, ..., A.1 <- A.2, A.0 <- A.1
    ;;; bytes: 3
    ;;; cycles: 4
    .macro asr_a
        a7c
        ror
    .endmacro

    ;;; summary: Rotate Straight Right A  8-bit rotate right
    ;;; result: A.7 <- A.0, A.6 <- A.7, ..., A.1 <- A.2, A.0 <- A.1
    ;;; bytes: 5
    ;;; cycles: 6-8
    ;;; notes: at adc: C = 1, so will add extra 1.
    .macro rsr_a
        lsr
        bcc :+
        adc # $80 - 1
        :
    .endmacro

    ;;; summary: Rotate Straight Right  8-bit rotate right Byte in memory
    ;;; result: [M].7 <- [M].0, [M].6 <- [M].7, ..., [M].1 <- [M].2, [M].0 <- [M].1, A = +
    .macro rsr_b M
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
    .macro not_a
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

    ;;; summary: Is bit bitindex set in [M]?
    .macro is_bit_set M, bitindex
        lda 0 + (M)
        and # 1 << (bitindex)
    .endmacro

    ;;; summary: Set bit bitindex in [M]?
    .macro set_bit M, bitindex
        lda 0 + (M)
        ora # 1 << (bitindex)
        sta 0 + (M)
    .endmacro

    ;;; summary: Clear bit bitindex in [M]
    .macro clr_bit M, bitindex
        lda 0 + (M)
        and # < ~ (1 << (bitindex))
        sta 0 + (M)
    .endmacro

    ;;; summary: Clear bits in [M] by set mask
    .macro clr_bits M, setMask
        lda 0 + (M)
        and # ~ (setMask)
        sta 0 + (M)
    .endmacro

;endregion

;region Synthetic instuctions - Load constant values

    ;;; summary: LoaD A from constant byte Value
    ;;; result: A = Value
    ;;; changed: A+ N+ Z+
    .macro ld_a_v Value
        lda # (Value)
    .endmacro

    ;;; summary: LoaD X from constant byte Value
    ;;; result: X = Value
    ;;; changed: X+ N+ Z+
    .macro ld_x_v Value
        ldx # (Value)
    .endmacro

    ;;; summary: LoaD Y from constant byte Value
    ;;; result: Y = Value
    ;;; changed: Y+ N+ Z+
    .macro ld_y_v Value
        ldy # (Value)
    .endmacro

    .macro ld_xy_v_w W
        ldx # < (W)
        ldy # > (W)
    .endmacro

    ;;; summary: LoaD memory Byte Target from constant byte Value
    ;;; result: [Target] = Value
    ;;; changed: A N+ Z+
    .macro ld_b_v Target, Value
        lda # (Value)
        sta 0 + (Target)
    .endmacro

    ;;; summary: LoaD memory Word Target from constant word Value
    ;;; result: [Target]:w = Value
    ;;; changed: A+ N+ Z+
    .macro ld_w_v Target, Value
        lda # < (Value)
        sta 0 + (Target)
        lda # > (Value)
        sta 1 + (Target)
    .endmacro

    ;;; summary: LoaD AL from constant byte Value
    ;;; result: AL <- Value
    ;;; changed: A+ N+ Z+
    .macro ld_al_v Value
        ld_b_v (AL), (Value)
    .endmacro

    ;;; summary: LoaD AH from constant byte Value
    ;;; result: AH = Value
    ;;; changed: A+ N+ Z+
    .macro ld_ah_v Value
        ld_b_v (AH), (Value)
    .endmacro

    ;;; summary: LoaD AX from constant word Value
    ;;; result: AX = Value
    ;;; changed: A N+ Z+
    .macro ld_ax_v Value
        ld_w_v (AX), (Value)
    .endmacro

    ;;; summary: LoaD BL from constant byte Value
    ;;; result: BL = Value
    ;;; changed: A N+ Z+
    .macro ld_bl_v Value
        ld_b_v (BL), (Value)
    .endmacro

    ;;; summary: LoaD BH from constant byte Value
    ;;; result: BH = Value
    ;;; changed: A+ N+ Z+
    .macro ld_bh_v Value
        ld_b_v (BH), (Value)
    .endmacro

    ;;; summary: LoaD BX from constant word Value
    ;;; result: BX = Value
    ;;; changed: A+ N+ Z+
    .macro ld_bx_v Value
        ld_w_v (BX), (Value)
    .endmacro

    ;;; summary: LoaD CL from constant byte Value
    ;;; result: CL <- Value
    ;;; changed: N+ , Z+
    ;;; changed: A+ N+ Z+
    .macro ld_cl_v Value
        ld_b_v (CL), (Value)
    .endmacro

    ;;; summary: LoaD CH from constant byte Value
    ;;; result: CH = Value
    ;;; changed: A+ N+ Z+
    .macro ld_ch_v Value
        ld_b_v (CH), (Value)
    .endmacro

    ;;; summary: LoaD CX from constant word Value
    ;;; result: CX = Value
    ;;; changed: A+ N+ Z+
    .macro ld_cx_v Value
        ld_w_v (CX), (Value)
    .endmacro

    ;;; summary: LoaD DL from constant byte Value
    ;;; result: DL = Value
    ;;; changed: A+ N+ Z+
    .macro ld_dl_v Value
        ld_b_v (DL), (Value)
    .endmacro

    ;;; summary: LoaD DH from constant byte Value
    ;;; result: DH = Value
    ;;; changed: A+ N+ Z+
    .macro ld_dh_v Value
        ld_b_v (DH), (Value)
    .endmacro

    ;;; summary: LoaD DX from constant word Value
    ;;; result: DX = Value
    ;;; changed: A+ N+ Z+
    .macro ld_dx_v Value
        ld_w_v (DX), (Value)
    .endmacro

;endregion

;region Synthetic instuctions - Clear

    ;;; summary: Clear A
    ;;; result: A = 0
    ;;; changed: A+ N0 Z1
    .macro clr_a
        ld_a_v (0)
    .endmacro

    ;;; summary: Clear X
    ;;; result: X = 0
    ;;; changed: X+ N0 Z1
    .macro clr_x
        ld_x_v (0)
    .endmacro

    ;;; summary: Clear Y
    ;;; result: Y = 0
    ;;; changed: Y+ N0 Z1
    .macro clr_y
        ld_y_v (0)
    .endmacro

    ;;; summary: Clear Byte memory
    ;;; result: [M]:b = 0
    ;;; changed: [M]+ N0 Z1
    .macro clr_b M
        ld_b_v (M), (0)
    .endmacro

    ;;; summary: Clear Word memory
    ;;; result: [M]:w = 0
    ;;; changed: [M], N0 , Z1
    .macro clr_w M
        clr_a
        sta 0 + (M)
        sta 1 + (M)
    .endmacro

    ;;; summary: Clear AL
    ;;; result: AL = 0
    ;;; changed: AL, N0 , Z1
    .macro clr_al
        clr_b (AL)
    .endmacro

    ;;; summary: Clear AH
    ;;; result: AH = 0
    ;;; changed: AH, N0 , Z1
    .macro clr_ah
        clr_b (AH)
    .endmacro

    ;;; summary: Clear AX
    ;;; result: AX = 0
    ;;; changed: AX+ N0 Z1
    .macro clr_ax
        clr_w (AX)
    .endmacro

    ;;; summary: Clear BL
    ;;; result: BL = 0
    ;;; changed: BL+ N0 Z1
    .macro clr_bl
        clr_b (BL)
    .endmacro

    ;;; summary: Clear BH
    ;;; result: BH = 0
    ;;; changed: BH, N0 , Z1
    .macro clr_bh
        clr_b (BH)
    .endmacro

    ;;; summary: Clear BX
    ;;; result: BX = 0
    ;;; changed: BX, N0 , Z1
    .macro clr_bx
        clr_w (BX)
    .endmacro

    ;;; summary: Clear CL
    ;;; result: CL = 0
    ;;; changed: CL+ N0 Z1
    .macro clr_cl
        clr_b (CL)
    .endmacro

    ;;; summary: Clear CH
    ;;; result: CH = 0
    ;;; changed: CH, N0 , Z1
    .macro clr_ch
        clr_b (CH)
    .endmacro

    ;;; summary: Clear CX
    ;;; result: CX = 0
    ;;; changed: CX, N0 , Z1
    .macro clr_cx
        clr_w (CX)
    .endmacro

    ;;; summary: Clear DL
    ;;; result: DL = 0
    ;;; changed: DL, N0 , Z1
    .macro clr_dl
        clr_b (DL)
    .endmacro


    ;;; summary: Clear DH
    ;;; result: DH = 0
    ;;; changed: DH, N0 , Z1
    .macro clr_dh
        clr_b (DH)
    .endmacro

    ;;; summary: Clear DX
    ;;; result: DX = 0
    ;;; changed: DX, N0 , Z1
    .macro clr_dx
        clr_w (DX)
    .endmacro

;endregion

;region Synthetic instuctions - Load memory values

    ;;; summary: LoaD memory Target from memory Source Byte
    ;;; result: [Target] <- [Source]
    ;;; changed: A , N+ , Z+
    .macro ld_b Target, Source
        lda 0 + (Source)
        sta 0 + (Target)
    .endmacro

    ;;; summary: LoaD memory Target from memory Source Word
    ;;; result: [Target]:w <- [Source]:w
    ;;; changed: A , N+ , Z+
    .macro ld_w Target, Source
        lda 0 + (Source)
        sta 0 + (Target)
        lda 1 + (Source)
        sta 1 + (Target)
    .endmacro

    ;;; summary: LoaD AL from byte Source
    ;;; result: AL <- [Source]
    ;;; changed: A , N+ , Z+
    .macro ld_al Source
        ld_b (AL), (Source)
    .endmacro

    ;;; summary: LoaD AH from byte Source
    ;;; result: AH <- [Source]
    ;;; changed: A , N+ , Z+
    .macro ld_ah Source
        ld_b (AH), (Source)
    .endmacro

    ;;; summary: LoaD AX from word Source
    ;;; result: AX <- [Source]:w
    ;;; changed: A , N+ , Z+
    .macro ld_ax Source
        ld_w (AX), (Source)
    .endmacro

    ;;; summary: LoaD BL from Source
    ;;; result: BL <- [Source]
    ;;; changed: A , N+ , Z+
    .macro ldbl Source
        ld_b (BL), (Source)
    .endmacro

    ;;; summary: LoaD BH from Source
    ;;; result: BH <- [Source]
    ;;; changed: A , N+ , Z+
    .macro ldbh Source
        ld_b (BH), (Source)
    .endmacro

    ;;; summary: LoaD BX from Source
    ;;; result: BX <- [Source]:w
    ;;; changed: A , N+ , Z+
    .macro ldbx Source
        ld_w (BX), (Source)
    .endmacro

    ;;; summary: LoaD CL from Source
    ;;; result: CL <- [Source]
    ;;; changed: A , N+ , Z+
    .macro ld_cl Source
        ld_b (CL), (Source)
    .endmacro

    ;;; summary: LoaD CH from Source
    ;;; result: CH <- [Source]
    ;;; changed: A , N+ , Z+
    .macro ld_ch Source
        ld_b (CH), (Source)
    .endmacro

    ;;; summary: LoaD CX from Source
    ;;; result: CX <- [Source]:w
    ;;; changed: A , N+ , Z+
    .macro ld_cx Source
        ld_w (CX), (Source)
    .endmacro

    ;;; summary: LoaD DL from Source
    ;;; result: DL <- [Source]
    ;;; changed: A , N+ , Z+
    .macro ld_dl Source
        ld_b (DL), (Source)
    .endmacro

    ;;; summary: LoaD DH from Source
    ;;; result: DH <- [Source]
    ;;; changed: A , N+ , Z+
    .macro ld_dh Source
        ld_b (DH), (Source)
    .endmacro

    ;;; summary: LoaD DX from Source
    ;;; result: DX <- [Source]:w
    ;;; changed: A , N+ , Z+
    .macro ld_dx Source
        ld_w (DX), (Source)
    .endmacro

    ;;; summary: LoaD AX from BX
    ;;; result: AX <- BX
    ;;; changed: A , N+ , Z+
    .macro ld_ax_bx
        ld_w (AX), (BX)
    .endmacro

    ;;; summary: LoaD AX from CX
    ;;; result: AX <- CX
    ;;; changed: A , N+ , Z+
    .macro ld_ax_cx
        ld_w (AX), (CX)
    .endmacro

    ;;; summary: LoaD AX from DX
    ;;; result: AX <- DX
    ;;; changed: A , N+ , Z+
    .macro ld_ax_dx
        ld_w (AX), (DX)
    .endmacro

    ;;; summary: LoaD BX from AX
    ;;; result: BX <- AX
    ;;; changed: A , N+ , Z+
    .macro ld_bx_ax
        ld_w (BX), (AX)
    .endmacro

    ;;; summary: LoaD BX from CX
    ;;; result: BX <- CX
    ;;; changed: A , N+ , Z+
    .macro ld_bx_cx
        ld_w (BX), (CX)
    .endmacro

    ;;; summary: LoaD BX from DX
    ;;; result: BX <- DX
    ;;; changed: A , N+ , Z+
    .macro ld_bx_dx
        ld_w (BX), (DX)
    .endmacro

    ;;; summary: LoaD CX from AX
    ;;; result: CX <- AX
    ;;; changed: A , N+ , Z+
    .macro ld_cx_ax
        ld_w (CX), (AX)
    .endmacro

    ;;; summary: LoaD CX from BX
    ;;; result: CX <- BX
    ;;; changed: A , N+ , Z+
    .macro ld_cx_bx
        ld_w (CX), (BX)
    .endmacro

    ;;; summary: LoaD CX from DX
    ;;; result: CX <- DX
    ;;; changed: A , N+ , Z+
    .macro ld_cx_dx
        ld_w (CX), (DX)
    .endmacro

    ;;; summary: LoaD DX from AX
    ;;; result: DX <- AX
    ;;; changed: A , N+ , Z+
    .macro ld_dx_ax
        ld_w (DX), (AX)
    .endmacro

    ;;; summary: LoaD DX from BX
    ;;; result: DX <- BX
    ;;; changed: A , N+ , Z+
    .macro ld_dx_bx
        ld_w (DX), (BX)
    .endmacro

    ;;; summary: LoaD DX from CX
    ;;; result: DX <- CX
    ;;; changed: A , N+ , Z+
    .macro ld_dx_cx
        ld_w (DX), (CX)
    .endmacro

    ;;; summary: LoaD AL from AH
    ;;; result: AL <- AH
    ;;; changed: A , N+ , Z+
    .macro ld_al_ah
        ld_b (AL), (AH)
    .endmacro

    ;;; summary: LoaD AL from BL
    ;;; result: AL <- BL
    ;;; changed: A , N+ , Z+
    .macro ld_al_bl
        ld_b (AL), (BL)
    .endmacro

    ;;; summary: LoaD AL from BH
    ;;; result: AL <- BH
    ;;; changed: A , N+ , Z+
    .macro ld_al_bh
        ld_b (AL), (BH)
    .endmacro

    ;;; summary: LoaD AL from CL
    ;;; result: AL <- CL
    ;;; changed: A , N+ , Z+
    .macro ld_al_cl
        ld_b (AL), (CL)
    .endmacro

    ;;; summary: LoaD AL from CH
    ;;; result: AL <- CH
    ;;; changed: A , N+ , Z+
    .macro ld_al_ch
        ld_b (AL), (CH)
    .endmacro

    ;;; summary: LoaD AL from DL
    ;;; result: AL <- DL
    ;;; changed: A , N+ , Z+
    .macro ld_al_dl
        ld_b (AL), (DL)
    .endmacro

    ;;; summary: LoaD AL from DH
    ;;; result: AL <- DH
    ;;; changed: A , N+ , Z+
    .macro ld_al_dh
        ld_b (AL), (DH)
    .endmacro

    ;;; summary: LoaD AH from AL
    ;;; result: AH <- AL
    ;;; changed: A , N+ , Z+
    .macro ldahal
        ld_b (AH), (AL)
    .endmacro

    ;;; summary: LoaD AH from BL
    ;;; result: AH <- BL
    ;;; changed: A , N+ , Z+
    .macro ld_ah_bl
        ld_b (AH), (BL)
    .endmacro

    ;;; summary: LoaD AH from BH
    ;;; result: AH <- BH
    ;;; changed: A , N+ , Z+
    .macro ld_ah_bh
        ld_b (AH), (BH)
    .endmacro

    ;;; summary: LoaD AH from CL
    ;;; result: AH <- CL
    ;;; changed: A , N+ , Z+
    .macro ld_ah_cl
        ld_b (AH), (CL)
    .endmacro

    ;;; summary: LoaD AH from CH
    ;;; result: AH <- CH
    ;;; changed: A , N+ , Z+
    .macro ld_ah_ch
        ld_b (AH), (CH)
    .endmacro

    ;;; summary: LoaD AH from DL
    ;;; result: AH <- DL
    ;;; changed: A , N+ , Z+
    .macro ld_ah_dl
        ld_b (AH), (DL)
    .endmacro

    ;;; summary: LoaD AH from DH
    ;;; result: AH <- DH
    ;;; changed: A , N+ , Z+
    .macro ld_ah_dh
        ld_b (AH), (DH)
    .endmacro

    ;;; summary: LoaD BL from AL
    ;;; result: BL <- AL
    ;;; changed: A , N+ , Z+
    .macro ld_bl_al
        ld_b (BL), (AL)
    .endmacro

    ;;; summary: LoaD BL from AH
    ;;; result: BL <- AH
    ;;; changed: A , N+ , Z+
    .macro ld_bl_ah
        ld_b (BL), (AH)
    .endmacro

    ;;; summary: LoaD BL from BH
    ;;; result: BL <- BH
    ;;; changed: A , N+ , Z+
    .macro ld_bl_bh
        ld_b (BL), (BH)
    .endmacro

    ;;; summary: LoaD BL from CL
    ;;; result: BL <- CL
    ;;; changed: A , N+ , Z+
    .macro ld_bl_cl
        ld_b (BL), (CL)
    .endmacro

    ;;; summary: LoaD BL from CH
    ;;; result: BL <- CH
    ;;; changed: A , N+ , Z+
    .macro ld_bl_ch
        ld_b (BL), (CH)
    .endmacro

    ;;; summary: LoaD BL from DL
    ;;; result: BL <- DL
    ;;; changed: A , N+ , Z+
    .macro ld_bl_dl
        ld_b (BL), (DL)
    .endmacro

    ;;; summary: LoaD BL from DH
    ;;; result: BL <- DH
    ;;; changed: A , N+ , Z+
    .macro ld_bl_dh
        ld_b (BL), (DH)
    .endmacro

    ;;; summary: LoaD BH from AL
    ;;; result: BH <- AL
    ;;; changed: A , N+ , Z+
    .macro ld_bh_al
        ld_b (BH), (AL)
    .endmacro

    ;;; summary: LoaD BH from AH
    ;;; result: BH <- AH
    ;;; changed: A , N+ , Z+
    .macro ld_bh_ah
        ld_b (BH), (AH)
    .endmacro

    ;;; summary: LoaD BH from BL
    ;;; result: BH <- BL
    ;;; changed: A , N+ , Z+
    .macro ld_bh_bl
        ld_b (BH), (BL)
    .endmacro

    ;;; summary: LoaD BH from CL
    ;;; result: BH <- CL
    ;;; changed: A , N+ , Z+
    .macro ld_bh_cl
        ld_b (BH), (CL)
    .endmacro

    ;;; summary: LoaD BH from CH
    ;;; result: BH <- CH
    ;;; changed: A , N+ , Z+
    .macro ld_bh_ch
        ld_b (BH), (CH)
    .endmacro

    ;;; summary: LoaD BH from DL
    ;;; result: BH <- DL
    ;;; changed: A , N+ , Z+
    .macro ld_bh_dl
        ld_b (BH), (DL)
    .endmacro

    ;;; summary: LoaD BH from DH
    ;;; result: BH <- DH
    ;;; changed: A , N+ , Z+
    .macro ld_bh_dh
        ld_b (BH), (DH)
    .endmacro

    ;;; summary: LoaD CL from AL
    ;;; result: CL <- AL
    ;;; changed: A , N+ , Z+
    .macro ld_cl_al
        ld_b (CL), (AL)
    .endmacro

    ;;; summary: LoaD CL from AH
    ;;; result: CL <- AH
    ;;; changed: A , N+ , Z+
    .macro ld_cl_ah
        ld_b (CL), (AH)
    .endmacro

    ;;; summary: LoaD CL from BL
    ;;; result: CL <- BL
    ;;; changed: A , N+ , Z+
    .macro ld_cl_bl
        ld_b (CL), (BL)
    .endmacro

    ;;; summary: LoaD CL from BH
    ;;; result: CL <- BH
    ;;; changed: A , N+ , Z+
    .macro ld_cl_bh
        ld_b (CL), (BH)
    .endmacro

    ;;; summary: LoaD CL from CH
    ;;; result: CL <- CH
    ;;; changed: A , N+ , Z+
    .macro ld_cl_ch
        ld_b (CL), (CH)
    .endmacro

    ;;; summary: LoaD CL from DL
    ;;; result: CL <- DL
    ;;; changed: A , N+ , Z+
    .macro ld_cl_dl
        ld_b (CL), (DL)
    .endmacro

    ;;; summary: LoaD CL from DH
    ;;; result: CL <- DH
    ;;; changed: A , N+ , Z+
    .macro ld_cl_dh
        ld_b (CL), (DH)
    .endmacro

    ;;; summary: LoaD CH from AL
    ;;; result: CH <- AL
    ;;; changed: A , N+ , Z+
    .macro ld_ch_al
        ld_b (CH), (AL)
    .endmacro

    ;;; summary: LoaD CH from AH
    ;;; result: CH <- AH
    ;;; changed: A , N+ , Z+
    .macro ld_ch_ah
        ld_b (CH), (AH)
    .endmacro

    ;;; summary: LoaD CH from BL
    ;;; result: CH <- BL
    ;;; changed: A , N+ , Z+
    .macro ld_ch_bl
        ld_b (CH), (BL)
    .endmacro

    ;;; summary: LoaD CH from BH
    ;;; result: CH <- BH
    ;;; changed: A , N+ , Z+
    .macro ld_ch_bh
        ld_b (CH), (BH)
    .endmacro

    ;;; summary: LoaD CH from CL
    ;;; result: CH <- CL
    ;;; changed: A , N+ , Z+
    .macro ld_ch_cl
        ld_b (CH), (CL)
    .endmacro

    ;;; summary: LoaD CH from DL
    ;;; result: CH <- DL
    ;;; changed: A , N+ , Z+
    .macro ld_ch_dl
        ld_b (CH), (DL)
    .endmacro

    ;;; summary: LoaD CH from DH
    ;;; result: CH <- DH
    ;;; changed: A , N+ , Z+
    .macro ld_ch_dh
        ld_b (CH), (DH)
    .endmacro

    ;;; summary: LoaD DL from AL
    ;;; result: DL <- AL
    ;;; changed: A , N+ , Z+
    .macro ld_dl_al
        ld_b (DL), (AL)
    .endmacro

    ;;; summary: LoaD DL from AH
    ;;; result: DL <- AH
    ;;; changed: A , N+ , Z+
    .macro ld_dl_ah
        ld_b (DL), (AH)
    .endmacro

    ;;; summary: LoaD DL from BL
    ;;; result: DL <- BL
    ;;; changed: A , N+ , Z+
    .macro ld_dl_bl
        ld_b (DL), (BL)
    .endmacro

    ;;; summary: LoaD DL from BH
    ;;; result: DL <- BH
    ;;; changed: A , N+ , Z+
    .macro ld_dl_bh
        ld_b (DL), (BH)
    .endmacro

    ;;; summary: LoaD DL from CL
    ;;; result: DL <- CL
    ;;; changed: A , N+ , Z+
    .macro ld_dl_cl
        ld_b (DL), (CL)
    .endmacro

    ;;; summary: LoaD DL from CH
    ;;; result: DL <- CH
    ;;; changed: A , N+ , Z+
    .macro ld_dl_ch
        ld_b (DL), (CH)
    .endmacro

    ;;; summary: LoaD DL from DH
    ;;; result: DL <- DH
    ;;; changed: A , N+ , Z+
    .macro ld_dl_dh
        ld_b (DL), (DH)
    .endmacro

    ;;; summary: LoaD DH from AL
    ;;; result: DH <- AL
    ;;; changed: A , N+ , Z+
    .macro ld_dh_al
        ld_b (DH), (AL)
    .endmacro

    ;;; summary: LoaD DH from AH
    ;;; result: DH <- AH
    ;;; changed: A , N+ , Z+
    .macro ld_dh_ah
        ld_b (DH), (AH)
    .endmacro

    ;;; summary: LoaD DH from BL
    ;;; result: DH <- BL
    ;;; changed: A , N+ , Z+
    .macro ld_dh_bl
        ld_b (DH), (BL)
    .endmacro

    ;;; summary: LoaD DH from BH
    ;;; result: DH <- BH
    ;;; changed: A , N+ , Z+
    .macro ld_dh_bh
        ld_b (DH), (BH)
    .endmacro

    ;;; summary: LoaD DH from CL
    ;;; result: DH <- CL
    ;;; changed: A , N+ , Z+
    .macro ld_dh_cl
        ld_b (DH), (CL)
    .endmacro

    ;;; summary: LoaD DH from CH
    ;;; result: DH <- CH
    ;;; changed: A , N+ , Z+
    .macro ld_dh_ch
        ld_b (DH), (CH)
    .endmacro

    ;;; summary: LoaD DH from DL
    ;;; result: DH <- DL
    ;;; changed: A , N+ , Z+
    .macro ld_dh_dl
        ld_b (DH), (DL)
    .endmacro

;endregion

;region Synthetic instuctions - Store constant values (mirror images from Load constant values)

    ;;; summary: STore byte Value into A
    ;;; result: A = Value
    ;;; changed: N+ , Z+
    .macro st_v_a Value
        ld_a_v (Value)
    .endmacro

    ;;; summary: STore byte Value into X
    ;;; result: X = Value
    ;;; changed: N+ , Z+
    .macro st_v_x Value
        ld_x_v (Value)
    .endmacro

    ;;; summary: STore byte Value into Y
    ;;; result: Y = Value
    ;;; changed: N+ , Z+
    .macro st_v_y Value
        ld_y_v (Value)
    .endmacro

    ;;; summary: STore Value to Target Byte
    ;;; result: [Target] = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_b Value, Target
        ld_b_v (Target), (Value)
    .endmacro

    ;;; summary: STore Value Word
    ;;; result: [Target]:w = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_w Value, Target
        ld_w_v (Target), (Value)
    .endmacro

    ;;; summary: STore byte Value into AL
    ;;; result: AL = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_al Value
        ld_al_v (Value)
    .endmacro

    ;;; summary: STore byte Value into AH
    ;;; result: AH = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_ah Value
        ld_ah_v (Value)
    .endmacro

    ;;; summary: STore word Value into AX
    ;;; result: AX = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_ax Value
        ld_ax_v (Value)
    .endmacro

    ;;; summary: STore byte Value into BL
    ;;; result: BL = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_bl Value
        ld_bl_v (Value)
    .endmacro

    ;;; summary: STore byte Value into BH
    ;;; result: BH = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_bh Value
        ld_bh_v (Value)
    .endmacro

    ;;; summary: STore word Value into BX
    ;;; result: BX = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_bx Value
        ld_bx_v (Value)
    .endmacro

    ;;; summary: STore byte Value into CL
    ;;; result: CL = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_cl Value
        ld_cl_v (Value)
    .endmacro

    ;;; summary: STore byte Value into CH
    ;;; result: CH = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_ch Value
        ld_ch_v (Value)
    .endmacro

    ;;; summary: STore word Value into CX
    ;;; result: CX = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_cx Value
        ld_cx_v (Value)
    .endmacro

    ;;; summary: STore byte Value into DL
    ;;; result: DL = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_dl Value
        ld_dl_v (Value)
    .endmacro

    ;;; summary: STore byte Value into DH
    ;;; result: DH = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_dh Value
        ld_dh_v (Value)
    .endmacro

    ;;; summary: STore word Value into DX
    ;;; result: DX = Value
    ;;; changed: A , N+ , Z+
    .macro st_v_dx Value
        ld_dx_v (Value)
    .endmacro

;endregion

;region Synthetic instuctions - Store memory values (mirror images from Load memory values)

    ;;; summary: STore memory Source into Target Byte
    ;;; result: [Target] <- [Source]
    ;;; changed: A , N+ , Z+
    .macro st_b Source, Target
        ld_b (Target), (Source)
    .endmacro

    ;;; summary: Store memory Source into Target Word
    ;;; result: [Target]:w <- [Source]:w
    ;;; changed: A , N+ , N+
    .macro st_w Source, Target
        ld_w (Target), (Source)
    .endmacro

    ;;; summary: STore AL into Target Byte
    ;;; result: [Target] <- AL
    ;;; changed: A , N+ , Z+
    .macro st_al Target
        st_b (AL), (Target)
    .endmacro

    ;;; summary: STore AH into Target Byte
    ;;; result: [Target] <- AH
    ;;; changed: A , N+ , Z+
    .macro st_ah Target
        st_b (AH), (Target)
    .endmacro

    ;;; summary: STore AX into Target Word
    ;;; result: [Target]:w <- AX
    ;;; changed: A , N+ , Z+
    .macro st_ax Target
        st_w (AX), (Target)
    .endmacro

    ;;; summary: STore BL into Target Byte
    ;;; result: [Target] <- BL
    ;;; changed: A , N+ , Z+
    .macro st_bl Target
        st_b (BL), (Target)
    .endmacro

    ;;; summary: STore BH into Target Byte
    ;;; result: [Target] <- BH
    ;;; changed: A , N+ , Z+
    .macro st_bh Target
        st_b (BH), (Target)
    .endmacro

    ;;; summary: STore BX into Target Word
    ;;; result: [Target]:w <- BX
    ;;; changed: A , N+ , Z+
    .macro st_bx Target
        st_w (BX), (Target)
    .endmacro

    ;;; summary: STore CL into Target Byte
    ;;; result: [Target] <- CL
    ;;; changed: A , N+ , Z+
    .macro st_cl Target
        st_b (CL), (Target)
    .endmacro

    ;;; summary: STore CH into Target Byte
    ;;; result: [Target] <- CH
    ;;; changed: A , N+ , Z+
    .macro st_ch Target
        st_b (CH), (Target)
    .endmacro

    ;;; summary: STore CX into Target Word
    ;;; result: [Target]:w <- CX
    ;;; changed: A , N+ , Z+
    .macro st_cx Target
        st_w (CX), (Target)
    .endmacro

    ;;; summary: STore DL into Target Byte
    ;;; result: [Target] <- DL
    ;;; changed: A , N+ , Z+
    .macro st_dl Target
        st_b (DL), (Target)
    .endmacro

    ;;; summary: STore DH into Target Byte
    ;;; result: [Target] <- DH
    ;;; changed: A , N+ , Z+
    .macro st_dh Target
        st_b (DH), (Target)
    .endmacro

    ;;; summary: STore DX into Target Word
    ;;; result: [Target]:w <- DX
    ;;; changed: A , N+ , Z+
    .macro st_dx Target
        st_w (DX), (Target)
    .endmacro

;endregion

;region Synthetic instuctions - Math

    ;;; summary: Reverse subtract A Value
    ;;; result: A <- Value - A
    ;;; bytes: 5-6
    ;;; cycles: 4-10
    .macro revsub_a_v Value
        oca
        sec
        adc # 0 + (Value)
    .endmacro

    ;;; summary: Reverse subtract A memory Byte
    ;;; result: A <- [M] - A
    ;;; bytes: 5-6
    ;;; cycles: 4-10
    .macro revsub_a M
        oca
        sec
        adc 0 + (M)
    .endmacro

    ;;; summary: INcrement memory Word
    ;;; result: [M]:w <- [M]:w + 1
    ;;; bytes: zp: 6 , ab: 8
    ;;; cycles: zp: 12-14 , ab: 14-16
    ;;; changed: Z=0 unless you inc $FFFF
    .macro inc_w M
        inc 0 + (M)
        bne :+
        inc 1 + (M)
        :
    .endmacro

    .macro inc_ax
        inc_w (AX)
    .endmacro

    .macro inc_bx
        inc_w (BX)
    .endmacro

    .macro inc_cx
        inc_w (CX)
    .endmacro

    .macro inc_dx
        inc_w (DX)
    .endmacro

    ;;; summary: DEcrement memory Word
    ;;; result: [M]:w <- [M]:w - 1
    .macro dec_w M
        lda 0 + (M)
        bne :+
        dec 1 + (M)
        :
        dec 0 + (M)
    .endmacro

    .macro dec_ax
        dec_w (AX)
    .endmacro

    .macro dec_bx
        dec_w (BX)
    .endmacro

    .macro dec_cx
        decw (CX)
    .endmacro

    .macro dec_dx
        decw (DX)
    .endmacro

    ;;; summary: add to unsigned word the signed byte in A
    ;;; result: [UW]:uw <- [UW]:uw + A:sb
    ;;; see: http://forums.nesdev.com/viewtopic.php_?t=10975
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
    .macro add_al_a
        clc
        adc (AL)
        sta (AL)
    .endmacro

    ;;; summary: Add to AH value of A (with clear C)
    ;;; result: AH <- A + AH with C=0
    .macro add_ah_a
        clc
        adc (AH)
        sta (AH)
    .endmacro

    ;;; summary: Add to BL value of A (with clear C)
    ;;; result: BL <- A + BL with C=0
    .macro add_bl_a
        clc
        adc (BL)
        sta (BL)
    .endmacro

    ;;; summary: Add to BH value of A (with clear C)
    ;;; result: BH <- A + BH with C=0
    .macro add_bh_a
        clc
        adc (BH)
        sta (BH)
    .endmacro

    ;;; summary: Add to CL value of A (with clear C)
    ;;; result: CL <- A + CL with C=0
    .macro add_cl_a
        clc
        adc (CL)
        sta (CL)
    .endmacro

    ;;; summary: Add to CH value of A (with clear C)
    ;;; result: CH <- A + CH with C=0
    .macro add_ch_a
        clc
        adc (CH)
        sta (CH)
    .endmacro

    ;;; summary: Add to DL value of A (with clear C)
    ;;; result: DL <- A + DL with C=0
    .macro add_dl_a
        clc
        adc (DL)
        sta (DL)
    .endmacro

    ;;; summary: Add to DH value of A (with clear C)
    ;;; result: DH <- A + DH with C=0
    .macro add_dh_a
        clc
        adc (DH)
        sta (DH)
    .endmacro

    ;;; summary: Add to AX the constant value V
    .macro add_ax_v Value
        clc
        lda (AL)
        adc # < (Value)
        sta (AL)
        lda (AH)
        adc # > (Value)
        sta (AH)
    .endmacro

    ;;; summary: Add to BX the constant value V
    .macro add_bx_v Value
        clc
        lda (BL)
        adc # < (Value)
        sta (BL)
        lda (BH)
        adc # > (Value)
        sta (BH)
    .endmacro

    ;;; summary: Add to CX the constant value V
    .macro add_cx_v Value
        clc
        lda (CL)
        adc # < (Value)
        sta (CL)
        lda (CH)
        adc # > (Value)
        sta (CH)
    .endmacro

    ;;; summary: Add to DX the constant value V
    .macro add_dx_v Value
        clc
        lda (DL)
        adc # < (Value)
        sta (DL)
        lda (DH)
        adc # > (Value)
        sta (DH)
    .endmacro

;endregion

;region Synthetic instuctions - Control flow

    ;;; summary JuMP to address stored at M + X (Absolute indexed by X)
    ;;; result: PC <- [M + X]:w
    ;;; bytes:  zp:  8 , ab: 10
    ;;; cycles: zp: 23 , ab: 23-26
    .macro jmp_ax M
        lda 1 + (M),x
        pha
        lda 0 + (M),x
        pha
        php_
        rti
    .endmacro

    ;;; summary: Skip next byte
    ;;; changed: N+ V+ Z+
    ;;; notes: C-
    .macro skip_1
        .byte OPCODE_BIT_ZP
    .endmacro

    ;;; summary: Skip next 2 bytes
    ;;; changed: N+ V+ Z+
    ;;; notes: C-
    .macro skip_2
        .byte OPCODE_BIT_AB
    .endmacro

;endregion

;region Synthetic instructions - Frame

    ; TODO: FRAME_DECLARE_*, php_*, plp_* will this work correctly with interrupts?
    
    ;;; summary: Restore RSP cache
    ;;; result: X <- [RSP]
    .macro RESTORE_RSP
        ldx RSP
    .endmacro

    ;;; summary: Restore FP cache
    ;;; result: X <- [FP]
    .macro RESTORE_FP
        ldx FP
    .endmacro

    ;;; summary: Begin pushing parameters
    ;;; result: X <- [RSP]
    .macro BEGIN_PUSH
        ldx RSP
    .endmacro

    ;;; summary: End pushing parameters
    ;;; result: [RSP] <- X
    .macro END_PUSH
        stx (RSP)
    .endmacro

    ;;; summary: Reset frame  discard any pushed parameters
    ;;; result: [FP] -> [FPP] , X = [FP] = [RSP]
    ;;; bytes: 
    ;;; cycles: 
    .macro RESET_FRAME
        ldx (FP)
        stx (RSP)
    .endmacro

    ;;; summary: Declare 1 local variable
    ;;; bytes: 
    ;;; cycles: 
    .macro FRAME_DECLARE_1_LOCAL_VAR
        inx
        stx (FP)
        stx (RSP)
    .endmacro

    .macro FRAME_DECLARE_1_LOCAL_VAR_INIT_0
        lda # 0
        sta 0 , x
        inx
        stx (FP)
        stx (RSP)
    .endmacro

    ;;; summary: Declare 2 local variables
    ;;; bytes: 
    ;;; cycles: 
    .macro FRAME_DECLARE_2_LOCAL_VAR
        inx
        inx
        stx (FP)
        stx (RSP)
    .endmacro

    .macro FRAME_DECLARE_2_LOCAL_VAR_INIT_0
        lda # 0
        sta 0 , x
        inx
        sta 0 , x
        inx
        stx (FP)
        stx (RSP)
    .endmacro

    ;;; summary: Declare 3 local variables
    ;;; bytes: 
    ;;; cycles: 
    .macro FRAME_DECLARE_3_LOCAL_VAR
        inx
        inx
        inx
        stx (FP)
        stx (RSP)
    .endmacro

    .macro FRAME_DECLARE_3_LOCAL_VAR_INIT_0
        lda # 0
        sta 0 , x
        inx
        sta 0 , x
        inx
        sta 0 , x
        inx
        stx (FP)
        stx (RSP)
    .endmacro

    ;;; summary: Declare 4 local variables
    ;;; bytes: 8
    ;;; cycles: 14
    .macro FRAME_DECLARE_4_LOCAL_VAR
        inx
        inx
        inx
        inx
        stx (FP)
        stx (RSP)
    .endmacro

    .macro FRAME_DECLARE_4_LOCAL_VAR_INIT_0
        lda # 0
        sta 0 , x
        inx
        sta 0 , x
        inx
        sta 0 , x
        inx
        sta 0 , x
        inx
        stx (FP)
        stx (RSP)
    .endmacro

    ;;; summary: Declare N local variables, best for N >= 5
    ;;; bytes: 9
    ;;; cycles: 14
    .macro FRAME_DECLARE_N_LOCAL_VAR Count
        txa
        clc
        adc # (Count)
        txa
        stx (FP)
        stx (RSP)
    .endmacro

;endregion

;region Synthetic instructions - Push parameter constant values

    ;;; summary: PusH Parameter Value Byte
    ;;; result: [old X] <- Value , X = old X + 1
    ;;; changed: A , N+ , Z+
    .macro php_v_b Value
        lda # (Value)
        inc RSP
        ldx RSP
        sta z: < -1 , x
    .endmacro

    ;;; summary: PusH Parameter Value Byte
    ;;; result: [old X] <- Value , X = old X + 1
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_v_b_ex Value
        lda # (Value)
        inx
        sta z: < -1 , x
    .endmacro

    ;;; summary: PusH Parameter Value Word
    ;;; result: [old X]w = Value:w , X = old X + 2
    ;;; changed: A , N+ , Z+
    .macro php_v_w Value
        lda # < (Value)
        inc RSP
        ldx RSP
        sta z: < -1 , x
        lda # > (Value)
        inc RSP
        inx
        sta z: < -1 , x
    .endmacro

    ;;; summary: PusH Parameter Value Word
    ;;; result: [old X]w = Value:w , X = old X + 2
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_v_w_ex Value
        lda # < (Value)
        inx
        sta z: < -1 , x
        lda # > (Value)
        inx
        sta z: < -1 , x
    .endmacro

;endregion

;region Synthetic instructions - Push parameter registers, memory

    ;;; summary:  PusH Parameter A
    ;;; result: [old X] = A, X = old X + 1
    ;;; changed: N+ , Z+
    .macro php_a
        inc RSP
        ldx RSP
        sta z: < -1 , x
    .endmacro

    ;;; summary:  PusH Parameter A
    ;;; result: [old X] = A, X = old X + 1
    ;;; changed: N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_a_ex
        inx
        sta z: < -1 , x
    .endmacro

    ;;; summary:  PusH Parameter Y
    ;;; result: [old X] = Y , X = old X + 1
    ;;; changed: P:N+Z+
    ;;; changed: N+ , Z+
    .macro php_y
        inc RSP
        ldx RSP
        sty z: < -1 , x
    .endmacro

    ;;; summary:  PusH Parameter Y
    ;;; result: [old X] = Y , X = old X + 1
    ;;; changed: P:N+Z+
    ;;; changed: N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_y_ex
        inx
        sty z: < -1 , x
    .endmacro

    ;;; summary: PusH Parameter Byte
    ;;; result: [old X] = [Source] , X = old X + 1
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_b Source
        lda 0 + (Source)
        inc RSP
        ldx RSP
        sta z: < -1,x
    .endmacro

    ;;; summary: PusH Parameter Byte
    ;;; result: [old X] = [Source] , X = old X + 1
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_b_ex Source
        lda 0 + (Source)
        inx
        sta z: < -1,x
    .endmacro

    ;;; summary: PusH Parameter Word
    ;;; result: [old X]:w = [Source]:w , X = old X + 2
    ;;; changed: A , N+ , Z+
    .macro php_w Source
        ; lo
        lda 0 + (Source)
        inc RSP
        ldx RSP
        sta z: < -1 , x
        ; hi
        lda 1 + (Source)
        inc RSP
        inx
        sta z: < -1 , x
    .endmacro

    ;;; summary: PusH Parameter Word
    ;;; result: [old X]:w = [Source]:w , X = old X + 2
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_w_ex Source
        ; lo
        lda 0 + (Source)
        inx
        sta z: < -1 , x
        ; hi
        lda 1 + (Source)
        inx
        sta z: < -1 , x
    .endmacro

    ;;; summary: PusH Parameter AL
    ;;; result: [old X] = AL , X = old X + 1
    ;;; changed: A , N+ , Z+
    .macro php_al
        php_b (AL)
    .endmacro

    ;;; summary: PusH Parameter AL
    ;;; result: [old X] = AL , X = old X + 1
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_al_ex
        php_b_ex (AL)
    .endmacro

    ;;; summary: PusH Parameter AH
    ;;; result: [old X] = AH , X = old X + 1
    ;;; changed: A , N+ , Z+
    .macro php_ah
        php_b (AH)
    .endmacro

    ;;; summary: PusH Parameter AH
    ;;; result: [old X] = AH , X = old X + 1
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_ah_ex
        php_b_ex (AH)
    .endmacro

    ;;; summary: PusH Parameter AX
    ;;; result: [old X]:w = AX , X = old X + 2
    ;;; changed: A , N+ , Z+
    .macro php_ax
        php_w (AX)
    .endmacro

    ;;; summary: PusH Parameter AX
    ;;; result: [old X]:w = AX , X = old X + 2
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_ax_ex
        php_w_ex (AX)
    .endmacro

    ;;; summary: PusH Parameter BL
    ;;; result: [old X] = BL , X = old X + 1
    ;;; changed: A , N+ , Z+
    .macro php_bl
        php_b (BL)
    .endmacro

    ;;; summary: PusH Parameter BL
    ;;; result: [old X] = BL , X = old X + 1
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_bl_ex
        php_b_ex (BL)
    .endmacro

    ;;; summary: PusH Parameter BH
    ;;; result: [old X] = BH , X = old X + 1
    ;;; changed: A , N+ , Z+
    .macro php_bh
        php_b BH
    .endmacro

    ;;; summary: PusH Parameter BH
    ;;; result: [old X] = BH , X = old X + 1
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_bh_ex
        php_b_ex BH
    .endmacro

    ;;; summary: PusH Parameter BX
    ;;; result: [old X]:w = BX , X = old X + 2
    ;;; changed: A , N+ , Z+
    .macro php_bx
        php_w BX
    .endmacro

    ;;; summary: PusH Parameter BX
    ;;; result: [old X]:w = BX , X = old X + 2
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_bx_ex
        php_w_ex BX
    .endmacro

    ;;; summary: PusH Parameter CL
    ;;; result: [old X] = CL , X = old X + 1
    ;;; changed: A , N+ , Z+
    .macro php_cl
        php_b CL
    .endmacro

    ;;; summary: PusH Parameter CL
    ;;; result: [old X] = CL , X = old X + 1
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_cl_ex
        php_b_ex CL
    .endmacro

    ;;; summary: PusH Parameter CH
    ;;; result: [old X] = CH , X = old X + 1
    ;;; changed: A , N+ , Z+
    .macro php_ch
        php_b CH
    .endmacro

    ;;; summary: PusH Parameter CH
    ;;; result: [old X] = CH , X = old X + 1
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_ch_ex
        php_b_ex CH
    .endmacro

    ;;; summary: PusH Parameter CX
    ;;; result: [old X]:w = CX , X = old X + 2
    ;;; changed: A , N+ , Z+
    .macro php_cx
        php_w CX
    .endmacro

    ;;; summary: PusH Parameter CX
    ;;; result: [old X]:w = CX , X = old X + 2
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_cx_ex
        php_w_ex CX
    .endmacro

    ;;; summary: PusH Parameter DL
    ;;; result: [old X] = DL , X = old X + 1
    ;;; changed: A , N+ , Z+
    .macro php_dl
        php_b DL
    .endmacro

    ;;; summary: PusH Parameter DL
    ;;; result: [old X] = DL , X = old X + 1
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_dl_ex
        php_b_ex DL
    .endmacro

    ;;; summary: PusH Parameter DH
    ;;; result: [old X] = DH , X = old X + 1
    ;;; changed: A , N+ , Z+
    .macro php_dh
        php_b DH
    .endmacro

    ;;; summary: PusH Parameter DH
    ;;; result: [old X] = DH , X = old X + 1
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_dh_ex
        php_b_ex DH
    .endmacro

    ;;; summary: PusH Parameter DX
    ;;; result: [old X]:w = DX , X = old X + 2
    ;;; changed: A , N+ , Z+
    .macro php_dx
        php_w DX
    .endmacro

    ;;; summary: PusH Parameter DX
    ;;; result: [old X]:w = DX , X = old X + 2
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro php_dx_ex
        php_w_ex DX
    .endmacro

;endregion

;region Synthetic instructions - Pull parameter registers, memory

    ;;; summary: PuLl Parameter A
    ;;; result: X = old X - 1 , A = [X]
    ;;; changed: N+ , Z+
    .macro plp_a
        ldx RSP
        lda z: < -1,x
        dex
        stx RSP
    .endmacro

    ;;; summary: PuLl Parameter A
    ;;; result: X = old X - 1 , A = [X]
    ;;; changed: N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_a_ex
        lda z: < -1,x
        dex
    .endmacro

    ;;; summary: PuLl Parameter Y
    ;;; result: X = old X - 1 , Y = [X]
    ;;; changed: P:N+Z+
    ;;; changed: N+ , Z+
    .macro plp_y
        ldx RSP
        ldy z: < -1,x
        dex
        stx RSP
    .endmacro

    ;;; summary: PuLl Parameter Y
    ;;; result: X = old X - 1 , Y = [X]
    ;;; changed: P:N+Z+
    ;;; changed: N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_y_ex
        ldy z: < -1,x
        dex
    .endmacro

    ;;; summary: PuLl Parameter Byte
    ;;; result: X = old X - 1 , [Target] = [X]
    ;;; changed: A , N+ , Z+
    .macro plp_b Target
        ldx RSP
        lda z: < -1,x
        sta 0 + (Target)
        dex
        stx RSP
    .endmacro

    ;;; summary: PuLl Parameter Byte
    ;;; result: X = old X - 1 , [Target] = [X]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_b_ex Target
        lda z: < -1,x
        sta 0 + (Target)
        dex
    .endmacro

    ;;; summary: Pull Parameter Word
    ;;; result: X = old X - 2 , [Target]:w = [X]:w
    ;;; changed: A , N+ , Z+
    .macro plp_w Target
        ldx RSP
        lda z: < -1,x
        sta 1 + (Target)
        dex
        lda z: < -1,x
        sta 0 + (Target)
        dex
        stx RSP
    .endmacro

    ;;; summary: Pull Parameter Word
    ;;; result: X = old X - 2 , [Target]:w = [X]:w
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_w_ex Target
        lda z: < -1,x
        sta 1 + (Target)
        dex
        lda z: < -1,x
        sta 0 + (Target)
        dex
    .endmacro

    ;;; summary: Pull Parameter AL
    ;;; result: X = old X - 1 , AL = [X]
    ;;; changed: A , N+ , Z+
    .macro plp_al
        plp_b AL
    .endmacro

    ;;; summary: Pull Parameter AL
    ;;; result: X = old X - 1 , AL = [X]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_al_ex
        plp_b_ex AL
    .endmacro

    ;;; summary: Pull Parameter AH
    ;;; result: X = old X - 1 , AH = [X]
    ;;; changed: A , N+ , Z+
    .macro plp_ah
        plp_b AH
    .endmacro

    ;;; summary: Pull Parameter AH
    ;;; result: X = old X - 1 , AH = [X]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_ah_ex
        plp_b_ex AH
    .endmacro

    ;;; summary: Pull Parameter AX
    ;;; result: X = old X - 2 , AX:w = [X]:w
    ;;; changed: A , N+ , Z+
    .macro plp_ax
        plp_w AX
    .endmacro

    ;;; summary: Pull Parameter AX
    ;;; result: X = old X - 2 , AX:w = [X]:w
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_ax_ex
        plp_w_ex AX
    .endmacro

    ;;; summary: Pull Parameter BL
    ;;; result: X = old X - 1 , BL = [X]
    ;;; changed: A , N+ , Z+
    .macro plp_bl
        plp_b (BL)
    .endmacro

    ;;; summary: Pull Parameter BL
    ;;; result: X = old X - 1 , BL = [X]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_bl_ex
        plp_b_ex (BL)
    .endmacro

    ;;; summary: Pull Parameter BH
    ;;; result: X = old X - 1 , BH = [X]
    ;;; changed: A , N+ , Z+
    .macro plp_bh
        plp_b BH
    .endmacro

    ;;; summary: Pull Parameter BH
    ;;; result: X = old X - 1 , BH = [X]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_bh_ex
        plp_b_ex BH
    .endmacro

    ;;; summary: Pull Parameter BX
    ;;; result: X = old X - 2 , BX:w = [X]:w
    ;;; changed: A , N+ , Z+
    .macro plp_bx
        plp_w BX
    .endmacro

    ;;; summary: Pull Parameter BX
    ;;; result: X = old X - 2 , BX:w = [X]:w
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_bx_ex
        plp_w_ex BX
    .endmacro

    ;;; summary: Pull Parameter CL
    ;;; result: X = old X - 1 , CL = [X]
    ;;; changed: A , N+ , Z+
    .macro plp_cl
        plp_b CL
    .endmacro

    ;;; summary: Pull Parameter CL
    ;;; result: X = old X - 1 , CL = [X]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_cl_ex
        plp_b_ex CL
    .endmacro

    ;;; summary: Pull Parameter CH
    ;;; result: X = old X - 1 , CH = [X]
    ;;; changed: A , N+ , Z+
    .macro plp_ch
        plp_b CH
    .endmacro

    ;;; summary: Pull Parameter CH
    ;;; result: X = old X - 1 , CH = [X]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_ch_ex
        plp_b_ex CH
    .endmacro

    ;;; summary: Pull Parameter CX
    ;;; result: X = old X - 2 , CX:w = [X]:w
    ;;; changed: A , N+ , Z+
    .macro plp_cx
        plp_w CX
    .endmacro

    ;;; summary: Pull Parameter CX
    ;;; result: X = old X - 2 , CX:w = [X]:w
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_cx_ex
        plp_w_ex CX
    .endmacro

    ;;; summary: Pull Parameter DL
    ;;; result: X = old X - 1 , DL = [X]
    ;;; changed: A , N+ , Z+
    .macro plp_dl
        plp_b DL
    .endmacro

    ;;; summary: Pull Parameter DL
    ;;; result: X = old X - 1 , DL = [X]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_dl_ex
        plp_b_ex DL
    .endmacro

    ;;; summary: Pull Parameter DH
    ;;; result: X = old X - 1 , DH = [X]
    ;;; changed: A , N+ , Z+
    .macro plp_dh
        plp_b DH
    .endmacro

    ;;; summary: Pull Parameter DH
    ;;; result: X = old X - 1 , DH = [X]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_dh_ex
        plp_b_ex DH
    .endmacro

    ;;; summary: Pull Parameter DX
    ;;; result: X = old X - 2 , DX:w = [X]:w
    ;;; changed: A , N+ , Z+
    .macro plp_dx
        plp_w DX
    .endmacro

    ;;; summary: Pull Parameter DX
    ;;; result: X = old X - 2 , DX:w = [X]:w
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [RSP]
    .macro plp_dx_ex
        plp_w_ex DX
    .endmacro

;endregion

;region Synthetic instructions - Load Target (A, Y, B, W, al, ...) from parameter

    ;;; summary: LoaD A from Parameter
    ;;; result: A <- [X + parameter]
    ;;; changed: N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_a_p Parameter
        lda z: < (0 + (Parameter)) ,x
    .endmacro

    ;;; summary: LoaD Y from Parameter
    ;;; result: Y <- [X + parameter]
    ;;; changed: N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_y_p Parameter
        ldy z: < (0 + (Parameter)) ,x
    .endmacro

    ;;; summary: LoaD Byte from Parameter
    ;;; result: [Target] <- [X + parameter]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_b_p Target, parameter
        lda z: < (0 + (Parameter)),x
        sta 0 + (Target)
    .endmacro

    ;;; summary: LoaD Word from Parameter
    ;;; result:  [Target]:w <- [X + parameter]:w
    ;;; changed: A , P:N+Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_w_p Target, parameter
        lda z: < (0 + (Parameter)) ,x
        sta 0 + (Target)
        lda z: < (1 + (Parameter)),x
        sta 1 + (Target)
    .endmacro

    ;;; summary: LoaD AL from Parameter
    ;;; result: AL <- [X + parameter]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_al_p Parameter
        ld_b_p AL, (Parameter)
    .endmacro

    ;;; summary: LoaD AH from Parameter
    ;;; result: AH <- [X + parameter]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_ah_p Parameter
        ld_b_p AH, (Parameter)
    .endmacro

    ;;; summary: LoaD AX from Parameter
    ;;; result: AX <- [X + parameter]:w
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_ax_p Parameter
        ld_w_p (AX), (Parameter)
    .endmacro

    ;;; summary: LoaD BL from Parameter
    ;;; result: BL <- [X + parameter]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_bl_p Parameter
        ld_b_p (BL), (Parameter)
    .endmacro

    ;;; summary: LoaD BH from Parameter
    ;;; result: BH <- [X + offset]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_bh_p Parameter
        ld_b_p (BH), (Parameter)
    .endmacro

    ;;; summary: LoaD BX from Parameter
    ;;; result: BX <- [X + offset]:w
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_bx_p Parameter
        ld_w_p (BX), (Parameter)
    .endmacro

    ;;; summary: LoaD CL from Parameter
    ;;; result: CL <- [X + parameter]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_cl_p Parameter
        ld_b_p (CL), (Parameter)
    .endmacro

    ;;; summary: LoaD CH from Parameter
    ;;; result: CH <- [X + parameter]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_ch_p Parameter
        ld_b_p (CH), (Parameter)
    .endmacro

    ;;; summary: LoaD CX from Parameter
    ;;; result: CX <- [X + parameter]:w
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_cx_p Parameter
        ld_w_p (CX), (Parameter)
    .endmacro

    ;;; summary: LoaD DL from Parameter
    ;;; result: DL <- [X + parameter]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_dl_p Parameter
        ld_b_p (DL), (Parameter)
    .endmacro

    ;;; summary: LoaD DH from Parameter
    ;;; result: DH <- [X + parameter]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_dh_p Parameter
        ld_b_p (DH), (Parameter)
    .endmacro

    ;;; summary: LoaD DX from Parameter
    ;;; result: DX <- [X + parameter]:w
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_dx_p Parameter
        ld_w_p (DX), (Parameter)
    .endmacro

    ;;; summary: LoaD Parameter with Value Byte
    ;;; result: [X + parameter] <- Value
    ;;; changed:
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_p_v_b Parameter, Value
        lda # (Value)
        sta z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: LoaD Parameter from Memory address Byte
    ;;; result: [X + parameter] <- [Address]
    ;;; changed:
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ld_p_b Parameter, Address
        lda (Address)
        sta z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: LoaD Target Parameter from Source Parameter (Byte)
    ;;; changed: A+ N+ Z+
    .macro ld_p_p_b Target, Source
        lda z: < (0 + (Source)) , x
        sta z: < (0 + (Target)) , x
    .endmacro

    ;;; summary: LoaD Target Parameter from Source Parameter (Word)
    ;;; changed: A+ N+ Z+
    .macro ld_p_p_w Target, Source
        lda z: < (0 + (Source)) , x
        sta z: < (0 + (Target)) , x
        lda z: < (1 + (Source)),x
        lda z: < (1 + (Target)),x
    .endmacro

;endregion

;region Synthetic instructions - Store soure (A, Y, B, W, al, ...) to parameters

    ;;; summary: STore A into Parameter
    ;;; result: [X + parameter] <- A
    ;;; changed:
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_a_p Parameter
        sta z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: STore Y into Parameter
    ;;; result: [X + parameter] <- Y
    ;;; changed:
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_y_p Parameter
        sty z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: STore Byte into Parameter
    ;;; result: [X + parameter] <- [Source]
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_b_p Source, parameter
        lda 0 + (Source)
        sta z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: STore Word into Parameter
    ;;; result: [X + parameter]:w [Source]:w
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_w_p Source, parameter
        lda 0 + (Source)
        sta z: < (0 + (Parameter)) , x
        lda 1 + (Source)
        sta z: < (1 + (Parameter)) , x
    .endmacro

    ;;; summary: STore AL into Parameter
    ;;; result: [X + parameter] <- AL
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_al_p Parameter
        st_b_p (AL), (Parameter)
    .endmacro

    ;;; summary: STore AH into Parameter
    ;;; result: [X + parameter] <- AH
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_ah_p Parameter
        st_b_p (AH), (Parameter)
    .endmacro

    ;;; summary: STore AX into Parameter
    ;;; result: [X + parameter]:w <- AX
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_ax_p Source
        st_w_p (AX), (Source)
    .endmacro

    ;;; summary: STore BL into Parameter
    ;;; result: [X + parameter] <- BL
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_bl_p Parameter
        st_b_p (BL), (Parameter)
    .endmacro

    ;;; summary: STore BH into Parameter
    ;;; result: [X + parameter] <- BH
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_bh_p Parameter
        st_b_p (BH), (Parameter)
    .endmacro

    ;;; summary: STore BX into Parameter
    ;;; result: [X + parameter]:w <- BX
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_bx_p Parameter
        st_w_p (BX), (Parameter)
    .endmacro

    ;;; summary: STore CL into Parameter
    ;;; result: [X + parameter] <- CL
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_cl_p Parameter
        st_b_p (CL), (Parameter)
    .endmacro

    ;;; summary: STore CH into Parameter
    ;;; result: [X + parameter] <- CH
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_ch_p Parameter
        st_b_p (CH), (Parameter)
    .endmacro

    ;;; summary: STore CX into Parameter
    ;;; result: [X + parameter]:w <- CX
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_cx_p Parameter
        st_w_p (CX), (Parameter)
    .endmacro

    ;;; summary: STore DL into Parameter
    ;;; result: [X + parameter] <- CL
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_dl_p Parameter
        st_b_p (DL), (Parameter)
    .endmacro

    ;;; summary: STore HH into Parameter
    ;;; result: [X + parameter] <- CH
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_dh_p Parameter
        st_b_p (DH), (Parameter)
    .endmacro

    ;;; summary: STore DX into Parameter
    ;;; result: [X + parameter]:w <- DX
    ;;; changed: A , N+ , Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro st_dx_p Parameter
        st_w_p (DX), (Parameter)
    .endmacro

;endregion

;region Synthetic instructions - Parameters operations Byte with A

    ;;; summary: ADd with Carry Parameter to A
    ;;; result: A,C <- A + [X + parameter] + C
    ;;; changed: N+ V+ C+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro adc_p Parameter
        adc z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: ADD with cleared carry Parameter to A
    ;;; result: A,C <- A + [X + parameter] + C
    ;;; changed: N+ V+ C+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro add_p Parameter
        clc
        adc_p (Parameter)
    .endmacro

    ;;; summary: AND of A and value of Parameter to A
    ;;; result: A <- A & [X + parameter]
    ;;; changed: N+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro and_p Parameter
        and z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: CoMPare A with Parameter
    ;;; result: [X + parameter] <- A
    ;;; changed: N+ C+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro cmp_p Parameter
        cmp z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: Exclusive OR A with Parameter to A
    ;;; result: A <- A ^ @parameter
    ;;; changed: N+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro eor_p Parameter
        eor z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: OR A with Parameter to A
    ;;; result: A <- A | @parameter
    ;;; changed: N+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ora_p Parameter
        ora z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: SuBtract with Carry Parameter from A to A
    ;;; result: A <- A - @parameter - C
    ;;; changed: N+ V+ C+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro sbc_p Parameter
        sbc z: < (0 + (Parameter)) , x
    .endmacro

    .macro sub_p Parameter
        sec
        sbc_p (Parameter)
    .endmacro

;endregion

;region Synthetic instructions - Parameters operations Byte

    ;;; summary: Arithmic Shift Left Parameter
    ;;; result: @parameter <- @parameter << 1
    ;;; changed: N+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro asl_p_b Parameter
        asl z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: DECrement Parameter
    ;;; result: @parameter <- @parameter - 1
    ;;; changed: N+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro dec_p_b Parameter
        dec z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: INCrement Parameter
    ;;; result: @parameter <- @parameter + 1
    ;;; changed: N+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro inc_p_b Parameter
        inc z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: Logical Shift Right Parameter (unsigned)
    ;;; result: @parameter <- @parameter >>1
    ;;; changed: N+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro lsr_p_b Parameter
        lsr z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: ROtate Left Parameter
    ;;; result: C <- @parameter[76543210] <- C
    ;;; changed: N+ C+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro rol_p_b Parameter
        rol z: < (0 + (Parameter)) , x
    .endmacro

    ;;; summary: ROtate Right Parameter
    ;;; result: C -> @parameter[76543210] -> C
    ;;; changed: N+ C+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ror_p_b Parameter
        ror z: < (0 + (Parameter)) , x
    .endmacro

;endregion

;region Synthetic instructions - Parameters operations Word

    .macro asl_p_w Parameter
        asl z: < (0 + (Parameter)) , x
        rol z: < (1 + (Parameter)) , x
    .endmacro

    ;;; notes:
    ;;;   Expensive, but we cannot use registers
    .macro dec_p_w Parameter
        inc z: < (0 + (Parameter)) , x
        dec z: < (0 + (Parameter)) , x
        bne :+
            dec z: < (1 + (Parameter)) , x
        :
        dec z: < (0 + (Parameter)) , x
    .endmacro

    .macro inc_p_w Parameter
        inc z: < (0 + (Parameter)) , x
        bne :+
        inc z: < (1 + (Parameter)) , x
        :
    .endmacro

    .macro lsr_p_w Parameter
        lsr z: < (0 + (Parameter)) , x
        ror z: < (1 + (Parameter)) , x
    .endmacro

    ;;; summary: ROtate Left Parameter
    ;;; result: C <- @parameter[76543210] <- C
    ;;; changed: N+ C+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro rol_p_w Parameter
        rol z: < (0 + (Parameter)) , x
        rol z: < (1 + (Parameter)) , x
    .endmacro

    ;;; summary: ROtate Right Parameter
    ;;; result: C -> @parameter[76543210] -> C
    ;;; changed: N+ C+ Z+
    ;;; notes: Assumes X is cached [FP]/[RSP]
    .macro ror_p_w Parameter
        ror z: < (0 + (Parameter)) , x
        ror z: < (1 + (Parameter)) , x
    .endmacro

;endregion

;region Synthetic instructions - Interrupt flag on stack

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

;endregion

;region Synthetic instructions - JAM

    .macro jam

    .byte $02

    .endmacro

;endregion

.endif
