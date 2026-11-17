#ifndef SEKIL_H 
#define SEKIL_H


#include "time.h"
#include "math.h"
#include "string.h"

struct SEKIL{
    char *renk;
    char *olusturulmaTarihi;

    void (*setRenk)(struct SEKIL*, char*);
    char* (*getTarih)(struct SEKIL*);
    char* (*toString)(struct Sekil*, void*);
    double (*alan)();
    double (*cevre)();
    void (*delete_Sekil)(struct SEKIL*);

};
typedef struct SEKIL *Sekil;
Sekil new_Sekil(char* renk);
void setRenk(const Sekil, char*);
char* getTarih(const Sekil);
char* toString(const Sekil, void*);
void delete_Sekil(Sekil this);

#endif