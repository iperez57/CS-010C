/*
In the OccupancyPercentage class, when an input value is invalid, throw a user-defined InvalidOccupancy exception as follows:

Start a throw statement with throw.
Call the InvalidOccupancy() constructor with the message "Entered occupancy percentage is invalid" as the argument.
*/

#include <iostream>
using namespace std;

class InvalidOccupancy : public exception {
public:
    InvalidOccupancy(string exceptionMessage) {
        message = "Error: " + exceptionMessage;
    }
    virtual const char* what() {
        return message.c_str();
    }
private:
    string message;
};

int getOccupancyPercentage() {
    int occupancyPercentage;

    cin >> occupancyPercentage;

    if ((occupancyPercentage < 0) || (occupancyPercentage > 100)) {

        /* Your code goes here */
        throw(InvalidOccupancy("Entered occupancy percentage is invalid"));

    }
    return occupancyPercentage;
}

int main() {
    int occupancyPercentage;

    try {
        occupancyPercentage = getOccupancyPercentage();

        cout << "Valid input: Occupancy percentage is ";
        cout << occupancyPercentage << endl;
    }
    catch (InvalidOccupancy excpt) {
        cout << excpt.what() << endl;
    }
    catch (exception& excpt) {
        cout << "Unexpected error: " << excpt.what() << endl;
    }

    return 0;
}