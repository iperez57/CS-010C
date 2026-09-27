#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
    void SetName(string employeeName) {
        name = employeeName;
    }

    virtual void PrintInfo() {
        cout << name << endl;
    }

protected:
    string name;
};

class Designer : public Employee {
public:
    void SetObject(string setObject) {
        object = setObject;
    }

    void PrintInfo() {
        cout << name << " designs " << object << endl;
    }

private:
    string object;
};

class Nurse : public Employee {
public:
    void SetHospital(string setHospital) {
        hospital = setHospital;
    }

    void PrintInfo() {
        cout << name << " works at " << hospital << endl;
    }

private:
    string hospital;
};

int main() {
    Employee* person1;
    Designer* person2;
    Nurse* person3;

    vector<Employee*> personList;
    unsigned int i;

    person1 = new Employee();
    person1->SetName("Mia");

    person2 = new Designer();
    person2->SetName("Bill");
    person2->SetObject("cars");

    person3 = new Nurse();
    person3->SetName("Liam");
    person3->SetHospital("Town Hospital");

    personList.push_back(person1);
    personList.push_back(person2);
    personList.push_back(person3);

    for (i = 0; i < personList.size(); ++i) {
        personList.at(i)->PrintInfo();
    }

    return 0;
}