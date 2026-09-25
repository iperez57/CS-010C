/*
Organize the code blocks to complete the following tasks:

Dynamically allocate an array of HeartBeat objects with a size of numReadings read from input, and assign heartBeatReadings with the array.
For each object in heartBeatReadings:
Initialize the object's data members with values read from input.
Assign averageBPM with the return value of each object's CalculateAverage().
Output averageBPM using each object's PrintBPM() function.
Output "Readings complete" and deallocate heartBeatReadings.
*/

#include <iostream>
using namespace std;

class HeartBeat
{
public:
	HeartBeat(int restingBPM = 0, int activeBPM = 0);
	void Set(int restingBPM, int activeBPM);
	void PrintBPM(int valueBPM);
	int CalculateAverage();

private:
	int resting;
	int active

};

HeartBeat::HeartBeat(int restingBPM, int activeBPM)
{
	resting = restingBPM;
	active = activeBPM;
}

int HeartBeat::CalculateAverage()
{
	return ((active + resting) / 2);
}

void HeartBeat::PrintBPM(int valueBPM)
{
	cout << valueBPM << " beats/minute" << endl;
}

int main()
{
	HeartBeat* heartBeatReading;
	int numReading;
	int restingInput;
	int activeInput;
	int averageBPM;

	cin >> numReading;

	heartBeatReading = new HeartBeat[numReading];

	for (int i = 0; i < numReading; i++)
	{
		cin >> activeInput;
		cin >> restingInput;

		heartBeatReading[i].Set(restingInput, activeInput);
		averageBPM = heartBeatReading[i].CalculateAverage();
		heartBeatReading[i].PrintBPM(averageBPM);
	}

	cout << "Readings complete" << endl;

	return 0;
}