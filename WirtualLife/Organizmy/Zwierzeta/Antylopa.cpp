//
// Created by Carlos on 09.05.2020.
//

#include "Antylopa.h"


#define ANTYLOPA_INICJATYWA 4
#define ANTYLOPA_SILA 4

Antylopa::Antylopa(Swiat *swiat, int positionX, int positionY) : Zwierze(swiat,positionX ,positionY,ANTYLOPA_INICJATYWA,ANTYLOPA_SILA){
    this->Wizerunek = 'A' ;
    this->zasieg = 2 ;
}

Antylopa::~Antylopa() {

}

void Antylopa::akcja() {
    Zwierze::akcja();
}

void Antylopa::kolizja(Organizm* atakujacy) {
    Zwierze::kolizja(atakujacy);
}

bool Antylopa::czyTenSamGatunek(Organizm *organizm) {
    return dynamic_cast<Antylopa*>(organizm) != nullptr;;
}

Organizm *Antylopa::wygererujKopie() {
    Organizm * dziecko = new Antylopa(swiat , -1 ,-1) ;

    return dziecko;
}

bool Antylopa::unik() {
    int LOS = rand()%2 ;
    return LOS == 1;
}

string Antylopa::Gatunek() {
    return "Antylopa" ;
}
