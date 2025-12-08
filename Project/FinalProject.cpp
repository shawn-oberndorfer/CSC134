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

    Attack chooseAttack() const {
        if (type.attacks.empty()) return Attack("Bash", 1, 2, false);
        int idx = rand() % type.attacks.size();
        return type.attacks[idx];
    }

    void startCharging(const Attack &a) {
        pendingAttack = a;
        chargeRemaining = max(1, a.chargeTurns);
        hasPending = true;
    }

    EnemyActionResult takeTurn() {
        if (!alive()) return EnemyActionResult(0, getName() + " is down.", false);

        if (hasPending) {
            if (chargeRemaining > 1) {
                chargeRemaining--;
                return EnemyActionResult(0, getName() + " continues charging " + pendingAttack.name + ".", false);
            } else {
                int dmg = pendingAttack.getDamage();
                string msg = getName() + " fires " + pendingAttack.name + " for " + to_string(dmg) + " damage!";
                bool died = false;
                if (pendingAttack.selfDestruct) {
                    health = 0;
                    died = true;
                    msg += " " + getName() + " explodes and is destroyed!";
                }
                hasPending = false;
                chargeRemaining = 0;
                return EnemyActionResult(dmg, msg, died);
            }
        }

        Attack a = chooseAttack();
        if (a.chargeTurns > 0) {
            startCharging(a);
            return EnemyActionResult(0, getName() + " begins charging " + a.name + ".", false);
        } else {
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
    {"Thrall", 60, { Attack("Claw Slash", 4, 9, false), Attack("Leap Attack", 6, 11, false) }},
    {"Accolyte", 80, { Attack("Dark Shot", 6, 13, true) }},
    {"Cursed Thrall", 70, {
        Attack("Self-Destruct", 60, 80, false, 2, true)
    }},
    {"Hive Knight", 170, { Attack("Shielded Slash", 11, 20, false), Attack("Sword Throw", 11, 18, true) }},
    {"Wizard", 140, { Attack("Arc Blast", 13, 22, true), Attack("Void Nova", 11, 20, false) }},
    {"Ogre", 260, { Attack("Ground Slam", 16, 28, false), Attack("Eye Beam", 24, 34, true, 2, false) }}
};

vector<EnemyType> fallenEnemies = {
    {"Dreg", 44, { Attack("Knife Slash", 4, 9, false), Attack("Pistol Shot", 6, 13, true) }},
    {"Vandal", 82, { Attack("Rifle Burst", 7, 15, true), Attack("Charge", 6, 11, false) }},
    {"Marauder", 95, { Attack("Axe Swing", 9, 18, false), Attack("Grenade Toss", 11, 20, true) }},
    {"Shank", 33, { Attack("Shank Jab", 3, 7, false), Attack("Shrapnel Shot", 4, 9, true) }},
    {"Servitor", 120, { Attack("Energy Beam", 11, 20, true) }},
    {"Captain", 132, { Attack("Sword Strike", 14, 22, false), Attack("Plasma Rifle", 17, 27, true) }}
};

vector<EnemyType> vexEnemies = {
    {"Hobgoblin", 88, { Attack("Sniper Beam", 11, 20, true), Attack("Energy Punch", 10, 15, false) }},
    {"Fanatic", 77, { Attack("Ritual Bolt", 9, 18, true), Attack("Frenzy Swipe", 8, 13, false) }},
    {"Minotaur", 200, { Attack("Heavy Laser", 18, 30, true), Attack("Ram", 13, 22, false) }},
    {"Hydra", 160, { Attack("Multi-Beam", 15, 24, true), Attack("Tail Whip", 10, 18, false) }},
    {"Harpy", 66, { Attack("Dive Bomb", 8, 15, false), Attack("Sonic Shot", 6, 13, true) }},
    {"Cyclops", 300, { Attack("Laser Cannon", 28, 44, true), Attack("Shockwave", 24, 38, false) }}
};

// Boss templates (one per faction)
EnemyType hiveBoss = {"Hive Ogre Overlord", 440, { Attack("Cataclysmic Slam", 32, 48, false), Attack("Void Eye Beam", 38, 54, true, 2, false) }, true};
EnemyType fallenBoss = {"Fallen Baron", 380, { Attack("Baron Cleave", 30, 44, false), Attack("Arc Barrage", 32, 46, true) }, true};
EnemyType vexBoss = {"Vex Hydra Prime", 460, { Attack("Prime Laser", 34, 52, true), Attack("Phase Crush", 30, 44, false) }, true};

// -------------------- Player --------------------
enum ClassType { TITAN, WARLOCK, HUNTER };

struct Ability {
    string name;
    int cooldownMax;
    int cooldown; // turns remaining
    int power; // effect magnitude (damage or heal or overshield)
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
    int overshield;  // separate overshield value
    vector<Ability> abilities;
public:
    Player(string n, ClassType c) : name(n), cls(c), weaponBoost(0), overshield(0) {
        if (c == TITAN) {
            maxHealth = 260; health = maxHealth; // increased
            baseDamageMin = 16; baseDamageMax = 24; // increased
            abilities.push_back(Ability("Fists of Havoc", 4, 80, "Heavy melee strike"));
            abilities.push_back(Ability("Flamming Hammer Strike", 5, 50, "Ranged solar melee strike"));
            abilities.push_back(Ability("Void Shield Throw", 3, 30, "Damage + grant overshield"));
            abilities.push_back(Ability("Void Overshield", 5, 60, "Grant a strong overshield"));
        } else if (c == WARLOCK) {
            maxHealth = 180; health = maxHealth; // increased
            baseDamageMin = 18; baseDamageMax = 26; // increased
            abilities.push_back(Ability("Nova Bomb", 5, 100, "High damage AoE"));
            abilities.push_back(Ability("Healing Rift", 6, 60, "Heal over time"));
            abilities.push_back(Ability("Chaos Reach", 4, 60, "Arc ranged beam"));
        } else { // HUNTER
            maxHealth = 150; health = maxHealth; // increased
            baseDamageMin = 22; baseDamageMax = 34; // increased
            abilities.push_back(Ability("Throwing Knife", 3, 80, "High single-target damage"));
            abilities.push_back(Ability("Staff Slide", 4, 36, "Quick melee with mobility"));
            abilities.push_back(Ability("Smoke Grenade", 5, 20, "Dodge/avoid damage for a turn"));
            abilities.push_back(Ability("Void Dodge", 6, 30, "Evade and counter"));
        }

    }

    int useAbility(int idx, Enemy &target) {
        std::vector<Enemy> empty;
        return useAbility(idx, target, empty);
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
    int getOvershield() const { return overshield; }

    // Damage first reduces overshield, then HP
    void takeDamage(int d) {
        if (d <= 0) return;
        if (overshield > 0) {
            if (d <= overshield) {
                overshield -= d;
                return;
            } else {
                d -= overshield;
                overshield = 0;
            }
        }
        health -= d;
        if (health < 0) health = 0;
    }

    // heal and report actual healed amount
    void heal(int amount) {
        if (amount <= 0) return;
        int before = health;
        health += amount;
        if (health > maxHealth) health = maxHealth;
        int actual = health - before;
        if (actual > 0) {
            pl("You heal for " + to_string(actual) + " health");
        } else {
            pl("You heal for 0 health");
        }
    }

    // add overshield and report amount gained
    void addOvershield(int amount) {
        if (amount <= 0) return;
        overshield += amount;
        pl("You gain " + to_string(amount) + " Overshield");
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
            } else if (a.name == "Flamming Hammer Strike") {
                dmg = a.power - 10 + (rand() % 21);
                target.takeDamage(dmg);
            } else if (a.name == "Void Shield Throw") {
                // damage + grant overshield
                dmg = a.power/2 + (rand() % 11);
                target.takeDamage(dmg);
                int os = a.power/3;
                addOvershield(os); // grant a portion as overshield and print
            } else if (a.name == "Void Overshield") {
                addOvershield(a.power); // grant overshield instead of healing and print
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
                int healAmt = a.power/2;
                heal(healAmt); // heal() prints actual healed amount
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
                // Smoke grants a small overshield to simulate dodge buffer
                addOvershield(12);
            } else if (a.name == "Void Dodge") {
                dmg = a.power + (rand() % 8);
                target.takeDamage(dmg);
                addOvershield(8);
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

    // status string for printing
    string statusString() const {
        return to_string(health) + "/" + to_string(maxHealth) + " (Overshield: " + to_string(overshield) + ")";
    }
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

bool getYesNo(const string &prompt) {
    while (true) {
        cout << prompt << " (y/n): ";
        string s;
        if (!(cin >> s)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (s.empty()) continue;
        char c = tolower(s[0]);
        if (c == 'y') return true;
        if (c == 'n') return false;
        pl("Please enter 'y' or 'n'.");
    }
}

EnemyType randomFrom(const vector<EnemyType>& pool) {
    int idx = rand() % pool.size();
    return pool[idx];
}

// Spawn enemies for a round based on count and faction
vector<Enemy> spawnEnemiesForRound(int round, const vector<EnemyType>& pool, const EnemyType& bossType) {
    vector<Enemy> enemies;
    if (round == 5 || round == 10 || round == 15) {
        EnemyType boss = bossType;
        double bossMult = 1.0;
        if (round == 10) bossMult = 1.05;
        if (round == 15) bossMult = 1.1;
        boss.maxHealth = int(boss.maxHealth * bossMult);
        enemies.push_back(Enemy(boss));
        return enemies;
    }
    int count = 1;
    if (round >= 1 && round <= 3) count = 1;
    else if (round == 4 || (round >= 6 && round <= 8)) count = 2;
    else if (round >= 9 && round <= 14) {
        if (round == 10) count = 1;
        else count = 3;
    }

    double roundMult = 1.0;
    if (round <= 3) roundMult = 0.95;
    else if (round <= 5) roundMult = 1.05;
    else if (round <= 8) roundMult = 1.15;
    else if (round <= 12) roundMult = 1.30;
    else roundMult = 1.40;

    for (int i = 0; i < count; ++i) {
        EnemyType et = randomFrom(pool);
        et.maxHealth = max(1, int(et.maxHealth * roundMult));
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

// -------------------- Game run (single playthrough) --------------------
bool runPlaythrough() {
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
            pl("\nPlayer: " + player.statusString());
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
                        pl("Returning to action selection...");
                        continue;
                    }

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
                    pl("You take " + to_string(ar.damage) + " damage. (You: " + player.statusString() + ")");
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
                bool again = getYesNo("Play again?");
                return again;
            }
        } // end combat loop

        pl("Round " + to_string(round) + " cleared!");
        player.heal(20); // slightly larger passive heal (prints)
        pl("You rest briefly. (" + player.statusString() + ")");

        // Random post-round event: offer elite fight or rest (30% chance)
        int eventRoll = rand() % 100;
        if (eventRoll < 30 && round != 15) {
            pl("\nA patrol reports a tougher enemy nearby. Do you:");
            pl("1) Fight the elite for potential loot");
            pl("2) Rest and recover (heal 25)");
            cout << "Enter: ";
            int choice = getIntInput(1,2);
            if (choice == 1) {
                EnemyType elite = randomFrom(enemyPool);
                elite.name = "Elite " + elite.name;
                elite.maxHealth = int(elite.maxHealth * 1.5);
                for (auto &a : elite.attacks) {
                    a.minDamage = int(a.minDamage * 1.2);
                    a.maxDamage = int(a.maxDamage * 1.2);
                }
                Enemy e(elite);
                pl("You engage " + e.getName() + " (" + to_string(e.getHealth()) + " HP)");

                // elite duel loop — text output matches the rest of the game
               // elite duel loop — now matches normal fight text style
                while (player.alive() && e.alive()) {
                    pl("\nPlayer: " + to_string(player.getHealth()) + "/" + to_string(player.getMaxHealth()));
                    pl("Enemy: " + e.getName() + " (" + to_string(e.getHealth()) + "/" + to_string(e.getMaxHealth()) + ")");

                    // Player turn
                    bool actionTaken = false;
                    while (!actionTaken) {
                        pl("\nChoose action:");
                        pl("1) Basic Attack");
                        pl("2) Use Ability");
                        cout << "Enter: ";
                        int action = getIntInput(1,2);

                        if (action == 1) {
                            int dmg = player.attackDamage();
                            e.takeDamage(dmg);
                            pl("You attack " + e.getName() + " for " + to_string(dmg) + " damage.");
                            actionTaken = true;
                        } else if (action == 2) {
                            auto &abs = player.getAbilities();
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
                                pl("Returning to action selection...");
                                continue;
                            }

                            int res = player.useAbility(ai, e);
                            if (res == -2) pl("Invalid ability.");
                            else if (res == -3) pl("Ability on cooldown.");
                            else {
                                pl("You used " + abs[ai].name + ".");
                                if (res > 0) pl("It dealt " + to_string(res) + " damage.");
                                actionTaken = true;
                            }
                        }
                    }

                    // Elite's turn
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

                    if (!player.alive()) {
                        pl("You were killed by the elite. Game over.");
                        bool again = getYesNo("Play again?");
                        return again;
                    }
                }


                if (player.alive()) {
                    pl("You defeated the elite! Loot: weapon boost +2.");
                    player.addWeaponBoost(2);
                } else {
                    pl("You were killed by the elite. Game over.");
                    bool again = getYesNo("Play again?");
                    return again;
                }
            } else {
                pl("You rest and recover 25 HP.");
                player.heal(25);
                pl("You now have: " + player.statusString());
            }
        }

        // Boss reward on boss rounds
        if (round == 5 || round == 10 || round == 15) {
            pl("Boss defeated! You gain a major weapon upgrade (+6 damage) and heal fully.");
            player.addWeaponBoost(6); // increased boss reward
            player.heal(player.getMaxHealth());
            pl("You now have: " + player.statusString());
        }

        // small checkpoint
        pl("End of round " + to_string(round) + ". Current HP: " + player.statusString());
        pl("");
    } // end rounds

    // Player survived all rounds
    pl("Congratulations! You survived 15 rounds. Final stats:");
    pl("HP: " + player.statusString());
    pl("Weapon boost: (+" + to_string(player.getWeaponBoost()) + ")");
    pl("Thanks for playing the prototype.");
    bool again = getYesNo("Play again?");
    return again;
}

// -------------------- Main --------------------
int main() {
    srand((unsigned)time(0));
    pl("=== Destiny-style Roguelike (Console) ===");
    pl("");

    while (true) {
        bool playAgain = runPlaythrough();
        if (!playAgain) {
            pl("Goodbye.");
            break;
        }
        pl("\nRestarting...\n");
    }

    return 0;
}
