//
// Created by Carlos on 16.05.2020.
//

#ifndef PROJEKTSWIATC_ELEMENT_H
#define PROJEKTSWIATC_ELEMENT_H


#include "../WirtualLife/Organizm.h"

class Element {
public:
    Element* next ;
    Element( Organizm* organizm );
    ~Element() ;
    Organizm* organizm ;



};


#endif //PROJEKTSWIATC_ELEMENT_H
