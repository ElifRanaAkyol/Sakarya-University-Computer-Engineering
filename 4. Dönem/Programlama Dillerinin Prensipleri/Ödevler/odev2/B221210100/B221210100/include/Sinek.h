#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK
{
    Bocek super;
    char* symbol;
    int value;

    void (*deleteSinek)(struct SINEK*);
};
typedef struct SINEK* Sinek;

Sinek newSinek();
char* viewSinek(const Sinek);
void deleteSinek(const Sinek);

#endif