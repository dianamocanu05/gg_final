#pragma once
#include "Tabla.h"
#include <fstream>
#include "Player.h"
#include <cstdio>
char nume1[20],nume2[20];
int nrPlayeri=2;
int playerCurent=1;
Player player1,player2;
Dreptunghi tablaAct[3][3];
int matrice[3][3];
int miscareAnterioara[3][3];
bool AmAlesPvP(int x, int y)
{
    Dreptunghi buton;
    InitDreptunghi(0,0,lungimeEcran/2,latimeEcran,buton);
    return (Contine(x,y,buton));
}

int win(int matrice[3][3])
{
    int neg=0,poz=0,i,j;
    for(i=0; i<3; i++)
    {
        neg=0;
        poz=0;
        for(j=0; j<3; j++)
            if(matrice[i][j]!=0)
            {
                if(matrice[i][j]<0)
                    neg++;
                else
                    poz++;
            }
        if(neg==3)
            return 2;
        if(poz==3)
            return 1;
    }
    for(j=0; j<3; j++)
    {
        neg=0;
        poz=0;
        for(i=0; i<3; i++)
            if(matrice[i][j]!=0)
            {
                if(matrice[i][j]<0)
                    neg++;
                else
                    poz++;
                if(neg==3)
                    return 2;
                if(poz==3)
                    return 1;
            }
    }
    neg=0;
    poz=0;
    for(i=0;i<3;i++)
    {
        if(matrice[i][i]!=0)
        {
         if(matrice[i][i]<0)
            neg++;
         else
            poz++;
        }
    }
    if(neg==3) return 2;
    if(poz==3) return 1;

    neg=0;
    poz=0;

    for(i=0;i<3;i++)
    {
        if(matrice[i][2-i]!=0)
        {
         if(matrice[i][2-i]<0)
            neg++;
         else
            poz++;
        }
    }
    if(neg==3) return 2;
    if(poz==3) return 1;

    return 0;
}


void NumePVP()
{
    cleardevice();
    settextstyle(0,0,4);
    setcolor(WHITE);
    outtextxy(50,100,"Introdu numele jucatorilor:");
    outtextxy(50,200,"Player 1:");
    outtextxy(50,300,"Player 2: ");
    outtextxy(50,200,"Player 1:");
    outtextxy(50,300,"Player 2: ");
    //outtextxy(350,200,nume1);

    IntroduNume(350,200,nume1,nrPlayeri);
    outtextxy(350,200,nume1);
    IntroduNume(350,300,nume2,nrPlayeri,nume1);

}

void Update()
{
    setfillstyle(SOLID_FILL,BLACK);
    settextstyle(0,0,4);
    bar(0,0,lungimeEcran,latimeEcran);
    CopiazaMatrice(miscareAnterioara,matrice);

    if(playerCurent==1)
    {
        setcolor(4);
        outtextxy(50,50,nume1);
    }
    else
    {

        setcolor(1);
        outtextxy(latimeEcran-100,50,nume2);
    }
    int x,y,linie,coloana;
    int i;
    DeseneazaTabla(tablaAct);
    DeseneazaPiese(player1);
    DeseneazaPiese(player2);
    Click(x,y);
    if(playerCurent==1)
    {
        for( i=0; i<6; i++)
        {

            if(Contine(x,y,player1.piese[i].d))
            {
                player1.piese[i].aFostSelectata=true;
                std::cout<<player1.piese[i].aFostSelectata;
                break;
            }
        }

    }
    else
    {
        for( i=0; i<6; i++)
        {

            if(Contine(x,y,player2.piese[i].d))
            {
                player2.piese[i].aFostSelectata=true;
                break;
            }
        }

    }
    Click(x,y);
    int l=DeterminaLinie(y);
    int c=DeterminaColoana(x);
    if(playerCurent==1)
    {

        if(PotPunePiesa(player1.piese[i].dimensiune,l,c,matrice))
        {
            Piesa mutare;
            CopiazaPiese(mutare,player1.piese[i]);
            PlaseazaPiesa(tablaAct,l,c,player1.piese[i]);
            Dreptunghi confirma;
            Dreptunghi undo;
            DeseneazaButoane(confirma,undo);
            Click(x,y);
            if(Contine(x,y,undo))
            {
                CopiazaMatrice(matrice,miscareAnterioara);
                CopiazaPiese(player1.piese[i],mutare);
            }

            //confirma sau undo;

        }

    }
    if(playerCurent==2)
    {
        if(PotPunePiesa(player2.piese[i].dimensiune,l,c,matrice))
        {

            Piesa mutare;
            CopiazaPiese(mutare,player2.piese[i]);
            PlaseazaPiesa(tablaAct,l,c,player2.piese[i]);
            Dreptunghi confirma;
            Dreptunghi undo;
            DeseneazaButoane(confirma,undo);
            Click(x,y);
            if(Contine(x,y,undo))
            {
                CopiazaMatrice(matrice,miscareAnterioara);
                CopiazaPiese(player2.piese[i],mutare);
            }

        }

    }
    if(!ComparaMatrici(matrice,miscareAnterioara)) //daca cele doua matrici sunt egale->s a apasat undo
    {
        playerCurent=(playerCurent++)%2+1;
    }
}
void JocPvP()
{
    time_t gameStart;
    time_t timpFinal;
    gameStart=clock();
    int playerCastigator;
    playerCurent=1;
    InitTabla(tablaAct);
    Piesa piesePl1[6];
    Piesa piesePl2[6];
    InitPiese(piesePl1,piesePl2);
    InitPlayer(player1,nume1,piesePl1);
    InitPlayer(player2,nume2,piesePl2);
    while(1)
    {
        Update();
        playerCastigator=win(matrice);
        if(playerCastigator!=0)
        {

            timpFinal=clock();
            break;
        }
    }
    settextstyle(0,0,4);
    char buffer[100];
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,0,lungimeEcran,latimeEcran);
    //aici calulam timpul pt leaderboard
    time_t timpTotal=(timpFinal-gameStart)/ CLOCKS_PER_SEC;
    if(playerCastigator==1)
    {
        sprintf(buffer,"Jucatorul %s a castigat!!!",nume1);
        outtextxy(100,100,buffer);
        sprintf(buffer,"%s %d",nume1,timpTotal);
        ScrieInFisier(buffer);
    }
    else
    {
        sprintf(buffer,"Jucatorul %s a castigat!!!",nume2);
        outtextxy(100,100,buffer);
        sprintf(buffer,"%s %d",nume2,timpTotal);
        ScrieInFisier(buffer);
    }
    AfiseazaNEntryuri(5);


}


