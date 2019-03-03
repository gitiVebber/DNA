//
// Created by vebber on 12/27/18.
//
#include "../../Model/MetaData.h"
#include "NewCommand.h"
#include "../../Model/DNA.h"
#include "../CommandsFactory.h"
#include "../../Model/CLIDataColection.h"

#include <sstream>
#include <iostream>

#define CHAR_FOR_DEFALT_NAME "seq"
#define LITTEL_NUMBER_FOR_ARGS 1
#define MUCH_NUMBER_FOR_ARGS 2
#define NAME_COMMAND "new"



int NewCmd::NewCommand = CommandsFactory::registerCommand(NAME_COMMAND,new NewCmd);

int NewCmd::numNameSeqDna=0;

void NewCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1)
{

    std::string name = "";

    try {

        if (checkNumberArguments(parameters.size(), LITTEL_NUMBER_FOR_ARGS, MUCH_NUMBER_FOR_ARGS,NAME_COMMAND))
        {
            name = getName(parameters, name,MUCH_NUMBER_FOR_ARGS,LITTEL_NUMBER_FOR_ARGS,CHAR_FOR_DEFALT_NAME,numNameSeqDna,cliDataColection1);

            MetaData *metaData1;
            metaData1=CreationIdna(parameters.front(),name,metaData1,cliDataColection1);

            setMessage(metaData1);
        }
    }
    catch (std::invalid_argument &e)
    {
        m_message = e.what();
    }
}

