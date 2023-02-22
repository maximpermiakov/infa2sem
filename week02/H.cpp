#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n) {
    if (n == 2) {
        return true;
    }
    else if (n % 2 == 0){
        return false;
    }
    else {
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    int n;
    cin >> n;
    if (prime(n)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}