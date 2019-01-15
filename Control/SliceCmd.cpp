//
// Created by vebber on 1/13/19.
//

#include <sstream>
#include "SliceCmd.h"
#include "../Model/Slice.h"
#include "CommandsFactory.h"




int SliceCmd::SliceCommand =CommandsFactory::registerCommand("slice",new SliceCmd);

int SliceCmd::numNameSeqDna=0;

void SliceCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1) {
   // Slice slice;
    MetaData *newMetaData, *oldMetaData1;
    size_t fromNum,toNum;
    std::string name = "";

    try {
        if ((parameters.size() != 3) && (parameters.size() != 5))
        {
            m_message = "invalid number of args to function pair!!!!";
            return;
        }

        oldMetaData1 = cliDataColection1.get(parameters.front());
        if (oldMetaData1 == NULL)
            return;

        stringToSize_t(parameters,fromNum,toNum);

        if(CheckIntegrity(oldMetaData1->getIdna()->getLength(),fromNum,toNum))
        {

            Slice *slice = new Slice(oldMetaData1->getIdna(),fromNum,toNum);

            if (parameters.size() == 1)
            {
                oldMetaData1->setSequnce(slice);
                oldMetaData1->setStatus(MODIFIED);
                setMessage(oldMetaData1);
                return;
            }

            name = getName(parameters, oldMetaData1, name);
            newMetaData = new MetaData(slice, name);
            cliDataColection1.addIDna(newMetaData);
            setMessage(newMetaData);
        }
        else {
            m_message = "not valid parameters for slice";
            return;
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cout << e.what();
    }
}

bool SliceCmd::CheckIntegrity(size_t lenSeq,size_t from,size_t to)
{
    return((to>=from)||(to-from>lenSeq));
}

std::string SliceCmd::getName(std::list<std::string> parameters,MetaData *oldMetaData1,std::string name)
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

void SliceCmd::setMessage(MetaData *metaData)
{   std::stringstream message;
    message << "[" << metaData->getId() << "] " << metaData->getName() << ":" << metaData->getSequnce();
    m_message = message.str();
}

std::string SliceCmd::getmMessage()
{
    return m_message;
}

void SliceCmd::stringToSize_t(std::list<std::string> &parameters,size_t &fromNum,size_t &toNum)
{
    parameters.pop_front();
    std::stringstream fromStr,toStr;
    fromStr<<parameters.front();
    parameters.pop_front();
    toStr<<parameters.front();
    fromStr>>fromNum;
    toStr>>toNum;
}