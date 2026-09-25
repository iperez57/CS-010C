//The stream inFS is associated with a file that contains the number of sofas sold by a furniture store.A while loop outputs each value read from the file and subtracts the value from remainingSofas.Complete the following missing parts in the while loop:
//Iterate while inFS.fail() is false.
//Read integer sofaQuantity from inFS.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream inFS;
	string sofaFileName;
	int sofaQuantity;
	int remainingSofas;

	cin >> sofaFileName;

	inFS.open(sofaFileName);
	if (!inFS.is_open()) {
		cout << sofaFileName << ": could not be opened" << endl;
		return 1;
	}

	remainingSofas = 260;

	cout << "Started with: " << remainingSofas << endl;

	inFS >> sofaQuantity;

	while (/* Put the condition here */ !inFS.fail()) {
		cout << sofaQuantity << endl;
		remainingSofas = remainingSofas - sofaQuantity;
		/* Read sofaQuantity from inFS here */
		inFS >> sofaQuantity;
	}

	if (inFS.eof()) {
		cout << "Reached end of file" << endl;
	}
	else {
		cout << "Read operation failed" << endl;
	}

	cout << "Unsold: " << remainingSofas << endl;

	inFS.close();

	return 0;
}