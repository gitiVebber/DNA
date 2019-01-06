//
// Created by vebber on 1/3/19.
//
#include "ListCmd.h"
#include "../Model/WriteFileDna.h"
#include "CommandsFactory.h"



int ListCmd::ListCommand =CommandsFactory::registerCommand("list",new ListCmd);

void ListCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1)
{

    try
    {
        m_message=cliDataColection1.getAllIDna();
    }
    catch (std::invalid_argument &e)
    {
        std::cout<<e.what();
    }
}

std::string ListCmd::getmMessage()
{
    return m_message;
}


