/*
Integer numVases is read from input, and lupinesSold is an integer pointer.Perform the following tasks :
Dynamically allocate an array with numVases elements, and assign lupinesSold with the array's address.
For indices 0 to numVases - 1 of lupinesSold, assign lupinesSold[i] with the next integer read from input.
Call PrintVasesContent() to output the elements in lupinesSold.
Deallocate the array pointed to by lupinesSold.
*/

//#include "memtest.h"
#include <iostream>
using namespace std;

void PrintVasesContent(int* arrayPtr, int arraySize) {
    int i;

    if (arrayPtr != nullptr) {
        cout << "Lupines in vases: ";
        for (i = 0; i < arraySize - 1; ++i) {
            cout << arrayPtr[i] << ", ";
        }
        cout << arrayPtr[arraySize - 1] << endl;
    }
}

int main() {
    int* lupinesSold = nullptr;
    int numVases;
    int i;

    cin >> numVases;

    /* Your code goes here */
    lupinesSold = new int[numVases];
    for (i = 0; i < numVases; i++)
    {
        cin >> lupinesSold[i];
    }

    PrintVasesContent(lupinesSold, numVases);

    delete[] lupinesSold;

   // memtest(); // Check memory for testing purposes only

    return 0;
}