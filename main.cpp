#include <iostream>
#include "HuffmanEncoder.h"

int main(){

    HuffmanEncoder encoder("testInputFile.txt", "testOutputFile.txt");
    //HuffmanEncoder decoder("testOutputFile.txt", "testInputFile.txt");

    encoder.compress();
    //decoder.decompress();
    encoder.debugRegime();

    std::cout << encoder.getCompressionDegree();

    return 0;
}