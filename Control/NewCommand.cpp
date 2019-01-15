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

void NewCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1) {

    std::string name="";

    try
    {

        name=getName(parameters,name);

        if(name.compare("")==0)
            return;

        IDna *iDna = new Dna(parameters.front());
        MetaData *metaData1 = new MetaData(iDna, name);
        cliDataColection1.addIDna(metaData1);

        setMessage(metaData1);
    }
    catch (std::invalid_argument &e) {
        m_message=e.what();
    }
}


void NewCmd::setMessage(MetaData *metaData1)
{   std::stringstream message;
    message << "[" << metaData1->getId() << "] " << metaData1->getName() << ": " << metaData1->getSequnce();
    m_message = message.str();
}


std::string NewCmd::getName(std::list<std::string> parameters,std::string name)
{
    if (parameters.size() == 2)
        name = parameters.back().substr(1);
    else if (parameters.size() == 1)
        name = "seq" + std::to_string(++numNameSeqDna);
    else
        m_message = "too many args to new\n";

    return name;
}

std::string NewCmd::getmMessage()
{
    return m_message;
}
