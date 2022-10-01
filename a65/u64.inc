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

;;; summary: U64: Unicode for the C64: Unicode code points in the range 0x0000-0x00FF:
;;;   * control character
;;;   * basic latin
;;;   * latin-1 supplement
;;;   * extended with special glyphs for C64, indicated by U_EX_

U_NUL                                           = $00  ; "\0"
U_EX_BLACK_SPADE_SUIT                           = $01  ; "♠" U+2660 Black Spade Suit
U_EX_BLACK_CLUB_SUIT                            = $02  ; "♣" U+2663 Black Club Suit
U_EX_BLACK_HEART_SUIT                           = $03  ; "♥" U+2665 Black Heart Suit
U_EX_BLACK_DIAMOND_SUIT                         = $04  ; "♦" U+2666 Black Diamond Suit
U_EX_BULLET                                     = $05  ; "•" U+2022 Bullet
U_EX_WHITE_BULLET                               = $06  ; "◦" U+25E6 White Bullet
U_EX_CHECK_MARK                                 = $07  ; "✓" U+2713 CHECK MARK
U_BS                                            = $08  ; "\b"
U_HT                                            = $09  ; "\t"
U_LF                                            = $0A  ; "\n"
U_CLEAR_SCREEN                                  = $0B  ; CLEAR SCREEN
U_FF                                            = $0C  ; "\f"
U_CR                                            = $0D  ; "\r"
U_EX_F1                                         = $0E  ; F1
U_EX_F2                                         = $0F  ; F2
U_EX_F3                                         = $10  ; F3
U_EX_F4                                         = $11  ; F4
U_EX_F5                                         = $12  ; F5
U_EX_F6                                         = $13  ; F6
U_EX_F7                                         = $14  ; F7
U_EX_F8                                         = $15  ; F8
U_EX_HOME                                       = $16  ; HOME
U_EX_END                                        = $17  ; END
U_EX_INSERT                                     = $18  ; INSERT
U_EX_PAGE_DOWN                                  = $19  ; PAGE DOWN
U_EX_PAGE_UP                                    = $1A  ; PAGE UP
U_ESC                                           = $1B  ; ESC
U_EX_CURSOR_DOWN                                = $1C  ; CURSOR DOWN
U_EX_CURSOR_UP                                  = $1D  ; CURSOR UP
U_EX_CURSOR_RIGHT                               = $1E  ; CURSOR RIGHT
U_EX_CURSOR_LEFT                                = $1F  ; CURSOR LEFT
U_SPACE                                         = $20  ; " "
U_EXCLAMATION_MARK                              = $21  ; "!"
U_QUOTATION_MARK                                = $22  ; """
U_NUMBER_SIGN                                   = $23  ; "#"
U_DOLLAR                                        = $24  ; "$"
U_PERCENT                                       = $25  ; "%"
U_AMPERSAND                                     = $26  ; "&"
U_APOSTROPHE                                    = $27  ; "'"
U_LEFT_PARENTHESIS                              = $28  ; "("
U_RIGHT_PARENTHESIS                             = $29  ; ")"
U_ASTERISK                                      = $2A  ; "*"
U_PLUS_SIGN                                     = $2B  ; "+"
U_COMMA                                         = $2C  ; ","
U_HYPHEN_MINUS                                  = $2D  ; "-"
U_FULL_STOP                                     = $2E  ; "."
U_SOLIDUS                                       = $2F  ; "/"
U_DIGIT_ZERO                                    = $30  ; "0"
U_DIGIT_ONE                                     = $31  ; "1"
U_DIGIT_TWO                                     = $32  ; "2"
U_DIGIT_THREE                                   = $33  ; "3"
U_DIGIT_FOUR                                    = $34  ; "4"
U_DIGIT_FIVE                                    = $35  ; "5"
U_DIGIT_SIX                                     = $36  ; "6"
U_DIGIT_SEVEN                                   = $37  ; "7"
U_DIGIT_EIGHT                                   = $38  ; "8"
U_DIGIT_NINE                                    = $39  ; "9"
U_COLON                                         = $3A  ; ":"
U_SEMICOLON                                     = $3B  ; ";"
U_LESS_THAN_SIGN                                = $3C  ; "<"
U_EQUALS_SIGN                                   = $3D  ; "="
U_GREATER_THAN_SIGN                             = $3E  ; ">"
U_QUESTION_MARK                                 = $3F  ; "?"
U_COMMERCIAL_AT                                 = $40  ; "@"
U_LATIN_CAPITAL_LETTER_A                        = $41  ; "A"
U_LATIN_CAPITAL_LETTER_B                        = $42  ; "B"
U_LATIN_CAPITAL_LETTER_C                        = $43  ; "C"
U_LATIN_CAPITAL_LETTER_D                        = $44  ; "D"
U_LATIN_CAPITAL_LETTER_E                        = $45  ; "E"
U_LATIN_CAPITAL_LETTER_F                        = $46  ; "F"
U_LATIN_CAPITAL_LETTER_G                        = $47  ; "G"
U_LATIN_CAPITAL_LETTER_H                        = $48  ; "H"
U_LATIN_CAPITAL_LETTER_I                        = $49  ; "I"
U_LATIN_CAPITAL_LETTER_J                        = $4A  ; "J"
U_LATIN_CAPITAL_LETTER_K                        = $4B  ; "K"
U_LATIN_CAPITAL_LETTER_L                        = $4C  ; "L"
U_LATIN_CAPITAL_LETTER_M                        = $4D  ; "M"
U_LATIN_CAPITAL_LETTER_N                        = $4E  ; "N"
U_LATIN_CAPITAL_LETTER_O                        = $4F  ; "O"
U_LATIN_CAPITAL_LETTER_P                        = $50  ; "P"
U_LATIN_CAPITAL_LETTER_Q                        = $51  ; "Q"
U_LATIN_CAPITAL_LETTER_R                        = $52  ; "R"
U_LATIN_CAPITAL_LETTER_S                        = $53  ; "S"
U_LATIN_CAPITAL_LETTER_T                        = $54  ; "T"
U_LATIN_CAPITAL_LETTER_U                        = $55  ; "U"
U_LATIN_CAPITAL_LETTER_V                        = $56  ; "V"
U_LATIN_CAPITAL_LETTER_W                        = $57  ; "W"
U_LATIN_CAPITAL_LETTER_X                        = $58  ; "X"
U_LATIN_CAPITAL_LETTER_Y                        = $59  ; "Y"
U_LATIN_CAPITAL_LETTER_Z                        = $5A  ; "Z"
U_LEFT_SQUARE_BRACKET                           = $5B  ; "["
U_REVERSE_SOLIDUS                               = $5C  ; "\"
U_RIGHT_SQUARE_BRACKET                          = $5D  ; "]"
U_CIRCUMFLEX_ACCENT                             = $5E  ; "^"
U_LOW_LINE                                      = $5F  ; "_"
U_GRAVE_ACCENT                                  = $60  ; "`"
U_LATIN_SMALL_LETTER_A                          = $61  ; "a"
U_LATIN_SMALL_LETTER_B                          = $62  ; "b"
U_LATIN_SMALL_LETTER_C                          = $63  ; "c"
U_LATIN_SMALL_LETTER_D                          = $64  ; "d"
U_LATIN_SMALL_LETTER_E                          = $65  ; "e"
U_LATIN_SMALL_LETTER_F                          = $66  ; "f"
U_LATIN_SMALL_LETTER_G                          = $67  ; "g"
U_LATIN_SMALL_LETTER_H                          = $68  ; "h"
U_LATIN_SMALL_LETTER_I                          = $69  ; "i"
U_LATIN_SMALL_LETTER_J                          = $6A  ; "j"
U_LATIN_SMALL_LETTER_K                          = $6B  ; "k"
U_LATIN_SMALL_LETTER_L                          = $6C  ; "l"
U_LATIN_SMALL_LETTER_M                          = $6D  ; "m"
U_LATIN_SMALL_LETTER_N                          = $6E  ; "n"
U_LATIN_SMALL_LETTER_O                          = $6F  ; "o"
U_LATIN_SMALL_LETTER_P                          = $70  ; "p"
U_LATIN_SMALL_LETTER_Q                          = $71  ; "q"
U_LATIN_SMALL_LETTER_R                          = $72  ; "r"
U_LATIN_SMALL_LETTER_S                          = $73  ; "s"
U_LATIN_SMALL_LETTER_T                          = $74  ; "t"
U_LATIN_SMALL_LETTER_U                          = $75  ; "u"
U_LATIN_SMALL_LETTER_V                          = $76  ; "v"
U_LATIN_SMALL_LETTER_W                          = $77  ; "w"
U_LATIN_SMALL_LETTER_X                          = $78  ; "x"
U_LATIN_SMALL_LETTER_Y                          = $79  ; "y"
U_LATIN_SMALL_LETTER_Z                          = $7A  ; "z"
U_LEFT_CURLY_BRACKET                            = $7B  ; "{"
U_VERTICAL_LINE                                 = $7C  ; "|"
U_RIGHT_CURLY_BRACKET                           = $7D  ; "}"
U_TILDE                                         = $7E  ; "~"
U_DEL                                           = $7F  ; DELETE
U_EX_BOX_DRAWINGS_LIGHT_HORIZONTAL              = $80  ; "─" U+2500 Box Drawings Ligh Horizontal
U_EX_BOX_DRAWINGS_LIGHT_VERTICAL                = $81  ; "│" U+2502 Box Drawings Ligh Vertical
U_EX_BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT          = $82  ; "┌" U+250C Box Drawings Ligh Down And Right
U_EX_BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT           = $83  ; "┐" U+2510 Box Drawings Ligh Down And Left
U_EX_BOX_DRAWINGS_LIGHT_UP_AND_RIGHT            = $84  ; "└" U+2514 Box Drawings Ligh Up And Right
U_EX_BOX_DRAWINGS_LIGHT_UP_AND_LEFT             = $85  ; "┘" U+2518 Box Drawings Ligh Up And Left
U_EX_BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT      = $86  ; "├" U+251C Box Drawings Ligh Vertical And Right
U_EX_BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT       = $87  ; "┤" U+2524 Box Drawings Ligh Vertical And Left
U_EX_BOX_DRAWINGS_LIGHT_DOWN_AND_HORIZONTAL     = $88  ; "┬" U+252C Box Drawings Ligh Down And Horizontal
U_EX_BOX_DRAWINGS_LIGHT_UP_AND_HORIZONTAL       = $89  ; "┴" U+2534 Box Drawings Ligh Up And Horizontal
U_EX_BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL = $8A  ; "┼" U+253C Box Drawings Ligh Vertical And Horizontal
U_EX_LEFTWARDS_ARROW                            = $8B  ; "←" U+2190 Leftwards Arrow
U_EX_UPWARDS_ARROW                              = $8C  ; "↑" U+2191 Upwards Arrow
U_EX_RIGHTWARDS_ARROW                           = $8D  ; "→" U+2192 Rightwards Arrow
U_EX_DOWNWARDS_ARROW                            = $8E  ; "↓" U+2193 Downwards Arrow
U_EX_EURO_SIGN                                  = $8F  ; "€" U+20AC Euro Sign
U_EX_COLOR_0_BLK                                = $90  ; Color $0 BLK
U_EX_COLOR_1_WHT                                = $91  ; Color $1 WHT
U_EX_COLOR_2_RED                                = $92  ; Color $2 RED
U_EX_COLOR_3_CYN                                = $93  ; Color $3 CYN
U_EX_COLOR_4_PUR                                = $94  ; Color $4 PUR
U_EX_COLOR_5_GRN                                = $95  ; Color $5 GRN
U_EX_COLOR_6_BLU                                = $96  ; Color $6 BLU
U_EX_COLOR_7_YEL                                = $97  ; Color $7 YEL
U_EX_COLOR_8_ORA                                = $98  ; Color $8 ORA
U_EX_COLOR_9_BRO                                = $99  ; Color $9 BRO
U_EX_COLOR_A_PIN                                = $9A  ; Color $A PIN
U_EX_COLOR_B_DGY                                = $9B  ; Color $B DGY
U_EX_COLOR_C_GRY                                = $9C  ; Color $C GRY
U_EX_COLOR_D_LGN                                = $9D  ; Color $D LGN
U_EX_COLOR_E_LBL                                = $9E  ; Color $E LBL
U_EX_COLOR_F_LGY                                = $9F  ; Color $F LGY
U_NO_BREAK_SPACE                                = $A0  ; " "
U_INVERTED_EXCLAMATION_MARK                     = $A1  ; "¡" Keyboard {AltGr}+{1!}
U_CENT_SIGN                                     = $A2  ; "¢" Keyboard {AltGr}+{SHIFT}+{c}
U_POUND_SIGN                                    = $A3  ; "£"
U_CURRENCY_SIGN                                 = $A4  ; "¤" Keyboard {AltGr}+{4$}
U_YEN_SIGN                                      = $A5  ; "¥" Keyboard {AltGr}+{-_}
U_BROKEN_BAR                                    = $A6  ; "¦"
U_SECTION_SIGN                                  = $A7  ; "§"
U_DIAERESIS                                     = $A8  ; "¨"
U_COPYRIGHT_SIGN                                = $A9  ; "©"
U_FEMININE_ORDINAL_INDICATOR                    = $AA  ; "ª"
U_LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK     = $AB  ; "«"
U_NOT_SIGN                                      = $AC  ; "¬"
U_SOFT_HYPHEN                                   = $AD  ; "-"
U_REGISTERED_SIGN                               = $AE  ; "®"
U_MACRON                                        = $AF  ; "¯"
U_DEGREE_SIGN                                   = $B0  ; "°"
U_PLUS_MINUS_SIGN                               = $B1  ; "±"
U_SUPERSCRIPT_TWO                               = $B2  ; "²"
U_SUPERSCRIPT_THREE                             = $B3  ; "³"
U_ACUTE_ACCENT                                  = $B4  ; "´"
U_MICRO_SIGN                                    = $B5  ; "µ"
U_PILCROW_SIGN                                  = $B6  ; "¶"
U_MIDDLE_DOT                                    = $B7  ; "·"
U_CEDILLA                                       = $B8  ; "¸"
U_SUPERSCRIPT_ONE                               = $B9  ; "¹"
U_MASCULINE_ORDINAL_INDICATOR                   = $BA  ; "º"
U_RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK    = $BB  ; "»"
U_VULGAR_FRACTION_ONE_QUARTER                   = $BC  ; "¼"
U_VULGAR_FRACTION_ONE_HALF                      = $BD  ; "½"
U_VULGAR_FRACTION_THREE_QUARTERS                = $BE  ; "¾"
U_INVERTED_QUESTION_MARK                        = $BF  ; "¿"
U_LATIN_CAPITAL_LETTER_A_WITH_GRAVE             = $C0  ; "À"
U_LATIN_CAPITAL_LETTER_A_WITH_ACUTE             = $C1  ; "Á"
U_LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX        = $C2  ; "Â"
U_LATIN_CAPITAL_LETTER_A_WITH_TILDE             = $C3  ; "Ã"
U_LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS         = $C4  ; "Ä"
U_LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE        = $C5  ; "Å"
U_LATIN_CAPITAL_LETTER_AE                       = $C6  ; "Æ"
U_LATIN_CAPITAL_LETTER_C_WITH_CEDILLA           = $C7  ; "Ç"
U_LATIN_CAPITAL_LETTER_E_WITH_GRAVE             = $C8  ; "È"
U_LATIN_CAPITAL_LETTER_E_WITH_ACUTE             = $C9  ; "É"
U_LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX        = $CA  ; "Ê"
U_LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS         = $CB  ; "Ë"
U_LATIN_CAPITAL_LETTER_I_WITH_GRAVE             = $CC  ; "Ì"
U_LATIN_CAPITAL_LETTER_I_WITH_ACUTE             = $CD  ; "Í"
U_LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX        = $CE  ; "Î"
U_LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS         = $CF  ; "Ï"
U_LATIN_CAPITAL_LETTER_ETH                      = $D0  ; "Ð"
U_LATIN_CAPITAL_LETTER_N_WITH_TILDE             = $D1  ; "Ñ"
U_LATIN_CAPITAL_LETTER_O_WITH_GRAVE             = $D2  ; "Ò"
U_LATIN_CAPITAL_LETTER_O_WITH_ACUTE             = $D3  ; "Ó"
U_LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX        = $D4  ; "Ô"
U_LATIN_CAPITAL_LETTER_O_WITH_TILDE             = $D5  ; "Õ"
U_LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS         = $D6  ; "Ö"
U_MULTIPLICATION_SIGN                           = $D7  ; "×"
U_LATIN_CAPITAL_LETTER_O_WITH_STROKE            = $D8  ; "Ø"
U_LATIN_CAPITAL_LETTER_U_WITH_GRAVE             = $D9  ; "Ù"
U_LATIN_CAPITAL_LETTER_U_WITH_ACUTE             = $DA  ; "Ú"
U_LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX        = $DB  ; "Û"
U_LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS         = $DC  ; "Ü"
U_LATIN_CAPITAL_LETTER_Y_WITH_ACUTE             = $DD  ; "Ý"
U_LATIN_CAPITAL_LETTER_THORN                    = $DE  ; "Þ"
U_LATIN_SMALL_LETTER_SHARP_S                    = $DF  ; "ß"
U_LATIN_SMALL_LETTER_A_WITH_GRAVE               = $E0  ; "à"
U_LATIN_SMALL_LETTER_A_WITH_ACUTE               = $E1  ; "á"
U_LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX          = $E2  ; "â"
U_LATIN_SMALL_LETTER_A_WITH_TILDE               = $E3  ; "ã"
U_LATIN_SMALL_LETTER_A_WITH_DIAERESIS           = $E4  ; "ä"
U_LATIN_SMALL_LETTER_A_WITH_RING_ABOVE          = $E5  ; "å"
U_LATIN_SMALL_LETTER_AE                         = $E6  ; "æ"
U_LATIN_SMALL_LETTER_C_WITH_CEDILLA             = $E7  ; "ç"
U_LATIN_SMALL_LETTER_E_WITH_GRAVE               = $E8  ; "è"
U_LATIN_SMALL_LETTER_E_WITH_ACUTE               = $E9  ; "é"
U_LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX          = $EA  ; "ê"
U_LATIN_SMALL_LETTER_E_WITH_DIAERESIS           = $EB  ; "ë"
U_LATIN_SMALL_LETTER_I_WITH_GRAVE               = $EC  ; "ì"
U_LATIN_SMALL_LETTER_I_WITH_ACUTE               = $ED  ; "í"
U_LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX          = $EE  ; "î"
U_LATIN_SMALL_LETTER_I_WITH_DIAERESIS           = $EF  ; "ï"
U_LATIN_SMALL_LETTER_ETH                        = $F0  ; "ð"
U_LATIN_SMALL_LETTER_N_WITH_TILDE               = $F1  ; "ñ"
U_LATIN_SMALL_LETTER_O_WITH_GRAVE               = $F2  ; "ò"
U_LATIN_SMALL_LETTER_O_WITH_ACUTE               = $F3  ; "ó"
U_LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX          = $F4  ; "ô"
U_LATIN_SMALL_LETTER_O_WITH_TILDE               = $F5  ; "õ"
U_LATIN_SMALL_LETTER_O_WITH_DIAERESIS           = $F6  ; "ö"
U_DIVISION_SIGN                                 = $F7  ; "÷"
U_LATIN_SMALL_LETTER_O_WITH_STROKE              = $F8  ; "ø"
U_LATIN_SMALL_LETTER_U_WITH_GRAVE               = $F9  ; "ù"
U_LATIN_SMALL_LETTER_U_WITH_ACUTE               = $FA  ; "ú"
U_LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX          = $FB  ; "û"
U_LATIN_SMALL_LETTER_U_WITH_DIAERESIS           = $FC  ; "ü"
U_LATIN_SMALL_LETTER_Y_WITH_ACUTE               = $FD  ; "ý"
U_SMALL_LETTER_THORN                            = $FE  ; "þ"
U_LATIN_SMALL_LETTER_Y_WITH_DIAERESIS           = $FF  ; "ÿ"

; The following code points are on the US International keyboard, but are
; outside the 0x0000-0x00FF range:
U_EURO_SIGN                                     = $20AC  ; "€"
U_LEFT_SINGLE_QUOTATION_MARK                    = $2018  ; "‘"
U_RIGHT_SINGLE_QUOTATION_MARK                   = $2019  ; "’"
