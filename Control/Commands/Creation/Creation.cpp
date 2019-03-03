//
// Created by vebber on 2/26/19.
//

#include "Creation.h"
#include "../../Model/DNA.h"
#include "../../Model/MetaData.h"


std::string Creation::getName(std::list<std::string> parameters,std::string name,int muchNumberArgs,int littelNumberArgs,
        char* charForDefultName,int numNameSeqDna,CLIDataColection& cliDataColection1) {

    if (parameters.size() == muchNumberArgs)
        name = checkName(parameters.back().substr(1), cliDataColection1);
    else if (parameters.size() == littelNumberArgs)
        name = charForDefultName + std::to_string(++numNameSeqDna);

    return name;
}

MetaData* Creation::CreationIdna(std::string seq,std::string name,MetaData *metaData1,CLIDataColection& cliDataColection1) {
    IDna *iDna = new Dna(seq);
    metaData1 = new MetaData(iDna, name);
    cliDataColection1.addIDna(metaData1);
    return metaData1;
}
