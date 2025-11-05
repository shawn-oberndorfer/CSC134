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


int main(){
    int storyChoice;

    storyChoice = AdventureStart();

    cout << storyChoice;


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
    cout << "Choice 1, 2, and 3.\n";
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
            cout << "Hey you shouldn't be able to see this text.\n";
    }


    return storyChoice;
}