// Dr. Anne Anderson Coding Contest 1 P4 - Lighting
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define endl '\n'
#define ILOOP(n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N,K; cin >> N >> K;
    vi lights(N,0); {
        string s; cin >> s;
        ILOOP(N) {if (s[i] == '1') lights[i] = 1;}
    }
    
    int res = 0; 
    int l = 0, r = -1;
    int found, place;
    while (l < N) {
        if (r >= l) {l++; continue;}

        found = -1;
        for (int j = min(N-1,l+K); j >= max(0,l-K); j--) {
            if (lights[j]) {found = j; break;}
        }

        if (found != -1) r = found+K;
        else {
            place = min(N-1,l+K);
            lights[place] = 1;
            r = place+K;
            res++;
        }

        l++;
    }

    cout << res << endl;
    return 0;
}
