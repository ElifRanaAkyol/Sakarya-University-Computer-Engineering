org 0000h
sjmp basla
org 0030h
basla:
mov p0,#0ffh
acall bekle
mov p0, #0feh
acall bekle
mov p0, #0fch
acall bekle
mov p0, #0f8h
acall bekle
mov p0, #0f0h
acall bekle
mov p0, #0e0h
acall bekle
mov p0, #0c0h
acall bekle
mov p0, #080h
acall bekle
mov p0, #00h
acall bekle
/////////////////////////////////////
mov p1,#7fh
acall bekle
mov p1, #3fh
acall bekle
mov p1, #1fh
acall bekle
mov p1, #0fh
acall bekle
mov p1, #07h
acall bekle
mov p1, #03h
acall bekle
mov p1,#01h
acall bekle
mov p1, #00h
acall bekle
ljmp basla
bekle:
mov r7,#0ffh
tekrar: mov r6,#0ffh
djnz r6,$
djnz r7,tekrar
ret
end