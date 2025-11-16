/*
Shawn Oberndorfer
CSC-134
M5LAB1
11/5/25
CYOA Program expanded.
*/
#include <iostream>

using namespace std;

int GetChoice(int);
void showChoices(string choice1, string choice2, string choice3);
void AdventureStart();
void TowerInterior();
void TowerUpper();
void TowerLower();
void TreasureRoom();
void MonsterRoom();
void SecretLibrary();
void YouWin();
void YouLose();

int main() {
    AdventureStart();

    return 0;
}

int GetChoice(int maxChoice) {
    int choice = 0;
    while(choice < 1 || choice > maxChoice) {
        cout << "What would you like to do?\n";
        cin >> choice;
        if(choice < 1 || choice > maxChoice) {
            cout << "Invalid Choice. Please enter an integer between 1 and " << maxChoice << "\n";
        }
    }
    return choice;
}

void showChoices(string choice1, string choice2, string choice3) {
    
    cout << "---- MAKE YOUR CHOICE ----" << endl;
    int num = 1;
    cout << num << ". " << choice1 << endl;
    num++;
    if(choice2 != "") {
        cout << num << ". " << choice2 << endl;
        num++;
    }
    if(choice3 != "") {
        cout << num << ". " << choice3 << endl;
        num++;
    }
}

void AdventureStart() {
    int choice;
    cout << R"(The kingdom's plea echoes in your mind: a relic of untold power lies hidden in the long forgotten tower.
Few who enter return, and those who do speak only in riddles. With staff in hand and wards upon your robes, you set forth into the night.
The tower awaits.)" << endl;

    showChoices("Enter the tower through the front door.",
                "Search around the tower for another entrance",
                "Go home. Exploring this tower would be too much work.");
    choice = GetChoice(3);

    if(choice == 1) {
        cout << "\nYou walk up to the front of the tower and push the doors open revealing the magnificent interior to you.\n";
        TowerInterior();
    } else if(choice == 2) {
        cout << R"(You see a ladder leading to a high up window around the back of the tower.
As you climb the ladder up to the window a gust of wind knocks you off and you land on your arm, breaking it.
You head back home and hope that people don't ask how you injured yourself.)" << endl << endl;
        YouLose();
    } else {
        cout << "\nYou go home to be shamed by your fellow adventurers for your cowardice.\n";
        YouLose();
    }
}

void TowerInterior() {
    int choice;
    cout << R"(As you enter the tower you can see murals of glorious battles etched into the dust-covered walls.
From your surroundings you can tell that this was once a regal structure of great significance.
As you venture further you come across a grand spiral staircase.)" << endl;

    showChoices("Venture up the stairs to the upper stories",
                "Head down the stairs into the dark cellars below",
                "");
    choice = GetChoice(2);

    if(choice == 1) {
        cout << "\nYou ascend the spiral staircase, each step creaking under your weight.\n";
        TowerUpper();
    } else {
        cout << "\nYou descend into the cellar, the air growing colder and damper with each step.\n";
        TowerLower();
    }
}

void TowerUpper() {
    int choice;
    cout << R"(The upper floors are lined with broken windows and collapsed beams.
Yet, at the end of the hallway, two doors remain intact: one carved with runes, the other plain and wooden.)" << endl;

    showChoices("Enter the rune-carved door",
                "Enter the plain wooden door",
                "");
    choice = GetChoice(2);

    if(choice == 1) {
        cout << "\nThe runes glow faintly as you push the door open...\n";
        SecretLibrary();
    } else {
        cout << "\nThe wooden door creaks open to reveal a monstrous guardian!\n";
        MonsterRoom();
    }
}

void TowerLower() {
    int choice;
    cout << R"(The cellar is pitch dark, but your staff glows faintly.
You see two paths: one leading to a heavy iron door, the other to a crumbling archway.)" << endl;

    showChoices("Open the iron door",
                "Step through the crumbling archway",
                "");
    choice = GetChoice(2);

    if(choice == 1) {
        cout << "\nThe iron door resists at first, but finally swings open...\n";
        TreasureRoom();
    } else {
        cout << "\nYou step through the archway and the floor collapses beneath you!\n";
        YouLose();
    }
}

void TreasureRoom() {
    cout << R"(Inside the iron chamber lies the relic: a crystal pulsing with ancient energy.
You carefully lift it, feeling its warmth spread through your body.
The kingdom will rejoice at your success!)" << endl;
    YouWin();
}

void MonsterRoom() {
    cout << R"(The guardian roars, shaking the walls of the tower.
You raise your staff, but the beast is too strong.
With one swipe of its claws, your adventure ends...)" << endl;
    YouLose();
}

void SecretLibrary() {
    cout << R"(You find yourself in a forgotten library, filled with tomes of magic and history.
Among them lies a scroll describing the relic's true power.
Armed with knowledge, you leave the tower wiser than any adventurer before you.)" << endl;
    YouWin();
}

void YouWin() {
    cout << "\n---CONGRATULATIONS---\n";
    cout << "---YOU WIN---\n";
}

void YouLose() {
    cout << "\n---GAME OVER---\n";
    cout << "---YOU LOSE---\n";
}