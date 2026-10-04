#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book {
    char titles[10][150];     
    char searchTitle[150];     
    char filename[100];        
    int choice;

public:
    void askFileName() {
        cout << "Enter the name of the binary file (e.g., books.dat): "<<endl;
        cin.getline(filename, 100);
    }

    void menu() {
        cout << "Menu:"<<endl;
        cout << "1. Write names of 10 books to the file"<<endl;
        cout << "2. Search if a book is in the file or not"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        cin.ignore(); 
    }

    void enterTitles() {
        cout << "\nEnter 10 book titles:\n";
        for (int i = 0; i < 10; i++) {
            cout << "Book " << (i + 1) << ": ";
            cin.getline(titles[i], 150);
        }
    }

    void saveToFile() {
        ofstream file(filename, ios::binary | ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < 10; i++) {
            file.write(titles[i], sizeof(titles[i]));  
        }

        file.close();
        cout << "All 10 titles saved successfully to " << filename <<endl;
    }

    void searchInFile() {
        cout << "Enter the title of the book to search: "<<endl;
        cin.getline(searchTitle, 150);

        ifstream file(filename, ios::binary);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        char buffer[150];
        bool found = false;

        while (file.read(buffer, sizeof(buffer))) {
            if (strcmp(buffer, searchTitle) == 0) {
                found = true;
                break;
            }
        }

        file.close();

        if (found)
            cout << "The book is present in the file."<<endl;
        else
            cout << "The book is NOT present in the file."<<endl;
    }

    void processChoice() {
        switch (choice) {
            case 1:
                enterTitles();
                saveToFile();
                break;
            case 2:
                searchInFile();
                break;
            default:
                cout << "Invalid choice. Please select 1 or 2." << endl;
        }
    }
};

int main() {
    Book b;
    b.askFileName();
    b.menu();
    b.processChoice();
    return 0;
}

