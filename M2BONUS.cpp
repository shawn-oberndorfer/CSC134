/*
4. If the pizza from question 3 is cut into 8 pieces, what is the area of each piece?
As usual, upload a zip containing your source code as well as a screenshot of your running program. Your file should be named in the format M1BONUS_Lastname.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    //Variables
    int recHeight = 8, recWidth = 10, recArea;
    double productCost = 99.99, productTax, taxPercent = 0.08, finalCost;
    double pizzaDiameter = 12, pizzaArea, pizzaRadius, sliceArea;
    
    cout << "-----Problem 1-----" << endl;
    recArea = recHeight * recWidth;
    cout << "The area of the rectangle is " << recArea << "." << endl;
    cout << endl;
    cout << "-----Problem 2-----" << endl;
    productTax = productCost * taxPercent;
    finalCost = productCost + productTax;
    cout << setprecision(2) << fixed; 
    cout << "Subtotal: " << productCost << endl;
    cout << "Tax:      " << productTax << endl;
    cout << "Total:    " << finalCost << endl;
    cout << endl;
    cout << "-----Problem 3-----" << endl;
    pizzaRadius = pizzaDiameter / 2;
    pizzaArea = pizzaRadius * pizzaRadius * M_PI;
    cout << "The area of the pizza is " << pizzaArea << "." << endl;
    cout << endl;
    cout << "-----Problem 4 -----" << endl;
    sliceArea = pizzaArea / 8;
    cout << "The area of each slice is " << sliceArea << "." << endl;




    return 0;
}