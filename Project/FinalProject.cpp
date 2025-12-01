#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Attack {
    string name; // Name of the attack
    int minDamage; // Minimum damage
    int maxDamage; // Maximum damage
    bool isRanged; //Determines if the attack is ranged or melee

    Attack(string n, int minD, int maxD, bool ranged)
        : name(n), minDamage(minD), maxDamage(maxD), isRanged(ranged) {}

    int getDamage() const {
        return minDamage + (rand() % (maxDamage - minDamage + 1));
    }
};

struct EnemyType {
    string name;
    int health;
    vector<Attack> attacks;
};

class Enemy {
    EnemyType type;
public:
    Enemy(EnemyType t) : type(t) {}

    void attack() {
        if (type.attacks.empty()) {
            cout << type.name << " has no attacks!\n";
            return;
        }
        int choice = rand() % type.attacks.size();
        Attack atk = type.attacks[choice];
        cout << type.name << " uses " << atk.name
             << (atk.isRanged ? " (Ranged)" : " (Melee)")
             << " for " << atk.getDamage() << " damage!\n";
    }

    string getName() { return type.name; }
    int getHealth() { return type.health; }
};
// Hive enemies
vector<EnemyType> hiveEnemies = {
    {"Thrall", 50, { Attack("Claw Slash", 4, 8, false), Attack("Leap Attack", 6, 10, false) }},
    {"Accolyte", 70, { Attack("Dark Shot", 6, 12, true) }},
    {"Ogre", 200, { Attack("Ground Slam", 18, 25, false), Attack("Eye Beam", 22, 30, true) }}
};

// Fallen enemies
vector<EnemyType> fallenEnemies = {
    {"Dreg", 40, { Attack("Knife Slash", 4, 8, false), Attack("Pistol Shot", 6, 12, true) }},
    {"Captain", 120, { Attack("Sword Strike", 15, 20, false), Attack("Plasma Rifle", 18, 25, true) }}
};

// Vex enemies
vector<EnemyType> vexEnemies = {
    {"Hobgoblin", 80, { Attack("Sniper Beam", 12, 18, true), Attack("Energy Punch", 10, 14, false) }},
    {"Cyclops", 250, { Attack("Laser Cannon", 30, 40, true), Attack("Shockwave", 25, 35, false) }}
};



int main() {
    srand(time(0));

    return 0;
}
