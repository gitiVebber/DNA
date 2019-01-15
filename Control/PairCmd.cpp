//
// Created by vebber on 1/8/19.
//

#include <sstream>
#include "PairCmd.h"
#include "../Model/Pair.h"
#include "CommandsFactory.h"




int PairCmd::PairCommand =CommandsFactory::registerCommand("pair",new PairCmd);

int PairCmd::numNameSeqDna=0;

void PairCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1) {
    Pair *pair;
    MetaData *newMetaData, *oldMetaData1;
    std::string name = "";
    try {
        if ((parameters.size() != 1) && (parameters.size() != 3))
        {
            m_message = "invalid number of args to function pair!!!!";
            return;
        }

        oldMetaData1 = cliDataColection1.get(parameters.front());
        if (oldMetaData1 == NULL)
            return;

        pair = new Pair(oldMetaData1->getIdna());

        if (parameters.size() == 1)
        {
            oldMetaData1->setSequnce(pair);
            oldMetaData1->setStatus(MODIFIED);
            setMessage(oldMetaData1);
            return;
        }

        name = getName(parameters, oldMetaData1, name);
        newMetaData = new MetaData(pair, name);
        cliDataColection1.addIDna(newMetaData);
        setMessage(newMetaData);
    }
    catch (std::invalid_argument &e)
    {
        std::cout << e.what();
    }
}

std::string PairCmd::getName(std::list<std::string> parameters,MetaData *oldMetaData1,std::string name)
{

    if (parameters.back().compare(0, 2, "@@") == 0)
    {
        name=oldMetaData1->getName() + "_p"+std::to_string(++numNameSeqDna);
    }
    else if (parameters.back().compare(0, 1, "@") == 0)
    {
        name= parameters.back().substr(1);
    }
    else
        m_message="invalid argument for name";

    return name;

}
void PairCmd::setMessage(MetaData *metaData)
{   std::stringstream message;
    message << "[" << metaData->getId() << "] " << metaData->getName() << ":" << metaData->getSequnce();
    m_message = message.str();
}

std::string PairCmd::getmMessage()
{
    return m_message;
}