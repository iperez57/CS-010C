//The stream inFS is associated with a file that contains the number of beds ordered from a wholesaler by various retailers.A while loop reads each pair of integer and string from the file.Complete the following missing parts in the while loop:
//Iterate while inFS.eof() is false.
//Read integer bedCount from inFS.
//Read string purchaser from inFS.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFS;
    string nameOfFile;
    string purchaser;
    int bedCount;

    cin >> nameOfFile;

    inFS.open(nameOfFile);
    if (!inFS.is_open()) {
        cout << nameOfFile << ": file open failed" << endl;
        return 1;
    }

    while (/* Put the condition here */!inFS.eof()) {
        /* Read bedCount from inFS here */
        inFS >> bedCount;
        /* Read purchaser from inFS here */
        inFS >> purchaser;

        if (!inFS.fail()) {
            cout << purchaser << " purchased " << bedCount << " beds." << endl;
        }
    }

    inFS.close();

    return 0;
}