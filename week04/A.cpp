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

void gnome_sort(int (&array)[N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
            }
        }
    }
}

int main() {
    int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    gnome_sort(array);
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}