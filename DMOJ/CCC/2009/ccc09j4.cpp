// CCC '09 J4 - Signage
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define endl '\n'
#define PRIMLOOP(N) for (int i = 0; i < N; i++)


/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int W; cin >> W;
    queue<string> rem = queue<string>({"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"});

    while (!rem.empty()) {
        string ln = "";

        int words = 1;

        ln += rem.front(); rem.pop();

        int totallen = 0;
        while (!rem.empty() && ln.length()+1 + rem.front().length() <= W) {
            ln += '.';
            ln += rem.front(); rem.pop();
            words++;
        }
        
        if (words == 1) {
            if (ln.length() + 1 <= W) ln += '.';
        }

        ln += ' ';
        char c;
        while (ln.length() <= W) {
            PRIMLOOP(ln.length()) {
                if (ln.length() > W) break;

                c = ln[i];
                if (c == '.') {
                    ln = ln.substr(0, i+1) + '.' + ln.substr(i+1);
                    while (c == '.') {
                        i++;
                        c = ln[i];
                    }
                }
            }
        }

        ln.pop_back();
        cout << ln << endl;
    }

    return 0;
}
