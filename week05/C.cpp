#include <iostream>
using namespace std;

int main() {
    int *ptr = nullptr;
    int size = 0, input = -1;
    cin >> input;
    while (input != 0) {
        size++;
        int *ptr2 = new int[size];
        for (int i = 0; i < size - 1; i++) {
            ptr2[i] = ptr[i];
        }
        ptr2[size - 1] = input;
        cin >> input;
        delete[] ptr;
        ptr = ptr2;
    }
    for (int i = 0; i < size - 1; i++) {
        cout << ptr[i] - ptr[i + 1] << " ";
    }
    cout << endl;
    delete[] ptr;
    return 0;
}