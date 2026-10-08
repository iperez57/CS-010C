/*
The while loop makes up to two attempts to read an integer divisible by 2 from input into numDancers.

Write a catch block to catch exceptions of type invalid_argument thrown. In the catch block:
Output "Bad input: " followed by the message of the invalid_argument exception.
Assign attemptsLeft with 0.
Then, write another catch block to catch exceptions of type runtime_error thrown. In the catch block:
Output the message of the runtime_error exception.
Subtract 1 from attemptsLeft.
End each output with a newline.
*/

#include <iostream>
using namespace std;

int main() {
    int numDancers;
    int attemptsLeft = 2;

    while (attemptsLeft > 0) {
        cout << "Attempts left: " << attemptsLeft << endl;

        try {
            cin >> numDancers;

            if (numDancers < 0) {
                throw invalid_argument("Invalid number of dancers");
            }

            if (numDancers % 2 != 0) {
                throw runtime_error("Dancers cannot be paired");
            }

            attemptsLeft = 0;
            cout << "Valid input: ";
            cout << numDancers << " dancers form " << (numDancers / 2) << " pairs" << endl;
        }

        /* Your code goes here */
        catch (invalid_argument& excpt)
        {
            cout << "Bad input: " << excpt.what() << endl;
            attemptsLeft = 0;
        }
        catch (runtime_error& excpt)
        {
            cout << excpt.what() << endl;
            attemptsLeft--;
        }

    }
}