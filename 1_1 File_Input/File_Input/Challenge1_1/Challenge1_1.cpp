#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream dataFS;
    int futonCount;

    /* Your code goes here */
    dataFS.open("data1.txt");

    if (!dataFS.is_open()) {
        cout << "data1.txt: program exiting due to error" << endl;
        return 1;
    }

    dataFS >> futonCount;

    cout << futonCount << endl;

    dataFS.close();

    return 0;
}