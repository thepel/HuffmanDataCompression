#include "huffmanTree.hpp"

#define JUNCTION_NODE 'X'

Node* HuffmanTree::getRoot(){ return this->root; }

HuffmanTree::HuffmanTree() { this->root = NULL; }
HuffmanTree::~HuffmanTree() {} // TODO Implement HuffmanTree destructor.

void HuffmanTree::createTreeFromList( std::list<Node*> *node_list ){
	Node *n1 = NULL;
	Node *n2 = NULL;
	Node *ju = NULL;

	bool add_root = false;
	bool done	  = false;

	std::cout << "Gerando arvore de Huffman..." << std::endl;

	while( !done ){

		if( n1 == NULL ){

			n1 = node_list->front();
			node_list->pop_front();

		} else if( n2 == NULL ){

			if( !empty() ){

				if( n1->getFrequency() >= this->root->getFrequency() )
					add_root = true;

			}

			if( add_root == true ){
				n2 = this->root;
				add_root = false;
			}
			else{
				n2 = node_list->front();
				node_list->pop_front();
			}

		}

		if( n1 != NULL && n2 != NULL ){

			std::cout << "Adding to tree: " << std::endl;
			n1->print();
			n2->print();
			std::cout << std::endl;

			ju = new Node( JUNCTION_NODE );

			ju->setFrequency( n1->getFrequency() + n2->getFrequency() );

			ju->setLeft( n1 );
			ju->setRight( n2 );

			this->root = ju;

			n1 = NULL;
			n2 = NULL;

		}

		if( node_list->empty() && n1 == NULL && n2 == NULL )
			done = true;

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
	printRec( this->root, 0 );
}

void HuffmanTree::printRec( Node *n, std::list<char> *tree_structure, int level ){

	if( n == NULL )
		return;

	printRec( n->getLeft(), indent + 4 );

	if( indent ){

		std::cout << ' ';

		std::cout << n->getLetter();
		std::cout << ' ';
		std::cout << n->getFrequency();

	}

	printRec( n->getRight(), indent + 4 );

}

