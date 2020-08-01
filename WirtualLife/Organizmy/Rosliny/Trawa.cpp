//
// Created by Carlos on 09.05.2020.
//

#include "Trawa.h"

#define TRAWA_SILA 0


Trawa::Trawa(Swiat *swiat, int positionX, int positionY) : Roslina(swiat, positionX, positionY,TRAWA_SILA) {
    this->Wizerunek = (char)176 ;
}

Trawa::~Trawa() {

}

Organizm *Trawa::wygererujKopie() {
    Organizm * nasiono = new Trawa(swiat , -1 ,-1) ;

    return nasiono;
}

PrawdopodobienstwaRozsiania Trawa::podajPrawdopodobienstwo() {
    return pTrawa;
}

string Trawa::Gatunek() {
    return "Trawa";
}
