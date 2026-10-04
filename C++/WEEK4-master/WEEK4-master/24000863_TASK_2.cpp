#include <iostream>
#include <stack>
using namespace std;

class Problem {
    int a[10];
    stack<int> B;

public:
    void input() {
        cout << "Enter 10 values for the stack:" << endl;
        for (int i = 0; i < 10; i++) {
            cin >> a[i];
        }
    }

    void imp() {
        cout << "Pushing elements into stack B..." << endl;
        for (int i = 0; i < 10; i++) {
            B.push(a[i]);
        }
    }
	    	void pp() {
      cout << "Removing top 2 elements from stack B..." << endl;
      if (!B.empty()) B.pop();
     if (!B.empty()) B.pop();


        }
        
    

    void middle() {
        cout << "Middle element = " << a[4] << endl; 
    }

    void reverse() {
        int mid = 4; 
        for (int i = 0; i <= mid / 2; i++) {
            int temp = a[i];
            a[i] = a[mid - i];
            a[mid - i] = temp;
        }

        cout << "After reversing bottom half:" << endl;
        for (int i = 0; i <8; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Problem p;
    p.input();
    p.imp();
    p.pp();
    p.middle();
    p.reverse();
    return 0;
}

