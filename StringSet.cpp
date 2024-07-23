#include "StringSet.h"

StringSet::StringSet() {}

StringSet::StringSet(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;
    
    // Process the file or treat fileName as a document string
    if (!file.is_open()) {
        // Load words from document string
        // ...
    } else {
        // Load words from file
        // ...
    }
}

void StringSet::pushToSet(std::string string1) {
    set.push_back(string1);
}

void StringSet::popFromSet(std::string stringPoped) {
    set.erase(std::remove(set.begin(), set.end(), stringPoped), set.end());
}

void StringSet::clearSet() {
    set.clear();
}

int StringSet::sizeSet() const {
    return set.size();
}

void StringSet::printSet() const {
    const int lineLength = 70;
    int currentLength = 0;

    for (const std::string& word : set) {
        currentLength += word.length() + 1;
        if (currentLength > lineLength) {
            std::cout << std::endl;
            currentLength = word.length() + 1;
        }
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

StringSet& StringSet::operator+(const StringSet& otherSet) {
    for (const std::string& s : otherSet.set) {
        this->set.push_back(s);
    }
    return *this;
}

StringSet& StringSet::operator*(const StringSet& otherSet) {
    StringSet intersection;
    for (const std::string& s : set) {
        if (std::find(otherSet.set.begin(), otherSet.set.end(), s) != otherSet.set.end()) {
            intersection.pushToSet(s);
        }
    }
    *this = intersection;
    return *this;
}

StringSet& StringSet::operator=(const StringSet& otherSet) {
    if (this != &otherSet) {
        set = otherSet.set;
    }
    return *this;
}

void StringSet::similarityCheck(const StringSet& otherSet) const {
    double similarityRatio;
    int intersectionSize = (*this * otherSet).sizeSet();
    similarityRatio = intersectionSize / (sqrt(otherSet.sizeSet()) * sqrt(this->sizeSet()));
    std::cout << "Similarity ratio: " << similarityRatio << std::endl;
}
