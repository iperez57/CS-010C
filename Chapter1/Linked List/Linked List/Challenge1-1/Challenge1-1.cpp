/*
Two integers, babies1 and babies2, are read from input as the number of babies of two hares. headObj has the default value of -1. Create a new node firstHare with integer babies1 and insert firstHare after headObj. Then, create a second node secondHare with integer babies2 and insert secondHare after firstHare.

Ex: If the input is 24 27, then the output is:

-1
24
27

*/

#include <iostream>
using namespace std;

class HareNode {
public:
    HareNode(int babiesInit = 0, HareNode* nextLoc = nullptr);
    void InsertAfter(HareNode* nodeLoc);
    HareNode* GetNext();
    void PrintNodeData();
private:
    int babiesVal;
    HareNode* nextNodePtr;
};

HareNode::HareNode(int babiesInit, HareNode* nextLoc) {
    this->babiesVal = babiesInit;
    this->nextNodePtr = nextLoc;
}

void HareNode::InsertAfter(HareNode* nodeLoc) {
    HareNode* tmpNext = nullptr;

    tmpNext = this->nextNodePtr;
    this->nextNodePtr = nodeLoc;
    nodeLoc->nextNodePtr = tmpNext;
}

HareNode* HareNode::GetNext() {
    return this->nextNodePtr;
}

void HareNode::PrintNodeData() {
    cout << this->babiesVal << endl;
}

int main() {
    HareNode* headObj = nullptr;
    HareNode* firstHare = nullptr;
    HareNode* secondHare = nullptr;
    HareNode* currHare = nullptr;
    int babies1;
    int babies2;

    cin >> babies1;
    cin >> babies2;

    headObj = new HareNode(-1);

    /* Your code goes here */
    firstHare = new HareNode(babies1);
    headObj->InsertAfter(firstHare);

    secondHare = new HareNode(babies2);
    firstHare->InsertAfter(secondHare);

    currHare = headObj;
    while (currHare != nullptr) {
        currHare->PrintNodeData();
        currHare = currHare->GetNext();
    }

    return 0;
}