#include <iostream>
#include <string>
#include <list>
#include "Node.hpp"
#include "huffmanTree.hpp"

using namespace std;

//: Area de declaração de funções ://
string readWord();
list<Node*>* createFreqList( string wrd );
bool compareListElements( Node *n1, Node *n2 );

int main(){
    string wrd;
    Node *freq;
    list<Node*>::iterator it;
    list<Node*> *freq_list;
    HuffmanTree *hTree;

	//: Read user input ://
    wrd = readWord();

	//: Creates a list of letter/frequency ://
    freq_list = createFreqList( wrd );

    cout << endl << "Lista formada: " << endl;

    for( it = freq_list->begin(); it != freq_list->end(); it++ ){
        freq = *it;
        freq->print();
    }

    freq_list->sort( compareListElements );

    cout << endl << "Lista ordenada por frequencia: " << endl;

    for( it = freq_list->begin(); it != freq_list->end(); it++ ){
        freq = *it;
        freq->print();
    }

    cout << endl;

	hTree = new HuffmanTree();

    hTree->createTreeFromList( freq_list );

    hTree->print();

    delete freq_list;

    return 0;
}

string readWord(){
	string wrd;

	cout << "Digite a palavra a ser comprimida: ";
    cin >> wrd;
    cout << endl;

    return wrd;
}

list<Node*>* createFreqList( string wrd ){
    string::iterator wrd_it;
    list<Node*>::iterator l_it;
    list<Node*> *l   = NULL;
    Node *aux        = NULL;
    bool lFound                 = false;


    l = new list<Node*>;

    for( wrd_it = wrd.begin(); wrd_it != wrd.end(); wrd_it++ ){

        lFound = false;

        for( l_it = l->begin(); l_it != l->end(); l_it++ ){

            aux = *l_it;

            if( aux->getLetter() == *wrd_it ){
                lFound = true;
                break;
            }
        }

        if( lFound ){
            // Se esse caracter já foi armazena, apenaas incrementa a frequência
            cout << "ja existe  " << *wrd_it << endl;
            aux->incFrequency();
        }
        else{
            cout << "nao existe " << *wrd_it << endl;
            aux = new Node( *wrd_it );
            l->push_back( aux );
        }

    }

    return l;
}

bool compareListElements( Node *n1, Node *n2 ){

    if( n1->compareFrequency( n2 ) )
        return true;

    return false;

}
