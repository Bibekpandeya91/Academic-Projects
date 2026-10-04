#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <limits>
#include <ios>

using namespace std;

class Game {
    int difficultyChoice, guess, randomNumber, maxRange;

public:
    void menu() {
        cout << "Enter difficulty level:" << endl;
        cout << "1. Easy [1-8]" << endl;
        cout << "2. Medium [1-30]" << endl;
        cout << "3. Hard [1-50]" << endl;

        while (true) {
            cout << "Enter your choice (1, 2, or 3): ";
            cin >> difficultyChoice;
            if (cin.fail() || difficultyChoice < 1 || difficultyChoice > 3) {
                cout << "Invalid input. Please enter 1, 2, or 3." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                 break; 
            }
        }

        setMaxRange();
        randomNumber = rand() % maxRange + 1;
        cout << "I have selected a number between 1 and " << maxRange << ". You have " << 3 << " attempts." << endl;
    }

    void setMaxRange() {
        if (difficultyChoice == 1) {
            maxRange = 8;
        } else if (difficultyChoice == 2) {
            maxRange = 30;
        } else { 
            maxRange = 50;
        }
    }

    void operation() {
        int currentAttempt = 0; 
        while (currentAttempt < 3) {
            cout << "Attempt " << (currentAttempt + 1) << "/" << 3 << endl;

            while (true) {
                 cout << "Enter your guess: ";
                 cin >> guess;
                 if (cin.fail()) {
                    cout << "Invalid input. Please enter a whole number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                 } else {
                     break; 
                 }
            }

            if (guess == randomNumber) {
                cout << "Congratulations! You guessed it right!" << endl;
                return;
            } else if (guess > randomNumber) {
                cout << "Your guess is too high." << endl;
            } else {
                cout << "Your guess is too low." << endl;
            }
            currentAttempt++;
        }
        cout << "You ran out of attempts. The correct number was " << randomNumber << "." << endl;
    }
};

int main() {
    srand(time(0)); 
    Game g;
    g.menu();
    g.operation();
    return 0;
}
