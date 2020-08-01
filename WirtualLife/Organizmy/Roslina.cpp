//
// Created by Carlos on 09.05.2020.
//

#include "Roslina.h"

#define ROSLINY_INICJATYWA 0



Roslina::Roslina(Swiat *swiat, int positionX, int positionY, unsigned int sila) : Organizm(swiat,positionX,positionY,ROSLINY_INICJATYWA,sila)
{}

Roslina::~Roslina() {

}

void Roslina::kolizja(Organizm *atakujacy) {

    Zwierze* zwierze = dynamic_cast<Zwierze *>(atakujacy) ;

    Field* miejsceWalki = swiat->getField(this->positionY , this->positionX) ;

    int Y = this->getPositionY() ;
    int X =this->getPositionX() ;

    this->zwalniamPole() ;


    if(trujaca()){
        string txt = this->Gatunek()+" zatruwa " + atakujacy->Gatunek() ;
        swiat->komentarze.push_back(txt) ;
        zwierze->Umrzyj(nullptr) ;
    }
    else{
        // zwalniam pole bo zostałem zjedzony :>
        string txt = atakujacy->Gatunek()+" konsumuje " + this->Gatunek() ;
        swiat->komentarze.push_back(txt) ;
        dajBonus(zwierze) ;
        zwierze->zajmujePole(Y,X) ;
    }

    this->Umrzyj(nullptr) ;
}

void Roslina::akcja() {
    if(this->udaloRozsiac()) {
        Organizm::rozmnazanie();
    }
}


void Roslina::dajBonus(Zwierze* zwierze) {
    if(bonus()){
        zwierze->setSila(zwierze->getSila()+3) ;
    }

}

bool Roslina::bonus() {
    return false;
}

bool Roslina::trujaca() {
    return false;
}


bool Roslina::udaloRozsiac() {
    double LOS = rand()%100+1 ;
    return LOS <= PrawdopodobienstwaRozsianiaTab[this->podajPrawdopodobienstwo()];

}




