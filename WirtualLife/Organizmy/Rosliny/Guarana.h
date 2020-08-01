//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___GUARANA_H
#define PROJECTC___GUARANA_H


#include "../Roslina.h"

class Guarana : public Roslina {
public:
    Guarana(Swiat *swiat, int positionX, int positionY);

    virtual ~Guarana();

    Organizm *wygererujKopie() override;

    string Gatunek() override;

protected:
    bool bonus() override;

protected:
    PrawdopodobienstwaRozsiania podajPrawdopodobienstwo() override;


};


#endif //PROJECTC___GUARANA_H
