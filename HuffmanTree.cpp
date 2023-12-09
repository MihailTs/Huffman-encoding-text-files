#include "HuffmanTree.h"
#include <utility>
#include <iostream>
#include <algorithm>

HuffmanTree::HuffmanTree(int* occurrenceCounts){
    std::vector<Node*> charValuePairs;
    for(int i = 0; i < ENCODING_TABLE_SIZE; i++){
        if(occurrenceCounts[i] > 0){
            charValuePairs.push_back(new Node{(char) i, occurrenceCounts[i], nullptr, nullptr});
        }
    }

    std::sort(charValuePairs.begin(), charValuePairs.end(), 
                [](Node* first, Node* second) -> bool {return first->value > second->value;});

    constructTree(charValuePairs);
}

void HuffmanTree::constructTree(std::vector<Node*>& charValuePairs){
    if(charValuePairs.size() == 1){
        root = charValuePairs.at(0);
        return;
    }

    Node* lowestPair1 = charValuePairs.back();
    charValuePairs.pop_back();
    Node* lowestPair2 = charValuePairs.back();
    charValuePairs.pop_back();
    
    Node* newPair = new Node{'-', lowestPair1->value + lowestPair2->value, lowestPair1, lowestPair2};

    if(newPair->value > charValuePairs.front()->value){
        charValuePairs.insert(charValuePairs.begin(), newPair);
    } else{
        for(int i = charValuePairs.size() - 1; i >= 0; i--){
            if(charValuePairs.at(i)->value >= newPair->value){
                charValuePairs.insert(charValuePairs.begin() + i + 1, newPair);
                break;
            }
        }
    }

    constructTree(charValuePairs);
}

void HuffmanTree::printLeafes(Node* nodeRoot){
    if(nodeRoot == nullptr){
        return;
    }

    if(nodeRoot->left == nullptr && nodeRoot->right == nullptr){
        std::cout << "(" << nodeRoot->symbol << ", " << nodeRoot->value << ")";
    } else {
        printLeafes(nodeRoot->left);
        printLeafes(nodeRoot->right);
    }

}

std::vector<std::string> HuffmanTree::getCharEncodings(){
    std::vector<std::string> charEncodings;
    for(int i = 0; i < ENCODING_TABLE_SIZE; i++){
        charEncodings.push_back("");
    }

    findEncodings(charEncodings);
    return charEncodings;
}

void HuffmanTree::findEncodings(std::vector<std::string>& charEncodings){
    findEncodings(charEncodings, root, "");
}

void HuffmanTree::findEncodings(std::vector<std::string>& charEncodings, Node* nodeRoot, std::string currEncoding){
    if(nodeRoot == nullptr){
        return;
    }
    
    if(nodeRoot->left == nullptr && nodeRoot->right == nullptr){
        charEncodings.at((int) nodeRoot->symbol) = currEncoding;
        return;
    }

    findEncodings(charEncodings, nodeRoot->left, currEncoding + "0");
    findEncodings(charEncodings, nodeRoot->right, currEncoding + "1");
}

std::string HuffmanTree::serialized(){
    std::string serializationStr = "";
    serialized(root, serializationStr);
    return serializationStr;
}

void HuffmanTree::serialized(Node* nodeRoot, std::string& str){
    if(nodeRoot == nullptr){
        return;
    }

    if(nodeRoot->left == nullptr && nodeRoot->right == nullptr){
        str = str + "'" + nodeRoot->symbol + " ";
    } else {
        str = str + nodeRoot->symbol + " ";
    }

    serialized(nodeRoot->left, str);
    serialized(nodeRoot->right, str);
}

void HuffmanTree::cleanup(Node* nodeRoot){
    if(nodeRoot->left == nullptr && nodeRoot->right == nullptr){
        delete nodeRoot;
    } else{
        cleanup(nodeRoot->left);
        cleanup(nodeRoot->right);
    }
}

void HuffmanTree::cleanup(){
    cleanup(root);
}

HuffmanTree::~HuffmanTree(){
    cleanup();
}