#include <iostream>
using namespace std;

struct Segment
{
    int begin;
    int end;
};

void swap(int &lha, int &rha) {
    int tmp = lha;
    lha     = rha;
    rha     = tmp;
}

int main() {
    int N;
    bool safe = 1;
    cin >> N;
    Segment segments[N];
    for (int i = 0; i < N; i++) {
        cin >> segments[i].begin >> segments[i].end;
        if (segments[i].begin > segments[i].end) {
            swap(segments[i].begin, segments[i].end);
        }
    }
    for (int i = 1; i < N; i++) {
        segments[i].begin = max(segments[i].begin, segments[i - 1].begin);
        segments[i].end   = min(segments[i].end, segments[i - 1].end);
        if (segments[i].begin > segments[i].end) {
            safe = 0;
        }
    }
    if (safe) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
    return 0;
}