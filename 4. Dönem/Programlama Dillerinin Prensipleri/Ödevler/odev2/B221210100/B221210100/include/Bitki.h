#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI
{
    Canli super;
    char* symbol;
    int value;

    void (*deleteBitki)(struct BITKI*);
};
typedef struct BITKI* Bitki;

Bitki newBitki();
char* viewBitki(const Bitki);
void deleteBitki(const Bitki);

#endif