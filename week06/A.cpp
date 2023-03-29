#include <iostream>
using namespace std;

struct Students
{
    string name;
    int score;
};

int main() {
    int N = 10;
    int minscore;
    Students students[N];
    for (int i = 0; i < N; i++) {
        cin >> students[i].name >> students[i].score;
    }
    cin >> minscore;
    for (int i = 0; i < N; i++) {
        if (students[i].score >= minscore) {
            cout << students[i].name << " ";
        }
    }
    cout << endl;
    return 0;
}