/*
Two integers are read from input as the radius and the height of a Cylinder object. Assign pointer cylinderPtr with a new Cylinder object using the radius and the height as arguments in that order.

Ex: If the input is 16 29, then the output is:

Cylinder's radius: 16
Cylinder's height: 29
*/

#include <iostream>
using namespace std;

class Cylinder {
public:
    Cylinder(int radiusValue, int heightValue);
    void Print();
private:
    int radius;
    int height;
};

Cylinder::Cylinder(int radiusValue, int heightValue) {
    radius = radiusValue;
    height = heightValue;
}

void Cylinder::Print() {
    cout << "Cylinder's radius: " << radius << endl;
    cout << "Cylinder's height: " << height << endl;
}

int main() {
    Cylinder* cylinderPtr = nullptr;
    int radiusVal;
    int heightVal;

    cin >> radiusVal;
    cin >> heightVal;

    /* Your code goes here */
    cylinderPtr = new Cylinder(radiusVal, heightVal);

    cylinderPtr->Print();

    delete cylinderPtr;

    return 0;
}