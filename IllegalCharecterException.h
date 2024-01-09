#pragma once
#include <exception>

class IllegalCharercterException : public std::exception{
    public:
        IllegalCharercterException();
        const char* what();
};