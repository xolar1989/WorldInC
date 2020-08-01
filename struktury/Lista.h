//
// Created by Carlos on 17.05.2020.
//

#ifndef PROJEKTSWIATC_LISTA_H
#define PROJEKTSWIATC_LISTA_H

#include "Element.h"

class Lista {
public:
    Lista() ;
    ~Lista() ;
    Element* first ;
    void pushBack(Organizm* organizm) ;
    void deleteElement(Organizm* organizm) ;
    void removeFront() ;
    Organizm* getOrganizmfromElement(int index) ;
    bool containCzlowiek() ;
    int getSize() ;
private:
    int size ;


};


#endif //PROJEKTSWIATC_LISTA_H
