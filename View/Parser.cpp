//
// Created by vebber on 12/26/18.
//
#include "Parser.h"
#include <algorithm>
#include <cstring>
#include <list>
#define  DELIMETER  " "


std::list<std::string> Parser::parse(char* cli)
{
    parseData.clear();

    char *word= strtok(cli, DELIMETER);

    int i;

    for (i=0 ;word ;++i)
    {
        parseData.push_back(word);
        word =strtok(NULL, DELIMETER);
    }
    return parseData;
}


std::list<std::string> Parser::getParseData()
{
    return parseData;
}
