//
// Created by vebber on 12/27/18.
//
#include "CommandsFactory.h"
#include "NewCommand.h"

ICommand* CommandsFactory::getCommand(char* command)
{
    if (command == NULL)
        return NULL;
    if ((strcmp(command, "new")==0)||(strcmp(command,"New")==0))
        return new NewCmd();
    return NULL;
}
