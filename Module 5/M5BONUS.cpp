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

using namespace std;

int roll();


int main()
{
    int roll1;
    int roll2;
    int point;
    
    srand(time(0));

    roll1 = roll();
    roll2 = roll();
    int sum = roll1 + roll2;

    cout << "ROLL: " << sum << endl;

    if (sum == 7 || sum == 11){
        cout <<"You Win!" << endl;
    }
    else if(sum == 2 || sum == 3 || sum == 12){
        cout << "You Lose" << endl;
    } 
    else if(sum == 4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10){
            point = sum;
            cout << "Your point is: " << point << endl;
    }


    return 0;
}

int roll(){
    int myRoll;
    myRoll = (rand() % 6) + 1;
    return myRoll;
}