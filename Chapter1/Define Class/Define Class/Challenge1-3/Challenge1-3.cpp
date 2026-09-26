/*
In the Patient class, declare the following public member functions:

SetName() with one string parameter
SetHeight() with one double parameter
and the following private data members:

string name
double height
Ex: If the input is Bandile 7.5, then the output is:

Name: Bandile
Height: 7.5
*/

#include <iostream>
using namespace std;

class Patient {
public:
    string GetName();
    double GetHeight();
    /* Member function declarations go here */
    void SetName(string customName);
    void SetHeight(double customHeight);
private:
    /* Data members go here */
    string name;
    double height;
};

void Patient::SetName(string customName) {
    name = customName;
}

void Patient::SetHeight(double customHeight) {
    height = customHeight;
}

string Patient::GetName() {
    return name;
}

double Patient::GetHeight() {
    return height;
}

int main() {
    Patient patient1;
    string inputName;
    double inputHeight;

    cin >> inputName;
    cin >> inputHeight;

    patient1.SetName(inputName);
    patient1.SetHeight(inputHeight);

    cout << "Name: " << patient1.GetName() << endl;
    cout << "Height: " << patient1.GetHeight() << endl;

    return 0;
}