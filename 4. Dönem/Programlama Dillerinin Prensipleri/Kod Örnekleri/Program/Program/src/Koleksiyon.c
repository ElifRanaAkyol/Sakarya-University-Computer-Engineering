#include "Koleksiyon.h"

Koleksiyon new_Koleksiyon(int* sayilar,int uzunluk){ //Koleksiyon yapıcı fonksiyonu
    Koleksiyon this;  //this bir pointer,OOP'ye benzesin diye this yazdık.
    this= (Koleksiyon)malloc(sizeof(struct KOLEKSIYON));    //heapte yapıyı oluşturduk
    this->super = new_Topluluk(sayilar,uzunluk); //Koleksiyon yapıcı fonksiyonu
    this->ortalama = &ortalama;
    this->override_yaz = &override_yaz;
    this->delete_Koleksiyon = &delete_Koleksiyon;
    return this;
}

double ortalama(const Koleksiyon this){
    double toplam = 0;
    for(int index=0;index<this->super->uzunluk;index++){
        toplam += this->super->sayilar[index];
    }
    return toplam/this->super->uzunluk;
}


void override_yaz(const Koleksiyon this){
    this->super->yaz(this->super);
    printf("\nKoleksiyonun ortalamasi: %f\n",this->ortalama(this));
}


void delete_Koleksiyon(Koleksiyon this){

    if(this == NULL) return;
    this->super->delete_Topluluk(this->super); //Koleksiyon yapıcı fonksiyonu
    free(this);
    //this = NULL;     bu satır önemli değil ama iyi bir uygulama.Fatih hoca this =NULL yazmadı!
    //this'i NULL yapmazsak, bu pointer hala bellekte varmış gibi davranır.
}