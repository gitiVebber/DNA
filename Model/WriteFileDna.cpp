//
// Created by vebber on 1/1/19.
//
#include "WriteFileDna.h"

WriteFile::WriteFile(const std::string  path):m_file_name(path){}

WriteFile::WriteFile(WriteFile const & other):m_file_name(other.m_file_name){}

WriteFile::~WriteFile(){}

void WriteFile:: write(SharedPtr<IDna> dna)
{
    ofstream myfile;
    myfile.open(m_file_name.c_str());
    if (!myfile.is_open())
        throw  ("unable to open file");
    for (int i=0 ;i<dna->getLength();++i)
        myfile<<dna->operator[](i);myfile;
    myfile.close();
}
