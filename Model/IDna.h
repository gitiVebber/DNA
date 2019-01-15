//
// Created by vebber on 12/25/18.
//
#include "Nucleotide.h"
#include <string>
#ifndef PROJECTDNA_IDNA_H
#define PROJECTDNA_IDNA_H


class IDna
{
public:
    virtual ~IDna(){};
    virtual Nucleotide operator[](const size_t index)=0;
    virtual size_t getLength()const=0;
};



//inline ostream& operator<<(ostream& os, const IDna& iDna)
//{
//    for (size_t i = 0; i < iDna.getLength(); i++)
//        os << *iDna[i];
//    return os;
//}
#endif //PROJECTDNA_IDNA_H

