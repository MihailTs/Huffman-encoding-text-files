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

        void findEncodings(std::vector<std::string>&);

        void findEncodings(std::vector<std::string>&, Node*, std::string);

        void cleanup(Node*);

        void constructTree(std::vector<Node*>&);

        void printLeafes(Node*);

        void serialized(Node*, std::string&);

        void deserialized(Node*&, const std::string&, int&);

    public:

        static const int ENCODING_TABLE_SIZE = 128;

        HuffmanTree();
        HuffmanTree(int*);
        // HuffmanTree(const HuffmanTree&);

        std::vector<std::string> getCharEncodings();

        void deserialized(const std::string&);

        std::string serialized();

        std::string decode(const std::string&);

        // bool operator=(const HuffmanTree&);
        // void copy(const HuffmanTree&);
        void cleanup();
        ~HuffmanTree();

};