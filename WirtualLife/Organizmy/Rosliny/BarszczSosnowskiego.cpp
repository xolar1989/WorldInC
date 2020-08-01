//
// Created by Carlos on 09.05.2020.
//

#include "BarszczSosnowskiego.h"

#define BARSZCZSOSNOWSKIEGO_SILA 10

BarszczSosnowskiego::BarszczSosnowskiego(Swiat *swiat, int positionX, int positionY) : Roslina(swiat,positionX,positionY,BARSZCZSOSNOWSKIEGO_SILA)
{
    this->Wizerunek = (char)178 ;
}

BarszczSosnowskiego::~BarszczSosnowskiego() {

}

Organizm *BarszczSosnowskiego::wygererujKopie() {
    Organizm * nasiono = new BarszczSosnowskiego(swiat , -1 ,-1) ;

    return nasiono;
}

PrawdopodobienstwaRozsiania BarszczSosnowskiego::podajPrawdopodobienstwo() {
    return pBarszczSosnowskiego;
}

bool BarszczSosnowskiego::trujaca() {
    return true;
}

void BarszczSosnowskiego::akcja() {

    Organizm::wypalanie();
    Roslina::akcja();
}

string BarszczSosnowskiego::Gatunek() {
    return "BarszczSosnowskiego";
}
