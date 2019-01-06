//
// Created by vebber on 12/27/18.
//

#ifndef PROJECTDNA_COMMANDSFACTORY_H
#define PROJECTDNA_COMMANDSFACTORY_H
#include <map>
#include <string>
#include "ICommand.h"


class  CommandsFactory {

public:
    static std::map<std::string,ICommand*>&  getMap ();
    static ICommand* getCommand(std::string command);
    static int registerCommand(std::string nameCommad,ICommand* iCommand);


};
#endif //PROJECTDNA_COMMANDSFACTORY_H
