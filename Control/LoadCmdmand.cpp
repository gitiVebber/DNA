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

void LoadCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1)
{

    std::string name;
    std::string tempName;
    int numNameSeqDna=0;
    bool nameAlreadyExists= true;

    try
    {
        if (parameters.size()==3)
            name = parameters.back().substr(1);
        else
            {
            name=parameters.back().substr(0,parameters.back().find('.'));
                tempName=name;
                while(nameAlreadyExists)
                {
                    if(cliDataColection1.get(tempName)!=NULL)
                        tempName=name+std::to_string(++numNameSeqDna);
                    else
                        nameAlreadyExists= false;
                }
                name=tempName;
        }
        parameters.pop_front();

        ReadFile* readFile=new ReadFile(parameters.front().c_str());
        parameters.pop_front();
        IDna* iDna=new Dna(readFile->read());

        MetaData *metaData1=new MetaData(iDna,name);
        parameters.clear();
        cliDataColection1.addIDna(metaData1);

        std::stringstream message;
        message << "[" << metaData1->getId() << "] " << metaData1->getName() << ": " << metaData1->getSequnce();
        m_message = message.str();
    }
    catch (std::invalid_argument &e)
    {
        std::cout<<e.what();
    }
}

std::string LoadCmd::getmMessage()
{
    return m_message;
}


