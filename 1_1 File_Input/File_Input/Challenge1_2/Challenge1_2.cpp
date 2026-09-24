//If dataFS.is_open() returns false, then:
//Output benchFileName, followed by ": failed to open file" and a newline.
//Terminate the program with the return value 1, so that the program does not proceed to read the file.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream dataFS;
    string benchFileName;
    int benchCount;

    cin >> benchFileName; // Assigns benchFileName with a string read from input

    dataFS.open(benchFileName); // Attempts to open the file associated with benchFileName

    /* Your code goes here */

    if (!dataFS.is_open()) {
        cout << benchFileName << ": failed to open file" << endl;
        return 1;
    }

    dataFS >> benchCount;

    cout << benchCount << endl;

    dataFS.close();

    return 0;
}