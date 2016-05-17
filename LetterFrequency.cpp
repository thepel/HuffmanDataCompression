#include "LetterFrequency.hpp"

LetterFrequency::LetterFrequency( char word ){
    this->word = word;
    this->freq = 1;
}

LetterFrequency::~LetterFrequency(){
    //TODO Destructor of LetterFrequency
}

char LetterFrequency::getWord(){
    return this->word;
}

int LetterFrequency::getFrequency(){
    return this->freq;
}

void LetterFrequency::incFrequency(){
    this->freq++;
}

void LetterFrequency::setFrequency( int freq ){ this->freq = freq; }

bool LetterFrequency::compare( LetterFrequency *wf ){

    if( this->word == wf->getWord() )
        return true;

    return false;
}

bool LetterFrequency::compareContent( char c ){

    if( this->word == c )
        return true;

    return false;
}

bool LetterFrequency::compareFrequency( LetterFrequency *wf ){

    if( this->freq < wf->getFrequency() )
        return true;

    return false;
}

void LetterFrequency::print(){
	std::cout << "Letter: " << this->word;
	std::cout << "    Freq: " << this->freq;
}
