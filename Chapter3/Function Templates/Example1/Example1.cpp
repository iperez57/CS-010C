
#include <iostream>
using namespace std;

//needs T as placeholder value T is all data types
template<typename T>
T TripleMin(double item1, T item2, T item3) {
    T minVal = item1;   // Holds min item value, init to first item

    if (item2 < minVal) {
        minVal = item2;
    }
    if (item3 < minVal) {
        minVal = item3;
    }

    return minVal;
}

int main() {
    int num1;
    int num2;
    int num3;
    double dbl1;

    num1 = 55;
    num2 = 99;
    num3 = 66;
    dbl1 = 12.5;

    cout << "Items: " << num1 << " " << num2 << " " << num3 << endl;
    cout << "Min: " << TripleMin(num1, num2, num3) << endl << endl;

    cout << "Items: " << dbl1 << " " << num2 << " " << num3 << endl;
    cout << "Min: " << TripleMin(dbl1, num2, num3) << endl << endl;

    return 0;
}
