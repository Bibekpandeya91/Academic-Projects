#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Manager {
private:
    vector<string> names;
    map<string, int> AgeMap;
    void sortNames() {
        for (int i = 0; i < names.size(); ++i) {
            for (int j = i + 1; j < names.size(); ++j) {
                if (names[j] < names[i]) {
                    string temp = names[i];
                    names[i] = names[j];
                    names[j] = temp;
                }
            }
        }
    }

public:
    void addPerson(string name, int age) {
        names.push_back(name);
        AgeMap[name] = age;
    }
    void showPeopleAboveAge(int ageLimit) {
        cout << "People older than " << ageLimit << ":"<<endl;
        for (int i = 0; i < names.size(); ++i) {
            string name = names[i];
            if (AgeMap[name] > ageLimit) {
                cout << name << " (" << AgeMap[name] << ")\n";
            }
        }
    }
    void displaySorted() {
        sortNames(); 
        cout << "All names sorted alphabetically:"<<endl;
        for (int i = 0; i < names.size(); ++i) {
            string name = names[i];
            cout << name << " (" << AgeMap[name] << ")\n";
        }
    }
};

int main() {
    Manager m;
    int n;

    cout << "How many people do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name;
        int age;

        cout << "Enter name #" << (i + 1) << ": ";
        cin >> name;
        cout << "Enter age of " << name << ": ";
        cin >> age;

        m.addPerson(name, age);
    }

    int ageLimit;
    cout << "Enter age limit to find people older than: "<<endl;
    cin >> ageLimit;

    m.showPeopleAboveAge(ageLimit);
    m.displaySorted();

    return 0;
}

