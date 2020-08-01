//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___WILCZEJAGODY_H
#define PROJECTC___WILCZEJAGODY_H


#include "../Roslina.h"

class WilczeJagody : public Roslina {
public:
    WilczeJagody(Swiat *swiat, int positionX, int positionY);

    virtual ~WilczeJagody();

    Organizm *wygererujKopie() override;

    string Gatunek() override;

protected:
    bool trujaca() override;

    PrawdopodobienstwaRozsiania podajPrawdopodobienstwo() override;


};


#endif //PROJECTC___WILCZEJAGODY_H
