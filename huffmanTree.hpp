#ifndef _HUFFMANTREE_HPP_
#define _HUFFMANTREE_HPP_

#include <iostream>
#include "Node.hpp"

class HuffmanTree{
private:
    Node *root;

    Node* getRoot();

public:
    HuffmanTree();
    ~HuffmanTree();

    bool empty();
    int getTotalFrequency();
	void print();

};

#endif // _HUFFMANTREE_HPP_
