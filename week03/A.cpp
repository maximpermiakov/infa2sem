#include <iostream>
using namespace std;

#ifndef N
#define N 5  // actual size of the array
#endif

void swap(int& lha, int& rha) {
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

int main() {
    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < N / 2; i++) {
        swap(array[i], array[N - i - 1]);
    }
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}