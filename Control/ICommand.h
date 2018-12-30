//
// Created by vebber on 12/27/18.
//

#ifndef PROJECTDNA_ICOMMAND_H
#define PROJECTDNA_ICOMMAND_H

#include <string.h>
#include "../Model/IDna.h"

#define INTERFACE struct


INTERFACE ICommand
{
    //virtual string help()=0;
    virtual void run(char** &parameters,IDna* iDna)=0;
};
#endif //PROJECTDNA_ICOMMAND_H
