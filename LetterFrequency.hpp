#ifndef _LETTERFREQUENCY_HPP_
#define _LETTERFREQUENCY_HPP_

#include <iostream>

class LetterFrequency{
    private:
        char word;
        int freq;

    public:
        LetterFrequency( char word );
        ~LetterFrequency();

        char getWord();
        int getFrequency();
        void incFrequency();
        bool compare( LetterFrequency *wf );
        void print();

};

#endif // _LETTERFREQUENCY_HPP_
