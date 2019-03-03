//
// Created by vebber on 1/13/19.
//

#include <sstream>
#include "SliceCmd.h"
#include "../../Model/Decorator/Slice.h"
#include "../CommandsFactory.h"
#define CHAR_FOR_DEFALT_NAME 's'
#define LITTEL_NUMBER_FOR_ARGS 3
#define MUCH_NUMBER_FOR_ARGS 5
#define NAME_COMMAND "slice"




int SliceCmd::SliceCommand =CommandsFactory::registerCommand(NAME_COMMAND,new SliceCmd);

int SliceCmd::numNameSeqDna=0;

void SliceCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1) {
    Slice *slice;
    MetaData  *oldMetaData1;
    size_t fromNum, toNum;

    try
    {
        if (checkNumberArguments(parameters.size(), LITTEL_NUMBER_FOR_ARGS, MUCH_NUMBER_FOR_ARGS, NAME_COMMAND)) {
            oldMetaData1 = cliDataColection1.get(parameters.front());
            if (oldMetaData1 == NULL)
                return;
            stringToSize_t(parameters, fromNum, toNum);

            if (CheckIntegrity(oldMetaData1->getIdna()->getLength(), fromNum, toNum)) {

                slice = new Slice(oldMetaData1->getIdna(), fromNum, toNum);
                setObjectFields(parameters,cliDataColection1, oldMetaData1,slice, CHAR_FOR_DEFALT_NAME, numNameSeqDna);
            }
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cout << e.what();
    }
}


bool SliceCmd::CheckIntegrity(size_t lenSeq,size_t from,size_t to) const
{
    return((to>=from)||(to-from>lenSeq));
}


void SliceCmd::stringToSize_t(std::list<std::string> &parameters,size_t &fromNum,size_t &toNum)
{
    parameters.pop_front();
    std::stringstream fromStr,toStr;
    fromStr<<parameters.front();
    parameters.pop_front();
    toStr<<parameters.front();
    fromStr>>fromNum;
    toStr>>toNum;
}