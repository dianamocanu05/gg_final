#pragma once
#include <iostream>
#include <graphics.h>
#include <winbgim.h>


struct Dreptunghi{
    int sus,jos,stanga,dreapta;
    int culoare;
};

void InitDreptunghi(int sstanga,int ssus, int ddreapta, int jjos, Dreptunghi&d, int cculoare=1)
{
    d.sus=ssus;
    d.stanga=sstanga;
    d.jos=jjos;
    d.dreapta=ddreapta;
    d.culoare=cculoare;
}

void Deseneaza(Dreptunghi d)
{
    setfillstyle(SOLID_FILL,d.culoare);
    bar(d.stanga,d.sus,d.dreapta,d.jos);

}

