// Mispelling
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int m; cin >> m; m--;
        cin.ignore();
        string word; getline(cin,word);

        word.erase(word.begin()+m);
        cout << i+1 << " " << word << "\n";
    }

    return 0;
}
