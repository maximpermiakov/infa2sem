#include <iostream>

using namespace std;

int main() {
    int m, n, q, k, l;
    cin >> m >> n;
    k = m;
    l = n;
    while (k % l != 0) {
        q = k % l;
        k = l;
        l = q;
    }
    cout << (m * n / l) << endl;
    return 0;
}