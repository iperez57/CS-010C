/*
Write SumSequence()'s recursive case to:

Output val followed by " + ".
Recursively call SumSequence() with val - 1.
Return val added to the return value of the recursive call.
*/

#include <iostream>
using namespace std;

int SumSequence(int val) {
	if (val <= 1) {
		cout << val;
		return val;
	}

	/* Your code goes here */
	else
	{
		cout << val << " + ";
		val += SumSequence(val - 1);
	}
	return val;
}

int main() {
	int val;
	int sum;

	cin >> val;
	sum = SumSequence(val);
	cout << " = " << sum << endl;

	return 0;
}