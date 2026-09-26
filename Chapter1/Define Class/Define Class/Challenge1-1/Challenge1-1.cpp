/*
Organize the code statements to print person1's kids, apply the IncNumKids() function to increment person1's number of kids, and print again, outputting text as below.

Ex: If the input is 3, then the output is:

Kids: 3

New baby, kids now: 4
*/

#include <iostream>
using namespace std;

class PersonInfo
{
public: 
	void SetNumKids(int personKidsToSet);
	void IncNumKids();
	int GetNumKids() const;
private:
	int numKids;
};

void PersonInfo::SetNumKids(int personsKidsToSet)
{
	numKids = personsKidsToSet;
}

void PersonInfo::IncNumKids()
{
	numKids = numKids + 1;
}

int PersonInfo::GetNumKids() const
{
	return numKids;
}

int main()
{
	PersonInfo person1;
	int personKids;

	cin >> personKids;
	person1.SetNumKids(personKids);
	cout << "Kids: " << person1.GetNumKids() << endl;
	person1.IncNumKids(); 
	cout << "New Baby, kids now: " << person1.GetNumKids() << endl;
	return 0;
}