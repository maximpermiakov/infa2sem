#include <iostream>
using namespace std;

#ifndef N
#define N 10  // actual size of the array
#endif

void swap(int& lha, int& rha) {
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void cheops_sort(int (&array)[N], int idx_last) {
    for (int i = idx_last; i >=  0; i--) {
        if(2 * i + 1 <= idx_last & array[i] < array[2 * i + 1]) {
            swap(array[i], array[2 * i + 1]);
        }
        if(2 * i + 2 <= idx_last & array[i] < array[2 * i + 2]) {
            swap(array[i], array[2 * i + 2]);
        }
    }
    swap(array[0], array[idx_last]);
    idx_last--;
    if (idx_last > 0) {
        cheops_sort(array, idx_last);
    }
    return;
}

int main() {
    int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    cheops_sort(array, N - 1);
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}