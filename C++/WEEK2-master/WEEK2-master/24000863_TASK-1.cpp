#include <iostream>
using namespace std;

class Student {
    string fname, lname;
    int m1, m2, m3, calc;
    float avg, per;

public:
    void input() {
        cout << "Enter your First name: ";
        cin >> fname;
        cout << "Enter your Last name: ";
        cin >> lname;
    }

    void finput() {
        while (true) {
            cout << "Enter marks for 3 subjects (0-100): ";
            cin >> m1 >> m2 >> m3;

            if ((m1 >= 0 && m1 <= 100) && (m2 >= 0 && m2 <= 100) && (m3 >= 0 && m3 <= 100)) {
                break;
            } else {
                cout << "? One or more marks were invalid. Please re-enter marks between 0 and 100.\n";
            }
        }
    }

    void calculation() {
        calc = m1 + m2 + m3;
            avg = (float)(calc) / 3;            
            per = ((float)(calc) / 300) * 100; 

    }

    void displaydetails() {
        cout << "\nName: " << fname << " " << lname << endl;
        cout << "Total Marks: " << calc << endl;
        cout << "Average Marks: " << avg << endl;
    }

    void display() {
        cout << "Percentage: " << per << "%" << endl;
        if (per < 60)
            cout << "Grade = F" << endl;
        else if (per < 70)
            cout << "Grade = D" << endl;
        else if (per < 80)
            cout << "Grade = C" << endl;
        else if (per < 90)
            cout << "Grade = B" << endl;
        else
            cout << "Grade = A" << endl;
    }
};

int main() {
    Student s;
    s.input();
    s.finput();        
    s.calculation();    
    s.displaydetails();
    s.display();
    return 0;
}


