//
// Created by vebber on 12/27/18.
//

#ifndef PROJECTDNA_NEWCOMMAND_H
#define PROJECTDNA_NEWCOMMAND_H

#include "ICommand.h"
#include "../Model/MetaData.h"
#include <list>

class NewCmd:public ICommand
{
public:
    //virtual string help()=0;

    virtual void run(std::list<std::string> parameters,CLIDataColection& cliDataColection1);
    virtual std::string getmMessage();

private:
    std::string getName(std::list<std::string> parameters,std::string name);
    void setMessage(MetaData *metaData1);
    static int NewCommand;
    std::string m_message;
    static int numNameSeqDna;

};
#endif //PROJECTDNA_NEWCOMMAND_H
