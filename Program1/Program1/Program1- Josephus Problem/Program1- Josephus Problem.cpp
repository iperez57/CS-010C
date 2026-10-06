/*
The Josephus Problem has gruesome roots, which you can read about on Wikipedia (https://en.wikipedia.org/wiki/Josephus_problem).
Meanwhile, think of it as a game of Survivor: everyone sits in a circle and repeatedly votes out the person next to them, making the circle smaller until only one person remains and wins.
The challenge is to figure out: Who is the last person standing?

We will also add a few twists (parameters):
Let n be the number of people in the initial circle (i.e., select the first n people from a list of names as input)
Let k be the number k-th person to vote out (i.e., skip over k-1 people, and vote out the kth person)
We want you to use a circular linked list to solve this problem. The output should declare the winner, e.g., "Paea wins!"

Sample input:
5
1
Georgia
Jeremiah
Donnell
Clarice
Aurelia
Kristina
Marcy
Lyle
.
Note: Since n=5, Kristina, Marcy and Lyle are ignored. So it starts with Georgia voting out Jeremiah (k=1, i.e., skip k-1 or none). 
Then Donnell votes out Clarice. 
Next it loops around so that Aurelia votes out Georgia, and finally Donnell votes out Aurelia. 
Try it yourself on paper.

Sample output:
Donnell wins!
Note: in our version of this game, it is possible for a player to vote themselves out. 
(That's not exactly how the real Josephus Problem works.)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Node 
{
    string payload;
    Node* next;
};

Node* newNode(string payload) 
{
    /** fill in this code **/
    Node* newNode = new Node();
    newNode->payload = payload;
    newNode->next = nullptr;

    return newNode;
}

Node* loadGame(int n, vector<string> names) 
{
    Node* head = nullptr;
    Node* prev = nullptr;
    string name;

    for (int i = 0; i < n; ++i) 
    {
        name = names.at(i);
        if (head == nullptr) 
        {
            head = newNode(name); // initialize head specially
            /** fill in this code **/
            prev = head;
        }
        else 
        {
            prev->next = newNode(name);
            /** fill in this code **/
            prev = prev->next;
        }
    }

    if (prev != nullptr) 
    {
        /** fill in this code **/ // make circular
        prev->next = head;
    }
    return head;
}

void print(Node* start) { 
    // prints list
    Node* curr = start;
    while (curr != nullptr) 
    {
        cout << curr->payload << endl;
        curr = curr->next;
        if (curr == start) 
        {
            break; // exit circular list
        }
    }
}

Node* runGame(Node* start, int k) { // josephus w circular list, k = num skips
    Node* curr = start;
    Node* prev = curr;
    while (/** fill in this code **/curr != nullptr) 
    { 
        // exit condition, last person standing
        for (int i = 0; i < k; ++i) 
        {   // find kth node
            /** fill in this code**/
            prev = curr;
            curr = curr->next;
        }

        /** fill in this code **/ 
        // delete kth node
        prev->next = curr->next;
        delete curr;
        /** fill in this code **/
        curr = prev->next;
        
    }

    return curr; // last person standing
}

/* Driver program to test above functions */
int main() {
    int n = 1, k = 1, max; // n = num names; k = num skips (minus 1)
    string name;
    vector<string> names;

    // get inputs
    cin >> n >> k;
    while (cin >> name && name != ".") { names.push_back(name); } // EOF or . ends input

    // initialize and run game
    Node* startPerson = loadGame(n, names);
    Node* lastPerson = runGame(startPerson, k);

    if (lastPerson != nullptr) {
        cout << lastPerson->payload << " wins!" << endl;
    }
    else {
        cout << "error: null game" << endl;
    }

    return 0;
}

