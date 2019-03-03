////
//// Created by vebber on 1/1/19.
////
#include "ReadFileDna.h"

ReadFile::ReadFile(const char *path)
{
    ifstream myfile(path);
    if (!myfile.is_open())
        throw ("unable to open file");
    while(!myfile.eof())
    {
        myfile >> m_file_name;
    }
    myfile.close();
}
ReadFile::ReadFile(ReadFile const & other):m_file_name(other.m_file_name){}
ReadFile::~ReadFile(){}

std::string ReadFile:: read()
{
    //Dna DNA(m_file_name);
    return m_file_name;
}