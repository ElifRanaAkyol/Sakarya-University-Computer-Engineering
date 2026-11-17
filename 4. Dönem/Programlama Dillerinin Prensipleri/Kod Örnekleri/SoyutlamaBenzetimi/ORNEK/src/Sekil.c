#include "Sekil.H"

char* zamanGetir(){
    char* buff= malloc(sizeof(char)*100);   //bellekten 100 karakterlik yer ayırır
    time_t simdi =time(0);//şu anki zamanı alır
    strftime(buff,100,"%d %m %H:%M %Y",localtime(&simdi)); //stringe çevirir
    return buff;
}
int doubleUzunluk(double deger){
    char alanStr[50];
    //deger double degiskenini stringe cevirip alan dizisinin icine yuazar:
    sprintf(alanStr,"%lf",deger); //istediğin formatta char pointerın gösterdiği yere atar.
    int uzunluk=strlen(alanStr);
    return uzunluk;
}
Sekil new_Sekil(char* renk)
{
    Sekil this;
    this= (Sekil)malloc(sizeof(struct SEKIL));
    this->renk =renk;
    this->olusturulmaTarihi= zamanGetir(); //privatein benzetimizidir.
    //dışardan (sekilede) erişim yok. sadece buradan erişilebilir.
    //delete yaparken çnce içerisindekiler free yapılıp sonra sekil sınıfı free yapılacak.
    //olusturulmaTarihi alanı dışardan doğrudan değiştirilemez, çünkü değeri yalnızca zamanGetir() fonksiyonuyla atanıyor.
    //fonskiyon göstericileri:
    //gercek fonksiyonları atıyoruz. artık thise ait bir metod gibi çağırırız
    //yani dışarda tanımladığımız gerçek fonksiyonları, fonskiyon işaretçilerine atıyoruz.
    this->setRenk = &setRenk;
    this->getTarih = &getTarih;
    this->toString = &toString;
    this->delete_Sekil = &delete_Sekil;
    return this;


}


void setRenk(const Sekil this,char*renk){
    this->renk=renk;
}
char* getTarih(const Sekil this){
    return this->olusturulmaTarihi; //veya return zamanGetir();
}
char* toString(const Sekil this,void* p){
    int toplamUzunluk=36;
    toplamUzunluk+=strlen(this->olusturulmaTarihi);
    toplamUzunluk+=strlen(this->renk);//uzunluklarını döndürür
    toplamUzunluk+=doubleUzunluk(this->alan(p));
    toplamUzunluk+=doubleUzunluk(this->cevre(p));
    char* str=(char*)malloc(sizeof(char)*toplamUzunluk+1);//+1 => \n için
    //formatı string olarak birleştirmek için sprintf ile str ye aktarım yapıyoruz.
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