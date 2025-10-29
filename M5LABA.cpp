#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
const int NUMCLASSES = 3;
const int MAXLEVEL = 10;

string classNames[NUMCLASSES] = {"Titan", "Hunter", "Warlock"};
int    classMaxHP[NUMCLASSES] = {225, 175, 200};
int    classMeleeAttack[NUMCLASSES] = {15, 12, 10};
int    classRangeAttack[NUMCLASSES] = {10, 15, 13};
int    classAbilityAttack[NUMCLASSES] = {13, 10, 15};
string classDescriptions[NUMCLASSES] = {
    "The best class. High melee damage and resist.",
    "Your a weirdo if your playing hunter. Best to play at a range.",
    "Get on Well. JK, A more balanced mid range class."
};

string attackDistance[3] = {"Close Range", "Mid Range", "Long Range",};
int    titanDefense[3] = {5, 2, 0};
int    HunterDefense[3] = {0, 2, 5};
int    WarlockDefense[3] = {2, 4, 2};


void CharacterSelect(int&);
void HealthRegen(int&, int);
void LevelUpChart(int);

int main(){

    int currentHP = 100;
    int characterChoice;

    CharacterSelect(characterChoice);

    HealthRegen(currentHP, characterChoice);


    return 0;
}

void CharacterSelect(int& characterChoice){
    bool isValid = false;
    for (int i = 0; i < NUMCLASSES; i++) {
        cout << (i + 1) << ". " << classNames[i] << "\n";
        cout << "   HP: " << classMaxHP[i] 
             << " | Attack: (Melee) " << classMeleeAttack[i] << " (Ability) " << classAbilityAttack[i]  << " (Ranged) "<< classRangeAttack[i] << "\n";
        cout << "   " << classDescriptions[i] << "\n\n";
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

    
cout << "Starting health: " << currentHP << "/" << classMaxHP[characterChoice] << endl;
cout << "Resting to recover health..." << endl << endl;

while(currentHP < classMaxHP[characterChoice]){
    currentHP = currentHP + 10;
    if(currentHP > classMaxHP[characterChoice]){
        currentHP = classMaxHP[characterChoice];
    }
    cout << "Health: " << currentHP << "/" << classMaxHP[characterChoice] << endl;
    this_thread::sleep_for(std::chrono::milliseconds(1250));
}
cout << "Fully Recovered!" << endl;
}

void LevelUpChart(int characterChoice){
    cout << "Level |  HP  | Melee | Range | Ability |\n";
    for (int i = 0; i < MAXLEVEL; i++) {
        cout << "   " << i << "   |  " << classMaxHP[characterChoice];
    }
}