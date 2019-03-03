//
// Created by vebber on 1/8/19.
//

#ifndef PROJECTDNA_PAIRCMD_H
#define PROJECTDNA_PAIRCMD_H

#include "Manipulation.h"
#include "../../Model/MetaData.h"
#include <list>
#include "Manipulation.h"

class PairCmd:public Manipulation {
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters, CLIDataColection &cliDataColection1);


private:
//    //MetaData* getDnaToPair(std::string parameters,MetaData* metaData,CLIDataColection& cliDataColection1);
//    std::string getName(std::list<std::string> parameters,MetaData *oldMetaData1,std::string name);
//    void setMessage(MetaData *metaData);

    static int PairCommand;
    static int numNameSeqDna;
//    std::string m_message;
};
#endif //PROJECTDNA_PAIRCMD_H
