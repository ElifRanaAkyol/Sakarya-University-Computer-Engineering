#include "Kare.h"

Kare new_Kare(char* renk, double kenar)
{
    Kare this;
    this = (Kare)malloc(sizeof(struct KARE));
    this->super = new_Sekil(renk);
    this->kenar = kenar;
    
    this->super->alan = &alan;
    this->super->cevre = &cevre;
    this->delete_Kare = &delete_Kare;
    
    return this;
}

double alan(const Kare this){
    return this->kenar * this->kenar;
}
double cevre(const Kare this){
    return 4 * this->kenar;
}
void delete_Kare(Kare this){
    if (this == NULL)
    {
        return;
    }
    this->super->delete_Sekil(this->super);
    free(this);
}