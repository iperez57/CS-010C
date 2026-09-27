#include <string>
#include <iostream>
using namespace std;

class Domestic : public Animal {
private:
    string owner;

public:
    Domestic(string domesticName, int domesticAge, string domesticOwner) {
        this->name = domesticName;
        this->age = domesticAge;
        this->owner = domesticOwner;
    }

    void printInfo() const {
        string nameAndAge = this->getNameAndAge();

        cout << nameAndAge << endl;
        cout << "Owner: " << this->owner << endl;
    }
};