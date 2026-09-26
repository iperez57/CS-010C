/*
A smiley is a colon combined with a parenthesis to represent a smiling face. Ex: Both :) and (: are smileys. Organize the code statements to complete the recursive PrintSmiley() function. The function outputs n smileys on both sides of the word "happy".

Ex: If the input is 4, then the output is:

(:(:(:(: happy :):):):)
*/

#include <iostream>
using namespace std;

void PrintSmiley(int n)
{
	if (n == 0)
	{
		cout << " happy ";

	}

	else {
		cout << "(:";
		PrintSmiley(n - 1);
		cout << ":)";
	}
}

int main()
{
	int numSmiles;

	cin >> numSmiles;
	PrintSmiley(numSmiles);

	return 0;
}