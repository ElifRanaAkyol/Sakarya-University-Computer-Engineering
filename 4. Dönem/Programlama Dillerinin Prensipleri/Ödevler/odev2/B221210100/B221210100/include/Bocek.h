#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK
{
    Canli super;
    char* symbol;
    int value;

    void (*deleteBocek)(struct BOCEK*);
};
typedef struct BOCEK* Bocek;

Bocek newBocek();
char* viewBocek(const Bocek);
void deleteBocek(const Bocek);

#endif