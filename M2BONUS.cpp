/*
1. Given a rectangle with height 8 and width 10, calculate and print the area. (This one is most similar to "Apple Orchard", except these are both of type int. The formula "Area equals length times width" will be useful.)
2. Assume a product is sold for $99.99, and sales tax is 8%. Display the product price, the amount of sales tax, and then the final cost including sales tax. (For handling monetary values, and percentages, you will want to use the double type. "Percent" is "per cent", meaning a 8% sales tax in numerical terms is 0.08 )
3. Assume a pizza is 12 inches in diameter. Using the standard formula, calculate and display the area of that pizza. (You'll need to determine what common geometrical shape best fits a pizza, then look up the formula for area for that shape.)
4. If the pizza from question 3 is cut into 8 pieces, what is the area of each piece?
As usual, upload a zip containing your source code as well as a screenshot of your running program. Your file should be named in the format M1BONUS_Lastname.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    //Variables
    int recHeight = 8, recWidth = 10, recArea;
    double productCost = 99.99, productTax, taxPercent = 0.08, finalCost;
    double pizzaDiameter = 12, pizzaArea;
    
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




    return 0;
}