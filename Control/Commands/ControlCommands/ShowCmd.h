//
// Created by vebber on 1/5/19.
//

#ifndef PROJECTDNA_SHOWCMD_H
#define PROJECTDNA_SHOWCMD_H

#include <string>
#include <list>

#include "../Command.h"
#include "../../Model/MetaData.h"
#include "../../Model/CLIDataColection.h"

class ShowCmd:public Command{
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters, CLIDataColection &cliDataColection1);

private:
    static int ShowCommand;

};
#endif //PROJECTDNA_SHOWCMD_H
