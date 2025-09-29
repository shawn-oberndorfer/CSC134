/*
Shawn Oberndorfer
CSC 134
M3LAB2
9/29/2025
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void letterGrader();
void combat();


int main(){

    letterGrader();


    return 0;
}


void letterGrader(){
    
    double numberGrade;
    string letterGrade;
    bool isValid = false;

    const double A_Grade = 90;
    const double B_Grade = 80;
    const double C_Grade = 70;
    const double D_Grade = 60;
    const double F_Grade = 60;

    do{

        cout << "Enter a number grade from 0-100: " << endl;
        cin >> numberGrade;

        if(numberGrade >= 101){
            letterGrade = "A";
            cout << "Wow that is an impressive grade!" << endl;
            isValid = true;
        }else if(numberGrade >= A_Grade && numberGrade < 101){
            letterGrade = "A";
            isValid = true;
        }else if(numberGrade >= B_Grade && numberGrade < 101){
            letterGrade = "B";
            isValid = true;
        }else if(numberGrade >= C_Grade && numberGrade < 101){
            letterGrade = "C";
            isValid = true;
        }else if(numberGrade >= D_Grade && numberGrade < 101){
            letterGrade = "D";
            isValid = true;
        }else if(numberGrade <= F_Grade && numberGrade >= 0){
            letterGrade = "F";
            isValid = true;
        }else{
            cout << "Not a valid input." << endl;
            isValid = false;
        }

    }while(isValid == false);
    
    cout << "A number grade of " << numberGrade << " is a letter grade: " << letterGrade << "." << endl;

}


void combat(){

}