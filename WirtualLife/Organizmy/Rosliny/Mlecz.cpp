//
// Created by Carlos on 09.05.2020.
//

#include "Mlecz.h"

#define MLECZ_SILA 0

Mlecz::Mlecz(Swiat *swiat, int positionX, int positionY) : Roslina(swiat, positionX, positionY,MLECZ_SILA) {
    this->Wizerunek = 'm' ;
}

Mlecz::~Mlecz() {

}

Organizm *Mlecz::wygererujKopie() {
    Organizm * nasiono = new Mlecz(swiat , -1 ,-1) ;

    return nasiono;
}

PrawdopodobienstwaRozsiania Mlecz::podajPrawdopodobienstwo() {
    return pMlecz;
}

void Mlecz::akcja() {
    // trzy próby
    for (int i = 0; i <3 ; ++i) {
        Roslina::akcja();
    }
}

string Mlecz::Gatunek() {
    return "Mlecz";
}
