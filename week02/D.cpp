#include <iostream>
using namespace std;

int recursive_power(int base, int power) {
    if (power > 0) {
        return base * recursive_power(base, --power);
    }
    else {
        return 1;
    }
}

int main() {
    int base, power;
     cin >> base >> power;
    cout << recursive_power(base, power) << endl;
    return 0;
}