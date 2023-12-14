#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>
#include <string>
#include "../HuffmanTree.h"

TEST_CASE("testConstructors"){
    int* charOccurrences = new int[128]();
    charOccurrences[68] = 4;
    charOccurrences[69] = 3;
    charOccurrences[70] = 2;
    charOccurrences[71] = 6;
    charOccurrences[72] = 17;
    HuffmanTree* ht = new HuffmanTree(charOccurrences);

    delete []charOccurrences;

    std::vector<std::string> enc = ht->getCharEncodings();
    CHECK(enc.at(68) == "010");
    CHECK(enc.at(69) == "0111");
    CHECK(enc.at(70) == "0110");
    CHECK(enc.at(71) == "00");
    CHECK(enc.at(72) == "1");

    HuffmanTree* htCopy = new HuffmanTree(*ht);
    enc = htCopy->getCharEncodings();
    CHECK(enc.at(68) == "010");
    CHECK(enc.at(69) == "0111");
    CHECK(enc.at(70) == "0110");
    CHECK(enc.at(71) == "00");
    CHECK(enc.at(72) == "1");
}

TEST_CASE("testSerializationNonEmpty"){
    int* charOccurrences = new int[128]();
    charOccurrences[68] = 4;
    charOccurrences[69] = 3;
    charOccurrences[70] = 2;
    charOccurrences[71] = 6;
    charOccurrences[72] = 17;
    HuffmanTree* ht = new HuffmanTree(charOccurrences);
    delete []charOccurrences;

    CHECK(ht->serialized() == "--'G-'D-'F'E'H");
}

TEST_CASE("testDeserialize"){
    HuffmanTree* ht = new HuffmanTree();
    
    ht->deserialized("----'n'r'e---'f--'v'k'w'h-'a-'u'l---'s-'d-'p'c-'o----'A--'B-'I'D':-'W-'z-';'q','i--'t---'''y'm--'b'g---'.'---'F'?--'O'M'N'T' ");
    CHECK(ht->serialized() == "----'n'r'e---'f--'v'k'w'h-'a-'u'l---'s-'d-'p'c-'o----'A--'B-'I'D':-'W-'z-';'q','i--'t---'''y'm--'b'g---'.'---'F'?--'O'M'N'T' ");
}

TEST_CASE("testDecode"){
    int* charOccurrences = new int[128]();
    charOccurrences[68] = 4;
    charOccurrences[69] = 3;
    charOccurrences[70] = 2;
    charOccurrences[71] = 6;
    charOccurrences[72] = 17;
    HuffmanTree* ht = new HuffmanTree(charOccurrences);
    delete []charOccurrences;

    CHECK(ht->decode("01001000110110") == "DDGHHF");
}