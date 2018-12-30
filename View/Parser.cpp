//
// Created by vebber on 12/26/18.
//
#include "Parser.h"
#include <vector>
#include <algorithm>
#include <string.h>

char** Parser::parse(char* line)
{
    char * currentPars;
    int i=0;

    currentPars= strtok (line," ");
    while (currentPars != NULL)
    {
        parseData[i]=new char[255];
        strcpy(parseData[i++],currentPars);
        currentPars= strtok (NULL," ");
    }
    return parseData;
}


char** Parser::getParseData()
{
    return parseData;
}
