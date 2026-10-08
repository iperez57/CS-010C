#include <iostream>
#include <vector>
using namespace std;

int main() {
    int playerNum;
    int score;
    vector<int> playerScores = { 650, 400, 100, 600, 800, 150,
                                 200, 350, 550, 750, 250, 500 };

    try {
        cin >> playerNum;

        score = playerScores.at(playerNum - 1);
        cout << "Player " << playerNum << ": " << score << " pts" << endl;
    }
    catch (out_of_range& excpt) {
        cout << "Error: Invalid player" << endl;
    }

    return 0;
}