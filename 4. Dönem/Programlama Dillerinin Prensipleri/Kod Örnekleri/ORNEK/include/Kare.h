#ifndef DAIRE_H
#define DAIRE_H

#include "Sekil.h" // Ensure Sekil is defined



struct KARE{
    Sekil super; //inheritance
    double kenar;
    
    void (*delete_Kare)(struct KARE*);

};
typedef struct KARE *Kare;
Kare new_Kare(char* renk, double kenar);
double alan(const Kare ); //hem dairede hem de karede aynı isimde fonksiyon olamaz c de overloading yok. o yüzden farklı isim yaptık
double cevre(const Kare );
void delete_Kare(Kare );


#endif