#pragma once
#include "Command.h"

class PrintHelpCommand : public Command{

    public:
        PrintHelpCommand();

        void execute();
};