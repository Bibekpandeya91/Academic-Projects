#include <iostream>
using namespace std;

class Overload {
    int in;
public:
    void findmax(int a, int b) {
        cout << "Maximum: " << ((a > b) ? a : b) << endl;
    }

    void findmax(float a, float b) {
        cout << "Maximum: " << ((a > b) ? a : b) << endl;
    }

    void findmax(int a, int b, int c) {
        cout << "Maximum: " << ((a > b && a > c) ? a : (b > c ? b : c)) << endl;
    }

    void findmax(int a, float b) {
        cout << "Maximum: " << ((a > b) ? a : b) << endl;
    }

    void menu() {
        cout << "Select from below:"<<endl;
        cout << "1. Two integers maximum"<<endl;
        cout << "2. Two floating maximum"<<endl;
        cout << "3. Three integers maximum"<<endl;
        cout << "4. One integer and one floating maximum"<<endl;
        cout << "Enter choice: ";
        cin >> in;
    }

    void calc() {
        switch (in) {
            case 1: {
                int a, b;
                cout << "Enter two integers: ";
                cin >> a >> b;
                findmax(a, b);
                break;
            }
            case 2: {
                float a, b;
                cout << "Enter two floating numbers: ";
                cin >> a >> b;
                findmax(a, b);
                break;
            }
            case 3: {
                int a, b, c;
                cout << "Enter three integers: ";
                cin >> a >> b >> c;
                findmax(a, b, c);
                break;
            }
            case 4: {
                int a;
                float b;
                cout << "Enter one integer and one floating number: ";
                cin >> a >> b;
                findmax(a, b);
                break;
            }
            default:
                cout << "Please enter a number between 1 and 4."<<endl;
        }
    }
};

int main() {
    Overload o;
    o.menu();
    o.calc();
    return 0;
}

