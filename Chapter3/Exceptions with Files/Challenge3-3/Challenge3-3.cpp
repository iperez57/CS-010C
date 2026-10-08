/*
Complete the if statement to check if the file associated with fileStream remains open.
*/

#include <iostream>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

int main() {
    string pepperDataFileName;
    ifstream fileStream;
    int pepperValue;

    cin >> pepperDataFileName;
    fileStream.exceptions(ifstream::failbit);

    try {
        fileStream.open(pepperDataFileName);

        fileStream >> pepperValue;
        cout << "Value read from " << pepperDataFileName << ": " << pepperValue << endl;
    }
    catch (ios_base::failure& excpt) {
        cout << "Something went wrong: " << excpt.what() << endl;
    }

    if (/* Your code goes here */ fileStream.is_open()) {
        fileStream.close();
    }

    RunTests(fileStream);  // For testing purposes

    return 0;
}