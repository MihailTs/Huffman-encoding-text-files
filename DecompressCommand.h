#pragma once
#include "HuffmanEncoder.h"
#include "Command.h"

class DecompressCommand : public Command{

    private:
        HuffmanEncoder* encoder;

    public:
        DecompressCommand(HuffmanEncoder*);

        void execute();
};