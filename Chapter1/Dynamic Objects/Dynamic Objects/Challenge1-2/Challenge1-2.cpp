/*
Two doubles are read from input as the voltage and the current of a Circuit object. Declare and assign pointer circuitPtr with a new Circuit object using the voltage and the current as arguments in that order. Then, call circuitPtr's IncreaseVoltageAndCurrent() member function.

Ex: If the input is 3.5 2.0, then the output is:

Circuit's voltage and current are increased.
Circuit's voltage: 21.0
Circuit's current: 12.0
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Circuit {
public:
    Circuit(double voltageValue, double currentValue);
    void IncreaseVoltageAndCurrent();
    void Print();
private:
    double voltage;
    double current;
};

Circuit::Circuit(double voltageValue, double currentValue) {
    voltage = voltageValue;
    current = currentValue;
}

void Circuit::IncreaseVoltageAndCurrent() {
    voltage = voltage * 6.0;
    current = current * 6.0;
    cout << "Circuit's voltage and current are increased." << endl;
}

void Circuit::Print() {
    cout << "Circuit's voltage: " << fixed << setprecision(1) << voltage << endl;
    cout << "Circuit's current: " << fixed << setprecision(1) << current << endl;
}

int main() {

    /* Additional variable declarations go here */
    Circuit* circuitPtr = nullptr;

    double voltageInput;
    double currentInput;

    cin >> voltageInput;
    cin >> currentInput;

    /* Your code goes here */
    circuitPtr = new Circuit(voltageInput, currentInput);
    circuitPtr->IncreaseVoltageAndCurrent();


    circuitPtr->Print();

    delete circuitPtr;

    return 0;
}