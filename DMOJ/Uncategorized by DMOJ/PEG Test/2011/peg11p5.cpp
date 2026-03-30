// PEG Test '11 - Cyclopian Puzzle
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct args {
    int n;
    char src = 'A';
    char help = 'B';
    char dest = 'C';
};

/* Orz bruce */
void hanoi(args args) {
    if (args.n == 1) cout << args.src << args.dest << endl;
    else {
        hanoi({.n = args.n-1, .src = args.src, .help = args.dest, .dest = args.help});
        cout << args.src << args.dest << endl;
        hanoi({.n = args.n-1, .src = args.help, .help = args.src, .dest = args.dest});
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    hanoi({.n = N});

    return 0;
}
