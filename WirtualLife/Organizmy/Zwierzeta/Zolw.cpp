//
// Created by Carlos on 09.05.2020.
//

#include "Zolw.h"

#define ZOLW_INICJATYWA 1
#define ZOLW_SILA 2

Zolw::Zolw(Swiat *swiat, int positionX, int positionY) : Zwierze(swiat, positionX,positionY , ZOLW_INICJATYWA , ZOLW_SILA ){

    this->Wizerunek = (char)254 ;
}

Zolw::~Zolw() {
}

void Zolw::akcja() {

    int LOS = rand()%4 ;

    if(LOS == 0) {
        Zwierze::akcja();
    }
}


void Zolw::kolizja(Organizm* atakujacy) {
    Zwierze::kolizja(atakujacy);
}

bool Zolw::czyTenSamGatunek(Organizm *organizm) {
    return dynamic_cast<Zolw*>(organizm) != nullptr;
}

Organizm *Zolw::wygererujKopie() {

    Organizm * dziecko = new Zolw(swiat , -1 ,-1) ;

    return dziecko;
}

bool Zolw::czyOdbilAtak(Organizm *atakujacy) {

    return atakujacy->getSila() < 5;
}

string Zolw::Gatunek() {
    return "Zolw";
}
