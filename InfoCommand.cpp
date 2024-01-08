#include "InfoCommand.h"
#include <iostream>

InfoCommand::InfoCommand(HuffmanEncoder* _encoder){
    encoder = _encoder;
}

void InfoCommand::execute(){
    std::cout << encoder->getCompressionDegree()
                        << " efficiency. (input bits / output bits ratio)" << std::endl;
}