//
// Created by vebber on 1/1/19.
//

#ifndef PROJECTDNA_LOADCMDMAND_H
#define PROJECTDNA_LOADCMDMAND_H
#include "Creation.h"
#include "../../../Model/MetaData.h"
#include <list>

class LoadCmd:public Creation
{
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters,CLIDataColection& cliDataColection1);

private:
    static  int LoadCommand;
    static int numNameSeqDna;

};

#endif //PROJECTDNA_LOADCMDMAND_H
