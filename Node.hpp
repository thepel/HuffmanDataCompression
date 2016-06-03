#ifndef _NODE_HPP_
#define _NODE_HPP_

class Node{
private:
	char letter;
	int freq;

	Node *left;
	Node *right;

public:
	Node( char letter );
	~Node();

	char getLetter();
	int  getFrequency();
	void incFrequency();
	void setFrequency( int freq );
	bool compareLetter( Node *n );
	bool compareFrequency( Node *n );
	void setLeft( Node *n );
    void setRight( Node *n );
    Node* getLeft();
    Node* getRight();
	void print();

};

#endif // _NODE_HPP_
