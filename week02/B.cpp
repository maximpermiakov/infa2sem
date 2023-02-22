#include <iostream>
using namespace std;

int main() {
    int x = 0, res = 0;
    cin >> x;
    while (x != 0) {
        if (x % 2 == 0) {
            res++;
        }
        cin >> x;
    }
    cout << res << endl;
    return 0;
}