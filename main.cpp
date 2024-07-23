#include "StringSet.h"

int main() {
    StringSet sMain("document.txt");
    StringSet s1("We just became so cruel so insensitive and rough really talking with no thinking"
                 " reacting with no caring running around just running people's peace of mind and maybe even traumatizing"
                 " them for life I am just saying let's try to be better do and act better "
                 "it all will be over before we know it.");
    
    sMain.printSet();
    std::cout << "-------------------" << std::endl;
    s1.printSet();
    std::cout << "-------------------" << std::endl;

    std::cout << "First Test Result:" << std::endl;
    sMain.similarityCheck(s1);
    std::cout << "-------------------" << std::endl;

    StringSet s2("The magic you are looking for is in the work you are avoiding");
    std::cout << "Second Test Result:" << std::endl;
    sMain.similarityCheck(s2);
    std::cout << "-------------------" << std::endl;

    std::cout << "Testing the + to append the two StringSet together:" << std::endl;
    sMain + s2;
    sMain.printSet();
    std::cout << "-------------------" << std::endl;

    std::cout << "Testing the * to get the intersection between the two documents:" << std::endl;
    StringSet s3 = sMain * s1;
    s3.printSet();

    return 0;
}
