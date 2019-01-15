//
// Created by vebber on 1/13/19.
//

#ifndef PROJECTDNA_SLICECMD_H
#define PROJECTDNA_SLICECMD_H

#include "ICommand.h"
#include "../Model/MetaData.h"
#include <list>

class SliceCmd:public ICommand {
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters, CLIDataColection &cliDataColection1);
    virtual std::string getmMessage();

private:
    //MetaData* getDnaToPair(std::string parameters,MetaData* metaData,CLIDataColection& cliDataColection1);
    std::string getName(std::list<std::string> parameters,MetaData *oldMetaData1,std::string name);
    bool CheckIntegrity(size_t lenSeq,size_t from,size_t to);
    void setMessage(MetaData *metaData);
    void stringToSize_t(std::list<std::string> &parameters,size_t &fromNum,size_t &toNum);


    static int SliceCommand;
    static int numNameSeqDna;
    std::string m_message;
};
#endif //PROJECTDNA_SLICECMD_H
