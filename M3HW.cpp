/*
Shawn Oberndorfer
CSC 134
M3HW - Gold
10/8/2025
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void Question1(){

}

void Question2(){
cout << "Test 2" << endl;
}

void Question3(){
cout << "Test 3" << endl;
}

void Question4(){
    int adden1, adden2, sum, userInput;
    char tryAgainChar;
    bool tryAgainBool = true;
    bool isValid = true;

    while(tryAgainBool == true){

        adden1 = (rand() % 9999) + 1;
        adden2 = (rand() % 9999) + 1;
        cout << "What is the summ of " <<adden1 << " + " << adden2 << "?" << endl;
        sum = adden1 + adden2;
        cin >> userInput;
        if (userInput == sum){
            cout << "Correct!" << endl;
        } 
        else{
            cout << "Sorry your answer is wrong. The correct answer is " << sum << "." << endl;
        }
        do{
        cout << "Would you like to try again? (y/n)" << endl;
        cin >> tryAgainChar;
        if(tryAgainChar == 'Y' || tryAgainChar == 'y'){
            tryAgainBool = true;
        }
        else if(tryAgainChar == 'N' || tryAgainChar == 'n'){
            tryAgainBool = false;
            cout << "Goodbye." << endl;
        }
        else{
            cout << "Invalid Input please enter y/n." << endl;
            isValid = false;
        }
        }while(isValid == false);
        
    }
}

int main(){
    srand(time(0));

    int questionChoice;

    cout << "1. Question 1: Chat Bot" << endl;
    cout << "2. Question 2: Receipt Calculator" << endl;
    cout << "3. Question 3: Choose Your Own Adventure" << endl;
    cout << "4. Question 4: Math Practice" << endl;
    cin >> questionChoice;
    switch(questionChoice){
        case 1:
            Question1();
            break;
        case 2:
            Question2();
            break;
        case 3:
            Question3();
            break;
        case 4:
            Question4();
            break;
        default:
            cout << "Invalid Input" << endl;
    }


    return 0;
}

