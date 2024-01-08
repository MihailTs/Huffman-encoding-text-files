#include "PrintHelpCommand.h"
#include <iostream>

PrintHelpCommand::PrintHelpCommand(){}

void PrintHelpCommand::execute(){
    std::cout << "Manual: " << std::endl <<
        "-c[ompress] - parameter, indicatind that the program is going to be working in compression regime;" << std::endl <<
        "-d[ecompress] - parameter, indicatind that the program is going to be working in decompression regime;" << std::endl <<
        "-i <filename> - parameter indicating the name of the input file (being compressed or decompressed);" << std::endl <<
        "-o <filename> - parameter indicating the name of the output file;" << std::endl <<
        "-info - command, showing the efficiency of the last compression executed on the input and output files;" << std::endl <<
        "-debug - command, showing a series of 8-bit numbers representing the last-compressed information grouped;" << std::endl;
}