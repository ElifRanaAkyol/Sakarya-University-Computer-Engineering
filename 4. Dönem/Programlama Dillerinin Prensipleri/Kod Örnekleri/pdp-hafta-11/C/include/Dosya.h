#ifndef DOSYA_H
#define DOSYA_H


struct DOSYA{
   char* yol;
   char* icerik;
    char* (*oku)(struct DOSYA*);
    void (*dosyaYokEt)(struct DOSYA*);

};
typedef struct DOSYA *Dosya;
Dosya dosyaOlustur(char*);
void dosyaYokEt(const Dosya );
char* oku(Dosya );


#endif