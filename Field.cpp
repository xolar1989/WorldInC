//
// Created by Carlos on 13.05.2020.
//

#include "Field.h"

Field::Field( int y,  int x)  {
    this->item = nullptr ;
    this->Y = y ;
    this->X = x ;
}


bool Field::isFreeField() {
    return item == nullptr;
}

void Field::setField(Organizm *nowy) {
    this->item = nowy ;
    nowy->setPositions(Y , X) ;


    int x = 0 ;
}

Organizm* Field::getItem() {
    return item ;
}

void Field::beFree() {
    this->item->setPositions(-1 , -1) ;
    this->item = nullptr ;
}