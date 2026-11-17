;30h ile 50h adresleri arasýndaki verilerin en büyügünü bulan
;ve 60h adresine yazan program 
;ve adresini de 61H adresine yazan program
;en büyükten kaç adet varsa 62H adresine yazan pORG,
mov 30h,#01h
	mov 31h,#0F8h
	mov 37h,#0F8h
	mov 3ah,#92h
	mov 3fh,#0F4h
	
		ORG 0000H
		SJMP BASLA
BASLA:	ORG 30H
		R0,#31H
		60H,30H
TEKRAR:	MOV A,@R0
		CJNE A, 60H, ESITDEGIL
		SJMP KONTROL
		
ESITDEGIL:JC YENISAYIKUCUK
	
YENISAYIKUCUK:
KONTROL:
		CJNE R0,#50H
		INC R0 , TEKRAR
		END
