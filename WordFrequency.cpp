#include "WordFrequency.h"

WordFrequency::WordFrequency( char word ){
    this->word = word;
    this->freq = 0;
}

WordFrequency::~WordFrequency(){
    //TODO Destructor of WordFrequency
}

char WordFrequency::getWord(){
    return this->word;
}

int WordFrequency::getFrequency(){
    return this->freq;
}

void WordFrequency::incFrequency(){
    this->freq++;
}

bool WordFrequency::compare( WordFrequency *wf ){

    if( this->word == wf->getWord() )
        return true;

    return false;
}
