//
// Created by vebber on 12/25/18.
//
#include "Nucleotide.h"
#ifndef PROJECTDNA_IDNA_H
#define PROJECTDNA_IDNA_H
class IDna
{
public:
    virtual ~IDna(){};
    virtual Nucleotide& operator[](const size_t index)=0;
    virtual bool operator==(const IDna* iDnaSequnce)const=0;
    virtual bool operator!=(const IDna* iDnaSequnce)const=0;
    //virtual  void ptint(const IDna* iDnaSequnce)const=0;

};
#endif //PROJECTDNA_IDNA_H
