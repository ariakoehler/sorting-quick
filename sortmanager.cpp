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
    //create istream from input file name
    //open file
    //check to see that file is open
    //read number of words
    //read number of outputs
    //until EOF, read each word
}


//Reads the number of words in the input, which is specified on line 1
void SortManager::readNumWords(std::istream & inputStream) {
    //set numWords to StringToInt of dsstring of first line
}


//Reads how many words are to be outputted, as specified on line 2
void SortManager::readNumOutputs(std::istream & inputStream) {
    //set numOutputs to StringToInt of dsstring of second line
}


//Reads an individual word and adds it to running list of words
void SortManager::readWord(std::istream & inputStream) {
    //read next line to a dsstring
    //push dsstring to wordList
}


//Writes the specified number of words to output file
void SortManager::writeToOutput() {
    //loop until numOutputs
        //print next word from wordlist
}


//=======
//SORTING
//=======


//Calls DSVector's sort function on list of words
void SortManager::sortWords() {
    //call whichever sorting algo is fastest
    //maybe include logic for determining which one will perform best
}


//Runs high-level processes, calls lower-level functions
void SortManager::runSortingCompetition() {
    readInputFile();
    sortWords();
    writeToOutput();
}
