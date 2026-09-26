/*
Integer beeCount is read from input as the number of input values that follow. The node headBee is created with the value of beeCount. Use cin to read beeCount integers. Insert a BeeNode for each integer at the end of the linked list.

Ex: If the input is 3 49 59 65, then the output is:

3
49
59
65
*/

#include <iostream>
using namespace std;

class BeeNode {
public:
    BeeNode(int babiesInit = 0, BeeNode* nextLoc = nullptr);
    void InsertAfter(BeeNode* nodeLoc);
    BeeNode* GetNext();
    void PrintNodeData();
private:
    int babiesVal;
    BeeNode* nextNodePtr;
};

BeeNode::BeeNode(int babiesInit, BeeNode* nextLoc) {
    this->babiesVal = babiesInit;
    this->nextNodePtr = nextLoc;
}

void BeeNode::InsertAfter(BeeNode* nodeLoc) {
    BeeNode* tmpNext = nullptr;

    tmpNext = this->nextNodePtr;
    this->nextNodePtr = nodeLoc;
    nodeLoc->nextNodePtr = tmpNext;
}

BeeNode* BeeNode::GetNext() {
    return this->nextNodePtr;
}

void BeeNode::PrintNodeData() {
    cout << this->babiesVal << endl;
}

int main() {
    BeeNode* headBee = nullptr;
    BeeNode* currBee = nullptr;
    BeeNode* lastBee = nullptr;
    int beeCount;
    int inputValue;
    int i;

    cin >> beeCount;

    headBee = new BeeNode(beeCount);
    lastBee = headBee;

    /* Your code goes here */
    for (i = 0; i < beeCount; i++)
    {
        cin >> inputValue;
        currBee = new BeeNode(inputValue);
        lastBee->InsertAfter(currBee);
        lastBee = currBee;
    }

    currBee = headBee;
    while (currBee != nullptr) {
        currBee->PrintNodeData();
        currBee = currBee->GetNext();
    }

    return 0;
}