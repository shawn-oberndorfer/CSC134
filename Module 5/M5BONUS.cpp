/* 
M5BONUS - Craps Part 2
CSC 134
Shawn Oberndorfer
Start Date 11/2/2025
Last Worked On 11/2/2025
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int roll();
int firstRollResults();
int pointRollResults();
int winCondition();
int gameOver();

int roll1;
int roll2;
int sum;
int point;
int winConditionNum;
int winConditionCheck;
bool gameEnd;
bool moneyConfirm;
string blankSpace;
char moneyConfirm2;

int main()
{
   srand(time(0));
   firstRollResults();
   
   if(gameEnd == true){
    winCondition();
    gameOver();
   }
   else{
    pointRollResults();
    winCondition();
    gameOver();
   }
    return 0;
}

int roll(){
    int myRoll;
    myRoll = (rand() % 6) + 1;
    return myRoll;
}
int firstRollResults(){
    roll1 = roll();
    roll2 = roll();
    sum = roll1 + roll2;

    cout << "ROLL: " << sum << endl;

    if (sum == 7 || sum == 11){
        winConditionCheck = 1;
        gameEnd = true;
    }
    else if(sum == 2 || sum == 3 || sum == 12){
        winConditionCheck = 2;
        gameEnd = true;
    } 
    else if(sum == 4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10){
        point = sum;
        cout << "The point is: " << point << endl;
        cout << "Hit 'enter' to roll again." << endl;
        cin.get();
        gameEnd = false;
    }

    return 0;
}
int pointRollResults(){
    do{
        roll1 = roll();
        roll2 = roll();
        sum = roll1 + roll2;

        cout << "ROLL: " << sum << endl;
        if(sum == point){
            winConditionCheck = 1;
            gameEnd = true;
        } else if(sum == 7){
            winConditionCheck = 2;
            gameEnd = true;
        }else{
            cout << "Roll again." << endl;
            cin.ignore();
            gameEnd = false;
        }

    }while(gameEnd == false);

    return 0;
}
int winCondition(){
    if(winConditionNum == winConditionCheck){
        cout << "Congrats You Win!" << endl;
    }
    else{
        cout << "Sorry you lose." << endl;
    }
    return 0;
}
int gameOver(){
    cout << "------Game Over------" << endl;
    cout << "Thank You For Playing" << endl;
    return 0;
}