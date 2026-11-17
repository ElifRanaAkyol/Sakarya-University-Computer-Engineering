/** 
* @file / Sinek.c
* @description / Sinek dosyasý. Sinek iþlemleri yapýlýr.
* @course / Programlama Dillerinin Prensipleri / 1-A
* @assignment / 2.Ödev
* @date / 12-05-2024
* @author / Muhammed Yusuf Öngel / muhammed.ongel@sakarya.edu.tr
*/
#include "Sinek.h"

Sinek newSinek(int value)
{
    Sinek this;
    
    //"Sýnýf" yapýsý için bellekte yer ayýrýyoruz.
    this = (Sinek)malloc(sizeof(struct SINEK));
    this->symbol = "S";

    this->super = newBocek(value);
    this->super->super = newCanli(this->symbol);
    this->super->super->value = value;
    this->super->super->view = &viewSinek;
    this->deleteSinek = &deleteSinek;

    return this;
}

char* viewSinek(const Sinek this)
{
    printf("%s ", this->symbol);

    return this->symbol;
}

void deleteSinek(const Sinek this)
{
    if (this == NULL)   return;
    this->super->deleteBocek(this->super);
    free(this);
}