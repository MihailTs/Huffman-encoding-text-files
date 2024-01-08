#pragma once
#include "HuffmanEncoder.h"
#include "Command.h"

class CompressCommand : public Command{

    private:
        HuffmanEncoder* encoder;

    public:
        CompressCommand(HuffmanEncoder*);

        void execute();
};