#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

string FireRound(int);
int roll(int currentRound[], int);

int main(){
    srand(time(0));
    int roundNumber = 1;
    int playerHealth = 3;
    int opponentHealth = 3;

    cout << FireRound(roundNumber) << "\n";
    return 0;
}

string FireRound(int roundNumber){
    int currentRound[4] = {3, 4, 5, 7};
    string round1[3] = {"Live", "Blank", "Blank"};
    // roll(currentRound, roundNumber);

    if(roundNumber == 1){
        int result = roll(currentRound, roundNumber);
        return round1[result];
    }
    return "Null";
}

int roll(int currentRound[], int roundNumber){
    int shotFired;
    shotFired = (rand() % currentRound[roundNumber-1]);
    return shotFired;
}