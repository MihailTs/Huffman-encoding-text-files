#include "DecompressCommand.h"

DecompressCommand::DecompressCommand(HuffmanEncoder* _encoder){
    encoder = _encoder;
}

void DecompressCommand::execute(){
    encoder->decompress();
}