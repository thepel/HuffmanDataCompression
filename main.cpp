#include <iostream>
#include <string>
#include "WordFrequency.h"
#include "H:\alpro3\libBruno\LinkedList\LinkedList.hpp"

using namespace std;

int main(){
    string wrd;
    LinkedList<WordFrequency> *char_list;
    WordFrequency *wf;

    cout << "Digite a palavra a ser comprimida: ";
    cin >> wrd;
    cout << endl;

    char_list = new LinkedList<WordFrequency>;

    for( string::iterator it = wrd.begin(); it != wrd.end(); it++ ){
        wf = new WordFrequency( *it );

        if( char_list->exists( wf ) == true )
            cout << "Ja tem a letra " << *it << endl;
        else{
            cout << "Nao tem a letra " << *it << endl;
            char_list->add( wf );
        }

    }

    delete char_list;

    return 0;
}
