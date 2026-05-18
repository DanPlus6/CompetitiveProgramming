// Max's Anger Contest Series 2 P2 - Password Anger
#include <bits/stdc++.h>
using namespace std;

int N,M;

int get_hash(string s) {
    int hash = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        hash = hash * 13 + s[i] - 'a' + 1;
    }
    return hash;
}

int res = 0;
void solve(string run) {
    if (run.length() == N) { if (get_hash(run) == M) ++res; return; }

    for (int i = 'a'; i <= 'z'; i++) {
        solve(run + (char)i);
    }
}


/* Orz bruce */
int main() {
    scanf("%d\n%d",&N,&M);

    solve("");

    printf("%d\n",res);

    return 0;
}
