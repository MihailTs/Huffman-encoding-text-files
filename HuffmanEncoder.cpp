#include "HuffmanEncoder.h"

HuffmanEncoder::HuffmanEncoder(){
    inputFile = "";
    outputFile = "";
}

HuffmanEncoder::HuffmanEncoder(std::string _inputFile){
    inputFile = _inputFile;
}

HuffmanEncoder::HuffmanEncoder(std::string _inputFile, std::string _outputFile){
    inputFile = _inputFile;
    outputFile = _outputFile;
}

void HuffmanEncoder::setInputFile(std::string _inputFile){
    inputFile = _inputFile;
}

void HuffmanEncoder::setOutputFile(std::string _outputFile){
    outputFile = _outputFile;
}

void HuffmanEncoder::findCountOccurrences(std::fstream reader, int* countOccurrences){
    std::string line;
    while(std::getline(firstReader, line)){
        std::cout << line << std::endl;
        for(int i = 0; i < line.size(); i++){
            countOccurrences[(int) line[i]]++;
        }
    }
}

void HuffmanEncoder::compress(){
    //What if no output file is given
    try {
        std::fstream firstReader(inputFile);

        int* countOccurrences = new int[HuffmanTree::ENCODING_TABLE_SIZE];
        for(int i = 0; i < HuffmanTree::ENCODING_TABLE_SIZE; i++){
            countOccurrences[i] = 0;
        }

        //
        //new line is not encoded        
        //

        findCountOfOccurrences(firstReader, countOccurrences);

        HuffmanTree hf(countOccurrences);
        std::vector<std::string> charEncodings = hf.getCharEncodings();

        delete [] countOccurrences;
        firstReader.close();

        //only for testing
        for(int i = 0; i < charEncodings.size(); i++){
            if(charEncodings.at(i) != ""){
                std::cout << "(" << (char) i << ", " << charEncodings.at(i) << ")" << std::endl;
            }
        }



        //rereading and writing to the file        
        
        std::fstream secondReader(inputFile);
        std::fstream writer(outputFile);

        std::string line;
        while(std::getline(firstReader, line)){
            std::cout << line << std::endl;
            for(int i = 0; i < line.size(); i++){
                secondReader << charEncodings.at((int) line[i]);
            }

            secondReader << std::endl;
        }        

        secondReader.close();
        writer.close();
    }

    catch (std::ifstream::failure e) {
        std::cout << "Exception reading/writing to file";
    }
}

