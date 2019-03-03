//
// Created by vebber on 1/1/19.
//
#include "../../Model/MetaData.h"


#include <sstream>
#include <iostream>
#include "../../Model/Files/ReadFileDna.h"
#include "LoadCmdmand.h"
#include "../CommandsFactory.h"
#include "../../Model/CLIDataColection.h"

#define CHAR_FOR_DEFALT_NAME "seq"
#define LITTEL_NUMBER_FOR_ARGS 1
#define MUCH_NUMBER_FOR_ARGS 2
#define NAME_COMMAND "load"

int LoadCmd::LoadCommand=CommandsFactory::registerCommand(NAME_COMMAND,new LoadCmd);

int LoadCmd::numNameSeqDna=0;

void LoadCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1) {

    std::string name;

    try {

        if (checkNumberArguments(parameters.size(), LITTEL_NUMBER_FOR_ARGS, MUCH_NUMBER_FOR_ARGS, NAME_COMMAND)) {

            name = getName(parameters, name, MUCH_NUMBER_FOR_ARGS, LITTEL_NUMBER_FOR_ARGS, CHAR_FOR_DEFALT_NAME, numNameSeqDna, cliDataColection1);

            ReadFile *readFile = new ReadFile(parameters.front().c_str());

            MetaData *metaData1;
            metaData1 = CreationIdna(readFile->read(), name, metaData1, cliDataColection1);

            setMessage(metaData1);

        }
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
