#include "Topluluk.h"


Topluluk new_Topluluk(int* sayilar,int uzunluk){

Topluluk this;  //this bir pointer,OOP'ye benzesin diye this yazdık.
this= (Topluluk)malloc(sizeof(struct TOPLULUK));    //heapte yapıyı oluşturduk

this->sayilar=(int*)malloc(sizeof(int)*uzunluk);
this->uzunluk = uzunluk;
    for(int index =0;index<uzunluk;index++){
        this->sayilar[index] = sayilar[index];
    }
    this->sirala = &sirala;
    this->yaz = &yaz;
    this->delete_Topluluk = &delete_Topluluk;
    return this;

}





int* sirala(const Topluluk this){

    for(int i=0;i<this->uzunluk-1;i++){
        for(int j=1;j<this->uzunluk-i;j++){
        }
        int* siraliDizi = (int*)malloc(sizeof(int)*this->uzunluk);
        for (int index=0;index<this->uzunluk;index++)      {
            siraliDizi[index] = this->sayilar[index];


        }
         return siraliDizi;
    }




}




void yaz(const Topluluk this) //yıkıcı fonksiyon yazmaya gerek yok
{
    this->sirala(this);
    for(int index=0;index<this->uzunluk;index++){
        printf("%d ",this->sayilar[index]);
    }
    
}



void delete_Topluluk(Topluluk this){

    if(this == NULL) return;
    if(this->sayilar != NULL) free(this->sayilar); //sayilar dizisini serbest bırakıyoruz.
    free(this); //yapıyı serbest bırakıyoruz.


}








