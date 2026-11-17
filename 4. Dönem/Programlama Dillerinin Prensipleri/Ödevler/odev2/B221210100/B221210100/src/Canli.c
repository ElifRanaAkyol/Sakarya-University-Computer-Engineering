/** 
* @file / Canlý.c
* @description / Canlý dosyasý. Canlý iþlemleri yapýlýr. view fonksiyonu ile soyut sýnýf benzetimi yapar.
* @course / Programlama Dillerinin Prensipleri / 1-A
* @assignment / 2.Ödev
* @date / 12-05-2024
* @author / Muhammed Yusuf Öngel / muhammed.ongel@sakarya.edu.tr
*/
#include "Canli.h"

Canli newCanli(char* symbol)
{
    Canli this;
    
    //"Sýnýf" yapýsý için bellekte yer ayýrýyoruz.
    this = (Canli)malloc(sizeof(struct CANLI));
    
    this->value = 0;
    this->symbol = symbol;
    this->viewDead = &viewDead;
    this->deleteCanli = &deleteCanli;

    return this;
}

char* viewDead()
{
    return "X";
}

char* getSymbol(const Canli this)
{
    return this->symbol;
}

void deleteCanli(const Canli this)
{
    if(this == NULL)    return;
    free(this);
}
