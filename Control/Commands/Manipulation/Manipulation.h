//
// Created by vebber on 1/15/19.
//

#ifndef PROJECTDNA_MANIPULATION_H
#define PROJECTDNA_MANIPULATION_H

#include "../Command.h"
class Manipulation:public Command {

protected:
    std::string getName(std::string parameter, std::string name, MetaData *oldMetaData1, char charForDefalt, int numNameSeqDna,
            CLIDataColection &cliDataColection1);

    void setObjectFields(std::list<std::string> parameters, CLIDataColection &cliDataColection1, MetaData *oldMetaData1,
                         IDna *iDna, char charForDefalt, int numNameSeqDna);
};

#endif //PROJECTDNA_MANIPULATION_H
