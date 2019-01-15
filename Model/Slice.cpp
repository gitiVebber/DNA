
//
// Created by vebber on 1/11/19.
//

#include "Slice.h"
Slice::Slice(SharedPtr <IDna> dna, size_t from, size_t to) : m_dna(dna), m_from(from), m_to(to)
{}

size_t Slice::getLength() const
{
    return m_to - m_from;
}

Nucleotide Slice::operator[](const size_t index)
{
        return m_dna->operator[](index+m_from-1);
}
