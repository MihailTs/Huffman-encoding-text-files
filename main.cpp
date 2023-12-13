#include <iostream>
#include "CommandProcessing.h"
#include "HuffmanEncoder.h"

int main(){

    HuffmanEncoder encoder("testInputFile.txt", "testOutputFile.txt");
    
    std::string command;

    while(true){
        std::cout << "> ";
        std::getline(std::cin, command);

        command = strip(command);

        if(command == "c"){
            encoder.compress();
        } else if(command == "d"){
            encoder.decompress();
        } else if(command.substr(0, 2) == "i "){
            encoder.setInputFile(command.substr(2));
        } else if(command.substr(0, 2) == "o "){
            encoder.setOutputFile(command.substr(2));
        } else if(command == "debug"){
            encoder.debugRegime();
        } else if(command == "info"){
            std::cout << "The last compression had " << encoder.getCompressionDegree()
                            << " efficiency. (input bits / output bits ratio)" << std::endl;
        } else if(command == "exit"){
            std::cout << "Bye!";
            break;
        }

    }

    return 0;
}