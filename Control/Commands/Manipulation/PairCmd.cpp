//
// Created by vebber on 1/8/19.
//

#include <sstream>
#include "PairCmd.h"
#include "../../Model/Decorator/Pair.h"
#include "../CommandsFactory.h"
#define CHAR_FOR_DEFALT_NAME 'p'
#define LITTEL_NUMBER_FOR_ARGS 1
#define MUCH_NUMBER_FOR_ARGS 3
#define NAME_COMMAND "pair"




int PairCmd::PairCommand =CommandsFactory::registerCommand(NAME_COMMAND,new PairCmd);

int PairCmd::numNameSeqDna=0;

void PairCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1) {
    Pair *pair;
    MetaData  *oldMetaData1;
    std::string name = "";
    try {

        if (checkNumberArguments(parameters.size(), LITTEL_NUMBER_FOR_ARGS, MUCH_NUMBER_FOR_ARGS,NAME_COMMAND))
        {
            oldMetaData1 = cliDataColection1.get(parameters.front());
            if (oldMetaData1 == NULL)
                return;

            pair = new Pair(oldMetaData1->getIdna());

            setObjectFields(parameters,cliDataColection1, oldMetaData1,pair, CHAR_FOR_DEFALT_NAME, numNameSeqDna);
        }
    }
    catch (std::invalid_argument & e)
    {
        std::cout << e.what();
    }
}
