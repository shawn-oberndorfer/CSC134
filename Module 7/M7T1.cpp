#include <iostream>
using namespace std;

// Next time we'll put the class in a separate file
class Restaurant {
  private:
    string name;    // the name
    double rating;  // 0 to 5 stars

  public:
	// constructor 
	Restaurant(string n, double r) {
		name = n;
		rating = r;
	}
	// getters and setters
    void setName(string n) {
        name = n; 
    }
    void setRating(double r) {

        if (r >= 0 && r <= 5) {
            rating = r;
        }
    }
    string getName() const {
        return name;
    }
    double getRating() const {
        return rating;
    }
  

    void printInfo() {
        cout << "Restaurant: " << name << ", \nRating: " << rating << " stars\n" << endl;
    }
};

int main() {
    cout << "M7T1 - Restaurant Reviews" << endl;


    Restaurant breakfast = Restaurant("Pancakes and Waffles", 3.9);
    Restaurant lunch = Restaurant("Zaxbys", 4.0);
    Restaurant dinner = Restaurant("Olive Garden", 4.5);


    breakfast.printInfo();
    lunch.printInfo();
    dinner.printInfo();

    return 0;

}