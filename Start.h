#pragma once
#include <graphics.h>
#include <winbgim.h>
#include "ModJoc.h"
#include "Ajutor.h"

void Start()
{
    int x,y;
    readimagefile("menu.jpg",0,0,lungimeEcran,latimeEcran);
    Click(x,y);
    if(AmAlesJoaca(x,y))
        ModJoc();
    if(AmAlesAjutor(x,y))
        Ajutor();
}
