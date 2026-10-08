/*
Surround the three statements between  Begin your try block here  and  End your try block here  in a try block.Then,
write a catch block to catch an out_of_range exception,
and output "Error: Bad index for yearOfBirthVector" followed by a newline.

Ex: If the input is - 5 12 4, then the output is :

Error: Bad index for yearOfBirthVector
Error : Bad index for yearOfBirthVector
Year of birth is 1939 at index 4
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> yearOfBirthVector = { 1903, 1989, 1919, 1959, 1939, 1948, 1958, 1950, 2020, 1976 };
    int vIndex;
    int yearOfBirth;
    bool acceptedIndex = false;

    while (!acceptedIndex) {

        /* Begin your try block here */
        try
        {


            cin >> vIndex;
            yearOfBirth = yearOfBirthVector.at(vIndex);
            acceptedIndex = true;

            /* End your try block here */
        }

        /* Your catch block goes here */
        catch (out_of_range excpt)
        {
            cout << "Error: Bad index for yearOfBirthVector" << endl;
        }
    }

    cout << "Year of birth is " << yearOfBirth << " at index " << vIndex << endl;

    return 0;
}