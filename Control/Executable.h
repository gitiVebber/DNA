//
// Created by vebber on 12/27/18.
//

#ifndef PROJECTDNA_EXECUTABLE_H
#define PROJECTDNA_EXECUTABLE_H
#include "../View/UiInterface.h"
#include "../Model/CLIDataColection.h"
#include "../View/Parser.h"
#include "../Control/CommandsFactory.h"

class Executable
{

public:
    Executable(UiInterface* Ui,CLIDataColection* cliDataColection);
    void Execut();

private:
    UiInterface* m_uiInterface;
    ICommand* m_command;
    Parser* m_parser;
    CLIDataColection* m_cliDataColection;

};

#endif //PROJECTDNA_EXECUTABLE_H
