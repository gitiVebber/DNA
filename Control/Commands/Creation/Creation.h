//
// Created by vebber on 2/26/19.
//

#ifndef PROJECTDNA_CREATION_H
#define PROJECTDNA_CREATION_H
#include "../Command.h"

class Creation:public Command {
protected:
    std::string getName(std::list<std::string> parameters, std::string name, int muchNumberArgs, int littelNumberArgs,
                        char *charForDefultName, int numNameSeqDna, CLIDataColection &cliDataColection1);
    MetaData* CreationIdna(std::string seq,std::string name,MetaData *metaData1,CLIDataColection& cliDataColection1);

};
#endif //PROJECTDNA_CREATION_H
