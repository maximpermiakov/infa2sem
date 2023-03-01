#include <iostream>
using namespace std;

#ifndef N
#define N 6  // actual size of the array
#endif

int binsearch(int (&array)[N]) {
    int l = 0, r = N - 1;
    int m;
    while (l < r) {
        m = (l + r) / 2;
        if (array[m] == 0) {
            l = m + 1;
            if (array[l] == 1) {
                return l - 1;
            }
        }
        else {
            r = m - 1;
        }
    }
    return l;
}

int main() {
    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    cout << binsearch(array) << endl;
    return 0;
}