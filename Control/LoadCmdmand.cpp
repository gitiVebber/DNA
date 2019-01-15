//
// Created by vebber on 1/1/19.
//
#include "../Model/MetaData.h"


#include <sstream>
#include <iostream>
#include "../Model/ReadFileDna.h"
#include "LoadCmdmand.h"
#include "CommandsFactory.h"
#include "../Model/CLIDataColection.h"

int LoadCmd::LoadCommand=CommandsFactory::registerCommand("load",new LoadCmd);

void LoadCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1) {

    std::string name;

    try {
        name=getName(parameters, cliDataColection1);

        ReadFile *readFile = new ReadFile(parameters.front().c_str());
        IDna *iDna = new Dna(readFile->read());

        MetaData *metaData1 = new MetaData(iDna, name);
        cliDataColection1.addIDna(metaData1);

        setMessage(metaData1);

    }
    catch (std::invalid_argument &e)
    {
        m_message= e.what();
    }
    catch (const char* err)
    {
        m_message=err;
    }
}

void LoadCmd::setMessage(MetaData *metaData1)
{
    std::stringstream message;
    message << "[" << metaData1->getId() << "] " << metaData1->getName() << ": " << metaData1->getSequnce();
    m_message = message.str();
}

std::string LoadCmd::getmMessage()
{
    return m_message;
}


std::string LoadCmd::getName(std::list<std::string> parameters,CLIDataColection& cliDataColection1)
{
    std::string name,tempName;
    bool nameAlreadyExists= true;
    int numNameSeqDna = 0;

    if (parameters.size() == 2)
        name = parameters.back().substr(1);

    else {
        name = parameters.back().substr(0, parameters.back().find('.'));
        tempName = name;
        while (nameAlreadyExists)
        {
            if (cliDataColection1.get("@"+tempName) != NULL)
                tempName = name + std::to_string(++numNameSeqDna);
            else
                nameAlreadyExists = false;
        }
        name = tempName;
    }
    return name;
}

