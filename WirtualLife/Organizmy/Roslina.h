//
// Created by Carlos on 09.05.2020.
//

#ifndef PROJECTC___ROSLINA_H
#define PROJECTC___ROSLINA_H

#include "../Organizm.h"
#include "Prawdopodobienstwo.h"

class Roslina : public Organizm {
public:
    Roslina(Swiat *swiat, int positionX, int positionY, unsigned int sila);

     ~Roslina();



    void akcja() override;

    void kolizja(Organizm *atakujacy) override;





protected:
    virtual bool bonus() ;
    void dajBonus(Zwierze* zwierze) ;
    virtual  PrawdopodobienstwaRozsiania podajPrawdopodobienstwo() = 0 ;

    bool udaloRozsiac()  ;
    virtual bool trujaca() ;


};


#endif //PROJECTC___ROSLINA_H
