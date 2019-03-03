//
// Created by vebber on 2/26/19.
//


#ifndef PROJECTDNA_COMMAND_H
#define PROJECTDNA_COMMAND_H
#include "ICommand.h"
class Command:public ICommand {
public:
    std::string getmMessage() const;

    void setMessage(MetaData *metaData);

    std::string checkName(std::string name, CLIDataColection &cliDataColection1);

    bool checkNumberArguments(int parameters,int littelNumberForArgs,int muchNumberForArgs,std::string nameCommand);

protected:
    std::string m_message;
};

#endif //PROJECTDNA_COMMAND_H
