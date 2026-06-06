// CCC '01 J2 - Mod Inverse
#include <bits/stdc++.h>
using namespace std;

int main() {
    int X,M; scanf("%d\n%d",&X,&M);

    if (__gcd(X,M) == 1) {
        for (int i = 1; i <= M; i++) if (X * i % M == 1) printf("%d\n",i);
    } else printf("No such integer exists.\n");

    return 0;
}
