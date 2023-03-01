#include <iostream>
using namespace std;

#ifndef N
#define N 3  // actual size of the array
#endif

int main() {
    int array[N * N];
    int x = 0;
    for (int i = 0; i < N * N; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < N * N; i += N + 1) {
        x += array[i];
    }
    cout << x << endl;
    return 0;
}