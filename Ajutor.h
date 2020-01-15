#pragma once
#include "Dreptunghi.h"
#include "FunctiiUtilitare.h"
#include "Start.h"

bool AmAlesAjutor(int x,int y)
{
    Dreptunghi buton;
    InitDreptunghi(757,25,925,91,buton);
    return (Contine(x,y,buton));
}

bool AmAlesInapoi(int x,int y)
{
    Dreptunghi buton;
    InitDreptunghi(765,25,985,75,buton);
    return (Contine(x,y,buton));

}

void Ajutor()
{
    int x, y;
    bar(0,0,lungimeEcran,latimeEcran);
    readimagefile("help.jpg",0,0,lungimeEcran,latimeEcran);
    Click(x,y);

    if(AmAlesInapoi(x,y))
        //Start();
        std::cout<<"inapoi";
}
