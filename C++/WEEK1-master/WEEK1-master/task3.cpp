#include <iostream>
#include <limits>
#include <ios>

using namespace std;

class Ascending {
    int a[50]; 
    int n;   

public:
    void inputSize() {
        while (true) {
             cout << "Enter how many integers you want to sort (1-50): ";
             cin >> n;
             if (cin.fail() || n < 1 || n > 50) {
                 cout << "Invalid input. Please enter a number between 1 and 50." << endl;
                 cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
             } else {
                 break; 
             }
        }
    }

    void arrayInput() {
        cout << "Enter " << n << " integers: " << endl;
        for (int i = 0; i < n; ++i) {
             while(true) {
                cin >> a[i];
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a whole number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break; 
                }
             }
        }
    }

    void sortArray() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { 
                if (a[i] < a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }

    void display() {
        cout << "Sorted numbers in ascending order: ";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Ascending A;
    A.inputSize();   
    A.arrayInput();  
    A.sortArray();   
    A.display();
    return 0;
}
