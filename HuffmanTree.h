#pragma once
#include <vector>
#include <string>

class HuffmanTree {

    private:

        struct Node {
            char symbol;
            int value;
            Node* left;
            Node* right;
        };

        Node* root;

        void printLeafes(Node*);

        void findEncodings(std::vector<std::string>&);

        void findEncodings(std::vector<std::string>&, Node*, std::string);

        void cleanup(Node*);

        void constructTree(std::vector<Node*>&);

    public:

        static const int ENCODING_TABLE_SIZE = 128;

        HuffmanTree(int*);
        // HuffmanTree(const HuffmanTree&);

        std::vector<std::string> getCharEncodings();

        // bool operator=(const HuffmanTree&);
        // void copy(const HuffmanTree&);
        void cleanup();
        ~HuffmanTree();

};