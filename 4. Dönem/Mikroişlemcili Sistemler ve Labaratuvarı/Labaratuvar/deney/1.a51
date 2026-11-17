ORG 0000h
    SJMP BASLA

ORG 0030h
BASLA:
    ; 1. display (en sag): '1'
    MOV P1, #01h    ; 1. display aktif
    MOV P0, #0F9h   ; 1 yaz

    ACALL BEKLE

    ; 2. display: '9'
    MOV P1, #02h    ; 2. display aktif
    MOV P0, #090h   ; 9 yaz

    ACALL BEKLE

    SJMP BASLA

; Gecikme
BEKLE:
    MOV R7, #0FFh
GEK:
    MOV R6, #0FFh
 DJNZ R6, $
    DJNZ R7, GEK
    RET

END