#ifndef HABITAT_H
#define HABITAT_H

#include "Canli.h"

struct HABITAT
{
    void (*vs)(Canli, Canli);
    void (*bitkiVSpire)(Canli, Canli);
    void (*bocekVSbitki)(Canli, Canli);
    void (*sinekVSpire)(Canli, Canli);
    void (*bitkiVSsinek)(Canli, Canli);
    void (*sinekVSbocek)(Canli, Canli);
    void (*bocekVSpire)(Canli, Canli);
    void (*deleteHabitat)(struct HABITAT*);
};
typedef struct HABITAT* Habitat;

Habitat newHabitat();

void vs(Canli, Canli);

void bitkiVSpire(Canli, Canli);
void bocekVSbitki(Canli, Canli);
void sinekVSpire(Canli, Canli);
void bitkiVSsinek(Canli, Canli);
void sinekVSbocek(Canli, Canli);
void bocekVSpire(Canli, Canli);

void deleteHabitat(const Habitat);

#endif