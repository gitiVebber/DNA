//
// Created by vebber on 12/30/18.
//

#ifndef PROJECTDNA_CLIDATACOLECTION_H
#define PROJECTDNA_CLIDATACOLECTION_H

#include <map>
#include <cstring>
#include "MetaData.h"
class CLIDataColection
{
public:
    void addIDna(MetaData *metaData);
    std::string getAllIDna();

//    void deleteIDna(std::string name);
    MetaData* get(std::string name);



private:
    std::map<size_t ,MetaData*> mapColectionById;
    std::map<std::string,MetaData*> mapColectionByName;
};

#endif //PROJECTDNA_CLIDATACOLECTION_H
