/*
Assign pointer myCylinder with a new Cylinder object. Call myCylinder's Read() to read the object's data members from input. Then, call myCylinder's Print() to output the values of the data members. Finally, delete myCylinder.

Ex: If the input is 3.0 7.0, then the output is:

Cylinder's radius: 3.0
Cylinder's height: 7.0
*/

//#include "memtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Cylinder {
public:
    Cylinder();
    void Read();
    void Print();
private:
    double radius;
    double height;
};

Cylinder::Cylinder() {
    radius = 0.0;
    height = 0.0;
}

void Cylinder::Read() {
    cin >> radius;
    cin >> height;
}

void Cylinder::Print() {
    cout << "Cylinder's radius: " << fixed << setprecision(1) << radius << endl;
    cout << "Cylinder's height: " << fixed << setprecision(1) << height << endl;
}

int main() {
    Cylinder* myCylinder = nullptr;

    /* Your code goes here */
    myCylinder = new Cylinder();
    myCylinder->Read();
    myCylinder->Print();

    delete myCylinder;

   // memtest(); // Check memory for testing purposes only

    return 0;
}