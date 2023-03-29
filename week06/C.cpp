#include <iostream>
using namespace std;

struct Time
{
    int h;
    int m;
    int s;
};

Time timesum(Time time1, Time time2) {
    Time sum;
    sum.s = time1.s + time2.s;
    sum.m = time1.m + time2.m + (sum.s / 60);
    sum.s = sum.s % 60;
    sum.h = time1.h + time2.h + (sum.m / 60);
    sum.m = sum.m % 60;
    sum.h = sum.h % 24;
    return sum;
}

int main() {
    Time time1, time2;
    cin >> time1.h >> time1.m >> time1.s >> time2.h >> time2.m >> time2.s;
    Time sum = timesum(time1, time2);
    cout << sum.h << ":" << sum.m << ":" << sum.s << endl;
    return 0;
}