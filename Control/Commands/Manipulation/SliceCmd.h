//
// Created by vebber on 1/13/19.
//

#ifndef PROJECTDNA_SLICECMD_H
#define PROJECTDNA_SLICECMD_H

#include "Manipulation.h"
#include "../../../Model/MetaData.h"
#include <list>

class SliceCmd:public Manipulation {
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters, CLIDataColection &cliDataColection1);

private:
    bool CheckIntegrity(size_t lenSeq,size_t from,size_t to) const ;
    void stringToSize_t(std::list<std::string> &parameters,size_t &fromNum,size_t &toNum);

    static int SliceCommand;
    static int numNameSeqDna;
};
#endif //PROJECTDNA_SLICECMD_H
