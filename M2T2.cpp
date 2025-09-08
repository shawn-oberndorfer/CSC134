/*
CSC 134
M2T2
Shawn Oberndorfer
9/8/2025
Recipt Program
This program prints a recipt for a simple meal.
*/
#include <iostream>
using namespace std;

int main(){

    const double meal_price  = 5.99;
    const double tax_percent = 0.08;
    double tax_amount  = 0;
    double total_cost  = 0;
    
    tax_amount = meal_price * tax_percent;
    total_cost = meal_price + tax_amount;


    cout << "Subtotal: " << meal_price << endl;
    cout << endl;
    cout << "Tax 1: " << tax_percent << endl;
    cout << endl;
    cout << "Total: " << total_cost << endl;

    
    
    
    
    return 0;
}