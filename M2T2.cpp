/*
CSC 134
M2T2
Shawn Oberndorfer
9/8/2025
Recipt Program
This program prints a recipt for a simple meal.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){

    const double meal_price  = 5.99;
    const double tax_percent = 0.08;

    double tax_amount         = 0;
    double total_cost         = 0;
    double total_cost_rounded = 0;
    double tax_amount_rounded = 0;
    
    tax_amount = meal_price * tax_percent;
    total_cost = meal_price + tax_amount;

    total_cost_rounded = round(total_cost * 100.0) / 100.0;
    tax_amount_rounded = round(tax_amount * 100.0) / 100.0;


    cout << "Subtotal: $" << meal_price << endl;
    cout << endl;
    cout << "Tax 1:    $" << tax_amount_rounded << endl;
    cout << endl;
    cout << "Total:    $" << total_cost_rounded << endl;

    
    
    
    
    return 0;
}