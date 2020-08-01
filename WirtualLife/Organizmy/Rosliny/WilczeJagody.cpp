//
// Created by Carlos on 09.05.2020.
//

#include "WilczeJagody.h"

#define WILCZEJAGODY_SILA 99

WilczeJagody::WilczeJagody(Swiat *swiat, int positionX, int positionY) : Roslina(swiat, positionX,positionY,WILCZEJAGODY_SILA ) {
    this->Wizerunek = (char)248 ;
}

WilczeJagody::~WilczeJagody() {

}

Organizm *WilczeJagody::wygererujKopie() {
    Organizm * nasiono = new WilczeJagody(swiat , -1 ,-1) ;

    return nasiono;
}

PrawdopodobienstwaRozsiania WilczeJagody::podajPrawdopodobienstwo() {
    return pWilczeJagody;
}

bool WilczeJagody::trujaca() {
    return true;
}

string WilczeJagody::Gatunek() {
    return "WilczeJagody" ;
}


