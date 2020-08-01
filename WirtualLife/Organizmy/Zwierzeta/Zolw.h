//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___ZOLW_H
#define PROJECTC___ZOLW_H

#include "../Zwierze.h"

class Zolw: public Zwierze {
public:
    Zolw(Swiat *swiat, int positionX, int positionY) ;
    ~Zolw() ;
    void akcja() override;

    void kolizja(Organizm* atakujacy) override;

    Organizm *wygererujKopie() override;

    string Gatunek() override;

protected:
    bool czyTenSamGatunek(Organizm *organizm) override;
    bool czyOdbilAtak(Organizm *atakujacy) override;





};


#endif //PROJECTC___ZOLW_H
