#include "sortmanager.h"

#include <fstream>
#include <iostream>


//============
//CONSTRUCTORS
//============

SortManager::SortManager(){}


//constructor which sets input and output file names
SortManager::SortManager(const DSString & inputFile, const DSString & outputFile) {
    //call various setters
    setInput(inputFile);
    setOutput(outputFile);
}


SortManager::~SortManager() {
    delete wordList;
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
    std::ifstream fileIn;

    //open file
    fileIn.open(input.c_str(), std::ios::in);

    //check to see that file is open
    if(!fileIn.is_open()) {
        std::cout << "Input file did not open." << std::endl;
        return;
    }

    //read number of words
    readNumWords(fileIn);

    //read number of outputs
    readNumOutputs(fileIn);

    //until EOF, read each word
    for(int i=0; i<numWords; i++) {
        readWord(fileIn);
    }

    //don't forget to close the file
    fileIn.close();
}


//Reads the number of words in the input, which is specified on line 1
void SortManager::readNumWords(std::ifstream & inputStream) {
    //set numWords to StringToInt of dsstring of first line
    inputStream >> numWords;

    //set wordList to that size to speed things up
    wordList = new DSVector<DSString>(numWords);
}


//Reads how many words are to be outputted, as specified on line 2
void SortManager::readNumOutputs(std::ifstream & inputStream) {
    //set numOutputs to StringToInt of dsstring of second line
    inputStream >> numOutputs;
}


//Reads an individual word and adds it to running list of words
void SortManager::readWord(std::ifstream & inputStream) {
    //read next line to a dsstring and return it
    char buffer[30];
    inputStream >> buffer;
    wordList->push_back(DSString(buffer));
}


//Writes the specified number of words to output file
void SortManager::writeToOutput() {
    //create ostream object from output file name
    std::ofstream fileOut;

    //open file
    fileOut.open(output.c_str(), std::ios::out);

    //check to see file is open
    if(!fileOut.is_open()) {
        std::cout << "Output file failed to open." << std::endl;
        return;
    }

    //loop until numOutputs
    for(int i=0; i<numOutputs && i<numWords; i++) {
        //print next word from wordlist
        fileOut << (*wordList)[i] << '\n';
    }
    fileOut << std::endl;

    //don't forget to close file
    fileOut.close();
}


//=======
//SORTING
//=======


//Calls DSVector's sort function on list of words
void SortManager::sortWords() {
    //call whichever sorting algo is fastest
    wordList->quicksort(0, wordList->getSize()-1);
    //maybe include logic for determining which one will perform best on a given dataset
}


//Runs high-level processes, calls lower-level functions
void SortManager::runSortingCompetition() {
    readInputFile();
    sortWords();
    writeToOutput();
}
