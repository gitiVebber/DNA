//
// Created by vebber on 1/15/19.
//

#include "../../../Model/MetaData.h"
#include "DupCmd.h"
#include "../../../Model/DNA.h"
#include "../../CommandsFactory.h"
#include "../../../Model/CLIDataColection.h"

#include <sstream>
#include <iostream>


#define CHAR_FOR_DEFALT_NAME "seq"
#define LITTEL_NUMBER_FOR_ARGS 1
#define MUCH_NUMBER_FOR_ARGS 2
#define NAME_COMMAND "dup"



int DupCmd::DupCommand = CommandsFactory::registerCommand(NAME_COMMAND,new DupCmd);

int DupCmd::numNameSeqDna=0;

void DupCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1) {

    std::string name="";

    try
    {
        if (checkNumberArguments(parameters.size(), LITTEL_NUMBER_FOR_ARGS, MUCH_NUMBER_FOR_ARGS,NAME_COMMAND))
        {
            MetaData *metaData = cliDataColection1.get(parameters.front());

            if(parameters.size()==1)
                parameters.push_back("@"+metaData->getName());

            name = getName(parameters,name,MUCH_NUMBER_FOR_ARGS,LITTEL_NUMBER_FOR_ARGS,CHAR_FOR_DEFALT_NAME,numNameSeqDna,cliDataColection1);

            MetaData *metaData1;
            metaData1=CreationIdna(metaData->getSequnce(),name,metaData1,cliDataColection1);

            setMessage(metaData1);
        }
    }
    catch (std::invalid_argument &e) {
        m_message=e.what();
    }
}

