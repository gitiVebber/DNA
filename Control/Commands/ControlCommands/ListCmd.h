//
// Created by vebber on 1/3/19.
//

#ifndef PROJECTDNA_LISTCMD_H
#define PROJECTDNA_LISTCMD_H
#include <string>
#include <list>

#include "../Command.h"
#include "../../../Model/MetaData.h"
#include "../../../Model/CLIDataColection.h"

class ListCmd:public Command
{
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters,CLIDataColection& cliDataColection1);

private:
    static  int ListCommand;
};

#endif //PROJECTDNA_LISTCMD_H
