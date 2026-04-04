// CCC '24 S2 - Heavy-Light Composition
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T, N; cin >> T >> N;
    for (int _ = 0; _ < T; _++) {
        map<char,int> counter = {{'A',0}, {'B',0}, {'C',0}, {'D',0}, {'E',0}, {'F',0}, {'G',0}, {'H',0}, {'I',0}, {'J',0}, {'K',0}, {'L',0}, {'M',0}, {'N',0}, {'O',0}, {'P',0}, {'Q',0}, {'R',0}, {'S',0}, {'T',0}, {'U',0}, {'V',0}, {'W',0}, {'X',0}, {'Y',0}, {'Z',0}};

        string s; cin >> s;
        for (char c: s) counter[c]++;

        int last = (counter[s[0]] > 1) ? 1 : 0;
        int cur = 2;
        bool heavylight = true;
        for (int i = 1; i < N; i++) {
            cur = (counter[s[i]] > 1) ? 1 : 0;
            if (last == cur) {heavylight = false; break;}
            last = cur;
            cur = 2;
        }

        cout << ((heavylight) ? "T\n" : "F\n");
    }

    return 0;
}


// // CCC '24 S2 - Heavy-Light Composition
// #include <bits/stdc++.h>
// using namespace std;

// #define LOOP(n) for (int _ = 0; _ < n; _++)
// #define CLOOP(s) for (char c: s)


// int main() {
//     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//     int T, N; cin >> T >> N;
//     LOOP(T) {
//         map<char,int> counter = {{'A',0}, {'B',0}, {'C',0}, {'D',0}, {'E',0}, {'F',0}, {'G',0}, {'H',0}, {'I',0}, {'J',0}, {'K',0}, {'L',0}, {'M',0}, {'N',0}, {'O',0}, {'P',0}, {'Q',0}, {'R',0}, {'S',0}, {'T',0}, {'U',0}, {'V',0}, {'W',0}, {'X',0}, {'Y',0}, {'Z',0}};

//         string s; cin >> s;
//         CLOOP(s) counter[c]++;

//         int last = (counter[s[0]] > 1) ? 1 : 0;
//         int cur = 2;
//         bool heavylight = true;
//         for (int i = 1; i < N; i++) {
//             cur = (counter[s[i]] > 1) ? 1 : 0;
//             if (last == cur) {heavylight = false; break;}
//             last = cur;
//             cur = 2;
//         }

//         cout << ((heavylight) ? "T\n" : "F\n");
//     }

//     return 0;
// }
