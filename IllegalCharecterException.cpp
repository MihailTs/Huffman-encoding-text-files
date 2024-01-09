#include "IllegalCharecterException.h"
#include <cstring>
#include <string>

IllegalCharercterException::IllegalCharercterException(){}

const char* IllegalCharercterException::what(){
    std::string message("An illegal (non ASCII) charecter was passed."); 
    return message.c_str();
}