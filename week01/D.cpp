#include <iostream>

using namespace std;

int main() {
    int m, n, q;
    cin >> m >> n;
    while (m % n != 0) {
        q = m % n;
        m = n;
        n = q;
    }
    cout << n << endl;
}