/*
Variables nameOfFile, in1, in2, and in3, are read from input.Perform the following tasks :
Open nameOfFile as the output file.
If the output file fails to open, then use cout to output nameOfFile followed by ": failed to open file" and a newline.Then, terminate the program with 1 as the return value.
Otherwise, for strings in1, in2, and in3, write "Name is " followed by the string and a newline to the output file.
Close the file.
Ex : If the input is guestNamesData.txt Yael Harry Hania, then guestNamesData.txt contains :
Name is Yael
Name is Harry
Name is Hania
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFS;
    string nameOfFile;
    string in1;
    string in2;
    string in3;

    cin >> nameOfFile;
    cin >> in1;
    cin >> in2;
    cin >> in3;

    /* Your code goes here */
    outFS.open(nameOfFile);

    if (!outFS.is_open())
    {
        cout << nameOfFile << ": failed to open file" << endl;
        return 1;
    }

    outFS << "Name is " << in1 << endl;
    outFS << "Name is " << in2 << endl;
    outFS << "Name is " << in3 << endl;

    outFS.close();

    if (outFS.is_open()) {  /* For testing purpose only */
        outFS << "File is not closed." << endl;
    }

    return 0;
}