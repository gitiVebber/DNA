//
// Created by vebber on 1/8/19.
//

#ifndef PROJECTDNA_PAIRCMD_H
#define PROJECTDNA_PAIRCMD_H

#include "ICommand.h"
#include "../Model/MetaData.h"
#include <list>

class PairCmd:public ICommand {
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters, CLIDataColection &cliDataColection1);
    virtual std::string getmMessage();

private:
    //MetaData* getDnaToPair(std::string parameters,MetaData* metaData,CLIDataColection& cliDataColection1);
    std::string getName(std::list<std::string> parameters,MetaData *oldMetaData1,std::string name);
    void setMessage(MetaData *metaData);

    static int PairCommand;
    static int numNameSeqDna;
    std::string m_message;
};
#endif //PROJECTDNA_PAIRCMD_H
