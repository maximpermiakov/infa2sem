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
    cout << array[N - 1] << " ";
    for (int i = 0; i < N - 1; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}