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
    virtual Nucleotide& operator[](const size_t index)=0;
    virtual bool operator==(const IDna* iDnaSequnce)const=0;
    virtual bool operator!=(const IDna* iDnaSequnce)const=0;
    virtual  std::string get()const=0;
    virtual size_t getLength()const=0;


};
#endif //PROJECTDNA_IDNA_H
