#include <iostream>
#include <limits>
#include <ios>

using namespace std;

class Bouncy {
    int in;

public:
    void input() {
        while (true) {
            cout << "Enter a positive number: ";
            cin >> in;

            if (cin.fail() || in <= 0) {
                 if(cin.fail()) { 
                    cout << "Invalid input. Please enter a whole number." << endl;
                 } else { 
                    cout << "Invalid input. Please enter a POSITIVE number." << endl;
                 }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break; 
            }
        }
    }

    void calc() {
        int last = in % 10;  
        in = in / 10;        
        condition(last);
    }

    void condition(int last) {
        int increasing = 0, decreasing = 0; 

        while (in > 0) {
            int loop = in % 10;  

            if (loop < last) {
                increasing = 1;
            } else if (loop > last) {
                decreasing = 1;
            }

            last = loop;
            in = in / 10;
        }

        if (increasing == 1 && decreasing == 1) {
            cout << "Your number is bouncy" << endl;
        } else {
            cout << "Your number is not bouncy" << endl;
        }
    }
};

int main() {
    Bouncy b;
    b.input();
    b.calc();
    return 0;
}
