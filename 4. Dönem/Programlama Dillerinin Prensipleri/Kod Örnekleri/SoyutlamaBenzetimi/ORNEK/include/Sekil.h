#ifndef SEKIL_H 
#define SEKIL_H


#include "time.h"
#include "math.h"
#include "string.h"

struct SEKIL{
    char *renk;
    char *olusturulmaTarihi;

    //diğer sınıfların kalıtım alabilmesi için fonksiyon göstericileri tanımlanır
    //eğer kalıtım alıncak bir sınıf değilse fonksiyon göstericileri olmadan da yapılabilir
    //fonkiyon göstericileri: dışardaki fonksiyonu kendi fonksiyonuymuş gibi gösterir
    void (*setRenk)(struct SEKIL*, char*);
    char* (*getTarih)(struct SEKIL*);
    char* (*toString)(struct SEKIL*, void*);
    double (*alan)();   //soyut sınıfın benzetimidir
    double (*cevre)();
    void (*delete_Sekil)(struct SEKIL*);

};
typedef struct SEKIL *Sekil;
Sekil new_Sekil(char*);
void setRenk(const Sekil, char*);
char* getTarih(const Sekil);
char* toString(const Sekil, void*); //alt sınıfta bulunmayıp üst sınıftaki metodu çağırmak için void dedik
void delete_Sekil(const Sekil);

#endif