#include "DebugCommand.h"
#include <iostream>

DebugCommand::DebugCommand(HuffmanEncoder* _encoder){
    encoder = _encoder;
}

void DebugCommand::execute(){
    encoder->debugRegime();
    std::cout << std::endl;
}