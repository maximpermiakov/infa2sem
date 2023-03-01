#include <iostream>
using namespace std;

#ifndef N
#define N 6  // actual size of the array
#endif

int main() {
    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < N; i++) {
        if (array[i] >= 0) {
            cout << array[i] << " ";
        }
    }
    for (int i = 0; i < N; i++) {
        if (array[i] < 0) {
            cout << array[i] << " ";
        }
    }
    cout << endl;
    return 0;
}