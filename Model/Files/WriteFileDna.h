//
// Created by vebber on 1/1/19.
//

#ifndef PROJECTDNA_WRITEFILEDNA_H
#define PROJECTDNA_WRITEFILEDNA_H
#include <fstream>
#include <iostream>
#include <string>
#include "../IDna.h"
#include "../../Helper/SharedPtr.h"

using std::string;
using std::ofstream;


class WriteFile
{
private:
    string m_file_name;
public:
    WriteFile(const std::string  path);
    WriteFile(WriteFile const & other);
    ~WriteFile();
    void write(SharedPtr<IDna> dna);
};

#endif //PROJECTDNA_WRITEFILEDNA_H
