//
// Created by vebber on 12/30/18.
//

#ifndef PROJECTDNA_METADATA_H
#define PROJECTDNA_METADATA_H

#define LENGTH_TO_PRINT_SEQ 32


#include "../Helper/SharedPtr.h"
#include "IDna.h"
#include <map>

#define stringify( name ) # name

enum Status{NEW, UPTODATE, MODIFIED};




class MetaData
{
public:
    MetaData(IDna* sequnce,std::string name);

    void setId(size_t id);
    size_t getId();

    void setSequnce(IDna* iDna);
    std::string getSequnce(size_t length=LENGTH_TO_PRINT_SEQ);

    void setName(std::string name);
    std::string getName();

    void setStatus(Status status);
    const char* getStatus();
    const char* getStatusSign();

    SharedPtr<IDna> getIdna();

private:
    static size_t nextID;
    size_t m_id;
    SharedPtr<IDna> m_sequnce;
    std::string m_name;
    Status m_status;//enum

};

#endif //PROJECTDNA_METADATA_H



