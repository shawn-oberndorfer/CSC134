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

    while(tableMultiplier <= 0 || tableMultiplier > 12){
    cout << "What times table (1-12) would you like?" << endl;
    cin >> tableMultiplier;
    if(tableMultiplier <= 0 || tableMultiplier > 12){
        cout << "Not a currently valid table. Please enter a number 1-12." << endl;
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