org 0000h
sjmp basla             ; Baslangiç adresine ziplama
org 0030h

basla:
mov p0, #0FFh          ; P0 ilk basta tüm satirlari 1 yap (inactive)
mov p3, #0FFh          ; P3 temizlenir

dongu:
; ----- 1. Satir taraniyor (P0.4 aktif) -----
mov p0, #0FFh
clr p0.4               ; 1. satiri aktif et (LOW yap)
jnb p0.0, bir_bas      ; 1 tusu
jnb p0.1, iki_bas      ; 2 tusu
jnb p0.2, uc_bas       ; 3 tusu
jnb p0.3, A_bas        ; A tusu
setb p0.4              ; 1. satiri pasif yap

; ----- 2. Satir taraniyor (P0.5 aktif) -----
clr p0.5
jnb p0.0, dort_bas     ; 4 tusu
jnb p0.1, bes_bas      ; 5 tusu
jnb p0.2, alti_bas     ; 6 tusu
jnb p0.3, B_bas        ; B tusu
setb p0.5

; ----- 3. Satir taraniyor (P0.6 aktif) -----
clr p0.6
jnb p0.0, yedi_bas     ; 7 tusu
jnb p0.1, sekiz_bas    ; 8 tusu
jnb p0.2, dokuz_bas    ; 9 tusu
jnb p0.3, C_bas        ; C tusu
setb p0.6

; ----- 4. Satir taraniyor (P0.7 aktif) -----
clr p0.7
jnb p0.0, yildiz_bas   ; * tusu
jnb p0.1, sifir_bas    ; 0 tusu
jnb p0.2, kare_bas     ; # tusu
jnb p0.3, D_bas        ; D tusu
setb p0.7

ljmp dongu             ; Sonsuz döngüye gir

; ----------- Tus Fonksiyonlari -------------
bir_bas:     mov p3,#01h   ; 1 ? P3 = 01h
             ljmp donus

iki_bas:     mov p3,#02h   ; 2
             ljmp donus

uc_bas:      mov p3,#03h   ; 3
             ljmp donus

A_bas:       mov p3,#0Ah   ; A = 0Ah
             ljmp donus

dort_bas:    mov p3,#04h   ; 4
             ljmp donus

bes_bas:     mov p3,#05h   ; 5
             ljmp donus

alti_bas:    mov p3,#06h   ; 6
             ljmp donus

B_bas:       mov p3,#0Bh   ; B = 0Bh
             ljmp donus

yedi_bas:    mov p3,#07h   ; 7
             ljmp donus

sekiz_bas:   mov p3,#08h   ; 8
             ljmp donus

dokuz_bas:   mov p3,#09h   ; 9
             ljmp donus

C_bas:       mov p3,#0Ch   ; C = 0Ch
             ljmp donus

yildiz_bas:  mov p3,#0Eh   ; * = 0Eh
             ljmp donus

sifir_bas:   mov p3,#00h   ; 0
             ljmp donus

kare_bas:    mov p3,#0Fh   ; # = 0Fh
             ljmp donus

D_bas:       mov p3,#0Dh   ; D = 0Dh
             ljmp donus

donus:
ljmp dongu

end
