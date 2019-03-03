cmake_minimum_required(VERSION 3.12)
project(projectDNA)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectDNA main.cpp Model/Nucleotide.cpp View/Parser.cpp
        View/CLI.cpp Control/CommandsFactory.cpp   Control/Executable.cpp Control/Commands/Creation/NewCommand.cpp Control/Commands/ControlCommands/ListCmd.cpp Control/Commands/Creation/LoadCmdmand.cpp Control/Commands/Creation/DupCmd.cpp Model/DNA.cpp
        Model/CLIDataColection.cpp  Model/MetaData.cpp Model/Files/ReadFileDna.cpp Control/Commands/Manipulation/PairCmd.cpp Control/Commands/SequenceManagement/SaveCmd.cpp
        Model/Files/WriteFileDna.cpp Model/Decorator/Slice.cpp Control/Commands/Manipulation/SliceCmd.cpp Control/Commands/Manipulation/Manipulation.cpp Control/Commands/Command.cpp
        Control/Commands/Creation/Creation.cpp Control/Commands/ControlCommands/ShowCmd.cpp)