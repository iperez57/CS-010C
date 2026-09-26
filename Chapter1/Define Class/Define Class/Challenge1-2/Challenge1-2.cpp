/*
In the SailorLicense class, complete the function definition for SetYear() with the integer parameter newYear.

Ex: If the input is 33 835 2011, then the output is:

License fee: 33
License id: 835
License year: 2011
*/

#include <iostream>
using namespace std;

class SailorLicense {
public:
	void SetFee(int newFee);
	void SetId(int newId);
	void SetYear(int newYear);
	int GetFee();
	int GetId();
	int GetYear();
private:
	int fee;
	int id;
	int year;
};

void SailorLicense::SetFee(int newFee) {
	fee = newFee;
}

void SailorLicense::SetId(int newId) {
	id = newId;
}
void SailorLicense::SetYear(int newYear)
/* Your code goes here */ {
	year = newYear;
}

int SailorLicense::GetFee() {
	return fee;
}

int SailorLicense::GetId() {
	return id;
}

int SailorLicense::GetYear() {
	return year;
}

int main() {
	SailorLicense sailor1;
	int inputFee;
	int inputId;
	int inputYear;

	cin >> inputFee;
	cin >> inputId;
	cin >> inputYear;

	sailor1.SetFee(inputFee);
	sailor1.SetId(inputId);
	sailor1.SetYear(inputYear);

	cout << "License fee: " << sailor1.GetFee() << endl;
	cout << "License id: " << sailor1.GetId() << endl;
	cout << "License year: " << sailor1.GetYear() << endl;

	return 0;
}