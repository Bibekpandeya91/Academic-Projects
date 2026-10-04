#include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float getArea()  {
        return 3.14 * radius * radius;
    }

    friend void compareTwoCircles( Circle& c1,  Circle& c2);
};

void compareTwoCircles( Circle& c1,  Circle& c2) {
    float area1 = c1.getArea();
    float area2 = c2.getArea();

    cout << "Area of first circle: " << area1 << endl;
    cout << "Area of second circle: " << area2 << endl;

    if (area1 > area2) {
        cout << "First circle has the larger area.\n";
    } else if (area2 > area1) {
        cout << "Second circle has the larger area.\n";
    } else {
        cout << "Both circles have equal area.\n";
    }
}

int main() {
    float r1, r2;

    cout << "Enter radius of first circle: ";
    cin >> r1;
    cout << "Enter radius of second circle: ";
    cin >> r2;

    Circle c1(r1);
    Circle c2(r2);

    compareTwoCircles(c1, c2);

    return 0;
}

