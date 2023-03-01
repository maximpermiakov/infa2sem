#include <iostream>
using namespace std;

#ifndef N
#define N 3  // actual size of the array
#endif

int main() {
    int array1[N], array2[N];
    int i = 0, j = 0;
    for (int i = 0; i < N; i++) {
        cin >> array1[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> array2[i];
    }
    while (i < N or j < N) {
        if ((array1[i] <= array2[j] and i < N) or j >= N) {
            cout << array1[i] << " ";
            i++;
        }
        else {
            cout << array2[j] << " ";
            j++;
        }
    }
    cout << endl;
    return 0;
}