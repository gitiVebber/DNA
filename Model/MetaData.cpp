//
// Created by vebber on 12/30/18.
//
#include "MetaData.h"
#include <sstream>

size_t MetaData::nextID=1;
MetaData::MetaData(IDna* sequnce,std::string name):m_id(nextID++),m_sequnce(sequnce),m_name(name),m_status(NEW)
{}

void MetaData::setId(size_t id)
{
    m_id=id;
}

size_t MetaData::getId()
{
    return m_id;
}

void MetaData::setSequnce(IDna* iDna)
{
    m_sequnce=iDna;
}

std::string MetaData::getSequnce(size_t length)
{
    std::stringstream dnaString;
    size_t i;
    if(m_sequnce->getLength()<length)
    {
        for (i = 0; i < m_sequnce->getLength(); i++)
            dnaString << m_sequnce->operator[](i);
    }
    else
    {
        for ( i = 0; i < length; i++)
            dnaString << m_sequnce->operator[](i);
        dnaString<<"..."<< m_sequnce->operator[](i+1)<<m_sequnce->operator[](i+2)<<m_sequnce->operator[](i+3);
    }
    return dnaString.str();
}

void MetaData::setName(std::string name)
{
    m_name=name;
}

std::string MetaData::getName()
{
    return m_name;
}

void MetaData::setStatus(Status status)
{
    m_status=status;
}

const char* MetaData::getStatus()
{

    static const char* StatusValueNames[] =
            {
                    stringify( NEW ),
                    stringify( UPTODATE ),
                    stringify( MODIFIED )
            };


    return StatusValueNames[ m_status ] ;
}

const char* MetaData::getStatusSign()
{

    static const char* StatusValueNames[] =
            {
                    stringify( o ),
                    stringify( - ),
                    stringify( * )
            };


    return StatusValueNames[ m_status ] ;
}



SharedPtr<IDna> MetaData::getIdna()
{
    return m_sequnce;
}



