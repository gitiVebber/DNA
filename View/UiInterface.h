//
// Created by vebber on 12/28/18.
//

#ifndef PROJECTDNA_UIINTERFACE_H
#define PROJECTDNA_UIINTERFACE_H

#define INTERFACE struct

INTERFACE UiInterface
{
    virtual void readFromUser()=0;
};

#endif //PROJECTDNA_UIINTERFACE_H
