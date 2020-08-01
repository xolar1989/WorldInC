//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___LIS_H
#define PROJECTC___LIS_H

#include "../Zwierze.h"

class Lis: public Zwierze {
public:
    Lis(Swiat *swiat, int positionX, int positionY);

    ~Lis();

    void akcja() override;

    bool dobryWech(Organizm *rywal) override;

    void kolizja(Organizm* atakujacy) override;

    Organizm *wygererujKopie() override;

    string Gatunek() override;

protected:
    bool czyTenSamGatunek(Organizm *organizm) override;
};




#endif //PROJECTC___LIS_H
