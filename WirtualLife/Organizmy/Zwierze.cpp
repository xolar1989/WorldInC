//
// Created by Carlos on 09.05.2020.
//

#include "Zwierze.h"


#include <cstdlib>
#include <ctime>


#include "Kierunki.h"

Zwierze::Zwierze(Swiat *swiat, int positionX, int positionY, int inicijatywa, unsigned int sila) : Organizm(swiat,positionX,positionY,inicijatywa,sila)
{
    this->zasieg = 1 ;
}

Zwierze::~Zwierze() = default;

bool Zwierze::mozliwyRuch(int LOS) {

    switch(LOS){
        case 0:
            if(positionY > zasieg-1 ){
                return true ;
            }
            return false ;
        case 1:
            if(positionX > zasieg-1 ){
                return true ;
            }
            return false ;
        case 2:
            if(positionX < swiat->getSizeX() - zasieg){
                return true ;
            }
            return false ;
        case 3:
            if(positionY < swiat->getSizeY() - zasieg ){
                return true ;
            }
            return false ;
        default:
            return false ;

    }

}


void Zwierze::akcja() {

    int directionNumber = rand()%4 ;
    while(!mozliwyRuch(directionNumber)){
        directionNumber = rand()%4 ;
    }
    Kierunki KIERUNEK = Kierunki(directionNumber) ;

    int nowY = this->getPositionY() ;
    int nowX = this->getPositionX() ;


    switch(KIERUNEK){
        case PROSTO:
            ruchDoMiejsca(nowY-zasieg ,nowX) ;
            break ;
        case LEWO:
            ruchDoMiejsca(nowY , nowX-zasieg) ;
            break ;
        case PRAWO:
            ruchDoMiejsca(nowY , nowX+zasieg) ;
            break ;
        case DOL:
            ruchDoMiejsca(nowY+zasieg , nowX) ;
        default:
            break ;
    }

}


void Zwierze::ruchDoMiejsca(int Y, int X) {

    int nowY = this->getPositionY() ;
    int nowX = this->getPositionX() ;

    zwalniamPole() ;


    if(swiat->isFree(Y,X)){
        zajmujePole(Y,X) ;
    }
    else{
        //Pole jest zajete wiec kolizja ;
        Organizm* rywal = this->swiat->getOrganizm(Y,X) ;

        //sprawdzamy czy ten sam gatunek , rozmnazanie albo walka ;
        if(this->czyTenSamGatunek(rywal)){
            //jednak zostaje na swoim miejscu ;
            this->zajmujePole(nowY , nowX) ;
            rywal->rozmnazanie() ;
        }
        else if(this->dobryWech(rywal) || rywal->czyOdbilAtak(this)){
            this->zajmujePole(nowY , nowX) ;
        }
        else{
            rywal->kolizja(this) ;
        }


    }

}




void Zwierze::kolizja(Organizm* atakujacy) {

    Zwierze* zwierze = dynamic_cast<Zwierze *>(atakujacy) ;

    Field* miejsceWalki = swiat->getField(this->positionY , this->positionX) ;

    int Y = this->getPositionY() ;
    int X =this->getPositionX() ;

    if(this->getSila() > atakujacy->getSila()){
        string txt = this->Gatunek()+" zabija " + atakujacy->Gatunek() ;
        swiat->komentarze.push_back(txt) ;


        zwierze->Umrzyj(this) ;
    }
    else if(this->unik()){
        // wykonuje unik  ;
//        std::cout<<"Wykonuje unik"<<std::endl ;
        string txt = this->Gatunek()+" unika ataku " + atakujacy->Gatunek() ;
        swiat->komentarze.push_back(txt) ;

        this->akcja() ;
        zwierze->zajmujePole(Y,X) ;
    }
    else{
        string txt = atakujacy->Gatunek() +" zabija " + this->Gatunek() ;
        cout<<txt<<endl ;
        swiat->komentarze.push_back(txt) ;

        // zwalniam pole bo umieram :/
        this->zwalniamPole() ;
        zwierze->zajmujePole(Y,X) ;
        // atakujacy zabija mnie
        this->Umrzyj(atakujacy) ;

    }

}








