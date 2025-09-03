/*
CSC 134
M2T1
Shawn Oberndorfer
9/3/2025
Pokemon Card Sales Program
This is a duplicate program of M1LAB.
*/

#include <iostream>
using namespace std;

int main(){
string item_name    = "Pokemon Card";
int    num_items    = 1000;
int    wanted_items = 0;
double cost_per     = 5.99;

cout << "Welcome to the " << item_name << " store!" << endl;
cout << "Each " << item_name << " is $" << cost_per << endl;
cout << "We have " << num_items << " cards in stock." << endl;

double inventory_cost = num_items * cost_per;

cout << "Buying them all would cost $" << inventory_cost << endl;
cout << "How many " << item_name << "s would you like to buy?" << endl;
cin >> wanted_items;

double total_cost = wanted_items * cost_per;

cout << "If you were to buy " << wanted_items << " " << item_name << "s your total cost would be $" << total_cost << endl;
cout << "Thank you for shopping with us today!" << endl;


return 0;
}