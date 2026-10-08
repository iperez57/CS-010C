/*
Configure the ofstream fileStream to throw an exception if an error occurs when attempting to open or write to the file.
*/

#include "testcode.h"  // For testing purposes
#include <iostream>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

int main() {
    string fileName;
    ofstream fileStream;
    double volumeVal;

    cin >> fileName;
    cin >> volumeVal;

    /* Your code goes here */
    fileStream.exceptions(ostream::failbit);

    try {
        fileStream.open(fileName, ios::app); // Opens the file for writing

        fileStream << volumeVal;
    }
    catch (ios_base::failure& excpt) {
        cout << "Error with file: " << excpt.what() << endl;
    }

    // Closes the opened file
    if (fileStream.is_open()) {
        fileStream.close();
    }

    RunTests();  // For testing purposes

    return 0;
}