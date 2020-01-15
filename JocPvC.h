#pragma once
#include "Tabla.h"
#include <fstream>
#include "Player.h"
#include <cstdio>
int nrJuc=1;
int PCindex,marime;
bool computerMoved=false;
bool peLinie, peColoana, peDiag;
Player player,computer;
Dreptunghi tabla[3][3];
int matr[3][3];
char numeComputer[10];
char numePlayer[10];
int matriceAnt[3][3];
int castigator;

void StrategieComputerPeColoana()
{
    for(int i=0; i<3; i++)
    {
        int poz1=matr[i][0],poz2=matr[i][1],poz3=matr[i][2];
        //verific pe coloana daca celalalt player urmeaza sa faca o linie
        if(PotPunePiesa(marime,i,0,matr) && poz2>0 && poz3>0) //in acest caz, ii blochez urmatoarea miscare
        {
            PlaseazaPiesa(tabla,i,0,computer.piese[PCindex]);
            computerMoved=true;
            break;
        }
        else if(PotPunePiesa(marime,i,1,matr) && poz2>0 && poz1>0)
        {
            PlaseazaPiesa(tabla,i,1,computer.piese[PCindex]);
            computerMoved=true;
            break;
        }
        else if(PotPunePiesa(marime,i,2,matr) && poz1>0 && poz3>0)
        {
            PlaseazaPiesa(tabla,i,2,computer.piese[PCindex]);
            computerMoved=true;
            break;
        }
        break;

    }
      if(computerMoved)
            peColoana=true;

}

void StrategieComputerPeLinie()
{

    for(int i=0; i<3; i++)
    {

        int poz4=matr[0][i],poz5=matr[1][i],poz6=matr[2][i];
        //acelasi lucru, verificare pe linie
        if(PotPunePiesa(marime,0,i,matr) && poz5>0 && poz6>0)
        {
            PlaseazaPiesa(tabla,0,i,computer.piese[PCindex]);
            computerMoved=true;
            break;
        }
        if(PotPunePiesa(marime,i,1,matr) && poz4>0 && poz6>0)
        {
            PlaseazaPiesa(tabla,i,1,computer.piese[PCindex]);
            computerMoved=true;
            break;
        }
        if(PotPunePiesa(marime,i,2,matr) && poz4>0 && poz5>0)
        {
            PlaseazaPiesa(tabla,i,2,computer.piese[PCindex]);
            computerMoved=true;
            break;
        }

        if(computerMoved)
        {
            break;
            peLinie=true;
        }
    }

}


void StrategieComputerPeDiagonale()
{

    int poz7=matr[0][0],poz8=matr[1][1],poz9=matr[2][2];
    int poz10=matr[0][2],poz11=matr[2][0];

    if(PotPunePiesa(marime,0,0,matr) && poz8>0 && poz9>0)
    {
        PlaseazaPiesa(tabla,0,0,computer.piese[PCindex]);
        computerMoved=true;
    }
    else if(PotPunePiesa(marime,1,1,matr) && poz7>0 && poz9>0)
    {
        PlaseazaPiesa(tabla,1,1,computer.piese[PCindex]);
        computerMoved=true;
    }
    else if(PotPunePiesa(marime,2,2,matr) && poz7>0 && poz8>0)
    {
        PlaseazaPiesa(tabla,2,2,computer.piese[PCindex]);
        computerMoved=true;
    }
    else if(PotPunePiesa(marime,2,0,matr) && poz10>0 && poz8>0)
    {
        PlaseazaPiesa(tabla,2,0,computer.piese[PCindex]);
        computerMoved=true;
    }
    else if(PotPunePiesa(marime,1,1,matr) && poz10>0 && poz11>0)
    {
        PlaseazaPiesa(tabla,1,1,computer.piese[PCindex]);
        computerMoved=true;
    }
    else if(PotPunePiesa(marime,0,2,matr) && poz8>0 && poz11>0)
    {
        PlaseazaPiesa(tabla,0,2,computer.piese[PCindex]);
        computerMoved=true;
    }

    if(computerMoved)
        peDiag=true;



}
char GenereazaNumeComputer(char nume[10])
{

    char caractere[] =
        "0123456789"
        "!@#$%^&*"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    int lungime = strlen(caractere) - 1;


    srand(time(0));
    for(int z=0; z < 5; z++)
    {
        char aux[2];
        aux[0]=caractere[rand() % lungime];
        aux[1]='\0';
        strcat(nume, aux);

    }

}
bool AmAlesPvC(int x, int y)
{
    Dreptunghi buton;
    InitDreptunghi(501,0,lungimeEcran,latimeEcran,buton);
    return (Contine(x,y,buton));
}

