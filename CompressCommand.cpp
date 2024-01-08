#include "CompressCommand.h"
#include <iostream>

CompressCommand::CompressCommand(HuffmanEncoder* _encoder){
    encoder = _encoder;
}

void CompressCommand::execute(){
    encoder->compress();
}