//
// Created by vebber on 12/29/18.
//

#ifndef PROJECTDNA_DNA_H
#define PROJECTDNA_DNA_H
#include "IDna.h"

class Dna:public IDna
{
public:

    explicit Dna() {}
    explicit Dna(const char* dnaSequence);
    explicit Dna(const std::string& dnaSequence_s);
    Dna(const Dna& other);
    Dna(const Dna&, size_t from, size_t to);

    virtual ~Dna();

    Dna& operator=(const Dna& dnaSequence);///////const?
    Dna& operator=(const std::string& d);
    Dna& operator=(const char* d);


    Nucleotide& operator[](const size_t index);

    bool operator==(const IDna* iDnaSequnce)const;
    bool operator==(const std::string Sequence)const;
    bool operator==(const char* Sequence)const;
    bool operator!=(const IDna* iDnaSequnce)const;
    //virtual  void ptint(const IDna* iDnaSequnce)const;
    friend ostream& operator<<(ostream& os, const Dna& dna);
    bool isValide(size_t len);

private:
    void init_DnaSequence(const char* dna);

    Nucleotide* m_dnaSequence;
    size_t m_length;

};

inline bool Dna::isValide(std::size_t len)
{
    return (len % 3) == 0;
}

#endif //PROJECTDNA_DNA_H

