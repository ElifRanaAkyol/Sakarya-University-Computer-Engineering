#ifndef CANLI_H
#define CANLI_H

#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"

struct CANLI
{
    int value;
    char* symbol;
    
    char* (*view)();
    char* (*viewDead)();
    char* (*getSymbol)(struct CANLI*);
 
    void (*deleteCanli)(struct CANLI*);
};
typedef struct CANLI* Canli;

Canli newCanli();
char* viewDead();
char* getSymbol(const Canli);
void deleteCanli(const Canli);

#endif