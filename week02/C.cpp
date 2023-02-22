#include <iostream>
using namespace std;

int main() {
    int x = 0, i = 1;
    cin >> x;
    while (i < x) {
        i *= 2;
    }
    if (i == x) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}