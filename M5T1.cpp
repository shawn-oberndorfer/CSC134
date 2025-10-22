/*
Shawn Oberndorfer
CSC 134
M5T1 - Basic Functions
10/22/25
*/

#include <iostream>
using namespace std;


int getTheAnswer(){
   return 42;
}

void sayHello(){
    cout << "Welcome to the number doubler program!" << endl;

}

double doubleANumber(double myNum){
    double answer = myNum * 2;
    return answer;
}

int main(){

    double myNum;
    int    otherNum;


    sayHello();

    cout << "Please enter any number." << endl;
    cin >> myNum;

    cout << "Double the number is: " << doubleANumber(myNum) << endl; 
    cout << "But the only real answer is " << getTheAnswer() << endl; 

    return 0;
}

