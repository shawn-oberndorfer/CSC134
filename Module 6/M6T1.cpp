/*
CSC 134
M6T1
Shawn Oberndorfer
Date Started 11/10/2025
*/
#include <iostream>
using namespace std;


void part1();
void part2();

int main(){


    part2();

    return 0;
}

void part1(){
    const int maxDays = 5;
    int carsPast;
    int totalCars = 0;
    int averageCars;

    for(int i = 1; i <= maxDays; i++){
        cout << "\nHow many cars past on day " << i << ": ";
        cin >> carsPast;
        totalCars += carsPast;
    }
    averageCars = totalCars / maxDays;
    cout << "Total Cars: " << totalCars << "\nAverage Cars Per Day: " << averageCars;
}

void part2(){
    const int maxDays = 5;
    int totalCars = 0;
    int averageCars;

    int carsPast[maxDays];
    string daysOfWeek[maxDays];

    daysOfWeek[0] = "Monday";
    daysOfWeek[1] = "Tuesday";
    daysOfWeek[2] = "Wednesday";
    daysOfWeek[3] = "Thursday";
    daysOfWeek[4] = "Friday";

    for(int i = 1; i <= maxDays; i++){
        cout << "How many cars past on " << daysOfWeek[i-1] << ": ";
        cin >> carsPast[i-1];
        totalCars += carsPast[i-1];
        cout  << endl;
    }

    averageCars = totalCars / maxDays;
    
    for(int j = 1; j <= maxDays; j++){
        cout << "On " << daysOfWeek[j-1] << ": " << carsPast[j-1] << " cars past" << endl;
    }
    cout << "\nTotal Cars: " << totalCars << "\nAverage Cars Per Day: " << averageCars << endl;;


}
