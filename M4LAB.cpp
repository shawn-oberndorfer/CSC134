#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void exercise1_healthRegen();
void exercise2_levelUpStats();
void exercise3_inventorySystem();

int main()
{
int choice;

cout << "==================================" << endl;
cout << "    LAB 7: LOOP FUNDAMENTALS      " << endl;
cout << "==================================" << endl;
cout << "1. Exercise 1: Health Regeneration" << endl;
cout << "2. Exercise 2: Level Up Stats" << endl;
cout << "3. Exercise 3: Inventory System" << endl;
cout << "4. Run All Exercises" << endl;
cout << "5. Exit" << endl;
cout << "==================================" << endl;
cout << "Choice: ";
cin >> choice;

switch(choice)
{
    case 1:
        exercise1_healthRegen();
        break;
    case 2:
        exercise2_levelUpStats();
        break;
    case 3:
        exercise3_inventorySystem();
        break;
    case 4:
        exercise1_healthRegen();
        cout << endl;
        exercise2_levelUpStats();
        cout << endl;
        exercise3_inventorySystem();
        break;
    case 5:
        cout << "Goodbye!" << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
}

return 0;
}


void exercise1_healthRegen()
{
cout << "\n=== EXERCISE 1: HEALTH REGENERATION ===" << endl;

int health = 30;
int maxHealth = 100;

cout << "Starting health: " << health << "/" << maxHealth << endl;
cout << "Resting to recover health..." << endl << endl;

while(health < maxHealth){
    health = health + 10;
    cout << "Health: " << health << "/" << maxHealth << endl;
}
cout << "Fully Recovered!" << endl;
}


void exercise2_levelUpStats()
{
cout << "\n=== EXERCISE 2: LEVEL UP STATS ===" << endl;

// Base stats at level 0
const int BASE_STR = 10;
const int BASE_DEX = 8;
const int BASE_INT = 12;
int level = 1;
int maxLevel = 10;
int str, dex, Int;

str = BASE_STR + (level * 2);
dex = BASE_DEX + (level * 3);
Int = BASE_INT + (level * 1);

// TODO: Display table header
cout << " Level |  STR  |  DEX  |  INT  " << endl;
cout << "-------|-------|-------|-------" << endl;
while(level <= maxLevel){
    cout << "   " << level << "   |   " << str << "  |   " << dex << "  |   " << Int << "   " << endl;
    str = BASE_STR + (level * 2);
    dex = BASE_DEX + (level * 3);
    Int = BASE_INT + (level * 1);
    level++;
}
int strDif, dexDif, IntDif;

strDif = 28-12;
dexDif = 35-11;
IntDif = 21-13;
cout << "You gained " << strDif << " strength, " << dexDif << " dexterity, and " << IntDif << " intellect." << endl;
}


void exercise3_inventorySystem()
{
cout << "\n=== EXERCISE 3: INVENTORY SYSTEM ===" << endl;

// TODO: Create your equipment array with 5 items
string equipment[5] = {
    "Iron Sword",
    "Leather Armor",
    "Health Potion",
    "Magic Ring",
    "Rope"
};

// TODO: Display all items using a for loop
cout << "=== YOUR INVENTORY ===" << endl;
for (int i = 0; i < 5; i++)
{
    cout << (i+1) << ". " << equipment[i] << endl;
}



cout << "======================" << endl << endl;

// TODO: Get search term from user
string searchTerm;
cout << "Enter item to search for: ";
cin.ignore();  // Clear the input buffer
getline(cin, searchTerm);

// TODO: Search for the item using a loop
bool found = false;
int position = -1;

HINT: for (int i = 0; i < 5; i++)
{
    if (equipment[i] == searchTerm)
    {
        found = true;
        position = i;
        break;
    }
}



// TODO: Display search results
if (found)
{
    cout << "Found \"" << searchTerm << "\" in slot " 
         << (position + 1) << "!" << endl;
}
else
{
    cout << "\"" << searchTerm << "\" not found in inventory." << endl;
}
}