/*
Write a catch block to catch an out_of_range exception,
and output "Error: luggageWeightVector index invalid" followed by a newline.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> luggageWeightVector = { 40, 29, 44, 27, 23, 31, 28, 20, 26, 41, 35 };
    int vectorIndex;
    int luggageWeight;

    try {
        cin >> vectorIndex;
        luggageWeight = luggageWeightVector.at(vectorIndex);
        cout << "Luggage's weight (in g) is " << luggageWeight << " at index " << vectorIndex << endl;
    }

    /* Your code goes here */
    catch (out_of_range excpt)
    {
        cout << "Error: luggageWeightVector index invalid" << endl;
    }

    return 0;
}