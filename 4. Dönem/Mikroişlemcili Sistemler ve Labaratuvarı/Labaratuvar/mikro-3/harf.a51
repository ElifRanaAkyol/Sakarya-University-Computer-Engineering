org 0000h
sjmp basla

org 0030h
basla:
mov p0,#0f0h    
mov p1,#0ffh    

dongu:
; 1 rakami
mov p0,#092h    
mov p1,#00h      
setb p1.3        
lcall bekle

; 2 rakami
mov p0,#087h     
mov p1,#00h
setb p1.2       
lcall bekle

; 3 rakami
mov p0,#0C1h     
mov p1,#00h
setb p1.1        
lcall bekle

; 4 rakami
mov p0,#0E3h     
mov p1,#00h
setb p1.0        
lcall bekle

ljmp dongu


bekle:
mov r7,#0ffh
tekrar: 
mov r6,#001h
djnz r6,$
djnz r7,tekrar
ret

end
