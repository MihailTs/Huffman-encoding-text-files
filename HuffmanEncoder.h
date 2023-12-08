#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <exception>
#include "HuffmanTree.h"

class HuffmanEncoder{

    private:
        std::string inputFile;
        std::string outputFile;

        void findCountOccurrences(std::fstream, int*);
    
    public:

        HuffmanEncoder();
        HuffmanEncoder(std::string);
        HuffmanEncoder(std::string, std::string);

        void setInputFile(std::string);
        void setOutputFile(std::string);
        void compress();
        void decompress();

};