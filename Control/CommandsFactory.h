//
// Created by vebber on 12/27/18.
//

#ifndef PROJECTDNA_COMMANDSFACTORY_H
#define PROJECTDNA_COMMANDSFACTORY_H

#include <string.h>
#include "ICommand.h"

class  CommandsFactory {

public:
    ICommand* getCommand(char* command);
};
#endif //PROJECTDNA_COMMANDSFACTORY_H
