#ifndef DAIRE_H
#define DAIRE_H

#include "Sekil.h"

struct DAIRE{
    Sekil super; //inheritance
    double yaricap;
    void (*delete_Daire)(struct DAIRE*);

};
typedef struct DAIRE *Daire;
Daire new_Daire(char* renk, double yaricap);
double Alan(const Daire );
double Cevre(const Daire );
void delete_Daire(Daire );


#endif