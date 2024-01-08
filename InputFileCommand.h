#pragma once
#include "HuffmanEncoder.h"
#include "Command.h"
#include <string>

class InputFileCommand : public Command{

    private:
        HuffmanEncoder* encoder;
        std::string location;

    public:
        InputFileCommand(HuffmanEncoder*, const std::string&);

        void execute();
};