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
   string answer;

    cout << "Hey! I'm your friendly C++ chatbot." << endl;
    cout << "Quick question: Do you like pizza? Type yes or no." << endl;

    cin >> answer;

    if (answer == "yes" || answer == "Yes") {
        cout << "Excellent choice! You officially have good taste." << endl;
    }
    else if (answer == "no" || answer == "No") {
        cout << "What?! How could you not like pizza. Are you even human?" << endl;
    }
    else {
        cout << "I'll take that as a maybe." << endl;
    }
    cout << "Well now that I know a little more about you." << endl;
    cout << "How has your day been? Type yes or no." << endl;

    cin >> answer;

    if (answer == "yes" || answer == "Yes") {
        cout << "Glad to hear it. I hope it stays that way." << endl;
    }
    else if (answer == "no" || answer == "No") {
        cout << "I am so sorry to hear that. Don't worry though as there are always brighter days ahead." << endl;
    }
    else {
        cout << "Well either way I hope you are having a good day." << endl;
    }
    cout << "Anyways wouldn't you say this conversation has totally been worthy of a 100." << endl;
    cout << "Type yes or no." << endl;

    cin >> answer;

    if (answer == "yes" || answer == "Yes") {
        cout << "Phew. Well I am glad that we both can agree on that." << endl;
    }
    else if (answer == "no" || answer == "No") {
        cout << "Oh come on have you not enjoyed my company." << endl;
    }
    else {
        cout << "I'll take that as a yes." << endl;
    }
    cout << "It has been nice talking with you. Goodbye." << endl;
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
    bool runAgain = true;
    bool isValid  = false;
    char runAgainChar;

    do{
        do{
            cout << "1. Question 1: Chat Bot" << endl;
            cout << "2. Question 2: Receipt Calculator" << endl;
            cout << "3. Question 3: Choose Your Own Adventure" << endl;
            cout << "4. Question 4: Math Practice" << endl;
            runAgain = false;
            cin >> questionChoice;
            switch(questionChoice){
                case 1:
                    Question1();
                    isValid = true;
                    break;
                case 2:
                    Question2();
                    isValid = true;
                    break;
                case 3:
                    Question3();
                    isValid = true;
                    break;
                case 4:
                    Question4();
                    isValid = true;
                    break;
                default:
                    cout << "Invalid Input. Please enter a number 1-4." << endl;
                    isValid = false;
            }
        }while(isValid == false);
        cout << "Would you like to run another program? (y/n)" << endl;
        do{
            cin >> runAgainChar;
            if(runAgainChar == 'Y' || runAgainChar == 'y'){
                runAgain = true;
            }
            else if(runAgainChar == 'N' || runAgainChar == 'n'){
                runAgain = false;
                cout << "Goodbye." << endl;
            }
            else{
                cout << "Invalid Input please enter y/n." << endl;
                isValid = false;
            }
        }while(isValid == false);
    }while(runAgain == true);


    return 0;
}

