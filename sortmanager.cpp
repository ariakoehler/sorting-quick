#include "sortmanager.h"


//============
//CONSTRUCTORS
//============

SortManager::SortManager(){}


//constructor which sets input and output file names
SortManager::SortManager(const DSString & inputFile, const DSString & outputFile) {
    //call various setters
    setInput(inputFile);
    setOutput(outputFile);

    //initialize wordList and other member data
    int numWords;
    int numOutputs;
}



//==================
//ACCESSORS/MUTATORS
//==================

void SortManager::setInput(DSString fileName) {
    input = fileName;
}


void SortManager::setOutput(DSString fileName) {
    output = fileName;
}


void SortManager::setNumWords(int numberOfWords) {
    numWords = numberOfWords;
}


void SortManager::setNumOutputs(int numberOfOutputs) {
    numOutputs = numberOfOutputs;
}


DSString SortManager::getInput() {
    return input;
}


DSString SortManager::getOutput() {
    return output;
}


int SortManager::getNumWords() {
    return numWords;
}


int SortManager::getNumOutputs() {
    return numOutputs;
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
