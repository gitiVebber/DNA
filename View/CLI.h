//
// Created by vebber on 12/27/18.
//

#ifndef PROJECTDNA_CLI_H
#define PROJECTDNA_CLI_H

#include <string>
#include "Parser.h"
#include "UiInterface.h"

class CLI:public UiInterface
{

public:
    CLI();
    virtual char* readFromUser();
    void printMessage(std::string m_message);

private:
    char m_command[256];
    std::string prompt ;
    Parser parser;
};


#endif //PROJECTDNA_CLI_H
