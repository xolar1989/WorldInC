//
// Created by Carlos on 08.05.2020.
//
using namespace std ;


#include "Swiat.h"

#include "ListaOrganizmow.h"



#include "../Field.h"
#include "../Field.cpp"



#include "Includy.h"

#include "Organizmy/Zwierzeta/Czlowiek.cpp"
#include "Organizmy/Zwierzeta/Wilk.cpp"
#include "Organizmy/Zwierzeta/Zolw.cpp"
#include "Organizmy/Zwierzeta/Owca.cpp"
#include "Organizmy/Zwierzeta/Lis.cpp"
#include "Organizmy/Zwierzeta/Antylopa.cpp"

#include "Organizmy/Rosliny/Trawa.cpp"
#include "Organizmy/Rosliny/Mlecz.cpp"
#include "Organizmy/Rosliny/Guarana.cpp"
#include "Organizmy/Rosliny/WilczeJagody.cpp"
#include "Organizmy/Rosliny/BarszczSosnowskiego.cpp"



#include "../struktury/KolejkaPriorytetowa.cpp"
#include "../struktury/Lista.cpp"






#define ADRES "../Dane/zapis.txt"





Swiat::Swiat(int sizeX , int sizeY ) {
    this->sizeX = sizeX ;
    this->sizeY = sizeY ;
    this->gameover = false ;
    this->Map = new Field**[sizeY] ;
    this->Organizmy = new Lista() ;
    this->kolejkaOrganizmow = new KolejkaPriorytetowa() ;
    this->zabiteOrganizmy = new Lista() ;
    this->Postac = nullptr;
    this->tura = 1 ;


    for (int k = 0; k <sizeY ; ++k) {
        this->Map[k] = new Field*[sizeX] ;
    }
    for (int y = 0; y < sizeY; ++y) {
        for (int x = 0; x <sizeX ; ++x) {
            this->Map[y][x] = new Field(y,x) ;
        }
    }




}

void Swiat::ustawPostac(bool superMoc) {
    Postac = new Czlowiek(this , this->getSizeX()/2 , this->getSizeY() -2 , superMoc) ;

    getField(Postac->getPositionY(), Postac->getPositionX())->setField(Postac) ;

    this->Organizmy->pushBack(Postac) ;
}


Swiat::~Swiat() {}

void Swiat::start(bool superMoc) {
    if(!wczytajPlik()){
        RozpocznijNowaGre(superMoc) ;
    }
}



void Swiat::nastepnaTura() {
    this->tura++ ;
}

int Swiat::WyswietlTure() {
    return this->tura ;
}

bool Swiat::GAMEOVER() {
    return this->gameover ;
}

void Swiat::RozpocznijNowaGre(bool superMoc) {

    ustawPostac(superMoc) ;

    int iloscOrganizmow =getSizeX()*getSizeY()*PROCENT_ZAPELNIENIA ;
    int licznik = 0  ;
    int x,y ;
    Organizm* nowy = nullptr ;
    while(licznik< iloscOrganizmow){
        y = rand()%getSizeY() ;
        while(!isFreeLine(y) ){
            y = rand()%getSizeY() ;
        }
        x= rand()%getSizeX() ;
        while(!isFree(y ,x)){
            x= rand()%getSizeX() ;
        }



        nowy = generujLosowyOrganizm(y , x) ;

        licznik++ ;

        getField(y, x)->setField(nowy) ;

       this->Organizmy->pushBack(nowy) ;


    }


}

Organizm* Swiat::generujLosowyOrganizm(int Y, int X) {
    Organizm* nowy = nullptr ;
    int los  = rand()%ILOSC_ORGANIZMOW ;

    ListaOrganizmow Typ = ListaOrganizmow(los);

    nowy = generujOrganizm(Typ, Y,X) ;

    return nowy ;
}


Organizm* Swiat::generujOrganizm(ListaOrganizmow Typ, int Y, int X) {
    Organizm* nowy = nullptr ;

    switch(Typ){
        case trawa:
            nowy = new Trawa(this,X,Y) ;
            break ;
        case mlecz:
            nowy = new Mlecz(this,X,Y) ;
            break ;
        case guarana:
            nowy = new Guarana(this,X,Y) ;
            break ;
        case wilczeJagody:
            nowy = new WilczeJagody(this,X,Y) ;
            break ;
        case barszczSosnowskiego:
            nowy = new BarszczSosnowskiego(this,X,Y) ;
            break ;
        case wilk:
            nowy = new Wilk(this , X,Y) ;
            break ;
        case owca:
            nowy = new Owca(this , X ,Y) ;
            break ;
        case lis:
            nowy = new Lis(this , X,Y) ;
            break ;
        case zolw:
            nowy = new Zolw(this , X , Y) ;
            break ;
        case antylopa:
            nowy = new Antylopa(this , X ,Y) ;
            break ;
    }

    return nowy ;

}

Organizm* Swiat::odtworzOrganizm(string nazwa ,int Y , int X ) {
    Organizm* nowy = nullptr ;

    if(nazwa == "Zolw"){
        nowy = new Zolw(this , X , Y) ;
    }
    else if(nazwa == "Wilk"){
        nowy = new Wilk(this , X,Y) ;
    }
    else if(nazwa == "Owca"){
        nowy = new Owca(this , X,Y) ;
    }
    else if(nazwa == "Lis"){
        nowy = new Lis(this , X,Y) ;
    }
    else if(nazwa == "Czlowiek"){
        nowy = new Czlowiek(this , X,Y, true) ;
    }
    else if(nazwa == "Antylopa"){
        nowy = new Antylopa(this , X,Y) ;
    }
    else if(nazwa == "WilczeJagody"){
        nowy = new WilczeJagody(this , X,Y) ;
    }
    else if(nazwa == "Trawa"){
        nowy = new Trawa(this , X,Y) ;
    }
    else if(nazwa == "Mlecz"){
        nowy = new Mlecz(this , X,Y) ;
    }
    else if(nazwa == "Guarana"){
        nowy = new Guarana(this , X,Y) ;
    }
    else if(nazwa == "BarszczSosnowskiego"){
        nowy = new BarszczSosnowskiego(this , X,Y) ;
    }

    return nowy ;
}


