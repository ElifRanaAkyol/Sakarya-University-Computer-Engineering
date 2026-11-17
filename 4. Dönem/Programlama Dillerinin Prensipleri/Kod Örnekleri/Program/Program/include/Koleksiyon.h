#ifndef KOLEKSIYON_H
#define KOLEKSIYON_H

#include "Topluluk.h" //Koleksiyon, Topluluk'tan kalıtım alacak.


struct KOLEKSIYON{

    Topluluk super; //burada kalıtımı el ile biz yapıyoruz.
    double(*ortalama)(struct KOLEKSIYON*);
    void (*override_yaz)(struct KOLEKSIYON*);
    void (*delete_Koleksiyon)(struct KOLEKSIYON*);

};
typedef struct KOLEKSIYON* Koleksiyon;//Koleksiyon bir pointer yapısıdır.   


Koleksiyon new_Koleksiyon(int*,int); //Koleksiyon yapıcı fonksiyonu
double ortalama(const Koleksiyon);
void override_yaz(const Koleksiyon);
void delete_Koleksiyon(Koleksiyon);


#endif 