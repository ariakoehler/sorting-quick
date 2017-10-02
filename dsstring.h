#ifndef DSSTRING_H
#define DSSTRING_H
#include <vector>
#include <iostream>
#include "dsvector.hpp"

/*
  Implements a string class, serving as a wrapper for cstring with added features.
*/

class DSString
{

private:
    char * word;
    unsigned int length;

public:
    DSString();
    DSString(const char *);
    DSString(const DSVector<char>& rhs);
    DSString(const DSString& rhs);
    ~DSString();
    unsigned int getLength() const;
    char * c_str() const;
    int stringToInt() const;
    DSString normalize() const;
    DSString& operator =(const char *);
    DSString& operator =(const DSString&);
    char& operator [](unsigned int) const;
    bool operator ==(const char *) const;
    bool operator !=(const char *) const;
    bool operator ==(const DSString &) const;
    bool operator !=(const DSString&) const;
    bool operator <(const DSString&) const;
    bool operator >=(const DSString&) const;
    bool operator >(const DSString&) const;
    bool operator <=(const DSString&) const;
    friend std::ostream& operator <<(std::ostream& stream, const DSString& string);

};

#endif // DSSTRING_H
