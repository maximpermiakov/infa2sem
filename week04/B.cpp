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

void qsort(int (&array)[N], int ind_left_base, int ind_right_base) {
    int ind_left = ind_left_base, ind_right = ind_right_base;
    int pivot = array[(ind_left_base + ind_right_base) / 2];
    while (ind_left <= ind_right) {
        while (array[ind_left] < pivot) {
            ind_left++;
        }
        while (array[ind_right] > pivot) {
            ind_right--;
        }
        if (ind_left <= ind_right) {
            swap(array[ind_left], array[ind_right]);
            ind_left++;
            ind_right--;
        }
    }
    if (ind_left_base < ind_right) {
        qsort(array, ind_left_base, ind_right);
    }
    if (ind_right_base > ind_left) {
        qsort(array, ind_left, ind_right_base);
    }
    return;
}

int main() {
    int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    qsort(array, 0, N - 1);
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}