//
// Created by vebber on 12/27/18.
//
#include <iostream>
#include <string.h>
#include "CLI.h"

void CLI::readFromUser()
{
    std::cout<<" --------In readCommand-----\n";
    if(fgets(m_command, sizeof(m_command), stdin) == NULL) return;

    if(m_command[strlen(m_command) -1] == '\n')
        m_command[strlen(m_command) -1] = '\0';
}

