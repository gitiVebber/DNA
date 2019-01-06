//
// Created by vebber on 12/27/18.
//
#include <string>

#include "Executable.h"
#include "CommandsFactory.h"
#include "ICommand.h"


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

        std::string  s=m_parser->getParseData().front();

        m_command = CommandsFactory::getCommand(s);

//m_parser->getParseData().pop_front();

        if(m_command)
        {
            m_command->run(m_parser->getParseData(),*m_cliDataColection);
            m_uiInterface->printMessage(m_command->getmMessage());
        }
    }
}