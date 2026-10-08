/*
The user-defined InvalidMoneyValue class is used to handle exceptions for invalid input values. Complete the following tasks:

Define the InvalidMoneyValue class constructor with one string parameter named exceptionMessage.
In the constructor, assign the message variable with "Error: " + exceptionMessage.
*/

#include <iostream>
using namespace std;

class InvalidMoneyValue : public exception {
public:
    /* Your code goes here */
    InvalidMoneyValue(string exceptionMessage)
    {
        cout << "Error: " << exceptionMessage << endl;
    }

    virtual const char* what() {
        return message.c_str();
    }

private:
    string message;
};

int checkTotalCents() {
    int numCents;

    cin >> numCents;

    if (numCents % 25 != 0) {
        throw InvalidMoneyValue("Amount cannot be converted to quarters");
    }
    return numCents;
}

int main() {
    int numCents;

    try {
        numCents = checkTotalCents();

        cout << "Valid input: " << numCents << " cents = " << (numCents / 25);
        cout << " quarters" << endl;
    }
    catch (InvalidMoneyValue excpt) {
        cout << excpt.what() << endl;
    }
    catch (exception& excpt) {
        cout << "Unexpected error: " << excpt.what() << endl;
    }

    return 0;
}