/*
Shawn Oberndorfer
CSC 134
M4HW - Gold
10/13/2025
*/
#include <iostream>
using namespace std;

int main(){
    int tableMultiplier = 0;
    int tableMin = 1;
    int tableMax = 12;

    while(tableMultiplier < tableMin || tableMultiplier > tableMax){
    cout << "What times table (" << tableMin << "-" << tableMax << ") would you like?" << endl;
    cin >> tableMultiplier;
    if(tableMultiplier <= tableMin || tableMultiplier > tableMax){
        cout << "Not a currently valid table. Please enter a number " << tableMin << "-" << tableMax << "." << endl;
    }
    }
    cout << "---- " << tableMultiplier << " Times Table ----" << endl;
    cout << endl;
    int i = 1;
    while(i <= 12){
        int sum = tableMultiplier * i;
        cout << tableMultiplier << " times " << i << " = " << sum << endl; 
        i++;
    }

    return 0;
}