/*
CSC 134
M2HW1 Q1 - Gold
Shawn Oberndorfer
Start Date 9/10/25
Last Worked On 9/10/2025
*/
#include <iostream>
#include <cmath>
using namespace std;

    int  programSelect;
    char programRunAgain = 'N';

int main() {
    welcome();

    if(programSelect = 1){
        bankAccount();

    }


    

    return 0;
}
void welcome() {
    cout << "Welcome what program are you trying to access?" << endl;
    cout << "1. Bank Account" << endl;
    cout << "2." << endl;
    cout << "3." << endl;
    cout << "4." << endl;
    cin >> programSelect;
}
void ending(){
    cout << "Would you like to start another program?" << endl;
    cin >> programRunAgain;
}
void bankAccount() {
    char   depositConfirm;
    char   depositConfirmUpper;
    char   withdrawConfirm;
    char   withdrawConfirmUpper;
    string accountName;
    double oldAccountBalance = 0.0;
    double withdrawAmount = 0.0;
    double depositAmount = 0.0;
    double newAccountBalance = 0.0;
    int    accountNumber = 90876;


    cout << "Hello what is the name that your account is under?" << endl;
    cin >> accountName;

    cout << "Welcome " << accountName << ". What is your current account balance?" << endl;
    cin >> oldAccountBalance;

    cout << "Would you like to deposit money into your account? (Enter Y/N)" << endl;
    cin >> depositConfirm;

    depositConfirmUpper = toupper(depositConfirm);

    if (depositConfirm == 'Y')
    {
        cout << "How much money would you like to deposit?" << endl;
        cin >> depositAmount;
        cout << depositAmount << "$ has been deposited into your account." << endl;
        cout << endl;
    } 

    cout << "Would you like to withdraw any money from your account? (Enter Y/N)" << endl;
    cin >> withdrawConfirm;

    withdrawConfirmUpper = toupper(withdrawConfirm);

    if (withdrawConfirm == 'Y')
    {
        cout << "How much money would you like to withdraw from your account?" << endl;
        cin >> withdrawAmount;
        cout << withdrawAmount << "$ has been withdrawn from your account." << endl;
    }

    double roundedOldAccountBalance = round(oldAccountBalance * 100) / 100;

    newAccountBalance = (oldAccountBalance + depositAmount) - withdrawAmount;

    double roundedNewAccountBalance = round(newAccountBalance * 100) / 100;

    cout << "Account Name:             " << accountName << endl;
    cout << "Account Number:           " << accountNumber << endl;
    cout << "Original Account Balance: $" << roundedOldAccountBalance << endl;
    cout << "New Account Balance:      $" << roundedNewAccountBalance << endl;
}
