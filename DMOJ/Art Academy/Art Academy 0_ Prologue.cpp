// Art Academy 0: Prologue
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int n = 0, N = (cin >> N, N); n < N; n++) {
        string s; cin >> s;
        for (char i: s) {
            if ('0' <= i && i <= '9') cout << "Yes! ";
            else if (i == 'a' || i == 'A') cout << "Hi! ";
            else if (i == 'e' || i == 'E') cout << "Bye! ";
            else if (i == 'i' || i == 'I') cout << "How are you? ";
            else if (i == 'o' || i == 'O') cout << "Follow me! ";
            else if (i == 'u' || i == 'U') cout << "Help! ";
        }
        cout << "\n";
    }
    
    return 0;
}
