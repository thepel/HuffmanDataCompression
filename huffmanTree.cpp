#include "huffmanTree.hpp"

#define JUNCTION_NODE 'X'

Node* HuffmanTree::getRoot(){ return this->root; }

HuffmanTree::HuffmanTree() { this->root = NULL; }
HuffmanTree::~HuffmanTree() {} // TODO Implement HuffmanTree destructor.

bool HuffmanTree::empty(){
    if( this->root == NULL )
        return true;

    return false;
}

int HuffmanTree::getTotalFrequency(){

    if( empty() )
        return 0;

    return this->root->getFrequency();
}

void HuffmanTree::print(){

}

