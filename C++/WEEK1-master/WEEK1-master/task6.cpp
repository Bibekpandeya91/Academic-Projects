#include <iostream>
#include <limits>
#include <ios>

using namespace std;

class Cinema {
    char seats[5][5];
    int row, col; 

public:
    Cinema() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                seats[i][j] = 'O'; 
            }
        }
    }

    void displaySeats() {
        cout << "\nCurrent Seat Arrangement (O=Available, X=Booked):" << endl;
        cout << "  "; 
        for (int j = 0; j < 5; j++) {
            cout << j << " ";
        }
        cout << endl;

        for (int i = 0; i < 5; i++) {
            cout << i << " "; 
            for (int j = 0; j < 5; j++) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
         cout << endl;
    }

    void getBookingInput() {
         cout << "Enter seat to book:" << endl;
         while(true) {
            cout << "Row number (0-4): ";
            cin >> row;
            if(cin.fail() || row < 0 || row > 4) {
                cout << "Invalid input. Please enter a row between 0 and 4." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                 break; 
            }
         }
         while(true) {
             cout << "Column number (0-4): ";
             cin >> col;
             if(cin.fail() || col < 0 || col > 4) {
                cout << "Invalid input. Please enter a column between 0 and 4." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
             } else {
                  break; 
             }
         }
    }

    void processBooking() {
        if (seats[row][col] == 'X') {
             cout << "----------------------------------------" << endl;
            cout << "Error: Seat (" << row << "," << col << ") is already booked." << endl;
             cout << "----------------------------------------" << endl;
        } else {
            seats[row][col] = 'X';
             cout << "----------------------------------------" << endl;
            cout << "Success: Seat (" << row << "," << col << ") booked successfully!" << endl;
             cout << "----------------------------------------" << endl;
        }
       displaySeats();
    }
};

int main() {
    Cinema c;
    c.displaySeats();   
    c.getBookingInput(); 
    c.processBooking();  
    return 0;
}
