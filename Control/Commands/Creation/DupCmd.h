//
// Created by vebber on 1/15/19.
//

#ifndef PROJECTDNA_DUPCMD_H
#define PROJECTDNA_DUPCMD_H

#include "Creation.h"
#include "../../../Model/MetaData.h"
#include <list>

class DupCmd :public Creation {
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters, CLIDataColection &cliDataColection1);

private:
    static int DupCommand;
    static int numNameSeqDna;
};
#endif //PROJECTDNA_DUPCMD_H
