#include "Heap.h"
#include <iostream>
using namespace std;

Heap::Heap()
{
    numItems = 0;
}

void Heap::enqueue(PrintJob* print)
{
    //check if limit is reached
    if (numItems == MAX_HEAP_SIZE)
    {
        return;
    }

    arr[numItems] = print;
    int current = numItems;
    numItems++;

    while (current > 0)
    {
        int parent = (current - 1) / 2;

        if (arr[current]->getPriority() > arr[parent]->getPriority())
        {
            PrintJob* temp = arr[current];
            arr[current] = arr[parent];
            arr[parent] = temp;

            current = parent;
        }
        else
        {
            return;
        }
    }
}

PrintJob* Heap::highest()
{
    if (numItems == 0)
    {
        return nullptr;
    }
    //return item in first spot
    return arr[0];
}

void Heap::print()
{
    if (numItems == 0)
    {
        return;
    }

    cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;
}

void Heap::dequeue()
{
    if (numItems == 0)
    {
        return;
    }

    //replace first item with last item
    arr[0] = arr[numItems - 1];
    numItems--;
    //call trickledown
    trickleDown(0);
}

void Heap::trickleDown(int nodeIndex)
{
    if (numItems == 0)
    {
        return;
    }

    int childIndex = 2 * nodeIndex + 1;
    PrintJob* value = arr[nodeIndex];

    while (childIndex < numItems)
    {
        //find max among node and children
        PrintJob* maxValue = value;
        int maxIndex = -1;

        for (int i = 0; i < 2 && i + childIndex < numItems; i++)
        {
            if (arr[i + childIndex]->getPriority() > maxValue->getPriority())
            {
                maxValue = arr[i + childIndex];
                maxIndex = i + childIndex;
            }
        }

        if (maxValue == value)
        {
            return;
        }

        else
        {
            arr[nodeIndex] = arr[maxIndex];
            arr[maxIndex] = value;

            nodeIndex = maxIndex;
            childIndex = 2 * nodeIndex + 1;
        }
    }
}