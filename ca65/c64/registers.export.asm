.exportzp REGISTERS_BASE := $02

.exportzp AX := REGISTERS_BASE + 0                          ; $02
.exportzp AL := AX + 0                                      ; $02
.exportzp AH := AX + 1                                      ; $03

.exportzp BX := REGISTERS_BASE + 2                          ; $04
.exportzp BL := BX + 0                                      ; $04
.exportzp BH := BX + 1                                      ; $05

.exportzp CX := REGISTERS_BASE + 4                          ; $06
.exportzp CL := CX + 0                                      ; $06
.exportzp CH := CX + 1                                      ; $07

.exportzp DX := REGISTERS_BASE + 6                          ; $08
.exportzp DL := DX + 0                                      ; $08
.exportzp DH := DX + 1                                      ; $09
