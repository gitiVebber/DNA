//
// Created by vebber on 12/26/18.
//

#ifndef PROJECTDNA_PARSER_H
#define PROJECTDNA_PARSER_H

#include <string>
#include <list>


class Parser
{
public:

    std::list<std::string> parse (char* line);
    std::list<std::string> getParseData();


private:
    //char *parseData[30];
    std::list<std::string>parseData;


};
#endif //PROJECTDNA_PARSER_H
