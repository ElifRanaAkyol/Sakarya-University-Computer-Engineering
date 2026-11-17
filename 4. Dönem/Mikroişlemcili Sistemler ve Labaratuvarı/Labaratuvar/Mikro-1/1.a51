ORG 00H           ; program 00H adresinden baslasin
	SJMP DEVAM 
	ORG 30H
DEVAM:            ; 
    MOV A, #0     ; aküye 0 sabit degerinin yüklenmesi
    MOV P2, A     ; aküyü P2’ye yükle

SIFIR:
    JB P1.1, DEVAM ; P1.1 = 1 ise devam etiketine dallan
    JNB P1.0, SIFIR ; P1.0 = 0 ise sifir etiketine dallan
    INC A         ; aküyü 1 arttir
    MOV P2, A     ; aküyü P2’ye yükle
    CJNE A, #9, SIFIR ; aküyü 9 ile karsilastir, esit degilse sifir etiketine dallan
    SJMP DEVAM     ; devam etiketine dallan
	END