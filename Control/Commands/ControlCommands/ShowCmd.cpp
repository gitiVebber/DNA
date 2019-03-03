//
// Created by vebber on 1/5/19.
//
#include <sstream>
#include "ShowCmd.h"
#include "../../../Model/Files/WriteFileDna.h"
#include "../../CommandsFactory.h"

#define LITTEL_NUMBER_FOR_ARGS 1
#define MUCH_NUMBER_FOR_ARGS 2
#define NAME_COMMAND "show"

int ShowCmd::ShowCommand =CommandsFactory::registerCommand(NAME_COMMAND,new ShowCmd);

void ShowCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1)
{
    MetaData *metaData;
    try
    {
        if (checkNumberArguments(parameters.size(), LITTEL_NUMBER_FOR_ARGS, MUCH_NUMBER_FOR_ARGS, NAME_COMMAND))
            metaData = cliDataColection1.get(parameters.back());
        if (metaData)
            setMessage(metaData);
        else
            m_message = "not find this sequences";
    }
    catch (std::invalid_argument &e)
    {
        std::cout << e.what();
    }
}
