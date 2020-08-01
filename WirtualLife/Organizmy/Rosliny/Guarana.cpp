//
// Created by Carlos on 09.05.2020.
//

#include "Guarana.h"

#define GUARANA_SILA 0

Guarana::Guarana(Swiat *swiat, int positionX, int positionY) : Roslina(swiat, positionX, positionY,GUARANA_SILA) {
    this->Wizerunek = '+' ;

}

Guarana::~Guarana() {

}

Organizm *Guarana::wygererujKopie() {
    Organizm * nasiono = new Guarana(swiat , -1 ,-1) ;

    return nasiono;
}

PrawdopodobienstwaRozsiania Guarana::podajPrawdopodobienstwo() {
    return pGuarana;
}

string Guarana::Gatunek() {
    return "Guarana";
}

bool Guarana::bonus() {
    return true;
}
