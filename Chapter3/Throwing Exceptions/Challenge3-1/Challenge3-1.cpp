#include <iostream>
using namespace std;

int main() {
    int numWheels;

    try {
        cin >> numWheels;

        if (numWheels % 4 != 0) {
            throw runtime_error("Error: The number of wheels must be divisible by 4")/* Your code goes here */;
        }

        cout << "Valid input: ";
        cout << numWheels << " wheels can make " << (numWheels / 4) << " automobiles" << endl;
    }
    catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
    }

    return 0;
}