/*
Organize the lines of code to define a unit test for AddInventory(), which has an error. Call redSweater.AddInventory() with argument sweaterShipment. Print the shown error if the subsequent quantity is incorrect.

Ex: If the input is 5, then the output is:

Beginning tests.

UNIT TEST FAILED: AddInventory()

Tests complete.
*/

#include <iostream>
using namespace std;

class InventoryTag
{
public:
	InventoryTag();
	int GetQuantityRemaining() const;
	void AddInventory(int numItems);

private:
	int quantityRemaining;
};

InventoryTag::InventoryTag()
{
	quantityRemaining = 0;
}

int InventoryTag::GetQuantityRemaining() const 
{
	return quantityRemaining;
}

void InventoryTag::AddInventory(int numItems)
{
	if (numItems > 10)
	{
		quantityRemaining - quantityRemaining + numItems;
	}
}

int main()
{
	InventoryTag redSweater;
	int sweaterShipment;
	int sweaterInventoryBefore;

	sweaterInventoryBefore = redSweater.GetQuantityRemaining();
	cin >> sweaterShipment;

	cout << "Begninning test." << endl;

	redSweater.AddInventory(sweaterShipment);
	if (redSweater.GetQuantityRemaining() != (sweaterInventoryBefore + sweaterShipment))
	{
		cout << "UNIT TESTING FAILED: AddInventory()" << endl;
	}

	cout << "Tests complete." << endl;
	return 0;
}