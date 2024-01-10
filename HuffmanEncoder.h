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

        //finds the count of occurrences of ASCII symbols in a file
        //throws IllegalCharecterException if the file contains non-ASCII symbols
        void findCountOfOccurrences(std::ifstream&, int*);
        
        //writes the compressed contents of one file to another
        //using an encodings vector
        void writeCompressedData(std::ifstream&, std::ofstream&, const std::vector<std::string>&);
        
        //prints the contents of a file in debug format
        void printDebugData(std::ifstream&, const std::vector<std::string>&);
        
        //prints a line from the input file in debug format
        void printDebugLine(const std::string&);
        
        int binaryStringToInt(const std::string&);
        
        //accepts a string representation of binary number and a number of digits
        //and returns a the binary number with the given number of digits
        //and zeroes at the end
        std::string fillBinary(std::string, int);

    public:

        //initializes files names to be empty
        HuffmanEncoder();
        
        //constructor only by input file
        HuffmanEncoder(std::string);
        
        //constuctor by input and output files
        HuffmanEncoder(std::string, std::string);

        void setInputFile(std::string);
        
        void setOutputFile(std::string);
        
        std::string getInputFile();
        
        std::string getOutputFile();

        double getCompressionDegree();
        
        //compresses the inupt file into the output file
        //throws NoFileSpecifiedException if the input or output files are not specified
        void compress();

        //compresses the inupt file into the output file
        //throws NoFileSpecifiedException if the input or output files are not specified
        void decompress();

        //prints the input file in debug format
        void debugRegime();
};