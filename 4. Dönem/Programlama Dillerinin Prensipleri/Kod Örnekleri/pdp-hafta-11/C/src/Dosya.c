#include "Dosya.h"
#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;


#define try do { if (!setjmp(buffer)) {
    #define catch } else {
    #define throw longjmp(buffer, 1)
    #define tryEnd } } while(0)

Dosya dosyaOlustur(char* dosyaYolu) {
    Dosya this = (Dosya)malloc(sizeof(struct DOSYA));
    this->yol = dosyaYolu;
    this->icerik = NULL;

    this->oku = oku;
    this->dosyaYokEt = dosyaYokEt;
    return this;
}

char* oku(const Dosya this) {

    char* icerik = NULL;
    int uzunluk = 0;
    FILE* fp = fopen(this->yol, "r");
    if (!fp) throw; // Dosya acilamadi
    fseek(fp, 0, SEEK_END);
    uzunluk = ftell(fp);
    rewind(fp);//dosyanın başına gönderir
    icerik = (char*)malloc(sizeof(char) * (uzunluk+1)); // bu "/0 içindir"
    size_t dosyaUzunluk = fread(icerik, 1, uzunluk, fp);
    icerik[dosyaUzunluk] = '\0'; // null karakter ekle  sonlandırıcı karakter
    fclose(fp);
    this->icerik = icerik; // içeriği dosyaya atıyoruz
    return icerik; // içeriği döndürüyoruz
}
void dosyaYokEt(Dosya this) {
    if (this == NULL)  return;
    if (this->icerik != NULL) free(this->icerik);
    free(this);
}