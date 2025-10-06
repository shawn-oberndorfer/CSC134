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

/*
EXERCISE 1: HEALTH REGENERATION (30 points)

CONCEPT: while loop - repeat until condition changes

REQUIREMENTS:
1. Start with health = 30, maxHealth = 100
2. Use a while loop to regenerate health by 10 each iteration
3. Display current health after each regeneration
4. Display a "Fully Recovered!" message when done
5. Add a visual health bar using characters (optional bonus)

SAMPLE OUTPUT:
Resting to recover health...
Health: 40/100  [████░░░░░░]
Health: 50/100  [█████░░░░░]
Health: 60/100  [██████░░░░]
Health: 70/100  [███████░░░]
Health: 80/100  [████████░░]
Health: 90/100  [█████████░]
Health: 100/100 [██████████]
Fully recovered!
================================================================================
*/
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

/*
EXERCISE 2: LEVEL UP STATS (35 points)

CONCEPT: for loop - count through a sequence

REQUIREMENTS:
1. Display how character stats increase from level 1 to level 10
2. Use a for loop to iterate through levels
3. Calculate each stat based on level (formulas provided)
4. Display in a formatted table
5. Show total stat growth at the end

FORMULAS:
- Strength = baseStrength (10) + (level * 2)
- Dexterity = baseDexterity (8) + (level * 3)
- Intelligence = baseIntelligence (12) + (level * 1)

SAMPLE OUTPUT:
=== CHARACTER STAT GROWTH ===
Level |  STR  |  DEX  |  INT
------|-------|-------|-------
  1   |   12  |   11  |   13
  2   |   14  |   14  |   14
  3   |   16  |   17  |   15
...
 10   |   30  |   38  |   22
==============================
Total Growth: STR +20, DEX +30, INT +10
================================================================================
*/
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

/*
EXERCISE 3: INVENTORY SYSTEM (35 points)

CONCEPT: arrays + loops - managing collections

REQUIREMENTS:
1. Create an array of 5 equipment items
2. Display all items in a numbered list
3. Ask user to search for an item by name
4. Use a loop to search through the array
5. Display whether item was found and at what position
6. Handle case-insensitive search (optional bonus)

SAMPLE OUTPUT:
=== YOUR INVENTORY ===
1. Iron Sword
2. Leather Armor
3. Health Potion
4. Magic Ring
5. Rope
======================

Enter item to search for: Health Potion
Found "Health Potion" in slot 3!

Enter item to search for: Diamond
"Diamond" not found in inventory.
================================================================================
*/
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

/*
TESTING CHECKLIST:

Exercise 1:
[ ] Health starts at 30
[ ] Health increases by 10 each loop
[ ] Loop stops at exactly 100
[ ] "Fully recovered!" message displays
[ ] No infinite loop!

Exercise 2:
[ ] Stats calculate correctly for each level
[ ] Table is formatted and readable
[ ] All 10 levels display
[ ] Total growth is calculated correctly

Exercise 3:
[ ] All 5 items display with numbers
[ ] Search finds items that exist
[ ] Search correctly reports items not found
[ ] Position number is correct (1-5, not 0-4)
[ ] Program doesn't crash on any input
*/