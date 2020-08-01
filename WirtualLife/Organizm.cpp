//
// Created by Carlos on 08.05.2020.
//

#include "Organizm.h"

using namespace std ;

#include "Organizmy/Kierunki.h"

Organizm::~Organizm() {
    this->swiat = nullptr ;
    this->incijatywa = -1 ;
    this->positionX = -1 ;
    this->positionY = -1 ;
    this->sila = -1 ;
    this->dead = -1  ;
}

Organizm::Organizm(Swiat *swiat, int positionX , int positionY, int inicijatywa, unsigned int sila) {
    this->swiat = swiat ;
    this->incijatywa = inicijatywa ;
    this->positionX = positionX ;
    this->positionY = positionY ;
    this->sila = sila ;
    this->dead = false  ;

}


int Organizm::getPositionX() {
    return this->positionX ;
}


int Organizm::getPositionY() {
    return this->positionY ;
}

void Organizm::setPositions(int y , int x) {
    this->positionX = x ;
    this->positionY = y ;
}

void Organizm::setSila(unsigned int sila) {
    this->sila = sila ;
}

int Organizm::getInicjatywa() {
    return incijatywa ;
}

unsigned int Organizm::getSila() {
    return sila ;
} ;

bool Organizm::isDead() {
    return this->dead ;
}

void Organizm::Umrzyj(Organizm *zabojca) {

    this->dead = true ;
    swiat->Zabij(this) ;

}

bool Organizm::czyOdbilAtak(Organizm *atakujacy) {
    return false;
}

bool Organizm::dobryWech(Organizm *rywal) {
    return false;
}

bool Organizm::unik() {
    return false;
}


void Organizm::zwalniamPole() {
    this->swiat->getField(positionY , positionX)->beFree() ;
}

void Organizm::zajmujePole(int Y, int X) {
    this->swiat->getField(Y,X)->setField(this) ;
}


void Organizm::updateOtoczenia() {
    otoczenie.clear() ;
    zajeteOtoczenie.clear() ;
}



void Organizm::kierunekOtoczenie() {

    updateOtoczenia() ;

    //GORA
    if(positionY > 0){
        if(swiat->getField(positionY-1 , positionX)->isFreeField()){
            otoczenie.push_back(GORNY) ;
        }
        else{
            zajeteOtoczenie.push_back(GORNY) ;
        }
        if(positionX> 0){
            if( swiat->getField(positionY -1 , positionX -1)->isFreeField() ){
                otoczenie.push_back(LEWYGORNY) ;
            } else{
                zajeteOtoczenie.push_back(LEWYGORNY) ;
            }
        }
        if(positionX < swiat->getSizeX() - 1 ){
            if(swiat->getField(positionY -1 , positionX + 1)->isFreeField() ) {
                otoczenie.push_back(PRAWYGORNY);
            }
            else{
                zajeteOtoczenie.push_back(PRAWYGORNY) ;
            }
        }
    }
    if(positionY < swiat->getSizeY() - 1 ){
        if(swiat->getField(positionY+1 , positionX)->isFreeField()){
            otoczenie.push_back(DOLNY) ;
        }
        else{
            zajeteOtoczenie.push_back(DOLNY) ;
        }
        if(positionX> 0){
            if(swiat->getField(positionY +1 , positionX -1)->isFreeField()) {
                otoczenie.push_back(LEWYDOLNY);
            }
            else{
                zajeteOtoczenie.push_back(LEWYDOLNY);
            }
        }
        if(positionX < swiat->getSizeX() - 1 ){
            if(swiat->getField(positionY +1 , positionX + 1)->isFreeField() ){
                otoczenie.push_back(PRAWYDOLNY) ;
            } else{
                zajeteOtoczenie.push_back(PRAWYDOLNY) ;
            }
        }
    }
    if(positionX> 0){
        if( swiat->getField(positionY, positionX -1)->isFreeField() ) {
            otoczenie.push_back(LEWYSRODEK);
        }
        else{
         zajeteOtoczenie.push_back(LEWYSRODEK) ;
        }
    }
    if(positionX < swiat->getSizeX() - 1 ){
        if(swiat->getField(positionY, positionX + 1)->isFreeField() ){
            otoczenie.push_back(PRAWYSRODEK) ;
        }
        else{
            zajeteOtoczenie.push_back(PRAWYSRODEK) ;
        }

    }

    if(otoczenie.empty()){
        otoczenie.push_back(BRAK) ;
    }

    if(zajeteOtoczenie.empty()){
        zajeteOtoczenie.push_back(BRAK) ;
    }

}


