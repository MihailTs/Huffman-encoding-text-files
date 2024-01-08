#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>
#include <string>
#include "../HuffmanEncoder.h"

TEST_CASE("TestCompressNonEmptyFile"){
    HuffmanEncoder encoder("testInputFile.txt", "testOutputFile.txt");
    encoder.compress();

    std::string lines[2];
    std::ifstream reader("testOutputFile.txt");

    std::string line;
    int lineCounter = 0;
    while(std::getline(reader, line)){
        lines[lineCounter] = line;
        lineCounter++;
    }

    CHECK(lineCounter == 2);
    CHECK(lines[1] == "000110110001001001011100111110000110000000101101010111110011010001001001011100100111010011011110101100101011101011010011101111010000101000101111110000111011110111110110100101011101011111000000001011000101111101111101100011101110011101101010111100111010011011110101100111100110100010010110110111111000111000011111111010000010111111110010001001011011011111101101001101111100001110111101111110100111011111000011010110011111000011000000010110101011110011010000100110111101001011011101000001000111101100010100000110011000110011100011000011101111011111101001110111110000110101100111110000110000000101101010111100110100001001101111010010110111010000010001111011000101000001100110001");
}

TEST_CASE("TestCompressEmptyFile"){
    HuffmanEncoder he("testEmptyInputFile.txt", "testEmptyOutputFile.txt");
    he.compress();
 
    std::ifstream reader("testEmptyOutputFile.txt");

    std::string line;
    int lineCounter = 0;
    while(std::getline(reader, line)){
        lineCounter++;
    }

    CHECK(line.empty());
    CHECK(lineCounter == 0);
}

TEST_CASE("TestDecompressNonEmptyFile"){
    HuffmanEncoder encoder("testOutputFile.txt", "testInputFile.txt");
    encoder.decompress();

    std::string lines[4];
    std::ifstream reader("testInputFile.txt");

    std::string line;
    int lineCounter = 0;
    while(std::getline(reader, line)){
        lines[lineCounter] = line;
        lineCounter++;
    }

    CHECK(lineCounter == 4);
    CHECK(lines[0] == "First things first");
    CHECK(lines[1] == "I'ma say all the words inside my head");
    CHECK(lines[2] == "I'm fired up and tired of the way that things have been, oh-ooh");
    CHECK(lines[3] == "The way that things have been, oh-ooh");
}

TEST_CASE("TestDecompressEmptyFile"){
    HuffmanEncoder he("testEmptyOutputFile.txt", "testEmptyInputFile.txt");
    he.compress();
 
    std::ifstream reader("testEmptyInputFile.txt");

    std::string line;
    int lineCounter = 0;
    while(std::getline(reader, line)){
        lineCounter++;
    }

    CHECK(line.empty());
    CHECK(lineCounter == 0);
}