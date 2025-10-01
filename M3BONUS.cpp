/*
Shawn Oberndorfer / Copilot
10/1/2025

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
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

// Player's turn: now has Attack or Defend
void playerTurn(int& enemyHP, bool& isDefending) {
    cout << "\nYour turn!\n";
    cout << "Choose an action:\n";
    cout << "1) Attack\n";
    cout << "2) Defend\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        int damage = (rand() % 4) + 2;
        cout << "You strike the enemy for " << damage << " damage!\n";
        enemyHP -= damage;
        enemyHP = clampToZero(enemyHP);
        isDefending = false; // not defending this turn
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

// Enemy's turn: damage reduced if player defended
void enemyTurn(int& playerHP, bool& isDefending) {
    cout << "\nEnemy's turn...\n";
    int damage = (rand() % 3) + 1;

    if (isDefending) {
        cout << "Your defense absorbs some of the blow!\n";
        damage /= 2; // halve the damage
        isDefending = false; // defense only lasts one attack
    }

    cout << "The enemy hits you for " << damage << " damage!\n";
    playerHP -= damage;
    playerHP = clampToZero(playerHP);
}

int main() {
    srand(time(0));

    cout << "Welcome to the duel!\n";

    int playerHP = 10;
    int enemyHP = 8;
    bool isDefending = false; // track defense state

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

    cout << "\nThanks for playing!\n";
    return 0;
}