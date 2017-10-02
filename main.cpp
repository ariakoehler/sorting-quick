#include <iostream>
#include <fstream>

#include "dsvector.hpp"
#include "dsstring.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*
    int makeVec[20] = {26,42,500,3,92,-75,20,666,342,78,71,681,502,489,203,25,759,40,42,42};
    DSVector<int> testVec0 = DSVector<int>(makeVec, 20);
    DSVector<int> testVec1 = testVec0;
    DSVector<int> testVec2 = testVec0;

    testVec1.swap(5,12);

    //testVec0.sort(0,testVec0.getSize()-1);
    //testVec1.quicksort(0,testVec1.getSize()-1);
    testVec2.dualPivotQuicksort(0, testVec2.getSize()-1);

    //cout << testVec0 << endl;
    //cout << testVec1 << endl;
    cout << testVec2 << endl;

    */


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
