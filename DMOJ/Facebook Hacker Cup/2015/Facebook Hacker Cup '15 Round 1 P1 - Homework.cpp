// Facebook Hacker Cup '15 Round 1 P1 - Homework
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef vector<int> vi;
typedef vector<vi> vvi;
#define endl '\n'
#define LOOP(n) for (int _ = 1; _ <= n; _++)

constexpr int MM = 1e7+5;

int primacity[MM];
int main() {

    int T; cin >> T;

    bitset<MM> sieve; sieve.set();
    for (int i = 2; i < MM; i++) {
        if (sieve[i]) {
            for (int j = i; j < MM; j += i) {
                sieve.reset(j);
                primacity[j]++;
            }
        }
    }

    int A,B,K;
    LOOP(T) {
        scanf("%d %d %d",&A,&B,&K);
        int res = 0;
        for (int i = A; i <= B; i++) res += (primacity[i] == K ? 1 : 0);
        printf("Case #%d: %d\n",_,res);
    }

    return 0;
}
