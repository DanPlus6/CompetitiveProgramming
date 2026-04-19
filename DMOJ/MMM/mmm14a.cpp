// MMM '14 A - Distinct Prime Factors
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

constexpr int MM = 1e6+5;

/* Orz bruce */
int main() {
    vi sieve(MM+1, 0);
    for (int i = 2; i <= MM; i++) {
        if (sieve[i] == 0) {
            for (int j = i; j <= MM; j += i) sieve[j]++;
        }
    }

    int A,B; scanf("%d\n%d",&A,&B);
    for (int i = A; i <= B; i++) cout << sieve[i] << endl;

    return 0;
}
