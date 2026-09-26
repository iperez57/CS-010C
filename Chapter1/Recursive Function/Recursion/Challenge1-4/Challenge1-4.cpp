/*
Complete GetMerchandise()'s recursive case:

If total ? 200, call GetMerchandise() to compute the next month's total as the current month's total plus 45.
Otherwise, call GetMerchandise() to compute the next month's total as the current month's total plus 35.
*/

#include <iostream>
using namespace std;

void GetMerchandise(int month, int total) {
    cout << "month: " << month << ", total: " << total << endl;

    if (month == 3) {
        cout << "Finished" << endl;
    }
    else {

        /* Your code goes here */
        if (total <= 200)
        {
            GetMerchandise(month + 1, total + 45);
        }
        else
        {
            GetMerchandise(month + 1, total + 35);
        }

    }
}

int main() {
    int total;

    cin >> total;
    GetMerchandise(1, total);

    return 0;
}