//
// Created by vebber on 1/1/19.
//

#ifndef PROJECTDNA_LOADCMDMAND_H
#define PROJECTDNA_LOADCMDMAND_H
#include "ICommand.h"
#include "../Model/MetaData.h"
#include <list>

class LoadCmd:public ICommand
{
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters,CLIDataColection& cliDataColection1);
    virtual std::string getmMessage();

private:
    static  int LoadCommand;
    std::string m_message;

};

#endif //PROJECTDNA_LOADCMDMAND_H
