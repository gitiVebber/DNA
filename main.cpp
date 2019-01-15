#include <iostream>
#include <cstdio>//gets
#include <string.h>
#include "Model/Nucleotide.h"
#include "Model/DNA.h"
#include "View/Parser.h"
#include "View/CLI.h"
#include "Control/Executable.h"
#include "Model/CLIDataColection.h"
#include "Model/WriteFileDna.h"
bool testDnaCondChar()
{
    const char *nucleotide="agcaaa";
    const char *s="AGCAAA";
    Dna dna(nucleotide);
    if (dna==s)
        return true;
    return false;

}

//bool unitTestEqual ()
//{
//    const std::string c = "aaa";
//    const char *c1 = "aaa";
//    Dna dna(c);
//    Dna dna1(c1);
//
//    if(dna ==&dna1)
//        return true;
//    return false;
//}

//bool testOperatorEqual()
//{
//    char s[] = "ATGGTA";
//    IDna * iDnaSequence = new Dna(s);
//    Dna dnaSequence(s);
//    if ((*iDnaSequence) == &dnaSequence)
//        return true;
//    else
//        return false;
//}

bool testNucleotideCondDefult()
{
    Nucleotide nucleotide;
    return (nucleotide=='X');
}

bool testNucleotideCond()
{
    Nucleotide nucleotide('a');
    return (nucleotide.getM_nucleotide()=='A');
}

bool testNucleotide1()
{
    Nucleotide nucleotide('a');
    Nucleotide nucleotide1=nucleotide;
    return (nucleotide1.getM_nucleotide()=='A');
}

bool testNucleotideEqual()
{
    Nucleotide nucleotide('a');
    Nucleotide nucleotide1('A');
    return (nucleotide==nucleotide1);
}
bool testNucleotideNotEqual()
{
    Nucleotide nucleotide('c');
    Nucleotide nucleotide1('A');
    return (nucleotide!=nucleotide1);
}

bool testNucleotide()
{
    Nucleotide nucleotide('c');
    Nucleotide nucleotide1('A');
    return (nucleotide!=nucleotide1);
}

bool testNucleotidePair()
{
    Nucleotide nucleotide('c');
    Nucleotide nucleotide1=nucleotide.pair();
    return (nucleotide1.getM_nucleotide()=='G');
}

bool testNotValidNucleotideCond()
{
    try
    {
        Nucleotide nucleotide('b');
    }
    catch (const std::invalid_argument &argument)
    {
        return true;
    }
    return false;
}


int main() {


//    std::cout <<"1 ";
//    testNucleotideCondDefult()?std::cout <<"true"<<std::endl :std::cout <<"false"<<std::endl;
//    std::cout <<"2 ";
//    testNucleotideCond()?std::cout <<"true"<<std::endl :std::cout <<"false"<<std::endl;
//    std::cout <<"3 ";
//    testNotValidNucleotideCond()?std::cout <<"true"<<std::endl :std::cout <<"false"<<std::endl;
//    std::cout <<"4 ";
//    testNucleotideEqual()?std::cout <<"true"<<std::endl :std::cout <<"false"<<std::endl;
//    std::cout <<"5 ";
//    testNucleotide()?std::cout <<"true"<<std::endl :std::cout <<"false"<<std::endl;
//    std::cout <<"6 ";
//    testNucleotidePair()?std::cout <<"true"<<std::endl :std::cout <<"false"<<std::endl;
//    std::cout <<"7 ";
//    testNucleotide1()?std::cout <<"true"<<std::endl :std::cout <<"false"<<std::endl;
//    std::cout<<"TEST DNA:\n";
//    std::cout <<"1 ";
//    testDnaCondChar()?std::cout <<"true"<<std::endl :std::cout <<"false"<<std::endl;
//    //std::cout <<"2 ";
//    //testOperatorEqual()?std::cout <<"true"<<std::endl :std::cout <<"false"<<std::endl;
//    //std::cout <<"3 ";
////    unitTestEqual()?std::cout <<"true"<<std::endl :std::cout <<"false"<<std::endl;


    UiInterface* Ui=new CLI();
    CLIDataColection cliDataColection;
    Executable executable(Ui, &cliDataColection);
    executable.Execut();

    return 0;
}

