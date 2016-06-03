#include "Node.hpp"

Node::Node( char letter ){
    this->letter = letter;
    this->freq   = 1;
    this->left   = NULL;
    this->right  = NULL;
}

Node::~Node(){
    //TODO Destructor of LetterFrequency
}

char Node::getLetter(){
    return this->letter;
}

int Node::getFrequency(){
    return this->freq;
}

void Node::incFrequency(){
    this->freq++;
}

void Node::setFrequency( int freq ){ this->freq = freq; }

bool Node::compareLetter( Node *n ){

    if( this->letter == n->getLetter() )
        return true;

    return false;
}

bool Node::compareFrequency( Node *n ){

    if( this->freq < n->getFrequency() )
        return true;

    return false;
}

void Node::print(){
	std::cout << "Letter: " << this->letter;
	std::cout << "    Freq: " << this->freq;
	std::cout << "    Left: " << this->left;
	std::cout << "    Right " << this->right;
	std::cout << std::endl;
}

void Node::setLeft( Node *n ) { this->left = n; }

void Node::setRight( Node *n ) { this->right = n; }

Node* Node::getLeft() { return this->left; }

Node* Node::getRight() { return this->right; }
