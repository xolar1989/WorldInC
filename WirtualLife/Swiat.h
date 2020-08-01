//
// Created by Carlos on 08.05.2020.
//

#ifndef PROJECTC___SWIAT_H
#define PROJECTC___SWIAT_H



#include "Organizm.h"
#include "./Organizmy/Zwierze.h"
#include "./Organizmy/Roslina.h"


#include "../Field.h"
#include "../struktury/KolejkaPriorytetowa.h"
#include "../struktury/Lista.h"


#include "vector"

#include "fstream"

class Swiat {
public:
    Swiat(int sizeX, int sizeY ) ;

    ~Swiat() ;

    Field*** Map ;

    Organizm* Postac ;

    void start(bool superMoc) ;

    void WykonajTure();

    void nastepnaTura() ;

    int WyswietlTure() ;

    void RysujSwiat();

    bool isFree(int Y , int X) ;

    Field* getField(int Y, int X ) ;

    Organizm* getOrganizm(int Y,int X);

    int getSizeX() ;

    int getSizeY() ;

    Organizm* generujLosowyOrganizm(int Y , int X) ;

    void Zabij(Organizm* doZabicia) ;

    Lista* Organizmy ;

    void dodajDziecko(Organizm *dziecko) ;

    bool GAMEOVER() ;

    vector<string> komentarze ;

   bool wczytajPlik();
    void zapiszPlik();


private:
    void wyczyscPlik() ;

    Organizm* generujOrganizm(ListaOrganizmow Typ , int Y,int X) ;

    Organizm* odtworzOrganizm(string nazwa , int Y , int X) ;

    void Informacje() ;

    bool gameover ;
    void RozpocznijNowaGre(bool superMoc) ;
    bool isFreeLine(int Y) ;

    int sizeX ;
    int sizeY;
    KolejkaPriorytetowa *kolejkaOrganizmow ;
    Lista* zabiteOrganizmy ;
    void ustawPostac(bool superMoc) ;
    int tura ;





};


#endif //PROJECTC___SWIAT_H
