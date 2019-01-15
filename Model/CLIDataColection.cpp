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
        allIDna<<it->second->getStatusSign() <<" ["<<it->second->getId()<<"] "<<it->second->getName()<<": "<<it->second->getSequnce()<<"\n";

    return allIDna.str();
}


MetaData* CLIDataColection::getById(size_t id)
{
    std::map<size_t, MetaData *>::iterator it;

    it = mapColectionById.find(id);
    if (it == mapColectionById.end())
        return NULL;
    return it->second;
}

MetaData* CLIDataColection::getByName(std::string name)
{
    std::map<std::string, MetaData *>::iterator it;

    it = mapColectionByName.find(name);
    if (it == mapColectionByName.end())
        return NULL;
    return it->second;
}

MetaData* CLIDataColection::get(std::string parameters)
{
    if (parameters.compare(0,1,"@")==0)
    {
        return getByName(parameters.substr(1));
    }
    if(parameters.compare(0,1,"#")==0)
    {
        std::stringstream numOfObject;
        numOfObject<<parameters.substr(1);
        size_t num;
        numOfObject>>num;
        return getById(num);
    }
    return NULL;
}