//
// Created by Carlos on 17.05.2020.
//

#include "Lista.h"


Lista::Lista() {
    first = nullptr ;
    size = 0 ;
}

Lista::~Lista() {

}

void Lista::pushBack(Organizm *organizm) {

    Element* nowy = new Element(organizm) ;

    if(first == nullptr) {
        first = nowy ;
    } else{
        Element* tmp = first ;
        while(tmp->next != nullptr){
            tmp = tmp->next ;
        }
        tmp->next = nowy ;
    }
    size++ ;
}

void Lista::deleteElement(Organizm* organizm) {
    Element* tmp  ;
    Element* item ;

    if(first->organizm == organizm){
        item = first ;
        first = first->next ;
        delete item ;
    }

    else{
        tmp = first ;
        while(tmp->next != nullptr ){
            if(tmp->next->organizm != organizm) {
                tmp = tmp->next;
            } else{
                break ;
            }
        }
        if(tmp->next != nullptr){
            item = tmp->next ;
            tmp->next = item->next ;
            delete item ;
        }


    }

size-- ;
}

void Lista::removeFront() {

    if(first != nullptr){
        Element* zwracana = first ;
        Organizm* organizm = first->organizm ;
        first = first->next ;
        size-- ;
        delete zwracana ;
        delete organizm ;

    }

}


Organizm* Lista::getOrganizmfromElement(int index) {
    Element* temp = first ;
    int id = 0  ;
    while(temp != nullptr && id != index){
        temp = temp->next ;
        id++ ;
    }
    if(temp == nullptr){
        return nullptr ;
    }
    return temp->organizm ;

}


bool Lista::containCzlowiek() {
    Element*temp = first ;
    Organizm* item = nullptr ;
    while(temp != nullptr){
        item = temp->organizm ;
        if(dynamic_cast<Czlowiek*>(item) != nullptr){
            return true ;
        }
        temp = temp->next ;
    }

    return false ;

}




int Lista::getSize() {
    return this->size ;
}