/*
Write ComputeSum()'s base case to output " = ", followed by sum and a newline, if arg is less than or equal to 4.
*/

#include <iostream>
using namespace std;

void ComputeSum(int arg, int sum) {
	cout << arg;
	sum = sum + arg;

	/* Your code goes here */
	if (arg <= 4)
	{
		cout << " = " << sum << endl;
	}

	else {
		cout << " + ";
		ComputeSum(arg - 4, sum);
	}
}

int main() {
	int arg;

	cin >> arg;
	ComputeSum(arg, 0);

	return 0;
}