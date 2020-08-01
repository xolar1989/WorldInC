//
// Created by Carlos on 13.05.2020.
//

#ifndef PROJECTC___FIELD_H
#define PROJECTC___FIELD_H


#include "WirtualLife/Organizm.h"

class Field {
public:
    Organizm* item ;
    bool isFreeField();
    void setField(Organizm* nowy) ;
    void beFree() ;
    Organizm* getItem() ;
    Field( int y,  int x) ;
private:
     int Y ;
    int X ;






};


#endif //PROJECTC___FIELD_H
