/*
Complete the catch block to output "Failure: ", followed by excpt.what(). End with a newline.
*/

#include <iostream>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

int main() {
    string okraDataName;
    ifstream okraInStream;
    int okraVal;

    cin >> okraDataName;
    okraInStream.exceptions(ifstream::failbit);

    try {
        okraInStream.open(okraDataName);

        okraInStream >> okraVal;
        cout << "Value read from " << okraDataName << ": " << okraVal << endl;
    }
    catch (ios_base::failure& excpt) {
        cout << "Failure: " << excpt.what() << endl;
        /* Your code goes here */

    }

    // Closes the opened file
    if (okraInStream.is_open()) {
        okraInStream.close();
    }

    return 0;
}