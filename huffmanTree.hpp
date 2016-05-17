#ifndef _HUFFMANTREE_HPP_
#define _HUFFMANTREE_HPP_

#include "LetterFrequency.hpp"
#include "TNode.hpp"

class HuffmanTree{
private:
    TNode<LetterFrequency> *root;

    TNode<LetterFrequency>* getRoot();
    void addNode( TNode<LetterFrequency> *n );

public:
    HuffmanTree();
    ~HuffmanTree();

    void add( LetterFrequency *lf );
    void addTree( HuffmanTree *tree );
    bool empty();
    int getTotalFrequency();
	void print();

};

#endif // _HUFFMANTREE_HPP_
