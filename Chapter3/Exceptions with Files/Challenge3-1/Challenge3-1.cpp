/*
Complete the configuration of the ifstream weightStream to throw an exception if an error occurs when attempting to open or read from the file.
*/

#include <iostream>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

int main() {
    string weightFileName;
    ifstream weightStream;
    double weightValue;

    cin >> weightFileName;

    /* Your code goes here */weightStream.exceptions(ifstream::failbit);

    try {
        weightStream.open(weightFileName);

        weightStream >> weightValue;
        cout << "Value read from " << weightFileName << ": " << weightValue << endl;
    }
    catch (ios_base::failure& excpt) {
        cout << "Failed: " << excpt.what() << endl;
    }

    // Closes the opened file
    if (weightStream.is_open()) {
        weightStream.close();
    }

    return 0;
}
