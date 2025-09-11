/*
CSC 134
M2HW1 Q1
Shawn Oberndorfer
Start Date 9/10/25
Last Worked On 9/10/2025
*/
#include <iostream>
using namespace std;

int main(){
    
    char   depositConfirm;
    char   withdrawConfirm;
    string accountName;
    double oldAccountBalance;
    double withdrawAmount;
    double depositAmount;
    double newAccountBalance;
    int    accountNumber = 90876;


    cout << "Hello what is the name that your account is under?" << endl;
    cin >> accountName;

    cout << "Welcome " << accountName << ". What is your current account balance?" << endl;
    cin >> oldAccountBalance;

    cout << "Would you like to deposit money into your account? (Enter Y/N)" << endl;
    cin >> depositConfirm;

    if (depositConfirm = "Y")
    {
        cout << "How much money would you like to deposit?" << endl;
        cin >> depositAmount;
        cout << depositAmount << "$ has been deposited into your account." << endl;
    } else 

    cout << "Would you like to withdraw any money from your account? (Enter Y/N)" << endl;
    cin >> withdrawConfirm;

    if (withdrawConfirm = "Y")
    {
        cout << "How much money would you like to withdraw from your account?" << endl;
        cin >> withdrawAmount;
        cout << withdrawAmount << "$ has been withdrawn from your account." << endl;
    } else

    newAccountBalance = oldAccountBalance + depositAmount - withdrawAmount;

    cout << "Account Name:             " << accountName << endl;
    cout << "Account Number:           " << accountNumber << endl;
    cout << "Original Account Balance: " << oldAccountBalance << endl;
    cout << "New Account Balance:      " << newAccountBalance << endl;


    return 0;
}
