//
// Created by vebber on 1/3/19.
//
#include <list>
#include <sstream>

#include "SaveCmd.h"
#include "../Model/WriteFileDna.h"
#include "CommandsFactory.h"


int SaveCmd::SaveCommand =CommandsFactory::registerCommand("save",new SaveCmd);

void SaveCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1)
{
    parameters.pop_front();
    try
    {

        Dna dna=new Dna(parameters.front());
        parameters.pop_front();

        WriteFile* writeFile=new WriteFile(parameters.front().c_str());
        parameters.pop_front();

        writeFile->write(dna);

        MetaData* metaData1=new MetaData(iDna,parameters.front());
        cliDataColection1.addIDna(metaData1);

        std::stringstream message;
        message << "[" << metaData1->getId() << "] " << metaData1->getName() << ": " << metaData1->getSequnce();
        m_message = message.str();
    }
    catch (std::invalid_argument &e)
    {
        std::cout<<e.what();
    }
}

std::string SaveCmd::getmMessage()
{
    return m_message;
}

