//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___ZWIERZE_H
#define PROJECTC___ZWIERZE_H

#include "../Organizm.h"
#include "Kierunki.h"

class Zwierze : public Organizm{
public:
    Zwierze(Swiat* swiat ,int positionX, int positionY , int inicijatywa , unsigned int sila );

    ~Zwierze() ;

    virtual void akcja() override;

    virtual void kolizja(Organizm* atakujacy) override;




protected:
    virtual bool czyTenSamGatunek(Organizm *organizm) = 0 ;

    bool mozliwyRuch(int LOS) ;

    void ruchDoMiejsca(int Y , int X) ;

    int zasieg ;




};


#endif //PROJECTC___ZWIERZE_H
