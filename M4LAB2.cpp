/*
Shawn Oberndorfer
CSC 134
M4LAB2
Program draws a rectangle
*/
#include <iostream>
using namespace std;

int main(){
/*
    int length = 10;
    int height  = 10 ;
    string tile = "🎮";

    for (int i = 0; i < length; i++) {
        cout << tile;
    }
    cout << endl;


    int count = 0;
    while (count < length) {
        cout << tile;
        count++;
    }
    cout << endl;

    for(int i = 0;  i < height; i++){
        cout << tile << endl;
    }
*/
    int length = 10;
    int height  = 10 ;
    string tile = "🎮";

    cout << "Draw a Rectangle" << endl;
    cout << "Length: " << endl;
    cin >> length;
    cout << "Height: " << endl;
    cin >> height;
    cout << endl << endl;
    cout << "Rectangle "  << length << " x " << height << endl;

    for(int i=0; i < height; i++) {
        cout << endl;
        for(int j=0; j< length; j++){
            cout << tile;
        }
    }
    cout << endl;
    return 0;
}