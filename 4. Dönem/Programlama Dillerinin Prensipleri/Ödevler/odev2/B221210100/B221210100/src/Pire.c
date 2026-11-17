/** 
* @file / Pire.c
* @description / Pire dosyasý. Pire iþlemleri yapýlýr.
* @course / Programlama Dillerinin Prensipleri / 1-A
* @assignment / 2.Ödev
* @date / 12-05-2024
* @author / Muhammed Yusuf Öngel / muhammed.ongel@sakarya.edu.tr
*/
#include "Pire.h"

Pire newPire(int value)
{
    Pire this;
    
    //"Sýnýf" yapýsý için bellekte yer ayýrýyoruz.
    this = (Pire)malloc(sizeof(struct PIRE));
    this->symbol = "P";

    this->super = newBocek(value);
    this->super->super = newCanli(this->symbol);
    this->super->super->view = &viewPire;
    this->deletePire = &deletePire;

    return this;
}

char* viewPire(const Pire this)
{
    printf("%s ", this->symbol);

    return this->symbol;
}

void deletePire(const Pire this)
{
    if (this == NULL)   return;
    this->super->deleteBocek(this->super);
    free(this);
}