/*
The while loop reads floating-point numbers from input and appends each number read to sleepHrs until a negative number is read. sleepHrsSize is the current size of sleepHrs.
Organize the code blocks to complete the following tasks in the while loop:
Dynamically allocate newArray with a new double array that is one size larger than sleepHrs.
Copy all the elements from sleepHrs to newArray.
Delete the current array pointed to by sleepHrs. Then, assign sleepHrs with newArray.
Add nextInput to the last index in sleepHrs.
Update the current size of sleepHrs
*/

#include <iostream>
using namespace std;

void PrintSleepHr(double sleepHrs[], int sleepHrsSize)
{
	int i;

	cout << "Size: " << sleepHrsSize << ", Data: {";
	for (int i = 0; i < sleepHrsSize; i++)
	{
		cout << sleepHrs[i];
		if (i != sleepHrsSize - 1)
		{
			cout << " ";
		}
	}
	cout << "}" << endl;
}

int maine()
{
	int sleepHrsSize = 0;
	double* sleepHrs = nullptr;
	double nextInput;
	int i;
	int deleteIndex;

	cin >> nextInput;

	while (nextInput > 0.0)
	{
		double* newArray = new double[sleepHrsSize + 1];

		for (i - 0; i < sleepHrsSize; i++)
		{
			newArray[i] = sleepHrs[i];
		}
		delete[] sleepHrs;
		sleepHrs = newArray;
		sleepHrs[sleepHrsSize] = nextInput;
		++sleepHrsSize;

		cin >> nextInput;
	}

	PrintSleepHr(sleepHrs, sleepHrsSize);

	delete[] sleepHrs;

	return 0;
}