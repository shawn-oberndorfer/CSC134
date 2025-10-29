/*
SHawn Oberndorfer
CSC 134
M5LABA
10/29/2025
*/
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
const int NUMCLASSES = 3;
const int MAXLEVEL = 10;

struct classes {
    std::string Name;
    int maxHP;
    int meleeAttack;
    int rangeAttack;
    int abilityAttack;
    std::string description;
};

classes characterClasses[NUMCLASSES] = {
    {"Titan", 225, 15, 10, 13, "The best class. High melee damage and resist."},
    {"Hunter", 175, 12, 15, 10, "Your a weirdo if your playing hunter. Best to play at a range."},
    {"Warlock", 200, 10, 13, 15, "Get on Well. JK, A more balanced mid range class."}
};

string equipment[5] = {
    "Glimmer",
    "Heavy Ammo Brick",
    "Gjallarhorn",
    "Heart of Inmost Light",
    "Khovostov"
};

string enemyAttackType[3] = {"Close Range", "Mid Range", "Long Range",};
int    titanDefense[3] = {5, 2, 0};
int    HunterDefense[3] = {0, 2, 5};
int    WarlockDefense[3] = {2, 4, 2};


void CharacterSelect(int&);
void HealthRegen(int&, int);
void LevelUpChart(int);
void InventorySearch();

int main(){

    int currentHP = 100;
    int characterChoice;

    CharacterSelect(characterChoice);

    HealthRegen(currentHP, characterChoice);

    LevelUpChart(characterChoice);

    InventorySearch();

    return 0;
}

void CharacterSelect(int& characterChoice){
    bool isValid = false;
    for (int i = 0; i < NUMCLASSES; i++) {
        cout << (i + 1) << ". " << characterClasses[i].Name << "\n";
        cout << "   HP: " << characterClasses[i].maxHP 
             << " | Attack: (Melee) " << characterClasses[i].meleeAttack << " (Ability) " << characterClasses[i].abilityAttack  << " (Ranged) "<< characterClasses[i].rangeAttack << "\n";
        cout << "   " << characterClasses[i].description << "\n\n";
    }
    do{
        cout << "What class would you like to play as?\n";
        cin >> characterChoice;
        if(characterChoice < 4 && characterChoice > 0){
            isValid = true;
        }else{
            isValid = false;
        }

    }while(isValid == false);
    characterChoice = characterChoice - 1;
}

void HealthRegen(int& currentHP, int characterChoice){

    
cout << "Starting health: " << currentHP << "/" << characterClasses[characterChoice].maxHP << endl;
cout << "Resting to recover health..." << endl << endl;

while(currentHP < characterClasses[characterChoice].maxHP){
    currentHP = currentHP + 10;
    if(currentHP > characterClasses[characterChoice].maxHP){
        currentHP = characterClasses[characterChoice].maxHP;
    }
    cout << "Health: " << currentHP << "/" << characterClasses[characterChoice].maxHP << endl;
    this_thread::sleep_for(std::chrono::milliseconds(1250));
}
cout << "Fully Recovered!" << endl;
}

void LevelUpChart(int characterChoice){
    const int maxHP      = characterClasses[characterChoice].maxHP;
    const int maxMelee   = characterClasses[characterChoice].meleeAttack;
    const int maxAbility = characterClasses[characterChoice].abilityAttack;
    const int maxRange   = characterClasses[characterChoice].rangeAttack;

    cout << "Level |  HP  | Melee | Range | Ability |\n";
    if(characterChoice == 0){
        for (int level = 0; level < MAXLEVEL; level++) {
            cout << "  " << level << "   |  " << (maxHP + (level * 7)) << " |   " << (maxMelee + (level * 2)) << "  |  " << (maxRange + (level * 1)) << "   |    " << (maxAbility + (level * 1)) << "   |\n";
        }
    }
    else if(characterChoice == 1){
        for (int level = 0; level < MAXLEVEL; level++) {
            cout << "  " << level << "   |  " << (maxHP + (level * 5)) << " |   " << (maxMelee + (level * 1)) << "  |  " << (maxRange + (level * 2)) << "   |    " << (maxAbility + (level * 1)) << "   |\n";
        }
    }
    else if(characterChoice == 2){
        for (int level = 0; level < MAXLEVEL; level++) {
            cout << "  " << level << "   |  " << (maxHP + (level * 6)) << " |   " << (maxMelee + (level * 1)) << "  |  " << (maxRange + (level * 1)) << "   |    " << (maxAbility + (level * 2)) << "   |\n";
        }
    }
    cout << "\n";
}

void InventorySearch(){
    
    cout << "=== YOUR INVENTORY ===" << endl;
    for (int i = 0; i < 5; i++){
        cout << (i+1) << ". " << equipment[i] << endl;
    }



    cout << "======================" << endl << endl;

    string searchTerm;
    cout << "Enter item to search for: ";
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    int position = -1;

    HINT: for (int i = 0; i < 5; i++){
        if (equipment[i] == searchTerm){
            found = true;
            position = i;
            break;
        }
    }


    if (found){
        cout << "Found \"" << searchTerm << "\" in slot " 
            << (position + 1) << "!" << endl;
    }
    else{
        cout << "\"" << searchTerm << "\" not found in inventory." << endl;
    }
}
