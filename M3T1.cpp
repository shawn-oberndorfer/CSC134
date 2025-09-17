/*
Shawn Oberndorfer
CSC 134
M3T1
9/17/25
*/
#include <iostream>
using namespace std;

int main(){

    double length1, length2, width1, width2;
    double area1, area2;
    cout << "Enter the length and width of two rectangles." << endl;
    cout << "First rectangle." << endl;
    cout << "Length: ";
    cin >> length1;
    cout << "Width: ";
    cin >> width1;
    cout << "Second rectangle." << endl;
    cout << "Length: ";
    cin >> length2;
    cout << "Width: ";
    cin >> width2;

    area1 = length1 * width1;
    area2 = length2 * width2;

    cout << "The area of the first rectangle is " << area1 << " and the area of the second is " << area2 << "." << endl;

    if(area1 > area2) {
        cout << "The first rectangle is larger." << endl;
    } else if(area1 < area2) {
        cout << "The second rectangle is larger." << endl;
    }

    return 0;
}

