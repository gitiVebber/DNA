cmake_minimum_required(VERSION 3.12)
project(projectDNA)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectDNA main.cpp Model/Nucleotide.h Model/Nucleotide.cpp View/Parser.cpp View/Parser.h
        View/CLI.cpp View/CLI.h View/UiInterface.h Control/CommandsFactory.cpp  Control/CommandsFactory.h Control/Executable.cpp
        Control/Executable.h Control/ICommand.h Control/NewCommand.cpp Control/NewCommand.h Model/DNA.cpp Model/DNA.h Model/IDna.h
        Model/CLIDataColection.cpp Model/CLIDataColection.h Model/MetaData.cpp Model/MetaData.h Model/ReadFileDna.cpp Model/ReadFileDna.h
        Control/LoadCmdmand.h Control/LoadCmdmand.cpp Control/SaveCmd.h Control/SaveCmd.cpp Model/WriteFileDna.h Model/WriteFileDna.cpp)