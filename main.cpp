#include <iostream>
#include "FunctiiUtilitare.h"
#include "Meniu.h"
#include <fstream>
#include "Tabla.h"
using namespace std;

int main()
{

    initwindow(lungimeEcran,latimeEcran);
    Start();
    if(pvc)
    {
        JocPvC();
        //do stuff
    }
    else if(pvp)//pvp
    {
        JocPvP();
        //dupa win some bullshit
    }

    getch();

 return 0;
}
