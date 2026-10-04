#include <iostream>
#include <limits>
#include <ios>

using namespace std;

class Week {
    int dayNumber;

public:
    void Input() {
        while (true) {
            cout << "Enter number between 1-7: ";
            cin >> dayNumber;

            if (cin.fail() || dayNumber < 1 || dayNumber > 7) {
                cout << "Invalid input. Please enter a number between 1 and 7." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                 display(); 
                 break; 
            }
        }
    }


    void display() {
        switch (dayNumber) {
            case 1: 
			cout << "TODAY IS SUNDAY" << endl; 
			break;
            case 2: 
			cout << "TODAY IS MONDAY" << endl; 
			break;
            case 3:
			 cout << "TODAY IS TUESDAY" << endl; 
			 break;
            case 4: 
			cout << "TODAY IS WEDNESDAY" << endl; 
			break;
            case 5: 
			cout << "TODAY IS THURSDAY" << endl; 
			break;
            case 6:
			 cout << "TODAY IS FRIDAY" << endl;
			  break;
            case 7: 
			cout << "TODAY IS SATURDAY" << endl;
			 break;
        }
    }
};

int main() {
    Week w;
    w.Input(); 
    return 0;
}
