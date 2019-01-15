cmake_minimum_required(VERSION 3.12)
project(projectDNA)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectDNA main.cpp Model/Nucleotide.cpp View/Parser.cpp
        View/CLI.cpp Control/CommandsFactory.cpp   Control/Executable.cpp Control/NewCommand.cpp Model/DNA.cpp
        Model/CLIDataColection.cpp  Model/MetaData.cpp  Model/ReadFileDna.cpp Control/PairCmd.cpp Control/SaveCmd.cpp
        Model/WriteFileDna.cpp Model/Slice.cpp Control/SliceCmd.cpp)