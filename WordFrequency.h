#ifndef WORDFREQUENCY_H
#define WORDFREQUENCY_H

#include <string>

class WordFrequency{
    private:
        char word;
        int freq;

    public:
        WordFrequency( char word );
        ~WordFrequency();

        char getWord();
        int getFrequency();
        void incFrequency();
        bool compare( WordFrequency *wf );

};

#endif // WORDFREQUENCY_H
