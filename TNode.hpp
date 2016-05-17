#ifndef _TNODE_HPP_
#define _TNODE_HPP_

#include <iostream>

template <class Type>
class TNode{
private:
    Type *content;
    TNode *left;
    TNode *right;

public:
    TNode();
    TNode( Type c );
    ~TNode();

    void setContent( Type *c );
    void setLeft( TNode *n );
    void setRight( TNode *n );
    Type* getContent();
    TNode<Type>* getLeft();
    TNode<Type>* getRight();
    //bool greaterThan( Node *n );
    void print();

};

template <class Type>
TNode<Type>::TNode(){
    this->left = NULL;
    this->right = NULL;
}

template <class Type>
TNode<Type>::TNode( Type c ){
	this->content = c;
	TNode();
}

template <class Type>
TNode<Type>::~TNode(){} // TODO Node class destructor.

template <class Type>
void TNode<Type>::setContent( Type *c ) { this->content = c; }

template <class Type>
void TNode<Type>::setLeft( TNode *n ) { this->left = n; }

template <class Type>
void TNode<Type>::setRight( TNode *n ) { this->right = n; }

template <class Type>
Type* TNode<Type>::getContent() { return this->content; }

template <class Type>
TNode<Type>* TNode<Type>::getLeft() { return this->left; }

template <class Type>
TNode<Type>* TNode<Type>::getRight() { return this->right; }

template <class Type>
void TNode<Type>::print() { this->content->print(); }
#endif // _TNODE_HPP_
