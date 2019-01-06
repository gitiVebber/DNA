//
// Created by vebber on 12/30/18.
//

#include "CLIDataColection.h"
#include "MetaData.h"
#include <map>
#include <sstream>
#include "string"

void CLIDataColection::addIDna(MetaData  *metaData)
{
    mapColectionById.insert(std::pair<size_t ,MetaData*>(metaData->getId(),metaData));
    mapColectionByName.insert(std::pair<std::string ,MetaData*>(metaData->getName(),metaData));
}

std::string CLIDataColection::getAllIDna()
{
    std::stringstream allIDna;
    int i=mapColectionById.size();

    for(std::map<size_t ,MetaData*>::iterator it =mapColectionById.begin();it!=mapColectionById.end();++it)
        allIDna <<"["<<it->second->getId()<<"] "<<it->second->getName()<<": "<<it->second->getSequnce()<<"\n";

    return allIDna.str();
}

MetaData* CLIDataColection::get(std::string name)
{
    std::map<std::string,MetaData*>::iterator it;

    it = mapColectionByName.find(name);
    if (it == mapColectionByName.end())
        return NULL;
    return it->second;
}