//
// Created by Carlos on 09.05.2020.
//

#include "Czlowiek.h"
#include "conio.h"

#define CZLOWIEK_INICJATYWA 4
#define CZLOWIEK_SILA 5

#define CZLOWIEK_PRZOD 119  // klawisz w
#define CZLOWIEK_LEWO 97    // klawisz a
#define CZLOWIEK_PRAWO 100  // klawisz d
#define CZLOWIEK_DOL 115    // klawisz s


//#define CZLOWIEK_PRZOD 1  // klawisz w
//#define CZLOWIEK_LEWO 2    // klawisz a
//#define CZLOWIEK_PRAWO 3  // klawisz d
//#define CZLOWIEK_DOL 4    // klawisz s


Czlowiek::Czlowiek(Swiat* swiat ,int positionX, int positionY , bool superMoc ) : Zwierze(swiat ,positionX,positionY, CZLOWIEK_INICJATYWA , CZLOWIEK_SILA) {
    this->Wizerunek = 'C' ;
    this->superMoc = superMoc ;
}

Czlowiek::~Czlowiek() {}

void Czlowiek::akcja() {
    int klawisz = _getch() ;
    bool ruszyl = false ;
//    int klawisz = rand()%4+1 ;

    while(!ruszyl) {
        switch (klawisz) {
            case CZLOWIEK_PRZOD:
                if(this->mozliwyRuch(PROSTO)){
                    ruchDoMiejsca(getPositionY() - zasieg, getPositionX());
                }
               ruszyl = true ;
                break;
            case CZLOWIEK_LEWO:
                if(this->mozliwyRuch(LEWO)) {
                    ruchDoMiejsca(getPositionY(), getPositionX() - zasieg);
                }
                ruszyl = true ;
                break;
            case CZLOWIEK_PRAWO:
                if(this->mozliwyRuch(PRAWO)) {
                    ruchDoMiejsca(getPositionY(), getPositionX() + zasieg);
                }
                ruszyl = true ;
                break;
            case CZLOWIEK_DOL:
                if(this->mozliwyRuch(DOL)) {
                    ruchDoMiejsca(getPositionY() + zasieg, getPositionX());
                }
                ruszyl = true ;
            default:
                break;
        }
    }
    if(!this->isDead() && superMoc) {
        Organizm::wypalanie();
    }
}

void Czlowiek::kolizja(Organizm* atakujacy) {
    Zwierze::kolizja(atakujacy);
}

bool Czlowiek::czyTenSamGatunek(Organizm *organizm) {
    // mógbym dać tutaj dynamic cast ale bez sensu bo jest tylko jeden człowiek na swiecie
    return false;
}

Organizm *Czlowiek::wygererujKopie() {
    return nullptr;
}

string Czlowiek::Gatunek() {
    return "Czlowiek";
}

void Czlowiek::spal(int Y, int X) {


    Organizm* spalonyOrganizm =  swiat->getOrganizm(Y,X) ;

    string txt = "pale " + spalonyOrganizm->Gatunek() ;

    swiat->komentarze.push_back(txt) ;

    spalonyOrganizm->zwalniamPole();
    spalonyOrganizm->Umrzyj(this);


}
