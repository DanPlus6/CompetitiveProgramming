// COCI '07 Contest 4 #2 Veci
#include <bits/stdc++.h>
using namespace std;

bool sameDigits(int x, int y) {
    unordered_set<int> xdig, ydig;
    while (x) {
        xdig.insert(x%10);
        x/=10;
    }
    while (y) {
        ydig.insert(y%10);
        y/=10;
    }
    return xdig == ydig;
}

/* Orz bruce */
int main() {
    int X; scanf("%d",&X);

    int x = X;
    for (int i = 0; i < 1e9; i++) {
        x++;
        if (sameDigits(X,x)) {
            printf("%d\n",x);
            return 0;
        }
    }

    printf("0\n");

    return 0;
}
