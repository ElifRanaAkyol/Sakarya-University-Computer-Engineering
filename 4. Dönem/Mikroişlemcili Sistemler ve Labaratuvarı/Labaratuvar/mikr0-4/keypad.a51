org 0000h
sjmp basla            
org 0030h

basla:
mov p0, #0FFh          
mov p3, #0FFh          

dongu:
mov p0, #0FFh
clr p0.4              
jnb p0.0, bir_bas      
jnb p0.1, iki_bas      
jnb p0.2, uc_bas       
jnb p0.3, A_bas        
setb p0.4             


clr p0.5
jnb p0.0, dort_bas    
jnb p0.1, bes_bas     
jnb p0.2, alti_bas     
jnb p0.3, B_bas        
setb p0.5


clr p0.6
jnb p0.0, yedi_bas    
jnb p0.1, sekiz_bas    
jnb p0.2, dokuz_bas    
jnb p0.3, C_bas        
setb p0.6


clr p0.7
jnb p0.0, yildiz_bas   
jnb p0.1, sifir_bas    
jnb p0.2, kare_bas     
jnb p0.3, D_bas        
setb p0.7

ljmp dongu             


bir_bas:     mov p3,#11111110B 
             ljmp donus

iki_bas:     mov p3,#11111101B   
             ljmp donus

uc_bas:      mov p3,#11111100B   
             ljmp donus

A_bas:       mov p3,#11110101B  
             ljmp donus

dort_bas:    mov p3,#11111011B   
             ljmp donus

bes_bas:     mov p3,#11111010B   
             ljmp donus

alti_bas:    mov p3,#11111001B    
             ljmp donus

B_bas:       mov p3,#11110100B    
             ljmp donus

yedi_bas:    mov p3,#11111000B  
             ljmp donus

sekiz_bas:   mov p3,#11110111B  
             ljmp donus

dokuz_bas:   mov p3,#11110110B   
             ljmp donus

C_bas:       mov p3,#11110011B    
             ljmp donus

yildiz_bas:  mov p3,#11110001B   
             ljmp donus

sifir_bas:   mov p3,#11111111B   
             ljmp donus

kare_bas:    mov p3,#11110000B    
             ljmp donus

D_bas:       mov p3,#11110010B   
             ljmp donus

donus:
ljmp dongu

end
