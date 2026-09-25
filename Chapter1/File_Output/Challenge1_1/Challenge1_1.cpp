//Integer yamQuantity and string guestName are read from input.An ofstream named dataFS is declared and the file named note.txt is opened.Write the following to the opened file :
//"To purchase:"
//yamQuantity followed by " yams for " and guestName
//End each output with a newline.
//Ex : If the input is 38 Ben, then note.txt contains :
//To purchase :
//38 yams for Ben

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream dataFS;
    int yamQuantity;
    string guestName;

    cin >> yamQuantity;
    cin >> guestName;

    dataFS.open("note.txt");
    if (!dataFS.is_open()) {
        cout << "note.txt" << ": error occurred while opening file" << endl;
        return 1;
    }

    /* Your code goes here */

    dataFS << "To purchase:" << endl;
    dataFS << yamQuantity << " yams for " << guestName << endl;

    dataFS.close();

    return 0;
}