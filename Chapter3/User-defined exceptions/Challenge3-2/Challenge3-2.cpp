/*
The user-defined InvalidValue class is used to handle exceptions for invalid input values. Complete the definition of the public InvalidValue class as follows:

The type is class.
The class name is InvalidValue.
The class is public.
The base class is exception.
*/

#include <iostream>
using namespace std;

class InvalidValue : public exception/* Your code goes here */ {
public:
    InvalidValue(string exceptionMessage) {
        message = "Error: " + exceptionMessage;
    }
    virtual const char* what() {
        return message.c_str();
    }
private:
    string message;
};

int checkTotalEggs() {
    int numEggs;

    cin >> numEggs;

    if (numEggs % 12 != 0) {
        throw InvalidValue("Number of eggs must be divisible by 12");
    }
    return numEggs;
}

int main() {
    int numEggs;

    try {
        numEggs = checkTotalEggs();

        cout << "Valid input: " << numEggs << " eggs = " << (numEggs / 12);
        cout << " cartons of a dozen" << endl;
    }
    catch (InvalidValue excpt) {
        cout << excpt.what() << endl;
    }
    catch (exception& excpt) {
        cout << "Unexpected error: " << excpt.what() << endl;
    }

    return 0;
}