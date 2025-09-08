/*
CSC 134
M2LAB
Shawn Oberndorfer
Start Date 9/8/2025
Crate Calculator
A program that will take the dimenions of a crate and find its cost to make, sale price, and profit margin based off of set variables.
*/
#include <iostream>
using namespace std;

int main(){

    const double COST_PER_CUBIC_FOOT   = 0.23;
    const double CHARGE_PER_CUBIC_FOOT = 0.5;

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

    return 0;
}