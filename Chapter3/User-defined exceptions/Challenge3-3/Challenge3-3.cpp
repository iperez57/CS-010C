/*
The user-defined UnrecognizedInput class is used to handle exceptions for invalid input values. 
The public UnrecognizedInput class constructor assigns the message variable with an exception message.
Complete the definition of the public UnrecognizedInput class constructor with one string parameter named exceptionMessage.
*/

#include <iostream>
using namespace std;

class UnrecognizedInput : public exception {
public:
    UnrecognizedInput(string exceptionMessage)/* Your code goes here */ {
        message = "Error: " + exceptionMessage;
    }

    virtual const char* what() {
        return message.c_str();
    }
private:
    string message;
};

int checkPairsOfSocks() {
    int numSocks;

    cin >> numSocks;

    if (numSocks % 2 != 0) {
        throw UnrecognizedInput("Socks cannot be paired");
    }
    return numSocks;
}

int main() {
    int numSocks;

    try {
        numSocks = checkPairsOfSocks();

        cout << "Valid input: " << numSocks << " socks form " << (numSocks / 2);
        cout << " pairs" << endl;
    }
    catch (UnrecognizedInput excpt) {
        cout << excpt.what() << endl;
    }
    catch (exception& excpt) {
        cout << "Unexpected error: " << excpt.what() << endl;
    }

    return 0;
}