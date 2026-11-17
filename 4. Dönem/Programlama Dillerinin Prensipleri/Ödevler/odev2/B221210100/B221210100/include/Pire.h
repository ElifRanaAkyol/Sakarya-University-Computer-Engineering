#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE
{
    Bocek super;
    char* symbol;
    int value;

    void (*deletePire)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire newPire();
char* viewPire(const Pire);
void deletePire(const Pire);

#endif