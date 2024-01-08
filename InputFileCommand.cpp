#include "InputFileCommand.h"

InputFileCommand::InputFileCommand(HuffmanEncoder* _encoder, const std::string& _location){
    encoder = _encoder;
    location = _location;
}

void InputFileCommand::execute(){
    encoder->setInputFile(location);
}