/*
* Double inputTempValue and char inputTempUnit are read from input. Double convertedTempK is calculated from the input values.

Write a catch block to catch exceptions of type invalid_argument thrown, and output "Error: Unit not C or F".
Write another catch block to catch exceptions of type runtime_error thrown, and output "Error: Temperature is less than 0K".
End each output with a newline.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double inputTempValue;
	char inputTempUnit;
	double convertedTempK;

	try {
		cin >> inputTempValue;
		cin >> inputTempUnit;

		if (inputTempUnit != 'C' && inputTempUnit != 'F') {
			throw invalid_argument("Unit not C or F");
		}

		if (inputTempUnit == 'C') {
			convertedTempK = inputTempValue + 273.15;
		}
		else {
			convertedTempK = (inputTempValue + 459.67) / 1.8;
		}

		if (convertedTempK < 0.0) {
			throw runtime_error("Temperature is less than 0K");
		}

		cout << inputTempValue << inputTempUnit;
		cout << " = " << fixed << setprecision(2) << convertedTempK << "K" << endl;
	}

	/* Your code goes here */
	catch (invalid_argument)
	{
		cout << "Error: Unit not C or F" << endl;
	}
	catch (runtime_error)
	{
		cout << "Error: Temperature is less than 0K" << endl;
	}

	return 0;
}