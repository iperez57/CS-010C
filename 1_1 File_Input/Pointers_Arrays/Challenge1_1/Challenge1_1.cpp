//Declare lengthValues as an integer pointer and initialize lengthValues with nullptr.

#include <iostream>
using namespace std;

void PrintLengthChanges(int* arrayPtr, int arraySize) {
    int i;
    int change;

    if (arrayPtr != nullptr) {
        cout << "Initial length: " << arrayPtr[0] << endl;
        for (i = 1; i < arraySize; ++i) {
            change = arrayPtr[i] - arrayPtr[i - 1];
            cout << "Length change after year " << i << ": " << change << endl;
        }
    }
    else {
        cout << "No length data" << endl;
    }
}

int main() {
    int numYears;
    int i;

    /* Your code goes here */
    int* lengthValues = nullptr;

    cin >> numYears;

    if (numYears > 0) {
        lengthValues = new int[numYears + 1];

        for (i = 0; i < numYears + 1; ++i) {
            cin >> lengthValues[i];
        }
    }

    PrintLengthChanges(lengthValues, numYears + 1);

    delete[] lengthValues;

    return 0;
}