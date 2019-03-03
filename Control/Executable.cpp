//
// Created by vebber on 12/27/18.
//
#include <string>
#include <list>

#include "Executable.h"
#include "CommandsFactory.h"
#include "Commands/ICommand.h"


Executable::Executable(UiInterface* Ui,CLIDataColection* cliDataColection)
{
    m_uiInterface=Ui;
    m_cliDataColection=cliDataColection;
    m_parser=new Parser;
}

void Executable::Execut()
{
    while (1)
    {
        m_parser->parse(m_uiInterface->readFromUser());
        if(m_parser->getParseData().back().compare("exit")==0)
            break;

        std::list<std::string>allParameters=m_parser->getParseData();
        std::string  s=allParameters.front();

        m_command = CommandsFactory::getCommand(s);

        if(m_command)
        {
            allParameters.pop_front();
            m_command->run(allParameters,*m_cliDataColection);
            m_uiInterface->printMessage(m_command->getmMessage());
        }
    }
}