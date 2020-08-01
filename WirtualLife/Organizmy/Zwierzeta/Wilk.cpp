//
// Created by Carlos on 09.05.2020.
//



#define WILK_INICJATYWA 5
#define WILK_SILA 9

#include "Wilk.h"




Wilk::Wilk(Swiat *swiat, int positionX, int positionY) : Zwierze(swiat, positionX,positionY,WILK_INICJATYWA,WILK_SILA) {
   this->Wizerunek = 'W' ;
}

Wilk::~Wilk() {
}

void Wilk::akcja() {
    Zwierze::akcja();
}

void Wilk::kolizja(Organizm* atakujacy) {
    Zwierze::kolizja(atakujacy);
}

bool Wilk::czyTenSamGatunek(Organizm *organizm) {
    return dynamic_cast<Wilk*>(organizm) != nullptr;;
}

Organizm *Wilk::wygererujKopie() {
    Organizm * dziecko = new Wilk(swiat , -1 ,-1) ;

    return dziecko;
}

string Wilk::Gatunek() {
    return "Wilk";
}


