//
// Created by Carlos on 09.05.2020.
//

#include "Lis.h"

#define LIS_INICJATYWA 7
#define LIS_SILA 3

Lis::Lis(Swiat *swiat, int positionX, int positionY) : Zwierze(swiat, positionX,positionY,LIS_INICJATYWA , LIS_SILA){
  this->Wizerunek = 'L' ;
}

Lis::~Lis() {
}

void Lis::akcja() {
    Zwierze::akcja();
}

void Lis::kolizja(Organizm* atakujacy) {
    Zwierze::kolizja(atakujacy);
}

bool Lis::czyTenSamGatunek(Organizm *organizm) {
    return dynamic_cast<Lis*>(organizm) != nullptr;;
}

Organizm *Lis::wygererujKopie() {
    Organizm * dziecko = new Lis(swiat , -1 ,-1) ;

    return dziecko;
}

bool Lis::dobryWech(Organizm *rywal) {
    return rywal->getSila() > this->getSila() ;

}


string Lis::Gatunek() {
    return "Lis";
}
