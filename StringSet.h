#ifndef STRINGSET_H
#define STRINGSET_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>
#include <algorithm>

class StringSet {
private:
    std::vector<std::string> set;

public:
    StringSet();
    StringSet(std::string fileName);
    void pushToSet(std::string string1);
    void popFromSet(std::string stringPoped);
    void clearSet();
    int sizeSet() const;
    void printSet() const;
    StringSet& operator+(const StringSet& otherSet);
    StringSet& operator*(const StringSet& otherSet);
    StringSet& operator=(const StringSet& otherSet);
    void similarityCheck(const StringSet& otherSet) const;
};

#endif // STRINGSET_H
