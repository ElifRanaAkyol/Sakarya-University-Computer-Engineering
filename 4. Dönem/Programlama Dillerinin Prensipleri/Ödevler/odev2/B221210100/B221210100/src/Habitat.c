/** 
* @file / Habitat.c
* @description / Habitat dosyasý. Burada yapýlan þeyler türleri kapýþtýrma
* @course / Programlama Dillerinin Prensipleri / 1-A
* @assignment / 2.Ödev
* @date / 12-05-2024
* @author / Muhammed Yusuf Öngel / muhammed.ongel@sakarya.edu.tr
*/

#include "Habitat.h"

Habitat newHabitat()
{
    Habitat this;

    //"Sýnýf" yapýsý için bellekte yer ayýrýyoruz.
    this = (Habitat)malloc(sizeof(struct HABITAT));

    this->vs = &vs;
    this->bitkiVSpire = &bitkiVSpire;
    this->bitkiVSsinek = &bitkiVSsinek;
    this->bocekVSbitki = &bocekVSbitki;
    this->bocekVSpire = &bocekVSpire;
    this->sinekVSbocek = &sinekVSbocek;
    this->sinekVSpire = &sinekVSpire;
    this->deleteHabitat = &deleteHabitat;

    return this;
}

//c2 sürekli olarak bitiþ çizgisine daha yakýn. Bu yüzden eðer deðerleri de eþitse c1 ölür.
void vs(Canli c1, Canli c2)
{
    if((c1->symbol == "B" && c2->symbol == "P") || (c1->symbol == "P" && c2->symbol == "B"))
    {
        bitkiVSpire(c1, c2);
    }
    
    if((c1->symbol == "B" && c2->symbol == "S") || (c1->symbol == "S" && c2->symbol == "B"))
    {
        bitkiVSsinek(c1, c2);
    }
    
    if((c1->symbol == "C" && c2->symbol == "B") || (c1->symbol == "B" && c2->symbol == "C"))
    {
        bocekVSbitki(c1, c2);
    }
    
    if((c1->symbol == "C" && c2->symbol == "P") || (c1->symbol == "P" && c2->symbol == "C"))
    {
        bocekVSpire(c1, c2);
    }
    
    if((c1->symbol == "S" && c2->symbol == "C") || (c1->symbol == "C" && c2->symbol == "S"))
    {
        sinekVSbocek(c1, c2);
    }
    
    if((c1->symbol == "S" && c2->symbol == "P") || (c1->symbol == "P" && c2->symbol == "S"))
    {
        sinekVSpire(c1, c2);
    }
    
    if((c1->symbol == "B" && c2->symbol == "B") || (c1->symbol == "C" && c2->symbol == "C") || (c1->symbol == "S" && c2->symbol == "S") || (c1->symbol == "P" && c2->symbol == "P"))
    {
        if(c1->value > c2->value)
            c2->symbol = c2->viewDead();

        else if(c1->value < c2->value)
            c1->symbol = c1->viewDead();
        
        else if(c1->value == c2->value)
            c1->symbol = c1->viewDead();
    }
}

void bitkiVSpire(Canli c1, Canli c2)
{
    if(c1->symbol == "B")
        c2->symbol = c2->viewDead();

    else
        c1->symbol = c1->viewDead();
}

void bitkiVSsinek(Canli c1, Canli c2)
{
    if(c1->symbol == "B")
        c2->symbol = c2->viewDead();

    else
        c1->symbol = c1->viewDead();
}

void bocekVSbitki(Canli c1, Canli c2)
{
    if(c1->symbol == "C")
        c2->symbol = c2->viewDead();

    else
        c1->symbol = c1->viewDead();
}

void bocekVSpire(Canli c1, Canli c2)
{
    if(c1->symbol == "C")
        c2->symbol = c2->viewDead();

    else
        c1->symbol = c1->viewDead();
}

void sinekVSbocek(Canli c1, Canli c2)
{
    if(c1->symbol == "S")
        c2->symbol = c2->viewDead();

    else
        c1->symbol = c1->viewDead();
}

void sinekVSpire(Canli c1, Canli c2)
{
    if(c1->symbol == "S")
        c2->symbol = c2->viewDead();

    else
        c1->symbol = c1->viewDead();
}

void deleteHabitat(const Habitat this)
{
    if(this == NULL)    return;
    free(this);
}