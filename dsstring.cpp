#include "dsstring.h"
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

DSString::DSString() : word(nullptr), length(0) {}


DSString::DSString(const char * input) {

    //set length to 1+strlen
    length = strlen(input) + 1;

    //initizlize word of size length
    word = new char[length];

    //copy over chars
    for(int i=0; i<length; i++) {
        word[i] = input[i];
    }
}


DSString::DSString(const DSVector<char> &rhs) {

    length = rhs.getSize() + 1;

    word = new char[length];

    for(int i=0; i<length-1; i++) {
        word[i] = rhs[i];
    }

    word[length-1] = '\0';
}


DSString::DSString(const DSString& rhs) {

    //should already be lowercase alnums
    length = rhs.getLength();
    word = new char[length];    //allocate new array
    strcpy(word, rhs.c_str());  //copy over contents
}


DSString::~DSString() {
    delete[] word;
}


unsigned int DSString::getLength() const {
    return length;
}


//gets underlying cstring
char* DSString::c_str() const {
    return word;
}


//takes a string of all digits and returns it as an integer
int DSString::stringToInt() const {

    int total = 0;
    bool negative = false;

    for(unsigned int i=1; i<length; i++) {
        //check to see if the number is negative
        if(i == length - 1 && word[length - i - 1] == '-') {
            negative = true;
            continue;
        }

        //check to make sure is a digit
        if(int(word[length - i - 1]) < 48 || int(word[length - i - 1]) > 57) {
            throw(invalid_argument("String must consist entirely of numeric characters to use stringToInt."));
        }
        //increase the total by the value of the digit * 10 to the power of its location
        total += (word[length - i - 1] - '0') * pow(10.0, double(i - 1));
    }

    //account for negatives
    if(negative)
        total *= -1;

    return total;
}


//overloaded subscript operator implements bounds checking
char& DSString::operator [](unsigned int index) const {

    //check bounds; avoid operating on the null terminator
    if(index < length) {
        return word[index];
    } else {
        throw std::out_of_range("Requested index out of bounds!");
    }

}


//sets the underlying cstring to a new cstring
DSString& DSString::operator =(const char * input) {
    *this = DSString(input);
    return *this;
}


//overloaded assignment operator for managing dynamically allocated memory
DSString& DSString::operator =(const DSString& rhs) {

    if (&rhs != this){

        //free up old memory and allocated new memory
        if(word != nullptr) {
            delete[] word;
        }

        length = rhs.getLength();
        word = new char[length] {};

        //put new data in data members
        strcpy(word, rhs.c_str());
    }

    return *this;
}


//returns a string in all lowercase and without punctuation for comparisons and writing to files
DSString DSString::normalize() const {

    //initialize vector for pushing chars
    DSVector<char> temp = DSVector<char>();

    //push each alnum to a vector
    for(int i=0; i<strlen(word); i++) {
        //skip punctuation
        if(word[i] != ',' && word[i] != '.' && word[i] != '!' && word[i] != '?' && word[i] != ';' && word[i] != ':' && word[i] != '(' && word[i] != ')' && word[i] != '[' && word[i] != ']' && word[i] != '{' && word[i] != '}') {
            //normalize case
            if(int(word[i]) >= 65 && int(word[i]) <=90) {
                temp.push_back(char(word[i] + 32));
            } else {
                temp.push_back(word[i]);
            }
        }
    }

    //return dsstring built from vector
    return DSString(temp);
}


//overloaded stream insertion operator prints contents of cstring
std::ostream& operator <<(std::ostream& stream, const DSString& stringy) {
    //normalize
    stream << stringy.normalize().c_str();
    return stream;
}


//overloaded equality operator for comparing two DSStrings
bool DSString::operator ==(const DSString& rhs) const {
    //normalize
    return !strcmp(this->normalize().c_str(), rhs.normalize().c_str());
}


//overloaded inequality operator for compaing two DSStrings
bool DSString::operator !=(const DSString& rhs) const {
    return !(*this == rhs);
}


//overloaded equality operator for comparing to cstring
bool DSString::operator ==(const char * rhs) const {
    //normalize
    return (DSString(rhs).normalize() == this->normalize());
}


//overloaded inequality operator for comparing to cstring
bool DSString::operator !=(const char * rhs) const {
    return !(*this == rhs);
}


//tells whether or not a string comes after this one alphabetically
bool DSString::operator <(const DSString& rhs) const {
    //normalize
    DSString lnorm = this->normalize();
    DSString rnorm = rhs.normalize();

    //find minimum length to avoid going out of bounds
    unsigned int minLength = (lnorm.getLength() < rnorm.getLength()) ? (lnorm.getLength()) : (rnorm.getLength());

    for(unsigned int i=0; i<minLength; i++) {
        if(int(lnorm[i]) > int(rnorm[i])){
            //if char is greater than, return false
            return false;
        } else if(int(lnorm[i]) < int(rnorm[i])) {
            //if char is less than, return true
            return true;
        } else {
            //if chars equal, continue
            continue;
        }
    }
    return false;
}


//tells whether a string comes after this one alphabetically
bool DSString::operator >=(const DSString& rhs) const {
    return !(*this < rhs);
}


//tells whether a string comes after this one alphabetically
bool DSString::operator >(const DSString& rhs) const {

    //normalize
    DSString lnorm = this->normalize();
    DSString rnorm = rhs.normalize();

    //find minimum length to avoid going out of bounds
    unsigned int minLength = (lnorm.getLength() < rnorm.getLength()) ? (lnorm.getLength()) : (rnorm.getLength());

    for(unsigned int i=0; i<minLength; i++) {
        if(int(lnorm[i]) < int(rnorm[i])){
            //if char is greater than, return false
            return false;
        } else if(int(lnorm[i]) > int(rnorm[i])) {
            //if char is less than, return true
            return true;
        } else {
            //if chars equal, continue
            continue;
        }
    }
    return false;
}


//tells whether a string comes before this one alphabetically
bool DSString::operator <=(const DSString& rhs) const {
    return !(*this >= rhs);
}
