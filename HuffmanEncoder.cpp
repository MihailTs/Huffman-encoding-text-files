#include "HuffmanEncoder.h"
#include <math.h>
#include "NoFileSpecifiedException.h"
#include "IllegalCharecterException.h"

HuffmanEncoder::HuffmanEncoder(){
    inputFile = "";
    outputFile = "";
    inputBitSize = 0;
    outputBitSize = 0;
}

HuffmanEncoder::HuffmanEncoder(std::string _inputFile){
    inputFile = _inputFile;
    outputFile = "";
    inputBitSize = 0;
    outputBitSize = 0;
}

HuffmanEncoder::HuffmanEncoder(std::string _inputFile, std::string _outputFile){
    inputFile = _inputFile;
    outputFile = _outputFile;
    inputBitSize = 0;
    outputBitSize = 0;
}

void HuffmanEncoder::setInputFile(std::string _inputFile){
    inputFile = _inputFile;
    inputBitSize = 0;
    outputBitSize = 0;
}

void HuffmanEncoder::setOutputFile(std::string _outputFile){
    outputFile = _outputFile;
    outputBitSize = 0;
}

std::string HuffmanEncoder::getInputFile(){
    return inputFile;
}

std::string HuffmanEncoder::getOutputFile(){
    return outputFile;
}

void HuffmanEncoder::findCountOfOccurrences(std::ifstream& reader, int* countOccurrences){
    std::string line;
    while(std::getline(reader, line)){
        for(int i = 0; i < line.size(); i++){
            if((int) line[i] < 0 || (int) line[i] > 127){
                throw IllegalCharercterException();
            }
            countOccurrences[(int) line[i]]++;
            inputBitSize += 8;
        }
        countOccurrences[10]++;
    }
    if(countOccurrences[10] > 0) {
        countOccurrences[10]--;
    }
}

void HuffmanEncoder::writeCompressedData(std::ifstream& reader, std::ofstream& writer, 
                                            const std::vector<std::string>& charEncodings){
    std::string line;
    //read from first line and than read all other lines
    //this way there is no new line in the end of the compressed file
    if(std::getline(reader, line)){
         for(int i = 0; i < line.size(); i++){
            writer << charEncodings.at((int) line[i]);
            outputBitSize += charEncodings.at((int) line[i]).size();
        }
    }

    //compressed data is being written on one line
    while(std::getline(reader, line)){
        //this is the encoding for the new line charecter
        writer << charEncodings.at(10);
        for(int i = 0; i < line.size(); i++){
            writer << charEncodings.at((int) line[i]);
            outputBitSize += charEncodings.at((int) line[i]).size();
        }
    }                                                    
}

void HuffmanEncoder::printDebugData(std::ifstream& reader, 
                                    const std::vector<std::string>& charEncodings){

    std::string line;
    std::string encodedLine = "";

    while(std::getline(reader, line)){
        encodedLine = "";
        for(int i = 0; i < line.size(); i++){
            encodedLine += charEncodings.at((int) line[i]);
        }
        printDebugLine(encodedLine);
        //debug data on one line
        //std::cout << std::endl;
    }         

}

void HuffmanEncoder::printDebugLine(const std::string& encodedLine){
    for(int i = 0; i < encodedLine.size(); i += 8){
        if(encodedLine.size() - i <= 8){
            std::cout << binaryStringToInt(fillBinary(encodedLine.substr(i), 8)) << " ";
        } else {
            std::cout << binaryStringToInt(encodedLine.substr(i, 8)) << " ";
        }
    }
}

std::string HuffmanEncoder::fillBinary(std::string binary, int cntDigits){
    if(binary.size() > cntDigits){
        throw std::runtime_error("The given string is longer than the given number of digits");
    }

    while(binary.size() < cntDigits){
        binary += '0';
    }

    return binary;
}

int HuffmanEncoder::binaryStringToInt(const std::string& bin){
    int val = 0;

    for(int i = bin.size() - 1; i >= 0; i--){
        if(bin[i] == '1'){
            val += std::pow(2, bin.size() - 1 - i);
        }
    }

    return val;
}

void HuffmanEncoder::compress(){
    if(inputFile == "" || outputFile == ""){
        throw NoFileSpecifiedException();
    }

    try {
        std::ifstream firstReader(inputFile);
        std::ofstream writer(outputFile);
        
        int* countOccurrences = new int[HuffmanTree::ENCODING_TABLE_SIZE];
        for(int i = 0; i < HuffmanTree::ENCODING_TABLE_SIZE; i++){
            countOccurrences[i] = 0;
        }

        findCountOfOccurrences(firstReader, countOccurrences);

        bool isEmptyFile = true;
        for(int i = 0; i < HuffmanTree::ENCODING_TABLE_SIZE; i++){
            if(countOccurrences[i] > 0){
                isEmptyFile = false;
                break;
            }
        }

        //checking if the given file is empty. If yes -> emptying the output file
        if(isEmptyFile){
            writer.close();
            firstReader.close();
            delete []countOccurrences;
            return;
        }

        HuffmanTree ht(countOccurrences);
        std::vector<std::string> charEncodings = ht.getCharEncodings();

        delete []countOccurrences;
        firstReader.close();

        std::ifstream secondReader(inputFile);

        writer << ht.serialized() << std::endl;
        writeCompressedData(secondReader, writer, charEncodings);

        secondReader.close();
        writer.close();
    } catch (std::ifstream::failure e) {
        std::cout << "Exception occurred while reading/writing to file";
    }
}

double HuffmanEncoder::getCompressionDegree(){
    if(inputFile == "" || outputFile == ""){
        throw std::runtime_error("You must first compress the input file to see this data.");
    }
    return (double) outputBitSize / inputBitSize;
}

// decompresses the inputFile to the outputFile
void HuffmanEncoder::decompress(){
    if(inputFile == "" || outputFile == ""){
        throw NoFileSpecifiedException();
    }

    try {
        std::ifstream reader(inputFile);
        std::ofstream writer(outputFile);

        std::string line;
        
        //at first line contains the incoding info
        if(!std::getline(reader, line)){
            throw std::runtime_error("The given file is empty. Unable to decompress an empty file!");
        }

        HuffmanTree ht;
        ht.deserialized(line);

        if(std::getline(reader, line)){
            writer << ht.decode(line);
        } else {
            return;
        }

        while(std::getline(reader, line)){
            writer << std::endl;
            writer << ht.decode(line);
        }
        
        reader.close();
        writer.close();
    }

    catch (std::ifstream::failure e) {
        std::cout << "Exception reading/writing to file";
    }
}

void HuffmanEncoder::debugRegime(){
    if(inputFile == ""){
        throw NoFileSpecifiedException();
    }

    try {
        std::ifstream firstReader(inputFile);

        int* countOccurrences = new int[HuffmanTree::ENCODING_TABLE_SIZE];
        for(int i = 0; i < HuffmanTree::ENCODING_TABLE_SIZE; i++){
            countOccurrences[i] = 0;
        }

        findCountOfOccurrences(firstReader, countOccurrences);

        HuffmanTree ht(countOccurrences);
        std::vector<std::string> charEncodings = ht.getCharEncodings();

        delete [] countOccurrences;
        firstReader.close();

        //rereading and writing to the console    
        std::ifstream secondReader(inputFile);
        printDebugData(secondReader, charEncodings);

        secondReader.close();
    } catch (std::ifstream::failure e) {
        std::cout << "Exception reading/writing to file";
    }
}