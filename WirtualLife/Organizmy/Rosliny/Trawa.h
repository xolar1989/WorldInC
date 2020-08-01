//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___TRAWA_H
#define PROJECTC___TRAWA_H

#include "../Roslina.h"




class Trawa : public Roslina{
public:

    Trawa(Swiat *swiat, int positionX, int positionY);

    virtual ~Trawa();

    Organizm *wygererujKopie() override;

    string Gatunek() override;

protected:
    PrawdopodobienstwaRozsiania podajPrawdopodobienstwo() override;


};


#endif //PROJECTC___TRAWA_H
