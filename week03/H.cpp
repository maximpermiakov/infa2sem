#include <iostream>
using namespace std;

#ifndef N, M
#define N 2
#define M 2
#endif

void print_transposed(int (&array)[N][M]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << array[j][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int array[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> array[i][j];
        }
        cout << endl;
    }
    print_transposed(array);
    return 0;
}