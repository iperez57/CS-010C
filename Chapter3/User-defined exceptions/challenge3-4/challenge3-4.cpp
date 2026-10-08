/*
The user-defined DataOutOfRange class is used to handle exceptions for invalid input values. Complete the definition of the function that overrides what() as follows:

The function is virtual.
The return type is const char*.
The function name is what() without parameters.
The function returns message.c_str().
*/

#include <iostream>
using namespace std;

class DataOutOfRange : public exception {
public:
    DataOutOfRange(string exceptionMessage) {
        message = "Error: " + exceptionMessage;
    }

    virtual const char* what() {
        /* Your code goes here */return message.c_str();
    }

private:
    string message;
};

int getColorIntensity() {
    int colorIntensity;

    cin >> colorIntensity;

    if ((colorIntensity < 0) || (colorIntensity > 255)) {
        throw DataOutOfRange("Input cannot be processed");
    }
    return colorIntensity;
}

int main() {
    int colorIntensity;

    try {
        colorIntensity = getColorIntensity();

        cout << "Valid input: Color intensity is ";
        cout << colorIntensity << endl;
    }
    catch (DataOutOfRange excpt) {
        cout << excpt.what() << endl;
    }
    catch (exception& excpt) {
        cout << "Unexpected error: " << excpt.what() << endl;
    }

    return 0;
}