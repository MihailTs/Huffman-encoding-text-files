#include "HuffmanEncoder.h"

HuffmanEncoder::HuffmanEncoder(){
    inputFile = "";
    outputFile = "";
    inputBitSize = 0;
    outputBitSize = 0;
}

HuffmanEncoder::HuffmanEncoder(std::string _inputFile){
    inputFile = _inputFile;
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

void HuffmanEncoder::findCountOfOccurrences(std::ifstream& reader, int* countOccurrences){
    std::string line;
    while(std::getline(reader, line)){
        for(int i = 0; i < line.size(); i++){
            countOccurrences[(int) line[i]]++;
            inputBitSize += 8;
        }
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

    while(std::getline(reader, line)){
        writer << std::endl;
        for(int i = 0; i < line.size(); i++){
            writer << charEncodings.at((int) line[i]);
            outputBitSize += charEncodings.at((int) line[i]).size();
        }
    }                                                    
}

void HuffmanEncoder::compress(){
    //What if no output file is given
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

        //rereading and writing to the file        
        std::ifstream secondReader(inputFile);
        std::ofstream writer(outputFile);

        writer << ht.serialized() << std::endl;

        writeCompressedData(secondReader, writer, charEncodings);

        secondReader.close();
        writer.close();
    }

    catch (std::ifstream::failure e) {
        std::cout << "Exception reading/writing to file";
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