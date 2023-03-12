#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <deque>
using namespace std;

int main() {
    int playerSize = 5;

    deque<int> player1(playerSize);
    deque<int> player2(playerSize);

    for (int i = 0; i < 5; i++)
        cin >> player1[i];

    for (int i = 0; i < 5; i++)
        cin >> player2[i];

    int maxSteps = 1000000;
    int stepCount = 0;
    int card1 = 0;
    int card2 = 0;
    while (!player1.empty() && !player2.empty() && ++stepCount < maxSteps) {
        card1 = player1.front();
        player1.pop_front();
        card2 = player2.front();
        player2.pop_front();
        if (card1 == 9 && card2 == 0) {
            player2.push_back(card1);
            player2.push_back(card2);
        }
        else if (card2 == 9 && card1 == 0) {
            player1.push_back(card1);
            player1.push_back(card2);
        }
        else if (card1 < card2) {
            player2.push_back(card1);
            player2.push_back(card2);
        }
        else if (card2 < card1) {
            player1.push_back(card1);
            player1.push_back(card2);
        }
    }

    if (stepCount > maxSteps)
        cout << "botva";
    if (player1.empty())
        cout << "second " << stepCount;
    if (player2.empty())
        cout << "first " << stepCount;



    return(0);
}