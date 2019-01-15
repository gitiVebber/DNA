//
// Created by vebber on 1/10/19.
//

#ifndef PROJECTDNA_SLICE_H
#define PROJECTDNA_SLICE_H

#include "../Model/SharedPtr.h"
#include "IDna.h"

class Slice : public IDna {

public:
    Slice(SharedPtr <IDna> dna, size_t from, size_t to) ;

    size_t getLength() const ;

    virtual Nucleotide operator[](const size_t index) ;


private:
    SharedPtr <IDna> m_dna;
    size_t m_from;
    size_t m_to;
};
#endif //PROJECTDNA_SLICE_H
