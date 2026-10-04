#include <iostream>
#include <limits>  
#include <ios>

using namespace std;

class Temperature {
    float in, total;
    int choice;

public:
    void menu() {
        cout << "Select conversion type:" << endl;
        cout << "1. Celsius to Fahrenheit" << endl;
        cout << "2. Fahrenheit to Celsius" << endl;

        while (true) {
            cout << "Enter your choice (1 or 2): ";
            cin >> choice;

            if (cin.fail() || (choice != 1 && choice != 2)) {
                cout << "Invalid input. Please enter 1 or 2." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } else {
                break; 
            }
        }
    }

    void inputTemperature() {
        while (true) {
            cout << "Enter the temperature value: ";
            cin >> in;

            if (cin.fail()) {
                cout << "Invalid input. Please enter a numeric value." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break; 
            }
        }
    }

    void c2f() {
        total = (in * 9.0 / 5.0) + 32.0;
    }

    void f2c() {
        total = (in - 32.0) * 5.0 / 9.0;
    }

    void display() {
        cout << "The converted temperature is: "<< total << endl;
    }

    void operation() {
        inputTemperature();
        if (choice == 1) {
            c2f();
            display();
        } else { 
            f2c();
            display();
        }
    }
};

int main() {
    Temperature t;
    t.menu();
    t.operation();
    return 0;
}
