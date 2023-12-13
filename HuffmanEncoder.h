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
        int inputBitSize;
        int outputBitSize;

        void findCountOfOccurrences(std::ifstream&, int*);
        void writeCompressedData(std::ifstream&, std::ofstream&, const std::vector<std::string>&);
        void printDebugData(std::ifstream&, const std::vector<std::string>&);
        void printDebugLine(const std::string&);
        int binaryStringToInt(const std::string&);
        std::string fillBinary(std::string, int);

    public:

        HuffmanEncoder();
        HuffmanEncoder(std::string);
        HuffmanEncoder(std::string, std::string);

        void setInputFile(std::string);
        void setOutputFile(std::string);
        double getCompressionDegree();
        void compress();
        void decompress();
        void debugRegime();
};