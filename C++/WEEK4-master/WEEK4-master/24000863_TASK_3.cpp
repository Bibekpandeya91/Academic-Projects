#include <iostream>
#include <queue>
using namespace std;

class problem {
    int a[50], in, p, k;  
    queue<int> B;

public:
    void finput() {
        cout << "Enter how many data you want to enqueue, LIMIT IS 50" << endl;
        cin >> in;
    }

    void input() {
        cout << "Enter " << in << " data for enqueue" << endl;
        for (int i = 0; i < in; i++) {
            cin >> a[i];
        }
    }

    void pus() {
        for (int i = 0; i < in; i++) {
            B.push(a[i]);  
        }
    }

    void ipp() {
        cout << "How many data you want to pop" << endl;
        cin >> p;
    }

    void pp() {
        
        while (p > 0) {
            if (!B.empty()) {
                cout << "Popping element: " << B.front() << endl;
                B.pop();  
            } else {
                cout << "Queue is empty! Cannot pop." << endl;
                break;  
            }
            p--;  
        }
    }

    void ireverse() {
        cout << "How many data you want to reverse (from the remaining data)?" << endl;
        cin >> k;
    }

    void reverse() {
        
        if (k <= 0 || k > B.size()) {
            cout << "Invalid number of elements to reverse!" << endl;
            return;
        }

        queue<int> tempQueue = B;
        int tempArray[k];

       
        for (int i = 0; i < k; i++) {
            tempArray[i] = tempQueue.front();
            tempQueue.pop();
        }

        
        for (int i = 0; i < k / 2; i++) {
            int temp = tempArray[i];
            tempArray[i] = tempArray[k - 1 - i];
            tempArray[k - 1 - i] = temp;
        }

        
        while (!B.empty()) {
            B.pop();
        }

        
        for (int i = 0; i < k; i++) {
            B.push(tempArray[i]);
        }

        
        while (!tempQueue.empty()) {
            B.push(tempQueue.front());
            tempQueue.pop();
        }

        cout << "Current order of data after reverse:" << endl;
        queue<int> displayQueue = B;
        while (!displayQueue.empty()) {
            cout << displayQueue.front() << " ";
            displayQueue.pop();
        }
        cout << endl;
    }

    void alternate() {
        cout << "Values after alternating:" << endl;
        queue<int> tempQueue = B;
        int remainingSize = tempQueue.size();

        
        int tempArray[remainingSize];
        for (int i = 0; i < remainingSize; i++) {
            tempArray[i] = tempQueue.front();
            tempQueue.pop();
        }

        
        for (int i = 0; i < remainingSize / 2; i++) {
            cout << tempArray[i] << " " << tempArray[i + remainingSize / 2] << " ";
        }
        if (remainingSize % 2 != 0) {
            cout << tempArray[remainingSize / 2];
        }
        cout << endl;
    }

    void showQueue() {
        cout << "Current queue contents:" << endl;
        queue<int> tempQueue = B;
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
};

int main() {
    problem p;
    p.finput();
    p.input();
    p.pus();
    p.ipp();
    p.pp();  
    p.showQueue();  
    p.ireverse();  
    p.reverse();  
    p.alternate();  

    return 0;
}

