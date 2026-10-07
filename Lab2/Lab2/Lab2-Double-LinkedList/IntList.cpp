//IntList.cpp

#include "IntList.h"

//Constructor 
IntList::IntList()
{
	dummyHead = new IntNode(0);
	dummyTail = new IntNode(0);

	dummyHead->next = dummyTail;
	dummyTail->prev = dummyHead;
}

//Destructor
IntList::~IntList()
{
	IntNode* current = dummyHead->next;
	
	//Loops through code and deletes node until curr == dummyTail
	while (current != dummyTail)
	{
		IntNode* temp = current;
		current = current->next;
		delete temp;
	}
	//deletes the dummy head and dummy tail
	delete dummyHead;
	delete dummyTail;
}

//adds node to the front
void IntList::push_front(int value)
{
	//creates new node with int value
	IntNode* newNode = new IntNode(value);
	
	//assigns next and previous pointers to node after dummy head
	//assigns prev to dummy head
	newNode->next = dummyHead->next;
	newNode->prev = dummyHead;

	//changes dummy heads next prev and dummy heads next pointers
	dummyHead->next->prev = newNode;
	dummyHead->next = newNode;
}

//removes item at the front of the list
void IntList::pop_front()
{
	//if list is empty
	if (dummyHead->next == dummyTail)
	{
		return;
	}


	IntNode* successor = dummyHead->next->next;

		successor->prev = dummyHead;
		delete dummyHead->next;
		dummyHead->next = successor;
}

//adds node to the back of the list
void IntList::push_back(int value)
{
	IntNode* newNode = new IntNode(value);
	newNode->next = dummyTail;
	newNode->prev = dummyTail->prev;

	dummyTail->prev->next = newNode;
	dummyTail->prev = newNode;
}

//removes node at the end of the list
void IntList::pop_back()
{
	//check if list is empty
	if (dummyTail->prev == dummyHead)
	{
		return;
	}

	IntNode* predecessor = dummyTail->prev->prev;

		predecessor->next = dummyTail;
		delete dummyTail->prev;
		dummyTail->prev = predecessor;
}

//overloads << operator
ostream& operator<<(ostream& out, const IntList& rhs)
{
	IntNode* current = rhs.dummyHead->next;
	
	//loops until current == rhs.dummyTail
	while (current != rhs.dummyTail)
	{
		out << current->data;

		if (current->next != rhs.dummyTail)
		{
			out << " ";
		}
		current = current->next;
	}
	return out;
}