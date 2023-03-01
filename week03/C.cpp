#include <iostream>
using namespace std;

#ifndef N
#define N 6  // actual size of the array
#endif

int main() {
    int array[N];
    int k;
    cin >> k;
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    for (int i = N - k; i < N; i++) {
        cout << array[i] << " ";
    }
    for (int i = 0; i < N - k; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}