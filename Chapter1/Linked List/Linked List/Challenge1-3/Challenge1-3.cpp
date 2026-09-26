/*
Multiple integers, representing the number of babies, are read from input and inserted into a linked list of RabbitNodes. For each integer greater than or equal to 9 in the linked list of RabbitNodes, output the integer followed by " is a large quantity of babies." on a new line.

Ex: If the input is 2 20 10, then the output is:

20 is a large quantity of babies.
10 is a large quantity of babies.
*/

#include <iostream>
using namespace std;

class RabbitNode {
public:
    RabbitNode(int babiesInit = 0, RabbitNode* nextLoc = nullptr);
    void InsertAfter(RabbitNode* nodeLoc);
    RabbitNode* GetNext();
    int GetNodeData();
private:
    int babiesVal;
    RabbitNode* nextNodePtr;
};

RabbitNode::RabbitNode(int babiesInit, RabbitNode* nextLoc) {
    this->babiesVal = babiesInit;
    this->nextNodePtr = nextLoc;
}

void RabbitNode::InsertAfter(RabbitNode* nodeLoc) {
    RabbitNode* tmpNext = nullptr;

    tmpNext = this->nextNodePtr;
    this->nextNodePtr = nodeLoc;
    nodeLoc->nextNodePtr = tmpNext;
}

RabbitNode* RabbitNode::GetNext() {
    return this->nextNodePtr;
}

int RabbitNode::GetNodeData() {
    return this->babiesVal;
}

int main() {
    RabbitNode* headRabbit = nullptr;
    RabbitNode* currRabbit = nullptr;
    RabbitNode* lastRabbit = nullptr;
    int count;
    int inputValue;
    int i;

    cin >> count;

    headRabbit = new RabbitNode(count);
    lastRabbit = headRabbit;

    for (i = 0; i < count; ++i) {
        cin >> inputValue;

        currRabbit = new RabbitNode(inputValue);

        lastRabbit->InsertAfter(currRabbit);
        lastRabbit = currRabbit;
    }

    /* Your code goes here */
    currRabbit = headRabbit;

    while (currRabbit != nullptr)
    {
        if (currRabbit->GetNodeData() >= 9)
        {
            cout << currRabbit->GetNodeData() << " is a large quantity of babies." << endl;
        }
        currRabbit = currRabbit->GetNext();
    }

    return 0;
}
