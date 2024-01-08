#pragma once
#include <cstdlib>
#include "Command.h"

class ExitCommand : public Command{

    private:

    public:
        ExitCommand();

        void execute();

};