#pragma once
#include "HuffmanEncoder.h"
#include "Command.h"
#include "InfoCommand.h"
#include "ExitCommand.h"
#include "CompressCommand.h"
#include "DecompressCommand.h"
#include "InputFileCommand.h"
#include "OutputFileCommand.h"
#include "DebugCommand.h"
#include "PrintHelpCommand.h"

class Invoker{

    private:
        HuffmanEncoder* encoder;

        Command* command;

    public:
        Invoker(const Invoker&);

        Invoker(HuffmanEncoder*);

        void setCommand(const std::string&);
        
        //Превръща текстовата команда в обект
        Command* factory(const std::string&);

        Command* getCommand();

        Invoker& operator=(const Invoker&);

        ~Invoker();
};