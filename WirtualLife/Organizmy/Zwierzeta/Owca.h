//
// Created by Carlos on 16.05.2020.
//

#ifndef PROJEKTSWIATC_OWCA_H
#define PROJEKTSWIATC_OWCA_H

#include "../Zwierze.h"


class Owca : public Zwierze {
public:
    Owca(Swiat *swiat, int positionX, int positionY);

     ~Owca();

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;

    Organizm *wygererujKopie() override;

    string Gatunek() override;

protected:
    bool czyTenSamGatunek(Organizm *organizm) override;
};


#endif //PROJEKTSWIATC_OWCA_H
