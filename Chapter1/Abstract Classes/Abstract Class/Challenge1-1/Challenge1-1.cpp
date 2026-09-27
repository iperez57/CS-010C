#include "Animal.h"
#include "Domestic.h"
using namespace std;

int main() {
	Domestic myDomestic = Domestic("Fuzzy", 3, "Hans");

	myDomestic.printInfo();
}