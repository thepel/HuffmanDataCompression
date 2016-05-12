#ifndef _HUFFMANTREE_HPP_
#define _HUFFMANTREE_HPP_

#include "LetterFrequency.hpp"
#include "C:\Users\bruno.carneiro\Documents\faculdade\libBruno-master\Tree\TNode.hpp"

class HuffmanTree{
private:
    TNode<LetterFrequency> *root;

public:
    HuffmanTree();
    ~HuffmanTree();

	void print();
    //void add( LetterFrequency *lf );
    //void print();

};

#endif // _HUFFMANTREE_HPP_
