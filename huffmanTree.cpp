#include "huffmanTree.hpp"

#define JUNCTION_NODE 'X'

TNode<LetterFrequency>* HuffmanTree::getRoot(){ return this->root; }

HuffmanTree::HuffmanTree() { this->root = NULL; }
HuffmanTree::~HuffmanTree() {} // TODO Implement HuffmanTree destructor.

void HuffmanTree::add( LetterFrequency *lf ){
    TNode<LetterFrequency> *n = NULL;
    LetterFrequency *nlf      = NULL;

    if( empty() ){
        n = new TNode<LetterFrequency>;

        n->setContent( lf );

        this->root = n;

        return;
    }

    if( this->root->getContent()->getWord() == JUNCTION_NODE ){

        n = NULL;
    }
    else{

        //: Cria o novo nodo de junção ://
        nlf = new LetterFrequency( JUNCTION_NODE );

        // Calcula a frequencia de esquerda + direita ://
        nlf->setFrequency( this->root->getContent()->getFrequency() + lf->getFrequency() );

        //: Cria um nodo que será a nova raiz e conterá o nodo de junção ://
        n = new TNode<LetterFrequency>;

        n->setContent( nlf );

        n->setLeft( this->root );

        this->root = n;

        n = new TNode<LetterFrequency>;

        n->setContent( lf );

        this->root->setRight( n );

    }


    // TODO Finish implementation of HuffmanTree::add.

    return;
}

void HuffmanTree::addTree( HuffmanTree *tree ){
    TNode<LetterFrequency> *n;

    n = tree->root;

    add( n );


    return;
}

bool HuffmanTree::empty(){
    if( this->root == NULL )
        return true;

    return false;
}

int HuffmanTree::getTotalFrequency(){

    if( empty() )
        return 0;

    return this->root->getContent()->getFrequency();
}

void HuffmanTree::print(){

}