void NumePVC()
{
    cleardevice();
    settextstyle(0,0,4);
    setcolor(WHITE);
    outtextxy(50,100,"Introdu numele:");
    outtextxy(50,200,"Player 1:");
    outtextxy(50,300,"Computer: ");
    GenereazaNumeComputer(numeComputer);
    outtextxy(350,300,numeComputer);
    IntroduNume(350,200,numePlayer,nrJuc,numeComputer);

}
void Refresh()
{
    computerMoved=false;
    peLinie=false;
    peColoana=false;
    peDiag=false;
    setfillstyle(SOLID_FILL,BLACK);
    settextstyle(0,0,4);
    bar(0,0,lungimeEcran,latimeEcran);
    CopiazaMatrice(matriceAnt,matr);
    if(nrJuc==1)
    {
        setcolor(4);
        outtextxy(50,50,numePlayer);
    }
    else
    {

        setcolor(1);
        outtextxy(latimeEcran-100,50,numeComputer);
    }

    int x,y,linie,coloana;
    int i;
    DeseneazaTabla(tabla);
    DeseneazaPiese(player);
    DeseneazaPiese(computer);
    if(nrJuc==1)
    {
        Click(x,y);

        for( i=0; i<6; i++)
        {

            if(Contine(x,y,player.piese[i].d))
            {
                player.piese[i].aFostSelectata=true;
                break;
            }
        }

    }
    else
    {
        PCindex=rand()%3;
        marime=computer.piese[PCindex].dimensiune;
        std::cout<<std::endl<<marime;

        StrategieComputerPeColoana();
        std::cout<<std::endl<<peColoana;
        if(peColoana==false)
        {
            StrategieComputerPeLinie();
            std::cout<<std::endl<<peLinie;
            if(peLinie==false)
            {
                StrategieComputerPeDiagonale();
                std::cout<<std::endl<<peDiag;
                if(peDiag==false)
                {
                    for(int i=0; i<3; i++)
                    {
                        for(int j=0; j<3; j++)
                        {

                            if(matr[i][j]==0) //verificam unde o putem punte
                            {

                                if(PotPunePiesa(marime,i,j,matr))
                                {

                                    PlaseazaPiesa(tabla,i,j,computer.piese[PCindex]);
                                    computerMoved=true;
                                    break;
                                }
                            }

                        }
                        if(computerMoved)//s a produs o schimbare
                            break;
                    }
                }
            }
        }
        /*for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {

                if(matr[i][j]==0) //verificam unde o putem punte
                {

                    if(PotPunePiesa(computer.piese[PCindex].dimensiune,i,j,matr))
                    {

                        PlaseazaPiesa(tabla,i,j,computer.piese[PCindex]);
                        computerMoved=true;
                        break;
                    }
                }

            }
            if(computerMoved)//s a produs o schimbare
            {
                break;
            }
        }*/

    }
    if(nrJuc==1)
    {
        Click(x,y);
        int l=DeterminaLinie(y);
        int c=DeterminaColoana(x);

        if(PotPunePiesa(player.piese[i].dimensiune,l,c,matr))
        {
            Piesa mutare;
            CopiazaPiese(mutare,player.piese[i]);
            PlaseazaPiesa(tabla,l,c,player.piese[i]);
            Dreptunghi confirma;
            Dreptunghi undo;
            DeseneazaButoane(confirma,undo);
            Click(x,y);
            if(Contine(x,y,undo))
            {
                CopiazaMatrice(matr,matriceAnt);
                CopiazaPiese(player.piese[i],mutare);
            }

            //confirma sau undo;

        }

    }


    nrJuc=(nrJuc++)%2+1;

}
void JocPvC()
{
    time_t gameStart;
    time_t timpFinal;
    gameStart=clock();
    int playerCastigator;
    nrJuc=1;
    InitTabla(tabla);
    Piesa pieseP1[6];
    Piesa pieseP2[6];
    InitPiese(pieseP1,pieseP2);
    InitPlayer(player,numePlayer,pieseP1);
    InitPlayer(computer,numeComputer,pieseP2);
    while(1)
    {
        Refresh();
        castigator=win(matr);
        if(castigator!=0)
        {

            timpFinal=clock();
            break;
        }
    }
    std::cout<<std::endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            std::cout<<matr[i][j]<<' ';
        std::cout<<std::endl;
    }
    settextstyle(0,0,4);
    char buffer[40];
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,0,lungimeEcran,latimeEcran);

    time_t timpTotal=(timpFinal-gameStart)/ CLOCKS_PER_SEC;

    if(castigator==1)
    {
        sprintf(buffer,"Jucatorul %s a castigat!!!",numePlayer);
        outtextxy(100,100,buffer);
        sprintf(buffer,"%s %d",numePlayer,timpTotal);
        ScrieInFisier(buffer);
    }
    else
    {
        sprintf(buffer,"Jucatorul %s a castigat!!!",numeComputer);
        outtextxy(100,100,buffer);
        sprintf(buffer,"%s %d",numeComputer,timpTotal);
        ScrieInFisier(buffer);
    }
    AfiseazaNEntryuri(5);


}


