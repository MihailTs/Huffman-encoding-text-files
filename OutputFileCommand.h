#pragma once
#include "HuffmanEncoder.h"
#include "Command.h"
#include <string>

class OutputFileCommand : public Command{

    private:
        HuffmanEncoder* encoder;
        std::string location;

    public:
        OutputFileCommand(HuffmanEncoder*, const std::string&);

        void execute();
};