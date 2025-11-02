#include <iostream>
using namespace std;

int square(int);

void printAnswerLine(int, int);

int main(){
int i = 1;
    while(i < 11){
        int numSquared = square(i);
        printAnswerLine(numSquared, i);
        i++;
    }


    return 0;
}
int square(int i){
int squared = i * i;
return squared;

}

void printAnswerLine(int numSquared, int i){
    cout << i << " squared = " << numSquared << "." << endl;
}
