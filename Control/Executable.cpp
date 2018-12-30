//
// Created by vebber on 12/27/18.
//
#include <string>
#include "Executable.h"
#include "CommandsFactory.h"
#include "ICommand.h"


Executable::Executable(char** ParseData,IDna *iDna)
{
    CommandsFactory* commandsFactory = new CommandsFactory();

    ICommand* command = commandsFactory->getCommand(ParseData[0]);

    command->run(ParseData,iDna);
}