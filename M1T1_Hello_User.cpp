/*
M1T1 - Hello User
shawn-oberndorfer, 8/25/25

INPUT: run the program
PROCESS: None yet
OUTPUT: return 0 (no error)
SPECIAL FX: Greet the user.
*/

// magic start words
#include <iostream>
using namespace std;

int main(){
    //SFX: Greet User
    // strings hold words
    string first_name = "";

    cout << "Enter your Name" << endl;
    cin >> first_name;
    cout << "Hello, " << first_name << endl;

    //output
    return 0; // no errors
}