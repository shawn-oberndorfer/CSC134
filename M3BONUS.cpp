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

// Enemy definition
struct Enemy {
    string name;
    int maxHP;
    int minDamage;
    int maxDamage;
};

void printStatus(int playerHP, int enemyHP, string enemyName) {
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

void playerTurn(int& enemyHP, bool& isDefending, string enemyName) {
    cout << "\nYour turn!\n";
    cout << "Choose an action:\n";
    cout << "1) Attack\n";
    cout << "2) Defend\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        int damage = (rand() % 4) + 2; // random 2–5
        cout << "You strike the " << enemyName << " for " << damage << " damage!\n";
        enemyHP -= damage;
        enemyHP = clampToZero(enemyHP);
        isDefending = false;
        waitForEnter(); // pause until player presses Enter
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

void enemyTurn(int& playerHP, bool& isDefending, Enemy currentEnemy) {
    cout << "\n" << currentEnemy.name << "'s turn...\n";
    int damage = (rand() % (currentEnemy.maxDamage - currentEnemy.minDamage + 1))
                 + currentEnemy.minDamage;

    if (isDefending) {
        cout << "Your defense absorbs some of the blow!\n";
        damage /= 2;
        isDefending = false;
    }

    cout << currentEnemy.name << " hits you for " << damage << " damage!\n";
    playerHP -= damage;
    playerHP = clampToZero(playerHP);

    // Random pause between 1 and 3 seconds
    int pauseTime = (rand() % 2) + 1;
    this_thread::sleep_for(chrono::seconds(pauseTime));
}

int main() {
    srand(time(0)); // seed randomness once

    // Enemy list
    Enemy enemies[] = {
        {"Slime", 8, 1, 3},
        {"Goblin", 12, 2, 4},
        {"Wolf", 10, 1, 5}
    };
    int numEnemies = sizeof(enemies) / sizeof(enemies[0]);

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        cout << "\n=== New Battle Begins! ===\n";

        int playerHP = 10;
        bool isDefending = false;

        // Pick a random enemy
        int enemyIndex = rand() % numEnemies;
        Enemy currentEnemy = enemies[enemyIndex];
        int enemyHP = currentEnemy.maxHP;

        cout << "\nA wild " << currentEnemy.name << " appears!\n";

        // Battle loop
        while (playerHP > 0 && enemyHP > 0) {
            printStatus(playerHP, enemyHP, currentEnemy.name);
            playerTurn(enemyHP, isDefending, currentEnemy.name);

            if (enemyHP == 0) {
                cout << "\nThe " << currentEnemy.name << " falls. You win!\n";
                break;
            }

            enemyTurn(playerHP, isDefending, currentEnemy);

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