//String nameOfFile and integer yamQuantity are read from input.Open nameOfFile as an output file.If the file fails to open :
//Use cout to output nameOfFile followed by ": error opening file" and a newline.
//Terminate the program with 1 as the return value without writing to the file.
//Otherwise, write yamQuantity followed by " yams" and a newline to the opened file.
//Ex : If the input is note.txt 34, then note.txt contains :
//34 yams

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream dataFS;
    string nameOfFile;
    int yamQuantity;

    cin >> nameOfFile;
    cin >> yamQuantity;

    /* Your code goes here */
    dataFS.open(nameOfFile);
    if (!dataFS.is_open()) {
        cout << nameOfFile << ": error opening file" << endl;
        return 1;
    }
    else
        dataFS << yamQuantity << " yams" << endl;

    dataFS.close();

    return 0;
}