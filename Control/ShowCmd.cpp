//
// Created by vebber on 1/5/19.
//
#include <sstream>
#include "ShowCmd.h"
#include "../Model/WriteFileDna.h"
#include "CommandsFactory.h"



int ShowCmd::ShowCommand =CommandsFactory::registerCommand("show",new ShowCmd);

void ShowCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1)
{

    try
    {
        MetaData* metaData=cliDataColection1.get(parameters.back());
        std::stringstream message;
        message << "[" << metaData->getId() << "] " << metaData->getName() << " " <<metaData->getStatus()<<"\n"<< metaData->getSequnce();
        m_message = message.str();
    }
    catch (std::invalid_argument &e)
    {
        std::cout<<e.what();
    }
}

std::string ShowCmd::getmMessage()
{
    return m_message;
}