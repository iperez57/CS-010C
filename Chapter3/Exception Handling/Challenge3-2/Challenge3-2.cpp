/*
* Surround the three statements between Begin your try block here  and  End your try block here  in a try block, so that the block exits if an exception is thrown when accessing an invalid index of packageWeightVector.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> packageWeightVector = { 33, 20, 24, 29, 45, 50, 32, 26 };
    int dataIndex;
    int packageWeight;

    /* Begin your try block here */
    try
    {

        cin >> dataIndex;
        packageWeight = packageWeightVector.at(dataIndex);
        cout << "Package's weight (in g): " << packageWeight << " at index " << dataIndex << endl;
    }
    /* End your try block here */

    catch (out_of_range& excpt) {
        cout << "Error: packageWeightVector does not have requested index" << endl;
    }

    return 0;
}