void Swiat::dodajDziecko(Organizm *dziecko) {
    this->Organizmy->pushBack(dziecko) ;

}


int Swiat::getSizeX() {
    return sizeX ;
} ;

int Swiat::getSizeY() {
    return sizeY ;
};


void Swiat::WykonajTure() {
    Organizm* item ;
    for (int i = 0; i < Organizmy->getSize() ; ++i) {
        item = Organizmy->getOrganizmfromElement(i) ;
        kolejkaOrganizmow->wstaw(item) ;
    }


    while(!kolejkaOrganizmow->empty()){

        item = kolejkaOrganizmow->zdejmijMax()  ;
        if(!item->isDead()){
            item->akcja() ;
        }
    }

    if(Postac->isDead()){

        wyczyscPlik() ;
        gameover = true ;
    }
    else{
      nastepnaTura() ;
    }

    while(zabiteOrganizmy->getSize() > 0 ){
        zabiteOrganizmy->removeFront() ;
    }




}

void Swiat::Informacje() {
    if(!GAMEOVER()) {
        cout << "Tura : " << WyswietlTure() << " Postac atak : " << Postac->getSila() <<endl;

        int size = komentarze.size()< 5 ? komentarze.size() : 5 ;
        for (int i = 0; i <size ; ++i) {
            cout<<komentarze[i]<<endl ;
        }
        for (int j = 0; j <5-size ; ++j) {
            cout<<endl ;
        }
    }
    else{
        for (int i = 0; i <5 ; ++i) {
            if(i ==2 ) {
                for (int j = 0; j <this->getSizeX()-3 ; ++j) {
                 cout<<" " ;
                }
                cout <<"GAME OVER!!!"<< endl;
            } else{
                cout<<endl ;
            }
        }
    }


}


void Swiat::RysujSwiat() {
    this->Informacje() ;

    cout<<(char)201<<(char)205;
    for (int k = 0; k <sizeX ; ++k) {
        cout<<(char)205<<(char)205;
    }
    cout<<(char)187<<" ";
    cout<<endl ;
    for (int i = 0; i <sizeY ; ++i) {

            cout<<(char)186<<" ";



        for (int j = 0; j <sizeX ; ++j) {

            if(this->Map[i][j]->item == nullptr){
                cout<<"_"<<" ";
            }
            else{
                cout<<this->Map[i][j]->item->rysowanie()<<" " ;
            }
        }

            cout << (char) 186;

        cout<<endl ;
    }




    cout<<(char)200<<(char)205;
    for (int k = 0; k <sizeX ; ++k) {
        cout<<(char)205<<(char)205;
    }
    cout<<(char)188;
    cout<<endl ;


komentarze.clear();
}



bool Swiat::isFree(int Y, int X) {
    return this->Map[Y][X]->isFreeField() ;
}

Organizm* Swiat::getOrganizm(int Y, int X) {
    return getField(Y,X)->getItem() ;
}


void Swiat::Zabij(Organizm *doZabicia) {
    Organizmy->deleteElement(doZabicia) ;
    zabiteOrganizmy->pushBack(doZabicia) ;

}


bool Swiat::isFreeLine(int Y) {

    for (int j = 0; j <this->sizeX ; ++j) {
        if(isFree(Y,j)){
            return true ;
        }
    }
    return false ;

}





Field* Swiat::getField(int Y , int X) {
    return this->Map[Y][X] ;
}


void Swiat::zapiszPlik() {
    ofstream Plik(ADRES) ;


    for (int i = 0; i <Organizmy->getSize() ; ++i) {
        Organizm* item = Organizmy->getOrganizmfromElement(i) ;
        string txt = item->Gatunek() ;
        int X = item->getPositionX() ;
        int Y = item->getPositionY() ;
        int sila = item->getSila() ;

        Plik<<txt<<" "<<X<<" "<<Y<<" "<<sila<<endl ;
    }
    Plik.close() ;
}

bool Swiat::wczytajPlik() {
    ifstream Plik(ADRES) ;

    Organizm *nowy = nullptr ;

    if(Plik.is_open()){
        string Typ ;
        int Y  ;
        int X  ;
        int sila ;

        while(Plik>>Typ>>X>>Y>>sila){
//            cout<<Typ<<" "<<X<<" "<<Y<<" "<<sila<<endl ;
            nowy = odtworzOrganizm(Typ,Y,X) ;
            if(nowy->Gatunek() == "Czlowiek"){
                Postac = nowy ;

                getField(Postac->getPositionY(), Postac->getPositionX())->setField(Postac) ;

                this->Organizmy->pushBack(Postac) ;
            }
            else if(nowy != nullptr){
                getField(Y,X)->setField(nowy)  ;
                this->Organizmy->pushBack(nowy) ;
            }

        }

        if(this->Organizmy->getSize() > 0 && !this->Organizmy->containCzlowiek()){
            wyczyscPlik() ;
            gameover = true ;
        }

        Plik.close() ;

    }
    else{
        cout<<"Nie mozna otworzyc pliku"<<endl ;
    }

    return this->Organizmy->getSize() > 0 ;




}


void Swiat::wyczyscPlik() {
    ofstream plik ;
    plik.open(ADRES) ;
    plik.close() ;
}







