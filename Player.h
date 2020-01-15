#pragma once
#include "Dreptunghi.h"

struct Player
{

    char nume[20];
    Piesa piese[6];
};

void DeseneazaPiese(Player pl)
{
    for(int i=0; i<6; i++)
    {
            Dreptunghi piesa=pl.piese[i].d;
            Deseneaza(piesa);
    }
}

void InitPlayer(Player& pl,char numePl[10],Piesa pieces[6])
{
    strcpy(pl.nume,numePl);
    for(int i=0;i<6;i++)
    {
        pl.piese[i]=pieces[i];
    }
}
