#ifndef SORTMANAGER_H
#define SORTMANAGER_H

#include "dsstring.h"
#include "dsvector.hpp"

class SortManager
{
private:
    DSVector<DSString> * wordList;
    DSString input;
    DSString output;
    int numWords;
    int numOutputs;

public:
    SortManager();
    SortManager(const DSString&, const DSString&);
    ~SortManager();
    void setInput(DSString);
    void setOutput(DSString);
    void setNumWords(int);
    void setNumOutputs(int);
    DSString getInput();
    DSString getOutput();
    int getNumWords();
    int getNumOutputs();
    void readInputFile();
    void readNumWords(std::ifstream&);
    void readNumOutputs(std::ifstream &);
    void readWord(std::ifstream &);
    void writeToOutput();
    void sortWords();
    void runSortingCompetition();

};

#endif // SORTMANAGER_H
