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
void YouLose();


int main(){
    int storyChoice;
    bool hasLost = false;

    AdventureStart();

    return 0;
}

int GetChoice(int maxChoice){
    int choice = 0;
    while(choice < 1 || choice > maxChoice){
        cout << "What would you like to do?\n";
        cin >> choice;
        if(choice < 1 || choice > maxChoice){
                cout << "Invalid Choice please enter an integer between 1 and " << maxChoice << "\n";
        }
    }
    return choice;
}

void showChoices(string choice1, string choice2, string choice3) {
    // A quick menu. If a choice is empty ("") it's not shown
    // always at least one choice
    // Example: showChoices("run","fight","hide");
    cout << "---- MAKE YOUR CHOICE ----" << endl;
    int num = 1;
    cout << num << ". " << choice1 << endl;
    num++;

    if (choice2 != "") {
        cout << num << ". " << choice2 << endl;
        num++;
    }

    if (choice3 != "") {
        cout << num << ". " << choice3 << endl;
        num++;
    }

}

void AdventureStart(){
    int choice;
    int maxChoice;
    int storyChoice;

    cout << R"(The kingdom's plea echoes in your mind: a relic of untold power lies hidden in the long forgotten tower.
    Few who enter return, and those who do speak only in riddles. With staff in hand and wards upon your robes, you set forth into the night.
    The tower awaits.)" << endl;
    showChoices("Enter the tower through the front door.",
        "Search around the tower for another entrance",
        "Go home. Exploring this tower would be too much work.");
    maxChoice = 3;
    choice = GetChoice(maxChoice);
    if(choice == 1){
        cout << "\nYou walk up to the front of the tower and push the doors open revealing the magnificent interior to you." << endl;
        TowerInterior();
    } else if(choice == 2){
        cout << R"(        You see a ladder leading to a high up window around the back of the tower.
        As you climb the ladder up to the window a gust of wind knocks you off and land on your arm, breaking it.
        You head back home and hope that people don't ask how you injured yourself)" << endl << endl;
        YouLose();
    } else if(choice == 3){
        cout << "\nYou go home to be shamed by your fellow adventurers for your cowardice.\n";
        YouLose();
    }
    

}

void TowerInterior(){
    int choice;
    cout << R"(As you enter the tower you can see the murals of glorius battles etched into the dust covered walls.
    From your surroundings you can tell that this was once a regal structure of great significance to those who came before you.
    As you venture further you come across a grand spiral staircase.)" << endl;

    showChoices("Venture up the stairs to the upper stories",
    "Head down the stairs into the dark cellars below","");
    int max = 2;
    choice = GetChoice(max);

    if(choice == 1){
        cout << "Some Text";
        TowerUpper();
    } 
    else if(choice == 2){
        cout << "Some Text";
        TowerLower();
    }
}

void TowerUpper(){

}

void TowerLower(){

}

void YouLose(){
    cout << "---GAME OVER---\n";
    cout << "---YOU LOSE---\n";
}