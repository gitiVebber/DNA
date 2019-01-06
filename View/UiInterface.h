//
// Created by vebber on 12/28/18.
//

#ifndef PROJECTDNA_UIINTERFACE_H
#define PROJECTDNA_UIINTERFACE_H

#include <string>
#define INTERFACE struct

INTERFACE UiInterface
{
    virtual char* readFromUser()=0;
    virtual void printMessage(std::string)=0;
};

#endif //PROJECTDNA_UIINTERFACE_H
