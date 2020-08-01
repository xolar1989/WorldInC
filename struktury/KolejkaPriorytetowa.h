//
// Created by Carlos on 16.05.2020.
//

#ifndef PROJEKTSWIATC_KOLEJKAPRIORYTETOWA_H
#define PROJEKTSWIATC_KOLEJKAPRIORYTETOWA_H

#include "Element.h"

class KolejkaPriorytetowa {
public:
    KolejkaPriorytetowa() ;
    ~KolejkaPriorytetowa() ;
    Element* first ;
    void wstaw(Organizm* organizm);
    Organizm* zdejmijMax() ;
    int Size()  ;
    bool empty() ;



private:
    int size ;



};


#endif //PROJEKTSWIATC_KOLEJKAPRIORYTETOWA_H
