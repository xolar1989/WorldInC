//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___ANTYLOPA_H
#define PROJECTC___ANTYLOPA_H


#include "../Zwierze.h"

class Antylopa : public Zwierze {
public:
    Antylopa(Swiat *swiat, int positionX, int positionY);

    void akcja() override;

     ~Antylopa();

    void kolizja(Organizm* atakujacy) override;

    bool unik() override;

    Organizm *wygererujKopie() override;

    string Gatunek() override;

protected:
    bool czyTenSamGatunek(Organizm *organizm) override;

};


#endif //PROJECTC___ANTYLOPA_H
