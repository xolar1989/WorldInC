//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___WILK_H
#define PROJECTC___WILK_H

#include "../Zwierze.h"

class Wilk : public Zwierze {
public:
    Wilk(Swiat *swiat, int positionX, int positionY);

    ~Wilk() ;

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;

    Organizm *wygererujKopie() override;

    string Gatunek() override;

protected:
    bool czyTenSamGatunek(Organizm *organizm) override;


};


#endif //PROJECTC___WILK_H
