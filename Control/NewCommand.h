//
// Created by vebber on 12/27/18.
//

#ifndef PROJECTDNA_NEWCOMMAND_H
#define PROJECTDNA_NEWCOMMAND_H

#include "ICommand.h"
class NewCmd:public ICommand
{
public:
    NewCmd(){};//////
    //virtual string help()=0;
    virtual void run(char** &parameters,IDna* iDna);
};
#endif //PROJECTDNA_NEWCOMMAND_H
