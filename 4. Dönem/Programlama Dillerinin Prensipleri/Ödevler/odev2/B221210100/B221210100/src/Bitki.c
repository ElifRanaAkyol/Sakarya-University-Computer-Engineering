/** 
* @file / Bitki.c
* @description / Bitki dosyasý. Bitki iþlemleri yapýlýr.
* @course / Programlama Dillerinin Prensipleri / 1-A
* @assignment / 2.Ödev
* @date / 12-05-2024
* @author / Muhammed Yusuf Öngel / muhammed.ongel@sakarya.edu.tr
*/
#include "Bitki.h"


Bitki newBitki(int value)
{
    Bitki this;
    
    //"Sýnýf" yapýsý için bellekte yer ayýrýyoruz.
    this = (Bitki)malloc(sizeof(struct BITKI));

    this->symbol = "B";
    this->super = newCanli(this->symbol);
    this->super->value = value;
    this->super->view = &viewBitki;
    this->deleteBitki = &deleteBitki;

    return this;
}

char* viewBitki(const Bitki this)
{
    printf("%s ", this->symbol);

    return this->symbol;
}

void deleteBitki(const Bitki this)
{
    if (this == NULL)   return;
    this->super->deleteCanli(this->super);
    free(this);
}