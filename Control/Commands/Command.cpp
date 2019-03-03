//
// Created by vebber on 2/26/19.
//
#include "Command.h"
#include <sstream>
#include <string>

void Command::setMessage(MetaData *metaData)
{   std::stringstream message;
    message << "[" << metaData->getId() << "] " << metaData->getName() << ":" << metaData->getSequnce();
    m_message = message.str();
}

std::string Command::checkName(std::string name,CLIDataColection& cliDataColection1)
{
    bool nameAlreadyExists=true;
    std::string tempName=name;
    int numNameSeqDna = 0;

    while (nameAlreadyExists)
    {
        if (cliDataColection1.get("@"+tempName) != NULL)
            tempName = name + std::to_string(++numNameSeqDna);
        else
            nameAlreadyExists = false;
    }
    return tempName;

}

bool Command::checkNumberArguments(int parameters,int littelNumberForArgs,int muchNumberForArgs,std::string nameCommand)
{
    if ((parameters != littelNumberForArgs) && (parameters != muchNumberForArgs))
    {
        m_message = "invalid number of args to function "+nameCommand;
        return false;
    }
    return true;
}

std::string Command::getmMessage()const
{
    return m_message;
}