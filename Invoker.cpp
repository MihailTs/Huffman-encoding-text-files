#include "Invoker.h"
#include <string>

Invoker::Invoker(HuffmanEncoder* _encoder){
    encoder = _encoder;
    command = nullptr;
}

Invoker::Invoker(const Invoker& _other){
    encoder = _other.encoder;
    command = _other.command;
}

void Invoker::setCommand(const std::string& strCommand){
    if(command != nullptr){
        delete command;
    }

    command = factory(strCommand);
}

Command* Invoker::factory(const std::string& strCommand){
    Command* command;

    if(strCommand == "exit"){
        command = new ExitCommand;
    } else if(strCommand == "c"){
        command = new CompressCommand(encoder);
    } else if(strCommand == "d"){
        command = new DecompressCommand(encoder);
    } else if(strCommand.substr(0, 2) == "i "){
        command = new InputFileCommand(encoder, strCommand.substr(2));
    } else if(strCommand.substr(0, 2) == "o "){
        command = new OutputFileCommand(encoder, strCommand.substr(2));
    } else if(strCommand == "debug"){
        command = new DebugCommand(encoder);
    } else if(strCommand == "info"){
        command = new InfoCommand(encoder);
    } else {
        command = nullptr;
    }

    return command;
}

Command* Invoker::getCommand(){
    return command;
}

Invoker& Invoker::operator=(const Invoker& _other){
    if(this == &_other){
        return *this;
    }

    delete getCommand();
    command = _other.command;
    encoder = _other.encoder;
    return *this;
}

Invoker::~Invoker(){
    delete getCommand();
}