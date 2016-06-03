#include "huffmanTree.hpp"

#define JUNCTION_NODE 'X'

Node* HuffmanTree::getRoot(){ return this->root; }

HuffmanTree::HuffmanTree() { this->root = NULL; }
HuffmanTree::~HuffmanTree() {} // TODO Implement HuffmanTree destructor.

void HuffmanTree::createTreeFromList( std::list<Node*> *node_list ){
	Node *n;

	std::cout << "Gerando arvore de Huffman..." << std::endl;
	while( !node_list->empty() ){

		n = node_list->front();
		node_list->pop_front();

		n->print();

		std::cout << std::endl;
	}

}

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

