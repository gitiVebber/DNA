//
// Created by vebber on 1/15/19.
//
#include "string"
#include "Manipulation.h"
#include <sstream>


void Manipulation::setObjectFields(std::list<std::string> parameters,CLIDataColection& cliDataColection1,MetaData *oldMetaData1,IDna* iDna,char charForDefalt, int numNameSeqDna)
{
    if (parameters.size() == 1)
    {
        oldMetaData1->setSequnce(iDna);
        oldMetaData1->setStatus(MODIFIED);
        setMessage(oldMetaData1);
        return;
    }

    std::string name=" ";
    name=getName(parameters.back(), name, oldMetaData1, charForDefalt, numNameSeqDna++,cliDataColection1);
    MetaData* newMetaData = new MetaData(iDna, name);
    cliDataColection1.addIDna(newMetaData);
    setMessage(newMetaData);
}

std::string Manipulation::getName(std::string parameter,std::string name,MetaData *oldMetaData1,char charForDefalt ,int numNameSeqDna,CLIDataColection& cliDataColection1)
{
    if (parameter.compare(0, 2, "@@") == 0)
    {
        name = oldMetaData1->getName() + "_"+ charForDefalt + std::to_string(++numNameSeqDna);
    }

    else if (parameter.compare(0, 1, "@") == 0)
    {
        name = checkName(parameter.substr(1),cliDataColection1);
    } else
        m_message = "invalid argument for name";
    return name;
}
