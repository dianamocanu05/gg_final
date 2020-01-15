#pragma once
#include "Dreptunghi.h"
#include <stdio.h>
struct Piesa{
Dreptunghi d;
int dimensiune;
int contor;
bool aFostSelectata=false;
};

void CopiazaPiese(Piesa& p1, Piesa p2)
{
    p1.aFostSelectata=p2.aFostSelectata;
    p1.contor=p2.contor;
    p1.d=p2.d;
    p1.dimensiune=p2.dimensiune;
}
