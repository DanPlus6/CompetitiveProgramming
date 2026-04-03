// Word Scrambler
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<string> vs;
#define endl '\n'
#define ALL(x) x.begin(), x.end()
#define pb push_back


string S;
vs res;
void scrambler(string run, string rest) {
    if (rest == "") {res.pb(run); return;}
    
    for (int i = 0; i < rest.length(); i++) scrambler(run + rest[i], rest.substr(0,i) + rest.substr(i+1));
}

/* Orz bruce */
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> S;
    scrambler("", S);


    sort(ALL(res));
    for (string s: res) cout << s << endl;

    return 0;
}
