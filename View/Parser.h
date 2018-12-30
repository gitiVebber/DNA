//
// Created by vebber on 12/26/18.
//

#ifndef PROJECTDNA_PARSER_H
#define PROJECTDNA_PARSER_H

#include <string.h>

class Parser
{
public:
    char** parse (char* line);
    char** getParseData();

private:
    char *parseData[5];
};
#endif //PROJECTDNA_PARSER_H
