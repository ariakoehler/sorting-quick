#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "dsvector.hpp"
#include "dsstring.h"

using namespace std;

int runCatchTests(int argc, char* argv[]) {
    return Catch::Session().run();
}

int main(int argc, char *argv[])
{

    if(DSString(argv[1]) == DSString("-t")) {
        runCatchTests(argc, argv);
        return 0;
    }


    DSString fileName;
    DSVector<int> numbers = DSVector<int>();
    DSVector<char> currrentNumber = DSVector<char>();

    if(argc != 0)
        fileName = DSString(argv[1]);
    else
        throw invalid_argument("No valid files passed");

    ifstream fileIn;
    fileIn.open(fileName.c_str(),ios::in);

    char currentChar = ' ';
    while(fileIn.get(currentChar)) {
        if(currentChar == '\n' && currrentNumber.getSize() != 0) {
            numbers.push_back(DSString(currrentNumber).stringToInt());
            currrentNumber.clear();
        } else {
            currrentNumber.push_back(currentChar);
        }
    }

    numbers.quicksort(0,numbers.getSize()-1);
    cout << numbers << endl;
}
