//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___MLECZ_H
#define PROJECTC___MLECZ_H

#include "../Roslina.h"

class Mlecz : public Roslina {
public:
    Mlecz(Swiat *swiat, int positionX, int positionY);

    virtual ~Mlecz();

    Organizm *wygererujKopie() override;

    void akcja() override;

    string Gatunek() override;

protected:
    PrawdopodobienstwaRozsiania podajPrawdopodobienstwo() override;
};


#endif //PROJECTC___MLECZ_H
