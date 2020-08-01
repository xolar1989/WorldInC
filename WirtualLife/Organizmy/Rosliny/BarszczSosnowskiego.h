//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___BARSZCZSOSNOWSKIEGO_H
#define PROJECTC___BARSZCZSOSNOWSKIEGO_H

#include "../Roslina.h"

class BarszczSosnowskiego : public Roslina {
public:
    BarszczSosnowskiego(Swiat *swiat, int positionX, int positionY);

    virtual ~BarszczSosnowskiego();

    void akcja() override;

    Organizm *wygererujKopie() override;


    string Gatunek() override;

protected:
    PrawdopodobienstwaRozsiania podajPrawdopodobienstwo() override;

    bool trujaca() override;


};


#endif //PROJECTC___BARSZCZSOSNOWSKIEGO_H
