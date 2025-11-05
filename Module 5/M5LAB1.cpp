/*
Shawn Oberndorfer
CSC-134
M5LAB1
CYOA Program expanded.
*/
#include <iostream>

using namespace std;

int GetChoice(int);
int AdventureStart();
void YouLose();


int main(){
    int storyChoice;
    bool hasLost = false;

    storyChoice = AdventureStart();

    cout << storyChoice;

    switch(storyChoice){
        case 1:
            cout << "\nYou walk up to the front of the tower and push the doors open revealing the magnificent interior to you.";
            break;
        case 2:
            cout << "\nYou see a ladder leading to a high up window around the bock of the tower.\n As you climb the ladder up to the window a gust of wind knocks you off and land on your arm, breaking it.";
            cout << "\nYou head back home and hope that people don't ask how you injured yourself\n\n";
            hasLost = true;
            break;
        case 3:
            cout << "\nYou go home to be shamed by your fellow adventurers for your cowardice.\n";
            hasLost = true;
            break;
    }
    if(hasLost == false){
        //story continues here
    } 
    else{
        YouLose();
    }

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

int AdventureStart(){
    int choice;
    int maxChoice;
    int storyChoice;

    cout << "Story Text\n";
    cout << "1: Enter the tower through the front door.\n2: Search around the tower for another entrance\n3: Go home. Exploring this tower would be too much work.\n";
    maxChoice = 3;
    choice = GetChoice(maxChoice);
    switch(choice){
        case 1:
            cout << "Outcome 1\n";
            storyChoice = 1;
            break;
        case 2:
            cout << "Outcome 2\n";
            storyChoice = 2;
            break;
        case 3:
            cout << "Outcome 3\n";
            storyChoice = 3;
            break;
        default:
            cout << "Hey! You shouldn't be able to see this text.\n";
    }


    return storyChoice;
}

void YouLose(){
    cout << "---GAME OVER---\n";
    cout << "---YOU LOSE---\n";
}