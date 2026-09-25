/*
Dynamically allocate a double array with numHeights elements and assign heightsValues with the array's address. 
The program will read numHeights doubles into the array and then print each value.
*/

#include "memtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

void PrintItems(double* arrayPtr, int arraySize) {
    int i;

    if (arrayPtr != nullptr) {
        for (i = 0; i < arraySize; ++i) {
            cout << fixed << setprecision(1);
            cout << "Height " << i + 1 << ": " << arrayPtr[i] << " meters" << endl;
        }
    }
}

int main() {
    double* heightsValues = nullptr;
    int numHeights;
    int i;

    cin >> numHeights;

    /* Your code goes here */
    heightsValues = new double[numHeights];

    for (i = 0; i < numHeights; ++i) {
        cin >> heightsValues[i];
    }

    PrintItems(heightsValues, numHeights);

    delete[] heightsValues;

    memtest(); // Check memory for testing purposes only

    return 0;
}