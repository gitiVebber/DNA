//
// Created by vebber on 1/3/19.
//

#ifndef PROJECTDNA_LISTCMD_H
#define PROJECTDNA_LISTCMD_H
#include <string>
#include <list>

#include "ICommand.h"
#include "../Model/MetaData.h"
#include "../Model/CLIDataColection.h"

class ListCmd:public ICommand
{
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters,CLIDataColection& cliDataColection1);
    virtual std::string getmMessage();

private:
    static  int ListCommand;
    std::string m_message;
};

#endif //PROJECTDNA_LISTCMD_H
