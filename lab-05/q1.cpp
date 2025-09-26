#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int guessNumber(int target, int turn) {
    int g;
    cout << "Player " << turn << " enter guess: ";
    cin >> g;
    if (g == target) {
        cout << "Player " << turn << " wins!\n";
    return 1;
}
    if (g > target) cout << "Too high\n";
    else cout << "Too low\n";
    return guessNumber(target, (turn % 2) + 1);
}

int main() {
    srand(time(0));
    int num = rand() % 100 + 1;
    guessNumber(num, 1);
return 0;
}
