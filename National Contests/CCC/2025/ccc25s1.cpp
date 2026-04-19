// CCC '25 S1 - Positioning Peter's Paintings
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")


/* Orz bruce */
int main() {

    int A,B,X,Y; scanf("%d %d %d %d",&A,&B,&X,&Y);
    if (A == B && B == X && X == Y) {
        printf("%d\n", 2*(2*A+A));
    } else if (A == B && X == Y) {
        printf("%d\n", 2*(max(A,X) + (A+X)));
    } else {
        printf("%d\n", min(2*(max(B,Y) + A + X) , 2*(max(A,X) + B + Y)));
    }

    return 0;
}
