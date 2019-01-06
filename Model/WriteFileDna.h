//
// Created by vebber on 1/1/19.
//

#ifndef PROJECTDNA_WRITEFILEDNA_H
#define PROJECTDNA_WRITEFILEDNA_H
#include <fstream>
#include <iostream>
#include <string>
#include "DNA.h"

using std::string;
using std::ofstream;


class WriteFile
{
private:
    string m_file_name;
public:
    WriteFile(const char * path);
    WriteFile(WriteFile const & other);
    ~WriteFile();
    void write(const Dna dna);
};

#endif //PROJECTDNA_WRITEFILEDNA_H
