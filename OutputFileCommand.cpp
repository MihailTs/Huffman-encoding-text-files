#include "OutputFileCommand.h"

OutputFileCommand::OutputFileCommand(HuffmanEncoder* _encoder, const std::string& _location){
    encoder = _encoder;
    location = _location;
}

void OutputFileCommand::execute(){
    encoder->setOutputFile(location);
}