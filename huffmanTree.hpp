#ifndef _HUFFMANTREE_HPP_
#define _HUFFMANTREE_HPP_

#include <iostream>
#include <list>
#include "Node.hpp"

class HuffmanTree{
private:
    Node *root;

    Node* getRoot();

public:
    HuffmanTree();
    ~HuffmanTree();

	void createTreeFromList( std::list<Node*> *node_list );
    bool empty();
    int getTotalFrequency();
	void print();

};

#endif // _HUFFMANTREE_HPP_
