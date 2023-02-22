#include <iostream>
#include <cmath>
using namespace std;

bool palindrome(long long int n, int l) {
    if (l == 1 or l == 0) {
        return true;
    }
    else {
        long long int x = pow(10, l - 1);
        if (n % 10 == n / x) {
            return palindrome((n - x * (n / x)) / 10, l - 2);
        }
        else {
            return false;
        }
    }
}

int main() {
    long long int n, m;
    int l = 0;
    cin >> n;
    m = n;
    while (m != 0) {
        l++;
        m /= 10;
    }
    if (palindrome(n, l)) {
        cout << "YES" << endl;;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}