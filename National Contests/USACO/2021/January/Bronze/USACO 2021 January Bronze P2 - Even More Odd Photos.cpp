/**
 * Author: DanPlus6 // David Fu
 * Problem Name: USACO 2021 January Bronze P2 - Even More Odd Photos
 * Problem URL:  https://dmoj.ca/problem/usaco21janb2
 * Problem Code: usaco21janb2
 */
#include <bits/stdc++.h>
using namespace std;

#define ANS(x) { printf("%d\n",x); return 0; }

int main() {
    int N; scanf("%d",&N);
    int even = 0, odd = 0;
    for (int x,_=0;_<N;++_) {
        scanf("%d",&x);
        if (x&1) ++odd;
        else ++even;
    }

    if (even > odd+1) ANS(2*odd + 1);
    if (even < odd) {
        int k = max(0,(odd-even+2)/3);
        odd -= 2*k;
        even = min(even+k,odd+1);
        ANS(even+odd);
    }
    printf("%d\n",N);

    return 0;
}
