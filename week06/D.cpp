#include <iostream>
using namespace std;

struct Street
{
    int x1;
    int y1;
    int x2;
    int y2;
};

bool contain(Street street, int x, int y) {
    if (((street.x1 <= x and x <= street.x2) or (street.x2 <= x and x <= street.x1)) and
        (x - street.x1) * (street.y2 - street.y1) == (y - street.y1) * (street.x2 - street.x1))
        return 1;
    return 0;
}

bool intersect(Street street1, Street street2) {
    int a11 = street1.y1 - street1.y2, a12 = street1.x2 - street1.x1;
    int a21 = street2.y1 - street2.y2, a22 = street2.x2 - street2.x1;
    int b1 = street1.x2 * street1.y1 - street1.y2 * street1.x1;
    int b2 = street2.x2 * street2.y1 - street2.y2 * street2.x1;
    int d  = a11 * a22 - a21 * a12;
    if (d != 0) {
        int d1  = b1 * a22 - b2 * a12;
        int d2  = a11 * b2 - a21 * b1;
        float x = d1 / d;
        float y = d2 / d;
        if (contain(street1, x, y) and contain(street2, x, y)) return 1;
    }
    if (d == 0 and
        (contain(street1, street2.x1, street2.y1) or contain(street1, street2.x2, street2.y2) or
         contain(street2, street1.x1, street1.y1) or contain(street2, street1.x2, street1.y2)) and
        (street2.x1 - street1.x1) * (street1.y2 - street1.y1) ==
            (street2.y1 - street1.y1) * (street1.x2 - street1.x1)) {
        return 1;
    }
    return 0;
}

int main() {
    Street street1, street2;
    cin >> street1.x1 >> street1.y1 >> street1.x2 >> street1.y2 >> street2.x1 >> street2.y1 >> street2.x2 >> street2.y2;
    if (intersect(street1, street2))
        cout << "NO";
    else
        cout << "YES";
    cout << endl;
    return 0;
}