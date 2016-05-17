#include <iostream>
#include <string>
#include <list>
#include "LetterFrequency.hpp"
#include "huffmanTree.hpp"

using namespace std;

//: Area de declaração de funções ://
string readWord();
list<LetterFrequency*>* createFreqList( string wrd );
bool compareListElements( LetterFrequency *f1, LetterFrequency *f2 );
HuffmanTree* createHuffmanTree( list<LetterFrequency*> *freq_list );

int main(){
    string wrd;
    LetterFrequency *freq;
    list<LetterFrequency*>::iterator it;
    list<LetterFrequency*> *freq_list;
    HuffmanTree *hTree;

	//: Read user input ://
    wrd = readWord();

	//: Creates a list of letter/frequency ://
    freq_list = createFreqList( wrd );

    cout << endl << "Lista formada: " << endl;

    for( it = freq_list->begin(); it != freq_list->end(); it++ ){
        freq = *it;
        freq->print();
        cout << endl;
    }

    freq_list->sort( compareListElements );

    cout << endl << "Lista ordenada por frequencia: " << endl;

    for( it = freq_list->begin(); it != freq_list->end(); it++ ){
        freq = *it;
        freq->print();
        cout << endl;
    }

    hTree = createHuffmanTree( freq_list );

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

list<LetterFrequency*>* createFreqList( string wrd ){
    string::iterator wrd_it;
    list<LetterFrequency*>::iterator l_it;
    list<LetterFrequency*> *l   = NULL;
    LetterFrequency *aux        = NULL;
    bool lFound                 = false;


    l = new list<LetterFrequency*>;

    for( wrd_it = wrd.begin(); wrd_it != wrd.end(); wrd_it++ ){

        lFound = false;

        for( l_it = l->begin(); l_it != l->end(); l_it++ ){

            aux = *l_it;

            if( aux->compareContent( *wrd_it ) ){
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
            aux = new LetterFrequency( *wrd_it );
            l->push_back( aux );
        }

    }

    return l;
}

bool compareListElements( LetterFrequency *f1, LetterFrequency *f2 ){

    if( f1->compareFrequency( f2 ) )
        return true;

    return false;

}

HuffmanTree* createHuffmanTree( list<LetterFrequency*> *freq_list ){
    list<LetterFrequency*>::iterator freq_it;
    list<HuffmanTree*>::iterator     tree_it;

    list<HuffmanTree*> *tree_list   = NULL;
    HuffmanTree *hTree              = NULL;
    LetterFrequency *freq           = NULL;


    tree_list = new list<HuffmanTree*>;

    while( !freq_list->empty() ){

        freq = freq_list->front();
        freq_list->pop_front();

        hTree = new HuffmanTree();
        hTree->add( freq );

        tree_list->push_back( hTree );

    }

    hTree = new HuffmanTree();

    while( !tree_list->empty() ){

        hTree->addTree( tree_list->front() );
        tree_list->pop_front();

    }

    delete tree_list;

    return hTree;
}

