// CCC '20 J4 - Cyclic Shifts (Hard)
#include <bits/stdc++.h>
#include <cstdint>
// #include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// wtf is Z-algo
vector<uint8_t> get_str() {
    string s;
    getline(cin, s);
    return vector<uint8_t>(s.begin(), s.end());
}

vector<size_t> z_function(const vector<uint8_t>& s) {
    vector<size_t> z(s.size(), 0);
    size_t l = 0, r = 0;
    for (size_t i = 1; i < s.size(); i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<uint8_t> t = get_str();
    vector<uint8_t> s = get_str();

    vector<uint8_t> concat_f;
    concat_f.reserve(s.size() + 1 + t.size());
    concat_f.insert(concat_f.end(), s.begin(), s.end());
    concat_f.push_back(0);
    concat_f.insert(concat_f.end(), t.begin(), t.end());
    vector<size_t> f = z_function(concat_f);

    vector<uint8_t> s_rev(s.rbegin(), s.rend());
    vector<uint8_t> t_rev(t.rbegin(), t.rend());

    vector<uint8_t> concat_b;
    concat_b.reserve(s.size() + 1 + t.size());
    concat_b.insert(concat_b.end(), s_rev.begin(), s_rev.end());
    concat_b.push_back(0);
    concat_b.insert(concat_b.end(), t_rev.begin(), t_rev.end());
    vector<size_t> b = z_function(concat_b);

    for (size_t i = 1; i < t.size(); i++) {
        if (f[s.size() + 1 + i] + b[s.size() + 1 + t.size() - i] >= s.size()) {
            cout << "yes\n";
            return 0;
        }
    }
    cout << "no\n";
    return 0;
}


// wtf Z-algo is even more confusing
// int main() {
//     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     string T,S; cin >> T >> S;
//     int N = sizeof(T); int M = sizeof(S);
//     if (M>N) {cout << "no" << "\n";}

//     string fw = S + S + "|" + T;
//     int W = sizeof(fw);

//     vector<int> forward(W,0);
//     int l = 0; int r = 0;
//     for (int i = 1; i < W; i++) {
//         if (i <= r) {
//             forward[i] = min(r-i+1,forward[i-l]);
//         }
//         while (i + forward[i] < W && fw[forward[i]] == fw[i + forward[i]])
//             forward[i]++;
//         if (i + forward[i] - 1 > r) {
//             l = i;
//             r = i + forward[i] - 1;
//         }
//     }

//     string bw = reverse(S) * 2 + "|" + T;
//     vector<int> backward(W,0);


//     for (int i = M*2+1; i < W; i++) {
//         if (forward[i] >= M) {cout << "yes" << "\n"; return 0;}
//     }

//     cout << "no" << "\n";
    
//     return 0;
// }


// rolling hashes? never cook again
// ts pmo 🥀💔
// char T[10000001], S[10000001];
// char SS[20000002];
// int main() {
//     scanf("%10000000s",T);
//     scanf("%10000000s",S);
//     int N = strlen(T);
//     int M = strlen(S);
//     if (M > N) {cout << "no\n"; return 0;}

//     memcpy(SS, S, M);
//     memcpy(SS + M, S, M+1);
    
//     // rolling hash😭😭
//     // mom says I have bags under my eyes
//     unordered_set<uint64_t> hashes; hashes.reserve(M*2);
//     const uint64_t BASE = 91138233;
    
//     uint64_t pw = 1;
//     for (int i = 1; i < M; i++) {pw *= BASE;}

//     uint64_t h = 0;
//     for (int i = 0; i < M; i++) {h = h*BASE+(SS[i]-'A'+1);}
//     hashes.insert(h);

//     for (int i = M; i < 2 * M; i++) {
//         h -= (SS[i-M]-'A'+1) * pw;
//         h = h*BASE+(SS[i] - 'A' + 1);
//         hashes.insert(h);
//     }

//     h = 0;
//     for (int i = 0; i < M; i++) {
//         h = h*BASE+(T[i]-'A'+1);
//     }
//     if (hashes.find(h) != hashes.end()) {cout << "yes" << "\n"; return 0;}

//     for (int i = M; i < N; i++) {
//         h -= (T[i-M]-'A'+1) * pw;
//         h = h*BASE+(T[i]-'A'+1);
//         if (hashes.find(h) != hashes.end()) {cout << "yes" << "\n"; return 0;}
//     }

//     cout << "no" << "\n";
//     return 0;
// }

