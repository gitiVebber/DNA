//
// Created by vebber on 1/3/19.
//
#include "ListCmd.h"
#include "../../../Model/Files/WriteFileDna.h"
#include "../../CommandsFactory.h"

#define LITTEL_NUMBER_FOR_ARGS 0
#define MUCH_NUMBER_FOR_ARGS 0
#define NAME_COMMAND "list"

int ListCmd::ListCommand =CommandsFactory::registerCommand(NAME_COMMAND,new ListCmd);

void ListCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1)
{

    try
    {
        if (checkNumberArguments(parameters.size(), LITTEL_NUMBER_FOR_ARGS, MUCH_NUMBER_FOR_ARGS, NAME_COMMAND))
            m_message = cliDataColection1.getAllIDna();
    }
    catch (std::invalid_argument &e)
    {
        std::cout << e.what();
    }
}




