#include <iostream>
using namespace std;

int fibonacci(int i) {
    if (i == 0 or i == 1) {
        return 1;
    }
    else {
        i--;
        return (fibonacci(i) + fibonacci(--i));
    }
}

int main() {
    int i;
    cin >> i;
    cout << fibonacci(i) << endl;
    return 0;
}