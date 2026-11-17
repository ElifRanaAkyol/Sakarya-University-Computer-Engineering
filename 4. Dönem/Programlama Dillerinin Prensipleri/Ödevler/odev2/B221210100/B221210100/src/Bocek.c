#include "Bocek.h"


Bocek newBocek(int value)
{
    Bocek this;
    
    //"Sýnýf" yapýsý için bellekte yer ayýrýyoruz.
    this = (Bocek)malloc(sizeof(struct BOCEK));

    this->symbol = "C";
    this->super = newCanli(this->symbol);
    this->super->value = value;
    this->super->view = &viewBocek;
    this->deleteBocek = &deleteBocek;

    return this;
}

char* viewBocek(const Bocek this)
{
    printf("%s ", this->symbol);

    return this->symbol;
}

void deleteBocek(const Bocek this)
{
    if(this == NULL)    return;
    this->super->deleteCanli(this->super);
    free(this);
}