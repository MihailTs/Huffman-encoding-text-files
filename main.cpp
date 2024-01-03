#include <iostream>
#include "CommandProcessing.h"
#include "HuffmanEncoder.h"
#include "NoFileSpecifiedException.h"

int main(){

    HuffmanEncoder encoder;
    
    std::string command;

    while(true){
        std::cout << "> ";
        std::getline(std::cin, command);

        command = strip(command);

        if(command == "c"){
            try{
                encoder.compress();
            } catch(NoFileSpecifiedException e){
                std::cout << e.what() << std::endl;
            }
        } else if(command == "d"){
            try{
                encoder.decompress();
            } catch(NoFileSpecifiedException e){
                std::cout << e.what() << std::endl;
            }
        } else if(command.substr(0, 2) == "i "){
            encoder.setInputFile(command.substr(2));
        } else if(command.substr(0, 2) == "o "){
            encoder.setOutputFile(command.substr(2));
        } else if(command == "debug"){
            encoder.debugRegime();
            std::cout << std::endl;
        } else if(command == "info"){
            std::cout << "The last compression had " << encoder.getCompressionDegree()
                            << " efficiency. (input bits / output bits ratio)" << std::endl;
        } else if(command == "exit"){
            std::cout << "Bye!";
            break;
        } else {
            std::cout << "Illegal command!" << std::endl;
        }


    }

    return 0;
}