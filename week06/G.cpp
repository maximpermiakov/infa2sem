#include <iostream>
using namespace std;

struct Atom
{
    string name;
    int mass;
    int charge;
};

struct Reaction
{
    Atom atom;
    string rtype;
};

Atom reaction(Reaction reaction) {
    if (reaction.rtype == "alpha") {
        reaction.atom.mass -= 4;
        reaction.atom.charge -= 2;
    } else if (reaction.rtype == "beta-") {
        reaction.atom.charge += 1;
    } else if (reaction.rtype == "beta+") {
        reaction.atom.charge -= 1;
    }
    return reaction.atom;
}

int main() {
    int N, M;
    cin >> N;
    Atom atoms[N];
    for (int i = 0; i < N; i++) {
        cin >> atoms[i].name >> atoms[i].mass >> atoms[i].charge;
    }
    cin >> M;
    Reaction reactions[M];
    for (int i = 0; i < M; i++) {
        cin >> reactions[i].atom.name >> reactions[i].rtype;
        for (int j = 0; j < N; j++) {
            if (reactions[i].atom.name == atoms[j].name) {
                reactions[i].atom.mass   = atoms[j].mass;
                reactions[i].atom.charge = atoms[j].charge;
            }
        }
        reactions[i].atom.name = "NO DATA";
    }
    for (int i = 0; i < M; i++) {
        Atom product = reaction(reactions[i]);
        for (int i = 0; i < N; i++) {
            if (product.mass == atoms[i].mass and product.charge == atoms[i].charge) {
                product.name = atoms[i].name;
            }
        }
        cout << product.name << " ";
    }
    cout << endl;
    return 0;
}