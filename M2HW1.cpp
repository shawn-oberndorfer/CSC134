/*
CSC 134
M2HW1 - Gold
Shawn Oberndorfer
Start Date 9/10/25
Last Worked On 9/15/2025
*/
#include <iostream>
#include <cmath>
using namespace std;

    int  programSelect;
    char programRunAgain = 'Y';

    void welcome();
    void altWelcome();
    void ending();
    void bankAccount();
    void updatedCrates();
    void pizzaParty();
    void cheer();

int main() {

    welcome();

    do{
    if(programSelect == 1){
        bankAccount();
        ending();
    } else if(programSelect == 2){
        updatedCrates();
        ending();
    } else if(programSelect == 3){
        pizzaParty();
        ending();
    } else if(programSelect == 4){
        cheer();
        ending();
    } else if(programSelect > 4){
        altWelcome();
    }


    }while (programRunAgain == 'Y');
    cout << "Goodbye" << endl;
    return 0;
}
void altWelcome(){
    cout << "The number you entered is invalid please enter a number 1-4." << endl;
    cout << "1. Bank Account" << endl;
    cout << "2. Crate Calculator" << endl;
    cout << "3. Pizza Calculator" << endl;
    cout << "4. Cheer Program" << endl;
}
void welcome() {
    cout << "What program are you trying to access?" << endl;
    cout << "1. Bank Account" << endl;
    cout << "2. Crate Calculator" << endl;
    cout << "3. Pizza Calculator" << endl;
    cout << "4. Cheer Program" << endl;
    cin >> programSelect;
}
void ending(){
    programRunAgain = 'N';
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Would you like to start another program? (Y/N)" << endl;
    cin >> programRunAgain;
    programRunAgain = toupper(programRunAgain);
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

void updatedCrates(){

    const double COST_PER_CUBIC_FOOT   = 0.3;
    const double CHARGE_PER_CUBIC_FOOT = 0.52;

    double crate_height          = 0;
    double crate_depth           = 0;
    double crate_width           = 0;
    double crate_volume          = 0;
    double crate_production_cost = 0;
    double crate_sale_price      = 0;
    double crate_profit          = 0;

    cout << "What is the height of you crate in feet?" << endl;
    cin >> crate_height;
    cout << "What is the depth of your crate in feet?" << endl;
    cin >> crate_depth;
    cout << "What is the width of your crate in feet?" << endl;
    cin >> crate_width;

    crate_volume = crate_height * crate_depth * crate_width;
    crate_production_cost = crate_volume * COST_PER_CUBIC_FOOT;
    crate_sale_price = crate_volume * CHARGE_PER_CUBIC_FOOT;
    crate_profit = crate_sale_price - crate_production_cost;

    cout << "Each crate has a volume of " << crate_volume << " cubic feet." << endl;
    cout << "The cost to make each crate is $" << crate_production_cost << "." << endl;
    cout << "The sale price for each crate is $" << crate_sale_price << "." << endl;
    cout << "The profit per crate sold would be $" << crate_profit << "." << endl;

}

void pizzaParty(){

}

void cheer(){
string letsGo    = "Let's Go";
string school    = "FTCC"; 
string team      = "Trojans";
string cheerOne  = letsGo + " " + school;
string cheerTwo  = letsGo + " " + team;

cout << cheerOne << endl;
cout << cheerOne << endl;
cout << cheerOne << endl;
cout << cheerTwo << endl;
}