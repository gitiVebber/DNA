//
// Created by vebber on 12/27/18.
//
#include "../Model/DNA.h"
#include "NewCommand.h"
#include <iostream>

void NewCmd::run(char** &parameters,IDna* iDna)
{
    try
    {
        iDna=new Dna(parameters[1]);
    }
    catch (std::invalid_argument &e)
    {
        std::cout<<e.what();
    }
}
