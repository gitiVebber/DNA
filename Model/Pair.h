//
// Created by vebber on 1/8/19.
//

#ifndef PROJECTDNA_PAIR_H
#define PROJECTDNA_PAIR_H

#include "IDna.h"
#include "../Model/SharedPtr.h"

class Pair : public IDna
{
public:
    Pair( SharedPtr<IDna> dna) : m_dna(dna){}
    size_t getLength() const { return m_dna->getLength(); }
    virtual Nucleotide operator[](const size_t index)
    { return m_dna->operator[](index).pair(); }


private:
    SharedPtr<IDna> m_dna;
};
#endif //PROJECTDNA_PAIR_H
