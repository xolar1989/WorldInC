//
// Created by Carlos on 16.05.2020.
//

#include "Element.h"


Element::Element(Organizm *organizm) {
    this->organizm = organizm ;
    this->next = nullptr ;
}

Element::~Element() {
    this->organizm = nullptr ;
    this->next = nullptr ;
} ;


