// CCC '05 J2 - RSA Numbers
#include <bits/stdc++.h>
using namespace std;

int getDivisors(int x) {
    int res = 0;
    for (int i = 2; i*i <= x; i++) {
        if (x%i == 0) {
            res++;
            if (x/i != i) res++;
        }
    }
    return res;
}

/* Orz bruce */
int main() {
    int N,M; scanf("%d\n%d",&N,&M);

    int res = 0;

    for (int i = N; i <= M; i++) {
        if (getDivisors(i) == 2) res++;
    }
    

    printf("The number of RSA numbers between %d and %d is %d",N,M,res);

    return 0;
}
