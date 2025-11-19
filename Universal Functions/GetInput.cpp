#include <iostream>
#include <limits>

using namespace std;

int GetChoice(int, int);

int main() {
    int minChoice = 1;
    int maxChoice = 3;
    GetChoice(minChoice, maxChoice);
    
    return 0;
}

int GetChoice(int minChoice, int maxChoice) {
    int choice = 0;
    while(choice < minChoice || choice > maxChoice){
        cout << "Enter an integer between " << minChoice << " and " << maxChoice << "." << endl;
        cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } if(choice < 1 || choice > maxChoice) {
            cout << "Invalid Choice. Please enter an integer between " << minChoice <<  " and " << maxChoice << "\n";
        }
    }
    return choice;
}