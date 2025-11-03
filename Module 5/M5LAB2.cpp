/*
CSC 134
M5LAB2
Shawn Oberndorfer
11/3/2025
*/
#include <iostream>
using namespace std;

int getLength();
int getWidth();
int getArea(int, int);
void displayData(int, int, int);

int main()
{
	double length,    // The rectangle's length
           width,     // The rectangle's width
           area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}

int getLength(){
    int length; 
    cout << "Enter the length of your rectangle.\n";
    cin >> length;
    return length;
}
int getWidth(){
    int width; 
    cout << "Enter the width of your rectangle.\n";
    cin >> width;
    return width;
}
int getArea(int length, int width){
    int area;
    area = length * width;
    return area;
}
void displayData(int length, int width, int area){
    cout << "If Length: " << length;
    cout << "\nAnd Width: " << width;
    cout << "\nThen Area is: " << area << endl;
}