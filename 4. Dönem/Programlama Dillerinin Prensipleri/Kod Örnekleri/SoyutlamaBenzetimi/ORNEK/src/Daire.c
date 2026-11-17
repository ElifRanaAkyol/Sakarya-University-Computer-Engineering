#define _USE_MATH_DEFINES
#include <math.h>   
#include "Daire.h"
Daire new_Daire(char* renk, double yaricap)
{
    Daire this;
    this = (Daire)malloc(sizeof(struct DAIRE));
    this->super = new_Sekil(renk);
    this->yaricap = yaricap;
    
    this->super->alan = &Alan; //artık buradaki alan fonksiyonunu göstericek
    this->super->cevre = &Cevre;
    this->delete_Daire = &delete_Daire;
    
    return this;
} 

double Alan(const Daire this)
{
    return M_PI  *pow(this->yaricap,2);
}
double Cevre(const Daire this)
{
    return 2 * M_PI * this->yaricap;
}
void delete_Daire(Daire this)
{
    if (this == NULL)
    {
        return;
    }
    this->super->delete_Sekil(this->super);
    free(this);
}
