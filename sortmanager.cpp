#include "sortmanager.h"


//============
//CONSTRUCTORS
//============

SortManager::SortManager(){}


//constructor which sets input and output file names
SortManager::SortManager(const DSString & input, const DSString & output) {
    //call various setters
    //instantiate a DSVector of DSStrings
}



//==================
//ACCESSORS/MUTATORS
//==================

void SortManager::setInput(DSString fileName) {

}


void SortManager::setOutput(DSString fileName) {

}


void SortManager::setNumWords(int numberOfWords) {

}


void SortManager::setNumOutputs(int numberOfOutputs) {

}


DSString SortManager::getInput() {

}


DSString SortManager::getOutput() {

}


int SortManager::getNumWords() {

}


int SortManager::getNumOutputs() {

}


//========
//FILE I/O
//========

//Parses input file and calls various read functions where appropriate
void SortManager::readInputFile() {

}


//Reads the number of words, which is specified on line 1
void SortManager::readNumWords(std::istream & inputStream) {

}


//Reads how many words are to be outputted, as specified on line 2
void SortManager::readNumOutputs(std::istream & inputStream) {

}


//Reads an individual word and adds it to running list of words
void SortManager::readWord(std::istream & inputStream) {

}


//Writes the specified number of words to output file
void SortManager::writeToOutput() {

}


//=======
//SORTING
//=======


//Calls DSVector's sort function on list of words
void SortManager::sortWords() {

}


//Runs high-level processes, calls lower-level functions
void SortManager::runSortingCompetition() {

}
