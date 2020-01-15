#pragma once
#include <graphics.h>
#include <winbgim.h>
#include "Piesa.h"
#include <cmath>
#define latura 130

void InitTabla(Dreptunghi tabla[3][3])
{
    for(size_t i=0; i<3; i++)
        for(size_t j=0; j<3; j++)
            {
             tabla[i][j].stanga=270+ j*latura;
             tabla[i][j].sus=175+ i*latura;
             tabla[i][j].jos=tabla[i][j].sus+latura;
             tabla[i][j].dreapta=tabla[i][j].stanga+latura;
             tabla[i][j].culoare=BLACK;
            }
}

void DeseneazaTabla(Dreptunghi tabla[3][3])
{

    setcolor(WHITE);
    for(size_t i=0; i<3; i++)
        for(size_t j=0; j<3; j++)
           rectangle(tabla[i][j].stanga,tabla[i][j].sus,tabla[i][j].dreapta,tabla[i][j].jos);
}
void DeseneazaButoane(Dreptunghi &confirma,Dreptunghi &undo)
{

            InitDreptunghi(450,50,550,150,confirma,YELLOW);
            InitDreptunghi(600,50,700,150,undo,GREEN);
            Deseneaza(confirma);
            Deseneaza(undo);
            settextstyle(0,0,2);
            outtextxy(confirma.stanga,confirma.sus+20,"Confirma");
            outtextxy(undo.stanga+25,undo.sus+25,"Undo");
}
void PlaseazaPiesa(Dreptunghi tabla[3][3],int linie,int coloana,Piesa &p)
{
    setfillstyle(SOLID_FILL,p.d.culoare);
    int marime=p.d.dreapta-p.d.stanga;
    int undex=tabla[linie][coloana].stanga+(latura-marime)/2;
    int undey=tabla[linie][coloana].sus+(latura-marime)/2;
    p.d.stanga=undex;
    p.d.sus=undey;
    p.d.dreapta=undex+marime;
    p.d.jos=undey+marime;
    Deseneaza(p.d);

}
void InitPiese(Piesa piesePl1[6],Piesa piesePl2[6])
{
    for(int i=0; i<2; i++)
    {
        piesePl1[i].d.stanga=150;
        piesePl1[i].d.sus=200;
        piesePl1[i].d.dreapta=210;
        piesePl1[i].d.jos=260;
        piesePl1[i].d.culoare=4;
        piesePl1[i].dimensiune=3;
        piesePl1[i].contor=2;
    }
    for(int i=2; i<4; i++)
    {
        piesePl1[i].d.stanga=150;
        piesePl1[i].d.sus=375;
        piesePl1[i].d.dreapta=200;
        piesePl1[i].d.jos=425;
        piesePl1[i].d.culoare=4;
        piesePl1[i].dimensiune=2;
        piesePl1[i].contor=2;
    }
    for(int i=4; i<6; i++)
    {
        piesePl1[i].d.stanga=150;
        piesePl1[i].d.sus=500;
        piesePl1[i].d.dreapta=190;
        piesePl1[i].d.jos=540;
        piesePl1[i].d.culoare=4;
        piesePl1[i].dimensiune=1;
        piesePl1[i].contor=2;
    }
    for(int i=0; i<2; i++)
    {
        piesePl2[i].d.stanga=720;
        piesePl2[i].d.sus=200;
        piesePl2[i].d.dreapta=780;
        piesePl2[i].d.jos=260;
        piesePl2[i].d.culoare=1;
        piesePl2[i].dimensiune=-3;
        piesePl2[i].contor=2;
    }
    for(int i=2; i<4; i++)
    {
        piesePl2[i].d.stanga=730;
        piesePl2[i].d.sus=375;
        piesePl2[i].d.dreapta=780;
        piesePl2[i].d.jos=425;
        piesePl2[i].d.culoare=1;
        piesePl2[i].dimensiune=-2;
        piesePl2[i].contor=2;
    }
    for(int i=4; i<6; i++)
    {
        piesePl2[i].d.stanga=740;
        piesePl2[i].d.sus=500;
        piesePl2[i].d.dreapta=780;
        piesePl2[i].d.jos=540;
        piesePl2[i].d.culoare=1;
        piesePl2[i].dimensiune=-1;
        piesePl2[i].contor=2;
    }
}


bool PotPunePiesa(int dimensiune,int linie,int coloana,int Matrice[3][3])
{
 if(Matrice[linie][coloana]==0)
 {
    Matrice[linie][coloana]=dimensiune;
    return true;
 }
 if(std::abs(Matrice[linie][coloana])<std::abs(dimensiune))
 {
    Matrice[linie][coloana]=dimensiune;
    return true;
 }
 return false;
}
int DeterminaColoana(int xx)  //pe ce coloana
{

    if(xx>=270 && xx<400)
        return 0;
    if(xx>=400 && xx<530)
        return 1;
    if(xx>=530 && xx<=660)
        return 2;
}

int DeterminaLinie(int yy)  //pe ce linie
{

   if(yy>=175 && yy<305)
        return 0;
    if(yy>=305 && yy<435)
        return 1;
    if(yy>=435 && yy<=565)
        return 2;


}