void Organizm::rozmnazanie() {


    kierunekOtoczenie() ;

    int index = rand()% otoczenie.size() ;


//    cout<<"Otoczenie size : "<<otoczenie.size()<<endl  ;
//    cout<<"ZajeteOtoczenie size : "<<zajeteOtoczenie.size()<<endl  ;
    KierunkiRozmnazania Typ = otoczenie[index] ;


//    for (int i = 0; i < otoczenie.size() ; ++i) {
//        cout<<"Z romnazania "<<otoczenie[i]<<endl ;
//    }


    Organizm* dziecko = this->wygererujKopie() ;

    switch(Typ){
        case LEWYGORNY:
            dziecko->zajmujePole(positionY -1 , positionX-1) ;
            break ;
        case GORNY:
            dziecko->zajmujePole(positionY -1 , positionX) ;
            break ;
        case PRAWYGORNY:
            dziecko->zajmujePole(positionY -1 , positionX+1) ;
            break ;
        case LEWYSRODEK:
            dziecko->zajmujePole(positionY  , positionX-1) ;
            break ;
        case PRAWYSRODEK:
            dziecko->zajmujePole(positionY  , positionX+1) ;
            break ;
        case LEWYDOLNY:
            dziecko->zajmujePole(positionY+1  , positionX-1) ;
            break ;
        case DOLNY:
            dziecko->zajmujePole(positionY+1  , positionX) ;
            break ;
        case PRAWYDOLNY:
            dziecko->zajmujePole(positionY+1  , positionX+1) ;
            break ;
        case BRAK:
            delete dziecko ;
            dziecko = nullptr ;
            break ;
        default:
            break ;
    }
    if(dziecko != nullptr ){
        this->swiat->dodajDziecko(dziecko)  ;
    }

}


void Organizm::wypalanie() {

    kierunekOtoczenie() ;
    if(zajeteOtoczenieZawiera(LEWYGORNY)){
        spal(positionY -1 , positionX-1) ;
    }
    if(zajeteOtoczenieZawiera(GORNY)){
        spal(positionY -1 , positionX) ;
    }
    if(zajeteOtoczenieZawiera(PRAWYGORNY)){
        spal(positionY -1 , positionX+1);
    }
    if(zajeteOtoczenieZawiera(LEWYSRODEK)){
        spal(positionY  , positionX-1);
    }
    if(zajeteOtoczenieZawiera(PRAWYSRODEK)){
        spal(positionY  , positionX+1);
    }
    if(zajeteOtoczenieZawiera(LEWYDOLNY)){
        spal(positionY+1  , positionX-1);
    }
    if(zajeteOtoczenieZawiera(DOLNY)){
        spal(positionY+1  , positionX);
    }
    if(zajeteOtoczenieZawiera(PRAWYDOLNY)){
        spal(positionY+1  , positionX+1);
    }

}


void Organizm::spal(int Y, int X) {
   Organizm* spalonyOrganizm =  swiat->getOrganizm(Y,X) ;


   if(czyZwierze(spalonyOrganizm)) {
       cout<<"paleeee"<<endl ;
       spalonyOrganizm->zwalniamPole();
       spalonyOrganizm->Umrzyj(this);
   }

}



bool Organizm::zajeteOtoczenieZawiera(KierunkiRozmnazania kierunek) {
    for (int i = 0; i <zajeteOtoczenie.size() ; ++i) {
        if(zajeteOtoczenie[i] == kierunek){
            return true ;
        }
    }
    return false ;
}



bool Organizm::czyZwierze(Organizm *organizm)  {
    Zwierze* zwierze = dynamic_cast<Zwierze *>(organizm) ;
    return zwierze != nullptr ;

}


char Organizm::rysowanie() {
    return this->Wizerunek ;
}

