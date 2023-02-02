#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 1;
    while (n != 0) {
        m *= n;
        n--;
    }
    cout << m << endl;
    return 0;
}