#include "stdio.h"
#include "setjmp.h"
#include "Dosya.h"
jmp_buf buffer;



// javadaki try catch yapısını c dilinde simule eden bir kod parçası
#define try do { if (!setjmp(buffer)) {
#define catch } else {
#define throw longjmp(buffer, 1)
#define tryEnd } } while(0)

int bolme(int x, int y)
{
    if (y == 0) throw;
    return x / y;
}

int main()
{
  Dosya dosya = dosyaOlustur("test.txt");
    char* icerik = NULL;
    try {
        printf("Dosya Icerigi: %s\n",  dosya->oku(dosya));
    }
    catch {
        printf("Hata: Dosya okunamadi.\n");
    }
    tryEnd;
    return 0;

    // Bolme islemi


  ///////////
    int a = 5, b = 7;

    try {
        int c = bolme(a, b);
        printf("Sonuc: %d\n", c);
    }
    catch {
        printf("Hata: Bolme islemi yapilamadi.\n");
    }
    tryEnd;

    return 0;
}
