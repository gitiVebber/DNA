//
// Created by vebber on 1/5/19.
//

#ifndef PROJECTDNA_SHOWCMD_H
#define PROJECTDNA_SHOWCMD_H

#include <string>
#include <list>

#include "ICommand.h"
#include "../Model/MetaData.h"
#include "../Model/CLIDataColection.h"

class ShowCmd:public ICommand {
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters, CLIDataColection &cliDataColection1);

    virtual std::string getmMessage();

private:
    static int ShowCommand;
    std::string m_message;
};
#endif //PROJECTDNA_SHOWCMD_H
