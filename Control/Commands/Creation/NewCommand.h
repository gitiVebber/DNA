//
// Created by vebber on 12/27/18.
//

#ifndef PROJECTDNA_NEWCOMMAND_H
#define PROJECTDNA_NEWCOMMAND_H

#include "Creation.h"
#include "../../../Model/MetaData.h"
#include <list>

class NewCmd:public Creation
{
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters,CLIDataColection& cliDataColection1);

private:
    static int NewCommand;
    static int numNameSeqDna;

};
#endif //PROJECTDNA_NEWCOMMAND_H
