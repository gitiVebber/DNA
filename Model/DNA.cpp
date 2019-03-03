//
// Created by vebber on 12/29/18.
//
#include "DNA.h"
#include <cstring>
#include <sstream>
#define LENGTH_TO_PRINT 32

void Dna::init_DnaSequence(const char* dna)
{
    m_length = strlen(dna);
    if (!isValide(m_length))
        throw std::out_of_range("the dna length is wrongful");
    m_dnaSequence = new Nucleotide[m_length];
    for (size_t i = 0; i < m_length; i++)
        m_dnaSequence[i].setM_nucleotide(dna[i]) ;
}

Dna::Dna(const char* dnaSequence)
{
    try
    {
        init_DnaSequence(dnaSequence);
    }
    catch (const std::invalid_argument& e)
    {
        delete[] m_dnaSequence;
        throw std::invalid_argument("the Nucleotide is not valide");
    }
    catch (const std::out_of_range& e)
    {
        throw std::invalid_argument(e.what());
    }

}

Dna::Dna(const std::string& dnaSequence_s)
{
    try
    {
        init_DnaSequence(dnaSequence_s.c_str());
    }
    catch (const std::invalid_argument& e)
    {
        delete[] m_dnaSequence;
        throw std::invalid_argument("the Nucleotide is not valide");
    }
    catch (const std::out_of_range& e)
    {
        throw std::out_of_range(e.what());
    }
}

Dna::~Dna()
{
    delete[] m_dnaSequence;
}

Dna::Dna(const Dna& other)//copy
{
    Nucleotide* newarr = new Nucleotide[other.m_length];
    for (size_t i = 0; i < other.m_length; i++)
        newarr[i] = other.m_dnaSequence[i];
    m_length = other.m_length;
    m_dnaSequence = newarr;
}

Dna::Dna(const Dna& other, size_t from, size_t to)
{
    if (from > to || to > other.m_length)
        throw std::out_of_range("the index is out of range");
    m_dnaSequence = new Nucleotide[to - from];
    for (size_t i = 0; i < to - from; ++i)
        m_dnaSequence[i] = other.m_dnaSequence[to - from + i];
    this->m_length = to - from;
}

Dna& Dna::operator=(const std::string& d)
{
    if (!isValide(strlen(d.c_str())))
        throw std::out_of_range("the dna length is wrongful!");
    delete[] m_dnaSequence;
    m_length = strlen(d.c_str());
    m_dnaSequence = new Nucleotide[m_length];
    for (size_t i = 0; i < m_length; i++)
        m_dnaSequence[i] = d[i];
    return *this;
}

Dna& Dna::operator=(const char* d)
{
    if (!isValide(strlen(d)))
        throw std::out_of_range("the dna length is wrongful!");
    delete[] m_dnaSequence;
    m_length = strlen(d);
    m_dnaSequence = new Nucleotide[m_length];
    for (size_t i = 0; i < m_length; i++)
        m_dnaSequence[i] = d[i];
    return *this;

}

bool Dna::operator==(const IDna* dna)const
{
    if (m_length ==((Dna*)dna)->m_length)
    {
        for (size_t i = 0; i < m_length; ++i)
            if (m_dnaSequence[i] !=((Dna*)dna)->m_dnaSequence[i])
                return false;
        return true;
    }
    return false;
}

bool  Dna::operator==(const char* Sequence)const
{
    if (m_length == strlen(Sequence))
    {
        for (size_t i = 0; i < m_length; i++)
        {
            if (m_dnaSequence[i] != Sequence[i])
                return false;
        }
        return true;
    }
    return false;
}

bool Dna::operator==(const std::string Sequence)const
{
    return this->operator==(Sequence.c_str());
}

bool Dna::operator!=(const IDna* dna)const
{
    return !(m_dnaSequence ==((Dna*)dna)->m_dnaSequence);
}

Nucleotide Dna::operator[](const size_t index)
{
    if (index > m_length)
        throw std::invalid_argument("the location is out of range");
    return m_dnaSequence[index];
}

size_t  Dna::getLength() const
{
    return m_length;
}
