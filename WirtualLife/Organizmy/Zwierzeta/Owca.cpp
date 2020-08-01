//
// Created by Carlos on 16.05.2020.
//

#include "Owca.h"


#define OWCA_INICJATYWA 4
#define OWCA_SILA 4

Owca::Owca(Swiat *swiat, int positionX, int positionY) : Zwierze(swiat, positionX,positionY, OWCA_INICJATYWA , OWCA_SILA){
    this->Wizerunek = 'O' ;

}


Owca::~Owca() {

}

void Owca::akcja() {
    Zwierze::akcja();
}

void Owca::kolizja(Organizm* atakujacy) {
    Zwierze::kolizja(atakujacy);
}

bool Owca::czyTenSamGatunek(Organizm *organizm) {
    return dynamic_cast<Owca*>(organizm) != nullptr;;
}

Organizm *Owca::wygererujKopie() {
    Organizm * dziecko = new Owca(swiat , -1 ,-1) ;

    return dziecko;
}

string Owca::Gatunek() {
    return "Owca";
}
