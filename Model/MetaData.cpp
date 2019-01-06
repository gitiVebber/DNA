//
// Created by vebber on 12/30/18.
//
#include "MetaData.h"

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

std::string MetaData::getSequnce()
{
    return m_sequnce->get();
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

//std::string get()
//{
//
//}




