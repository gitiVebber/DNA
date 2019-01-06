//
// Created by vebber on 12/27/18.
//

#ifndef PROJECTDNA_ICOMMAND_H
#define PROJECTDNA_ICOMMAND_H

#include <string.h>
#include "../Model/IDna.h"
#include "../Model/CLIDataColection.h"
#include <list>
#define INTERFACE struct


INTERFACE ICommand
{
public:
    virtual void run(std::list<std::string> parameters,CLIDataColection& cliDataColection1)=0;
    //virtual string help()=0
    virtual std::string getmMessage()=0;

    CLIDataColection cliDataColection;
};
#endif //PROJECTDNA_ICOMMAND_H
