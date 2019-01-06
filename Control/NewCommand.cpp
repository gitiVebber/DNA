//
// Created by vebber on 12/27/18.
//
#include "../Model/MetaData.h"
#include "NewCommand.h"
#include "../Model/DNA.h"
#include "CommandsFactory.h"
#include "../Model/CLIDataColection.h"

#include <sstream>
#include <iostream>



int NewCmd::NewCommand = CommandsFactory::registerCommand("new",new NewCmd);

int NewCmd::numNameSeqDna=0;

void NewCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1)
{
    std::string name;
    try
    {
        parameters.pop_front();
        IDna* iDna=new Dna(parameters.front());

        if (parameters.size()==3)
            name = parameters.back().substr(1);
        else
            name = "seq" + std::to_string(++numNameSeqDna);



        MetaData* metaData1=new MetaData(iDna,name);
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


std::string NewCmd::getmMessage()
{
    return m_message;
}
