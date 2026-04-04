// CCC '19 S2 - Pretty Average Primes
#include <bits/stdc++.h>
using namespace std;

bool isprime(const long N) {
    for (int j = 2; j * j <= N; j++) {
        if (N%j==0) {return false;}
    }
    return true;
}

pair<int,int> solve(const int N) {
    if (isprime(N)) {return {N,N};}

    int twoN = N * 2;
    for (int i = 2; i < N; i++) {
        int dif = twoN - i;
        if (isprime(i) && isprime(dif)) {
            return {i,dif};
        }
    }
    return {-1,-1};
}

int T;
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        pair<int,int> ans = solve(N);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;    
}
