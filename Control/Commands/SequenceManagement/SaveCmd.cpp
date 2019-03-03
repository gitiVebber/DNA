//
// Created by vebber on 1/3/19.
//
#include <list>
#include <sstream>

#include "SaveCmd.h"
#include "../../Model/Files/WriteFileDna.h"
#include "../CommandsFactory.h"
#include "../../Model/DNA.h"


int SaveCmd::SaveCommand =CommandsFactory::registerCommand("save",new SaveCmd);

void SaveCmd::run(std::list<std::string> parameters,CLIDataColection& cliDataColection1)
{
    std::string name = "";
    MetaData *oldMetaData1;

    if (parameters.size() != 2 && parameters.size() != 1)
    {
        m_message = "invalid number of args to function save!!!!";
        return;
    }
    try
    {
        oldMetaData1 = cliDataColection1.get(parameters.front());
        if (oldMetaData1 == NULL) {
            m_message="There is no such dna in the system";
            return;
        }

        name = getName(parameters, oldMetaData1);

        WriteFile *writeFile = new WriteFile(name);
        writeFile->write(oldMetaData1->getIdna());

        oldMetaData1->setStatus(UPTODATE);
    }
    catch (std::invalid_argument &e)
    {
        throw  std::invalid_argument(e.what());
    }
    catch (const char * err)
    {
        m_message=err;
    }
}


    std::string SaveCmd::getName(std::list<std::string> parameters,MetaData* oldMetaData1)
    {
        std::string name;

        if(parameters.size() == 1)
            name=oldMetaData1->getName()+".rawdna";
        else
            name=parameters.back().c_str();

        return name;
    }












//    try
//    {
//        WriteFile* writeFile=new WriteFile(parameters.front().c_str());
//        parameters.pop_front();
//
//        IDna* idna=new Dna(parameters.front());
//        writeFile->write(idna);
//
//        MetaData* metaData1=new MetaData(idna,parameters.front());
//
//        cliDataColection1.addIDna(metaData1);
//
//        setMessage(metaData1);
//    }
//    catch (std::invalid_argument &e)
//    {
//        std::cout<<e.what();
//    }
//}

//void SaveCmd::setMessage(MetaData *metaData1)
//{
//    std::stringstream message;
//    message << "[" << metaData1->getId() << "] " << metaData1->getName() << ": " << metaData1->getSequnce();
//    m_message = message.str();
//}
//
std::string SaveCmd::getmMessage()const
{
    return m_message;
}

