// CCC '10 S2 - Huffman Encoding
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ILOOP(n) for (int i = 0; i < n; i++)
#define CLOOP(s) for (char c: s)

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    map<string,char> codes;
    set<string> headers;
    ILOOP(N) {
        char c;
        string seq;
        cin >> c >> seq;
        codes[seq] = c;
        headers.emplace(seq);
    }

    string S; cin >> S;
    string hold = "";
    string res = "";
    CLOOP(S) {
        hold += c;
        if (headers.find(hold) != headers.end()) {res += codes[hold]; hold = "";}
    }
    cout << res << endl;

    return 0;
}
