/*
Shawn Oberndorfer
CSC 134 Final Project
Destiny 2 based rougelike
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;

// small helper to print a line then pause for readability (~250 ms)
void pl(const string &s, int ms = 250) {
    cout << s << '\n';
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// -------------------- Basic types --------------------
struct Attack {
    string name;
    int minDamage;
    int maxDamage;
    bool isRanged;
    int chargeTurns;       // number of turns required to charge before firing
    bool selfDestruct;     // if true, attacker dies when attack fires

    Attack(string n = "", int minD = 0, int maxD = 0, bool ranged = false,
           int charge = 0, bool selfDes = false)
        : name(n), minDamage(minD), maxDamage(maxD), isRanged(ranged),
          chargeTurns(charge), selfDestruct(selfDes) {}

    int getDamage() const {
        if (maxDamage <= minDamage) return minDamage;
        return minDamage + (rand() % (maxDamage - minDamage + 1));
    }
};

struct EnemyType {
    string name;
    int maxHealth;
    vector<Attack> attacks;
    bool isBoss = false;
};

// Result of an enemy action
struct EnemyActionResult {
    int damage;         // damage dealt this turn (0 if charging or no damage)
    string message;     // message to print
    bool attackerDied;  // true if the enemy killed itself (self-destruct)
    EnemyActionResult(int d = 0, string m = "", bool died = false) : damage(d), message(m), attackerDied(died) {}
};

class Enemy {
    EnemyType type;
    int health;

    // charging state
    Attack pendingAttack;
    int chargeRemaining; // turns left before pendingAttack fires
    bool hasPending;

public:
    Enemy(const EnemyType& t) : type(t), health(t.maxHealth), chargeRemaining(0), hasPending(false) {}

    string getName() const { return type.name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return type.maxHealth; }
    bool alive() const { return health > 0; }

    // choose a random attack from available attacks
    Attack chooseAttack() const {
        if (type.attacks.empty()) return Attack("Bash", 1, 2, false);
        int idx = rand() % type.attacks.size();
        return type.attacks[idx];
    }

    // start charging an attack
    void startCharging(const Attack &a) {
        pendingAttack = a;
        chargeRemaining = max(1, a.chargeTurns); // ensure at least 1 if charge specified
        hasPending = true;
    }

    // Called each enemy turn to either charge or execute an attack
    EnemyActionResult takeTurn() {
        if (!alive()) return EnemyActionResult(0, getName() + " is down.", false);

        // If currently charging, decrement and possibly fire
        if (hasPending) {
            if (chargeRemaining > 1) {
                chargeRemaining--;
                return EnemyActionResult(0, getName() + " continues charging " + pendingAttack.name + ".", false);
            } else {
                // chargeRemaining == 1 -> this turn the attack fires
                int dmg = pendingAttack.getDamage();
                string msg = getName() + " fires " + pendingAttack.name + " for " + to_string(dmg) + " damage!";
                bool died = false;
                if (pendingAttack.selfDestruct) {
                    // attacker kills itself
                    health = 0;
                    died = true;
                    msg += " " + getName() + " explodes and is destroyed!";
                }
                hasPending = false;
                chargeRemaining = 0;
                return EnemyActionResult(dmg, msg, died);
            }
        }

        // Not charging: pick an attack
        Attack a = chooseAttack();
        if (a.chargeTurns > 0) {
            // begin charging this attack
            startCharging(a);
            return EnemyActionResult(0, getName() + " begins charging " + a.name + ".", false);
        } else {
            // immediate attack
            int dmg = a.getDamage();
            string msg = getName() + " uses " + a.name + " for " + to_string(dmg) + " damage!";
            return EnemyActionResult(dmg, msg, false);
        }
    }

    void takeDamage(int d) {
        health -= d;
        if (health < 0) health = 0;
    }

    bool isBoss() const { return type.isBoss; }
};

// -------------------- Faction enemy pools --------------------
vector<EnemyType> hiveEnemies = {
    {"Thrall", 50, { Attack("Claw Slash", 4, 8, false), Attack("Leap Attack", 6, 10, false) }},
    {"Accolyte", 70, { Attack("Dark Shot", 6, 12, true) }},
    {"Cursed Thrall", 60, {
        Attack("Self-Destruct", 60, 80, false, 2, true) // charges 2 turns then explodes, killing itself
    }},
    {"Hive Knight", 150, { Attack("Shielded Slash", 12, 18, false), Attack("Sword Throw", 10, 16, true) }},
    {"Wizard", 120, { Attack("Arc Blast", 14, 20, true), Attack("Void Nova", 10, 18, false) }},
    {"Ogre", 200, { Attack("Ground Slam", 18, 25, false), Attack("Eye Beam", 22, 30, true, 2, false) }}
};

vector<EnemyType> fallenEnemies = {
    {"Dreg", 40, { Attack("Knife Slash", 4, 8, false), Attack("Pistol Shot", 6, 12, true) }},
    {"Vandal", 75, { Attack("Rifle Burst", 8, 14, true), Attack("Charge", 6, 10, false) }},
    {"Marauder", 85, { Attack("Axe Swing", 10, 16, false), Attack("Grenade Toss", 12, 18, true) }},
    {"Shank", 30, { Attack("Shank Jab", 3, 6, false), Attack("Shrapnel Shot", 4, 8, true) }},
    {"Servitor", 110, { Attack("Energy Beam", 12, 18, true) }},
    {"Captain", 120, { Attack("Sword Strike", 15, 20, false), Attack("Plasma Rifle", 18, 25, true) }}
};

vector<EnemyType> vexEnemies = {
    {"Hobgoblin", 80, { Attack("Sniper Beam", 12, 18, true), Attack("Energy Punch", 10, 14, false) }},
    {"Fanatic", 70, { Attack("Ritual Bolt", 10, 16, true), Attack("Frenzy Swipe", 8, 12, false) }},
    {"Minotaur", 160, { Attack("Heavy Laser", 20, 28, true), Attack("Ram", 14, 20, false) }},
    {"Hydra", 140, { Attack("Multi-Beam", 16, 22, true), Attack("Tail Whip", 10, 16, false) }},
    {"Harpy", 60, { Attack("Dive Bomb", 8, 14, false), Attack("Sonic Shot", 6, 12, true) }},
    {"Cyclops", 250, { Attack("Laser Cannon", 30, 40, true), Attack("Shockwave", 25, 35, false) }}
};

// Boss templates (one per faction)
EnemyType hiveBoss = {"Hive Ogre Overlord", 400, { Attack("Cataclysmic Slam", 30, 45, false), Attack("Void Eye Beam", 35, 50, true, 2, false) }, true};
EnemyType fallenBoss = {"Fallen Baron", 350, { Attack("Baron Cleave", 28, 40, false), Attack("Arc Barrage", 30, 42, true) }, true};
EnemyType vexBoss = {"Vex Hydra Prime", 420, { Attack("Prime Laser", 32, 48, true), Attack("Phase Crush", 28, 40, false) }, true};

// -------------------- Player --------------------
enum ClassType { TITAN, WARLOCK, HUNTER };

struct Ability {
    string name;
    int cooldownMax;
    int cooldown; // turns remaining
    int power; // effect magnitude (damage or heal)
    string desc;
    Ability(string n = "", int cd = 0, int p = 0, string d = "") : name(n), cooldownMax(cd), cooldown(0), power(p), desc(d) {}
    bool ready() const { return cooldown == 0; }
    void use() { cooldown = cooldownMax; }
    void tick() { if (cooldown > 0) --cooldown; }
};

class Player {
    string name;
    ClassType cls;
    int maxHealth;
    int health;
    int baseDamageMin;
    int baseDamageMax;
    int weaponBoost; // loot increases this
    vector<Ability> abilities;
public:
    Player(string n, ClassType c) : name(n), cls(c), weaponBoost(0) {
        if (c == TITAN) {
            maxHealth = 220; health = maxHealth;
            baseDamageMin = 14; baseDamageMax = 22;
            abilities.push_back(Ability("Fists of Havoc", 4, 70, "Heavy melee strike"));
            abilities.push_back(Ability("Arc Staff Throw", 5, 50, "Ranged lightning melee strike"));
            abilities.push_back(Ability("Void Shield Throw", 6, 20, "Damage + shield (temporary)"));
            abilities.push_back(Ability("Void Overshield", 8, 40, "Gain overshield"));
        } else if (c == WARLOCK) {
            maxHealth = 160; health = maxHealth;
            baseDamageMin = 16; baseDamageMax = 24;
            abilities.push_back(Ability("Nova Bomb", 5, 80, "High damage AoE"));
            abilities.push_back(Ability("Healing Rift", 6, 50, "Heal over time"));
            abilities.push_back(Ability("Chaos Reach", 4, 60, "Ark ranged beam"));
        } else { // HUNTER
            maxHealth = 130; health = maxHealth;
            baseDamageMin = 20; baseDamageMax = 30;
            abilities.push_back(Ability("Throwing Knife", 3, 60, "High single-target damage"));
            abilities.push_back(Ability("Staff Slide", 4, 36, "Quick melee with mobility"));
            abilities.push_back(Ability("Smoke Grenade", 5, 20, "Dodge/avoid damage for a turn"));
            abilities.push_back(Ability("Void Dodge", 6, 30, "Evade and counter"));
        }
    }

    string getClassName() const {
        if (cls == TITAN) return "Titan";
        if (cls == WARLOCK) return "Warlock";
        return "Hunter";
    }

    int attackDamage() const {
        int base = baseDamageMin + (rand() % (baseDamageMax - baseDamageMin + 1));
        return base + weaponBoost;
    }

    bool alive() const { return health > 0; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }

    void takeDamage(int d) {
        health -= d;
        if (health < 0) health = 0;
    }

    void heal(int amount) {
        health += amount;
        if (health > maxHealth) health = maxHealth;
    }

    vector<Ability>& getAbilities() { return abilities; }

    // Use ability index on a single enemy (returns damage dealt or -1 for non-damage ability)
    int useAbility(int idx, Enemy &target, vector<Enemy>& enemies) {
        if (idx < 0 || idx >= (int)abilities.size()) return -2;
        Ability &a = abilities[idx];
        if (!a.ready()) return -3;
        int dmg = 0;
        string clsName = getClassName();
        if (clsName == "Titan") {
            if (a.name == "Fists of Havoc") {
                dmg = a.power + (rand() % 11);
                target.takeDamage(dmg);
            } else if (a.name == "Arc Staff Throw") {
                dmg = a.power - 10 + (rand() % 21);
                target.takeDamage(dmg);
            } else if (a.name == "Void Shield Throw") {
                dmg = a.power/2 + (rand() % 11);
                target.takeDamage(dmg);
                heal(20);
            } else if (a.name == "Void Overshield") {
                heal(a.power/2);
            }
        } else if (clsName == "Warlock") {
            if (a.name == "Nova Bomb") {
                for (Enemy &e : enemies) {
                    if (!e.alive()) continue;
                    int ed = a.power/2 + (rand() % (a.power/2));
                    e.takeDamage(ed);
                }
                dmg = a.power;
            } else if (a.name == "Healing Rift") {
                heal(a.power/2);
            } else if (a.name == "Chaos Reach") {
                dmg = a.power + (rand() % 16);
                target.takeDamage(dmg);
            }
        } else { // Hunter
            if (a.name == "Throwing Knife") {
                dmg = a.power + (rand() % 16);
                target.takeDamage(dmg);
            } else if (a.name == "Staff Slide") {
                dmg = a.power/2 + (rand() % 12);
                target.takeDamage(dmg);
            } else if (a.name == "Smoke Grenade") {
                heal(20);
            } else if (a.name == "Void Dodge") {
                dmg = a.power + (rand() % 8);
                target.takeDamage(dmg);
                heal(12);
            }
        }
        a.use();
        return dmg;
    }

    void tickCooldowns() {
        for (auto &a : abilities) a.tick();
    }

    void addWeaponBoost(int b) { weaponBoost += b; }
    int getWeaponBoost() const { return weaponBoost; }
};

// -------------------- Utility --------------------
int getIntInput(int minv, int maxv) {
    int choice;
    while (true) {
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pl("Please enter a number: ");
            continue;
        }
        if (choice < minv || choice > maxv) {
            pl("Enter a number between " + to_string(minv) + " and " + to_string(maxv) + ": ");
            continue;
        }
        break;
    }
    return choice;
}

EnemyType randomFrom(const vector<EnemyType>& pool) {
    int idx = rand() % pool.size();
    return pool[idx];
}

// Spawn enemies for a round based on count and faction
vector<Enemy> spawnEnemiesForRound(int round, const vector<EnemyType>& pool, const EnemyType& bossType) {
    vector<Enemy> enemies;
    if (round == 5 || round == 10 || round == 15) {
        enemies.push_back(Enemy(bossType));
        return enemies;
    }
    int count = 1;
    if (round >= 1 && round <= 3) count = 1;
    else if (round == 4 || (round >= 6 && round <= 8)) count = 2;
    else if (round >= 9 && round <= 14) {
        if (round == 10) count = 1;
        else count = 3;
    }
    for (int i = 0; i < count; ++i) {
        EnemyType et = randomFrom(pool);
        enemies.push_back(Enemy(et));
    }
    return enemies;
}

void printEnemyStatus(const vector<Enemy>& enemies) {
    pl("Enemies:");
    for (size_t i = 0; i < enemies.size(); ++i) {
        pl("  [" + to_string(i+1) + "] " + enemies[i].getName() + " (" + to_string(enemies[i].getHealth()) + "/" + to_string(enemies[i].getMaxHealth()) + ")");
    }
}

// -------------------- Main game loop --------------------
int main() {
    srand((unsigned)time(0));
    pl("=== Destiny-style Roguelike ===");
    pl("");

    // Choose faction for this playthrough (exact lines requested)
    vector<string> factions = {"Hive", "Fallen", "Vex"};
    int factionChoice = rand() % factions.size();
    string faction = factions[factionChoice];
    if (faction == "Hive") {
        pl("Hive bring a sword");
    } else if (faction == "Fallen") {
        pl("Fallen on the horizon");
    } else if (faction == "Vex") {
        pl("Vex on the field");
    }
    pl("");

    // Choose enemy pool and boss based on faction
    vector<EnemyType> enemyPool;
    EnemyType bossType;
    if (faction == "Hive") { enemyPool = hiveEnemies; bossType = hiveBoss; }
    else if (faction == "Fallen") { enemyPool = fallenEnemies; bossType = fallenBoss; }
    else { enemyPool = vexEnemies; bossType = vexBoss; }

    // Player creation
    pl("Choose your class:");
    pl("1) Titan (High HP, lower damage)");
    pl("2) Warlock (Balanced)");
    pl("3) Hunter (Low HP, high damage)");
    cout << "Enter choice: ";
    int c = getIntInput(1,3);
    ClassType chosen = (c==1?TITAN:(c==2?WARLOCK:HUNTER));
    cout << "Enter your Guardian name: ";
    string pname;
    cin >> pname;
    Player player(pname, chosen);
    pl("Welcome, " + pname + " the " + player.getClassName() + "!");
    pl("");

    // Rounds 1..15
    for (int round = 1; round <= 15; ++round) {
        pl("-----------------------------");
        pl("Round " + to_string(round));

        // Spawn enemies
        vector<Enemy> enemies = spawnEnemiesForRound(round, enemyPool, bossType);
        if (enemies.empty()) {
            pl("No enemies spawned this round.");
            continue;
        }

        // Combat loop for this round
        while (player.alive() && any_of(enemies.begin(), enemies.end(), [](const Enemy& e){ return e.alive(); })) {
            pl("\nPlayer: " + to_string(player.getHealth()) + "/" + to_string(player.getMaxHealth()));
            printEnemyStatus(enemies);

            // Player turn: repeat until a valid action is taken
            bool actionTaken = false;
            while (!actionTaken) {
                pl("\nChoose action:");
                pl("1) Basic Attack");
                pl("2) Use Ability");
                cout << "Enter: ";
                int action = getIntInput(1,2);

                if (action == 1) {
                    // choose target
                    cout << "Choose target number: ";
                    int t = getIntInput(1, (int)enemies.size()) - 1;
                    if (!enemies[t].alive()) {
                        pl("Target already down. Turn wasted.");
                    } else {
                        int dmg = player.attackDamage();
                        enemies[t].takeDamage(dmg);
                        pl("You attack " + enemies[t].getName() + " for " + to_string(dmg) + " damage.");
                    }
                    actionTaken = true;
                } else if (action == 2) {
                    auto &abs = player.getAbilities();
                    // check if any ability is ready
                    bool anyReady = false;
                    for (auto &ab : abs) if (ab.ready()) { anyReady = true; break; }

                    pl("Abilities (enter 0 to go back):");
                    for (size_t i = 0; i < abs.size(); ++i) {
                        pl("  " + to_string(i+1) + ") " + abs[i].name + " (CD: " + to_string(abs[i].cooldown) + "/" + to_string(abs[i].cooldownMax) + ") - " + abs[i].desc);
                    }
                    if (!anyReady) pl("All abilities appear to be on cooldown. You can press 0 to go back and choose another action.");

                    cout << "Choose ability number (0 to cancel): ";
                    int ai = getIntInput(0, (int)abs.size()) - 1;
                    if (ai == -1) {
                        // user chose to cancel/back out; re-prompt action selection
                        pl("Returning to action selection...");
                        continue; // inner while loop repeats, actionTaken remains false
                    }

                    // choose target for single-target abilities
                    int targetIndex = 0;
                    if (!enemies.empty()) {
                        cout << "Choose target number: ";
                        targetIndex = getIntInput(1, (int)enemies.size()) - 1;
                    }
                    int res = player.useAbility(ai, enemies[targetIndex], enemies);
                    if (res == -2) pl("Invalid ability.");
                    else if (res == -3) pl("Ability on cooldown.");
                    else {
                        pl("You used " + abs[ai].name + ".");
                        if (res > 0) pl("It dealt " + to_string(res) + " damage (or AoE equivalent).");
                        actionTaken = true;
                    }
                }
            } // end player action loop

            // Enemies' turn: each enemy takes its turn (may charge or fire)
            for (size_t i = 0; i < enemies.size(); ++i) {
                EnemyActionResult ar = enemies[i].takeTurn();
                pl(ar.message);
                if (ar.damage > 0) {
                    player.takeDamage(ar.damage);
                    pl("You take " + to_string(ar.damage) + " damage. (You: " + to_string(player.getHealth()) + "/" + to_string(player.getMaxHealth()) + ")");
                }
                if (ar.attackerDied) {
                    pl(enemies[i].getName() + " has been destroyed by its own attack.");
                }
                if (!player.alive()) break;
            }

            // tick cooldowns
            player.tickCooldowns();

            if (!player.alive()) {
                pl("You have been defeated on round " + to_string(round) + ". Game over.");
                return 0;
            }
        } // end combat loop

        pl("Round " + to_string(round) + " cleared!");
        // reward: small heal and chance for weapon boost
        player.heal(15);
        pl("You rest briefly and heal 15 HP. (" + to_string(player.getHealth()) + "/" + to_string(player.getMaxHealth()) + ")");

        // Random post-round event: offer elite fight or rest (30% chance)
        int eventRoll = rand() % 100;
        if (eventRoll < 30 && round != 15) {
            pl("\nA patrol reports a tougher enemy nearby. Do you:");
            pl("1) Fight the elite for potential loot");
            pl("2) Rest and recover (heal 25)");
            cout << "Enter: ";
            int choice = getIntInput(1,2);
            if (choice == 1) {
                // spawn a single elite (stronger enemy)
                EnemyType elite = randomFrom(enemyPool);
                elite.name = "Elite " + elite.name;
                elite.maxHealth = int(elite.maxHealth * 1.5);
                for (auto &a : elite.attacks) {
                    a.minDamage = int(a.minDamage * 1.2);
                    a.maxDamage = int(a.maxDamage * 1.2);
                }
                Enemy e(elite);
                pl("You engage " + e.getName() + " (" + to_string(e.getHealth()) + " HP)");
                // simple duel
                while (player.alive() && e.alive()) {
                    pl("Your HP: " + to_string(player.getHealth()) + "/" + to_string(player.getMaxHealth()));
                    pl("1) Attack  2) Ability");
                    cout << "Choose: ";
                    int a = getIntInput(1,2);
                    if (a == 1) {
                        int dmg = player.attackDamage();
                        e.takeDamage(dmg);
                        pl("You hit for " + to_string(dmg) + ". Elite HP: " + to_string(e.getHealth()));
                    } else {
                        auto &abs = player.getAbilities();
                        bool anyReady = false;
                        for (auto &ab : abs) if (ab.ready()) { anyReady = true; break; }

                        pl("Abilities (enter 0 to go back):");
                        for (size_t i = 0; i < abs.size(); ++i) {
                            pl(to_string(i+1) + ") " + abs[i].name + " (CD " + to_string(abs[i].cooldown) + ")");
                        }
                        if (!anyReady) pl("All abilities appear to be on cooldown. You can press 0 to go back and choose another action.");

                        cout << "Choose ability (0 to cancel): ";
                        int ai = getIntInput(0, (int)abs.size()) - 1;
                        if (ai == -1) {
                            pl("Returning to duel action selection...");
                            continue; // go back to duel loop top
                        }
                        vector<Enemy> tmp; // empty for signature
                        int res = player.useAbility(ai, e, tmp);
                        if (res >= 0) pl("Ability dealt " + to_string(res) + " damage.");
                        else if (res == -3) pl("Ability on cooldown.");
                    }
                    if (e.alive()) {
                        EnemyActionResult ar = e.takeTurn();
                        pl(ar.message);
                        if (ar.damage > 0) {
                            player.takeDamage(ar.damage);
                            pl("You take " + to_string(ar.damage) + " damage. (You: " + to_string(player.getHealth()) + "/" + to_string(player.getMaxHealth()) + ")");
                        }
                        if (ar.attackerDied) pl(e.getName() + " has been destroyed by its own attack.");
                    }
                    player.tickCooldowns();
                }
                if (player.alive()) {
                    pl("You defeated the elite! Loot: weapon boost +2.");
                    player.addWeaponBoost(2);
                } else {
                    pl("You were killed by the elite. Game over.");
                    return 0;
                }
            } else {
                pl("You rest and recover 25 HP.");
                player.heal(25);
            }
        }

        // Boss reward on boss rounds
        if (round == 5 || round == 10 || round == 15) {
            pl("Boss defeated! You gain a major weapon upgrade (+5 damage) and heal fully.");
            player.addWeaponBoost(5);
            player.heal(player.getMaxHealth());
        }

        // small checkpoint
        pl("End of round " + to_string(round) + ". Current HP: " + to_string(player.getHealth()) + "/" + to_string(player.getMaxHealth()));
        pl("");
    } // end rounds

    pl("Congratulations! You survived 15 rounds. Final stats:");
    pl("HP: " + to_string(player.getHealth()) + "/" + to_string(player.getMaxHealth()));
    pl("Weapon boost: (+" + to_string(player.getWeaponBoost()) + ")");
    pl("Thanks for playing.");
    return 0;
}
