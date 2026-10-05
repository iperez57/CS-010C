//IntList.cpp

#include "IntList.h"

IntList::IntList()
{
	dummyHead = new IntNode(0);
	dummyTail = new IntNode(0);

	dummyHead->next = dummyTail;
	dummyTail->prev = dummyHead;
}

IntList::~IntList()
{
	IntNode* current = dummyHead->next;
	
	while (current != dummyTail)
	{
		IntNode* temp = current;
		current = current->next;
		delete temp;
	}
	delete dummyHead;
	delete dummyTail;
}

void IntList::push_front(int value)
{
	IntNode* newNode = new IntNode(value);
	
	newNode->next = dummyHead->next;
	newNode->prev = dummyHead;

	dummyHead->next->prev = newNode;
	dummyHead->next = newNode;
}

void IntList::pop_front()
{

	if (dummyHead->next == dummyTail)
	{
		return;
	}
	IntNode* successor = dummyHead->next->next;

	if (successor != nullptr)
	{
		successor->prev = dummyHead;
		delete dummyHead->next;
		dummyHead->next = successor;
	}
}

void IntList::push_back(int value)
{
	IntNode* newNode = new IntNode(value);
	newNode->next = dummyTail;
	newNode->prev = dummyTail->prev;

	dummyTail->prev->next = newNode;
	dummyTail->prev = newNode;
}

void IntList::pop_back()
{
	if (dummyTail->prev == dummyHead)
	{
		return;
	}
	IntNode* predecessor = dummyTail->prev->prev;

	if (predecessor != nullptr)
	{
		predecessor->next = dummyTail;
		delete dummyTail->prev;
		dummyTail->prev = predecessor;
	}
}

ostream& operator<<(ostream& out, const IntList& rhs)
{
	IntNode* current = rhs.dummyHead->next;
	
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