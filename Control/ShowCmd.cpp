//
// Created by vebber on 1/5/19.
//
#include <sstream>
#include "ShowCmd.h"
#include "../Model/WriteFileDna.h"
#include "CommandsFactory.h"



int ShowCmd::ShowCommand =CommandsFactory::registerCommand("show",new ShowCmd);

void ShowCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1)
{
    MetaData *metaData;
    try {

        if ((parameters.back().compare(0, 1, "@") != 0 && (parameters.back().compare(0, 1, "#") != 0)))
        {
            m_message = "invalid character to function show!!!!";
            return;
        }

        metaData = cliDataColection1.get(parameters.back());
        if(metaData)
            setMessage(metaData);
        else
            m_message="not find this sequences";
    }
    catch (std::invalid_argument &e)
    {
        std::cout << e.what();
    }
}

void ShowCmd::setMessage(MetaData *metaData)
{
    std::stringstream message;
    message << "[" << metaData->getId() << "] " << metaData->getName() << " " <<metaData->getStatus()<<"\n"<< metaData->getSequnce();
    m_message = message.str();
}

std::string ShowCmd::getmMessage()
{
    return m_message;
}