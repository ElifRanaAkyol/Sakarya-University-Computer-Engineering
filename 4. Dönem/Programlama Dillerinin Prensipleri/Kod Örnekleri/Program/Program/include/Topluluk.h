#ifndef TOPLULUK_H
#define TOPLULUK_

#include "stdio.h"
#include "stdlib.h"


struct TOPLULUK{

    int *sayilar;
    int uzunluk;

    int* (*sirala)(struct TOPLULUK*); //parantez kullanmak demek bunun fonksiyon göstericisi olduğunu ifade eder.
    void (*yaz)(struct TOPLULUK*);
    void (*delete_Topluluk)(struct TOPLULUK*);
/*    yapıcı fonksiyona gösterici yapmadık neden?: kurucu fonksiyon zaten bir şey oluşunca çağırılacak.
      Çağırılan bir şeyi tekrar neden çağıralım?                                                         */
};
typedef struct TOPLULUK* Topluluk;


Topluluk new_Topluluk(int*,int);

int* sirala(const Topluluk);
void yaz(const Topluluk); //yıkıcı fonksiyon yazmaya gerek yok

void delete_Topluluk(Topluluk);




#endif 