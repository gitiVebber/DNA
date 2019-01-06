//
// Created by vebber on 1/1/19.
//

#ifndef PROJECTDNA_READFILEDNA_H
#define PROJECTDNA_READFILEDNA_H

//#include "DNA.h"
//class DnaReader
//{
//private:
//    char* path;
//public:
//    DnaReader(char* path);
//    ~DnaReader(){};
//    Dna read();
//};
//#include <iostream>
//#include <string>
//#include <fstream>
//#include "DNA.h"
//using std::ifstream;
//using std::ofstream;
//using std::string;
//using std::ostream;
//using std::iostream;
//
//class DnaReader
//{
//private:
//    char* path;
//public:
//    DnaReader(char* path);
//    Dna read();
#include <fstream>
#include <iostream>
#include <string>
#include "DNA.h"
using std::string;
using std::ifstream;

class ReadFile
{
private:
    string m_file_name;
public:
    ReadFile(const char * path);
    ReadFile(ReadFile const & other);
    ~ReadFile();
    Dna read();
};







#endif //PROJECTDNA_READFILEDNA_H
