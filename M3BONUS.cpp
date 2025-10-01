/*
Shawn Oberndorfer / Copilot
10/1/2025

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <limits>
using namespace std;

void printStatus(int playerHP, int enemyHP) {
    cout << "\n--- Status ---\n";
    cout << "Player HP: " << playerHP << "\n";
    cout << "Enemy  HP: " << enemyHP << "\n";
}

int clampToZero(int hp) {
    if (hp < 0) return 0;
    return hp;
}

void waitForEnter() {
    cout << "\n(Press Enter to continue...)";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover input
    cin.get(); // actually wait for Enter
}

void playerTurn(int& enemyHP, bool& isDefending) {
    cout << "\nYour turn!\n";
    cout << "Choose an action:\n";
    cout << "1) Attack\n";
    cout << "2) Defend\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        int damage = (rand() % 4) + 2; // random 2–5
        cout << "\nYou strike the enemy for " << damage << " damage!\n";
        enemyHP -= damage;
        enemyHP = clampToZero(enemyHP);
        isDefending = false;
        waitForEnter();
    } 
    else if (choice == 2) {
        cout << "You brace yourself for the enemy's attack!\n";
        isDefending = true;
    } 
    else {
        cout << "Invalid choice. You hesitate and miss your turn.\n";
        isDefending = false;
    }
}

void enemyTurn(int& playerHP, bool& isDefending) {
    cout << "\nEnemy's turn...\n";
    int damage = (rand() % 3) + 1; // random 1–3

    if (isDefending) {
        cout << "Your defense absorbs some of the blow!\n";
        damage /= 2;
        isDefending = false;
    }

    cout << "The enemy hits you for " << damage << " damage!\n";
    this_thread::sleep_for(chrono::seconds(2)); // 2-second pause
    playerHP -= damage;
    playerHP = clampToZero(playerHP);
}

int main() {
    srand(time(0)); // seed randomness once

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        cout << "\n=== New Battle Begins! ===\n";

        int playerHP = 10;
        int enemyHP = 8;
        bool isDefending = false;

        while (playerHP > 0 && enemyHP > 0) {
            printStatus(playerHP, enemyHP);
            playerTurn(enemyHP, isDefending);

            if (enemyHP == 0) {
                cout << "\nThe enemy falls. You win!\n";
                break;
            }

            enemyTurn(playerHP, isDefending);

            if (playerHP == 0) {
                cout << "\nYou collapse. Game over.\n";
                break;
            }
        }

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nThanks for playing!\n";
    return 0;
}