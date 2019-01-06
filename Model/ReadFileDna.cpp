////
//// Created by vebber on 1/1/19.
////
#include "ReadFileDna.h"
//
//#include <iostream>
//#include <fstream>
//
//DnaReader::DnaReader(char *mypath)
//{
//    path=mypath;
//}
//
//Dna DnaReader::read()
//{
//    std::ifstream myFile;
//    myFile.open(path);
//    if (!myFile.is_open())
//       throw std::logic_error("unable to open file");
//    char *newDna=new char[myFile.tellg()];
//    myFile>>newDna;
//    myFile.close();
//    return Dna (newDna);
//}
////
////ReadFile::ReadFile(char * path)
////{
////    std::ifstream myFile;
////    myFile.open(path);
////    if (!myFile.is_open())
////        throw std::logic_error("unable to open file");
////    myFile >> m_file_name;
////    myFile.close();
////}
////ReadFile::ReadFile(ReadFile const & other) :m_file_name(other.m_file_name) {}
////ReadFile::~ReadFile() {}
////Dna ReadFile::read()
////{
////    Dna DNA(m_file_name);
////    return DNA;
////}
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

Dna ReadFile:: read()
{
    Dna DNA(m_file_name);
    return DNA;
}