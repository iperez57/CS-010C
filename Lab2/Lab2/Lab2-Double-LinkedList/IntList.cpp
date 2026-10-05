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