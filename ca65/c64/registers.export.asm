.exportzp REGISTERS_BASE := $02

.exportzp AX := REGISTERS_BASE + 0
.exportzp AL := AX + 0
.exportzp AH := AX + 1

.exportzp BX := REGISTERS_BASE + 2
.exportzp BL := BX + 0
.exportzp BH := BX + 1

.exportzp CX := REGISTERS_BASE + 4
.exportzp CL := CX + 0
.exportzp CH := CX + 1

.exportzp DX := REGISTERS_BASE + 6
.exportzp DL := DX + 0
.exportzp DH := DX + 1
