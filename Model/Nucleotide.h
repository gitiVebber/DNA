//
// Created by vebber on 12/25/18.
//

#ifndef PROJECTDNA_NUCLEOTIDE_H
#define PROJECTDNA_NUCLEOTIDE_H

#include <iostream>
using std::ostream;
class Nucleotide
{
public:
    Nucleotide();
    Nucleotide(char c);
    Nucleotide& operator=(char nucleotide);
    Nucleotide& operator=(const Nucleotide &nucleotide);
    

    bool operator==(Nucleotide& nucleotide)const;
    bool operator!=(Nucleotide& nucleotide)const;
    bool operator==(char nucleotide)const;
    bool operator!=(char nucleotide)const;
    friend ostream& operator<<(ostream& os, const Nucleotide& nucleotide);
    Nucleotide pair();
    char getM_nucleotide();
    void setM_nucleotide(char c);

    

private:
    char isValid(char nucleotide);

    char m_nucleotide;
};


inline Nucleotide::Nucleotide() :m_nucleotide('A')
{}

inline Nucleotide::Nucleotide(char c)
{
    setM_nucleotide(c);
}

inline char Nucleotide::isValid(char nucleotide)
{
    nucleotide =(char)toupper(nucleotide);
    if (nucleotide != 'T' && nucleotide != 'C' && nucleotide != 'G' && nucleotide != 'A')
        throw std::invalid_argument("the nucleotid is not valide");
    return nucleotide;
}

inline ostream& operator<<(ostream& os, const Nucleotide& nucleotide)
{
    os << nucleotide.m_nucleotide;
    return os;
}
inline char Nucleotide::getM_nucleotide()
{
    return m_nucleotide;
}

inline void Nucleotide::setM_nucleotide(char c)
{
    try
    {
        m_nucleotide=isValid(c);
    }
    catch (const std::invalid_argument &execption)
    {
        throw std::invalid_argument(execption.what());
    }
}





#endif //PROJECTDNA_NUCLEOTIDE_H
