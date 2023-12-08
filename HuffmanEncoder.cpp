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

void HuffmanEncoder::findCountOfOccurrences(std::ifstream& reader, int* countOccurrences){
    std::string line;
    while(std::getline(reader, line)){
        for(int i = 0; i < line.size(); i++){
            countOccurrences[(int) line[i]]++;
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
        }
    }

    while(std::getline(reader, line)){
         writer << std::endl;
        for(int i = 0; i < line.size(); i++){
            writer << charEncodings.at((int) line[i]);
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

        HuffmanTree hf(countOccurrences);
        std::vector<std::string> charEncodings = hf.getCharEncodings();

        delete [] countOccurrences;
        firstReader.close();

        //rereading and writing to the file        
        std::ifstream secondReader(inputFile);
        std::ofstream writer(outputFile);

        writeCompressedData(secondReader, writer, charEncodings);

        secondReader.close();
        writer.close();
    }

    catch (std::ifstream::failure e) {
        std::cout << "Exception reading/writing to file";
    }
}

void HuffmanEncoder::decompress(){
}