#pragma once
#include <vector>
#include <string>

class HuffmanTree {

    private:

        //node of the tree
        struct Node {
            char symbol;
            int value;
            Node* left;
            Node* right;
        };

        Node* root;

        //returns vector (map) of the encodings
        void findEncodings(std::vector<std::string>&);

        //helper to find the encodings - traversing the tree
        void findEncodings(std::vector<std::string>&, Node*, std::string);

        void cleanup(Node*);

        void copy(Node*, Node*&);

        //constructs the tree from the vector of nodes
        void constructTree(std::vector<Node*>&);

        //method used for debugging
        void printLeafes(Node*);

        //Helper method for serialization
        void serialized(Node*, std::string&);

        //Helper method for deserialization
        void deserialized(Node*&, const std::string&, int&);

    public:

        static const int ENCODING_TABLE_SIZE = 128;

        HuffmanTree();

        //Конструктор по масив от броя срещания на всеки символ
        HuffmanTree(int*);

        HuffmanTree(const HuffmanTree&);

        //returns the vector (map) of the encodings of the chars
        std::vector<std::string> getCharEncodings();

        //deserializes the tree
        void deserialized(const std::string&);

        //serializes the tree
        std::string serialized();

        //returns the symbol that is encoded with the passed string
        std::string decode(const std::string&);

        HuffmanTree& operator=(const HuffmanTree&);
        void copy(const HuffmanTree&);
        void cleanup();
        ~HuffmanTree();
};