#include "ExitCommand.h"
#include <iostream>

ExitCommand::ExitCommand(){}

void ExitCommand::execute(){
    std::cout << "Goodbye!\n";
    exit(0);
}