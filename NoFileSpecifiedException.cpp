#include "NoFileSpecifiedException.h"
#include <cstring>
#include <string>

NoFileSpecifiedException::NoFileSpecifiedException(){}

const char* NoFileSpecifiedException::what(){
    std::string message("No input/output file was specified"); 
    return message.c_str();
}