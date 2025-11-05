/*
CSC 134
M5HW - Gold
Shawn Oberndorfer
Started 11/3/2025
Last Worked on 11/5/2025
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
void QuestionSelect(bool&);
void Question1();
void Question2();
void Question3();
void Question4();
void Question5();
void Goodbye();

int main(){
    bool runAgain = true;
    
    while(runAgain == true){
    
        QuestionSelect(runAgain);
    }


    Goodbye();

    return 0;
}

void QuestionSelect(bool& runAgain){
    int questionChoice;
    bool isValid = false;

    while(isValid == false){
        cout << "What question would you like to run? \n1. Question 1 \n2. Question 2 \n3. Question 3 \n4. Question 4 \n5. Question 5 \n6. Exit Program\n";
        cin >> questionChoice;

        switch(questionChoice){
            case 1:
                Question1();
                isValid = true;
                break;
            case 2:
                Question2();
                isValid = true;
                break;
            case 3:
                Question3();
                isValid = true;
                break;
            case 4:
                Question4();
                isValid = true;
                break;
            case 5:
                Question5();
                isValid = true;
                break;
            case 6:
                isValid = true;
                runAgain = false;
                break;
            default:
                isValid = false;
                cout << "PLease enter a valid menu option. (1-6)\n";
                break;
        }
    }
}

void Question1(){

    string month1, month2, month3;
    double rainfall1, rainfall2, rainfall3;
    double averageRainfall;

    cout << "-----Average Monthly Rainfall Calculator-----\n";
    cout << "What is the name of the first month you will average?\n";
    cin >> month1;
    cout << "What was that month's rainfall in inches?\n";
    cin >> rainfall1;

    cout << "What is the name of the second month you will average?\n";
    cin >> month2;
    cout << "What was that month's rainfall in inches?\n";
    cin >> rainfall2;

    cout << "What is the name of the third month you will average?\n";
    cin >> month3;
    cout << "What was that month's rainfall in inches?\n";
    cin >> rainfall3;

    averageRainfall = ((rainfall1 + rainfall2 + rainfall3) / 3);

    cout << "The average rainfall for the months " << month1 << ", " << month2 << ", and " << month3 << " was " << averageRainfall << " inches.\n\n\n";
}

void Question2(){
    double height = 0, length = 0, width = 0, volume;

    cout << "-----Block Calculator-----\n";
    while(height < 0){
        cout << "What is the height of your block? (Must be a value greter than 0)\n";
        cin >> height;
    }
    while(length < 0){
        cout << "What is the length of your block? (Must be a value greter than 0)\n";
        cin >> length;
    }
    while(width < 0){
        cout << "What is the width of your block? (Must be a value greter than 0)\n";
        cin >> width;
    }

    volume = height * length * width;
    cout << "Height: " << height << "\nLength: " << length << "\nWidth: " << width << "\nVolume: " << volume << "\n\n\n";

}

void Question3(){
    int numericValue;
    string romanNumeral;
    bool isValid = false;
    cout << "-----Roman Numeral Converter-----\n\n";
    while(isValid == false){
        cout << "Enter a number (1-10) to convert to a roman numeral.\n";
        cin >> numericValue;
        switch(numericValue){
            case 1:
                romanNumeral = "I";
                isValid = true;
                break;
            case 2:
                romanNumeral = "II";
                isValid = true;
                break;
            case 3:
                romanNumeral = "III";
                isValid = true;
                break;
            case 4:
                romanNumeral = "IV";
                isValid = true;
                break;
            case 5:
                romanNumeral = "V";
                isValid = true;
                break;
            case 6:
                romanNumeral = "VI";
                isValid = true;
                break;
            case 7:
                romanNumeral = "VII";
                isValid = true;
                break;
            case 8:
                romanNumeral = "VIII";
                isValid = true;
                break;
            case 9:
                romanNumeral = "IX";
                isValid = true;
                break;
            case 10:
                romanNumeral = "X";
                isValid = true;
                break;
            default:
                cout << "Please enter a valid integer.\n";
                isValid = false; 
        }
    }
    cout << numericValue << " in roman numerals is " << romanNumeral << ".\n\n";

}

void Question4(){
    int shapeChoice;
    double radius, length, width, base, height, area;
    bool isValid = false;

    cout << "-----Geometry Calculator-----\n";
    while(isValid == false){
        cout << "1. Calculate the area of a Circle \n2. Calculate the area of a Rectangle \n3. Calculate the area of a Triangle \n4. Quit\n";
        cout << "Enter your choice (1-4)";
        cin >> shapeChoice;
        switch(shapeChoice){
            case 1:
                while(radius < 0){
                    cout << "What is the radius of your circle? (Must be a value greter than 0)\n";
                    cin >> radius;
                }
                area = pow(radius, 2) * M_PI;
                cout << setprecision(4) << fixed;
                cout << "The circle has an area of " << area << ".\n";
                isValid = true;
                break;
            case 2:
                while(width < 0){
                    cout << "What is the width of your rectangle? (Must be a value greter than 0)\n";
                    cin >> height;
                }
                while(length < 0){
                    cout << "What is the length of your rectangle? (Must be a value greter than 0)\n";
                    cin >> length;
                }
                area = length * width;
                cout << "The rectangle has an area of " << area << ".\n";
                isValid = true;
                break;
            case 3:
                while(height < 0){
                    cout << "What is the height of your triangle? (Must be a value greter than 0)\n";
                    cin >> height;
                }
                while(base < 0){
                    cout << "What is the length of the base of your triangle? (Must be a value greter than 0)\n";
                    cin >> base;
                }
                area = .5 * height * base;
                cout << "The trianghle has an area of " << area << ".\n";
                isValid = true;
                break;
            case 4:
                isValid = true;
                break;
            default:
                isValid = false;
                cout << "PLease enter a valid menu option. (1-4)\n";
                break;
                


        }
    }
}

void Question5(){
    double hoursTraveled, milesPerHour, distanceTraveled;

    cout <<"-----Distance Travelled Calculator-----\n";
    cout << "What was the speed of the car in mph?\n";
    cin >> milesPerHour;
    cout << "How long did the car travel for in hours?\n";
    cin >> hoursTraveled;

    distanceTraveled = milesPerHour * hoursTraveled;
    cout << "If the car was travelling at " << milesPerHour << " mph for " << hoursTraveled << " hours. The car will have gone " << distanceTraveled << " miles.\n\n"; 
}

void Goodbye(){
    cout << "Goodbye\n";
}