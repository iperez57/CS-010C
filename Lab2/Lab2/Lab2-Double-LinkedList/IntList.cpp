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
	IntNode* successor = dummyHead->next->next;

	if (dummyHead->next == dummyTail)
	{
		return;
	}

	if (successor != nullptr)
	{
		successor->prev = dummyHead;
		delete dummyHead->next;
		dummyHead->next = successor;
	}
	
}