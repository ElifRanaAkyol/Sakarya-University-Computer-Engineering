#include "Koleksiyon.h"

int main(){

int sayilar[] = {10,20,30,40,50,60};

    Koleksiyon koleksiyon = new_Koleksiyon(sayilar,6); //Koleksiyon yapıcı fonksiyonu
    

    koleksiyon->override_yaz(koleksiyon); //override_yaz fonksiyonu
    //koleksiyon->super->yaz(koleksiyon->super); //Topluluk yaz fonksiyonu


    koleksiyon->delete_Koleksiyon(koleksiyon); //Koleksiyon yıkıcı fonksiyonu
    //koleksiyon->delete_Koleksiyon(koleksiyon); //Koleksiyon yıkıcı fonksiyonu



    return 0;
}