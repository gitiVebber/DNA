//
// Created by vebber on 1/3/19.
//

#ifndef PROJECTDNA_SAVECMD_H
#define PROJECTDNA_SAVECMD_H
#include <string>
#include <list>

#include "ICommand.h"
#include "../Model/MetaData.h"
#include "../Model/CLIDataColection.h"

class SaveCmd:public ICommand
{
public:
    //virtual string help()=0;
    virtual void run(std::list<std::string> parameters,CLIDataColection& cliDataColection1);
    virtual std::string getmMessage();
    void setMessage(MetaData *metaData1);


private:
    std::string getName(std::list<std::string> parameters,MetaData* oldMetaData1);

    static  int SaveCommand;
    std::string m_message;
};
#endif //PROJECTDNA_SAVECMD_H
