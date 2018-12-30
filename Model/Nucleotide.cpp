#include "Nucleotide.h"
#include <assert.h>

Nucleotide Nucleotide::Nucleotide::pair()
{
    char pair ;
    switch (this->m_nucleotide)
    {
        case 'A':
            pair = 'T';
            break;
        case 'C':
            pair = 'G';
            break;
        case 'G':
            pair = 'C';
            break;
        case 'T':
            pair = 'A';
        default:
            assert(this->m_nucleotide);
    }
    return Nucleotide(pair);
}

Nucleotide& Nucleotide::operator=(char nucleotide) {

    m_nucleotide = isValid(nucleotide);
    return *this;
}

Nucleotide& Nucleotide::operator=(const Nucleotide &nucleotide)
{
    m_nucleotide=nucleotide.m_nucleotide;
    return *this;
}
bool Nucleotide::operator!=(Nucleotide& nucleotide)const
{
    if(m_nucleotide!=nucleotide.m_nucleotide)
        return true;
    return false;
}

bool Nucleotide::operator==(Nucleotide& nucleotide)const
{
    return !(m_nucleotide!=nucleotide.m_nucleotide);
}

bool Nucleotide::operator==(char nucleotide)const
{
    if(m_nucleotide!=nucleotide)
        return true;
    return false;
}
bool Nucleotide::operator!=(char nucleotide)const
{
    return !(m_nucleotide!=nucleotide);
}