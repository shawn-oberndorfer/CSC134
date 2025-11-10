#include <iostream>
using namespace std;


void part1();
void part2();

int main(){


    part1();

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

    for(int i = 1; i <= maxDays; i++){
        cout << "\nHow many cars past on day " << i << ": ";
        cin >> carsPast[i-1];
        totalCars += carsPast[i-1];
    }

    

}
