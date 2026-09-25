//Integer pointer chrysanthemumsReceived points to a dynamically allocated array with numBunches elements. 
//Deallocate the array pointed to by chrysanthemumsReceived.

#include <iostream>
using namespace std;

void PrintChrysanthemums(int* arrayPtr, int arraySize) {
    int i;

    if (arrayPtr != nullptr) {
        for (i = 0; i < arraySize; ++i) {
            cout << "Bunch " << i + 1 << ": " << arrayPtr[i] << " chrysanthemums" << endl;
        }
    }
}

int main() {
    int* chrysanthemumsReceived = nullptr;
    int numBunches;
    int i;

    cin >> numBunches;

    chrysanthemumsReceived = new int[numBunches];

    for (i = 0; i < numBunches; ++i) {
        cin >> chrysanthemumsReceived[i];
    }

    PrintChrysanthemums(chrysanthemumsReceived, numBunches);

    /* Your code goes here */
    delete[] chrysanthemumsReceived;

    return 0;
}