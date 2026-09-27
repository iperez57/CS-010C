
#include <iostream>
#include <vector>
using namespace std;

class Watch {
public:
    void SetHours(int watchHours) {
        hours = watchHours;
    }

    void SetMins(int watchMins) {
        mins = watchMins;
    }

    virtual void PrintItem() {
        cout << hours << ":" << mins << endl;
    }

protected:
    int hours;
    int mins;
};

class SmartWatch : public Watch {
public:
    void SetPercentage(int watchPercentage) {
        batteryPercentage = watchPercentage;
    }

    void PrintItem() {
        cout << hours << ":" << mins << " " << batteryPercentage << "%" << endl;
    }

private:
    int batteryPercentage;
};

int main() {
    Watch* watch1;
    Watch* watch2;
    SmartWatch* watch3;

    vector<Watch*> watchList;
    unsigned int i;

    watch1 = new Watch();
    watch1->SetHours(7);
    watch1->SetMins(19);

    watch2 = new Watch();
    watch2->SetHours(6);
    watch2->SetMins(30);

    watch3 = new SmartWatch();
    watch3->SetHours(9);
    watch3->SetMins(24);
    watch3->SetPercentage(92);

    watchList.push_back(watch1);
    watchList.push_back(watch2);
    watchList.push_back(watch3);

    for (i = 0; i < watchList.size(); ++i) {
        watchList.at(i)->PrintItem();
    }

    return 0;
}