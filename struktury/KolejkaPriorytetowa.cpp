//
// Created by Carlos on 16.05.2020.
//

#include "KolejkaPriorytetowa.h"
#include "Element.cpp"


KolejkaPriorytetowa::KolejkaPriorytetowa() {
    first = nullptr ;
    size = 0 ;
}

KolejkaPriorytetowa::~KolejkaPriorytetowa() {
}

int KolejkaPriorytetowa::Size() {
    return this->size ;
}

void KolejkaPriorytetowa::wstaw(Organizm *organizm) {

    Element* nowy = new Element(organizm) ;
    if(first == nullptr){
        first = nowy;
    }
    else if(first->organizm->getInicjatywa() < nowy->organizm->getInicjatywa()){
        nowy->next = first ;
        first = nowy ;
    }
    else{
        Element* tmp = first ;
        while(tmp->next != nullptr && tmp->next->organizm->getInicjatywa()>= nowy->organizm->getInicjatywa()){
            tmp= tmp->next ;
        }
        nowy->next = tmp->next ;
        tmp->next = nowy ;
    }

    size++ ;


}

Organizm* KolejkaPriorytetowa::zdejmijMax() {
    if(first != nullptr){
        Element* zwracana = first ;
        Organizm* organizm = first->organizm ;
        first = first->next ;
        size-- ;
        delete zwracana ;
        return organizm ;
    }
    return nullptr ;

}

bool KolejkaPriorytetowa::empty() {
    return first == nullptr;
}