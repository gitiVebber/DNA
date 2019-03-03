//
// Created by vebber on 12/27/18.
//
#include "CommandsFactory.h"
//#include "Creation/NewCommand.h"
//#include "Creation/LoadCmdmand.h"



std::map<std::string,ICommand*>& CommandsFactory::getMap()
{
    static std::map<std::string,ICommand*> mapiCommand;
    return mapiCommand;
}

ICommand* CommandsFactory::getCommand(std::string command)
{
    std::map<std::string,ICommand*>::iterator it;
    it = getMap().find(command);

    if (it == getMap().end()) {
        return NULL;
    }
    return it->second;
}

int CommandsFactory::registerCommand(std::string nameCommand,ICommand* iCommand )
{
    std::cout<<nameCommand<<std::endl;
    std::pair<std::map<std::string,ICommand*>::iterator,bool> ret;
    ret = getMap().insert(std::pair<std::string,ICommand*>(nameCommand,iCommand));

    return ret.second?1:0;
}