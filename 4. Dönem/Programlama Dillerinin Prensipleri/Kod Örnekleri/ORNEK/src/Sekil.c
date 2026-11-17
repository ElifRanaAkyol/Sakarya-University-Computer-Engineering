#include "Sekil.H"

char* zamanGetir(){
    char* buff= malloc(sizeof(char)*100);
    time_t simdi =time(0);
    strftime(buff,100,"%d %m %H:%M %Y",localtime(&simdi));
    return buff;
}
int doubleUzunluk(double deger){
    char alanStr[50];
    sprintf(alanStr,"%lf",deger); //istediğin formatta char pointerın gösterdiği yere atar.
    return alanStr;
    int uzunluk=strlen(alanStr);
    return uzunluk;
}
Sekil new_Sekil(char* renk)
{
    Sekil this;
    this= (Sekil)malloc(sizeof(struct SEKIL))
    this->renk =renk;
    this->olusturulmaTarihi= zamanGetir(); //privatein benzetimizidir.

    this->setRenk = &setRenk;
    this->getTarih = &getTarih;
    this->toString = &toString;
    this->delete_Sekil = &delete_Sekil;
    return this;


}


void setRenk(const Sekil,char*){
    this->renk=renk;
}
char* getTarih(const Sekil){
    return this->olusturulmaTarihi;
}
char* toString(const Sekil,void*){
    int toplamUzunluk=36;
    toplamUzunluk+=strlen(this->olusturulmaTarihi);
    toplamUzunluk+=strlen(this->renk);
    toplamUzunluk+=doubleUzunluk(this->alan(p));
    toplamUzunluk+=doubleUzunluk(this->cevre(p));
    char* str=malloc(sizeof(char)*toplamUzunluk+1);
    sprintf(str,"\nRenk: %s\nTarih: %s\nAlan: %lf\nCevre: %lf\n",this->renk,this->olusturulmaTarihi,this->alan(p),this->cevre(p));
    
    return str;
}
void delete_Sekil(Sekil this){
    if(this==NULL){
        return;
    }
    if(this->olusturulmaTarihi!=NULL){
        free(this->olusturulmaTarihi);
    }
    free(this);
}