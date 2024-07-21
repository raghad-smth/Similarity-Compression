// Purpose: Program to calculate how simler two doucuments to each other
// Author(s): Raghad Mohammed Suliman Mohammed
// ID(s): 20220704
// Section: 12
// Date: 8.December.2023


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<cctype>
#include <cmath>
#include<algorithm>

using namespace std;
class StringSet{
private :
    vector<string> set;
public :
    StringSet();
    StringSet(string fileName);
    void pushToSet(string string1);
    void popFromSet(string stringPoped);
    void clearSet();
    int sizeSet();
    void printSet();
    StringSet& operator+(StringSet otherSet);
    StringSet& operator*(StringSet otherSet);
    StringSet& operator=(StringSet otherSet);
    void simalrtyCheck(StringSet otherSet);

};
StringSet intersec;

StringSet ::StringSet() {
    for (string s : set){
        s =  "";
    }
}

StringSet ::StringSet(std::string fileName) {
    // opening the file
    ifstream file(fileName);
    string line;
    // if the file didn't open then this must be a string that contain a document so we deal with it as follows
    if (!file.is_open()){
        for (int i = 0; i <fileName.size(); i++) {
            string word;
            for (int j = i; fileName[j] != 32 && j < fileName.size(); j++) {
                word += fileName[j];
                i = j;
            }
            // incrementing the i cause the j is pointing to the char right before the space char
            i++;
            set.push_back(word);
            word = "";
        }
    }
     else {
        while (getline(file, line)) {
            for (int i = 0; i <= line.size(); i++) {
                if ((line[i] >= 33 && line[i] <= 47) || (line[i] >= 58 && line[i] <= 64)) {
                    line.erase(i, 1);
                    // decreasing the index  by one every time we erase form the string line to not miss any chars
                    i--;
                }
                line[i] = tolower(line[i]);
            }

            // loading the strings from the file into the set
            for (int i = 0; i < line.size(); i++) {
                string word;
                for (int j = i; line[j] != 32 && j < line.size(); j++) {
                    word += line[j];
                    i = j;
                }
                // incrementing the i cause the j is pointing to the char right before the space char
                i++;

                set.push_back(word);
                word = "";
            }

        }
    }
}



 void StringSet ::pushToSet(string string1){
    set.push_back(string1);

 }
 void StringSet ::popFromSet(std::string stringPoped) {
    for(auto ss : set){
        if (ss == stringPoped){
            set.erase(remove(set.begin(), set.end(), ss), set.end());
        }
    }

}
void StringSet :: clearSet(){
    set.clear();
};
int StringSet :: sizeSet(){
    return set.size();
};

void StringSet ::printSet() {
    // making sure that the string will get printed in a new line if the line won't fit the full string

    const int linLenght = 700;
    int j = 0;
    for (int i=0 ; i<set.size(); i++) {
        j = j + 1 + sizeof(set[i]);         // keeping track of the size of strings t
        if (sizeof(set[i])+j > linLenght) { // see if adding the size of the string to j will excced the capacity of the line
            cout << endl << set[i] << " ";
            j =0 ;
        }
        else {
            cout << set[i] << " ";
        }
    }
}


StringSet& StringSet:: operator+(StringSet otherSet){
    for (string s : otherSet.set ){
        this->set.push_back(s);
    }
    return *this;
}


StringSet& StringSet :: operator*(StringSet otherSet){
     int loopSize=0;
     vector <string> smaller;
     vector <string> larger;
     //setting how many times we will loop depending on the size of the smallest document
    if (this->sizeSet() >  otherSet.sizeSet()){
        loopSize = otherSet.sizeSet();
        smaller = otherSet.set;
        larger = this->set;
    }
    else {
        loopSize = this->sizeSet();
        smaller = this->set;
        larger = otherSet.set;
    }
    //pushing to the object that holds the result only the vlaues that are found in both doucmentries  using the find function
    for (int i=0; i<loopSize; i++){
        if (find(larger.begin(),larger.end(), smaller[i]) != larger.end()){
            intersec.pushToSet(smaller[i]);
        }
    }
    return intersec;
}

// overloading the = to be able to hold the result of two sets intersection
StringSet& StringSet :: operator=(StringSet otherSet){
    for (string s : otherSet.set){
        this->pushToSet(s);
    }
    return *this;
}

void StringSet :: simalrtyCheck(StringSet otherSet){
    double simRes;
    int intersection;
    intersection = (otherSet * (*this)).sizeSet();    // claculating the size of the shared words between the two documentres
    simRes = intersection / ( sqrt(otherSet.sizeSet())* sqrt(this->sizeSet()));
    cout << "Similarity's ratio  : " << simRes << endl;
}

// testing the program with two documents : the first is loaded from a fie , and the second is loaded from a vector of strings



int main() {


    // Printing the two documents
    StringSet sMain("doucumentry");  // getting doc form a file
    // getting from construcer's prameter
    StringSet s1("We just became so crule so insenstive and rough really talking with no thinking"
                 " reacting with no caring running around just runing peopls peace of mind and maybe even tramatize"
                 "them for life I am just saying lets try to be better do and act better "
                 "it all will be over before we know it.");
    sMain.printSet();
    cout << '\n' <<"-------------------" << '\n';
    s1.printSet();
    cout << '\n' << "-------------------" << '\n';


    // First test:

    cout << "First Test Result : " << '\n';
    sMain.simalrtyCheck(s1); // checking for the similarties
    cout << "-------------------" << '\n';

    // Second test:

    cout << "Second Test Result : " << '\n';
    StringSet s2("The mageic you are looking for is in the work you are avoiding");
    sMain.simalrtyCheck(s2);
    cout << "-------------------" << '\n';

    // Testing the + :

    cout << "Testing the + to append the two StringSet together : " << '\n';
    sMain+s2;
    sMain.printSet();
    cout << '\n' <<"-------------------" << '\n';

    // Testing the * :
    cout << "Testing the * to get the intersection between the two documents : " << '\n';
    StringSet s3 = sMain * s1;
    s3.printSet();

    return 0;
}

