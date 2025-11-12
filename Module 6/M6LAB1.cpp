#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

int currentRound[4] = {3, 4, 5, 7};
int livePerRound[4] = {1, 2, 3, 4};
int blankPerRound[4] = {2, 2, 2, 3};
string round1[3] = {"Blank", "Live", "Blank"};
string round2[4] = {"Blank", "Live", "Blank", "Live"};
string round3[5] = {"Live", "Blank", "Live", "Blank", "Live"};
string round4[7] = {"Blank", "Live", "Blank", "Live", "Blank", "Live", "Live"};

string BulletType(int);
bool turnOutcome(bool, int&, int&, int);
bool playerTurn();
bool opponetTurn();
void gameOver(int, int);
int roll(int currentRound[], int);

int main(){
    srand(time(0));
    int roundNumber = 1;
    int playerHealth = 3;
    int opponentHealth = 3;
    int shotsFired;
    bool playersTurn;

    while(playerHealth > 0 && opponentHealth > 0 && roundNumber < 5){
        cout << "Round " << roundNumber << "!\n";
        cout << "Player Health: " << playerHealth << " | Opponent Health: " << opponentHealth << "\n";
        cout << "There are " << livePerRound[roundNumber - 1] << " live rounds and " << blankPerRound[roundNumber - 1] << " blank rounds in the chamber.\n\n";
        shotsFired = 0;
        playersTurn = true;
        while(shotsFired < currentRound[roundNumber - 1]){
            playersTurn = turnOutcome(playersTurn, playerHealth, opponentHealth, roundNumber);
            shotsFired++;
            if(playerHealth <= 0 || opponentHealth <= 0) {
                break;
            }
        }
        roundNumber++;
    }
    gameOver(playerHealth, opponentHealth);
    return 0;
}

string BulletType(int roundNumber){
    int result;

    if(roundNumber == 1){
        do{    
            result = roll(currentRound, roundNumber);
        } while(round1[result] == " ");
        string shot = round1[result];
        round1[result] = " ";
        return shot;
    } else if(roundNumber == 2){
        do{    
            result = roll(currentRound, roundNumber);
        } while(round2[result] == " ");
        string shot = round2[result];
        round2[result] = " ";
        return shot;
    } else if(roundNumber == 3){
        do{    
            result = roll(currentRound, roundNumber);
        } while(round3[result] == " ");
        string shot = round3[result];
        round3[result] = " ";
        return shot;
    } else if(roundNumber == 4){
        do{    
            result = roll(currentRound, roundNumber);
        } while(round4[result] == " ");
        string shot = round4[result];
        round4[result] = " ";
        return shot;
    }
    return "Null";
}

bool playerTurn(){
    int playerChoice;
    cout << "Would would you like to shoot?\n 1. Yourself\n 2. Opponent\n";
    cin >> playerChoice;
    if(playerChoice == 1){
        return true;
    } else if(playerChoice == 2){
        return false;
    } else {
        cout << "Invalid choice. Please choose again.\n";
        return playerTurn();
    }
}

bool opponetTurn(){
    int opponentChoice = rand() % 2 + 1;
    if(opponentChoice == 1){
        return true;
    } else if(opponentChoice == 2){
        return false;
    } else {
        return opponetTurn();
    }
}

bool turnOutcome(bool playersTurn, int &playerHealth, int &opponentHealth, int roundNumber){
    bool playerShot;
    if(playersTurn == true){
        playerShot = playerTurn();
    } else if(playersTurn == false){
        playerShot = opponetTurn();
    }
    
    string shotType = BulletType(roundNumber);
    if(playersTurn == true && playerShot == true){
        if(shotType == "Blank"){
            cout << "You shot yourself with a blank round!\n\n";
            playersTurn = true;
        } else if(shotType == "Live"){
            cout << "You shot yourself with a live round!\n\n";
            playerHealth--;
            playersTurn = false;
        }
    } else if(playersTurn == true && playerShot == false){
        if(shotType == "Blank"){
            cout << "You shot your opponent with a blank round!\n\n";
            playersTurn = false;
        } else if(shotType == "Live"){
            cout << "You shot your opponent with a live round!\n\n";
            opponentHealth--;
            playersTurn = false;
        }
    } else if(playersTurn == false && playerShot == true){
        this_thread::sleep_for(std::chrono::seconds(1));
        if(shotType == "Blank"){
            cout << "Your opponent shot you with a blank round!\n\n";
            playersTurn = true;
        } else if(shotType == "Live"){
            cout << "Your opponent shot you with a live round!\n\n";
            playerHealth--;
            playersTurn = true;
        }
    } else if(playersTurn == false && playerShot == false){
        this_thread::sleep_for(std::chrono::seconds(3));
        if(shotType == "Live"){
            cout << "Your opponent shot themselves with a live round!\n\n";
            opponentHealth--;
            playersTurn = true;
        } else if(shotType == "Blank"){
            cout << "Your opponent shot themselves with a blank round!\n\n";
            playersTurn = false;
        }
    }
    return playersTurn;
}

int roll(int currentRound[], int roundNumber){
    int shotFired;
    shotFired = (rand() % currentRound[roundNumber-1]);
    return shotFired;
}

void gameOver(int playerHealth, int opponentHealth){
    cout << "Game Over!\n";
    if(playerHealth = 0){
        cout << "You have been defeated!\n";
    } else if(opponentHealth <= 0){
        cout << "You are victorious!\n";
    } else {
        cout << "The game ended in a draw!\n";
    }
    cout << "Thanks for playing!\n";
}