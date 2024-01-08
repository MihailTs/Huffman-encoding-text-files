#pragma once
#include "HuffmanEncoder.h"
#include "Command.h"

class DebugCommand : public Command{

    private:
        HuffmanEncoder* encoder;

    public:
        DebugCommand(HuffmanEncoder*);

        void execute();
};