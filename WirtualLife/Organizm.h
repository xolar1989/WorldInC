//
// Created by Carlos on 08.05.2020.
//

#ifndef PROJECTC___ORGANIZM_H
#define PROJECTC___ORGANIZM_H


#include "Swiat.h"


#include "Organizmy/Kierunki.h"
#include "ListaOrganizmow.h"

#include <vector>

class Swiat;

class Organizm {
public:
    virtual void akcja() = 0 ;
    virtual void kolizja(Organizm* atakujacy) = 0  ;
    virtual char rysowanie()  ;

//    virtual ListaOrganizmow gatunek() = 0 ;

    Organizm(Swiat* swiat ,int positionX, int positionY , int inicijatywa , unsigned int sila );
    virtual ~Organizm() ;

    int getPositionX() ;

    int getPositionY() ;

    void setPositions(int y , int x) ;

    void setSila(unsigned int sila) ;

    int getInicjatywa() ;

    bool isDead() ;

    unsigned int getSila() ;
    void Umrzyj(Organizm* atakujacy) ;

    virtual Organizm* wygererujKopie() =  0 ;


    void zwalniamPole()  ;

    void zajmujePole(int Y, int X) ;



    virtual void rozmnazanie() ;

    virtual bool czyOdbilAtak(Organizm* atakujacy) ;
    virtual bool dobryWech(Organizm* rywal) ;
    virtual bool unik() ;
    virtual string Gatunek() = 0 ;

protected:

    bool dead ;
    unsigned int sila ;
    int incijatywa ;
    int positionX ;
    int positionY ;
    char Wizerunek ;
    Swiat* swiat ;
    virtual void wypalanie() ;

    std::vector<KierunkiRozmnazania> otoczenie ;
    std::vector<KierunkiRozmnazania> zajeteOtoczenie;

private:
    bool czyZwierze(Organizm *organizm) ;
    void kierunekOtoczenie() ;
    void updateOtoczenia() ;
    bool zajeteOtoczenieZawiera(KierunkiRozmnazania kierunek) ;
    virtual void spal(int Y , int X) ;







};


#endif //PROJECTC___ORGANIZM_H
