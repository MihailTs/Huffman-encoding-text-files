#pragma once
#include <cstdlib>
#include "Command.h"
#include "HuffmanEncoder.h"

class InfoCommand : public Command{

    private:
        HuffmanEncoder* encoder;

    public:
        InfoCommand(HuffmanEncoder*);

        void execute();
};