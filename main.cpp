#include <iostream>
#include "HuffmanEncoder.h"
#include "NoFileSpecifiedException.h"
#include "Invoker.h"

int main(){

    HuffmanEncoder* encoder = new HuffmanEncoder();
    Invoker invoker(encoder);

    std::cout << "Huffman encoding!\n";

    while(true){
        std::cout << "> ";

        std::string command;
        std::getline(std::cin, command);

        if(command == "") {continue;}

        //създаване и изпълнение на командата
        try{
            invoker.setCommand(command);
            if(invoker.getCommand() == nullptr) {
                std::cout << "Illegal command! Check the manual for the right syntax for your command." << std::endl;
            } else {
                invoker.getCommand()->execute();
            }
        } catch(std::exception& e){
            std::cout << e.what() << " Check the manual for the right syntax for your command." << std::endl;
        }
    }

    delete encoder;
    return 0;
}