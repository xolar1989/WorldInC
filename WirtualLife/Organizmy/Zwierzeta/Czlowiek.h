//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___CZLOWIEK_H
#define PROJECTC___CZLOWIEK_H



#include "../Zwierze.h"


class Czlowiek : public Zwierze {
public:
    Czlowiek(Swiat* swiat ,int positionX, int positionY , bool superMoc ) ;

    ~Czlowiek() ;

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;

    Organizm *wygererujKopie() override;

    string Gatunek() override;


private:
    void spal(int Y, int X) override;

    bool superMoc ;

protected:
    bool czyTenSamGatunek(Organizm *organizm) override;

};


#endif //PROJECTC___CZLOWIEK_H
