#pragma once
#include <exception>

class NoFileSpecifiedException : public std::exception{
    public:
        NoFileSpecifiedException();
        const char* what();
};