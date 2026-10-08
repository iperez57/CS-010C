/*
Define a try block to:

Read vIndex from input.
Assign postalZipCode with the element at postalZipCodeVector's vIndex.
Assign foundIndex with true.
Ex: If the input is -2 13 7, then the output is:

Error: postalZipCodeVector does not have requested index
Error: postalZipCodeVector does not have requested index
Postal ZIP code is 59381 at index 7
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> postalZipCodeVector = { 19835, 58391, 89135, 51893, 91835, 15389, 89153, 59381, 93158 };
    int vIndex;
    int postalZipCode;
    bool foundIndex = false;

    while (!foundIndex) {

        /* Your code goes here */
        try
        {
            cin >> vIndex;
            postalZipCode = postalZipCodeVector.at(vIndex);
            foundIndex = true;
        }

        catch (out_of_range& excpt) {
            cout << "Error: postalZipCodeVector does not have requested index" << endl;
        }
    }

    cout << "Postal ZIP code is " << postalZipCode << " at index " << vIndex << endl;

    return 0;
}