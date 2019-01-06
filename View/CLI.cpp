//
// Created by vebber on 12/27/18.
//
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "CLI.h"
CLI::CLI()
{
    prompt="> cmd >>>";
}

char* CLI::readFromUser()
{
    std::cout<<prompt;

    if(fgets(m_command, sizeof(m_command), stdin) == NULL) return 0;

    if(m_command[strlen(m_command) -1] == '\n')
        m_command[strlen(m_command) -1] = '\0';
    return m_command;
}

void CLI::printMessage(std::string m_message)
{
    std::cout<<m_message<<std::endl;
}
