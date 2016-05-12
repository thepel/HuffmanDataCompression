#include <iostream>
#include <string>
#include "LetterFrequency.hpp"
#include "huffmanTree.hpp"
#include "C:\Users\bruno.carneiro\Documents\faculdade\libBruno-master\LinkedList\LinkedList.hpp"

using namespace std;

string readWord();
LinkedList<LetterFrequency>* newLetterList( string wrd );

int main(){
    string wrd;
    LinkedList<HuffmanTree> *lst;
    LinkedList<LetterFrequency> *lFreq;

	//: Read user input ://
    wrd = readWord();

	//: Creates a list of letter/frequency ://
    lFreq = newLetterList( wrd );

    cout << "Lista formada: " << endl;

    lFreq->printContent();

    delete lFreq;

    return 0;
}

string readWord(){
	string wrd;

	cout << "Digite a palavra a ser comprimida: ";
    cin >> wrd;
    cout << endl;

    return wrd;
}

LinkedList<LetterFrequency>* newLetterList( string wrd ){
	LinkedList<LetterFrequency> *lFreq;
	string::iterator it;
	LetterFrequency *aux;


	lFreq = new LinkedList<LetterFrequency>;

    for( it = wrd.begin(); it != wrd.end(); it++ ){
        aux = new LetterFrequency( *it );

		aux = lFreq->findElement( aux );

        if(  aux == NULL ){
        	cout << "Nao tem a letra " << *it << endl;
            lFreq->add( new LetterFrequency( *it ) );
        }
        else{
            cout << "Ja tem a letra " << *it << endl;
            aux->incFrequency();
        }

    }

    return lFreq;
}
