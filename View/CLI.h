//
// Created by vebber on 12/27/18.
//

#ifndef PROJECTDNA_CLI_H
#define PROJECTDNA_CLI_H

#include "Parser.h"
#include "UiInterface.h"

class CLI:public UiInterface
{
public:
    virtual void readFromUser();
    char m_command[255];////////

private:

    Parser parser;
};


#endif //PROJECTDNA_CLI_H
